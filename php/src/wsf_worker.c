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
    
#include "wsf_worker.h"
#include <axis2_http_transport.h>
#include <axis2_conf.h>
#include <axutil_string.h>
#include <axis2_msg_ctx.h>
#include <axis2_http_out_transport_info.h>
#include <axis2_http_transport_utils.h>
#include <axis2_op_ctx.h>
#include <axis2_engine.h>
#include <axutil_uuid_gen.h>
#include <axis2_conf_init.h>
#include <axutil_url.h>
#include <axiom_soap_const.h>
#include <axiom_soap.h>
#include "wsf_out_transport_info.h"
#include "wsf_stream.h"
#include "wsf_util.h"
#include "wsf_policy.h"
    
#define READ_SIZE 32
struct wsf_worker_t 
{
    axis2_conf_ctx_t * conf_ctx;
};
void WSF_CALL
wsf_worker_dummy_free_function (
    void *obj, const axutil_env_t * env)
{
    return;
}

axis2_op_t *AXIS2_CALL
wsf_worker_get_op_with_method_and_location(
    const axis2_svc_t * svc,
    const axutil_env_t * env,
    const axis2_char_t * method,
    const axis2_char_t * location,
    int * param_count,
    axis2_char_t **** params)
{
    axutil_array_list_t *op_list = NULL;
    axis2_char_t *loc_str = NULL;
    axis2_char_t *loc_str_tmp = NULL;
    axis2_char_t *rindex = NULL;
    axis2_bool_t pass_one = AXIS2_TRUE;
    axis2_bool_t loop_state = AXIS2_TRUE;
    AXIS2_PARAM_CHECK(env->error, location, NULL);
    AXIS2_PARAM_CHECK(env->error, method, NULL);
    
    loc_str = axutil_strtrim(env, location, NULL);
    if (!loc_str)
    {
        return NULL;
    }
    loc_str_tmp = loc_str;
    if (loc_str_tmp[0] == '/')
    {
        loc_str_tmp++;
    }
    if (strchr(loc_str_tmp, '?'))
    {
        axis2_char_t *temp = NULL;

        temp = strchr(loc_str_tmp, '?');
        temp[0] = '\0';
    }
    while(loop_state)
    {
        rindex = axutil_rindex(loc_str_tmp, '/');

        if (rindex && *rindex)
        {
            loc_str_tmp = axutil_string_substring_ending_at(loc_str_tmp, (int)(rindex - loc_str_tmp));
            /* We are sure that the difference lies within the int range */
        }
        else if (pass_one)
        {
            pass_one = AXIS2_FALSE;
        }
        else
        {
            int i = 0;
            i = (int)strlen(loc_str_tmp);
            /* We are sure that the difference lies within the int range */
            if (i == 0)
            {
                break;
            }
            loc_str_tmp[i - 1] = '\0';
        }

        if (!loc_str_tmp || !*loc_str_tmp)
        {
            break;
        }
        op_list = axis2_svc_get_rest_op_list_with_method_and_location(svc, env,
                                                                      method, loc_str_tmp);
        if (op_list && axutil_array_list_size(op_list, env) != 0)
        {
            int i = 0;
            int size = 0;

            size = axutil_array_list_size(op_list, env);
            for (i = 0; i < size; i++)
            {
                axis2_op_t *op_temp = NULL;
                axis2_char_t *op_location = NULL;
                int match_count = 0;
                axis2_char_t ***matches = NULL;
                axis2_status_t status = AXIS2_FAILURE;

                op_temp = axutil_array_list_get(op_list, env, i);
                op_location = axis2_op_get_rest_http_location(op_temp, env);
                if (!op_location)
                {
                    continue;
                }
                status = axutil_parse_rest_url_for_params(env, op_location, location,
                                                          &match_count, &matches);
                if (status == AXIS2_SUCCESS)
                {
                    *params = matches;
                    *param_count = match_count;
                    AXIS2_FREE (env->allocator, loc_str);
                    return op_temp;
                }
                else if (matches)
                {
                    for (i = 0; i < match_count; i++)
                    {
                        AXIS2_FREE (env->allocator, matches[i]);
                    }
                    AXIS2_FREE (env->allocator, matches);
                }
            }
        }
    }
    AXIS2_FREE (env->allocator, loc_str);
    return NULL;
}

