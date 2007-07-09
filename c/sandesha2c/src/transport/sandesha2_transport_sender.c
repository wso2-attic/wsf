/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <sandesha2_transport_sender.h>
#include <sandesha2_constants.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_utils.h>
#include <axis2_conf.h>
#include <axutil_string.h>


/** 
 * @brief Transport Sender struct impl
 *	Sandesha2 Transport Sender
 */
typedef struct sandesha2_transport_sender_impl sandesha2_transport_sender_impl_t;  
  
struct sandesha2_transport_sender_impl
{
    axis2_transport_sender_t transport_sender;
};

#define SANDESHA2_INTF_TO_IMPL(transport_sender) \
                        ((sandesha2_transport_sender_impl_t *)(transport_sender))

/***************************** Function headers *******************************/
axis2_status_t AXIS2_CALL
sandesha2_transport_sender_init(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env, 
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_out_desc_t *transport_out);
            
axis2_status_t AXIS2_CALL
sandesha2_transport_sender_clean_up(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);
            
axis2_status_t AXIS2_CALL
sandesha2_transport_sender_invoke (
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);
            
void AXIS2_CALL 
sandesha2_transport_sender_free(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env);								

/***************************** End of function headers ************************/

static const axis2_transport_sender_ops_t sandesha2_transport_sender_ops_var = {
    sandesha2_transport_sender_init,
    sandesha2_transport_sender_invoke,
    sandesha2_transport_sender_clean_up,
    sandesha2_transport_sender_free
};

AXIS2_EXTERN axis2_transport_sender_t* AXIS2_CALL
sandesha2_transport_sender_create(
    const axutil_env_t *env)
{
    sandesha2_transport_sender_impl_t *transport_sender_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    transport_sender_impl =  (sandesha2_transport_sender_impl_t *)
                        AXIS2_MALLOC (env->allocator, 
                        sizeof(sandesha2_transport_sender_impl_t));
	
    if(NULL == transport_sender_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
        
    transport_sender_impl->transport_sender.ops = AXIS2_MALLOC(env->allocator,
                        sizeof(axis2_transport_sender_ops_t));
    if(NULL == transport_sender_impl->transport_sender.ops)
	{
		sandesha2_transport_sender_free((axis2_transport_sender_t*)
                        transport_sender_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    transport_sender_impl->transport_sender.ops = &sandesha2_transport_sender_ops_var; 
	return &(transport_sender_impl->transport_sender);
}


void AXIS2_CALL 
sandesha2_transport_sender_free(
    axis2_transport_sender_t *transport_sender, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
       
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(transport_sender));
}

axis2_status_t AXIS2_CALL
sandesha2_transport_sender_init(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env, 
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_out_desc_t *transport_out)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, transport_out, AXIS2_FAILURE);
    
    /* we have nothing to do here */
    return AXIS2_SUCCESS;
}
            
axis2_status_t AXIS2_CALL
sandesha2_transport_sender_clean_up(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
        
    /* we have nothing to do here */
    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
sandesha2_transport_sender_invoke (
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axutil_property_t *property = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_char_t *key = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    sandesha2_storage_mgr_t *storage_man = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
        
    property = axis2_msg_ctx_get_property(msg_ctx, env, 
                        SANDESHA2_ORIGINAL_TRANSPORT_OUT_DESC);
                        
    if(NULL == property || NULL == axutil_property_get_value(property, env))
        return AXIS2_FAILURE;
    out_desc = axutil_property_get_value(property, env);
    axis2_msg_ctx_set_transport_out_desc(msg_ctx, env, out_desc);
    
    property = axis2_msg_ctx_get_property(msg_ctx, env, 
                        SANDESHA2_MESSAGE_STORE_KEY);
                        
    if(NULL == property || NULL == axutil_property_get_value(property, env))
        return AXIS2_FAILURE;
    
    key = axutil_property_get_value(property, env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_man = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    
    property = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
    axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_QUALIFIED_FOR_SENDING,
        property);
    sandesha2_storage_mgr_update_msg_ctx(storage_man, env, key, msg_ctx);
    return AXIS2_SUCCESS;
}

