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

#include <axiom_namespace.h>
#include <axutil_string.h>
#include "axiom_namespace_internal.h"

struct axiom_namespace
{
    /** namespace URI */
    axutil_string_t *uri;
    /** namespace prefix  */
    axutil_string_t *prefix;

    axis2_char_t *key;

    int ref;
};

AXIS2_EXTERN axiom_namespace_t *AXIS2_CALL
axiom_namespace_create(const axutil_env_t *env,
    const axis2_char_t * uri,
    const axis2_char_t * prefix)
{
    axiom_namespace_t *om_namespace = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    if (!uri)
    {
      uri = "";
    }

    om_namespace = (axiom_namespace_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axiom_namespace_t));
    if (!om_namespace)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY , AXIS2_FAILURE);
        return NULL;
    }

    om_namespace->ref = 0;
    om_namespace->prefix = NULL;
    om_namespace->uri = NULL;
    om_namespace->key = NULL;

    om_namespace->uri = axutil_string_create(env, uri);
    if (!om_namespace->uri)
    {
        AXIS2_FREE(env->allocator, om_namespace);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    if (prefix)
    {
        om_namespace->prefix = axutil_string_create(env, prefix);
        if (!om_namespace->prefix)
        {
            AXIS2_FREE(env->allocator, om_namespace);
            AXIS2_FREE(env->allocator, om_namespace->uri);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }

    return om_namespace ;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_namespace_free(axiom_namespace_t *om_namespace,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (--om_namespace->ref > 0)
    {
        return;
    }

    if (om_namespace->prefix)
    {
        axutil_string_free(om_namespace->prefix, env);
    }

    if (om_namespace->uri)
    {
        axutil_string_free(om_namespace->uri, env);
    }

    if (om_namespace->key)
    {
        AXIS2_FREE(env->allocator, om_namespace->key);
    }

    AXIS2_FREE(env->allocator, om_namespace);

    return;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_namespace_equals(axiom_namespace_t *om_namespace,
    const axutil_env_t *env,
    axiom_namespace_t *om_namespace1)
{
    int uris_differ = 0;
    int prefixes_differ = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_namespace, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_namespace1, AXIS2_FAILURE);

    if (!om_namespace || !om_namespace1)
    {
        return AXIS2_FALSE;
    }

    if (om_namespace->uri && om_namespace1->uri)
    {
        uris_differ = axutil_strcmp(axutil_string_get_buffer(om_namespace->uri, env), 
            axutil_string_get_buffer(om_namespace1->uri, env));
    }
    else
    {
        uris_differ = (om_namespace->uri || om_namespace1->uri);
    }

    if (om_namespace->prefix && om_namespace1->prefix)
    {
        prefixes_differ =
            axutil_strcmp(axutil_string_get_buffer(om_namespace->prefix, env), 
            axutil_string_get_buffer(om_namespace1->prefix, env));
    }
    else
    {
        prefixes_differ = (om_namespace->prefix || om_namespace1->prefix);
    }

    return (!uris_differ && !prefixes_differ);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_namespace_serialize(axiom_namespace_t *om_namespace,
    const axutil_env_t *env,
    axiom_output_t *om_output)
{
    int status = AXIS2_SUCCESS;
    if (!om_namespace)
    {
        return AXIS2_FAILURE;
    }

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_output, AXIS2_FAILURE);

    if (om_namespace->uri && NULL != om_namespace->prefix &&
        axutil_strcmp(axutil_string_get_buffer(om_namespace->prefix, env), "") != 0)
    {
        status = axiom_output_write(om_output, env, AXIOM_NAMESPACE,
            2, axutil_string_get_buffer(om_namespace->prefix, env),
            axutil_string_get_buffer(om_namespace->uri, env));
    }
    else if (om_namespace->uri)
    {
        status = axiom_output_write(om_output, env, AXIOM_NAMESPACE,
            2, NULL, axutil_string_get_buffer(om_namespace->uri, env));
    }
    return status;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_namespace_get_uri(axiom_namespace_t *om_namespace,
    const axutil_env_t *env)
{
    if (om_namespace->uri)
    {
        return (axis2_char_t *)axutil_string_get_buffer(om_namespace->uri, env);
    }
    return NULL;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_namespace_get_prefix(axiom_namespace_t *om_namespace,
    const axutil_env_t *env)
{
    if (om_namespace->prefix)
    {
        return (axis2_char_t *)axutil_string_get_buffer(om_namespace->prefix, env);
    }
    return NULL;
}

AXIS2_EXTERN axiom_namespace_t *AXIS2_CALL
axiom_namespace_clone(axiom_namespace_t *om_namespace,
    const axutil_env_t *env)
{
    axiom_namespace_t *cloned_ns    = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    cloned_ns = axiom_namespace_create_str(env,
        om_namespace->uri, om_namespace->prefix);
    if (cloned_ns)
    {
        return cloned_ns;
    }
    return NULL;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_namespace_to_string(axiom_namespace_t *om_namespace,
    const axutil_env_t *env)
{
    axis2_char_t *temp_str = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    if (om_namespace->key)
    {
        AXIS2_FREE(env->allocator, om_namespace->key);
        om_namespace->key = NULL;
    }
    if ((om_namespace->uri) && (NULL != om_namespace->prefix))
    {
        temp_str = axutil_stracat(env, axutil_string_get_buffer(om_namespace->uri, env), "|");
        om_namespace->key = axutil_stracat(env,
			temp_str, 
            axutil_string_get_buffer(om_namespace->prefix, env));
        if (temp_str)
        {
            AXIS2_FREE(env->allocator, temp_str);
            temp_str = NULL;
        }
    }
    else if ((om_namespace->uri) && !(om_namespace->prefix))
    {
        om_namespace->key = axutil_strdup(env, axutil_string_get_buffer(om_namespace->uri, env));
        if (!(om_namespace->key))
        {
            return NULL;
        }
    }
    return om_namespace->key;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_namespace_set_uri(axiom_namespace_t *om_namespace,
    const axutil_env_t *env,
    const axis2_char_t *uri)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, uri, AXIS2_FAILURE);

    if (om_namespace->uri)
    {
        axutil_string_free(om_namespace->uri, env);
        om_namespace->uri = NULL;
    }

    om_namespace->uri = axutil_string_create(env, uri);
    if (!(om_namespace->uri))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axiom_namespace_increment_ref(struct axiom_namespace *om_namespace,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    om_namespace->ref++;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_namespace_t *AXIS2_CALL
axiom_namespace_create_str(const axutil_env_t *env,
    axutil_string_t * uri,
    axutil_string_t * prefix)
{
    axiom_namespace_t *om_namespace = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    if (!uri)
    {
      uri = axutil_string_create(env, "");
    }

    om_namespace = (axiom_namespace_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axiom_namespace_t));
    if (!om_namespace)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY , AXIS2_FAILURE);
        return NULL;
    }

    om_namespace->ref = 0;
    om_namespace->prefix = NULL;
    om_namespace->uri = NULL;
    om_namespace->key = NULL;

    om_namespace->uri = axutil_string_clone(uri, env);
    if (!om_namespace->uri)
    {
        AXIS2_FREE(env->allocator, om_namespace);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    if (prefix)
    {
        om_namespace->prefix = axutil_string_clone(prefix, env);
        if (!om_namespace->prefix)
        {
            AXIS2_FREE(env->allocator, om_namespace);
            AXIS2_FREE(env->allocator, om_namespace->uri);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }

    return om_namespace ;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_namespace_set_uri_str(axiom_namespace_t *om_namespace,
    const axutil_env_t *env,
    axutil_string_t *uri)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, uri, AXIS2_FAILURE);

    if (om_namespace->uri)
    {
        axutil_string_free(om_namespace->uri, env);
        om_namespace->uri = NULL;
    }

    om_namespace->uri = axutil_string_clone(uri, env);
    if (!(om_namespace->uri))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;

}

AXIS2_EXTERN axutil_string_t *AXIS2_CALL
axiom_namespace_get_uri_str(axiom_namespace_t *om_namespace,
    const axutil_env_t *env)
{
    return om_namespace->uri;
}

AXIS2_EXTERN axutil_string_t *AXIS2_CALL
axiom_namespace_get_prefix_str(axiom_namespace_t *om_namespace,
    const axutil_env_t *env)
{
    return om_namespace->prefix;
}

