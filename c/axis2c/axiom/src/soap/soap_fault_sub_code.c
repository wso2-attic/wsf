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

#include <axiom_soap_fault_sub_code.h>
#include "_axiom_soap_fault_code.h"
#include <axiom_soap_fault_value.h>
#include <axiom_soap_builder.h>

struct axiom_soap_fault_sub_code
{
    /* corresponding om element node */
    axiom_node_t *om_ele_node;
    /* sub element fault value */
    axiom_soap_fault_value_t *value;
    /* sub element fault subcode */
    axiom_soap_fault_sub_code_t *subcode;
    /* pointer to soap builder */
    axiom_soap_builder_t *builder;

    int soap_version;
};

AXIS2_EXTERN axiom_soap_fault_sub_code_t * AXIS2_CALL
axiom_soap_fault_sub_code_create(const axutil_env_t *env)
{
    axiom_soap_fault_sub_code_t *fault_sub_code = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    fault_sub_code = (axiom_soap_fault_sub_code_t*) AXIS2_MALLOC(
                env->allocator,
                sizeof(axiom_soap_fault_sub_code_t));
    if (!fault_sub_code)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    fault_sub_code->om_ele_node = NULL;
    fault_sub_code->value = NULL;
    fault_sub_code->subcode = NULL;
    fault_sub_code->builder = NULL;

    return  fault_sub_code;
}

AXIS2_EXTERN axiom_soap_fault_sub_code_t * AXIS2_CALL
axiom_soap_fault_sub_code_create_with_parent(const axutil_env_t *env,
        axiom_soap_fault_code_t *fault_code)
{
    axiom_soap_fault_sub_code_t *fault_sub_code = NULL;
    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;
    axiom_namespace_t *parent_ns = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, fault_code, NULL);
    fault_sub_code = axiom_soap_fault_sub_code_create(env);

    if (!fault_sub_code)
        return NULL;

    parent_node = axiom_soap_fault_code_get_base_node(fault_code, env);
    if (!parent_node)
    {
        axiom_soap_fault_sub_code_free(fault_sub_code, env);
        return NULL;
    }

    parent_ele  = (axiom_element_t *)axiom_node_get_data_element(
                parent_node, env);
    if (!parent_ele)
    {
        axiom_soap_fault_sub_code_free(fault_sub_code, env);
        return NULL;
    }
    fault_sub_code->soap_version =
        axiom_soap_fault_code_get_soap_version(fault_code, env);

    if (fault_sub_code->soap_version == AXIOM_SOAP12)
    {
        parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);
    }

    this_ele = axiom_element_create(env,
            parent_node, AXIOM_SOAP12_SOAP_FAULT_SUB_CODE_LOCAL_NAME,
            parent_ns, &this_node);

    if (!this_ele)
    {
        axiom_soap_fault_sub_code_free(fault_sub_code, env);
        return NULL;
    }

    fault_sub_code->om_ele_node = this_node;

    axiom_soap_fault_code_set_sub_code(fault_code, env, fault_sub_code);

    return fault_sub_code;
}

AXIS2_EXTERN axiom_soap_fault_sub_code_t * AXIS2_CALL
axiom_soap_fault_sub_code_create_with_parent_value(const axutil_env_t *env,
        axiom_soap_fault_code_t *fault_code,
        axis2_char_t *value)
{
    axiom_soap_fault_sub_code_t *fault_sub_code = NULL;
    axiom_soap_fault_value_t *fault_value       = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, value, NULL);

    fault_sub_code =
        axiom_soap_fault_sub_code_create_with_parent(env, fault_code);
    if (!fault_sub_code)
    {
        return NULL;
    }
    fault_value = axiom_soap_fault_value_create_with_subcode(env, fault_sub_code);
    if (!fault_value)
    {
        axiom_soap_fault_sub_code_free(fault_sub_code, env);
        return NULL;
    }

    axiom_soap_fault_value_set_text(fault_value, env, value);
    return fault_sub_code;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_soap_fault_sub_code_free(axiom_soap_fault_sub_code_t *fault_sub_code,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    if (fault_sub_code->value)
    {
        axiom_soap_fault_value_free(fault_sub_code->value, env);
        fault_sub_code->value = NULL;
    }
    if (fault_sub_code->subcode)
    {
        axiom_soap_fault_sub_code_free(fault_sub_code->subcode, env);
        fault_sub_code->subcode = NULL;
    }
    AXIS2_FREE(env->allocator, fault_sub_code);

    fault_sub_code = NULL;

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_sub_code_set_sub_code(
    axiom_soap_fault_sub_code_t *fault_sub_code,
    const axutil_env_t *env,
    axiom_soap_fault_sub_code_t *subcode)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, subcode, AXIS2_FAILURE);

    if (!(fault_sub_code->subcode))
    {
        fault_sub_code->subcode  = subcode;
        return AXIS2_SUCCESS;
    }
    else
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "error tring to set fault subcode more than once");
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axiom_soap_fault_value_t* AXIS2_CALL
axiom_soap_fault_sub_code_get_value
(axiom_soap_fault_sub_code_t *fault_sub_code,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);

    if (fault_sub_code->builder)
    {
        while (!(fault_sub_code->value) &&
                !axiom_node_is_complete(fault_sub_code->om_ele_node, env))
        {
            status = axiom_soap_builder_next(fault_sub_code->builder, env);
            if (status == AXIS2_FAILURE)
                break;
        }
    }
    return fault_sub_code->value;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_sub_code_set_value
(axiom_soap_fault_sub_code_t *fault_sub_code,
        const axutil_env_t *env,
        axiom_soap_fault_value_t *fault_sub_code_val)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, fault_sub_code_val, AXIS2_FAILURE);

    if (!(fault_sub_code->value))
    {
        fault_sub_code->value  = fault_sub_code_val;
        return AXIS2_SUCCESS;
    }
    else
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                "error tring to set fault subcode value more than once");
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axiom_soap_fault_sub_code_t* AXIS2_CALL
axiom_soap_fault_sub_code_get_subcode(
    axiom_soap_fault_sub_code_t *fault_sub_code,
    const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env, NULL);

    if (fault_sub_code->builder)
    {
        while (!(fault_sub_code->subcode) &&
                !axiom_node_is_complete(fault_sub_code->om_ele_node, env))
        {
            status = axiom_soap_builder_next(fault_sub_code->builder, env);
            if (status == AXIS2_FAILURE)
                break;
        }
    }
    return fault_sub_code->subcode;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_sub_code_set_base_node
(axiom_soap_fault_sub_code_t *fault_sub_code,
        const axutil_env_t *env,
        axiom_node_t *node)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, node, AXIS2_FAILURE);

    if (axiom_node_get_node_type(node, env) != AXIOM_ELEMENT)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_BASE_TYPE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    fault_sub_code->om_ele_node = node;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_fault_sub_code_get_base_node
(axiom_soap_fault_sub_code_t *fault_sub_code,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return fault_sub_code->om_ele_node;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_sub_code_set_builder(axiom_soap_fault_sub_code_t *fault_sub_code,
        const axutil_env_t *env,
        axiom_soap_builder_t *builder)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, builder, AXIS2_FAILURE);

    fault_sub_code->builder = builder;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_sub_code_set_soap_version(
    axiom_soap_fault_sub_code_t *fault_sub_code,
    const axutil_env_t *env,
    int soap_version)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    fault_sub_code->soap_version = soap_version;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axiom_soap_fault_sub_code_get_soap_version
(axiom_soap_fault_sub_code_t *fault_sub_code,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return fault_sub_code->soap_version;
}

