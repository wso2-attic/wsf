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

import org.apache.axiom.om.OMAbstractFactory;
import org.apache.axiom.om.OMAttribute;
import org.apache.axiom.om.OMElement;
import org.apache.axiom.om.OMFactory;
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
import org.apache.axis2.databinding.types.Day;
import org.apache.axis2.databinding.types.Duration;
import org.apache.axis2.databinding.types.Month;
import org.apache.axis2.databinding.types.MonthDay;
import org.apache.axis2.databinding.types.Time;
import org.apache.axis2.databinding.types.Year;
import org.apache.axis2.databinding.types.YearMonth;
import org.apache.axis2.databinding.utils.ConverterUtil;
import org.apache.axis2.description.AxisMessage;
import org.apache.axis2.description.AxisOperation;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.description.java2wsdl.TypeTable;
import org.apache.axis2.engine.MessageReceiver;
import org.apache.axis2.json.JSONOMBuilder;
import org.apache.axis2.receivers.AbstractInOutMessageReceiver;
import org.apache.axis2.wsdl.WSDLConstants;
import org.apache.ws.commons.schema.XmlSchemaComplexType;
import org.apache.ws.commons.schema.XmlSchemaElement;
import org.apache.ws.commons.schema.XmlSchemaEnumerationFacet;
import org.apache.ws.commons.schema.XmlSchemaObjectCollection;
import org.apache.ws.commons.schema.XmlSchemaParticle;
import org.apache.ws.commons.schema.XmlSchemaSequence;
import org.apache.ws.commons.schema.XmlSchemaSimpleType;
import org.apache.ws.commons.schema.XmlSchemaSimpleTypeContent;
import org.apache.ws.commons.schema.XmlSchemaSimpleTypeRestriction;
import org.apache.ws.commons.schema.XmlSchemaType;
import org.apache.ws.commons.schema.constants.Constants;
import org.mozilla.javascript.Context;
import org.mozilla.javascript.NativeArray;
import org.mozilla.javascript.NativeObject;
import org.mozilla.javascript.Scriptable;
import org.mozilla.javascript.Undefined;
import org.mozilla.javascript.UniqueTag;
import org.wso2.javascript.xmlimpl.XML;
import org.wso2.javascript.xmlimpl.XMLList;

import javax.xml.namespace.QName;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.net.URL;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.TimeZone;

/**
 * Class JavaScriptReceiver implements the AbstractInOutSyncMessageReceiver,
 * which, is the abstract IN-OUT MEP message receiver.
 */
