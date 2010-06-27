<?php
/*
 * Copyright (c) 2005-2010 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

define("WSF_WSDL", "wsdl");
define("WSF_HTTP_AUTH_USERNAME","httpAuthUsername");
define ("WSF_HTTP_AUTH_PASSWORD","httpAuthPassword");
define ("WSF_HTTP_AUTH_DIGEST","Digest");
define ("WSF_HTTP_AUTH_BASIC","Basic");
define ("WSF_HTTP_AUTH_TYPE","httpAuthType");
define("WSF_ENDPOINT", "endpoint");
define("WSF_INVOKE_FUNCTION", "invoke_function");
define("WSF_ARG_COUNT", "arg_count");
define("WSF_ARG_ARRAY", "arg_array");
define("WSF_SIGNATURE", "signature");
define("WSF_METHOD", "method");
define("WSF_INFERENCE", "inference");
define("WSF_RPC", "rpc");
define("WSF_RPC_ENCODED", "rpc-enc");
define("WSF_DOCLIT", "doclit");
define("WSF_ENDPOINT_URI", "endpoint_uri");
define("WSF_BINDING_DETAILS", "binding_details");
define("WSF_W2P_BINDING_DETAILS", "binding-details");
define("WSF_REQUEST_PAYLOAD", "request_payload");
define("WSF_POLICY_NODE", "policy_node");
define("WSF_POLICIES", "policies");
define("WSF_SERVICE_NAME", "serviceName");
define("WSF_PORT_NAME", "portName");
define("WSF_USE_MTOM", "useMTOM");

define("WSF_DEFINITION", "definitions");
define("WSF_DESCRIPTION", "description");
define("WSF_OPERATIONS", "operations");
define("WSF_OPERATION" , "operation");
define("WSF_ADDRESS", "address");
define("WSF_NAME" , "name");
define("WSF_TYPE", "type");
define("WSF_MAX_OCCURS", "maxOccurs");
define("WSF_MIN_OCCURS", "minOccurs");
define("WSF_TYPE_REP", "type_rep");
define("WSF_ID", "Id");
define("WSF_SERVICE", "service");
define("WSF_CLIENT", "client");
define("WSF_BINDING", "binding");
define("WSF_POLICY_REFERENCE", "PolicyReference");
define("WSF_POLICY", "Policy");
define("WSF_REF", "ref");
define("WSF_URI", "URI");
define("WSF_PARAMS", "params");
define("WSF_PARAM" , "param");
define("WSF_WRAPPER_ELEMENT", "wrapper-element");
define("WSF_WRAPPER_ELEMENT_NS", "wrapper-element-ns");
define("WSF_TARGETNAMESPACE", "targetNamespace");
define("WSF_BINDINDG_DETAILS", "binding-details");
define("WSF_WSAWAACTION", "wsawaction");
define("WSF_SOAPACTION", "soapaction");
define("WSF_HTTPMETHOD", "httpmethod");
define("WSF_USE_SOAP", "usesoap");
define("WSF_WSA", "wsa");
define("WSF_SOAP", "soap");
define("WSF_SOAP11", "SOAP11");
define("WSF_SOAP12", "SOAP12");
define("WSF_SOAP_VERSION", "soap_version");
define("WSF_RETURNS", "returns");
define("WSF_RESPONSE_SIG_MODEL", "response_sig_model");
define("WSF_IS_MULTI_INTERFACES", "is_multiple_interfaces");
define("WSF_SIG_MODEL_STRING", "sig_model_string");
define("WSF_IS_WSDL_11", "is_wsdl_11");
define("WSF_PAYLOAD_STRING", "payload_string");
define("WSF_OPERATION_NAME", "operation_name");
define("WSF_FUNCTION_NAME", "function_name");
define("WSF_CLASS_NAME", "class_name");
define("WSF_CLASS_ARGS", "class_args");
define("WSF_ATTACHMENTS", "attachments");
define("WSF_CID2CONTENT_TYPE", "cid2contentType");
define("WSF_ENVELOPE", "envelope");
define("WSF_BODY", "body");
define("WSF_TYPE_NAMESPACE", "type-namespace");
define("WSF_CLASSMAP", "classmap");
define("WSF_NS", "ns");
define("WSF_TYPE_NS", "type_ns");
define("WSF_TNS", "tns");
define("WSF_PORT", "port");
define("WSF_LOCATION", "location");
define("WSF_XSLT_LOCATION", "xslt_location");
define("WSF_TYPES", "types");
define("WSF_SCHEMA", "schema");
define("WSF_ELEMENT", "element");
define("WSF_LIST", "list");
define("WSF_UNION", "union");
define("WSF_WSDL_DOM", "wsdl_dom");
define("WSF_WSDL_SIMPLE", "simple");
define("WSF_WSDL_COMPLEX_TYPE", "complexType");
define("WSF_WSDL_PORT_TYPE", "portType");
define("WSF_WSDL_MESSAGE", "message");
define("WSF_WSDL_INPUT", "input");
define("WSF_WSDL_OUTPUT", "output");
define("WSF_WSDL_PART", "part");

define("WSF_WSDL1TO2_XSL_LOCATION", "dynamic_invocation/xslt/wsdl11to20.xsl10.xsl");
define("WSF_SIG_XSL_LOCATION", "dynamic_invocation/xslt/wsdl2sig.xslt");

define("WSF_WSDL2_NAMESPACE", "http://www.w3.org/ns/wsdl");
define("WSF_WSDL_NAMESPACE", "http://schemas.xmlsoap.org/wsdl/");
define("WSF_POLICY_REFERENCE_NAMESPACE_URI", "http://schemas.xmlsoap.org/ws/2004/09/policy");
define("WSF_POLICY_NAMESPACE_URI", "http://www.w3.org/ns/ws-policy");
define("WSF_POLICY_ID_NAMESPACE_URI", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd");

// constants involves in sig model data 

define("WSF_SIG_META_DATA", "__sig_meta_data"); // doesn't support elements with this name in schemas

define("WSF_SIG_CHILDS", "childs"); // doesn't support elements with this name in schemas
define("WSF_HAS_SIG_CHILDS", "has_childs");

define("WSF_CLASSMAP_NAME", "classmap_name");
define("WSF_XSD_NILLABLE", "nillable");
define("WSF_CONTENT_MODEL", "contentModel");
define("WSF_INNER_CONTENT", "inner-content");
define("WSF_INHERITED_CONTENT", "inherited-content");
define("WSF_INHERITING_TYPE", "inheriting-type");
define("WSF_XSI_TYPE", "xsi-type");
define("WSF_XSI_TYPE_NS", "xsi-type-ns");
define("WSF_XSI_NAMESPACE", "http://www.w3.org/2001/XMLSchema-instance");
define("WSF_XSD_NAMESPACE", "http://www.w3.org/2001/XMLSchema");
define("WSF_EXTENSION", "extension");
define("WSF_ATTRIBUTE", "attribute");

define("WSF_STARTING_NS_PREFIX", "ns1");
define("WSF_SOAP_BODY", "Body");

define("WSF_WSDL_SEQUENCE", "sequence");
define("WSF_WSDL_CHOICE", "choice");
define("WSF_WSDL_ALL", "all");

define("WSF_SIMPLE_CONTENT_VALUE", "value");
define("WSF_SIMPLE_CONTENT", "simpleContent");

define("WSF_XSD_ANYTYPE", "anyType");
define("WSF_ANY_ELEMENT", "any#");
define("WSF_VALUE", "value");

define("WSF_XSD_BASE64", "base64Binary");
define("WSF_POSTFIX_BASE64", "_encoded");
define("WSF_CONTENT_TYPE", "contentType");

define("WSF_DEFAULT_CONTENT_TYPE", "application/octet-stream");
define("WSF_MIME_NAMESPACE_PREFIX", "xmlmime");
define("WSF_MIME_NAMESPACE_URI", "http://www.w3.org/2004/06/xmlmime");
define("WSF_XOP_NAMESPACE_PREFIX", "xop");
define("WSF_XOP_NAMESPACE_URI", "http://www.w3.org/2004/08/xop/include");
define("WSF_MTOM_INCLUDE_TAG", "Include");
define("WSF_HREF_PREFIX", "cid:");
define("WSF_HREF", "href");
define("WSF_ATTACHMENT_MAP", "attachment_map");
define("WSF_RESPONSE_PAYLOAD", "response_payload");

define("WSF_SOAPHEADER", "soapheader");
define("WSF_HEADER_FOR_ATTRIBUTE", "for");
define("WSF_INPUT_HEADERS", "input_headers");
define("WSF_OUTPUT_HEADERS", "output_headers");
define("WSF_HEADER_STRING", "header_string");
define("WSF_REQUIRED", "required");
define("WSF_RESPONSE_PAYLOAD_PARAM", "response_payload_param");
define("WSF_RESPONSE_HEADER_PARAM", "response_header_param");

// log level definition

define("WSF_LOG_CRITICAL", 0);
define("WSF_LOG_ERROR", 1);
define("WSF_LOG_WARNING", 2);
define("WSF_LOG_INFO", 3);
define("WSF_LOG_DEBUG", 4);
define("WSF_LOG_USER", 5);
define("WSF_LOG_TRACE", 6);

?>