axis2_op_t *
wsf_worker_find_op_and_params_with_location_and_method(
	axutil_env_t *env, 
	axis2_char_t *method, 
	wsf_svc_info_t *svc_info,
	wsf_request_info_t *req_info,
	axis2_msg_ctx_t *msg_ctx)
{
	axis2_op_t *op = NULL;
	int param_count = 0;
	char ***params = NULL;
	if(svc_info->loc_str)
	{
		op = wsf_worker_get_op_with_method_and_location(svc_info->svc, 
			env, method, svc_info->loc_str, &param_count, &params);
	}
	req_info->param_count = param_count;
	req_info->params = params;

   if (op)
   {
         AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsfphp] Operation found using target endpoint uri fragment");
    }else{
		int i = 0;
		int j = 0;
		axutil_array_list_t *supported_rest_methods = NULL;
		const axis2_char_t *http_method = NULL;
		axis2_char_t *rest_methods[] = {AXIS2_HTTP_GET, AXIS2_HTTP_POST,
			AXIS2_HTTP_PUT, AXIS2_HTTP_DELETE, AXIS2_HTTP_HEAD};
		supported_rest_methods = axutil_array_list_create(env, 0);
		http_method = axis2_msg_ctx_get_rest_http_method(msg_ctx, env);
		if (!http_method)
		{
			AXIS2_LOG_WARNING (env->log, AXIS2_LOG_SI, "unable to find http method \
				for location: %s", svc_info->loc_str);
			return NULL;
		}

		for (i = 0; i < 5; i++)
		{
			if (axutil_strcasecmp(rest_methods[i], 
								  http_method))
			{
				if (wsf_worker_get_op_with_method_and_location(svc_info->svc, env,
					rest_methods[i], svc_info->loc_str, &param_count, &params))
				{
					for (j = 0; j < param_count; j++)
					{
						AXIS2_FREE (env->allocator, params[j][0]);
						AXIS2_FREE (env->allocator, params[j][1]);
						AXIS2_FREE (env->allocator, params[j]);
					}
					if (params)
					{
						AXIS2_FREE (env->allocator, params);
					}
					axutil_array_list_add(supported_rest_methods, env,
										  axutil_strdup(env, rest_methods[i]));
				}
			}
		}
		axis2_msg_ctx_set_supported_rest_http_methods(msg_ctx, env, supported_rest_methods);
	}	


	return op;
}

