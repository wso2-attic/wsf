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

#include <iksemel.h>

#include <axis2_transport_in_desc.h>
#include <axis2_param_container.h>
#include <axis2_url.h>
#include <axis2_conf_init.h>

#include <axis2_xmpp_server.h>
#include <axis2_xmpp_transport.h>
#include <axis2_xmpp_svr_thread.h>
#include <axis2_xmpp_worker.h>

/**
 * @brief XMPP server struct impl
 *   Axis2 XMPP server impl
 */

typedef struct axis2_xmpp_server_impl
{
    axis2_transport_receiver_t xmpp_server;
    axis2_xmpp_svr_thread_t *svr_thread;
    int port;
    axis2_conf_ctx_t* conf_ctx;
    axis2_conf_ctx_t* conf_ctx_private;
    int use_sasl;
    int use_tls;
    int subscribe;
}
axis2_xmpp_server_impl_t;

#define AXIS2_INTF_TO_IMPL(xmpp_server) \
                ((axis2_xmpp_server_impl_t *)(xmpp_server))

/* Function headers ***********************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_server_init(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_in_desc_t *in_desc);

axis2_status_t AXIS2_CALL
axis2_xmpp_server_start(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env);

axis2_status_t AXIS2_CALL
axis2_xmpp_server_stop(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env);

axis2_conf_ctx_t *AXIS2_CALL
axis2_xmpp_server_get_conf_ctx(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env);

axis2_endpoint_ref_t *AXIS2_CALL
axis2_xmpp_server_get_reply_to_epr(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env,
    const axis2_char_t *svc_name);

axis2_bool_t AXIS2_CALL
axis2_xmpp_server_is_running(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env);

axis2_status_t AXIS2_CALL
axis2_xmpp_server_free(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env);

/* End of function headers ****************************************************/

/******************************************************************************/

