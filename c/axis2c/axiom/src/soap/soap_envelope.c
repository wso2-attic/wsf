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
#include <axiom_soap_body.h>
#include <axiom_soap_header.h>
#include <axiom_soap_header_block.h>
#include <axutil_hash.h>
#include <axiom_soap_const.h>
#include <axiom_soap_builder.h>
#include <axiom_soap_fault_code.h>
#include <axiom_soap_fault_reason.h>
#include <axiom_soap_fault_detail.h>
#include <axiom_soap_fault_role.h>
#include <axiom_soap_fault_value.h>
#include <axiom_soap_fault_text.h>
#include <axiom_namespace_internal.h>

struct axiom_soap_envelope
{
    /* corresponding om element node */
    axiom_node_t *om_ele_node;
    /* soap version */
    int soap_version;
    /* soap header */
    axiom_soap_header_t *header;
    /* soap body */
    axiom_soap_body_t *body;
    /* pointer to soap builder */
    axiom_soap_builder_t *soap_builder;
};
static axis2_status_t
check_and_set_soap_version(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env,
    axiom_namespace_t *ns);

AXIS2_EXTERN axiom_soap_envelope_t* AXIS2_CALL
axiom_soap_envelope_create_null(const axutil_env_t *env)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    soap_envelope = (axiom_soap_envelope_t*)AXIS2_MALLOC(
        env->allocator,
        sizeof(axiom_soap_envelope_t));
    if (!soap_envelope)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    soap_envelope->om_ele_node = NULL;
    soap_envelope->soap_version = AXIOM_SOAP12;
    soap_envelope->header = NULL;
    soap_envelope->body = NULL;
    soap_envelope->soap_builder = NULL;

    return soap_envelope;
}


AXIS2_EXTERN axiom_soap_envelope_t* AXIS2_CALL
axiom_soap_envelope_create(const axutil_env_t *env,
     axiom_namespace_t *ns)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_element_t *ele = NULL;
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ns, NULL);

    soap_envelope = axiom_soap_envelope_create_null(env);
    if (!soap_envelope)
        return NULL;

    status =  check_and_set_soap_version(soap_envelope, env, ns);
    if (status == AXIS2_FAILURE)
    {
        AXIS2_FREE(env->allocator, soap_envelope);
        return NULL;
    }

    ele = axiom_element_create(env, NULL,
        AXIOM_SOAP_ENVELOPE_LOCAL_NAME, ns,
        &(soap_envelope->om_ele_node));
    if (!ele)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        axiom_soap_envelope_free(soap_envelope, env);
        return NULL;
    }
    return soap_envelope;
}

AXIS2_EXTERN axiom_soap_envelope_t* AXIS2_CALL
axiom_soap_envelope_create_with_soap_version_prefix(const axutil_env_t *env,
    int soap_version,
    const axis2_char_t *prefix)
{
    axiom_namespace_t *ns        = NULL;
    const axis2_char_t *ns_prefix = NULL;
    const axis2_char_t *ns_uri    = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    if (soap_version == AXIOM_SOAP11)
    {
        ns_uri = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    else if (soap_version == AXIOM_SOAP12)
    {
        ns_uri = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_SOAP_VERSION, AXIS2_FAILURE);
        return NULL;
    }
    if (!prefix || axutil_strcmp(prefix, "") == 0)
    {
        ns_prefix = AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX;
    }
    else
    {
        ns_prefix = prefix;
    }

    ns = axiom_namespace_create(env, ns_uri, ns_prefix);
    if (!ns)
        return NULL;
    return axiom_soap_envelope_create(env, ns);
}

