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

#include <axiom_stax_builder.h>
#include <axiom_element.h>
#include <axiom_text.h>
#include <axiom_processing_instruction.h>
#include <axiom_comment.h>
#include <axutil_string.h>
#include <axiom_xml_writer.h>
#include <axiom_doctype.h>
#include "axiom_node_internal.h"
#include "axiom_stax_builder_internal.h"

struct axiom_stax_builder
{
    /** pull parser instance used by the om_builder */
    axiom_xml_reader_t *parser;
    /** last node the om_builder found */
    axiom_node_t *lastnode;

    axiom_node_t *root_node;
    /** document associated with the om_builder */
    axiom_document_t *document;
    /** done building the document? */
    axis2_bool_t done;
    /** parser was accessed? */
    axis2_bool_t parser_accessed;
    /** caching enabled? */
    axis2_bool_t cache;
    /** current event */
    int current_event;

    int element_level;
    axutil_hash_t *declared_namespaces;
};

AXIS2_EXTERN axiom_stax_builder_t *AXIS2_CALL
axiom_stax_builder_create(const axutil_env_t *env,
    axiom_xml_reader_t *parser)
{
    axiom_stax_builder_t *om_builder = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, parser, NULL);

    om_builder = (axiom_stax_builder_t *)AXIS2_MALLOC(env->allocator,
        sizeof(axiom_stax_builder_t));

    if (!om_builder)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    om_builder->cache = AXIS2_TRUE;
    om_builder->parser_accessed = AXIS2_FALSE;
    om_builder->done = AXIS2_FALSE;
    om_builder->lastnode = NULL;
    om_builder->document = NULL;
    om_builder->parser = parser;
    om_builder->current_event = -1;
    om_builder->root_node = NULL;
    om_builder->element_level = 0;

    om_builder->declared_namespaces = axutil_hash_make(env);

    om_builder->document = axiom_document_create(env, NULL, om_builder);
    if (!om_builder->document)
    {
        AXIS2_FREE(env->allocator, om_builder);
        return NULL;
    }

    return om_builder;
}


axis2_status_t
axiom_stax_builder_process_attributes(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env,
    axiom_node_t *element_node)
{
    int i = 0;
    int attribute_count;
    axiom_attribute_t *attribute = NULL;
    axiom_namespace_t *ns = NULL;
    axis2_char_t *uri = NULL;
    axis2_char_t *prefix = NULL;
    axis2_char_t *attr_name = NULL;
    axis2_char_t *attr_value = NULL;
    axutil_string_t *attr_name_str = NULL;
    axutil_string_t *attr_value_str = NULL;


    axis2_status_t status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, element_node, AXIS2_FAILURE);

    attribute_count = axiom_xml_reader_get_attribute_count(om_builder->parser,
        env);
    for (i = 1; i <= attribute_count ; i++)
    {
        axiom_element_t *temp_ele =  NULL;

        uri =
            axiom_xml_reader_get_attribute_namespace_by_number(om_builder->parser,
                env, i);

        prefix = axiom_xml_reader_get_attribute_prefix_by_number(om_builder->parser,
            env, i);
        if (uri)
        {
            if (axutil_strcmp(uri, "") != 0)
            {
                axiom_element_t *om_ele = NULL;
                om_ele = (axiom_element_t*)axiom_node_get_data_element(element_node, env);
                if (om_ele)
                {
                    ns = axiom_element_find_namespace(om_ele ,
                        env , element_node, uri, prefix);

                    /* newly added to handle "xml:*" attributes" (axutil_strcmp(prefix, "xml") == 0) && */
                    if (!ns)
                    {
                        ns = axiom_namespace_create(env, uri, prefix);
                    }
                }
            }
        }

        attr_name = axiom_xml_reader_get_attribute_name_by_number(
            om_builder->parser, env, i);

#ifdef WIN32	
		attr_name_str = axutil_string_create(env, attr_name);
		axiom_xml_reader_xml_free(om_builder->parser, env, attr_name);
#else
		attr_name_str = axutil_string_create_assume_ownership(env, &attr_name);
#endif
       
        attr_value = axiom_xml_reader_get_attribute_value_by_number(
            om_builder->parser, env, i);


#ifdef WIN32	
		attr_value_str = axutil_string_create(env, attr_value);
		axiom_xml_reader_xml_free(om_builder->parser, env, attr_value);
#else
		attr_value_str = axutil_string_create_assume_ownership(env, &attr_value);
#endif

        if (attr_name)
        {
            attribute = axiom_attribute_create_str(env, attr_name_str, attr_value_str, ns);
            if (!attribute)
            {
                return AXIS2_FAILURE;
            }

            temp_ele = (axiom_element_t*)axiom_node_get_data_element(element_node, env);
            if (temp_ele)
            {
                status = axiom_element_add_attribute(temp_ele,
                    env, attribute, element_node);
            }
        }
        if (uri)
        {
            axiom_xml_reader_xml_free(om_builder->parser, env, uri);
        }
        if (prefix)
        {
            axiom_xml_reader_xml_free(om_builder->parser, env, prefix);
        }
        if (attr_name_str)
        {
            axutil_string_free(attr_name_str, env);
        }
        if (attr_value_str)
        {
            axutil_string_free(attr_value_str, env);
        }
        ns = NULL;
    }
    return status;
}

