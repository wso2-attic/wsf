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

#include "axis2_callback_recv.h"
#include <axis2_const.h>
#include <axutil_hash.h>

struct axis2_callback_recv
{
    /** base context struct */
    axis2_msg_recv_t *base;
    axis2_bool_t base_deep_copy;
    /** callback map */
    axutil_hash_t *callback_map;
    axutil_thread_mutex_t *mutex;
};

static axis2_status_t AXIS2_CALL
axis2_callback_recv_receive(
    axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    void *callback_recv_param);
    
AXIS2_EXTERN axis2_callback_recv_t *AXIS2_CALL
axis2_callback_recv_create(
    const axutil_env_t *env)
{
    axis2_callback_recv_t *callback_recv = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    callback_recv =
        AXIS2_MALLOC(env->allocator, sizeof(axis2_callback_recv_t));

    if (!callback_recv)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    callback_recv->base = NULL;
    callback_recv->base_deep_copy = AXIS2_TRUE;
    callback_recv->callback_map = NULL;
    callback_recv->mutex = NULL;

    callback_recv->base = axis2_msg_recv_create(env);
    if (!(callback_recv->base))
    {
        axis2_callback_recv_free(callback_recv, env);
        return NULL;
    }
    axis2_msg_recv_set_derived(callback_recv->base, env, callback_recv);
    axis2_msg_recv_set_receive(callback_recv->base, env, axis2_callback_recv_receive);

    callback_recv->callback_map = axutil_hash_make(env);
    if (!(callback_recv->callback_map))
    {
        axis2_callback_recv_free(callback_recv, env);
        return NULL;
    }

    callback_recv->mutex = axutil_thread_mutex_create(env->allocator,
                                 AXIS2_THREAD_MUTEX_DEFAULT);
    return callback_recv;
}

AXIS2_EXTERN axis2_msg_recv_t *AXIS2_CALL
axis2_callback_recv_get_base(
    axis2_callback_recv_t *callback_recv,
    const axutil_env_t *env)
{
    callback_recv->base_deep_copy = AXIS2_FALSE;
    return callback_recv->base;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_callback_recv_free(
    axis2_callback_recv_t *callback_recv,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if(callback_recv->mutex)
    {
        axutil_thread_mutex_destroy(callback_recv->mutex);
    }

    if (callback_recv->callback_map)
    {
        axutil_hash_index_t *hi = NULL;
        const void *key = NULL;
        void *val = NULL;
        for (hi = axutil_hash_first(callback_recv->callback_map, env); hi;
                hi = axutil_hash_next(env, hi))
        {
            axutil_hash_this(hi, &key, NULL, &val);
            if (key)
                AXIS2_FREE(env->allocator, (char*)key);

        }

        axutil_hash_free(callback_recv->callback_map, env);
    }

    if (callback_recv->base && callback_recv->base_deep_copy)
    {
        axis2_msg_recv_free(callback_recv->base, env);
    }

    if (callback_recv)
    {
        AXIS2_FREE(env->allocator, callback_recv);
    }

    return;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_callback_recv_add_callback(
    axis2_callback_recv_t *callback_recv,
    const axutil_env_t *env,
    const axis2_char_t *msg_id,
    axis2_callback_t *callback)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (msg_id)
    {
        axis2_char_t *mid = axutil_strdup(env, msg_id);
        axutil_hash_set(callback_recv->callback_map,
                mid, AXIS2_HASH_KEY_STRING, callback);
    }
    return AXIS2_SUCCESS;
}

static axis2_status_t AXIS2_CALL
axis2_callback_recv_receive(
    axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    void *callback_recv_param)
{
    axis2_callback_recv_t *callback_recv = NULL;
    axis2_relates_to_t *relates_to = NULL;
    axis2_msg_info_headers_t *msg_info_headers = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    callback_recv = axis2_msg_recv_get_derived(msg_recv, env);
    
    msg_info_headers =  axis2_msg_ctx_get_msg_info_headers(msg_ctx, env);
    if (msg_info_headers)
    {
        relates_to = axis2_msg_info_headers_get_relates_to(msg_info_headers, env);
        if (relates_to)
        {
            const axis2_char_t *msg_id = axis2_relates_to_get_value(relates_to, env);
            if (msg_id)
            {
                axis2_async_result_t *result = NULL;
                axis2_callback_t *callback = (axis2_callback_t*)
                        axutil_hash_get(callback_recv->callback_map, msg_id, AXIS2_HASH_KEY_STRING);

                result = axis2_async_result_create(env, msg_ctx);
                if (callback && result)
                {
                    axis2_callback_invoke_on_complete(callback, env, result);
                    axis2_callback_set_complete(callback, env, AXIS2_TRUE);
                     axis2_msg_ctx_set_soap_envelope(msg_ctx, env, NULL);
                }

                axis2_async_result_free(result, env);
                if (callback && result)
                    return AXIS2_SUCCESS;
            }
        }
    }

    return AXIS2_FAILURE;
}


