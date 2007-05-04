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
#include "_axiom_soap_fault.h"
#include <axiom_soap_const.h>
#include "_axiom_soap_body.h"
#include <axiom_node.h>
#include <axiom_element.h>
#include <axiom_soap_fault_code.h>
#include <axiom_soap_fault_detail.h>
#include <axiom_soap_fault_value.h>
#include <axiom_soap_fault_text.h>
#include <axiom_soap_fault_reason.h>
#include <axiom_soap_fault_role.h>
#include <axiom_soap_fault_node.h>
#include <axiom_soap_builder.h>

struct axiom_soap_fault
{
    /* om element node corresponding to soap soap_fault */
    axiom_node_t *om_ele_node;

    /* soap soap_fault code sub element */
    axiom_soap_fault_code_t *fcode;
    /* soap soap_fault reason sub element */
    axiom_soap_fault_reason_t *freason;
    /* soap soap_fault node sub element */
    axiom_soap_fault_node_t *fnode;
    /* soap soap_fault role sub element */
    axiom_soap_fault_role_t *frole;
    /* soap soap_fault detail sub element */
    axiom_soap_fault_detail_t *fdetail;

    axis2_char_t *exception;
    /* reference to soap builder */
    axiom_soap_builder_t *soap_builder;

    int soap_version;
};

AXIS2_EXTERN axiom_soap_fault_t * AXIS2_CALL
axiom_soap_fault_create(const axutil_env_t *env)
{
    axiom_soap_fault_t *soap_fault = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    soap_fault = (axiom_soap_fault_t*)AXIS2_MALLOC(
                env->allocator,
                sizeof(axiom_soap_fault_t));
    if (!soap_fault)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    soap_fault->exception = NULL;
    soap_fault->fcode = NULL;
    soap_fault->fdetail = NULL;
    soap_fault->fnode = NULL;
    soap_fault->freason = NULL;
    soap_fault->frole = NULL;
    soap_fault->om_ele_node = NULL;
    soap_fault->soap_builder = NULL;
    return soap_fault;
}


AXIS2_EXTERN axiom_soap_fault_t * AXIS2_CALL
axiom_soap_fault_create_with_parent(const axutil_env_t *env,
        axiom_soap_body_t *body)
{
    axiom_soap_fault_t *soap_fault = NULL;
    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;
    axiom_namespace_t *parent_ns = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, body, NULL);

    soap_fault = axiom_soap_fault_create(env);
    if (!soap_fault)
        return NULL;

    parent_node = axiom_soap_body_get_base_node(body, env);
    if (!parent_node)
    {
        AXIS2_FREE(env->allocator, soap_fault);
        return NULL;
    }
    soap_fault->soap_version =
        axiom_soap_body_get_soap_version(body, env);

    parent_ele  = (axiom_element_t *)axiom_node_get_data_element(
                parent_node, env);
    if (!parent_ele)
    {
        AXIS2_FREE(env->allocator, soap_fault);
        return NULL;
    }
    parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);

    this_ele = axiom_element_create(env,
            parent_node,
            AXIOM_SOAP_FAULT_LOCAL_NAME,
            parent_ns,
            &this_node);
    if (!this_ele)
    {
        AXIS2_FREE(env->allocator, soap_fault);
        return NULL;
    }

    soap_fault->om_ele_node = this_node;
    axiom_soap_body_set_fault(body, env, soap_fault);
    return  soap_fault;
}


