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
#include <sandesha2_ack_msg_processor.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_seq.h>
#include <sandesha2_next_msg_mgr.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_fault_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_sender_bean.h>
#include <sandesha2_sender_mgr.h>
#include <axis2_msg_ctx.h>
#include <axutil_string.h>
#include <axis2_engine.h>
#include <axiom_soap_const.h>
#include <stdio.h>
#include <sandesha2_storage_mgr.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_core_utils.h>
#include <sandesha2_seq_ack.h>
#include <sandesha2_create_seq_res.h>
#include <axutil_uuid_gen.h>
#include <sandesha2_create_seq_bean.h>
#include <sandesha2_create_seq_mgr.h>
#include <axis2_endpoint_ref.h>
#include <axis2_op_ctx.h>
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_seq_mgr.h>
#include <sandesha2_terminate_mgr.h>
#include <sandesha2_ack_mgr.h>

/** 
 * @brief Acknowledgement Message Processor struct impl
 *	Sandesha2 Acknowledgement Msg Processor
 */
typedef struct sandesha2_ack_msg_processor_impl 
                        sandesha2_ack_msg_processor_impl_t;  
  
struct sandesha2_ack_msg_processor_impl
{
	sandesha2_msg_processor_t msg_processor;
};

#define SANDESHA2_INTF_TO_IMPL(msg_proc) \
						((sandesha2_ack_msg_processor_impl_t *)(msg_proc))

/***************************** Function headers *******************************/
static axis2_status_t AXIS2_CALL 
sandesha2_ack_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx);
    
static sandesha2_sender_bean_t* AXIS2_CALL 
sandesha2_ack_msg_processor_get_retrans_entry(
    const axutil_env_t *env, 
    axutil_array_list_t *list,
    long msg_no);

static long AXIS2_CALL 
sandesha2_ack_msg_processor_get_no_of_msgs_acked(
    const axutil_env_t *env, 
    axutil_array_list_t *list);
                    	
static axis2_status_t AXIS2_CALL 
sandesha2_ack_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_msg_processor_t* AXIS2_CALL
sandesha2_ack_msg_processor_create(
    const axutil_env_t *env)
{
    sandesha2_ack_msg_processor_impl_t *msg_proc_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
              
    msg_proc_impl =  (sandesha2_ack_msg_processor_impl_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof(sandesha2_ack_msg_processor_impl_t));
	
    if(!msg_proc_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_msg_processor_ops_t));
    if(!msg_proc_impl->msg_processor.ops)
	{
		sandesha2_ack_msg_processor_free((sandesha2_msg_processor_t*)
                         msg_proc_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops->process_in_msg = 
                        sandesha2_ack_msg_processor_process_in_msg;
    msg_proc_impl->msg_processor.ops->free = sandesha2_ack_msg_processor_free;
                        
	return &(msg_proc_impl->msg_processor);
}


static axis2_status_t AXIS2_CALL 
sandesha2_ack_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env)
{
    sandesha2_ack_msg_processor_impl_t *msg_proc_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_proc_impl = SANDESHA2_INTF_TO_IMPL(msg_processor);
    
    if(msg_processor->ops)
        AXIS2_FREE(env->allocator, msg_processor->ops);
    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(msg_processor));
	return AXIS2_SUCCESS;
}


