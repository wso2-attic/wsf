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

#ifndef SANDESHA2_MSG_CREATOR_H
#define SANDESHA2_MSG_CREATOR_H

/**
 * @file sandesha2_msg_creator.h
 * @brief Sandesha In Memory Message creator Interface
 */

#include <axutil_allocator.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_utils.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_msg_ctx.h>
#include <axis2_msg_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_msg_creator sandesha2_msg_creator_t;
typedef struct sandesha2_msg_creator_ops sandesha2_msg_creator_ops_t;

/** @defgroup sandesha2_msg_creator In Memory Message creator
  * @ingroup sandesha2
  * @{
  */

/**
 * Create a new create_seq_msg
 * @param application_rm_msg
 * @param internal_seq_id
 * @param acks_to
 * @return
 */
sandesha2_msg_ctx_t *AXIS2_CALL
sandesha2_msg_creator_create_create_seq_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *application_rm_msg, 
    axis2_char_t *internal_seq_id,
    axis2_char_t *acks_to,
    sandesha2_storage_mgr_t *storage_mgr);

/**
 * Create a new create_seq_response message.
 * @param create_seq_msg
 * @param out_msg
 * @param new_seq_id
 * @return
 */
sandesha2_msg_ctx_t *
sandesha2_msg_creator_create_create_seq_res_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *create_seq_msg,
    axis2_msg_ctx_t *out_msg,
    axis2_char_t *new_seq_id,
    sandesha2_storage_mgr_t *storage_mgr);
 
/**
 * Create a new close_seq_response message.
 * @param close_seq_msg
 * @param out_msg
 * @param storage_mgr
 * @return
 */
sandesha2_msg_ctx_t *
sandesha2_msg_creator_create_close_seq_res_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *close_seq_msg,
    axis2_msg_ctx_t *out_msg,
    sandesha2_storage_mgr_t *storage_mgr);


sandesha2_msg_ctx_t *AXIS2_CALL
sandesha2_msg_creator_create_terminate_seq_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *ref_rm_msg,
    axis2_char_t *seq_id,
    axis2_char_t *internal_seq_id,
    sandesha2_storage_mgr_t *storage_mgr);


sandesha2_msg_ctx_t *AXIS2_CALL
sandesha2_msg_creator_create_terminate_seq_res_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *ref_rm_msg,
    axis2_msg_ctx_t *out_msg,
    sandesha2_storage_mgr_t *storage_mgr);

/**
 * Adds an ack message to the given application message.
 * 
 * @param app_msg
 * @param sequence_id
 */
axis2_status_t AXIS2_CALL
sandesha2_msg_creator_add_ack_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *app_msg,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr);

sandesha2_msg_ctx_t *AXIS2_CALL
sandesha2_msg_creator_create_make_connection_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *ref_rm_msg_ctx, 
    axis2_char_t *make_conn_seq_id,
    axis2_char_t *make_conn_anon_uri,
    sandesha2_storage_mgr_t *storage_mgr);

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* SANDESHA2_MSG_CREATOR_H */
