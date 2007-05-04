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


#include <axis2_const.h>
#include <axis2_phase_rule.h>
#include <axutil_string.h>

struct axis2_phase_rule
{
    /** name of phase or handler before */
    axis2_char_t *before;
    /** name of phase or handler after */
    axis2_char_t *after;
    /** phase name */
    axis2_char_t *name;
    /** Is this first in phase? */
    axis2_bool_t first;
    /** Is this last in phase? */
    axis2_bool_t last;

};

AXIS2_EXTERN axis2_phase_rule_t *AXIS2_CALL
axis2_phase_rule_create(const axutil_env_t *env,
    const axis2_char_t *name)
{
    axis2_phase_rule_t *phase_rule = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    phase_rule = AXIS2_MALLOC(env->allocator, sizeof(axis2_phase_rule_t));
    if (!phase_rule)
    {
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
        return NULL;
    }

    phase_rule->before = NULL;
    phase_rule->after = NULL;
    phase_rule->name = NULL;
    phase_rule->first = AXIS2_FALSE;
    phase_rule->last = AXIS2_FALSE;

    if (name)
    {
        phase_rule->name = axutil_strdup(env, name);
    }

    return phase_rule;
}

const axis2_char_t *AXIS2_CALL
axis2_phase_rule_get_before(const axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env)
{
    return phase_rule->before;
}

axis2_status_t AXIS2_CALL
axis2_phase_rule_set_before(axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env,
    const axis2_char_t *before)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (phase_rule->before)
    {
        AXIS2_FREE(env->allocator, phase_rule->before);
    }

    if (before)
    {
        phase_rule->before = axutil_strdup(env, before);
        if (!phase_rule->before)
        {
            AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
            AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

const axis2_char_t *AXIS2_CALL
axis2_phase_rule_get_after(const axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env)
{
    return phase_rule->after;
}

axis2_status_t AXIS2_CALL
axis2_phase_rule_set_after(axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env,
    const axis2_char_t *after)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (phase_rule->after)
    {
        AXIS2_FREE(env->allocator, phase_rule->after);
    }

    if (after)
    {
        phase_rule->after = axutil_strdup(env, after);
        if (!phase_rule->after)
        {
            AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
            AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

const axis2_char_t *AXIS2_CALL
axis2_phase_rule_get_name(const axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env)
{
    return phase_rule->name;
}

axis2_status_t AXIS2_CALL
axis2_phase_rule_set_name(axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env,
    const axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (phase_rule->name)
    {
        AXIS2_FREE(env->allocator, phase_rule->name);
    }

    if (name)
    {
        phase_rule->name = axutil_strdup(env, name);
        if (!phase_rule->name)
        {
            AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_NO_MEMORY);
            AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_phase_rule_is_first(const axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return phase_rule->first;
}

axis2_status_t AXIS2_CALL
axis2_phase_rule_set_first(axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env,
    axis2_bool_t first)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    phase_rule->first = first;
    return AXIS2_SUCCESS;
}

axis2_bool_t AXIS2_CALL
axis2_phase_rule_is_last(const axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return phase_rule->last;
}

axis2_status_t AXIS2_CALL
axis2_phase_rule_set_last(axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env,
    axis2_bool_t last)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    phase_rule->last = last;
    return AXIS2_SUCCESS;
}

void AXIS2_CALL
axis2_phase_rule_free(axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (phase_rule->before)
    {
        AXIS2_FREE(env->allocator, phase_rule->before);
    }

    if (phase_rule->after)
    {
        AXIS2_FREE(env->allocator, phase_rule->after);
    }

    if (phase_rule->name)
    {
        AXIS2_FREE(env->allocator, phase_rule->name);
    }

    AXIS2_FREE(env->allocator, phase_rule);

    return;
}

axis2_phase_rule_t *AXIS2_CALL
axis2_phase_rule_clone(axis2_phase_rule_t *phase_rule,
    const axutil_env_t *env)
{
    axis2_phase_rule_t *phase_rule_new = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    phase_rule_new = axis2_phase_rule_create(env, NULL);
    if (!phase_rule_new)
        return NULL;

    axis2_phase_rule_set_before(phase_rule_new, env,
        axis2_phase_rule_get_before(phase_rule, env));

    axis2_phase_rule_set_after(phase_rule_new, env,
        axis2_phase_rule_get_after(phase_rule, env));

    axis2_phase_rule_set_name(phase_rule_new, env,
        axis2_phase_rule_get_name(phase_rule, env));

    axis2_phase_rule_set_first(phase_rule_new, env,
        axis2_phase_rule_is_first(phase_rule, env));

    axis2_phase_rule_set_last(phase_rule_new, env,
        axis2_phase_rule_is_last(phase_rule, env));

    return phase_rule_new;
}


