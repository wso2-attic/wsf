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


#include "axiom_mime_body_part.h"
#include <axiom_data_handler.h>
#include <axutil_hash.h>

struct axiom_mime_body_part
{
    /** hash map to hold header name, value pairs */
    axutil_hash_t *header_map;
    axiom_data_handler_t *data_handler;
};

extern axis2_char_t AXIS2_CRLF[];


AXIS2_EXTERN axiom_mime_body_part_t * AXIS2_CALL
axiom_mime_body_part_create(const axutil_env_t *env)
{
    axiom_mime_body_part_t *mime_body_part = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    mime_body_part = (axiom_mime_body_part_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axiom_mime_body_part_t));

    if (!mime_body_part)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    mime_body_part->header_map = NULL;
    mime_body_part->data_handler = NULL;

    mime_body_part->header_map = axutil_hash_make(env);
    if (!(mime_body_part->header_map))
    {
        axiom_mime_body_part_free(mime_body_part, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return mime_body_part;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_mime_body_part_free(axiom_mime_body_part_t *mime_body_part, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (mime_body_part->header_map)
    {
        axutil_hash_index_t *hash_index = NULL;
        const void *key = NULL;
        void *value = NULL;
        for (hash_index = axutil_hash_first(mime_body_part->header_map, env);
            hash_index; hash_index = axutil_hash_next(env, hash_index))
        {
            axutil_hash_this(hash_index, &key, NULL, &value);
            if (value)
            {
                AXIS2_FREE(env->allocator, value);
            }
        }

    
        axutil_hash_free(mime_body_part->header_map, env);
        mime_body_part->header_map = NULL;
    }

    if (mime_body_part)
    {
        AXIS2_FREE(env->allocator, mime_body_part);
    }

    return;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_mime_body_part_add_header(axiom_mime_body_part_t *mime_body_part,
    const axutil_env_t *env,
    const axis2_char_t *name,
    const axis2_char_t *value)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FAILURE);

    axutil_hash_set(mime_body_part->header_map, name,
        AXIS2_HASH_KEY_STRING, value);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_mime_body_part_set_data_handler(axiom_mime_body_part_t *mime_body_part,
    const axutil_env_t *env, axiom_data_handler_t *data_handler)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    mime_body_part->data_handler = data_handler;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_mime_body_part_write_to(axiom_mime_body_part_t *mime_body_part, 
    const axutil_env_t *env,
    axis2_byte_t **output_stream, int *output_stream_size)
{
    axutil_hash_index_t *hash_index = NULL;
    const void *key = NULL;
    void *value = NULL;
    axis2_char_t *header_str = NULL;
    axis2_char_t *temp_header_str = NULL;
    int header_str_size = 0;
    axis2_byte_t *data_handler_stream = NULL;
    int data_handler_stream_size = 0;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_byte_t *byte_stream = NULL;
    int size = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    for (hash_index = axutil_hash_first(mime_body_part->header_map, env);
        hash_index; hash_index = axutil_hash_next(env, hash_index))
    {
        axutil_hash_this(hash_index, &key, NULL, &value);
        if (key && value)
        {
            temp_header_str = axutil_stracat(env, header_str, (axis2_char_t*)key);
            if (header_str)
            {
                AXIS2_FREE(env->allocator, header_str);
            }
            header_str = temp_header_str;
            temp_header_str = axutil_stracat(env, header_str, ": ");
            AXIS2_FREE(env->allocator, header_str);
            header_str = temp_header_str;
            temp_header_str = axutil_stracat(env, header_str, (axis2_char_t*)value);
            AXIS2_FREE(env->allocator, header_str);
            header_str = temp_header_str;
            temp_header_str = axutil_stracat(env, header_str, "\r\n");
            AXIS2_FREE(env->allocator, header_str);
            header_str = temp_header_str;
        }
    }

    if (mime_body_part->data_handler)
    {
        temp_header_str = axutil_stracat(env, header_str, "\r\n");
        AXIS2_FREE(env->allocator, header_str);
        header_str = temp_header_str;
    }

    if (header_str)
    {
        header_str_size = axutil_strlen(header_str);
    }

    /* TODO: We only support binary as of now,
       Axis2/Java supports "base64", "uuencode", "x-uuencode", "x-uue", 
       "quoted-printable" */
    if (mime_body_part->data_handler)
    {
        status = axiom_data_handler_read_from(mime_body_part->data_handler, env,
            &data_handler_stream, &data_handler_stream_size);
        if (status == AXIS2_FAILURE)
	{
            return AXIS2_FAILURE;
	}
    }

    size = header_str_size + data_handler_stream_size;
    byte_stream = AXIS2_MALLOC(env->allocator, (size) * sizeof(axis2_byte_t));
    if (!byte_stream)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        if (data_handler_stream)
        {
            AXIS2_FREE(env->allocator, data_handler_stream);
        }
        if (header_str)
        {
            AXIS2_FREE(env->allocator, header_str);
        }
        return AXIS2_FAILURE;
    }
    if (header_str)
    {
        memcpy(byte_stream, header_str, header_str_size);
        AXIS2_FREE(env->allocator, header_str);
    }

    if (data_handler_stream)
    {
        memcpy(byte_stream + header_str_size, 
	    data_handler_stream, data_handler_stream_size);
    }

    *output_stream = byte_stream;
    *output_stream_size = size;

    return AXIS2_SUCCESS;
}
