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
 
#ifndef SANDESHA2_RM_ELEMENTS_H
#define SANDESHA2_RM_ELEMENTS_H

/**
  * @file sandesha2_rm_elements.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <sandesha2_create_seq.h>
#include <sandesha2_create_seq_res.h>
#include <sandesha2_terminate_seq.h>
#include <sandesha2_terminate_seq_res.h>
#include <sandesha2_close_seq.h>
#include <sandesha2_close_seq_res.h>
#include <sandesha2_seq_ack.h>
#include <sandesha2_ack_requested.h>
#include <sandesha2_seq.h>
#include <sandesha2_identifier.h>
#include <sandesha2_msg_number.h>
#include <sandesha2_make_connection.h>
#include <sandesha2_msg_pending.h>



#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup sandesha2_util
 * @{
 */

typedef struct sandesha2_rm_elements_t sandesha2_rm_elements_t;

AXIS2_EXTERN sandesha2_rm_elements_t* AXIS2_CALL
sandesha2_rm_elements_create(
    const axutil_env_t *env,
    axis2_char_t *addr_ns_uri);
 
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_from_soap_envelope(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope,
    axis2_char_t *action);
            
axiom_soap_envelope_t* AXIS2_CALL 
sandesha2_rm_elements_to_soap_envelope(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope);
            
sandesha2_create_seq_t* AXIS2_CALL 
sandesha2_rm_elements_get_create_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_create_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_create_seq_t *create_seq);
    
sandesha2_create_seq_res_t* AXIS2_CALL
sandesha2_rm_elements_get_create_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_create_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
            sandesha2_create_seq_res_t *create_seq_res);
            
sandesha2_seq_t* AXIS2_CALL 
sandesha2_rm_elements_get_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_seq_t *seq);
            
sandesha2_seq_ack_t* AXIS2_CALL 
sandesha2_rm_elements_get_seq_ack(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_seq_ack(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_seq_ack_t *seq_ack);
            
sandesha2_terminate_seq_t* AXIS2_CALL 
sandesha2_rm_elements_get_terminate_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_terminate_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_terminate_seq_t *terminate_seq);
            
sandesha2_terminate_seq_res_t* AXIS2_CALL 
sandesha2_rm_elements_get_terminate_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_terminate_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_terminate_seq_res_t *terminate_seq_res);
            
sandesha2_ack_requested_t* AXIS2_CALL 
sandesha2_rm_elements_get_ack_requested(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_ack_requested(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_ack_requested_t *ack_reqested);
    
sandesha2_close_seq_t* AXIS2_CALL 
sandesha2_rm_elements_get_close_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_close_seq(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_close_seq_t *close_seq);
    
sandesha2_close_seq_res_t* AXIS2_CALL 
sandesha2_rm_elements_get_close_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_set_close_seq_res(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    sandesha2_close_seq_res_t *close_seq_res);
    
axis2_char_t* AXIS2_CALL 
sandesha2_rm_elements_get_addr_ns_val(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);

axis2_char_t* AXIS2_CALL 
sandesha2_rm_elements_get_rm_ns_val(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope,
    axis2_char_t *action);

axis2_char_t* AXIS2_CALL 
sandesha2_rm_elements_get_addr_ns_val_from_env(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_envelope,
    axis2_char_t *action);
            
axis2_status_t AXIS2_CALL 
sandesha2_rm_elements_free(
    sandesha2_rm_elements_t *mgr, 
    const axutil_env_t *env);								

sandesha2_make_connection_t* AXIS2_CALL 
sandesha2_rm_elements_get_make_connection(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);

sandesha2_msg_pending_t* AXIS2_CALL 
sandesha2_rm_elements_get_msg_pending(
    sandesha2_rm_elements_t *rm_elements,
    const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SANDESHA2_RM_ELEMENTS_H*/
