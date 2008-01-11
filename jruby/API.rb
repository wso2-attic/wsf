include Java


Dir[ENV['AXIS2_HOME'] + '/lib/*.jar'].each{|j| require j}




OMAbstractFactory = org.apache.axiom.om.OMAbstractFactory
OMElement = org.apache.axiom.om.OMElement
OMFactory = org.apache.axiom.om.OMFactory
OMNamespace = org.apache.axiom.om.OMNamespace
EndpointReference = org.apache.axis2.addressing.EndpointReference
Options = org.apache.axis2.client.Options
ServiceClient = org.apache.axis2.client.ServiceClient
OMNs = org.apache.axiom.om.impl.llom.factory.OMLinkedListImplFactory
OMNAS = org.apache.axiom.om.impl.llom.factory.OMXMLBuilderFactory
StAXOMBuilder =  org.apache.axiom.om.impl.builder.StAXOMBuilder
OMTextImpl = org.apache.axiom.om.impl.llom.OMTextImpl
ByteArrayInputStream = java.io.ByteArrayInputStream
XMLStreamException = javax.xml.stream.XMLStreamException
Java_String = java.lang.String
StringBufferInputStream = java.io.StringBufferInputStream
Constants = org.apache.axis2.Constants
Boolean = java.lang.Boolean
HTTPConstants = org.apache.axis2.transport.http.HTTPConstants
HttpTransportProperties = org.apache.axis2.transport.http.HttpTransportProperties
QName = javax.xml.namespace.QName
ConfigurationContext = org.apache.axis2.context.ConfigurationContext
ConfigurationContextFactory = org.apache.axis2.context.ConfigurationContextFactory
WSPasswordCallback = org.apache.ws.security.WSPasswordCallback
Callback = javax.security.auth.callback.Callback;
CallbackHandler = javax.security.auth.callback.CallbackHandler;
ServiceContext = org.apache.axis2.context.ServiceContext
Java_Array = java.lang.reflect.Array