public class JavaScriptReceiver extends AbstractInOutMessageReceiver implements MessageReceiver,
        JavaScriptEngineConstants {

    /**
     * Invokes the Javascript service with the parameters from the inMessage
     * and sets the outMessage with the response from the service.
     *
     * @param inMessage  MessageContext object with information about the incoming message
     * @param outMessage MessageContext object with information about the outgoing message
     * @throws AxisFault
     */
    public void invokeBusinessLogic(MessageContext inMessage, MessageContext outMessage)
            throws AxisFault {
        SOAPEnvelope soapEnvelope = inMessage.getEnvelope();
        try {
            // Create JS Engine, Inject HostObjects
            String serviceName = inMessage.getAxisService().getName();
            JavaScriptEngine engine = new JavaScriptEngine(serviceName);

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
            context.putThreadLocal(AXIS2_CONFIGURATION_CONTEXT, inMessage
                    .getConfigurationContext());
            JavaScriptEngineUtils.loadGlobalPropertyObjects(engine, inMessage
                    .getConfigurationContext().getAxisConfiguration(), serviceName);
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

            OMElement payload = soapEnvelope.getBody().getFirstElement();
            Object args = payload;
            if (payload != null) {

                // We neet to get the Axis Message from the incomming message so that we can get its schema.
                // We need the schema in order to unwrap the parameters.
                AxisMessage axisMessage = inMessage.getAxisOperation().getMessage(
                        WSDLConstants.MESSAGE_LABEL_IN_VALUE);
                XmlSchemaElement xmlSchemaElement = axisMessage.getSchemaElement();
                if (xmlSchemaElement != null) {

                    // Once the schema is obtauned we iterate through the schema looking for the elemants in the payload.
                    // for Each element we extract its value and create a parameter which can be passed into the
                    // javascript function.
                    XmlSchemaType schemaType = xmlSchemaElement.getSchemaType();
                    if (schemaType instanceof XmlSchemaComplexType) {
                        XmlSchemaComplexType complexType = ((XmlSchemaComplexType) schemaType);
                        List params = handleComplexTypeInRequest(complexType, payload, engine,
                                                                 new ArrayList());
                        args = params.toArray();
                    } else if (xmlSchemaElement.getSchemaTypeName() == Constants.XSD_ANYTYPE) {
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
                                "Non-XML payload is not allowed. PayLoad inside the SOAP body needs to be an XML element.");
                    }
                }
            }
            AxisMessage outAxisMessage = inMessage.getAxisOperation().getMessage(
                    WSDLConstants.MESSAGE_LABEL_OUT_VALUE);
            // Get the result by executing the javascript file
            boolean annotated = false;
            Parameter parameter = outAxisMessage.getParameter(JavaScriptEngineConstants.ANNOTATED);
            if (parameter != null) {
                annotated = ((Boolean) parameter.getValue()).booleanValue();
            }
            Object response = engine.call(jsFunctionName, reader, args, scripts);

            // Create the outgoing message
            SOAPFactory fac;
            if (inMessage.isSOAP11()) {
                fac = OMAbstractFactory.getSOAP11Factory();
            } else {
                fac = OMAbstractFactory.getSOAP12Factory();
            }
            SOAPEnvelope envelope = fac.getDefaultEnvelope();
            SOAPBody body = envelope.getBody();
            XmlSchemaElement xmlSchemaElement = outAxisMessage.getSchemaElement();
            OMElement outElement;
            String prefix = "ws";
            if (xmlSchemaElement != null) {
                QName elementQName = xmlSchemaElement.getSchemaTypeName();
                OMNamespace namespace = fac.createOMNamespace(elementQName.getNamespaceURI(),
                                                              prefix);
                outElement = fac.createOMElement(xmlSchemaElement.getName(), namespace);
                XmlSchemaType schemaType = xmlSchemaElement.getSchemaType();
                if (schemaType instanceof XmlSchemaComplexType) {
                    XmlSchemaComplexType complexType = ((XmlSchemaComplexType) schemaType);
                    handleComplexTypeInResponse(complexType, outElement, response, fac,
                                                engine.isJson(), false);
                    body.addChild(outElement);
                } else if (xmlSchemaElement.getSchemaTypeName() == Constants.XSD_ANYTYPE) {
                    if (!JavaScriptEngine.isNull(response)) {
                        // If its anyType that means we have to add xsi:type
                        OMElement element = buildResponse(false, engine.isJson(), response,
                                                          xmlSchemaElement);
                        if (element != null) {
                            body.addChild(element);
                        }
                    }
                }
            } else if (!JavaScriptEngine.isNull(response)) {
                OMElement element =
                        buildResponse(annotated, engine.isJson(), response, xmlSchemaElement);
                if (element != null) {
                    body.addChild(element);
                }
            }
            outMessage.setEnvelope(envelope);
        } catch (Throwable throwable) {
            AxisFault fault = AxisFault.makeFault(throwable);
            // This is a workaround to avoid Axis2 sending the SOAPFault with a
            // http-400 code when sending using SOAP1. We explicitly set the
            // FualtCode to 'Receiver'.
            fault.setFaultCode(SOAP12Constants.SOAP_ENVELOPE_NAMESPACE_URI.equals(soapEnvelope
                    .getNamespace().getNamespaceURI())
                    ? SOAP12Constants.SOAP_DEFAULT_NAMESPACE_PREFIX + ":" + SOAP12Constants
                    .FAULT_CODE_RECEIVER
                    : SOAP12Constants.SOAP_DEFAULT_NAMESPACE_PREFIX + ":" + SOAP11Constants
                    .FAULT_CODE_RECEIVER);
            throw fault;
        }
    }

    private void handleComplexTypeInResponse(XmlSchemaComplexType complexType, OMElement outElement,
                                             Object response,
                                             OMFactory fac, boolean json,
                                             boolean isInnerParam) throws AxisFault {
        XmlSchemaParticle particle = complexType.getParticle();
        if (particle instanceof XmlSchemaSequence) {
            XmlSchemaSequence xmlSchemaSequence = (XmlSchemaSequence) particle;
            XmlSchemaObjectCollection schemaObjectCollection = xmlSchemaSequence.getItems();
            int count = schemaObjectCollection.getCount();
            Iterator iterator = schemaObjectCollection.getIterator();
            // now we need to know some information from the binding operation.
            while (iterator.hasNext()) {
                XmlSchemaElement innerElement = (XmlSchemaElement) iterator.next();
                String name = innerElement.getName();
                XmlSchemaType schemaType = innerElement.getSchemaType();
                if (schemaType instanceof XmlSchemaComplexType) {
                    Scriptable scriptable = (Scriptable) response;
                    Object object = scriptable.get(name, scriptable);
                    if (checkRequired(innerElement, object)) {
                        continue;
                    }
                    XmlSchemaComplexType innerComplexType = (XmlSchemaComplexType) schemaType;
                    OMElement complexTypeElement =
                            fac.createOMElement(name, outElement.getNamespace());
                    outElement.addChild(complexTypeElement);
                    handleComplexTypeInResponse(innerComplexType, complexTypeElement, object, fac,
                                                json, true);
                } else {
                    Object object;
                    if (isInnerParam || count > 1) {
                        Scriptable scriptable = (Scriptable) response;
                        object = scriptable.get(name, scriptable);
                    } else {
                        object = response;
                    }
                    if (checkRequired(innerElement, object)) {
                        if (innerElement.getSchemaTypeName() != Constants.XSD_ANYTYPE) {
                            continue;
                        }
                    }
                    handleSimpleTypeinResponse(innerElement, object, fac, json,
                                               outElement);
                }
            }
        } else {
            throw new AxisFault("Unsupported schema type in response.");
        }
    }

    private boolean checkRequired(XmlSchemaElement innerElement, Object object) throws AxisFault {
        if (JavaScriptEngine.isNull(object)) {
            if (innerElement.getSchemaTypeName() == Constants.XSD_ANYTYPE ||
                    innerElement.getMinOccurs() == 0) {
                return true;
            }
            throw new AxisFault("Required element " + innerElement.getName() + " of type " +
                    innerElement.getSchemaTypeName() +
                    " was not found in the response");
        }
        return false;
    }

    private List handleComplexTypeInRequest(XmlSchemaComplexType complexType, OMElement payload,
                                            JavaScriptEngine engine, List paramNames)
            throws AxisFault {
        XmlSchemaParticle particle = complexType.getParticle();
        List params = new ArrayList();
        if (particle instanceof XmlSchemaSequence) {
            XmlSchemaSequence xmlSchemaSequence = (XmlSchemaSequence) particle;
            Iterator iterator = xmlSchemaSequence.getItems().getIterator();
            // now we need to know some information from the
            // binding operation.
            while (iterator.hasNext()) {
                XmlSchemaElement innerElement = (XmlSchemaElement) iterator.next();
                XmlSchemaType schemaType = innerElement.getSchemaType();
                if (schemaType instanceof XmlSchemaComplexType) {
                    String innerElementName = innerElement.getName();
                    QName payloadQname = payload.getQName();
                    OMElement complexTypePayload = null;
                    QName qName;
                    // When retrieving elements we have to look for the namespace too. There may be
                    // Ocations even when the children are namespace qualified. In such situations
                    // we should retrieve them using that namespace.
                    // If that fails we try using the localname only.
                    if (payloadQname != null) {
                        qName = new QName(payloadQname.getNamespaceURI(),
                                          innerElementName);
                        complexTypePayload = payload.getFirstChildWithName(qName);
                    }
                    if (complexTypePayload == null) {
                        qName = new QName(innerElementName);
                        complexTypePayload = payload.getFirstChildWithName(qName);
                    }
                    if (complexTypePayload == null) {
                        throw new AxisFault(
                                "Required element " + complexType.getName()
                                        + " defined in the schema can not be found in the request");
                    }
                    List innerParamNames = new ArrayList();
                    List innerParams = handleComplexTypeInRequest((XmlSchemaComplexType) schemaType,
                                                                  complexTypePayload,
                                                                  engine, innerParamNames);
                    Scriptable scriptable = engine.getCx().newObject(engine);
                    for (int i = 0; i < innerParams.size(); i++) {
                        scriptable.put((String) innerParamNames.get(i), scriptable,
                                       innerParams.get(i));
                    }
                    params.add(scriptable);
                } else if (schemaType instanceof XmlSchemaSimpleType) {
                    // Handle enumerations in here.
                    XmlSchemaSimpleType xmlSchemaSimpleType = (XmlSchemaSimpleType) schemaType;
                    XmlSchemaSimpleTypeContent content = xmlSchemaSimpleType.getContent();
                    if (content instanceof XmlSchemaSimpleTypeRestriction) {
                        // We only support restriction on xs:string.
                        XmlSchemaSimpleTypeRestriction simpleTypeRestriction =
                                (XmlSchemaSimpleTypeRestriction) content;
                        String elementName = innerElement.getName();
                        Object object = handleSimpleElement(payload, engine, elementName,
                                                            innerElement.getMinOccurs(),
                                                            simpleTypeRestriction.getBaseTypeName());
                        XmlSchemaObjectCollection facets = simpleTypeRestriction.getFacets();
                        Iterator iterator1 = facets.getIterator();
                        // Used to check whether the incoming value of the enumeration matches one thats defined in the
                        // schema.
                        boolean valueFound = false;
                        while (iterator1.hasNext()) {
                            XmlSchemaEnumerationFacet enumerationFacet =
                                    (XmlSchemaEnumerationFacet) iterator1.next();
                            if (enumerationFacet.getValue().equals(object)) {
                                valueFound = true;
                                break;
                            }
                        }
                        if (!valueFound) {
                            throw new AxisFault("The element " + innerElement.getName() +
                                    " is an enumeration of " +
                                    "strings. The input " + object +
                                    " does not match the defined enumeration.");
                        }
                        params.add(object);
                        paramNames.add(elementName);
                    } else {
                        throw new AxisFault("Unsupported restriction in Schema");
                    }
                } else {
                    params.add(handleSimpleTypeInRequest(payload, engine, innerElement));
                    paramNames.add(innerElement.getName());
                }
            }
        } else {
            throw new AxisFault("Unsupported schema type in request");
        }
        return params;
    }

    private Object handleSimpleTypeInRequest(OMElement payload, JavaScriptEngine engine,
                                             XmlSchemaElement innerElement) throws AxisFault {
        long maxOccurs = innerElement.getMaxOccurs();
        // Check whether the schema advertises this element as an array
        if (maxOccurs > 1) {
            // If its an array get all elements with that name and create a sinple parameter out of it
            String innerElemenrName = innerElement.getName();
            Iterator iterator1 = payload.getChildrenWithName(new QName(
                    innerElemenrName));
            return handleArray(iterator1, innerElement.getSchemaTypeName(), engine);
        } else {
            return handleSimpleElement(payload, engine, innerElement.getName(),
                                       innerElement.getMinOccurs(),
                                       innerElement.getSchemaTypeName());
        }
    }

    private Object handleSimpleElement(OMElement payload, JavaScriptEngine engine,
                                       String innerElementName, long minOccurs, QName schemaType)
            throws AxisFault {
        QName payloadQname = payload.getQName();
        OMElement omElement = null;
        QName qName;
        // When retrieving elements we have to look for the namespace too. There may be
        // Ocations even when the children are namespace qualified. In such situations
        // we should retrieve them using that namespace.
        // If that fails we try using the localname only.
        if (payloadQname != null) {
            qName = new QName(payloadQname.getNamespaceURI(),
                                    innerElementName);
            omElement = payload.getFirstChildWithName(qName);
        }
        if (omElement == null ){
            qName = new QName(innerElementName);
            omElement = payload.getFirstChildWithName(qName);
        }
        if (omElement == null) {
            // There was no such element in the payload. Therefore we check for minoccurs
            // and if its 0 add null as a parameter (If not we might mess up the parameters
            // we pass into the function).
            if (minOccurs == 0) {
                return Undefined.instance;
            } else {
                // If minoccurs is not zero throw an exception.
                // Do we need to di strict schema validation?
                throw new AxisFault(
                        "Required element " + innerElementName
                                + " defined in the schema can not be found in the request");
            }
        }
        return createParam(omElement, schemaType, engine);
    }

    private void handleSimpleTypeinResponse(XmlSchemaElement innerElement, Object jsObject,
                                            OMFactory factory, boolean json,
                                            OMElement outElement) throws AxisFault {
        long maxOccurs = innerElement.getMaxOccurs();
        if (maxOccurs > 1 && !innerElement.getSchemaTypeName().equals(Constants.XSD_ANYTYPE)) {
            if (jsObject instanceof Object[]) {
                Object[] objects = (Object[]) jsObject;
                for (int i = 0; i < objects.length; i++) {
                    outElement.addChild(handleSchemaTypeinResponse(innerElement, objects[i],
                                                                   factory, json));
                }
            } else if (jsObject instanceof NativeArray) {
                NativeArray nativeArray = (NativeArray) jsObject;
                Object[] objects = nativeArray.getAllIds();
                for (int i = 0; i < objects.length; i++) {
                    Object object = objects[i];
                    Object o;
                    if (object instanceof String) {
                        String property = (String) object;
                        if ("length".equals(property)) {
                            continue;
                        }
                        o = nativeArray.get(property, nativeArray);
                    } else {
                        Integer property = (Integer) object;
                        o = nativeArray.get(property.intValue(), nativeArray);
                    }
                    outElement.addChild(handleSchemaTypeinResponse(innerElement, o,
                                                                   factory, json));
                }
            } else {
                outElement.addChild(handleSchemaTypeinResponse(innerElement, jsObject, factory,
                                                               json));
            }
            return;
        }
        outElement.addChild(
                handleSchemaTypeinResponse(innerElement, jsObject, factory, json));
    }

    private OMElement handleSchemaTypeinResponse(XmlSchemaElement innerElement, Object jsObject,
                                                 OMFactory factory, boolean json)
            throws AxisFault {
        QName qName = innerElement.getSchemaTypeName();
        OMElement element = factory.createOMElement(innerElement.getName(), null);
        if (qName.equals(Constants.XSD_ANYTYPE)) {
            if (JavaScriptEngine.isNull(jsObject)) {
                return element;
            }
            // need to set annotated as false cause we need to set xsi:type
            return buildResponse(false, json, jsObject, innerElement);
        }
        if (qName.equals(Constants.XSD_STRING)) {
            String str = JSToOMConverter.convertToString(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_FLOAT)) {
            String str = JSToOMConverter.convertToFloat(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_DOUBLE)) {
            String str = JSToOMConverter.convertToDouble(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_INTEGER)) {
            String str = JSToOMConverter.convertToInteger(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_INT)) {
            String str = JSToOMConverter.convertToInt(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_NONPOSITIVEINTEGER)) {
            String str = JSToOMConverter.convertToNonPositiveInteger(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_NONNEGATIVEINTEGER)) {
            String str = JSToOMConverter.convertToNonNegativeInteger(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_POSITIVEINTEGER)) {
            String str = JSToOMConverter.convertToPositiveInteger(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_NEGATIVEINTEGER)) {
            String str = JSToOMConverter.convertToNegativeInteger(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_LONG)) {
            String str = JSToOMConverter.convertToLong(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_SHORT)) {
            String str = JSToOMConverter.convertToShort(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_BYTE)) {
            String str = JSToOMConverter.convertToByte(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_UNSIGNEDLONG)) {
            String str = JSToOMConverter.convertToUnsignedLong(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_UNSIGNEDBYTE)) {
            String str = JSToOMConverter.convertToUnsignedByte(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_UNSIGNEDINT)) {
            String str = JSToOMConverter.convertToUnsignedInt(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_UNSIGNEDSHORT)) {
            String str = JSToOMConverter.convertToUnsignedShort(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_DECIMAL)) {
            String str = JSToOMConverter.convertToDecimal(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_BOOLEAN)) {
            String str = JSToOMConverter.convertToBoolean(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_DATETIME)) {
            String str = JSToOMConverter.convertToDateTime(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_DATE)) {
            String str = JSToOMConverter.convertToDate(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_TIME)) {
            String str = JSToOMConverter.convertToTime(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_YEARMONTH)) {
            String str = JSToOMConverter.convertToGYearMonth(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_MONTHDAY)) {
            String str = JSToOMConverter.convertToGMonthDay(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_YEAR)) {
            String str = JSToOMConverter.convertToGYear(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_MONTH)) {
            String str = JSToOMConverter.convertToGMonth(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_DAY)) {
            String str = JSToOMConverter.convertToGDay(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_DURATION)) {
            String str = JSToOMConverter.convertToDuration(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_NORMALIZEDSTRING)) {
            String str = JSToOMConverter.convertToNormalizedString(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_TOKEN)) {
            String str = JSToOMConverter.convertToToken(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_LANGUAGE)) {
            String str = JSToOMConverter.convertToLanguage(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_NAME)) {
            String str = JSToOMConverter.convertToName(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_NCNAME)) {
            String str = JSToOMConverter.convertToNCName(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_NOTATION)) {
            String str = JSToOMConverter.convertToNOTATION(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_ANYURI)) {
            String str = JSToOMConverter.convertToAnyURI(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_QNAME)) {
            String str = JSToOMConverter.convertToQName(jsObject, element);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_HEXBIN)) {
            String str = JSToOMConverter.convertToHexBinary(jsObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_BASE64)) {
            String str = JSToOMConverter.convertToBase64Binary(jsObject);
            element.setText(str);
            return element;
        }
        return element;
    }

    /**
     * Provides support for importing JavaScript files specified in the
     * Services.xml or the Axis2.xml using the "loadJSScripts" parameter.
     *
     * @param inMessage - The incoming message Context
     * @return String
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

    /**
     * Creates an object that can be passed into a javascript function from an OMElement.
     *
     * @param omElement - The OMElement that the parameter should be created for
     * @param type      - The schemaType of the incoming message element
     * @param engine    - Reference to the javascript engine
     * @return - An Object that can be passed into a JS function
     * @throws AxisFault - In case an exception occurs
     */
    private Object createParam(OMElement omElement, QName type, JavaScriptEngine engine)
            throws AxisFault {

        if (Constants.XSD_ANYTYPE.equals(type)) {
            Context context = engine.getCx();
            OMElement element = omElement.getFirstElement();
            if (element != null) {
                Object[] objects = { element };
                return context.newObject(engine, "XML", objects);
            } else if (omElement.getText() != null) {
                OMAttribute omAttribute = omElement.getAttribute(new QName("http://www.w3.org/2001/XMLSchema-instance", "type"));
                if (omAttribute != null) {
                    String value = omAttribute.getAttributeValue();
                    if (value != null && !value.trim().equals("")) {
                        String[] strings = value.split(":");
                        TypeTable table = new TypeTable();
                        QName qName = table.getQNamefortheType(strings[1]);
                        return createParam(omElement, qName, engine);
                    }
                }
                return omElement.getText();
            } else {
                return Undefined.instance;
            }
        }
        String value = omElement.getText();
        if (value == null) {
            throw new AxisFault(
                    "The value of Element " + omElement.getLocalName() + " cannot be null");
        }
        if (Constants.XSD_BOOLEAN.equals(type)) {
            try {
                return Boolean.valueOf(ConverterUtil.convertToBoolean(value));
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "boolean"));
            }
        }
        if (Constants.XSD_DOUBLE.equals(type)) {
            try {
                return new Double(ConverterUtil.convertToDouble(value));
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "double"));
            }
        }
        if (Constants.XSD_FLOAT.equals(type)) {
            try {
                return new Float(ConverterUtil.convertToFloat(value));
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "float"));
            }
        }
        if (Constants.XSD_INT.equals(type)) {
            try {
                return new Integer(ConverterUtil.convertToInt(value));
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "int"));
            }
        }
        if (Constants.XSD_INTEGER.equals(type)) {
            try {
                if ((value == null) || value.equals("")) {
                    return new Integer(Integer.MIN_VALUE);
                }
                if (value.startsWith("+")) {
                    value = value.substring(1);
                }
                return new Integer(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "integer"));
            }
        }
        if (Constants.XSD_POSITIVEINTEGER.equals(type)) {
            try {
                return ConverterUtil.convertToPositiveInteger(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "positive integer"));
            }
        }
        if (Constants.XSD_NEGATIVEINTEGER.equals(type)) {
            try {
                return ConverterUtil.convertToNegativeInteger(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "negative integer"));
            }
        }
        if (Constants.XSD_NONPOSITIVEINTEGER.equals(type)) {
            try {
                return ConverterUtil.convertToNonPositiveInteger(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "non-positive integer"));
            }
        }
        if (Constants.XSD_NONNEGATIVEINTEGER.equals(type)) {
            try {
                return ConverterUtil.convertToNonNegativeInteger(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "non-negative integer"));
            }
        }
        if (Constants.XSD_LONG.equals(type)) {
            try {
                return new Long(ConverterUtil.convertToLong(value));
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "long"));
            }
        }
        if (Constants.XSD_SHORT.equals(type)) {
            try {
                return new Short(ConverterUtil.convertToShort(value));
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "short"));
            }
        }
        if (Constants.XSD_BYTE.equals(type)) {
            try {
                return new Byte(ConverterUtil.convertToByte(value));
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "byte"));
            }
        }
        if (Constants.XSD_UNSIGNEDINT.equals(type)) {
            try {
                return ConverterUtil.convertToUnsignedInt(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "unsigned int"));
            }
        }
        if (Constants.XSD_UNSIGNEDLONG.equals(type)) {
            try {
                return ConverterUtil.convertToUnsignedLong(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "unsigned long"));
            }
        }
        if (Constants.XSD_UNSIGNEDSHORT.equals(type)) {
            try {
                return ConverterUtil.convertToUnsignedShort(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "unsigned short"));
            }
        }
        if (Constants.XSD_UNSIGNEDBYTE.equals(type)) {
            try {
                return ConverterUtil.convertToUnsignedByte(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "unsigned byte"));
            }
        }
        if (Constants.XSD_DECIMAL.equals(type)) {
            try {
                return ConverterUtil.convertToDecimal(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "decimal"));
            }
        }
        if (Constants.XSD_DATETIME.equals(type)) {
            try {
                Calendar calendar = ConverterUtil.convertToDateTime(value);
                return engine.getCx().newObject(engine, "Date", new Object[] { new Long(calendar.getTimeInMillis()) });
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "date time"));
            }
        }
        if (Constants.XSD_DATE.equals(type)) {
            try {
                Date date = ConverterUtil.convertToDate(value);
                return engine.getCx().newObject(engine, "Date", new Object[] { new Long(date.getTime()) });
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "date"));
            }
        }
        if (Constants.XSD_TIME.equals(type)) {
            try {
                Time time = ConverterUtil.convertToTime(value);
                return engine.getCx().newObject(engine, "Date", new Object[] { new Long(time.getAsCalendar().getTimeInMillis()) });
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "time"));
            }
        }
        if (Constants.XSD_YEARMONTH.equals(type)) {
            try {
                YearMonth yearMonth = ConverterUtil.convertToGYearMonth(value);
                Calendar calendar = Calendar.getInstance();
                calendar.clear();
                calendar.set(Calendar.YEAR, yearMonth.getYear());
                calendar.set(Calendar.MONTH, yearMonth.getMonth());
                String timezone = yearMonth.getTimezone();
                if (timezone != null) {
                    calendar.setTimeZone(TimeZone.getTimeZone(timezone));
                }
                return engine.getCx().newObject(engine, "Date", new Object[] { new Long(calendar.getTimeInMillis()) });
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "yearMonth"));
            }
        }
        if (Constants.XSD_MONTHDAY.equals(type)) {
            try {
                MonthDay monthDay = ConverterUtil.convertToGMonthDay(value);
                Calendar calendar = Calendar.getInstance();
                calendar.clear();
                calendar.set(Calendar.DAY_OF_MONTH, monthDay.getDay());
                calendar.set(Calendar.MONTH, monthDay.getMonth());
                String timezone = monthDay.getTimezone();
                if (timezone != null) {
                    calendar.setTimeZone(TimeZone.getTimeZone(timezone));
                }
                return engine.getCx().newObject(engine, "Date", new Object[] { new Long(calendar.getTimeInMillis()) });
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "MonthDay"));
            }
        }
        if (Constants.XSD_YEAR.equals(type)) {
            try {
                Year year = ConverterUtil.convertToGYear(value);
                Calendar calendar = Calendar.getInstance();
                calendar.clear();
                calendar.set(Calendar.YEAR, year.getYear());
                String timezone = year.getTimezone();
                if (timezone != null) {
                    calendar.setTimeZone(TimeZone.getTimeZone(timezone));
                }
                return engine.getCx().newObject(engine, "Date", new Object[] { new Long(calendar.getTimeInMillis()) });
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "year"));
            }
        }
        if (Constants.XSD_MONTH.equals(type)) {
            try {
                Month month = ConverterUtil.convertToGMonth(value);
                Calendar calendar = Calendar.getInstance();
                calendar.clear();
                calendar.set(Calendar.MONTH, month.getMonth());
                String timezone = month.getTimezone();
                if (timezone != null) {
                    calendar.setTimeZone(TimeZone.getTimeZone(timezone));
                }
                return engine.getCx().newObject(engine, "Date", new Object[] { new Long(calendar.getTimeInMillis()) });
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "month"));
            }
        }
        if (Constants.XSD_DAY.equals(type)) {
            try {
                Day day = ConverterUtil.convertToGDay(value);
                Calendar calendar = Calendar.getInstance();
                calendar.clear();
                calendar.set(Calendar.DAY_OF_MONTH, day.getDay());
                String timezone = day.getTimezone();
                if (timezone != null) {
                    calendar.setTimeZone(TimeZone.getTimeZone(timezone));
                }
                return engine.getCx().newObject(engine, "Date", new Object[] { new Long(calendar.getTimeInMillis()) });
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "day"));
            }
        }
        if (Constants.XSD_DURATION.equals(type)) {
            try {
                Duration duration = ConverterUtil.convertToDuration(value);
                return duration.toString();
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "duration"));
            }
        }
        if (Constants.XSD_QNAME.equals(type)) {
            try {
                int index = value.indexOf(":");
                String prefix = "";
                if (index > -1) {
                   prefix = value.substring(0, index);
                    value = value.substring(index+1);
                }
                OMNamespace namespace = omElement.findNamespaceURI(prefix);
                String namespaceURI = null;
                if (namespace != null) {
                    namespaceURI = namespace.getNamespaceURI();
                }
                Scriptable e4xNamespace = null;
                if (namespaceURI != null) {
                    Object[] namespaceObjects = { prefix,
                            namespaceURI };
                    e4xNamespace =
                            engine.getCx().newObject(engine, "Namespace", namespaceObjects);
                }
                Object[] qnameObjects = { e4xNamespace,
                        value };
                return engine.getCx().newObject(engine, "QName", qnameObjects);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "string"));
            }
        }
        if (Constants.XSD_HEXBIN.equals(type)) {
            try {
                return ConverterUtil.convertToString(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "hexBinary"));
            }
        }
        if (Constants.XSD_BASE64.equals(type)) {
            try {
                return ConverterUtil.convertToString(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "base64Binary"));
            }
        }
        return omElement.getText();
    }

    /**
     * Creates an array object that can be passed into a JS function
     *
     * @param iterator - Iterator to the omelements that belong to the array
     * @param type     - The schematype of the omelement
     * @param engine   Reference to the javascript engine
     * @return - An array Object that can be passed into a JS function
     * @throws AxisFault - In case an exception occurs
     */
    private Object handleArray(Iterator iterator, QName type, JavaScriptEngine engine)
            throws AxisFault {
        ArrayList objectList = new ArrayList();
        while (iterator.hasNext()) {
            OMElement omElement = (OMElement) iterator.next();
            objectList.add(createParam(omElement, type, engine));
        }
        int length = objectList.size();
        NativeArray nativeArray = new NativeArray(0);
        for (int i = 0; i < length; i++) {
            nativeArray.put(i, nativeArray, objectList.get(i));
        }
        return nativeArray;
    }

    /**
     * Extracts and returns the name of the JS function associated for the
     * currently dispatched operation. First we try to retrieve the function
     * name vis the JS_FUNCTION_NAME parameter of the AxisOperation. If not we
     * assume the localpart of the operation name to be the function name.
     *
     * @param inMessage MessageContext object with information about the incoming
     *                  message
     * @return the name of the requested JS function
     * @throws AxisFault if the function name cannot be inferred.
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
     *                   implementation is not available
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

    private OMElement buildResponse(boolean annotated, boolean json, Object result,
                                    XmlSchemaElement innerElement) throws AxisFault {
        if (json) {
            result = ((String) result).substring(1, ((String) result).length() - 1);
            InputStream in = new ByteArrayInputStream(((String) result).getBytes());
            JSONOMBuilder builder = new JSONOMBuilder();
            return builder.processDocument(in, null, null);
        }
        // Convert the JS return to XML

        // Check whether the innerElement is null.
        if (innerElement != null) {
            return createResponseElement(result, innerElement.getName(), !annotated);
        } else {

            // wrap the response in a wrapper element called return. If the wrapper contains an OMElemet return the
            // OMElement (There is no use in the wrapper). 
            // There are occations when the function returns a js type which is not XML.
            // Therefore we need the wrapper element tp wrap it. What if the service returned null? just return null.
            OMElement element = createResponseElement(result, "return", !annotated);
            OMElement omElement = element.getFirstElement();
            if (omElement == null) {
                String elementText = element.getText();
                if (elementText == null || "".equals(elementText)) {
                    return null;
                }
                return element;
            } else if (omElement.getNextOMSibling() != null) {
                return element;
            } else {
                return omElement;
            }
        }
    }

    /**
     * Given a jsObject converts it to corresponding OMElement
     *
     * @param jsObject    - The object that needs to be converted
     * @param elementName - The element name of the wrapper
     * @param addTypeInfo - Whether type information should be added into the element as an attribute
     * @return - OMelement which represents the JSObject
     * @throws AxisFault - Thrown in case an exception occurs during the conversion
     */
    private OMElement createResponseElement(Object jsObject, String elementName,
                                            boolean addTypeInfo) throws AxisFault {
        String className = jsObject.getClass().getName();
        OMFactory fac = OMAbstractFactory.getOMFactory();
        OMNamespace namespace = fac.createOMNamespace("http://www.wso2.org/ns/jstype", "js");
        OMNamespace xsiNamespace = fac.createOMNamespace("http://www.w3.org/2001/XMLSchema-instance", "xsi");
        OMNamespace xsNamespace = fac.createOMNamespace("http://www.w3.org/2001/XMLSchema", "xs");
        OMElement element = fac.createOMElement(elementName, null);
        // Get the OMNode inside the jsObjecting object
        if (jsObject instanceof XML) {
            element.addChild((((XML) jsObject).getAxiomFromXML()));
            if (addTypeInfo) {
                element.addAttribute("type", "xml", namespace);
                element.declareNamespace(xsNamespace);
                element.addAttribute("type", "xs:anyType", xsiNamespace);
            }
        } else if (jsObject instanceof XMLList) {
            XMLList list = (XMLList) jsObject;
            OMNode[] omNodes = list.getAxiomFromXML();
            if (omNodes.length == 0) {
                return element;
            } else if (omNodes.length == 1) {

                // If the XMLList returned has only one child we annotate it as XML
                element.addChild(omNodes[0]);
                if (addTypeInfo) {
                    element.addAttribute("type", "xml", namespace);
                    element.declareNamespace(xsNamespace);
                    element.addAttribute("type", "xs:anyType", xsiNamespace);
                }
            } else {
                for (int i = 0; i < omNodes.length; i++) {
                    element.addChild(omNodes[i]);
                }
                if (addTypeInfo) {
                    element.addAttribute("type", "xmlList", namespace);
                    element.declareNamespace(xsNamespace);
                    element.addAttribute("type", "xs:anyType", xsiNamespace);
                }
            }
        } else {

            if (jsObject instanceof String) {
                element.setText((String) jsObject);
                if (addTypeInfo) {
                    element.addAttribute("type", "string", namespace);
                    element.declareNamespace(xsNamespace);
                    element.addAttribute("type", "xs:string", xsiNamespace);
                }
            } else if (jsObject instanceof Boolean) {
                Boolean booljsObject = (Boolean) jsObject;
                element.setText(booljsObject.toString());
                if (addTypeInfo) {
                    element.addAttribute("type", "boolean", namespace);
                    element.declareNamespace(xsNamespace);
                    element.addAttribute("type", "xs:boolean", xsiNamespace);
                }
            } else if (jsObject instanceof Number) {
                Number numjsObject = (Number) jsObject;
                String str = numjsObject.toString();
                if (str.indexOf("Infinity") >= 0) {
                    str = str.replace("Infinity", "INF");
                }
                element.setText(str);
                if (addTypeInfo) {
                    element.addAttribute("type", "number", namespace);
                    element.addAttribute("type", "xs:double", xsiNamespace);
                    element.declareNamespace(xsNamespace);
                }
            } else
            if (jsObject instanceof Date || "org.mozilla.javascript.NativeDate".equals(className)) {
                Date date = (Date) Context.jsToJava(jsObject, Date.class);
                Calendar calendar = Calendar.getInstance();
                calendar.clear();
                calendar.setTime(date);
                String dateTime = ConverterUtil.convertToString(calendar);
                element.setText(dateTime);
                if (addTypeInfo) {
                    element.addAttribute("type", "date", namespace);
                    element.addAttribute("type", "xs:dateTime", xsiNamespace);
                    element.declareNamespace(xsNamespace);
                }
            } else if (jsObject instanceof NativeArray) {
                element.addAttribute("type", "array", namespace);
                element.declareNamespace(xsiNamespace);
                element.declareNamespace(xsNamespace);
                NativeArray nativeArray = (NativeArray) jsObject;
                Object[] objects = nativeArray.getAllIds();
                for (int i = 0; i < objects.length; i++) {
                    Object object = objects[i];
                    Object o;
                    String propertyElementName;
                    if (object instanceof String) {
                        String property = (String) object;
                        if ("length".equals(property)) {
                            continue;
                        }
                        o = nativeArray.get(property, nativeArray);
                        propertyElementName = property;
                    } else {
                        Integer property = (Integer) object;
                        o = nativeArray.get(property.intValue(), nativeArray);
                        propertyElementName = "item";
                    }
                    OMElement paramElement = createResponseElement(o, propertyElementName, true);
                    element.addChild(paramElement);
                }
            } else if (jsObject instanceof Object[]) {
                element.addAttribute("type", "array", namespace);
                element.declareNamespace(xsiNamespace);
                element.declareNamespace(xsNamespace);
                Object[] objects = (Object[]) jsObject;
                for (int i = 0; i < objects.length; i++) {
                    Object object = objects[i];
                    OMElement paramElement = createResponseElement(object, "item", true);
                    element.addChild(paramElement);
                }
            } else if (jsObject instanceof NativeObject) {
                element.addAttribute("type", "object", namespace);
                element.declareNamespace(xsiNamespace);
                element.declareNamespace(xsNamespace);
                NativeObject nativeObject = (NativeObject) jsObject;
                Object[] objects = NativeObject.getPropertyIds(nativeObject);
                for (int i = 0; i < objects.length; i++) {
                    Object object = objects[i];
                    Object o;
                    if (object instanceof String) {
                        String property = (String) object;
                        o = nativeObject.get(property, nativeObject);
                        OMElement paramElement = createResponseElement(o, property, true);
                        element.addChild(paramElement);
                    }
                }
            } else if (jsObject instanceof Undefined || jsObject instanceof UniqueTag) {
                if (addTypeInfo) {
                    element.addAttribute("type", "undefined", namespace);
                }
            }
        }
        return element;
    }

    private String getFaultString(String value, String type) {
        return "Unable to convert value \"" + value + "\" to " + type;
    }
}