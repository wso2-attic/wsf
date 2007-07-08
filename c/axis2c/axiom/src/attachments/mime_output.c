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


#include "axiom_mime_output.h"
#include "axiom_data_handler.h"
#include "axiom_mime_body_part.h"
#include <axutil_string.h>
#include <axiom_text.h>
#include <axiom_mime_const.h>

axis2_char_t AXIS2_CRLF[] =  { 13, 10 };

struct axiom_mime_output
{
    int dummy;
};

static axis2_status_t 
axis2_char_2_byte(const axutil_env_t *env, 
    axis2_char_t *char_buffer, 
    axis2_byte_t **byte_buffer, 
    int *byte_buffer_size);

static axiom_mime_body_part_t *
axis2_create_mime_body_part(axiom_text_t *text, 
    const axutil_env_t *env);

static axis2_status_t
axis2_write_body_part(axiom_mime_output_t *mime_output, 
    const axutil_env_t *env,
    axis2_byte_t **output_stream, 
    int *output_stream_size,
    axiom_mime_body_part_t *part, 
    axis2_char_t *boundary);

static axis2_status_t 
axis2_write_mime_boundary(axiom_mime_output_t *mime_output, 
    const axutil_env_t *env,
    axis2_byte_t **output_stream, 
    int *output_stream_size,
    axis2_char_t *boundary);

static axis2_status_t 
axis2_write_finish_writing_mime(axiom_mime_output_t *mime_output, 
    const axutil_env_t *env,
    axis2_byte_t **output_stream, 
    int *output_stream_size, 
    axis2_char_t *boundary);

static axis2_status_t 
axis2_start_writing_mime(axiom_mime_output_t *mime_output,
    const axutil_env_t *env, 
    axis2_byte_t **output_stream,
    int *output_stream_size, 
    axis2_char_t *boundary);

