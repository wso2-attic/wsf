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
#include <sandesha2_in_order_invoker.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_transaction.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_terminate_mgr.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_next_msg_mgr.h>
#include <sandesha2_invoker_mgr.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_seq.h>
#include <sandesha2_msg_init.h>
#include <axis2_addr.h>
#include <axis2_engine.h>
#include <stdio.h>
#include <platforms/axutil_platform_auto_sense.h>


/** 
 * @brief In Order Invoker struct impl
 *	Sandesha2 In Order Invoker
 */
typedef struct sandesha2_in_order_invoker_args sandesha2_in_order_invoker_args_t;

struct sandesha2_in_order_invoker_t
{
	axis2_conf_ctx_t *conf_ctx;
    axis2_bool_t run_invoker;
    axutil_array_list_t *working_seqs;
    axutil_thread_mutex_t *mutex;
};

struct sandesha2_in_order_invoker_args
{
    sandesha2_in_order_invoker_t *impl;
    axutil_env_t *env;
};

AXIS2_EXTERN sandesha2_in_order_invoker_t* AXIS2_CALL
sandesha2_in_order_invoker_create(const axutil_env_t *env)
{
    sandesha2_in_order_invoker_t *invoker = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    invoker =  (sandesha2_in_order_invoker_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof(sandesha2_in_order_invoker_t));
	
    if(NULL == invoker)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    invoker->conf_ctx = NULL;
    invoker->run_invoker = AXIS2_FALSE;
    invoker->working_seqs = NULL;
    invoker->mutex = NULL;
    
    invoker->working_seqs = axutil_array_list_create(env, 
                        AXIS2_ARRAY_LIST_DEFAULT_CAPACITY);
    invoker->mutex = axutil_thread_mutex_create(env->allocator,
                        AXIS2_THREAD_MUTEX_DEFAULT);
                        
	return invoker;
}

axis2_status_t AXIS2_CALL
sandesha2_in_order_invoker_free_void_arg(
    void *invoker,
    const axutil_env_t *env)
{
    sandesha2_in_order_invoker_t *invoker_l = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    invoker_l = (sandesha2_in_order_invoker_t *) invoker;
    return sandesha2_in_order_invoker_free(invoker_l, env);
}

axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_free(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env)
{
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    /* Do not free this */
    invoker->conf_ctx = NULL;
    
    if(NULL != invoker->mutex)
    {
        axutil_thread_mutex_destroy(invoker->mutex);
        invoker->mutex = NULL;
    }
    if(NULL != invoker->working_seqs)
    {
        axutil_array_list_free(invoker->working_seqs, env);
        invoker->working_seqs = NULL;
    }
	AXIS2_FREE(env->allocator, invoker);
	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_stop_invoker_for_seq(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env, axis2_char_t *seq_id)
{
    int i = 0;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    
    for(i = 0; i < axutil_array_list_size(invoker->working_seqs, env); i++)
    {
        axis2_char_t *tmp_id = NULL;
        tmp_id = axutil_array_list_get(invoker->working_seqs, env, i);
        if(0 == axutil_strcmp(seq_id, tmp_id))
        {
            axutil_array_list_remove(invoker->working_seqs, env, i);
            break;
        }
    }
    if(0 == axutil_array_list_size(invoker->working_seqs, env))
        invoker->run_invoker = AXIS2_FALSE;
    return AXIS2_SUCCESS;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_stop_invoking (
    sandesha2_in_order_invoker_t *invoker,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    invoker->run_invoker = AXIS2_FALSE;
    return AXIS2_SUCCESS;
}
            
axis2_bool_t AXIS2_CALL 
sandesha2_in_order_invoker_is_invoker_started(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env)
{
    axis2_bool_t started = AXIS2_FALSE;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    started = invoker->run_invoker;
    return started;    
}
            
axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_run_for_seq (
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env, 
    axis2_conf_ctx_t *conf_ctx, 
    axis2_char_t *seq_id)
{
    axutil_thread_mutex_lock(invoker->mutex);
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FAILURE);
    
    if(!sandesha2_utils_array_list_contains(env, 
                        invoker->working_seqs, seq_id))
        axutil_array_list_add(invoker->working_seqs, env, seq_id);
    if(!invoker->run_invoker)
    {
        invoker->conf_ctx = conf_ctx;
        invoker->run_invoker = AXIS2_TRUE;
        sandesha2_in_order_invoker_run(invoker, env);
    }
    axutil_thread_mutex_unlock(invoker->mutex);
    return AXIS2_SUCCESS;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_run (
    sandesha2_in_order_invoker_t *invoker,
    const axutil_env_t *env)
{
    axutil_thread_t *worker_thread = NULL;
    sandesha2_in_order_invoker_args_t *args = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    args = AXIS2_MALLOC(env->allocator, sizeof(
                        sandesha2_in_order_invoker_args_t)); 
    args->impl = invoker;
    args->env = (axutil_env_t*)env;
    worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
        sandesha2_in_order_invoker_worker_func, (void*)args);
    if(NULL == worker_thread)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed"
                  " sandesha2_in_order_invoker_run");
        return AXIS2_FAILURE;
    }
    axutil_thread_pool_thread_detach(env->thread_pool, worker_thread); 
        
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
sandesha2_in_order_invoker_make_msg_ready_for_reinjection(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env, 
    axis2_msg_ctx_t *msg_ctx)
{
    axutil_property_t *property = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    
    axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_WSA_VERSION, NULL);
    axis2_msg_ctx_set_message_id(msg_ctx, env, NULL);
    axis2_msg_ctx_set_to(msg_ctx, env, NULL);
    axis2_msg_ctx_set_wsa_action(msg_ctx, env, NULL);
    property = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
    axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_REINJECTED_MESSAGE, 
                        property);
    return AXIS2_SUCCESS;
}

