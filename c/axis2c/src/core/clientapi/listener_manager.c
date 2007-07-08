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

#include <axis2_listener_manager.h>
#include <axis2_const.h>
#include <axutil_hash.h>
#include <axis2_transport_receiver.h>

/**
 * keep information about the listener for a given transport
 */
typedef struct axis2_transport_listener_state
{
    int waiting_calls;

    axis2_transport_receiver_t *listener;

}axis2_transport_listener_state_t;


struct axis2_listener_manager
{
    /** hash map of listeners */
    axis2_transport_listener_state_t *listener_map[AXIS2_TRANSPORT_ENUM_MAX];
    /** configuration context */
    axis2_conf_ctx_t *conf_ctx;
};

typedef struct axis2_listener_manager_worker_func_args
{
    const axutil_env_t *env;
    axis2_listener_manager_t *listner_manager;
    axis2_transport_receiver_t *listener;
}axis2_listener_manager_worker_func_args_t;

void *AXIS2_THREAD_FUNC
axis2_listener_manager_worker_func(axutil_thread_t *thd,
    void *data);

AXIS2_EXTERN axis2_listener_manager_t *AXIS2_CALL
axis2_listener_manager_create(const axutil_env_t *env)
{
    axis2_listener_manager_t *listener_manager = NULL;
    int i = 0;

    AXIS2_ENV_CHECK(env, NULL);

    listener_manager =
        AXIS2_MALLOC(env->allocator, sizeof(axis2_listener_manager_t));

    if (!listener_manager)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    listener_manager->conf_ctx = NULL;
    
    for (i = 0; i < AXIS2_TRANSPORT_ENUM_MAX; i++)
    {
        listener_manager->listener_map[i] = NULL;
    }

    return listener_manager;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_listener_manager_make_sure_started(axis2_listener_manager_t *listener_manager,
    const axutil_env_t *env, 
    const AXIS2_TRANSPORT_ENUMS transport,
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_transport_listener_state_t *tl_state = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);

    if (listener_manager->conf_ctx)
    {
        if (conf_ctx != listener_manager->conf_ctx)
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_CLIENT_SIDE_SUPPORT_ONLY_ONE_CONF_CTX, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    else
    {
        listener_manager->conf_ctx = conf_ctx;
    }


    tl_state = listener_manager->listener_map[transport];

    if (!tl_state)
    {
        /*means this transport not yet started, start the transport*/
        axis2_transport_in_desc_t *transport_in = NULL;
        axis2_conf_t *conf = NULL;
        axis2_transport_receiver_t *listener = NULL;

        conf =  axis2_conf_ctx_get_conf(conf_ctx, env);
        if (conf)
        {
            transport_in =  axis2_conf_get_transport_in(conf, env, transport);
            if (transport_in)
            {
                listener = axis2_transport_in_desc_get_recv(transport_in, env);
                if (listener)
                {
                    axutil_thread_t *worker_thread = NULL;
                    axis2_listener_manager_worker_func_args_t *arg_list = NULL;
                    arg_list = AXIS2_MALLOC(env->allocator,
                            sizeof(axis2_listener_manager_worker_func_args_t));
                    if (! arg_list)
                    {
                        return AXIS2_FAILURE;
                    }
                    arg_list->env = env;
                    arg_list->listner_manager = listener_manager;
                    arg_list->listener = listener;
#ifdef AXIS2_SVR_MULTI_THREADED
                    if (env->thread_pool)
                    {
                        worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
                                axis2_listener_manager_worker_func, (void*)arg_list);
                        if (! worker_thread)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed"
                                    "Invoke non blocking failed");
                        }
                        else
                        {
                            axutil_thread_pool_thread_detach(env->thread_pool, worker_thread);
                        }
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread pool not set in environment."
                                " Cannot invoke call non blocking");
                    }
#else
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Threading not enabled."
                            " Cannot start separate listener");
                    return AXIS2_FAILURE;
#endif

                    tl_state = AXIS2_MALLOC(env->allocator,
                            sizeof(axis2_transport_listener_state_t));

                    if (!tl_state)
                    {
                        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                    }
                    else
                    {
                        tl_state->listener = listener;
                        tl_state->waiting_calls = 0;
                        listener_manager->listener_map[transport] = tl_state;
                    }
                }
            }
        }
    }

    if (tl_state)
    {
        tl_state->waiting_calls++;
        return AXIS2_SUCCESS;
    }
    else
        return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_listener_manager_stop(axis2_listener_manager_t *listener_manager,
    const axutil_env_t *env,
    const AXIS2_TRANSPORT_ENUMS transport)
{
    axis2_transport_listener_state_t *tl_state = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    tl_state = listener_manager->listener_map[transport];

    if (tl_state)
    {
        tl_state->waiting_calls--;
        if (tl_state->waiting_calls == 0)
        {
            status = axis2_transport_receiver_stop(tl_state->listener, env);
            if (status != AXIS2_SUCCESS)
                return status;

            listener_manager->listener_map[transport] = NULL;
        }
    }

    return status;
}

AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
axis2_listener_manager_get_reply_to_epr(const axis2_listener_manager_t *listener_manager,
    const axutil_env_t *env,
    const axis2_char_t *svc_name,
    const AXIS2_TRANSPORT_ENUMS transport)
{
    axis2_transport_listener_state_t *tl_state = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    tl_state = listener_manager->listener_map[transport];
    if (tl_state)
    {
        return axis2_transport_receiver_get_reply_to_epr(tl_state->listener, env, svc_name);
    }
    return NULL;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_listener_manager_free(axis2_listener_manager_t *listener_manager,
    const axutil_env_t *env)
{
    int i = 0;

    AXIS2_ENV_CHECK(env, void);

    for (i = 0; i < AXIS2_TRANSPORT_ENUM_MAX; i++)
    {
        if (listener_manager->listener_map[i])
            AXIS2_FREE(env->allocator, listener_manager->listener_map[i]);
    }

    AXIS2_FREE(env->allocator, listener_manager);

    return;
}

AXIS2_EXTERN axis2_conf_ctx_t *AXIS2_CALL
axis2_listener_manager_get_conf_ctx(const axis2_listener_manager_t *listener_manager,
    const axutil_env_t *env)
{
    return listener_manager->conf_ctx;
}

void *AXIS2_THREAD_FUNC
axis2_listener_manager_worker_func(axutil_thread_t *thd,
    void *data)
{
    axis2_listener_manager_worker_func_args_t *args_list = NULL;
    const axutil_env_t *th_env = NULL;

    args_list = (axis2_listener_manager_worker_func_args_t *) data;
    if (!args_list)
        return NULL;

    AXIS2_ENV_CHECK(args_list->env, AXIS2_FAILURE);
    th_env = axutil_init_thread_env(args_list->env);
    if (args_list->listener)
    {
        axis2_transport_receiver_start(args_list->listener, th_env);
    }
    return NULL;
}


