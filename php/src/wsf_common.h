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

#define WS_LOCATION         "location"
#define WS_USE              "use"
#define WS_USE_SOAP_IN_OUT  "use_soap_in_out"
#define WS_STYLE            "style"

/* defaults to WS_SOAP_12 */
#define WS_SOAP_VERSION  "soap_version" 
#define WS_SERVICE_NAME  "service_name"
#define WS_SOAP_ACTION	"soap_action"

/* defaults to true */
#define WS_THROW_EXCEPTION_ON_FAULT	"throw_exception_on_fault"
/* defaults to false */
#define WS_USE_SEPERATE_LISTENER	"use_seperate_listener"
#define WS_TIME_OUT				"time_out"


/* addressing specific properties */
#define WS_ADDR_ACTION		"ADDR_ACTION"
#define WS_FAULT_TO			"fault_to"
#define WS_FROM				"from"
#define WS_TRANSPORT_IN_PROTOCOL	"transport_in_protocol"
#define WS_MESSAGE_ID		"message_id"
#define WS_RELATES_TO		"relates_to"
#define WS_REPLY_TO			"reply_to"
#define WS_REFERENCE_PARAMETERS	"reference_parameters"
#define WS_SENDER_TRANSPORT_PROTOCOL	"sender_transport_protocol"
#define WS_TO				"to"

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


/* sandesha */
#define AXIS2_SANDESHA_LAST_MESSAGE "Sandesha2LastMessage"

/* security specific properties */
#define WS_USER 			"user"
#define WS_PASSWORD 		"password"
#define WS_PASSWORD_TYPE	"passwordType"
#define WS_PASSWORD_TEXT	"passwordText"
#define WS_PASSWORD_DIGEST	"passwordDigest"

#define WS_Basic256Rsa15	101
#define WS_Basic192Rsa15	102
#define WS_Basic128Rsa15	103
#define WS_TripleDesRsa15	104

#define WS_Aes128		"http://www.w3.org/2001/04/xmlenc#aes128-cbc"
#define WS_Aes192		"http://www.w3.org/2001/04/xmlenc#aes192-cbc"
#define WS_Aes256		"http://www.w3.org/2001/04/xmlenc#aes256-cbc"
#define WS_TripleDes	"http://www.w3.org/2001/04/xmlenc#tripledes-cbc"
#define WS_KwRsa15		"http://www.w3.org/2001/04/xmlenc#rsa-1_5"

#define WS_SECURITY_TOKEN_TYPE_ENC 150
#define WS_SECURITY_TOKEN_TYPE_DEC 151

#define WS_ALGORITHM_ASYMMETRIC 161
#define WS_ALGORITHM_SYMMETRIC	162

/* for annonymous stuff*/
#define ANON_SERVICE_NAME	"__ANONYMOUS_SERVICE__"
#define ANON_OUT_ONLY_OP_NAME	"__OPERATION_OUT_ONLY__"
#define ANON_ROBUST_OUT_ONLY_OP_NAME	"__OPERATION_ROBUST_OUT_ONLY__"
#define	ANON_OUT_IN_OP_NAME	"__OPERATION_OUT_IN__"

/** sandesha2 */
#define WSF_SANDESHA2_CLIENT_ACKS_TO "Sandesha2AcksTo"
#define WSF_SANDESHA2_CLIENT_LAST_MESSAGE "Sandesha2LastMessage"
#define WSF_SANDESHA2_CLIENT_OFFERED_SEQ_ID "Sandesha2OfferedSequenceId"
#define WSF_SANDESHA2_CLIENT_DEBUG_MODE "Sandesha2DebugMode"
#define WSF_SANDESHA2_CLIENT_SEQ_KEY "Sandesha2SequenceKey"
#define WSF_SANDESHA2_CLIENT_MESSAGE_NUMBER "Sandesha2MessageNumber"
#define WSF_SANDESHA2_CLIENT_RM_SPEC_VERSION "Sandesha2RMSpecVersion"
#define WSF_SANDESHA2_CLIENT_DUMMY_MESSAGE "Sandesha2DummyMessage"

#define WSF_SANDESHA2_SPEC_VERSION_1_0 "Spec_2005_02"
#define WSF_RM_VERSION_1_0  1
#define WSF_SANDESHA2_SPEC_VERSION_1_1 "Spec_2006_08"
#define WSF_RM_VERSION_1_1  2

#define WSF_SANDESHA_CLIENT_PROP "wsf_cli_prop"

/************ engaged module names *****************/
#define WS_MODULE_ADDRESSING AXIS2_MODULE_ADDRESSING
#define WS_MODULE_SECURITY   "rampart"
#define WS_MODULE_RM         "sandesha2"

#define WS_MODULE_ADDR_KEY     "ws_addressing"
#define WS_MODULE_RM_KEY       "ws_sandesha2"
#define WS_MODULE_SEC_KEY      "ws_rampart"

#define WS_HTTP_OK 200

#define WS_HTTP_INTERNAL_SERVER_ERROR 500

#define WS_HTTP_ACCEPTED 202

#define WS_SVC_INFO "Axis2PHPSvcInfo"

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
