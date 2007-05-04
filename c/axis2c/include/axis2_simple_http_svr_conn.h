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

#ifndef AXIS2_SIMPLE_HTTP_SVR_CONN_H
#define AXIS2_SIMPLE_HTTP_SVR_CONN_H

/**
 * @ingroup axis2_core_transport_http
 * @{
 */


/**
 * @file axis2_simple_http_svr_conn.h
 * @brief Axis2 simple http server connection
 */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_http_simple_request.h>
#include <axis2_http_simple_response.h>
#include <axis2_http_response_writer.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axis2_simple_http_svr_conn axis2_simple_http_svr_conn_t;

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_simple_http_svr_conn_close(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_simple_http_svr_conn_is_open(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     * @param keep_alive 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_simple_http_svr_conn_set_keep_alive(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env,
        axis2_bool_t keep_alive);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_simple_http_svr_conn_is_keep_alive(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axutil_stream_t* AXIS2_CALL
    axis2_simple_http_svr_conn_get_stream(const axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_http_response_writer_t *AXIS2_CALL
    axis2_simple_http_svr_conn_get_writer(const axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_http_simple_request_t *AXIS2_CALL
    axis2_simple_http_svr_conn_read_request(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     * @param response response
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_simple_http_svr_conn_write_response(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env,
        axis2_http_simple_response_t *response);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     * @param timeout timeout
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_simple_http_svr_conn_set_rcv_timeout(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env,
        int timeout);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     * @param timeout timeout
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_simple_http_svr_conn_set_snd_timeout(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env,
        int timeout);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_simple_http_svr_conn_get_svr_ip(const axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_simple_http_svr_conn_get_peer_ip(const axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);

    /**
     * @param svr_conn pointer to server connection struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_simple_http_svr_conn_free(axis2_simple_http_svr_conn_t *svr_conn,
        const axutil_env_t *env);


    /**
     * creates axis2_simple_http_svr_conn struct
     * @param env pointer to environment struct
     * @param sockfd sockfd
     */
    AXIS2_EXTERN axis2_simple_http_svr_conn_t *AXIS2_CALL
    axis2_simple_http_svr_conn_create(
        const axutil_env_t *env, 
        int sockfd);

/** @} */

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_SIMPLE_HTTP_SVR_CONN_H */
