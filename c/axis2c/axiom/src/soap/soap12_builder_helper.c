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

#include "axiom_soap12_builder_helper.h"
#include <axutil_array_list.h>
#include "_axiom_soap_body.h"
#include "_axiom_soap_fault.h"
#include "_axiom_soap_envelope.h"
#include "_axiom_soap_fault_code.h"
#include "_axiom_soap_fault_sub_code.h"
#include "_axiom_soap_fault_node.h"
#include "_axiom_soap_fault_detail.h"
#include "_axiom_soap_fault_reason.h"
#include "_axiom_soap_fault_role.h"
#include "_axiom_soap_fault_value.h"
#include "_axiom_soap_fault_text.h"

struct axiom_soap12_builder_helper
{
    axiom_soap_builder_t *soap_builder;

    axis2_bool_t code_present;

    axis2_bool_t reason_present;

    axis2_bool_t node_present;

    axis2_bool_t role_present;

    axis2_bool_t detail_present;

    axis2_bool_t subcode_value_present;

    axis2_bool_t value_present;

    axis2_bool_t sub_code_present;

    axis2_bool_t sub_sub_code_present;

    axis2_bool_t code_processing;

    axis2_bool_t sub_code_processing;

    axis2_bool_t reason_processing;

    axutil_array_list_t *detail_element_names;
};

