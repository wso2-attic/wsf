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

#include <axiom_soap_fault_reason.h>
#include "_axiom_soap_fault.h"
#include <axiom_element.h>
#include <axiom_soap_fault_text.h>
#include <axiom_soap_builder.h>
#include <axiom_soap_builder.h>

struct axiom_soap_fault_reason
{
    /* corresponding om element node */
    axiom_node_t *om_ele_node;

    axutil_array_list_t *fault_texts;
    /* pointer to soap builder */
    axiom_soap_builder_t *soap_builder;

    int soap_version;
};

static axis2_bool_t
axiom_soap_fault_reason_lang_exists(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env,
        axis2_char_t *lang);

AXIS2_EXTERN axiom_soap_fault_reason_t * AXIS2_CALL
axiom_soap_fault_reason_create(const axutil_env_t *env)
{
    axiom_soap_fault_reason_t *fault_reason = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    fault_reason = (axiom_soap_fault_reason_t*) AXIS2_MALLOC(
                env->allocator,
                sizeof(axiom_soap_fault_reason_t));
    if (!fault_reason)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    fault_reason->om_ele_node = NULL;
    fault_reason->fault_texts = NULL;

    return  fault_reason;
}

AXIS2_EXTERN axiom_soap_fault_reason_t * AXIS2_CALL
axiom_soap_fault_reason_create_with_parent(const axutil_env_t *env,
        axiom_soap_fault_t *fault)
{
    axiom_soap_fault_reason_t *fault_reason = NULL;
    axiom_element_t *this_ele = NULL;
    axiom_node_t *this_node = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *parent_ele = NULL;
    axiom_namespace_t *parent_ns = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, fault, NULL);

    fault_reason = axiom_soap_fault_reason_create(env);
    if (!fault_reason)
        return NULL;

    parent_node = axiom_soap_fault_get_base_node(fault, env);
    if (!parent_node)
    {
        return NULL;
    }
    parent_ele  = (axiom_element_t *)axiom_node_get_data_element(
                parent_node, env);
    if (!parent_ele)
    {
        return NULL;
    }
    fault_reason->soap_version =
        axiom_soap_fault_get_soap_version(fault, env);
    if (fault_reason->soap_version == AXIOM_SOAP12)
    {
        parent_ns = axiom_element_get_namespace(parent_ele, env, parent_node);
    }
    this_ele = axiom_element_create(env,
            parent_node,
            AXIOM_SOAP12_SOAP_FAULT_REASON_LOCAL_NAME,
            parent_ns,
            &this_node);
    if (!this_ele)
    {
        return NULL;
    }

    fault_reason->om_ele_node = this_node;

    axiom_soap_fault_set_reason(fault, env, fault_reason);
    return  fault_reason;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_soap_fault_reason_free(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (fault_reason->fault_texts)
    {
        int size = 0;
        int i    = 0;
        size = axutil_array_list_size(fault_reason->fault_texts, env);

        for (i = 0  ; i < size; i++)
        {
            axiom_soap_fault_text_t *fault_text = NULL;
            void *value = NULL;
            value = axutil_array_list_get(fault_reason->fault_texts, env, i);
            if (value)
            {
                fault_text = (axiom_soap_fault_text_t *)value;
                axiom_soap_fault_text_free(fault_text, env);
                fault_text = NULL;
            }
        }
        axutil_array_list_free(fault_reason->fault_texts, env);
        fault_reason->fault_texts = NULL;
    }

    AXIS2_FREE(env->allocator, fault_reason);

    fault_reason = NULL;

    return;
}