AXIS2_EXTERN axiom_mime_output_t * AXIS2_CALL
axiom_mime_output_create(const axutil_env_t *env)
{
    axiom_mime_output_t *mime_output = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    mime_output = (axiom_mime_output_t *) AXIS2_MALLOC(env->allocator,
            sizeof(axiom_mime_output_t));

    if (! mime_output)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return mime_output;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_mime_output_free(axiom_mime_output_t *mime_output, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (mime_output)
    {
        AXIS2_FREE(env->allocator, mime_output);
        mime_output = NULL;
    }
    return;
}


AXIS2_EXTERN axis2_byte_t * AXIS2_CALL
axiom_mime_output_complete(axiom_mime_output_t *mime_output,
        const axutil_env_t *env,
        axis2_byte_t **output_stream,
        int *output_stream_size,
        axis2_char_t *soap_body_buffer,
        axutil_array_list_t *binary_node_list,
        axis2_char_t *boundary,
        axis2_char_t *content_id,
        axis2_char_t *char_set_encoding,
        const axis2_char_t *soap_content_type)
{
    axis2_status_t status = AXIS2_FAILURE;
    axis2_char_t *header_value = NULL;
    axis2_char_t *temp_header_value = NULL;
    axis2_char_t *content_id_string = NULL;
    axis2_char_t *temp_content_id_string = NULL;
    axiom_mime_body_part_t *root_mime_body_part = NULL;
    axis2_byte_t *output_stream_start = NULL;
    int output_stream_start_size = 0;
    axis2_byte_t *output_stream_body = NULL;
    int output_stream_body_size = 0;
    axis2_byte_t *output_stream_body_parts = NULL;
    int output_stream_body_parts_size = 0;
    axis2_byte_t *boundary_stream = NULL;
    int boundary_stream_size = 0;
    axis2_byte_t *stream_buffer = NULL;
    int stream_buffer_size = 0;
    int soap_body_buffer_size = 0;
    axis2_char_t *temp_soap_body_buffer;

    AXIS2_ENV_CHECK(env, NULL);

    status = axis2_start_writing_mime(mime_output, env, &output_stream_start, &output_stream_start_size, boundary);
    if (status == AXIS2_FAILURE)
        return NULL;


    root_mime_body_part = axiom_mime_body_part_create(env);

    /* content-type */
    header_value = axutil_strdup(env, "application/xop+xml; charset=");
    temp_header_value = axutil_stracat(env, header_value, char_set_encoding);
    AXIS2_FREE(env->allocator, header_value);
    header_value = temp_header_value;
    temp_header_value = axutil_stracat(env, header_value, "; type=\"");
    AXIS2_FREE(env->allocator, header_value);
    header_value = temp_header_value;
    temp_header_value = axutil_stracat(env, header_value, soap_content_type);
    AXIS2_FREE(env->allocator, header_value);
    header_value = temp_header_value;
    temp_header_value = axutil_stracat(env, header_value, "\";");
    AXIS2_FREE(env->allocator, header_value);
    header_value = temp_header_value;
    AXIOM_MIME_BODY_PART_ADD_HEADER(root_mime_body_part, env, "content-type", header_value);

    /* content-transfer-encoding */
    AXIOM_MIME_BODY_PART_ADD_HEADER(root_mime_body_part, env, "content-transfer-encoding", axutil_strdup(env, "binary"));

    /* content-id */
    content_id_string = (axis2_char_t *)"<";
    content_id_string = axutil_stracat(env, content_id_string, content_id);
    temp_content_id_string = axutil_stracat(env, content_id_string, ">");
    AXIS2_FREE(env->allocator, content_id_string);
    content_id_string = temp_content_id_string;
    AXIOM_MIME_BODY_PART_ADD_HEADER(root_mime_body_part, env, "content-id", content_id_string);

    axis2_write_body_part(mime_output, env, &output_stream_body, &output_stream_body_size, root_mime_body_part, boundary);

    AXIOM_MIME_BODY_PART_FREE(root_mime_body_part, env);
    root_mime_body_part = NULL;

    if (binary_node_list)
    {
        int j = 0;
        axis2_byte_t *temp_stream = NULL;
        int temp_stream_size = 0;
        axis2_byte_t *temp = NULL;
        int temp_size = 0;
        for (j = 0; j < axutil_array_list_size(binary_node_list, env); j++)
        {
            axiom_text_t *text = (axiom_text_t *)axutil_array_list_get(binary_node_list, env, j);
            if (text)
            {
                axiom_mime_body_part_t *mime_body_part = NULL;
                mime_body_part = axis2_create_mime_body_part(text, env);
                axis2_write_body_part(mime_output, env, &temp_stream,
                        &temp_stream_size, mime_body_part, boundary);

                AXIOM_MIME_BODY_PART_FREE(mime_body_part, env);
                mime_body_part = NULL;

                temp = output_stream_body_parts;
                temp_size = output_stream_body_parts_size;
                output_stream_body_parts_size = temp_size +
                        output_stream_start_size + temp_stream_size;
                output_stream_body_parts = AXIS2_MALLOC(env->allocator,
                        output_stream_body_parts_size * sizeof(axis2_byte_t));
                if (!output_stream_body_parts)
                {
                    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                    return NULL;
                }

                if (temp)
                {
                    memcpy(output_stream_body_parts, temp, temp_size);
                    AXIS2_FREE(env->allocator, temp);
                    temp = NULL;
                }

                if (output_stream_start)
                {
                    memcpy(output_stream_body_parts + temp_size,
                            output_stream_start, output_stream_start_size);
                }

                if (temp_stream)
                {
                    memcpy(output_stream_body_parts + temp_size +
                            output_stream_start_size, temp_stream, temp_stream_size);
                    AXIS2_FREE(env->allocator, temp_stream);
                    temp_stream = NULL;
                }

                temp_size = 0;
                temp_stream_size = 0;
            }
        }
    }

    axis2_write_finish_writing_mime(mime_output,  env, &boundary_stream,
            &boundary_stream_size, boundary);

    if (soap_body_buffer)
    {
        temp_soap_body_buffer = axutil_stracat(env, soap_body_buffer, "\r\n");
        
        /*AXIS2_FREE(env->allocator, soap_body_buffer);*/
        soap_body_buffer = temp_soap_body_buffer;
        
        soap_body_buffer_size = axutil_strlen(soap_body_buffer);
    }

    stream_buffer_size = output_stream_start_size + output_stream_body_size +
            soap_body_buffer_size + output_stream_body_parts_size +
            boundary_stream_size;

    stream_buffer = AXIS2_MALLOC(env->allocator,
            stream_buffer_size * sizeof(axis2_byte_t));

    if (output_stream_start)
    {
        memcpy(stream_buffer, output_stream_start, output_stream_start_size);
        AXIS2_FREE(env->allocator, output_stream_start);
        output_stream_start = NULL;
    }

    if (output_stream_body)
    {
        memcpy(stream_buffer + output_stream_start_size, output_stream_body,
                output_stream_body_size);
        AXIS2_FREE(env->allocator, output_stream_body);
        output_stream_body = NULL;
    }

    if (soap_body_buffer)
    {
        memcpy(stream_buffer + output_stream_start_size + output_stream_body_size,
                soap_body_buffer, soap_body_buffer_size);
        AXIS2_FREE(env->allocator, soap_body_buffer);
        soap_body_buffer = NULL;
    }

    if (output_stream_body_parts)
    {
        memcpy(stream_buffer + output_stream_start_size + output_stream_body_size +
                soap_body_buffer_size,
                output_stream_body_parts, output_stream_body_parts_size);
        AXIS2_FREE(env->allocator, output_stream_body_parts);
        output_stream_body_parts = NULL;
    }

    if (boundary_stream)
    {
        memcpy(stream_buffer + output_stream_start_size + output_stream_body_size +
                soap_body_buffer_size + output_stream_body_parts_size,
                boundary_stream, boundary_stream_size);
        AXIS2_FREE(env->allocator, boundary_stream);
        boundary_stream = NULL;
    }

    *output_stream = stream_buffer;
    *output_stream_size = stream_buffer_size;
    return stream_buffer;
}

static axis2_status_t 
axis2_start_writing_mime(axiom_mime_output_t *mime_output,
        const axutil_env_t *env, axis2_byte_t **output_stream,
        int *output_stream_size, axis2_char_t *boundary)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return axis2_write_mime_boundary(mime_output, env, output_stream, output_stream_size, boundary);
}

