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
#include <sandesha2_fault_mgr.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_create_seq_mgr.h>
#include <sandesha2_next_msg_mgr.h>
#include <sandesha2_constants.h>
#include <axutil_hash.h>
#include <axis2_core_utils.h>
#include <axiom_soap_const.h>
#include <sandesha2_iom_rm_part.h>
#include <sandesha2_create_seq.h>
#include <sandesha2_seq_ack.h>
#include <sandesha2_seq.h>
#include <sandesha2_identifier.h>
#include <sandesha2_msg_number.h>
#include <sandesha2_utils.h>
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_msg_init.h>
#include <stdio.h>
#include <string.h>

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_create_seq_refused (
    const axutil_env_t *env,
    axis2_msg_ctx_t *create_seq_msg,
    sandesha2_storage_mgr_t *storage_man)
{
    sandesha2_msg_ctx_t *rm_msg_ctx = NULL;
    sandesha2_create_seq_t *create_seq = NULL;
    axis2_bool_t refuse_seq = AXIS2_FALSE;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, create_seq_msg, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_man, NULL);
    
    rm_msg_ctx = sandesha2_msg_init_init_msg(env, create_seq_msg);
    create_seq = (sandesha2_create_seq_t*)sandesha2_msg_ctx_get_msg_part(
                        rm_msg_ctx, env, SANDESHA2_MSG_PART_CREATE_SEQ);
    
    if(NULL == create_seq)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_REQD_MSG_PART_MISSING, 
                        AXIS2_FAILURE);
        return NULL;
    }
    if(AXIS2_TRUE == refuse_seq)
    {
        sandesha2_fault_data_t *fault_data = NULL;
        fault_data = sandesha2_fault_data_create(env);
        sandesha2_fault_data_set_type(fault_data, env, 
                        SANDESHA2_SOAP_FAULT_TYPE_CREATE_SEQ_REFUSED);
        if(SANDESHA2_SOAP_VERSION_1_1 == sandesha2_utils_get_soap_version(env, 
                        sandesha2_msg_ctx_get_soap_envelope(rm_msg_ctx, env)))
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP11_FAULT_CODE_SENDER);
        else
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP12_FAULT_CODE_SENDER);
        sandesha2_fault_data_set_sub_code(fault_data, env, 
                        SANDESHA2_SOAP_FAULT_SUBCODE_CREATE_SEQ_REFUSED);
        sandesha2_fault_data_set_reason(fault_data, env, "");
        return sandesha2_fault_mgr_get_fault(env, rm_msg_ctx,
                        fault_data, sandesha2_msg_ctx_get_addr_ns_val(rm_msg_ctx,
                        env), storage_man);
    }
    return NULL;
}
            
sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_last_msg_num_exceeded(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *app_rm_msg,
    sandesha2_storage_mgr_t *storage_man)
{
    sandesha2_seq_t *sequence = NULL;
    long msg_num = -1;
    axis2_char_t *seq_id = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *last_msg_bean = NULL;
    axis2_bool_t exceeded = AXIS2_FALSE;
    axis2_char_t reason[256];
        
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, app_rm_msg, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_man, NULL);
    
    sequence = (sandesha2_seq_t*)sandesha2_msg_ctx_get_msg_part(
                        app_rm_msg, env, SANDESHA2_MSG_PART_SEQ);
    msg_num = SANDESHA2_MSG_NUMBER_GET_MSG_NUM(sandesha2_seq_get_msg_num(
                        sequence, env), env);
    seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_seq_get_identifier(sequence, env), env);
                        
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
                        storage_man, env);
    last_msg_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr,
                        env, seq_id, SANDESHA2_SEQ_PROP_LAST_OUT_MESSAGE_NO);
    if(NULL != last_msg_bean)
    {
        long last_msg_no = -1;
        last_msg_no = atol(sandesha2_seq_property_bean_get_value(last_msg_bean,
                        env));
        if(msg_num > last_msg_no)
        {
            exceeded = AXIS2_TRUE;
            sprintf(reason, "The message number of the message %ld exceeded the"
                        " last message number %ld which was mentioned as last"
                        " message in a previosly received application message",
                        msg_num, last_msg_no);
        }
    }
    if(exceeded)
    {
        sandesha2_fault_data_t *fault_data = NULL;
        fault_data = sandesha2_fault_data_create(env);
        sandesha2_fault_data_set_type(fault_data, env, 
                        SANDESHA2_SOAP_FAULT_TYPE_LAST_MESSAGE_NO_EXCEEDED);
        if(SANDESHA2_SOAP_VERSION_1_1 == sandesha2_utils_get_soap_version(env, 
                        sandesha2_msg_ctx_get_soap_envelope(app_rm_msg, env)))
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP11_FAULT_CODE_SENDER);
        else
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP12_FAULT_CODE_SENDER);
        sandesha2_fault_data_set_sub_code(fault_data, env, 
                        SANDESHA2_SOAP_FAULT_SUBCODE_LAST_MESSAGE_NO_EXCEEDED);
        sandesha2_fault_data_set_reason(fault_data, env, reason);
        return sandesha2_fault_mgr_get_fault(env, app_rm_msg,
                        fault_data, sandesha2_msg_ctx_get_addr_ns_val(app_rm_msg,
                        env), storage_man);
    }
    return NULL;    
}
            
sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_msg_num_rollover(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_man)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_man, NULL);
    
    return NULL;
}

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_unknown_seq(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_man)
{
    sandesha2_create_seq_mgr_t *create_seq_mgr = NULL;
    int type = -1;
    axis2_bool_t valid_seq = AXIS2_TRUE;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_man, NULL);
    AXIS2_PARAM_CHECK(env->error, seq_id, NULL);
    
    create_seq_mgr = sandesha2_storage_mgr_get_create_seq_mgr(
                        storage_man, env);
    type = sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, env);
    if(SANDESHA2_MSG_TYPE_ACK == type || 
        SANDESHA2_MSG_TYPE_CREATE_SEQ_RESPONSE == type ||
        SANDESHA2_MSG_TYPE_TERMINATE_SEQ_RESPONSE == type ||
        SANDESHA2_MSG_TYPE_CLOSE_SEQ_RESPONSE == type)
    {
        sandesha2_create_seq_bean_t *find_bean = NULL;
        axutil_array_list_t *list = NULL;
        find_bean = sandesha2_create_seq_bean_create(env);
        sandesha2_create_seq_bean_set_seq_id(find_bean, env, seq_id);
        list = sandesha2_create_seq_mgr_find(create_seq_mgr, env, 
                        find_bean);
        if(list)
        {
            if(0 == axutil_array_list_size(list, env))
                valid_seq = AXIS2_FALSE;
        }
        else
            valid_seq = AXIS2_FALSE;        
    }
    else
    {
        sandesha2_next_msg_mgr_t *next_msg_mgr = NULL;
        axutil_array_list_t *list = NULL;
        axis2_bool_t contains = AXIS2_FALSE;
        
        next_msg_mgr = sandesha2_storage_mgr_get_next_msg_mgr(
                        storage_man, env);
        list = sandesha2_next_msg_mgr_retrieve_all(next_msg_mgr, env);
        if(list)
        {
            int size = axutil_array_list_size(list, env);
            int i = 0;
			for(i = 0; i < size; i++)
            {
                sandesha2_next_msg_bean_t *next_bean = NULL;
                axis2_char_t *tmp_id = NULL;
                
                next_bean = axutil_array_list_get(list, env, i);
                tmp_id = sandesha2_next_msg_bean_get_seq_id(
                    (sandesha2_rm_bean_t *) next_bean, env);
                if(0 == axutil_strcmp(seq_id, tmp_id))
                {
                    contains = AXIS2_TRUE;
                    break;
                }
            }
        }
        if(contains)
            valid_seq = AXIS2_TRUE;
        else
            valid_seq = AXIS2_FALSE;
    }
    if(!valid_seq)
    {
        sandesha2_fault_data_t *fault_data = NULL;
        axis2_char_t *rm_ns_val = NULL;
        axiom_element_t *detail_ele = NULL;
        axiom_node_t *detail_node = NULL;
        axutil_qname_t *qname = NULL;
        
        fault_data = sandesha2_fault_data_create(env);
        rm_ns_val = sandesha2_msg_ctx_get_rm_ns_val(rm_msg_ctx, env);
        if(SANDESHA2_SOAP_VERSION_1_1 == sandesha2_utils_get_soap_version(env, 
                        sandesha2_msg_ctx_get_soap_envelope(rm_msg_ctx, env)))
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP11_FAULT_CODE_SENDER);
        else
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP12_FAULT_CODE_SENDER);
        sandesha2_fault_data_set_sub_code(fault_data, env, 
                        SANDESHA2_SOAP_FAULT_SUBCODE_UNKNOWN_SEQ);
        qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_IDENTIFIER,
                        rm_ns_val, SANDESHA2_WSRM_COMMON_NS_PREFIX_RM);
        detail_ele = axiom_element_create_with_qname(env, NULL, qname, 
                        &detail_node);
        sandesha2_fault_data_set_detail(fault_data, env, detail_node);
        sandesha2_fault_data_set_reason(fault_data, env, "A sequence with the" \
                        " given sequenceID has NOT been established");
        return sandesha2_fault_mgr_get_fault(env, rm_msg_ctx,
                        fault_data, sandesha2_msg_ctx_get_addr_ns_val(rm_msg_ctx,
                        env), storage_man);
    }
    return NULL;
}

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_invalid_ack(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *ack_rm_msg,
    sandesha2_storage_mgr_t *storage_man)
{
    axis2_bool_t invalid_ack = AXIS2_FALSE;
    axis2_char_t reason[256];
    sandesha2_seq_ack_t *seq_ack = NULL;
    axutil_array_list_t *ack_range_list = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, ack_rm_msg, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_man, NULL);
    
    if(SANDESHA2_MSG_TYPE_ACK != sandesha2_msg_ctx_get_msg_type(ack_rm_msg, env))
        return NULL;
    seq_ack = (sandesha2_seq_ack_t*)sandesha2_msg_ctx_get_msg_part(ack_rm_msg, 
                        env, SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT);
    ack_range_list = sandesha2_seq_ack_get_ack_range_list(seq_ack, env);
    if(ack_range_list)
    {
        int i = 0;
        for(i = 0; i < axutil_array_list_size(ack_range_list, env); i++)
        {
            sandesha2_ack_range_t *ack_range = NULL;
            long upper = -1;
            long lower = -1;
            ack_range = axutil_array_list_get(ack_range_list, env, i);
            lower = sandesha2_ack_range_get_lower_value(ack_range, env);
            upper = sandesha2_ack_range_get_upper_value(ack_range, env);
            if(lower > upper)
            {
                invalid_ack = AXIS2_TRUE;
                sprintf(reason, "The SequenceAcknowledgement is invalid. "
                        "Lower value is larger than upper value");
            }            
        }
    }
    if(invalid_ack)
    {
        sandesha2_fault_data_t *fault_data = NULL;
        axis2_char_t *rm_ns_val = NULL;
        axiom_element_t *detail_ele = NULL;
        axiom_node_t *detail_node = NULL;
        axiom_element_t *dummy_ele = NULL;
        axiom_node_t *dummy_node = NULL;
        axutil_qname_t *qname = NULL;
                
        fault_data = sandesha2_fault_data_create(env);
        rm_ns_val = sandesha2_msg_ctx_get_rm_ns_val(ack_rm_msg, env);
        if(SANDESHA2_SOAP_VERSION_1_1 == sandesha2_utils_get_soap_version(env, 
                        sandesha2_msg_ctx_get_soap_envelope(ack_rm_msg, env)))
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP11_FAULT_CODE_SENDER);
        else
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP12_FAULT_CODE_SENDER);
        sandesha2_fault_data_set_sub_code(fault_data, env, 
                        SANDESHA2_SOAP_FAULT_SUBCODE_INVALID_ACKNOWLEDGEMENT);
        dummy_ele = axiom_element_create(env, NULL, "dummy_ele", NULL, 
                        &dummy_node);
        sandesha2_iom_rm_element_to_om_node((sandesha2_iom_rm_element_t *)seq_ack, env, dummy_node);
        qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_SEQ_ACK, 
                        NULL, NULL);
        detail_ele = axiom_element_get_first_child_with_qname(dummy_ele, env,
                        qname, dummy_node, &detail_node);
        sandesha2_fault_data_set_detail(fault_data, env, detail_node);
        sandesha2_fault_data_set_reason(fault_data, env, reason);
        return sandesha2_fault_mgr_get_fault(env, ack_rm_msg,
                        fault_data, sandesha2_msg_ctx_get_addr_ns_val(ack_rm_msg,
                        env), storage_man);
    }
    return NULL;
}

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_check_for_seq_closed(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_man)
{
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *closed_bean = NULL;
    axis2_bool_t seq_closed = AXIS2_FALSE;
    axis2_char_t reason[256];
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_man, NULL);
    AXIS2_PARAM_CHECK(env->error, seq_id, NULL);
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
                        storage_man, env);
    closed_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env,
                        seq_id, SANDESHA2_SEQ_PROP_SEQ_CLOSED);
    if(closed_bean && 0 == axutil_strcmp(AXIS2_VALUE_TRUE,
                        sandesha2_seq_property_bean_get_value(closed_bean, env)))
    {
        seq_closed = AXIS2_TRUE;
        sprintf(reason, "The sequence with the id %s was closed previously."
                        " Cannot accept this message", seq_id);
    }
    if(seq_closed)
    {
        sandesha2_fault_data_t *fault_data = NULL;
        
        fault_data = sandesha2_fault_data_create(env);
        if(SANDESHA2_SOAP_VERSION_1_1 == sandesha2_utils_get_soap_version(env, 
                        sandesha2_msg_ctx_get_soap_envelope(rm_msg_ctx, env)))
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP11_FAULT_CODE_SENDER);
        else
            sandesha2_fault_data_set_code(fault_data, env, 
                        AXIOM_SOAP12_FAULT_CODE_SENDER);
        
        sandesha2_fault_data_set_reason(fault_data, env, reason);
        return sandesha2_fault_mgr_get_fault(env, rm_msg_ctx,
                        fault_data, sandesha2_msg_ctx_get_addr_ns_val(rm_msg_ctx,
                        env), storage_man);
    }
    return NULL;
}

