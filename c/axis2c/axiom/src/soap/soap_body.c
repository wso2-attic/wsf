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

#include "_axiom_soap_envelope.h"
#include "_axiom_soap_body.h"
#include <axutil_hash.h>
#include <axiom_soap_const.h>
#include <axiom_soap_builder.h>
#include <axiom_soap_fault_code.h>
#include <axiom_soap_fault_reason.h>
#include <axiom_soap_fault_detail.h>
#include <axiom_soap_fault_role.h>
#include <axiom_soap_fault_value.h>
#include <axiom_soap_fault_text.h>

struct axiom_soap_body
{
    axiom_node_t *om_ele_node;

    axis2_bool_t has_fault;

    axiom_soap_fault_t *soap_fault;

    axiom_soap_builder_t *soap_builder;

    int soap_version;
};

AXIS2_EXTERN axiom_soap_body_t* AXIS2_CALL
axiom_soap_body_create(const axutil_env_t *env)
{
    axiom_soap_body_t *soap_body = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    soap_body = (axiom_soap_body_t*)AXIS2_MALLOC(
                env->allocator,
                sizeof(axiom_soap_body_t));

    if (!soap_body)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    soap_body->om_ele_node = NULL;
    soap_body->soap_builder = NULL;
    soap_body->has_fault = AXIS2_FALSE;
    soap_body->soap_fault = NULL;

    return soap_body;
}



