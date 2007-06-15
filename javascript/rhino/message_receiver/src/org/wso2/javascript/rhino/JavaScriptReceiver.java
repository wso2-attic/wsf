/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.wso2.javascript.rhino;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.net.URL;
import java.util.Iterator;
import java.util.ArrayList;

import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.OMNode;
import org.apache.axiom.soap.SOAPEnvelope;
import org.apache.axiom.soap.SOAPFactory;
import org.apache.axiom.soap.SOAPBody;
import org.apache.axis2.AxisFault;
import org.apache.axis2.wsdl.WSDLConstants;
import org.apache.axis2.context.MessageContext;
import org.apache.axis2.description.AxisOperation;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.description.AxisMessage;
import org.apache.axis2.engine.MessageReceiver;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.receivers.AbstractInOutSyncMessageReceiver;
import org.apache.ws.commons.schema.XmlSchemaElement;
import org.apache.ws.commons.schema.XmlSchemaType;
import org.apache.ws.commons.schema.XmlSchemaComplexType;
import org.apache.ws.commons.schema.XmlSchemaParticle;
import org.apache.ws.commons.schema.XmlSchemaSequence;
import org.apache.ws.commons.schema.constants.Constants;
import org.mozilla.javascript.Context;
import org.mozilla.javascript.xmlimpl.XML;

import javax.xml.namespace.QName;

/**
 * Class JavaScriptReceiver implements the AbstractInOutSyncMessageReceiver,
 * which, is the abstract IN-OUT MEP message receiver.
 */
