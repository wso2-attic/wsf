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

#include "_axiom_soap_fault_node.h"
#include <axiom_node.h>
#include <axiom_element.h>
#include "_axiom_soap_fault.h"

struct axiom_soap_fault_node
{
    axiom_node_t *om_ele_node;
};

AXIS2_EXTERN axiom_soap_fault_node_t * AXIS2_CALL
axiom_soap_fault_node_create(const axutil_env_t *env)
{
    axiom_soap_fault_node_t *fault_node = NULL;

    fault_node = (axiom_soap_fault_node_t*)AXIS2_MALLOC(
        env->allocator,
        sizeof(axiom_soap_fault_node_t));

    if (!fault_node)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    fault_node->om_ele_node = NULL;

    return fault_node;
}

AXIS2_EXTERN axiom_soap_fault_node_t * AXIS2_CALL
axiom_soap_fault_node_create_with_parent(const axutil_env_t *env,
    axiom_soap_fault_t *fault)
{
    axiom_soap_fault_node_t *fault_node = NULL;
    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;

    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;

    axiom_namespace_t *parent_ns = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, fault, NULL);

    fault_node = axiom_soap_fault_node_create(env);
    if (!fault_node)
        return NULL;

    parent_node = axiom_soap_fault_get_base_node(fault, env);
    if (!parent_node)
    {
        axiom_soap_fault_node_free(fault_node, env);
        return NULL;
    }

    parent_ele  = (axiom_element_t *)axiom_node_get_data_element(
        parent_node, env);
    if (!parent_ele)
    {
        axiom_soap_fault_node_free(fault_node, env);
        return NULL;
    }

    parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);

    this_ele = axiom_element_create(env,
        parent_node,
        AXIOM_SOAP12_SOAP_FAULT_NODE_LOCAL_NAME,
        parent_ns,
        &this_node);

    if (!this_ele)
    {
        axiom_soap_fault_node_free(fault_node, env);
        return NULL;
    }

    fault_node->om_ele_node = this_node;

    axiom_soap_fault_set_node(fault, env, fault_node);

    return  fault_node;
}



AXIS2_EXTERN void AXIS2_CALL
axiom_soap_fault_node_free(axiom_soap_fault_node_t *fault_node,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    AXIS2_FREE(env->allocator, fault_node);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_node_set_value(axiom_soap_fault_node_t *fault_node,
    const axutil_env_t *env,
    axis2_char_t *uri)
{
    axiom_element_t *om_ele = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, uri, AXIS2_FAILURE);

    if (fault_node->om_ele_node)
    {
        om_ele = (axiom_element_t *)axiom_node_get_data_element(
            fault_node->om_ele_node, env);

        if (om_ele)
        {
            return axiom_element_set_text(om_ele, env, uri,
                fault_node->om_ele_node);
        }
    }

    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_soap_fault_node_get_value(axiom_soap_fault_node_t *fault_node,
    const axutil_env_t *env)
{
    axiom_element_t *om_ele =  NULL;

    AXIS2_ENV_CHECK(env, NULL);
    if (fault_node->om_ele_node)
    {
        om_ele = (axiom_element_t *)axiom_node_get_data_element(
            fault_node->om_ele_node, env);
        if (om_ele)
        {
            return axiom_element_get_text(om_ele,
                env, fault_node->om_ele_node);
        }

    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_node_set_base_node(axiom_soap_fault_node_t *fault_node,
    const axutil_env_t *env,
    axiom_node_t *node)
{
    AXIS2_PARAM_CHECK(env->error, node, AXIS2_FAILURE);
    if (axiom_node_get_node_type(node, env) != AXIOM_ELEMENT)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_INVALID_BASE_TYPE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    fault_node->om_ele_node = node;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_fault_node_get_base_node(axiom_soap_fault_node_t *fault_node,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return fault_node->om_ele_node;
}
