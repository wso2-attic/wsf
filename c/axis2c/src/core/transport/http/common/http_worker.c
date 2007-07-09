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


#include <axis2_http_worker.h>
#include <axutil_string.h>
#include <axis2_http_transport.h>
#include <axis2_conf.h>
#include <axutil_string.h>
#include <axis2_msg_ctx.h>
#include <axis2_http_request_line.h>
#include <axis2_http_out_transport_info.h>
#include <axis2_http_transport_utils.h>
#include <axis2_op_ctx.h>
#include <axis2_engine.h>
#include <axutil_uuid_gen.h>
#include <axutil_url.h>
#include <axutil_property.h>
#include <string.h>

struct axis2_http_worker
{
    axis2_conf_ctx_t *conf_ctx;
    int svr_port;
};

static axis2_status_t 
axis2_http_worker_set_response_headers(
    axis2_http_worker_t *http_worker,
    const axutil_env_t *env,
    axis2_simple_http_svr_conn_t *svr_conn,
    axis2_http_simple_request_t *simple_request,
    axis2_http_simple_response_t *simple_response,
    axis2_ssize_t content_length);

static axis2_status_t 
axis2_http_worker_set_transport_out_config(
    axis2_http_worker_t *http_worker,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_http_simple_response_t *simple_response);

static axutil_hash_t *
axis2_http_worker_get_headers(
    axis2_http_worker_t *http_worker,
    const axutil_env_t *env,
    axis2_http_simple_request_t *request);

