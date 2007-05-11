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
#include <sandesha2_sender_worker.h>
#include <sandesha2_ack_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_transaction.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_sender_mgr.h>
#include <sandesha2_seq_property_bean.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_seq.h>
#include <axis2_addr.h>
#include <axis2_engine.h>
#include <stdlib.h>
#include <axis2_http_transport.h>
#include <axis2_http_transport_utils.h>
#include <axiom_soap_const.h>
#include <axiom_soap_fault.h>
#include <axiom_soap_body.h>
#include <sandesha2_msg_init.h>
#include <sandesha2_terminate_seq.h>
#include <sandesha2_terminate_seq_res.h>
#include <sandesha2_terminate_mgr.h>
#include <sandesha2_msg_retrans_adjuster.h>
#include <platforms/axutil_platform_auto_sense.h>

/** 
 * @brief Sender struct impl
 *	Sandesha2 Sender Invoker
 */
typedef struct sandesha2_sender_worker_args sandesha2_sender_worker_args_t;

struct sandesha2_sender_worker_t
{
	axis2_conf_ctx_t *conf_ctx;
    axutil_thread_mutex_t *mutex;
    int counter;
    axis2_char_t *msg_id;
    axis2_msg_ctx_t *msg_ctx;
    axis2_transport_out_desc_t *transport_out;
    axis2_status_t status;
};

struct sandesha2_sender_worker_args
{
    sandesha2_sender_worker_t *impl;
    axutil_env_t *env;
};

axis2_status_t AXIS2_CALL 
sandesha2_sender_worker_get_status (
    sandesha2_sender_worker_t *sender_worker,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL 
sandesha2_sender_worker_run (
    sandesha2_sender_worker_t *sender_worker,
    const axutil_env_t *env);
                        
static void * AXIS2_THREAD_FUNC
sandesha2_sender_worker_worker_func(
    axutil_thread_t *thd, 
    void *data);

static axis2_bool_t AXIS2_CALL
sandesha2_sender_worker_is_piggybackable_msg_type(
    sandesha2_sender_worker_t *sender_worker, 
    const axutil_env_t *env, 
    int msg_type);

static axis2_bool_t AXIS2_CALL
sandesha2_sender_worker_is_ack_already_piggybacked(
    sandesha2_sender_worker_t *sender_worker, 
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx);

static axis2_status_t AXIS2_CALL
sandesha2_sender_worker_check_for_sync_res(
    const axutil_env_t *env, 
    axis2_msg_ctx_t *msg_ctx);

static axis2_bool_t AXIS2_CALL
sandesha2_sender_worker_is_fault_envelope(
    const axutil_env_t *env, 
    axiom_soap_envelope_t *soap_envelope);

axis2_status_t AXIS2_CALL 
sandesha2_sender_worker_free(
    sandesha2_sender_worker_t *sender_worker, 
    const axutil_env_t *env);								


AXIS2_EXTERN sandesha2_sender_worker_t* AXIS2_CALL
sandesha2_sender_worker_create(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *msg_id)
{
    sandesha2_sender_worker_t *sender_worker = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    sender_worker =  (sandesha2_sender_worker_t *)AXIS2_MALLOC 
                        (env->allocator, 
                        sizeof(sandesha2_sender_worker_t));
	
    if(!sender_worker)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    sender_worker->conf_ctx = conf_ctx;
    sender_worker->mutex = NULL;
    sender_worker->counter = 0;
    sender_worker->msg_id = axutil_strdup(env, msg_id);
    sender_worker->msg_ctx = NULL;
    sender_worker->transport_out = NULL;
    sender_worker->status = AXIS2_FAILURE;
    
    sender_worker->mutex = axutil_thread_mutex_create(env->allocator,
                        AXIS2_THREAD_MUTEX_DEFAULT);
                        
	return sender_worker;
}

AXIS2_EXTERN sandesha2_sender_worker_t* AXIS2_CALL
sandesha2_sender_worker_create_with_msg_ctx(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *msg_id,
    axis2_msg_ctx_t *msg_ctx)
{
    sandesha2_sender_worker_t *sender_worker = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    
    sender_worker =  (sandesha2_sender_worker_t *)AXIS2_MALLOC 
        (env->allocator, sizeof(sandesha2_sender_worker_t));
	
    if(!sender_worker)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
	}
    sender_worker->conf_ctx = conf_ctx;
    sender_worker->mutex = NULL;
    sender_worker->counter = 0;
    sender_worker->msg_id = axutil_strdup(env, msg_id);
    sender_worker->msg_ctx = msg_ctx;
    sender_worker->transport_out = NULL;
    sender_worker->status = AXIS2_FAILURE;
    
    sender_worker->mutex = axutil_thread_mutex_create(env->allocator,
                        AXIS2_THREAD_MUTEX_DEFAULT);
                        
	return sender_worker;
}

