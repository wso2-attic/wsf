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

#include <axis2_http_status_line.h>
#include <axutil_string.h>
#include <axis2_http_transport.h>
#include <string.h>
#include <axutil_types.h>

struct axis2_http_status_line
{
    axis2_char_t *line;
    axis2_char_t *http_version;
    axis2_char_t *status_code;
    axis2_char_t *reason_phrase;
};

AXIS2_EXTERN axis2_http_status_line_t *AXIS2_CALL
axis2_http_status_line_create(
    const axutil_env_t *env,
    const axis2_char_t *str)
{
    axis2_char_t *tmp_status_line = NULL;
    axis2_char_t *reason_phrase = NULL;
    axis2_char_t *status_code = NULL;
    axis2_char_t *http_version = NULL;
    int i = 0;
    axis2_char_t *tmp = NULL;
    axis2_http_status_line_t *status_line  = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    status_line = (axis2_http_status_line_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_http_status_line_t));

    if (! status_line)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

	status_line->line = (axis2_char_t *)axutil_strdup(env, str);
    status_line->http_version = NULL;
    status_line->reason_phrase = NULL;
    status_line->status_code = NULL;

    tmp = strstr(str, AXIS2_HTTP_CRLF);
    if (! tmp)
    {
        axis2_http_status_line_free((axis2_http_status_line_t *)
                status_line, env);
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_HTTP_HEADER_START_LINE,
                AXIS2_FAILURE);
        return NULL;
    }
    i = tmp - str;
    tmp_status_line = AXIS2_MALLOC(env->allocator,
            i * sizeof(axis2_char_t) + 1);
    if (! tmp_status_line)
    {
        axis2_http_status_line_free((axis2_http_status_line_t *)
                status_line, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    memcpy(tmp_status_line, str, i *sizeof(axis2_char_t));
    tmp_status_line[i] = '\0';
    tmp = tmp_status_line;

    http_version = tmp;
    tmp = strchr(tmp, ' ');
    if (! tmp)
    {
        AXIS2_FREE(env->allocator, tmp_status_line);
        axis2_http_status_line_free((axis2_http_status_line_t *)
                status_line, env);
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_HTTP_HEADER_START_LINE,
                AXIS2_FAILURE);
        return NULL;
    }
    *tmp++ = '\0';
    status_code = tmp;
    tmp = strchr(tmp, ' ');
    if (! tmp)
    {
        AXIS2_FREE(env->allocator, tmp_status_line);
        axis2_http_status_line_free((axis2_http_status_line_t *)
                status_line, env);
        AXIS2_ERROR_SET(env->error,
                AXIS2_ERROR_INVALID_HTTP_HEADER_START_LINE,
                AXIS2_FAILURE);
        return NULL;
    }
    *tmp++ = '\0';
    reason_phrase = tmp;
    status_line->http_version = (axis2_char_t *)
            axutil_strdup(env, http_version);
    status_line->status_code = (axis2_char_t *)
            axutil_strdup(env, status_code);
    status_line->reason_phrase = (axis2_char_t *)
            axutil_strdup(env, reason_phrase);

    if (! status_line->http_version ||
            ! status_line->reason_phrase)
    {
        AXIS2_FREE(env->allocator, tmp_status_line);
        axis2_http_status_line_free((axis2_http_status_line_t *)
                status_line, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    AXIS2_FREE(env->allocator, tmp_status_line);

    return status_line;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_status_line_free(
    axis2_http_status_line_t *status_line,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (status_line->line)
    {
        AXIS2_FREE(env->allocator, status_line->line);
    }
    if (status_line->http_version)
    {
        AXIS2_FREE(env->allocator, status_line->http_version);
    }
    if (status_line->status_code)
    {
        AXIS2_FREE(env->allocator, status_line->status_code);
    }
    if (status_line->reason_phrase)
    {
        AXIS2_FREE(env->allocator, status_line->reason_phrase);
    }

    AXIS2_FREE(env->allocator, status_line);
    return;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_http_status_line_get_status_code(
    const axis2_http_status_line_t *status_line,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    if (status_line->status_code)
    {
        return AXIS2_ATOI(status_line->status_code);
    }
    else
    {
        return AXIS2_CRITICAL_FAILURE;
    }

}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_status_line_get_http_version(
    const axis2_http_status_line_t *status_line,
    const axutil_env_t *env)
{
    return status_line->http_version;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_status_line_get_reason_phrase(
    const axis2_http_status_line_t *status_line,
    const axutil_env_t *env)
{
    return status_line->reason_phrase;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_http_status_line_starts_with_http(
    axis2_http_status_line_t *status_line,
    const axutil_env_t *env)
{
    if (0 == axutil_strncasecmp(status_line->line, "HTTP", 4))
    {
        return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_status_line_to_string(
    axis2_http_status_line_t *status_line,
    const axutil_env_t *env)
{
    return status_line->line;
}
