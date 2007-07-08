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

#include <axutil_property.h>
#include <stdio.h>

struct axutil_property
{
    axis2_scope_t scope;
    AXIS2_FREE_VOID_ARG free_func;
    void *value;
    axis2_bool_t own_value;
};

axutil_property_t *AXIS2_CALL
axutil_property_create(const axutil_env_t *env)
{
    axutil_property_t *property = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    property = (axutil_property_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axutil_property_t));

    if (!property)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    property->value = NULL;
    property->scope = AXIS2_SCOPE_REQUEST;
    property->free_func = 0;
    property->own_value = AXIS2_TRUE;

    return property;
}
/*****************************************************************************/
axutil_property_t *AXIS2_CALL
axutil_property_create_with_args(const axutil_env_t *env,
    axis2_scope_t scope,
    axis2_bool_t own_value,
    AXIS2_FREE_VOID_ARG free_func,
    void *value) 
{
    axutil_property_t *property = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    property = (axutil_property_t *) axutil_property_create(env);

    if (!property)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    property->value = value;
    property->scope = scope;
    property->own_value = own_value;
    property->free_func = free_func;

    return property;
}

void AXIS2_CALL
axutil_property_free(axutil_property_t *property,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (property->value)
    {
        if (property->scope != AXIS2_SCOPE_APPLICATION)
        {
            if (property->free_func && property->own_value)
            {
                property->free_func(property->value, env);
            }
            else if(property->own_value)
            {
                AXIS2_FREE(env->allocator, property->value);
            }
        }
    }

    if (property)
    {
        AXIS2_FREE(env->allocator, property);
    }
    return;
}

axis2_status_t AXIS2_CALL
axutil_property_set_scope(axutil_property_t *property,
    const axutil_env_t *env,
    axis2_scope_t scope)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    property->scope = scope;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axutil_property_set_free_func(axutil_property_t *property,
    const axutil_env_t *env,
    AXIS2_FREE_VOID_ARG free_func)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    property->free_func = free_func;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axutil_property_set_value(axutil_property_t *property,
    const axutil_env_t *env,
    void *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (property->value)
    {
        if (property->scope != AXIS2_SCOPE_APPLICATION)
        {
            if (property->free_func && property->own_value)
            {
                property->free_func(property->value, env);
            }
            else if(property->own_value)
            {
                AXIS2_FREE(env->allocator, property->value);
            }
        }
    }

    property->value = value;
    return AXIS2_SUCCESS;
}

void *AXIS2_CALL
axutil_property_get_value(axutil_property_t *property,
    const axutil_env_t *env)
{
    return property->value;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_property_set_own_value(axutil_property_t *property,
    const axutil_env_t *env,
    axis2_bool_t own_value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    property->own_value = own_value;
    return AXIS2_SUCCESS;
}


axutil_property_t* AXIS2_CALL
axutil_property_clone(axutil_property_t *property,
    const axutil_env_t *env)
{
    axutil_property_t *new_property = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    new_property = axutil_property_create(env);
    axutil_property_set_free_func(new_property, env, property->free_func);
    axutil_property_set_scope(new_property, env, property->scope);
    axutil_property_set_own_value(new_property, env, property->own_value);
    axutil_property_set_value(new_property, env, property->value);
    return new_property; 
}

