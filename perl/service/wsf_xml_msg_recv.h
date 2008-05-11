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

#ifndef WSF_XML_MSG_RECV_H
#define WSF_XML_MSG_RECV_H

#include "wsf_defs.h"
#include "wsf_constants.h"

axis2_msg_recv_t*
wsf_xml_msg_recv_create (const axutil_env_t* env);

axis2_status_t AXIS2_CALL 
wsf_xml_msg_recv_invoke_business_logic_sync (axis2_msg_recv_t*   msg_recv,
											 const axutil_env_t* env,
    										 axis2_msg_ctx_t*    in_msg_ctx,
    							             axis2_msg_ctx_t*    out_msg_ctx);

static axis2_char_t* 
wsf_xml_msg_recv_get_method_name (axis2_msg_ctx_t*    msg_ctx,
    				              const axutil_env_t* env);

static axiom_node_t* 
wsf_xml_msg_recv_invoke_wsmsg (const axutil_env_t* env,
							   axis2_char_t* soap_ns,
							   axis2_char_t* op_name,
							   axiom_node_t* om_node,
							   axis2_msg_ctx_t* out_msg_ctx,
							   char* classname,
							   wsf_svc_info_t* svc_info,
							   int use_mtom,
							   int request_xop);

static axiom_node_t* 
wsf_xml_msg_recv_invoke_mixed (const axutil_env_t* env,
							   wsf_svc_info_t* svc_info,
							   axis2_msg_ctx_t* in_msg_ctx,
							   axis2_msg_ctx_t* out_msg_ctx,
							   axis2_char_t* function_name,
							   axis2_char_t* class_name);

#endif /* WS_XML_MSG_RECV_H */