axiom_node_t *
axiom_stax_builder_create_om_text(axiom_stax_builder_t * om_builder,
    const axutil_env_t *env)
{
    axis2_char_t *temp_value = NULL;
	axutil_string_t *temp_value_str = NULL;
    axiom_node_t *node = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (!om_builder->lastnode)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_INVALID_BUILDER_STATE_LAST_NODE_NULL, AXIS2_FAILURE);
        return NULL;
    }
    temp_value = axiom_xml_reader_get_value(om_builder->parser, env);
    if (!temp_value)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_XML_READER_VALUE_NULL,
            AXIS2_FAILURE);
        return NULL;
    }

	    
#ifdef WIN32	
	temp_value_str = axutil_string_create(env, temp_value);
	axiom_xml_reader_xml_free(om_builder->parser, env, temp_value);
#else
    temp_value_str = axutil_string_create_assume_ownership(env, &temp_value);
#endif
	

    if (axiom_node_is_complete(om_builder->lastnode, env))
    {
        axiom_text_create_str(env,
            axiom_node_get_parent(om_builder->lastnode, env),
            temp_value_str, &node);

    }
    else
    {
        axiom_text_create_str(env, om_builder->lastnode, temp_value_str, &node);
    }

    axiom_node_set_complete(node , env, AXIS2_TRUE);
    om_builder->lastnode = node;

	axutil_string_free(temp_value_str, env);
    return node;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_stax_builder_discard_current_element(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    axiom_node_t *element = NULL;
    axiom_node_t *prev_node = NULL;
    axiom_node_t *parent = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    element = om_builder->lastnode;

    if (axiom_node_is_complete(element, env) || !(om_builder->cache))
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_INVALID_BUILDER_STATE_CANNOT_DISCARD, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    om_builder->cache = AXIS2_FALSE;
    do
    {
        while (axiom_xml_reader_next(om_builder->parser, env)
            != AXIOM_XML_READER_END_ELEMENT);
    }
    while (!(axiom_node_is_complete(element, env)));

    /*All children of this element is pulled now */

    prev_node = axiom_node_get_previous_sibling(element, env);
    if (prev_node)
    {
        axiom_node_free_tree(axiom_node_get_next_sibling(prev_node, env), env);
        axiom_node_set_next_sibling(prev_node, env, NULL);
    }
    else
    {
        parent = axiom_node_get_parent(element, env);
        axiom_node_free_tree(axiom_node_get_first_child(parent, env), env);
        axiom_node_set_first_child(parent, env, NULL);
        om_builder->lastnode = parent;
    }
    om_builder->cache = AXIS2_TRUE;

    return AXIS2_SUCCESS;
}

