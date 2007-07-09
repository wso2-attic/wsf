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

#include <axutil_param.h>
#include <axutil_utils.h>
#include <axutil_string.h>
#include <axutil_generic_obj.h>

struct axutil_param
{
    /** Parameter name */
    axis2_char_t *name;
    /** Parameter value */
    void* value;
    /** Parameter locked? */
    axis2_bool_t locked;
    /** Parameter type */
    int type; /*default is AXIS2_TEXT_PARAM */
    axutil_hash_t *attrs;
    axutil_array_list_t *value_list;
    axis2_status_t (AXIS2_CALL *
    value_free) (void *param_value,
        const axutil_env_t *env);
};

AXIS2_EXTERN axutil_param_t* AXIS2_CALL
axutil_param_create(const axutil_env_t *env,
    axis2_char_t *name, 
    void *value)
{
    axutil_param_t *param = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    param = AXIS2_MALLOC(env->allocator, sizeof(axutil_param_t));
    if (!param)
    {
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
        return NULL;
    }

    param->name = axutil_strdup(env, name);
    param->value = value; /* shallow copy.*/
    param->locked = AXIS2_FALSE;
    param->type = AXIS2_TEXT_PARAM;
    param->attrs = NULL;
    param->value_list = NULL;
    param->value_free = NULL;

    return param;
}

axis2_char_t* AXIS2_CALL
axutil_param_get_name(axutil_param_t *param,
    const axutil_env_t *env)
{
    return param->name;
}

void* AXIS2_CALL
axutil_param_get_value(axutil_param_t *param,
    const axutil_env_t *env)
{
    return param->value;
}

axis2_status_t AXIS2_CALL
axutil_param_set_name(axutil_param_t *param,
    const axutil_env_t *env,
    const axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    param->name = axutil_strdup(env, name);
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axutil_param_set_value(axutil_param_t *param,
    const axutil_env_t *env,
    const void *value)
{
    void *param_value = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    param_value = axutil_param_get_value(param, env);
    if (param_value)
    {
        if (param && param->value_free)
        {
            param->value_free(param_value, env);
        }
        else /* we assume that param value is axis2_char_t* */
        {
            AXIS2_FREE(env->allocator, param_value);
        }
    }
    param->value = (void *)value;
    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axutil_param_is_locked(axutil_param_t *param,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return param->locked;
}

axis2_status_t AXIS2_CALL
axutil_param_set_locked(axutil_param_t *param,
    const axutil_env_t *env,
    axis2_bool_t value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    param->locked = value;
    return AXIS2_SUCCESS;
}

int AXIS2_CALL
axutil_param_get_param_type(axutil_param_t *param,
    const axutil_env_t *env)
{
    return param->type;
}

axis2_status_t AXIS2_CALL
axutil_param_set_param_type(axutil_param_t *param,
    const axutil_env_t *env,
    int type)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    param->type = type;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axutil_param_set_attributes(axutil_param_t *param,
    const axutil_env_t *env,
    axutil_hash_t *attrs)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, attrs, AXIS2_FAILURE);

    if (param->attrs)
    {
        axutil_hash_index_t *i = NULL;
        void *v = NULL;

        for (i = axutil_hash_first(param->attrs, env); i;
            i = axutil_hash_next(env, i))
        {
            axutil_hash_this(i, NULL, NULL, &v);
            axutil_generic_obj_free(v, env);
        }
        axutil_hash_free(param->attrs, env);
    }

    param->attrs = attrs;
    return AXIS2_SUCCESS;
}

axutil_hash_t* AXIS2_CALL
axutil_param_get_attributes(axutil_param_t *param,
    const axutil_env_t *env)
{
    return param->attrs;
}

axis2_status_t AXIS2_CALL
axutil_param_set_value_list(axutil_param_t *param,
    const axutil_env_t *env,
    axutil_array_list_t *value_list)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, value_list, AXIS2_FAILURE);

    if (param->value_list)
    {
        int i = 0, size = 0;

        size = axutil_array_list_size(param->value_list, env);
        for (i = 0; i < size; i++)
        {
            axutil_param_t *param = NULL;

            param = (axutil_param_t *) axutil_array_list_get(
                param->value_list, env, i);
            axutil_param_free(param, env);
        }
        axutil_array_list_free(param->value_list, env);
    }
    param->value_list = value_list;

    return AXIS2_SUCCESS;
}

axutil_array_list_t* AXIS2_CALL
axutil_param_get_value_list(axutil_param_t *param,
    const axutil_env_t *env)
{
    return param->value_list;
}

void AXIS2_CALL
axutil_param_free(axutil_param_t *param,
    const axutil_env_t *env)
{
    void *param_value = NULL;
    axis2_char_t *param_name = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    param_value = axutil_param_get_value(param, env);
    if (param_value)
    {
        if (param && param->value_free)
        {
            param->value_free(param_value, env);
        }
        else /* we assume that param value is axis2_char_t* */
        {
            AXIS2_FREE(env->allocator, param_value);
        }
    }

    if (param->attrs)
    {
        axutil_hash_index_t *i = NULL;
        void *v = NULL;

        for (i = axutil_hash_first(param->attrs, env); i;
            i = axutil_hash_next(env, i))
        {
            axutil_hash_this(i, NULL, NULL, &v);
            axutil_generic_obj_free(v, env);
        }
        axutil_hash_free(param->attrs, env);
    }

    if (param->value_list)
    {
        int i = 0, size = 0;

        size = axutil_array_list_size(param->value_list, env);
        for (i = 0; i < size; i++)
        {
            axutil_param_t *param_l = NULL;

            param_l = (axutil_param_t *) axutil_array_list_get(
                param->value_list, env, i);
            if (param_l)
            {
                axutil_param_free(param_l, env);
            }
        }
        axutil_array_list_free(param->value_list, env);
    }
    param_name = axutil_param_get_name(param, env);
    AXIS2_FREE(env->allocator, param_name);
    AXIS2_FREE(env->allocator, param);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_param_set_value_free(axutil_param_t *param,
    const axutil_env_t *env,
    void *free_fn)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    param->value_free = free_fn;

    return AXIS2_SUCCESS;
}