AXIS2_EXTERN axiom_soap12_builder_helper_t* AXIS2_CALL
axiom_soap12_builder_helper_create(const axutil_env_t *env,
        axiom_soap_builder_t *soap_builder)
{
    axiom_soap12_builder_helper_t *builder_helper = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, soap_builder, NULL);

    builder_helper = (axiom_soap12_builder_helper_t*)AXIS2_MALLOC(
                env->allocator, sizeof(axiom_soap12_builder_helper_t));
    if (!builder_helper)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    builder_helper->code_present = AXIS2_FALSE;
    builder_helper->detail_present = AXIS2_FALSE;
    builder_helper->reason_present = AXIS2_FALSE;
    builder_helper->role_present = AXIS2_FALSE;
    builder_helper->sub_code_present = AXIS2_FALSE;
    builder_helper->reason_processing = AXIS2_FALSE;
    builder_helper->code_processing = AXIS2_FALSE;
    builder_helper->sub_code_processing = AXIS2_FALSE;
    builder_helper->detail_element_names = NULL;
    builder_helper->node_present = AXIS2_FALSE;
    builder_helper->soap_builder = soap_builder;
    builder_helper->sub_sub_code_present = AXIS2_FALSE;
    builder_helper->value_present = AXIS2_FALSE;
    builder_helper->subcode_value_present = AXIS2_FALSE;

    return builder_helper;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_soap12_builder_helper_free(axiom_soap12_builder_helper_t *builder_helper,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (builder_helper->detail_element_names)
    {
        axutil_array_list_free(builder_helper->detail_element_names, env);
        builder_helper->detail_element_names = NULL;
    }

    AXIS2_FREE(env->allocator, builder_helper);
    builder_helper = NULL;
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap12_builder_helper_handle_event(axiom_soap12_builder_helper_t *builder_helper,
        const axutil_env_t *env,
        axiom_node_t *om_ele_node,
        int element_level)
{
    axis2_char_t* ele_localname = NULL;
    axiom_element_t *om_ele = NULL;

    axiom_soap_body_t *soap_body = NULL;
    axiom_soap_fault_t *soap_fault = NULL;
    axiom_soap_envelope_t *soap_envelope = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_ele_node, AXIS2_FAILURE);

    om_ele = (axiom_element_t *)axiom_node_get_data_element(om_ele_node, env);
    if (!om_ele)
        return AXIS2_FAILURE;

    ele_localname = axiom_element_get_localname(om_ele, env);
    if (!ele_localname)
        return AXIS2_FAILURE;

    soap_envelope = axiom_soap_builder_get_soap_envelope(builder_helper->soap_builder, env);
    if (!soap_envelope)
        return AXIS2_FAILURE;

    soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
    if (!soap_body)
        return AXIS2_FAILURE;

    soap_fault = axiom_soap_body_get_fault(soap_body, env);
    if (!soap_fault)
        return AXIS2_FAILURE;

    if (element_level == 4)
    {
        if (axutil_strcmp(AXIOM_SOAP12_SOAP_FAULT_CODE_LOCAL_NAME, ele_localname) == 0)
        {
            if (builder_helper->code_present)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MULTIPLE_CODE_ELEMENTS_ENCOUNTERED, AXIS2_FAILURE);

                return AXIS2_FAILURE;
            }
            else
            {
                axiom_soap_fault_code_t* soap_fault_code = NULL;
                soap_fault_code = axiom_soap_fault_code_create(env);
                if (!soap_fault_code)
                    return AXIS2_FAILURE;

                axiom_soap_fault_code_set_base_node(soap_fault_code , env, om_ele_node);


                axiom_soap_fault_code_set_builder(soap_fault_code, env,
                        builder_helper->soap_builder);

                axiom_soap_fault_set_code(soap_fault, env, soap_fault_code);

                builder_helper->code_present = AXIS2_TRUE;
                builder_helper->code_processing = AXIS2_TRUE;
            }
        }
        else if (axutil_strcmp(AXIOM_SOAP12_SOAP_FAULT_REASON_LOCAL_NAME, ele_localname) == 0)
        {
            if (!(builder_helper->code_processing) && !(builder_helper->sub_code_processing))
            {
                if (builder_helper->code_present)
                {
                    if (builder_helper->reason_present)
                    {
                        AXIS2_ERROR_SET(env->error,
                                AXIS2_ERROR_MULTIPLE_REASON_ELEMENTS_ENCOUNTERED, AXIS2_FAILURE);

                        return AXIS2_FAILURE;
                    }
                    else
                    {
                        axiom_soap_fault_reason_t *fault_reason = NULL;
                        fault_reason = axiom_soap_fault_reason_create(env);
                        if (!fault_reason)
                            return AXIS2_FAILURE;

                        axiom_soap_fault_reason_set_base_node(fault_reason, env, om_ele_node);

                        axiom_soap_fault_set_reason(soap_fault, env, fault_reason);

                        axiom_soap_fault_reason_set_builder(fault_reason , env,
                                builder_helper->soap_builder);

                        builder_helper->reason_present = AXIS2_TRUE;
                        builder_helper->reason_processing = AXIS2_TRUE;
                    }
                }
                else
                {
                    AXIS2_ERROR_SET(env->error,
                            AXIS2_ERROR_WRONG_ELEMENT_ORDER_ENCOUNTERED, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
            }
            else
            {
                if (builder_helper->code_processing)
                {
                    AXIS2_ERROR_SET(env->error,
                            AXIS2_ERROR_SOAP_FAULT_CODE_DOES_NOT_HAVE_A_VALUE, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
                else
                {
                    AXIS2_ERROR_SET(env->error,
                            AXIS2_ERROR_SOAP_FAULT_CODE_DOES_NOT_HAVE_A_VALUE, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
            }
        }
        else if (axutil_strcmp(ele_localname, AXIOM_SOAP12_SOAP_FAULT_NODE_LOCAL_NAME) == 0)
        {
            if (!(builder_helper->reason_processing))
            {
                if (builder_helper->reason_present &&
                        !(builder_helper->role_present) &&
                        !(builder_helper->detail_present))
                {
                    if (builder_helper->node_present)
                    {
                        AXIS2_ERROR_SET(env->error,
                                AXIS2_ERROR_MULTIPLE_NODE_ELEMENTS_ENCOUNTERED, AXIS2_FAILURE);
                        return AXIS2_FAILURE;
                    }
                    else
                    {
                        axiom_soap_fault_node_t *soap_fault_node = NULL;
                        soap_fault_node = axiom_soap_fault_node_create(env);
                        if (!soap_fault_node)
                            return AXIS2_FAILURE;

                        axiom_soap_fault_node_set_base_node(soap_fault_node, env, om_ele_node);

                        axiom_soap_fault_set_node(soap_fault, env, soap_fault_node);

                        builder_helper->node_present = AXIS2_TRUE;
                    }
                }
                else
                {
                    AXIS2_ERROR_SET(env->error,
                            AXIS2_ERROR_WRONG_ELEMENT_ORDER_ENCOUNTERED, AXIS2_FALSE);


                    return AXIS2_FAILURE;
                }
            }
            else
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_SOAP_FAULT_REASON_ELEMENT_SHOULD_HAVE_A_TEXT, AXIS2_FALSE);
                return AXIS2_FAILURE;
            }

        }
        else if (axutil_strcmp(ele_localname, AXIOM_SOAP12_SOAP_FAULT_ROLE_LOCAL_NAME) == 0)
        {
            if (!(builder_helper->reason_processing))
            {
                if (builder_helper->reason_present && !(builder_helper->detail_present))
                {
                    if (builder_helper->role_present)
                    {
                        AXIS2_ERROR_SET(env->error,
                                AXIS2_ERROR_MULTIPLE_ROLE_ELEMENTS_ENCOUNTERED, AXIS2_FAILURE);

                        return AXIS2_FAILURE;
                    }
                    else
                    {
                        axiom_soap_fault_role_t *soap_fault_role = NULL;
                        soap_fault_role = axiom_soap_fault_role_create(env);
                        if (!soap_fault_role)
                            return AXIS2_FAILURE;

                        axiom_soap_fault_role_set_base_node(soap_fault_role, env, om_ele_node);

                        axiom_soap_fault_set_role(soap_fault, env, soap_fault_role);
                        builder_helper->role_present = AXIS2_TRUE;
                    }
                }
                else
                {
                    AXIS2_ERROR_SET(env->error,
                            AXIS2_ERROR_WRONG_ELEMENT_ORDER_ENCOUNTERED, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
            }
            else
            {

                AXIS2_ERROR_SET(env->error,  AXIS2_ERROR_SOAP_FAULT_ROLE_ELEMENT_SHOULD_HAVE_A_TEXT, AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
        }
        else if (axutil_strcmp(ele_localname, AXIOM_SOAP12_SOAP_FAULT_DETAIL_LOCAL_NAME) == 0)
        {
            if (!(builder_helper->reason_processing))
            {
                if (builder_helper->reason_present)
                {
                    if (builder_helper->detail_present)
                    {
                        AXIS2_ERROR_SET(env->error,
                                AXIS2_ERROR_MULTIPLE_DETAIL_ELEMENTS_ENCOUNTERED, AXIS2_FAILURE);
                        return AXIS2_FAILURE;
                    }
                    else
                    {

                        axiom_soap_fault_detail_t *soap_fault_detail = NULL;
                        soap_fault_detail = axiom_soap_fault_detail_create(env);
                        if (!soap_fault_detail)
                            return AXIS2_FAILURE;

                        axiom_soap_fault_detail_set_base_node(soap_fault_detail, env, om_ele_node);

                        axiom_soap_fault_set_detail(soap_fault, env, soap_fault_detail);
                        builder_helper->detail_present = AXIS2_TRUE;
                    }
                }
                else
                {
                    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRONG_ELEMENT_ORDER_ENCOUNTERED, AXIS2_FAILURE);

                    return AXIS2_FAILURE;

                }
            }
            else
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_SOAP_FAULT_REASON_ELEMENT_SHOULD_HAVE_A_TEXT, AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }

        }
        else
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_UNSUPPORTED_ELEMENT_IN_SOAP_FAULT_ELEMENT, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    else if (element_level == 5)
    {
        axiom_node_t *parent_node = NULL;
        axiom_element_t *parent_ele = NULL;
        axis2_char_t *parent_localname = NULL;
        parent_node = axiom_node_get_parent(om_ele_node, env);
        if (!parent_node)
            return AXIS2_FAILURE;

        parent_ele = (axiom_element_t *)axiom_node_get_data_element(parent_node, env);
        if (!parent_ele)
            return AXIS2_FAILURE;

        parent_localname = axiom_element_get_localname(parent_ele, env);
        if (!parent_localname)
            return AXIS2_FAILURE;

        if (axutil_strcmp(parent_localname,
                AXIOM_SOAP12_SOAP_FAULT_CODE_LOCAL_NAME) == 0)
        {
            if (axutil_strcmp(ele_localname, AXIOM_SOAP12_SOAP_FAULT_VALUE_LOCAL_NAME) == 0)
            {
                if (!(builder_helper->value_present))
                {
                    axiom_soap_fault_value_t *soap_fault_value = NULL;
                    axiom_soap_fault_code_t *parent_fcode = NULL;

                    soap_fault_value = axiom_soap_fault_value_create(env);
                    if (!soap_fault_value)
                        return AXIS2_FAILURE;

                    axiom_soap_fault_value_set_base_node(soap_fault_value, env, om_ele_node);

                    parent_fcode = axiom_soap_fault_get_code(soap_fault, env);
                    if (!parent_fcode)
                        return AXIS2_FAILURE;

                    axiom_soap_fault_code_set_value(parent_fcode, env, soap_fault_value);

                    builder_helper->value_present = AXIS2_TRUE;
                    builder_helper->code_processing = AXIS2_FALSE;

                }
                else
                {
                    AXIS2_ERROR_SET(env->error,
                            AXIS2_ERROR_MULTIPLE_VALUE_ENCOUNTERED_IN_CODE_ELEMENT, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
            }
            else if (axutil_strcmp(ele_localname,
                    AXIOM_SOAP12_SOAP_FAULT_SUB_CODE_LOCAL_NAME) == 0)
            {
                if (!(builder_helper->sub_code_present))
                {
                    if (builder_helper->value_present)
                    {

                        axiom_soap_fault_sub_code_t *fault_subcode = NULL;
                        axiom_soap_fault_code_t *fault_code = NULL;

                        fault_subcode = axiom_soap_fault_sub_code_create(env);
                        if (!fault_subcode)
                            return AXIS2_FAILURE;

                        axiom_soap_fault_sub_code_set_base_node(fault_subcode, env, om_ele_node);


                        fault_code = axiom_soap_fault_get_code(soap_fault, env);
                        if (!fault_code)
                            return AXIS2_FAILURE;

                        axiom_soap_fault_code_set_sub_code(fault_code, env, fault_subcode);

                        axiom_soap_fault_sub_code_set_builder(fault_subcode, env,
                                builder_helper->soap_builder);

                        builder_helper->sub_code_present = AXIS2_TRUE;
                        builder_helper->sub_code_processing = AXIS2_TRUE;
                    }
                    else
                    {
                        AXIS2_ERROR_SET(env->error,
                                AXIS2_ERROR_SOAP_FAULT_VALUE_SHOULD_BE_PRESENT_BEFORE_SUB_CODE, AXIS2_FAILURE);
                        return AXIS2_FAILURE;
                    }
                }
                else
                {
                    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MULTIPLE_SUB_CODE_VALUES_ENCOUNTERED, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
            }
            else
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_THIS_LOCALNAME_NOT_SUPPORTED_INSIDE_THE_CODE_ELEMENT, AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
        }
        else if (axutil_strcmp(parent_localname, AXIOM_SOAP12_SOAP_FAULT_REASON_LOCAL_NAME) == 0)
        {
            if (axutil_strcmp(ele_localname, AXIOM_SOAP12_SOAP_FAULT_TEXT_LOCAL_NAME) == 0)
            {
                axiom_soap_fault_text_t *soap_fault_text = NULL;
                axiom_soap_fault_reason_t *fault_reason = NULL;

                soap_fault_text = axiom_soap_fault_text_create(env);
                if (!soap_fault_text)
                    return AXIS2_FAILURE;

                axiom_soap_fault_text_set_base_node(soap_fault_text, env, om_ele_node);

                fault_reason = axiom_soap_fault_get_reason(soap_fault, env);
                if (!fault_reason)
                    return AXIS2_FAILURE;

                axiom_soap_fault_reason_add_soap_fault_text(fault_reason, env, soap_fault_text);
                builder_helper->reason_processing = AXIS2_FALSE;

                axiom_soap_builder_set_bool_processing_mandatory_fault_elements(builder_helper->soap_builder, env, AXIS2_FALSE);

            }
            else
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_THIS_LOCALNAME_IS_NOT_SUPPORTED_INSIDE_THE_REASON_ELEMENT, AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }

        }
        else if (axutil_strcmp(parent_localname, AXIOM_SOAP12_SOAP_FAULT_DETAIL_LOCAL_NAME) == 0)
        {
            axiom_soap_builder_set_processing_detail_elements(builder_helper->soap_builder, env, AXIS2_TRUE);

            if (!(builder_helper->detail_element_names))
            {
                builder_helper->detail_element_names = axutil_array_list_create(env, 20);
            }

            axutil_array_list_add(builder_helper->detail_element_names, env, ele_localname);

        }
        else
        {

            return AXIS2_FAILURE;
        }

    }
    else if (element_level > 5)
    {
        axiom_node_t *parent_node = NULL;
        axiom_element_t *parent_ele = NULL;
        axis2_char_t *parent_localname = NULL;

        parent_node = axiom_node_get_parent(om_ele_node, env);
        if (!parent_node)
            return AXIS2_FAILURE;

        parent_ele = (axiom_element_t *)axiom_node_get_data_element(parent_node, env);
        if (!parent_ele)
            return AXIS2_FAILURE;

        parent_localname = axiom_element_get_localname(parent_ele, env);
        if (!parent_localname)
            return AXIS2_FAILURE;



        if (axutil_strcmp(parent_localname, AXIOM_SOAP12_SOAP_FAULT_SUB_CODE_LOCAL_NAME) == 0)
        {
            if (axutil_strcmp(ele_localname, AXIOM_SOAP12_SOAP_FAULT_VALUE_LOCAL_NAME) == 0)
            {
                if (builder_helper->subcode_value_present)
                {
                    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MULTIPLE_SUB_CODE_VALUES_ENCOUNTERED, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }
                else
                {

                    axiom_soap_fault_sub_code_t *sub_code = NULL;
                    axiom_soap_fault_code_t *code = NULL;
                    axiom_soap_fault_value_t *value = NULL;
                    code = axiom_soap_fault_get_code(soap_fault, env);

                    if (!code)
                    {
                        AXIS2_LOG_DEBUG(env->log , AXIS2_LOG_SI, "fault code null when it should not be null");
                        return AXIS2_FAILURE;
                    }

                    sub_code = axiom_soap_fault_code_get_sub_code(code, env);
                    if (!sub_code)
                    {
                        AXIS2_LOG_DEBUG(env->log , AXIS2_LOG_SI, "fault subcode null when it should not be null");
                        return AXIS2_FAILURE;
                    }
                    value = axiom_soap_fault_value_create(env);
                    if (!value)
                        return AXIS2_FAILURE;

                    axiom_soap_fault_value_set_base_node(value, env, om_ele_node);

                    axiom_soap_fault_sub_code_set_value(sub_code, env, value);

                    builder_helper->subcode_value_present = AXIS2_TRUE;
                    builder_helper->sub_sub_code_present = AXIS2_FALSE;
                    builder_helper->sub_code_processing = AXIS2_FALSE;
                }
            }
            else if (axutil_strcmp(ele_localname, AXIOM_SOAP12_SOAP_FAULT_SUB_CODE_LOCAL_NAME) == 0)
            {
                if (builder_helper->subcode_value_present)
                {
                    if (!(builder_helper->sub_sub_code_present))
                    {
                        axiom_soap_fault_code_t *fault_code = NULL;
                        axiom_soap_fault_sub_code_t *parent_subcode = NULL;
                        axiom_soap_fault_sub_code_t *subcode = NULL;

                        subcode = axiom_soap_fault_sub_code_create(env);
                        if (!subcode)
                            return AXIS2_FAILURE;

                        axiom_soap_fault_sub_code_set_base_node(subcode, env, om_ele_node);

                        fault_code = axiom_soap_fault_get_code(soap_fault, env);
                        if (!fault_code)
                        {
                            AXIS2_LOG_DEBUG(env->log , AXIS2_LOG_SI, "fault code null when it should not be null");
                            return AXIS2_FAILURE;
                        }
                        parent_subcode = axiom_soap_fault_code_get_sub_code(fault_code, env);
                        if (!parent_subcode)
                        {
                            AXIS2_LOG_DEBUG(env->log , AXIS2_LOG_SI, "fault subcode null when it should not be null");
                            return AXIS2_FAILURE;
                        }

                        axiom_soap_fault_sub_code_set_sub_code(parent_subcode, env, subcode);

                        builder_helper->subcode_value_present = AXIS2_FALSE;
                        builder_helper->sub_sub_code_present = AXIS2_TRUE;
                        builder_helper->sub_code_processing = AXIS2_TRUE;
                    }
                    else
                    {
                        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_MULTIPLE_SUB_CODE_VALUES_ENCOUNTERED, AXIS2_FAILURE);

                        return AXIS2_FAILURE;
                    }
                }
                else
                {
                    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SOAP_FAULT_VALUE_SHOULD_BE_PRESENT_BEFORE_SUB_CODE, AXIS2_FAILURE);

                    return AXIS2_FAILURE;

                }
            }
            else
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_THIS_LOCALNAME_IS_NOT_SUPPORTED_INSIDE_THE_SUB_CODE_ELEMENT, AXIS2_FAILURE);

                return AXIS2_FAILURE;
            }
        }
        else if (axiom_soap_builder_is_processing_detail_elements(builder_helper->soap_builder, env))
        {

            int detail_element_level = 0;
            axis2_bool_t local_name_exists = AXIS2_FALSE;
            int i = 0;
            if (!(builder_helper->detail_element_names))
                return AXIS2_FAILURE;

            for (i = 0; i < axutil_array_list_size(builder_helper->detail_element_names, env) ; i++)
            {
                if (axutil_strcmp(parent_localname, axutil_array_list_get(builder_helper->detail_element_names, env, i)) == 0)
                {
                    local_name_exists = AXIS2_TRUE;
                    detail_element_level = i + 1;
                }
            }
            if (local_name_exists)
            {
                axutil_array_list_add(builder_helper->detail_element_names, env, ele_localname);
            }
            else
            {
                return AXIS2_FAILURE;
            }
        }
    }
    return AXIS2_SUCCESS;
}
