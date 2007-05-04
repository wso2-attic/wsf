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
#include <axiom_soap_fault_value.h>
#include "_axiom_soap_fault_sub_code.h"
#include "_axiom_soap_fault_code.h"
#include <axiom_element.h>
#include <axiom_text.h>

struct axiom_soap_fault_value
{
    /** store om element node */
    axiom_node_t *om_ele_node;
};

AXIS2_EXTERN axiom_soap_fault_value_t * AXIS2_CALL
axiom_soap_fault_value_create(const axutil_env_t *env)
{
    axiom_soap_fault_value_t *fault_value = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    fault_value = (axiom_soap_fault_value_t *)AXIS2_MALLOC(
        env->allocator,
        sizeof(axiom_soap_fault_value_t));

    if (!fault_value)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    fault_value->om_ele_node = NULL;

    return fault_value;
}


AXIS2_EXTERN axiom_soap_fault_value_t * AXIS2_CALL
axiom_soap_fault_value_create_with_subcode(const axutil_env_t *env,
    axiom_soap_fault_sub_code_t *parent)
{
    axiom_soap_fault_value_t *fault_value = NULL;

    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;
    axiom_namespace_t *parent_ns = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;
    int soap_version = -1;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, parent, NULL);

    fault_value = axiom_soap_fault_value_create(env);

    if (!fault_value)
    {
        return NULL;
    }

    parent_node = axiom_soap_fault_sub_code_get_base_node(parent, env);

    if (!parent_node)
    {
        axiom_soap_fault_value_free(fault_value, env);
        return NULL;
    }

    parent_ele  = (axiom_element_t*)
        axiom_node_get_data_element(parent_node, env);

    if (!parent_ele)
    {
        axiom_soap_fault_value_free(fault_value, env);
        return NULL;
    }
    soap_version =
        axiom_soap_fault_sub_code_get_soap_version(parent, env);
    if (soap_version == AXIOM_SOAP12)
    {
        parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);
    }

    this_ele = axiom_element_create(env,
        parent_node,
        AXIOM_SOAP12_SOAP_FAULT_VALUE_LOCAL_NAME,
        parent_ns,
        &this_node);

    if (!this_ele)
    {
        axiom_soap_fault_value_free(fault_value, env);
        return NULL;
    }

    fault_value->om_ele_node = this_node;

    axiom_soap_fault_sub_code_set_value(parent, env, fault_value);

    return fault_value;
}

AXIS2_EXTERN axiom_soap_fault_value_t * AXIS2_CALL
axiom_soap_fault_value_create_with_code(const axutil_env_t *env,
    axiom_soap_fault_code_t *parent)
{
    axiom_soap_fault_value_t *fault_value = NULL;
    int soap_version = -1;
    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;
    axiom_namespace_t *parent_ns = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, parent, NULL);

    fault_value = axiom_soap_fault_value_create(env);

    if (!fault_value)
    {
        return NULL;
    }

    parent_node = axiom_soap_fault_code_get_base_node(parent, env);
    if (!parent_node)
    {
        axiom_soap_fault_value_free(fault_value, env);
        return NULL;
    }
    parent_ele  = (axiom_element_t*)
        axiom_node_get_data_element(parent_node, env);
    if (!parent_ele)
    {
        axiom_soap_fault_value_free(fault_value, env);
        return NULL;
    }
    soap_version = axiom_soap_fault_code_get_soap_version(parent, env);
    if (soap_version == AXIOM_SOAP12)
    {
        parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);
    }
    this_ele = axiom_element_create(env,
        parent_node, AXIOM_SOAP12_SOAP_FAULT_VALUE_LOCAL_NAME,
        parent_ns, &this_node);

    if (!this_ele)
    {
        axiom_soap_fault_value_free(fault_value, env);
        return NULL;
    }
    fault_value->om_ele_node = this_node;

    axiom_soap_fault_code_set_value(parent, env, fault_value);

    return fault_value;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_soap_fault_value_free(axiom_soap_fault_value_t *fault_value,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    AXIS2_FREE(env->allocator, fault_value);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_value_set_base_node(axiom_soap_fault_value_t *fault_value,
    const axutil_env_t *env,
    axiom_node_t *node)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (axiom_node_get_node_type(node, env) != AXIOM_ELEMENT)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_INVALID_BASE_TYPE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    fault_value->om_ele_node = node;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_fault_value_get_base_node(axiom_soap_fault_value_t *fault_value,
    const axutil_env_t *env)
{
    return fault_value->om_ele_node;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_soap_fault_value_get_text(axiom_soap_fault_value_t *fault_value,
    const axutil_env_t *env)
{
    axiom_node_t *value_node = NULL;
    axiom_element_t *value_element = NULL;

    value_node = axiom_soap_fault_value_get_base_node(fault_value, env);

    if (!value_node)
        return NULL;

    value_element = (axiom_element_t*)axiom_node_get_data_element(
        value_node, env);

    if (!value_element)
        return NULL;

    return axiom_element_get_text(value_element, env, value_node);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_value_set_text(axiom_soap_fault_value_t *fault_value,
    const axutil_env_t *env,
    axis2_char_t *text)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, text, AXIS2_FAILURE);
    if (fault_value->om_ele_node &&
        axiom_node_get_node_type(fault_value->om_ele_node, env) == AXIOM_ELEMENT)
    {
        axiom_element_t *om_ele = NULL;
        om_ele = (axiom_element_t *)
            axiom_node_get_data_element(fault_value->om_ele_node, env);
        return axiom_element_set_text(om_ele, env, text, fault_value->om_ele_node);
    }
    return AXIS2_FAILURE;
}
