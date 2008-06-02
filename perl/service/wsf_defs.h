/*
 * Copyright 2005 - 2008 WSO2, Inc. http://wso2.com
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

#ifndef WSF_DEFS
#define WSF_DEFS

#include <axis2_svc.h>
#include <axis2_msg_recv.h>
#include <axiom.h>

#ifdef WIN32
	#define WSF_CALL __stdcall
#else
	#define WSF_CALL
#endif

#ifdef WIN32
	#ifndef snprintf
		#define snprintf sprintf_s
	#endif
#endif

typedef struct wsf_svc_info
{
    axis2_svc_t* svc;
    axis2_msg_recv_t* msg_recv;
    struct wsf_worker_t* perl_worker;
    axutil_hash_t* ops_to_actions;
    axutil_hash_t* ops_to_functions;
    axutil_array_list_t* modules_to_engage;
    axutil_hash_t* ops_to_classes;
    int request_xop;
    int use_mtom;
    char* svc_name;
    char* port_name;
    int generated_svc_name;
    char* op_name;
    char *script_filename;
}
wsf_svc_info_t;

/* axis2 object types */
typedef enum ws_object_types
{
    WS_NONE,
    WS_SVC_CLIENT,
    WS_SVC,
    WS_FAULT,
    WS_PARAM,
    WS_OBJECT_LAST
} 
ws_object_types_t;

/** using input */
typedef enum ws_input_types
{
    WS_USING_STRING,
    WS_USING_MSG,
    WS_USING_INCORRECT_INPUT
} 
ws_input_types_t;

typedef struct wsf_req_info
{
    long svr_port;
    char *svr_name;
    char *http_protocol;
    char *content_encoding;
    char *soap_action;
    char *request_uri;
    char *query_string;
    long content_length;
    char *content_type;
    char *request_method;
    char *req_data;
    int req_data_length;
    char *result_payload;
    int result_length;
    char *transfer_encoding;
	char *out_content_type;
} 
wsf_req_info_t;

#endif
