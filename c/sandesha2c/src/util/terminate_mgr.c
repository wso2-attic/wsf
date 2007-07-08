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
#include <sandesha2_terminate_mgr.h>
#include <sandesha2_terminate_seq.h>
#include <sandesha2_constants.h>
#include <sandesha2_property_bean.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_ack_range.h>
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_invoker_mgr.h>
#include <sandesha2_next_msg_mgr.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_create_seq_mgr.h>
#include <sandesha2_sender_mgr.h>
#include <sandesha2_sender_worker.h>
#include <sandesha2_sender_bean.h>
#include <axutil_string.h>
#include <axutil_uuid_gen.h>
#include <axis2_addr.h>
#include <axutil_property.h>
#include <axutil_array_list.h>
#include <axis2_engine.h>
#include <sandesha2_msg_creator.h>
#include <sandesha2_rm_bean.h>
#include <axis2_transport_out_desc.h>

axutil_hash_t *sandesha2_terminate_mgr_rcv_side_clean_map = NULL;

static axis2_status_t
sandesha2_terminate_mgr_clean_sending_side_data(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    axis2_bool_t svr_side,
    sandesha2_storage_mgr_t *storage_mgr);
                        
static axis2_status_t
sandesha2_terminate_mgr_complete_termination_of_recv_side(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr);
                        
static axis2_status_t
sandesha2_terminate_mgr_remove_recv_side_properties(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr);

