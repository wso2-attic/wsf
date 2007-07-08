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

#include <axis2_http_server.h>

#include <axis2_http_transport.h>
#include <axis2_http_svr_thread.h>
#include <axis2_http_server.h>
#include <axis2_transport_in_desc.h>
#include <axutil_param_container.h>
#include <axutil_url.h>
#include <axis2_conf_init.h>

/**
 * @brief HTTP Client struct impl
 *   Axis2 HTTP Client impl
 */

typedef struct axis2_http_server_impl
{
    axis2_transport_receiver_t http_server;
    axis2_http_svr_thread_t *svr_thread;
    int port;
    axis2_conf_ctx_t* conf_ctx;
    axis2_conf_ctx_t* conf_ctx_private;
}
axis2_http_server_impl_t;

#define AXIS2_INTF_TO_IMPL(http_server) \
                ((axis2_http_server_impl_t *)(http_server))

/***************************** Function headers *******************************/

axis2_status_t AXIS2_CALL
axis2_http_server_init(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_in_desc_t *in_desc);

axis2_status_t AXIS2_CALL
axis2_http_server_start(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_http_server_stop(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env);

axis2_conf_ctx_t *AXIS2_CALL
axis2_http_server_get_conf_ctx(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env);

axis2_endpoint_ref_t *AXIS2_CALL
axis2_http_server_get_reply_to_epr(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env,
    const axis2_char_t *svc_name);

axis2_bool_t AXIS2_CALL
axis2_http_server_is_running(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env);

void AXIS2_CALL
axis2_http_server_free(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env);

static const axis2_transport_receiver_ops_t http_transport_receiver_ops_var = {
    axis2_http_server_init,
    axis2_http_server_start,
    axis2_http_server_get_reply_to_epr,
    axis2_http_server_get_conf_ctx,
    axis2_http_server_is_running,
    axis2_http_server_stop,
    axis2_http_server_free
};

AXIS2_EXTERN axis2_transport_receiver_t *AXIS2_CALL
axis2_http_server_create(
    const axutil_env_t *env,
    const axis2_char_t *repo,
    const int port)
{
    axis2_http_server_impl_t *server_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    server_impl = (axis2_http_server_impl_t *)AXIS2_MALLOC
            (env->allocator, sizeof(axis2_http_server_impl_t));

    if (! server_impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    server_impl->svr_thread = NULL;
    server_impl->conf_ctx = NULL;
    server_impl->conf_ctx_private = NULL;
    server_impl->port = port;

    server_impl->http_server.ops = &http_transport_receiver_ops_var;
    
    if (repo)
    {
        /**
         * We first create a private conf ctx which is owned by this server
         * we only free this private conf context. We should never free the
         * server_impl->conf_ctx because it may own to any other object which
         * may lead to double free
         */
        server_impl->conf_ctx_private = axis2_build_conf_ctx(env, repo);
        if (! server_impl->conf_ctx_private)
        {
            axis2_http_server_free((axis2_transport_receiver_t *) server_impl, env);
            return NULL;
        }
        server_impl->conf_ctx = server_impl->conf_ctx_private;
    }

    return &(server_impl->http_server);
}

void AXIS2_CALL
axis2_http_server_free(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env)
{
    axis2_http_server_impl_t *server_impl = NULL;
    AXIS2_ENV_CHECK(env, void);
    server_impl = AXIS2_INTF_TO_IMPL(server);
    if (server_impl->svr_thread)
    {
        axis2_http_svr_thread_destroy(server_impl->svr_thread, env);
        axis2_http_svr_thread_free(server_impl->svr_thread, env);
        server_impl->svr_thread = NULL;
    }

    if (server_impl->conf_ctx_private)
    {
         axis2_conf_ctx_free(server_impl->conf_ctx_private, env);
        server_impl->conf_ctx_private = NULL;
    }
    /**
     * Do not free this. It may own to some other object
     */
    server_impl->conf_ctx = NULL;

    AXIS2_FREE(env->allocator, server_impl);
    return;
}


axis2_status_t AXIS2_CALL
axis2_http_server_init(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_in_desc_t *in_desc)
{
    axis2_http_server_impl_t *server_impl = NULL;
    axis2_char_t *port_str = NULL;
    axutil_param_t *param = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    server_impl = AXIS2_INTF_TO_IMPL(server);

    server_impl->conf_ctx = conf_ctx;
    param = (axutil_param_t *)axutil_param_container_get_param(
                axis2_transport_in_desc_param_container(in_desc, env), 
                env, "port");
    if (param)
    {
        port_str = axutil_param_get_value(param, env);
    }
    if (port_str)
    {
        server_impl->port = atoi(port_str);
    }
    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_http_server_start(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env)
{

    axis2_http_server_impl_t *server_impl = NULL;
    axis2_http_worker_t *worker = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    server_impl = AXIS2_INTF_TO_IMPL(server);
    server_impl->svr_thread = axis2_http_svr_thread_create(env,
            server_impl->port);
    if (! server_impl->svr_thread)
    {
        return AXIS2_FAILURE;
    }
    worker = axis2_http_worker_create(env, server_impl->conf_ctx);
    axis2_http_worker_set_svr_port(worker, env, server_impl->port);
    if (! worker)
    {
        axis2_http_svr_thread_free(server_impl->svr_thread, env);
        return AXIS2_FAILURE;
    }
    AXIS2_LOG_INFO(env->log, "Starting HTTP server thread");
    axis2_http_svr_thread_set_worker(server_impl->svr_thread, env, worker);
    axis2_http_svr_thread_run(server_impl->svr_thread, env);
    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_http_server_stop(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIS2_LOG_INFO(env->log, "Terminating HTTP server thread");
    if (AXIS2_INTF_TO_IMPL(server)->svr_thread)
    {
        axis2_http_svr_thread_destroy(AXIS2_INTF_TO_IMPL(server)->svr_thread,
                env);
    }
    AXIS2_LOG_INFO(env->log, "Successfully terminated  HTTP server"
            " thread");
    return AXIS2_SUCCESS;
}

axis2_conf_ctx_t *AXIS2_CALL
axis2_http_server_get_conf_ctx(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return AXIS2_INTF_TO_IMPL(server)->conf_ctx;
}

axis2_endpoint_ref_t *AXIS2_CALL
axis2_http_server_get_reply_to_epr(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env,
    const axis2_char_t *svc_name)
{
    axis2_endpoint_ref_t *epr = NULL;
    const axis2_char_t *host_address = NULL;
    axis2_char_t *svc_path = NULL;
    axutil_url_t *url = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, svc_name, NULL);

    host_address = "127.0.0.1"; /* TODO : get from axis2.xml */
    svc_path = axutil_stracat(env, "/axis2/services/", svc_name);
    url = axutil_url_create(env, "http", host_address,
            AXIS2_INTF_TO_IMPL(server)->port, svc_path);
    AXIS2_FREE(env->allocator, svc_path);
    if (! url)
    {
        return NULL;
    }
    epr = axis2_endpoint_ref_create(env, axutil_url_to_external_form(url, env));
    axutil_url_free(url, env);
    return epr;
}

axis2_bool_t AXIS2_CALL
axis2_http_server_is_running(
    axis2_transport_receiver_t *server,
    const axutil_env_t *env)
{
    axis2_http_server_impl_t *server_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    server_impl = AXIS2_INTF_TO_IMPL(server);
    if (! server_impl->svr_thread)
    {
        return AXIS2_FALSE;
    }
    else
    {
        return axis2_http_svr_thread_is_running(server_impl->svr_thread, env);
    }
    return AXIS2_FALSE;
}

/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int axis2_get_instance(
    struct axis2_transport_receiver **inst,
    const axutil_env_t *env)
{
    *inst = axis2_http_server_create(env, NULL, -1);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int axis2_remove_instance(
    axis2_transport_receiver_t *inst,
    const axutil_env_t *env)
{
    if (inst)
    {
        axis2_transport_receiver_free(inst, env);
    }
    return AXIS2_SUCCESS;
}
