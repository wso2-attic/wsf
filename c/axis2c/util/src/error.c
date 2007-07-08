/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>
#include "axutil_error_default.h"

AXIS2_EXPORT const axis2_char_t* axutil_error_messages[AXIS2_ERROR_LAST + 10000];

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_error_init()
{
    int i = 0;
    for (i = 0; i < AXIS2_ERROR_LAST; i++)
    {
        axutil_error_messages[i] = "Unknown Error :(";
    }

    /* Common Errors */
    axutil_error_messages[AXIS2_ERROR_NONE] = "No Error";
    axutil_error_messages[AXIS2_ERROR_NO_MEMORY] = "Out of memory";
    axutil_error_messages[AXIS2_ERROR_INVALID_NULL_PARAM] =
        "NULL paramater was passed when a non NULL parameter was expected";
    /* core:addr */

    /* core:clientapi */
    axutil_error_messages[AXIS2_ERROR_BLOCKING_INVOCATION_EXPECTS_RESPONSE] =
        "Blocking invocation expects response";
    axutil_error_messages[AXIS2_ERROR_CANNOT_INFER_TRANSPORT] =
        "cannot infer transport from URL";
    axutil_error_messages[AXIS2_ERROR_CLIENT_SIDE_SUPPORT_ONLY_ONE_CONF_CTX] =
        "Client side support only one configuration context";
    axutil_error_messages[AXIS2_ERROR_MEP_CANNOT_BE_NULL_IN_MEP_CLIENT] =
        "MEP cannot be NULL in MEP client";
    axutil_error_messages[AXIS2_ERROR_MEP_MISMATCH_IN_MEP_CLIENT] =
        "MEP Mismatch";
    axutil_error_messages[AXIS2_ERROR_TWO_WAY_CHANNEL_NEEDS_ADDRESSING] =
        "Two way channel needs addressing module to be engaged";
    axutil_error_messages[AXIS2_ERROR_UNKNOWN_TRANSPORT] =
        "Unknown Transport";
    axutil_error_messages[AXIS2_ERROR_UNSUPPORTED_TYPE] =
        "type is not supported";
    axutil_error_messages[AXIS2_ERROR_OPTIONS_OBJECT_IS_NOT_SET] =
        "Options object is not set";
    /* core:clientapi:diclient */

    /* core:context */
    axutil_error_messages[AXIS2_ERROR_INVALID_SOAP_ENVELOPE_STATE] =
        "Invalid SOAP envelope state";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_MSG_CTX] =
        "Invalid message context state";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_SVC] =
        "Service accessed has invalid state";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_SVC_GRP] =
        "Service group accessed has invalid state";
    axutil_error_messages[AXIS2_ERROR_SERVICE_NOT_YET_FOUND] =
        "Service not yet found";
    /* core:deployment */
    axutil_error_messages[AXI2_ERROR_INVALID_PHASE] =
        "Invalid phase found in phase validation*";
    axutil_error_messages[AXIS2_ERROR_CONFIG_NOT_FOUND] =
        "axis2.xml cannot be found";
    axutil_error_messages[AXIS2_ERROR_DATA_ELEMENT_IS_NULL] =
        "Data element of the OM Node is null";
    axutil_error_messages[AXIS2_ERROR_IN_FLOW_NOT_ALLOWED_IN_TRS_OUT] =
        "In transport sender, Inflow is not allowed";
    axutil_error_messages[AXIS2_ERROR_INVALID_HANDLER_STATE] =
        "Invalid handler state";
    axutil_error_messages[AXIS2_ERROR_INVALID_MODUELE_REF] =
        "Invalid Module Ref encountered";
    axutil_error_messages[AXIS2_ERROR_INVALID_MODUELE_REF_BY_OP] =
        "Invalid Module Reference by Operation";
    axutil_error_messages[AXIS2_ERROR_INVALID_MODULE_CONF] =
        "Invalid Module Configuration";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_DESC_BUILDER] =
        "Description Builder is found to be in invalid state";
    axutil_error_messages[AXIS2_ERROR_MODULE_NOT_FOUND] =
        "Module Not Found";
    axutil_error_messages[AXIS2_ERROR_MODULE_VALIDATION_FAILED] =
        "Module Validation Failed";
    axutil_error_messages[AXIS2_ERROR_MODULE_XML_NOT_FOUND_FOR_THE_MODULE] =
        "Module xml file is not found in the given path";
    axutil_error_messages[AXIS2_ERROR_NO_DISPATCHER_FOUND] =
        "No dispatcher found";
    axutil_error_messages[AXIS2_ERROR_OP_NAME_MISSING] =
        "Operation name is missing";
    axutil_error_messages[AXIS2_ERROR_OUT_FLOW_NOT_ALLOWED_IN_TRS_IN] =
        "In transport Receiver, Outflow is not allowed";
    axutil_error_messages[AXIS2_ERROR_REPO_CAN_NOT_BE_NULL] =
        "Repository name cannot be NULL";
    axutil_error_messages[AXIS2_ERROR_REPOSITORY_NOT_EXIST] =
        "Repository in path does not exist";
    axutil_error_messages[AXIS2_ERROR_REPOS_LISTENER_INIT_FAILED] =
        "Repository Listener initialization failed";
    axutil_error_messages[AXIS2_ERROR_SERVICE_XML_NOT_FOUND] =
        "Service xml file is not found in the given path";
    axutil_error_messages[AXIS2_ERROR_SVC_NAME_ERROR] =
        "Service Name Error";
    axutil_error_messages[AXIS2_ERROR_TRANSPORT_SENDER_ERROR] =
        "Transport Sender Error";
    axutil_error_messages[AXIS2_PATH_TO_CONFIG_CAN_NOT_BE_NULL] =
        "Path to Config can not be NULL";
    axutil_error_messages[AXIS2_ERROR_INVALID_SVC] =
        "Invalid Service";
    /* core:description */
    axutil_error_messages[AXIS2_ERROR_CANNOT_CORRELATE_MSG] =
        "Cannot correlate message";
    axutil_error_messages[AXIS2_ERROR_COULD_NOT_MAP_MEP_URI_TO_MEP_CONSTANT] =
        "Could not Map the MEP URI to a axis MEP constant value";
    axutil_error_messages[AXIS2_ERROR_INVALID_MESSAGE_ADDITION] =
        "Invalid messge addition operation context completed";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_MODULE_DESC] =
        "Module description accessed has invalid state";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_PARAM_CONTAINER] =
        "Parameter container not set";
    axutil_error_messages[AXIS2_ERROR_MODULE_ALREADY_ENGAGED_TO_OP] =
        "module has alredy engaged to the op op terminated !!!";
    axutil_error_messages[AXIS2_ERROR_MODULE_ALREADY_ENGAGED_TO_SVC] =
        "module has alredy been engaged on the service.Operation terminated !!!";
    axutil_error_messages[AXIS2_ERROR_MODULE_ALREADY_ENGAGED_TO_SVC_GRP] =
        "module has alredy been engaged on the service. Group Operation terminated !!!";
    axutil_error_messages[AXIS2_ERROR_PARAMETER_LOCKED_CANNOT_OVERRIDE] =
        "Parameter locked, Cannot override";
    axutil_error_messages[AXIS2_ERROR_EMPTY_SCHEMA_LIST] =
        "schema list is empty or NULL in svc ";
    /* core:engine */
    axutil_error_messages[AXIS2_ERROR_BEFORE_AFTER_HANDLERS_SAME] =
        "Both before and after handlers cannot be the same";
    axutil_error_messages[AXIS2_ERROR_INVALID_HANDLER_RULES] =
        "Invalid handler rules";
    axutil_error_messages[AXIS2_ERROR_INVALID_MODULE] =
        "Invalid Module";
    axutil_error_messages[AXIS2_ERROR_INVALID_PHASE_FIRST_HANDLER] =
        "Invalid first handler for phase";
    axutil_error_messages[AXIS2_ERROR_INVALID_PHASE_LAST_HANDLER] =
        "Invalid last handler for phase";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_CONF] =
        "Invalid engine config state";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_PROCESSING_FAULT_ALREADY] =
        "Message context processing a fault already";
    axutil_error_messages[AXIS2_ERROR_NOWHERE_TO_SEND_FAULT] =
        "fault to field not specified in message context";
    axutil_error_messages[AXIS2_ERROR_PHASE_ADD_HANDLER_INVALID] =
        "Only one handler allowed for phase, adding another handler is not allowed";
    axutil_error_messages[AXIS2_ERROR_PHASE_FIRST_HANDLER_ALREADY_SET] =
        "First handler of phase already set";
    axutil_error_messages[AXIS2_ERROR_PHASE_LAST_HANDLER_ALREADY_SET] =
        "Last handler of phase already set";
    axutil_error_messages[AXIS2_ERROR_TWO_SVCS_CANNOT_HAVE_SAME_NAME] =
        "Two service can not have same name, a service with same name alredy";
    /* core:phaseresolver */
    axutil_error_messages[AXIS2_ERROR_INVALID_MODULE_REF] =
        "Invalid Module Ref";
    axutil_error_messages[AXIS2_ERROR_INVALID_PHASE] =
        "Invalid Phase";
    axutil_error_messages[AXIS2_ERROR_NO_TRANSPORT_IN_CONFIGURED] =
        "There are no in transport chains configured";
    axutil_error_messages[AXIS2_ERROR_NO_TRANSPORT_OUT_CONFIGURED] =
        "There are no out transport chains configured";
    axutil_error_messages[AXIS2_ERROR_PHASE_IS_NOT_SPECIFED] =
        "Phase is not specified";
    axutil_error_messages[AXIS2_ERROR_SERVICE_MODULE_CAN_NOT_REFER_GLOBAL_PHASE] =
        "Service module can not refer global phase";
    /* core:wsdl*/
    axutil_error_messages[AXIS2_ERROR_WSDL_SCHEMA_IS_NULL] =
        "Schema is NULL";
    /* core:receivers */
    axutil_error_messages[AXIS2_ERROR_OM_ELEMENT_INVALID_STATE] =
        "Om Element has invalid state";
    axutil_error_messages[AXIS2_ERROR_OM_ELEMENT_MISMATCH] =
        "Om Elements do not match";
    axutil_error_messages[AXIS2_ERROR_RPC_NEED_MATCHING_CHILD] =
        "RPC style soap body don't have a child element";
    axutil_error_messages[AXIS2_ERROR_UNKNOWN_STYLE] =
        "Operation Description has unknown operation style";
    axutil_error_messages[AXIS2_ERROR_STRING_DOES_NOT_REPRESENT_A_VALID_NC_NAME] =
        "String does not represent a valid NCName";
    /* core:transport */

    /* core:transport:http */
    axutil_error_messages[AXIS2_ERROR_HTTP_CLIENT_TRANSPORT_ERROR] =
        "Error occured in transport";
    axutil_error_messages[AXIS2_ERROR_HTTP_REQUEST_NOT_SENT] =
        "A read attempt(HTTP) for the reply without sending the request";
    axutil_error_messages[AXIS2_ERROR_INVALID_HEADER] =
        "Invalid string passed as a http header";
    axutil_error_messages[AXIS2_ERROR_INVALID_HTTP_HEADER_START_LINE] =
        "Invalid status line or invalid request line";
    axutil_error_messages[AXIS2_ERROR_INVALID_TRANSPORT_PROTOCOL] =
        "Transport protocol is unsupported by axis2";
    axutil_error_messages[AXIS2_ERROR_NULL_BODY] =
        "No body present in the request or the response";
    axutil_error_messages[AXIS2_ERROR_NULL_CONFIGURATION_CONTEXT] =
        "A valid conf_ctx is reqd for the http worker";
    axutil_error_messages[AXIS2_ERROR_NULL_HTTP_VERSION] =
        "HTTP version cannot be null in the status/request line";
    axutil_error_messages[AXIS2_ERROR_NULL_IN_STREAM_IN_MSG_CTX] =
        "Input stream is NULL in msg_ctx";
    axutil_error_messages[AXIS2_ERROR_NULL_OM_OUTPUT] =
        "OM output is NULL";
    axutil_error_messages[AXIS2_ERROR_NULL_SOAP_ENVELOPE_IN_MSG_CTX] =
        "Null soap envelope in msg_ctx";
    axutil_error_messages[AXIS2_ERROR_NULL_STREAM_IN_CHUNKED_STREAM] =
        "NULL stream in the http chunked stream";
    axutil_error_messages[AXIS2_ERROR_NULL_STREAM_IN_RESPONSE_BODY] =
        "We got a NULL stream in the response body";
    axutil_error_messages[AXIS2_ERROR_NULL_URL] =
        "URL NULL in http client";
    axutil_error_messages[AXIS2_ERROR_OUT_TRNSPORT_INFO_NULL] =
        "We need transport_info in msg_ctx";
    axutil_error_messages[AXIS2_ERROR_RESPONSE_CONTENT_TYPE_MISSING] =
        "Content-Type header missing in HTTP response";
    axutil_error_messages[AXIS2_ERROR_RESPONSE_TIMED_OUT] =
        "Response timed out";
    axutil_error_messages[AXIS2_ERROR_SOAP_ENVELOPE_OR_SOAP_BODY_NULL] =
        "SOAP envelope or SOAP body NULL";
    axutil_error_messages[AXIS2_ERROR_SSL_ENGINE] =
        "Error occured in SSL engine";
    axutil_error_messages[AXIS2_ERROR_SSL_NO_CA_FILE] =
        "Either axis2c cannot find certificates or the env variable is not set";
    axutil_error_messages[AXIS2_ERROR_WRITING_RESPONSE] =
        "Error in writing the response in response writer";
    axutil_error_messages[AXIS2_ERROR_REQD_PARAM_MISSING] =
        "Required parameter is missing in url encoded request";
    axutil_error_messages[AXIS2_ERROR_UNSUPPORTED_SCHEMA_TYPE] =
        " Unsuppoted schema type in REST";
    axutil_error_messages[AXIS2_ERROR_SVC_OR_OP_NOT_FOUND] =
        "Service or operation not found";
    /* mod_addr */

    /* platforms */

    /* utils */
    axutil_error_messages[AXIS2_ERROR_COULD_NOT_OPEN_FILE] =
        "Could not open the file";
    axutil_error_messages[AXIS2_ERROR_DLL_CREATE_FAILED] =
        "Failed in creating DLL";
    axutil_error_messages[AXIS2_ERROR_DLL_LOADING_FAILED] =
        "DLL loading failed";
    axutil_error_messages[AXIS2_ERROR_ENVIRONMENT_IS_NULL] =
        "Environment passed is null";
    axutil_error_messages[AXIS2_ERROR_FILE_NAME_NOT_SET] =
        "Axis2 File does not have a file name";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_DLL_DESC] =
        "dll description has invalid state of not having valid dll create function, \
        of valid delete function or valid dll_handler";
    axutil_error_messages[AXIS2_ERROR_HANDLER_CREATION_FAILED] =
        "Failed in creating Handler";
    axutil_error_messages[AXIS2_ERROR_INDEX_OUT_OF_BOUNDS] =
        "Array list index out of bounds";
    axutil_error_messages[AXIS2_ERROR_INVALID_ADDRESS] =
        "Invalid IP or hostname";
    axutil_error_messages[AXIS2_ERROR_INVALID_FD] =
        "Trying to do operation on invalid file descriptor";
    axutil_error_messages[AXIS2_ERROR_INVALID_SOCKET] =
        "Trying to do operation on closed/not opened socket";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_PARAM] =
        "Parameter not set";
    axutil_error_messages[AXIS2_ERROR_MODULE_CREATION_FAILED] =
        "Module create failed";
    axutil_error_messages[AXIS2_ERROR_MSG_RECV_CREATION_FAILED] =
        "Failed in creating Message Receiver";
    axutil_error_messages[AXIS2_ERROR_NO_SUCH_ELEMENT] =
        "No such element";
    axutil_error_messages[AXIS2_ERROR_SOCKET_BIND_FAILED] =
        "Socket bind failed. Another process may be already using this port";
    axutil_error_messages[AXIS2_ERROR_SOCKET_ERROR] =
        "Error creating a socket. Most probably error returned by OS";
    axutil_error_messages[AXIS2_ERROR_SOCKET_LISTEN_FAILED] =
        "Listen failed for the server socket";
    axutil_error_messages[AXIS2_ERROR_SVC_SKELETON_CREATION_FAILED] =
        "Failed in creating Service Skeleton";
    axutil_error_messages[AXIS2_ERROR_TRANSPORT_RECV_CREATION_FAILED] =
        "Failed in creating Transport Receiver";
    axutil_error_messages[AXIS2_ERROR_TRANSPORT_SENDER_CREATION_FAILED] =
        "Failed in creating Transport Sender";
    axutil_error_messages[AXIS2_ERROR_UUID_GEN_FAILED] =
        "Generation of platform dependent uuid failed";
    axutil_error_messages[AXIS2_ERROR_POSSIBLE_DEADLOCK]=
       "Possible deadlock";
    /* wsdl */
    axutil_error_messages[AXIS2_ERROR_INTERFACE_OR_PORT_TYPE_NOT_FOUND_FOR_THE_BINDING] =
        "Interface or Port Type not found for the binding";
    axutil_error_messages[AXIS2_ERROR_INTERFACES_OR_PORTS_NOT_FOUND_FOR_PARTIALLY_BUILT_WOM] =
        "Interfaces or Ports not found for the partially built WOM";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_WSDL_OP] =
        "Wsdl op accessed has invalid state";
    axutil_error_messages[AXIS2_ERROR_INVALID_STATE_WSDL_SVC] =
        "Wsdl Service accessed has invalid state";
    axutil_error_messages[AXIS2_ERROR_MEP_CANNOT_DETERMINE_MEP] =
        "Cannot determine MEP";
    axutil_error_messages[AXIS2_ERROR_WSDL_BINDING_NAME_IS_REQUIRED] =
        "Wsdl binding name is cannot be NULL(Is required)";
    axutil_error_messages[AXIS2_ERROR_WSDL_INTERFACE_NAME_IS_REQUIRED] =
        " PortType/Interface name cannot be null(Required)";
    axutil_error_messages[AXIS2_ERROR_WSDL_PARSER_INVALID_STATE] =
        "Wsdl parsing has resulted in an invalid state";
    axutil_error_messages[AXIS2_ERROR_WSDL_SVC_NAME_IS_REQUIRED] =
        " Wsdl svc name cannot be null(Required)";
    /* xml */

    /* xml:attachments */

    /* xml:om */
    axutil_error_messages[AXIS2_ERROR_BUILDER_DONE_CANNOT_PULL] =
        "Builder done with pulling. Cannot pull any more";
    axutil_error_messages[AXIS2_ERROR_INVALID_BUILDER_STATE_CANNOT_DISCARD] =
        "Discard faile because the builder state is invalid";
    axutil_error_messages[AXIS2_ERROR_INVALID_BUILDER_STATE_LAST_NODE_NULL] =
        "Bulder's last node is NULL when it is not supposed to be NULL";
    axutil_error_messages[AXIS2_ERROR_INVALID_DOCUMENT_STATE_ROOT_NULL] =
        "Document root is NULL] =  when it is not supposed to be NULL";
    axutil_error_messages[AXIS2_ERROR_INVALID_DOCUMENT_STATE_UNDEFINED_NAMESPACE] =
        "Undefined namespace used";
    axutil_error_messages[AXIS2_ERROR_INVALID_EMPTY_NAMESPACE_URI] =
        "Error a namespace should have a valid uri";
    axutil_error_messages[AXIS2_ERROR_ITERATOR_NEXT_METHOD_HAS_NOT_YET_BEEN_CALLED] =
        "next method has not been called so cannot remove"
        "an element before calling next valid for any om iterator";
    axutil_error_messages[AXIS2_ERROR_ITERATOR_REMOVE_HAS_ALREADY_BEING_CALLED] =
        "Document root is NULL, when it is not supposed to be NULL";
    axutil_error_messages[AXIS2_ERROR_XML_READER_ELEMENT_NULL] =
        "axiom_xml_reader returned NULL element";
    axutil_error_messages[AXIS2_ERROR_XML_READER_VALUE_NULL] =
        "axiom_xml_reader returned NULL value";
    /* xml:parser */
    axutil_error_messages[AXIS2_ERROR_CREATING_XML_STREAM_READER] =
        "error occured creating xml stream reader";
    axutil_error_messages[AXIS2_ERROR_CREATING_XML_STREAM_WRITER] =
        "error occured creating xml stream writer";
    axutil_error_messages[AXIS2_ERROR_WRITING_ATTRIBUTE] =
        "error in writing attribute";
    axutil_error_messages[AXIS2_ERROR_WRITING_ATTRIBUTE_WITH_NAMESPACE] =
        "error in writing attribute with namespace";
    axutil_error_messages[AXIS2_ERROR_WRITING_ATTRIBUTE_WITH_NAMESPACE_PREFIX] =
        "error in writing attribute with namespace prefix";
    axutil_error_messages[AXIS2_ERROR_WRITING_COMMENT] =
        "error in writing comment";
    axutil_error_messages[AXIS2_ERROR_WRITING_DATA_SOURCE] =
        "error in writing data source";
    axutil_error_messages[AXIS2_ERROR_WRITING_DEFAULT_NAMESPACE] =
        "error in writing default namespace";
    axutil_error_messages[AXIS2_ERROR_WRITING_DTD] =
        "error in writing dtd";
    axutil_error_messages[AXIS2_ERROR_WRITING_EMPTY_ELEMENT] =
        "error occured in writing empty element";
    axutil_error_messages[AXIS2_ERROR_WRITING_EMPTY_ELEMENT_WITH_NAMESPACE] =
        "error occured in writing empty element with namespace";
    axutil_error_messages[AXIS2_ERROR_WRITING_EMPTY_ELEMENT_WITH_NAMESPACE_PREFIX] =
        "error in writing empty element with namespace prefix";
    axutil_error_messages[AXIS2_ERROR_WRITING_END_DOCUMENT] =
        "error occured in writing end document in xml writer";
    axutil_error_messages[AXIS2_ERROR_WRITING_END_ELEMENT] =
        "error occured in writing end element in xml writer";
    axutil_error_messages[AXIS2_ERROR_WRITING_PROCESSING_INSTRUCTION] =
        "error in writing processing instruction";
    axutil_error_messages[AXIS2_ERROR_WRITING_START_DOCUMENT] =
        "error occured in writing start element in start document in xml writer";
    axutil_error_messages[AXIS2_ERROR_WRITING_START_ELEMENT] =
        "error occured in writing start element in xml writer";
    axutil_error_messages[AXIS2_ERROR_WRITING_START_ELEMENT_WITH_NAMESPACE] =
        "error occured in writing start element with namespace in xml writer";
    axutil_error_messages[AXIS2_ERROR_WRITING_START_ELEMENT_WITH_NAMESPACE_PREFIX] =
        "error occured in writing start element with namespace prefix";
    axutil_error_messages[AXIS2_ERROR_WRITING_CDATA] =
        "error in writing cdata section";
    axutil_error_messages[AXIS2_ERROR_XML_PARSER_INVALID_MEM_TYPE] =
        "AXIS2_XML_PARSER_TYPE_BUFFER or AXIS2_XML_PARSER_TYPE_DOC is expected";

    /* invalid type passed */
    axutil_error_messages[AXIS2_ERROR_INVALID_BASE_TYPE] =
        "invalid type passed";
    axutil_error_messages[AXIS2_ERROR_INVALID_SOAP_NAMESPACE_URI] =
        "invalid soap namespace uri found";
    axutil_error_messages[AXIS2_ERROR_INVALID_SOAP_VERSION] =
        "Invalid SOAP version";
    axutil_error_messages[AXIS2_ERROR_INVALID_VALUE_FOUND_IN_MUST_UNDERSTAND] =
        "invalid value found in must understand";
    axutil_error_messages[AXIS2_ERROR_MULTIPLE_CODE_ELEMENTS_ENCOUNTERED] =
        "multiple  fault code elements encountered in soap fault";
    axutil_error_messages[AXIS2_ERROR_MULTIPLE_DETAIL_ELEMENTS_ENCOUNTERED] =
        "multiple fault detail elements encountered in soap fault";
    axutil_error_messages[AXIS2_ERROR_MULTIPLE_NODE_ELEMENTS_ENCOUNTERED] =
        "multiple fault node elements encountered in soap fault";
    axutil_error_messages[AXIS2_ERROR_MULTIPLE_REASON_ELEMENTS_ENCOUNTERED] =
        "multiple fault reason elements encountered in soap fault";
    axutil_error_messages[AXIS2_ERROR_MULTIPLE_ROLE_ELEMENTS_ENCOUNTERED] =
        "multiple fault role elements encountered in soap fault ";
    axutil_error_messages[AXIS2_ERROR_MULTIPLE_SUB_CODE_VALUES_ENCOUNTERED] =
        "multiple fault subcode value elements encountered";
    axutil_error_messages[AXIS2_ERROR_MULTIPLE_VALUE_ENCOUNTERED_IN_CODE_ELEMENT] =
        "multiple fault value elements encounterd";
    axutil_error_messages[AXIS2_ERROR_MUST_UNDERSTAND_SHOULD_BE_1_0_TRUE_FALSE] =
        "must understatnd attribute should have values of true or false";
    axutil_error_messages[AXIS2_ERROR_OM_ELEMENT_EXPECTED] =
        "om element is expected";
    axutil_error_messages[AXIS2_ERROR_ONLY_CHARACTERS_ARE_ALLOWED_HERE] =
        "processing soap11 fault value element should have only"
        "text as its children";
    axutil_error_messages[AXIS2_ERROR_ONLY_ONE_SOAP_FAULT_ALLOWED_IN_BODY] =
        "only one SOAP fault allowed in SOAP body";
    axutil_error_messages[AXIS2_ERROR_SOAP11_FAULT_ACTOR_SHOULD_NOT_HAVE_CHILD_ELEMENTS] =
        "AXIS2_ERROR_SOAP11_FAULT_ACTOR_SHOULD_NOT_HAVE_CHILD_ELEMENTS";
    axutil_error_messages[AXIS2_ERROR_SOAP_BUILDER_ENVELOPE_CAN_HAVE_ONLY_HEADER_AND_BODY] =
        "soap builder found a child element other than header or body in envelope"
        "element";
    axutil_error_messages[AXIS2_ERROR_SOAP_BUILDER_HEADER_BODY_WRONG_ORDER] =
        "soap builder encounterd body element first and header next";
    axutil_error_messages[AXIS2_ERROR_SOAP_BUILDER_MULTIPLE_BODY_ELEMENTS_ENCOUNTERED] =
        "soap builder multiple body elements encounterd";
    axutil_error_messages[AXIS2_ERROR_SOAP_BUILDER_MULTIPLE_HEADERS_ENCOUNTERED] =
        "soap builder encountered multiple headers";
    axutil_error_messages[AXIS2_ERROR_SOAP_FAULT_CODE_DOES_NOT_HAVE_A_VALUE] =
        "AXIS2_ERROR_SOAP_FAULT_CODE_DOES_NOT_HAVE_A_VALUE";
    axutil_error_messages[AXIS2_ERROR_SOAP_FAULT_REASON_ELEMENT_SHOULD_HAVE_A_TEXT] =
        "AXIS2_ERROR_SOAP_FAULT_REASON_ELEMENT_SHOULD_HAVE_A_TEXT";
    axutil_error_messages[AXIS2_ERROR_SOAP_FAULT_ROLE_ELEMENT_SHOULD_HAVE_A_TEXT] =
        "soap fault role element should have a text value";
    axutil_error_messages[AXIS2_ERROR_SOAP_FAULT_VALUE_SHOULD_BE_PRESENT_BEFORE_SUB_CODE] =
        "soap fault value should be present before subcode element in soap fault code";
    axutil_error_messages[AXIS2_ERROR_SOAP_MESSAGE_DOES_NOT_CONTAIN_AN_ENVELOPE] =
        "soap message does not contain a soap envelope element";
    axutil_error_messages[AXIS2_ERROR_SOAP_MESSAGE_FIRST_ELEMENT_MUST_CONTAIN_LOCAL_NAME] =
        "soap messgae first element should have a localname";
    axutil_error_messages[AXIS2_ERROR_THIS_LOCALNAME_IS_NOT_SUPPORTED_INSIDE_THE_REASON_ELEMENT] =
        "localname not supported inside a reason element";
    axutil_error_messages[AXIS2_ERROR_THIS_LOCALNAME_IS_NOT_SUPPORTED_INSIDE_THE_SUB_CODE_ELEMENT] =
        "localname not supported inside the subcode element";
    axutil_error_messages[AXIS2_ERROR_THIS_LOCALNAME_NOT_SUPPORTED_INSIDE_THE_CODE_ELEMENT] =
        "localname not supported inside the code element";
    axutil_error_messages[AXIS2_ERROR_TRANSPORT_LEVEL_INFORMATION_DOES_NOT_MATCH_WITH_SOAP] =
        "transport identified soap version does not match with soap message version ";
    axutil_error_messages[AXIS2_ERROR_UNSUPPORTED_ELEMENT_IN_SOAP_FAULT_ELEMENT] =
        "unsupported element found in soap fault element";
    axutil_error_messages[AXIS2_ERROR_WRONG_ELEMENT_ORDER_ENCOUNTERED] =
        "wrong element order encountered ";
    /* services */
    axutil_error_messages[AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST] =
        "Invalid XML format in request";
    axutil_error_messages[AXIS2_ERROR_SVC_SKEL_INPUT_OM_NODE_NULL] =
        "Input OM node NULL, Probably error in SOAP request";
    axutil_error_messages[AXIS2_ERROR_SVC_SKEL_INVALID_OPERATION_PARAMETERS_IN_SOAP_REQUEST] =
        "Invalid parameters for service operation in SOAP request";

    axutil_error_messages[AXIS2_ERROR_WSDL_SCHEMA_IS_NULL] =
        "Schema is NULL";

    /* repos */
    axutil_error_messages[AXIS2_ERROR_REPOS_NOT_AUTHENTICATED] =
        "NOT_AUTHENTICATED";
    axutil_error_messages[AXIS2_ERROR_REPOS_UNSUPPORTED_MODE] =
        "UNSUPPORTED_MODE";
    axutil_error_messages[AXIS2_ERROR_REPOS_EXPIRED] =
        "EXPIRED";
    axutil_error_messages[AXIS2_ERROR_REPOS_NOT_IMPLEMENTED] =
        "NOT_IMPLEMENTED";
    axutil_error_messages[AXIS2_ERROR_REPOS_NOT_FOUND] =
        "NOT_FOUND";
    axutil_error_messages[AXIS2_ERROR_REPOS_BAD_SEARCH_TEXT] =
        "BAD_SEARCH_TEXT";

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN void AXIS2_CALL
axutil_error_free(axutil_error_t *error)
{
    if (error)
    {
        AXIS2_FREE(error->allocator, error);
    }
    return;
}

