/*
 * copyright 1999-2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#ifndef SANDESHA2_MSG_STORE_BEAN_H
#define SANDESHA2_MSG_STORE_BEAN_H

#include <axutil_utils_defines.h>
#include <axis2_const.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_msg_store_bean_t sandesha2_msg_store_bean_t;


/* constructors 
 */
AXIS2_EXTERN sandesha2_msg_store_bean_t* AXIS2_CALL
sandesha2_msg_store_bean_create(
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_msg_store_bean_free (
    sandesha2_msg_store_bean_t *msg_store,
    const axutil_env_t *env);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_msg_id(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_msg_id(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * msg_id);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_stored_key(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_stored_key(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * key);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_soap_envelope_str(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_soap_envelope_str(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * soap_env_str); 

int AXIS2_CALL 
sandesha2_msg_store_bean_get_soap_version( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_soap_version(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    int soap_version);

AXIS2_TRANSPORT_ENUMS AXIS2_CALL 
sandesha2_msg_store_bean_get_transport_out(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_transport_out(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    AXIS2_TRANSPORT_ENUMS transport_sender);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_op( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_op(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * op);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_svc( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_svc(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * svc);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_svc_grp( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_svc_grp(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * svc_grp);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_op_mep( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_op_mep(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * opAdd);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_to_url( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_to_url(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * to_url);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_reply_to( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_reply_to(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * reply_to);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_transport_to( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_transport_to(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * transport_to); 

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_execution_chain_str( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_execution_chain_str(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * execution_chain_str);

int AXIS2_CALL 
sandesha2_msg_store_bean_get_flow( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_flow(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    int flow);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_msg_recv_str( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_msg_recv_str(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * msg_recv_str); 

axis2_bool_t AXIS2_CALL 
sandesha2_msg_store_bean_is_svr_side( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_svr_side(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_bool_t svr_side);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_in_msg_store_key(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_in_msg_store_key(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * request_msg_key);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_persistent_property_str( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_persistent_property_str(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * persistent_property_str);

axis2_char_t *AXIS2_CALL 
sandesha2_msg_store_bean_get_action( 
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_msg_store_bean_set_action(
    sandesha2_msg_store_bean_t *msg_store_bean,
    const axutil_env_t *env,
    axis2_char_t * action);

#ifdef __cplusplus
}

#endif
	
#endif /* End of SANDESHA2_MSG_STORE_BEAN_H */
