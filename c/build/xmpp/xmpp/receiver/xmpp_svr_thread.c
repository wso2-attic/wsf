/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      xmpp://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <signal.h>

#include <axutil_string.h>
#include <platforms/axutil_platform_auto_sense.h>
#include <axiom.h>
#include <axiom_soap.h>
#include <axutil_qname.h>
#include <axis2_svc_ctx.h>
#include <axis2_engine.h>
#include <axutil_error_default.h>
#include <axis2_conf_ctx.h>
#include <axis2_conf.h>
#include <axiom_xml_reader.h>

#include <iksemel.h>

#include <axis2_xmpp_svr_thread.h>
#include <axis2_xmpp_transport.h>

/**
 * @brief XMPP Server Thread struct impl
 * Axis2 XMPP Server Thread impl
 */

typedef struct axis2_xmpp_svr_thread_impl
{
    axis2_xmpp_svr_thread_t svr_thread;
    axis2_bool_t stopped;
    axis2_xmpp_worker_t *worker;
    int port;
    axis2_conf_ctx_t *conf_ctx;
    axutil_array_list_t *xmpp_sessions;
    int use_sasl;
    int use_tls;
    int subscribe;
}
axis2_xmpp_svr_thread_impl_t;

typedef struct axis2_xmpp_svr_thd_args
{
    const axutil_env_t *env;
    axis2_xmpp_worker_t *worker;
}
axis2_xmpp_svr_thd_args_t;


#define AXIS2_INTF_TO_IMPL(xmpp_svr_thread) \
                ((axis2_xmpp_svr_thread_impl_t *)(xmpp_svr_thread))

/***************************** Function headers *******************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_run(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_destroy(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env);

int AXIS2_CALL
axis2_xmpp_svr_thread_get_local_port(
    const axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env);

axis2_bool_t AXIS2_CALL
axis2_xmpp_svr_thread_is_running(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_set_worker(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env,
    axis2_xmpp_worker_t *worker);

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_free(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env);

AXIS2_EXTERN const axutil_env_t *AXIS2_CALL
init_thread_env(
    const axutil_env_t **system_env);

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_get_all_xmpp_services(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env);

void * AXIS2_THREAD_FUNC
worker_func(
    axutil_thread_t *thd,
    void *data);

/***************************** End of function headers ************************/

axis2_xmpp_svr_thread_t *AXIS2_CALL
axis2_xmpp_svr_thread_create(
    const axutil_env_t *env,
    int port,
    axis2_conf_ctx_t *conf_ctx,
    int use_sasl,
    int use_tls,
    int subscribe)
{
    axis2_xmpp_svr_thread_impl_t *impl = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);

    impl = (axis2_xmpp_svr_thread_impl_t *)AXIS2_MALLOC
        (env->allocator, sizeof(axis2_xmpp_svr_thread_impl_t));
    if (!impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    impl->worker = NULL;
    impl->stopped = AXIS2_FALSE;
    impl->port = port;
    impl->conf_ctx = conf_ctx;
    impl->use_sasl = use_sasl;
    impl->use_tls = use_tls;
    impl->subscribe = subscribe;
    
    impl->svr_thread.ops = NULL;
    impl->svr_thread.ops = AXIS2_MALLOC(env->allocator,
        sizeof(axis2_xmpp_svr_thread_ops_t));
    if (!impl->svr_thread.ops)
    {
        axis2_xmpp_svr_thread_free((axis2_xmpp_svr_thread_t *)impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    impl->svr_thread.ops->run = axis2_xmpp_svr_thread_run;
    impl->svr_thread.ops->destroy = axis2_xmpp_svr_thread_destroy;
    impl->svr_thread.ops->get_local_port = axis2_xmpp_svr_thread_get_local_port;
    impl->svr_thread.ops->is_running = axis2_xmpp_svr_thread_is_running;
    impl->svr_thread.ops->set_worker = axis2_xmpp_svr_thread_set_worker;
    impl->svr_thread.ops->free = axis2_xmpp_svr_thread_free;

    return &(impl->svr_thread);
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_free(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    axis2_xmpp_svr_thread_impl_t *svr_thread_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    svr_thread_impl = AXIS2_INTF_TO_IMPL(svr_thread);

    if (svr_thread_impl->worker)
    {
        AXIS2_XMPP_WORKER_FREE(svr_thread_impl->worker, env);
        svr_thread_impl->worker = NULL;
    }

    svr_thread_impl->stopped = AXIS2_TRUE;
    if (svr_thread->ops)
        AXIS2_FREE(env->allocator, svr_thread->ops);

    AXIS2_FREE(env->allocator, AXIS2_INTF_TO_IMPL(svr_thread));
    return AXIS2_SUCCESS;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_run(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    axis2_xmpp_svr_thread_impl_t *impl = NULL;
    axis2_xmpp_worker_t *worker = NULL;
    axutil_thread_t *worker_thread = NULL;
    axis2_xmpp_svr_thd_args_t *args = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    int svc_count = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    impl = AXIS2_INTF_TO_IMPL(svr_thread);

    /* Get all the services with a mapping jid from the conf ctx */

    status = axis2_xmpp_svr_thread_get_all_xmpp_services(svr_thread, env);
    if (status != AXIS2_SUCCESS)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to enumerate all "
                "XMPP services");
        return status;
    }

    /* Create an xmpp worker for each service in the above list and spawn the
     * worker on a different thread. Wait until child threads exit. Unlike the
     * http transport which keeps listening, the main thread here is not doing
     * any work */

    args = AXIS2_MALLOC(env->allocator, sizeof(axis2_xmpp_svr_thd_args_t));

    svc_count = AXIS2_ARRAY_LIST_SIZE(impl->xmpp_sessions, env);
    if (svc_count <= 0)
    {
        AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI, "No services to be exposed "
               " as XMPP services");
        return AXIS2_FAILURE;
    }

#ifndef AXIS2_SVR_MULTI_THREADED
    if (svc_count > 1)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Cannot expose multiple XMPP "
                "services in single threaded server mode");
        return AXIS2_FAILURE;
    }
