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

#include <axiom_comment.h>
#include "axiom_node_internal.h"
#include <axutil_string.h>

struct axiom_comment
{
    /** comment text */
    axis2_char_t *value;
};

AXIS2_EXTERN axiom_comment_t *AXIS2_CALL
axiom_comment_create(const axutil_env_t *env,
    axiom_node_t *parent,
    const axis2_char_t *value,
    axiom_node_t **node)
{
    axiom_comment_t *comment = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, value, NULL);
    AXIS2_PARAM_CHECK(env->error, node, NULL);
    *node = NULL;
    *node = axiom_node_create(env);
    if (!*node)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    comment = (axiom_comment_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axiom_comment_t));
    if (!comment)
    {
        AXIS2_FREE(env->allocator, (*node));
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    comment->value = NULL;

    if (value)
    {
        comment->value = (axis2_char_t*)axutil_strdup(env, value);
        if (!comment->value)
        {
            AXIS2_FREE(env->allocator, comment);
            AXIS2_FREE(env->allocator, (*node));
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }

    axiom_node_set_data_element((*node), env, comment);
    axiom_node_set_node_type((*node), env, AXIOM_COMMENT);

    if (parent)
    {
        axiom_node_add_child(parent, env, (*node));
    }

    return comment;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_comment_free(axiom_comment_t *comment,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (comment->value)
    {
        AXIS2_FREE(env->allocator, comment->value);
    }
    AXIS2_FREE(env->allocator, comment);
    return;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_comment_get_value(axiom_comment_t *comment,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return comment->value;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_comment_set_value(axiom_comment_t *comment,
    const axutil_env_t *env,
    const axis2_char_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, value, AXIS2_FAILURE);
    if (comment->value)
    {
        AXIS2_FREE(env->allocator, comment->value);
    }

    comment->value = (axis2_char_t*)axutil_strdup(env, value);

    if (!comment->value)
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_comment_serialize(axiom_comment_t *comment,
    const axutil_env_t *env,
    axiom_output_t *om_output)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_output, AXIS2_FAILURE);

    if (comment->value)
    {
        return  axiom_output_write(om_output, env,
            AXIOM_COMMENT , 1 , comment->value);
    }
    return AXIS2_FAILURE;
}


