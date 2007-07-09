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

#include <libxml/xmlwriter.h>
#include <axutil_utils.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axiom_xml_writer.h>
#include <axutil_string.h>
#include <string.h>
#include <axutil_stack.h>
#include <axutil_hash.h>
#include <axutil_array_list.h>

/*******************************************************************************/

#define ENCODING "ISO-8859-1"

#define AXIS2_XMLNS_NAMESPACE_URI "http://www.w3.org/XML/1998/namespace"
#define AXIS2_XMLNS_PREFIX "xml"

typedef struct uri_prefix_element
{
    axis2_char_t *prefix;

    axis2_char_t *uri;

    axis2_char_t *real_prefix;

    axis2_char_t *key;

}
uri_prefix_element_t;

typedef struct axis2_libxml2_writer_wrapper_impl
{
    axiom_xml_writer_t writer;

    xmlTextWriterPtr xml_writer;

    xmlBufferPtr buffer;

    xmlDocPtr doc;

    int writer_type;

    axis2_char_t *encoding;

    int is_prefix_defaulting;

    int compression;

    axutil_stack_t *stack;

    axis2_bool_t in_empty_element;

    axis2_bool_t in_start_element;

    axutil_hash_t *uri_prefix_map;

    uri_prefix_element_t *default_lang_namespace;

} axis2_libxml2_writer_wrapper_impl_t;


#define AXIS2_INTF_TO_IMPL(p) ((axis2_libxml2_writer_wrapper_impl_t*)p)

void AXIS2_CALL
axis2_libxml2_writer_wrapper_free(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_end_start_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_element_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_element_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_empty_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_empty_element_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_empty_element_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_end_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_end_document(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_attribute(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_attribute_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value,
    axis2_char_t *namespace_uri);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_attribute_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *prefix,
    axis2_char_t *namespace_uri);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_default_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *namespace_uri);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_comment(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *value);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_processing_instruction(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *target);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_processing_instruction_data(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *target,
    axis2_char_t *data);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_cdata(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *data);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_dtd(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *dtd);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_entity_ref(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *name);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_document(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_document_with_version(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *version);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_document_with_version_encoding(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *encoding,
    axis2_char_t *version);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_characters(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *text);

axis2_char_t *AXIS2_CALL
axis2_libxml2_writer_wrapper_get_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_set_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *prefix,
    axis2_char_t *uri);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_set_default_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_encoded(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *text,
    int in_attr);

