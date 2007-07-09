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

#include <axis2_relates_to.h>
#include <axutil_string.h>

struct axis2_relates_to
{
    /** value string  */
    axis2_char_t *value;
    /** relationship type string */
    axis2_char_t *relationship_type;
};

axis2_relates_to_t *AXIS2_CALL
axis2_relates_to_create(const axutil_env_t *env,
    const axis2_char_t *value,
    const axis2_char_t *relationship_type)
{
    axis2_relates_to_t *relates_to = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    relates_to = AXIS2_MALLOC(env->allocator, sizeof(axis2_relates_to_t));
    if (!relates_to)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    relates_to->value = NULL;
    relates_to->relationship_type = NULL;

    if (value)
    {
        relates_to->value = axutil_strdup(env, value);
        if (!(relates_to->value))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            axis2_relates_to_free(relates_to, env);
            return NULL;
        }
    }

    if (relationship_type)
    {
        relates_to->relationship_type = axutil_strdup(env, relationship_type);
        if (!(relates_to->relationship_type))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            axis2_relates_to_free(relates_to, env);
            return NULL;
        }
    }

    return relates_to;
}

const axis2_char_t *AXIS2_CALL
axis2_relates_to_get_value(const axis2_relates_to_t *relates_to,
    const axutil_env_t *env)
{
    return relates_to->value;
}

axis2_status_t AXIS2_CALL
axis2_relates_to_set_value(struct axis2_relates_to *relates_to,
    const axutil_env_t *env,
    const axis2_char_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (relates_to->value)
    {
        AXIS2_FREE(env->allocator, relates_to->value);
    }

    if (value)
    {
        relates_to->value = (axis2_char_t *)axutil_strdup(env, value);
        if (!(relates_to->value))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

const axis2_char_t *AXIS2_CALL
axis2_relates_to_get_relationship_type(const axis2_relates_to_t *relates_to,
    const axutil_env_t *env)
{
    return relates_to->relationship_type;
}

axis2_status_t AXIS2_CALL
axis2_relates_to_set_relationship_type(struct axis2_relates_to *relates_to,
    const axutil_env_t *env,
    const axis2_char_t *relationship_type)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (relates_to->relationship_type)
    {
        AXIS2_FREE(env->allocator, relates_to->relationship_type);
    }

    if (relationship_type)
    {
        relates_to->relationship_type =
            (axis2_char_t *)axutil_strdup(env, relationship_type);
        if (!(relates_to->relationship_type))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

void AXIS2_CALL
axis2_relates_to_free(struct axis2_relates_to *relates_to,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (relates_to->value)
    {
        AXIS2_FREE(env->allocator, relates_to->value);
    }

    if (relates_to->relationship_type)
    {
        AXIS2_FREE(env->allocator, relates_to->relationship_type);
    }

    AXIS2_FREE(env->allocator, relates_to);

    return;
}
