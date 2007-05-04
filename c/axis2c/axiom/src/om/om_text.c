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

#include <axiom_text.h>
#include <axiom_output.h>
#include <axutil_string.h>
#include "axiom_node_internal.h"
#include <axiom_xml_writer.h>
#include <axiom_output.h>
#include <axiom_attribute.h>
#include <axiom_namespace.h>
#include <axutil_base64.h>

static const axis2_char_t *AXIS2_CALL
axiom_text_get_text(axiom_text_t *om_text,
    const axutil_env_t *env);

static axis2_bool_t AXIS2_CALL
axiom_text_get_is_binary(axiom_text_t *om_text,
    const axutil_env_t *env);

static axis2_status_t AXIS2_CALL
axiom_text_serialize_start_part(axiom_text_t *om_text,
    const axutil_env_t *env,
    axiom_output_t *om_output);

struct axiom_text
{
    /** Text value */
    axutil_string_t *value;
    /** The following fields are for MTOM */
    axis2_char_t *mime_type;
    axis2_bool_t optimize;
    const axis2_char_t *localname;
    axis2_bool_t is_binary;
    axis2_char_t *content_id;
    axiom_attribute_t *om_attribute;
    axiom_namespace_t *ns;
    axiom_data_handler_t *data_handler;
};

AXIS2_EXTERN axiom_text_t *AXIS2_CALL
axiom_text_create(const axutil_env_t *env,
    axiom_node_t * parent,
    const axis2_char_t * value,
    axiom_node_t **node)
{
    axiom_text_t *om_text = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, node, NULL);

    *node = axiom_node_create(env);

    if (!(*node))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    om_text = (axiom_text_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axiom_text_t));
    if (!om_text)
    {
        AXIS2_FREE(env->allocator, *node);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    om_text->mime_type = NULL;
    om_text->optimize = AXIS2_FALSE;
    om_text->localname = "Include";
    om_text->is_binary = AXIS2_FALSE;
    om_text->content_id = NULL;
    om_text->om_attribute = NULL;
    om_text->value = NULL;
    om_text->ns = NULL;
    om_text->data_handler = NULL;
    om_text->mime_type = NULL;

    om_text->ns = NULL;

    if (value)
    {
        om_text->value = axutil_string_create(env, value);
    }

    axiom_node_set_data_element((*node), env, om_text);
    axiom_node_set_node_type((*node), env, AXIOM_TEXT);
    axiom_node_set_complete((*node), env, AXIS2_FALSE);

    if (parent && axiom_node_get_node_type(parent, env) == AXIOM_ELEMENT)
    {
        axiom_node_add_child(parent, env, (*node));
    }

    return om_text;
}