static axis2_bool_t
sandesha2_terminate_mgr_is_property_deletable(
    const axutil_env_t *env,
    axis2_char_t *name);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_clean_recv_side_after_terminate_msg(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr)
{
    axis2_bool_t in_order_invoke = AXIS2_FALSE;
    sandesha2_property_bean_t *prop_bean = NULL;
    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_terminate_mgr_clean_recv_side_after_terminate_msg");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    if(!sandesha2_terminate_mgr_rcv_side_clean_map)
    {
        axutil_allocator_switch_to_global_pool(env->allocator);
        sandesha2_terminate_mgr_rcv_side_clean_map = axutil_hash_make(env);
        axutil_allocator_switch_to_local_pool(env->allocator);
    }
    
    prop_bean = sandesha2_utils_get_property_bean(env, axis2_conf_ctx_get_conf(
        conf_ctx, env));
    in_order_invoke = sandesha2_property_bean_is_in_order(prop_bean, env);
    if(!in_order_invoke)
    {
        axutil_allocator_switch_to_global_pool(env->allocator);
        axutil_hash_set(sandesha2_terminate_mgr_rcv_side_clean_map, seq_id,
            AXIS2_HASH_KEY_STRING, axutil_strdup(env, SANDESHA2_CLEANED_ON_TERMINATE_MSG));
        axutil_allocator_switch_to_local_pool(env->allocator);
        sandesha2_terminate_mgr_clean_recv_side_after_invocation(env, conf_ctx,
            seq_id, storage_mgr);
    }
    else
    {	axis2_char_t *clean_status = NULL;
        axutil_allocator_switch_to_global_pool(env->allocator);
        clean_status = axutil_hash_get(
            sandesha2_terminate_mgr_rcv_side_clean_map, seq_id, 
            AXIS2_HASH_KEY_STRING);
        axutil_allocator_switch_to_local_pool(env->allocator);
        if(clean_status && 0 == axutil_strcmp(clean_status, 
            SANDESHA2_CLEANED_AFTER_INVOCATION))
        {
            sandesha2_terminate_mgr_complete_termination_of_recv_side(env, conf_ctx, seq_id,
                storage_mgr);
        }
        else
        {
            axutil_allocator_switch_to_global_pool(env->allocator);
            axutil_hash_set(sandesha2_terminate_mgr_rcv_side_clean_map, seq_id,
                AXIS2_HASH_KEY_STRING, axutil_strdup(env, 
                SANDESHA2_CLEANED_ON_TERMINATE_MSG));
            axutil_allocator_switch_to_local_pool(env->allocator);
        }
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_terminate_mgr_clean_recv_side_after_terminate_msg");
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_clean_recv_side_after_invocation(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_invoker_mgr_t *invoker_mgr = NULL;
    sandesha2_invoker_bean_t *find_bean = NULL;
    axutil_array_list_t *found_list = NULL;
    int i = 0;
    axis2_char_t *clean_status = NULL;
    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_terminate_mgr_clean_recv_side_after_invocation");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    if(!sandesha2_terminate_mgr_rcv_side_clean_map)
    {
        axutil_allocator_switch_to_global_pool(env->allocator);
        sandesha2_terminate_mgr_rcv_side_clean_map = axutil_hash_make(env);
        axutil_allocator_switch_to_local_pool(env->allocator);
    }
    
    invoker_mgr = sandesha2_storage_mgr_get_storage_map_mgr(storage_mgr, env);
    find_bean = sandesha2_invoker_bean_create(env);
    
    sandesha2_invoker_bean_set_seq_id(find_bean, env, seq_id);
    sandesha2_invoker_bean_set_invoked(find_bean, env, AXIS2_TRUE);
    
    found_list = sandesha2_invoker_mgr_find(invoker_mgr, env, find_bean);
    for(i = 0; i < axutil_array_list_size(found_list, env); i++)
    {
        sandesha2_invoker_bean_t *map_bean = NULL;
        axis2_char_t *msg_store_key = NULL;
        
        map_bean = axutil_array_list_get(found_list, env, i);
        msg_store_key = sandesha2_invoker_bean_get_msg_ctx_ref_key(
            (sandesha2_rm_bean_t *) map_bean, env);
        sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, msg_store_key);
        sandesha2_invoker_mgr_remove(invoker_mgr, env, 
            sandesha2_invoker_bean_get_msg_ctx_ref_key((sandesha2_rm_bean_t *) 
                map_bean, env));
    }
    axutil_allocator_switch_to_global_pool(env->allocator);
    clean_status = axutil_hash_get(sandesha2_terminate_mgr_rcv_side_clean_map,
        seq_id, AXIS2_HASH_KEY_STRING);
    axutil_allocator_switch_to_local_pool(env->allocator);
                    
    if(clean_status && 0 == axutil_strcmp(clean_status, 
        SANDESHA2_CLEANED_ON_TERMINATE_MSG))
    {
        sandesha2_terminate_mgr_complete_termination_of_recv_side(env, conf_ctx, seq_id,
            storage_mgr);
    }
    else
    {
        axutil_allocator_switch_to_global_pool(env->allocator);
        axutil_hash_set(sandesha2_terminate_mgr_rcv_side_clean_map, seq_id,
            AXIS2_HASH_KEY_STRING, axutil_strdup(env, 
                SANDESHA2_CLEANED_AFTER_INVOCATION));
        axutil_allocator_switch_to_local_pool(env->allocator);
    }

    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_terminate_mgr_clean_recv_side_after_invocation");
    return AXIS2_SUCCESS;
}
                        
static axis2_status_t
sandesha2_terminate_mgr_complete_termination_of_recv_side(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_next_msg_mgr_t *next_mgr = NULL;
    sandesha2_next_msg_bean_t *find_bean = NULL;
    axutil_array_list_t *found_list = NULL;
    axis2_char_t *highest_in_msg_key = NULL;
    int i = 0, size = 0;
    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_terminate_mgr_complete_termination_of_recv_side");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    next_mgr = sandesha2_storage_mgr_get_next_msg_mgr(storage_mgr, env);
    find_bean = sandesha2_next_msg_bean_create(env);
    sandesha2_next_msg_bean_set_seq_id(find_bean, env, seq_id);
    
    found_list = sandesha2_next_msg_mgr_find(next_mgr, env, find_bean);
    if(found_list)
        size = axutil_array_list_size(found_list, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_next_msg_bean_t *bean = axutil_array_list_get(found_list, 
            env, i);
        if(bean)
        {
            axis2_char_t *key = NULL;
            axis2_char_t *seq_id = NULL;
            key = sandesha2_next_msg_bean_get_ref_msg_key(bean, env);
            if(key)
            {
                sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, key);
            }
            seq_id = sandesha2_next_msg_bean_get_seq_id((sandesha2_rm_bean_t *) 
                bean, env);
            if(seq_id)
                sandesha2_next_msg_mgr_remove(next_mgr, env, seq_id);
        }
    }
    highest_in_msg_key = sandesha2_utils_get_seq_property(env, seq_id,
        SANDESHA2_SEQ_PROP_HIGHEST_IN_MSG_KEY, storage_mgr);
    if(highest_in_msg_key)
    {
        sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, 
            highest_in_msg_key);
    }
    sandesha2_terminate_mgr_remove_recv_side_properties(env, conf_ctx, seq_id,
        storage_mgr);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_terminate_mgr_complete_termination_of_recv_side");
    return AXIS2_SUCCESS;
}
                        