static axis2_status_t 
axis2_write_mime_boundary(axiom_mime_output_t *mime_output, const axutil_env_t *env,
        axis2_byte_t **output_stream, int *output_stream_size,
        axis2_char_t *boundary)
{
    axis2_byte_t *byte_buffer = NULL;
    axis2_byte_t *byte_stream = NULL;
    int size = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    axis2_char_2_byte(env, boundary, &byte_buffer, &size);
    if (!byte_buffer)
        return AXIS2_FAILURE;
    byte_stream = AXIS2_MALLOC(env->allocator, (size + 2) * sizeof(axis2_byte_t));
    if (!byte_stream)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    byte_stream[0] = AXIOM_MIME_BOUNDARY_BYTE;
    byte_stream[1] = AXIOM_MIME_BOUNDARY_BYTE;
    if (byte_buffer)
    {
        memcpy(byte_stream + 2, byte_buffer, size);
        AXIS2_FREE(env->allocator, byte_buffer);
        byte_buffer = NULL;
    }

    /*AXIS2_FREE(env->allocator, byte_buffer);*/

    *output_stream = byte_stream;
    *output_stream_size = size + 2;

    return AXIS2_SUCCESS;
}

static axiom_mime_body_part_t *
axis2_create_mime_body_part(axiom_text_t *text, const axutil_env_t *env)
{
    axiom_data_handler_t *data_handler = NULL;
    const axis2_char_t *content_type = "application/octet-stream";
    axiom_mime_body_part_t * mime_body_part = axiom_mime_body_part_create(env);
    axis2_char_t *content_id = (axis2_char_t *)"<";
    axis2_char_t *temp_content_id = NULL;
    if (!mime_body_part)
        return NULL;
    data_handler = axiom_text_get_data_handler(text, env);

    if (data_handler)
    {
        content_type = axiom_data_handler_get_content_type(data_handler, env);
    }

    AXIOM_MIME_BODY_PART_SET_DATA_HANDLER(mime_body_part, env,
            data_handler);
    content_id = axutil_stracat(env,
		    content_id,
            axiom_text_get_content_id(text, env));
    temp_content_id = axutil_stracat(env, content_id, ">");
    
    AXIS2_FREE(env->allocator, content_id);
    content_id = temp_content_id;
    
    AXIOM_MIME_BODY_PART_ADD_HEADER(mime_body_part, env, "content-id", content_id);
    AXIOM_MIME_BODY_PART_ADD_HEADER(mime_body_part, env, "content-type", axutil_strdup(env, content_type));
    AXIOM_MIME_BODY_PART_ADD_HEADER(mime_body_part, env, "content-transfer-encoding", axutil_strdup(env, "binary"));

    return mime_body_part;
}

static axis2_status_t 
axis2_write_body_part(axiom_mime_output_t *mime_output, const axutil_env_t *env,
        axis2_byte_t **output_stream, int *output_stream_size,
        axiom_mime_body_part_t *part, axis2_char_t *boundary)
{
    axis2_byte_t *byte_buffer = NULL;
    axis2_byte_t *byte_stream = NULL;
    int byte_buffer_size = 0;
    axis2_byte_t *body_stream = NULL;
    int body_stream_size = 0;
    int size = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIOM_MIME_BODY_PART_WRITE_TO(part, env, &body_stream, &body_stream_size);

    size = byte_buffer_size + body_stream_size + 4;

    byte_stream = AXIS2_MALLOC(env->allocator, size * sizeof(axis2_byte_t));
    if (!byte_stream)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    byte_stream[0] = AXIS2_CRLF[0];
    byte_stream[1] = AXIS2_CRLF[1];

    if (body_stream)
    {
        memcpy(byte_stream + 2, body_stream, body_stream_size);
        AXIS2_FREE(env->allocator, body_stream);
        body_stream = NULL;
    }

    byte_stream[body_stream_size + 2] = AXIS2_CRLF[0];
    byte_stream[body_stream_size + 3] = AXIS2_CRLF[1];

    if (byte_buffer)
    {
        memcpy(byte_stream + 2 + body_stream_size + 2, byte_buffer, byte_buffer_size);
        AXIS2_FREE(env->allocator, byte_buffer);
        byte_buffer = NULL;
    }

    *output_stream = byte_stream;
    *output_stream_size = size;

    return AXIS2_SUCCESS;

}

