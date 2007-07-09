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

#include <platforms/axutil_platform_auto_sense.h>
#include <axis2_http_svr_thread.h>
#include <axis2_http_server.h>
#include <axis2_http_transport.h>
#include <axutil_string.h>
#include <axutil_network_handler.h>
#include <axis2_http_simple_request.h>
#include <axis2_simple_http_svr_conn.h>
#include <axutil_url.h>
#include <axutil_error_default.h>
#include <axiom_xml_reader.h>
#include <signal.h>

AXIS2_EXPORT int axis2_http_socket_read_timeout = AXIS2_HTTP_DEFAULT_SO_TIMEOUT;

struct axis2_http_svr_thread
{
    int listen_socket;
    axis2_bool_t stopped;
    axis2_http_worker_t *worker;
    int port;
};

typedef struct axis2_http_svr_thd_args
{
    axutil_env_t *env;
    axis2_socket_t socket;
    axis2_http_worker_t *worker;
    axutil_thread_t *thread;
}axis2_http_svr_thd_args_t;


AXIS2_EXTERN const axutil_env_t *AXIS2_CALL
init_thread_env(
    const axutil_env_t **system_env);

void *AXIS2_THREAD_FUNC
axis2_svr_thread_worker_func(
    axutil_thread_t *thd,
    void *data);

axis2_http_svr_thread_t *AXIS2_CALL
axis2_http_svr_thread_create(
    const axutil_env_t *env,
    int port)
{
    axis2_http_svr_thread_t *svr_thread = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    svr_thread = (axis2_http_svr_thread_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_http_svr_thread_t));

    if (! svr_thread)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    svr_thread->worker = NULL;
    svr_thread->stopped = AXIS2_FALSE;
    svr_thread->port = port;
    svr_thread->listen_socket = axutil_network_handler_create_server_socket
            (env, svr_thread->port);
    if (-1 == svr_thread->listen_socket)
    {
        axis2_http_svr_thread_free((axis2_http_svr_thread_t *) svr_thread,
                env);
        return NULL;
    }

    return svr_thread;
}


void AXIS2_CALL
axis2_http_svr_thread_free(
    axis2_http_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (svr_thread->worker)
    {
        axis2_http_worker_free(svr_thread->worker, env);
        svr_thread->worker = NULL;
    }
    if (-1 != svr_thread->listen_socket)
    {
        axutil_network_handler_close_socket(env, svr_thread->listen_socket);
        svr_thread->listen_socket = -1;
    }
    svr_thread->stopped = AXIS2_TRUE;
    
    AXIS2_FREE(env->allocator, svr_thread);
    return;
}


axis2_status_t AXIS2_CALL
axis2_http_svr_thread_run(
    axis2_http_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    while (AXIS2_FALSE == svr_thread->stopped)
    {
        int socket = -1;
        axis2_http_svr_thd_args_t *arg_list = NULL;
        axutil_thread_t *worker_thread = NULL;

        socket = axutil_network_handler_svr_socket_accept(env,
                svr_thread->listen_socket);
        if (! svr_thread->worker)
        {
            AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI, "Worker not ready yet."
                    " Cannot serve the request");
            axutil_network_handler_close_socket(env, socket);
            continue;
        }
        arg_list = AXIS2_MALLOC(env->allocator,
                sizeof(axis2_http_svr_thd_args_t));
        if (! arg_list)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                    "Memory allocation error in the svr thread loop");
            continue;
        }
        arg_list->env = (axutil_env_t *)env;
        arg_list->socket = socket;
        arg_list->worker = svr_thread->worker;
#ifdef AXIS2_SVR_MULTI_THREADED
        worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
                axis2_svr_thread_worker_func, (void *)arg_list);
        if (! worker_thread)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed"
                    "server thread loop");
            continue;
        }
        axutil_thread_pool_thread_detach(env->thread_pool, worker_thread);
#else
        axis2_svr_thread_worker_func(NULL, (void *)arg_list);
