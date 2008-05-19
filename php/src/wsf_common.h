/*
 * Copyright 2005,2007 WSO2, Inc. http://wso2.com
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
    WS_NONE,
    WS_SVC_CLIENT,
    WS_SVC,
    WS_FAULT,
    WS_PARAM,
    WS_OBJECT_LAST
} ws_object_types_t;
/* }}} */

/** using input */
typedef enum ws_input_types
{
    WS_USING_STRING,
    WS_USING_MSG,
    WS_USING_INCORRECT_INPUT
} ws_input_types_t;

/** options for services array */

#define WS_PHP_LOG_PREFIX      "[WSF/PHP] "

#define WS_ACTIONS      "actions"
#define WS_OPERATIONS  "operations"
#define WS_OP_TO_URL_MAP "restmaping"
#define WS_OP_MEP      "opMEP"
#define WS_OP_PARAMS    "opParams"
#define WS_WSDL         "wsdl"
#define WS_CLASSMAP     "classmap"
#define WS_CLASSES      "classes"
#define WS_CONS_ARGS    "args"
#define WS_SERVICE_NAME "serviceName"
#define WS_PORT_NAME    "portName"


/** Options array options */

#define WS_IN_ONLY "IN_ONLY"
#define WS_IN_OUT "IN_OUT"

#define WS_TO				"to"    /** endpoint uri */

#define WS_USE_WSA     		"useWSA"
#define WS_ACTION			"action"        /** addressing options */
#define WS_FROM				"from"
#define WS_REPLY_TO			"replyTo"
#define WS_FAULT_TO			"faultTo"

#define WS_SOAP_ACTION      "SOAPAction"

#define WS_USES_XOP			"usesXOP"      /** MTOM XOP */
#define WS_DEFAULT_ATTACHEMENT_CONTENT_TYPE "defaultAttachmentContentType"
#define WS_ATTACHMENTS 			"attachments"
#define WS_CID2CONTENT_TYPE 	"cid2contentType"
#define WS_RESPONSE_XOP 		"responseXOP"
#define WS_REQUEST_XOP  		"requestXOP"
#define WS_USE_MTOM     		"useMTOM"
#define WS_TIMEOUT              "timeout"

/** Reliable Messaging */
#define WS_WILL_CONTINUE_SEQUENCE 	"willContinueSequence"
#define WS_LAST_MESSAGE 		    "lastMessage"
#define WS_RELIABLE			        "reliable"
#define WS_SEQUENCE_EXPIRY_TIME 	"sequenceExpiryTime"
#define WS_SEQUENCE_KEY      		"sequenceKey"

/** protocol */
#define WS_USE_SOAP			    "useSOAP"
#define WS_HTTP_METHOD 			"HTTPMethod"
#define WS_REST_LOCATION        "restLocation"

/** SSL certificate */
#define WS_SERVER_CERT 			"CACert"
#define WS_CLIENT_CERT 			"clientCert"
#define WS_PASSPHRASE  			"passphrase"

/** wsdl mode */
#define WS_BINDING_STYLE 		"bindingStyle"
#define WS_WSDL          		"wsdl"
#define WS_CACHE_WSDL           "cache_wsdl"
#define WS_CLASSMAP             "classmap"

/** http authentication */
#define WS_HTTP_AUTH_USERNAME      "httpAuthUsername"
#define WS_HTTP_AUTH_PASSWORD      "httpAuthPassword"
#define WS_HTTP_AUTH_TYPE          "httpAuthType"

/** proxy authentication */
#define WS_PROXY_AUTH_USERNAME      "proxyAuthUsername"
#define WS_PROXY_AUTH_PASSWORD      "proxyAuthPassword"
#define WS_PROXY_AUTH_TYPE          "proxyAuthType"

/** soap fault */
#define WS_FAULT_REASON 		"Reason"
#define WS_FAULT_ROLE   		"Role"
#define WS_FAULT_TEXT   		"text"
#define WS_FAULT_CODE   		"Code"
#define WS_FAULT_CODE_NS        "codens"
#define WS_FAULT_SUBCODE 		"Subcode"
#define WS_FAULT_DETAIL 		"Detail"

