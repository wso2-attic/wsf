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

#include <axiom_soap_builder.h>
#include "_axiom_soap_envelope.h"
#include "_axiom_soap_header.h"
#include "axiom_soap11_builder_helper.h"
#include "axiom_soap12_builder_helper.h"
#include <axiom_soap_const.h>
#include "_axiom_soap_body.h"
#include "_axiom_soap_header_block.h"
#include <axiom_stax_builder_internal.h>
#include "_axiom_soap_fault.h"

axis2_status_t
axiom_soap_builder_create_om_element(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axiom_node_t *current_node,
        int current_event);

static axis2_status_t
axiom_soap_builder_construct_node(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axiom_node_t *parent,
        axiom_node_t *om_element_node,
        axis2_bool_t is_soap_envelope);

static axis2_status_t
axiom_soap_builder_identify_soap_version(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        const axis2_char_t* soap_version_uri_from_transport);

static axis2_status_t
axiom_soap_builder_parse_headers(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env);

static axis2_status_t
axiom_soap_builder_construct_node_for_empty_element
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axiom_node_t *parent,
        axiom_node_t *om_element_node);

struct axiom_soap_builder
{
    axiom_stax_builder_t *om_builder;

    axiom_soap_envelope_t *soap_envelope;

    axis2_bool_t header_present;

    axis2_bool_t body_present;

    int element_level;

    axis2_bool_t processing_fault;

    axis2_bool_t processing_detail_elements;

    axis2_char_t* sender_fault_code;

    axis2_char_t* receiver_fault_code;

    axis2_bool_t processing_mandatory_fault_elements;

    void *builder_helper;

    axiom_namespace_t *envelope_ns;

    int soap_version;

    int last_node_status;

    axis2_bool_t  done;

    axutil_hash_t *mime_body_parts;

};

typedef enum axis2_builder_last_node_states
{
    AXIS2_BUILDER_LAST_NODE_NULL = 0,
    AXIS2_BUILDER_LAST_NODE_NOT_NULL
}axis2_builder_last_node_states;

#define AXIS2_MAX_EVENT 100

AXIS2_EXTERN axiom_soap_builder_t * AXIS2_CALL
axiom_soap_builder_create(const axutil_env_t *env,
        axiom_stax_builder_t *stax_builder,
        const axis2_char_t *soap_version)
{
    axiom_soap_builder_t *soap_builder = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, stax_builder, NULL);

    soap_builder = (axiom_soap_builder_t*)AXIS2_MALLOC(env->allocator, 
        sizeof(axiom_soap_builder_t));

    if (soap_builder == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    soap_builder->done = AXIS2_FALSE;
    soap_builder->body_present = AXIS2_FALSE;
    soap_builder->builder_helper = NULL;
    soap_builder->element_level = 0;
    soap_builder->header_present = AXIS2_FALSE;
    soap_builder->processing_detail_elements = AXIS2_FALSE;
    soap_builder->processing_fault = AXIS2_FALSE;
    soap_builder->processing_mandatory_fault_elements = AXIS2_FALSE;
    soap_builder->receiver_fault_code = NULL;
    soap_builder->sender_fault_code = NULL;
    soap_builder->soap_version = AXIOM_SOAP12;
    soap_builder->last_node_status = -1;
    soap_builder->envelope_ns = NULL;
    soap_builder->soap_envelope = NULL;
    soap_builder->mime_body_parts = NULL;
    soap_builder->om_builder = stax_builder;

    status = axiom_soap_builder_identify_soap_version(soap_builder, env, soap_version);
    if (status == AXIS2_FAILURE)
    {
        axiom_soap_builder_free(soap_builder, env);
        return NULL;
    }
    status = axiom_soap_builder_parse_headers(soap_builder, env);
    if (status == AXIS2_FAILURE)
    {
        axiom_soap_builder_free(soap_builder, env);
        return NULL;
    }
    return soap_builder;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_soap_builder_free(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    if (!soap_builder)
        return;

    if (soap_builder->builder_helper)
    {
        if (soap_builder->soap_version == AXIOM_SOAP11 && soap_builder->builder_helper)
        {
            axiom_soap11_builder_helper_free((axiom_soap11_builder_helper_t *)(soap_builder->builder_helper), env);
            soap_builder->builder_helper = NULL;
        }
        else if (soap_builder->soap_version == AXIOM_SOAP12 && soap_builder->builder_helper)
        {
            axiom_soap12_builder_helper_free((axiom_soap12_builder_helper_t *)(soap_builder->builder_helper), env);
            soap_builder->builder_helper = NULL;
        }
    }
    
    if ( soap_builder->om_builder)
    {
        axiom_stax_builder_free(soap_builder->om_builder, env);
        soap_builder->om_builder = NULL;
    }
    
    if (soap_builder->mime_body_parts)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        const void *key = NULL;
        for (hi = axutil_hash_first(soap_builder->mime_body_parts, env);
                hi; hi = axutil_hash_next(env, hi))
        {
            axutil_hash_this(hi, &key, NULL, &val);

            if (key)
            {
                AXIS2_FREE(env->allocator, (char*)key);
            }

            val = NULL;
            key = NULL;
        }

        axutil_hash_free(soap_builder->mime_body_parts, env);
        soap_builder->mime_body_parts = NULL;
    }

    if (soap_builder)
    {
        AXIS2_FREE(env->allocator, soap_builder);
        soap_builder = NULL;
    }

    return;
}


