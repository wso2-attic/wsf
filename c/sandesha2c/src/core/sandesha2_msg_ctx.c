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
#include <sandesha2_msg_ctx.h>
#include <sandesha2_constants.h>
#include <axutil_hash.h>
#include <axiom_soap_const.h>
#include <sandesha2_iom_rm_part.h>
#include <stdio.h>


/** 
 * @brief Msg Ctx struct impl
 *	Sandesha2 Message Context
 */
struct sandesha2_msg_ctx_t
{
    axutil_hash_t *msg_parts;
    int msg_type;
    axis2_char_t *rm_ns_val;
    axis2_char_t *addr_ns_val;
    axis2_char_t *spec_ver;
	axis2_msg_ctx_t *msg_ctx;
};

AXIS2_EXTERN sandesha2_msg_ctx_t* AXIS2_CALL
sandesha2_msg_ctx_create(
    const axutil_env_t *env, 
    axis2_msg_ctx_t *msg_ctx)
{
    sandesha2_msg_ctx_t *rm_msg_ctx = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    rm_msg_ctx =  (sandesha2_msg_ctx_t *)AXIS2_MALLOC 
                        (env->allocator, sizeof(sandesha2_msg_ctx_t));
	
    if(!rm_msg_ctx)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    rm_msg_ctx->rm_ns_val = NULL;
    rm_msg_ctx->addr_ns_val = NULL;
    rm_msg_ctx->msg_parts = NULL;
    rm_msg_ctx->msg_ctx = NULL;
    rm_msg_ctx->spec_ver = NULL;
    
    rm_msg_ctx->msg_parts = axutil_hash_make(env);
    rm_msg_ctx->msg_type = SANDESHA2_MSG_TYPE_UNKNOWN;
    rm_msg_ctx->msg_ctx = msg_ctx;

	return rm_msg_ctx;
}


axis2_status_t AXIS2_CALL 
sandesha2_msg_ctx_free(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env)
{
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(rm_msg_ctx->addr_ns_val)
    {
        AXIS2_FREE(env->allocator, rm_msg_ctx->addr_ns_val);
        rm_msg_ctx->addr_ns_val = NULL;
    }
    if(rm_msg_ctx->rm_ns_val)
    {
        AXIS2_FREE(env->allocator, rm_msg_ctx->rm_ns_val);
        rm_msg_ctx->rm_ns_val = NULL;
    }
    if(rm_msg_ctx->spec_ver)
    {
        AXIS2_FREE(env->allocator, rm_msg_ctx->spec_ver);
        rm_msg_ctx->spec_ver = NULL;
    }
    if(rm_msg_ctx->msg_parts)
    {
        axutil_hash_free(rm_msg_ctx->msg_parts, env);
        rm_msg_ctx->msg_parts = NULL;
    }
	AXIS2_FREE(env->allocator, rm_msg_ctx);
	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_msg_ctx(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env, 
    axis2_msg_ctx_t *msg_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    
    rm_msg_ctx->msg_ctx = msg_ctx;
    return AXIS2_SUCCESS;
}
            
axis2_msg_ctx_t *AXIS2_CALL
sandesha2_msg_ctx_get_msg_ctx(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return rm_msg_ctx->msg_ctx;
}
    
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_add_soap_envelope(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    int soap_ver = AXIOM_SOAP11;
    axutil_hash_index_t *hi = NULL;
    axiom_soap_envelope_t *soap_envelope = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(AXIS2_FALSE == axis2_msg_ctx_get_is_soap_11(rm_msg_ctx->msg_ctx, env))
        soap_ver = AXIOM_SOAP12;
    soap_envelope = axis2_msg_ctx_get_soap_envelope(rm_msg_ctx->msg_ctx, env);
    if(NULL == soap_envelope)
    {
        soap_envelope = axiom_soap_envelope_create_default_soap_envelope(env,
                        soap_ver);
        axis2_msg_ctx_set_soap_envelope(rm_msg_ctx->msg_ctx, env, 
                        soap_envelope);
    }
    
    for(hi = axutil_hash_first(rm_msg_ctx->msg_parts, env); NULL != hi;
                        hi = axutil_hash_next(env, hi))
    {
        sandesha2_iom_rm_part_t *part = NULL;
        void *value = NULL;

        axutil_hash_this(hi, NULL, NULL, &value);
        part = (sandesha2_iom_rm_part_t*)value;
        sandesha2_iom_rm_part_to_soap_envelope(part, env, soap_envelope);
    }
    return AXIS2_SUCCESS;
}
            
int AXIS2_CALL
sandesha2_msg_ctx_get_msg_type (
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, -1);
    return rm_msg_ctx->msg_type;
}
            
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_msg_type (
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, int msg_type)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    rm_msg_ctx->msg_type = msg_type;
    return AXIS2_SUCCESS;
}
            
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_msg_part (
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, int part_id,
    sandesha2_iom_rm_part_t *part)
{
    axis2_char_t *part_id_str = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, part, AXIS2_FAILURE);
    
    part_id_str = AXIS2_MALLOC(env->allocator, 32 * sizeof(axis2_char_t));
    sprintf(part_id_str, "%d", part_id);
    axutil_hash_set(rm_msg_ctx->msg_parts, part_id_str, AXIS2_HASH_KEY_STRING,
                        (const void*)part);
    return AXIS2_SUCCESS;
}
            
