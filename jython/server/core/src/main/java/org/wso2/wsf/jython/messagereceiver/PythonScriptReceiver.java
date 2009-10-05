/*
 * Copyright 2008 WSO2, Inc. http://www.wso2.org
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

package org.wso2.wsf.jython.messagereceiver;

import org.apache.axis2.receivers.AbstractInOutMessageReceiver;
import org.apache.axis2.context.MessageContext;
import org.apache.axis2.AxisFault;
import org.apache.axis2.databinding.utils.ConverterUtil;
import org.apache.axis2.databinding.types.*;
import org.apache.axis2.wsdl.WSDLConstants;
import org.apache.axis2.i18n.Messages;
import org.apache.axis2.description.AxisOperation;
import org.apache.axis2.description.AxisService;
import org.apache.axis2.description.Parameter;
import org.apache.axis2.description.AxisMessage;
import org.apache.axis2.engine.MessageReceiver;
import org.apache.axiom.soap.*;
import org.apache.axiom.om.*;
import org.apache.axiom.om.impl.builder.StAXOMBuilder;
import org.apache.ws.commons.schema.*;
import org.apache.ws.commons.schema.constants.Constants;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.namespace.QName;
import java.io.*;
import java.util.*;

import org.python.core.*;

public class PythonScriptReceiver extends AbstractInOutMessageReceiver implements MessageReceiver {
    private static final Log log = LogFactory.getLog(PythonScriptReceiver.class);

    public void invokeBusinessLogic(MessageContext inMessage, MessageContext outMessage) throws AxisFault {
        SOAPEnvelope soapEnvelope = inMessage.getEnvelope();
        try {
            String pMethod = null;
            String pArgs = null;
            try {
                pMethod = getPythonMethod(inMessage);
                pArgs = getArgs(inMessage);
            } catch (XMLStreamException e) {
                throw new AxisFault(e.getMessage());
            }
            String pReader = readPythonScript(inMessage);

            if (pReader == null) {
                throw new AxisFault("Unable to load Python file");
            }
            if (pMethod == null) {
                throw new AxisFault("Unable to read the method");
            }

            OMElement payload = soapEnvelope.getBody().getFirstElement();
            Object args = payload;
            if (payload != null) {
                // We neet to get the Axis Message from the incomming message so that we can get its schema.
                // We need the schema in order to unwrap the parameters.
                AxisMessage axisMessage = inMessage.getAxisOperation().getMessage(
                        WSDLConstants.MESSAGE_LABEL_IN_VALUE);
                XmlSchemaElement xmlSchemaElement = axisMessage.getSchemaElement();
                if (xmlSchemaElement != null) {
                    // Once the schema is obtained we iterate through the schema looking for the elemants in the payload.
                    // for Each element we extract its value and create a parameter which can be passed into the
                    // pythonscript function.
                    XmlSchemaType schemaType = xmlSchemaElement.getSchemaType();
                    if (schemaType instanceof XmlSchemaComplexType) {
                        XmlSchemaComplexType complexType = ((XmlSchemaComplexType) schemaType);
                        List<Object> params = handleComplexTypeInRequest(complexType, payload, new ArrayList<String>());
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

            //Setting up the out message 
            AxisMessage outAxisMessage = inMessage.getAxisOperation().getMessage(
                    WSDLConstants.MESSAGE_LABEL_OUT_VALUE);
            boolean annotated = false;
            Parameter parameter = outAxisMessage.getParameter(PythonScriptEngineConstants.ANNOTATED);
            if (parameter != null) {
                annotated = (Boolean) parameter.getValue();
            }
            // ------------ annotated = true is done for a test . delete it after the proj is finished!
            annotated = true;

            Object response = PythonScriptEngine.invoke(pMethod, pReader, (java.lang.Object[]) (args));
            if (log.isDebugEnabled()) {
                log.debug("object returned from jython : " + response);
            }

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
                            false);
                    body.addChild(outElement);
                } else if (xmlSchemaElement.getSchemaTypeName() == Constants.XSD_ANYTYPE) {
                    if (!PythonScriptEngine.isNull(response)) {
                        // If its anyType that means we have to add xsi:type
                        OMElement element = buildResponse(false, response,
                                xmlSchemaElement);
                        if (element != null) {
                            body.addChild(element);
                        }
                    }
                }
            } else if (!PythonScriptEngine.isNull(response)) {
                OMElement element =
                        buildResponse(annotated, response, xmlSchemaElement);
                if (log.isDebugEnabled()) {
                    log.debug("The built element is " + element.toString());
                }
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
            fault.setFaultCode(SOAP12Constants.SOAP_ENVELOPE_NAMESPACE_URI.equals(soapEnvelope.getNamespace().getNamespaceURI())
                    ? SOAP12Constants.SOAP_DEFAULT_NAMESPACE_PREFIX + ":" + SOAP12Constants
                    .FAULT_CODE_RECEIVER
                    : SOAP12Constants.SOAP_DEFAULT_NAMESPACE_PREFIX + ":" + SOAP11Constants
                    .FAULT_CODE_RECEIVER);
            throw fault;
        }

    }

    /**
     * @param str The string to embed in the OMElement
     * @return an OMElement
     * @throws javax.xml.stream.XMLStreamException
     *
     */
    private OMElement getpayLoad(String str) throws XMLStreamException {
        XMLStreamReader xmlReader =
                XMLInputFactory.newInstance().createXMLStreamReader(
                        new ByteArrayInputStream(str.getBytes()));
        OMFactory fac = OMAbstractFactory.getOMFactory();
        StAXOMBuilder staxOMBuilder =
                new StAXOMBuilder(fac, xmlReader);
        return staxOMBuilder.getDocumentElement();
    }

    /**
     * @param inMessage
     * @return the pythonscript message to invoke
     * @throws AxisFault
     * @throws XMLStreamException
     */
    public String getPythonMethod(MessageContext inMessage) throws AxisFault, XMLStreamException {
        //Look at the method name. if available this should be a pythonscript method
        AxisOperation op = inMessage.getOperationContext().getAxisOperation();
        if (op == null) {
            throw new AxisFault(Messages.getMessage("notFound", "Operation"));
        }
        return op.getName().getLocalPart();
    }

    /**
     * @param inMessage
     * @return the pythonscript source file
     * @throws AxisFault
     */
    public String readPythonScript(MessageContext inMessage) throws AxisFault {
        AxisService service = inMessage.getAxisService();
        Parameter implInfoParam = service.getParameter(PythonScriptEngineConstants.PYTHON_SCRIPT);

// HERE I am changing the code to suit my sample--------------------------------
//        Parameter implInfoParam = service.getParameter("ServiceScript");
        if (implInfoParam == null) {
            throw new AxisFault(Messages.getMessage("Parameter is not specified", PythonScriptEngineConstants.PYTHON_SCRIPT));
        }
        //InputStream jsFileStream = service.getClassLoader().getResourceAsStream(implInfoParam.getValue().toString());
        String fileName = implInfoParam.getValue().toString();

        if (fileName == null) {
            throw new AxisFault(Messages.getMessage("PythonScriptUnableToLoad", implInfoParam.getValue().toString()));
        }
        return fileName;
    }

    /**
     * Locates the service pythonscript file associated with ServiceJS parameter and returns
     * a Reader for it.
     *
     * @param inMessage MessageContext object with information about the incoming message
     * @return an input stream to the pythonscript source file
     * @throws AxisFault if the parameter ServiceJS is not specified or if the service
     *                   implementation is not available
     */
    private Reader readJS(MessageContext inMessage) throws AxisFault {
        InputStream jsFileStream;
        AxisService service = inMessage.getServiceContext().getAxisService();
        Parameter implInfoParam = service.getParameter("PythonScript");
        if (implInfoParam == null) {
            throw new AxisFault("Parameter 'PythonScript' not specified");
        }
        if (implInfoParam.getValue() instanceof File) {
            try {
                jsFileStream = new FileInputStream((File) (implInfoParam.getValue()));
            } catch (FileNotFoundException e) {
                throw new AxisFault("Unable to load the pythonscript, File not Found", e);
            }
        } else {
            jsFileStream = service.getClassLoader().getResourceAsStream(
                    implInfoParam.getValue().toString());
        }
        if (jsFileStream == null) {
            throw new AxisFault("Unable to load the pythonscript");
        }
        return new BufferedReader(new InputStreamReader(jsFileStream));
    }

    /**
     * @param inMessage
     * @return arguments to be sent to the pythonscript function
     * @throws XMLStreamException
     */
    public String getArgs(MessageContext inMessage) throws XMLStreamException {

        String args = inMessage.getEnvelope().getBody().getFirstElement().getText();
        //String value = firstChild.toStringWithConsume();
        if (args != null) {
            return args;
        }
        return null;

    }

    private List<Object> handleComplexTypeInRequest(XmlSchemaComplexType complexType, OMElement payload,
                                            List<String> paramNames)
            throws AxisFault {
        XmlSchemaParticle particle = complexType.getParticle();
        List<Object> params = new ArrayList<Object>();
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
                    List<String> innerParamNames = new ArrayList<String>();
                    List<Object> innerParams = handleComplexTypeInRequest((XmlSchemaComplexType) schemaType,
                            complexTypePayload,
                            innerParamNames);
                } else if (schemaType instanceof XmlSchemaSimpleType) {
                    // Handle enumerations in here.
                    XmlSchemaSimpleType xmlSchemaSimpleType = (XmlSchemaSimpleType) schemaType;
                    XmlSchemaSimpleTypeContent content = xmlSchemaSimpleType.getContent();
                    if (content instanceof XmlSchemaSimpleTypeRestriction) {
                        // TODO: This feature will also be implemented in the future

                    } else {
                        throw new AxisFault("Unsupported restriction in Schema");
                    }
                } else {
                    params.add(handleSimpleTypeInRequest(payload, innerElement));
                    paramNames.add(innerElement.getName());
                }
            }
        } else {
            throw new AxisFault("Unsupported schema type in request");
        }
        return params;
    }

    private Object handleSimpleTypeInRequest(OMElement payload, XmlSchemaElement innerElement) throws AxisFault {
        long maxOccurs = innerElement.getMaxOccurs();
        // Check whether the schema advertises this element as an array
        if (maxOccurs > 1) {
            // If its an array get all elements with that name and create a sinple parameter out of it
            String innerElemenrName = innerElement.getName();
            Iterator iterator1 = payload.getChildrenWithName(new QName(
                    innerElemenrName));
            return handleArray(iterator1, innerElement.getSchemaTypeName());
        } else {
            return handleSimpleElement(payload, innerElement.getName(),
                    innerElement.getMinOccurs(),
                    innerElement.getSchemaTypeName());
        }
    }


    /**
     * Creates an array object that can be passed into a JS function
     *
     * @param iterator - Iterator to the omelements that belong to the array
     * @param type     - The schematype of the omelement
     *                 //@param engine   Reference to the pythonscript engine
     * @return - An array Object that can be passed into a JS function
     * @throws AxisFault - In case an exception occurs
     */
    private Object handleArray(Iterator iterator, QName type)
            throws AxisFault {
        ArrayList objectList = new ArrayList();
        while (iterator.hasNext()) {
            OMElement omElement = (OMElement) iterator.next();
            objectList.add(createParam(omElement, type));
        }
        return objectList;
    }


    /**
     * Creates an object that can be passed into a pythonscript function from an OMElement.
     *
     * @param omElement - The OMElement that the parameter should be created for
     * @param type      - The schemaType of the incoming message element
     *                  //@param engine    - Reference to the pythonscript engine
     * @return - An Object that can be passed into a Py function
     * @throws AxisFault - In case an exception occurs
     */
    private Object createParam(OMElement omElement, QName type)
            throws AxisFault {
        if (log.isDebugEnabled()) {
            log.debug("QName type of the parameter : " + type.toString());
        }

        if (Constants.XSD_ANYTYPE.equals(type)) {

        }
        String value = omElement.getText();
        if (value == null) {
            throw new AxisFault(
                    "The value of Element " + omElement.getLocalName() + " cannot be null");
        }
        if (Constants.XSD_BOOLEAN.equals(type)) {
            try {
                return ConverterUtil.convertToBoolean(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "boolean"));
            }
        }
        if (Constants.XSD_DOUBLE.equals(type)) {
            try {
                return ConverterUtil.convertToDouble(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "double"));
            }
        }
        if (Constants.XSD_FLOAT.equals(type)) {
            try {
                return ConverterUtil.convertToFloat(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "float"));
            }
        }
        if (Constants.XSD_INT.equals(type)) {
            try {
                return ConverterUtil.convertToInt(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "int"));
            }
        }
        if (Constants.XSD_INTEGER.equals(type)) {
            try {
                if ((value == null) || value.equals("")) {
                    return Integer.MIN_VALUE;
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
                return ConverterUtil.convertToLong(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "long"));
            }
        }
        if (Constants.XSD_SHORT.equals(type)) {
            try {
                return ConverterUtil.convertToShort(value);
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "short"));
            }
        }
        if (Constants.XSD_BYTE.equals(type)) {
            try {
                return ConverterUtil.convertToByte(value);
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
        if (Constants.XSD_DURATION.equals(type)) {
            try {
                Duration duration = ConverterUtil.convertToDuration(value);
                return duration.toString();
            } catch (Exception e) {
                throw new AxisFault(getFaultString(value, "duration"));
            }
        }
        if (Constants.XSD_QNAME.equals(type)) {

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


    private String getFaultString(String value, String type) {
        return "Unable to convert value \"" + value + "\" to " + type;
    }


    private boolean checkRequired(XmlSchemaElement innerElement, Object object) throws AxisFault {
        if (PythonScriptEngine.isNull(object)) {
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


    private void handleComplexTypeInResponse(XmlSchemaComplexType complexType, OMElement outElement,
                                             Object response,
                                             OMFactory fac,
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
                    Object object = response;

                    if (checkRequired(innerElement, object)) {
                        continue;
                    }
                    XmlSchemaComplexType innerComplexType = (XmlSchemaComplexType) schemaType;
                    OMElement complexTypeElement =
                            fac.createOMElement(name, outElement.getNamespace());
                    outElement.addChild(complexTypeElement);

                    handleComplexTypeInResponse(innerComplexType, complexTypeElement, object, fac,
                            true);
                } else {
                    Object object = response;
                    if (isInnerParam || count > 1) {

                    } else {
                        object = response;
                    }
                    if (checkRequired(innerElement, object)) {
                        if (innerElement.getSchemaTypeName() != Constants.XSD_ANYTYPE) {
                            continue;
                        }
                    }
                    handleSimpleTypeinResponse(innerElement, object, fac,
                            outElement);
                }
            }
        } else {
            throw new AxisFault("Unsupported schema type in response.");
        }
    }


    private void handleSimpleTypeinResponse(XmlSchemaElement innerElement, Object pyObject,
                                            OMFactory factory,
                                            OMElement outElement) throws AxisFault {
        long maxOccurs = innerElement.getMaxOccurs();
        if (maxOccurs > 1 && !innerElement.getSchemaTypeName().equals(Constants.XSD_ANYTYPE)) {
            if (pyObject instanceof Object[]) {
                Object[] objects = (Object[]) pyObject;
                for (Object object : objects) {
                    outElement.addChild(handleSchemaTypeinResponse(innerElement, object,
                            factory));
                }
            } else {
                outElement.addChild(handleSchemaTypeinResponse(innerElement, pyObject, factory));
            }
            return;
        }
        outElement.addChild(
                handleSchemaTypeinResponse(innerElement, pyObject, factory));
    }

    private OMElement buildResponse(boolean annotated, Object result,
                                    XmlSchemaElement innerElement) throws AxisFault {
        // Check whether the innerElement is null.
        if (innerElement != null) {
            return createResponseElement(result, innerElement.getName(), !annotated);
        } else {

            // wrap the response in a wrapper element called return. If the wrapper contains an OMElemet return the
            // OMElement (There is no use in the wrapper).
            // There are occations when the function returns a py type which is not XML.
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
     * Given pyObject is converted to corresponding OMElement
     *
     * @param pyObject    - The object that needs to be converted
     * @param elementName - The element name of the wrapper
     * @param addTypeInfo - Whether type information should be added into the element as an attribute
     * @return - OMelement which represents the pyObject
     * @throws AxisFault - Thrown in case an exception occurs during the conversion
     */
    private OMElement createResponseElement(Object pyObject, String elementName,
                                            boolean addTypeInfo) throws AxisFault {
        //String className = pyObject.getClass().getName();
        OMFactory fac = OMAbstractFactory.getOMFactory();
        //OMNamespace namespace = fac.createOMNamespace("http://www.wso2.org/ns/py    type", "py");
        OMNamespace xsiNamespace = fac.createOMNamespace("http://www.w3.org/2001/XMLSchema-instance", "xsi");
        OMNamespace xsNamespace = fac.createOMNamespace("http://www.w3.org/2001/XMLSchema", "xs");
        OMElement element = fac.createOMElement(elementName, null);

        // Get the OMNode inside the pyObjecting object
        if (pyObject instanceof PyString) {
            element.setText((String) pyObject);
            if (addTypeInfo) {
                element.declareNamespace(xsNamespace);
                element.addAttribute("type", "xs:string", xsiNamespace);
            }
        } else if (pyObject instanceof PyInteger) {
            element.setText(pyObject.toString());
            if (addTypeInfo) {
                element.declareNamespace(xsNamespace);
                element.addAttribute("type", "xs:integer", xsiNamespace);
            }
        } else if (pyObject instanceof PyFloat) {
            element.setText(pyObject.toString());
            if (addTypeInfo) {
                element.declareNamespace(xsNamespace);
                element.addAttribute("type", "xs:float", xsiNamespace);
            }
        } else if (pyObject instanceof PyLong) {
            element.setText(pyObject.toString());
            if (addTypeInfo) {
                element.declareNamespace(xsNamespace);
                element.addAttribute("type", "xs:long", xsiNamespace);
            }
        } else if (pyObject instanceof PyList) {
            String strXml = "<List>";
            String st[];
            st = pyObject.toString().substring(1, pyObject.toString().length() - 1).split(",");
            for (int i = 0; i < st.length; i++) {
                strXml = strXml + "<" + i + ">" + st[i] + "</" + i + ">";
            }
            strXml = strXml + "</List>";
            strXml = strXml.replaceAll("'", "");
            strXml = strXml.replaceAll(" ", "");
            element.setText(strXml);
            if (addTypeInfo) {
                element.declareNamespace(xsNamespace);
                element.addAttribute("type", "xs:anyType", xsiNamespace);
            }
        } else if (pyObject instanceof PyTuple) {
            String strXml = "<Tuple>";
            String st[];
            st = pyObject.toString().substring(1, pyObject.toString().length() - 1).split(",");
            for (int i = 0; i < st.length; i++) {
                strXml = strXml + "<" + i + ">" + st[i] + "</" + i + ">";
            }
            strXml = strXml + "</Tuple>";
            element.setText(strXml);
            if (addTypeInfo) {
                element.declareNamespace(xsNamespace);
                element.addAttribute("type", "xs:anyType", xsiNamespace);
            }
        } else if (pyObject instanceof PyDictionary) {
            String strXml = "<Dictionary>";
            String st[], stTemp[];
            st = pyObject.toString().substring(1, pyObject.toString().length() - 1).split(",");
            for (String aSt : st) {
                stTemp = aSt.split(":");
                strXml = strXml + "<" + stTemp[0] + ">" + stTemp[1] + "</" + stTemp[0] + ">";
            }
            strXml = strXml + "</Dictionary>";
            strXml = strXml.replaceAll(" ", "");
            strXml = strXml.replaceAll("'", "");
            element.setText(strXml);
            if (addTypeInfo) {
                element.declareNamespace(xsNamespace);
                element.addAttribute("type", "xs:anyType", xsiNamespace);
            }
        }
        return element;
    }


    private OMElement handleSchemaTypeinResponse(XmlSchemaElement innerElement, Object pyObject,
                                                 OMFactory factory)
            throws AxisFault {
        QName qName = innerElement.getSchemaTypeName();
        OMElement element = factory.createOMElement(innerElement.getName(), null);
        if (qName.equals(Constants.XSD_ANYTYPE)) {
            if (PythonScriptEngine.isNull(pyObject)) {
                return element;
            }
            // need to set annotated as false cause we need to set xsi:type
            return buildResponse(false, pyObject, innerElement);
        }
        if (qName.equals(Constants.XSD_INTEGER)) {
            String str = PyToOMConverter.convertToInteger(pyObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_INT)) {
            String str = PyToOMConverter.convertToInt(pyObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_FLOAT)) {
            String str = PyToOMConverter.convertToFloat(pyObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_LONG)) {
            String str = PyToOMConverter.convertToLong(pyObject);
            element.setText(str);
            return element;
        }
        if (qName.equals(Constants.XSD_STRING)) {
            String str = PyToOMConverter.convertToString(pyObject);
            element.setText(str);
            return element;
        }
        element.setText(pyObject.toString());
        return element;
    }


    private Object handleSimpleElement(OMElement payload,
                                       String innerElementName, long minOccurs, QName schemaType)
            throws AxisFault {
        QName payloadQname = payload.getQName();
        OMElement omElement = null;
        QName qName;
        // When retrieving elements we have to look for the namespace too. There may be
        // Occations even when the children are namespace qualified. In such situations
        // we should retrieve them using that namespace.
        // If that fails we try using the localname only.
        if (payloadQname != null) {
            qName = new QName(payloadQname.getNamespaceURI(),
                    innerElementName);
            omElement = payload.getFirstChildWithName(qName);
        }
        if (omElement == null) {
            qName = new QName(innerElementName);
            omElement = payload.getFirstChildWithName(qName);
        }
        if (omElement == null) {
            // There was no such element in the payload. Therefore we check for minoccurs
            // and if its 0 add null as a parameter (If not we might mess up the parameters
            // we pass into the function).
            if (minOccurs == 0) {
                //return Undefined.instance;
                return null;
            } else {
                // If minoccurs is not zero throw an exception.
                // Do we need to di strict schema validation?
                throw new AxisFault(
                        "Required element " + innerElementName
                                + " defined in the schema can not be found in the request");
            }
        }
        return createParam(omElement, schemaType);
    }


}