sandesha2_msg_ctx_t* AXIS2_CALL 
sandesha2_fault_mgr_get_fault(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_fault_data_t *fault_data,
    axis2_char_t *addr_ns_uri,
    sandesha2_storage_mgr_t *storage_man)
{
    axis2_msg_ctx_t *fault_msg_ctx = NULL;
    axis2_msg_ctx_t *ref_msg = NULL;
    axis2_op_t *op = NULL;
    axis2_op_ctx_t *op_ctx = NULL;
    axis2_char_t *acks_to_str = NULL;
    axutil_string_t *grp_ctx_id = NULL;
    int soap_ver = -1;
    sandesha2_msg_ctx_t *fault_rm_msg = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, NULL);
    AXIS2_PARAM_CHECK(env->error, storage_man, NULL);
    AXIS2_PARAM_CHECK(env->error, addr_ns_uri, NULL);
    AXIS2_PARAM_CHECK(env->error, fault_data, NULL);
    
    ref_msg = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    fault_msg_ctx = axis2_core_utils_create_out_msg_ctx(env, ref_msg);
    
    /* Setting context hierachy - be caereful about freeing
     */
    axis2_msg_ctx_set_svc_grp(fault_msg_ctx, env, axis2_msg_ctx_get_svc_grp(
                        ref_msg, env));
    axis2_msg_ctx_set_svc_grp(fault_msg_ctx, env, (axis2_svc_grp_t *)axis2_msg_ctx_get_svc(ref_msg, 
                        env));
    axis2_msg_ctx_set_svc_grp_ctx(fault_msg_ctx, env, 
                        axis2_msg_ctx_get_svc_grp_ctx(ref_msg, env));
    axis2_msg_ctx_set_svc_ctx(fault_msg_ctx, env, axis2_msg_ctx_get_svc_ctx(
                        ref_msg, env));
    grp_ctx_id = (axutil_string_t *) axis2_msg_ctx_get_svc_grp_ctx_id(ref_msg, 
        env);
    axis2_msg_ctx_set_svc_grp_ctx_id(fault_msg_ctx, env, grp_ctx_id);
    axis2_msg_ctx_set_svc_ctx_id(fault_msg_ctx, env, 
                        axis2_msg_ctx_get_svc_ctx_id(ref_msg, env));
    op = axis2_op_create(env);
    axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_ONLY);
    op_ctx = axis2_op_ctx_create(env, op, NULL);
    axis2_msg_ctx_set_op(fault_msg_ctx, env, op);
    axis2_msg_ctx_set_op_ctx(fault_msg_ctx, env, op_ctx);
    
    if(SANDESHA2_MSG_TYPE_CREATE_SEQ == sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, 
                        env))
    {
        sandesha2_create_seq_t *create_seq = NULL;
        axis2_endpoint_ref_t *epr = NULL;
        
        create_seq = (sandesha2_create_seq_t *)sandesha2_msg_ctx_get_msg_part(
                        rm_msg_ctx, env, SANDESHA2_MSG_PART_CREATE_SEQ);
        epr =  sandesha2_address_get_epr(sandesha2_acks_to_get_address(
                        sandesha2_create_seq_get_acks_to(create_seq, env), 
                        env), env);
        acks_to_str = (axis2_char_t*)axis2_endpoint_ref_get_address(epr, env);
    }
    else
    {
        sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
        sandesha2_seq_property_bean_t *acks_to_bean = NULL;
        axis2_char_t *seq_id = NULL;
        
        seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
                        storage_man, env);
        seq_id = sandesha2_fault_data_get_seq_id(fault_data, env);
        acks_to_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr,
                        env, seq_id, SANDESHA2_SEQ_PROP_ACKS_TO_EPR);
        if(NULL != acks_to_bean)
            acks_to_str = sandesha2_seq_property_bean_get_value(acks_to_bean, 
                        env);
    }
    if(!sandesha2_utils_is_anon_uri(env, acks_to_str))
        axis2_msg_ctx_set_to(fault_msg_ctx, env, axis2_endpoint_ref_create(env,
                        acks_to_str));
    soap_ver = sandesha2_utils_get_soap_version(env, 
                        sandesha2_msg_ctx_get_soap_envelope(rm_msg_ctx, env));
    /* this method is not implemented. Uncomment this when implemented */
    /* sandesha2_soap_env_creator_add_soap_env(env, fault_msg_ctx, soap_ver, 
                        fault_data, sandesha2_msg_ctx_get_rm_ns_val(rm_msg_ctx,
                        env));*/
    
    fault_rm_msg = sandesha2_msg_init_init_msg(env, fault_msg_ctx);
    return fault_rm_msg;
}