#endif

    int i = 0;
    for (i=0; i < svc_count; i++)
    {
        axis2_xmpp_session_data_t *session = NULL;

        session = AXIS2_ARRAY_LIST_GET(impl->xmpp_sessions, env, i);
        session->conf_ctx = impl->conf_ctx;
        worker = axis2_xmpp_worker_create(env, session);
        if (!worker)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    
        AXIS2_XMPP_WORKER_SET_SVR_PORT(worker, env, impl->port);

        args->env = env;
        args->worker = worker;

#ifdef AXIS2_SVR_MULTI_THREADED
        worker_thread = AXIS2_THREAD_POOL_GET_THREAD(env->thread_pool,
            worker_func, (void *)args);
        if (!worker_thread)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create worker thread");
            continue;
        }

        if (i == (svc_count -1)) 
            AXIS2_THREAD_POOL_JOIN_THREAD(env->thread_pool, worker_thread);
        else
            AXIS2_THREAD_POOL_THREAD_DETACH(env->thread_pool, worker_thread);

#else
        worker_func(NULL, (void*)args);
#endif
    }
	
    return AXIS2_SUCCESS;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_destroy(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    axis2_xmpp_svr_thread_impl_t *svr_thread_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Terminating XMPP server "
            "thread...");
    
    svr_thread_impl = AXIS2_INTF_TO_IMPL(svr_thread);
    if (AXIS2_TRUE == svr_thread_impl->stopped)
    {
        return AXIS2_SUCCESS;
    }
    
    svr_thread_impl->stopped = AXIS2_TRUE;    

    /* TODO: stop all the child threads */

    return AXIS2_SUCCESS;
}

/*****************************************************************************/

int AXIS2_CALL
axis2_xmpp_svr_thread_get_local_port(
    const axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    return AXIS2_INTF_TO_IMPL(svr_thread)->port;
}

/*****************************************************************************/

