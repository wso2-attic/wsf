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

#ifndef SANDESHA2_SENDER_BEAN_H
#define SANDESHA2_SENDER_BEAN_H

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <sandesha2_rm_bean.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_sender_bean sandesha2_sender_bean_t;
struct sandesha2_transaction;

AXIS2_DECLARE_DATA struct sandesha2_sender_bean
{
    sandesha2_rm_bean_t rm_bean;
};

/* constructors 
 */
AXIS2_EXTERN sandesha2_sender_bean_t* AXIS2_CALL
sandesha2_sender_bean_create(
    const axutil_env_t *env);

AXIS2_EXTERN sandesha2_sender_bean_t* AXIS2_CALL
sandesha2_sender_bean_create_with_data(
    const axutil_env_t *env,
    axis2_char_t *msg_id,
    axis2_char_t *key,
    axis2_bool_t send,
    long	time_to_send,
    axis2_char_t *int_seq_id,
    long msg_no);

void AXIS2_CALL
sandesha2_sender_bean_free (
    sandesha2_rm_bean_t *sender,
    const axutil_env_t *env);

struct sandesha2_rm_bean * AXIS2_CALL
sandesha2_sender_bean_get_base( 
    sandesha2_rm_bean_t* sender,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_base (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env, 
    struct sandesha2_rm_bean* rm_bean);

axis2_char_t* AXIS2_CALL
sandesha2_sender_bean_get_msg_ctx_ref_key (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_msg_ctx_ref_key (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    axis2_char_t *ref_key);

axis2_char_t* AXIS2_CALL
sandesha2_sender_bean_get_msg_id (
    sandesha2_rm_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_sender_bean_set_msg_id (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
axis2_char_t *msg_id);

axis2_bool_t AXIS2_CALL
sandesha2_sender_bean_is_send (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_sender_bean_set_send (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
axis2_bool_t send);

axis2_char_t* AXIS2_CALL
sandesha2_sender_bean_get_internal_seq_id (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_sender_bean_set_internal_seq_id (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    axis2_char_t *int_seq_id);

int AXIS2_CALL 
sandesha2_sender_bean_get_sent_count (
    sandesha2_sender_bean_t *sender,
	const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_sender_bean_set_sent_count (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    int sent_count);

long AXIS2_CALL
sandesha2_sender_bean_get_msg_no (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_msg_no (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    long msg_no);

axis2_bool_t AXIS2_CALL
sandesha2_sender_bean_is_resend (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_resend (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    axis2_bool_t resend);

long AXIS2_CALL
sandesha2_sender_bean_get_time_to_send (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_time_to_send (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    long time_to_send);

int AXIS2_CALL
sandesha2_sender_bean_get_msg_type (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_msg_type (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    int msg_type);

axis2_char_t* AXIS2_CALL
sandesha2_sender_bean_get_seq_id(
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_seq_id (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    axis2_char_t *seq_id);

axis2_char_t* AXIS2_CALL
sandesha2_sender_bean_get_wsrm_anon_uri(
    sandesha2_sender_bean_t *sender,
	const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_wsrm_anon_uri (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    axis2_char_t *anon_uri);

void AXIS2_CALL
sandesha2_sender_bean_set_to_address (
    sandesha2_sender_bean_t *sender,
    const axutil_env_t *env,
    axis2_char_t *to_address);

axis2_char_t* AXIS2_CALL
sandesha2_sender_bean_get_to_address(
    sandesha2_sender_bean_t *sender,
	const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_id( 
    sandesha2_rm_bean_t *sender_bean,
	const axutil_env_t *env, 
    long id);

long AXIS2_CALL
sandesha2_sender_bean_get_id( 
    sandesha2_rm_bean_t *sender_bean,
	const axutil_env_t *env);

void AXIS2_CALL
sandesha2_sender_bean_set_transaction( 
    sandesha2_rm_bean_t *sender_bean,
	const axutil_env_t *env, 
    struct sandesha2_transaction *transaction);

struct sandesha2_transaction *AXIS2_CALL
sandesha2_sender_bean_get_transaction( 
    sandesha2_rm_bean_t *sender_bean,
	const axutil_env_t *env);

#ifdef __cplusplus
}

#endif
	
#endif /* End of SANDESHA2_SENDER_BEAN_H */
