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
#include <sandesha2_terminate_seq_res_msg_processor.h>
#include <sandesha2_seq_ack.h>
#include <sandesha2_terminate_seq_res.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_constants.h>
#include <axis2_conf_ctx.h>
#include <sandesha2_utils.h>
#include <sandesha2_terminate_mgr.h>

/** 
 * @brief Terminate Sequence Response Message Processor struct impl
 *	Sandesha2 Terminate Sequence Response Msg Processor
 */
typedef struct sandesha2_terminate_seq_res_msg_processor_impl 
                        sandesha2_terminate_seq_res_msg_processor_impl_t;  
  
struct sandesha2_terminate_seq_res_msg_processor_impl
{
	sandesha2_msg_processor_t msg_processor;
};

#define SANDESHA2_INTF_TO_IMPL(msg_proc) \
						((sandesha2_terminate_seq_res_msg_processor_impl_t *)\
                        (msg_proc))

/***************************** Function headers *******************************/
static axis2_status_t AXIS2_CALL 
sandesha2_terminate_seq_res_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx);
    
static axis2_status_t AXIS2_CALL 
sandesha2_terminate_seq_res_msg_processor_process_out_msg(
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx);
    
static axis2_status_t AXIS2_CALL 
sandesha2_terminate_seq_res_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_msg_processor_t* AXIS2_CALL
sandesha2_terminate_seq_res_msg_processor_create(
    const axutil_env_t *env)
{
    sandesha2_terminate_seq_res_msg_processor_impl_t *msg_proc_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
              
    msg_proc_impl =  ( sandesha2_terminate_seq_res_msg_processor_impl_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof( sandesha2_terminate_seq_res_msg_processor_impl_t));
	
    if(!msg_proc_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_msg_processor_ops_t));
    if(!msg_proc_impl->msg_processor.ops)
	{
        sandesha2_terminate_seq_res_msg_processor_free((sandesha2_msg_processor_t*)
                         msg_proc_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops->process_in_msg = 
                        sandesha2_terminate_seq_res_msg_processor_process_in_msg;
    msg_proc_impl->msg_processor.ops->process_out_msg = 
    					sandesha2_terminate_seq_res_msg_processor_process_out_msg;
    msg_proc_impl->msg_processor.ops->free = 
                        sandesha2_terminate_seq_res_msg_processor_free;
                        
	return &(msg_proc_impl->msg_processor);
}


static axis2_status_t AXIS2_CALL 
sandesha2_terminate_seq_res_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env)
{
    sandesha2_terminate_seq_res_msg_processor_impl_t *msg_proc_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_proc_impl = SANDESHA2_INTF_TO_IMPL(msg_processor);
    
    if(msg_processor->ops)
        AXIS2_FREE(env->allocator, msg_processor->ops);
    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(msg_processor));
	return AXIS2_SUCCESS;
}


static axis2_status_t AXIS2_CALL 
sandesha2_terminate_seq_res_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    axis2_msg_ctx_t *msg_ctx = NULL;
    sandesha2_terminate_seq_res_t *term_seq_res = NULL;
    axis2_char_t *seq_id = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
   
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] sandesha2_terminate_msg_processor_process_in_msg .........");
    
    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    
    term_seq_res = (sandesha2_terminate_seq_res_t*)sandesha2_msg_ctx_get_msg_part(
        rm_msg_ctx, env, SANDESHA2_MSG_PART_TERMINATE_SEQ_RESPONSE);
    if(!term_seq_res)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Terminate "
            "Sequence part is not available");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_REQD_MSG_PART_MISSING, 
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    seq_id = sandesha2_identifier_get_identifier(
        sandesha2_terminate_seq_res_get_identifier(term_seq_res, env), env);
    if(!seq_id || 0 == axutil_strlen(seq_id))
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Invalid "
            "sequence id");
        return AXIS2_FAILURE;
    }
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    storage_mgr = (sandesha2_storage_mgr_t *) sandesha2_utils_get_storage_mgr(
        env, conf_ctx, axis2_conf_ctx_get_conf(conf_ctx, env));
    sandesha2_terminate_mgr_terminate_sending_side(env, conf_ctx, seq_id, 
        AXIS2_FALSE, storage_mgr);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Exit: sandesha2_terminate_seq_res_msg_processor_process_in_msg");
    return AXIS2_SUCCESS;
}

    
static axis2_status_t AXIS2_CALL 
sandesha2_terminate_seq_res_msg_processor_process_out_msg(
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    
    return AXIS2_SUCCESS;
}

