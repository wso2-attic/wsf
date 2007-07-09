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

#include <axis2_any_content_type.h>
#include <axutil_string.h>

struct axis2_any_content_type
{
    /** map of values in the any content type  */
    axutil_hash_t *value_map;
};

AXIS2_EXTERN axis2_any_content_type_t *AXIS2_CALL
axis2_any_content_type_create(const axutil_env_t *env)
{
    axis2_any_content_type_t *any_content_type = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    any_content_type = AXIS2_MALLOC(env->allocator,
	    sizeof(axis2_any_content_type_t));
    if (!any_content_type)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    any_content_type->value_map = NULL;

    any_content_type->value_map  = axutil_hash_make(env);

    if (!(any_content_type->value_map))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        axis2_any_content_type_free(any_content_type, env);
        return NULL;
    }

    return any_content_type;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_any_content_type_add_value(axis2_any_content_type_t *any_content_type,
    const axutil_env_t *env,
    const axutil_qname_t *qname,
    const axis2_char_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (any_content_type->value_map)
    {
        axis2_char_t *name = NULL;

        name = axutil_qname_to_string((axutil_qname_t *)qname, env);
        axutil_hash_set(any_content_type->value_map, name,
		    AXIS2_HASH_KEY_STRING, value);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_any_content_type_get_value(const axis2_any_content_type_t *any_content_type,
    const axutil_env_t *env,
    const axutil_qname_t *qname)
{
    if (any_content_type->value_map)
    {
        axis2_char_t *name = NULL;

        name = axutil_qname_to_string((axutil_qname_t *)qname, env);
        return axutil_hash_get(any_content_type->value_map, name,
            AXIS2_HASH_KEY_STRING);
    }
    return NULL;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_any_content_type_get_value_map(const axis2_any_content_type_t *any_content_type,
    const axutil_env_t *env)
{
	return any_content_type->value_map;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_any_content_type_free(axis2_any_content_type_t *any_content_type,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (any_content_type->value_map)
    {
        axutil_hash_free(any_content_type->value_map, env);
    }

    AXIS2_FREE(env->allocator, any_content_type);
    
	return;
}
