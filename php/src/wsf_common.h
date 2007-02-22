/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
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

#ifndef WSF_COMMON_H
#define WSF_COMMON_H

#ifdef PHP_WIN32
#define WSF_PHP_API __declspec(dllexport)
#else
#define WSF_PHP_API
#endif

#ifdef PHP_WIN32
#define WSF_CALL	__stdcall
#else
#define WSF_CALL
#endif
#include <axis2_svc.h>
#include <axis2_msg_recv.h>
#include <axiom.h>
#include <php.h>


/* {{{ axis2 object types */
typedef enum ws_object_types_t
{
  	WS_SVC_CLIENT,
	WS_SVC,
	WS_FAULT,
	WS_PARAM,
    WS_OBJECT_LAST
}ws_object_types_t;
/* }}} */

/** using input */
typedef enum ws_input_types{
    WS_USING_DOM = 0,
    WS_USING_SIMPLEXML,
    WS_USING_STRING,
    WS_USING_MSG,
    WS_USING_INCORRECT_INPUT
}ws_input_types_t;


/** Options array options */
#define WS_TO			"to"    /** endpoint uri */

#define WS_USE_WSA     "useWSA"
#define WS_ACTION		"action"		/** addressing options */
#define WS_FROM		"from"
#define WS_REPLY_TO		"replyTo"
#define WS_FAULT_TO		"faultTo"

#define WS_USES_XOP	"usesXOP"	   /** MTOM XOP */
#define WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE "defaultAttachmentContentType"
#define WS_ATTACHMENTS "attachments"
#define WS_RESPONSE_XOP "responseXOP"
#define WS_REQUEST_XOP  "requestXOP"
#define WS_USE_MTOM     "useMTOM"

#define WS_WILL_CONTINUE_SEQUENCE "willContinueSequence"  
#define WS_LAST_MESSAGE "lastMessage"
#define WS_RELIABLE	"reliable"
#define WS_SEQUENCE_EXPIRY_TIME "sequenceExpiryTime"

#define WS_USE_SOAP	"useSOAP"
#define WS_HTTP_METHOD "HTTPMethod"

#define WS_SERVER_CERT "serverCertificate"
#define WS_CLIENT_CERT "clientCertificate"
#define WS_PASSPHRASE  "passphrase"

#define WS_BINDING_STYLE "bindingStyle"
#define WS_WSDL          "wsdl"

#define WS_FAULT_REASON "reason"
#define WS_FAULT_ROLE   "role"
#define WS_FAULT_TEXT   "text"
#define WS_FAULT_CODE   "code"
#define WS_FAULT_SUBCODE "subcode"
#define WS_FAULT_DETAIL "detail"

#define WS_HEADERS      "headers"    /** header options */
#define WS_HEADER_NS    "ns"
#define WS_HEADER_LOCALNAME "localname"
#define WS_HEADER_DATA     "data"
#define WS_HEADER_ROLE     "role"
#define WS_HEADER_MUST_UNDERSTAND "mustUnderstand"

#define WS_POLICY "policy"
#define WS_SECURITY_TOKEN "securityToken"

/** end options */


#define WS_MSG_PAYLOAD_STR "str"
#define WS_MSG_PAYLOAD_SXML "simpleXML"
#define WS_MSG_PAYLOAD_DOM "dom"

#define WS_MSG_PAYLOAD_TYPE "payloadtype"
#define WS_MSG_TYPE "type"

/** soap header attributes */

#define WS_SOAP_ROLE_NONE			1
#define WS_SOAP_ROLE_NEXT			2
#define WS_SOAP_ROLE_ULTIMATE_RECEIVER	3

#define WS_SOAP_ROLE_NONE_URI "http://www.w3.org/2003/05/soap-envelope/role/none"
#define WS_SOAP_ROLE_NEXT_URI "http://www.w3.org/2003/05/soap-envelope/role/next"
#define WS_SOAP_ROLE_ULTIMATE_RECEIVER_URI "http://www.w3.org/2003/05/soap-envelope/role/next"

