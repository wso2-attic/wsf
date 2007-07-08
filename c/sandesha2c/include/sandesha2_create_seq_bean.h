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

#ifndef SANDESHA2_CREATE_SEQ_BEAN_H
#define SANDESHA2_CREATE_SEQ_BEAN_H

#include <axutil_qname.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <axutil_utils_defines.h>
#include <sandesha2_rm_bean.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_create_seq_bean sandesha2_create_seq_bean_t;
struct sandesha2_transaction;

AXIS2_DECLARE_DATA struct sandesha2_create_seq_bean
{
    sandesha2_rm_bean_t rm_bean;
};

/* constructors 
 */
AXIS2_EXTERN sandesha2_create_seq_bean_t* AXIS2_CALL
sandesha2_create_seq_bean_create(
    const axutil_env_t *env);

AXIS2_EXTERN sandesha2_create_seq_bean_t* AXIS2_CALL
sandesha2_create_seq_bean_create_with_data(
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id,
    axis2_char_t *create_seq_msg_id, 
    axis2_char_t *seq_id);

void AXIS2_CALL 
sandesha2_create_seq_bean_free  (
    sandesha2_rm_bean_t *create_seq_bean,
    const axutil_env_t *env);

struct sandesha2_rm_bean * AXIS2_CALL
sandesha2_create_seq_bean_get_base( 
    sandesha2_rm_bean_t* create_seq,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_create_seq_bean_set_base (
    sandesha2_create_seq_bean_t *create_seq_bean,
    const axutil_env_t *env, 
    struct sandesha2_rm_bean* rm_bean);

axis2_char_t* AXIS2_CALL 
sandesha2_create_seq_bean_get_create_seq_msg_id  (
    sandesha2_rm_bean_t *create_seq_bean,
    const axutil_env_t *env);

void AXIS2_CALL 
sandesha2_create_seq_bean_set_create_seq_msg_id (
    sandesha2_create_seq_bean_t *create_seq_bean,
    const axutil_env_t *env, 
    axis2_char_t* seq_msg_id) ;

axis2_char_t* AXIS2_CALL 
sandesha2_create_seq_bean_get_seq_id (
    sandesha2_create_seq_bean_t *create_seq_bean,
    const axutil_env_t *env);
	
void AXIS2_CALL
sandesha2_create_seq_bean_set_seq_id (
    sandesha2_create_seq_bean_t *create_seq_bean,
    const axutil_env_t *env, 
    axis2_char_t* seq_id) ;

axis2_char_t* AXIS2_CALL
sandesha2_create_seq_bean_get_internal_seq_id (
    sandesha2_create_seq_bean_t *create_seq_bean,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_create_seq_bean_set_internal_seq_id (
    sandesha2_create_seq_bean_t *create_seq_bean,
    const axutil_env_t *env, 
    axis2_char_t* int_seq_id);

axis2_char_t * AXIS2_CALL
sandesha2_create_seq_bean_get_create_seq_msg_store_key(
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env);

void AXIS2_CALL
sandesha2_create_seq_bean_set_create_seq_msg_store_key(
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env, 
    axis2_char_t *create_seq_msg_store_key);

axis2_char_t * AXIS2_CALL
sandesha2_create_seq_bean_get_ref_msg_store_key( 
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env);

void AXIS2_CALL
sandesha2_create_seq_bean_set_ref_msg_store_key( 
    sandesha2_create_seq_bean_t *create_seq_bean,
	const axutil_env_t *env, 
    axis2_char_t *ref_msg_store_key);

void AXIS2_CALL
sandesha2_create_seq_bean_set_id( 
    sandesha2_rm_bean_t *create_seq_bean,
	const axutil_env_t *env, 
    long id);

long AXIS2_CALL
sandesha2_create_seq_bean_get_id( 
    sandesha2_rm_bean_t *create_seq_bean,
	const axutil_env_t *env);

void AXIS2_CALL
sandesha2_create_seq_bean_set_transaction( 
    sandesha2_rm_bean_t *create_seq_bean,
	const axutil_env_t *env, 
    struct sandesha2_transaction *transaction);

struct sandesha2_transaction *AXIS2_CALL
sandesha2_create_seq_bean_get_transaction( 
    sandesha2_rm_bean_t *create_seq_bean,
	const axutil_env_t *env);

#ifdef __cplusplus
}

#endif
	
#endif /* End of SANDESHA2_CREATE_SEQ_BEAN_H */