sandesha2_iom_rm_part_t *AXIS2_CALL
sandesha2_msg_ctx_get_msg_part(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    int part_id)
{
    axis2_char_t part_id_str[32];
    AXIS2_ENV_CHECK(env, NULL);
    
    sprintf(part_id_str, "%d", part_id);
    return axutil_hash_get(rm_msg_ctx->msg_parts, part_id_str, 
                        AXIS2_HASH_KEY_STRING);
}
    
axis2_endpoint_ref_t *AXIS2_CALL
sandesha2_msg_ctx_get_from(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return axis2_msg_ctx_get_from(rm_msg_ctx->msg_ctx, env);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_from(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_endpoint_ref_t *from)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, from, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_to(rm_msg_ctx->msg_ctx, env, from);;
}
    
axis2_endpoint_ref_t *AXIS2_CALL
sandesha2_msg_ctx_get_to (
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return axis2_msg_ctx_get_to(rm_msg_ctx->msg_ctx, env);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_to(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env, 
    axis2_endpoint_ref_t *to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, to, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_to(rm_msg_ctx->msg_ctx, env, to);
}
    
axis2_endpoint_ref_t *AXIS2_CALL
sandesha2_msg_ctx_get_reply_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return axis2_msg_ctx_get_reply_to(rm_msg_ctx->msg_ctx, env);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_reply_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, axis2_endpoint_ref_t *reply_to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, reply_to, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_reply_to(rm_msg_ctx->msg_ctx, env, reply_to);
}
    
axis2_endpoint_ref_t *AXIS2_CALL
sandesha2_msg_ctx_get_fault_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return axis2_msg_ctx_get_fault_to(rm_msg_ctx->msg_ctx, env);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_fault_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, axis2_endpoint_ref_t *fault_to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, fault_to, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_fault_to(rm_msg_ctx->msg_ctx, env, fault_to);
}
    