AXIS2_EXTERN axiom_text_t *AXIS2_CALL
axiom_text_create_with_data_handler(const axutil_env_t *env,
    axiom_node_t * parent,
    axiom_data_handler_t* data_handler,
    axiom_node_t **node)
{

    axiom_text_t *om_text = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, data_handler, NULL);

    om_text = (axiom_text_t*)axiom_text_create(env, parent, NULL, node);
    if (!om_text)
    {
        return NULL;
    }
    om_text->optimize = AXIS2_TRUE;
    om_text->is_binary = AXIS2_TRUE;
    om_text->data_handler = data_handler;
    return om_text;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_text_free(axiom_text_t * om_text,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (om_text->value)
    {
        axutil_string_free(om_text->value, env);
    }

    if (om_text->ns)
    {
        axiom_namespace_free(om_text->ns, env);
    }

    if (om_text->content_id)
    {
        AXIS2_FREE(env->allocator, om_text->content_id);
    }

    if (om_text->om_attribute)
    {
        axiom_attribute_free(om_text->om_attribute, env);
    }

    if (om_text->data_handler)
    {
        axiom_data_handler_free(om_text->data_handler, env);
    }

    AXIS2_FREE(env->allocator, om_text);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_serialize(axiom_text_t *om_text,
    const axutil_env_t *env,
    axiom_output_t *om_output)
{
    int status = AXIS2_SUCCESS;
    axis2_char_t *attribute_value = NULL;
    const axis2_char_t *text = NULL;
    axiom_xml_writer_t *om_output_xml_writer = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_output, AXIS2_FAILURE);

    if (!axiom_text_get_is_binary(om_text, env))
    {
        if (om_text->value)
        {
            status = axiom_output_write(om_output, env,
                AXIOM_TEXT, 1, axutil_string_get_buffer(om_text->value, env));
        }
    }
    else
    {
        om_output_xml_writer = axiom_output_get_xml_writer(om_output, env);
        if (om_text->optimize)
        {
            if (!(axiom_text_get_content_id(om_text, env)))
            {
                axis2_char_t *content_id = axiom_output_get_next_content_id(om_output, env);
                if (content_id)
                {
                    om_text->content_id = axutil_strdup(env, content_id);
                }
            }

            attribute_value = axutil_stracat(env, "cid:", om_text->content_id);

            /*send binary as MTOM optimised*/
            if (om_text->om_attribute)
            {
                axiom_attribute_free(om_text->om_attribute, env);
                om_text->om_attribute = NULL;
            }

            om_text->om_attribute = axiom_attribute_create(env, "href", attribute_value, NULL);

            AXIS2_FREE(env->allocator, attribute_value);
            attribute_value = NULL;

            axiom_text_serialize_start_part(om_text, env, om_output);

            axiom_output_write_optimized(om_output, env, om_text);

            axiom_output_write(om_output, env, AXIOM_ELEMENT, 0);
        }
        else
        {
            text = axiom_text_get_text(om_text, env);
            axiom_xml_writer_write_characters(om_output_xml_writer, env, (axis2_char_t*)text);
        }
    }
    return status;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axiom_text_get_value(axiom_text_t *om_text,
    const axutil_env_t *env)
{
	if (om_text->value)
    {
        return axutil_string_get_buffer(om_text->value, env);
    }
    return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_set_value(axiom_text_t *om_text,
    const axutil_env_t *env,
    const axis2_char_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error , om_text, AXIS2_FAILURE);

    if (om_text->value)
    {
        axutil_string_free(om_text->value, env);
        om_text->value = NULL;
    }

	om_text->value = axutil_string_create(env, value);
    if (!om_text->value)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

/*Following has been implemented for the MTOM support*/

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_text_get_mime_type(axiom_text_t *om_text,
    const axutil_env_t *env)
{
    return om_text->mime_type;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_set_mime_type(axiom_text_t *om_text,
    const axutil_env_t *env,
    const axis2_char_t *mime_type)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error , om_text, AXIS2_FAILURE);
    if (om_text->mime_type)
    {
        AXIS2_FREE(env->allocator, om_text->mime_type);
    }
    om_text->mime_type = (axis2_char_t*)axutil_strdup(env, mime_type);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axiom_text_get_optimize(axiom_text_t *om_text,
    const axutil_env_t *env)
{
    return om_text->optimize;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_set_optimize(axiom_text_t *om_text,
    const axutil_env_t *env,
    const axis2_bool_t optimize)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error , om_text, AXIS2_FAILURE);
    om_text->optimize = optimize;
    return AXIS2_SUCCESS;
}

static axis2_bool_t AXIS2_CALL
axiom_text_get_is_binary(axiom_text_t *om_text,
    const axutil_env_t *env)
{
    return om_text->is_binary;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_set_is_binary(axiom_text_t *om_text,
    const axutil_env_t *env,
    const axis2_bool_t is_binary)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error , om_text, AXIS2_FAILURE);
    om_text->is_binary = is_binary;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axiom_text_get_localname(axiom_text_t *om_text,
    const axutil_env_t *env)
{
    return om_text->localname;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_text_get_content_id(axiom_text_t *om_text,
    const axutil_env_t *env)
{
    return om_text->content_id;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_set_content_id(axiom_text_t *om_text,
    const axutil_env_t *env,
    const axis2_char_t *content_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error , om_text, AXIS2_FAILURE);
    if (om_text->content_id)
    {
        AXIS2_FREE(env->allocator, om_text->content_id);
    }
    om_text->content_id = (axis2_char_t*)axutil_strdup(env, content_id);
    return AXIS2_SUCCESS;
}

static axis2_status_t AXIS2_CALL
axiom_text_serialize_start_part(axiom_text_t *om_text,
    const axutil_env_t *env,
    axiom_output_t *om_output)
{
    axis2_char_t *namespace_uri = NULL;
    axis2_char_t *prefix = NULL;
    const axis2_char_t *local_name = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    local_name = axiom_text_get_localname(om_text, env);

    om_text->ns = axiom_namespace_create(env,
        "http://www.w3.org/2004/08/xop/include", "xop");

    if (om_text->ns)
    {
        namespace_uri = axiom_namespace_get_uri(om_text->ns, env);
        if (namespace_uri)
        {
            prefix = axiom_namespace_get_prefix(om_text->ns, env);

            if (prefix)
            {
                axiom_output_write(om_output, env, AXIOM_ELEMENT, 3,
                    local_name, namespace_uri, prefix);
            }
            else
            {
                axiom_output_write(om_output, env, AXIOM_ELEMENT, 2,
                    local_name, namespace_uri);
            }
        }
        else
        {
            axiom_output_write(om_output, env, AXIOM_ELEMENT, 1,
                local_name);
        }
    }
    else
    {
        axiom_output_write(om_output, env, AXIOM_TEXT, 1,
            local_name);
    }
    if (om_text->om_attribute)
    {
        axiom_attribute_serialize(om_text->om_attribute, env, om_output);
    }
    if (om_text->ns)
    {
        axiom_namespace_serialize(om_text->ns, env, om_output);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_serialize_attribute(axiom_text_t *om_text,
    const axutil_env_t *env,
    axiom_output_t *om_output,
    axiom_attribute_t *om_attribute)
{
    axiom_xml_writer_t *xml_writer = NULL;
    axiom_namespace_t *om_namespace = NULL;

    axis2_char_t *namespace_uri = NULL;
    axis2_char_t *prefix = NULL;
    axis2_char_t *attribute_local_name = NULL;
    axis2_char_t *attribute_value = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    xml_writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0,
        AXIS2_XML_PARSER_TYPE_BUFFER);
    om_namespace = axiom_namespace_create(env, "" , "");

    namespace_uri = axiom_namespace_get_uri(om_text->ns, env);
    attribute_local_name = axiom_attribute_get_localname(om_attribute, env);

    if (om_namespace)
    {
        prefix = axiom_namespace_get_prefix(om_text->ns, env);
        attribute_value = axiom_attribute_get_value(om_attribute, env);
        if (prefix)
        {
            axiom_xml_writer_write_attribute(xml_writer, env, attribute_local_name, attribute_value);
        }
        else
        {
            axiom_xml_writer_write_attribute_with_namespace(xml_writer, env,
                attribute_local_name, attribute_value, namespace_uri);
        }
    }
    else
    {
        axiom_xml_writer_write_attribute(xml_writer, env, attribute_local_name, attribute_value);
    }
    axiom_namespace_free(om_namespace, env);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_serialize_namespace(axiom_text_t *om_text,
    const axutil_env_t *env,
    const axiom_namespace_t *om_namespace,
    axiom_output_t *om_output)
{
    axiom_xml_writer_t *xml_writer = NULL;
    axis2_char_t *namespace_uri = NULL;
    axis2_char_t *namespace_prefix = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    xml_writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0,
        AXIS2_XML_PARSER_TYPE_BUFFER);
    om_namespace = axiom_namespace_create(env, "" , "");

    if (om_namespace)
    {
        namespace_uri = axiom_namespace_get_uri(om_text->ns, env);
        namespace_prefix = axiom_namespace_get_prefix(om_text->ns, env);
        axiom_xml_writer_write_namespace(xml_writer, env, namespace_prefix, namespace_uri);
        axiom_xml_writer_set_prefix(xml_writer, env, namespace_prefix, namespace_uri);
    }
    return AXIS2_SUCCESS;
}

static const axis2_char_t *AXIS2_CALL
axiom_text_get_text(axiom_text_t *om_text,
    const axutil_env_t *env)
{
    if (om_text->value)
    {
        return axutil_string_get_buffer(om_text->value, env);
    }
    else
    {
        axis2_char_t *data_handler_stream = NULL;
        int data_handler_stream_size = 0;
        if (om_text->data_handler)
        {
            int encoded_len = 0;
            axis2_char_t *encoded_str = NULL;
            axiom_data_handler_read_from(om_text->data_handler, env,
                &data_handler_stream, &data_handler_stream_size);
            if (data_handler_stream)
            {
                encoded_len = axutil_base64_encode_len(data_handler_stream_size);
                encoded_str = AXIS2_MALLOC(env->allocator, encoded_len + 2);
                if (encoded_str)
                {
                    encoded_len = axutil_base64_encode(encoded_str,
                        data_handler_stream, data_handler_stream_size);
                    encoded_str[encoded_len] = '\0';
                    return encoded_str;
                }
            }
        }
    }
    return NULL;
}

AXIS2_EXTERN axiom_data_handler_t *AXIS2_CALL
axiom_text_get_data_handler(axiom_text_t *om_text,
    const axutil_env_t *env)
{
    return om_text->data_handler;
}

AXIS2_EXTERN axiom_text_t *AXIS2_CALL
    axiom_text_create_str(const axutil_env_t *env,
        axiom_node_t *parent,
        axutil_string_t *value,
        axiom_node_t ** node)
{
    axiom_text_t *om_text = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, node, NULL);

    *node = axiom_node_create(env);

    if (!(*node))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    om_text = (axiom_text_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axiom_text_t));
    if (!om_text)
    {
        AXIS2_FREE(env->allocator, *node);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    om_text->mime_type = NULL;
    om_text->optimize = AXIS2_FALSE;
    om_text->localname = "Include";
    om_text->is_binary = AXIS2_FALSE;
    om_text->content_id = NULL;
    om_text->om_attribute = NULL;
    om_text->value = NULL;
    om_text->ns = NULL;
    om_text->data_handler = NULL;
    om_text->mime_type = NULL;

    om_text->ns = NULL;

    if (value)
    {
        om_text->value = axutil_string_clone(value, env);
    }

    axiom_node_set_data_element((*node), env, om_text);
    axiom_node_set_node_type((*node), env, AXIOM_TEXT);
    axiom_node_set_complete((*node), env, AXIS2_FALSE);

    if (parent && axiom_node_get_node_type(parent, env) == AXIOM_ELEMENT)
    {
        axiom_node_add_child(parent, env, (*node));
    }

    return om_text;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_text_set_value_str(struct axiom_text *om_text,
    const axutil_env_t *env,
    axutil_string_t *value)
{
	if (om_text->value)
	{
		axutil_string_free(om_text->value, env);
		om_text->value = NULL;
	}
	if (value)
    {
        om_text->value = axutil_string_clone(value, env);
    }
	return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_string_t *AXIS2_CALL
axiom_text_get_value_str(struct axiom_text *om_text,
    const axutil_env_t *env)
{
	return om_text->value;
}

