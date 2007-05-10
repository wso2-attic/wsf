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
#include <sandesha2_ack_req_msg_processor.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_fault_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_sender_mgr.h>
#include <sandesha2_sender_bean.h>
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
#include <sandesha2_ack_requested.h>
#include <axis2_addr.h>
#include <sandesha2_msg_init.h>
#include <sandesha2_msg_creator.h>
#include <axis2_transport_out_desc.h>

/** 
 * @brief Ack Requested Message Processor struct impl
 *	Sandesha2 Ack Requested Msg Processor
 */
typedef struct sandesha2_ack_req_msg_processor_impl 
                        sandesha2_ack_req_msg_processor_impl_t;  
  
struct sandesha2_ack_req_msg_processor_impl
{
	sandesha2_msg_processor_t msg_processor;
};

#define SANDESHA2_INTF_TO_IMPL(msg_proc) \
						((sandesha2_ack_req_msg_processor_impl_t *)(msg_proc))

/***************************** Function headers *******************************/
static axis2_status_t AXIS2_CALL 
sandesha2_ack_req_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx);
    
static axis2_status_t AXIS2_CALL 
sandesha2_ack_req_msg_processor_process_out_msg(
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx);
    
static axis2_status_t AXIS2_CALL 
sandesha2_ack_req_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_msg_processor_t* AXIS2_CALL
sandesha2_ack_req_msg_processor_create(const axutil_env_t *env)
{
    sandesha2_ack_req_msg_processor_impl_t *msg_proc_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
              
    msg_proc_impl =  (sandesha2_ack_req_msg_processor_impl_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof(sandesha2_ack_req_msg_processor_impl_t));
	
    if(!msg_proc_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_msg_processor_ops_t));
    if(!msg_proc_impl->msg_processor.ops)
	{
		sandesha2_ack_req_msg_processor_free((sandesha2_msg_processor_t*)
                         msg_proc_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops->process_in_msg = 
                        sandesha2_ack_req_msg_processor_process_in_msg;
    msg_proc_impl->msg_processor.ops->process_out_msg = 
    					sandesha2_ack_req_msg_processor_process_out_msg;
    msg_proc_impl->msg_processor.ops->free = 
                        sandesha2_ack_req_msg_processor_free;
                        
	return &(msg_proc_impl->msg_processor);
}


static axis2_status_t AXIS2_CALL 
sandesha2_ack_req_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env)
{
    sandesha2_ack_req_msg_processor_impl_t *msg_proc_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_proc_impl = SANDESHA2_INTF_TO_IMPL(msg_processor);
    
    if(msg_processor->ops)
        AXIS2_FREE(env->allocator, msg_processor->ops);
    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(msg_processor));
	return AXIS2_SUCCESS;
}


