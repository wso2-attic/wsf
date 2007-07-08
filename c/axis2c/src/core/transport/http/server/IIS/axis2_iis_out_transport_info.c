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

#include "axis2_iis_out_transport_info.h"
#include <axutil_string.h>
#include <axis2_http_transport.h>
#include <axutil_string.h>

#include "axis2_iis_constants.h"
/**
 * @brief IIS Out transport info impl structure
 * Axis2 iis_out_transport_info_impl
 */


typedef struct axis2_iis_out_transport_info_s
{
    axis2_http_out_transport_info_t out_transport_info;    
    axis2_char_t *encoding;
	axis2_char_t content_type[MAX_HTTP_CONTENT_TYPE_LEN];
}axis2_iis_out_transport_info_t;

#define AXIS2_INTF_TO_IMPL(out_transport_info) \
                ((axis2_iis_out_transport_info_t *)(out_transport_info))

void AXIS2_CALL
axis2_iis_out_transport_info_free(
    axis2_http_out_transport_info_t *out_transport_info,
    const axutil_env_t *env)
{
    axis2_iis_out_transport_info_t *info = NULL;
    AXIS2_ENV_CHECK(env, void);

    info = AXIS2_INTF_TO_IMPL(out_transport_info);
    
    if (info->encoding)
    {
        AXIS2_FREE(env->allocator, info->encoding);
        info->encoding = NULL;
    }

    AXIS2_FREE(env->allocator, info);
    return;
}

void AXIS2_CALL
axis2_iis_out_transport_info_free_void_arg(
    void *transport_info,
    const axutil_env_t *env)
{
    axis2_http_out_transport_info_t *transport_info_l = NULL;

    AXIS2_ENV_CHECK(env, void);
    transport_info_l = (axis2_http_out_transport_info_t *) transport_info;
    axis2_http_out_transport_info_free(transport_info_l, env);
    return;
}

axis2_status_t AXIS2_CALL
axis2_iis_out_transport_info_set_content_type(
    axis2_http_out_transport_info_t *info,
    const axutil_env_t *env,
    const axis2_char_t *content_type)
{
	int temp = 0;
    axis2_iis_out_transport_info_t *info_impl = NULL;

	info_impl = AXIS2_INTF_TO_IMPL(info);	
	info_impl->content_type[0] = '\0';	
    if (info_impl->encoding)
    {       
		sprintf(info_impl->content_type, "%s%s%s", content_type, ";charser:", info_impl->encoding);			
    }
    else
    {
		strcat(info_impl->content_type, content_type);
    }
    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
axis2_iis_out_transport_info_set_char_encoding(
    axis2_http_out_transport_info_t *info,
    const axutil_env_t *env,
    const axis2_char_t *encoding)
{
    axis2_iis_out_transport_info_t *info_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, encoding, AXIS2_FAILURE);

    info_impl = AXIS2_INTF_TO_IMPL(info);

    if (info_impl->encoding)
    {
        AXIS2_FREE(env->allocator, info_impl->encoding);
    }
    info_impl->encoding = axutil_strdup(env, encoding);

    return AXIS2_SUCCESS;
}
axis2_http_out_transport_info_t *AXIS2_CALL
axis2_iis_out_transport_info_create(
    const axutil_env_t *env,
	LPEXTENSION_CONTROL_BLOCK lpECB)
{
    axis2_iis_out_transport_info_t *info = NULL;
    axis2_http_out_transport_info_t *http_out_info = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    info = (axis2_iis_out_transport_info_t *)AXIS2_MALLOC
            (env->allocator, sizeof(
                        axis2_iis_out_transport_info_t));

    if (! info)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    info->encoding = NULL;

    http_out_info =  &(info->out_transport_info);

    axis2_http_out_transport_info_set_content_type_func(http_out_info, 
            env, axis2_iis_out_transport_info_set_content_type); 
    axis2_http_out_transport_info_set_char_encoding_func(http_out_info,
            env, axis2_iis_out_transport_info_set_char_encoding);
	axis2_http_out_transport_info_set_free_func(http_out_info, 
            env, axis2_iis_out_transport_info_free);

    return http_out_info;
}

axis2_char_t *
axis2_iis_out_transport_get_content(axis2_http_out_transport_info_t *info)
{
	axis2_iis_out_transport_info_t *info_impl = NULL;
	info_impl = AXIS2_INTF_TO_IMPL(info);
	return info_impl->content_type;
}




