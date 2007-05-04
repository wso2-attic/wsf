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

#ifndef AXIS2_HTTP_SVR_THREAD_H
#define AXIS2_HTTP_SVR_THREAD_H

/**
 * @defgroup axis2_http_svr_thread http server thread 
 * @ingroup axis2_core_trans_http
 * @{
 */

/**
 * @file axis2_http_svr_thread.h
 * @brief axis2 HTTP server listning thread implementation
 */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_http_worker.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axist_http_svr_thread */
    typedef struct axis2_http_svr_thread axis2_http_svr_thread_t;

    extern int axis2_http_socket_read_timeout;

    /**
     * @param svr_thread pointer to server thread
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_svr_thread_run(axis2_http_svr_thread_t *svr_thread,
        const axutil_env_t *env);

    /**
     * @param svr_thread pointer to server thread
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_svr_thread_destroy(axis2_http_svr_thread_t *svr_thread,
        const axutil_env_t *env);

    /**
     * @param svr_thread pointer to server thread
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_http_svr_thread_get_local_port(const axis2_http_svr_thread_t *svr_thread,
        const axutil_env_t *env);

    /**
     * @param svr_thread pointer to server thread
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_http_svr_thread_is_running(axis2_http_svr_thread_t *svr_thread,
        const axutil_env_t *env);

    /**
     * @param svr_thread pointer to server thread
     * @param env pointer to environment struct
     * @param worker pointer to worker
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_http_svr_thread_set_worker(axis2_http_svr_thread_t *svr_thread,
        const axutil_env_t *env,
        axis2_http_worker_t *worker);

    /**
     * @param svr_thread pointer to server thread
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_http_svr_thread_free(axis2_http_svr_thread_t *svr_thread,
        const axutil_env_t *env);

    /**
     * @param env pointer to environment struct
     * @param port
     */
    AXIS2_EXTERN axis2_http_svr_thread_t *AXIS2_CALL
    axis2_http_svr_thread_create (
        const axutil_env_t *env,
        int port);

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_HTTP_SVR_THREAD_H */