void* AXIS2_CALL
axis2_libxml2_writer_wrapper_get_xml(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

unsigned int AXIS2_CALL 
axis2_libxml2_writer_wrapper_get_xml_size(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_flush(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

int AXIS2_CALL
axis2_libxml2_writer_wrapper_get_type(axiom_xml_writer_t *writer,
    const axutil_env_t *env);
    
axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_raw(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *content);

static axis2_status_t
axis2_libxml2_writer_wrapper_push(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    const axis2_char_t *uri,
    const axis2_char_t *prefix);

static axis2_bool_t
axis2_libxml2_writer_wrapper_is_namespace_declared(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *key);

static void
uri_prefix_element_free(uri_prefix_element_t *up_element,
    const axutil_env_t *env);

static uri_prefix_element_t *
uri_prefix_element_create(const axutil_env_t *env,
    const axis2_char_t *uri,
    const axis2_char_t *prefix,
    const axis2_char_t *real_prefix,
    const axis2_char_t *key);

static void
create_key_from_uri_prefix(const axutil_env_t *env,
    const axis2_char_t *uri,
    const axis2_char_t *prefix,
    axis2_char_t *array);

static axis2_char_t*
axis2_libxml2_writer_wrapper_find_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri);

static uri_prefix_element_t*
axis2_libxml2_writer_wrapper_find_prefix_in_context(axutil_array_list_t  *context,
    const axutil_env_t *env,
    axis2_char_t *uri);

static const axiom_xml_writer_ops_t axiom_xml_writer_ops_var = {
    axis2_libxml2_writer_wrapper_free,
    axis2_libxml2_writer_wrapper_write_start_element,
    axis2_libxml2_writer_wrapper_end_start_element,
    axis2_libxml2_writer_wrapper_write_start_element_with_namespace,
    axis2_libxml2_writer_wrapper_write_start_element_with_namespace_prefix,
    axis2_libxml2_writer_wrapper_write_empty_element,
    axis2_libxml2_writer_wrapper_write_empty_element_with_namespace,
    axis2_libxml2_writer_wrapper_write_empty_element_with_namespace_prefix,
    axis2_libxml2_writer_wrapper_write_end_element,
    axis2_libxml2_writer_wrapper_write_end_document,
    axis2_libxml2_writer_wrapper_write_attribute,
    axis2_libxml2_writer_wrapper_write_attribute_with_namespace,
    axis2_libxml2_writer_wrapper_write_attribute_with_namespace_prefix,
    axis2_libxml2_writer_wrapper_write_namespace,
    axis2_libxml2_writer_wrapper_write_default_namespace,
    axis2_libxml2_writer_wrapper_write_comment,
    axis2_libxml2_writer_wrapper_write_processing_instruction,
    axis2_libxml2_writer_wrapper_write_processing_instruction_data,
    axis2_libxml2_writer_wrapper_write_cdata,
    axis2_libxml2_writer_wrapper_write_dtd,
    axis2_libxml2_writer_wrapper_write_entity_ref,
    axis2_libxml2_writer_wrapper_write_start_document,
    axis2_libxml2_writer_wrapper_write_start_document_with_version,
    axis2_libxml2_writer_wrapper_write_start_document_with_version_encoding,
    axis2_libxml2_writer_wrapper_write_characters,
    axis2_libxml2_writer_wrapper_get_prefix,
    axis2_libxml2_writer_wrapper_set_prefix,
    axis2_libxml2_writer_wrapper_set_default_prefix,
    axis2_libxml2_writer_wrapper_write_encoded,
    axis2_libxml2_writer_wrapper_get_xml,
    axis2_libxml2_writer_wrapper_get_xml_size,
    axis2_libxml2_writer_wrapper_get_type,
    axis2_libxml2_writer_wrapper_write_raw,
    axis2_libxml2_writer_wrapper_flush
};

AXIS2_EXTERN axiom_xml_writer_t *AXIS2_CALL
axiom_xml_writer_create(const axutil_env_t *env,
    axis2_char_t *filename,
    axis2_char_t *encoding,
    int is_prefix_default,
    int compression)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    writer_impl = (axis2_libxml2_writer_wrapper_impl_t *)AXIS2_MALLOC(env->allocator,
        sizeof(axis2_libxml2_writer_wrapper_impl_t));
    if (!writer_impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    writer_impl->xml_writer = xmlNewTextWriterFilename(filename, compression);

    if (!(writer_impl->xml_writer))
    {
        AXIS2_FREE(env->allocator, writer_impl);
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_CREATING_XML_STREAM_WRITER, AXIS2_FAILURE);
        return NULL;
    }
    writer_impl->buffer = NULL;
    writer_impl->encoding = NULL;
    writer_impl->compression = 0;
    writer_impl->in_empty_element = AXIS2_FALSE;
    writer_impl->in_start_element = AXIS2_FALSE;
    writer_impl->stack = NULL;
    writer_impl->uri_prefix_map = NULL;
    writer_impl->default_lang_namespace = NULL;

    writer_impl->writer_type = AXIS2_XML_PARSER_TYPE_FILE;
    writer_impl->compression = compression;

    if (encoding)
    {
        writer_impl->encoding = axutil_strdup(env, encoding);
    }
    else
    {
        writer_impl->encoding = axutil_strdup(env, ENCODING);
    }

    writer_impl->uri_prefix_map = axutil_hash_make(env);
    if (!(writer_impl->uri_prefix_map))
    {
        axis2_libxml2_writer_wrapper_free(&(writer_impl->writer), env);
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    writer_impl->writer.ops = &axiom_xml_writer_ops_var;
    return &(writer_impl->writer);
}

AXIS2_EXTERN axiom_xml_writer_t *AXIS2_CALL
axiom_xml_writer_create_for_memory(const axutil_env_t *env,
    axis2_char_t *encoding,
    int is_prefix_default,
    int compression,
    int type)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    writer_impl = (axis2_libxml2_writer_wrapper_impl_t *)AXIS2_MALLOC(env->allocator,
        sizeof(axis2_libxml2_writer_wrapper_impl_t));
    if (!writer_impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    writer_impl->encoding = NULL;
    writer_impl->buffer = NULL;
    writer_impl->doc = NULL;
    writer_impl->in_empty_element = AXIS2_FALSE;
    writer_impl->in_start_element = AXIS2_FALSE;
    writer_impl->stack = NULL;
    writer_impl->uri_prefix_map = NULL;
    writer_impl->default_lang_namespace = NULL;
    writer_impl->compression = compression;

    if (AXIS2_XML_PARSER_TYPE_BUFFER == type)
    {
        writer_impl->writer_type = AXIS2_XML_PARSER_TYPE_BUFFER;
        writer_impl->buffer = xmlBufferCreate();
        if (!(writer_impl->buffer))
        {
            axis2_libxml2_writer_wrapper_free(&(writer_impl->writer), env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }

        writer_impl->xml_writer = xmlNewTextWriterMemory(writer_impl->buffer, 0);
    }
    else if (AXIS2_XML_PARSER_TYPE_DOC == type)
    {
        writer_impl->writer_type = AXIS2_XML_PARSER_TYPE_DOC;
        writer_impl->xml_writer = xmlNewTextWriterDoc(&writer_impl->doc, 0);
    }
    else
    {
        axis2_libxml2_writer_wrapper_free(&(writer_impl->writer), env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_XML_PARSER_INVALID_MEM_TYPE, AXIS2_FAILURE);
        return NULL;
    }

    if (!(writer_impl->xml_writer))
    {
        axis2_libxml2_writer_wrapper_free(&(writer_impl->writer), env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CREATING_XML_STREAM_WRITER , AXIS2_FAILURE);
        return NULL;
    }

    if (encoding)
    {
        writer_impl->encoding = axutil_strdup(env, encoding);
    }
    else
    {
        writer_impl->encoding = axutil_strdup(env, ENCODING);
    }

    writer_impl->uri_prefix_map = axutil_hash_make(env);
    if (!(writer_impl->uri_prefix_map))
    {
        axis2_libxml2_writer_wrapper_free(&(writer_impl->writer), env);
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    writer_impl->stack = axutil_stack_create(env);
    if (!(writer_impl->stack))
    {
        axis2_libxml2_writer_wrapper_free(&(writer_impl->writer), env);
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    writer_impl->writer.ops = &axiom_xml_writer_ops_var;

    return &(writer_impl->writer);
}

void AXIS2_CALL
axis2_libxml2_writer_wrapper_free(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    if(writer_impl->xml_writer)
    {
        xmlFreeTextWriter(writer_impl->xml_writer);
        writer_impl->xml_writer = NULL;
    }
    if (writer_impl->buffer)
    {
        xmlBufferFree(writer_impl->buffer);
        writer_impl->buffer = NULL;
    }
    if (writer_impl->encoding)
    {
        AXIS2_FREE(env->allocator, writer_impl->encoding);
        writer_impl->encoding = NULL;
    }
    if (writer_impl->uri_prefix_map)
    {
        axutil_hash_free(writer_impl->uri_prefix_map, env);
        writer_impl->uri_prefix_map = NULL;
    }
    if (writer_impl->stack)
    {
        axutil_stack_free(writer_impl->stack, env);
        writer_impl->stack = NULL;
    }
    if (writer_impl->default_lang_namespace)
    {
        uri_prefix_element_free(writer_impl->default_lang_namespace, env);
        writer_impl->default_lang_namespace = NULL;
    }

    AXIS2_FREE(env->allocator, writer_impl);
    writer_impl = NULL;
    return;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname)
{
    int status = 0;
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname, AXIS2_FAILURE);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    writer_impl->in_start_element = AXIS2_TRUE;

    status =  xmlTextWriterStartElement(writer_impl->xml_writer, (xmlChar *)localname);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_START_ELEMENT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_end_start_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    /* nothing to do ,
       it is automatically taken care by the libxml2 writer */
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_element_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, namespace_uri, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    status = xmlTextWriterStartElementNS(writer_impl->xml_writer,
        NULL, BAD_CAST localname, NULL);

    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_START_ELEMENT_WITH_NAMESPACE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_element_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname,  AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, namespace_uri, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, prefix, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    writer_impl->in_start_element = AXIS2_TRUE;

    status = xmlTextWriterStartElementNS(writer_impl->xml_writer,
        BAD_CAST prefix,
        BAD_CAST localname,
        BAD_CAST NULL);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_START_ELEMENT_WITH_NAMESPACE_PREFIX, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_empty_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname)
{
    int status = 0;
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname, AXIS2_FAILURE);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    status =  xmlTextWriterStartElement(writer_impl->xml_writer, (xmlChar *)localname);

    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_EMPTY_ELEMENT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    status =  xmlTextWriterEndElement(writer_impl->xml_writer);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_EMPTY_ELEMENT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_empty_element_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, namespace_uri, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    status = xmlTextWriterStartElementNS(writer_impl->xml_writer,
        NULL, BAD_CAST localname, BAD_CAST namespace_uri);

    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_EMPTY_ELEMENT_WITH_NAMESPACE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    status =  xmlTextWriterEndElement(writer_impl->xml_writer);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_EMPTY_ELEMENT_WITH_NAMESPACE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_empty_element_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname,  AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, namespace_uri, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, prefix, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    status = xmlTextWriterStartElementNS(writer_impl->xml_writer,
        BAD_CAST prefix,
        BAD_CAST localname,
        BAD_CAST NULL);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_START_ELEMENT_WITH_NAMESPACE_PREFIX, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    status =  xmlTextWriterEndElement(writer_impl->xml_writer);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_EMPTY_ELEMENT_WITH_NAMESPACE_PREFIX, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_end_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    writer_impl->in_start_element = AXIS2_FALSE;

    status = xmlTextWriterFullEndElement(writer_impl->xml_writer);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_END_ELEMENT,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_end_document(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    status =  xmlTextWriterEndDocument(writer_impl->xml_writer);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_END_DOCUMENT,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_attribute(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname, AXIS2_FAILURE);
    if (!value)
    {
        value = "";
    }

    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    status = xmlTextWriterWriteAttribute(writer_impl->xml_writer,
        BAD_CAST localname, BAD_CAST value);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_ATTRIBUTE,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_attribute_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value,
    axis2_char_t *namespace_uri)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname,  AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, namespace_uri, AXIS2_FAILURE);

    if (!value)
    {
        value = "";
    }

    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    status = xmlTextWriterWriteAttributeNS(writer_impl->xml_writer,
        NULL, BAD_CAST localname, BAD_CAST NULL,
        BAD_CAST value);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_ATTRIBUTE_WITH_NAMESPACE,  AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_attribute_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, localname,  AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, namespace_uri, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, prefix, AXIS2_FAILURE);

    if (!value)
    {
        value = "";
    } 
    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    status = xmlTextWriterWriteAttributeNS(writer_impl->xml_writer,
        BAD_CAST prefix , BAD_CAST localname,
        BAD_CAST NULL , BAD_CAST value);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_ATTRIBUTE_WITH_NAMESPACE_PREFIX,  AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

/** need to work on this */
axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_namespace(axiom_xml_writer_t *writer,
        const axutil_env_t *env,
        axis2_char_t *prefix,
        axis2_char_t *namespace_uri)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    char *xmlnsprefix = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, namespace_uri, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    if (prefix && (axutil_strcmp(prefix, "") != 0))
    {
        xmlnsprefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator,
            (sizeof(char) * (axutil_strlen(prefix) + 7)));
        sprintf(xmlnsprefix, "xmlns:%s", prefix);
    }
    else
    {
        xmlnsprefix = axutil_strdup(env, "xmlns");
    }

    status = xmlTextWriterWriteAttribute(writer_impl->xml_writer,
        BAD_CAST xmlnsprefix, BAD_CAST namespace_uri);
        AXIS2_FREE(env->allocator, xmlnsprefix);
        xmlnsprefix = NULL;

   if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_ATTRIBUTE_WITH_NAMESPACE_PREFIX,  AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    AXIS2_FREE(env->allocator, xmlnsprefix);
    xmlnsprefix = NULL;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_default_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *namespace_uri)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    axis2_char_t *xmlns = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, namespace_uri, AXIS2_FAILURE)

    xmlns = AXIS2_MALLOC(env->allocator,
        sizeof(axis2_char_t) * (strlen("xmlns") + 1));
    sprintf(xmlns, "xmlns");
    status = xmlTextWriterWriteAttribute(writer_impl->xml_writer,
        (const xmlChar *)xmlns , BAD_CAST namespace_uri);

    if (xmlns)
    {
        AXIS2_FREE(env->allocator, xmlns);
        xmlns = NULL;
    }
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_DEFAULT_NAMESPACE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_comment(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *value)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, value, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    status = xmlTextWriterWriteComment(writer_impl->xml_writer, BAD_CAST value);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_COMMENT,  AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_processing_instruction(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *target)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, target, AXIS2_FAILURE);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    status = xmlTextWriterStartPI(writer_impl->xml_writer, BAD_CAST target);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_PROCESSING_INSTRUCTION, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_processing_instruction_data(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *target,
    axis2_char_t *data)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, target, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, data, AXIS2_FAILURE);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    status = xmlTextWriterWritePI(writer_impl->xml_writer,
        BAD_CAST target,
        BAD_CAST data);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_PROCESSING_INSTRUCTION, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_cdata(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *data)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, data, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    status = xmlTextWriterWriteCDATA(writer_impl->xml_writer, BAD_CAST data);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_CDATA, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_dtd(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *dtd)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, dtd, AXIS2_FAILURE);

    status = xmlTextWriterStartDTD(writer_impl->xml_writer,
       BAD_CAST dtd, NULL, NULL);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_WRITING_DTD, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_entity_ref(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FAILURE);
    return AXIS2_FAILURE;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_document(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    axis2_libxml2_writer_wrapper_impl_t *wrapper_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    wrapper_impl = AXIS2_INTF_TO_IMPL(writer);
    status = xmlTextWriterStartDocument(wrapper_impl->xml_writer,
        NULL, NULL, NULL);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_START_DOCUMENT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_document_with_version(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *version)
{
    axis2_libxml2_writer_wrapper_impl_t *wrapper_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, version, AXIS2_FAILURE);

    wrapper_impl = AXIS2_INTF_TO_IMPL(writer);
    status = xmlTextWriterStartDocument(wrapper_impl->xml_writer,
        version , NULL, NULL);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_START_DOCUMENT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_start_document_with_version_encoding(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *version,
    axis2_char_t *encoding)
{
    axis2_libxml2_writer_wrapper_impl_t *wrapper_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    wrapper_impl = AXIS2_INTF_TO_IMPL(writer);
    status = xmlTextWriterStartDocument(wrapper_impl->xml_writer,
        version , encoding , NULL);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_START_DOCUMENT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_characters(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *text)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, text, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    status = xmlTextWriterWriteString(writer_impl->xml_writer,
        BAD_CAST text);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_START_DOCUMENT, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_char_t* AXIS2_CALL
axis2_libxml2_writer_wrapper_get_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    AXIS2_PARAM_CHECK(env->error, uri, NULL);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    if (!uri || axutil_strcmp(uri, "") == 0)
    {
        return NULL;
    }
    return axis2_libxml2_writer_wrapper_find_prefix(writer, env, uri);
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_set_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *prefix,
    axis2_char_t *uri)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;

    axis2_bool_t is_declared = AXIS2_FALSE;
    axis2_char_t key[1024];

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, prefix, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, uri, AXIS2_FAILURE);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    if (axutil_strcmp(uri, "") == 0)
    {
        return AXIS2_FAILURE;
    }

    create_key_from_uri_prefix(env, uri, prefix, key);

    is_declared = axis2_libxml2_writer_wrapper_is_namespace_declared(writer, env, key);
    if (!is_declared)
    {
        return axis2_libxml2_writer_wrapper_push(writer, env, uri, prefix);
    }
    return AXIS2_FAILURE;
}
axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_set_default_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri)
{
    axis2_bool_t is_declared = AXIS2_FALSE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, uri, AXIS2_FAILURE);
    if (axutil_strcmp(uri, "") == 0)
    {
        return AXIS2_FAILURE;
    }
    is_declared = axis2_libxml2_writer_wrapper_is_namespace_declared(writer, env, uri);
    if (!is_declared)
    {
        return axis2_libxml2_writer_wrapper_push(writer, env, uri, NULL);
    }
    return AXIS2_FAILURE;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_encoded(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *text,
    int in_attr)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, text, AXIS2_FAILURE);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    return AXIS2_FAILURE;
}

