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

#include "axiom_soap11_builder_helper.h"
#include <axiom_stax_builder.h>
#include <axiom_soap_builder.h>
#include <axiom_soap_const.h>
#include "_axiom_soap_fault_code.h"
#include "_axiom_soap_fault_value.h"
#include "_axiom_soap_fault_reason.h"
#include "_axiom_soap_fault.h"
#include "_axiom_soap_body.h"
#include "_axiom_soap_fault_detail.h"
#include <axiom_soap_fault_text.h>
#include "_axiom_soap_fault_role.h"
#include <axiom_stax_builder_internal.h>
#include <axiom_node_internal.h>

static axis2_status_t
axiom_soap11_builder_helper_process_text(axiom_soap11_builder_helper_t *builder_helper,
        const axutil_env_t *env);

struct axiom_soap11_builder_helper
{
    axiom_soap_builder_t *soap_builder;

    axis2_bool_t fault_code_present;

    axis2_bool_t fault_string_present;

    axiom_stax_builder_t *om_builder;

    axiom_node_t *last_processed_node;

};

AXIS2_EXTERN axiom_soap11_builder_helper_t* AXIS2_CALL
axiom_soap11_builder_helper_create(const axutil_env_t *env,
        axiom_soap_builder_t *soap_builder,
        axiom_stax_builder_t *om_builder)
{
    axiom_soap11_builder_helper_t *builder_helper = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, soap_builder, NULL);
    AXIS2_PARAM_CHECK(env->error, om_builder, NULL);

    builder_helper = (axiom_soap11_builder_helper_t*)AXIS2_MALLOC(
                env->allocator, sizeof(axiom_soap11_builder_helper_t));
    if (!builder_helper)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    builder_helper->fault_code_present = AXIS2_FALSE;
    builder_helper->fault_string_present = AXIS2_FALSE;
    builder_helper->last_processed_node = NULL;
    builder_helper->om_builder = NULL;

    builder_helper->soap_builder = soap_builder;
    builder_helper->om_builder = om_builder;

    return builder_helper;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_soap11_builder_helper_free(axiom_soap11_builder_helper_t *builder_helper,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    AXIS2_FREE(env->allocator, builder_helper);
    builder_helper = NULL;
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap11_builder_helper_handle_event(axiom_soap11_builder_helper_t *builder_helper,
        const axutil_env_t *env,
        axiom_node_t *om_element_node,
        int element_level)
{
    axiom_element_t *om_ele = NULL;
    axis2_char_t *ele_localname = NULL;
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_soap_fault_t *soap_fault = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_element_node, AXIS2_FAILURE);

    om_ele = (axiom_element_t *)axiom_node_get_data_element(om_element_node, env);

    ele_localname = axiom_element_get_localname(om_ele, env);
    if (!ele_localname)
    {
        return AXIS2_FAILURE;
    }

    soap_envelope = axiom_soap_builder_get_soap_envelope(builder_helper->soap_builder, env);

    if (!soap_envelope)
    {
        return AXIS2_FAILURE;
    }

    soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
    if (!soap_body)
    {
        return AXIS2_FAILURE;
    }

    soap_fault = axiom_soap_body_get_fault(soap_body, env);
    if (!soap_fault)
    {
        return AXIS2_FAILURE;
    }


    if (element_level == 4)
    {
        axiom_soap_fault_code_t *fault_code = NULL;
        axiom_soap_fault_value_t *fault_value = NULL;
        axiom_node_t *fault_value_node = NULL;
        axiom_element_t *fault_value_ele  = NULL;

        if (axutil_strcmp(ele_localname, AXIOM_SOAP11_SOAP_FAULT_CODE_LOCAL_NAME) == 0)
        {
            axis2_status_t status = AXIS2_SUCCESS;

            if (builder_helper->fault_string_present)
            {
                axiom_soap_builder_set_bool_processing_mandatory_fault_elements(
                    builder_helper->soap_builder, env, AXIS2_FALSE);
            }

            fault_code = axiom_soap_fault_code_create(env);
            if (!fault_code)
                return AXIS2_FAILURE;

            axiom_soap_fault_code_set_base_node(fault_code, env, om_element_node);

            axiom_soap_fault_set_code(soap_fault, env, fault_code);

            axiom_soap_fault_code_set_builder(fault_code, env, builder_helper->soap_builder);

            axiom_element_set_localname(om_ele, env, AXIOM_SOAP12_SOAP_FAULT_CODE_LOCAL_NAME);

            fault_value = axiom_soap_fault_value_create_with_code(env, fault_code);
            if (!fault_value)
                return AXIS2_FAILURE;

            fault_value_node = axiom_soap_fault_value_get_base_node(fault_value, env);
            if (!fault_value_node)
                return AXIS2_FAILURE;

            fault_value_ele = (axiom_element_t *)axiom_node_get_data_element(
                        fault_value_node, env);

            axiom_stax_builder_set_lastnode(builder_helper->om_builder,
                    env, fault_value_node);

            status = axiom_soap11_builder_helper_process_text(builder_helper, env);
            if (status  == AXIS2_FAILURE)
            {
                return AXIS2_FAILURE;
            }
            axiom_stax_builder_set_lastnode(builder_helper->om_builder,
                    env, om_element_node);
            axiom_node_set_complete(om_element_node, env, AXIS2_TRUE);

            axiom_stax_builder_set_element_level(builder_helper->om_builder,
                    env, (element_level - 1));
            builder_helper->fault_code_present = AXIS2_TRUE;
        }
        else if (axutil_strcmp(AXIOM_SOAP11_SOAP_FAULT_STRING_LOCAL_NAME, ele_localname) == 0)
        {

            axiom_soap_fault_reason_t *fault_reason = NULL;
            axiom_soap_fault_text_t *fault_text = NULL;
            axiom_node_t *fault_text_node = NULL;
            int status = AXIS2_SUCCESS;
            if (builder_helper->fault_code_present)
            {
                axiom_soap_builder_set_bool_processing_mandatory_fault_elements(
                    builder_helper->soap_builder, env, AXIS2_FALSE);
            }

            axiom_element_set_localname(om_ele, env, AXIOM_SOAP12_SOAP_FAULT_REASON_LOCAL_NAME);

            fault_reason = axiom_soap_fault_reason_create(env);
            if (!fault_reason)
                return AXIS2_FAILURE;

            axiom_soap_fault_reason_set_base_node(fault_reason, env, om_element_node);

            axiom_soap_fault_set_reason(soap_fault, env, fault_reason);

            fault_text = axiom_soap_fault_text_create_with_parent(env, fault_reason);
            if (!fault_text)
                return AXIS2_FAILURE;

            fault_text_node = axiom_soap_fault_text_get_base_node(fault_text, env);
            if (!fault_text_node)
                return AXIS2_FAILURE;

            axiom_stax_builder_set_lastnode(builder_helper->om_builder, env, fault_text_node);

            status = axiom_soap11_builder_helper_process_text(builder_helper, env);
            if (status == AXIS2_FAILURE)
                return AXIS2_FAILURE;

            axiom_stax_builder_set_lastnode(builder_helper->om_builder, env, om_element_node);

            axiom_node_set_complete(om_element_node, env, AXIS2_TRUE);

            axiom_stax_builder_set_element_level(builder_helper->om_builder,
                    env , (element_level - 1));

            builder_helper->fault_string_present = AXIS2_TRUE;

        }
        else if (axutil_strcmp(AXIOM_SOAP11_SOAP_FAULT_ACTOR_LOCAL_NAME, ele_localname) == 0)
        {
            axiom_soap_fault_role_t *fault_role = NULL;
            fault_role = axiom_soap_fault_role_create(env);
            if (!fault_role)
                return AXIS2_FAILURE;

            axiom_element_set_localname(om_ele, env, AXIOM_SOAP12_SOAP_FAULT_ROLE_LOCAL_NAME);

            axiom_soap_fault_role_set_base_node(fault_role, env, om_element_node);

            axiom_soap_fault_set_role(soap_fault, env, fault_role);
            /*
            Role element may not have a namespace associated, hence commented, else it segfaults here - Samisa
            status = axiom_soap_builder_process_namespace_data(
                builder_helper->soap_builder, env, om_element_node, AXIS2_TRUE);
            if(status == AXIS2_FAILURE)
                    return AXIS2_FAILURE;*/
        }
        else if (axutil_strcmp(AXIOM_SOAP11_SOAP_FAULT_DETAIL_LOCAL_NAME, ele_localname) == 0)
        {
            axiom_soap_fault_detail_t *fault_detail = NULL;
            fault_detail = axiom_soap_fault_detail_create(env);
            if (!fault_detail)
                return AXIS2_FAILURE;

            axiom_element_set_localname(om_ele, env, AXIOM_SOAP12_SOAP_FAULT_DETAIL_LOCAL_NAME);

            axiom_soap_fault_detail_set_base_node(fault_detail, env, om_element_node);

            axiom_soap_fault_set_detail(soap_fault, env, fault_detail);
        }
        else
        {
            return AXIS2_SUCCESS;
        }
    }
    else if (element_level == 5)
    {
        axiom_node_t *parent_node = NULL;
        axiom_element_t *parent_element = NULL;
        axis2_char_t *parent_localname = NULL;

        parent_node = axiom_node_get_parent(om_element_node, env);
        if (!parent_node)
            return AXIS2_FAILURE;
        parent_element = (axiom_element_t *)axiom_node_get_data_element(
                    om_element_node, env);
        parent_localname = axiom_element_get_localname(parent_element, env);

        if (!parent_localname)
            return AXIS2_FAILURE;
        if (axutil_strcmp(parent_localname, AXIOM_SOAP12_SOAP_FAULT_ROLE_LOCAL_NAME) == 0)
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_SOAP11_FAULT_ACTOR_SHOULD_NOT_HAVE_CHILD_ELEMENTS, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    return AXIS2_SUCCESS;
}

static axis2_status_t
axiom_soap11_builder_helper_process_text(axiom_soap11_builder_helper_t *builder_helper,
        const axutil_env_t *env)
{
    int token = 0;

    token = axiom_stax_builder_next_with_token(builder_helper->om_builder, env);

    if (token == -1)
        return AXIS2_FAILURE;

    while (token != AXIOM_XML_READER_END_ELEMENT)
    {
        if (token != AXIOM_XML_READER_CHARACTER)
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_ONLY_CHARACTERS_ARE_ALLOWED_HERE, AXIS2_FAILURE);
            return AXIS2_FAILURE;

        }
        token = axiom_stax_builder_next_with_token(builder_helper->om_builder, env);
        if (token == -1)
            return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}
