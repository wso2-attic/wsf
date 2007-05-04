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

#include <axis2_http_out_transport_info.h>
#include <axutil_string.h>
#include <axis2_http_transport.h>
#include <axutil_string.h>

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_out_transport_info_impl_set_content_type(
    axis2_http_out_transport_info_t *http_out_transport_info,
    const axutil_env_t *env,
    const axis2_char_t *content_type)
{
    axis2_char_t *tmp1 = NULL;
    axis2_char_t *tmp2 = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, content_type, AXIS2_FAILURE);
    if (http_out_transport_info->encoding)
    {
        axis2_char_t *charset_pos = axutil_strcasestr(content_type, "charset");
        if (!charset_pos)
        {
            tmp1 = axutil_stracat(env, content_type, ";charset=");
            tmp2 = axutil_stracat(env, tmp1, http_out_transport_info->encoding);
            axis2_http_simple_response_set_header(http_out_transport_info->response, env,
                    axis2_http_header_create(env, AXIS2_HTTP_HEADER_CONTENT_TYPE,
                            tmp2));
            AXIS2_FREE(env->allocator, tmp1);
            AXIS2_FREE(env->allocator, tmp2);
        }
        else
        {
            axis2_http_simple_response_set_header(http_out_transport_info->response, env,
                axis2_http_header_create(env, AXIS2_HTTP_HEADER_CONTENT_TYPE,
                        content_type));
        }
    }
    else
    {
        if(http_out_transport_info->response)
            axis2_http_simple_response_set_header(http_out_transport_info->response, env,
                axis2_http_header_create(env, AXIS2_HTTP_HEADER_CONTENT_TYPE,
                        content_type));
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_out_transport_info_impl_set_char_encoding(
    axis2_http_out_transport_info_t *http_out_transport_info,
    const axutil_env_t *env,
    const axis2_char_t *encoding)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, encoding, AXIS2_FAILURE);
    if (http_out_transport_info->encoding)
    {
        AXIS2_FREE(env->allocator, http_out_transport_info->encoding);
    }
    http_out_transport_info->encoding = axutil_strdup(env, encoding);
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN void AXIS2_CALL
axis2_http_out_transport_info_impl_free(
    axis2_http_out_transport_info_t *http_out_transport_info,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);
    if(http_out_transport_info->response)
    {
        axis2_http_simple_response_free(http_out_transport_info->response, env);
    }
    if (http_out_transport_info->encoding)
    {
        AXIS2_FREE(env->allocator, http_out_transport_info->encoding);
    }
    AXIS2_FREE(env->allocator, http_out_transport_info);
    return;
}

AXIS2_EXTERN axis2_http_out_transport_info_t *AXIS2_CALL
axis2_http_out_transport_info_create(
    const axutil_env_t *env,
    axis2_http_simple_response_t *response)
{
    axis2_http_out_transport_info_t *http_out_transport_info = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    http_out_transport_info = (axis2_http_out_transport_info_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_http_out_transport_info_t));

    if (! http_out_transport_info)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    http_out_transport_info->response = response;
    http_out_transport_info->encoding = NULL;
	http_out_transport_info->set_char_encoding = NULL;
	http_out_transport_info->set_content_type = NULL;
	http_out_transport_info->free_function = NULL;

	http_out_transport_info->set_char_encoding =
          axis2_http_out_transport_info_impl_set_char_encoding;
	http_out_transport_info->set_content_type = 
        axis2_http_out_transport_info_impl_set_content_type;
	http_out_transport_info->free_function = 
        axis2_http_out_transport_info_impl_free;
    
    return http_out_transport_info;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_out_transport_info_free(
    axis2_http_out_transport_info_t *http_out_transport_info,
    const axutil_env_t *env)
{
    http_out_transport_info->free_function(http_out_transport_info, env);
    return;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_out_transport_info_free_void_arg(
    void *transport_info,
    const axutil_env_t *env)
{
    axis2_http_out_transport_info_t *transport_info_l = NULL;

    AXIS2_ENV_CHECK(env, void);
    transport_info_l = (axis2_http_out_transport_info_t *) transport_info;
    axis2_http_out_transport_info_free(transport_info_l, env);
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_out_transport_info_set_content_type(
    axis2_http_out_transport_info_t *http_out_transport_info,
    const axutil_env_t *env,
    const axis2_char_t *content_type)
{
	return http_out_transport_info->set_content_type(http_out_transport_info, env, content_type);
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_http_out_transport_info_set_char_encoding(
    axis2_http_out_transport_info_t *http_out_transport_info,
    const axutil_env_t *env,
    const axis2_char_t *encoding)
{
	return http_out_transport_info->set_char_encoding(http_out_transport_info, env, encoding);
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_out_transport_info_set_char_encoding_func(
		axis2_http_out_transport_info_t *out_transport_info,
		const axutil_env_t *env,
		axis2_status_t (AXIS2_CALL *set_char_encoding)
		(axis2_http_out_transport_info_t *,	const axutil_env_t *,const axis2_char_t *))
{
	out_transport_info->set_char_encoding = set_char_encoding;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_out_transport_info_set_content_type_func(
	axis2_http_out_transport_info_t *out_transport_info,
	const axutil_env_t *env,
	axis2_status_t (AXIS2_CALL *set_content_type)(
		axis2_http_out_transport_info_t *,
		const axutil_env_t*,const axis2_char_t *))
{
	out_transport_info->set_content_type = set_content_type;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_http_out_transport_info_set_free_func(
    axis2_http_out_transport_info_t *out_transport_info,
    const axutil_env_t *env,
    void (AXIS2_CALL *free_function)(axis2_http_out_transport_info_t *,const axutil_env_t*)
    )
{
	out_transport_info->free_function = free_function;
}
