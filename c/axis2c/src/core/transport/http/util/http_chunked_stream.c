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

#include <axis2_http_chunked_stream.h>
#include <axutil_string.h>
#include <string.h>
#include <axis2_http_transport.h>
#include <stdlib.h>

struct axis2_http_chunked_stream
{
    axutil_stream_t *stream;
    int current_chunk_size;
    int unread_len;
    axis2_bool_t end_of_chunks;
    axis2_bool_t chunk_started;
};

static axis2_status_t
axis2_http_chunked_stream_start_chunk(
    axis2_http_chunked_stream_t *chunked_stream,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_http_chunked_stream_t *AXIS2_CALL
axis2_http_chunked_stream_create(
    const axutil_env_t *env,
    axutil_stream_t *stream)
{
    axis2_http_chunked_stream_t *chunked_stream = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, stream, NULL);

    chunked_stream = (axis2_http_chunked_stream_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_http_chunked_stream_t));

    if (! chunked_stream)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    chunked_stream->stream = stream;
    chunked_stream->current_chunk_size = -1;
    chunked_stream->unread_len = -1;
    chunked_stream->end_of_chunks = AXIS2_FALSE;
    chunked_stream->chunk_started = AXIS2_FALSE;

    return chunked_stream;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_chunked_stream_free(
    axis2_http_chunked_stream_t *chunked_stream,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    AXIS2_FREE(env->allocator, chunked_stream);
    return;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_http_chunked_stream_read(
    axis2_http_chunked_stream_t *chunked_stream,
    const axutil_env_t *env,
    void *buffer,
    size_t count)
{
    int len = -1;
    int yet_to_read = 0;
    axutil_stream_t *stream = chunked_stream->stream;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (! buffer)
    {
        return -1;
    }
    if (! stream)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_STREAM_IN_CHUNKED_STREAM
                , AXIS2_FAILURE);
        return -1;
    }
    if (AXIS2_TRUE == chunked_stream->end_of_chunks)
    {
        return 0;
    }
    if (AXIS2_FALSE == chunked_stream->chunk_started)
    {
        axis2_http_chunked_stream_start_chunk(chunked_stream, env);
    }
    yet_to_read = count;
    while (AXIS2_FALSE == chunked_stream->end_of_chunks && yet_to_read > 0)
    {
        if (chunked_stream->unread_len < yet_to_read)
        {
            len = axutil_stream_read(chunked_stream->stream, env,
                    (axis2_char_t *)buffer + count - yet_to_read,
                    chunked_stream->unread_len);
            yet_to_read -= len;
            chunked_stream->unread_len -= len;
            if (chunked_stream->unread_len <= 0)
            {
                axis2_http_chunked_stream_start_chunk(chunked_stream, env);
            }
        }
        else
        {
            len = axutil_stream_read(chunked_stream->stream, env,
                    (axis2_char_t *)buffer + count - yet_to_read,
                    yet_to_read);
            yet_to_read -= len;
            chunked_stream->unread_len -= len;
        }
    }
    return count - yet_to_read;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_http_chunked_stream_write(
    axis2_http_chunked_stream_t *chunked_stream,
    const axutil_env_t *env,
    const void *buffer,
    size_t count)
{
    axutil_stream_t *stream = chunked_stream->stream;
    int len = -1;
    axis2_char_t tmp_buf[10];
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (! buffer)
    {
        return -1;
    }
    if (! stream)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NULL_STREAM_IN_CHUNKED_STREAM
                , AXIS2_FAILURE);
        return -1;
    }
    sprintf(tmp_buf, "%x%s", (unsigned int)count, AXIS2_HTTP_CRLF);
    len = axutil_stream_write(stream, env, tmp_buf, axutil_strlen(tmp_buf));
    len = axutil_stream_write(stream, env, buffer, count);
    axutil_stream_write(stream, env, AXIS2_HTTP_CRLF, 2);
    return len;
}


AXIS2_EXTERN int AXIS2_CALL
axis2_http_chunked_stream_get_current_chunk_size(
    const axis2_http_chunked_stream_t *chunked_stream,
    const axutil_env_t *env)
{
    return chunked_stream->current_chunk_size;
}


static axis2_status_t
axis2_http_chunked_stream_start_chunk(
    axis2_http_chunked_stream_t *chunked_stream,
    const axutil_env_t *env)
{
    axis2_char_t tmp_buf[3] = "";
    axis2_char_t str_chunk_len[512] = "";
    axis2_char_t *tmp = NULL;
    int read = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /* remove the last CRLF of the previous chunk if any */
    if (AXIS2_TRUE == chunked_stream->chunk_started)
    {
        read = axutil_stream_read(chunked_stream->stream, env, tmp_buf, 2);
        chunked_stream->chunk_started = AXIS2_FALSE;
    }
    /* read the len and chunk extension */
    while ((read = axutil_stream_read(chunked_stream->stream, env, tmp_buf,
            1)) > 0)
    {
        tmp_buf[read] = '\0';
        strcat(str_chunk_len, tmp_buf);
        if (0 != strstr(str_chunk_len, AXIS2_HTTP_CRLF))
        {
            break;
        }
    }
    /* check whether we have extensions */
    tmp = strchr(str_chunk_len, ';');
    if (tmp)
    {
        /* we don't use extensions right now */
        *tmp = '\0';
    }
    chunked_stream->current_chunk_size = strtol(str_chunk_len, NULL, 16);
    if (0 == chunked_stream->current_chunk_size)
    {
        /* Read the last CRLF */
        read = axutil_stream_read(chunked_stream->stream, env, tmp_buf, 2);
        chunked_stream->end_of_chunks = AXIS2_TRUE;
    }
    else
    {
        chunked_stream->chunk_started = AXIS2_TRUE;
        chunked_stream->unread_len =
            chunked_stream->current_chunk_size;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_chunked_stream_write_last_chunk(
    axis2_http_chunked_stream_t *chunked_stream,
    const axutil_env_t *env)
{
    axutil_stream_t *stream = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    stream = chunked_stream->stream;
    if (axutil_stream_write(stream, env, "0\r\n\r\n", 5) == 5)
    {
        return AXIS2_SUCCESS;
    }
    return AXIS2_FAILURE;
}