void* AXIS2_CALL
axis2_libxml2_writer_wrapper_get_xml(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    if (writer_impl->writer_type == AXIS2_XML_PARSER_TYPE_BUFFER)
    {
        int output_bytes = 0;
        output_bytes = xmlTextWriterFlush(writer_impl->xml_writer);
        return writer_impl->buffer->content;
    }
    else if (writer_impl->writer_type == AXIS2_XML_PARSER_TYPE_DOC)
    {
        return (void*)writer_impl->doc;
    }
    else if (writer_impl->writer_type == AXIS2_XML_PARSER_TYPE_FILE)
    {
        return NULL;
    }

    return NULL;
}

unsigned int AXIS2_CALL 
axis2_libxml2_writer_wrapper_get_xml_size(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    if (writer_impl->writer_type == AXIS2_XML_PARSER_TYPE_BUFFER)
    {
        return writer_impl->buffer->use;
    }
    else
    {
        return 0;
    }
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_flush(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    if (writer_impl->xml_writer)
    {
        int ret = 0;
        ret = xmlTextWriterFlush(writer_impl->xml_writer);
        if (ret > -1)
            return AXIS2_SUCCESS;
    }

    return AXIS2_FAILURE;
}

int AXIS2_CALL
axis2_libxml2_writer_wrapper_get_type(axiom_xml_writer_t *writer,
    const axutil_env_t *env)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    return writer_impl->writer_type;
}