AXIS2_EXTERN void AXIS2_CALL
axiom_soap_envelope_free(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (soap_envelope->header)
    {
        axiom_soap_header_free(soap_envelope->header, env);
    }
    if (soap_envelope->body)
    {
        axiom_soap_body_free(soap_envelope->body, env);
    }
    if (soap_envelope->om_ele_node)
    {
        if (soap_envelope->soap_builder)
        {
            axiom_soap_builder_free(soap_envelope->soap_builder, env);
            soap_envelope->om_ele_node = NULL;
        }
        else
        {
            axiom_node_free_tree(soap_envelope->om_ele_node, env);
        }
    }

    AXIS2_FREE(env->allocator, soap_envelope);
    return;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_envelope_get_base_node(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env)
{
    return soap_envelope->om_ele_node;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_envelope_set_base_node(axiom_soap_envelope_t *soap_envelope,
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
    soap_envelope->om_ele_node = node;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axiom_soap_envelope_get_soap_version(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env)
{
    return soap_envelope->soap_version;
}

/** this is an internal function */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_envelope_set_soap_version_internal(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env,
    int soap_version)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    soap_envelope->soap_version = soap_version;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_soap_header_t* AXIS2_CALL
axiom_soap_envelope_get_header(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;

    if (soap_envelope->header)
    {
        return soap_envelope->header;
    }
    else if (soap_envelope->soap_builder)
    {
        while (!(soap_envelope->header) && !axiom_node_is_complete(
                    soap_envelope->om_ele_node, env))
        {
            status = axiom_soap_builder_next(soap_envelope->soap_builder, env);
            if (status == AXIS2_FAILURE)
                break;
        }
    }

    return soap_envelope->header;
}

AXIS2_EXTERN axiom_soap_header_block_t* AXIS2_CALL
axiom_soap_envelope_add_header(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env,
    axis2_char_t *namespace_uri,
    axis2_char_t *name)
{
    axiom_namespace_t *ns = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    if (!soap_envelope->header)
        return NULL;

    if (namespace_uri)
    {
        ns = axiom_namespace_create(env, namespace_uri, NULL);
    }

    return axiom_soap_header_block_create_with_parent(env, name, ns, soap_envelope->header);
}

AXIS2_EXTERN axiom_soap_body_t* AXIS2_CALL
axiom_soap_envelope_get_body(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS;

    if (soap_envelope->body)
    {
        return soap_envelope->body;
    }
    else if (soap_envelope->soap_builder)
    {
        while (!(soap_envelope->body)  && !axiom_node_is_complete(soap_envelope->om_ele_node, env))
        {
            status = axiom_soap_builder_next(soap_envelope->soap_builder, env);
            if (status == AXIS2_FAILURE)
            {
                return NULL;
            }
        }
    }
    return soap_envelope->body;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_envelope_serialize(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env,
    axiom_output_t *om_output,
    axis2_bool_t cache)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_envelope, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_output, AXIS2_FAILURE);

    /*
       if soap version is soap11 we modify the soap fault part.
       This is done because the builder construct a soap12 fault all
       the time. So when serializing if the soap version is soap11
       we should convert it back to soap11 fault
    */
    if (soap_envelope->soap_version == AXIOM_SOAP11)
    {
        axiom_soap_body_t *soap_body = NULL;
        soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
		axiom_soap_body_convert_fault_to_soap11(soap_body, env);
    }
    /* write the xml version and encoding
       These should be set to om output before calling the serialize function
       Otherwise default values will be written
    */
    axiom_output_get_content_type(om_output, env);
    return axiom_node_serialize(soap_envelope->om_ele_node, env, om_output);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_envelope_set_body(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env,
    axiom_soap_body_t *body)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!(soap_envelope->body))
    {
        soap_envelope->body = body;
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
            "trying to set a soap bedy to soap_envelope when a soap body alrady exists");
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL axiom_soap_envelope_set_header(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env, axiom_soap_header_t *header)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!(soap_envelope->header))
    {
        soap_envelope->header = header;
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
            " trying to set a soap header to soap_envelope when a soap header alrady exists");
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_namespace_t* AXIS2_CALL
axiom_soap_envelope_get_namespace(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (soap_envelope->om_ele_node)
    {
        axiom_element_t *ele = NULL;
        if (axiom_node_get_node_type(soap_envelope->om_ele_node, env) == AXIOM_ELEMENT)
        {
            ele = (axiom_element_t*)axiom_node_get_data_element(soap_envelope->om_ele_node, env);
            if (ele)
            {
                return axiom_element_get_namespace(ele, env, soap_envelope->om_ele_node);
            }
        }
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_envelope_set_builder(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env,
    axiom_soap_builder_t *soap_builder)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_builder, AXIS2_FAILURE);
    soap_envelope->soap_builder = soap_builder;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_soap_envelope_t * AXIS2_CALL
axiom_soap_envelope_create_default_soap_envelope(const axutil_env_t *env,
    int soap_version)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_namespace_t *om_ns = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    if (soap_version == AXIOM_SOAP11)
    {
        om_ns = axiom_namespace_create(env,
            AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI,
            AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX);
        if (!om_ns)
            return NULL;
        soap_envelope = axiom_soap_envelope_create(env, om_ns);

        soap_header = axiom_soap_header_create_with_parent(env, soap_envelope);
        soap_body   = axiom_soap_body_create_with_parent(env, soap_envelope);
        soap_envelope->body = soap_body;
        soap_envelope->header = soap_header;
        return soap_envelope;
    }
    else if (soap_version == AXIOM_SOAP12)
    {
        om_ns = axiom_namespace_create(env,
            AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI,
            AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX);
        if (!om_ns)
            return NULL;
        soap_envelope = axiom_soap_envelope_create(env, om_ns);

        soap_header = axiom_soap_header_create_with_parent(env, soap_envelope);
        soap_body   = axiom_soap_body_create_with_parent(env, soap_envelope);
        soap_envelope->body = soap_body;
        soap_envelope->header = soap_header;
        return soap_envelope;
    }

    AXIS2_ERROR_SET(env->error,
        AXIS2_ERROR_INVALID_SOAP_VERSION, AXIS2_FAILURE);
    return NULL;
}

AXIS2_EXTERN axiom_soap_envelope_t * AXIS2_CALL
axiom_soap_envelope_create_default_soap_fault_envelope(const axutil_env_t *env,
    const axis2_char_t *code_value,
    const axis2_char_t *reason_text,
    const int soap_version,
    axutil_array_list_t *sub_codes,
    axiom_node_t *detail_node)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_soap_fault_t *fault = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    if (AXIOM_SOAP11 != soap_version && AXIOM_SOAP12 != soap_version)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_INVALID_SOAP_VERSION, AXIS2_FAILURE);
        return NULL;
    }

    soap_envelope = axiom_soap_envelope_create_default_soap_envelope(env, soap_version);
    if (!soap_envelope)
    {
        return NULL;
    }

    soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
    if (!soap_body)
    {
        axiom_soap_envelope_free(soap_envelope, env);
        return NULL;
    }
    fault = axiom_soap_fault_create_default_fault(env, soap_body,
        code_value, reason_text, soap_version);
    if (!fault)
    {
        axiom_soap_envelope_free(soap_envelope, env);
        return NULL;
    }

    if (sub_codes)
    {
        int i = 0;
        axiom_soap_fault_code_t *fault_code = NULL;
        fault_code = axiom_soap_fault_get_code(fault, env);
        if (fault_code)
        {
            for (i = 0; i < axutil_array_list_size(sub_codes, env); i++)
            {
                axis2_char_t *sub_code = (axis2_char_t*) axutil_array_list_get(sub_codes, env, i);
                if (sub_code)
                {
                    axiom_soap_fault_sub_code_create_with_parent_value(env, fault_code, sub_code);
                }
            }
        }
    }

    if (detail_node)
    {
        axiom_soap_fault_detail_t *detail =
            axiom_soap_fault_detail_create_with_parent(env, fault);
        if (detail)
        {
            axiom_soap_fault_detail_add_detail_entry(detail, env, detail_node);
        }
    }

    return soap_envelope;

}

