/*
 * Copyright 2005,2010 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <axutil_stream.h>
#include "wsf_common.h"
#include <string.h>
#include <stdlib.h>
#include <SAPI.h>
#include <php.h>

typedef struct wsf_stream_impl wsf_stream_impl_t;

struct wsf_stream_impl
{
    axutil_stream_t stream;
    axutil_stream_type_t stream_type;
    wsf_request_info_t *req_info;
    axis2_char_t *buffer;
    int current_rlen;
    int buffer_len;
};

#define AXIS2_INTF_TO_IMPL(stream) ((wsf_stream_impl_t *)(stream))

axis2_status_t WSF_CALL 
wsf_stream_free (
    axutil_stream_t * stream,
    const axutil_env_t * env);

axutil_stream_type_t WSF_CALL 
wsf_stream_get_type (
    axutil_stream_t * stream,
    const axutil_env_t * env);

int WSF_CALL 
wsf_stream_write (
    axutil_stream_t * stream,
    const axutil_env_t * env,
    const void *buffer,
    size_t count);

int WSF_CALL 
wsf_stream_read (
    axutil_stream_t * stream,
    const axutil_env_t * env,
    void *buffer,
    size_t count);

int WSF_CALL 
wsf_stream_skip (
    axutil_stream_t * stream,
    const axutil_env_t * env,
    int count);

WSF_PHP_API axutil_stream_t *WSF_CALL
wsf_stream_create (
    const axutil_env_t * env,
    wsf_request_info_t * req_info TSRMLS_DC)
{
    wsf_stream_impl_t *stream_impl = NULL;

    stream_impl = (wsf_stream_impl_t *) AXIS2_MALLOC (env->allocator,
        sizeof (wsf_stream_impl_t));

    if (!stream_impl) {
        AXIS2_ERROR_SET (env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    axutil_stream_set_read (&(stream_impl->stream), env, wsf_stream_read);
    axutil_stream_set_write (&(stream_impl->stream), env, wsf_stream_write);
    axutil_stream_set_skip (&(stream_impl->stream), env, wsf_stream_skip);

    stream_impl->req_info = req_info;
    stream_impl->buffer = NULL;
    stream_impl->buffer_len = 0;
    stream_impl->current_rlen = 0;
    stream_impl->buffer = AXIS2_MALLOC(env->allocator,
		sizeof (axis2_char_t) * req_info->request_data_length);

    memcpy (stream_impl->buffer, req_info->request_data,
        req_info->request_data_length);

    stream_impl->buffer_len = req_info->request_data_length;

    return &(stream_impl->stream);
}

axis2_status_t WSF_CALL
wsf_stream_free (
    axutil_stream_t * stream,
    const axutil_env_t * env)
{
    wsf_stream_impl_t *stream_impl = NULL;
    stream_impl = AXIS2_INTF_TO_IMPL (stream);

    if (stream_impl->buffer) {
        AXIS2_FREE (env->allocator, stream_impl->buffer);
        stream_impl->buffer = NULL;
    }

	AXIS2_FREE (env->allocator, stream_impl);
    return AXIS2_SUCCESS;
}

axutil_stream_type_t WSF_CALL
wsf_stream_get_type (
    axutil_stream_t * stream,
    const axutil_env_t * env)
{

    return AXIS2_INTF_TO_IMPL (stream)->stream_type;
}

int WSF_CALL
wsf_stream_write (
    axutil_stream_t * stream,
    const axutil_env_t * env,
    const void *buf,
    size_t count)
{
    return -1;
}

int WSF_CALL
wsf_stream_read (
    axutil_stream_t * stream,
    const axutil_env_t * env,
    void *buffer,
    size_t count)
{
    wsf_stream_impl_t *stream_impl = NULL;
    int len = 0;
    
	stream_impl = AXIS2_INTF_TO_IMPL (stream);
    if (!buffer)
        return -1;

    len = stream_impl->buffer_len - stream_impl->current_rlen;
    if (len >= count) 
	{
        memcpy (buffer, stream_impl->buffer 
			+  stream_impl->current_rlen * sizeof (axis2_char_t), count);

        stream_impl->current_rlen += count;

        return count;
    } else if (len < count && len > 0) 
	{
        memcpy (buffer, stream_impl->buffer 
			+ stream_impl->current_rlen * sizeof (axis2_char_t), len);

        stream_impl->current_rlen += len;
        
		return len;

    } else 
	{
        buffer = '\0';
        return 0;
    }
}

int WSF_CALL
wsf_stream_skip (
    axutil_stream_t * stream,
    const axutil_env_t * env,
    int count)
{
    wsf_stream_impl_t *stream_impl = NULL;
    stream_impl = AXIS2_INTF_TO_IMPL (stream);
    return -1;
}