AXIS2_EXTERN axutil_error_t* AXIS2_CALL
axutil_error_create(axutil_allocator_t * allocator)
{
    axutil_error_t *error;
    if (!allocator)
        return NULL;

    error =
        (axutil_error_t *) AXIS2_MALLOC(allocator, sizeof(axutil_error_t));

    if (!error)
        return NULL;

    error->allocator = allocator;

	error->message = NULL;

    return error;
}

AXIS2_EXTERN const axis2_char_t * AXIS2_CALL
axutil_error_get_message(const axutil_error_t *error)
{
	const axis2_char_t *message = NULL;
	if (error)
	{
		if (error->error_number > AXIS2_ERROR_NONE && error->error_number < AXIS2_ERROR_LAST)
			message = axutil_error_messages[error->error_number];
		else
		{
			if (error->message)
				message = error->message;
			else if (error->error_number == AXIS2_ERROR_NONE)
				message = axutil_error_messages[AXIS2_ERROR_NONE];
			else 
				message = "Invalid Error Number";
		}
	}

    return message;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_error_set_error_number(axutil_error_t *error, 
    axutil_error_codes_t error_number)
{
    error->error_number = error_number;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_error_set_status_code(axutil_error_t *error, 
    axis2_status_codes_t status_code)
{
    error->status_code = status_code;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_error_get_status_code(axutil_error_t *error)
{
    return error->status_code;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_error_set_error_message(axutil_error_t *error, 
    axis2_char_t *message)
{
	if (message)
		error->message = message;
    return AXIS2_SUCCESS;
}


