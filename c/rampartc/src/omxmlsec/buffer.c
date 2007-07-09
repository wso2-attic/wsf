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

#include <axis2_defines.h>
#include <stdio.h>
#include <axis2_util.h>
#include <oxs_constants.h>
#include <oxs_buffer.h>
#include <oxs_axiom.h>
#include <oxs_error.h>



struct oxs_buffer
{
    unsigned char* data;
    unsigned int size;
    unsigned int max_size;
    oxs_AllocMode alloc_mode;
};


/******************** end of function headers *****************/

AXIS2_EXTERN oxs_buffer_t *AXIS2_CALL
oxs_buffer_create(const axutil_env_t *env)
{
    oxs_buffer_t *buffer = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);

    buffer = (oxs_buffer_t*)AXIS2_MALLOC(env->allocator, sizeof(oxs_buffer_t));
    if (!buffer)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    buffer->data = NULL;
    buffer->size = 0;
    buffer->max_size = 0;
    buffer->alloc_mode = oxs_alloc_mode_double;

    status = oxs_buffer_set_max_size(buffer, env, OXS_BUFFER_INITIAL_SIZE);
    if (status == AXIS2_FAILURE)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                  "oxs_buffer_set_max_size");
        return NULL;
    }

    return buffer;

}

axis2_status_t AXIS2_CALL
oxs_buffer_free(
    oxs_buffer_t *buffer,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (buffer->data)
    {
        AXIS2_FREE(env->allocator,  buffer->data);
        buffer->data = NULL;
    }

    AXIS2_FREE(env->allocator,  buffer);
    buffer = NULL;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_buffer_remove_head(
    oxs_buffer_t *buffer,
    const axutil_env_t *env,
    int size
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /*If the size to be removed is less than the buffer size*/
    if (size < buffer->size)
    {
        if (!buffer->data)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "oxs_buffer_remove_head failed. data is NULL");
            return  AXIS2_FAILURE;
        }
        buffer->size -= size;
        memmove(buffer->data, buffer->data + size, buffer->size);
    }
    else
    {
        buffer->size = 0;
    }

    /*If the buffer size is less than the max_size.*/
    if (buffer->size < buffer->max_size)
    {
        if (!buffer->data)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "oxs_buffer_remove_head failed");
            return  AXIS2_FAILURE;
        }
        memset(buffer->data + buffer->size, 0, buffer->max_size - buffer->size);
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_buffer_remove_tail(
    oxs_buffer_t *buffer,
    const axutil_env_t *env,
    int size
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (size < buffer->size)
    {
        buffer->size -= size;
    }
    else
    {
        buffer->size = 0;
    }
    if (buffer->size < buffer->max_size)
    {
        if (buffer->data)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "");
            return  AXIS2_FAILURE;
        }
        memset(buffer->data + buffer->size, 0, buffer->max_size - buffer->size);
    }


    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_buffer_populate(
    oxs_buffer_t *buffer,
    const axutil_env_t *env,
    unsigned char *data,
    int size
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (size > 0)
    {
        oxs_buffer_set_max_size(buffer, env, size);
        if (!data)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "data is NULL");
            return AXIS2_FAILURE;
        }

        memcpy(buffer->data, data, size);
        buffer->size = size;
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_buffer_append(
    oxs_buffer_t *buffer,
    const axutil_env_t *env,
    unsigned char *data,
    int size
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (size > 0)
    {
        oxs_buffer_set_max_size(buffer, env,  buffer->size + size);
        if (!data)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "data is NULL");
            return AXIS2_FAILURE;
        }

        memcpy(buffer->data + buffer->size, data, size);
        buffer->size += size;
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_buffer_prepend(
    oxs_buffer_t *buffer,
    const axutil_env_t *env,
    unsigned char *data,
    int size
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (size > 0)
    {
        if (!data)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "Passed data is NULL");
            return AXIS2_FAILURE;
        }

        buffer->max_size = buffer->size + size;

        memmove(buffer->data + size, buffer->data, buffer->size);
        memcpy(buffer->data, data, size);
        buffer->size += size;
    }

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_buffer_read_file(
    oxs_buffer_t *buffer,
    const axutil_env_t *env,
    const axis2_char_t *filename
)
{
    unsigned char fbuffer[1024];
    FILE* f;
    int  len;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    f = fopen(filename, "rb");
    if (f == NULL)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "");
        return AXIS2_FAILURE;
    }

    while (1)
    {
        len = fread(fbuffer, 1, sizeof(fbuffer), f);
        if (len == 0)
        {
            break; /*Stop reading*/
        }
        else if (len < 0)
        {
            fclose(f);
            return AXIS2_FAILURE;
        }
        status = oxs_buffer_append(buffer, env, fbuffer, len);
        if (status == AXIS2_FAILURE)
        {
            fclose(f);
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "");
            return AXIS2_FAILURE;
        }

        /*Alright so far everything is fine. So let's close the output*/
        fclose(f);
        return AXIS2_SUCCESS;
    }/*End of while*/

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_buffer_set_size(
    oxs_buffer_t *buffer,
    const axutil_env_t *env,
    int size
)
{
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /*First we need to make sure that the max size has a value greater or equal value*/
    status = oxs_buffer_set_max_size(buffer, env,  size);
    if (status == AXIS2_FAILURE)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "oxs_buffer_set_max_size failed");
        return AXIS2_FAILURE;
    }
    /*Now set the size*/
    buffer->size = size;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_buffer_set_max_size(
    oxs_buffer_t *buffer,
    const axutil_env_t *env,
    int size
)
{
    unsigned char* new_data;
    unsigned int new_size = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (size <= buffer->max_size)
    {
        return AXIS2_SUCCESS;
    }

    switch (buffer->alloc_mode)
    {
    case oxs_alloc_mode_exact:
        new_size = size + 8;
        break;
    case oxs_alloc_mode_double:
        new_size = 2 * size + 32;
        break;
    }

    if (new_size < OXS_BUFFER_INITIAL_SIZE)
    {
        new_size = OXS_BUFFER_INITIAL_SIZE;
    }

    /*If there are data already then use realloc instead of malloc*/
    if (buffer->data)
    {
#if 0
        new_data = (unsigned char*)AXIS2_REALLOC(env->allocator, buffer_impl->data, new_size);
#else

        /*Assign extra amnt of memory*/
        new_data = (unsigned char*)AXIS2_MALLOC(env->allocator, new_size + buffer->max_size);

        /*Copy to newdata*/
        new_data = memcpy(new_data, buffer->data, buffer->size);

#endif
    }
    else
    {
        new_data = (unsigned char*)AXIS2_MALLOC(env->allocator, new_size);
    }

    if (new_data == NULL)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "");
        return AXIS2_FAILURE;
    }

    buffer->data = new_data;
    buffer->max_size = new_size;

    if (buffer->size < buffer->max_size)
    {
        if (buffer->data == NULL)
        {
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                      "");
            return AXIS2_FAILURE;
        }
        memset(buffer->data + buffer->size, 0, buffer->max_size - buffer->size);
    }

    return AXIS2_SUCCESS;
}

unsigned char* AXIS2_CALL
oxs_buffer_get_data(
    oxs_buffer_t *buffer,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return buffer->data;
}

int AXIS2_CALL
oxs_buffer_get_size(
    oxs_buffer_t *buffer,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return buffer->size;
}

int AXIS2_CALL
oxs_buffer_get_max_size(
    oxs_buffer_t *buffer,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return buffer->max_size;
}