#endif
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_http_svr_thread_destroy(
    axis2_http_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);

    if (AXIS2_TRUE == svr_thread->stopped)
    {
        return AXIS2_SUCCESS;
    }
    svr_thread->stopped = AXIS2_TRUE;
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Terminating HTTP server "
            "thread.");
    if (svr_thread->listen_socket)
    {
        axutil_network_handler_close_socket(env, svr_thread->listen_socket);
        svr_thread->listen_socket = -1;
    }
    return AXIS2_SUCCESS;
}

int AXIS2_CALL
axis2_http_svr_thread_get_local_port(
    const axis2_http_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    return svr_thread->port;
}

axis2_bool_t AXIS2_CALL
axis2_http_svr_thread_is_running(
    axis2_http_svr_thread_t *svr_thread,
    const axutil_env_t *env)
{
    return svr_thread->port;
}

axis2_status_t AXIS2_CALL
axis2_http_svr_thread_set_worker(
    axis2_http_svr_thread_t *svr_thread,
    const axutil_env_t *env,
    axis2_http_worker_t *worker)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, worker, AXIS2_FAILURE);
    svr_thread->worker = worker;
    return AXIS2_SUCCESS;
}


/**
 * Thread worker function.
 */
void *AXIS2_THREAD_FUNC
axis2_svr_thread_worker_func (
    axutil_thread_t *thd,
    void *data)
{
    struct AXIS2_PLATFORM_TIMEB t1, t2;
    axis2_simple_http_svr_conn_t *svr_conn = NULL;
    axis2_http_simple_request_t *request = NULL;
    int millisecs = 0;
    double secs = 0;
    axis2_http_worker_t *tmp = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axutil_env_t *env = NULL;
    axis2_socket_t socket;
    axutil_env_t *thread_env = NULL;
    axis2_http_svr_thd_args_t *arg_list = NULL;

#ifndef WIN32
#ifdef AXIS2_SVR_MULTI_THREADED
    signal(SIGPIPE, SIG_IGN);
#endif
#endif

    arg_list = (axis2_http_svr_thd_args_t *)data;
    if (! arg_list)
    {
        return NULL;
    }
    AXIS2_PLATFORM_GET_TIME_IN_MILLIS(&t1);
    env = arg_list->env;
    thread_env = axutil_init_thread_env(env);
    socket = arg_list->socket;
    svr_conn = axis2_simple_http_svr_conn_create(thread_env, socket);
    axis2_simple_http_svr_conn_set_rcv_timeout(svr_conn, thread_env,
            axis2_http_socket_read_timeout);
    request = axis2_simple_http_svr_conn_read_request(svr_conn, thread_env);
    tmp = arg_list->worker;
    status = axis2_http_worker_process_request(tmp, thread_env, svr_conn,
            request);
    axis2_simple_http_svr_conn_free(svr_conn, thread_env);
    if (request)
        axis2_http_simple_request_free(request, thread_env);
    AXIS2_PLATFORM_GET_TIME_IN_MILLIS(&t2);
    millisecs = t2.millitm - t1.millitm;
    secs = difftime(t2.time, t1.time);
    if (millisecs < 0)
    {
        millisecs += 1000;
        secs--;
    }
    secs += millisecs / 1000.0;

    if (status == AXIS2_SUCCESS)
    {
#if defined(WIN32)
        AXIS2_LOG_INFO(thread_env->log, "Request served successfully");
#else
        AXIS2_LOG_INFO(thread_env->log, "Request served in %.3f seconds", secs);
#endif
    }
    else
    {
#if defined(WIN32)
        AXIS2_LOG_WARNING(thread_env->log, AXIS2_LOG_SI,
                "Error occured in processing request ");
#else
        AXIS2_LOG_WARNING(thread_env->log, AXIS2_LOG_SI,
                "Error occured in processing request (%.3f seconds)",
                secs);
#endif
    }

    AXIS2_FREE(thread_env->allocator, arg_list);

    if (thread_env)
    {
        /*axutil_free_thread_env(thread_env);*/
        thread_env = NULL;
    }
#ifdef AXIS2_SVR_MULTI_THREADED
    /*axutil_thread_pool_exit_thread(env->thread_pool, thd);*/
#endif

    return NULL;
}