axis2_status_t AXIS2_CALL
sandesha2_sender_worker_free_void_arg(
    void *sender_worker,
    const axutil_env_t *env)
{
    sandesha2_sender_worker_t *sender_worker_l = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    sender_worker_l = (sandesha2_sender_worker_t *) sender_worker;
    return sandesha2_sender_worker_free(sender_worker_l, env);
}

axis2_status_t AXIS2_CALL 
sandesha2_sender_worker_free(
    sandesha2_sender_worker_t *sender_worker, 
    const axutil_env_t *env)
{
	AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    /* Do not free this */
    sender_worker->conf_ctx = NULL;
    
    if(sender_worker->mutex)
    {
        axutil_thread_mutex_destroy(sender_worker->mutex);
        sender_worker->mutex = NULL;
    }
    if(sender_worker->msg_id)
    {
        AXIS2_FREE(env->allocator, sender_worker->msg_id);
        sender_worker->msg_id = NULL;
    }
	AXIS2_FREE(env->allocator, sender_worker);
	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL 
sandesha2_sender_worker_run (
    sandesha2_sender_worker_t *sender_worker,
    const axutil_env_t *env)
{
    axutil_thread_t *worker_thread = NULL;
    sandesha2_sender_worker_args_t *args = NULL;

    AXIS2_LOG_INFO(env->log, "Start:sandesha2_sender_worker_run");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    sender_worker->status = AXIS2_TRUE;
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_sender_worker_args_t)); 
    args->impl = sender_worker;
    args->env = (axutil_env_t*)env;

    worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
        sandesha2_sender_worker_worker_func, (void*)args);
    if(!worker_thread)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]Thread creation "
                        "failed sandesha2_sender_worker_run");
        return AXIS2_FAILURE;
    }
    axutil_thread_pool_thread_detach(env->thread_pool, worker_thread); 
    AXIS2_LOG_INFO(env->log, "Exit:sandesha2_sender_worker_run");
    return AXIS2_SUCCESS;
}

/**
 * Thread worker function.
 */