AXIS2_EXTERN axiom_soap_envelope_t* AXIS2_CALL
axiom_soap_builder_get_soap_envelope
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env)
{
    int status = AXIS2_SUCCESS ;

    AXIS2_ENV_CHECK(env, NULL);
    if (!soap_builder)
        return NULL;

    if (!(soap_builder->om_builder))
        return NULL;

    while (!(soap_builder->soap_envelope) &&
            !axiom_stax_builder_is_complete(soap_builder->om_builder, env))
    {
        status = axiom_soap_builder_next(soap_builder, env);
        if (status == AXIS2_FAILURE)
            break;
    }

    return soap_builder->soap_envelope;
}

AXIS2_EXTERN axiom_document_t* AXIS2_CALL
axiom_soap_builder_get_document
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    if (!soap_builder)
        return NULL;
    if (soap_builder->om_builder)
    {
        return axiom_stax_builder_get_document(soap_builder->om_builder, env);
    }
    else
        return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_builder_next(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env)
{
    axiom_node_t *lastnode = NULL;
    int current_event = AXIS2_MAX_EVENT;
    axiom_node_t *current_node =  NULL;
    int status = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (!soap_builder)
        return AXIS2_FAILURE;
    if (soap_builder->done)
    {
        return AXIS2_FAILURE;
    }
    if (!(soap_builder->om_builder))
        return AXIS2_FAILURE;

    lastnode = axiom_stax_builder_get_lastnode(soap_builder->om_builder, env);

    if (!lastnode)
    {
        soap_builder->last_node_status = AXIS2_BUILDER_LAST_NODE_NULL;
    }
    else
    {
        soap_builder->last_node_status = AXIS2_BUILDER_LAST_NODE_NOT_NULL;
    }
    current_event = axiom_stax_builder_next_with_token(soap_builder->om_builder, env);
    if (current_event == -1)
    {
        soap_builder->done = AXIS2_TRUE;
        return AXIS2_FAILURE;
    }
    if (current_event == AXIOM_XML_READER_EMPTY_ELEMENT ||
            current_event ==  AXIOM_XML_READER_START_ELEMENT)
    {
        current_node = axiom_stax_builder_get_lastnode(soap_builder->om_builder, env);
        if (current_node)
            status = axiom_soap_builder_create_om_element(soap_builder, env, current_node, current_event);
        else
            return AXIS2_FAILURE;
    }

    return status;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_soap_builder_get_document_element
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    if (soap_builder->soap_envelope)
    {
        return axiom_soap_envelope_get_base_node(soap_builder->soap_envelope, env);
    }
    else
        return NULL;
}