/** header options */
#define WS_INPUT_HEADERS        "inputHeaders"
#define WS_OUTPUT_HEADERS       "outputHeaders"
#define WS_HEADER_PREFIX        "prefix"
#define WS_HEADER_NS    		"ns"
#define WS_HEADER_LOCALNAME 	"name"
#define WS_HEADER_DATA     		"data"
#define WS_HEADER_STR           "str"
#define WS_HEADER_ROLE     		"role"
#define WS_HEADER_ACTOR         "actor"
#define WS_HEADER_MUST_UNDERSTAND 	"mustUnderstand"
#define WS_HEADER_PREFIX        "prefix"

/** security policy */
#define WS_POLICY_NAME 			"policy"
#define WS_SECURITY_TOKEN 		"securityToken"

#define WS_PROXY_HOST           "proxyHost"
#define WS_PROXY_PORT           "proxyPort"
/** end options */

#define WS_MSG_PAYLOAD_STR 		"str"

/** soap header attributes */

#define WS_SOAP_ROLE_NONE			        1
#define WS_SOAP_ROLE_NEXT			        2
#define WS_SOAP_ROLE_ULTIMATE_RECEIVER		3

#define WS_SOAP_ROLE_NONE_URI "http://www.w3.org/2003/05/soap-envelope/role/none"
#define WS_SOAP_ROLE_NEXT_URI "http://www.w3.org/2003/05/soap-envelope/role/next"
#define WS_SOAP_ROLE_ULTIMATE_RECEIVER_URI "http://www.w3.org/2003/05/soap-envelope/role/next"

#define WS_SOAP_1_1_NAMESPACE_URI "http://schemas.xmlsoap.org/soap/envelope/"
#define WS_SOAP_1_2_NAMESPACE_URI "http://www.w3.org/2003/05/soap-envelope"

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

#define WS_RM_RESPONSE_TIMEOUT "responseTimeout"
#define WS_RM_DEFAULT_RESPONSE_TIMEOUT "12"



/************ engaged module names *****************/
#define WS_MODULE_ADDRESSING "addressing"
#define WS_MODULE_SECURITY   "rampart"
#define WS_MODULE_RM         "sandesha2"

/** http status codes */
#define WS_HTTP_OK 200

#define WS_HTTP_INTERNAL_SERVER_ERROR 500

#define WS_HTTP_ACCEPTED 202

#define WS_SVC_INFO "WSFPHPSvcInfo"

#define WS_REQ_INFO "WSFPHPRequestInfo"

/*************************************************/

#define WS_SOAP_DOCUMENT 1
#define WS_SOAP_RPC 2

#define WS_SOAP_ENCODED 1
#define WS_SOAP_LITERAL 2

typedef struct wsf_svc_info
{

  axis2_svc_t *svc;
  
  axis2_msg_recv_t *msg_recv;
  
  struct wsf_worker_t *php_worker;
  
  axutil_hash_t *ops_to_actions;

  axutil_hash_t *ops_to_functions;
  
  axutil_array_list_t *modules_to_engage;
  
  axutil_hash_t *ops_to_classes;
  
  zval *class_args;
  
  HashTable *ht_op_params;
  
  int request_xop;
 
  int use_mtom;

  int enable_swa;
  
  zval *policy;
  
  zval *security_token;
  
  char *svc_name;

  char *port_name;

  int generated_svc_name;

  char *sig_model_string;

  zval *class_map;

  zval *wsdl_gen_class_map;

  char *wsdl;

  /**http://<domain>/<..*.php>/<loc_str>/ */
  char *loc_str;	


}
wsf_svc_info_t;


typedef struct wsf_request_info
{
    long svr_port;
    char *svr_name;
    char *http_protocol;
    char *soap_action;
    char *request_uri;
    char *query_string;
    long content_length;
    char *content_type;
    char *request_method;
    void *request_data;
    int request_data_length;
    
	char *transfer_encoding;
	
	/** REST parameter count */
	int param_count;
	/** parameters array */
	char ***params;
} wsf_request_info_t;

typedef struct wsf_response_info
{
	void *response_data;
	int  response_length;
	char *http_protocol;
	int  http_status_code;
	char *http_status_code_name;
	char *content_type;
}wsf_response_info_t;

/** functions */

#endif /* WS_COMMON_H */