AXIS2_EXTERN axis2_http_worker_t *AXIS2_CALL
axis2_http_worker_create(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_http_worker_t *http_worker = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    http_worker = (axis2_http_worker_t *)
            AXIS2_MALLOC(env->allocator, sizeof(axis2_http_worker_t));

    if (! http_worker)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    http_worker->conf_ctx = conf_ctx;
    http_worker->svr_port = 9090; /* default - must set later*/

    return http_worker;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_worker_free(
    axis2_http_worker_t *http_worker,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    http_worker->conf_ctx = NULL;

    AXIS2_FREE(env->allocator, http_worker);

    return;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_worker_process_request(
    axis2_http_worker_t *http_worker,
    const axutil_env_t *env,
    axis2_simple_http_svr_conn_t *svr_conn,
    axis2_http_simple_request_t *simple_request)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axutil_stream_t *request_body = NULL;
    axutil_stream_t *out_stream = axutil_stream_create_basic(env);
    axis2_http_simple_response_t *response = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
    axis2_char_t *http_version = NULL;
    axis2_char_t *soap_action = NULL;
    axutil_string_t *soap_action_str = NULL;
    axis2_bool_t processed = AXIS2_FALSE;
    axis2_status_t status = AXIS2_FAILURE;
    int content_length = -1;
    axis2_http_header_t *encoding_header = NULL;
    axis2_char_t *encoding_header_value = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_char_t *svr_ip = NULL;
    axis2_char_t *peer_ip = NULL;
    axutil_url_t *request_url = NULL;
    axis2_http_out_transport_info_t *http_out_transport_info = NULL;
    axutil_hash_t *headers = NULL;
    axis2_char_t *url_external_form = NULL;
    axis2_char_t *svc_grp_uuid = NULL;
    axis2_char_t *path = NULL;
    axutil_property_t *peer_property = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svr_conn, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, simple_request, AXIS2_FAILURE);

    conf_ctx = http_worker->conf_ctx;

    if (! conf_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_CONFIGURATION_CONTEXT,
                AXIS2_FAILURE);
        return AXIS2_FALSE;
    }

    content_length = axis2_http_simple_request_get_content_length(simple_request
            , env);
    http_version = axis2_http_request_line_get_http_version
            (axis2_http_simple_request_get_request_line
                    (simple_request, env), env);
    if (! http_version)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_HTTP_VERSION,
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Client HTTP version %s",
            http_version);

    response = axis2_http_simple_response_create_default(env);
    encoding_header = axis2_http_simple_request_get_first_header(simple_request,
            env, AXIS2_HTTP_HEADER_TRANSFER_ENCODING);
    if (encoding_header)
    {
        encoding_header_value = axis2_http_header_get_value(encoding_header,
                env);
    }
    if (content_length < 0 && (encoding_header_value && 0 != axutil_strcmp
            (encoding_header_value,
                    AXIS2_HTTP_HEADER_TRANSFER_ENCODING_CHUNKED)))
    {
        if (0 == axutil_strcasecmp(axis2_http_request_line_get_method(
                    axis2_http_simple_request_get_request_line(
                        simple_request, env), env), AXIS2_HTTP_POST))
        {
            axis2_http_simple_response_set_status_line(response, env,
                    http_version, 411, "Length Required");
            status = axis2_simple_http_svr_conn_write_response(svr_conn, env,
                    response);
            axis2_http_simple_response_free(response, env);
            response = NULL;
            return status;
        }

    }
    request_body = axis2_http_simple_request_get_body(simple_request, env);

    out_desc =  axis2_conf_get_transport_out( axis2_conf_ctx_get_conf
            (http_worker->conf_ctx, env), env,
            AXIS2_TRANSPORT_ENUM_HTTP);
    in_desc =  axis2_conf_get_transport_in( axis2_conf_ctx_get_conf
            (http_worker->conf_ctx, env), env,
            AXIS2_TRANSPORT_ENUM_HTTP);
    msg_ctx = axis2_msg_ctx_create(env, conf_ctx, in_desc, out_desc);
    axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);


    if (0 == axutil_strcasecmp(http_version, AXIS2_HTTP_HEADER_PROTOCOL_11))
    {
        axis2_http_worker_set_transport_out_config(http_worker, env, conf_ctx,
                response);
    }

    svr_ip = axis2_simple_http_svr_conn_get_svr_ip(svr_conn, env);
    peer_ip = axis2_simple_http_svr_conn_get_peer_ip(svr_conn, env);

    if (peer_ip)
    {
        peer_property = axutil_property_create (env);
        axutil_property_set_value (peer_property, env, axutil_strdup (env, peer_ip));
        axis2_msg_ctx_set_property (msg_ctx, env, AXIS2_SVR_PEER_IP_ADDR, peer_property); 
    }

    path =   axis2_http_request_line_get_uri(
	axis2_http_simple_request_get_request_line(
	    simple_request, env), env);

    request_url = axutil_url_create(env, "http", svr_ip,
				   http_worker->svr_port,
				   path);

	url_external_form = axutil_url_to_external_form(request_url, env);
    
    axis2_msg_ctx_set_transport_out_stream(msg_ctx, env, out_stream);

    headers = axis2_http_worker_get_headers(http_worker, env, simple_request);
    axis2_msg_ctx_set_transport_headers(msg_ctx, env, headers);

    svc_grp_uuid = axutil_uuid_gen(env);
    if (svc_grp_uuid)
    {
        axutil_string_t *svc_grp_uuid_str = axutil_string_create_assume_ownership(env, &svc_grp_uuid);
         axis2_msg_ctx_set_svc_grp_ctx_id(msg_ctx, env, svc_grp_uuid_str);
        axutil_string_free(svc_grp_uuid_str, env);
    }

    http_out_transport_info = axis2_http_out_transport_info_create(env, response);
    axis2_msg_ctx_set_http_out_transport_info(msg_ctx, env, http_out_transport_info);

    if (axis2_http_simple_request_get_first_header(simple_request, env,
            AXIS2_HTTP_HEADER_SOAP_ACTION))
    {
        soap_action = axis2_http_header_get_value(
                    axis2_http_simple_request_get_first_header(
                        simple_request, env, AXIS2_HTTP_HEADER_SOAP_ACTION),
                    env);
        soap_action_str = axutil_string_create(env, soap_action);
    }
    if (0 == axutil_strcasecmp(axis2_http_request_line_get_method(
                axis2_http_simple_request_get_request_line(
                    simple_request, env), env), AXIS2_HTTP_GET))
    {
        processed = axis2_http_transport_utils_process_http_get_request
                (env, msg_ctx, request_body, out_stream,
                        axis2_http_simple_request_get_content_type(
                            simple_request, env) , soap_action_str,
                        axutil_url_to_external_form(request_url, env),
                        conf_ctx,
                        axis2_http_transport_utils_get_request_params(env,
                                axis2_http_request_line_get_uri(
                                    axis2_http_simple_request_get_request_line(
                                        simple_request, env), env)));
        if (AXIS2_FALSE == processed)
        {
            axis2_http_header_t *cont_len = NULL;
            axis2_http_header_t *cont_type = NULL;
            axis2_char_t *body_string = NULL;
            axis2_char_t *wsdl = NULL;
            axis2_http_simple_response_set_status_line(response, env,
                    http_version, AXIS2_HTTP_RESPONSE_OK_CODE_VAL, "OK");
            wsdl = strstr (url_external_form, AXIS2_REQUEST_WSDL);
            if (wsdl)
            {
                body_string = axis2_http_transport_utils_get_services_static_wsdl(
                        env, conf_ctx, url_external_form);
            }
            else
            {
                body_string = axis2_http_transport_utils_get_services_html(env,
                    conf_ctx);
            }
            if (body_string)
            {
                axis2_char_t str_len[10];
                axis2_http_simple_response_set_body_string(response, env,
                    body_string);
                sprintf(str_len, "%d", axutil_strlen(body_string));
                cont_len = axis2_http_header_create(env,
                    AXIS2_HTTP_HEADER_CONTENT_LENGTH, str_len);
                axis2_http_simple_response_set_header(response, env, cont_len);
                cont_type = axis2_http_header_create(env,
                    AXIS2_HTTP_HEADER_CONTENT_TYPE, AXIS2_HTTP_HEADER_ACCEPT_TEXT_HTML);
                axis2_http_simple_response_set_header(response, env, cont_type);
             }
                axis2_http_worker_set_response_headers(http_worker, env, svr_conn,
                    simple_request, response, 0);
                axis2_simple_http_svr_conn_write_response(svr_conn, env, response);
                axis2_http_simple_response_free(response, env);
                return AXIS2_TRUE;
        }
    }
    else if (0 == axutil_strcasecmp(axis2_http_request_line_get_method(
                axis2_http_simple_request_get_request_line(
                    simple_request, env), env), AXIS2_HTTP_POST))
    {
        status = axis2_http_transport_utils_process_http_post_request
                (env, msg_ctx, request_body, out_stream,
                        axis2_http_simple_request_get_content_type(
                            simple_request, env) , content_length, soap_action_str,
                        url_external_form);
        if (status == AXIS2_FAILURE)
        {
            axis2_msg_ctx_t *fault_ctx = NULL;
            axis2_engine_t *engine = axis2_engine_create(env, conf_ctx);
            axis2_http_request_line_t *req_line = NULL;
            axis2_http_status_line_t *tmp_stat_line = NULL;
            axis2_char_t status_line_str[100];
            axutil_property_t *http_error_property = NULL;
            axis2_char_t *http_error_value = NULL;
            if (! engine)
            {
                return AXIS2_FALSE;
            }

            http_error_property =  axis2_msg_ctx_get_property(msg_ctx, env,
                AXIS2_HTTP_TRANSPORT_ERROR);

            if (http_error_property)
                http_error_value = (axis2_char_t *)axutil_property_get_value(
                    http_error_property, env);

            fault_ctx =  axis2_engine_create_fault_msg_ctx(engine, env, msg_ctx);
            req_line = axis2_http_simple_request_get_request_line(simple_request
                , env);
            if (req_line)
            {
                if (!http_error_value)
                {
                    sprintf(status_line_str, "%s 500 Internal Server Error\r\n",
                            axis2_http_request_line_get_http_version(req_line,
                                env));
                }
                else
                {
                    sprintf(status_line_str, "%s %s",
                        axis2_http_request_line_get_http_version(req_line,env),
                        http_error_value);
                }
            }
            else
            {
                sprintf(status_line_str, "HTTP/1.1 500 Internal Server Error\
                        \r\n");
            }

            tmp_stat_line = axis2_http_status_line_create(env,
                    status_line_str);

            if (!http_error_value)
                axis2_engine_send_fault(engine, env, fault_ctx);

            axis2_http_simple_response_set_status_line(response, env,
                    axis2_http_status_line_get_http_version(tmp_stat_line, env),
                    axis2_http_status_line_get_status_code(tmp_stat_line, env) ,
                    axis2_http_status_line_get_reason_phrase(tmp_stat_line, env));
            axis2_http_simple_response_set_body_stream(response, env,
                    out_stream);
            axis2_http_worker_set_response_headers(http_worker, env, svr_conn,
                    simple_request, response, axutil_stream_get_len(
                        out_stream, env));

            status = axis2_simple_http_svr_conn_write_response(svr_conn, env,
                    response);
            return status;

        }
    }

    op_ctx =  axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if (axis2_op_ctx_get_response_written(op_ctx, env))
    {
        axis2_http_simple_response_set_status_line(response, env, http_version,
                AXIS2_HTTP_RESPONSE_OK_CODE_VAL, "OK");
        axis2_http_simple_response_set_body_stream(response, env, out_stream);
    }
    else
    {
        axis2_http_simple_response_set_status_line(response, env, http_version,
                AXIS2_HTTP_RESPONSE_ACK_CODE_VAL, "Accepted");
    }
    axis2_http_worker_set_response_headers(http_worker, env, svr_conn,
            simple_request, response, axutil_stream_get_len(
                out_stream, env));

    status = axis2_simple_http_svr_conn_write_response(svr_conn, env, response);
    AXIS2_FREE(env->allocator, url_external_form);
    url_external_form = NULL;
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
        
    } /* Done freeing message contexts */
    
    msg_ctx = NULL;
    axutil_url_free(request_url, env);
    axutil_string_free(soap_action_str, env);
    request_url = NULL;
    return status;
}