axis2_status_t
axiom_soap_builder_create_om_element
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axiom_node_t *current_node,
        int current_event)
{
    int ret_val = AXIS2_SUCCESS;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, current_node, AXIS2_FAILURE);
    if (!soap_builder)
        return AXIS2_FAILURE;

    if (soap_builder->last_node_status == AXIS2_BUILDER_LAST_NODE_NULL)
    {
        ret_val =  axiom_soap_builder_construct_node(soap_builder, env, NULL, current_node, AXIS2_TRUE);
    }
    else
    {
        int element_level = 0;
        axiom_node_t *parent_node = NULL;
        parent_node = axiom_node_get_parent(current_node, env);
        if (!soap_builder->om_builder)
            return  AXIS2_FAILURE;

        element_level = axiom_stax_builder_get_element_level(
                    soap_builder->om_builder, env);
        if (parent_node && element_level == 1 && current_event == AXIOM_XML_READER_EMPTY_ELEMENT)
        {
            ret_val = axiom_soap_builder_construct_node_for_empty_element(soap_builder, env, parent_node , current_node);
        }
        else if (parent_node)
        {
            ret_val = axiom_soap_builder_construct_node(soap_builder, env, parent_node , current_node, AXIS2_FALSE);
        }
        else
            return AXIS2_FAILURE;
    }
    return ret_val;
}

