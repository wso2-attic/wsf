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

#include "wsf_out_transport_info.h"
#include <axutil_string.h>
#include <axis2_http_transport.h>


/** 
 * @brief wsf_out_transport_info struct
 */
typedef struct wsf_out_transport_info_impl wsf_out_transport_info_impl_t;

struct wsf_out_transport_info_impl
{
    axis2_http_out_transport_info_t out_transport_info;
    wsf_response_info_t *response;
    axis2_char_t *encoding;
};

#define AXIS2_INTF_TO_IMPL(out_transport_info) \
		((wsf_out_transport_info_impl_t *)(out_transport_info))

/***************************** Function headers *******************************/
axis2_status_t WSF_CALL wsf_http_out_transport_info_set_content_type (
    axis2_http_out_transport_info_t * info,
    const axutil_env_t * env,
    const axis2_char_t * content_type);

axis2_status_t WSF_CALL wsf_http_out_transport_info_set_char_encoding (
    axis2_http_out_transport_info_t * info,
    const axutil_env_t * env,
    const axis2_char_t * encoding);

axis2_status_t WSF_CALL wsf_http_out_transport_info_free (
    axis2_http_out_transport_info_t * out_transport_info,
    const axutil_env_t * env);

axis2_status_t WSF_CALL
wsf_out_transport_info_impl_set_content_type(
    axis2_out_transport_info_t * out_transport_info,
    const axutil_env_t * env,
    const axis2_char_t * content_type)
{
    return 0;
}

axis2_status_t AXIS2_CALL
wsf_out_transport_info_impl_set_char_encoding(
    axis2_out_transport_info_t * out_transport_info,
    const axutil_env_t * env,
    const axis2_char_t * encoding)
{   
    return 0;
}

axis2_status_t AXIS2_CALL
wsf_out_transport_info_impl_set_cookie_header(
    axis2_out_transport_info_t * info,
    const axutil_env_t * env,
    const axis2_char_t * cookie_header)
{
	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
wsf_out_transport_info_impl_set_session(
    axis2_out_transport_info_t * info,
    const axutil_env_t * env,
    const axis2_char_t * session_id,
    const axis2_char_t * session_value)
{
	return AXIS2_SUCCESS;
}

void AXIS2_CALL
wsf_out_transport_info_impl_free(
    axis2_out_transport_info_t * out_transport_info,
    const axutil_env_t * env)
{
    return;
}
/******************************************************************************/

static const axis2_out_transport_info_ops_t ops_var = {
    wsf_out_transport_info_impl_set_content_type,
    wsf_out_transport_info_impl_set_char_encoding,
	wsf_out_transport_info_impl_set_cookie_header,
	wsf_out_transport_info_impl_set_session,
    wsf_out_transport_info_impl_free
};

/***************************** End of function headers ************************/

axis2_http_out_transport_info_t *
wsf_out_transport_info_create (
    const axutil_env_t * env,
    wsf_response_info_t * request)
{
    wsf_out_transport_info_impl_t *info_impl = NULL;
    axis2_http_out_transport_info_t *out_transport_info = NULL;

	info_impl = (wsf_out_transport_info_impl_t *) AXIS2_MALLOC
        (env->allocator, sizeof (wsf_out_transport_info_impl_t));

    if (NULL == info_impl) 
	{
        AXIS2_ERROR_SET (env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    info_impl->response = request;
    info_impl->encoding = NULL;

    out_transport_info = &(info_impl->out_transport_info);
    out_transport_info->out_transport.ops = &ops_var;

    axis2_http_out_transport_info_set_char_encoding_func (out_transport_info,
        env, wsf_http_out_transport_info_set_char_encoding);
    axis2_http_out_transport_info_set_content_type_func (out_transport_info,
        env, wsf_http_out_transport_info_set_content_type);
    axis2_http_out_transport_info_set_free_func (out_transport_info, env,
        (void *) wsf_http_out_transport_info_free);
    return out_transport_info;
}


axis2_status_t WSF_CALL
wsf_http_out_transport_info_free (
    axis2_http_out_transport_info_t * info,
    const axutil_env_t * env)
{
    wsf_out_transport_info_impl_t *info_impl = NULL;
    info_impl = AXIS2_INTF_TO_IMPL (info);

    info_impl->response = NULL;  /* request doesn't belong to info */
    if (NULL != info_impl->encoding) 
	{
        AXIS2_FREE (env->allocator, info_impl->encoding);
        info_impl->encoding = NULL;
    }
    AXIS2_FREE (env->allocator, info_impl);
    return AXIS2_SUCCESS;
}

axis2_status_t WSF_CALL
wsf_out_transport_info_free_void_arg (
    void *transport_info,
    const axutil_env_t * env)
{
    axis2_http_out_transport_info_t *transport_info_l = NULL;

    transport_info_l = (axis2_http_out_transport_info_t *) transport_info;
    return wsf_http_out_transport_info_free (transport_info_l, env);
}

axis2_status_t WSF_CALL wsf_http_out_transport_info_set_content_type (
    axis2_http_out_transport_info_t * info,
    const axutil_env_t * env,
    const axis2_char_t * content_type)
{
    axis2_char_t *tmp1 = NULL;
    axis2_char_t *tmp2 = NULL;
    wsf_out_transport_info_impl_t *info_impl = NULL;

    AXIS2_PARAM_CHECK (env->error, content_type, AXIS2_FAILURE);

    info_impl = AXIS2_INTF_TO_IMPL (info);

    if (NULL != info_impl->encoding && axutil_strstr(content_type, "charset=") == NULL)
    {
        	tmp1 = axutil_stracat (env, content_type, ";charset=");
        	tmp2 = axutil_stracat (env, tmp1, info_impl->encoding);
        	info_impl->response->content_type = axutil_strdup (env, tmp2);
        	AXIS2_FREE (env->allocator, tmp1);
        	AXIS2_FREE (env->allocator, tmp2);
    }
    else
    {
        info_impl->response->content_type = axutil_strdup (env, content_type);
    }
    return AXIS2_SUCCESS;
}


axis2_status_t WSF_CALL wsf_http_out_transport_info_set_char_encoding (
    axis2_http_out_transport_info_t * info,
    const axutil_env_t * env,
    const axis2_char_t * encoding)
{
    wsf_out_transport_info_impl_t *info_impl = NULL;
    if (!encoding)
        return AXIS2_FAILURE;

    info_impl = AXIS2_INTF_TO_IMPL (info);

    if (NULL != info_impl->encoding) {
        AXIS2_FREE (env->allocator, info_impl->encoding);
    }
    info_impl->encoding = axutil_strdup (env, encoding);
    return AXIS2_SUCCESS;
}

