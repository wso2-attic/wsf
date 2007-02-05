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

#define READ_SIZE  32

struct wsf_worker_t
{
   axis2_conf_ctx_t *conf_ctx;
};

wsf_worker_t * wsf_worker_create (const axis2_env_t *env, 
								axis2_char_t *repo_path)
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
	worker->conf_ctx = build_conf_ctx(env, repo_path);

	if(NULL == worker->conf_ctx) {
		wsf_worker_free(worker, env);
		return NULL;
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
		/*
		AXIS2_CONF_CTX_FREE(worker->conf_ctx, env);
		worker->conf_ctx = NULL;
		*/
	}
	AXIS2_FREE(env->allocator, worker);
}

int wsf_worker_process_request(
        wsf_worker_t *worker, 
        const axis2_env_t *env, 
        php_req_info_t *request,
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
	
	axiom_soap_envelope_t *soap_envelope = NULL;
    axis2_property_t *property = NULL;
    axis2_url_t *url = NULL;
	axis2_qname_t *transport_qname = NULL;
	
   
	int content_length = -1;
	int send_status = -1;
	axis2_bool_t processed = AXIS2_FALSE;
	
	
	axis2_char_t *http_version = NULL;
	axis2_char_t *soap_action = NULL;
	axis2_char_t *ctx_written = NULL;
	axis2_char_t *encoding_header_value = NULL;
	axis2_char_t *req_url = NULL;
	axis2_char_t *body_string = NULL;
	axis2_char_t *content_type = NULL;
	axis2_char_t *ctx_uuid = NULL;
    axis2_char_t *is_class = NULL;
    
    TSRMLS_FETCH();
	
	AXIS2_PARAM_CHECK(env->error, request, AXIS2_CRITICAL_FAILURE);
   
	conf_ctx = worker->conf_ctx;
	url = axis2_url_create(env, "http", request->svr_name, 
                        request->svr_port, request->request_uri);
	
    if(NULL == conf_ctx) {
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_CONFIGURATION_CONTEXT,
							AXIS2_FAILURE);
		return AXIS2_CRITICAL_FAILURE;
	}
    
	content_length = request->content_length;
	http_version = request->http_protocol;
	req_url = AXIS2_URL_TO_EXTERNAL_FORM(url, env);
    
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

	out_desc = AXIS2_CONF_GET_TRANSPORT_OUT(AXIS2_CONF_CTX_GET_CONF
					(worker->conf_ctx, env), env, AXIS2_TRANSPORT_ENUM_HTTP);

	in_desc = AXIS2_CONF_GET_TRANSPORT_IN(AXIS2_CONF_CTX_GET_CONF
				(worker->conf_ctx, env), env, AXIS2_TRANSPORT_ENUM_HTTP);
	

	
    msg_ctx = axis2_msg_ctx_create(env, conf_ctx, in_desc, out_desc);
	
    AXIS2_MSG_CTX_SET_SERVER_SIDE(msg_ctx, env, AXIS2_TRUE);
    
    AXIS2_MSG_CTX_SET_SVC(msg_ctx, env, svc_info->svc); 
	
    /** create transport out description */
	{
		axis2_property_t *out_stream_prop = NULL;
		
		out_stream_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_REQUEST,
			AXIS2_TRUE ,axis2_stream_free_void_arg, out_stream);

		AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, AXIS2_TRANSPORT_OUT, 
			out_stream_prop, AXIS2_FALSE);
	}
    /** generate uuid for context */
	ctx_uuid = axis2_uuid_gen(env);
    AXIS2_MSG_CTX_SET_SVC_GRP_CTX_ID(msg_ctx, env, ctx_uuid);
    AXIS2_FREE(env->allocator, ctx_uuid);
    
    /** create transport in description */
	{
		axis2_property_t *trns_in_desc_prop = NULL;
		php_out_transport_info = wsf_out_transport_info_create(env, request);
		trns_in_desc_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_REQUEST, AXIS2_TRUE,
			wsf_out_transport_info_free_void_arg, php_out_transport_info);
		AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, AXIS2_HTTP_OUT_TRANSPORT_INFO,
			trns_in_desc_prop, AXIS2_FALSE);
	}
   
    /* service path */
	{
		axis2_property_t *svc_path_prop = NULL;
		svc_path_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_REQUEST,
			AXIS2_TRUE,NULL, AXIS2_STRDUP(svc_info->svc_path, env));
		AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, "WS_SVC_PATH", svc_path_prop, AXIS2_FALSE);
	}
    
    if(request->transfer_encoding){
		axis2_property_t *tns_enc_prop = NULL;
        tns_enc_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_REQUEST,AXIS2_TRUE,
			NULL, AXIS2_STRDUP(request->transfer_encoding, env));
        AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, AXIS2_HTTP_HEADER_TRANSFER_ENCODING,
			tns_enc_prop, AXIS2_FALSE);
    }
    
    /** store svc_info struct as a property */  
	{
		axis2_property_t *svc_info_prop = NULL;
		svc_info_prop = axis2_property_create_with_args(env, AXIS2_SCOPE_REQUEST,
			AXIS2_TRUE,NULL, svc_info);				
		AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, WS_SVC_INFO, 
			svc_info_prop, AXIS2_FALSE);
	}
    /** use MTOM property */
    if(svc_info->use_mtom == 1){
	    axis2_property_t *mtom_property = axis2_property_create(env);
        if (mtom_property){
            AXIS2_PROPERTY_SET_SCOPE(mtom_property, env, AXIS2_SCOPE_REQUEST);
            AXIS2_PROPERTY_SET_VALUE(mtom_property, env, AXIS2_STRDUP(AXIS2_VALUE_TRUE, env));
            AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, AXIS2_ENABLE_MTOM, mtom_property, AXIS2_FALSE);
        }
    }  
    if(svc_info->secure == 1){
        axis2_property_t *sec_prop = NULL;
        axis2_param_t *inflow_param = NULL;
        axis2_param_t *outflow_param = NULL;
        axis2_array_list_t *inlist = NULL;
        axis2_array_list_t *outlist = NULL;
        axis2_param_t *sec_param = NULL;
        axis2_param_t *param = NULL;
        axis2_char_t *tmp = NULL;
        axis2_char_t *tmp1 = NULL;
        axis2_char_t *pwcb = NULL;
        
        axis2_property_t *prop = NULL;
        inflow_param = axis2_param_create(env, "InflowSecurity", NULL); 
        inlist = axis2_array_list_create(env, 4);
        
        sec_prop = axis2_property_create(env);
        AXIS2_PROPERTY_SET_SCOPE(sec_prop, env, AXIS2_SCOPE_REQUEST);
        AXIS2_PROPERTY_SET_VALUE(sec_prop, env, AXIS2_STRDUP("UsernameToken", env));
        AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, "items", sec_prop, AXIS2_FALSE);
    
        tmp = AXIS2_STRDUP("htpwcb", env);
        tmp1 = AXIS2_STRACAT(AXIS2_LIB_PREFIX, tmp, env);
        pwcb = AXIS2_STRACAT(tmp1, AXIS2_LIB_SUFFIX, env);
        AXIS2_FREE(env->allocator ,tmp);
        AXIS2_FREE(env->allocator, tmp1);

        sec_prop = axis2_property_create(env);
        AXIS2_PROPERTY_SET_SCOPE(sec_prop, env, AXIS2_SCOPE_REQUEST);
        AXIS2_PROPERTY_SET_VALUE(sec_prop, env, pwcb);
        AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, "passwordCallbackClass", sec_prop, AXIS2_FALSE);
        AXIS2_SVC_ADD_PARAM(svc_info->svc, env, inflow_param);

		prop = axis2_property_create(env);
        if (prop){
            AXIS2_PROPERTY_SET_SCOPE(prop, env, AXIS2_SCOPE_REQUEST);
            AXIS2_PROPERTY_SET_VALUE(prop, env, AXIS2_STRDUP(svc_info->password_location, env));
            AXIS2_MSG_CTX_SET_PROPERTY(msg_ctx, env, "callbackSpecificProperty", prop, AXIS2_FALSE);
            }
        }  
          
	soap_action = request->soap_action;
    if(soap_action == NULL)
        soap_action = "";
        
	request_body = axis2_stream_create_php(env, request TSRMLS_CC);
	if(NULL == request_body) {
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error occured in"
							" creating input stream.");
		return AXIS2_CRITICAL_FAILURE;
	}
    
	if(0 == strcmp("GET", request->request_method)) {
		processed = axis2_http_transport_utils_process_http_get_request
						(env, msg_ctx, request_body, out_stream,
						content_type ,soap_action,
						req_url,
						conf_ctx, 
						axis2_http_transport_utils_get_request_params(env,
						(axis2_char_t*)req_url));

		if(AXIS2_FALSE == processed) {
			body_string = axis2_http_transport_utils_get_services_html(env, 
			conf_ctx);
			request->content_type = "text/html";
		  	send_status = WS_HTTP_OK; 
		}
        if(NULL != body_string)
        {
            request->result_payload = body_string;
            request->result_length = strlen(body_string);
        }
	} else if (0 == strcmp("POST", request->request_method)) {
		axis2_status_t status = AXIS2_FAILURE;
        axis2_property_t *prop = NULL;
        
		status = axis2_http_transport_utils_process_http_post_request
						(env, msg_ctx, request_body, out_stream,
						content_type , content_length,
						soap_action,
						(axis2_char_t*)req_url);
	
        if(status == AXIS2_FAILURE) {
			axis2_msg_ctx_t *fault_ctx = NULL;
			axis2_engine_t *engine = axis2_engine_create(env, conf_ctx);
			if(NULL == engine) {
				send_status =  WS_HTTP_INTERNAL_SERVER_ERROR; 
			}
			fault_ctx = AXIS2_ENGINE_CREATE_FAULT_MSG_CTX(engine, env, msg_ctx);
			AXIS2_ENGINE_SEND_FAULT(engine, env, fault_ctx);
			body_string = wsf_worker_get_bytes(env, out_stream);
			send_status =  WS_HTTP_INTERNAL_SERVER_ERROR;
            if(NULL != body_string){
                request->result_payload = body_string;
                request->result_length = strlen(body_string);
            }                
		}
   }
	if(-1 == send_status) {
    
		op_ctx = AXIS2_MSG_CTX_GET_OP_CTX(msg_ctx, env);
		if(NULL != op_ctx) {
			axis2_ctx_t *ctx = AXIS2_OP_CTX_GET_BASE(AXIS2_MSG_CTX_GET_OP_CTX(
									msg_ctx, env), env);
			if (NULL != ctx) {
				property = AXIS2_CTX_GET_PROPERTY(ctx, env, 
											AXIS2_RESPONSE_WRITTEN, AXIS2_FALSE);
				if(property) {
					ctx_written = AXIS2_PROPERTY_GET_VALUE(property, env);
					property = NULL;
				}
			}
		}
        
		if(NULL != ctx_written && AXIS2_STRCASECMP(ctx_written, "TRUE") == 0) {
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
    return send_status;
}


axis2_conf_ctx_t* wsf_worker_get_conf_ctx(wsf_worker_t *worker,
                              const axis2_env_t *env)
{
	return worker->conf_ctx;
}