static axis2_status_t
axiom_soap_builder_construct_node(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axiom_node_t *parent,
        axiom_node_t *om_element_node,
        axis2_bool_t is_soap_envelope)
{
    axiom_element_t *parent_ele  = NULL;
    axis2_char_t *parent_localname = NULL;

    axiom_element_t *om_element = NULL;
    const axis2_char_t *ele_localname = NULL;

    int element_level = 0;
    int status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_element_node, AXIS2_FAILURE);
    if (!soap_builder)
        return AXIS2_FAILURE;

    if (!soap_builder->om_builder)
        return AXIS2_FAILURE;
    /** get element level of this om element */
    element_level = axiom_stax_builder_get_element_level(
                soap_builder->om_builder, env);
    /* get om element struct from node */
    om_element = (axiom_element_t *)
            axiom_node_get_data_element(om_element_node, env);
    if (!om_element)
        return AXIS2_FAILURE;
    /* get element localname */
    ele_localname = axiom_element_get_localname(om_element, env);
    if (!ele_localname)
        return AXIS2_FAILURE;

    /* start: handle MTOM stuff */
    if (axutil_strcmp(ele_localname, AXIS2_XOP_INCLUDE) == 0)
    {
        axiom_namespace_t *ns = NULL;
        ns = axiom_element_get_namespace(om_element, env, om_element_node);
        if (ns)
        {
            axis2_char_t *uri = axiom_namespace_get_uri(ns, env);
            if (uri)
            {
                if (axutil_strcmp(uri, AXIS2_XOP_NAMESPACE_URI) == 0)
                {
                    axutil_qname_t *qname = NULL;
                    qname = axutil_qname_create(env, "href", NULL, NULL);
                    if (qname)
                    {
                        axis2_char_t *id = NULL;
                        id = axiom_element_get_attribute_value(om_element, env, qname);
                        if (id)
                        {
                            axis2_char_t *pos = NULL;
                            pos = axutil_strstr(id, "cid:");
                            if (pos)
                            {
                                axiom_data_handler_t *data_handler = NULL;
                                id += 4;
                                if (soap_builder->mime_body_parts)
                                {
                                    data_handler = (axiom_data_handler_t *)axutil_hash_get(
                                                soap_builder->mime_body_parts,
                                                (void*)id, AXIS2_HASH_KEY_STRING);
                                    if (data_handler)
                                    {
                                        axiom_text_t *data_text = NULL;
                                        axiom_node_t *data_om_node = NULL;
                                        data_text = axiom_text_create_with_data_handler(
                                                    env, om_element_node, data_handler, &data_om_node);
                                        axiom_text_set_optimize(data_text, env, AXIS2_FALSE);
                                    }
                                }
                            }
                        }
                    }
                    axutil_qname_free(qname, env);
                }
            }
        }
    }
    /* end: handle MTOM stuff */

    if (parent)
    {
        /** a parent node exist , so not soap envelope element */
        parent_ele = (axiom_element_t *)axiom_node_get_data_element(parent, env);
        if (parent_ele)
            parent_localname = axiom_element_get_localname(parent_ele, env);
    }
    if (!parent && is_soap_envelope)
    {
        /** this is the soap envelope element */
        if (axutil_strcasecmp(ele_localname, AXIOM_SOAP_ENVELOPE_LOCAL_NAME) != 0)
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_SOAP_MESSAGE_FIRST_ELEMENT_MUST_CONTAIN_LOCAL_NAME, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }

        /** create a null soap envelope struct */
        soap_builder->soap_envelope = axiom_soap_envelope_create_null(env);
        if (!soap_builder->soap_envelope)
            return AXIS2_FAILURE;
        /** wrap this om node in it */
        status = axiom_soap_envelope_set_base_node(soap_builder->soap_envelope,
                env, om_element_node);

        axiom_soap_envelope_set_builder(soap_builder->soap_envelope, env, soap_builder);
        status = axiom_soap_builder_process_namespace_data(soap_builder, env, om_element_node, AXIS2_TRUE);
        if (status == AXIS2_FAILURE)
            return AXIS2_FAILURE;
    }
    else if (element_level == 2)
    {
        if (axutil_strcmp(ele_localname, AXIOM_SOAP_HEADER_LOCAL_NAME) == 0)
        {
            /** this is the soap header element */
            axiom_soap_header_t *soap_header = NULL;
            if (soap_builder->header_present)
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_SOAP_BUILDER_MULTIPLE_HEADERS_ENCOUNTERED, AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
            if (soap_builder->body_present)
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_SOAP_BUILDER_HEADER_BODY_WRONG_ORDER, AXIS2_FAILURE);
                return  AXIS2_FAILURE;
            }

            soap_builder->header_present = AXIS2_TRUE;

            soap_header = axiom_soap_header_create(env);
            if (!soap_header)
                return AXIS2_FAILURE;

            axiom_soap_header_set_base_node(soap_header, env, om_element_node);

            axiom_soap_envelope_set_header(soap_builder->soap_envelope, env, soap_header);

            axiom_soap_header_set_builder(soap_header, env, soap_builder);

            axiom_soap_header_set_soap_version(soap_header, env, soap_builder->soap_version);

            status = axiom_soap_builder_process_namespace_data(soap_builder, env,
                    om_element_node, AXIS2_TRUE);
            if (status == AXIS2_FAILURE)
                return AXIS2_FAILURE;

        }
        else if (axutil_strcmp(ele_localname, AXIOM_SOAP_BODY_LOCAL_NAME) == 0)
        {

            axiom_soap_body_t *soap_body = NULL;
            if (soap_builder->body_present)
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_SOAP_BUILDER_MULTIPLE_BODY_ELEMENTS_ENCOUNTERED, AXIS2_FAILURE);
                return AXIS2_FAILURE;

            }
            soap_builder->body_present = AXIS2_TRUE;

            soap_body = axiom_soap_body_create(env);
            if (!soap_body)
                return AXIS2_FAILURE;

            axiom_soap_body_set_base_node(soap_body, env, om_element_node);

            axiom_soap_body_set_builder(soap_body, env, soap_builder);

            axiom_soap_envelope_set_body(soap_builder->soap_envelope, env, soap_body);

            status = axiom_soap_builder_process_namespace_data(soap_builder, env,
                    om_element_node, AXIS2_TRUE);

            if (status == AXIS2_FAILURE)
                return AXIS2_FAILURE;
        }
        else
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_SOAP_BUILDER_ENVELOPE_CAN_HAVE_ONLY_HEADER_AND_BODY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    else if ((element_level == 3) &&  parent_localname &&
            axutil_strcasecmp(parent_localname, AXIOM_SOAP_HEADER_LOCAL_NAME) == 0)
    {
        axiom_soap_header_block_t *header_block = NULL;
        axiom_soap_header_t *soap_header = NULL;

        soap_header = axiom_soap_envelope_get_header(soap_builder->soap_envelope, env);
        if (!soap_header)
            return AXIS2_FAILURE;

        header_block = axiom_soap_header_block_create(env);
        if (!header_block)
            return AXIS2_FAILURE;

        axiom_soap_header_block_set_base_node(header_block, env, om_element_node);

        axiom_soap_header_set_header_block(soap_header, env, header_block);

        axiom_soap_header_block_set_soap_version(header_block, env, soap_builder->soap_version);


    }
    else if ((element_level == 3) && parent_localname &&
            axutil_strcasecmp(parent_localname, AXIOM_SOAP_BODY_LOCAL_NAME) == 0 &&
            axutil_strcasecmp(ele_localname, AXIOM_SOAP_BODY_FAULT_LOCAL_NAME) == 0)
    {
        axiom_soap_body_t *soap_body = NULL;
        axiom_soap_fault_t *soap_fault = NULL;
        axiom_namespace_t *env_ns = NULL;

        env_ns = axiom_soap_envelope_get_namespace(soap_builder->soap_envelope, env);
        if (!env_ns)
            return AXIS2_FAILURE;

        soap_body = axiom_soap_envelope_get_body(soap_builder->soap_envelope, env);

        if (!soap_body)
            return AXIS2_FAILURE;

        soap_fault = axiom_soap_fault_create(env);
        if (!soap_fault)
            return AXIS2_FAILURE;

        axiom_soap_fault_set_base_node(soap_fault, env, om_element_node);

        axiom_soap_body_set_fault(soap_body, env, soap_fault);
    
        axiom_soap_fault_set_builder(soap_fault, env, soap_builder);

        soap_builder->processing_fault = AXIS2_TRUE;

        soap_builder->processing_mandatory_fault_elements = AXIS2_TRUE;

        if (axutil_strcmp(AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI,
                axiom_namespace_get_uri(env_ns , env)) == 0)
        {
            soap_builder->builder_helper = axiom_soap12_builder_helper_create(env, soap_builder);
            if (!(soap_builder->builder_helper))
                return AXIS2_FAILURE;
        }
        else if (axutil_strcmp(AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI,
                axiom_namespace_get_uri(env_ns , env)) == 0)
        {
            soap_builder->builder_helper = axiom_soap11_builder_helper_create(env, soap_builder, soap_builder->om_builder);
            if (!(soap_builder->builder_helper))
                return AXIS2_FAILURE;
        }

    }
    else if (element_level > 3 && soap_builder->processing_fault)
    {
        if (soap_builder->soap_version == AXIOM_SOAP11)
        {
            status = axiom_soap11_builder_helper_handle_event(
                        ((axiom_soap11_builder_helper_t*)(soap_builder->builder_helper)),
                        env,  om_element_node , element_level);

        }
        else if (soap_builder->soap_version == AXIOM_SOAP12)
        {
            status = axiom_soap12_builder_helper_handle_event(
                        ((axiom_soap12_builder_helper_t *)(soap_builder->builder_helper)),
                        env,  om_element_node , element_level);
        }

    }
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_builder_process_namespace_data
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axiom_node_t *om_node,
        int is_soap_element)
{
    axiom_element_t *om_ele = NULL;
    axiom_namespace_t *om_ns = NULL;
    axis2_char_t *ns_uri = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (!om_node)
        return AXIS2_FAILURE;

    if (!is_soap_element)
        return AXIS2_SUCCESS;

    if (axiom_node_get_node_type(om_node, env) == AXIOM_ELEMENT)
    {
        om_ele = (axiom_element_t *) axiom_node_get_data_element(om_node, env);
        if (om_ele)
        {
            om_ns = axiom_element_get_namespace(om_ele, env, om_node);
            if (om_ns)
            {
                ns_uri = axiom_namespace_get_uri(om_ns, env);
                if (ns_uri &&
                        (axutil_strcmp(ns_uri, AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI) != 0) &&
                        (axutil_strcmp(ns_uri, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI) != 0))
                {
                    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_SOAP_NAMESPACE_URI, AXIS2_FAILURE);
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "AXIS2_ERROR_INVALID_SOAP_NAMESPACE_URI");
                    return AXIS2_FAILURE;
                }

            }
        }
    }
    return AXIS2_SUCCESS;
}

