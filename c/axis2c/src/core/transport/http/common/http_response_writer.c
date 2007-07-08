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

#include <axis2_http_response_writer.h>
#include <axutil_array_list.h>
#include <axis2_http_transport.h>
#include <axutil_string.h>

struct axis2_http_response_writer
{
    axutil_stream_t *stream;
    axis2_char_t *encoding;
};

AXIS2_EXTERN axis2_http_response_writer_t *AXIS2_CALL
axis2_http_response_writer_create(
    const axutil_env_t *env,
    axutil_stream_t *stream)
{
    AXIS2_ENV_CHECK(env, NULL);
    return axis2_http_response_writer_create_with_encoding(env, stream,
            AXIS2_HTTP_DEFAULT_CONTENT_CHARSET);

}

AXIS2_EXTERN axis2_http_response_writer_t *AXIS2_CALL
axis2_http_response_writer_create_with_encoding(
    const axutil_env_t *env,
    axutil_stream_t *stream,
    const axis2_char_t *encoding)
{
    axis2_http_response_writer_t *response_writer = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, encoding, NULL);

    response_writer = (axis2_http_response_writer_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_http_response_writer_t));

    if (! response_writer)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    response_writer->stream = stream;
    response_writer->encoding = (axis2_char_t *)axutil_strdup(env, encoding);

    return response_writer;
}


AXIS2_EXTERN void AXIS2_CALL
axis2_http_response_writer_free(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_FREE(env->allocator,
        response_writer->encoding);

    AXIS2_FREE(env->allocator, response_writer);

    return;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_response_writer_get_encoding(
    const axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return response_writer->encoding;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_response_writer_close(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_response_writer_flush(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return AXIS2_FALSE;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_response_writer_write_char(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env,
    char c)
{
    int write = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (! response_writer->stream)
    {
        return AXIS2_FAILURE;
    }
    write = axutil_stream_write(response_writer->stream, env, &c, 1);
    if (write < 0)
    {
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_response_writer_write_buf(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env,
    char *buf,
    int offset,
    axis2_ssize_t len)
{
    int write = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, buf, AXIS2_FAILURE);

    if (! response_writer->stream)
    {
        return AXIS2_FAILURE;
    }
    write = axutil_stream_write(response_writer->stream, env, buf, len);
    if (write < 0)
    {
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_response_writer_print_str(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env,
    const char *str)
{
    int write = -1;
    int len = -1;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, str, AXIS2_FAILURE);

    len = axutil_strlen(str);
    if (! response_writer->stream)
    {
        return AXIS2_FAILURE;
    }
    write = axutil_stream_write(response_writer->stream, env, str, len);
    if (write < 0)
    {
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_response_writer_print_int(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env,
    int i)
{
    axis2_char_t int_str[10];
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    sprintf(int_str, "%10d", i);
    return axis2_http_response_writer_print_str(response_writer, env, int_str);
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_response_writer_println_str(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env,
    const char *str)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, str, AXIS2_FAILURE);

    if (AXIS2_SUCCESS == axis2_http_response_writer_print_str(response_writer,
            env, str))
    {
        return axis2_http_response_writer_print_str(response_writer, env,
                AXIS2_HTTP_CRLF);
    }
    return AXIS2_FAILURE;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_response_writer_println(
    axis2_http_response_writer_t *response_writer,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return axis2_http_response_writer_print_str(response_writer, env,
            AXIS2_HTTP_CRLF);
}