static axis2_status_t
axis2_libxml2_writer_wrapper_push(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    const axis2_char_t *uri,
    const axis2_char_t *prefix)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    axutil_array_list_t *current_list = NULL;
    axis2_char_t key[1024];
    const axis2_char_t *temp_prefix = NULL;
    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    if (!prefix || axutil_strcmp(prefix, "") == 0)
    {
        temp_prefix = "default";
    }
    else
    {
        temp_prefix = prefix;
    }

    if (writer_impl->stack)
    {
        current_list = (axutil_array_list_t *)
            axutil_stack_get(writer_impl->stack, env);

        if (current_list)
        {
            uri_prefix_element_t *ele = NULL;
            create_key_from_uri_prefix(env, uri, prefix, key);

            ele = uri_prefix_element_create(env, uri , temp_prefix, prefix,  key);
            if (ele)
            {
                axutil_array_list_add(current_list, env, ele);
                axutil_hash_set(writer_impl->uri_prefix_map, ele->key,
                    AXIS2_HASH_KEY_STRING, ele->prefix);
            }
        }
    }
    return AXIS2_SUCCESS;
}

static axis2_bool_t
axis2_libxml2_writer_wrapper_is_namespace_declared(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    if (writer_impl->uri_prefix_map && NULL != key)
    {
        void *ret = NULL;
        ret = axutil_hash_get(writer_impl->uri_prefix_map, key,
            AXIS2_HASH_KEY_STRING);
        if (ret)
        {
            return AXIS2_TRUE;
        }
    }
    return AXIS2_FALSE;
}