static axis2_status_t
axiom_soap_builder_identify_soap_version(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        const axis2_char_t* soap_version_uri_from_transport)
{
    axiom_namespace_t *om_ns = NULL;
    axiom_node_t *envelope_node = NULL;
    axiom_element_t *om_ele = NULL;
    axis2_char_t *ns_uri = NULL;

    AXIS2_PARAM_CHECK(env->error, soap_version_uri_from_transport, AXIS2_FAILURE);
    if (!soap_builder)
        return AXIS2_FAILURE;

    soap_builder->soap_envelope = axiom_soap_builder_get_soap_envelope(soap_builder, env);

    if (soap_builder->soap_envelope == NULL)
    {
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_SOAP_MESSAGE_DOES_NOT_CONTAIN_AN_ENVELOPE, AXIS2_FAILURE);
        AXIS2_LOG_CRITICAL(env->log, AXIS2_LOG_SI,
                "SOAP message does not have a SOAP envelope element ");
        return AXIS2_FAILURE;
    }

    envelope_node = axiom_soap_envelope_get_base_node(soap_builder->soap_envelope, env);

    if (!envelope_node)
        return AXIS2_FAILURE;

    om_ele = (axiom_element_t *) axiom_node_get_data_element(envelope_node, env);
    if (!om_ele)
        return AXIS2_FAILURE;

    om_ns = axiom_element_get_namespace(om_ele, env, envelope_node);
    if (!om_ns)
        return AXIS2_FAILURE;

    ns_uri = axiom_namespace_get_uri(om_ns, env);

    if (ns_uri)
    {
        if (soap_version_uri_from_transport && axutil_strcmp(soap_version_uri_from_transport, ns_uri) != 0)
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_TRANSPORT_LEVEL_INFORMATION_DOES_NOT_MATCH_WITH_SOAP, AXIS2_FAILURE);

            AXIS2_LOG_ERROR(env->log , AXIS2_LOG_SI,
                    "AXIS2_ERROR_TRANSPORT_LEVEL_INFORMATION_DOES_NOT_MATCH_WITH_SOAP");
            return AXIS2_FAILURE;
        }
        if (axutil_strcmp(AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI, ns_uri) == 0)
        {
            soap_builder->soap_version = AXIOM_SOAP11;

            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Identified soap version is soap11");

            axiom_soap_envelope_set_soap_version_internal(soap_builder->soap_envelope,
                    env, soap_builder->soap_version);

            return AXIS2_SUCCESS;
        }
        else if (axutil_strcmp(AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI, ns_uri) == 0)
        {
            soap_builder->soap_version = AXIOM_SOAP12;

            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "identified soap version is soap12");

            axiom_soap_envelope_set_soap_version_internal(soap_builder->soap_envelope,
                    env, soap_builder->soap_version);

            return AXIS2_SUCCESS;
        }
    }
    return AXIS2_FAILURE;
}

