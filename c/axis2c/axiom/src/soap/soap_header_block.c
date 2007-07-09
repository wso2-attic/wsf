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

#include <axiom_soap_const.h>
#include "_axiom_soap_header_block.h"
#include "_axiom_soap_header.h"
#include <axiom_soap_envelope.h>
#include <axiom_soap_builder.h>

struct axiom_soap_header_block
{
    /** om_element node corresponding to this headerblock */
    axiom_node_t *om_ele_node;
    /** soap version */
    int soap_version;
    axis2_bool_t processed;
};

AXIS2_EXTERN axiom_soap_header_block_t * AXIS2_CALL
axiom_soap_header_block_create(const axutil_env_t *env)
{
    axiom_soap_header_block_t *header_block = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    header_block = (axiom_soap_header_block_t*)AXIS2_MALLOC(
                env->allocator,
                sizeof(axiom_soap_header_block_t));
    if (!header_block)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    header_block->om_ele_node      = NULL;
    header_block->soap_version     = AXIOM_SOAP_VERSION_NOT_SET;
    header_block->processed = AXIS2_FALSE;

    return header_block;
}


AXIS2_EXTERN axiom_soap_header_block_t * AXIS2_CALL
axiom_soap_header_block_create_with_parent(const axutil_env_t *env,
        const axis2_char_t *localname,
        axiom_namespace_t *ns,
        axiom_soap_header_t *header)
{
    axiom_soap_header_block_t *header_block = NULL;
    axiom_node_t *this_node = NULL;
    axiom_node_t *parent_node = NULL;
    axiom_element_t *om_ele = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, localname, NULL);

    header_block = axiom_soap_header_block_create(env);
    if (!header_block)
        return NULL;

    parent_node = axiom_soap_header_get_base_node(header, env);
    if (!parent_node)
        return NULL;

    om_ele = axiom_element_create(env, parent_node, localname,
            ns , &this_node);
    if (!om_ele)
    {
        axiom_soap_header_block_free(header_block, env);
        return NULL;
    }
    header_block->om_ele_node = this_node;

    axiom_soap_header_set_header_block(header, env, header_block);

    header_block->soap_version =
        axiom_soap_header_get_soap_version(header, env);

    return header_block;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_soap_header_block_free(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    AXIS2_FREE(env->allocator, header_block);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_block_set_role(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env,
        axis2_char_t *role_uri)
{
    const axis2_char_t *attr_localname = NULL;
    const axis2_char_t *attr_nsuri     = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (header_block->soap_version == AXIOM_SOAP_VERSION_NOT_SET)
        return AXIS2_FAILURE;
    if (header_block->soap_version == AXIOM_SOAP11)
    {
        attr_localname = AXIOM_SOAP11_ATTR_ACTOR;
        attr_nsuri     = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    if (header_block->soap_version == AXIOM_SOAP12)
    {
        attr_localname = AXIOM_SOAP12_SOAP_ROLE;
        attr_nsuri     = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    axiom_soap_header_block_set_attribute(header_block,
            env, attr_localname, role_uri, attr_nsuri);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_soap_header_block_get_role
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env)
{
    const axis2_char_t *attr_localname = NULL;
    const axis2_char_t *attr_nsuri     = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (header_block->soap_version == AXIOM_SOAP_VERSION_NOT_SET)
        return NULL;
    if (header_block->soap_version == AXIOM_SOAP11)
    {
        attr_localname = AXIOM_SOAP11_ATTR_ACTOR;
        attr_nsuri     = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    if (header_block->soap_version == AXIOM_SOAP12)
    {
        attr_localname = AXIOM_SOAP12_SOAP_ROLE;
        attr_nsuri     = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    return axiom_soap_header_block_get_attribute(header_block, env,
            attr_localname, attr_nsuri);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_block_set_must_understand_with_bool
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env,
        axis2_bool_t must_understand)
{
    const axis2_char_t *attr_nsuri     = NULL;
    const axis2_char_t* attr_value = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (header_block->soap_version == AXIOM_SOAP_VERSION_NOT_SET)
        return AXIS2_FAILURE;

    if (header_block->soap_version == AXIOM_SOAP11)
    {
        attr_nsuri     = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    if (header_block->soap_version == AXIOM_SOAP12)
    {
        attr_nsuri     = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    if (must_understand)
    {
        attr_value = "1";
    }
    else
    {
        attr_value = "0";
    }
    return axiom_soap_header_block_set_attribute(header_block, env,
            AXIOM_SOAP_ATTR_MUST_UNDERSTAND, attr_value, attr_nsuri);

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_block_set_must_understand_with_string
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env,
        axis2_char_t *must_understand)
{
    const axis2_char_t *attr_nsuri     = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, must_understand, AXIS2_FAILURE);

    if (header_block->soap_version == AXIOM_SOAP_VERSION_NOT_SET)
        return AXIS2_FAILURE;

    if (header_block->soap_version == AXIOM_SOAP11)
    {
        attr_nsuri     = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    if (header_block->soap_version == AXIOM_SOAP12)
    {
        attr_nsuri     = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }

    if (axutil_strcmp(AXIOM_SOAP_ATTR_MUST_UNDERSTAND_TRUE, must_understand) == 0 ||
            axutil_strcmp(AXIOM_SOAP_ATTR_MUST_UNDERSTAND_FALSE, must_understand) == 0 ||
            axutil_strcmp(AXIOM_SOAP_ATTR_MUST_UNDERSTAND_0, must_understand) == 0 ||
            axutil_strcmp(AXIOM_SOAP_ATTR_MUST_UNDERSTAND_1, must_understand) == 0)
    {

        axiom_soap_header_block_set_attribute(header_block, env,
                AXIOM_SOAP_ATTR_MUST_UNDERSTAND, must_understand, attr_nsuri);
        return AXIS2_SUCCESS;
    }
    else
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_MUST_UNDERSTAND_SHOULD_BE_1_0_TRUE_FALSE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_soap_header_block_get_must_understand
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env)
{
    const axis2_char_t *must_understand = NULL;
    const axis2_char_t *attr_nsuri     = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (header_block->soap_version == AXIOM_SOAP_VERSION_NOT_SET)
        return AXIS2_FAILURE;
    if (header_block->soap_version == AXIOM_SOAP11)
    {
        attr_nsuri     = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    if (header_block->soap_version == AXIOM_SOAP12)
    {
        attr_nsuri     = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    must_understand = axiom_soap_header_block_get_attribute(header_block,
            env, AXIOM_SOAP_ATTR_MUST_UNDERSTAND, attr_nsuri);
    if (!must_understand)
        return AXIS2_FALSE;


    if (axutil_strcmp(must_understand, AXIOM_SOAP_ATTR_MUST_UNDERSTAND_1) == 0 ||
            axutil_strcmp(must_understand, AXIOM_SOAP_ATTR_MUST_UNDERSTAND_TRUE) == 0)
    {
        return AXIS2_TRUE;
    }
    else if (axutil_strcmp(must_understand, AXIOM_SOAP_ATTR_MUST_UNDERSTAND_0) == 0 ||
            axutil_strcmp(must_understand, AXIOM_SOAP_ATTR_MUST_UNDERSTAND_FALSE) == 0)
    {
        return AXIS2_FALSE;
    }
    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_VALUE_FOUND_IN_MUST_UNDERSTAND,
            AXIS2_FAILURE);
    return AXIS2_FALSE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_block_set_attribute
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env,
        const axis2_char_t *attr_name,
        const axis2_char_t *attr_value,
        const axis2_char_t *soap_envelope_namespace_uri)
{
    axiom_attribute_t* om_attr = NULL;
    axiom_node_t *header_node = NULL;
    axiom_element_t *header_ele = NULL;
    axiom_namespace_t *header_ns = NULL;
    axis2_char_t *prefix = NULL;
    axutil_qname_t *qn = NULL;
    axiom_namespace_t *om_ns = NULL;
    axiom_element_t *om_ele = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, attr_name, AXIS2_FAILURE);

    header_node = axiom_node_get_parent(header_block->om_ele_node, env);
    if (!header_node)
    {
        return AXIS2_FAILURE;
    }
    if (axiom_node_get_node_type(header_node, env) == AXIOM_ELEMENT)
    {
        header_ele = (axiom_element_t*)axiom_node_get_data_element(header_node, env);
        if (!header_ele)
        {
            return AXIS2_FAILURE;
        }
        header_ns = axiom_element_get_namespace(header_ele, env, header_node);
        if (!header_ns)
            return AXIS2_FAILURE;
        prefix = axiom_namespace_get_prefix(header_ns, env);
    }

    qn = axutil_qname_create(env, attr_name, soap_envelope_namespace_uri, prefix);

    if (!qn)
        return AXIS2_FAILURE;

    if (!header_block->om_ele_node)
        return AXIS2_FAILURE;


    om_ele = (axiom_element_t *)axiom_node_get_data_element(
                header_block->om_ele_node, env);

    om_attr = axiom_element_get_attribute(om_ele, env, qn);

    axutil_qname_free(qn, env);
    if (om_attr)
    {
        return  axiom_attribute_set_value(om_attr, env, attr_value);
    }
    else
    {
        if (soap_envelope_namespace_uri)
            om_ns = axiom_namespace_create(env,
                    soap_envelope_namespace_uri,
                    AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX);

        om_attr = axiom_attribute_create(env, attr_name, attr_value, om_ns);
        if (!om_attr && om_ns)
        {
            axiom_namespace_free(om_ns, env);
            return AXIS2_FAILURE;
        }

        return axiom_element_add_attribute(om_ele, env, om_attr,
                header_block->om_ele_node);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_soap_header_block_get_attribute
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env,
        const axis2_char_t *attr_name,
        const axis2_char_t *soap_envelope_namespace_uri)
{
    axiom_attribute_t* om_attr = NULL;
    axis2_char_t *attr_value = NULL;
    axiom_node_t *header_node = NULL;
    axiom_element_t *header_ele = NULL;
    axiom_namespace_t *header_ns = NULL;
    axis2_char_t *prefix = NULL;
    axutil_qname_t *qn = NULL;
    axiom_element_t *om_ele = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, attr_name, NULL);
    AXIS2_PARAM_CHECK(env->error, soap_envelope_namespace_uri, NULL);

    header_node = axiom_node_get_parent(header_block->om_ele_node, env);
    if (!header_node)
    {
        return NULL;
    }
    if (axiom_node_get_node_type(header_node, env) == AXIOM_ELEMENT)
    {
        header_ele = (axiom_element_t*)axiom_node_get_data_element(header_node, env);
        if (!header_ele)
        {
            return NULL;
        }
        header_ns = axiom_element_get_namespace(header_ele, env, header_node);
        if (!header_ns)
            return NULL;
        prefix = axiom_namespace_get_prefix(header_ns, env);
    }
    qn = axutil_qname_create(env, attr_name, soap_envelope_namespace_uri, prefix);
    if (!qn)
        return NULL;
    om_ele = (axiom_element_t *)axiom_node_get_data_element(
                header_block->om_ele_node, env);
    om_attr = axiom_element_get_attribute(om_ele, env, qn);
    if (om_attr)
        attr_value = axiom_attribute_get_value(om_attr, env);
    axutil_qname_free(qn, env);
    return attr_value;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_soap_header_block_is_processed
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return header_block->processed;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_block_set_processed
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    header_block->processed = AXIS2_TRUE;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL axiom_soap_header_block_set_base_node
(axiom_soap_header_block_t *header_block,
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
    header_block->om_ele_node = node;
    return AXIS2_SUCCESS;

}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_header_block_get_base_node
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return header_block->om_ele_node;
}

AXIS2_EXTERN int AXIS2_CALL
axiom_soap_header_block_get_soap_version
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return header_block->soap_version;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_header_block_set_soap_version
(axiom_soap_header_block_t *header_block,
        const axutil_env_t *env,
        int soap_version)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    header_block->soap_version = soap_version;
    return AXIS2_SUCCESS;
}
