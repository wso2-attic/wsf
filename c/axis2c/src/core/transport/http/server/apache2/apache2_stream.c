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

#include <string.h>
#include <stdlib.h>
#include "apache2_stream.h"
#include <http_protocol.h>

typedef struct apache2_stream_impl
{
    axutil_stream_t stream;
    axutil_stream_type_t stream_type;
    request_rec *request;
}apache2_stream_impl_t;

#define AXIS2_INTF_TO_IMPL(stream) ((apache2_stream_impl_t *)(stream))

axutil_stream_type_t AXIS2_CALL
apache2_stream_get_type(
    axutil_stream_t *stream,
    const axutil_env_t *env);

int AXIS2_CALL
apache2_stream_write(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    const void *buffer,
    size_t count);

int AXIS2_CALL
apache2_stream_read(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    void *buffer,
    size_t count);

int AXIS2_CALL
apache2_stream_skip(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    int count);

int AXIS2_CALL
apache2_stream_get_char(
    axutil_stream_t *stream,
    const axutil_env_t *env);

AXIS2_EXTERN axutil_stream_t * AXIS2_CALL
axutil_stream_create_apache2(
    const axutil_env_t *env,
    request_rec *request)
{
    apache2_stream_impl_t *stream_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, request, NULL);

    stream_impl = (apache2_stream_impl_t *)AXIS2_MALLOC(
                env->allocator, sizeof(apache2_stream_impl_t));

    if (! stream_impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    stream_impl->request = request;
    stream_impl->stream_type = AXIS2_STREAM_MANAGED;

    axutil_stream_set_read(&(stream_impl->stream), env, apache2_stream_read);
    axutil_stream_set_write(&(stream_impl->stream), env, apache2_stream_write);
    axutil_stream_set_skip(&(stream_impl->stream), env, apache2_stream_skip);

    return &(stream_impl->stream);
}

int AXIS2_CALL
apache2_stream_read(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    void *buffer,
    size_t count)
{
    apache2_stream_impl_t *stream_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);

    stream_impl = AXIS2_INTF_TO_IMPL(stream);
    return ap_get_client_block(stream_impl->request, buffer, count);
}

int AXIS2_CALL
apache2_stream_write(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    const void *buf,
    size_t count)
{
    apache2_stream_impl_t *stream_impl = NULL;
    axis2_char_t *buffer = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    AXIS2_PARAM_CHECK(env->error, buf, AXIS2_FAILURE);
    stream_impl = AXIS2_INTF_TO_IMPL(stream);
    buffer = (axis2_char_t*)buf;
    if (count <= 0)
    {
        return count;
    }
    /* assume that buffer is not null terminated */
    return ap_rwrite(buffer, count, stream_impl->request);
}


int AXIS2_CALL
apache2_stream_skip(
    axutil_stream_t *stream,
    const axutil_env_t *env,
    int count)
{
    apache2_stream_impl_t *stream_impl = NULL;
    axis2_char_t *tmp_buffer = NULL;
    int len = -1;
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    stream_impl = AXIS2_INTF_TO_IMPL(stream);

    tmp_buffer = AXIS2_MALLOC(env->allocator, count * sizeof(axis2_char_t));
    if (tmp_buffer == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY,
                AXIS2_FAILURE);
        return -1;
    }
    len = ap_get_client_block(stream_impl->request, tmp_buffer, count);
    AXIS2_FREE(env->allocator, tmp_buffer);
    return len;

}

int AXIS2_CALL
apache2_stream_get_char(
    axutil_stream_t *stream,
    const axutil_env_t *env)
{
    int ret = -1;
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);

    return ret;
}

axutil_stream_type_t AXIS2_CALL
apache2_stream_get_type(
    axutil_stream_t *stream,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_CRITICAL_FAILURE);
    return AXIS2_INTF_TO_IMPL(stream)->stream_type;
}

