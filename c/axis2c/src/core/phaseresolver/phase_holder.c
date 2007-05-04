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

#include <axis2_phase_holder.h>

struct axis2_phase_holder
{
    axutil_array_list_t *phase_list;
};

AXIS2_EXTERN axis2_phase_holder_t *AXIS2_CALL
axis2_phase_holder_create(const axutil_env_t *env)
{
    axis2_phase_holder_t *phase_holder = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    phase_holder = (axis2_phase_holder_t *) AXIS2_MALLOC(env->
        allocator, sizeof(axis2_phase_holder_t));

    if (! phase_holder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    phase_holder->phase_list = NULL;

    return phase_holder;
}

AXIS2_EXTERN axis2_phase_holder_t *AXIS2_CALL
axis2_phase_holder_create_with_phases(const axutil_env_t *env,
    axutil_array_list_t *phases)
{
    axis2_phase_holder_t *phase_holder = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (!phases)
    {
        return NULL;
    }

    phase_holder = (axis2_phase_holder_t *)axis2_phase_holder_create(env);
    phase_holder->phase_list = phases;

    return phase_holder;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_phase_holder_free(axis2_phase_holder_t *phase_holder,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (phase_holder)
    {
        AXIS2_FREE(env->allocator, phase_holder);
    }

    return;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_phase_holder_is_phase_exist(axis2_phase_holder_t *phase_holder,
    const axutil_env_t *env,
    const axis2_char_t *phase_name)
{
    int size = 0;
    int i = 0;
    axis2_phase_t *phase = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, phase_name, AXIS2_FALSE);

    size = axutil_array_list_size(phase_holder->phase_list, env);

    for (i = 0; i < size; i++)
    {
        const axis2_char_t *phase_name_l = NULL;

        phase = (axis2_phase_t *) axutil_array_list_get(phase_holder->
            phase_list, env, i);
        phase_name_l =  axis2_phase_get_name(phase, env);
        if (0 == axutil_strcmp(phase_name_l, phase_name))
        {
            return AXIS2_TRUE;
        }
    }
    return AXIS2_FALSE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_holder_add_handler(axis2_phase_holder_t *phase_holder,
    const axutil_env_t *env,
    axis2_handler_desc_t *handler)
{
    const axis2_char_t *phase_name = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "axis2_phase_holder_add_handler start");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, handler, AXIS2_FAILURE);

    phase_name = axis2_phase_rule_get_name(
        axis2_handler_desc_get_rules(handler, env), env);
    if (AXIS2_TRUE == axis2_phase_holder_is_phase_exist(phase_holder, env,
        phase_name))
    {
        axis2_phase_t *phase = NULL;

        phase = axis2_phase_holder_get_phase(phase_holder, env, phase_name);
        status = axis2_phase_add_handler_desc(phase, env, handler);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Add handler %s to phase %s",
            axutil_string_get_buffer(axis2_handler_desc_get_name(handler, env), env), 
            phase_name);
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_PHASE, AXIS2_FAILURE);
        status = AXIS2_FAILURE;
    }
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "axis2_phase_holder_add_handler end status = %s",
        status ? "SUCCESS" : "FAILURE");
    return status;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_holder_remove_handler(axis2_phase_holder_t *phase_holder,
    const axutil_env_t *env,
    axis2_handler_desc_t *handler)
{
    const axis2_char_t *phase_name = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "axis2_phase_holder_remove_handler start");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, handler, AXIS2_FAILURE);

    phase_name = axis2_phase_rule_get_name(
        axis2_handler_desc_get_rules(handler, env), env);
    if (AXIS2_TRUE == axis2_phase_holder_is_phase_exist(phase_holder, env,
        phase_name))
    {
        axis2_phase_t *phase = NULL;

        phase = axis2_phase_holder_get_phase(phase_holder, env, phase_name);
        status = axis2_phase_remove_handler_desc(phase, env, handler);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Remove handler %s from phase %s",
            axutil_string_get_buffer(axis2_handler_desc_get_name(handler, env), env), 
            phase_name);
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_PHASE, AXIS2_FAILURE);
        status = AXIS2_FAILURE;
    }
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "axis2_phase_holder_remove_handler end status = %s",
        status ? "SUCCESS" : "FAILURE");
    return status;
}

AXIS2_EXTERN axis2_phase_t *AXIS2_CALL
axis2_phase_holder_get_phase(const axis2_phase_holder_t *phase_holder,
    const axutil_env_t *env,
    const axis2_char_t *phase_name)
{
    int size = 0;
    int i = 0;
    axis2_phase_t *phase = NULL;

    AXIS2_PARAM_CHECK(env->error, phase_name, NULL);

    size = axutil_array_list_size(phase_holder->phase_list, env);

    for (i = 0; i < size; i++)
    {
        const axis2_char_t *phase_name_l = NULL;
        phase = (axis2_phase_t *) axutil_array_list_get(phase_holder->
            phase_list, env, i);
        phase_name_l =  axis2_phase_get_name(phase, env);
        if (0 == axutil_strcmp(phase_name_l, phase_name))
        {
            return phase;
        }
    }

    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_phase_holder_build_transport_handler_chain(axis2_phase_holder_t *phase_holder,
    const axutil_env_t *env,
    axis2_phase_t *phase,
    axutil_array_list_t *handlers)
{
    axis2_handler_t *handler = NULL;
    int size = 0;
    int status = AXIS2_FAILURE;
    int i = 0;
    axis2_handler_desc_t *handler_desc = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, phase, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, handlers, AXIS2_FAILURE);

    size = axutil_array_list_size(handlers, env);

    for (i = 0; i < size; i++)
    {
        handler_desc = (axis2_handler_desc_t *) axutil_array_list_get(
            handlers, env, i);
        status = axis2_handler_init(handler, env, handler_desc);
        if (AXIS2_FAILURE == status)
	{
            return status;
	}

        status = axis2_handler_desc_set_handler(handler_desc, env, handler);
        if (AXIS2_FAILURE == status)
	{
            return status;
	}

        status = axis2_phase_add_handler(phase, env, handler);
    }
    return status;
}
