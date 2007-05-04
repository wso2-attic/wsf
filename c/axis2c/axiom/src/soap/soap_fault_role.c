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

#include <axiom_soap_fault_role.h>
#include "_axiom_soap_fault.h"
#include <axiom_soap_builder.h>
#include <axiom_element.h>

struct axiom_soap_fault_role
{
    axiom_node_t *om_ele_node;
};

AXIS2_EXTERN axiom_soap_fault_role_t * AXIS2_CALL
axiom_soap_fault_role_create(const axutil_env_t *env)
{
    axiom_soap_fault_role_t *fault_role = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    fault_role = (axiom_soap_fault_role_t*) AXIS2_MALLOC(
        env->allocator,
        sizeof(axiom_soap_fault_role_t));

    if (!fault_role)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    fault_role->om_ele_node = NULL;

    return  fault_role;
}

AXIS2_EXTERN axiom_soap_fault_role_t * AXIS2_CALL
axiom_soap_fault_role_create_with_parent(const axutil_env_t *env,
    axiom_soap_fault_t *fault)
{
    axiom_soap_fault_role_t *fault_role = NULL;
    int soap_version = -1;

    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;

    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;

    axiom_namespace_t *parent_ns = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, fault, NULL);

    fault_role = axiom_soap_fault_role_create(env);
    if (!fault_role)
        return NULL;

    parent_node = axiom_soap_fault_get_base_node(fault, env);
    if (!parent_node)
    {
        axiom_soap_fault_role_free(fault_role, env);
        return NULL;
    }
    parent_ele  = (axiom_element_t *)axiom_node_get_data_element(
        parent_node, env);

    if (!parent_ele)
    {
        axiom_soap_fault_role_free(fault_role, env);
        return NULL;
    }
    soap_version = axiom_soap_fault_get_soap_version(fault, env);
    if (soap_version == AXIOM_SOAP12)
    {
        parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);
    }
    this_ele = axiom_element_create(env,
        parent_node, AXIOM_SOAP12_SOAP_FAULT_ROLE_LOCAL_NAME,
        parent_ns, &this_node);

    if (!this_ele)
    {
        axiom_soap_fault_role_free(fault_role, env);
        return NULL;
    }

    fault_role->om_ele_node = this_node;

    axiom_soap_fault_set_role(fault, env, fault_role);

    return fault_role;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_soap_fault_role_free(axiom_soap_fault_role_t *fault_role,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    AXIS2_FREE(env->allocator, fault_role);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_role_set_role_value
(axiom_soap_fault_role_t *fault_role,
    const axutil_env_t *env,
    axis2_char_t* uri)
{
    axiom_element_t *role_ele = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, uri, AXIS2_FAILURE);

    if (!fault_role->om_ele_node)
        return AXIS2_FAILURE;

    role_ele = (axiom_element_t*)axiom_node_get_data_element
        (fault_role->om_ele_node, env);

    if (role_ele)
    {
        return axiom_element_set_text(role_ele,  env, uri,
            fault_role->om_ele_node);
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_soap_fault_role_get_role_value
(axiom_soap_fault_role_t *fault_role,
    const axutil_env_t *env)
{
    axiom_element_t *role_ele = NULL;

    if (!fault_role->om_ele_node)
        return NULL;

    role_ele = (axiom_element_t *)axiom_node_get_data_element
        (fault_role->om_ele_node, env);

    if (role_ele)
    {
        return axiom_element_get_text(role_ele,  env,
            fault_role->om_ele_node);
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_role_set_base_node
(axiom_soap_fault_role_t *fault_role,
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
    fault_role->om_ele_node = node;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_fault_role_get_base_node
(axiom_soap_fault_role_t *fault_role,
    const axutil_env_t *env)
{
    return fault_role->om_ele_node;
}