AXIS2_EXTERN axiom_soap_fault_t * AXIS2_CALL
axiom_soap_fault_create_with_exception(const axutil_env_t *env,
        axiom_soap_body_t *body,
        axis2_char_t* exception)
{
    axiom_soap_fault_t *soap_fault = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, body, NULL);
    AXIS2_PARAM_CHECK(env->error, exception, NULL);
    soap_fault = axiom_soap_fault_create_with_parent(env, body);
    if (!soap_fault)
        return NULL;
    status = axiom_soap_fault_set_exception(soap_fault, env, exception);
    if (status == AXIS2_FAILURE)
    {
        axiom_soap_fault_free(soap_fault, env);
        return NULL;
    }
    return soap_fault;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_soap_fault_free(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (soap_fault->fcode)
    {
        axiom_soap_fault_code_free(soap_fault->fcode, env);
        soap_fault->fcode = NULL;
    }
    if (soap_fault->fdetail)
    {
        axiom_soap_fault_detail_free(soap_fault->fdetail, env);
        soap_fault->fdetail = NULL;
    }
    if (soap_fault->fnode)
    {
        axiom_soap_fault_node_free(soap_fault->fnode, env);
        soap_fault->fnode = NULL;
    }
    if (soap_fault->freason)
    {
        axiom_soap_fault_reason_free(soap_fault->freason, env);
        soap_fault->freason = NULL;
    }
    if (soap_fault->frole)
    {
        axiom_soap_fault_role_free(soap_fault->frole, env);
        soap_fault->frole = NULL;
    }
    AXIS2_FREE(env->allocator, soap_fault);
    soap_fault = NULL;
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_code(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env,
        axiom_soap_fault_code_t *code)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, code, AXIS2_FAILURE);
    if (!(soap_fault->fcode))
    {
        soap_fault->fcode = code;
        return AXIS2_SUCCESS;
    }
    else
    {
        AXIS2_LOG_DEBUG(env->log,
                AXIS2_LOG_SI, "tring to set multiple code elements to soap_fault ");

    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_soap_fault_code_t * AXIS2_CALL
axiom_soap_fault_get_code(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);
    if (soap_fault->fcode)
    {
        return soap_fault->fcode;
    }
    else if (soap_fault->soap_builder)
    {
        while (!(soap_fault->fcode) && !(axiom_node_is_complete(soap_fault->om_ele_node, env)))
        {
            status = axiom_soap_builder_next(soap_fault->soap_builder, env);
            if (status == AXIS2_FAILURE)
                break;
        }
    }
    return soap_fault->fcode;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_reason(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env,
        axiom_soap_fault_reason_t *reason)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, reason, AXIS2_FAILURE);
    if (!(soap_fault->freason))
    {
        soap_fault->freason = reason;
        return AXIS2_SUCCESS;
    }
    else
    {
        AXIS2_LOG_DEBUG(env->log,
                AXIS2_LOG_SI, "tring to set soap_fault reason twice");
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axiom_soap_fault_reason_t* AXIS2_CALL
axiom_soap_fault_get_reason(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);
    if (soap_fault->freason)
    {
        return soap_fault->freason;
    }
    else if (soap_fault->soap_builder)
    {
        while (!(soap_fault->freason) && !(axiom_node_is_complete(soap_fault->om_ele_node, env)))
        {
            status = axiom_soap_builder_next(soap_fault->soap_builder, env);
            if (status == AXIS2_FAILURE)
                break;
        }
    }
    return soap_fault->freason;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_node(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env,
        axiom_soap_fault_node_t *node)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, node, AXIS2_FAILURE);
    if (!(soap_fault->fnode))
    {
        soap_fault->fnode = node;
        return AXIS2_SUCCESS;
    }
    else
    {
        AXIS2_LOG_DEBUG(env->log,
                AXIS2_LOG_SI, "tring to set soap_fault node more than once");
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axiom_soap_fault_node_t* AXIS2_CALL
axiom_soap_fault_get_node(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);

    if (soap_fault->fnode)
    {
        return soap_fault->fnode;
    }
    else if (soap_fault->soap_builder)
    {
        while (!(soap_fault->fnode) && !(axiom_node_is_complete(soap_fault->om_ele_node, env)))
        {
            status = axiom_soap_builder_next(soap_fault->soap_builder, env);
            if (status == AXIS2_FAILURE)
                break;
        }
    }
    return soap_fault->fnode;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_role(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env,
        axiom_soap_fault_role_t *role)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, role, AXIS2_FAILURE);

    if (!(soap_fault->frole))
    {
        soap_fault->frole = role;
        return AXIS2_FAILURE;
    }
    else
    {
        AXIS2_LOG_DEBUG(env->log,
                AXIS2_LOG_SI, "tring to set soap_fault role more than once ");
    }
    return AXIS2_FAILURE;

}

