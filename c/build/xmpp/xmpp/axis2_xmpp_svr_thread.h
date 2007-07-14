/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXIS2_XMPP_SVR_THREAD_H
#define AXIS2_XMPP_SVR_THREAD_H

/**
 * @defgroup axis2_xmpp_svr_thread xmpp server thread 
 * @ingroup axis2_core_trans_xmpp
 * @{
 */

/**
 * @file axis2_xmpp_svr_thread.h
 * @brief axis2 XMPP server listning thread implementation
 */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>

#include <axis2_xmpp_worker.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axist_xmpp_svr_thread_ops */
    typedef struct axis2_xmpp_svr_thread_ops axis2_xmpp_svr_thread_ops_t;
    /** Type name for struct axist_xmpp_svr_thread */
    typedef struct axis2_xmpp_svr_thread axis2_xmpp_svr_thread_t;

    extern int axis2_xmpp_socket_read_timeout;

    /**
     * XMPP Server Thread ops struct
     * Encapsulator struct for ops of axis2_xmpp_svr_thread
     */
    struct axis2_xmpp_svr_thread_ops
    {
        /**
         * @param svr_thread pointer to server thread
         * @param env pointer to environment struct
         */
        axis2_status_t (AXIS2_CALL *
                run)(
                    axis2_xmpp_svr_thread_t *svr_thread,
                    const axutil_env_t *env);

        /**
         * @param svr_thread pointer to server thread
         * @param env pointer to environment struct
         */
        axis2_status_t (AXIS2_CALL *
                destroy)(
                    axis2_xmpp_svr_thread_t *svr_thread,
                    const axutil_env_t *env);

        /**
         * @param svr_thread pointer to server thread
         * @param env pointer to environment struct
         */
        int (AXIS2_CALL *
                get_local_port)(
                    const axis2_xmpp_svr_thread_t *svr_thread,
                    const axutil_env_t *env);

        /**
         * @param svr_thread pointer to server thread
         * @param env pointer to environment struct
         */
        axis2_bool_t (AXIS2_CALL *
                is_running)(
                    axis2_xmpp_svr_thread_t *svr_thread,
                    const axutil_env_t *env);

        /**
         * @param svr_thread pointer to server thread
         * @param env pointer to environment struct
         * @param worker pointer to worker
         */
        axis2_status_t (AXIS2_CALL *
                set_worker)(
                    axis2_xmpp_svr_thread_t *svr_thread,
                    const axutil_env_t *env,
                    axis2_xmpp_worker_t *worker);

        /**
         * @param svr_thread pointer to server thread
         * @param env pointer to environment struct
         */
        axis2_status_t (AXIS2_CALL *
                free)(
                    axis2_xmpp_svr_thread_t *svr_thread,
                    const axutil_env_t *env);
    };

    /**
     * axis2 xmpp server thread
     */
    struct axis2_xmpp_svr_thread
    {
        /** operations of axis2 xmpp server thread */
        axis2_xmpp_svr_thread_ops_t *ops;
    };

    /**
     * @param env pointer to environment struct
     * @param port
     */
    AXIS2_EXTERN axis2_xmpp_svr_thread_t *AXIS2_CALL
    axis2_xmpp_svr_thread_create (
        const axutil_env_t *env,
        int port,
        axis2_conf_ctx_t *conf_ctx,
        int use_sasl,
        int use_tls,
        int subscribe);

/************************** Start of function macros **************************/

/** Run.
    @sa axis2_xmpp_svr_thread_ops#run */
#define AXIS2_XMPP_SVR_THREAD_RUN(svr_thread, env) \
                  ((svr_thread)->ops->run(svr_thread, env))

/** Destroy.
    @sa axis2_xmpp_svr_thread_ops#destroy */
#define AXIS2_XMPP_SVR_THREAD_DESTROY(svr_thread, env) \
                        ((svr_thread)->ops->destroy(svr_thread, env))

/** Gets the local port.
    @sa axis2_xmpp_svr_thread_ops#get_local_port */
#define AXIS2_XMPP_SVR_THREAD_GET_LOCAL_PORT(svr_thread, env) \
                        ((svr_thread)->ops->get_local_port(svr_thread,\
                  env))

/** Is running.
    @sa axis2_xmpp_svr_thread_ops#is_running */
#define AXIS2_XMPP_SVR_THREAD_IS_RUNNING(svr_thread, env) \
                        ((svr_thread)->ops->is_running(svr_thread, env))

/** Set worker.
    @sa axis2_xmpp_svr_thread_ops#set_worker */
#define AXIS2_XMPP_SVR_THREAD_SET_WORKER(svr_thread, env, worker) \
                        ((svr_thread)->ops->set_worker(svr_thread, env,\
                  worker))

/** Frees the xmpp_svr_thread.
    @sa axis2_xmpp_svr_thread_ops#free */
#define AXIS2_XMPP_SVR_THREAD_FREE(svr_thread, env) \
                ((svr_thread)->ops->free(svr_thread, env))

/************************** End of function macros ****************************/

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_XMPP_SVR_THREAD_H */
