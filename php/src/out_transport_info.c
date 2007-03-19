/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
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
#include <axis2_string.h>
#include <axis2_http_transport.h>


/** 
 * @brief wsf_out_transport_info struct
 */
typedef struct wsf_out_transport_info_impl 
					wsf_out_transport_info_impl_t;  
  
struct wsf_out_transport_info_impl
{
	axis2_http_out_transport_info_t out_transport_info;
	wsf_req_info_t *request;
	axis2_char_t *encoding;
};

#define AXIS2_INTF_TO_IMPL(out_transport_info) \
					((wsf_out_transport_info_impl_t *)(out_transport_info))

/***************************** Function headers *******************************/
axis2_status_t WSF_CALL 
wsf_http_out_transport_info_set_content_type 
       (axis2_http_out_transport_info_t *info, 
		const axis2_env_t *env, 
        const axis2_char_t *content_type);

axis2_status_t WSF_CALL 
wsf_http_out_transport_info_set_char_encoding 
           (axis2_http_out_transport_info_t *info, 
			const axis2_env_t *env,
            const axis2_char_t *encoding);
    
axis2_status_t WSF_CALL 
wsf_http_out_transport_info_free 
           (axis2_http_out_transport_info_t *out_transport_info, 
            const axis2_env_t *env);



/***************************** End of function headers ************************/

axis2_http_out_transport_info_t* 
wsf_out_transport_info_create(const axis2_env_t *env,
                        wsf_req_info_t *request)
{
    wsf_out_transport_info_impl_t *info_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
        
    info_impl = (wsf_out_transport_info_impl_t *)AXIS2_MALLOC 
          (env->allocator, sizeof(wsf_out_transport_info_impl_t));
   
    if(NULL == info_impl){
      AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    info_impl->request = request;
    info_impl->encoding = NULL;  
     
    info_impl->out_transport_info.ops = AXIS2_MALLOC(env->allocator,
                    sizeof(axis2_http_out_transport_info_ops_t));
    if(NULL == info_impl->out_transport_info.ops){
		wsf_http_out_transport_info_free((axis2_http_out_transport_info_t*)
                         info_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
      return NULL;
    }

    info_impl->out_transport_info.ops->set_content_type = 
                  wsf_http_out_transport_info_set_content_type;
    info_impl->out_transport_info.ops->set_char_encoding = 
                  wsf_http_out_transport_info_set_char_encoding;
    info_impl->out_transport_info.ops->free = 
                  wsf_http_out_transport_info_free;
                        
   return &(info_impl->out_transport_info);
}


axis2_status_t WSF_CALL 
wsf_http_out_transport_info_free (axis2_http_out_transport_info_t *info, 
                  const axis2_env_t *env)
{
    wsf_out_transport_info_impl_t *info_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    info_impl = AXIS2_INTF_TO_IMPL(info);
   
	info_impl->request = NULL; /* request doesn't belong to info */
    if(NULL != info_impl->encoding){
        AXIS2_FREE(env->allocator, info_impl->encoding);
        info_impl->encoding = NULL;
    }
    if(NULL != info->ops)
        AXIS2_FREE(env->allocator, info->ops);
    
   AXIS2_FREE(env->allocator, info_impl);
   return AXIS2_SUCCESS;
}

axis2_status_t WSF_CALL
wsf_out_transport_info_free_void_arg (void *transport_info,
                                             const axis2_env_t *env)
{
    axis2_http_out_transport_info_t *transport_info_l = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    transport_info_l = (axis2_http_out_transport_info_t *) transport_info;
    return wsf_http_out_transport_info_free(transport_info_l, env);
}

axis2_status_t WSF_CALL 
wsf_http_out_transport_info_set_content_type 
            (axis2_http_out_transport_info_t *info, const axis2_env_t *env, 
            const axis2_char_t *content_type)
{
   axis2_char_t *tmp1 = NULL;
   axis2_char_t *tmp2 = NULL;
   wsf_out_transport_info_impl_t *info_impl = NULL;
   
   AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
   AXIS2_PARAM_CHECK(env->error, content_type, AXIS2_FAILURE);
   
   info_impl = AXIS2_INTF_TO_IMPL(info);
   
   if(NULL != info_impl->encoding){
      
      tmp1 = axis2_stracat(content_type, ";charset=", env);
      tmp2 = axis2_stracat(tmp1, info_impl->encoding, env);
        info_impl->request->content_type = axis2_strdup(tmp2, env);
      AXIS2_FREE(env->allocator, tmp1);
      AXIS2_FREE(env->allocator, tmp2);      
   }
   else{
      info_impl->request->content_type = axis2_strdup(content_type, env); 
   }
   return AXIS2_SUCCESS;
}


axis2_status_t WSF_CALL 
wsf_http_out_transport_info_set_char_encoding 
            (axis2_http_out_transport_info_t *info, const axis2_env_t *env,
            const axis2_char_t *encoding)
{
    wsf_out_transport_info_impl_t *info_impl = NULL;
	if(!encoding)
		return AXIS2_FAILURE;

    info_impl = AXIS2_INTF_TO_IMPL(info);
   
    if(NULL != info_impl->encoding){
      AXIS2_FREE(env->allocator, info_impl->encoding);
    }
    info_impl->encoding = axis2_strdup(encoding, env);
    return AXIS2_SUCCESS;
}
