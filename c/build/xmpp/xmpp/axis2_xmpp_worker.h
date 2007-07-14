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

#ifndef AXIS2_XMPP_WORKER_H
#define AXIS2_XMPP_WORKER_H

/**
 * @defgroup axis2_xmpp_worker xmpp worker
 * @ingroup axis2_core_trans_xmpp
 * @{
 */

/**
 * @file axis2_xmpp_worker.h
 * @brief axis2 XMPP Worker
 */

#include <iksemel.h>

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>

#include <axis2_xmpp_session.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_xmpp_worker_ops */
    typedef struct axis2_xmpp_worker_ops axis2_xmpp_worker_ops_t;
    /** Type name for struct axis2_xmpp_worker */
    typedef struct axis2_xmpp_worker axis2_xmpp_worker_t;

    /**
     * XMPP Worker ops struct
     * Encapsulator struct for ops of axis2_xmpp_worker
     */
    struct axis2_xmpp_worker_ops
    {
        /**
         * @param xmpp_worker pointer to xmpp worker
         * @param env pointer to environment struct
         */
        axis2_status_t (AXIS2_CALL *
            run)(
                axis2_xmpp_worker_t *worker,
                const axutil_env_t *env);

        /**
         * @param xmpp_worker pointer to xmpp worker
         * @param env pointer to environment struct
         * @param port
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t (AXIS2_CALL *
                set_svr_port)(
                    axis2_xmpp_worker_t *xmpp_worker,
                    const axutil_env_t *env,
                    int port);

        /**
         * @param xmpp_worker pointer to xmpp worker
         * @param env pointer to environment strut
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t (AXIS2_CALL *
                free)(
                    axis2_xmpp_worker_t *xmpp_worker,
                    const axutil_env_t *env);
    };

    /**
     * axis2 xmpp worker
     */
    struct axis2_xmpp_worker
    {
        /** operations of axis2 xmpp worker */
        axis2_xmpp_worker_ops_t *ops;
    };


    /**
     * @param env pointer to environment struct
     * @param data pointer to XMPP data struct
     */
    AXIS2_EXTERN axis2_xmpp_worker_t * AXIS2_CALL
    axis2_xmpp_worker_create (
        const axutil_env_t *env,
        axis2_xmpp_session_data_t *data);

    /**
     * @param data pointer to xmpp session data struct
     */

    AXIS2_EXTERN int AXIS2_CALL 
    axis2_xmpp_worker_on_data(
        void* user_data,
        int type,
        iks* node);

    AXIS2_EXTERN void AXIS2_CALL 
    axis2_xmpp_worker_on_log(
        void *user_data,
        const char* data,
        size_t size,
        int is_incoming);

    AXIS2_EXTERN int AXIS2_CALL 
    axis2_xmpp_worker_on_iq(
        void *user_data,
        ikspak *pak);



/* Start of function macros ***************************************************/

/** Start the worker. Will connect to the XMPP server and will
    go in to the receive loop
    @sa axis2_xmpp_worker_ops#run */
#define AXIS2_XMPP_WORKER_RUN(xmpp_worker, env) \
    ((xmpp_worker)->ops->run(xmpp_worker, env))
    
/** Sets the server port.
    @sa axis2_xmpp_worker_ops#set_svr_port */
#define AXIS2_XMPP_WORKER_SET_SVR_PORT(xmpp_worker, env, port) \
                ((xmpp_worker)->ops->set_svr_port(xmpp_worker, env, port))

/** Frees the xmpp worker.
    @sa axis2_xmpp_worker_ops#free */
#define AXIS2_XMPP_WORKER_FREE(xmpp_worker, env) \
                ((xmpp_worker)->ops->free(xmpp_worker, env))

/* End of function macros *****************************************************/

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* AXIS2_XMPP_WORKER_H */