axis2_status_t
axiom_stax_builder_process_namespaces(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env,
    axiom_node_t *node,
    int is_soap_element)
{
    axis2_status_t status = AXIS2_SUCCESS;
    int namespace_count = 0;
    axiom_namespace_t *om_ns = NULL;
    /* temp values */
    axis2_char_t *temp_prefix = NULL;
    axis2_char_t *temp_ns_prefix = NULL;
    axis2_char_t *temp_ns_uri    = NULL;
    axutil_string_t *temp_ns_prefix_str = NULL;
    axutil_string_t *temp_ns_uri_str = NULL;

    int i = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    namespace_count = axiom_xml_reader_get_namespace_count(om_builder->parser, env);
    for (i = 1; i <= namespace_count; i++)
    {
        temp_ns_prefix = axiom_xml_reader_get_namespace_prefix_by_number(
            om_builder->parser, env, i);

        temp_ns_uri = axiom_xml_reader_get_namespace_uri_by_number(
            om_builder->parser, env , i);

#ifdef WIN32	
		temp_ns_prefix_str = axutil_string_create(env, temp_ns_prefix);
#else
		temp_ns_prefix_str = axutil_string_create_assume_ownership(env, &temp_ns_prefix);
#endif

#ifdef WIN32
		temp_ns_uri_str = axutil_string_create(env, temp_ns_uri);
#else
        temp_ns_uri_str = axutil_string_create_assume_ownership(env, &temp_ns_uri);
#endif
        if (!temp_ns_prefix || axutil_strcmp(temp_ns_prefix, "xmlns") == 0)
        {
            /** default namespace case */
            /** !temp_ns_prefix is for guththila */
            axiom_element_t *om_ele = NULL;
            temp_ns_prefix_str = axutil_string_create(env, "");
            om_ele = (axiom_element_t *)axiom_node_get_data_element(node, env);

            om_ns = axiom_namespace_create_str(env, temp_ns_uri_str, temp_ns_prefix_str);
            if (!om_ns || !om_ele)
            {
                return AXIS2_FAILURE;
            }

            status = axiom_element_declare_namespace(om_ele, env, node, om_ns);

            if (!status)
            {
                axiom_namespace_free(om_ns, env);
                om_ns = NULL;
            }
        }
        else
        {
            axiom_element_t *om_ele = NULL;
            axis2_char_t *prefix = NULL;
            om_ele = (axiom_element_t *)axiom_node_get_data_element(node, env);

            om_ns = axiom_namespace_create_str(env, temp_ns_uri_str, temp_ns_prefix_str);
            if (!om_ns || !om_ele)
            {
                return AXIS2_FAILURE;
            }

            status = axiom_element_declare_namespace_assume_param_ownership(om_ele,
                env, om_ns);
            prefix = axiom_namespace_get_prefix(om_ns, env);
            axutil_hash_set(om_builder->declared_namespaces,
                prefix, AXIS2_HASH_KEY_STRING, om_ns);
        }
        axutil_string_free(temp_ns_uri_str, env);
        axutil_string_free(temp_ns_prefix_str, env);
#ifdef WIN32	
		axiom_xml_reader_xml_free(om_builder->parser, env, temp_ns_uri);
		axiom_xml_reader_xml_free(om_builder->parser, env, temp_ns_prefix);
#endif
        if (!om_ns)
        {
            /* something went wrong */
            return AXIS2_FAILURE;
        }
    }
    /* set own namespace */
    temp_prefix = axiom_xml_reader_get_prefix(om_builder->parser, env);
    if (temp_prefix)
    {
        om_ns = axutil_hash_get(om_builder->declared_namespaces,
            temp_prefix, AXIS2_HASH_KEY_STRING);

        if (om_ns)
        {
            axiom_element_t *om_ele = NULL;
            om_ele = (axiom_element_t *)axiom_node_get_data_element(node, env);
            if (om_ele)
            {
                axiom_element_set_namespace_assume_param_ownership(om_ele, env, om_ns);
            }
        }
        else
        {
            AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_DOCUMENT_STATE_UNDEFINED_NAMESPACE, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }
    if (temp_prefix)
    {
        axiom_xml_reader_xml_free(om_builder->parser, env, temp_prefix);
    }
    return status;
}

axiom_node_t *
axiom_stax_builder_create_om_element(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    axiom_node_t *element_node = NULL;
    axiom_element_t *om_ele = NULL;
    axis2_char_t *temp_localname = NULL;
    axutil_string_t *temp_localname_str = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, om_builder, NULL);

    temp_localname  = axiom_xml_reader_get_name(om_builder->parser, env);

    if (!temp_localname)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_XML_READER_ELEMENT_NULL,
            AXIS2_FAILURE);
        return NULL;
    }
    
