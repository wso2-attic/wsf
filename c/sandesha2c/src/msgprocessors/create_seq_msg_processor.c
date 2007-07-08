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
#include <sandesha2_create_seq_msg_processor.h>
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
#include <sandesha2_create_seq.h>
#include <axis2_conf_ctx.h>
#include <axis2_core_utils.h>
#include <sandesha2_create_seq_res.h>
#include <sandesha2_seq_offer.h>
#include <sandesha2_accept.h>
#include <sandesha2_address.h>
#include <sandesha2_acks_to.h>
#include <sandesha2_create_seq_res.h>
#include <axutil_uuid_gen.h>
#include <sandesha2_create_seq_bean.h>
#include <sandesha2_create_seq_mgr.h>
#include <axis2_endpoint_ref.h>
#include <axis2_op_ctx.h>
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_msg_creator.h>
#include <sandesha2_seq_mgr.h>

/** 
 * @brief Create Sequence Message Processor struct impl
 *	Sandesha2 Create Sequence Msg Processor
 */
typedef struct sandesha2_create_seq_msg_processor_impl 
                        sandesha2_create_seq_msg_processor_impl_t;  
  
struct sandesha2_create_seq_msg_processor_impl
{
	sandesha2_msg_processor_t msg_processor;
};

#define SANDESHA2_INTF_TO_IMPL(msg_proc) \
						((sandesha2_create_seq_msg_processor_impl_t *)(msg_proc))

/***************************** Function headers *******************************/
static axis2_status_t AXIS2_CALL 
sandesha2_create_seq_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx);
    
static axis2_status_t AXIS2_CALL 
sandesha2_create_seq_msg_processor_process_out_msg(
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx);
    
static axis2_bool_t AXIS2_CALL 
sandesha2_create_seq_msg_processor_offer_accepted(
    const axutil_env_t *env, 
    axis2_char_t *seq_id,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_mgr);
                    
static axis2_status_t AXIS2_CALL 
sandesha2_create_seq_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
    const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_msg_processor_t* AXIS2_CALL
sandesha2_create_seq_msg_processor_create(
    const axutil_env_t *env)
{
    sandesha2_create_seq_msg_processor_impl_t *msg_proc_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
              
    msg_proc_impl =  (sandesha2_create_seq_msg_processor_impl_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof(sandesha2_create_seq_msg_processor_impl_t));
	
    if(NULL == msg_proc_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_msg_processor_ops_t));
    if(NULL == msg_proc_impl->msg_processor.ops)
	{
		sandesha2_create_seq_msg_processor_free((sandesha2_msg_processor_t*)
                         msg_proc_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops->process_in_msg = 
                        sandesha2_create_seq_msg_processor_process_in_msg;
    msg_proc_impl->msg_processor.ops->process_out_msg = 
    					sandesha2_create_seq_msg_processor_process_out_msg;
    msg_proc_impl->msg_processor.ops->free = sandesha2_create_seq_msg_processor_free;
                        
	return &(msg_proc_impl->msg_processor);
}


static axis2_status_t AXIS2_CALL 
sandesha2_create_seq_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env)
{
    sandesha2_create_seq_msg_processor_impl_t *msg_proc_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_proc_impl = SANDESHA2_INTF_TO_IMPL(msg_processor);
    
    if(NULL != msg_processor->ops)
        AXIS2_FREE(env->allocator, msg_processor->ops);
    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(msg_processor));
	return AXIS2_SUCCESS;
}


