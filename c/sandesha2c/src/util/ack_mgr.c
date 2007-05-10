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
 
#include <sandesha2_utils.h>
#include <sandesha2_ack_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_property_bean.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_ack_range.h>
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_sender_mgr.h>
#include <sandesha2_sender_bean.h>
#include <axutil_string.h>
#include <axutil_uuid_gen.h>
#include <axis2_addr.h>
#include <axutil_property.h>
#include <axutil_array_list.h>
#include <sandesha2_msg_init.h>
#include <sandesha2_seq_ack.h>
#include <axis2_op.h>
#include <sandesha2_msg_creator.h>
#include <axis2_transport_out_desc.h>

AXIS2_EXTERN sandesha2_msg_ctx_t *AXIS2_CALL
sandesha2_ack_mgr_generate_ack_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *ref_rm_msg,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr)
{
    axis2_msg_ctx_t *ref_msg = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *acks_to_bean = NULL;
    axis2_endpoint_ref_t *acks_to = NULL;
    axis2_char_t *acks_to_str = NULL;
    axis2_op_t *ack_op = NULL;
    axis2_op_t *ref_op = NULL;
    axis2_msg_ctx_t *ack_msg_ctx = NULL;
    axis2_char_t *addr_ns_uri = NULL;
    axutil_property_t *property = NULL;
    sandesha2_msg_ctx_t *ack_rm_msg = NULL;
    axiom_soap_envelope_t *soap_env = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, seq_id, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, NULL);
    
    ref_msg = sandesha2_msg_ctx_get_msg_ctx(ref_rm_msg, env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(ref_msg, env);
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr,
        env);
    acks_to_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env,
        seq_id, SANDESHA2_SEQ_PROP_ACKS_TO_EPR);
    if(acks_to_bean)
        acks_to = axis2_endpoint_ref_create(env, 
            sandesha2_seq_property_bean_get_value(acks_to_bean, 
                env));
    if(acks_to)
        acks_to_str = (axis2_char_t*)axis2_endpoint_ref_get_address(acks_to, env);
    if(!acks_to_str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Invalid epr");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_INVALID_EPR, AXIS2_FAILURE);
        return NULL;
    }
    ack_op = axis2_op_create(env);
    axis2_op_set_msg_exchange_pattern(ack_op, env, AXIS2_MEP_URI_OUT_ONLY);
    
    ref_op = axis2_msg_ctx_get_op(ref_msg, env);
    if(ref_op)
    {
        axutil_array_list_t *out_flow = NULL;
        axutil_array_list_t *out_fault_flow = NULL;
        axutil_array_list_t *new_out_flow = NULL;
        axutil_array_list_t *new_out_fault_flow = NULL;
        out_flow = axis2_op_get_out_flow(ref_op, env);
        new_out_flow = axis2_phases_info_copy_flow(env, out_flow);
        out_fault_flow = axis2_op_get_fault_out_flow(ref_op, env);
        new_out_fault_flow = axis2_phases_info_copy_flow(env, out_fault_flow);
        if(new_out_flow)
            axis2_op_set_out_flow(ack_op, env, new_out_flow);
        if(new_out_fault_flow)
            axis2_op_set_fault_out_flow(ack_op, env, new_out_fault_flow);
    }
    ack_msg_ctx = sandesha2_utils_create_new_related_msg_ctx(env, ref_rm_msg,
        ack_op);
    
    property = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
        AXIS2_FALSE, 0, AXIS2_VALUE_TRUE);
    if(property)
    {
        axis2_msg_ctx_set_property(ack_msg_ctx, env, 
            SANDESHA2_APPLICATION_PROCESSING_DONE, property);
        property = NULL;
    }
    ack_rm_msg = sandesha2_msg_init_init_msg(env, ack_msg_ctx);
    sandesha2_msg_ctx_set_rm_ns_val(ack_rm_msg, env, 
        sandesha2_msg_ctx_get_rm_ns_val(ref_rm_msg, env));
    axis2_msg_ctx_set_wsa_message_id(ack_msg_ctx, env, axutil_uuid_gen(env));
    soap_env = axiom_soap_envelope_create_default_soap_envelope(env, 
        sandesha2_utils_get_soap_version(env, 
        axis2_msg_ctx_get_soap_envelope(ref_msg, env)));
    axis2_msg_ctx_set_soap_envelope(ack_msg_ctx, env, soap_env);
    axis2_msg_ctx_set_to(ack_msg_ctx, env, acks_to);
    /* Adding the sequence acknowledgement part */
    sandesha2_msg_creator_add_ack_msg(env, ack_rm_msg, seq_id, storage_mgr);
    axis2_msg_ctx_set_property(ack_msg_ctx, env, AXIS2_TRANSPORT_IN, NULL);
    addr_ns_uri = sandesha2_utils_get_seq_property(env, seq_id, 
        SANDESHA2_SEQ_PROP_ADDRESSING_NAMESPACE_VALUE, 
            storage_mgr);
    if(addr_ns_uri)
    {
        property = axis2_msg_ctx_get_property(ack_msg_ctx, env, AXIS2_WSA_VERSION);
        if(property)
        {
            axutil_property_set_value(property, env, addr_ns_uri);
        }
        else
        {
            property = axutil_property_create_with_args(env, 0, 0, 0, addr_ns_uri);
            axis2_msg_ctx_set_property(ack_msg_ctx, env, AXIS2_WSA_VERSION, property);
        }
    }
    if(sandesha2_utils_is_anon_uri(env, acks_to_str))
    {
        axis2_op_ctx_t *op_ctx = NULL;

        op_ctx = axis2_msg_ctx_get_op_ctx(ref_msg, env);
        if(!op_ctx)
        {
            axis2_op_t *op = axis2_op_create(env);
            axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_IN_OUT);
            op_ctx = axis2_op_ctx_create(env, op, NULL);
            axis2_msg_ctx_set_op(ref_msg, env, op);
            axis2_msg_ctx_set_op_ctx(ref_msg, env, op_ctx);            
        }
        axis2_op_ctx_set_response_written(op_ctx, env, AXIS2_TRUE);
        
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
            AXIS2_FALSE, 0, AXIS2_VALUE_TRUE);
        axis2_msg_ctx_set_property(ref_msg, env, SANDESHA2_ACK_WRITTEN, property);
        axis2_msg_ctx_set_server_side(ack_msg_ctx, env, AXIS2_TRUE);
        return ack_rm_msg;
    }
    else
    {
        sandesha2_sender_mgr_t *retrans_mgr = NULL;
        sandesha2_sender_bean_t *ack_bean = NULL;
        sandesha2_sender_bean_t *find_bean = NULL;
        axis2_char_t *key = NULL;
        sandesha2_property_bean_t *ack_int_bean = NULL;
        long ack_interval = -1;
        long time_to_send = -1;
        axutil_array_list_t *bean_list = NULL;
        int i = 0;
        axis2_transport_out_desc_t *orig_trans_out = NULL;
        axis2_transport_out_desc_t *trans_out = NULL;
        sandesha2_msg_ctx_t *ret_rm_msg = NULL;
        
        retrans_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, env);
        key = axutil_uuid_gen(env);
        ack_bean = sandesha2_sender_bean_create(env);
        sandesha2_sender_bean_set_msg_ctx_ref_key(ack_bean, env, key);
        sandesha2_sender_bean_set_msg_id(ack_bean, env, 
            (axis2_char_t*)axis2_msg_ctx_get_wsa_message_id(
                ack_msg_ctx, env));
        sandesha2_sender_bean_set_resend(ack_bean, env, AXIS2_FALSE);
        sandesha2_sender_bean_set_seq_id(ack_bean, env, seq_id);
        sandesha2_sender_bean_set_send(ack_bean, env, AXIS2_TRUE);
        sandesha2_sender_bean_set_seq_id(ack_bean, env, seq_id);
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
            AXIS2_FALSE, 0, AXIS2_VALUE_FALSE);
        axis2_msg_ctx_set_property(ack_msg_ctx, env, 
            SANDESHA2_QUALIFIED_FOR_SENDING, property);
        sandesha2_sender_bean_set_msg_type(ack_bean, env, 
            SANDESHA2_MSG_TYPE_ACK);

        /* Avoid retrieving property bean from operation until it is availbale */
        /*ack_int_bean = sandesha2_utils_get_property_bean_from_op(env,
            axis2_msg_ctx_get_op(ref_msg, env));*/
        ack_int_bean = sandesha2_utils_get_property_bean(env,
            axis2_conf_ctx_get_conf(conf_ctx, env));
        ack_interval = sandesha2_property_bean_get_ack_interval(ack_int_bean, 
            env);
        time_to_send = sandesha2_utils_get_current_time_in_millis(env) + 
            ack_interval;
        find_bean = sandesha2_sender_bean_create(env);
        sandesha2_sender_bean_set_msg_type(find_bean, env, 
            SANDESHA2_MSG_TYPE_ACK);
        sandesha2_sender_bean_set_send(find_bean, env, AXIS2_TRUE);
        sandesha2_sender_bean_set_resend(find_bean, env, AXIS2_FALSE);
        bean_list = sandesha2_sender_mgr_find_by_sender_bean(retrans_mgr, env, 
            find_bean);
        
        for(i = 0; i < axutil_array_list_size(bean_list, env); i++)
        {
            sandesha2_sender_bean_t *old_ack_bean = NULL;
            old_ack_bean = axutil_array_list_get(bean_list, env, i);
            time_to_send = sandesha2_sender_bean_get_time_to_send(old_ack_bean,
                env);
            sandesha2_sender_mgr_remove(retrans_mgr, env, 
                sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) 
                    old_ack_bean, env));
            sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, 
                sandesha2_sender_bean_get_msg_ctx_ref_key(
                    old_ack_bean, env));
        }
        sandesha2_sender_bean_set_time_to_send(ack_bean, env, time_to_send);
        sandesha2_storage_mgr_store_msg_ctx(storage_mgr, env, key, ack_msg_ctx);
        sandesha2_sender_mgr_insert(retrans_mgr, env, ack_bean);
        
        orig_trans_out = axis2_msg_ctx_get_transport_out_desc(ack_msg_ctx, 
            env);
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_APPLICATION, 
            AXIS2_FALSE, axis2_transport_out_desc_free_void_arg, orig_trans_out);
        axis2_msg_ctx_set_property(ack_msg_ctx, env,
            SANDESHA2_ORIGINAL_TRANSPORT_OUT_DESC, property);
        
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
            AXIS2_FALSE, 0, AXIS2_VALUE_TRUE);
        axis2_msg_ctx_set_property(ack_msg_ctx, env, 
            SANDESHA2_SET_SEND_TO_TRUE, property);
                        
        property = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
            AXIS2_FALSE, 0, key);
        axis2_msg_ctx_set_property(ack_msg_ctx, env, 
            SANDESHA2_MESSAGE_STORE_KEY, property);
        
        trans_out = sandesha2_utils_get_transport_out(env);
        axis2_msg_ctx_set_transport_out_desc(ack_msg_ctx, env, trans_out);
        
        ret_rm_msg = sandesha2_msg_init_init_msg(env, ack_msg_ctx);
        sandesha2_utils_start_sender_for_seq(env, conf_ctx, seq_id);
        return ret_rm_msg;
    }
    return NULL;
}