static axis2_status_t 
axis2_http_worker_set_response_headers(
    axis2_http_worker_t *http_worker,
    const axutil_env_t *env,
    axis2_simple_http_svr_conn_t *svr_conn,
    axis2_http_simple_request_t *simple_request,
    axis2_http_simple_response_t *simple_response,
    axis2_ssize_t content_length)
{
    axis2_http_header_t *conn_header = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, svr_conn, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, simple_request, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, simple_response, AXIS2_FAILURE);
    if (AXIS2_FALSE == axis2_http_simple_response_contains_header
            (simple_response, env, AXIS2_HTTP_HEADER_CONNECTION))
    {
        conn_header = axis2_http_simple_request_get_first_header(simple_request,
                env, AXIS2_HTTP_HEADER_CONNECTION);
        if (conn_header)
        {
            if (0 == axutil_strcasecmp(axis2_http_header_get_value(conn_header,
                    env), AXIS2_HTTP_HEADER_CONNECTION_KEEPALIVE))
            {
                axis2_http_header_t *header = axis2_http_header_create(env,
                        AXIS2_HTTP_HEADER_CONNECTION,
                        AXIS2_HTTP_HEADER_CONNECTION_KEEPALIVE);
                axis2_http_simple_response_set_header(simple_response, env,
                        header);
                axis2_simple_http_svr_conn_set_keep_alive(svr_conn, env,
                        AXIS2_TRUE);
            }
            if (0 == axutil_strcasecmp(axis2_http_header_get_value(conn_header,
                    env), AXIS2_HTTP_HEADER_CONNECTION_CLOSE))
            {
                axis2_http_header_t *header = axis2_http_header_create(env,
                        AXIS2_HTTP_HEADER_CONNECTION,
                        AXIS2_HTTP_HEADER_CONNECTION_CLOSE);
                axis2_http_simple_response_set_header(simple_response, env,
                        header);
                axis2_simple_http_svr_conn_set_keep_alive(svr_conn, env,
                        AXIS2_FALSE);
            }
        }
        else
        {
            if (axis2_http_simple_response_get_http_version(simple_response, env)
                    && axutil_strcasecmp(
                        axis2_http_simple_response_get_http_version(
                            simple_response, env), AXIS2_HTTP_HEADER_PROTOCOL_11))
            {
                axis2_simple_http_svr_conn_set_keep_alive(svr_conn, env,
                        AXIS2_TRUE);
            }
            else
            {
                axis2_simple_http_svr_conn_set_keep_alive(svr_conn, env,
                        AXIS2_FALSE);
            }
        }
        if (AXIS2_FALSE == axis2_http_simple_request_contains_header(
                    simple_request, env,
                    AXIS2_HTTP_HEADER_TRANSFER_ENCODING))
        {
            if (0 != content_length)
            {
                axis2_char_t content_len_str[10];
                axis2_http_header_t *content_len_hdr = NULL;

                sprintf(content_len_str, "%d", content_length);
                content_len_hdr = axis2_http_header_create(
                            env, AXIS2_HTTP_HEADER_CONTENT_LENGTH, content_len_str);
                axis2_http_simple_response_set_header(simple_response, env,
                        content_len_hdr);
            }
        }
        else
        {
            axis2_http_header_t *transfer_enc_header = axis2_http_header_create(
                        env, AXIS2_HTTP_HEADER_TRANSFER_ENCODING,
                        AXIS2_HTTP_HEADER_TRANSFER_ENCODING_CHUNKED);
            axis2_http_simple_response_set_header(simple_response, env,
                    transfer_enc_header);
        }
    }
    return AXIS2_SUCCESS;
}