static axis2_status_t
sandesha2_terminate_mgr_remove_recv_side_properties(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *all_seq_bean = NULL;
    axutil_array_list_t *found_list = NULL;
    sandesha2_seq_property_bean_t *find_seq_prop_bean = NULL;
    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_terminate_mgr_remove_recv_side_properties");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    all_seq_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
        SANDESHA2_SEQ_PROP_ALL_SEQS, SANDESHA2_SEQ_PROP_INCOMING_SEQ_LIST);
    if(all_seq_bean)
    {
        axutil_array_list_t *all_seq_list = NULL;
        axis2_char_t *all_seq_str = NULL;
        
        all_seq_list = sandesha2_utils_get_array_list_from_string(env, 
            sandesha2_seq_property_bean_get_value(all_seq_bean, env));
        if(all_seq_list)
        {
            int i = 0;
            for(i = 0; i < axutil_array_list_size(all_seq_list, env); i++)
            {
                axis2_char_t *value = axutil_array_list_get(all_seq_list, env, i);
                if(0 == axutil_strcmp(value, seq_id))
                {
                    axutil_array_list_remove(all_seq_list, env, i);
                    break;
                }
            }
            all_seq_str = sandesha2_utils_array_list_to_string(env, all_seq_list,
                SANDESHA2_ARRAY_LIST_STRING);
            sandesha2_seq_property_bean_set_value(all_seq_bean, env, all_seq_str);
            sandesha2_seq_property_mgr_update(seq_prop_mgr, env, all_seq_bean);
        }
    }
    find_seq_prop_bean = sandesha2_seq_property_bean_create(env);
    sandesha2_seq_property_bean_set_seq_id(find_seq_prop_bean, env, seq_id);
    found_list = sandesha2_seq_property_mgr_find(seq_prop_mgr, env, 
        find_seq_prop_bean);
    if(found_list)
    {
        int i = 0, size = 0;
        size = axutil_array_list_size(found_list, env);
        for(i = 0; i < size; i++)
        {
            sandesha2_seq_property_bean_t *seq_prop_bean = NULL;
            
            seq_prop_bean = axutil_array_list_get(found_list, env, i);
            /*sandesha2_terminate_mgr_do_updates_if_needed(env, out_seq_id,
                seq_prop_bean, seq_prop_mgr);*/
            if(sandesha2_terminate_mgr_is_property_deletable(env,
                sandesha2_seq_property_bean_get_name(seq_prop_bean, env)))
            {
                axis2_char_t *highest_in_msg_key_str = NULL;
                axis2_char_t *seq_id = sandesha2_seq_property_bean_get_seq_id(
                    seq_prop_bean, env);
                axis2_char_t *name = sandesha2_seq_property_bean_get_name(
                    seq_prop_bean, env);
                if(axutil_strcmp(name, SANDESHA2_SEQ_PROP_HIGHEST_IN_MSG_NUMBER))
                {
                    highest_in_msg_key_str = 
                        sandesha2_seq_property_bean_get_value(seq_prop_bean, env);
                    sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, 
                        highest_in_msg_key_str);
                }
                sandesha2_seq_property_mgr_remove(seq_prop_mgr, env, seq_id, name);
            }
        }
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_terminate_mgr_remove_recv_side_properties");
    return AXIS2_SUCCESS;
}
                        
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_terminate_sending_side(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    axis2_bool_t svr_side,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *seq_term_bean = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_terminate_mgr_terminate_sending_side");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    seq_term_bean = sandesha2_seq_property_bean_create_with_data(env, seq_id,
        SANDESHA2_SEQ_PROP_SEQ_TERMINATED, AXIS2_VALUE_TRUE);
    sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, seq_term_bean);
    
    sandesha2_terminate_mgr_clean_sending_side_data(env, conf_ctx, seq_id, 
        svr_side, storage_mgr);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_terminate_mgr_terminate_sending_side");
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_do_updates_if_needed(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    sandesha2_seq_property_bean_t *prop_bean,
    sandesha2_seq_property_mgr_t *prop_mgr)
{
    axis2_bool_t add_entry_with_seq_id = AXIS2_FALSE;
    axis2_char_t *name = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, prop_bean, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, prop_mgr, AXIS2_FAILURE);
    
    name = sandesha2_seq_property_bean_get_name(prop_bean, env);
    if(NULL == name)
        return AXIS2_FAILURE;
    
    if(0 == axutil_strcmp(name, SANDESHA2_SEQ_PROP_CLIENT_COMPLETED_MESSAGES))
        add_entry_with_seq_id = AXIS2_TRUE;
    if(0 == axutil_strcmp(name, SANDESHA2_SEQ_PROP_SEQ_TERMINATED))
        add_entry_with_seq_id = AXIS2_TRUE;
    if(0 == axutil_strcmp(name, SANDESHA2_SEQ_PROP_SEQ_CLOSED))
        add_entry_with_seq_id = AXIS2_TRUE;
    if(0 == axutil_strcmp(name, SANDESHA2_SEQ_PROP_SEQ_TIMED_OUT))
        add_entry_with_seq_id = AXIS2_TRUE;
        
    if(AXIS2_TRUE == add_entry_with_seq_id && seq_id)
    {
        sandesha2_seq_property_bean_t *new_bean = NULL;
        new_bean = sandesha2_seq_property_bean_create(env);
        sandesha2_seq_property_bean_set_seq_id(new_bean, env, seq_id);
        sandesha2_seq_property_bean_set_name(new_bean, env, name);
        sandesha2_seq_property_bean_set_value(new_bean, env, 
                        sandesha2_seq_property_bean_get_value(prop_bean, env));
        sandesha2_seq_property_mgr_insert(prop_mgr, env, new_bean);
        sandesha2_seq_property_mgr_remove(prop_mgr, env, 
                    sandesha2_seq_property_bean_get_seq_id(prop_bean, env),
                    name);
    }
    return AXIS2_SUCCESS;
}


