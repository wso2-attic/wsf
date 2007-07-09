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
 
#ifndef SANDESHA2_SPEC_SPECIFIC_CONSTS_H
#define SANDESHA2_SPEC_SPECIFIC_CONSTS_H

/**
  * @file sandehsa2_spec_specific_consts.h
  * @brief 
  */

#include <axutil_allocator.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_utils.h>
#include <axutil_hash.h>
#include <axutil_uri.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandehsa2_spec_specific_consts
 * @ingroup sandesha2_util
 * @{
 */
AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_spec_specific_consts_get_spec_ver_str(
    const axutil_env_t *env,
    axis2_char_t *ns_val);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_spec_specific_consts_get_rm_ns_val(
    const axutil_env_t *env,
    axis2_char_t *spec_ver);
                    
AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_ack_final_allowed(
    const axutil_env_t *env, 
    axis2_char_t *rm_spec_ver);
                        
AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_ack_none_allowed(
    const axutil_env_t *env, 
    axis2_char_t *rm_spec_ver);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_default_spec_version(
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_terminate_seq_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_create_seq_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_create_seq_soap_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_ack_req_soap_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_create_seq_res_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_create_seq_res_soap_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_close_seq_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_close_seq_res_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);
	
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_ack_req_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);
	
AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_seq_closing_allowed(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_spec_specific_consts_get_default_spec_version(
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
sandesha2_spec_specific_consts_get_anon_uri(
    const axutil_env_t *env,
    axis2_char_t *addr_ns_val);

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_term_seq_res_reqd(
    const axutil_env_t *env,
    axis2_char_t *spec_version);
        
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_terminate_seq_soap_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL        
sandesha2_spec_specific_consts_get_teminate_seq_res_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_seq_ack_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);
	
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_seq_ack_soap_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);
        
axis2_bool_t AXIS2_CALL
sandesha2_spec_specific_consts_is_last_msg_indicator_reqd(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

axis2_char_t *AXIS2_CALL
sandesha2_spec_specific_consts_get_make_connection_action(
    const axutil_env_t *env,
    axis2_char_t *spec_version);

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_SPEC_SPECIFIC_CONSTS_H */

