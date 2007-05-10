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
#include <sandesha2_make_connection_msg_processor.h>
#include <sandesha2_make_connection.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_fault_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_address.h>
#include <sandesha2_identifier.h>
#include <sandesha2_sender_worker.h>
#include <sandesha2_msg_pending.h>
#include <sandesha2_msg_init.h>
#include <sandesha2_sender_mgr.h>
#include <sandesha2_sender_bean.h>
#include <sandesha2_terminate_seq.h>
#include <sandesha2_terminate_seq_res.h>
#include <sandesha2_seq.h>
#include <axis2_msg_ctx.h>
#include <axutil_string.h>
#include <axis2_engine.h>
#include <axiom_soap_const.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_core_utils.h>
#include <axutil_uuid_gen.h>
#include <axis2_endpoint_ref.h>
#include <axis2_op_ctx.h>
#include <axis2_transport_out_desc.h>
#include <axis2_http_transport.h>
#include <axis2_http_out_transport_info.h>
#include <axutil_rand.h>
#include <sandesha2_msg_retrans_adjuster.h>
#include <sandesha2_terminate_mgr.h>


/** 
 * @brief Make Connection Message Processor struct impl
 *	Sandesha2 Make Connection Msg Processor
 */
typedef struct sandesha2_make_connection_msg_processor_impl 
                        sandesha2_make_connection_msg_processor_impl_t;  
  
struct sandesha2_make_connection_msg_processor_impl
{
	sandesha2_msg_processor_t msg_processor;
};

#define SANDESHA2_INTF_TO_IMPL(msg_proc) \
    ((sandesha2_make_connection_msg_processor_impl_t *)(msg_proc))

/***************************** Function headers *******************************/
static axis2_status_t AXIS2_CALL 
sandesha2_make_connection_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx);

static void 
add_msg_pending_header(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *return_msg_ctx,
    axis2_bool_t pending);
    
static void
set_transport_properties(
    const axutil_env_t *env,
    axis2_msg_ctx_t *return_msg_ctx,
    sandesha2_msg_ctx_t *make_conn_msg_ctx);

static axis2_status_t AXIS2_CALL 
sandesha2_make_connection_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env);								

/***************************** End of function headers ************************/

