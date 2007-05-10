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
#include <sandesha2_polling_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_transaction.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_terminate_mgr.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_seq.h>
#include <sandesha2_msg_init.h>
#include <sandesha2_msg_creator.h>
#include <sandesha2_next_msg_mgr.h>
#include <sandesha2_sender_bean.h>
#include <sandesha2_sender_mgr.h>
#include <axis2_addr.h>
#include <axis2_engine.h>
#include <axutil_uuid_gen.h>
#include <axutil_rand.h>
#include <stdio.h>
#include <platforms/axutil_platform_auto_sense.h>
#include <axutil_types.h>


/** 
 * @brief Polling Manager struct impl
 *	Sandesha2 Polling Manager
 */
typedef struct sandesha2_polling_mgr_args sandesha2_polling_mgr_args_t;

struct sandesha2_polling_mgr_t
{
	axis2_conf_ctx_t *conf_ctx;
    /**
     * By adding an entry to this, the polling_mgr will be asked to do a polling 
     * request on this sequence.
     */
    axutil_array_list_t *scheduled_polling_reqs;
    axis2_bool_t poll;
    axutil_thread_mutex_t *mutex;
};

struct sandesha2_polling_mgr_args
{
    sandesha2_polling_mgr_t *impl;
    axutil_env_t *env;
    sandesha2_storage_mgr_t *storage_mgr;
};
            
static axis2_status_t AXIS2_CALL 
sandesha2_polling_mgr_run (
    sandesha2_polling_mgr_t *polling_mgr,
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr);

/**
 * Thread worker function.
 */
static void * AXIS2_THREAD_FUNC
sandesha2_polling_mgr_worker_func(
    axutil_thread_t *thd, 
    void *data);

AXIS2_EXTERN sandesha2_polling_mgr_t* AXIS2_CALL
sandesha2_polling_mgr_create(
    const axutil_env_t *env)
{
    sandesha2_polling_mgr_t *polling_mgr = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    polling_mgr =  (sandesha2_polling_mgr_t *)AXIS2_MALLOC 
        (env->allocator, 
        sizeof(sandesha2_polling_mgr_t));
	
    if(!polling_mgr)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    polling_mgr->scheduled_polling_reqs = NULL;
    polling_mgr->poll = AXIS2_FALSE; 
    polling_mgr->mutex = axutil_thread_mutex_create(env->allocator,
        AXIS2_THREAD_MUTEX_DEFAULT);
                        
	return polling_mgr;
}

axis2_status_t AXIS2_CALL
sandesha2_polling_mgr_free_void_arg(
    void *polling_mgr,
    const axutil_env_t *env)
{
    sandesha2_polling_mgr_t *polling_mgr_l = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    polling_mgr_l = (sandesha2_polling_mgr_t *) polling_mgr;
    return sandesha2_polling_mgr_free(polling_mgr_l, env);
}

axis2_status_t AXIS2_CALL 
sandesha2_polling_mgr_free(
    sandesha2_polling_mgr_t *polling_mgr, 
    const axutil_env_t *env)
{
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    /* Do not free this */
    polling_mgr->conf_ctx = NULL;
    
    if(polling_mgr->mutex)
    {
        axutil_thread_mutex_destroy(polling_mgr->mutex);
        polling_mgr->mutex = NULL;
    }
    if(polling_mgr->scheduled_polling_reqs)
    {
        axutil_array_list_free(polling_mgr->scheduled_polling_reqs, env);
        polling_mgr->scheduled_polling_reqs = NULL;
    }
	AXIS2_FREE(env->allocator, polling_mgr);
	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL 
sandesha2_polling_mgr_stop_polling (
    sandesha2_polling_mgr_t *polling_mgr,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    sandesha2_polling_mgr_set_poll(polling_mgr, env, AXIS2_FALSE);
    return AXIS2_SUCCESS;
}
            
axis2_status_t AXIS2_CALL 
sandesha2_polling_mgr_start (
    sandesha2_polling_mgr_t *polling_mgr, 
    const axutil_env_t *env, 
    axis2_conf_ctx_t *conf_ctx,
    const axis2_char_t *internal_seq_id)
{
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, AXIS2_FAILURE);
    
    axutil_thread_mutex_lock(polling_mgr->mutex);
    polling_mgr->conf_ctx = conf_ctx;
    polling_mgr->scheduled_polling_reqs = axutil_array_list_create(env, 
        AXIS2_ARRAY_LIST_DEFAULT_CAPACITY);

    if(!polling_mgr->conf_ctx)
    {
        axutil_thread_mutex_unlock(polling_mgr->mutex);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "conf_ctx is NULL");
        return AXIS2_FAILURE;
    }
    storage_mgr = sandesha2_utils_get_storage_mgr(env, 
        polling_mgr->conf_ctx, 
        axis2_conf_ctx_get_conf(polling_mgr->conf_ctx, env));
    sandesha2_polling_mgr_set_poll(polling_mgr, env, AXIS2_TRUE);
    sandesha2_polling_mgr_schedule_polling_request(polling_mgr, env, 
        internal_seq_id);
    sandesha2_polling_mgr_run(polling_mgr, env, storage_mgr);
    axutil_thread_mutex_unlock(polling_mgr->mutex);
    return AXIS2_SUCCESS;
}
            