AXIS2_EXTERN axiom_soap_fault_role_t* AXIS2_CALL
axiom_soap_fault_get_role(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);
    if (soap_fault->frole)
    {
        return soap_fault->frole;
    }
    else if (soap_fault->soap_builder)
    {
        while (!(soap_fault->frole) && !(axiom_node_is_complete(soap_fault->om_ele_node, env)))
        {
            status = axiom_soap_builder_next(soap_fault->soap_builder, env);
            if (status == AXIS2_FAILURE)
                break;
        }
    }
    return soap_fault->frole;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_detail(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env,
        axiom_soap_fault_detail_t *detail)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, detail, AXIS2_FAILURE);

    if (!(soap_fault->fdetail))
    {
        soap_fault->fdetail = detail;
        return AXIS2_SUCCESS;
    }
    else
    {
        AXIS2_LOG_DEBUG(env->log,
                AXIS2_LOG_SI, " tring to set soap_fault detail more than once");

    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axiom_soap_fault_detail_t* AXIS2_CALL
axiom_soap_fault_get_detail(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);
    if (soap_fault->fdetail)
    {
        return soap_fault->fdetail;
    }
    else if (soap_fault->soap_builder)
    {
        while (!(soap_fault->fdetail) && !(axiom_node_is_complete(soap_fault->om_ele_node, env)))
        {
            status = axiom_soap_builder_next(soap_fault->soap_builder, env);
            if (status == AXIS2_FAILURE)
                break;
        }
    }
    return soap_fault->fdetail;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_base_node(axiom_soap_fault_t *soap_fault,
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
    soap_fault->om_ele_node = node;
    return AXIS2_SUCCESS;

}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_fault_get_base_node(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return soap_fault->om_ele_node;
}


AXIS2_EXTERN axis2_char_t * AXIS2_CALL
axiom_soap_fault_get_exception(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    axiom_soap_fault_detail_t *detail = NULL;
    axiom_node_t *detail_node = NULL;
    axiom_element_t *detail_ele = NULL;
    axiom_node_t *exception_node = NULL;
    axiom_element_t *exception_ele = NULL;
    axutil_qname_t *qn = NULL;
    axis2_char_t *excep = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    detail = axiom_soap_fault_get_detail(soap_fault, env);
    if (!detail)
        return NULL;
    detail_node = axiom_soap_fault_detail_get_base_node(detail, env);
    if (detail_node)
    {
        detail_ele = (axiom_element_t *)axiom_node_get_data_element(
                    detail_node, env);

        qn = axutil_qname_create(env,
                AXIOM_SOAP_FAULT_DETAIL_EXCEPTION_ENTRY, NULL, NULL);
        if (qn)
        {
            exception_ele = axiom_element_get_first_child_with_qname(
                        detail_ele, env,
                        qn, detail_node, &exception_node);
            axutil_qname_free(qn, env);
            if (exception_ele &&
                    (excep = axiom_element_get_text(exception_ele, env, exception_node)))
            {
                return excep;
            }
        }
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_exception(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env,
        axis2_char_t *exception)
{
    axiom_soap_fault_detail_t *detail = NULL;
    axiom_node_t *fault_detail_entry_node = NULL;
    axiom_element_t *fault_detail_ele = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIS2_PARAM_CHECK(env->error, exception, AXIS2_FAILURE);

    detail = axiom_soap_fault_get_detail(soap_fault, env);

    if (!detail)
    {
        detail = axiom_soap_fault_detail_create_with_parent(env, soap_fault);
        if (!detail)
            return AXIS2_FAILURE;
    }
    /** create an om element with the exception enrty */

    fault_detail_ele = axiom_element_create(env, NULL,
            AXIOM_SOAP_FAULT_DETAIL_EXCEPTION_ENTRY,
            NULL, &fault_detail_entry_node);
    if (!fault_detail_ele)
    {
        return AXIS2_FAILURE;
    }
    /** set the exception string as a text node of newly created om element */
    axiom_element_set_text(fault_detail_ele,
            env, exception, fault_detail_entry_node);
    /** now add this om element as a child of soap soap_fault detail om element node */
    return axiom_soap_fault_detail_add_detail_entry(detail, env, fault_detail_entry_node);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_builder(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env,
        axiom_soap_builder_t *builder)
{
    AXIS2_PARAM_CHECK(env->error, builder, AXIS2_FAILURE);
    soap_fault->soap_builder = builder;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_soap_fault_t * AXIS2_CALL
axiom_soap_fault_create_default_fault(const axutil_env_t *env,
        struct axiom_soap_body *parent,
        const axis2_char_t *code_value,
        const axis2_char_t *reason_text,
        const int soap_version)
{
    axiom_soap_fault_t *soap_fault = NULL;
    axiom_node_t *fault_node    = NULL;

    axiom_soap_fault_code_t *soap_fault_code = NULL;
    axiom_soap_fault_value_t *soap_fault_value = NULL;

    axiom_soap_fault_reason_t *soap_fault_reason = NULL;
    axiom_soap_fault_text_t *soap_fault_text = NULL;

    axiom_node_t *value_node  = NULL;
    axiom_element_t *value_ele = NULL;

    axiom_node_t *text_node = NULL;
    axiom_element_t *text_ele = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, code_value, NULL);
    AXIS2_PARAM_CHECK(env->error, reason_text, NULL);

    soap_fault = axiom_soap_fault_create_with_parent(env, parent);
    if (!soap_fault)
        return NULL;
    fault_node = axiom_soap_fault_get_base_node(soap_fault, env);
    if (!fault_node)
    {
        axiom_soap_fault_free(soap_fault, env);
        return NULL;
    }

    soap_fault_code = axiom_soap_fault_code_create_with_parent(env, soap_fault);
    if (!soap_fault_code)
    {
        axiom_soap_fault_free(soap_fault, env);
        axiom_node_free_tree(fault_node, env);
        return NULL;
    }
    soap_fault_reason = axiom_soap_fault_reason_create_with_parent(env, soap_fault);
    if (!soap_fault_reason)
    {
        axiom_soap_fault_free(soap_fault, env);
        axiom_node_free_tree(fault_node, env);
        return NULL;
    }

    soap_fault_value = axiom_soap_fault_value_create_with_code(env, soap_fault_code);
    if (!soap_fault_value)
    {
        axiom_soap_fault_free(soap_fault, env);
        axiom_node_free_tree(fault_node, env);
        return NULL;
    }

    value_node = axiom_soap_fault_value_get_base_node(soap_fault_value, env);
    if (!value_node)
    {
        return NULL;
    }
    value_ele  = (axiom_element_t *)axiom_node_get_data_element(value_node, env);

    axiom_element_set_text(value_ele, env, code_value, value_node);

    soap_fault_text = axiom_soap_fault_text_create_with_parent(env, soap_fault_reason);
    if (!soap_fault_text)
    {
        axiom_soap_fault_free(soap_fault, env);
        axiom_node_free_tree(fault_node, env);
        return NULL;
    }
    axiom_soap_fault_text_set_lang(soap_fault_text, env, "en");

    text_node = axiom_soap_fault_text_get_base_node(soap_fault_text, env);
    if (!text_node)
    {
        return NULL;
    }
    text_ele  = (axiom_element_t *)axiom_node_get_data_element(text_node, env);

    axiom_element_set_text(text_ele, env, reason_text, text_node);

    return soap_fault;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_set_soap_version(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env,
        int soap_version)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    soap_fault->soap_version = soap_version;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axiom_soap_fault_get_soap_version(axiom_soap_fault_t *soap_fault,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return soap_fault->soap_version;
}

