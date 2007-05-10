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

#include <axis2_handler_desc.h>
#include <axutil_array_list.h>
#include <axis2_svc.h>
#include <axis2_msg_ctx.h>
#include <axutil_property.h>
#include <axis2_conf_ctx.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_transaction.h>
#include <sandesha2_msg_processor.h>
#include <sandesha2_ack_msg_processor.h>
#include <sandesha2_ack_req_msg_processor.h>
#include <sandesha2_msg_init.h>
#include <sandesha2_seq.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_seq_ack.h>
#include <sandesha2_ack_requested.h>

/*static const axutil_string_t *AXIS2_CALL
sandesha2_in_handler_get_name(
    const struct axis2_handler *handler, 
    const axutil_env_t *env);*/

static axis2_status_t AXIS2_CALL
sandesha2_in_handler_invoke(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);
                                             
/******************************************************************************/                         

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
sandesha2_in_handler_create(
    const axutil_env_t *env, 
    axutil_qname_t *qname) 
{
    axis2_handler_t *handler = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    handler = axis2_handler_create(env);
    if (!handler)
    {
        return NULL;
    }
   
    /* handler init is handled by conf loading, so no need to do it here */
    
    /* set the base struct's invoke op */
    axis2_handler_set_invoke(handler, env, sandesha2_in_handler_invoke);
    return handler;
}


static axis2_status_t AXIS2_CALL
sandesha2_in_handler_invoke(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    axutil_property_t *temp_prop = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_ctx_t *ctx = NULL;
    axis2_char_t *str_done = NULL;
    axis2_char_t *reinjected_msg = NULL;
    axis2_char_t *within_transaction_str = NULL;
    axis2_bool_t within_transaction = AXIS2_FALSE;
    axis2_bool_t rolled_back = AXIS2_FALSE;
    axis2_svc_t *svc = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_transaction_t *transaction = NULL;
    sandesha2_msg_ctx_t *rm_msg_ctx = NULL;
    sandesha2_msg_processor_t *msg_processor = NULL;
    sandesha2_seq_ack_t *seq_ack = NULL;
    sandesha2_ack_requested_t *ack_requested = NULL;
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    
    AXIS2_LOG_INFO(env->log, "[sandesha2] Start: sandesha2_in_handler_invoke");

    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if(!conf_ctx)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "[sandesha2] Configuration Context is NULL");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CONF_CTX_NULL, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    ctx = axis2_msg_ctx_get_base(msg_ctx, env);
    temp_prop = axis2_ctx_get_property(ctx, env, 
            SANDESHA2_APPLICATION_PROCESSING_DONE);
    if(temp_prop)
        str_done = (axis2_char_t *) axutil_property_get_value(temp_prop, env); 
    if(str_done && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, str_done))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Application processing done");
        return AXIS2_SUCCESS;
    }
    temp_prop = axis2_ctx_get_property(ctx, env, SANDESHA2_REINJECTED_MESSAGE);
    if(temp_prop)
        reinjected_msg = (axis2_char_t *) axutil_property_get_value(temp_prop, 
                        env);
    if(reinjected_msg && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, reinjected_msg))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Reinjected_msg. So return here");
        return AXIS2_SUCCESS; /* Reinjected Messages are not processed by 
                                 sandesha2 inflow handlers */
    }
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    temp_prop = NULL;
    temp_prop = axis2_ctx_get_property(ctx, env, 
            SANDESHA2_WITHIN_TRANSACTION);
    if(temp_prop)
        within_transaction_str = (axis2_char_t *) axutil_property_get_value(
                        temp_prop, env);
    if(within_transaction_str && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, 
                within_transaction_str))
    {
        within_transaction = AXIS2_TRUE;
    }
    if(!within_transaction)
    {
        axutil_property_t *prop = NULL;
        transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, env);
        prop = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
        axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, prop);
    }
    svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if(!svc)
    {
        if(!within_transaction)
        {
            axutil_property_t *prop = NULL;
            sandesha2_transaction_rollback(transaction, env);
            prop = axutil_property_create_with_args(env, 0, 0, 0, 
                AXIS2_VALUE_FALSE);
            axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, 
                prop);
            rolled_back = AXIS2_TRUE;
        }
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "[sandesha2] Axis2 Service is NULL");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SVC_NULL, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    rm_msg_ctx = sandesha2_msg_init_init_msg(env, msg_ctx);

    if(!AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        /* Message should not be sent in an exception situation */
        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
        if(!within_transaction)
        {
            axutil_property_t *prop = NULL;

            sandesha2_transaction_rollback(transaction, env);
            prop = axutil_property_create_with_args(env, 0, 0, 0, 
                AXIS2_VALUE_FALSE);
            axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, 
                    prop);
            rolled_back = AXIS2_TRUE;
            
        }
        if(!within_transaction && !rolled_back)
        {
            axutil_property_t *prop = NULL;
            sandesha2_transaction_commit(transaction, env);
            prop = axutil_property_create_with_args(env, 0, 0, 0, 
                AXIS2_VALUE_FALSE);
            axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, 
                prop);
        }
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Cannot initialize the message");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CANNOT_INIT_MSG, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    /* 
     * TODO Validate the message
     * SANDESHA2_MSG_VALIDATOR_VALIDATE(env, rm_msg_ctx, storage_mgr);
     */
    seq_ack = (sandesha2_seq_ack_t*)sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, 
        env, SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT);
    if(seq_ack)
    {
        sandesha2_msg_processor_t *ack_proc = NULL;
        ack_proc = sandesha2_ack_msg_processor_create(env);
        sandesha2_msg_processor_process_in_msg(ack_proc, env, rm_msg_ctx);
    }
    ack_requested = (sandesha2_ack_requested_t*)sandesha2_msg_ctx_get_msg_part(
        rm_msg_ctx, env, SANDESHA2_MSG_PART_ACK_REQUEST);
    if(ack_requested)
    {
        sandesha2_ack_requested_set_must_understand(ack_requested, env, 
            AXIS2_FALSE);
        sandesha2_msg_ctx_add_soap_envelope(rm_msg_ctx, env);
    }
    msg_processor = sandesha2_msg_processor_create_msg_processor(env, 
        rm_msg_ctx);
    if(msg_processor)
    {
        sandesha2_msg_processor_process_in_msg(msg_processor, env, rm_msg_ctx);
    }
    if(!within_transaction && !rolled_back)
    {
        axutil_property_t *prop = NULL;
        sandesha2_transaction_commit(transaction, env);
        prop = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_FALSE);
        axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, 
            prop);
    }
    AXIS2_LOG_INFO(env->log, "[sandesha2] Exit: sandesha2_in_handler_invoke");
   
    return AXIS2_SUCCESS;
}

/*static const axutil_string_t *AXIS2_CALL
sandesha2_in_handler_get_name(
    const struct axis2_handler *handler, 
    const axutil_env_t *env)
{
    return axutil_string_create(env, SANDESHA2_IN_HANDLER_NAME);
}*/

