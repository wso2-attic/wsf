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

#include <axiom_soap_fault.h>
#include <axiom_element.h>
#include "_axiom_soap_fault_text.h"
#include "_axiom_soap_fault_reason.h"
#include <axiom_namespace.h>
#include <axutil_qname.h>

struct axiom_soap_fault_text
{
    axiom_attribute_t *lang_attribute;

    axiom_namespace_t *lang_namespace;

    axiom_node_t *om_ele_node;

    axis2_bool_t lang_ns_used;
};

AXIS2_EXTERN axiom_soap_fault_text_t * AXIS2_CALL
axiom_soap_fault_text_create(const axutil_env_t *env)
{
    axiom_soap_fault_text_t *fault_text = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    fault_text = (axiom_soap_fault_text_t*)AXIS2_MALLOC(
                env->allocator,
                sizeof(axiom_soap_fault_text_t));
    if (!fault_text)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    fault_text->om_ele_node = NULL;
    fault_text->lang_attribute = NULL;
    fault_text->lang_namespace = NULL;
    fault_text->lang_ns_used = AXIS2_FALSE;

    fault_text->lang_namespace = axiom_namespace_create(env,
            AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_NS_URI,
            AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_NS_PREFIX);

    if (!(fault_text->lang_namespace))
        return NULL;

    return fault_text;
}



AXIS2_EXTERN axiom_soap_fault_text_t * AXIS2_CALL
axiom_soap_fault_text_create_with_parent(const axutil_env_t *env,
        axiom_soap_fault_reason_t *parent)
{
    axiom_soap_fault_text_t *fault_text = NULL;
    int soap_version = -1;
    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;
    axiom_namespace_t *parent_ns = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, parent, NULL);

    fault_text = axiom_soap_fault_text_create(env);

    if (!fault_text)
    {
        return NULL;
    }

    parent_node = axiom_soap_fault_reason_get_base_node(parent, env);
    if (!parent_node)
    {
        axiom_soap_fault_text_free(fault_text, env);
        return NULL;
    }

    parent_ele  = (axiom_element_t*)
            axiom_node_get_data_element(parent_node, env);
    if (!parent_ele)
    {
        axiom_soap_fault_text_free(fault_text, env);
        return NULL;
    }
    soap_version = axiom_soap_fault_reason_get_soap_version(parent, env);
    if (soap_version == AXIOM_SOAP12)
    {
        parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);
    }
    this_ele = axiom_element_create(env,
            parent_node, AXIOM_SOAP12_SOAP_FAULT_TEXT_LOCAL_NAME,
            parent_ns, &this_node);

    if (!this_ele)
    {
        axiom_soap_fault_text_free(fault_text, env);
        return NULL;
    }

    fault_text->om_ele_node = this_node;

    axiom_soap_fault_reason_add_soap_fault_text(parent, env, fault_text);

    return fault_text;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_soap_fault_text_free(axiom_soap_fault_text_t *fault_text,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (fault_text->lang_ns_used == AXIS2_FALSE && fault_text->lang_namespace)
    {
        axiom_namespace_free(fault_text->lang_namespace, env);
        fault_text->lang_namespace = NULL;
    }
    AXIS2_FREE(env->allocator, fault_text);
    fault_text = NULL;
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_text_set_lang(axiom_soap_fault_text_t *fault_text,
        const axutil_env_t *env,
        const axis2_char_t* lang)
{
    int status = AXIS2_SUCCESS;
    axiom_element_t *om_ele = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, lang, AXIS2_FAILURE);

    if (fault_text->lang_attribute)
    {
        axis2_char_t *attr_lang = NULL;
        attr_lang = axiom_attribute_get_value(fault_text->lang_attribute, env);
        if (attr_lang)
        {
            if (axutil_strcmp(attr_lang, lang) == 0)
            {
                /** this attribute already exists */
                return AXIS2_SUCCESS;
            }
        }
        axiom_attribute_set_value(fault_text->lang_attribute, env, lang);
        return AXIS2_SUCCESS;
    }

    fault_text->lang_attribute = axiom_attribute_create(env,
            AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_LOCAL_NAME,
            lang, fault_text->lang_namespace);
    if (!fault_text->lang_attribute)
        return AXIS2_FAILURE;


    if (!fault_text->om_ele_node)
        return AXIS2_FAILURE;

    om_ele = (axiom_element_t*)axiom_node_get_data_element(fault_text->om_ele_node, env);
    if (!om_ele)
        return AXIS2_FAILURE;

    status = axiom_element_add_attribute(om_ele, env, fault_text->lang_attribute,
            fault_text->om_ele_node);

    if (status == AXIS2_SUCCESS)
        fault_text->lang_ns_used = AXIS2_TRUE;
    else
    {
        axiom_attribute_free(fault_text->lang_attribute, env);
        fault_text->lang_attribute = NULL;
    }
    return status;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_soap_fault_text_get_lang(axiom_soap_fault_text_t *fault_text,
        const axutil_env_t *env)
{
    axiom_element_t* om_ele = NULL;
    axutil_qname_t* tmp_qname = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    if (!fault_text->om_ele_node)
        return NULL;

    om_ele = (axiom_element_t*)
            axiom_node_get_data_element(fault_text->om_ele_node, env);
    if (!om_ele)
        return NULL;

    if (!(fault_text->lang_attribute))
    {

        /* this logic need to be rechecked */
        tmp_qname = axutil_qname_create(env,
                AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_LOCAL_NAME,
                AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_NS_URI,
                AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_NS_PREFIX);

        fault_text->lang_attribute =
            axiom_element_get_attribute(om_ele, env, tmp_qname);
        axutil_qname_free(tmp_qname, env);
    }
    if (fault_text->lang_attribute)
    {
        return axiom_attribute_get_value(fault_text->lang_attribute, env);
    }
    else
        return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_text_set_base_node(axiom_soap_fault_text_t *fault_text,
        const axutil_env_t *env,
        axiom_node_t *node)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, node, AXIS2_FAILURE);

    if (axiom_node_get_node_type(node, env) != AXIOM_ELEMENT)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_BASE_TYPE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    fault_text->om_ele_node = node;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_fault_text_get_base_node(axiom_soap_fault_text_t *fault_text,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return fault_text->om_ele_node;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_text_set_text(axiom_soap_fault_text_t *fault_text,
        const axutil_env_t *env,
        axis2_char_t *value,
        axis2_char_t *lang)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, value, AXIS2_FAILURE);

    if (fault_text->om_ele_node)
    {
        axiom_element_t *text_ele = NULL;
        text_ele = (axiom_element_t *)
                axiom_node_get_data_element(fault_text->om_ele_node, env);
        if (text_ele)
        {
            axiom_element_set_text(text_ele, env, value, fault_text->om_ele_node);
            if (lang)
            {
                axiom_soap_fault_text_set_lang(fault_text, env, lang);
            }
            return AXIS2_SUCCESS;
        }
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_soap_fault_text_get_text(axiom_soap_fault_text_t *fault_text,
        const axutil_env_t *env)
{
    axis2_char_t *text = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    if (fault_text->om_ele_node)
    {
        axiom_element_t *text_ele = NULL;
        text_ele = (axiom_element_t *)
                axiom_node_get_data_element(fault_text->om_ele_node, env);
        if (text_ele)
        {
            text = axiom_element_get_text(text_ele, env,
                    fault_text->om_ele_node);
            return text;
        }
    }
    return NULL;
}


