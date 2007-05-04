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

#include <axutil_thread_pool.h>
#include <axutil_env.h>
#include <axutil_error_default.h>

struct axutil_thread_pool
{
    axutil_allocator_t *allocator;
};

AXIS2_EXTERN axutil_thread_pool_t * AXIS2_CALL
axutil_thread_pool_init(axutil_allocator_t *allocator)
{
    axutil_thread_pool_t *pool = NULL;

    pool = (axutil_thread_pool_t *)AXIS2_MALLOC(allocator,
        sizeof(axutil_thread_pool_t));

    if (!pool)
    {
        return NULL;
    }
    pool->allocator = allocator;

    return pool;
}


AXIS2_EXTERN void AXIS2_CALL
axutil_thread_pool_free(axutil_thread_pool_t *pool)
{
    if (!pool)
    {
        return;
    }
    if (!pool->allocator)
    {
        return;
    }
    AXIS2_FREE(pool->allocator, pool);
    return;
}

AXIS2_EXTERN axutil_thread_t* AXIS2_CALL
axutil_thread_pool_get_thread(axutil_thread_pool_t *pool,
    axutil_thread_start_t func, void *data)
{
    if (!pool)
    {
        return NULL;
    }
    if (!pool->allocator)
    {
        return NULL;
    }
    return axutil_thread_create(pool->allocator, NULL, func, data);
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_pool_join_thread(axutil_thread_pool_t *pool,
    axutil_thread_t *thd)
{
    if (!pool || !thd)
    {
        return AXIS2_FAILURE;
    }
    return axutil_thread_join(thd);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_pool_exit_thread(axutil_thread_pool_t *pool,
    axutil_thread_t *thd)
{
    if (!pool || !thd)
    {
        return AXIS2_FAILURE;
    }
    return axutil_thread_exit(thd, pool->allocator);
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_thread_pool_thread_detach(axutil_thread_pool_t *pool,
    axutil_thread_t *thd)
{
    if (!pool || !thd)
    {
        return AXIS2_FAILURE;
    }
    return axutil_thread_detach(thd);
}

AXIS2_EXTERN axutil_env_t *AXIS2_CALL
axutil_init_thread_env(const axutil_env_t *system_env)
{
    axutil_error_t *error = axutil_error_create(system_env->allocator);
    return axutil_env_create_with_error_log_thread_pool(system_env->allocator, error,
        system_env->log, system_env->thread_pool);
}

AXIS2_EXTERN void AXIS2_CALL
axutil_free_thread_env(struct axutil_env *thread_env)
{
    if (!thread_env)
    {
        return;
    }
    /* log, thread_pool and allocator are shared, so do not free them */
    thread_env->log = NULL;
    thread_env->thread_pool = NULL;
    if (thread_env->error)
    {
        AXIS2_ERROR_FREE(thread_env->error);
    }
    AXIS2_FREE(thread_env->allocator, thread_env);
}

