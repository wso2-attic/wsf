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

#include <axutil_param_container.h>

struct axutil_param_container
{
    axutil_hash_t *params;
    axutil_array_list_t *params_list;
};

AXIS2_EXTERN axutil_param_container_t * AXIS2_CALL
axutil_param_container_create(const axutil_env_t *env)
{
    axutil_param_container_t *param_container = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    param_container = (axutil_param_container_t *) AXIS2_MALLOC(env->
        allocator, sizeof(axutil_param_container_t));

    if (!param_container)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    param_container->params = NULL;
    param_container->params_list = NULL;
    param_container->params_list = axutil_array_list_create(env, 0);

    param_container->params = axutil_hash_make(env);
    if (!param_container->params)
    {
        axutil_param_container_free(param_container, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return param_container;
}

AXIS2_EXTERN void AXIS2_CALL
axutil_param_container_free(axutil_param_container_t *param_container,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (param_container->params)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        for (hi = axutil_hash_first(param_container->params, env); hi;
            hi = axutil_hash_next(env, hi))
        {
            axutil_param_t *param = NULL;
            axutil_hash_this(hi, NULL, NULL, &val);
            param = (axutil_param_t *) val;
            if (param)
            {
                axutil_param_free(param, env);
                param = NULL;
            }
            val = NULL;
        }
        axutil_hash_free(param_container->params, env);
    }
    if (param_container->params_list)
    {
        /* This is the array list which is returned when all params are
         * requested from param_container. Params referenced here are
         * actually contained in params hash table
         */
        axutil_array_list_free(param_container->params_list, env);
        param_container->params_list = NULL;
    }

    AXIS2_FREE(env->allocator, param_container);
    return;
}

AXIS2_EXTERN void AXIS2_CALL
axutil_param_container_free_void_arg(void *param_container,
    const axutil_env_t *env)
{
    axutil_param_container_t *param_container_l = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    param_container_l = (axutil_param_container_t *) param_container;
    axutil_param_container_free(param_container_l, env);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_param_container_add_param(axutil_param_container_t *param_container,
    const axutil_env_t *env,
    axutil_param_t *param)
{
    axis2_char_t *param_name = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, param, AXIS2_FAILURE);

    if (!(param_container->params))
    {
        param_container->params = axutil_hash_make(env);
        if (!param_container->params)
        {
            return AXIS2_FAILURE;
        }
    }
    param_name = axutil_param_get_name(param, env);
    if (!param_name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_PARAM,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    axutil_hash_set(param_container->params, param_name, 
        AXIS2_HASH_KEY_STRING, param);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_param_t * AXIS2_CALL
axutil_param_container_get_param(axutil_param_container_t *param_container,
    const axutil_env_t *env,
    const axis2_char_t *name)
{
    return (axutil_param_t *)(axutil_hash_get(param_container->params, 
        name, AXIS2_HASH_KEY_STRING));
}

AXIS2_EXTERN axutil_array_list_t * AXIS2_CALL
axutil_param_container_get_params(axutil_param_container_t *param_container,
    const axutil_env_t *env)
{
    axutil_hash_index_t *index_i = 0;
    axis2_status_t status = AXIS2_FAILURE;
    void *value = NULL;

    if (!param_container->params_list)
    {
        param_container->params_list = axutil_array_list_create(env, 0);
        if (!param_container->params_list)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY,
                AXIS2_FAILURE);
            return NULL;
        }
    }

    for (index_i = axutil_hash_first(param_container->params, env);
        index_i; index_i = axutil_hash_next(env, index_i))
    {
        axutil_hash_this(index_i, NULL, NULL, &value);
        status = axutil_array_list_add(param_container->params_list, env,
            value);
        if (AXIS2_SUCCESS != status)
        {
            axutil_array_list_free(param_container->params_list , env);
            return NULL;
        }
    }

    return param_container->params_list;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axutil_param_container_is_param_locked(axutil_param_container_t *param_container,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    axutil_param_t *param = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    param = (axutil_param_t *)(axutil_hash_get(param_container->params, 
        param_name, AXIS2_HASH_KEY_STRING));
    if (!param)
    {
        /* In this case we consider param is not locked */
        return AXIS2_FALSE;
    }
    return axutil_param_is_locked(param, env);
}