AXIS2_EXTERN sandesha2_msg_processor_t* AXIS2_CALL
sandesha2_make_connection_msg_processor_create(
    const axutil_env_t *env)
{
    sandesha2_make_connection_msg_processor_impl_t *msg_proc_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
              
    msg_proc_impl =  (sandesha2_make_connection_msg_processor_impl_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof(sandesha2_make_connection_msg_processor_impl_t));
	
    if(!msg_proc_impl)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops = AXIS2_MALLOC(env->allocator,
        sizeof(sandesha2_msg_processor_ops_t));
    if(!msg_proc_impl->msg_processor.ops)
	{
		sandesha2_make_connection_msg_processor_free((sandesha2_msg_processor_t*)
                         msg_proc_impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    
    msg_proc_impl->msg_processor.ops->process_in_msg = 
                        sandesha2_make_connection_msg_processor_process_in_msg;
    msg_proc_impl->msg_processor.ops->free = sandesha2_make_connection_msg_processor_free;
                        
	return &(msg_proc_impl->msg_processor);
}


static axis2_status_t AXIS2_CALL 
sandesha2_make_connection_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
	const axutil_env_t *env)
{
    sandesha2_make_connection_msg_processor_impl_t *msg_proc_impl = NULL;
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    msg_proc_impl = SANDESHA2_INTF_TO_IMPL(msg_processor);
    
    if(msg_processor->ops)
        AXIS2_FREE(env->allocator, msg_processor->ops);
    
	AXIS2_FREE(env->allocator, SANDESHA2_INTF_TO_IMPL(msg_processor));
	return AXIS2_SUCCESS;
}

/**
 * Prosesses incoming MakeConnection request messages.
 * A message is selected by the set of SenderBeans that are waiting to be sent.
 * This is processed using a SenderWorker.
 */
static axis2_status_t AXIS2_CALL 
sandesha2_make_connection_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    sandesha2_make_connection_t *make_conn = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_sender_mgr_t *sender_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_sender_bean_t *find_sender_bean = NULL;
    sandesha2_sender_bean_t *sender_bean = NULL;
    sandesha2_sender_bean_t *bean1 = NULL;
    sandesha2_address_t *address = NULL;
    sandesha2_identifier_t *identifier = NULL;
    sandesha2_msg_ctx_t *return_rm_msg_ctx = NULL;
    axutil_property_t *property = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_msg_ctx_t *return_msg_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axutil_array_list_t *retrans_list = NULL;
    axis2_bool_t pending = AXIS2_FALSE;
    axis2_transport_out_desc_t *transport_out = NULL;
    axis2_char_t *msg_storage_key = NULL;
    axis2_char_t *seq_id = NULL;
    axis2_char_t *internal_seq_id = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_char_t *msg_id = NULL;
    axis2_transport_sender_t *transport_sender = NULL;
    int size = 0, item_to_pick = -1, item = 0;
    int msg_type = -1;
    axis2_bool_t continue_sending = AXIS2_TRUE;
    axis2_char_t *qualified_for_sending = NULL;
    sandesha2_property_bean_t *prop_bean = NULL;
    sandesha2_seq_property_bean_t *int_seq_bean = NULL;
    axutil_array_list_t *msgs_not_to_send = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    AXIS2_LOG_INFO(env->log, "[sandesha2] sandesha2_make_connection_msg_" \
            "processor_process_in_msg .........");

    make_conn = (sandesha2_make_connection_t*)
        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_MAKE_CONNECTION);
    if(!make_conn)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]"
            " make_connection part is null");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_REQD_MSG_PART_MISSING,
                        AXIS2_FAILURE);
        return AXIS2_FAILURE;        
    }
    address = sandesha2_make_connection_get_address(make_conn, env);
    identifier = sandesha2_make_connection_get_identifier(make_conn, env);
    if(identifier)
        seq_id = sandesha2_identifier_get_identifier(identifier, env);
    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    if(msg_ctx)
        conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if(conf_ctx)
        storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, 
                        axis2_conf_ctx_get_conf(conf_ctx, env));
    if(storage_mgr)
    {
        sender_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, env);
        seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, 
            env);
    }
    int_seq_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
        seq_id, SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
    if(int_seq_bean)
        internal_seq_id = sandesha2_seq_property_bean_get_value(int_seq_bean, env);
    /* Selecting the set of sender beans that suit the given criteria */
    find_sender_bean = sandesha2_sender_bean_create(env);
    if(find_sender_bean)
        sandesha2_sender_bean_set_send(find_sender_bean, env, AXIS2_TRUE);
    if(address)
    {
        axis2_endpoint_ref_t *epr = NULL;
        axis2_char_t *epr_address = NULL;
        epr = sandesha2_address_get_epr(address, env);
        if(epr)
            epr_address = (axis2_char_t *) axis2_endpoint_ref_get_address(epr, 
                env);
        if(epr_address)
            sandesha2_sender_bean_set_wsrm_anon_uri(find_sender_bean, env, 
                epr_address);
    }
    if(internal_seq_id)
        sandesha2_sender_bean_set_seq_id(find_sender_bean, env, internal_seq_id);
    /* Find the beans that go with the criteria of the passed sender bean */
    if(find_sender_bean)
    {
        retrans_list = axutil_array_list_create(env, 0);
        if(!retrans_list)
            return AXIS2_FAILURE;
        retrans_list = sandesha2_sender_mgr_find_by_sender_bean(sender_mgr, 
                env, find_sender_bean);
    }
    /* Selecting a bean to send randomly. TODO - Should use a better mechanism */
    if(retrans_list)
        size = axutil_array_list_size(retrans_list, env);
    if(size > 0)
    {
       unsigned int rand_var = axutil_rand_get_seed_value_based_on_time(env);
       item_to_pick = axutil_rand_with_range(&rand_var, 0, size);
       item_to_pick--;
    }
    if(size > 1)
        pending = AXIS2_TRUE; /*There are more than one message to be delivered 
                               using the makeConnection. So the MessagePending 
                               header should have value true;*/

    for(item = 0; item < size; item++)
    {
        sender_bean = (sandesha2_sender_bean_t *) axutil_array_list_get(
                retrans_list, env, item);
        if(item == item_to_pick)
            break;
    }
    if(!sender_bean)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2]sender_bean is NULL. So returning");
        return AXIS2_SUCCESS;
    }
    transport_out = axis2_msg_ctx_get_transport_out_desc(msg_ctx, env);
    if(!transport_out)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]"
            " Cannot infer transport for the make connection request");
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_CANNOT_INFER_TRANSPORT, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    msg_storage_key = sandesha2_sender_bean_get_msg_ctx_ref_key(sender_bean, 
        env);
    return_msg_ctx = sandesha2_storage_mgr_retrieve_msg_ctx(storage_mgr, env, 
        msg_storage_key, conf_ctx, AXIS2_TRUE);
    return_rm_msg_ctx = sandesha2_msg_init_init_msg(env, return_msg_ctx);
    add_msg_pending_header(env, return_rm_msg_ctx, pending);
    set_transport_properties(env, return_msg_ctx, rm_msg_ctx);
    /* Setting that the response gets written. This will be used by transports.*/
    if(msg_ctx)
    {
        op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        axis2_op_ctx_set_response_written(op_ctx, env, AXIS2_TRUE);
    }
    /*
     *running the make_connection through a sender_worker.
     *This will allow Sandesha2 to consider both of following scenarios equally.
     * 1. A message being sent by the Sender thread.
     * 2. A message being sent as a reply to an make_connection.
     */
    msg_id = sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) 
        sender_bean, env);
    /*if(msg_id)
    {
        sandesha2_sender_worker_t *sender_worker = NULL;
        sender_worker = sandesha2_sender_worker_create(env, conf_ctx, msg_id);
        sender_worker = sandesha2_sender_worker_create_with_msg_ctx(env, 
            conf_ctx, msg_id, return_msg_ctx);
        sandesha2_sender_worker_set_transport_out(sender_worker, env, transport_out); 
        sandesha2_sender_worker_run(sender_worker, env);
    }*/
    continue_sending = sandesha2_msg_retrans_adjuster_adjust_retrans(env,
        sender_bean, conf_ctx, storage_mgr);
    if(!continue_sending)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Do not continue sending the message as response to"\
                "MakeConnection message");
        return AXIS2_SUCCESS;
    }
    
    property = axis2_msg_ctx_get_property(msg_ctx, env, 
        SANDESHA2_QUALIFIED_FOR_SENDING);
    if(property)
        qualified_for_sending = axutil_property_get_value(property, env);
    if(qualified_for_sending && 0 != axutil_strcmp(
        qualified_for_sending, AXIS2_VALUE_TRUE))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Message is not qualified for sending as reply to "\
                "MakeConnection message");
        return AXIS2_SUCCESS;
    }
    
    /* Avoid retrieving property bean from operation until it is availbale */
    /*prop_bean = sandesha2_utils_get_property_bean_from_op(env, 
        axis2_msg_ctx_get_op(return_msg_ctx, env));*/
    prop_bean = sandesha2_utils_get_property_bean(env, 
        axis2_conf_ctx_get_conf(conf_ctx, env));
    if(prop_bean)
        msgs_not_to_send = sandesha2_property_bean_get_msg_types_to_drop(
            prop_bean, env);
    if(msgs_not_to_send)
    {
        int j = 0;
        axis2_bool_t continue_sending = AXIS2_FALSE;

        for(j = 0; j < axutil_array_list_size(msgs_not_to_send, env); j++)
        {
            axis2_char_t *value = NULL;
            int int_val = -1;
            int msg_type = -1;
            
            value = axutil_array_list_get(msgs_not_to_send, env, j);
            int_val = atoi(value);
            msg_type = sandesha2_msg_ctx_get_msg_type(return_rm_msg_ctx, env);
            if(msg_type == int_val)
                continue_sending = AXIS2_TRUE;
        }
        if(continue_sending)
        {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Continue "\
                "Sending is true. So returning from make_connection_msg_processor");
            return AXIS2_SUCCESS;
        }
    }
    msg_type = sandesha2_msg_ctx_get_msg_type(return_rm_msg_ctx, env);
    if(msg_type == SANDESHA2_MSG_TYPE_APPLICATION)
    {
        sandesha2_seq_t *seq = NULL;
        axis2_char_t *seq_id = NULL;
        sandesha2_identifier_t *identifier = NULL;
        
        seq = (sandesha2_seq_t*) sandesha2_msg_ctx_get_msg_part(return_rm_msg_ctx, 
            env, SANDESHA2_MSG_PART_SEQ);
        identifier = sandesha2_seq_get_identifier(seq, env);
        seq_id = sandesha2_identifier_get_identifier(identifier, env);
    }

    transport_sender = axis2_transport_out_desc_get_sender(transport_out, env);
    AXIS2_TRANSPORT_SENDER_INVOKE(transport_sender, env, return_msg_ctx);
    bean1 = sandesha2_sender_mgr_retrieve(sender_mgr, env, msg_id);
    if(bean1)
    {
        axis2_bool_t resend = AXIS2_FALSE;
        
        resend = sandesha2_sender_bean_is_resend(sender_bean, env);
        if(resend)
        {
            sandesha2_sender_bean_set_sent_count(bean1, env, 
                sandesha2_sender_bean_get_sent_count(sender_bean, env));
            sandesha2_sender_bean_set_time_to_send(bean1, env, 
                sandesha2_sender_bean_get_time_to_send(sender_bean, env));
            sandesha2_sender_mgr_update(sender_mgr, env, bean1);
        }
        else
        {
            axis2_char_t *msg_stored_key = NULL;
            
            msg_id = sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) 
                bean1, env);
            sandesha2_sender_mgr_remove(sender_mgr, env, msg_id);
            /* Removing the message from the storage */
            msg_stored_key = sandesha2_sender_bean_get_msg_ctx_ref_key(
                bean1, env);
            sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, 
                msg_stored_key);
        }
    }
    msg_type = sandesha2_msg_ctx_get_msg_type(return_rm_msg_ctx, env);
    if(SANDESHA2_MSG_TYPE_TERMINATE_SEQ == msg_type)
    {
        sandesha2_terminate_seq_t *terminate_seq = NULL;
        axis2_char_t *seq_id = NULL;
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_char_t *int_seq_id = NULL;
        
        terminate_seq = (sandesha2_terminate_seq_t*)
            sandesha2_msg_ctx_get_msg_part(return_rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_TERMINATE_SEQ);
        seq_id = sandesha2_identifier_get_identifier(
            sandesha2_terminate_seq_get_identifier(terminate_seq, 
                env), env);
        conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        int_seq_id = sandesha2_utils_get_seq_property(env, seq_id, 
            SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID, storage_mgr);
        sandesha2_terminate_mgr_terminate_sending_side(env, conf_ctx,
            int_seq_id, axis2_msg_ctx_get_server_side(msg_ctx, env), 
                storage_mgr);
    }
    axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
    AXIS2_LOG_INFO(env->log, "[sandesha2] EXIT sandesha2_make_connection_msg_" \
            "processor_process_in_msg .........");
    return AXIS2_SUCCESS;
}

