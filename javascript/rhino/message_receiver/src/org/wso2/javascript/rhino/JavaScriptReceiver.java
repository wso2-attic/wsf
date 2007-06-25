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
import java.util.ArrayList;
import java.util.Iterator;

import javax.xml.namespace.QName;

import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.OMNamespace;
import org.apache.axiom.om.OMNode;
import org.apache.axiom.om.OMText;
import org.apache.axiom.soap.SOAP11Constants;
import org.apache.axiom.soap.SOAP12Constants;
import org.apache.axiom.soap.SOAPBody;
import org.apache.axiom.soap.SOAPEnvelope;
import org.apache.axiom.soap.SOAPFactory;
import org.apache.axis2.AxisFault;
import org.apache.axis2.context.MessageContext;
import org.apache.axis2.description.AxisMessage;
import org.apache.axis2.description.AxisOperation;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.engine.MessageReceiver;
import org.apache.axis2.receivers.AbstractInOutMessageReceiver;
import org.apache.axis2.wsdl.WSDLConstants;
import org.apache.ws.commons.schema.XmlSchemaComplexType;
import org.apache.ws.commons.schema.XmlSchemaElement;
import org.apache.ws.commons.schema.XmlSchemaParticle;
import org.apache.ws.commons.schema.XmlSchemaSequence;
import org.apache.ws.commons.schema.XmlSchemaType;
import org.apache.ws.commons.schema.constants.Constants;
import org.mozilla.javascript.Context;

/**
 * Class JavaScriptReceiver implements the AbstractInOutSyncMessageReceiver,
 * which, is the abstract IN-OUT MEP message receiver.
 */