#ifdef WIN32	
	temp_localname_str = axutil_string_create(env, temp_localname);
	axiom_xml_reader_xml_free(om_builder->parser, env, temp_localname);
#else
    temp_localname_str = axutil_string_create_assume_ownership(env, &temp_localname);
#endif
    
    om_builder->element_level++;

    if (!(om_builder->lastnode))
    {
        om_ele = axiom_element_create_str(env , NULL, temp_localname_str, NULL, &element_node);
        if (!om_ele)
        {
            return NULL;
        }

        om_builder->root_node = element_node;

        axiom_node_set_builder(element_node, env, om_builder);

        if (om_builder->document)
        {
            axiom_node_set_document(element_node, env, om_builder->document);
            axiom_document_set_root_element(om_builder->document,
                env, element_node);
        }
    }
    else if (axiom_node_is_complete(om_builder->lastnode, env))
    {
        om_ele = axiom_element_create_str(env,
            axiom_node_get_parent(om_builder->lastnode, env),
            temp_localname_str, NULL, &element_node);
        if (!om_ele)
        {
            return NULL;
        }

        if (element_node)
        {
            axiom_node_set_next_sibling(om_builder->lastnode,
                env, element_node);
            axiom_node_set_previous_sibling(element_node,
                env, om_builder->lastnode);
            axiom_node_set_document(element_node,
                env, om_builder->document);
            axiom_node_set_builder(element_node,
                env, om_builder);
        }
    }
    else
    {
        om_ele = axiom_element_create_str(env, om_builder->lastnode,
            temp_localname_str, NULL, &element_node);
        if (element_node)
        {
            axiom_node_set_first_child(om_builder->lastnode,
                env, element_node);
            axiom_node_set_parent(element_node , env, om_builder->lastnode);
            axiom_node_set_document(element_node, env, om_builder->document);
            axiom_node_set_builder(element_node, env, om_builder);
        }
    }

    axutil_string_free(temp_localname_str, env);

    /** order of processing namespaces first is important */
    axiom_stax_builder_process_namespaces(om_builder, env, element_node, 0);
    axiom_stax_builder_process_attributes(om_builder, env, element_node);

    om_builder->lastnode = element_node;

    return element_node;
}


axiom_node_t *
axiom_stax_builder_create_om_comment(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    axiom_node_t *comment_node = NULL;
    axis2_char_t *comment_value = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    comment_value  = axiom_xml_reader_get_value(om_builder->parser, env);
    if (!comment_value)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_XML_READER_ELEMENT_NULL,
            AXIS2_FAILURE);
        return NULL;
    }

    if (!(om_builder->lastnode))
    {
        /* do nothing */
        axiom_xml_reader_xml_free(om_builder->parser , env, comment_value);
        return NULL;
    }
    else if (axiom_node_is_complete(om_builder->lastnode, env))
    {
        axiom_comment_create(env,
            axiom_node_get_parent(om_builder->lastnode, env),
            comment_value , &comment_node);

        axiom_node_set_next_sibling(om_builder->lastnode, env, comment_node);
        axiom_node_set_previous_sibling(comment_node , env,
            om_builder->lastnode);
        axiom_node_set_builder(comment_node, env, om_builder);
        axiom_node_set_document(comment_node, env, om_builder->document);
    }
    else
    {
        axiom_comment_create(env, om_builder->lastnode,
            comment_value , &comment_node);

        axiom_node_set_first_child(om_builder->lastnode , env, comment_node);
        axiom_node_set_parent(comment_node , env, om_builder->lastnode);
        axiom_node_set_builder(comment_node, env, om_builder);
        axiom_node_set_document(comment_node, env, om_builder->document);
    }

    om_builder->element_level++;
    axiom_xml_reader_xml_free(om_builder->parser , env, comment_value);

    om_builder->lastnode = comment_node;

    return comment_node;
}