/*
 * This is only called for HTTP/1.1 to enable 1.1 specific parameters.
 *
 */
static axis2_status_t 
axis2_http_worker_set_transport_out_config(
    axis2_http_worker_t *http_worker,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_http_simple_response_t *simple_response)
{
    axis2_conf_t *config = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, simple_response, AXIS2_FAILURE);

    config =  axis2_conf_ctx_get_conf(conf_ctx, env);

    return AXIS2_SUCCESS;
}

static axutil_hash_t *
axis2_http_worker_get_headers(
    axis2_http_worker_t *http_worker,
    const axutil_env_t *env,
    axis2_http_simple_request_t *request)
{
    axutil_array_list_t *header_list = NULL;
    int hdr_count = 0;
    int i = 0;
    axutil_hash_t *header_map = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, request, AXIS2_FAILURE);

    header_list = axis2_http_simple_request_get_headers(request, env);
    if (!header_list)
    {
        return NULL;
    }
    hdr_count = axutil_array_list_size(header_list, env);
    if (0 == hdr_count)
    {
        return NULL;
    }

    for (i = 0; i < hdr_count; i++)
    {
        axis2_http_header_t *tmp_hdr = NULL;
        tmp_hdr = axutil_array_list_get(header_list, env, i);
        if (!tmp_hdr)
        {
            continue;
        }
        if (!header_map)
        {
            header_map = axutil_hash_make(env);
            if (!header_map)
            {
                return NULL;
            }
        }
        axutil_hash_set(header_map, axis2_http_header_get_name(tmp_hdr, env),
                AXIS2_HASH_KEY_STRING, tmp_hdr);
    }
    return header_map;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_worker_set_svr_port(
    axis2_http_worker_t *worker,
    const axutil_env_t *env,
    int port)
{
    worker->svr_port = port;
    return AXIS2_SUCCESS;
}
