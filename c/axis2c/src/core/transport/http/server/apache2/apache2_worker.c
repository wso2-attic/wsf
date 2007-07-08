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

#include "axis2_apache2_worker.h"
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
#include "axis2_apache2_out_transport_info.h"
#include <axutil_url.h>
#include <http_core.h>
#include <http_protocol.h>


#define READ_SIZE  2048

struct axis2_apache2_worker
{
    axis2_conf_ctx_t *conf_ctx;
};

AXIS2_EXTERN axis2_apache2_worker_t *AXIS2_CALL
axis2_apache2_worker_create(
    const axutil_env_t *env,
    axis2_char_t *repo_path)
{
    axis2_apache2_worker_t *apache2_worker = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    apache2_worker = (axis2_apache2_worker_t *)
            AXIS2_MALLOC(env->allocator, sizeof(axis2_apache2_worker_t));

    if (! apache2_worker)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    apache2_worker->conf_ctx = axis2_build_conf_ctx(env, repo_path);

    if (! apache2_worker->conf_ctx)
    {
        axis2_apache2_worker_free((axis2_apache2_worker_t *)apache2_worker,
                env);
        return NULL;
    }
    
    return apache2_worker;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_apache2_worker_free(
    axis2_apache2_worker_t *apache2_worker,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (apache2_worker->conf_ctx)
    {
         axis2_conf_ctx_free(apache2_worker->conf_ctx, env);
        apache2_worker->conf_ctx = NULL;
    }

    AXIS2_FREE(env->allocator, apache2_worker->conf_ctx);

    return;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_apache2_worker_process_request(
    axis2_apache2_worker_t *apache2_worker,
    const axutil_env_t *env,
    request_rec *request)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axutil_stream_t *request_body = NULL;
    axutil_stream_t *out_stream = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
    axis2_char_t *http_version = NULL;
    axutil_string_t *soap_action = NULL;
    axis2_bool_t processed = AXIS2_FALSE;
    int content_length = -1;
    axis2_char_t *encoding_header_value = NULL;
    axis2_char_t *req_url = NULL;
    axis2_char_t *body_string = NULL;
    unsigned int body_string_len = 0;
    int send_status = -1;
    axis2_char_t *content_type = NULL;
    axis2_http_out_transport_info_t *apache2_out_transport_info = NULL;
    axis2_char_t *ctx_uuid = NULL;
    axis2_op_ctx_t *op_ctx = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    AXIS2_PARAM_CHECK(env->error, request, AXIS2_CRITICAL_FAILURE);

    conf_ctx = apache2_worker->conf_ctx;

    if (! conf_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_CONFIGURATION_CONTEXT,
                AXIS2_FAILURE);
        return AXIS2_CRITICAL_FAILURE;
    }
    content_length = request->remaining;
    http_version = request->protocol;
    req_url = request->unparsed_uri;

    content_type = (axis2_char_t *)apr_table_get(request->headers_in,
            AXIS2_HTTP_HEADER_CONTENT_TYPE);
    request->content_type = content_type;
    if (request->read_chunked == AXIS2_TRUE && 0 == content_length)
    {
        content_length = -1;
        request->chunked = 1;
    }
    if (! http_version)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_HTTP_VERSION,
                AXIS2_FAILURE);
        return AXIS2_CRITICAL_FAILURE;
    }
    out_stream = axutil_stream_create_basic(env);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Client HTTP version %s",
            http_version);

    encoding_header_value = (axis2_char_t*)request->content_encoding;

    out_desc =  axis2_conf_get_transport_out( axis2_conf_ctx_get_conf
            (apache2_worker->conf_ctx, env), env,
            AXIS2_TRANSPORT_ENUM_HTTP);
    in_desc =  axis2_conf_get_transport_in( axis2_conf_ctx_get_conf
            (apache2_worker->conf_ctx, env), env,
            AXIS2_TRANSPORT_ENUM_HTTP);

    msg_ctx = axis2_msg_ctx_create(env, conf_ctx, in_desc, out_desc);
     axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);

    axis2_msg_ctx_set_transport_out_stream(msg_ctx, env, out_stream);

    ctx_uuid = axutil_uuid_gen(env);
    if (ctx_uuid)
    {
        axutil_string_t *uuid_str = axutil_string_create_assume_ownership(env, &ctx_uuid);
         axis2_msg_ctx_set_svc_grp_ctx_id(msg_ctx, env, uuid_str);
        axutil_string_free(uuid_str, env);
    }

    apache2_out_transport_info = axis2_apache2_out_transport_info_create(env,
            request);
    axis2_msg_ctx_set_http_out_transport_info(msg_ctx, env, apache2_out_transport_info);

    soap_action = axutil_string_create(env, 
            (axis2_char_t *)apr_table_get(request->headers_in,
            AXIS2_HTTP_HEADER_SOAP_ACTION));
    request_body = axutil_stream_create_apache2(env, request);
    if (! request_body)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error occured in"
                " creating input stream.");
        return AXIS2_CRITICAL_FAILURE;
    }
    if (M_GET == request->method_number)
    {
        processed = axis2_http_transport_utils_process_http_get_request
                (env, msg_ctx, request_body, out_stream,
                        content_type , soap_action,
                        req_url,
                        conf_ctx,
                        axis2_http_transport_utils_get_request_params(env,
                                (axis2_char_t *)req_url));
        if (AXIS2_FALSE == processed)
        {
            axis2_char_t *wsdl = NULL;
            wsdl = strstr ((axis2_char_t *)req_url, AXIS2_REQUEST_WSDL);
            if (wsdl)
            {
                body_string = axis2_http_transport_utils_get_services_static_wsdl(
                    env,conf_ctx, (axis2_char_t *)req_url);
                request->content_type = "text/xml";
            
            }
            else
            {
                body_string = axis2_http_transport_utils_get_services_html(env,
                     conf_ctx);
                request->content_type = "text/html";
            
            }

            if (body_string)
            {
                body_string_len = axutil_strlen(body_string);
            }
            send_status = OK;
        }

    }
    else if (M_POST == request->method_number)
    {
        axis2_status_t status = AXIS2_FAILURE;
        status = axis2_http_transport_utils_process_http_post_request
                (env, msg_ctx, request_body, out_stream,
                        content_type , content_length,
                        soap_action,
                        (axis2_char_t *)req_url);
        if (status == AXIS2_FAILURE)
        {
            axis2_msg_ctx_t *fault_ctx = NULL;
            axis2_engine_t *engine = axis2_engine_create(env, conf_ctx);
            if (! engine)
            {
                send_status =  HTTP_INTERNAL_SERVER_ERROR;
            }
            fault_ctx =  axis2_engine_create_fault_msg_ctx(engine, env, msg_ctx);
            axis2_engine_send_fault(engine, env, fault_ctx);
            if (out_stream)
            {
                body_string = axutil_stream_get_buffer(out_stream, env);
                body_string_len = axutil_stream_get_len(out_stream, env);
            }
            send_status =  HTTP_INTERNAL_SERVER_ERROR;
        }
    }
    
    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    
    if (-1 == send_status)
    {
        if (axis2_op_ctx_get_response_written(op_ctx, env))
        {
            send_status = OK;
            if (out_stream)
            {
                body_string = axutil_stream_get_buffer(out_stream, env);
                body_string_len = axutil_stream_get_len(out_stream, env);
            }
        }
        else
        {
            send_status = DONE;
            request->status = HTTP_ACCEPTED;
        }
    }
    
    if (op_ctx)
    {
        axis2_op_ctx_destroy_mutex(op_ctx, env);
    }
    if (body_string)
    {
        ap_rwrite(body_string, body_string_len, request);
        body_string = NULL;
    }
    
    if (request_body)
    {
        axutil_stream_free(request_body, env);
        request_body = NULL;
    }

    axutil_string_free(soap_action, env);

    msg_ctx = NULL;
    return send_status;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_apache2_worker_get_bytes(
    const axutil_env_t *env,
    axutil_stream_t *stream)
{

    axutil_stream_t *tmp_stream = NULL;
    int return_size = -1;
    axis2_char_t *buffer = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, stream, NULL);

    tmp_stream = axutil_stream_create_basic(env);
    while (1)
    {
        int read = 0;
        int write = 0;

        char buf[READ_SIZE];
        read = axutil_stream_read(stream, env, buf, READ_SIZE);
        if (read < 0)
        {
            break;
        }
        write = axutil_stream_write(tmp_stream, env, buf, read);
        if (read < (READ_SIZE - 1))
        {
            break;
        }
    }
    return_size = axutil_stream_get_len(tmp_stream, env);

    if (return_size > 0)
    {
        buffer = (char *)AXIS2_MALLOC(env->allocator, sizeof(char) *
                (return_size + 2));
        return_size = axutil_stream_read(tmp_stream, env, buffer,
                return_size + 1);
        buffer[return_size + 1] = '\0';
    }
    axutil_stream_free(tmp_stream, env);
    return buffer;
}