static void * AXIS2_THREAD_FUNC
sandesha2_sender_worker_worker_func(
    axutil_thread_t *thd, 
    void *data)
{
    sandesha2_sender_worker_t *sender_worker = NULL;
    sandesha2_sender_worker_args_t *args;
    axutil_env_t *env = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_transaction_t *transaction = NULL;
    sandesha2_sender_bean_t *sender_worker_bean = NULL;
    sandesha2_sender_bean_t *bean1 = NULL;
    sandesha2_sender_mgr_t *sender_mgr = NULL;
    axis2_char_t *key = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axutil_property_t *property = NULL;
    axis2_bool_t continue_sending = AXIS2_TRUE;
    axis2_char_t *qualified_for_sending = NULL;
    sandesha2_msg_ctx_t *rm_msg_ctx = NULL;
    sandesha2_property_bean_t *prop_bean = NULL;
    axutil_array_list_t *msgs_not_to_send = NULL;
    int msg_type = -1;
    axis2_transport_out_desc_t *transport_out = NULL;
    axis2_transport_sender_t *transport_sender = NULL;
    axis2_bool_t successfully_sent = AXIS2_FALSE;
    axis2_char_t *msg_id = NULL;

    args = (sandesha2_sender_worker_args_t*)data;
    env = axutil_init_thread_env(args->env);
    sender_worker = args->impl;
    msg_id = sender_worker->msg_id;
    msg_ctx = sender_worker->msg_ctx;
    transport_out = sender_worker->transport_out;
    
    AXIS2_LOG_INFO(env->log, "[Sandesha2] Entry:sandesha2_sender_worker_worker_func\n");        
    
    storage_mgr = sandesha2_utils_get_storage_mgr(env, 
        sender_worker->conf_ctx, 
        axis2_conf_ctx_get_conf(sender_worker->conf_ctx, env));
    transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, env);
    sender_mgr = sandesha2_storage_mgr_get_retrans_mgr(storage_mgr, env);
    sender_worker_bean = sandesha2_sender_mgr_retrieve(sender_mgr, env, msg_id);
    if(!sender_worker_bean)
    {
        sandesha2_transaction_rollback(transaction, env);
        #ifdef AXIS2_SVR_MULTI_THREADED
            AXIS2_THREAD_POOL_EXIT_THREAD(env->thread_pool, thd);
        #endif
        return NULL;
    }

    key = sandesha2_sender_bean_get_msg_ctx_ref_key(sender_worker_bean, env);
    if(!msg_ctx)
    {
        axutil_allocator_switch_to_global_pool(env->allocator);
        msg_ctx = sandesha2_storage_mgr_retrieve_msg_ctx(storage_mgr, env, key, 
            sender_worker->conf_ctx, AXIS2_FALSE);
        axutil_allocator_switch_to_local_pool(env->allocator);
    }
    if(!msg_ctx)
    {
        sandesha2_transaction_rollback(transaction, env);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] msg_ctx is "
                    "not present in the store");
        #ifdef AXIS2_SVR_MULTI_THREADED
            AXIS2_THREAD_POOL_EXIT_THREAD(env->thread_pool, thd);
        #endif
        return NULL;
    }
    property = axis2_msg_ctx_get_property(msg_ctx, env, 
        SANDESHA2_WITHIN_TRANSACTION);
    if(property)
        axutil_property_set_value(property, env, AXIS2_VALUE_TRUE);
    else
    {
        property = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_TRUE);
        axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_WITHIN_TRANSACTION,
            property);
    }
    continue_sending = sandesha2_msg_retrans_adjuster_adjust_retrans(env,
        sender_worker_bean, sender_worker->conf_ctx, storage_mgr);
    sandesha2_sender_mgr_update(sender_mgr, env, sender_worker_bean);
    if(!continue_sending)
    {
        sender_worker->status = AXIS2_FAILURE;
        /* We commit here since we have cleaned the
         * sending side data and that need to commited */
        sandesha2_transaction_commit(transaction, env);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Do not continue sending the message");
        #ifdef AXIS2_SVR_MULTI_THREADED
            AXIS2_THREAD_POOL_EXIT_THREAD(env->thread_pool, thd);
        #endif
        return NULL;
    }
    
    property = axis2_msg_ctx_get_property(msg_ctx, env, 
        SANDESHA2_QUALIFIED_FOR_SENDING);
    if(property)
        qualified_for_sending = axutil_property_get_value(property, env);
    if(qualified_for_sending && 0 != axutil_strcmp(
        qualified_for_sending, AXIS2_VALUE_TRUE))
    {
        sandesha2_transaction_rollback(transaction, env);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Message is not qualified for sending");
        #ifdef AXIS2_SVR_MULTI_THREADED
            AXIS2_THREAD_POOL_EXIT_THREAD(env->thread_pool, thd);
        #endif
        return NULL;
    }
    rm_msg_ctx = sandesha2_msg_init_init_msg(env, msg_ctx);
    
    prop_bean = sandesha2_utils_get_property_bean(env, 
        axis2_conf_ctx_get_conf(sender_worker->conf_ctx, env));
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
            msg_type = sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, env);
            if(msg_type == int_val)
                continue_sending = AXIS2_TRUE;
        }
        if(continue_sending)
        {
            sandesha2_transaction_rollback(transaction, env);
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Continue "\
                "Sending is true. So returning from Sender Worker");
            #ifdef AXIS2_SVR_MULTI_THREADED
                AXIS2_THREAD_POOL_EXIT_THREAD(env->thread_pool, thd);
            #endif
            return NULL;
        }
    }
    /* 
     *  This method is not implemented yet
     *  update_msg(sender_worker, env, msg_xtx);
     */
    msg_type = sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, env);
    if(msg_type == SANDESHA2_MSG_TYPE_APPLICATION)
    {
        sandesha2_seq_t *seq = NULL;
        axis2_char_t *seq_id = NULL;
        sandesha2_identifier_t *identifier = NULL;
        
        seq = (sandesha2_seq_t*)
                    sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, 
                    env, SANDESHA2_MSG_PART_SEQ);
        identifier = sandesha2_seq_get_identifier(seq, env);
        seq_id = sandesha2_identifier_get_identifier(identifier, env);
    }
    if(sandesha2_sender_worker_is_piggybackable_msg_type(sender_worker, env,
        msg_type) && AXIS2_FALSE  == 
        sandesha2_sender_worker_is_ack_already_piggybacked(sender_worker, env,
        rm_msg_ctx))
    {
        sandesha2_ack_mgr_piggyback_acks_if_present(env, rm_msg_ctx, 
            storage_mgr);
    }
    
    if(!transport_out) 
        transport_out = axis2_msg_ctx_get_transport_out_desc(msg_ctx, env);
    transport_sender = axis2_transport_out_desc_get_sender(transport_out, env);
    if(transport_sender)
    {
        sandesha2_transaction_commit(transaction, env);
        property = axis2_msg_ctx_get_property(msg_ctx, env, 
            SANDESHA2_WITHIN_TRANSACTION);
        if(property)
            axutil_property_set_value(property, env, AXIS2_VALUE_FALSE);
        else
        {
            property = axutil_property_create_with_args(env, 0, 0, 0,
                AXIS2_VALUE_FALSE);
            axis2_msg_ctx_set_property(msg_ctx, env, 
                SANDESHA2_WITHIN_TRANSACTION, property);
        }
        /* This is neccessary to avoid a double free */
        axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_TRANSPORT_IN, NULL);
        /* Consider building soap envelope */
        if(AXIS2_TRANSPORT_SENDER_INVOKE(transport_sender, env, msg_ctx))
		{
        	successfully_sent = AXIS2_TRUE;
        	sender_worker->counter++;
		}else
		{
        	successfully_sent = AXIS2_FALSE;
		}
    }
    transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, env);
    property = axis2_msg_ctx_get_property(msg_ctx, env, 
        SANDESHA2_WITHIN_TRANSACTION); 
    if(property)
        axutil_property_set_value(property, env, AXIS2_VALUE_TRUE);
    else
    {
        property = axutil_property_create_with_args(env, 0, 0, 0,
            AXIS2_VALUE_TRUE);
        axis2_msg_ctx_set_property(msg_ctx, env, 
            SANDESHA2_WITHIN_TRANSACTION, property);
    }
    msg_id = sandesha2_sender_bean_get_msg_id((sandesha2_rm_bean_t *) 
        sender_worker_bean, env);
    bean1 = sandesha2_sender_mgr_retrieve(sender_mgr, env, msg_id);
    if(bean1)
    {
        axis2_bool_t resend = AXIS2_FALSE;
        
        resend = sandesha2_sender_bean_is_resend(sender_worker_bean, env);
        if(resend)
        {
            sandesha2_sender_bean_set_sent_count(bean1, env, 
                sandesha2_sender_bean_get_sent_count(sender_worker_bean, env));
            sandesha2_sender_bean_set_time_to_send(bean1, env, 
                sandesha2_sender_bean_get_time_to_send(sender_worker_bean, env));
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
    if(successfully_sent)
    {
        if(AXIS2_FALSE == axis2_msg_ctx_get_server_side(msg_ctx, env))
            sandesha2_sender_worker_check_for_sync_res(env, msg_ctx);
    }
    msg_type = sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, env);
    if(SANDESHA2_MSG_TYPE_TERMINATE_SEQ == msg_type)
    {
        sandesha2_terminate_seq_t *terminate_seq = NULL;
        axis2_char_t *seq_id = NULL;
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_char_t *internal_seq_id = NULL;
        
        terminate_seq = (sandesha2_terminate_seq_t*)
                    sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                    SANDESHA2_MSG_PART_TERMINATE_SEQ);
        seq_id = sandesha2_identifier_get_identifier(
                    sandesha2_terminate_seq_get_identifier(terminate_seq, 
                    env), env);
        conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        internal_seq_id = sandesha2_utils_get_seq_property(env, seq_id, 
                    SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID, storage_mgr);
        sandesha2_terminate_mgr_terminate_sending_side(env, conf_ctx,
            internal_seq_id, axis2_msg_ctx_get_server_side(msg_ctx, env), 
                storage_mgr);
        sender_worker->status = AXIS2_FAILURE;
    }
    property = axis2_msg_ctx_get_property(msg_ctx, env, 
        SANDESHA2_WITHIN_TRANSACTION);
    if(property)
        axutil_property_set_value(property, env, AXIS2_VALUE_FALSE);
    else
    {
        property = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_FALSE);
        axis2_msg_ctx_set_property(msg_ctx, env, 
                    SANDESHA2_WITHIN_TRANSACTION, property);
    }
    /* TODO make transaction handling effective */
    if(transaction)
    {
        sandesha2_transaction_commit(transaction, env);
    }
    #ifdef AXIS2_SVR_MULTI_THREADED
        AXIS2_THREAD_POOL_EXIT_THREAD(env->thread_pool, thd);
    #endif
    AXIS2_LOG_INFO(env->log, "[Sandesha2] Exit:sandesha2_sender_worker_worker_func\n");        
    return NULL;
}