static axis2_status_t
axiom_soap_builder_parse_headers(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env)
{
    axiom_node_t *om_node = NULL;
    axiom_soap_header_t *soap_header = NULL;
    int status = AXIS2_SUCCESS;
    if (!soap_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    if (!soap_builder->soap_envelope)
        return AXIS2_FAILURE;

    soap_header = axiom_soap_envelope_get_header(soap_builder->soap_envelope, env);

    if (soap_header)
    {
        om_node = axiom_soap_header_get_base_node(soap_header, env);
        if (om_node)
        {
            while (!axiom_node_is_complete(om_node, env))
            {
                status = axiom_soap_builder_next(soap_builder, env);
                if (status == AXIS2_FAILURE)
                    return AXIS2_FAILURE;
            }
            /*HACK: to fix AXIS2C-129 - Samisa*/
            /*
            axiom_stax_builder_set_element_level(
                    soap_builder->om_builder, env, 1);
            */
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_builder_set_bool_processing_mandatory_fault_elements
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axis2_bool_t value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    soap_builder->processing_mandatory_fault_elements = value;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_builder_set_processing_detail_elements
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axis2_bool_t value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    soap_builder->processing_detail_elements = value;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_soap_builder_is_processing_detail_elements
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    return soap_builder->processing_detail_elements ;
}

AXIS2_EXTERN int AXIS2_CALL
axiom_soap_builder_get_soap_version(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    return soap_builder->soap_version ;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_builder_set_mime_body_parts
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axutil_hash_t *map)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    soap_builder->mime_body_parts = map;
    return AXIS2_SUCCESS;
}

static axis2_status_t
axiom_soap_builder_construct_node_for_empty_element
(axiom_soap_builder_t *soap_builder,
        const axutil_env_t *env,
        axiom_node_t *parent,
        axiom_node_t *om_element_node)
{
    axiom_element_t *parent_ele  = NULL;
    axis2_char_t *parent_localname = NULL;

    axiom_element_t *om_element = NULL;
    axis2_char_t *ele_localname = NULL;

    int element_level = 0;
    int status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_element_node, AXIS2_FAILURE);
    if (!soap_builder)
        return AXIS2_FAILURE;

    if (!soap_builder->om_builder)
        return AXIS2_FAILURE;

    element_level = axiom_stax_builder_get_element_level(
                soap_builder->om_builder, env);

    om_element = (axiom_element_t *)
            axiom_node_get_data_element(om_element_node, env);
    if (!om_element)
        return AXIS2_FAILURE;

    ele_localname = axiom_element_get_localname(om_element, env);
    if (!ele_localname)
        return AXIS2_FAILURE;

    if (!parent)
        return AXIS2_FAILURE;


    parent_ele = (axiom_element_t *)axiom_node_get_data_element(parent, env);
    if (!parent_ele)
        return AXIS2_FAILURE;

    parent_localname = axiom_element_get_localname(parent_ele, env);
    if (!parent_localname)
        return AXIS2_FAILURE;

    if (element_level == 1)
    {
        if (axutil_strcmp(ele_localname, AXIOM_SOAP_HEADER_LOCAL_NAME) == 0)
        {
            /** this is the soap header element */
            axiom_soap_header_t *soap_header = NULL;
            if (soap_builder->header_present)
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_SOAP_BUILDER_MULTIPLE_HEADERS_ENCOUNTERED, AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
            if (soap_builder->body_present)
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_SOAP_BUILDER_HEADER_BODY_WRONG_ORDER, AXIS2_FAILURE);
                return  AXIS2_FAILURE;
            }

            soap_builder->header_present = AXIS2_TRUE;

            soap_header = axiom_soap_header_create(env);
            if (!soap_header)
                return AXIS2_FAILURE;

            axiom_soap_header_set_base_node(soap_header, env, om_element_node);

            axiom_soap_envelope_set_header(soap_builder->soap_envelope, env, soap_header);

            axiom_soap_header_set_builder(soap_header, env, soap_builder);

            axiom_soap_header_set_soap_version(soap_header, env, soap_builder->soap_version);

            status = axiom_soap_builder_process_namespace_data(soap_builder, env,
                    om_element_node, AXIS2_TRUE);
            if (status == AXIS2_FAILURE)
                return AXIS2_FAILURE;

        }
        else if (axutil_strcmp(ele_localname, AXIOM_SOAP_BODY_LOCAL_NAME) == 0)
        {

            axiom_soap_body_t *soap_body = NULL;
            if (soap_builder->body_present)
            {
                AXIS2_ERROR_SET(env->error,
                        AXIS2_ERROR_SOAP_BUILDER_MULTIPLE_BODY_ELEMENTS_ENCOUNTERED, AXIS2_FAILURE);
                return AXIS2_FAILURE;

            }
            soap_builder->body_present = AXIS2_TRUE;

            soap_body = axiom_soap_body_create(env);
            if (!soap_body)
                return AXIS2_FAILURE;

            axiom_soap_body_set_base_node(soap_body, env, om_element_node);

            axiom_soap_body_set_builder(soap_body, env, soap_builder);

            axiom_soap_envelope_set_body(soap_builder->soap_envelope, env, soap_body);

            status = axiom_soap_builder_process_namespace_data(soap_builder, env,
                    om_element_node, AXIS2_TRUE);

            if (status == AXIS2_FAILURE)
                return AXIS2_FAILURE;
        }
        else
        {
            AXIS2_ERROR_SET(env->error,
                    AXIS2_ERROR_SOAP_BUILDER_ENVELOPE_CAN_HAVE_ONLY_HEADER_AND_BODY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    return status;
}
