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

#include "wsf_worker.h"
#include <axis2_http_transport.h>
#include <axis2_conf.h>
#include <axis2_string.h>
#include <axis2_msg_ctx.h>
#include <axis2_http_out_transport_info.h>
#include <axis2_http_transport_utils.h>
#include <axis2_op_ctx.h>
#include <axis2_engine.h>
#include <axis2_uuid_gen.h>
#include <axis2_conf_init.h>
#include <axis2_url.h>
#include <axiom_soap_const.h>
#include <axiom_soap.h>
#include "wsf_out_transport_info.h"
#include "wsf_stream.h"
#include "wsf_util.h"
#include "wsf_policy.h"

#define READ_SIZE 32

struct wsf_worker_t
{
   axis2_conf_ctx_t *conf_ctx;
};

wsf_worker_t * wsf_worker_create (const axis2_env_t *env, 
								  axis2_char_t *repo_path,
								  axis2_char_t *rm_db_dir)
{
	wsf_worker_t *worker = NULL;
	AXIS2_ENV_CHECK(env, NULL);

	worker = (wsf_worker_t *)AXIS2_MALLOC(env->allocator, 
		sizeof(wsf_worker_t));
	if(!worker)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}
	worker->conf_ctx = NULL;
	worker->conf_ctx = axis2_build_conf_ctx(env, repo_path);

	if(NULL == worker->conf_ctx) {
		wsf_worker_free(worker, env);
		return NULL;
	}
	if(rm_db_dir){
		axis2_conf_t *conf = NULL;
		axis2_module_desc_t *module_desc = NULL;
		axis2_param_t *param = NULL;
		axis2_qname_t *sandesha2_qname = NULL;

		sandesha2_qname = axis2_qname_create(env, "sandesha2", NULL, NULL);

		conf = axis2_conf_ctx_get_conf(worker->conf_ctx, env);
		module_desc = axis2_conf_get_module(conf, env, sandesha2_qname);
		if(module_desc){
			param = axis2_module_desc_get_param(module_desc, env, "sandesha2_db");
			if(param){
				axis2_param_set_value(param, env, rm_db_dir);	
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsf_svr] rm_db_dir %s", rm_db_dir);
			}
		}
	}
	return worker;
}

axis2_char_t* wsf_worker_get_bytes(const axis2_env_t *env, 
                        axis2_stream_t *stream)
{
    
	axis2_stream_t *tmp_stream = NULL;
	int return_size = -1;
	axis2_char_t *buffer = NULL;
    
	AXIS2_ENV_CHECK(env, NULL);
	AXIS2_PARAM_CHECK(env->error, stream, NULL);
    
	tmp_stream = axis2_stream_create_basic(env);
	while(1) {
		int read = 0;
		int write = 0;
        
		char buf[READ_SIZE];
		read = AXIS2_STREAM_READ(stream, env, buf, READ_SIZE);
		if(read < 0) {
			break;
		}
		write = AXIS2_STREAM_WRITE(tmp_stream, env, buf, read);
		if(read < (READ_SIZE -1)) {
			break;
		}
	}
	return_size = AXIS2_STREAM_BASIC_GET_LEN(tmp_stream, env);

	if(return_size > 0) {
		buffer = (char *)AXIS2_MALLOC(env->allocator, sizeof(char)*
													(return_size +2));
		return_size = AXIS2_STREAM_READ(tmp_stream, env, buffer,
													return_size + 1);
		buffer[return_size + 1] = '\0';
	}
	AXIS2_STREAM_FREE(tmp_stream, env);
	return buffer;
}

void wsf_worker_free(wsf_worker_t *worker, 
		     const axis2_env_t *env)
{
	if(!worker)
		return;
	if(worker->conf_ctx != NULL) {
		axis2_conf_ctx_free(worker->conf_ctx, env);
		worker->conf_ctx = NULL;
	}
	AXIS2_FREE(env->allocator, worker);
}

