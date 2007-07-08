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

#include <axis2_http_header.h>
#include <axutil_string.h>
#include <axis2_http_transport.h>
#include <stdio.h>
#include <string.h>

struct axis2_http_header
{
    axis2_char_t *name;
    axis2_char_t *value;
};

AXIS2_EXTERN axis2_http_header_t *AXIS2_CALL
axis2_http_header_create(
    const axutil_env_t *env,
    const axis2_char_t *name,
    const axis2_char_t *value)
{
    axis2_http_header_t *http_header = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_ENV_CHECK(env, NULL);

    http_header = (axis2_http_header_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_http_header_t));

    if (! http_header)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    http_header->name = (axis2_char_t *)axutil_strdup(env, name);
    http_header->value = (axis2_char_t *)axutil_strdup(env, value);

    return http_header;
}

AXIS2_EXTERN axis2_http_header_t *AXIS2_CALL
axis2_http_header_create_by_str(
    const axutil_env_t *env,
    const axis2_char_t *str)
{
    axis2_char_t *tmp_str = NULL;
    axis2_char_t *ch = NULL;
    axis2_char_t *ch2 = NULL;
    axis2_http_header_t *ret = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_ENV_CHECK(env, NULL);

    tmp_str = axutil_strdup(env, str);
    if (! tmp_str)
    {
        return NULL;
    }
    /* remove trailing \r\n */
    if ('\r' == tmp_str[axutil_strlen(tmp_str)-2])
    {
        tmp_str[axutil_strlen(tmp_str)-2] = '\0';
    }

    ch = strchr((const char *)tmp_str, ':');
    if (! ch)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_HEADER,
                AXIS2_FAILURE);
        AXIS2_FREE(env->allocator, tmp_str);
        return NULL;
    }
    ch2 = ch + sizeof(axis2_char_t);
    /* skip spaces */
    while (' ' == *ch2)
    {
        ch2 += sizeof(axis2_char_t);
    }
    *ch = '\0';
    ret = axis2_http_header_create(env, tmp_str, ch2);
    AXIS2_FREE(env->allocator, tmp_str);
    return ret;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_header_free(
    axis2_http_header_t *http_header,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (http_header->name)
    {
        AXIS2_FREE(env->allocator, http_header->name);
    }
    if (http_header->value)
    {
        AXIS2_FREE(env->allocator, http_header->value);
    }

    AXIS2_FREE(env->allocator, http_header);
    return;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_header_to_external_form(
    axis2_http_header_t *http_header,
    const axutil_env_t *env)
{
    axis2_ssize_t len = 0;
    axis2_char_t *external_form = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    len = axutil_strlen(http_header->name) +
            axutil_strlen(http_header->value) + 8;
    external_form = (axis2_char_t *) AXIS2_MALLOC(env->allocator,
            len);
    sprintf(external_form, "%s: %s%s", http_header->name,
            http_header->value, AXIS2_HTTP_CRLF);
    return external_form;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_http_header_get_name(
    const axis2_http_header_t *http_header,
    const axutil_env_t *env)
{
    return http_header->name;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL

axis2_http_header_get_value(
    const axis2_http_header_t *http_header,
    const axutil_env_t *env)
{
    return http_header->value;
}