static axis2_status_t 
axis2_write_finish_writing_mime(axiom_mime_output_t *mime_output, const axutil_env_t *env,
        axis2_byte_t **output_stream, int *output_stream_size, axis2_char_t *boundary)
{
    axis2_byte_t *byte_buffer;
    axis2_byte_t *byte_stream;
    int size;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    axis2_char_2_byte(env, boundary, &byte_buffer, &size);
    byte_stream = AXIS2_MALLOC(env->allocator, (size + 4) * sizeof(axis2_byte_t));

    byte_stream[0] = AXIOM_MIME_BOUNDARY_BYTE;
    byte_stream[1] = AXIOM_MIME_BOUNDARY_BYTE;
    if (byte_buffer)
    {
        memcpy(byte_stream + 2, byte_buffer, size);
        AXIS2_FREE(env->allocator, byte_buffer);
        byte_buffer = NULL;
    }

    byte_stream[size + 2] = AXIOM_MIME_BOUNDARY_BYTE;
    byte_stream[size + 3] = AXIOM_MIME_BOUNDARY_BYTE;

    AXIS2_FREE(env->allocator, byte_buffer);

    *output_stream = byte_stream;
    *output_stream_size = size + 4;

    return AXIS2_SUCCESS;

}

AXIS2_EXTERN const axis2_char_t * AXIS2_CALL
axiom_mime_output_get_content_type_for_mime(axiom_mime_output_t *mime_output,
        const axutil_env_t *env,
        axis2_char_t *boundary,
        axis2_char_t *content_id,
        axis2_char_t *char_set_encoding,
        const axis2_char_t *soap_content_type)
{
    axis2_char_t *content_type_string = NULL;
    axis2_char_t *temp_content_type_string = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    content_type_string = axutil_strdup(env, "multipart/related");
    temp_content_type_string = axutil_stracat(env, content_type_string, "; ");
    AXIS2_FREE(env->allocator, content_type_string);
    content_type_string = temp_content_type_string;
    if (boundary)
    {
        temp_content_type_string = axutil_stracat(env, content_type_string, "boundary=");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, boundary);
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, "; ");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
    }
    temp_content_type_string = axutil_stracat(env, content_type_string, "type=\"application/xop+xml\"");
    AXIS2_FREE(env->allocator, content_type_string);
    content_type_string = temp_content_type_string;
    temp_content_type_string = axutil_stracat(env, content_type_string, "; ");
    AXIS2_FREE(env->allocator, content_type_string);
    content_type_string = temp_content_type_string;
    if (content_id)
    {
        temp_content_type_string = axutil_stracat(env, content_type_string, "start=\"<");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, content_id);
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, ">\"");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, "; ");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
    }
    if (soap_content_type)
    {
        temp_content_type_string = axutil_stracat(env, content_type_string, "start-info=\"");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, soap_content_type);
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, "\"; ");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
    }
    if (char_set_encoding)
    {
        temp_content_type_string = axutil_stracat(env, content_type_string, "charset=\"");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, char_set_encoding);
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
        temp_content_type_string = axutil_stracat(env, content_type_string, "\"");
        AXIS2_FREE(env->allocator, content_type_string);
        content_type_string = temp_content_type_string;
    }

    return content_type_string;
}

static axis2_status_t
axis2_char_2_byte(const axutil_env_t *env, 
    axis2_char_t *char_buffer, 
    axis2_byte_t **byte_buffer, 
    int *byte_buffer_size)
{
    int length;
    int i = 0;
    axis2_byte_t *bytes;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    length = axutil_strlen(char_buffer);
    bytes = AXIS2_MALLOC(env->allocator, length * sizeof(axis2_byte_t));

    for (i = 0; i < length; i++)
    {
        bytes[i] = (axis2_byte_t) char_buffer[i];
    }
    *byte_buffer = bytes;
    *byte_buffer_size = length;
    return AXIS2_SUCCESS;
}
