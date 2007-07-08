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
#include <sandesha2_close_seq_msg_processor.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_fault_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_msg_ctx.h>
#include <axis2_msg_ctx.h>
#include <axutil_string.h>
#include <axis2_engine.h>
#include <axiom_soap_const.h>
#include <stdio.h>
#include <sandesha2_storage_mgr.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <sandesha2_seq_ack.h>
#include <sandesha2_close_seq.h>
#include <axutil_uuid_gen.h>
#include <sandesha2_create_seq_bean.h>
#include <sandesha2_create_seq_mgr.h>
#include <axis2_endpoint_ref.h>
#include <axis2_op_ctx.h>
#include <sandesha2_spec_specific_consts.h>
#include <axis2_core_utils.h>
#include <sandesha2_ack_mgr.h>
#include <sandesha2_msg_creator.h>

/** 
 * @brief Close Sequence Message Processor struct impl
 *	Sandesha2 Close Sequence Msg Processor
 */
typedef struct sandesha2_close_seq_msg_processor_impl 
                        sandesha2_close_seq_msg_processor_impl_t;  
  
struct sandesha2_close_seq_msg_processor_impl
{
	sandesha2_msg_processor_t msg_processor;
};

#define SANDESHA2_INTF_TO_IMPL(msg_proc) \
						((sandesha2_close_seq_msg_processor_impl_t *)(msg_proc))

/***************************** Function headers *******************************/
axis2_status_t AXIS2_CALL 
sandesha2_close_seq_msg_processor_process_in_msg (
                        sandesha2_msg_processor_t *msg_processor,
						const axutil_env_t *env,
                        sandesha2_msg_ctx_t *rm_msg_ctx);
    
axis2_status_t AXIS2_CALL 
sandesha2_close_seq_msg_processor_process_out_msg(
                        sandesha2_msg_processor_t *msg_processor,
                    	const axutil_env_t *env, 
                        sandesha2_msg_ctx_t *rm_msg_ctx);
                    	
