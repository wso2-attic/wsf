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

#ifndef AXIS2_HTTP_TRANSPORT_UTILS_H
#define AXIS2_HTTP_TRANSPORT_UTILS_H

/**
 * @ingroup axis2_core_transport_http
 * @{
 */


/**
  * @file axis2_http_transport_utils.h
  * @brief axis2 HTTP Transport Utility class
  */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axiom_stax_builder.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axutil_hash.h>
#include <axiom_element.h>
#include <axutil_stream.h>
#include <axiom_soap_envelope.h>
#include <axis2_http_chunked_stream.h>
#include <axutil_url.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /*
     * struct to hold the callback information
     */
    struct axis2_callback_info
    {
        const axutil_env_t *env;
        void *in_stream;
        int content_length;
        int unread_len;
        axis2_http_chunked_stream_t *chunked_stream;
    };
    typedef struct axis2_callback_info axis2_callback_info_t;

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_transport_utils_process_http_post_request(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        axutil_stream_t *in_stream,
        axutil_stream_t *out_stream,
        const axis2_char_t *content_type,
        const int content_length,
        axutil_string_t *soap_action_header,
        const axis2_char_t *request_uri);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_http_transport_utils_process_http_get_request(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        axutil_stream_t *in_stream,
        axutil_stream_t *out_stream,
        const axis2_char_t *content_type,
        axutil_string_t *soap_action_header,
        const axis2_char_t *request_uri,
        axis2_conf_ctx_t *conf_ctx,
        axutil_hash_t *request_params);

    AXIS2_EXTERN axiom_stax_builder_t *AXIS2_CALL
    axis2_http_transport_utils_select_builder_for_mime(
        const axutil_env_t *env, 
        axis2_char_t *request_uri,
        axis2_msg_ctx_t *msg_ctx, 
        axutil_stream_t *in_stream,
        axis2_char_t *content_type);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_http_transport_utils_do_write_mtom(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_http_transport_utils_is_doing_rest(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_http_transport_utils_is_doing_rest_through_post(
        const axutil_env_t *env, 
        axis2_msg_ctx_t *msg_ctx);

    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_http_transport_utils_get_request_params(
        const axutil_env_t *env,
        axis2_char_t *request_uri);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_http_transport_utils_get_services_html(
        const axutil_env_t *env,
        axis2_conf_ctx_t *conf_ctx);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_http_transport_utils_get_services_static_wsdl(
        const axutil_env_t *env,
        axis2_conf_ctx_t *conf_ctx,
        axis2_char_t *request_url);

    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_http_transport_utils_get_request_params(
        const axutil_env_t *env,
        axis2_char_t *request_uri);

    AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
    axis2_http_transport_utils_create_soap_msg(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        const axis2_char_t *soap_ns_uri);


/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_HTTP_TRANSPORT_UTILS_H */
