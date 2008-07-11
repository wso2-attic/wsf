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

#include "wsf_util.h"
#include "wsf_stream.h"
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

wsf_worker_t * wsf_worker_create (const axutil_env_t * env,
    axis2_char_t * repo_path, axis2_char_t * rm_db_dir) 
{
    wsf_worker_t * worker = NULL;
    AXIS2_ENV_CHECK (env, NULL);
    worker = (wsf_worker_t *) AXIS2_MALLOC (env->allocator,
                sizeof (wsf_worker_t));
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
                axutil_param_set_value (param, env, rm_db_dir);
                AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI,
                    "[wsf_svr] rm_db_dir %s", rm_db_dir);
            }
        }
        
        axutil_qname_free(sandesha2_qname, env);
    }
    return worker;
}

axis2_char_t * wsf_worker_get_bytes (const axutil_env_t * env,
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
        return_size =
            axutil_stream_read (tmp_stream, env, buffer, return_size + 1);
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
    wsf_req_info_t * request,
    wsf_svc_info_t * svc_info) 
{
    axis2_conf_ctx_t * conf_ctx = NULL;
    axis2_msg_ctx_t * msg_ctx = NULL;
    axis2_op_ctx_t * op_ctx = NULL;
    axis2_http_out_transport_info_t * ruby_out_transport_info = NULL;
    axis2_transport_out_desc_t * out_desc = NULL;
    axis2_transport_in_desc_t * in_desc = NULL;
    axutil_stream_t * request_body = NULL;
    axutil_stream_t * out_stream = NULL;
    axutil_url_t * url = NULL;
    axis2_char_t * request_uri_with_query_string;
    int content_length = -1;
    int send_status = -1;
    axis2_char_t * http_version = NULL;
    axis2_char_t * soap_action = NULL;
    axutil_string_t * soap_action_str = NULL;
    axis2_char_t * encoding_header_value = NULL;
    axis2_char_t * req_url = NULL;
    axis2_char_t * body_string = NULL;
    axis2_char_t * content_type = NULL;
    axis2_char_t * ctx_uuid = NULL;
    axutil_string_t * ctx_uuid_str = NULL;


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
    http_version = request->http_protocol;

    content_type = (axis2_char_t *) request->content_type;
    if (NULL == http_version) {
        AXIS2_ERROR_SET (env->error, AXIS2_ERROR_NULL_HTTP_VERSION,
            AXIS2_FAILURE);
        return AXIS2_CRITICAL_FAILURE;
    }
    out_stream = axutil_stream_create_basic (env);
    AXIS2_LOG_DEBUG (env->log, AXIS2_LOG_SI, "Client HTTP version %s",
        http_version);
    encoding_header_value = request->content_encoding;
    out_desc = axis2_conf_get_transport_out (axis2_conf_ctx_get_conf 
        (worker->conf_ctx, env), env, AXIS2_TRANSPORT_ENUM_HTTP);
    in_desc = axis2_conf_get_transport_in (axis2_conf_ctx_get_conf 
        (worker->conf_ctx, env), env, AXIS2_TRANSPORT_ENUM_HTTP);
    msg_ctx = axis2_msg_ctx_create (env, conf_ctx, in_desc, out_desc);
    axis2_msg_ctx_set_server_side (msg_ctx, env, AXIS2_TRUE);
    axis2_msg_ctx_set_svc (msg_ctx, env, svc_info->svc);
    if (svc_info->op_name) {
        axis2_op_t * op = NULL;
        op =
            axis2_svc_get_op_with_name (svc_info->svc, env,
            svc_info->op_name);
        if (op) {
            axis2_msg_ctx_set_op (msg_ctx, env, op);
        }
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
    ruby_out_transport_info = wsf_out_transport_info_create (env, request);
    axis2_msg_ctx_set_out_transport_info (msg_ctx, env,
        &(ruby_out_transport_info->out_transport));
    if (request->transfer_encoding) {
        axis2_msg_ctx_set_transfer_encoding (msg_ctx, env,
            axutil_strdup (env, request->transfer_encoding));
    }
    
    /** store svc_info struct as a property */ 
    {
        axutil_property_t * svc_info_prop = NULL;
        svc_info_prop =
            axutil_property_create_with_args (env, AXIS2_SCOPE_REQUEST,
            AXIS2_TRUE, wsf_worker_dummy_free_function, svc_info);
        axis2_msg_ctx_set_property (msg_ctx, env, WS_SVC_INFO,
            svc_info_prop);
    }
    
    /** use MTOM property */ 
        if (svc_info->use_mtom == 1) {
        axis2_msg_ctx_set_doing_mtom (msg_ctx, env, AXIS2_TRUE);
    }
    
	if (svc_info->security_token != Qnil && svc_info->policy != Qnil) {
        /**  call security function here */
        axis2_conf_t * conf = NULL;
        conf = axis2_conf_ctx_get_conf (worker->conf_ctx, env);
        wsf_policy_handle_server_security (svc_info->security_token,
            svc_info->policy, env, svc_info->svc, conf);
    }

	soap_action = request->soap_action;
	if (soap_action){
	    soap_action_str = axutil_string_create (env, soap_action);
	}
	request_body = wsf_stream_create (env, request);
    if (!request_body) {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Error occured in" 
            " creating input stream.");
        return AXIS2_CRITICAL_FAILURE;
    }
    
    if( request->request_method == NULL)
    {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, "Error occured:" 
            " server request mehthod not set.");
        return AXIS2_CRITICAL_FAILURE;
    }
    if (0 == strcmp ("GET", request->request_method)) {
        axis2_bool_t processed = AXIS2_FALSE;
        processed =
            axis2_http_transport_utils_process_http_get_request (env,
            msg_ctx, request_body, out_stream, content_type,
            soap_action_str, req_url, conf_ctx,
            axis2_http_transport_utils_get_request_params (env,
                (axis2_char_t *) req_url) );
        if (AXIS2_FALSE == processed) {
            body_string = axis2_http_transport_utils_get_services_html (env, conf_ctx);
			request->out_content_type = axutil_strdup(env,"text/html");
            send_status = WS_HTTP_OK;
        }
        if (body_string) {
            request->result_payload = body_string;
            request->result_length = strlen (body_string);
        }
    } else if (0 == strcmp ("POST", request->request_method)) {
        axis2_status_t status = AXIS2_FAILURE;
        status = axis2_http_transport_utils_process_http_post_request 
            (env, msg_ctx, request_body, out_stream, content_type,
            content_length, soap_action_str, (axis2_char_t *) req_url);
        if (status == AXIS2_FAILURE) {
            axis2_char_t *fault_code = NULL;
            axis2_msg_ctx_t * fault_ctx = NULL;
            axis2_engine_t * engine = axis2_engine_create (env, conf_ctx);
            if (engine) {
                send_status = WS_HTTP_INTERNAL_SERVER_ERROR;
            }
            if ( axis2_msg_ctx_get_is_soap_11 (msg_ctx, env)){
                fault_code = AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX ":"
                    AXIOM_SOAP11_FAULT_CODE_SENDER;
            }
            else{
                fault_code = AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX ":"
                    AXIOM_SOAP12_SOAP_FAULT_VALUE_SENDER;
            }

            fault_ctx = axis2_engine_create_fault_msg_ctx (engine, env, msg_ctx,
                fault_code, axutil_error_get_message(env->error));
            axis2_engine_send_fault (engine, env, fault_ctx);
            
			if(out_stream){
                body_string = wsf_worker_get_bytes (env, out_stream);
            }
            send_status = WS_HTTP_INTERNAL_SERVER_ERROR;
            if (body_string) {
                request->result_payload = body_string;
                request->result_length = strlen (body_string);
            }
        }
    }

	op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if (-1 == send_status) {
        if (axis2_op_ctx_get_response_written (op_ctx, env)) {
			           
			int rlen = 0;
            int readlen = 0;
            void *val = NULL;
            send_status = WS_HTTP_OK;
            rlen = axutil_stream_get_len (out_stream, env);
            val = AXIS2_MALLOC (env->allocator, sizeof (char) * (rlen + 1));
            readlen = axutil_stream_read (out_stream, env, val, rlen + 1);

            if (val) {
				request->result_payload = val;
				request->result_length = rlen;
				send_status = WS_HTTP_OK;
            }
        } else {
            send_status = WS_HTTP_ACCEPTED;
        }
    }
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
        
    } /* Done freeing message contexts */
    if (soap_action_str) {
        axutil_string_free (soap_action_str, env);
    }
	if(request_body){
		wsf_stream_free(request_body, env);
	}
	if(req_url){
		AXIS2_FREE(env->allocator, req_url);
	}

    return send_status;
}

axis2_conf_ctx_t * wsf_worker_get_conf_ctx (wsf_worker_t * worker,
    const axutil_env_t * env) 
{
    return worker->conf_ctx;
}