/**
 * Thread worker function.
 */
void * AXIS2_THREAD_FUNC
sandesha2_in_order_invoker_worker_func(
    axutil_thread_t *thd, 
    void *data)
{
    sandesha2_in_order_invoker_t *invoker = NULL;
    sandesha2_in_order_invoker_args_t *args;
    axutil_env_t *env = NULL;
    
    args = (sandesha2_in_order_invoker_args_t*)data;
    env = axutil_init_thread_env(args->env);
    invoker = args->impl;
    
    while(invoker->run_invoker)
    {
        sandesha2_transaction_t *transaction = NULL;
        /* Use when transaction handling is done 
        axis2_bool_t rollbacked = AXIS2_FALSE;*/
        sandesha2_storage_mgr_t *storage_mgr = NULL;
        sandesha2_next_msg_mgr_t *next_msg_mgr = NULL;
        sandesha2_invoker_mgr_t *storage_map_mgr = NULL;
        sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
        sandesha2_seq_property_bean_t *all_seq_bean = NULL;
        axutil_array_list_t *all_seq_list = NULL;
        int i = 0;

        AXIS2_SLEEP(SANDESHA2_INVOKER_SLEEP_TIME);
        if(!invoker->conf_ctx)
            return NULL;
        storage_mgr = sandesha2_utils_get_storage_mgr(env, 
                        invoker->conf_ctx, 
                        axis2_conf_ctx_get_conf(invoker->conf_ctx, env));
        next_msg_mgr = sandesha2_storage_mgr_get_next_msg_mgr(
                        storage_mgr, env);
        storage_map_mgr = sandesha2_storage_mgr_get_storage_map_mgr
                        (storage_mgr, env);
        seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
                        storage_mgr, env);
        transaction = sandesha2_storage_mgr_get_transaction(storage_mgr,
                        env);
        all_seq_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr,
                        env, SANDESHA2_SEQ_PROP_ALL_SEQS, 
                        SANDESHA2_SEQ_PROP_INCOMING_SEQ_LIST);
        if(!all_seq_bean)
            continue;
        all_seq_list = sandesha2_utils_get_array_list_from_string(env,
                        sandesha2_seq_property_bean_get_value(all_seq_bean, env));
        if(!all_seq_list)
            continue;
            
        for(i = 0; i < axutil_array_list_size(all_seq_list, env); i++)
        {
            axis2_char_t *seq_id = NULL;
            long next_msg_no = -1;
            sandesha2_next_msg_bean_t *next_msg_bean = NULL;
            axutil_array_list_t *st_map_list = NULL;
            sandesha2_invoker_bean_t *find_bean = NULL;
            axis2_bool_t invoked = AXIS2_FALSE;
            int j = 0, size = 0;
            axis2_bool_t continue_seq = AXIS2_TRUE;
            
            seq_id = axutil_array_list_get(all_seq_list, env, i);
            sandesha2_transaction_commit(transaction, env);
            transaction = sandesha2_storage_mgr_get_transaction(
                        storage_mgr, env);
            next_msg_bean = sandesha2_next_msg_mgr_retrieve(
                        next_msg_mgr, env, seq_id);
            if(!next_msg_bean)
            {
                axis2_char_t *str_list = NULL;
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Next message not set" 
                        " correctly. Removing invalid entry.");
                axutil_array_list_remove(all_seq_list, env, i);
                /* We need to make sure we are not skipping element after 
                 * removing current element
                 */                 
                i--;
                str_list = sandesha2_utils_array_list_to_string(env, all_seq_list, 
                        SANDESHA2_ARRAY_LIST_STRING);
                sandesha2_seq_property_bean_set_value(all_seq_bean, env,
                        str_list);
                sandesha2_seq_property_mgr_update(seq_prop_mgr, env, 
                        all_seq_bean);
                continue;
            }
            next_msg_no = sandesha2_next_msg_bean_get_next_msg_no_to_process(
                        next_msg_bean, env);
            if(next_msg_no < 0)
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Invalid message number"
                        " as the Next Message Number.");
                return data;
            }
            find_bean = sandesha2_invoker_bean_create_with_data(env, NULL,
                        next_msg_no, seq_id, AXIS2_FALSE);
            st_map_list = sandesha2_invoker_mgr_find(storage_map_mgr,
                        env, find_bean);
            size = axutil_array_list_size(st_map_list, env);
            for(j = 0; j < size; j++)
            {
                sandesha2_invoker_bean_t *st_map_bean = NULL;
                axis2_char_t *key = NULL;
                axis2_msg_ctx_t *msg_to_invoke = NULL;
                sandesha2_msg_ctx_t *rm_msg_ctx = NULL;
                axutil_property_t *property = NULL;
                axis2_bool_t post_failure_invocation = AXIS2_FALSE;
                axis2_char_t *post_failure_str = NULL;
                axis2_msg_ctx_t *msg_ctx = NULL;
                axis2_engine_t *engine = NULL;
                
                st_map_bean = axutil_array_list_get(st_map_list, env, j);
                key = sandesha2_invoker_bean_get_msg_ctx_ref_key(
                    (sandesha2_rm_bean_t *) st_map_bean, env);
                msg_to_invoke = sandesha2_storage_mgr_retrieve_msg_ctx(
                    storage_mgr, env, key, invoker->conf_ctx, AXIS2_FALSE);
                if(msg_to_invoke)
                    rm_msg_ctx = sandesha2_msg_init_init_msg(env, 
                        msg_to_invoke);
                else continue;
                /* have to commit the transaction before invoking. This may get 
                 * changed when WS-AT is available.
                 */
                sandesha2_transaction_commit(transaction, env);
                property = axutil_property_create_with_args(env, 0, 0, 0, 
                    AXIS2_VALUE_TRUE);
                axis2_msg_ctx_set_property(msg_to_invoke, env, 
                        SANDESHA2_WITHIN_TRANSACTION, property);
                        
                property = axis2_msg_ctx_get_property(msg_to_invoke, env,
                        SANDESHA2_POST_FAILURE_MESSAGE);
                if(property)
                    post_failure_str = axutil_property_get_value(property, env);
                if(post_failure_str && 0 == axutil_strcmp(
                        post_failure_str, AXIS2_VALUE_TRUE))
                    post_failure_invocation = AXIS2_TRUE;
                engine = axis2_engine_create(env, invoker->conf_ctx);
                if(AXIS2_TRUE == post_failure_invocation)
                {
                    sandesha2_in_order_invoker_make_msg_ready_for_reinjection(
                        invoker, env, msg_to_invoke);
                    axis2_engine_receive(engine, env, msg_to_invoke);
                }
                else
                {
                    axis2_status_t status = AXIS2_FAILURE;
                    axis2_msg_ctx_set_paused(msg_to_invoke, env, AXIS2_FALSE);
                    status = axis2_engine_resume_receive(engine, env, msg_to_invoke);
                    if(!status)
                        return NULL;
                }
                invoked = AXIS2_TRUE;
                transaction = sandesha2_storage_mgr_get_transaction(
                        storage_mgr, env);
                sandesha2_storage_mgr_remove_msg_ctx(storage_mgr, env, key);
                msg_ctx = sandesha2_storage_mgr_retrieve_msg_ctx(
                    storage_mgr, env, key, invoker->conf_ctx, AXIS2_FALSE);
                if(msg_ctx)
                    sandesha2_storage_mgr_remove_msg_ctx(storage_mgr,
                        env, key);
                if(SANDESHA2_MSG_TYPE_APPLICATION == 
                        sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, env))
                {
                    sandesha2_seq_t *seq = NULL;
                    seq = (sandesha2_seq_t*)sandesha2_msg_ctx_get_msg_part(
                            rm_msg_ctx, env, SANDESHA2_MSG_PART_SEQ);
                    if(sandesha2_seq_get_last_msg(seq, env))
                    {
                        sandesha2_terminate_mgr_clean_recv_side_after_invocation(
                            env, invoker->conf_ctx, seq_id, 
                            storage_mgr);
                        /* we are done with current seq */
                        continue_seq = AXIS2_FALSE;
                        break;
                    }
                }
            }
            if(!continue_seq)
            {
                break;
            }
            if(invoked)
            {
                next_msg_no++;
                sandesha2_next_msg_bean_set_next_msg_no_to_process(next_msg_bean,
                        env, next_msg_no);
                sandesha2_next_msg_mgr_update(next_msg_mgr, env, 
                        next_msg_bean);
            }
        }
        sandesha2_transaction_commit(transaction, env);
        
        /* TODO make transaction handling effective */
    }
    return NULL;
}

