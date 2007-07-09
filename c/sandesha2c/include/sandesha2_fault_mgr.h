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
 
#ifndef SANDESHA2_FAULT_MGR_H
#define SANDESHA2_FAULT_MGR_H

/**
  * @file sandesha2_fault_mgr.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_fault_data.h>
#include <axis2_msg_ctx.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup sandesha2_util
 * @{
 */
 
sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_create_seq_refused(
    const axutil_env_t *env,
    axis2_msg_ctx_t *create_seq_msg,
    sandesha2_storage_mgr_t *storage_man);
        
sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_last_msg_num_exceeded(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *app_rm_msg,
    sandesha2_storage_mgr_t *storage_man);
            
sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_msg_num_rollover(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_man);

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_unknown_seq(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_man);

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_invalid_ack(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *ack_rm_msg,
    sandesha2_storage_mgr_t *storage_man);

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_seq_closed(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_man);

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_get_fault(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_fault_data_t *fault_data,
    axis2_char_t *addr_ns_uri,
    sandesha2_storage_mgr_t *storage_man);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SANDESHA2_FAULT_MGR_H*/