public class JavaScriptReceiver extends AbstractInOutSyncMessageReceiver implements
        MessageReceiver, JavaScriptEngineConstants {

    private String UNSUPPORTED_SCHEMA_TYPE =
            "At the moment we only support WSDL 2.0 RPC style schema, which has a secquence " +
                    "within a complexType";

    /**
     * Invokes the Javascript service with the parameters from the inMessage
     * and sets the outMessage with the response from the service.
     *
     * @param inMessage MessageContext object with information about the incoming message
     * @param outMessage MessageContext object with information about the outgoing message
     * @throws AxisFault
     */
    public void invokeBusinessLogic(MessageContext inMessage, MessageContext outMessage)
            throws AxisFault {
        try {
            // Create JS Engine, Inject HostObjects
            JavaScriptEngine engine = new JavaScriptEngine();

            // Rhino E4X XMLLibImpl object can be instantiated only from within a script
            // So we instantiate it in here, so that we can use it outside of the script later
            engine.getCx().evaluateString(engine, "new XML();", "Instantiate E4X", 0, null);


            JavaScriptEngineUtils.loadHostObjects(engine, inMessage.getConfigurationContext()
                    .getAxisConfiguration());
            
            // Inject the incoming MessageContext to the Rhino Context. Some
            // host objects need access to the MessageContext. Eg: FileSystem,
            // WSRequest
            Context context = engine.getCx();
            context.putThreadLocal(AXIS2_MESSAGECONTEXT, inMessage);
            
            // Some host objects depend on the data we obtain from the
            // AxisService.. It is possible to get these
            // date through the MessageContext, but we face problems at the
            // deployer, where we need to instantiate host objects
            // in order for the annotations framework to work. It is possible to
            // inject the AxisService at the message receiver, but not a
            // MessageContext. For the consistency we inject the AxisService in here too..
            context.putThreadLocal(AXIS2_SERVICE, inMessage.getAxisService());
            
            JavaScriptEngineUtils.loadGlobalPropertyObjects(engine, inMessage
                    .getConfigurationContext().getAxisConfiguration());
            // JS Engine seems to need the Axis2 repository location to load the
            // imported scripts
            // TODO: Do we really need this (thilina)
            URL repoURL = inMessage.getConfigurationContext().getAxisConfiguration()
                    .getRepository();
            if (repoURL != null) {
                JavaScriptEngine.axis2RepositoryLocation = repoURL.getPath();
            }

            Reader reader = readJS(inMessage);
            String jsFunctionName = inferJavaScriptFunctionName(inMessage);
            String scripts = getImportScriptsList(inMessage);
            SOAPEnvelope soapEnvelope = inMessage.getEnvelope();
            ArrayList params = new ArrayList();
            OMNode result = null;
            OMElement payload = soapEnvelope.getBody().getFirstElement();
            if (payload != null) {
                AxisMessage axisMessage =
                        inMessage.getAxisOperation()
                                .getMessage(WSDLConstants.MESSAGE_LABEL_IN_VALUE);
                XmlSchemaElement xmlSchemaElement = axisMessage.getSchemaElement();
                if (xmlSchemaElement != null) {
                    XmlSchemaType schemaType = xmlSchemaElement.getSchemaType();
                    if (schemaType instanceof XmlSchemaComplexType) {
                        XmlSchemaComplexType complexType = ((XmlSchemaComplexType) schemaType);
                        XmlSchemaParticle particle = complexType.getParticle();
                        if (particle instanceof XmlSchemaSequence) {
                            XmlSchemaSequence xmlSchemaSequence = (XmlSchemaSequence) particle;
                            Iterator iterator = xmlSchemaSequence.getItems().getIterator();
                            // now we need to know some information from the binding operation.
                            while (iterator.hasNext()) {
                                XmlSchemaElement innerElement = (XmlSchemaElement) iterator.next();
                                OMElement omElement = payload.getFirstChildWithName(new QName(innerElement.getName()));
                                if (omElement == null) {
                                    throw new AxisFault("Required element " + innerElement.getName() +
                                            " defined in the schema can not be found in the request");
                                }
                                params.add(createParam(omElement, innerElement.getSchemaTypeName(), engine));
                            }
                            Object[] objects = params.toArray();
                            result = engine.call(jsFunctionName, reader, objects, scripts);
                        } else {
                            throw new AxisFault("Unsupported schema type in request");
                        }
                    } else if (xmlSchemaElement.getSchemaTypeName() == Constants.XSD_ANY){
                        result = engine.call(jsFunctionName, reader, payload, scripts);
                    }
                } else {
                    result = engine.call(jsFunctionName, reader, payload, scripts);
                }
            } else {
                // Get the result by executing the javascript file
                result = engine.call(jsFunctionName, reader, payload, scripts);
            }

//            if (result == null) {
//                throw new AxisFault(Messages.getMessage("JavaScriptNoanswer"));
//            }

            // Create the outgoing message
            SOAPFactory fac;
            if (inMessage.isSOAP11()) {
                fac = OMAbstractFactory.getSOAP11Factory();
            } else {
                fac = OMAbstractFactory.getSOAP12Factory();
            }
            SOAPEnvelope envelope = fac.getDefaultEnvelope();
            SOAPBody body = envelope.getBody();
            AxisMessage outAxisMessage =
                        inMessage.getAxisOperation()
                                .getMessage(WSDLConstants.MESSAGE_LABEL_OUT_VALUE);
                XmlSchemaElement xmlSchemaElement = outAxisMessage.getSchemaElement();
            OMElement outElement;
            String prefix = "ws";
            if (xmlSchemaElement != null) {
                QName elementQName = xmlSchemaElement.getSchemaTypeName();
                outElement = fac.createOMElement(xmlSchemaElement.getName(), fac.createOMNamespace(elementQName.getNamespaceURI(), prefix));
                    XmlSchemaType schemaType = xmlSchemaElement.getSchemaType();
                    if (schemaType instanceof XmlSchemaComplexType) {
                        XmlSchemaComplexType complexType = ((XmlSchemaComplexType) schemaType);
                        XmlSchemaParticle particle = complexType.getParticle();
                        if (particle instanceof XmlSchemaSequence) {
                            XmlSchemaSequence xmlSchemaSequence = (XmlSchemaSequence) particle;
                            Iterator iterator = xmlSchemaSequence.getItems().getIterator();
                            // now we need to know some information from the binding operation.
                            while (iterator.hasNext()) {
                                XmlSchemaElement innerElement = (XmlSchemaElement) iterator.next();
                                QName qName = innerElement.getSchemaTypeName();
                                if (qName == Constants.XSD_ANYTYPE) {
                                    outElement.addChild(result);
                                } else {
                                    OMElement omElement = fac.createOMElement(innerElement.getName(), fac.createOMNamespace(qName.getNamespaceURI(), prefix));
                                    OMElement element = (OMElement) result;
                                    omElement.setText(element.getText());
                                    outElement.addChild(omElement);
                                }
                            }
                            body.addChild(outElement);

                        } else {
                            throw new AxisFault("Unsupported schema type in request");
                        }
                    } else if (xmlSchemaElement.getSchemaTypeName() == Constants.XSD_ANY){
                        body.addChild(result);
                    }
                } else if (result != null){
                body.addChild(result);
            }
            outMessage.setEnvelope(envelope);
        } catch (Throwable throwable) {
            throw AxisFault.makeFault(throwable);
        }
    }

    private String getImportScriptsList(MessageContext inMessage) {
        String scripts = null;

        // Get necessary JavaScripts to be loaded from services.xml
        Parameter param = inMessage.getOperationContext().getAxisOperation().getParameter(
                JavaScriptEngineConstants.LOAD_JSSCRIPTS);
        if (param != null) {
            scripts = (String) param.getValue();
        }

        /**** TODO We might not need the following code since getting a parameter
        from an Operation covers this(thilina) ****/
        // Get necessary JavaScripts to be loaded from axis2.xml
        param = inMessage.getConfigurationContext().getAxisConfiguration().getParameter(
                JavaScriptEngineConstants.LOAD_JSSCRIPTS);
        if (param != null) {
            if (scripts == null) {
                scripts = (String) param.getValue();
            } else {
                // Avoids loading the same set of script files twice
                if (!scripts.equals(param.getValue())) {
                    scripts += "," + param.getValue();
                }
            }
        }
        return scripts;
    }

    private Object createParam(OMElement omElement, QName type, JavaScriptEngine engine) {
        // TODO we may need to handle arrays here and also do some type conversion in some cases.

        if (Constants.XSD_ANYTYPE.equals(type)) {
            Context context = engine.getCx();
            OMElement element  = omElement.getFirstElement();
            Object[] objects = {element};
            Object args = context.newObject(engine, "XML",objects);
            return args;
        }
        return omElement.getText();
    }

    /*
     * Extracts and returns the name of the JS function to be invoked from the
     * inMessage
     * 
     * @param inMessage
     *            MessageContext object with information about the incoming
     *            message
     * @return the name of the requested JS function
     * @throws AxisFault
     *             if the function name cannot be inferred.
     */
    private String inferJavaScriptFunctionName(MessageContext inMessage) throws AxisFault {
        //Look at the method name. if available this should be a javascript method
        AxisOperation op = inMessage.getOperationContext().getAxisOperation();
        if (op == null) {
            throw new AxisFault("Operation notFound");
        }
        Parameter parameter;
        String jsFunctionName;
        if ((parameter = op.getParameter(JS_FUNCTION_NAME)) != null) {
            jsFunctionName = (String) parameter.getValue();
        } else {
            jsFunctionName = op.getName().getLocalPart();
        }
        if (jsFunctionName == null)
            throw new AxisFault(
                    "Unable to infer the JavaScript function  corresponding to this message.");
        return jsFunctionName;
    }

    /*
     * Locates the service Javascript associated with ServiceJS parameter and returns
     * an input stream to it.
     *
     * @param inMessage MessageContext object with information about the incoming message
     * @return an input stream to the javascript source file
     * @throws AxisFault if the parameter ServiceJS is not specified or if the service
     * implementation is not available
     */
    private Reader readJS(MessageContext inMessage) throws AxisFault {
        InputStream jsFileStream;
        AxisService service = inMessage.getServiceContext().getAxisService();
        Parameter implInfoParam = service.getParameter(JavaScriptEngineConstants.SERVICE_JS);
        if (implInfoParam == null) {
            throw new AxisFault("Parameter 'ServiceJS' not specified");
        }
        if (implInfoParam.getValue() instanceof File) {
            try {
                jsFileStream = new FileInputStream((File) (implInfoParam.getValue()));
            } catch (FileNotFoundException e) {
                throw new AxisFault("Unable to load the javaScript, File not Found", e);
            }
        } else {
            jsFileStream = service.getClassLoader().getResourceAsStream(
                    implInfoParam.getValue().toString());
        }
        if (jsFileStream == null) {
            throw new AxisFault("Unable to load the javaScript");
        }
        return new BufferedReader(new InputStreamReader(jsFileStream));
    }
}