static axis2_bool_t
sandesha2_terminate_mgr_is_property_deletable(
    const axutil_env_t *env,
    axis2_char_t *name)
{
    axis2_bool_t deletable = AXIS2_TRUE;
        
    if(0 == axutil_strcasecmp(name, SANDESHA2_SEQ_PROP_TERMINATE_ADDED))
        deletable = AXIS2_FALSE;
    if(0 == axutil_strcasecmp(name, SANDESHA2_SEQ_PROP_NO_OF_OUTGOING_MSGS_ACKED))
        deletable = AXIS2_FALSE;
    if(0 == axutil_strcasecmp(name, SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID))
        deletable = AXIS2_FALSE;
    if(0 == axutil_strcasecmp(name, SANDESHA2_SEQ_PROP_SEQ_TERMINATED))
        deletable = AXIS2_FALSE;
    if(0 == axutil_strcasecmp(name, SANDESHA2_SEQ_PROP_SEQ_CLOSED))
        deletable = AXIS2_FALSE;
    if(0 == axutil_strcasecmp(name, SANDESHA2_SEQ_PROP_SEQ_TIMED_OUT))
        deletable = AXIS2_FALSE;
    return deletable;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_time_out_sending_side_seq(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    axis2_bool_t svr_side,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *seq_term_bean = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    seq_term_bean = sandesha2_seq_property_bean_create_with_data(env, seq_id,
        SANDESHA2_SEQ_PROP_SEQ_TIMED_OUT, AXIS2_VALUE_TRUE);
    
    sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, seq_term_bean);
    sandesha2_terminate_mgr_clean_sending_side_data(env, conf_ctx, seq_id,
        svr_side, storage_mgr);
    return AXIS2_SUCCESS;
}

