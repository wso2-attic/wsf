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

#ifndef AXIS2_HTTP_SENDER_H
#define AXIS2_HTTP_SENDER_H

/**
 * @ingroup axis2_core_transport_http
 * @{
 */

/**
 * @file axis2_http_sender.h
 * @brief axis2 SOAP over HTTP sender
 */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_msg_ctx.h>
#include <axiom_output.h>
#include <axis2_http_simple_response.h>
#include <axiom_soap_envelope.h>
#include <axis2_http_simple_request.h>

#ifdef AXIS2_LIBCURL_ENABLED
#include <curl/curl.h>
#endif


#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_http_sender_ */
    typedef struct axis2_http_sender axis2_http_sender_t;


    /**
     * @param sender sender
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @param out out
     * @param str_url str url
     * @param soap_action pointer to soap action
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_sender_send(axis2_http_sender_t *sender,
        const axutil_env_t *env, 
        axis2_msg_ctx_t *msg_ctx,
        axiom_soap_envelope_t *out,
        const axis2_char_t *str_url,
        const axis2_char_t *soap_action);


    void AXIS2_CALL
    axis2_http_sender_util_add_header (
        const axutil_env_t *env,
        axis2_http_simple_request_t *request,
        axis2_char_t *header_name,
        const axis2_char_t *header_value);

#ifdef AXIS2_LIBCURL_ENABLED
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_libcurl_http_send(axis2_http_sender_t *sender,
        const axutil_env_t *env, 
        axis2_msg_ctx_t *msg_ctx,
        axiom_soap_envelope_t *out,
        const axis2_char_t *str_url,
        const axis2_char_t *soap_action);
#endif


    /**
     * @param sender sender
     * @param env pointer to environment struct
     * @param chunked chunked
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_sender_set_chunked(axis2_http_sender_t *sender,
        const axutil_env_t *env, 
        axis2_bool_t chunked);

    /**
     * @param sender sender
     * @param env pointer to environment struct
     * @param om_output om output
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_sender_set_om_output(axis2_http_sender_t *sender,
        const axutil_env_t *env, 
        axiom_output_t *om_output);

    /**
     * @param sender sender
     * @param env pointer to environment struct
     * @param version pointer to version
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_sender_set_http_version(axis2_http_sender_t *sender,
        const axutil_env_t *env, 
        axis2_char_t *version);

    /**
     * @param sender sender
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_http_sender_free(axis2_http_sender_t *sender,
        const axutil_env_t *env);

    /**
     * @param sender soap over http sender
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @param response pointer to response
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_sender_get_header_info(axis2_http_sender_t *sender,
        const axutil_env_t *env, 
        axis2_msg_ctx_t *msg_ctx,
        axis2_http_simple_response_t *response);

    /**
     * @param sender soap over http sender
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @param response pointer to response
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_sender_process_response(axis2_http_sender_t *sender,
        const axutil_env_t *env, 
        axis2_msg_ctx_t *msg_ctx,
        axis2_http_simple_response_t *response);


    /**
     * @param sender soap over http sender
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_sender_get_timeout_values(axis2_http_sender_t *sender,
        const axutil_env_t *env, 
        axis2_msg_ctx_t *msg_ctx);

	AXIS2_EXTERN axis2_char_t *AXIS2_CALL
	axis2_http_sender_get_param_string(axis2_http_sender_t *sender,
	const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

    /**
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_http_sender_t *AXIS2_CALL
    axis2_http_sender_create(const axutil_env_t *env);

/** Send. */
#define AXIS2_HTTP_SENDER_SEND(sender, env, msg_ctx, output, url,soap_action)\
	axis2_http_sender_send(sender, env, msg_ctx,output, url, soap_action)

/** Set chunked. */
#define AXIS2_HTTP_SENDER_SET_CHUNKED(sender, env, chunked) \
                        axis2_http_sender_set_chunked(sender, env, chunked)

/** Set om output. */
#define AXIS2_HTTP_SENDER_SET_OM_OUTPUT(sender, env, om_output) \
                        axis2_http_sender_set_om_output (sender, env, om_output)

/** Set http version. */
#define AXIOM_SENDER_SET_HTTP_VERSION(sender, env, version)\
                        axis2_http_sender_set_http_version (sender, env, version)

/** Frees the soap over http sender. */
#define AXIS2_HTTP_SENDER_FREE(sender, env) \
                        axis2_http_sender_free(sender, env)

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* AXIS2_HTTP_SENDER_H */