int wsf_worker_process_request(
        wsf_worker_t *worker, 
        axis2_env_t *env, 
        wsf_req_info_t *request,
	ws_svc_info_t *svc_info)
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_msg_ctx_t *msg_ctx = NULL;
	axis2_op_ctx_t *op_ctx = NULL;
	
	axis2_http_out_transport_info_t *php_out_transport_info = NULL;
	axis2_transport_out_desc_t *out_desc = NULL;
	axis2_transport_in_desc_t *in_desc = NULL;
	
	
	axis2_stream_t *request_body = NULL;
	axis2_stream_t *out_stream = NULL;
	
    	axis2_url_t *url = NULL;
	axis2_char_t *request_uri_with_query_string;
	
   
	int content_length = -1;
	int send_status = -1;
	
	
	axis2_char_t *http_version = NULL;
	axis2_char_t *soap_action = NULL;
	axis2_string_t *soap_action_str = NULL;
	axis2_char_t *encoding_header_value = NULL;
	axis2_char_t *req_url = NULL;
	axis2_string_t *req_url_str = NULL;
	axis2_char_t *body_string = NULL;
	axis2_char_t *content_type = NULL;
	axis2_char_t *ctx_uuid = NULL;
	axis2_string_t *ctx_uuid_str = NULL;
	/*
	axis2_char_t *is_class = NULL;
        */
	TSRMLS_FETCH();
	
	if(!request)
		return -1;

	conf_ctx = worker->conf_ctx;
	if(request->query_string){       
		request_uri_with_query_string = malloc((strlen(request->request_uri) + 5 + strlen(request->query_string)));
		sprintf(request_uri_with_query_string, "%s?%s", request->request_uri, request->query_string);
	}else{
		request_uri_with_query_string =  request->request_uri;
	}

	url = axis2_url_create(env, "http", request->svr_name, 
			request->svr_port, request_uri_with_query_string);

        if(NULL == conf_ctx) {
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_CONFIGURATION_CONTEXT,
							AXIS2_FAILURE);
		return AXIS2_CRITICAL_FAILURE;
	}
    
	content_length = request->content_length;
	http_version = request->http_protocol;
	req_url = axis2_url_to_external_form(url, env);
        req_url_str = axis2_string_create(env, req_url);
    
	content_type = (axis2_char_t*) request->content_type;

	if(NULL == http_version) {
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_HTTP_VERSION, 
							AXIS2_FAILURE);
		return AXIS2_CRITICAL_FAILURE;
	}
	
	out_stream = axis2_stream_create_basic(env);
	
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Client HTTP version %s", 
						http_version);
	
	encoding_header_value = request->content_encoding;

	out_desc = axis2_conf_get_transport_out(axis2_conf_ctx_get_conf
					(worker->conf_ctx, env), env, AXIS2_TRANSPORT_ENUM_HTTP);

	in_desc =axis2_conf_get_transport_in(axis2_conf_ctx_get_conf
				(worker->conf_ctx, env), env, AXIS2_TRANSPORT_ENUM_HTTP);
	

	msg_ctx = axis2_msg_ctx_create(env, conf_ctx, in_desc, out_desc);
	

	axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);
    
	axis2_msg_ctx_set_svc(msg_ctx, env, svc_info->svc);
	
	if(svc_info->op_name){
		axis2_op_t *op = NULL;
        	op = axis2_svc_get_op_with_name(svc_info->svc, env, svc_info->op_name);
		if(op){
			axis2_msg_ctx_set_op(msg_ctx, env, op);
		}
	} 
	
    	/** create transport out description */
	{
		axis2_property_t *out_stream_prop = NULL;
		
		out_stream_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_REQUEST,
			AXIS2_TRUE ,axis2_stream_free_void_arg, out_stream);

		axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_TRANSPORT_OUT, 
			out_stream_prop, AXIS2_FALSE);
        	axis2_msg_ctx_set_transport_out_stream(msg_ctx, env, out_stream);
	}
	
	/** generate uuid for context */
	ctx_uuid = axis2_uuid_gen(env);
    	ctx_uuid_str = axis2_string_create(env, ctx_uuid);
    	axis2_msg_ctx_set_svc_grp_ctx_id(msg_ctx, env, ctx_uuid_str);
    	AXIS2_FREE(env->allocator, ctx_uuid);
    	axis2_string_free(ctx_uuid_str, env);
    
    	php_out_transport_info = wsf_out_transport_info_create(env, request);
    	axis2_msg_ctx_set_http_out_transport_info(msg_ctx, env, php_out_transport_info);
   
    	if(request->transfer_encoding){
        	axis2_msg_ctx_set_transfer_encoding(msg_ctx, env, axis2_strdup(request->transfer_encoding, env));
    	}
    
    /** store svc_info struct as a property */  
	{
		axis2_property_t *svc_info_prop = NULL;
		svc_info_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_REQUEST,
			AXIS2_TRUE,NULL, svc_info);				
		axis2_msg_ctx_set_property(msg_ctx, env, WS_SVC_INFO, 
			svc_info_prop, AXIS2_FALSE);
	}
    /** use MTOM property */
    	if(svc_info->use_mtom == 1){
        	axis2_msg_ctx_set_doing_mtom(msg_ctx, env, AXIS2_TRUE);
    	}  
    	
	if(svc_info->security_token != NULL && svc_info->policy != NULL){
		/**  call security function here */
		axis2_conf_t *conf = NULL;
		conf = axis2_conf_ctx_get_conf(worker->conf_ctx, env);
		ws_policy_handle_server_security(svc_info->security_token, svc_info->policy,
			env, svc_info->svc, conf TSRMLS_CC);
    	}  
          
	soap_action = request->soap_action;
	if(soap_action == NULL)
        	soap_action = "";
    
    	soap_action_str = axis2_string_create(env, soap_action);
    
	request_body = axis2_stream_create_php(env, request TSRMLS_CC);
	
	if(NULL == request_body) {
	
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error occured in"
							" creating input stream.");
		return AXIS2_CRITICAL_FAILURE;
	}
    
	if(0 == strcmp("GET", request->request_method)) {
		
		axis2_bool_t processed = AXIS2_FALSE;
		
		processed = axis2_http_transport_utils_process_http_get_request	(env, 
						msg_ctx, 
						request_body, 
						out_stream,
						content_type ,soap_action_str,
						req_url,
						conf_ctx, 
						axis2_http_transport_utils_get_request_params(env,(axis2_char_t*)req_url)
					);

		if(AXIS2_FALSE == processed) {
			body_string = axis2_http_transport_utils_get_services_html(env, conf_ctx);
			request->content_type = "text/html";
		  	send_status = WS_HTTP_OK; 
		}
        	if(NULL != body_string){
            		request->result_payload = body_string;
            		request->result_length = strlen(body_string);
        	}
	} else if (0 == strcmp("POST", request->request_method)) {
		axis2_status_t status = AXIS2_FAILURE;
        	
		status = axis2_http_transport_utils_process_http_post_request
						(env, msg_ctx, request_body, out_stream,
						content_type , content_length,
						soap_action_str,
						(axis2_char_t*)req_url);
	
        	if(status == AXIS2_FAILURE) {
			axis2_msg_ctx_t *fault_ctx = NULL;
			axis2_engine_t *engine = axis2_engine_create(env, conf_ctx);
			if(NULL == engine) {
				send_status =  WS_HTTP_INTERNAL_SERVER_ERROR; 
			}
			fault_ctx = axis2_engine_create_fault_msg_ctx(engine, env, msg_ctx);
			axis2_engine_send_fault(engine, env, fault_ctx);
			body_string = wsf_worker_get_bytes(env, out_stream);
			send_status =  WS_HTTP_INTERNAL_SERVER_ERROR;
		        if(NULL != body_string){
                		request->result_payload = body_string;
		                request->result_length = strlen(body_string);
            		}                
		}
   	}
	if(-1 == send_status) {
    
		op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
		if(axis2_op_ctx_get_response_written(op_ctx, env)) {
			int rlen = 0;
			int readlen = 0;
            		void *val = NULL;
            	
			send_status = WS_HTTP_OK;
            
			rlen = AXIS2_STREAM_BASIC_GET_LEN(out_stream, env);
            		val = AXIS2_MALLOC(env->allocator, sizeof(char)*(rlen+1));
			readlen = AXIS2_STREAM_READ(out_stream, env, val, rlen+1);
            
        	    	if(readlen == rlen){
                		request->result_payload = val;
                		request->result_length = readlen;
	            	}
		}else{
			send_status = WS_HTTP_ACCEPTED;
		}
   	}	

   	axis2_string_free(soap_action_str, env);
    
    return send_status;
}


axis2_conf_ctx_t* wsf_worker_get_conf_ctx(wsf_worker_t *worker,
                              const axis2_env_t *env)
{
	return worker->conf_ctx;
}