static axis2_status_t AXIS2_CALL 
sandesha2_create_seq_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    axis2_msg_ctx_t *msg_ctx = NULL;
    sandesha2_create_seq_t *create_seq_part = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_msg_ctx_t *fault_rm_msg_ctx = NULL;
    axis2_msg_ctx_t *out_msg_ctx = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    axutil_property_t *property = NULL;
    axis2_char_t *new_seq_id = NULL;
    sandesha2_msg_ctx_t *create_seq_res_msg = NULL;
    sandesha2_create_seq_res_t *create_seq_res_part = NULL;
    sandesha2_seq_offer_t *seq_offer = NULL;
    axis2_endpoint_ref_t *acks_to = NULL;
    sandesha2_seq_property_bean_t *acks_to_bean = NULL;
    sandesha2_seq_property_bean_t *to_bean = NULL;
    axis2_engine_t *engine = NULL;
    axis2_char_t *addr_ns_uri = NULL;
    axis2_char_t *anon_uri = NULL;
    axis2_endpoint_ref_t *to_epr = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
     
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Start:sandesha2_create_seq_msg_processor_process_in_msg");
    
    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    create_seq_part = (sandesha2_create_seq_t*)sandesha2_msg_ctx_get_msg_part(
                        rm_msg_ctx, env, SANDESHA2_MSG_PART_CREATE_SEQ);
    if(!create_seq_part)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]create_seq_part"
            " is NULL");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_REQD_MSG_PART_MISSING,
                        AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, 
        axis2_conf_ctx_get_conf(conf_ctx, env));
    
    fault_rm_msg_ctx = sandesha2_fault_mgr_check_for_create_seq_refused(
                        env, msg_ctx, storage_mgr);
    if(fault_rm_msg_ctx)
    {
        axis2_engine_t *engine = NULL;
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2]A fault occurred"); 
        engine = axis2_engine_create(env, conf_ctx);
        axis2_engine_send_fault(engine, env, sandesha2_msg_ctx_get_msg_ctx(
            fault_rm_msg_ctx, env));
        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
        return AXIS2_SUCCESS;
    }
    out_msg_ctx = axis2_core_utils_create_out_msg_ctx(env, msg_ctx);
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, 
                        env);
    new_seq_id = sandesha2_seq_mgr_setup_new_seq(env, rm_msg_ctx, 
                        storage_mgr);
    create_seq_res_msg = sandesha2_msg_creator_create_create_seq_res_msg(env,
                        rm_msg_ctx, out_msg_ctx, new_seq_id, storage_mgr);
    axis2_msg_ctx_set_flow(out_msg_ctx, env, AXIS2_OUT_FLOW);
    
    property = axutil_property_create_with_args(env, 0, 0, 0, 
        AXIS2_VALUE_TRUE);
    /* For making sure that this won't be processed again */
    sandesha2_msg_ctx_set_property(create_seq_res_msg, env, 
        SANDESHA2_APPLICATION_PROCESSING_DONE, property); 
    
    create_seq_res_part = (sandesha2_create_seq_res_t*)
        sandesha2_msg_ctx_get_msg_part(create_seq_res_msg, 
        env, SANDESHA2_MSG_PART_CREATE_SEQ_RESPONSE);
    seq_offer = sandesha2_create_seq_get_seq_offer(create_seq_part, 
                        env);
    /* Offer processing */ 
    if(seq_offer)
    {
        sandesha2_accept_t *accept = NULL;
        axis2_char_t *offer_seq_id = NULL;
        axis2_bool_t offer_accepted = AXIS2_FALSE;

        if(create_seq_res_part) 
            accept = sandesha2_create_seq_res_get_accept(create_seq_res_part, env);
        if(!accept)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]Accept part "
                "has not genereated for a message with offer");
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_REQD_MSG_PART_MISSING,
                 AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
        offer_seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_seq_offer_get_identifier(seq_offer, env), env);
        offer_accepted = sandesha2_create_seq_msg_processor_offer_accepted(
            env, offer_seq_id, rm_msg_ctx, 
            storage_mgr);
        if(offer_accepted)
        {
            sandesha2_create_seq_bean_t *create_seq_bean = NULL;
            axis2_char_t *int_seq_id = NULL;
            sandesha2_create_seq_mgr_t *create_seq_mgr = NULL;
            sandesha2_seq_property_bean_t *out_seq_bean = NULL;
            sandesha2_seq_property_bean_t *int_seq_bean = NULL;
    
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "[sandesha2] Offer Accepted"); 
            create_seq_bean = sandesha2_create_seq_bean_create(env);
            sandesha2_create_seq_bean_set_seq_id(create_seq_bean, env, 
                        offer_seq_id);
            int_seq_id = sandesha2_utils_get_outgoing_internal_seq_id(env,
                        new_seq_id);
            sandesha2_create_seq_bean_set_internal_seq_id(create_seq_bean, env,
                        int_seq_id);
            sandesha2_create_seq_bean_set_create_seq_msg_id(create_seq_bean, env,
                        axutil_uuid_gen(env));
            create_seq_mgr = sandesha2_storage_mgr_get_create_seq_mgr(
                        storage_mgr, env);
            sandesha2_create_seq_mgr_insert(create_seq_mgr, env, create_seq_bean);
            
            out_seq_bean = sandesha2_seq_property_bean_create(env);
            sandesha2_seq_property_bean_set_name(out_seq_bean, env, 
                SANDESHA2_SEQ_PROP_OUT_SEQ_ID);
            sandesha2_seq_property_bean_set_seq_id(out_seq_bean, env, 
                int_seq_id);
            sandesha2_seq_property_bean_set_value(out_seq_bean, env, 
                offer_seq_id);
            sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, 
                out_seq_bean);
            int_seq_bean = sandesha2_seq_property_bean_create(env);
            sandesha2_seq_property_bean_set_name(int_seq_bean, env, 
                SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
            sandesha2_seq_property_bean_set_seq_id(int_seq_bean, env, 
                offer_seq_id);
            sandesha2_seq_property_bean_set_value(int_seq_bean, env, 
                int_seq_id);
            sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, 
                int_seq_bean);
        }
        else
        {
            sandesha2_create_seq_res_set_accept(create_seq_res_part, env, NULL);
            sandesha2_msg_ctx_add_soap_envelope(create_seq_res_msg, env);
        }
    }
    acks_to = sandesha2_address_get_epr(sandesha2_acks_to_get_address(
        sandesha2_create_seq_get_acks_to(create_seq_part, env), 
        env), env);
    if(!acks_to || !axis2_endpoint_ref_get_address(acks_to, 
                    env))
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]Acks to is null");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_INVALID_EPR, 
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    acks_to_bean = sandesha2_seq_property_bean_create_with_data(env, 
        new_seq_id, SANDESHA2_SEQ_PROP_ACKS_TO_EPR, 
        (axis2_char_t*)axis2_endpoint_ref_get_address(acks_to, env));
    sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, acks_to_bean);
    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    axis2_op_ctx_set_response_written(op_ctx, env, AXIS2_TRUE);
    sandesha2_seq_mgr_update_last_activated_time(env, new_seq_id, 
        storage_mgr);
    engine = axis2_engine_create(env, conf_ctx);
    axis2_engine_send(engine, env, out_msg_ctx);
    to_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
        new_seq_id, SANDESHA2_SEQ_PROP_TO_EPR);
    if(!to_bean)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]wsa:To is not set");
        return AXIS2_FAILURE;
    }
    to_epr = axis2_endpoint_ref_create(env, 
        sandesha2_seq_property_bean_get_value(to_bean, env));
    addr_ns_uri = sandesha2_utils_get_seq_property(env, new_seq_id, 
        SANDESHA2_SEQ_PROP_ADDRESSING_NAMESPACE_VALUE,
        storage_mgr);
    anon_uri = sandesha2_spec_specific_consts_get_anon_uri(env, addr_ns_uri);
    
    op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if(sandesha2_utils_is_anon_uri(env, axis2_endpoint_ref_get_address(to_epr, 
        env)))
    {
        axis2_op_ctx_set_response_written(op_ctx, env, AXIS2_TRUE);
    }
    else
    {
        axis2_op_ctx_set_response_written(op_ctx, env, AXIS2_FALSE);
    }
    
    sandesha2_msg_ctx_set_paused(rm_msg_ctx, env, AXIS2_TRUE);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
            "[sandesha2] Exit: sandesha2_create_seq_msg_processor_process_in_msg");
    return AXIS2_SUCCESS;
    
}
    
static axis2_status_t AXIS2_CALL 
sandesha2_create_seq_msg_processor_process_out_msg(
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    
    /* TODO
     * adding the SANDESHA_LISTENER
     */
    return AXIS2_SUCCESS;
}


static axis2_bool_t AXIS2_CALL 
sandesha2_create_seq_msg_processor_offer_accepted(
    const axutil_env_t *env, 
    axis2_char_t *seq_id,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_create_seq_mgr_t *create_seq_mgr = NULL;
    sandesha2_create_seq_bean_t *find_bean = NULL;
    axutil_array_list_t *list = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FALSE);
    
    create_seq_mgr = sandesha2_storage_mgr_get_create_seq_mgr(storage_mgr, env);
    find_bean = sandesha2_create_seq_bean_create_with_data(env, NULL, NULL, 
                        seq_id);
    list = sandesha2_create_seq_mgr_find(create_seq_mgr, env, find_bean);
    /* Single char offerings are not accepted */
    if(1 >= axutil_strlen(seq_id))
        return AXIS2_FALSE;
        
    if(NULL != list && 0 < axutil_array_list_size(list, env))
        return AXIS2_FALSE;
        
    return AXIS2_TRUE;
}

