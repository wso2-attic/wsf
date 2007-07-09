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

#include <axis2_handler_desc.h>
#include <axutil_param_container.h>
#include <axutil_string.h>
#include <axis2_handler.h>

struct axis2_handler_desc
{
    /** name */
    axutil_string_t *name;
    /** phase rules */
    axis2_phase_rule_t *rules;
    /** handler represented by meta information*/
    axis2_handler_t *handler;
    /** class name */
    axis2_char_t *class_name;
    /** parent param container */
    axutil_param_container_t *parent;
    /** parameter container */
    axutil_param_container_t *param_container;
};

AXIS2_EXTERN axis2_handler_desc_t *AXIS2_CALL
axis2_handler_desc_create(const axutil_env_t *env,
    axutil_string_t *name)
{
    axis2_handler_desc_t *handler_desc = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    handler_desc = AXIS2_MALLOC(env->allocator,
            sizeof(axis2_handler_desc_t));
    if (!handler_desc)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    handler_desc->param_container = NULL;
    handler_desc->name = NULL;
    handler_desc->rules = NULL;
    handler_desc->handler = NULL;
    handler_desc->class_name = NULL;
    handler_desc->parent = NULL;

    handler_desc->param_container  =
        axutil_param_container_create(env);
    if (!handler_desc->param_container)
    {
        /** error code is already set by last param container create */
        axis2_handler_desc_free(handler_desc, env);
        return NULL;
    }

    handler_desc->rules = axis2_phase_rule_create(env, NULL);
    if (!handler_desc->rules)
    {
        /** error code is already set by last param container create */
        axis2_handler_desc_free(handler_desc, env);
        return NULL;
    }

    if (name)
    {
        handler_desc->name = axutil_string_clone(name, env);
    }

    return handler_desc;
}

AXIS2_EXTERN const axutil_string_t *AXIS2_CALL
axis2_handler_desc_get_name(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env)
{
    return handler_desc->name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_desc_set_name(axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env,
    axutil_string_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (handler_desc->name)
    {
        axutil_string_free(handler_desc->name, env);
        handler_desc->name = NULL;
    }

    if (name)
    {
        handler_desc->name = axutil_string_clone(name, env);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_phase_rule_t *AXIS2_CALL
axis2_handler_desc_get_rules(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env)
{
    return handler_desc->rules;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_desc_set_rules(axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env,
    axis2_phase_rule_t *phase_rule)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (handler_desc->rules)
    {
        axis2_phase_rule_free(handler_desc->rules, env);
    }

    if (phase_rule)
    {
        handler_desc->rules = axis2_phase_rule_clone(phase_rule, env);
        if (!(handler_desc->rules))
        {
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_param_t *AXIS2_CALL
axis2_handler_desc_get_param(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env,
    const axis2_char_t *name)
{
    return axutil_param_container_get_param(handler_desc->param_container, env, name);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_desc_add_param(axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env,
    axutil_param_t *param)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (axutil_param_container_is_param_locked(handler_desc->parent, env,
        axutil_param_get_name(param, env)))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_PARAMETER_LOCKED_CANNOT_OVERRIDE,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    return axutil_param_container_add_param(handler_desc->param_container, 
        env, param);
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_handler_desc_get_all_params(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env)
{
    return axutil_param_container_get_params(handler_desc->param_container, 
        env);
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_handler_desc_is_param_locked(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /* see if it is locked in parent */
    if (axutil_param_container_is_param_locked(handler_desc->parent, env,
        param_name))
    {
        return AXIS2_TRUE;
    }

    return axutil_param_container_is_param_locked(handler_desc->param_container,
        env, param_name);
}

AXIS2_EXTERN axis2_handler_t *AXIS2_CALL
axis2_handler_desc_get_handler(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env)
{
    return handler_desc->handler;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_desc_set_handler(axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env,
    axis2_handler_t *handler)
{
    /* handler description is the place where the handler really lives.
       Hence this is a deep copy and should be freed by the free method. */
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (handler_desc->handler && (handler_desc->handler != handler))
    {
        axis2_handler_free(handler_desc->handler, env);
    }

    if (handler)
        handler_desc->handler = handler; /* Shallow copy, but free method
            should free this */

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_handler_desc_get_class_name(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env)
{
    return handler_desc->class_name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_desc_set_class_name(axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env,
    const axis2_char_t *class_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (handler_desc->class_name)
    {
        AXIS2_FREE(env->allocator, handler_desc->class_name);
    }

    if (class_name)
    {
        handler_desc->class_name = axutil_strdup(env, class_name);
        if (!handler_desc->class_name)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
axis2_handler_desc_get_parent(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env)
{
    return handler_desc->parent;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_handler_desc_set_parent(axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env,
    axutil_param_container_t *parent)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    handler_desc->parent = parent; /* shallow copy, because
        the parent lives somewhere else*/
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_handler_desc_free(axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (handler_desc->param_container)
    {
        axutil_param_container_free(handler_desc-> param_container, env);
    }

    if (handler_desc->name)
    {
        axutil_string_free(handler_desc->name, env);
    }

    if (handler_desc->rules)
    {
        axis2_phase_rule_free(handler_desc->rules, env);
    }

    if (handler_desc->handler)
    {
        axis2_handler_free(handler_desc->handler, env);
    }

    if (handler_desc->class_name)
    {
        AXIS2_FREE(env->allocator, handler_desc->class_name);
    }
    if (handler_desc)
    {
        AXIS2_FREE(env->allocator, handler_desc);
    }

    return;
}

AXIS2_EXTERN axutil_param_container_t *AXIS2_CALL
axis2_handler_desc_get_param_container(const axis2_handler_desc_t *handler_desc,
    const axutil_env_t *env)
{
    return handler_desc->param_container;
}


