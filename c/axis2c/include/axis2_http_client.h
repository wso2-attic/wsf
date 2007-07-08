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

#ifndef AXIS2_HTTP_CLIENT_H
#define AXIS2_HTTP_CLIENT_H

/**
 * @defgroup axis2_http_client http client
 * @ingroup axis2_core_trans_http
 * Description
 * @{
 */

/**
 * @file axis2_http_client.h
 * @brief axis2 HTTP Header name:value pair implementation
 */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_http_simple_response.h>
#include <axis2_http_simple_request.h>
#include <axutil_url.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_http_client */
    typedef struct axis2_http_client axis2_http_client_t;


    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     * @param request pointer to request
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_client_send(axis2_http_client_t *client,
        const axutil_env_t *env,
        axis2_http_simple_request_t *request,
        axis2_char_t *ssl_pp);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_http_client_recieve_header(axis2_http_client_t *client,
        const axutil_env_t *env);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_http_simple_response_t *AXIS2_CALL
    axis2_http_client_get_response(const axis2_http_client_t *client,
        const axutil_env_t *env);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     * @param url pointer to url
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_client_set_url(axis2_http_client_t *client,
        const axutil_env_t *env,
        axutil_url_t *url);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axutil_url_t *AXIS2_CALL
    axis2_http_client_get_url(const axis2_http_client_t *client,
        const axutil_env_t *env);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     * @param timeout_ms
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_client_set_timeout(axis2_http_client_t *client,
        const axutil_env_t *env,
        int timeout_ms);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_http_client_get_timeout(const axis2_http_client_t *client,
        const axutil_env_t *env);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     * @param proxy_host pointer to proxy host
     * @param proxy_port
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_client_set_proxy(axis2_http_client_t *client,
        const axutil_env_t *env,
        axis2_char_t *proxy_host,
        int proxy_port);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_http_client_get_proxy(const axis2_http_client_t *client,
        const axutil_env_t *env);

	AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_client_connect_ssl_host(axis2_http_client_t *client,
        const axutil_env_t *env,
        axis2_char_t *host,
        int port);
    
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_client_set_dump_input_msg(axis2_http_client_t *client,
        const axutil_env_t *env,
        axis2_bool_t dump_input_msg);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     * @param server_cert server certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_client_set_server_cert(axis2_http_client_t *client,
        const axutil_env_t *env,
        axis2_char_t *server_cert);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_http_client_get_server_cert(const axis2_http_client_t *client,
        const axutil_env_t *env);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     * @param key_file chain file containing 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_client_set_key_file(axis2_http_client_t *client,
        const axutil_env_t *env,
        axis2_char_t *key_file);

    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_http_client_get_key_file(const axis2_http_client_t *client,
        const axutil_env_t *env);


    /**
     * @param client pointer to client
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_http_client_free(axis2_http_client_t *client,
        const axutil_env_t *env);

    /**
     * @param env pointer to environment struct
     * @param url pointer to url
     */
    AXIS2_EXTERN axis2_http_client_t *AXIS2_CALL
    axis2_http_client_create (const axutil_env_t *env,
        axutil_url_t *url);

    /**
     * Free http_client passed as void pointer. This will be
     * cast into appropriate type and then pass the cast object
     * into the http_client structure's free method
     * @param client
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_http_client_free_void_arg (void *client,
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_HTTP_CLIENT_H */