static axis2_bool_t AXIS2_CALL
sandesha2_sender_worker_is_piggybackable_msg_type(
    sandesha2_sender_worker_t *sender_worker, 
    const axutil_env_t *env, 
    int msg_type)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(SANDESHA2_MSG_TYPE_ACK == msg_type)
        return AXIS2_FALSE;
    
    return AXIS2_TRUE;
}

static axis2_bool_t AXIS2_CALL
sandesha2_sender_worker_is_ack_already_piggybacked(
    sandesha2_sender_worker_t *sender_worker, 
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FAILURE);
    
    if(sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
        SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT))
        return AXIS2_TRUE;
    
    return AXIS2_FALSE;
}

static axis2_status_t AXIS2_CALL
sandesha2_sender_worker_check_for_sync_res(
    const axutil_env_t *env, 
    axis2_msg_ctx_t *msg_ctx)
{
    axutil_property_t *property = NULL;
    axutil_property_t *new_property = NULL;
    axis2_msg_ctx_t *res_msg_ctx = NULL;
    axis2_op_ctx_t *req_op_ctx = NULL;
    axiom_soap_envelope_t *res_envelope = NULL;
    axis2_char_t *soap_ns_uri = NULL;
   
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2] Start:sandesha2_sender_worker_check_for_sync_res");
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    /*property = axis2_msg_ctx_get_property(msg_ctx, env, AXIS2_TRANSPORT_IN);
    if(!property)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] transport_in property not found");
        return AXIS2_SUCCESS;
    }*/
        
    res_msg_ctx = axis2_msg_ctx_create(env, axis2_msg_ctx_get_conf_ctx(msg_ctx,
        env), axis2_msg_ctx_get_transport_in_desc(
        msg_ctx, env), axis2_msg_ctx_get_transport_out_desc(msg_ctx,
        env));
    /* Setting the message as serverSide will let it go through the 
     * Message Receiver (may be callback MR).
     */
    axis2_msg_ctx_set_server_side(res_msg_ctx, env, AXIS2_TRUE);
    property = axis2_msg_ctx_get_property(msg_ctx, env, AXIS2_TRANSPORT_IN);
    if(property)
    {
		axutil_property_t *temp_prop = NULL;
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "AXIS2_TRANSPORT_IN not NULL");
        temp_prop = axutil_property_clone(property, env);
        axis2_msg_ctx_set_property(res_msg_ctx, env, AXIS2_TRANSPORT_IN, 
            temp_prop);
    }
    else
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "AXIS2_TRANSPORT_IN NULL######################################3");

    axis2_msg_ctx_set_svc_ctx(res_msg_ctx, env, axis2_msg_ctx_get_svc_ctx(
        msg_ctx, env));
    axis2_msg_ctx_set_svc_grp_ctx(res_msg_ctx, env, 
        axis2_msg_ctx_get_svc_grp_ctx(msg_ctx, env));
    req_op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
    if(req_op_ctx)
    {
        axis2_ctx_t *ctx = NULL;
        
        ctx = axis2_op_ctx_get_base(req_op_ctx, env);
        if(axis2_ctx_get_property(ctx, env, MTOM_RECIVED_CONTENT_TYPE))
        {
            axis2_msg_ctx_set_property(res_msg_ctx, env, 
                MTOM_RECIVED_CONTENT_TYPE, axis2_ctx_get_property(ctx, env, 
                MTOM_RECIVED_CONTENT_TYPE));
        }
        if(axis2_ctx_get_property(ctx, env, AXIS2_HTTP_CHAR_SET_ENCODING))
        {
            axis2_msg_ctx_set_property(res_msg_ctx, env, 
                AXIS2_HTTP_CHAR_SET_ENCODING, axis2_ctx_get_property(ctx, env, 
                AXIS2_HTTP_CHAR_SET_ENCODING));
        }
    }
    axis2_msg_ctx_set_doing_rest(res_msg_ctx, env, axis2_msg_ctx_get_doing_rest(
        msg_ctx, env));
    soap_ns_uri = axis2_msg_ctx_get_is_soap_11(msg_ctx, env) ?
         AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI:
         AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;

    res_envelope = axis2_msg_ctx_get_response_soap_envelope(msg_ctx, env);
    if(!res_envelope)
        res_envelope = axis2_http_transport_utils_create_soap_msg(env, msg_ctx,
            soap_ns_uri);
    
    property = axis2_msg_ctx_get_property(msg_ctx, env, 
        SANDESHA2_WITHIN_TRANSACTION);
    if(property)
        new_property = axutil_property_clone(property, env);
    if(new_property)
        axis2_msg_ctx_set_property(res_msg_ctx, env, 
            SANDESHA2_WITHIN_TRANSACTION, new_property);
    if(res_envelope)
    {
        axis2_engine_t *engine = NULL;
        axis2_msg_ctx_set_soap_envelope(res_msg_ctx, env, res_envelope);
       
        engine = axis2_engine_create(env, axis2_msg_ctx_get_conf_ctx(msg_ctx, 
            env));
        if(AXIS2_TRUE == sandesha2_sender_worker_is_fault_envelope(env, 
            res_envelope))
            axis2_engine_receive_fault(engine, env, res_msg_ctx);
        else
            axis2_engine_receive(engine, env, res_msg_ctx);        
    }
    /* To avoid a second passing through incoming handlers at mep_client */
    property = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
    axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_HANDLER_ALREADY_VISITED, 
        property);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2] Exit:sandesha2_sender_worker_check_for_sync_res");
    return AXIS2_SUCCESS;
}

static axis2_bool_t AXIS2_CALL
sandesha2_sender_worker_is_fault_envelope(
    const axutil_env_t *env, 
    axiom_soap_envelope_t *soap_envelope)
{
    axiom_soap_fault_t *fault = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, soap_envelope, AXIS2_FAILURE);
    
    fault = axiom_soap_body_get_fault(axiom_soap_envelope_get_body(soap_envelope,
        env), env);
    if(fault)
        return AXIS2_TRUE;
        
    return AXIS2_FALSE;
}

void sandesha2_sender_worker_set_transport_out(
    sandesha2_sender_worker_t *sender_worker,
    const axutil_env_t *env,
    axis2_transport_out_desc_t *transport_out)
{
    sender_worker->transport_out = transport_out;
}

axis2_status_t AXIS2_CALL 
sandesha2_sender_worker_get_status (
    sandesha2_sender_worker_t *sender_worker,
    const axutil_env_t *env)
{
    return sender_worker->status;
}