wsf_worker_t* 
wsf_worker_create (
	const axutil_env_t *env,
    axis2_char_t *repo_path, 
	axis2_char_t *rm_db_dir) 
{
    wsf_worker_t * worker = NULL;

	worker = (wsf_worker_t *) AXIS2_MALLOC (env->allocator,sizeof (wsf_worker_t));
    if (!worker){
        AXIS2_ERROR_SET (env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    worker->conf_ctx = NULL;
    worker->conf_ctx = axis2_build_conf_ctx (env, repo_path);
    if (NULL == worker->conf_ctx) {
        wsf_worker_free (worker, env);
        return NULL;
    }
    if (rm_db_dir) {
        axis2_conf_t * conf = NULL;
        axis2_module_desc_t * module_desc = NULL;
        axutil_param_t * param = NULL;
        axutil_qname_t * sandesha2_qname = NULL;
		sandesha2_qname = axutil_qname_create (env, "sandesha2", NULL, NULL);
        conf = axis2_conf_ctx_get_conf (worker->conf_ctx, env);
        module_desc = axis2_conf_get_module (conf, env, sandesha2_qname);
        if (module_desc) {
            param = axis2_module_desc_get_param (module_desc, env, "sandesha2_db");
            if (param) {
			    smart_str sandesha2_db = { 0 };
				smart_str_appends(&sandesha2_db, rm_db_dir);
		        smart_str_appends(&sandesha2_db, "/");
		        smart_str_appends(&sandesha2_db, "sandesha2_db");
		        smart_str_0(&sandesha2_db);
				axutil_param_set_value (param, env, axutil_strdup(env , sandesha2_db.c));
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "[wsf_svr] rm_db_dir %s", sandesha2_db.c);
				smart_str_free(&sandesha2_db);
            }
        }
        axutil_qname_free(sandesha2_qname, env);
    }
    return worker;
}

axis2_char_t* 
wsf_worker_get_bytes (const axutil_env_t * env,
    axutil_stream_t * stream) 
{
    axutil_stream_t * tmp_stream = NULL;
    int return_size = -1;
    axis2_char_t * buffer = NULL;
    AXIS2_ENV_CHECK (env, NULL);
    AXIS2_PARAM_CHECK (env->error, stream, NULL);
    tmp_stream = axutil_stream_create_basic (env);
    while (1) {
        int read = 0;
        int write = 0;
        char buf[READ_SIZE];
        read = axutil_stream_read (stream, env, buf, READ_SIZE);
        if (read < 0) {
            break;
        }
        write = axutil_stream_write (tmp_stream, env, buf, read);
        if (read < (READ_SIZE - 1)) {
            break;
        }
    }
    return_size = axutil_stream_get_len (tmp_stream, env);
    if (return_size > 0) {
        buffer = (char *) AXIS2_MALLOC (env->allocator, sizeof (char) * (return_size + 2));
        return_size = axutil_stream_read (tmp_stream, env, buffer, return_size + 1);
        buffer[return_size + 1] = '\0';
    }
    axutil_stream_free (tmp_stream, env);
    return buffer;
}
void
wsf_worker_free (
    wsf_worker_t * worker,
    const axutil_env_t * env) 
{
    if (!worker)
        return;
    if (worker->conf_ctx != NULL) {
        axis2_conf_ctx_free (worker->conf_ctx, env);
        worker->conf_ctx = NULL;
    }
    AXIS2_FREE (env->allocator, worker);
}


int
wsf_worker_process_request (
    wsf_worker_t * worker,
    axutil_env_t * env,
    wsf_request_info_t * request,
	wsf_response_info_t *response,
    wsf_svc_info_t * svc_info TSRMLS_DC) 
{
    axis2_conf_ctx_t * conf_ctx = NULL;
    axis2_msg_ctx_t * msg_ctx = NULL;
    axis2_op_ctx_t * op_ctx = NULL;
    axis2_http_out_transport_info_t * php_out_transport_info = NULL;
    axis2_transport_out_desc_t * out_desc = NULL;
    axis2_transport_in_desc_t * in_desc = NULL;
    axutil_stream_t * in_stream = NULL;
    axutil_stream_t * out_stream = NULL;
    axutil_url_t * url = NULL;
	axis2_char_t * request_uri_with_query_string = NULL;
    int content_length = -1;
    axutil_string_t * soap_action_str = NULL;
    axis2_char_t * req_url = NULL;
    axis2_char_t * body_string = NULL;
    axis2_char_t * content_type = NULL;
    axis2_char_t * ctx_uuid = NULL;
    axutil_string_t * ctx_uuid_str = NULL;
	axis2_op_t *op = NULL;
	axis2_status_t status = AXIS2_FAILURE;

    if (!request)
		return -1;

	conf_ctx = worker->conf_ctx;
	
    if (request->query_string) {
        request_uri_with_query_string = AXIS2_MALLOC (env->allocator,
			(strlen (request->request_uri) + 5 + strlen (request->query_string)));
        
		sprintf (request_uri_with_query_string, "%s?%s",
            request->request_uri, request->query_string);

		url = axutil_url_create (env, "http" , request->svr_name, request->svr_port,
				request_uri_with_query_string);
		if(request_uri_with_query_string){
			AXIS2_FREE(env->allocator, request_uri_with_query_string);
		}
    } else {
		url = axutil_url_create (env, "http" , request->svr_name, request->svr_port,
			request->request_uri);
	}
    
    req_url = axutil_url_to_external_form (url, env);

	if(url){
		axutil_url_free(url, env);
	}

	if (NULL == conf_ctx) {
		AXIS2_LOG_CRITICAL(env->log, AXIS2_LOG_SI, "[wsf worker ] configuration ctx null");
        AXIS2_ERROR_SET (env->error, AXIS2_ERROR_NULL_CONFIGURATION_CONTEXT,
            AXIS2_FAILURE);
        return AXIS2_CRITICAL_FAILURE;
    }

    content_length = request->content_length;

    content_type = (axis2_char_t *) request->content_type;
    if (NULL == request->http_protocol) {
        AXIS2_ERROR_SET (env->error, AXIS2_ERROR_NULL_HTTP_VERSION, AXIS2_FAILURE);
        return AXIS2_CRITICAL_FAILURE;
    }
    response->http_protocol = request->http_protocol;
    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "Client HTTP version %s", request->http_protocol);

    out_stream = axutil_stream_create_basic (env);
    
	out_desc = axis2_conf_get_transport_out (
					axis2_conf_ctx_get_conf (worker->conf_ctx, env), 
					env, AXIS2_TRANSPORT_ENUM_HTTP);
    
	in_desc = axis2_conf_get_transport_in (
					axis2_conf_ctx_get_conf(worker->conf_ctx, env), 
					env, AXIS2_TRANSPORT_ENUM_HTTP);

    msg_ctx = axis2_msg_ctx_create (env, conf_ctx, in_desc, out_desc);
    
	axis2_msg_ctx_set_server_side (msg_ctx, env, AXIS2_TRUE);
    
	axis2_msg_ctx_set_svc (msg_ctx, env, svc_info->svc);
    
	op = wsf_worker_find_op_and_params_with_location_and_method(env, 
					request->request_method, svc_info,request,msg_ctx);
	
	if(op){
		axis2_msg_ctx_set_op(msg_ctx, env, op);
	}

    axis2_msg_ctx_set_transport_out_stream (msg_ctx, env, out_stream);
    
    /** generate uuid for context */ 
    ctx_uuid = axutil_uuid_gen (env);
    if (ctx_uuid) {
        ctx_uuid_str = axutil_string_create (env, ctx_uuid);
        axis2_msg_ctx_set_svc_grp_ctx_id (msg_ctx, env, ctx_uuid_str);
        AXIS2_FREE (env->allocator, ctx_uuid);
        axutil_string_free (ctx_uuid_str, env);
    }
    php_out_transport_info = wsf_out_transport_info_create (env, response);
	
	axis2_msg_ctx_set_out_transport_info (msg_ctx, env, &(php_out_transport_info->out_transport));
    
	if (request->transfer_encoding) {
        axis2_msg_ctx_set_transfer_encoding (msg_ctx, env,
            axutil_strdup (env, request->transfer_encoding));
    }
    
    /** store svc_info, req_info struct as a property */ 
    {
        axutil_property_t * svc_info_prop = NULL;
        axutil_property_t * req_info_prop = NULL;

		svc_info_prop = axutil_property_create_with_args (env, AXIS2_SCOPE_REQUEST,
            AXIS2_TRUE, wsf_worker_dummy_free_function, svc_info);
        axis2_msg_ctx_set_property (msg_ctx, env, WS_SVC_INFO, svc_info_prop);

		req_info_prop = axutil_property_create_with_args (env, AXIS2_SCOPE_REQUEST,
			AXIS2_TRUE, wsf_worker_dummy_free_function, request);
        axis2_msg_ctx_set_property (msg_ctx, env, WS_REQ_INFO, req_info_prop);
    }
	
    
    /** use MTOM property */ 
    if (svc_info->use_mtom == 1) {
        axis2_msg_ctx_set_doing_mtom (msg_ctx, env, AXIS2_TRUE);
    }
    if (svc_info->security_token != NULL && svc_info->policy != NULL) {
        
        /**  call security function here */ 
        axis2_conf_t * conf = NULL;
        conf = axis2_conf_ctx_get_conf (worker->conf_ctx, env);
        wsf_policy_handle_server_security (svc_info->security_token,
            svc_info->policy, env, svc_info->svc, conf TSRMLS_CC);
    }
    
	if (request->soap_action){
	    soap_action_str = axutil_string_create (env, request->soap_action);
	}
	in_stream = wsf_stream_create (env, request TSRMLS_CC);
    if (!in_stream) 
	{
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Error occured in" 
            " creating input stream.");
        return AXIS2_CRITICAL_FAILURE;
    }
    if (strcmp ("GET", request->request_method) == 0 || 
		strcmp ("HEAD", request->request_method) == 0 || 
		strcmp ("DELETE", request->request_method) == 0) 
	{
		axis2_bool_t processed = AXIS2_FALSE;

		if(strcmp("GET", request->request_method) == 0)
		{
			processed = axis2_http_transport_utils_process_http_get_request (env,
				msg_ctx, in_stream, out_stream, content_type,
				soap_action_str, req_url, conf_ctx, 
				axis2_http_transport_utils_get_request_params (env,
					(axis2_char_t *) req_url) );
		}else if(strcmp("HEAD", request->request_method) == 0){
			processed = axis2_http_transport_utils_process_http_head_request(env,
				msg_ctx, in_stream, out_stream, content_type,
				soap_action_str, req_url,conf_ctx, 
				axis2_http_transport_utils_get_request_params (env,
					(axis2_char_t *) req_url));
		}else if(strcmp("DELETE", request->request_method) == 0){
			processed = axis2_http_transport_utils_process_http_delete_request(env,
				msg_ctx, in_stream, out_stream, content_type,
				soap_action_str, req_url,conf_ctx, 
				axis2_http_transport_utils_get_request_params (env,
					(axis2_char_t *) req_url));
		}

        if (AXIS2_FALSE == processed) 
		{
			if(!svc_info->loc_str)
			{
				/** if location str is not present, it cannot be a rest request, so serve the 
				services html */
				body_string = axis2_http_transport_utils_get_services_html (env, conf_ctx);
				response->content_type = axutil_strdup(env,"text/html");
				response->http_status_code = AXIS2_HTTP_RESPONSE_OK_CODE_VAL;
				response->http_status_code_name = AXIS2_HTTP_RESPONSE_OK_CODE_NAME;

			}else if(env->error->error_number == AXIS2_ERROR_SVC_OR_OP_NOT_FOUND){
				axutil_array_list_t *method_list = NULL;
                int size = 0;
                method_list = axis2_msg_ctx_get_supported_rest_http_methods(msg_ctx, env);
                size = axutil_array_list_size(method_list, env);
				
				response->content_type = axutil_strdup(env,"text/html");
				
				if (method_list && size){
					/** 405 */
					body_string = axis2_http_transport_utils_get_method_not_allowed(env, conf_ctx);
					response->http_status_code = AXIS2_HTTP_RESPONSE_METHOD_NOT_ALLOWED_CODE_VAL;
					response->http_status_code_name = AXIS2_HTTP_RESPONSE_METHOD_NOT_ALLOWED_CODE_NAME;
				    
				}else {
					/** 404  */
					body_string = axis2_http_transport_utils_get_not_found(env, conf_ctx);
					response->http_status_code = AXIS2_HTTP_RESPONSE_NOT_FOUND_CODE_VAL;
					response->http_status_code_name = AXIS2_HTTP_RESPONSE_NOT_FOUND_CODE_NAME;
				}
			}
        }
        if (body_string) {
			response->response_data = axutil_strdup(env, body_string);
            response->response_length = strlen (body_string);
        }
    }else if (strcmp ("POST", request->request_method) == 0 ||
		strcmp("PUT", request->request_method) == 0 ) 
	{
		axis2_status_t status = AXIS2_FAILURE;

		if(strcmp ("POST", request->request_method) == 0)
		{
			status = axis2_http_transport_utils_process_http_post_request 
				(env, msg_ctx, in_stream, out_stream, content_type,
				content_length, soap_action_str, (axis2_char_t *) req_url);
		}else if(strcmp("PUT", request->request_method) == 0)
		{
			status = axis2_http_transport_utils_process_http_post_request 
				(env, msg_ctx, in_stream, out_stream, content_type,
				content_length, soap_action_str, (axis2_char_t *) req_url);
		}

        if (status == AXIS2_FAILURE) 
		{
	        axis2_char_t *fault_code = NULL;
		    axis2_msg_ctx_t * fault_ctx = NULL;
			axis2_engine_t * engine = axis2_engine_create (env, conf_ctx);

			if ( axis2_msg_ctx_get_is_soap_11 (msg_ctx, env))
			{
				fault_code = AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX ":"
					AXIOM_SOAP11_FAULT_CODE_SENDER;
			}else
			{
				fault_code = AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX ":"
					AXIOM_SOAP12_SOAP_FAULT_VALUE_SENDER;
			}

			fault_ctx = axis2_engine_create_fault_msg_ctx (engine, env, msg_ctx,
					fault_code, axutil_error_get_message(env->error));
			
			axis2_engine_send_fault (engine, env, fault_ctx);
    
			if(out_stream)
			{
				body_string = wsf_worker_get_bytes (env, out_stream);
				if (body_string) 
				{
					response->response_data = body_string;
					response->response_length = strlen (body_string);
					response->http_status_code = AXIS2_HTTP_RESPONSE_INTERNAL_SERVER_ERROR_CODE_VAL;
					response->http_status_code_name = AXIS2_HTTP_RESPONSE_INTERNAL_SERVER_ERROR_CODE_NAME;
				}
			}
		}
		op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
		if (status != AXIS2_FAILURE) 
		{
			if (axis2_op_ctx_get_response_written (op_ctx, env)) 
			{
				int data_length = 0;
				int read_length = 0;
				void *data = NULL;
				data_length = axutil_stream_get_len (out_stream, env);
				data = AXIS2_MALLOC (env->allocator, sizeof (char) * (data_length + 1));
				read_length = axutil_stream_read (out_stream, env, data, data_length + 1);
				if (data) {
					response->response_data = data;
					response->response_length = data_length;
					response->http_status_code = AXIS2_HTTP_RESPONSE_OK_CODE_VAL;
					response->http_status_code_name = AXIS2_HTTP_RESPONSE_OK_CODE_NAME;
				}
			}else 
			{
				response->response_length = 0;
				response->http_status_code = AXIS2_HTTP_RESPONSE_ACK_CODE_VAL;
				response->http_status_code_name = AXIS2_HTTP_RESPONSE_ACK_CODE_NAME;
			}
		}
	}
	if(!op_ctx)
		op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);

    if (op_ctx) 
    {
        axis2_msg_ctx_t *out_msg_ctx = NULL, *in_msg_ctx = NULL;
        axis2_msg_ctx_t **msg_ctx_map = NULL;
        axis2_char_t *msg_id = NULL;
        axis2_conf_ctx_t *conf_ctx = NULL;
        msg_ctx_map =  axis2_op_ctx_get_msg_ctx_map(op_ctx, env);

        out_msg_ctx = msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_OUT];
        in_msg_ctx = msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_IN];

        if (out_msg_ctx)
        {
            axis2_msg_ctx_free(out_msg_ctx, env);
            out_msg_ctx = NULL;
            msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_OUT] = NULL;
        }

        if (in_msg_ctx)
        {
            msg_id = axutil_strdup(env, axis2_msg_ctx_get_msg_id(in_msg_ctx, env));
            conf_ctx = axis2_msg_ctx_get_conf_ctx(in_msg_ctx, env);
        
            axis2_msg_ctx_free(in_msg_ctx, env);
            in_msg_ctx = NULL;
            msg_ctx_map[AXIS2_WSDL_MESSAGE_LABEL_IN] = NULL;
        }

        if(!axis2_op_ctx_is_in_use(op_ctx, env))
        {
            axis2_op_ctx_destroy_mutex(op_ctx, env);
            if (conf_ctx && msg_id)
            {
                axis2_conf_ctx_register_op_ctx(conf_ctx, env, msg_id, NULL);
                AXIS2_FREE(env->allocator, msg_id);
            }
            axis2_op_ctx_free(op_ctx, env);
        }
        
    }/* Done freeing message contexts */
    if (soap_action_str) {
        axutil_string_free (soap_action_str, env);
    }

    if(in_stream){
		wsf_stream_free(in_stream, env);
    }
    if(req_url){
       AXIS2_FREE(env->allocator, req_url);
    }
    return 1;
}

axis2_conf_ctx_t* 
wsf_worker_get_conf_ctx (
	wsf_worker_t * worker,
    const axutil_env_t * env) 
{
    return worker->conf_ctx;
}