static axis2_status_t AXIS2_CALL 
sandesha2_ack_req_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    sandesha2_ack_requested_t *ack_requested = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_char_t *seq_id = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *acks_to_bean = NULL;
    axis2_endpoint_ref_t *acks_to = NULL;
    axis2_char_t *acks_to_str = NULL;
    axis2_op_t *ack_op = NULL;
    axis2_op_t *rm_msg_op = NULL;
    axis2_msg_ctx_t *ack_msg_ctx = NULL;
    axutil_property_t *property = NULL;
    sandesha2_msg_ctx_t *ack_rm_msg = NULL;
    axiom_soap_envelope_t *envelope = NULL;
    axis2_char_t *wsa_version = NULL;
    axis2_char_t *addr_ns_val = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    
    ack_requested = (sandesha2_ack_requested_t*)sandesha2_msg_ctx_get_msg_part(
        rm_msg_ctx, env, SANDESHA2_MSG_PART_ACK_REQUEST);
    if(!ack_requested)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Ack requested "
            "part is missing");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_REQD_MSG_PART_MISSING,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    sandesha2_ack_requested_set_must_understand(ack_requested, env, AXIS2_FALSE);
    sandesha2_msg_ctx_add_soap_envelope(rm_msg_ctx, env);
    
    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    seq_id = sandesha2_identifier_get_identifier(
        sandesha2_ack_requested_get_identifier(ack_requested, env), env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, 
        axis2_conf_ctx_get_conf(conf_ctx, env));
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    acks_to_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, seq_id,
        SANDESHA2_SEQ_PROP_ACKS_TO_EPR);
    acks_to_str = sandesha2_seq_property_bean_get_value(acks_to_bean, env);
    
    if(!acks_to_str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] acks_to_str"
            " seqeunce property is not set correctly");
        return AXIS2_FAILURE;
    }
    acks_to = axis2_endpoint_ref_create(env, acks_to_str);
    ack_op = axis2_op_create(env);
    axis2_op_set_msg_exchange_pattern(ack_op, env, AXIS2_MEP_URI_IN_ONLY);
    rm_msg_op = axis2_msg_ctx_get_op(msg_ctx, env);
    if(rm_msg_op)
    {
        axutil_array_list_t *out_flow = NULL;
        axutil_array_list_t *new_out_flow = NULL;
        axutil_array_list_t *out_fault_flow = NULL;
        axutil_array_list_t *new_out_fault_flow = NULL;
        out_flow = axis2_op_get_out_flow(rm_msg_op, env);
        new_out_flow = axis2_phases_info_copy_flow(env, out_flow);
        out_fault_flow = axis2_op_get_out_flow(rm_msg_op, env);
        new_out_fault_flow = axis2_phases_info_copy_flow(env, out_fault_flow);
        if(new_out_flow)
            axis2_op_set_out_flow(ack_op, env, new_out_flow);
        if(new_out_fault_flow)
            axis2_op_set_fault_out_flow(ack_op, env, new_out_fault_flow);
    }
    ack_msg_ctx = sandesha2_utils_create_new_related_msg_ctx(env, rm_msg_ctx, 
        ack_op);
    property = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
    axis2_msg_ctx_set_property(ack_msg_ctx, env, 
        SANDESHA2_APPLICATION_PROCESSING_DONE, property);
    ack_rm_msg = sandesha2_msg_init_init_msg(env, ack_msg_ctx);
    sandesha2_msg_ctx_set_rm_ns_val(ack_rm_msg, env, 
        sandesha2_msg_ctx_get_rm_ns_val(rm_msg_ctx, env));
    axis2_msg_ctx_set_message_id(ack_msg_ctx, env, axutil_uuid_gen(env));
    
    envelope = axiom_soap_envelope_create_default_soap_envelope(env, 
        sandesha2_utils_get_soap_version(env, 
        axis2_msg_ctx_get_soap_envelope(msg_ctx, env)));
    axis2_msg_ctx_set_soap_envelope(ack_msg_ctx, env, envelope);
    axis2_msg_ctx_set_to(ack_msg_ctx, env, acks_to);
    axis2_msg_ctx_set_reply_to(ack_msg_ctx, env, axis2_msg_ctx_get_to(msg_ctx, 
        env));
    sandesha2_msg_creator_add_ack_msg(env, ack_rm_msg, seq_id, storage_mgr);
    axis2_msg_ctx_set_server_side(ack_msg_ctx, env, AXIS2_TRUE);
    
    property = axis2_msg_ctx_get_property(msg_ctx, env, AXIS2_WSA_VERSION);
    if(property)
        wsa_version = axutil_property_get_value(property, env);
    
    property = axutil_property_create_with_args(env, 0, 0, 0, wsa_version);
    if(property)
    {
        axis2_msg_ctx_set_property(ack_msg_ctx, env, AXIS2_WSA_VERSION, property);
        property = NULL;
    }
    
    addr_ns_val = sandesha2_utils_get_seq_property(env, seq_id, 
        SANDESHA2_SEQ_PROP_ADDRESSING_NAMESPACE_VALUE, storage_mgr);
    if(sandesha2_utils_is_anon_uri(env, acks_to_str))
    {
        axis2_engine_t *engine = NULL;
        axis2_op_ctx_t *op_ctx = NULL;
        
        if(!axis2_msg_ctx_get_op(msg_ctx, env))
        {
            axis2_op_t *operation = NULL;
            axis2_op_ctx_t *op_ctx = NULL;
            
            operation = axis2_op_create(env);
            axis2_op_set_msg_exchange_pattern(operation, env, 
                AXIS2_MEP_URI_IN_OUT);
            op_ctx = axis2_op_ctx_create(env, operation, NULL);
            axis2_msg_ctx_set_op(msg_ctx, env, operation);
            axis2_msg_ctx_set_op_ctx(msg_ctx, env, op_ctx);            
        }
        op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        axis2_op_ctx_set_response_written(op_ctx, env, AXIS2_TRUE);
        
        property = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_TRUE);
        axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_ACK_WRITTEN, 
            property);
        
        engine = axis2_engine_create(env, conf_ctx);
        if(AXIS2_FAILURE == axis2_engine_send(engine, env, ack_msg_ctx))
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] ack sending"
                " failed");
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SENDING_ACK, 
                AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }        
    }
    else
    {
        sandesha2_sender_mgr_t *retrans_mgr = NULL;
        axis2_char_t *key = NULL;
        sandesha2_sender_bean_t *ack_bean = NULL;
        sandesha2_sender_bean_t *find_bean = NULL;
        sandesha2_property_bean_t *prop_bean = NULL;
        long ack_interval = 0;
        long time_to_send = 0;
        axutil_array_list_t *found_list = NULL;
        axis2_msg_ctx_t *msg_ctx = NULL;
        axis2_engine_t *engine = NULL;
        axis2_transport_out_desc_t *transport_out = NULL;
        
        retrans_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, env);
        key = axutil_uuid_gen(env);
        ack_bean = sandesha2_sender_bean_create(env);
        sandesha2_sender_bean_set_msg_ctx_ref_key(ack_bean, env, key);
        sandesha2_sender_bean_set_msg_id(ack_bean, env, 
                        (axis2_char_t*)axis2_msg_ctx_get_msg_id(ack_msg_ctx, env));
        sandesha2_sender_bean_set_resend(ack_bean, env, AXIS2_FALSE);
        sandesha2_sender_bean_set_seq_id(ack_bean, env, seq_id);
        sandesha2_sender_bean_set_send(ack_bean, env, AXIS2_TRUE);
        sandesha2_sender_bean_set_msg_type(ack_bean, env, SANDESHA2_MSG_TYPE_ACK);
                        
        property = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_FALSE);
        axis2_msg_ctx_set_property(ack_msg_ctx, env, 
            SANDESHA2_QUALIFIED_FOR_SENDING, property);
        
        /* Avoid retrieving property bean from operation until it is availbale */
        /*prop_bean = sandesha2_utils_get_property_bean_from_op(env, 
            axis2_msg_ctx_get_op(msg_ctx, env));*/
        prop_bean = sandesha2_utils_get_property_bean(env, 
            axis2_conf_ctx_get_conf(conf_ctx, env));
        ack_interval = sandesha2_property_bean_get_ack_interval(prop_bean, env);
        time_to_send = sandesha2_utils_get_current_time_in_millis(env) +
            ack_interval;
                        
        find_bean = sandesha2_sender_bean_create(env);
        sandesha2_sender_bean_set_resend(find_bean, env, AXIS2_FALSE);
        sandesha2_sender_bean_set_send(find_bean, env, AXIS2_TRUE);
        sandesha2_sender_bean_set_msg_type(find_bean, env, 
            SANDESHA2_MSG_TYPE_ACK);
                        
        found_list = sandesha2_sender_mgr_find_by_sender_bean(retrans_mgr, env, 
            find_bean);
        if(found_list)
        {
            int i = 0;
            for(i = 0; i < axutil_array_list_size(found_list, env); i++)
            {
                axis2_char_t *msg_stored_key = NULL;
                sandesha2_sender_bean_t *old_ack_bean = NULL;
                old_ack_bean = axutil_array_list_get(found_list, env, i);
                time_to_send = sandesha2_sender_bean_get_time_to_send(
                    old_ack_bean, env);
                /*char *msg_id = sandesha2_sender_bean_get_msg_id(old_ack_bean, env);*/
                sandesha2_sender_mgr_remove(retrans_mgr, env, 
                    sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) 
                        old_ack_bean, env));
                /* Removing the message from the storage */
                msg_stored_key = sandesha2_sender_bean_get_msg_ctx_ref_key(
                    old_ack_bean, env);
                sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, 
                    msg_stored_key);
            }
        }
        sandesha2_sender_bean_set_time_to_send(ack_bean, env, time_to_send); 
        /*axis2_msg_ctx_set_keep_alive(ack_msg_ctx, env, AXIS2_TRUE);*/
        sandesha2_storage_mgr_store_msg_ctx(storage_mgr, env, key, ack_msg_ctx);
        sandesha2_sender_mgr_insert(retrans_mgr, env, ack_bean);
        
        transport_out = axis2_msg_ctx_get_transport_out_desc(ack_msg_ctx, env);
        property = axutil_property_create_with_args(env, 0, 0,
            axis2_transport_out_desc_free_void_arg, transport_out);
        axis2_msg_ctx_set_property(ack_msg_ctx, env, 
            SANDESHA2_ORIGINAL_TRANSPORT_OUT_DESC, property);
        
        property = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_TRUE);
        axis2_msg_ctx_set_property(ack_msg_ctx, env, 
            SANDESHA2_SET_SEND_TO_TRUE, property);
        
        property = axutil_property_create_with_args(env, 0, 0, 0, key);
        axis2_msg_ctx_set_property(ack_msg_ctx, env, 
            SANDESHA2_MESSAGE_STORE_KEY, property);
                        
        axis2_msg_ctx_set_transport_out_desc(ack_msg_ctx, env, 
            sandesha2_utils_get_transport_out(env));
        engine = axis2_engine_create(env, conf_ctx);
        if(AXIS2_FAILURE == axis2_engine_send(engine, env, ack_msg_ctx))
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] ack sending"
                " failed");
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SENDING_ACK, 
                AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
        sandesha2_utils_start_sender_for_seq(env, conf_ctx, seq_id);
        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
    }
    return AXIS2_SUCCESS;
}
    
static axis2_status_t AXIS2_CALL 
sandesha2_ack_req_msg_processor_process_out_msg(
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    
    return AXIS2_SUCCESS;
}