public class JavaScriptReceiver extends AbstractInOutMessageReceiver implements
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
        SOAPEnvelope soapEnvelope = inMessage.getEnvelope();
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
            
             
            /*
             * Some host objects depend on the data we obtain from the
             * AxisService & ConfigurationContext.. It is possible to get these
             * data through the MessageContext. But we face problems at the
             * deployer, where we need to instantiate host objects in order for
             * the annotations framework to work and the MessageContext is not
             * available at that time. For the consistency we inject them in
             * here too..
             */
            context.putThreadLocal(AXIS2_SERVICE, inMessage.getAxisService());
            context.putThreadLocal(AXIS2_CONFIGURATION_CONTEXT, inMessage.getConfigurationContext());
            
            JavaScriptEngineUtils.loadGlobalPropertyObjects(engine, inMessage
                    .getConfigurationContext().getAxisConfiguration());
            // JS Engine seems to need the Axis2 repository location to load the
            // imported scripts. TODO: Do we really need this (thilina)
            URL repoURL = inMessage.getConfigurationContext().getAxisConfiguration()
                    .getRepository();
            if (repoURL != null) {
                JavaScriptEngine.axis2RepositoryLocation = repoURL.getPath();
            }

            Reader reader = readJS(inMessage);
            String jsFunctionName = inferJavaScriptFunctionName(inMessage);
            
            //support for importing javaScript files using services.xml or the axis2.xml
            String scripts = getImportScriptsList(inMessage);
            
            ArrayList params = new ArrayList();
            OMNode result = null;
            OMElement payload = soapEnvelope.getBody().getFirstElement();
            Object args = payload;
            if (payload != null) {
                AxisMessage axisMessage = inMessage.getAxisOperation().getMessage(
                        WSDLConstants.MESSAGE_LABEL_IN_VALUE);
                XmlSchemaElement xmlSchemaElement = axisMessage.getSchemaElement();
                if (xmlSchemaElement != null) {
                    XmlSchemaType schemaType = xmlSchemaElement.getSchemaType();
                    if (schemaType instanceof XmlSchemaComplexType) {
                        XmlSchemaComplexType complexType = ((XmlSchemaComplexType) schemaType);
                        XmlSchemaParticle particle = complexType.getParticle();
                        if (particle instanceof XmlSchemaSequence) {
                            XmlSchemaSequence xmlSchemaSequence = (XmlSchemaSequence) particle;
                            Iterator iterator = xmlSchemaSequence.getItems().getIterator();
                            // now we need to know some information from the
                            // binding operation.
                            while (iterator.hasNext()) {
                                XmlSchemaElement innerElement = (XmlSchemaElement) iterator.next();
                                OMElement omElement = payload.getFirstChildWithName(new QName(
                                        innerElement.getName()));
                                if (omElement == null) {
                                    throw new AxisFault(
                                            "Required element "
                                                    + innerElement.getName()
                                                    + " defined in the schema can not be found in the request");
                                }
                                params.add(createParam(omElement, innerElement.getSchemaTypeName(),
                                        engine));
                            }
                            args = params.toArray();
                        } else {
                            throw new AxisFault("Unsupported schema type in request");
                        }
                    } else if (xmlSchemaElement.getSchemaTypeName() == Constants.XSD_ANYTYPE) {
                        // TODO : Keith > Don't we need to handle the 'else' in here..
                        args = payload;
                    }
                }
            } else {
                // This validates whether the user has sent a bad SOAP message
                // with a non-XML payload.
                if (soapEnvelope.getBody().getFirstOMChild() != null) {
                    OMText textPayLoad = (OMText) soapEnvelope.getBody().getFirstOMChild();
                    //we allow only a sequence of spaces
                    if (textPayLoad.getText().trim().length() > 0) {
                        throw new AxisFault(
                                "Non-XML payload is not allowed. PayLoad inside the SOAP body needs to an XML element.");
                    }
                }
            }
            // Get the result by executing the javascript file
            result = engine.call(jsFunctionName, reader, args, scripts);

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
                OMNamespace namespace =
                        fac.createOMNamespace(elementQName.getNamespaceURI(), prefix);
                outElement = fac.createOMElement(xmlSchemaElement.getName(), namespace);
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
                                // Passing Null for the namespace as the WSDL
                                // which was generated does not have one for
                                // the 'return' element
                                OMElement omElement = fac.createOMElement(innerElement.getName(), null);
                                if (qName == Constants.XSD_ANYTYPE) {
                                    omElement.addChild(result);
                                } else {
                                    if (result instanceof OMText) {
                                        omElement.addChild(result);
                                    } else {
                                        OMElement element = (OMElement) result;
                                        omElement.setText(element.getText());
                                    }

                                }
                                outElement.addChild(omElement);
                            }
                            body.addChild(outElement);
                        } else {
                            throw new AxisFault("Unsupported schema type in response.");
                        }
                    } else if (xmlSchemaElement.getSchemaTypeName() == Constants.XSD_ANYTYPE){
                        if (result != null) {
                            outElement.addChild(result);
                            body.addChild(outElement);
                        }
                    }
                } else if (result != null){
                body.addChild(result);
            }
            outMessage.setEnvelope(envelope);
        } catch (Throwable throwable) {
            AxisFault fault= AxisFault.makeFault(throwable);
            // This is a workaround to avoid Axis2 sending the SOAPFault with a
            // http-400 code when sending using SOAP1. We explicitly set the
            // FualtCode to 'Receiver'.
            fault.setFaultCode(SOAP12Constants.SOAP_ENVELOPE_NAMESPACE_URI.equals(soapEnvelope.getNamespace().getNamespaceURI())
            ? SOAP12Constants.SOAP_DEFAULT_NAMESPACE_PREFIX + ":"
            + SOAP12Constants.FAULT_CODE_RECEIVER
            : SOAP12Constants.SOAP_DEFAULT_NAMESPACE_PREFIX + ":"
            + SOAP11Constants.FAULT_CODE_RECEIVER);
            throw fault;
        }
    }

    /**
     * Provides support for importing JavaScript files specified in the
     * Services.xml or the Axis2.xml using the "loadJSScripts" parameter.
     */
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
        if (Constants.XSD_BOOLEAN.equals(type)) {
            String value  = omElement.getText();
            return Boolean.valueOf(value);
        }
        if (Constants.XSD_DOUBLE.equals(type)) {
            String value  = omElement.getText();
            return new Double(value);
        }
        return omElement.getText();
    }

    /**
     * Extracts and returns the name of the JS function associated for the
     * currently dispatched operation. First we try to retrieve the function
     * name vis the JS_FUNCTION_NAME parameter of the AxisOperation. If not we
     * assume the localpart of the operation name to be the function name.
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

    /**
     * Locates the service Javascript file associated with ServiceJS parameter and returns
     * a Reader for it.
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
