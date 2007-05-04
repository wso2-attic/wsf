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

#include <axis2_desc.h>
#include <axutil_property.h>
#include <axis2_msg.h>

struct axis2_desc
{
    /** parameter container */
    axutil_param_container_t *param_container;

    /** children of this description */
    axutil_hash_t *children;
};

AXIS2_EXTERN axis2_desc_t *AXIS2_CALL
axis2_desc_create(const axutil_env_t *env)
{
    axis2_desc_t *desc = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    desc = (axis2_desc_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_desc_t));

    if (!desc)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    desc->param_container = NULL;
    desc->children = NULL;

    desc->param_container = (axutil_param_container_t *)
        axutil_param_container_create(env);
    if (!(desc->param_container))
    {
        axis2_desc_free(desc, env);
        return NULL;
    }

    desc->children = axutil_hash_make(env);
	if (!(desc->children))
    {
        axis2_desc_free(desc, env);
        return NULL;
    }

    return desc;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_desc_free(axis2_desc_t *desc,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (desc->children)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;

        for (hi = axutil_hash_first(desc->children, env); hi;
            hi = axutil_hash_next(env, hi))
        {
            axutil_hash_this(hi, NULL, NULL, &val);

            if (val)
            {
                axis2_msg_free((axis2_msg_t *)val, env);
            }
        }

        axutil_hash_free(desc->children, env);
    }

    if (desc->param_container)
    {
        axutil_param_container_free(desc->param_container, env);
    }

    if (desc)
    {
        AXIS2_FREE(env->allocator, desc);
    }

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_desc_add_param(axis2_desc_t *desc,
    const axutil_env_t *env,
    axutil_param_t *param)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, param, AXIS2_FALSE);

    return axutil_param_container_add_param(desc->param_container, env, param);
}

AXIS2_EXTERN axutil_param_t *AXIS2_CALL
axis2_desc_get_param(const axis2_desc_t *desc,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    AXIS2_PARAM_CHECK(env->error, param_name, NULL);
    return axutil_param_container_get_param(desc->param_container, env,
	    param_name);
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_desc_get_all_params(const axis2_desc_t *desc,
    const axutil_env_t *env)
{
    AXIS2_PARAM_CHECK(env->error, desc->param_container, AXIS2_FALSE);

    return axutil_param_container_get_params(desc->param_container, env);
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_desc_is_param_locked(const axis2_desc_t *desc,
    const axutil_env_t *env,
    const axis2_char_t *param_name)
{
    axutil_param_t *param_l = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, param_name, AXIS2_FALSE);

    param_l = axis2_desc_get_param(desc, env, param_name);

    return (param_l  && axutil_param_is_locked(param_l, env));
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_desc_add_child(const axis2_desc_t *desc,
    const axutil_env_t *env,
    const axis2_char_t *key,
    const void *child)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);

    if (desc->children)
    {
        axutil_hash_set(desc->children, key,
            AXIS2_HASH_KEY_STRING, child);
        return AXIS2_SUCCESS;
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_desc_get_all_children(const axis2_desc_t *desc,
    const axutil_env_t *env)
{
    return desc->children;
}

AXIS2_EXTERN void *AXIS2_CALL
axis2_desc_get_child(const axis2_desc_t *desc,
    const axutil_env_t *env,
    const axis2_char_t *key)
{
    return axutil_hash_get(desc->children, key, AXIS2_HASH_KEY_STRING);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_desc_remove_child(const axis2_desc_t *desc,
    const axutil_env_t *env,
    const axis2_char_t *key)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);

    if (desc->children)
    {
        axutil_hash_set(desc->children, key,
            AXIS2_HASH_KEY_STRING, NULL);
        return AXIS2_SUCCESS;
    }
    return AXIS2_FAILURE;
}

