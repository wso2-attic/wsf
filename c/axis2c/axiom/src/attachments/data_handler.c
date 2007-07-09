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

#include <axiom_data_handler.h>
#include <stdio.h>
#include <sys/stat.h>

struct axiom_data_handler
{
    axis2_char_t* mime_type;
    axis2_char_t* file_name;
    axis2_byte_t* buffer;
    int buffer_len;
    int data_handler_type;
};

AXIS2_EXTERN axiom_data_handler_t * AXIS2_CALL
axiom_data_handler_create(const axutil_env_t *env,
    const axis2_char_t *file_name,
    const axis2_char_t *mime_type)
{
    axiom_data_handler_t *data_handler = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    data_handler = 
	(axiom_data_handler_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axiom_data_handler_t));

    if (!data_handler)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    data_handler->mime_type = NULL;
    data_handler->file_name = NULL;
    data_handler->buffer = NULL;
    data_handler->buffer_len = 0;

    if (mime_type)
    {
        data_handler->mime_type = axutil_strdup(env, mime_type);
        if (!(data_handler->mime_type))
        {
            axiom_data_handler_free(data_handler, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
    }
    if (file_name)
    {
        data_handler->file_name = axutil_strdup(env, file_name);
        if (!(data_handler->file_name))
        {
            axiom_data_handler_free(data_handler, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
        data_handler->data_handler_type = AXIOM_DATA_HANDLER_TYPE_FILE;
    }
    else
    {
        data_handler->data_handler_type = AXIOM_DATA_HANDLER_TYPE_BUFFER;
    }
    
    return data_handler;
}


AXIS2_EXTERN void AXIS2_CALL
axiom_data_handler_free(axiom_data_handler_t *data_handler, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (data_handler->file_name)
    {
        AXIS2_FREE(env->allocator, data_handler->file_name);
    }

    if (data_handler->mime_type)
    {
        AXIS2_FREE(env->allocator, data_handler->mime_type);
    }

    if (data_handler->buffer)
    {
        AXIS2_FREE(env->allocator, data_handler->buffer);
    }

    if (data_handler)
    {
        AXIS2_FREE(env->allocator, data_handler);
    }

    return;
}

AXIS2_EXTERN axis2_char_t * AXIS2_CALL
axiom_data_handler_get_content_type(axiom_data_handler_t *data_handler, 
    const axutil_env_t *env)
{
    return data_handler->mime_type;
}

AXIS2_EXTERN axis2_byte_t * AXIS2_CALL
axiom_data_handler_get_input_stream(axiom_data_handler_t *data_handler, 
    const axutil_env_t *env)
{
    return (axis2_byte_t *)"";
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_data_handler_read_from(axiom_data_handler_t *data_handler, 
    const axutil_env_t *env,
    axis2_byte_t** output_stream, 
    int *output_stream_size)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if(data_handler->data_handler_type == AXIOM_DATA_HANDLER_TYPE_BUFFER)
    {
        *output_stream = data_handler->buffer;
        *output_stream_size = data_handler->buffer_len;  
    }
    else if (data_handler->data_handler_type == AXIOM_DATA_HANDLER_TYPE_FILE
        &&  data_handler->file_name)
    {
        FILE *f = NULL;
        axis2_byte_t *byte_stream = NULL;
        axis2_byte_t *temp_byte_stream = NULL;
        axis2_byte_t *read_stream = NULL;
        int byte_stream_size = 0;
        int temp_byte_stream_size = 0;
        int read_stream_size = 0;
        int count = 0;

        f = fopen(data_handler->file_name, "rb");
        if (!f)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                " error opening file %s for reading ", 
		data_handler->file_name);
            return AXIS2_FAILURE;
        }

        do
        {
            struct stat stat_p;
            if (-1 ==  stat(data_handler->file_name, &stat_p))
            {
                return AXIS2_FAILURE;
	    }
	    else if(stat_p.st_size == 0)
	    {			  				
	        *output_stream = NULL;
		*output_stream_size = 0;
		return AXIS2_SUCCESS;
	    }


            read_stream_size = stat_p.st_size;
            read_stream = AXIS2_MALLOC(env->allocator, 
	        (read_stream_size) * sizeof(axis2_byte_t));
            if (!read_stream)
            {
                AXIS2_ERROR_SET(env->error, 
	            AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                if (byte_stream)
                {
                    AXIS2_FREE(env->allocator, byte_stream);
                }
                return AXIS2_FAILURE;
            }
            count = fread(read_stream, 1, read_stream_size, f);
            if (ferror(f) != 0)
            {
                AXIS2_ERROR_SET(env->error, 
                    AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                if (byte_stream)
                {
                    AXIS2_FREE(env->allocator, byte_stream);
                }
                if (read_stream)
                {
                    AXIS2_FREE(env->allocator, read_stream);
                }
                return AXIS2_FAILURE;
            }

            /* copy the read bytes */
            if (count > 0)
            {
                if (byte_stream)
                {
                    temp_byte_stream = byte_stream;
                    temp_byte_stream_size = byte_stream_size;
                    byte_stream_size = temp_byte_stream_size + count;
                    byte_stream = AXIS2_MALLOC(env->allocator, 
	                (byte_stream_size) * sizeof(axis2_byte_t));
                    if (!byte_stream)
                    {
                        AXIS2_ERROR_SET(env->error, 
			    AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                        if (read_stream)
                        {
                            AXIS2_FREE(env->allocator, read_stream);
                        }
                        if (temp_byte_stream)
                        {
                            AXIS2_FREE(env->allocator, temp_byte_stream);
                        }
                        return AXIS2_FAILURE;
                    }

                    memcpy(byte_stream, 
		        temp_byte_stream, temp_byte_stream_size);
                    memcpy(byte_stream + temp_byte_stream_size, 
		        read_stream, count);

                    if (read_stream)
                    {
                        AXIS2_FREE(env->allocator, read_stream);
                        read_stream_size = 0;
                    }
                    if (temp_byte_stream)
                    {
                        AXIS2_FREE(env->allocator, temp_byte_stream);
                        temp_byte_stream_size = 0;
                    }
                }
                else
                {
                    byte_stream = read_stream;
                    byte_stream_size = read_stream_size;
                    read_stream = NULL;
                    read_stream_size = 0;
                }
            }
            else
            {
                if (read_stream)
                {
                    AXIS2_FREE(env->allocator, read_stream);
                }
            }
        }
        while (!feof(f));

        fclose(f);

        *output_stream = byte_stream;
        *output_stream_size = byte_stream_size;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_data_handler_set_binary_data(axiom_data_handler_t *data_handler, 
    const axutil_env_t *env,
    axis2_byte_t* input_stream, int input_stream_len)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    data_handler = data_handler;

    data_handler->buffer = input_stream;
    data_handler->buffer_len = input_stream_len;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_data_handler_write_to(axiom_data_handler_t *data_handler, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (data_handler->file_name)
    {
        FILE *f = NULL;
        int count = 0;

        f = fopen(data_handler->file_name, "wb");
        if (!f)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                " error opening file %s for writing ", 
		data_handler->file_name);
            return AXIS2_FAILURE;
        }

        count = fwrite(data_handler->buffer, 
	    1, data_handler->buffer_len, f);

        if (ferror(f) != 0)
        {
            return AXIS2_FAILURE;
        }
        fflush(f);
        fclose(f);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_data_handler_set_file_name(axiom_data_handler_t *data_handler, 
    const axutil_env_t *env,
    axis2_char_t* file_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (data_handler->file_name)
    {
        AXIS2_FREE(env->allocator, data_handler->file_name);
    }

    if (file_name)
    {
        data_handler->file_name = axutil_strdup(env, file_name);
        if (!(data_handler->file_name))
        {
            axiom_data_handler_free(data_handler, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
    }

    return AXIS2_SUCCESS;
}