/**
 * This is used to get the acked messages of a sequence. If this is an outgoing 
 * message the sequence_identifier should be the internal sequenceID.
 * 
 * @param sequence_identifier
 * @param out_going_msg
 * @return
 */
AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
sandesha2_ack_mgr_get_client_completed_msgs_list(
        const axutil_env_t *env,
        axis2_char_t *seq_id,
        sandesha2_seq_property_mgr_t *seq_prop_mgr)
{
    sandesha2_seq_property_bean_t *internal_seq_bean = NULL;
    axis2_char_t *internal_seq_id = NULL;
    sandesha2_seq_property_bean_t *completed_msgs_bean = NULL;
    axutil_array_list_t *completed_msg_list = NULL;
    
    /* First trying to get it from the internal sequence id.*/
    internal_seq_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
            seq_id, SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
    if(internal_seq_bean != NULL)
    {
        internal_seq_id = sandesha2_seq_property_bean_get_value(
                internal_seq_bean, env);
    }
    if(internal_seq_id != NULL)
    {
        completed_msgs_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, 
                env, internal_seq_id, 
                SANDESHA2_SEQ_PROP_CLIENT_COMPLETED_MESSAGES);
    }
    if(completed_msgs_bean == NULL)
    {
        completed_msgs_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, 
                env, seq_id, 
                SANDESHA2_SEQ_PROP_CLIENT_COMPLETED_MESSAGES);
    }
    if(completed_msgs_bean != NULL)
    {
        axis2_char_t *value = sandesha2_seq_property_bean_get_value(
            completed_msgs_bean, env);
        completed_msg_list = sandesha2_utils_get_array_list_from_string(env, value);
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2]completed_msgs_bean is NULL");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_COMPLETED_MSGS_BEAN_IS_NULL, 
            AXIS2_FAILURE);
        return NULL;
    }
    return completed_msg_list;
}
 
AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
sandesha2_ack_mgr_get_svr_completed_msgs_list(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    sandesha2_seq_property_mgr_t *seq_prop_mgr)
{
    sandesha2_seq_property_bean_t *completed_msgs_bean = NULL;
    axutil_array_list_t *completed_msg_list = NULL;
    
    completed_msgs_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, 
        env, seq_id, 
        SANDESHA2_SEQ_PROP_SERVER_COMPLETED_MESSAGES);
    if(completed_msgs_bean)
    {
        axis2_char_t *value = sandesha2_seq_property_bean_get_value(
            completed_msgs_bean, env);
        completed_msg_list = sandesha2_utils_get_array_list_from_string(env, value);
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2]completed_msgs_bean is NULL");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_COMPLETED_MSGS_BEAN_IS_NULL, 
            AXIS2_FAILURE);
        return NULL;
    }
    return completed_msg_list;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
sandesha2_ack_mgr_verify_seq_completion(
    const axutil_env_t *env,
    axutil_array_list_t *ack_ranges,
    long last_msg_no)
{
    axutil_hash_t *hash = NULL;
    axis2_char_t tmp[32];
    int i = 0;
    long start = 1;
    
    
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, ack_ranges, AXIS2_FALSE);
    
    hash = axutil_hash_make(env);
    for(i  = 0; i< axutil_array_list_size(ack_ranges, env); i++)
    {
        sandesha2_ack_range_t *ack_range = NULL;
        
        ack_range = axutil_array_list_get(ack_ranges, env, i);
        sprintf(tmp, "%ld", sandesha2_ack_range_get_lower_value(ack_range, env));
        axutil_hash_set(hash, tmp, AXIS2_HASH_KEY_STRING, ack_range);
    }
    
    while(AXIS2_TRUE)
    {
        sandesha2_ack_range_t *ack_range = NULL;
        sprintf(tmp, "%ld", start);
        ack_range = axutil_hash_get(hash, tmp, AXIS2_HASH_KEY_STRING);
        
        if(!ack_range)
        {
            break;
        }
        if(sandesha2_ack_range_get_upper_value(ack_range, env) >= last_msg_no)
            return AXIS2_TRUE;
        start = sandesha2_ack_range_get_upper_value(ack_range, env) + 1;        
    }
    return AXIS2_FALSE;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_ack_mgr_piggyback_acks_if_present(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_mgr)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    sandesha2_sender_mgr_t *retrans_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_sender_bean_t *find_bean = NULL;
    axis2_char_t *to_str = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_endpoint_ref_t *to = NULL;
    axutil_array_list_t *found_list = NULL;
    int i = 0;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    retrans_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, env);
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    
    find_bean = sandesha2_sender_bean_create(env);
    sandesha2_sender_bean_set_msg_type(find_bean, env, SANDESHA2_MSG_TYPE_ACK);
    sandesha2_sender_bean_set_send(find_bean, env, AXIS2_TRUE);
    sandesha2_sender_bean_set_resend(find_bean, env, AXIS2_FALSE);

    to = sandesha2_msg_ctx_get_to(rm_msg_ctx, env);
    if(to)
        to_str = (axis2_char_t*)axis2_endpoint_ref_get_address(to, env);
                        
    found_list = sandesha2_sender_mgr_find_by_sender_bean(retrans_mgr, env, 
        find_bean);
    for(i = 0; i < axutil_array_list_size(found_list, env); i++)
    {
        sandesha2_sender_bean_t *sender_bean = NULL;
        long timenow = 0;
        
        timenow = sandesha2_utils_get_current_time_in_millis(env);
        sender_bean = axutil_array_list_get(found_list, env, i);
        
        if(sandesha2_sender_bean_get_time_to_send(sender_bean, env) > timenow)
        {
            axis2_msg_ctx_t *msg_ctx1 = NULL;
            axis2_char_t *to = NULL;
            sandesha2_msg_ctx_t *ack_rm_msg = NULL;
            sandesha2_iom_rm_part_t *seq_ack = NULL;
            axis2_char_t *msg_ctx_ref_key = NULL;
            
            msg_ctx_ref_key = sandesha2_sender_bean_get_msg_ctx_ref_key(
                sender_bean, env);
            msg_ctx1 = sandesha2_storage_mgr_retrieve_msg_ctx(storage_mgr, env,
                msg_ctx_ref_key, conf_ctx, AXIS2_FALSE);
            to = (axis2_char_t*)axis2_endpoint_ref_get_address(
                axis2_msg_ctx_get_to(msg_ctx1, env), env);
            if(0 == axutil_strcmp(to, to_str))
                continue; 
            sandesha2_sender_mgr_remove(retrans_mgr, env, 
                sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) 
                    sender_bean, env));
            sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, 
                msg_ctx_ref_key);
            ack_rm_msg = sandesha2_msg_init_init_msg(env, msg_ctx1);
            if(SANDESHA2_MSG_TYPE_ACK != sandesha2_msg_ctx_get_msg_type(ack_rm_msg, 
                env))
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Invalid"
                    " ack message entry");
                return AXIS2_FAILURE;
            }
            seq_ack = (sandesha2_iom_rm_part_t *)sandesha2_msg_ctx_get_msg_part(
                ack_rm_msg, env, SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT);
            sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT, seq_ack);
            sandesha2_msg_ctx_add_soap_envelope(rm_msg_ctx, env);
            break;
        }
    }
    return AXIS2_SUCCESS;
}

