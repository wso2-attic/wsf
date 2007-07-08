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
 
#ifndef SANDESHA2_MSG_CTX_H
#define SANDESHA2_MSG_CTX_H

/**
  * @file sandesha2_msg_ctx.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axiom_soap_envelope.h>
#include <axis2_msg_ctx.h>
#include <axis2_endpoint_ref.h>
#include <axis2_relates_to.h>
#include <sandesha2_iom_rm_part.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup sandesha2_msg_ctx
 * @{
 */
 
typedef struct sandesha2_msg_ctx_t sandesha2_msg_ctx_t;

AXIS2_EXTERN sandesha2_msg_ctx_t* AXIS2_CALL
sandesha2_msg_ctx_create(
    const axutil_env_t *env, 
    axis2_msg_ctx_t *msg_ctx);
 
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_msg_ctx(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env, 
    axis2_msg_ctx_t *msg_ctx);
            
axis2_msg_ctx_t *AXIS2_CALL
sandesha2_msg_ctx_get_msg_ctx(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env);
    
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_add_soap_envelope(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);
        
int AXIS2_CALL
sandesha2_msg_ctx_get_msg_type (
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);
        
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_msg_type (
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    int msg_type);
            
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_msg_part (
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    int part_id,
    sandesha2_iom_rm_part_t *part);
        
sandesha2_iom_rm_part_t *AXIS2_CALL
sandesha2_msg_ctx_get_msg_part(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    int part_id);
    
axis2_endpoint_ref_t *AXIS2_CALL
sandesha2_msg_ctx_get_from(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_from(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_endpoint_ref_t *from);
    
axis2_endpoint_ref_t *AXIS2_CALL
sandesha2_msg_ctx_get_to (
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_to(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env, 
    axis2_endpoint_ref_t *to);
    
axis2_endpoint_ref_t *AXIS2_CALL
sandesha2_msg_ctx_get_reply_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_reply_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_endpoint_ref_t *reply_to);
    
axis2_endpoint_ref_t *AXIS2_CALL
sandesha2_msg_ctx_get_fault_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_fault_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_endpoint_ref_t *fault_to);
    
axis2_relates_to_t *AXIS2_CALL
sandesha2_msg_ctx_get_relates_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_relates_to(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_relates_to_t *relates_to);
    
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_msg_id(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_msg_id(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env, 
    axis2_char_t *msg_id);
    
axiom_soap_envelope_t *AXIS2_CALL
sandesha2_msg_ctx_get_soap_envelope(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_soap_envelope(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *soap_envelope);
            
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_wsa_action(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_wsa_action(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_char_t *action);
            
void *AXIS2_CALL
sandesha2_msg_ctx_get_property(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_char_t *key);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_property(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_char_t *key, 
    void *val);
    
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_soap_action(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axutil_string_t *soap_action);
    
axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_paused(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_bool_t paused);
    
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_rm_ns_val(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_rm_ns_val(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_char_t *ns_val);
    
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_addr_ns_val(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_addr_ns_val(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    axis2_char_t *ns_val);
            
int AXIS2_CALL
sandesha2_msg_ctx_get_flow(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_flow(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env, 
    int flow);
                        
axis2_char_t *AXIS2_CALL
sandesha2_msg_ctx_get_rm_spec_ver(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_msg_ctx_free(
    sandesha2_msg_ctx_t *rm_msg_ctx, 
    const axutil_env_t *env);								
    
AXIS2_EXTERN axutil_stream_t *AXIS2_CALL
sandesha2_msg_ctx_get_transport_out_stream(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_transport_out_stream(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env,
    axutil_stream_t *stream);

AXIS2_EXTERN struct axis2_http_out_transport_info *AXIS2_CALL
sandesha2_msg_ctx_get_http_out_transport_info(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_set_http_out_transport_info(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env,
    struct axis2_http_out_transport_info *http_out_transport_info);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_msg_ctx_reset_http_out_transport_info(
    sandesha2_msg_ctx_t *rm_msg_ctx,
    const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SANDESHA2_MSG_CTX_H*/