AXIS2_EXTERN axiom_soap_fault_text_t* AXIS2_CALL
axiom_soap_fault_reason_get_soap_fault_text
(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env,
        axis2_char_t *lang)
{
    int status = AXIS2_SUCCESS;
    int size = 0;
    int i = 0;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, fault_reason, NULL);
    if (!lang || (axutil_strcmp(lang, "") == 0))
        return NULL;

    /** Here we have to build the soap fault reason element completly */
    if (!fault_reason->fault_texts)
    {

        if (fault_reason->soap_builder &&
                !(axiom_node_is_complete(fault_reason->om_ele_node, env)))
        {
            while (!(axiom_node_is_complete(fault_reason->om_ele_node, env)))
            {
                status = axiom_soap_builder_next(fault_reason->soap_builder, env);
                if (status == AXIS2_FAILURE)
                    return NULL;
            }
        }
    }

    if (!fault_reason->fault_texts)
        return NULL;

    /** iterate the array list */
    size = axutil_array_list_size(fault_reason->fault_texts, env);
    for (i = 0; i < size; i++)
    {
        axiom_soap_fault_text_t *fault_text = NULL;
        void *value = NULL;

        value = axutil_array_list_get(fault_reason->fault_texts, env, i);
        if (value)
        {
            axis2_char_t *fault_lang = NULL;
            fault_text = (axiom_soap_fault_text_t *)value;
            fault_lang = axiom_soap_fault_text_get_lang(fault_text, env);
            if (fault_lang && axutil_strcmp(lang, fault_lang) == 0)
            {
                return fault_text;
            }
        }
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_reason_set_base_node
(axiom_soap_fault_reason_t *fault_reason,
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
    fault_reason->om_ele_node = node;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_fault_reason_get_base_node
(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return fault_reason->om_ele_node;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_reason_set_builder(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env,
        axiom_soap_builder_t *builder)
{
    AXIS2_PARAM_CHECK(env->error, builder, AXIS2_FAILURE);

    fault_reason->soap_builder = builder;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
axiom_soap_fault_reason_get_all_soap_fault_texts
(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;

    if (!(fault_reason->fault_texts) && (fault_reason->soap_builder))
    {
        if (!(axiom_node_is_complete(fault_reason->om_ele_node, env)))
        {
            while (!(axiom_node_is_complete(fault_reason->om_ele_node, env)))
            {
                status = axiom_soap_builder_next(fault_reason->soap_builder, env);
                if (status == AXIS2_FAILURE)
                    return NULL;
            }
        }
    }
    return fault_reason->fault_texts;
}


AXIS2_EXTERN axiom_soap_fault_text_t* AXIS2_CALL
axiom_soap_fault_reason_get_first_soap_fault_text
(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;

    if (!(fault_reason->fault_texts) && (fault_reason->soap_builder))
    {
        if (!(axiom_node_is_complete(fault_reason->om_ele_node, env)))
        {
            while (!(axiom_node_is_complete(fault_reason->om_ele_node, env)))
            {
                status = axiom_soap_builder_next(fault_reason->soap_builder, env);
                if (status == AXIS2_FAILURE)
                    return NULL;
            }
        }
    }
    if (fault_reason->fault_texts)
    {
        void *value = NULL;
        value = axutil_array_list_get(fault_reason->fault_texts, env, 0);
        if (value)
            return (axiom_soap_fault_text_t*)value;
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_reason_add_soap_fault_text
(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env,
        axiom_soap_fault_text_t *fault_text)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (!fault_text)
        return AXIS2_FAILURE;

    if (!(fault_reason->fault_texts))
    {
        fault_reason->fault_texts = axutil_array_list_create(env, 1);
        if (!fault_reason->fault_texts)
            return AXIS2_FAILURE;
        axutil_array_list_add(fault_reason->fault_texts, env, fault_text);
    }
    else
    {
        axis2_char_t *lang = NULL;
        axis2_bool_t is_exists = AXIS2_FALSE;
        lang = axiom_soap_fault_text_get_lang(fault_text, env);
        if (lang)
        {
            is_exists = axiom_soap_fault_reason_lang_exists(fault_reason, env, lang);
            if (is_exists == AXIS2_TRUE)
                return AXIS2_FAILURE;
            /** this soap_fault text already exists */
        }
        axutil_array_list_add(fault_reason->fault_texts, env, fault_text);
    }
    return AXIS2_SUCCESS;
}

static axis2_bool_t
axiom_soap_fault_reason_lang_exists(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env,
        axis2_char_t *lang)
{
    int size = 0;
    int i    = 0;


    if (!lang || (axutil_strcmp(lang, "") == 0) || !fault_reason->fault_texts)
        return AXIS2_FALSE;

    size = axutil_array_list_size(fault_reason->fault_texts, env);
    for (i = 0; i < size; i++)
    {
        axiom_soap_fault_text_t *fault_text = NULL;
        void *value = NULL;
        value = axutil_array_list_get(fault_reason->fault_texts, env, i);
        if (value)
        {
            axis2_char_t *text_lang = NULL;
            fault_text = (axiom_soap_fault_text_t *)value;

            text_lang = axiom_soap_fault_text_get_lang(fault_text, env);
            if (text_lang && (axutil_strcmp(lang, text_lang) == 0))
            {
                return AXIS2_TRUE;
            }
        }
    }
    return AXIS2_FALSE;
}
/** internal function */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_reason_set_soap_version(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env,
        int soap_version)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    fault_reason->soap_version = soap_version;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_reason_get_soap_version(axiom_soap_fault_reason_t *fault_reason,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return fault_reason->soap_version;
}

