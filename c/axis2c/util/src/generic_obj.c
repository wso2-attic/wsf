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

#include <axutil_generic_obj.h>

struct axutil_generic_obj
{
    AXIS2_FREE_VOID_ARG free_func;
    int type;
    void *value;
};

AXIS2_EXTERN axutil_generic_obj_t *AXIS2_CALL
axutil_generic_obj_create(const axutil_env_t *env)
{
    axutil_generic_obj_t *generic_obj = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    generic_obj = (axutil_generic_obj_t *) AXIS2_MALLOC(env->allocator,
            sizeof(axutil_generic_obj_t));

    if (! generic_obj)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    generic_obj->value = NULL;
    generic_obj->free_func = 0;

    return generic_obj;
}

AXIS2_EXTERN void AXIS2_CALL
axutil_generic_obj_free(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (generic_obj->value)
    {
        if (generic_obj->free_func)
        {
            generic_obj->free_func(generic_obj->value, env);
        }
        else
        {
            AXIS2_FREE(env->allocator, generic_obj->value);
        }

    }

    if (generic_obj)
    {
        AXIS2_FREE(env->allocator, generic_obj);
    }
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_generic_obj_set_free_func(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env,
        AXIS2_FREE_VOID_ARG free_func)
{
    generic_obj->free_func = free_func;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_generic_obj_set_value(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env,
        void *value)
{
    generic_obj->value = value;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN void *AXIS2_CALL
axutil_generic_obj_get_value(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env)
{
    return generic_obj->value;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_generic_obj_set_type(
    axutil_generic_obj_t *generic_obj,
    const axutil_env_t *env,
    int type)
{
    generic_obj->type = type;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axutil_generic_obj_get_type(
    axutil_generic_obj_t *generic_obj,
    const axutil_env_t *env)
{
    return generic_obj->type;
}