static axis2_status_t AXIS2_CALL 
sandesha2_ack_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    sandesha2_seq_ack_t *seq_ack = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_sender_mgr_t *retrans_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    axutil_array_list_t *ack_range_list = NULL;
    axutil_array_list_t *nack_list = NULL;
    axis2_char_t *out_seq_id = NULL;
    axis2_char_t *int_seq_id = NULL;
    axutil_property_t *property = NULL;
    sandesha2_sender_bean_t *input_bean = NULL;
    axutil_array_list_t *retrans_list = NULL;
    axutil_array_list_t *acked_list = NULL;
    int i = 0, size = 0;
    long no_of_msgs_acked = 0;
    sandesha2_seq_property_bean_t *no_of_msgs_acked_bean = NULL;
    axis2_char_t str_long[32];
    sandesha2_seq_property_bean_t *completed_bean = NULL;
    axis2_char_t *str_list = NULL;
    axis2_char_t *last_out_msg_no_str = NULL;
    axis2_bool_t added = AXIS2_FALSE;
    const axis2_char_t *action = NULL;
    sandesha2_msg_ctx_t *fault_msg_ctx = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2] Entry:sandesha2_ack_msg_processor_process_in_msg");
    seq_ack = (sandesha2_seq_ack_t*)sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, 
        env, SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT);
    if(!seq_ack)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Sequence"
            " acknowledgement part is null");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_REQD_MSG_PART_MISSING,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;        
    }
    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, 
        axis2_conf_ctx_get_conf(conf_ctx, env));
    sandesha2_seq_ack_set_must_understand(seq_ack, env, AXIS2_FALSE);
    sandesha2_msg_ctx_add_soap_envelope(rm_msg_ctx, env);
   
    retrans_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, env);
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    
    ack_range_list = sandesha2_seq_ack_get_ack_range_list(seq_ack, env);
    nack_list = sandesha2_seq_ack_get_nack_list(seq_ack, env);
    out_seq_id = sandesha2_identifier_get_identifier(
        sandesha2_seq_ack_get_identifier(seq_ack, env), env);
    if(!out_seq_id || 0 == axutil_strlen(out_seq_id))
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] OutSequenceId is"
            " null");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NULL_SEQ, AXIS2_FAILURE);
        return AXIS2_FAILURE;        
    }
    int_seq_id = sandesha2_utils_get_seq_property(env, out_seq_id, 
        SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID, storage_mgr);
    fault_msg_ctx = sandesha2_fault_mgr_check_for_unknown_seq(env,
        rm_msg_ctx, out_seq_id, storage_mgr);
    if(fault_msg_ctx)
    {
        axis2_engine_t *engine = NULL;
        engine = axis2_engine_create(env, conf_ctx);
        axis2_engine_send_fault(engine, env, sandesha2_msg_ctx_get_msg_ctx(
            fault_msg_ctx, env));
        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
    }
    fault_msg_ctx = sandesha2_fault_mgr_check_for_invalid_ack(env, rm_msg_ctx, 
         storage_mgr);
    if(fault_msg_ctx)
    {
        axis2_engine_t *engine = NULL;
        engine = axis2_engine_create(env, conf_ctx);
        axis2_engine_send_fault(engine, env, sandesha2_msg_ctx_get_msg_ctx(
             fault_msg_ctx, env));
        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
    }
    if(int_seq_id)
        sandesha2_seq_mgr_update_last_activated_time(env, int_seq_id, 
            storage_mgr);
    property = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
    axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_ACK_PROCSSED, property);
                        
    input_bean = sandesha2_sender_bean_create(env);
    sandesha2_sender_bean_set_send(input_bean, env, AXIS2_TRUE);
    sandesha2_sender_bean_set_resend(input_bean, env, AXIS2_TRUE);
    retrans_list = sandesha2_sender_mgr_find_by_sender_bean(retrans_mgr, env, 
        input_bean);
   
    acked_list = axutil_array_list_create(env, 0);
    if(!acked_list)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    if(ack_range_list)
        size = axutil_array_list_size(ack_range_list, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_ack_range_t *ack_range  = NULL;
        long lower = -1;
        long upper = -1;
        long j = 0;
        
        ack_range = axutil_array_list_get(ack_range_list, env, i);
        lower = sandesha2_ack_range_get_lower_value(ack_range, env);
        upper = sandesha2_ack_range_get_upper_value(ack_range, env);
        for(j = lower; j <= upper; j++)
        {
            sandesha2_sender_bean_t *retrans_bean = NULL;
            long *add_no = NULL;
            
            retrans_bean = sandesha2_ack_msg_processor_get_retrans_entry(
                env, retrans_list, j);
            if(retrans_bean)
            {
                sandesha2_sender_mgr_remove(retrans_mgr, env, 
                    sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) 
                        retrans_bean, env));
                sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env,
                    sandesha2_sender_bean_get_msg_ctx_ref_key(retrans_bean, 
                        env));
            }
            add_no = AXIS2_MALLOC(env->allocator, sizeof(long));
            *add_no = (long)j;
            axutil_array_list_add(acked_list, env, add_no);
        }
    }
    for(i = 0; i < axutil_array_list_size(nack_list, env); i++)
    {
        sandesha2_nack_t *nack = NULL;
        nack = axutil_array_list_get(nack_list, env, i);
        /* TODO processing nacks */
    }
    no_of_msgs_acked = sandesha2_ack_msg_processor_get_no_of_msgs_acked(
        env, ack_range_list);
    no_of_msgs_acked_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, 
        env, out_seq_id, SANDESHA2_SEQ_PROP_NO_OF_OUTGOING_MSGS_ACKED);
    sprintf(str_long, "%ld", no_of_msgs_acked);
    if(!no_of_msgs_acked_bean)
    {
        added = AXIS2_TRUE;
        no_of_msgs_acked_bean = sandesha2_seq_property_bean_create(env);
        sandesha2_seq_property_bean_set_name(no_of_msgs_acked_bean, env,
            SANDESHA2_SEQ_PROP_NO_OF_OUTGOING_MSGS_ACKED);
        sandesha2_seq_property_bean_set_seq_id(no_of_msgs_acked_bean, env,
            out_seq_id);
    }
    sandesha2_seq_property_bean_set_value(no_of_msgs_acked_bean, env, 
        str_long);
    if(added)
    {
        sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, 
            no_of_msgs_acked_bean); 
    }
    else
    {
        sandesha2_seq_property_mgr_update(seq_prop_mgr, env, 
            no_of_msgs_acked_bean); 
    }
    completed_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, 
        env, out_seq_id, SANDESHA2_SEQ_PROP_CLIENT_COMPLETED_MESSAGES);
    if(!completed_bean && int_seq_id)
    {
        completed_bean = sandesha2_seq_property_bean_create(env);
        sandesha2_seq_property_bean_set_seq_id(completed_bean, env, int_seq_id);
        sandesha2_seq_property_bean_set_name(completed_bean, env, 
            SANDESHA2_SEQ_PROP_CLIENT_COMPLETED_MESSAGES);
        sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, completed_bean);
    }
    str_list = sandesha2_utils_array_list_to_string(env, acked_list,
        SANDESHA2_ARRAY_LIST_LONG);
    if(completed_bean)
    {
        sandesha2_seq_property_bean_set_value(completed_bean, env, str_list);
        sandesha2_seq_property_mgr_update(seq_prop_mgr, env, completed_bean);
    }
    last_out_msg_no_str = sandesha2_utils_get_seq_property(env, int_seq_id,
        SANDESHA2_SEQ_PROP_LAST_OUT_MESSAGE_NO, storage_mgr);
    if(last_out_msg_no_str)
    {
        long highest_out_msg_no = 0;
        highest_out_msg_no = atol(last_out_msg_no_str);
        if(highest_out_msg_no > 0)
        {
            axis2_bool_t completed = AXIS2_FALSE;
            completed = sandesha2_ack_mgr_verify_seq_completion(env, 
                ack_range_list, highest_out_msg_no);
            if(completed)
            {
                sandesha2_terminate_mgr_add_terminate_seq_msg(env, 
                    rm_msg_ctx, out_seq_id, int_seq_id, storage_mgr);
            }
        }
    }
    action = axis2_msg_ctx_get_wsa_action(msg_ctx, env);
    if(action && 0 == axutil_strcmp(action, 
        sandesha2_spec_specific_consts_get_ack_req_action(env, 
            sandesha2_msg_ctx_get_rm_spec_ver(rm_msg_ctx, env))))
    {
        sandesha2_msg_ctx_set_paused(rm_msg_ctx, env, AXIS2_TRUE);
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2] Exit: sandesha2_ack_msg_processor_process_in_msg");
    return AXIS2_SUCCESS;
}
    
