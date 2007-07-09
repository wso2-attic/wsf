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

#include <axis2_http_simple_request.h>
#include <axutil_array_list.h>
#include <axis2_http_transport.h>
#include <axutil_string.h>
#include <string.h>
#include <axutil_types.h>

struct axis2_http_simple_request
{
    axis2_http_request_line_t *request_line;
    axutil_array_list_t *header_group;
    axutil_stream_t *stream;
    axis2_bool_t owns_stream;
};

AXIS2_EXTERN axis2_http_simple_request_t *AXIS2_CALL
axis2_http_simple_request_create(
    const axutil_env_t *env,
    axis2_http_request_line_t *request_line,
    axis2_http_header_t **http_headers,
    axis2_ssize_t http_hdr_count,
    axutil_stream_t *content)
{
    axis2_http_simple_request_t *simple_request = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_ENV_CHECK(env, NULL);

    simple_request = (axis2_http_simple_request_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_http_simple_request_t));

    if (! simple_request)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    simple_request->request_line = request_line;
    simple_request->stream = content;
    simple_request->header_group = NULL;
    simple_request->owns_stream = AXIS2_FALSE;

    if (!(simple_request->stream))
    {
        simple_request->stream = axutil_stream_create_basic(env);
        if (! simple_request->stream)
        {
            axis2_http_simple_request_free((axis2_http_simple_request_t *)
                    simple_request, env);
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
        simple_request->owns_stream = AXIS2_TRUE;
    }

    if (http_hdr_count > 0 &&  http_headers)
    {
        int i = 0;
        simple_request->header_group = axutil_array_list_create(env,
                http_hdr_count);

        for (i = 0; i < http_hdr_count; i++)
        {
            axutil_array_list_add(simple_request->header_group, env,
                    (void *)http_headers[i]);
        }
    }

    return simple_request;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_simple_request_free(
    axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (AXIS2_TRUE == simple_request->owns_stream)
    {
        axutil_stream_free(simple_request->stream, env);
    }
    /*
        Don't free the stream since it belongs to the socket
    */
    if (simple_request->request_line)
    {
        axis2_http_request_line_free(simple_request->request_line, env);
    }
    if (simple_request->header_group)
    {
        int i = 0;
        axis2_http_header_t *tmp = NULL;
        for (i = 0; i < axutil_array_list_size(simple_request->header_group,
                env); i++)
        {
            tmp = (axis2_http_header_t *)axutil_array_list_get(
                        simple_request->header_group, env, i);
            axis2_http_header_free(tmp, env);

        }
        axutil_array_list_free(simple_request->header_group, env);
    }

    AXIS2_FREE(env->allocator, simple_request);

    return;
}

AXIS2_EXTERN axis2_http_request_line_t *AXIS2_CALL
axis2_http_simple_request_get_request_line(
    const axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env)
{
    return simple_request->request_line;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_simple_request_set_request_line(
    axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env,
    axis2_http_request_line_t *request_line)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, request_line, AXIS2_FAILURE);
    simple_request->request_line = request_line;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_simple_request_contains_header(
    axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env,
    const axis2_char_t *name)
{
    int i = 0;
    axis2_char_t *header_name = NULL;
    int count = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FAILURE);

    if (! simple_request->header_group)
    {
        return AXIS2_FALSE;
    }

    count = axutil_array_list_size(simple_request->header_group, env);

    if (0 == count)
    {
        return AXIS2_FALSE;
    }

    for (i = 0; i < count; i++)
    {
        header_name = axis2_http_header_get_name((axis2_http_header_t *)
                axutil_array_list_get(simple_request->header_group,
                        env, i), env);
        if (0 == axutil_strcasecmp(name, header_name))
            return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
}


AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
axis2_http_simple_request_get_headers(
    const axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env)
{
    return simple_request->header_group;
}


AXIS2_EXTERN axis2_http_header_t *AXIS2_CALL
axis2_http_simple_request_get_first_header(
    const axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env,
    const axis2_char_t *str)
{
    axutil_array_list_t *header_group = NULL;
    int i = 0;
    int count = 0;
    axis2_http_header_t *tmp_header = NULL;
    axis2_char_t *tmp_name = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, str, NULL);

    header_group = simple_request->header_group;
    if (! simple_request->header_group)
    {
        return NULL;
    }
    if (0 == axutil_array_list_size(header_group, env))
    {
        return NULL;
    }


    count = axutil_array_list_size(header_group, env);


    for (i = 0; i < count; i++)
    {

        tmp_header = (axis2_http_header_t *)axutil_array_list_get(header_group,
                env, i);
        tmp_name = axis2_http_header_get_name(tmp_header, env);
        if (0 == axutil_strcasecmp(str, tmp_name))
        {
            return tmp_header;
        }
    }
    return NULL;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_simple_request_remove_headers(
    axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env,
    const axis2_char_t *str)
{
    axis2_http_header_t *tmp_header = NULL;
    axis2_char_t *tmp_name = NULL;
    int i = 0;
    int count = 0;
    axutil_array_list_t *header_group = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, str, AXIS2_FAILURE);

    header_group = simple_request->header_group;

    if (! header_group)
    {
        /* Even though we couldn't complete the op, we are sure that the
         * requred header is no more in the request. So we can proceed without a
         * problem.
         */
        return AXIS2_SUCCESS;
    }

    count = axutil_array_list_size(header_group, env);

    for (i = 0; i < count; i++)
    {
        tmp_header = (axis2_http_header_t *)axutil_array_list_get(header_group,
                env, i);
        tmp_name = axis2_http_header_get_name(tmp_header, env);
        if (0 == axutil_strcasecmp(str, tmp_name))
        {
            axis2_http_header_free(tmp_header, env);
            axutil_array_list_remove(header_group, env, i);
            break;
        }
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_simple_request_add_header(
    axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env,
    axis2_http_header_t *header)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, header, AXIS2_FAILURE);

    if (! simple_request->header_group)
    {
        simple_request->header_group = axutil_array_list_create(env, 1);
    }
    return axutil_array_list_add(simple_request->header_group,
            env, header);
}


AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_http_simple_request_get_content_type(
    const axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env)
{
    axis2_http_header_t *tmp_header = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    tmp_header = axis2_http_simple_request_get_first_header
            (simple_request, env, AXIS2_HTTP_HEADER_CONTENT_TYPE);
    if (tmp_header)
        return axis2_http_header_get_value(tmp_header, env);

    return AXIS2_HTTP_HEADER_ACCEPT_TEXT_PLAIN;
}


AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_http_simple_request_get_charset(
    const axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env)
{
    axis2_http_header_t *tmp_header  = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    tmp_header = axis2_http_simple_request_get_first_header
            (simple_request, env, AXIS2_HTTP_HEADER_CONTENT_TYPE);
    if (tmp_header)
    {
        axis2_char_t *value = axis2_http_header_get_value(tmp_header, env);
        axis2_char_t *charset = (axis2_char_t *)strstr((char *)value,
                (char *)AXIS2_HTTP_CHAR_SET_ENCODING);
        if (charset)
        {
            charset = strchr((char *)charset, '=');
            return charset;
        }
    }

    return AXIS2_HTTP_DEFAULT_CONTENT_CHARSET;
}


AXIS2_EXTERN axis2_ssize_t AXIS2_CALL
axis2_http_simple_request_get_content_length(
    const axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env)
{
    axis2_http_header_t *tmp_header = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    tmp_header = axis2_http_simple_request_get_first_header
            (simple_request, env, AXIS2_HTTP_HEADER_CONTENT_LENGTH);
    if (tmp_header)
    {
        return AXIS2_ATOI(axis2_http_header_get_value(tmp_header, env));
    }
    return -1;
}


AXIS2_EXTERN axutil_stream_t *AXIS2_CALL
axis2_http_simple_request_get_body(
    const axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env)
{
    return simple_request->stream;
}


AXIS2_EXTERN axis2_ssize_t AXIS2_CALL
axis2_http_simple_request_get_body_bytes(
    const axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env,
    char **buf)
{
    axutil_stream_t *body = NULL;
    char *tmp_buf = NULL;
    char *tmp_buf2 = NULL;
    char *tmp_buf3 = NULL;
    int length = 0;
    int read_len = 0;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    body = simple_request->stream;
    if (! body)
    {
        *buf = (char*)AXIS2_MALLOC(env->allocator, 1);
        *buf[0] = '\0';
        return 0;
    }
    length = axis2_http_simple_request_get_content_length(simple_request, env);
    if (length > 0)
    {
        *buf = (char*)AXIS2_MALLOC(env->allocator, length + 1);
        read_len = axutil_stream_read(body, env, *buf, length + 1);
        return read_len;
    }
    tmp_buf2 = AXIS2_MALLOC(env->allocator, 128 * sizeof(char));
    while (axutil_stream_read(body, env, tmp_buf2, 128) > 0)
    {
        tmp_buf3 = axutil_stracat(env, tmp_buf, tmp_buf2);
        if (tmp_buf)
        {
            AXIS2_FREE(env->allocator, tmp_buf);
            tmp_buf = NULL;
        }
        tmp_buf = tmp_buf3;

    }
    if (tmp_buf)
    {
        *buf = tmp_buf;
        return axutil_strlen(tmp_buf);
    }
    return -1;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_simple_request_set_body_string(
    axis2_http_simple_request_t *simple_request,
    const axutil_env_t *env,
    void *str,
    unsigned int str_len)
{
    axutil_stream_t *body_stream = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, str, AXIS2_FAILURE);

    body_stream = simple_request->stream;
    if (! body_stream)
    {
        body_stream = axutil_stream_create_basic(env);
        if (! body_stream)
        {
            return AXIS2_FAILURE;
        }
        simple_request->stream = body_stream;
        simple_request->owns_stream = AXIS2_TRUE;
    }
    axutil_stream_write(body_stream, env, str, str_len);
    return AXIS2_SUCCESS;
}
