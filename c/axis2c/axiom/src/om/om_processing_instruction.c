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

#include <axiom_processing_instruction.h>
#include <axutil_string.h>
#include "axiom_node_internal.h"

struct axiom_processing_instruction
{
    /** processing instruction  target */
    axis2_char_t *target;
    /** processing instruction  value */
    axis2_char_t *value;
};

AXIS2_EXTERN axiom_processing_instruction_t *AXIS2_CALL
axiom_processing_instruction_create(const axutil_env_t *env,
    axiom_node_t * parent,
    const axis2_char_t * target,
    const axis2_char_t * value,
    axiom_node_t ** node)
{
    axiom_processing_instruction_t *processing_instruction = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    if (!node || !target || !value)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM,
            AXIS2_FAILURE);
        return NULL;
    }

    *node = axiom_node_create(env);

    if (!*node)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    processing_instruction = 
        (axiom_processing_instruction_t *) AXIS2_MALLOC(env->allocator,
            sizeof(axiom_processing_instruction_t));

    if (!processing_instruction)
    {
        AXIS2_FREE(env->allocator, (*node));
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    processing_instruction->value = NULL;

    if (value)
    {
        processing_instruction->value = (axis2_char_t*)axutil_strdup(env, value);
        if (!processing_instruction->value)
        {
            AXIS2_FREE(env->allocator, processing_instruction);
            AXIS2_FREE(env->allocator , *node);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }

    processing_instruction->target = NULL;

    if (target)
    {
        processing_instruction->target = (axis2_char_t*) axutil_strdup(env, target);
        if (!processing_instruction->target)
        {
            AXIS2_FREE(env->allocator, processing_instruction->value);
            AXIS2_FREE(env->allocator, processing_instruction);
            AXIS2_FREE(env->allocator, *node);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }
    axiom_node_set_data_element(*node, env, processing_instruction);
    axiom_node_set_node_type(*node, env, AXIOM_PROCESSING_INSTRUCTION);
    if (parent)
    {
        axiom_node_add_child(parent, env, (*node));
    }

    return processing_instruction;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_processing_instruction_free(axiom_processing_instruction_t *om_pi,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (om_pi->value)
    {
        AXIS2_FREE(env->allocator, om_pi->value);
        om_pi->value = NULL;
    }

    if (om_pi->target)
    {
        AXIS2_FREE(env->allocator, om_pi->target);
        om_pi->target = NULL;
    }

    AXIS2_FREE(env->allocator, om_pi);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_processing_instruction_set_value(axiom_processing_instruction_t *om_pi,
    const axutil_env_t *env,
    const axis2_char_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, value, AXIS2_FAILURE);
    om_pi->value = (axis2_char_t*)axutil_strdup(env, value);
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_processing_instruction_set_target(axiom_processing_instruction_t *om_pi,
    const axutil_env_t *env,
    const axis2_char_t *target)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, target, AXIS2_FAILURE);
    om_pi->target = (axis2_char_t*)axutil_strdup(env, target);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_processing_instruction_get_value(axiom_processing_instruction_t *om_pi,
    const axutil_env_t *env)
{
    return om_pi->value;
}
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_processing_instruction_get_target(axiom_processing_instruction_t *om_pi,
    const axutil_env_t *env)
{
    return om_pi->target;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_processing_instruction_serialize(axiom_processing_instruction_t *om_pi,
    const axutil_env_t *env,
    axiom_output_t *om_output)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_output, AXIS2_FAILURE);

    if (om_pi->target && om_pi->value)
    {
        return axiom_output_write(om_output, env,
            AXIOM_PROCESSING_INSTRUCTION,
            2, om_pi->target, om_pi->value);
    }
    else if (om_pi->target)
    {
        return axiom_output_write(om_output, env,
            AXIOM_PROCESSING_INSTRUCTION,
            2, om_pi->target, om_pi->value);
    }
    return AXIS2_FAILURE;
}