AXIS2_EXTERN axis2_transport_receiver_t *AXIS2_CALL
axis2_xmpp_server_create(
    const axis2_env_t *env,
    const axis2_char_t *repo,
    const int port,
    int use_sasl,
    int use_tls,
    int subscribe)
{
    axis2_xmpp_server_impl_t *impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    impl = (axis2_xmpp_server_impl_t *)AXIS2_MALLOC
            (env->allocator, sizeof(axis2_xmpp_server_impl_t));

    if (!impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    impl->svr_thread = NULL;
    impl->conf_ctx = NULL;
    impl->conf_ctx_private = NULL;
    impl->port = port;
    impl->use_sasl = use_sasl;
    impl->use_tls = use_tls;
    impl->subscribe = subscribe;

    impl->xmpp_server.ops = AXIS2_MALLOC(env->allocator,
            sizeof(axis2_transport_receiver_ops_t));
    if (!impl->xmpp_server.ops)
    {
        axis2_xmpp_server_free((axis2_transport_receiver_t *)impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    if (repo)
    {
        /**
         * We first create a private conf ctx which is owned by this server
         * we only free this private conf context. We should never free the
         * impl->conf_ctx because it may belong to any other object
         * which may lead to double free
         */
        impl->conf_ctx_private = build_conf_ctx(env, repo);
        if (!impl->conf_ctx_private)
        {
            axis2_xmpp_server_free((axis2_transport_receiver_t *) impl, env);
            return NULL;
        }
        impl->conf_ctx = impl->conf_ctx_private;
    }

    impl->xmpp_server.ops->init = axis2_xmpp_server_init;
    impl->xmpp_server.ops->start = axis2_xmpp_server_start;
    impl->xmpp_server.ops->stop = axis2_xmpp_server_stop;
    impl->xmpp_server.ops->get_reply_to_epr = axis2_xmpp_server_get_reply_to_epr;
    impl->xmpp_server.ops->get_conf_ctx = axis2_xmpp_server_get_conf_ctx;
    impl->xmpp_server.ops->is_running = axis2_xmpp_server_is_running;
    impl->xmpp_server.ops->free = axis2_xmpp_server_free;

    return &(impl->xmpp_server);
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_server_free(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env)
{
    axis2_xmpp_server_impl_t *impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    impl = AXIS2_INTF_TO_IMPL(server);
    if (impl->svr_thread)
    {
        AXIS2_XMPP_SVR_THREAD_DESTROY(impl->svr_thread, env);
        AXIS2_XMPP_SVR_THREAD_FREE(impl->svr_thread, env);
        impl->svr_thread = NULL;
    }

    if (impl->conf_ctx_private)
    {
        AXIS2_CONF_CTX_FREE(impl->conf_ctx_private, env);
        impl->conf_ctx_private = NULL;
    }

    /**
     * Do not free this. It may belong to some other object
     */
    impl->conf_ctx = NULL;

    if (server->ops)
    {
        AXIS2_FREE(env->allocator, server->ops);
    }

    AXIS2_FREE(env->allocator, impl);

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_xmpp_server_init(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_in_desc_t *in_desc)
{
    axis2_xmpp_server_impl_t *server_impl = NULL;
    axis2_char_t *port_str = NULL;
    axis2_param_t *param = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    server_impl = AXIS2_INTF_TO_IMPL(server);

    server_impl->conf_ctx = conf_ctx;

    param = (axis2_param_t *)AXIS2_PARAM_CONTAINER_GET_PARAM(
                in_desc->param_container, env, "port");
    if (param)
    {
        port_str = AXIS2_PARAM_GET_VALUE(param, env);
    }

    if (port_str)
    {
        server_impl->port = atoi(port_str);
    }

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_xmpp_server_start(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env)
{
    axis2_xmpp_server_impl_t *impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    impl = AXIS2_INTF_TO_IMPL(server);

    impl->svr_thread = axis2_xmpp_svr_thread_create(env, impl->port,
            impl->conf_ctx, impl->use_sasl, impl->use_tls, impl->subscribe);
    if (!impl->svr_thread)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    AXIS2_LOG_INFO(env->log, "Starting XMPP server thread...");

    AXIS2_XMPP_SVR_THREAD_RUN(impl->svr_thread, env);

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_xmpp_server_stop(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIS2_LOG_INFO(env->log, "Terminating XMPP server thread");
    if (AXIS2_INTF_TO_IMPL(server)->svr_thread)
    {
        AXIS2_XMPP_SVR_THREAD_DESTROY(AXIS2_INTF_TO_IMPL(server)->svr_thread,
                env);
    }
    AXIS2_LOG_INFO(env->log, "Successfully terminated  XMPP server"
            " thread");
    return AXIS2_SUCCESS;
}

axis2_conf_ctx_t *AXIS2_CALL
axis2_xmpp_server_get_conf_ctx(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return AXIS2_INTF_TO_IMPL(server)->conf_ctx;
}

axis2_endpoint_ref_t *AXIS2_CALL
axis2_xmpp_server_get_reply_to_epr(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env,
    const axis2_char_t *svc_name)
{
    axis2_endpoint_ref_t *epr = NULL;
    const axis2_char_t *host_address = NULL;
    axis2_char_t *svc_path = NULL;
    axis2_url_t *url = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, svc_name, NULL);

    host_address = "127.0.0.1"; /* TODO : get from axis2.xml */
    svc_path = AXIS2_STRACAT("/axis2/services/", svc_name, env);
    url = axis2_url_create(env, "xmpp", host_address,
            AXIS2_INTF_TO_IMPL(server)->port, svc_path);
    AXIS2_FREE(env->allocator, svc_path);
    if (NULL == url)
    {
        return NULL;
    }
    epr = axis2_endpoint_ref_create(env, AXIS2_URL_TO_EXTERNAL_FORM(url, env));
    AXIS2_URL_FREE(url, env);
    return epr;
}

axis2_bool_t AXIS2_CALL
axis2_xmpp_server_is_running(
    axis2_transport_receiver_t *server,
    const axis2_env_t *env)
{
    axis2_xmpp_server_impl_t *server_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    server_impl = AXIS2_INTF_TO_IMPL(server);
    if (NULL == server_impl->svr_thread)
    {
        return AXIS2_FALSE;
    }
    else
    {
        return AXIS2_XMPP_SVR_THREAD_IS_RUNNING(server_impl->svr_thread, env);
    }
    return AXIS2_FALSE;
}

/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int axis2_get_instance(
    struct axis2_transport_receiver **inst,
    const axis2_env_t *env)
{
    *inst = axis2_xmpp_server_create(env, NULL, -1, 0, 0, 0);
    if (!(*inst))
    {
        printf("transport receiver load not success\n");
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int axis2_remove_instance(
    axis2_transport_receiver_t *inst,
    const axis2_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (inst)
    {
        status = AXIS2_TRANSPORT_RECEIVER_FREE(inst, env);
    }
    return status;
}