static axis2_status_t
sandesha2_terminate_mgr_clean_sending_side_data(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *seq_id,
    axis2_bool_t svr_side,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_sender_mgr_t *retrans_mgr = NULL;
    sandesha2_create_seq_mgr_t *create_seq_mgr = NULL;
    axis2_char_t *out_seq_id = NULL;
    axis2_char_t *internal_seq_id = NULL;
    axutil_array_list_t *found_list = NULL;
    sandesha2_create_seq_bean_t *find_create_seq_bean = NULL;
    sandesha2_seq_property_bean_t *find_seq_prop_bean = NULL;
    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_terminate_mgr_clean_sending_side_data");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    retrans_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, env);    
    create_seq_mgr = sandesha2_storage_mgr_get_create_seq_mgr(storage_mgr, env);
    
    out_seq_id = sandesha2_utils_get_seq_property(env, seq_id, 
        SANDESHA2_SEQ_PROP_OUT_SEQ_ID, storage_mgr);
    if(!svr_side)
    {
        sandesha2_seq_property_bean_t *acks_to_bean = NULL;
        axis2_char_t *addr_ns_uri = NULL;
        axis2_bool_t stop_listner_for_async = AXIS2_FALSE;
        
        acks_to_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env,
            seq_id, SANDESHA2_SEQ_PROP_ACKS_TO_EPR);
        addr_ns_uri = sandesha2_utils_get_seq_property(env, seq_id, 
            SANDESHA2_SEQ_PROP_ADDRESSING_NAMESPACE_VALUE, 
            storage_mgr);
        if(acks_to_bean)
        {
            axis2_char_t *acks_to = NULL;
            acks_to = sandesha2_seq_property_bean_get_value(acks_to_bean, env);
        if(sandesha2_utils_is_anon_uri(env, acks_to))
                stop_listner_for_async = AXIS2_TRUE;
        }
        
    }
    internal_seq_id = sandesha2_utils_get_seq_property(env, seq_id, 
        SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID, storage_mgr);
    found_list = sandesha2_sender_mgr_find_by_internal_seq_id(retrans_mgr, env,
        internal_seq_id);
    if(found_list)
    {
        int i = 0;
        for(i = 0; i < axutil_array_list_size(found_list, env); i++)
        {
            sandesha2_sender_bean_t *retrans_bean = NULL;
            axis2_char_t *msg_store_key = NULL;
            axis2_char_t *msg_id = NULL;
            
            retrans_bean = axutil_array_list_get(found_list, env, i);
            msg_id = sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) 
                retrans_bean, env);
            sandesha2_sender_mgr_remove(retrans_mgr, env, msg_id);
            msg_store_key = sandesha2_sender_bean_get_msg_ctx_ref_key(
                        retrans_bean, env);
            sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, msg_store_key);
        }
    }
    
    find_create_seq_bean = sandesha2_create_seq_bean_create(env);
    sandesha2_create_seq_bean_set_internal_seq_id(find_create_seq_bean, env,
        internal_seq_id);
    found_list = sandesha2_create_seq_mgr_find(create_seq_mgr, env, 
        find_create_seq_bean);
    if(found_list)
    {
        int i = 0;
        for(i = 0; i < axutil_array_list_size(found_list, env); i++)
        {
            axis2_char_t *key = NULL;
            axis2_char_t *msg_id = NULL;
            sandesha2_create_seq_bean_t *create_seq_bean = NULL;
            
            create_seq_bean = axutil_array_list_get(found_list, env, i);
            key = sandesha2_create_seq_bean_get_ref_msg_store_key(
                create_seq_bean, env);
            sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, key);
            msg_id = sandesha2_create_seq_bean_get_create_seq_msg_id(
                (sandesha2_rm_bean_t *) create_seq_bean, env);
            sandesha2_create_seq_mgr_remove(create_seq_mgr, env, msg_id);
        }
    }
    
    find_seq_prop_bean = sandesha2_seq_property_bean_create(env);
    sandesha2_seq_property_bean_set_seq_id(find_seq_prop_bean, env, internal_seq_id);
    found_list = sandesha2_seq_property_mgr_find(seq_prop_mgr, env, 
        find_seq_prop_bean);
    if(found_list)
    {
        int i = 0, size = 0;
        size = axutil_array_list_size(found_list, env);
        for(i = 0; i < size; i++)
        {
            sandesha2_seq_property_bean_t *seq_prop_bean = NULL;
            
            seq_prop_bean = axutil_array_list_get(found_list, env, i);
            sandesha2_terminate_mgr_do_updates_if_needed(env, out_seq_id,
                seq_prop_bean, seq_prop_mgr);
            if(sandesha2_terminate_mgr_is_property_deletable(env,
                sandesha2_seq_property_bean_get_name(seq_prop_bean, env)))
            {
                axis2_char_t *highest_in_msg_key_str = NULL;
                axis2_char_t *seq_id = sandesha2_seq_property_bean_get_seq_id(
                    seq_prop_bean, env);
                axis2_char_t *name = sandesha2_seq_property_bean_get_name(
                    seq_prop_bean, env);
                if(!axutil_strcmp(name, SANDESHA2_SEQ_PROP_HIGHEST_IN_MSG_NUMBER))
                {
                    highest_in_msg_key_str = 
                        sandesha2_seq_property_bean_get_value(seq_prop_bean, env);
                    sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, 
                        highest_in_msg_key_str);
                }
                sandesha2_seq_property_mgr_remove(seq_prop_mgr, env, seq_id, name);
            }
        }
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_terminate_mgr_clean_sending_side_data");
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_terminate_mgr_add_terminate_seq_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    axis2_char_t *out_seq_id,
    axis2_char_t *int_seq_id,
    sandesha2_storage_mgr_t *storage_mgr)
{
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_msg_ctx_t *terminate_msg_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *terminated = NULL;
    sandesha2_msg_ctx_t *terminate_rm_msg = NULL;
    axutil_property_t *property = NULL;
    axis2_endpoint_ref_t *to_epr = NULL;
    sandesha2_seq_property_bean_t *to_bean = NULL;
    axis2_char_t *rm_ver = NULL;
    sandesha2_seq_property_bean_t *transport_to_bean = NULL;
    axis2_char_t *key = NULL;
    sandesha2_sender_bean_t *terminate_bean = NULL;
    sandesha2_sender_mgr_t *retrans_mgr = NULL;
    sandesha2_seq_property_bean_t *terminate_added = NULL;
    axis2_transport_out_desc_t *transport_out = NULL;
    axis2_msg_ctx_t *msg_ctx1 = NULL;
    axis2_engine_t *engine = NULL;
    axis2_char_t *temp_action = NULL;
    axutil_string_t *soap_action = NULL;
    axis2_status_t status = AXIS2_FALSE;
    const axis2_char_t *to_addr = NULL;
    long send_time = -1;
    sandesha2_terminate_seq_t *terminate_seq = NULL;
    axis2_char_t *seq_id = NULL;
    axis2_char_t *internal_seq_id = NULL; 

    AXIS2_LOG_INFO(env->log, 
        "[sandesha2] Start:sandesha2_terminate_mgr_add_terminate_seq_msg");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, out_seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, int_seq_id, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FAILURE);
    
    msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    terminated = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
        out_seq_id, SANDESHA2_SEQ_PROP_TERMINATE_ADDED);
    if(terminated && sandesha2_seq_property_bean_get_value(terminated, env) 
        && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, 
        sandesha2_seq_property_bean_get_value(terminated, env)))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Terminate was"
            " added previously");
        /* If we do not return at this, there will be two terminate messsages
         * sent to the client
         */
        return AXIS2_SUCCESS;
    }
    terminate_rm_msg = sandesha2_msg_creator_create_terminate_seq_msg(env,
        rm_msg_ctx, out_seq_id, int_seq_id, storage_mgr);
    sandesha2_msg_ctx_set_flow(terminate_rm_msg, env, AXIS2_OUT_FLOW);
    property = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
    sandesha2_msg_ctx_set_property(terminate_rm_msg, env, 
        SANDESHA2_APPLICATION_PROCESSING_DONE, property);
    
    to_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, int_seq_id,
        SANDESHA2_SEQ_PROP_TO_EPR);
    if(to_bean)
        to_epr = axis2_endpoint_ref_create(env, 
            sandesha2_seq_property_bean_get_value(to_bean, env));
    /*if(!to_epr)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] To EPR has an "
            "invalid value");
        return AXIS2_FAILURE;
    }*/
    if(to_epr)
        to_addr = axis2_endpoint_ref_get_address(to_epr, env);
    sandesha2_msg_ctx_set_to(terminate_rm_msg, env, to_epr);
    rm_ver = sandesha2_utils_get_rm_version(env, int_seq_id, storage_mgr);
    if(!rm_ver)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Cannot find the "
            "rm version for msg");
        return AXIS2_FAILURE;
    }
    sandesha2_msg_ctx_set_wsa_action(terminate_rm_msg, env, 
        sandesha2_spec_specific_consts_get_terminate_seq_action(env, rm_ver));
    temp_action = sandesha2_spec_specific_consts_get_terminate_seq_soap_action
        (env, rm_ver);
    soap_action = axutil_string_create(env, temp_action);
    sandesha2_msg_ctx_set_soap_action(terminate_rm_msg, env, soap_action);
    transport_to_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env,
        int_seq_id, SANDESHA2_SEQ_PROP_TRANSPORT_TO);
    if(transport_to_bean)
    {
        axis2_char_t *value = sandesha2_seq_property_bean_get_value(
            transport_to_bean, env);
        property = axutil_property_create_with_args(env, 0, 0, 0, value);
        sandesha2_msg_ctx_set_property(terminate_rm_msg, env,
            AXIS2_TRANSPORT_URL, property);
    }
    
    sandesha2_msg_ctx_add_soap_envelope(terminate_rm_msg, env);
    if(axis2_msg_ctx_get_server_side(msg_ctx, env) &&
       sandesha2_utils_is_single_channel(env, rm_ver, to_addr))
    {
        axis2_msg_ctx_t *msg_ctx1 = sandesha2_msg_ctx_get_msg_ctx(terminate_rm_msg, env);
        axis2_op_ctx_set_response_written(axis2_msg_ctx_get_op_ctx(msg_ctx1, env), env, AXIS2_TRUE);
        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
        axis2_op_ctx_set_response_written(axis2_msg_ctx_get_op_ctx(msg_ctx, env), env, AXIS2_TRUE);
        engine = axis2_engine_create(env, conf_ctx);
        axis2_engine_send(engine, env, msg_ctx1);
        /* Clean sending side data */
        {
            sandesha2_terminate_seq_t *terminate_seq = NULL;
            axis2_char_t *seq_id = NULL;
            axis2_char_t *internal_seq_id = NULL;
            
            terminate_seq = (sandesha2_terminate_seq_t*)
                sandesha2_msg_ctx_get_msg_part(terminate_rm_msg, env, 
                SANDESHA2_MSG_PART_TERMINATE_SEQ);
            seq_id = sandesha2_identifier_get_identifier(
                sandesha2_terminate_seq_get_identifier(terminate_seq, 
                env), env);
            internal_seq_id = sandesha2_utils_get_seq_property(env, seq_id, 
                SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID, storage_mgr);
            sandesha2_terminate_mgr_terminate_sending_side(env, conf_ctx,
                internal_seq_id, axis2_msg_ctx_get_server_side(msg_ctx1, env), 
                    storage_mgr);
        }
        return AXIS2_SUCCESS;
    }
    key = axutil_uuid_gen(env);
    terminate_bean = sandesha2_sender_bean_create(env);
    sandesha2_sender_bean_set_msg_ctx_ref_key(terminate_bean, env, key);
    terminate_msg_ctx = sandesha2_msg_ctx_get_msg_ctx(terminate_rm_msg, env);
    sandesha2_storage_mgr_store_msg_ctx(storage_mgr, env, key, 
        terminate_msg_ctx);
    send_time = sandesha2_utils_get_current_time_in_millis(env) +
        SANDESHA2_TERMINATE_DELAY;
    sandesha2_sender_bean_set_time_to_send(terminate_bean, env, send_time);
    sandesha2_sender_bean_set_msg_id(terminate_bean, env, 
        sandesha2_msg_ctx_get_msg_id(terminate_rm_msg, env));
    sandesha2_sender_bean_set_send(terminate_bean, env, AXIS2_TRUE);

    terminate_seq = (sandesha2_terminate_seq_t*)
        sandesha2_msg_ctx_get_msg_part(terminate_rm_msg, env, 
        SANDESHA2_MSG_PART_TERMINATE_SEQ);
    seq_id = sandesha2_identifier_get_identifier(
        sandesha2_terminate_seq_get_identifier(terminate_seq, 
        env), env);
    internal_seq_id = sandesha2_utils_get_seq_property(env, seq_id, 
        SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID, storage_mgr);
    sandesha2_sender_bean_set_seq_id(terminate_bean, env, internal_seq_id);

    property = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_FALSE);
    sandesha2_msg_ctx_set_property(terminate_rm_msg, env, 
        SANDESHA2_QUALIFIED_FOR_SENDING, property);
    sandesha2_sender_bean_set_msg_type(terminate_bean, env, 
        SANDESHA2_MSG_TYPE_TERMINATE_SEQ);
                            
    sandesha2_sender_bean_set_resend(terminate_bean, env, AXIS2_FALSE);
    retrans_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, env);
    
    sandesha2_sender_mgr_insert(retrans_mgr, env, terminate_bean);
    
    terminate_added = sandesha2_seq_property_bean_create(env);
    sandesha2_seq_property_bean_set_name(terminate_added, env, 
        SANDESHA2_SEQ_PROP_TERMINATE_ADDED);
    sandesha2_seq_property_bean_set_seq_id(terminate_added, env, out_seq_id);
    sandesha2_seq_property_bean_set_value(terminate_added, env, 
        AXIS2_VALUE_TRUE);
                        
    sandesha2_seq_property_mgr_insert(seq_prop_mgr, env, terminate_added);
    
    msg_ctx1 = sandesha2_msg_ctx_get_msg_ctx(terminate_rm_msg, env);
    transport_out = axis2_msg_ctx_get_transport_out_desc(msg_ctx1, env);
    
    property = axutil_property_create_with_args(env, 0, 0,
        axis2_transport_out_desc_free_void_arg, transport_out);
    axis2_msg_ctx_set_property(msg_ctx1, env, 
        SANDESHA2_ORIGINAL_TRANSPORT_OUT_DESC, property);
    
    property = axutil_property_create_with_args(env, 0, 0, 0, key);
    axis2_msg_ctx_set_property(msg_ctx1, env, SANDESHA2_MESSAGE_STORE_KEY, 
        property);
                        
    property = axutil_property_create_with_args(env, 0, 0, 0, 
        AXIS2_VALUE_TRUE);
    axis2_msg_ctx_set_property(msg_ctx1, env, SANDESHA2_SET_SEND_TO_TRUE, 
        property);
                        
    axis2_msg_ctx_set_transport_out_desc(msg_ctx1, env, 
        sandesha2_utils_get_transport_out(env));
    {                
        axis2_endpoint_ref_t *reply_to_epr = NULL;
        reply_to_epr = axis2_msg_ctx_get_to(msg_ctx, env);
        if(reply_to_epr)
            axis2_msg_ctx_set_reply_to(msg_ctx1, env, reply_to_epr);
    }
    engine = axis2_engine_create(env, conf_ctx);
    status = axis2_engine_send(engine, env, msg_ctx1);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2] Exit:sandesha2_terminate_mgr_add_terminate_seq_msg");
    return status;
}