axis2_relates_to_t *AXIS2_CALL
sandesha2_msg_ctx_get_relates_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return axis2_msg_ctx_get_relates_to(rm_msg_ctx->msg_ctx, env);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_relates_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, axis2_relates_to_t *relates_to)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, relates_to, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_relates_to(rm_msg_ctx->msg_ctx, env, relates_to);
}
    
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_msg_id(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return (axis2_char_t*)axis2_msg_ctx_get_wsa_message_id(
                        rm_msg_ctx->msg_ctx, env);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_msg_id(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env, 
    axis2_char_t *msg_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_id, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_message_id(rm_msg_ctx->msg_ctx, env, msg_id);
}
    
axiom_soap_envelope_t *AXIS2_CALL
sandesha2_msg_ctx_get_soap_envelope(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return axis2_msg_ctx_get_soap_envelope(rm_msg_ctx->msg_ctx, env);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_soap_envelope(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *soap_envelope)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_envelope, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_soap_envelope(rm_msg_ctx->msg_ctx, env, 
                        soap_envelope);
}
            
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_wsa_action(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
        
    return (axis2_char_t*)axis2_msg_ctx_get_wsa_action(rm_msg_ctx->msg_ctx, env);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_wsa_action(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, axis2_char_t *action)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, action, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_wsa_action(rm_msg_ctx->msg_ctx, env, action);
}
            
void *AXIS2_CALL
sandesha2_msg_ctx_get_property(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, axis2_char_t *key)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, key, NULL);
    
    return axis2_msg_ctx_get_property(rm_msg_ctx->msg_ctx, env, key);
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_property(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_char_t *key, 
    void *val)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, key, AXIS2_FAILURE);
    
    return axis2_msg_ctx_set_property(rm_msg_ctx->msg_ctx, env, key, val);
}
    
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_soap_action(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axutil_string_t *soap_action)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_action, AXIS2_FAILURE);
    
    if(NULL == rm_msg_ctx->msg_ctx)
        return AXIS2_FAILURE;
    
    return axis2_msg_ctx_set_soap_action(rm_msg_ctx->msg_ctx, env, 
        soap_action);
}
    
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_paused(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_bool_t paused)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(NULL == rm_msg_ctx->msg_ctx)
        return AXIS2_FAILURE;
    return axis2_msg_ctx_set_paused(rm_msg_ctx->msg_ctx, env, paused);    
}
    
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_rm_ns_val(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return rm_msg_ctx->rm_ns_val;
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_rm_ns_val(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_char_t *ns_val)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, ns_val, AXIS2_FAILURE);
    
    if(NULL != rm_msg_ctx->rm_ns_val)
    {
        AXIS2_FREE(env->allocator, rm_msg_ctx->rm_ns_val);
        rm_msg_ctx->rm_ns_val = NULL;
    }
    rm_msg_ctx->rm_ns_val = axutil_strdup(env, ns_val);
    if(0 == axutil_strcmp(ns_val, SANDESHA2_SPEC_2005_02_NS_URI))
        rm_msg_ctx->spec_ver = axutil_strdup(env, SANDESHA2_SPEC_VERSION_1_0);
    if(0 == axutil_strcmp(ns_val, SANDESHA2_SPEC_2006_08_NS_URI))
        rm_msg_ctx->spec_ver = axutil_strdup(env, SANDESHA2_SPEC_VERSION_1_1);
        
    return AXIS2_SUCCESS;
}
    
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_addr_ns_val(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return rm_msg_ctx->addr_ns_val;
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_addr_ns_val(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, axis2_char_t *ns_val)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, ns_val, AXIS2_FAILURE);
    
    if(NULL != rm_msg_ctx->addr_ns_val)
    {
        AXIS2_FREE(env->allocator, rm_msg_ctx->addr_ns_val);
        rm_msg_ctx->addr_ns_val = NULL;
    }
    rm_msg_ctx->addr_ns_val = axutil_strdup(env, ns_val);
    return AXIS2_SUCCESS;
}
            
int AXIS2_CALL
sandesha2_msg_ctx_get_flow(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, -1);
    
    if(NULL == rm_msg_ctx->msg_ctx)
        return -1;
    return axis2_msg_ctx_get_flow(rm_msg_ctx->msg_ctx, env);     
}

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_flow(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, int flow)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(NULL == rm_msg_ctx->msg_ctx)
        return AXIS2_FAILURE;
        
    return axis2_msg_ctx_set_flow(rm_msg_ctx->msg_ctx, env, flow); 
}

axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_rm_spec_ver(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return rm_msg_ctx->spec_ver;
}

AXIS2_EXTERN axutil_stream_t *AXIS2_CALL
sandesha2_msg_ctx_get_transport_out_stream(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    if(!rm_msg_ctx->msg_ctx)
        return NULL;
    return axis2_msg_ctx_get_transport_out_stream(rm_msg_ctx->msg_ctx, env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_transport_out_stream(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env,
    axutil_stream_t *stream)
{
    if(!rm_msg_ctx->msg_ctx)
        return AXIS2_FAILURE;
    return axis2_msg_ctx_set_transport_out_stream(rm_msg_ctx->msg_ctx, env, 
        stream);
}

AXIS2_EXTERN struct axis2_http_out_transport_info *AXIS2_CALL
sandesha2_msg_ctx_get_http_out_transport_info(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    if(!rm_msg_ctx->msg_ctx)
        return NULL;
    return axis2_msg_ctx_get_http_out_transport_info(rm_msg_ctx->msg_ctx, env);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_http_out_transport_info(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env,
    struct axis2_http_out_transport_info *http_out_transport_info)
{
    if(!rm_msg_ctx->msg_ctx)
        return AXIS2_FAILURE;
    return axis2_msg_ctx_set_http_out_transport_info(rm_msg_ctx->msg_ctx, 
        env, http_out_transport_info);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_reset_http_out_transport_info(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env)
{
    if(!rm_msg_ctx->msg_ctx)
        return AXIS2_FAILURE;
    return axis2_msg_ctx_reset_http_out_transport_info(rm_msg_ctx->msg_ctx, env);
}