static sandesha2_sender_bean_t* AXIS2_CALL 
sandesha2_ack_msg_processor_get_retrans_entry(
    const axutil_env_t *env, 
    axutil_array_list_t *list,
    long msg_no)
{
    int i = 0;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, list, NULL);
    
    for(i = 0; i < axutil_array_list_size(list, env); i++)
    {
        sandesha2_sender_bean_t *bean = NULL;
        bean = axutil_array_list_get(list, env, i);
        if(sandesha2_sender_bean_get_msg_no(bean, env) == msg_no)
            return bean;
    }
    return NULL;    
}

static long AXIS2_CALL 
sandesha2_ack_msg_processor_get_no_of_msgs_acked(
    const axutil_env_t *env, 
    axutil_array_list_t *list)
{
    long no_of_msgs = 0;
    int i = 0;
    
    AXIS2_ENV_CHECK(env, -1);
    AXIS2_PARAM_CHECK(env->error, list, -1);
    
    for(i = 0; i <  axutil_array_list_size(list, env); i++)
    {
        sandesha2_ack_range_t *ack_range = NULL;
        long upper = 0;
        long lower = 0;
        long diff = 0;
        
        ack_range = axutil_array_list_get(list, env, i);
        lower = sandesha2_ack_range_get_lower_value(ack_range, env);
        upper = sandesha2_ack_range_get_upper_value(ack_range, env);
        
        diff = (upper - lower) + 1;
        if(diff > 0)
            no_of_msgs += diff;
    }
    return no_of_msgs;
}