axis2_status_t AXIS2_CALL 
sandesha2_close_seq_msg_processor_free (sandesha2_msg_processor_t *element, 
						const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_msg_processor_t* AXIS2_CALL
sandesha2_close_seq_msg_processor_create(const axutil_env_t *env)
{
    sandesha2_close_seq_msg_processor_impl_t *msg_proc_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
              
    msg_proc_impl =  (sandesha2_close_seq_msg_processor_impl_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof(sandesha2_close_seq_msg_processor_impl_t));
	
    if(!msg_proc_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_msg_processor_ops_t));
    if(!msg_proc_impl->msg_processor.ops)
	{
		sandesha2_close_seq_msg_processor_free((sandesha2_msg_processor_t*)
                         msg_proc_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops->process_in_msg = 
                        sandesha2_close_seq_msg_processor_process_in_msg;
    msg_proc_impl->msg_processor.ops->process_out_msg = 
    					sandesha2_close_seq_msg_processor_process_out_msg;
    msg_proc_impl->msg_processor.ops->free = sandesha2_close_seq_msg_processor_free;
                        
	return &(msg_proc_impl->msg_processor);
}


axis2_status_t AXIS2_CALL 
sandesha2_close_seq_msg_processor_free (sandesha2_msg_processor_t *msg_processor, 
						const axutil_env_t *env)
{
    sandesha2_close_seq_msg_processor_impl_t *msg_proc_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_proc_impl = SANDESHA2_INTF_TO_IMPL(msg_processor);
    
    if(msg_processor->ops)
        AXIS2_FREE(env->allocator, msg_processor->ops);
    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(msg_processor));
	return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL 
sandesha2_close_seq_msg_processor_process_in_msg (
                        sandesha2_msg_processor_t *msg_processor,
						const axutil_env_t *env,
                        sandesha2_msg_ctx_t *rm_msg_ctx)
{
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_close_seq_t *close_seq = NULL;
    axis2_char_t *seq_id = NULL;
    sandesha2_msg_ctx_t *fault_rm_msg_ctx = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *close_seq_bean = NULL;
    axis2_msg_ctx_t *ack_msg_ctx = NULL;
    sandesha2_msg_ctx_t *ack_rm_msg = NULL;
    axis2_char_t *rm_ns_val = NULL;
    axiom_soap_envelope_t *envelope = NULL;
    sandesha2_seq_ack_t *seq_ack  = NULL;
    axis2_msg_ctx_t *close_seq_res_msg = NULL;
    sandesha2_msg_ctx_t *close_seq_res_rm_msg = NULL;
    axutil_property_t *property = NULL;
    axis2_engine_t *engine = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    
    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, 
                        axis2_conf_ctx_get_conf(conf_ctx, env));
    close_seq = (sandesha2_close_seq_t*)sandesha2_msg_ctx_get_msg_part(
                        rm_msg_ctx, env, SANDESHA2_MSG_PART_CLOSE_SEQ);
    
    seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_close_seq_get_identifier(close_seq, env), env);
    
    fault_rm_msg_ctx = sandesha2_fault_mgr_check_for_unknown_seq(env,
                        rm_msg_ctx, seq_id, storage_mgr);
    if(fault_rm_msg_ctx)
    {
        engine = axis2_engine_create(env, conf_ctx);
        axis2_engine_send(engine, env, sandesha2_msg_ctx_get_msg_ctx(
                        fault_rm_msg_ctx, env));
        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
        return AXIS2_SUCCESS;
    }
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    close_seq_bean = sandesha2_seq_property_bean_create(env);
    sandesha2_seq_property_bean_set_seq_id(close_seq_bean, env, seq_id);
    sandesha2_seq_property_bean_set_name(close_seq_bean, env, 
                        SANDESHA2_SEQ_PROP_SEQ_CLOSED);
    sandesha2_seq_property_bean_set_value(close_seq_bean, env, 
                        AXIS2_VALUE_TRUE);
    
    sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, close_seq_bean);
    ack_rm_msg = sandesha2_ack_mgr_generate_ack_msg(env, rm_msg_ctx, seq_id,
                        storage_mgr);
    ack_msg_ctx = sandesha2_msg_ctx_get_msg_ctx(ack_rm_msg, env);
    rm_ns_val = sandesha2_msg_ctx_get_rm_ns_val(ack_rm_msg, env);
    sandesha2_msg_ctx_get_rm_ns_val(rm_msg_ctx, env);
    sandesha2_msg_ctx_set_rm_ns_val(ack_rm_msg, env, rm_ns_val);
    
    envelope = axiom_soap_envelope_create_default_soap_envelope(env,
                        sandesha2_utils_get_soap_version(env,
                        axis2_msg_ctx_get_soap_envelope(msg_ctx, env)));
    axis2_msg_ctx_set_soap_envelope(ack_msg_ctx, env, envelope);
    
    seq_ack = (sandesha2_seq_ack_t*)sandesha2_msg_ctx_get_msg_part(ack_rm_msg, 
                        env, SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT);
    close_seq_res_msg = axis2_core_utils_create_out_msg_ctx(env, msg_ctx);
    
    close_seq_res_rm_msg = sandesha2_msg_creator_create_close_seq_res_msg(env, 
                        rm_msg_ctx, close_seq_res_msg, storage_mgr);
    
    sandesha2_msg_ctx_set_msg_part(close_seq_res_rm_msg, env, 
                        SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT,
                        (sandesha2_iom_rm_part_t*)seq_ack);
    sandesha2_msg_ctx_set_flow(close_seq_res_rm_msg, env, AXIS2_OUT_FLOW);
    property = axutil_property_create_with_args(env, 0, 0, 0, 
        AXIS2_VALUE_TRUE);
    sandesha2_msg_ctx_set_property(close_seq_res_rm_msg, env, 
                        SANDESHA2_APPLICATION_PROCESSING_DONE, property);
    /*AXIS2_MSG_CTX_SET_RESPONSE_WRITTEN(close_seq_res_msg, env, AXIS2_TRUE);*/
    sandesha2_msg_ctx_add_soap_envelope(close_seq_res_rm_msg, env);
    
    engine = axis2_engine_create(env, conf_ctx);
    axis2_engine_send(engine, env, close_seq_res_msg);
    return AXIS2_SUCCESS;
}
    
axis2_status_t AXIS2_CALL 
sandesha2_close_seq_msg_processor_process_out_msg(
                        sandesha2_msg_processor_t *msg_processor,
                    	const axutil_env_t *env, 
                        sandesha2_msg_ctx_t *rm_msg_ctx)
{
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    
    return AXIS2_SUCCESS;
}