static void 
add_msg_pending_header(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *return_msg_ctx,
    axis2_bool_t pending)
{
    axis2_char_t *rm_ns = NULL;
    sandesha2_msg_pending_t *msg_pending = NULL; 
    axiom_soap_envelope_t *soap_env = NULL; 
    if(return_msg_ctx)
    {
        soap_env = sandesha2_msg_ctx_get_soap_envelope(
            return_msg_ctx, env);
        rm_ns = sandesha2_msg_ctx_get_rm_ns_val(return_msg_ctx, env);
        msg_pending = sandesha2_msg_pending_create(env, rm_ns);
    }
    if(msg_pending)
    {
        sandesha2_msg_pending_set_pending(msg_pending, env, pending);
        sandesha2_msg_pending_to_soap_envelope((sandesha2_iom_rm_part_t *)
            msg_pending, env, soap_env);
    }
}

static void
set_transport_properties(
    const axutil_env_t *env,
    axis2_msg_ctx_t *return_msg_ctx,
    sandesha2_msg_ctx_t *make_conn_msg_ctx)
{
    axutil_stream_t *out_stream = NULL;
    if(make_conn_msg_ctx && return_msg_ctx)
    {
        axis2_http_out_transport_info_t *out_info = NULL;
        axis2_http_out_transport_info_t *temp_out_info = NULL;
        out_stream = sandesha2_msg_ctx_get_transport_out_stream(make_conn_msg_ctx, 
            env);
        axis2_msg_ctx_set_transport_out_stream(return_msg_ctx, env, out_stream);
        temp_out_info = (axis2_http_out_transport_info_t *) 
            axis2_msg_ctx_get_http_out_transport_info(return_msg_ctx, env);
        if(!temp_out_info)
        {
            out_info = (axis2_http_out_transport_info_t *) 
                sandesha2_msg_ctx_get_http_out_transport_info(make_conn_msg_ctx, env);
            axis2_msg_ctx_set_http_out_transport_info(return_msg_ctx, env, out_info);
        }
    }
}