static axis2_status_t AXIS2_CALL 
sandesha2_polling_mgr_run (
    sandesha2_polling_mgr_t *polling_mgr,
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr)
{
    axutil_thread_t *worker_thread = NULL;
    sandesha2_polling_mgr_args_t *args = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    args = AXIS2_MALLOC(env->allocator, sizeof(
                        sandesha2_polling_mgr_args_t)); 
    args->impl = polling_mgr;
    args->env = (axutil_env_t*)env;
    args->storage_mgr = storage_mgr;
    worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
        sandesha2_polling_mgr_worker_func, (void*)args);
    if(!worker_thread)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed" \
            " sandesha2_polling_mgr_run");
        return AXIS2_FAILURE;
    }
    axutil_thread_pool_thread_detach(env->thread_pool, worker_thread); 
        
    return AXIS2_SUCCESS;
}

/**
 * Thread worker function.
 */
static void * AXIS2_THREAD_FUNC
sandesha2_polling_mgr_worker_func(
    axutil_thread_t *thd, 
    void *data)
{
    sandesha2_polling_mgr_t *polling_mgr = NULL;
    sandesha2_polling_mgr_args_t *args;
    sandesha2_storage_mgr_t *storage_mgr;
    axutil_env_t *env = NULL;
    
    args = (sandesha2_polling_mgr_args_t*)data;
    env = args->env;
    polling_mgr = args->impl;
    storage_mgr = args->storage_mgr;

    while(polling_mgr->poll)
    {
        sandesha2_next_msg_mgr_t *next_msg_mgr = NULL;
        sandesha2_next_msg_bean_t *next_msg_bean = NULL;
        sandesha2_msg_ctx_t *ref_rm_msg_ctx = NULL;
        sandesha2_msg_ctx_t *make_conn_rm_msg_ctx = NULL;
        sandesha2_sender_bean_t *make_conn_sender_bean = NULL;
        sandesha2_sender_mgr_t *sender_bean_mgr = NULL;
        int size = 0;
        axis2_char_t *seq_id = NULL;
        axis2_char_t *make_conn_seq_id = NULL;
        axis2_char_t *ref_msg_key = NULL;
        axis2_char_t *seq_prop_key = NULL;
        axis2_char_t *reply_to = NULL;
        axis2_char_t *wsrm_anon_reply_to_uri = NULL;
        axis2_char_t *make_conn_msg_store_key = NULL;
        axis2_char_t *msg_id = NULL;
        axis2_msg_ctx_t *ref_msg_ctx = NULL;
        axis2_msg_ctx_t *make_conn_msg_ctx = NULL;
        axis2_endpoint_ref_t *to = NULL;
        axutil_property_t *property = NULL;
        axutil_qname_t *qname = NULL;
        axutil_param_t *wait_time_param = NULL;
        int wait_time = 0;
        axis2_conf_t *conf = NULL;
        axis2_module_desc_t *module_desc = NULL;
        sandesha2_transaction_t *transaction = NULL;
        axis2_status_t status = AXIS2_FAILURE;

        conf = axis2_conf_ctx_get_conf(polling_mgr->conf_ctx, env);
        qname = axutil_qname_create(env, "sandesha2", NULL, NULL);
        module_desc = axis2_conf_get_module(conf, env, qname);
        wait_time_param = axis2_module_desc_get_param(module_desc, env, 
            SANDESHA2_POLLING_WAIT);
        if(wait_time_param)
        {
            wait_time = AXIS2_ATOI(axutil_param_get_value(wait_time_param, env));
        }
        axutil_qname_free(qname, env);
        AXIS2_SLEEP(wait_time);
        transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, env);
        next_msg_mgr = sandesha2_storage_mgr_get_next_msg_mgr(
                        storage_mgr, env);
         /* Getting the sequences to be polled. if schedule contains any requests, 
          * do the earliest one. else pick one randomly.
          */
        if(polling_mgr->scheduled_polling_reqs)
            size = axutil_array_list_size(polling_mgr->scheduled_polling_reqs, 
                env);
        if(size > 0)
        {
            seq_id = axutil_array_list_get(polling_mgr->scheduled_polling_reqs, 
                env, 0);
            /*axutil_array_list_remove(polling_mgr->scheduled_polling_reqs, env, 0);*/
        }
        if(!seq_id)
        {
            sandesha2_next_msg_bean_t *find_bean = 
                sandesha2_next_msg_bean_create(env);
            int size = 0;
            if(find_bean)
            {
                axutil_array_list_t *results = NULL;
                sandesha2_next_msg_bean_set_polling_mode(find_bean, env, 
                    AXIS2_TRUE);
                results = sandesha2_next_msg_mgr_find(next_msg_mgr, env, 
                    find_bean);
                if(results)
                    size = axutil_array_list_size(results, env);
                if(size > 0)
                {
                    unsigned int rand_var = 
                        axutil_rand_get_seed_value_based_on_time(env);
                    int item = axutil_rand_with_range(&rand_var, 0, size);
                    item--;
                    next_msg_bean = (sandesha2_next_msg_bean_t *) 
                        axutil_array_list_get(results, env, item);
                }

            }
        }
        else
        {
            sandesha2_next_msg_bean_t *find_bean = 
                sandesha2_next_msg_bean_create(env);
            if(find_bean)
            {
                sandesha2_next_msg_bean_set_polling_mode(find_bean, env, 
                    AXIS2_TRUE);
                sandesha2_next_msg_bean_set_internal_seq_id(find_bean, env, seq_id);
                next_msg_bean = sandesha2_next_msg_mgr_find_unique(next_msg_mgr,
                    env, find_bean);
            }
        }
        /* If no valid entry is found, try again later */
        if(!next_msg_bean)
        {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "No valid MakeConnection entry is found.");
            sandesha2_transaction_rollback(transaction, env);
            continue;
        }
        make_conn_seq_id = sandesha2_next_msg_bean_get_seq_id((sandesha2_rm_bean_t *) 
            next_msg_bean, env);
        /* Create a MakeConnection message */
        ref_msg_key = sandesha2_next_msg_bean_get_ref_msg_key(next_msg_bean, env);
        seq_prop_key = make_conn_seq_id;
        reply_to = sandesha2_utils_get_seq_property(env, seq_prop_key, 
            SANDESHA2_SEQ_PROP_REPLY_TO_EPR, storage_mgr);
        if(sandesha2_utils_is_wsrm_anon_reply_to(env, reply_to))
            wsrm_anon_reply_to_uri = reply_to;
        ref_msg_ctx = sandesha2_storage_mgr_retrieve_msg_ctx(storage_mgr, env, 
            ref_msg_key, polling_mgr->conf_ctx, AXIS2_FALSE);
        if(ref_msg_ctx)
            ref_rm_msg_ctx = sandesha2_msg_init_init_msg(env, ref_msg_ctx);
        make_conn_rm_msg_ctx = 
            sandesha2_msg_creator_create_make_connection_msg(env, 
            ref_rm_msg_ctx, make_conn_seq_id, wsrm_anon_reply_to_uri, storage_mgr);
        if(!make_conn_rm_msg_ctx)
        {
            sandesha2_transaction_rollback(transaction, env);
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "No memory");
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
            return NULL;
        }
        sandesha2_msg_ctx_set_property(make_conn_rm_msg_ctx, env, 
            AXIS2_TRANSPORT_IN, NULL);
        /* Storing the MakeConnection message */
        make_conn_msg_store_key = axutil_uuid_gen(env);
        property = axutil_property_create_with_args(env, 0, 0, 0, seq_prop_key);
        sandesha2_msg_ctx_set_property(make_conn_rm_msg_ctx, env, 
            SANDESHA2_MSG_CTX_PROP_SEQUENCE_PROPERTY_KEY, property); 
        make_conn_msg_ctx = sandesha2_msg_ctx_get_msg_ctx(make_conn_rm_msg_ctx, 
            env);
        sandesha2_storage_mgr_store_msg_ctx(storage_mgr, env, 
            make_conn_msg_store_key, make_conn_msg_ctx);
        /* Adde an entry for the MakeConnection message to the sender(with, 
         * send=true, resend=false)
         */
        make_conn_sender_bean = sandesha2_sender_bean_create(env);
        if(make_conn_sender_bean)
        {
            long millisecs = 0;
            millisecs = sandesha2_utils_get_current_time_in_millis(env);
            sandesha2_sender_bean_set_time_to_send(make_conn_sender_bean, env, 
                millisecs);
            sandesha2_sender_bean_set_msg_ctx_ref_key(make_conn_sender_bean, env, 
                make_conn_msg_store_key);
            msg_id = sandesha2_msg_ctx_get_msg_id(make_conn_rm_msg_ctx, env);
            sandesha2_sender_bean_set_msg_id(make_conn_sender_bean, env, msg_id);
            sandesha2_sender_bean_set_msg_type(make_conn_sender_bean, env, 
                SANDESHA2_MSG_TYPE_MAKE_CONNECTION_MSG);
            sandesha2_sender_bean_set_resend(make_conn_sender_bean, env, AXIS2_FALSE);
            sandesha2_sender_bean_set_send(make_conn_sender_bean, env, AXIS2_TRUE);
            sandesha2_sender_bean_set_seq_id(make_conn_sender_bean, env, seq_id);
            to = sandesha2_msg_ctx_get_to(make_conn_rm_msg_ctx, env);
            if(to)
            {
                axis2_char_t *address = (axis2_char_t *) 
                    axis2_endpoint_ref_get_address(
                    (const axis2_endpoint_ref_t *) to, env);
                sandesha2_sender_bean_set_to_address(make_conn_sender_bean, env, 
                    address);
            }
        }
        sender_bean_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, 
            env);
        /* This message should not be sent untils it is qualified. i.e. Till
         * it is sent through the sandesha2_transport_sender
         */
        property = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_FALSE);
        sandesha2_msg_ctx_set_property(make_conn_rm_msg_ctx, env, 
            SANDESHA2_QUALIFIED_FOR_SENDING, property);
        if(sender_bean_mgr)
        {
            sandesha2_sender_mgr_insert(sender_bean_mgr, env, 
                make_conn_sender_bean);
        }
        status = sandesha2_utils_execute_and_store(env, make_conn_rm_msg_ctx, 
            make_conn_msg_store_key);
        if(!status)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                "[sandesha2]make_connection sending failed");
            sandesha2_transaction_rollback(transaction, env);
            return NULL;
        }
        if(transaction)
        {
            sandesha2_transaction_commit(transaction, env);
        }
    }
    return NULL;
}

void AXIS2_CALL
sandesha2_polling_mgr_set_poll(
    sandesha2_polling_mgr_t *polling_mgr,
    const axutil_env_t *env,
    axis2_bool_t poll)
{
    polling_mgr->poll = poll;
}

axis2_bool_t AXIS2_CALL
sandesha2_polling_mgr_is_poll(
    sandesha2_polling_mgr_t *polling_mgr,
    const axutil_env_t *env)
{
    return polling_mgr->poll;
}

void AXIS2_CALL
sandesha2_polling_mgr_schedule_polling_request(
    sandesha2_polling_mgr_t *polling_mgr,
    const axutil_env_t *env,
    const axis2_char_t *internal_seq_id)
{
    if(!axutil_array_list_contains(polling_mgr->scheduled_polling_reqs, env, 
        (axis2_char_t *)internal_seq_id))
    {
        axutil_array_list_add(polling_mgr->scheduled_polling_reqs, env, 
            internal_seq_id);
    }
}