static axis2_status_t
check_and_set_soap_version(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env,
    axiom_namespace_t *ns)
{
    axis2_char_t *uri = NULL;
    if (!soap_envelope)
        return AXIS2_FAILURE;
    if (!ns)
        return AXIS2_FAILURE;

    uri = axiom_namespace_get_uri(ns, env);
    if (!uri)
        return AXIS2_FAILURE;

    if (axutil_strcmp(uri, AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI) == 0)
    {
        soap_envelope->soap_version = AXIOM_SOAP11;
        return AXIS2_SUCCESS;
    }
    else if (axutil_strcmp(uri, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI) == 0)
    {
        soap_envelope->soap_version = AXIOM_SOAP12;
        return AXIS2_SUCCESS;
    }
    else
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_INVALID_SOAP_NAMESPACE_URI, AXIS2_FAILURE);
    }
    return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_envelope_set_soap_version(axiom_soap_envelope_t *soap_envelope,
    const axutil_env_t *env,
    int soap_version)
{
    axiom_element_t *env_ele  = NULL;
    axiom_namespace_t *env_ns = NULL;
    const axis2_char_t *ns_uri         = NULL;
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (soap_version == AXIOM_SOAP11)
    {
        ns_uri = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    else if (soap_version == AXIOM_SOAP12)
    {
        ns_uri = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
    }
    else
    {   
        return AXIS2_FAILURE;
    }

    env_ele = (axiom_element_t*)
        axiom_node_get_data_element(soap_envelope->om_ele_node,
        env);
    if (!env_ele)
    {
        return AXIS2_FAILURE;
    }

    env_ns = axiom_element_get_namespace(env_ele, env, soap_envelope->om_ele_node);
    if (!env_ns)
        return AXIS2_FAILURE;

    status = axiom_namespace_set_uri(env_ns, env, ns_uri);
    if (status == AXIS2_SUCCESS)
    {
        axiom_soap_envelope_set_soap_version_internal(soap_envelope, env, soap_version);
        return AXIS2_SUCCESS;
    }
    return AXIS2_FAILURE;
}