axiom_node_t *
axiom_stax_builder_create_om_doctype(axiom_stax_builder_t * om_builder,
    const axutil_env_t *env)
{
    axiom_node_t *doctype_node = NULL;
    axis2_char_t *doc_value = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    doc_value = axiom_xml_reader_get_dtd(om_builder->parser, env);
    if (!doc_value)
    {
        return NULL;
    }
    if (!(om_builder->lastnode))
    {
        axiom_doctype_create(env, NULL, doc_value, &doctype_node);
        if (om_builder->document)
        {
            axiom_document_set_root_element(om_builder->document,
                env, doctype_node);
        }
    }
    om_builder->lastnode = doctype_node;
    axiom_xml_reader_xml_free(om_builder->parser, env, doc_value);
    return doctype_node;
}

axiom_node_t *
axiom_stax_builder_create_om_processing_instruction(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    axiom_node_t *pi_node = NULL;
    axis2_char_t *target = NULL;
    axis2_char_t *value  = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    target = axiom_xml_reader_get_pi_target(om_builder->parser, env);
    value  = axiom_xml_reader_get_pi_data(om_builder->parser, env);
    if (!target)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_XML_READER_ELEMENT_NULL,
            AXIS2_FAILURE);
        return NULL;
    }
    if (!(om_builder->lastnode))
    {
        /* do nothing */
        axiom_xml_reader_xml_free(om_builder->parser , env, target);
        axiom_xml_reader_xml_free(om_builder->parser , env, value);
        return NULL;
    }
    else if (axiom_node_is_complete(om_builder->lastnode, env) ||
        (axiom_node_get_node_type(om_builder->lastnode, env) == AXIOM_TEXT))
    {
        axiom_processing_instruction_create(env,
            axiom_node_get_parent(om_builder->lastnode, env),
            target, value, &pi_node);

        axiom_node_set_next_sibling(om_builder->lastnode, env, pi_node);
        axiom_node_set_previous_sibling(pi_node , env, om_builder->lastnode);
    }
    else
    {
        axiom_processing_instruction_create(env, om_builder->lastnode,
            target, value, &pi_node);
        axiom_node_set_first_child(om_builder->lastnode , env, pi_node);
        axiom_node_set_parent(pi_node , env, om_builder->lastnode);
    }

    om_builder->element_level++;

    if (target)
    {
        axiom_xml_reader_xml_free(om_builder->parser , env, target);
    }
    if (value)
    {
        axiom_xml_reader_xml_free(om_builder->parser , env, value);
    }

    om_builder->lastnode = pi_node;
    return pi_node;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_stax_builder_end_element(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    axiom_node_t *parent = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    om_builder->element_level--;

    if (om_builder->lastnode)
    {
        if (axiom_node_is_complete((om_builder->lastnode), env))
        {
            parent = axiom_node_get_parent((om_builder->lastnode), env);
            if (parent)
            {
                axiom_node_set_complete(parent, env, AXIS2_TRUE);
                om_builder->lastnode = parent;
            }
        }
        else
        {
            axiom_node_set_complete((om_builder->lastnode), env, AXIS2_TRUE);
        }
    }
    if (om_builder->root_node)
    {
        if (axiom_node_is_complete(om_builder->root_node , env))
        {
            om_builder->done = AXIS2_TRUE;
        }
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axiom_node_t * AXIS2_CALL
axiom_stax_builder_next(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    int token = 0;
    axiom_node_t *node = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    if (!om_builder->parser)
    {
        return NULL;
    }
    do
    {
        if (om_builder->done)
        {
            AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_BUILDER_DONE_CANNOT_PULL, AXIS2_FAILURE);
            return NULL;
        }

        token = axiom_xml_reader_next(om_builder->parser, env);
        if (token == -1)
        {
            return NULL;
        }

        om_builder->current_event = token;

        if (!(om_builder->cache))
        {
            return NULL;
        }

        switch (token)
        {
            case AXIOM_XML_READER_START_DOCUMENT:
                /*Do nothing */
                break;

            case AXIOM_XML_READER_START_ELEMENT:
                node = axiom_stax_builder_create_om_element(om_builder, env);
                break;

            case AXIOM_XML_READER_EMPTY_ELEMENT:
                node = axiom_stax_builder_create_om_element(om_builder, env);

            case AXIOM_XML_READER_END_ELEMENT:
                axiom_stax_builder_end_element(om_builder, env);
                break;


            case AXIOM_XML_READER_SPACE:
                node = axiom_stax_builder_create_om_text(om_builder, env);
                break;

            case AXIOM_XML_READER_CHARACTER:
                node = axiom_stax_builder_create_om_text(om_builder, env);
                break;

            case AXIOM_XML_READER_ENTITY_REFERENCE:
                break;

            case AXIOM_XML_READER_COMMENT:

                node = axiom_stax_builder_create_om_comment(om_builder, env);
                    axiom_stax_builder_end_element(om_builder, env);
                break;

            case AXIOM_XML_READER_PROCESSING_INSTRUCTION:

                node = 
                    axiom_stax_builder_create_om_processing_instruction(om_builder,
                        env);
                axiom_stax_builder_end_element(om_builder, env);
                break;

            case AXIOM_XML_READER_CDATA:
                break;

            case AXIOM_XML_READER_DOCUMENT_TYPE:
                break;

            default:
                break;
        }
    }
    while (!node);
    return node;
}

AXIS2_EXTERN void AXIS2_CALL 
axiom_stax_builder_free(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (!om_builder)
    {
        return;
    }
    if (om_builder->declared_namespaces)
    {
        axutil_hash_free(om_builder->declared_namespaces, env);
        om_builder->declared_namespaces = NULL;
    }

    if (om_builder->document)
    {
        axiom_document_free(om_builder->document, env);
        om_builder->document = NULL;
    }
    else
    {
        if (om_builder->root_node)
        {
            axiom_node_free_tree(om_builder->root_node, env);
            om_builder->root_node = NULL;
        }
    }

	if (om_builder->parser)
    {
        axiom_xml_reader_free(om_builder->parser, env);
        om_builder->parser = NULL;
    }

    AXIS2_FREE(env->allocator, om_builder);
    
    return;
}

AXIS2_EXTERN void AXIS2_CALL 
axiom_stax_builder_free_self(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (!om_builder)
    {
        return;
    }
    if (om_builder->declared_namespaces)
    {
        axutil_hash_free(om_builder->declared_namespaces, env);
        om_builder->declared_namespaces = NULL;
    }

	if (om_builder->parser)
    {
        axiom_xml_reader_free(om_builder->parser, env);
        om_builder->parser = NULL;
    }
	if (om_builder->document)
    {
        axiom_document_free_self(om_builder->document, env);
        om_builder->document = NULL;
    }

    AXIS2_FREE(env->allocator, om_builder);
    
    return;
}


AXIS2_EXTERN axiom_document_t* AXIS2_CALL
axiom_stax_builder_get_document(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    return om_builder->document;
}

/**
    This is an internal function
*/

AXIS2_EXTERN int AXIS2_CALL
axiom_stax_builder_get_current_event(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    AXIS2_PARAM_CHECK(env->error, om_builder, AXIS2_FAILURE);
    return om_builder->current_event;
}

/**
 This is an internal function
*/
AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_stax_builder_get_lastnode(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    AXIS2_PARAM_CHECK(env->error, om_builder, NULL);
    return om_builder->lastnode;
}

/**
This is an internal function
*/
AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_stax_builder_is_complete(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    return om_builder->done;
}

/**
This is an internal function to be used by soap om_builder only
*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_stax_builder_set_lastnode(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env,
    axiom_node_t *om_node)
{
    AXIS2_PARAM_CHECK(env->error, om_node, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_builder, AXIS2_FAILURE);

    om_builder->lastnode = om_node;
    return AXIS2_SUCCESS;
}

/**
internal function for soap om_builder only
*/
AXIS2_EXTERN int AXIS2_CALL
axiom_stax_builder_get_element_level(axiom_stax_builder_t* om_builder,
    const axutil_env_t *env)
{
    AXIS2_PARAM_CHECK(env->error, om_builder, -1);
    return om_builder->element_level;
}

/**
internal function for soap om_builder only
*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_stax_builder_set_element_level(axiom_stax_builder_t* om_builder,
    const axutil_env_t *env,
    int element_level)
{
    AXIS2_PARAM_CHECK(env->error, om_builder, AXIS2_FAILURE);
    om_builder->element_level = element_level;
    return AXIS2_SUCCESS;
}

int AXIS2_CALL
axiom_stax_builder_next_with_token(axiom_stax_builder_t *om_builder,
    const axutil_env_t *env)
{
    int token = 0;
    void *val = NULL;

    if (!om_builder)
    {
        return -1;
    }

    if (om_builder->done)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_BUILDER_DONE_CANNOT_PULL, AXIS2_FAILURE);
        return -1;
    }

    if (!om_builder->parser)
    {
        return -1;
    }

    token = axiom_xml_reader_next(om_builder->parser, env);

    if (token == -1)
    {
        om_builder->done = AXIS2_TRUE;
        return -1;
    }

    if (!(om_builder->cache))
    {
        return -1;
    }
    switch (token)
    {
        case AXIOM_XML_READER_START_DOCUMENT:
            /*Do nothing */
            break;

        case AXIOM_XML_READER_START_ELEMENT:
            val = axiom_stax_builder_create_om_element(om_builder, env);
            if (!val)
            {
                return -1;
            }
            break;

        case AXIOM_XML_READER_EMPTY_ELEMENT:
            val = axiom_stax_builder_create_om_element(
                om_builder, env);
            if (!val)
            {
                return -1;
            }
        case AXIOM_XML_READER_END_ELEMENT:
            axiom_stax_builder_end_element(om_builder, env);
            break;

        case AXIOM_XML_READER_SPACE:
            val = axiom_stax_builder_create_om_text(om_builder, env);
            if (!val)
            {
                return -1;
            }
            break;

        case AXIOM_XML_READER_CHARACTER:
            val = axiom_stax_builder_create_om_text(om_builder, env);
            if (!val)
            {
                return -1;
            }
            break;

        case AXIOM_XML_READER_ENTITY_REFERENCE:
            break;

        case AXIOM_XML_READER_COMMENT:
            val = axiom_stax_builder_create_om_comment(om_builder, env);
            if (!val)
            {
                return -1;
            }
            axiom_stax_builder_end_element(om_builder, env);
            break;

        case AXIOM_XML_READER_PROCESSING_INSTRUCTION:
            val = axiom_stax_builder_create_om_processing_instruction(om_builder,
                env);
            if (!val)
            {
                return -1;
            }
            axiom_stax_builder_end_element(om_builder, env);
            break;

        case AXIOM_XML_READER_CDATA:
            break;

        case AXIOM_XML_READER_DOCUMENT_TYPE:
            break;

        default:
            break;
    }
    return token;
}