#define WS_SOAP_1_1_NAMESPACE_URI "http://schemas.xmlsoap.org/soap/envelope/"
#define WS_SOAP_1_2_NAMESPACE_URI "http://www.w3.org/2003/05/soap-envelope"

/* defaults to true */
#define WS_THROW_EXCEPTION_ON_FAULT	"throw_exception_on_fault"



#define WS_WSA_NAMESPACE "http://www.w3.org/2005/08/addressing"
#define WS_WSA_RELATES_TO_RELATIONSHIP_TYPE_DEFAULT_VALUE "http://www.w3.org/2005/08/addressing/reply"
#define WS_WSA_ANONYMOUS_URL "http://www.w3.org/2005/08/addressing/anonymous"
#define WS_WSA_NONE_URL "http://www.w3.org/2005/08/addressing/none"

#define WS_WSA_IS_REFERENCE_PARAMETER_ATTRIBUTE "IsReferenceParameter"
#define WS_WSA_TYPE_ATTRIBUTE_VALUE "true"

#define WS_WSA_INTERFACE_NAME "InterfaceName"
#define WS_WSA_SERVICE_NAME_ENDPOINT_NAME "EndpointName"
#define WS_WSA_POLICIES "Policies"
#define WS_WSA_METADATA "Metadata"


/** sandesha2 */
#define WS_SANDESHA2_CLIENT_ACKS_TO "Sandesha2AcksTo"
#define WS_SANDESHA2_CLIENT_LAST_MESSAGE "Sandesha2LastMessage"
#define WS_SANDESHA2_CLIENT_OFFERED_SEQ_ID "Sandesha2OfferedSequenceId"
#define WS_SANDESHA2_CLIENT_DEBUG_MODE "Sandesha2DebugMode"
#define WS_SANDESHA2_CLIENT_SEQ_KEY "Sandesha2SequenceKey"
#define WS_SANDESHA2_CLIENT_MESSAGE_NUMBER "Sandesha2MessageNumber"
#define WS_SANDESHA2_CLIENT_RM_SPEC_VERSION "Sandesha2RMSpecVersion"
#define WS_SANDESHA2_CLIENT_DUMMY_MESSAGE "Sandesha2DummyMessage"

#define WS_RM_VERSION_1_0_STR "Spec_2005_02"
#define WS_RM_VERSION_1_0  1
#define WS_RM_VERSION_1_1_STR "Spec_2006_08"
#define WS_RM_VERSION_1_1  2

/************ engaged module names *****************/
#define WS_MODULE_ADDRESSING "addressing"
#define WS_MODULE_SECURITY   "rampart"
#define WS_MODULE_RM         "sandesha2"

#define WS_MODULE_ADDR_KEY     "ws_addressing"
#define WS_MODULE_RM_KEY       "ws_sandesha2"
#define WS_MODULE_SEC_KEY      "ws_rampart"


/** http status codes */
#define WS_HTTP_OK 200

#define WS_HTTP_INTERNAL_SERVER_ERROR 500

#define WS_HTTP_ACCEPTED 202

#define WS_SVC_INFO "WSFPHPSvcInfo"

typedef struct ws_svc_info{
    axis2_svc_t *svc;
    axis2_msg_recv_t *msg_recv;
    axis2_hash_t *class_info;
    struct wsf_worker_t *php_worker;
    
    axis2_hash_t *ops_to_actions;
    axis2_hash_t *ops_to_functions;
    axis2_array_list_t *modules_to_engage;
    
    int request_xop;
    int use_mtom;
    int is_class;
    int secure;
    char *password_location;
    char *svc_name;
    char *svc_path;

}ws_svc_info_t;

typedef struct php_req_info{
	char *svr_name;
	long svr_port;
	char *http_protocol;
	char *content_encoding;
	char *soap_action;
	char *request_uri;
	long content_length;
	char *content_type;

	char *request_method;

	void *req_data;
    int req_data_length;

	void *result_payload;
    int result_length;

	char *transfer_encoding;
}php_req_info_t; 

/** functions */

#endif /* WS_COMMON_H */
