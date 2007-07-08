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
 
#include <sandesha2_msg_validator.h>
#include <sandesha2_utils.h>
#include <sandesha2_constants.h>
#include <sandesha2_spec_specific_consts.h>



axis2_status_t AXIS2_CALL
sandesha2_msg_validator_validate_msg(
        const axutil_env_t *env,
        sandesha2_msg_ctx_t *rm_msg_ctx, 
        sandesha2_storage_mgr_t *storage_mgr)
{
    int msg_type = -1;
    axis2_char_t *seq_id = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    msg_type = sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, env);
    if(SANDESHA2_MSG_TYPE_CREATE_SEQ != msg_type && 
                        SANDESHA2_MSG_TYPE_UNKNOWN != msg_type)
    {
        seq_id = sandesha2_utils_get_seq_id_from_rm_msg_ctx(env, rm_msg_ctx);
        if(NULL != seq_id)
        {
            axis2_char_t *rm_ver_seq = NULL;
            axis2_char_t *addr_ns_seq = NULL;
            axis2_char_t *rm_ns_msg = NULL;
            axis2_char_t *addr_ns_msg = NULL;
            axis2_char_t *rm_ns_seq = NULL;
            
            rm_ver_seq = sandesha2_utils_get_seq_property(env, seq_id, 
                        SANDESHA2_SEQ_PROP_RM_SPEC_VERSION, storage_mgr);
            addr_ns_seq = sandesha2_utils_get_seq_property(env, seq_id, 
                        SANDESHA2_SEQ_PROP_ADDRESSING_NAMESPACE_VALUE, 
                        storage_mgr);
            rm_ns_msg = sandesha2_msg_ctx_get_rm_ns_val(rm_msg_ctx, env);
            addr_ns_msg = sandesha2_msg_ctx_get_addr_ns_val(rm_msg_ctx, env);
            
            if(NULL != rm_ver_seq)
                rm_ns_seq = sandesha2_spec_specific_consts_get_rm_ns_val(env,
                        rm_ver_seq);
            
            if(NULL != rm_ns_seq && 0 != axutil_strcmp(rm_ns_seq, rm_ns_msg))
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Validation"
                        " failed. The RM namespace of the message does not"
                        " match with the sequence");
                return AXIS2_FAILURE;
            } 
            if(NULL != addr_ns_seq && 0 != axutil_strcmp(addr_ns_seq, addr_ns_msg))
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Validation"
                        " failed. The Addressing namespace of the message does"
                        " not match with the sequence");
                return AXIS2_FAILURE;
            }            
            
        }   
    }
    return AXIS2_SUCCESS;
}
  