static void
uri_prefix_element_free(uri_prefix_element_t *up_element,
    const axutil_env_t *env)
{
    if (up_element)
    {
        if (up_element->uri)
        {
            AXIS2_FREE(env->allocator, up_element->uri);
            up_element->uri = NULL;
        }
        if (up_element->prefix)
        {
            AXIS2_FREE(env->allocator, up_element->prefix);
            up_element->prefix = NULL;
        }
        if (up_element->key)
        {
            AXIS2_FREE(env->allocator, up_element->key);
            up_element->key = NULL;
        }
        if (up_element->real_prefix)
        {
            AXIS2_FREE(env->allocator, up_element->real_prefix);
            up_element->real_prefix = NULL;
        }
        AXIS2_FREE(env->allocator, up_element);
        up_element = NULL;
    }
    return;
}

static uri_prefix_element_t *
uri_prefix_element_create(const axutil_env_t *env,
    const axis2_char_t *uri,
    const axis2_char_t *prefix,
    const axis2_char_t *real_prefix,
    const axis2_char_t *key)
{
    uri_prefix_element_t *up_element = NULL;
    up_element = (uri_prefix_element_t *)AXIS2_MALLOC(env->allocator,
        sizeof(uri_prefix_element_t));

    if (!uri)
    {
        return NULL;
    }

    if (!up_element)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    up_element->key = NULL;
    up_element->prefix = NULL;
    up_element->uri = NULL;
    up_element->real_prefix = NULL;

    up_element->uri = axutil_strdup(env, uri);
    if (!up_element->uri)
    {
        uri_prefix_element_free(up_element, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    up_element->prefix = axutil_strdup(env, prefix);
    if (prefix && !up_element->prefix)
    {
        uri_prefix_element_free(up_element, env);
        AXIS2_ERROR_SET(env->error , AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    up_element->key = axutil_strdup(env, key);
    if (key  && !up_element->key)
    {
        uri_prefix_element_free(up_element, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    up_element->real_prefix = axutil_strdup(env, real_prefix);

    return up_element;
}

static void
create_key_from_uri_prefix(const axutil_env_t *env,
    const axis2_char_t *uri,
    const axis2_char_t *prefix,
    axis2_char_t *array)
{
    if (!prefix)
    {
        prefix = "";
    }
    sprintf(array, "%s%s%s", uri, "|", prefix);
}

static axis2_char_t*
axis2_libxml2_writer_wrapper_find_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int size = 0;
    int i = 0;

    writer_impl = AXIS2_INTF_TO_IMPL(writer);

    if (!writer_impl->stack)
    {
        return NULL;
    }
    size = axutil_stack_size(writer_impl->stack, env);
    if (size <= 0)
    {
        return NULL;
    }

    for (i = size - 1 ; i < 0; i --)
    {
        axutil_array_list_t *context = NULL;
        void *value = NULL;
        value = axutil_stack_get_at(writer_impl->stack, env, i);
        if (value)
        {
            uri_prefix_element_t *up_ele = NULL;
            context = (axutil_array_list_t *)value;
            up_ele =
                axis2_libxml2_writer_wrapper_find_prefix_in_context(context,
                    env, uri);
            if (up_ele)
            {
                return up_ele->real_prefix;
            }
        }
    }
    return NULL;
}

static uri_prefix_element_t*
axis2_libxml2_writer_wrapper_find_prefix_in_context(axutil_array_list_t  *context,
    const axutil_env_t *env,
    axis2_char_t *uri)
{
    int size = 0;
    int i = 0;
    if (!context)
    {
        return NULL;
    }
    size = axutil_array_list_size(context, env);
    for (i = 0; i < size; i++)
    {
        uri_prefix_element_t *ele = NULL;
        void *value = NULL;
        value = axutil_array_list_get(context, env, i);
        if (value)
        {
            ele = (uri_prefix_element_t*)value;
            if (ele->uri && axutil_strcmp(uri, ele->uri))
            {
                return ele;
            }
        }
    }
    return NULL;
}

axis2_status_t AXIS2_CALL
axis2_libxml2_writer_wrapper_write_raw(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *content)
{
    axis2_libxml2_writer_wrapper_impl_t *writer_impl = NULL;
    int status = 0;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, content, AXIS2_FAILURE);

    writer_impl = AXIS2_INTF_TO_IMPL(writer);
    status = xmlTextWriterWriteRaw(writer_impl->xml_writer, BAD_CAST content);
    if (status < 0)
    {
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_WRITING_DATA_SOURCE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