AXIS2_EXTERN axiom_soap_body_t* AXIS2_CALL
axiom_soap_body_create_with_parent(const axutil_env_t *env,
        axiom_soap_envelope_t *envelope)
{
    axiom_soap_body_t *soap_body = NULL;
    axiom_element_t *ele = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele =  NULL;
    axiom_namespace_t *om_ns = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, envelope, NULL);

    soap_body = axiom_soap_body_create(env);
    if (!soap_body)
    {
        return NULL;
    }

    /*get parent node from SOAP envelope */
    parent_node = axiom_soap_envelope_get_base_node(envelope, env);
    if (!parent_node)
    {
        axiom_soap_body_free(soap_body, env);
        return NULL;
    }
    parent_ele = (axiom_element_t *)axiom_node_get_data_element(
                parent_node, env);

    if (!parent_ele)
    {
        axiom_soap_body_free(soap_body, env);
        return NULL;
    }

    om_ns = axiom_element_get_namespace(parent_ele, env, parent_node);

    ele = axiom_element_create(env, parent_node,
            AXIOM_SOAP_BODY_LOCAL_NAME, om_ns,
            &(soap_body->om_ele_node));
    if (!ele)
    {
        axiom_soap_body_free(soap_body, env);
        return NULL;
    }

    axiom_soap_envelope_set_body(envelope, env, soap_body);

    return soap_body;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_soap_body_free(axiom_soap_body_t *soap_body,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (soap_body->soap_fault)
    {
        axiom_soap_fault_free(soap_body->soap_fault, env);
        soap_body->soap_fault = NULL;
    }
    AXIS2_FREE(env->allocator, soap_body);
    soap_body = NULL;
    return;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL axiom_soap_body_has_fault(axiom_soap_body_t *soap_body,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (soap_body->soap_fault)
    {
        soap_body->has_fault = AXIS2_TRUE;
        return AXIS2_TRUE;
    }
    else
    {
        if (soap_body->soap_builder)
        {
            while (!(soap_body->soap_fault) && !(axiom_node_is_complete(soap_body->om_ele_node, env)))
            {
                status = axiom_soap_builder_next(soap_body->soap_builder, env);
                if (status == AXIS2_FAILURE)
                    return AXIS2_FALSE;
            }
            if (soap_body->soap_fault)
            {
                soap_body->has_fault = AXIS2_TRUE;
                return AXIS2_TRUE;
            }
        }
    }

    return AXIS2_FALSE;
}

/**
 * Returns the axiom_soap_fault_t struct in this axiom_soap_bodY_t
 * struct
 *
 * @return the <code>SOAPFault</code> object in this <code>SOAPBody</code>
 *         object
 */
AXIS2_EXTERN axiom_soap_fault_t* AXIS2_CALL
axiom_soap_body_get_fault(axiom_soap_body_t *soap_body,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    if (soap_body->soap_fault)
    {
        return soap_body->soap_fault;
    }
    else if (soap_body->soap_builder)
    {
        while (!(soap_body->soap_fault) && !(axiom_node_is_complete(soap_body->om_ele_node, env)))
        {
            int status = AXIS2_SUCCESS;
            status = axiom_soap_builder_next(soap_body->soap_builder, env);
            if (status == AXIS2_FAILURE)
                return NULL;
        }
        if (soap_body->soap_fault)
        {
            soap_body->has_fault = AXIS2_TRUE;
            return soap_body->soap_fault;
        }
    }
    return NULL;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_body_get_base_node(axiom_soap_body_t *soap_body,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return soap_body->om_ele_node;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_body_set_base_node(axiom_soap_body_t *soap_body,
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
    soap_body->om_ele_node = node;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_body_set_builder(axiom_soap_body_t *soap_body,
        const axutil_env_t *env,
        axiom_soap_builder_t *builder)
{
    AXIS2_PARAM_CHECK(env->error, builder, AXIS2_FAILURE);
    soap_body->soap_builder = builder;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_body_build(axiom_soap_body_t *soap_body,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (soap_body->om_ele_node && soap_body->soap_builder)
    {
        while (axiom_node_is_complete(soap_body->om_ele_node, env) != AXIS2_TRUE)
        {
            status = axiom_soap_builder_next(soap_body->soap_builder, env);
            if (status == AXIS2_FAILURE)
                return AXIS2_FAILURE;
        }
    }
    return AXIS2_SUCCESS;
}

/**
    This is an internal function

*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_body_set_fault(axiom_soap_body_t *soap_body,
        const axutil_env_t *env,
        axiom_soap_fault_t *soap_fault)
{
    AXIS2_PARAM_CHECK(env->error, soap_fault, AXIS2_FAILURE);
    if (soap_body->soap_fault)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_ONLY_ONE_SOAP_FAULT_ALLOWED_IN_BODY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    else
    {
        soap_body->soap_fault = soap_fault;
        soap_body->has_fault = AXIS2_TRUE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_body_add_child(axiom_soap_body_t *soap_body,
        const axutil_env_t *env,
        axiom_node_t *child)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, child, AXIS2_FAILURE);

    if (soap_body->om_ele_node)
    {
        return axiom_node_add_child(soap_body->om_ele_node, env, child);
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN int AXIS2_CALL
axiom_soap_body_get_soap_version(axiom_soap_body_t *soap_body,
        const axutil_env_t *env)
{
    axiom_element_t *body_ele = NULL;
    axiom_namespace_t *om_ns = NULL;
    axis2_char_t *uri           = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (!soap_body->om_ele_node)
        return AXIS2_FAILURE;
    body_ele = axiom_node_get_data_element(soap_body->om_ele_node, env);
    if (!body_ele)
        return AXIS2_FAILURE;
    om_ns = axiom_element_get_namespace(body_ele, env, soap_body->om_ele_node);
    if (!om_ns)
        return AXIS2_FAILURE;
    uri = axiom_namespace_get_uri(om_ns, env);
    if (uri)
    {
        if (axutil_strcmp(uri, AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI) == 0)
            return AXIOM_SOAP11;
        else if (axutil_strcmp(uri, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI) == 0)
            return AXIOM_SOAP12;
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_body_convert_fault_to_soap11(axiom_soap_body_t *soap_body,
    const axutil_env_t *env)
{
    if (soap_body)
    {
        axiom_soap_fault_t *soap_fault = NULL;
        if (axiom_soap_body_has_fault(soap_body, env))
        {
            soap_fault = axiom_soap_body_get_fault(soap_body, env);
            if (soap_fault)
            {
                axiom_soap_fault_code_t *fault_code = NULL;
                axiom_soap_fault_reason_t *fault_reason = NULL;
                axiom_soap_fault_detail_t *fault_detail = NULL;
                axiom_soap_fault_role_t *fault_role = NULL;
                fault_code = axiom_soap_fault_get_code(soap_fault, env);
                if (fault_code)
                {
                    axiom_node_t *fault_code_om_node = NULL;
                    axiom_element_t *fault_code_om_ele = NULL;
                    axiom_node_t *fault_value_om_node = NULL;
                    axiom_element_t *fault_value_om_ele = NULL;
                    axiom_soap_fault_value_t *fault_value = NULL;
                    axis2_char_t *text = NULL;

                    fault_code_om_node = axiom_soap_fault_code_get_base_node(fault_code, env);
                    if (fault_code_om_node)
                    {
                        fault_code_om_ele = (axiom_element_t *)
                            axiom_node_get_data_element(fault_code_om_node, env);
                        if (fault_code_om_ele)
                        {
                            axiom_element_set_localname(fault_code_om_ele,
                            env, AXIOM_SOAP11_SOAP_FAULT_CODE_LOCAL_NAME);

                            fault_value = axiom_soap_fault_code_get_value(fault_code, env);

                            if (fault_value)
                            {
                                fault_value_om_node = axiom_soap_fault_value_get_base_node(fault_value, env);
                                if (fault_value_om_node)
                                {
                                    fault_value_om_node =  axiom_node_detach(fault_value_om_node, env);
                                    fault_value_om_ele = (axiom_element_t *)
                                        axiom_node_get_data_element(fault_value_om_node, env);
                                    if (fault_value_om_ele)
                                    {
                                        text = axiom_element_get_text(fault_value_om_ele, env, fault_value_om_node);
                                        if (text)
                                        {
                                            axiom_element_set_text(fault_code_om_ele, env, text, fault_code_om_node);
                                        }
                                        axiom_node_free_tree(fault_value_om_node, env);
                                    }

                                }
                            }
                        }
                    }
                }
                fault_reason = axiom_soap_fault_get_reason(soap_fault, env);
                if (fault_reason)
                {
                    axiom_node_t *fault_reason_om_node = NULL;
                    axiom_element_t *fault_reason_om_ele = NULL;
                    axiom_node_t *fault_text_om_node = NULL;
                    axiom_element_t *fault_text_om_ele = NULL;
                    axiom_soap_fault_text_t *fault_text = NULL;
                    axis2_char_t *text =  NULL;

                    fault_reason_om_node = axiom_soap_fault_reason_get_base_node(fault_reason, env);
                    if (fault_reason_om_node)
                    {
                        fault_reason_om_ele  = (axiom_element_t *)
                            axiom_node_get_data_element(fault_reason_om_node, env);

                        if (fault_reason_om_ele)
                        {

                            axiom_element_set_localname(fault_reason_om_ele,
                                env, AXIOM_SOAP11_SOAP_FAULT_STRING_LOCAL_NAME);

                            fault_text =
                                axiom_soap_fault_reason_get_first_soap_fault_text(fault_reason, env);
                            if (fault_text)
                            {
                                fault_text_om_node = axiom_soap_fault_text_get_base_node(fault_text, env);
                                if (fault_text_om_node)
                                {
                                    fault_text_om_node = axiom_node_detach(fault_text_om_node, env);
                                    fault_text_om_ele  = (axiom_element_t *)
                                        axiom_node_get_data_element(fault_text_om_node, env);
                                    if (fault_text_om_ele)
                                    {
                                        text = axiom_element_get_text(fault_text_om_ele, env, fault_text_om_node);
                                        if (text)
                                        {
                                            axiom_element_set_text(fault_reason_om_ele,
                                                env, text, fault_reason_om_node);
                                        }
                                    }
                                    axiom_node_free_tree(fault_text_om_node, env);
                                }
                            }
                        }
                    }
                }

                fault_role = axiom_soap_fault_get_role(soap_fault, env);
                if (fault_role)
                {
                    axiom_node_t *fault_role_om_node = NULL;
                    axiom_element_t *fault_role_om_ele = NULL;

                    fault_role_om_node = axiom_soap_fault_role_get_base_node(fault_role, env);
                    if (fault_role_om_node)
                    {
                        fault_role_om_ele = (axiom_element_t *)
                            axiom_node_get_data_element(fault_role_om_node, env);
                        if (fault_role_om_ele)
                        {
                            axiom_element_set_localname(fault_role_om_ele, env,
                                AXIOM_SOAP11_SOAP_FAULT_ACTOR_LOCAL_NAME);
                        }
                    }
                }

                fault_detail = axiom_soap_fault_get_detail(soap_fault, env);
                if (fault_detail)
                {
                    axiom_node_t *fault_detail_om_node = NULL;
                    axiom_element_t *fault_detail_om_ele = NULL;
                    fault_detail_om_node = axiom_soap_fault_detail_get_base_node(fault_detail, env);
                    if (fault_detail_om_node)
                    {
                        fault_detail_om_ele = (axiom_element_t *)
                            axiom_node_get_data_element(fault_detail_om_node, env);
                        if (fault_detail_om_ele)
                        {
                            axiom_element_set_localname(fault_detail_om_ele,
                                env, AXIOM_SOAP11_SOAP_FAULT_DETAIL_LOCAL_NAME);
                        }
                    }
                }
            }
        }
    }
    return AXIS2_SUCCESS;
}
