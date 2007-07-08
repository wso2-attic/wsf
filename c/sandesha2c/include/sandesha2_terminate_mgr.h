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
 
#ifndef SANDESHA2_TERMINATER_MGR_H
#define SANDESHA2_TERMINATER_MGR_H



/**
  * @file sandesha2_terminate_mgr.h
  * @brief 
  */

#include <sandesha2_storage_mgr.h>
#include <axis2_conf_ctx.h>
#include <axis2_conf.h>
#include <axiom_soap_envelope.h>
#include <axutil_qname.h>
#include <axutil_array_list.h>
#include <axis2_op.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_msg_ctx.h>
#include <axiom_soap_envelope.h>


#ifdef __cplusplus
extern "C"
{
#endif

struct sandesha2_seq_property_mgr;
struct sandesha2_seq_property_bean_t;

/** @defgroup sandesha2_terminate_mgr
 * @ingroup sandesha2_util
 * @{
 */
#define SANDESHA2_CLEANED_ON_TERMINATE_MSG "CleanedOnTerminateMsg"
#define SANDESHA2_CLEANED_AFTER_INVOCATION "CleanedAfterInvocation"

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_clean_recv_side_after_terminate_msg(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_man);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_clean_recv_side_after_invocation(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_man);
                        
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_terminate_sending_side(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    axis2_bool_t svr_side,
    sandesha2_storage_mgr_t *storage_man);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_do_updates_if_needed(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    sandesha2_seq_property_bean_t *prop_bean,
    struct sandesha2_seq_property_mgr *prop_mgr);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_time_out_sending_side_seq(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    axis2_bool_t svr_side,
    sandesha2_storage_mgr_t *storage_man);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_add_terminate_seq_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    axis2_char_t *out_seq_id,
    axis2_char_t *int_seq_id,
    sandesha2_storage_mgr_t *storage_man);


/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_TERMINATER_MGR_H */