axis2_bool_t AXIS2_CALL
axis2_xmpp_svr_thread_is_running(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return AXIS2_INTF_TO_IMPL(svr_thread)->port;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_set_worker(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env,
    axis2_xmpp_worker_t *worker)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, worker, AXIS2_FAILURE);
    AXIS2_INTF_TO_IMPL(svr_thread)->worker = worker;
    return AXIS2_SUCCESS;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_get_all_xmpp_services(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    axis2_xmpp_svr_thread_impl_t *impl = NULL;
    axis2_conf_t *conf = NULL;
    axutil_hash_t *services = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    impl = AXIS2_INTF_TO_IMPL(svr_thread);

    impl->xmpp_sessions = axutil_array_list_create(env, 0);

    if (!impl->xmpp_sessions)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create services list");
        return AXIS2_FAILURE;
    }

    conf = AXIS2_CONF_CTX_GET_CONF(impl->conf_ctx, env);
    if (!conf)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to get reference to conf");
        return AXIS2_FAILURE;
    }

    services = AXIS2_CONF_GET_ALL_SVCS(conf, env);
    if (!services)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to get list of services");
        return AXIS2_FAILURE;
    }

    /* Go thru all the services and see whether they have a parameter
     * referring to an XMPP ID (i.e. a JID). If so, create an XMPP seesion data 
     * struct and add it to the session list. Later, we make XMPP connections
     * to expose those services */ 
    axutil_hash_index_t *hi = NULL;
    void *val = NULL;
    for (hi = axutil_hash_first(services, env); hi; hi = axutil_hash_next(env, hi))
    {
        axis2_svc_t *svc = NULL;
        axutil_param_t *param_jid = NULL;
        axutil_param_t *param_pw = NULL;
        axis2_char_t *jid = NULL;
        axis2_char_t *pw = NULL;
        axis2_xmpp_session_data_t *session = NULL;

        axutil_hash_this(hi, NULL, NULL, &val);
        svc = (axis2_svc_t*)val;
        if (svc)
        {
            param_jid = AXIS2_SVC_GET_PARAM(svc, env, AXIS2_XMPP_PARAM_ID);
            if (!param_jid)
            {
                /* A JID not given for service. No need to create an XMPP
                 * connection */
                continue;
            }
            
            param_pw = AXIS2_SVC_GET_PARAM(svc, env, AXIS2_XMPP_PARAM_PASSWORD);
            if (!param_pw)
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "A JID is given without"
                    " a password. Service: %s", AXIS2_SVC_GET_NAME(svc, env));
                continue;
            }

            jid = (axis2_char_t*)AXIS2_PARAM_GET_VALUE(param_jid, env);
            pw = (axis2_char_t*)AXIS2_PARAM_GET_VALUE(param_pw, env);

            session = (axis2_xmpp_session_data_t*)AXIS2_MALLOC(env->allocator,
                    sizeof(axis2_xmpp_session_data_t));
            axis2_xmpp_session_data_init(session);
            session->id_str = jid;
            session->password = pw;
            session->use_sasl = impl->use_sasl;
            session->use_tls = impl->use_tls;
            session->subscribe = impl->subscribe;
            session->svc = svc;

            axis2_xmpp_svr_thread_get_subscribing_ops(svr_thread, env, svc,
                    session);

            axutil_array_list_add(impl->xmpp_sessions, env, (void*)session);
        }

        val = NULL;
    }

    return AXIS2_SUCCESS;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_svr_thread_get_subscribing_ops(
    axis2_xmpp_svr_thread_t *svr_thread,
    const axutil_env_t *env,
    axis2_svc_t *svc,
    axis2_xmpp_session_data_t* session)
{
    axis2_xmpp_svr_thread_impl_t *impl = NULL;
    axutil_hash_t *ops = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    impl = AXIS2_INTF_TO_IMPL(svr_thread);

    ops = AXIS2_SVC_GET_ALL_OPS(svc, env);
    if (!ops)
    {
        /* No ops in the service */
        return AXIS2_SUCCESS;
    }

    /* Go thru all the operations and see whether they have a parameter
     * giving a JID to subscribe to. If a subscription ID is given, then
     * the type of the ID (i.e. whether a user or a chat room) must also
     * be given. If both are given, save it in the session with the
     * operation qname */ 

    axutil_hash_index_t *hi = NULL;
    void *val = NULL;
    for (hi = axutil_hash_first(ops, env); hi; hi = axutil_hash_next(env, hi))
    {
        axis2_op_t *op= NULL;
        axutil_param_t *param_jid = NULL;
        axutil_param_t *param_type = NULL;
        axis2_char_t *jid = NULL;
        axis2_char_t *type = NULL;
        const axutil_qname_t *qname = NULL;
        axis2_char_t *op_name = NULL;

        axutil_hash_this(hi, NULL, NULL, &val);
        op = (axis2_op_t*)val;
        if (op)
        {
            param_jid = AXIS2_OP_GET_PARAM(op, env, AXIS2_XMPP_PARAM_SUBSCRIBE_TO);
            if (!param_jid)
            {
                /* No subscription JID */
                continue;
            }
            
            qname = AXIS2_OP_GET_QNAME(op, env);
            op_name = AXIS2_QNAME_GET_LOCALPART(qname, env);

            param_type  = AXIS2_OP_GET_PARAM(op, env, AXIS2_XMPP_PARAM_SUBSCRIBE_TYPE);
            if (!param_type)
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "A Subscribe JID is given without"
                    " the type. Service: %s | Operation: %s", AXIS2_SVC_GET_NAME(svc, env),
                    op_name);
                continue;
            }

            jid = (axis2_char_t*)AXIS2_PARAM_GET_VALUE(param_jid, env);
            type = (axis2_char_t*)AXIS2_PARAM_GET_VALUE(param_type, env);

            session->subscribe_to = jid;
            session->subscribe_type = type;
            session->subscribe_op = op_name;
        }

        val = NULL;
    }

    return AXIS2_SUCCESS;
}

/*****************************************************************************/

/**
 * Thread worker function.
 */
void * AXIS2_THREAD_FUNC
worker_func(
    axutil_thread_t *thd,
    void *data)
{
    axis2_xmpp_svr_thd_args_t* args = NULL;

    args = (axis2_xmpp_svr_thd_args_t*)data;
    
    AXIS2_XMPP_WORKER_RUN(args->worker, args->env);
    
    return NULL;
}
