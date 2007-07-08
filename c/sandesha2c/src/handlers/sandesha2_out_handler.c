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
#include <sandesha2_seq.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_transaction.h>
#include <sandesha2_msg_processor.h>
#include <sandesha2_msg_init.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <sandesha2_app_msg_processor.h>
#include <sandesha2_client_constants.h>
#include <sandesha2_sender_mgr.h>
#include <platforms/axutil_platform_auto_sense.h>

axutil_string_t *AXIS2_CALL
sandesha2_out_handler_get_name(
    struct axis2_handler *handler, 
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_out_handler_invoke(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);
                                         
/******************************************************************************/                         

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
sandesha2_out_handler_create(
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
    axis2_handler_set_invoke(handler, env, sandesha2_out_handler_invoke);

    return handler;
}


axis2_status_t AXIS2_CALL
sandesha2_out_handler_invoke(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    axutil_property_t *temp_prop = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_char_t *str_done = NULL;
    axis2_char_t *dummy_msg_str = NULL;
    axis2_char_t *within_transaction_str = NULL;
    axis2_bool_t within_transaction = AXIS2_FALSE;
    axis2_bool_t rolled_back = AXIS2_FALSE;
    axis2_bool_t dummy_msg = AXIS2_FALSE;
    axis2_svc_t *svc = NULL;
    axutil_qname_t *module_qname = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_transaction_t *transaction = NULL;
    sandesha2_msg_ctx_t *rm_msg_ctx = NULL;
    sandesha2_msg_processor_t *msg_processor = NULL;
    int msg_type = -1;

    AXIS2_ENV_CHECK( env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  "[sandesha2] Start: sandesha2_out_handler_invoke");
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if(!conf_ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Configuration Context is NULL");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CONF_CTX_NULL, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if(!svc)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Axis2 Service is NULL");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SVC_NULL, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    module_qname = axutil_qname_create(env, "sandesha2", NULL, NULL);
    if(!axis2_svc_is_module_engaged(svc, env, module_qname))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] RM is not engaged. So return here");
        return AXIS2_SUCCESS;
    }
    axutil_qname_free(module_qname, env);
    if(!axis2_msg_ctx_get_server_side(msg_ctx, env))
    {
        axis2_ctx_t *conf_ctx_base = axis2_conf_ctx_get_base(conf_ctx, env);
        axutil_property_t *property = axutil_property_create_with_args(env, 0, 0, 
            0, NULL);
        axis2_ctx_set_property(conf_ctx_base, env, SANDESHA2_IS_SVR_SIDE, 
            property);
    }
    else
    {
        int size = -1, i = 0;
		axis2_bool_t found = AXIS2_FALSE;
		axutil_array_list_t *mod_qnames = NULL;
        axutil_qname_t *mod_qname = axutil_qname_create(env, "sandesha2", NULL, NULL);
		mod_qnames = (axutil_array_list_t *)axis2_svc_get_all_module_qnames(svc, env);
        size = axutil_array_list_size(mod_qnames, env);
        
        for (i = 0; i < size; i++)
        {
            axutil_qname_t *qname = NULL;
            qname = axutil_array_list_get(mod_qnames, env, i);
            if (qname)
            {
                found = axutil_qname_equals(mod_qname, env, qname);
                if (found)
                    break;
            }
        }
        if (!found)
        {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "[sandesha2] RM is not engaged. So return here.");
            return AXIS2_SUCCESS;
        }
    }
    temp_prop = axis2_msg_ctx_get_property(msg_ctx, env, 
            SANDESHA2_APPLICATION_PROCESSING_DONE);
    if(temp_prop)
        str_done = (axis2_char_t *) axutil_property_get_value(temp_prop, env); 
    if(str_done && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, str_done))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Application Processing Done. So return here.");
        return AXIS2_SUCCESS; 
    }
    temp_prop = axutil_property_create_with_args(env, 0, 0, 0, AXIS2_VALUE_TRUE);
    axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_APPLICATION_PROCESSING_DONE, 
            temp_prop);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    temp_prop = axis2_msg_ctx_get_property(msg_ctx, env, 
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
        prop = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_TRUE);
        axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_WITHIN_TRANSACTION, prop);
    }
    /* Getting rm message */ 
    rm_msg_ctx = sandesha2_msg_init_init_msg(env, msg_ctx);
    temp_prop = axis2_msg_ctx_get_property(msg_ctx, env, SANDESHA2_CLIENT_DUMMY_MESSAGE);
    if(NULL != temp_prop)
        dummy_msg_str = (axis2_char_t *) axutil_property_get_value(temp_prop, env); 
    if(dummy_msg_str && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, dummy_msg_str))
    {
        dummy_msg = AXIS2_TRUE;
    }
    msg_type = sandesha2_msg_ctx_get_msg_type(rm_msg_ctx, env);
    if(msg_type == SANDESHA2_MSG_TYPE_UNKNOWN)
    {
        axis2_msg_ctx_t *req_msg_ctx = NULL;
        axis2_op_ctx_t *op_ctx = NULL;

        op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
        req_msg_ctx =  axis2_op_ctx_get_msg_ctx(op_ctx, env, 
            AXIS2_WSDL_MESSAGE_LABEL_IN);
        if(req_msg_ctx) /* For the server side */
        {
            sandesha2_msg_ctx_t *req_rm_msg_ctx = NULL;
            sandesha2_seq_t *seq_part = NULL;

            req_rm_msg_ctx = sandesha2_msg_init_init_msg(env, req_msg_ctx);
            seq_part = (sandesha2_seq_t *) sandesha2_msg_ctx_get_msg_part(
                    req_rm_msg_ctx, env, SANDESHA2_MSG_PART_SEQ);
            
            if(seq_part)
            {
                msg_processor = (sandesha2_msg_processor_t *) 
                sandesha2_app_msg_processor_create(env); /* rm intended msg */
            }
        }
        else if(!axis2_msg_ctx_get_server_side(msg_ctx, env))
        {
            msg_processor = (sandesha2_msg_processor_t *) 
            sandesha2_app_msg_processor_create(env);
        }
    }
    else
    {
        msg_processor = sandesha2_msg_processor_create_msg_processor(env, 
            rm_msg_ctx);
    }
    if(msg_processor)
    {
        sandesha2_msg_processor_process_out_msg(msg_processor, env, rm_msg_ctx);
    }
    if(AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        /* Message should not be sent in an exception situation */
        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
        /* Rolling back the transaction */
        if(!within_transaction)
        {
            axutil_property_t *prop = NULL;
            sandesha2_transaction_rollback(transaction, env);
            prop = axutil_property_create_with_args(env, 0, 0, 0, 
                AXIS2_VALUE_FALSE);
            axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_WITHIN_TRANSACTION, 
                prop);
            rolled_back = AXIS2_TRUE;
        }
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Error in processing the message");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CANNOT_PROCESS_MSG, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    if(!within_transaction && !rolled_back)
    {
        axutil_property_t *prop = NULL;
        sandesha2_transaction_commit(transaction, env);
        prop = axutil_property_create_with_args(env, 0, 0, 0, 
            AXIS2_VALUE_FALSE);
        axis2_msg_ctx_set_property(msg_ctx, env, SANDESHA2_WITHIN_TRANSACTION, 
            prop);
    }
    
    temp_prop = axis2_msg_ctx_get_property(msg_ctx, env, 
            SANDESHA2_APPLICATION_PROCESSING_DONE);
    if(temp_prop)
        axutil_property_set_value(temp_prop, env, axutil_strdup(
            env,AXIS2_VALUE_FALSE));
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Exit: "
            "sandesha2_out_handler_invoke");
    return AXIS2_SUCCESS;
}

axutil_string_t *AXIS2_CALL
sandesha2_out_handler_get_name(
    struct axis2_handler *handler, 
    const axutil_env_t *env)
{
    return axutil_string_create(env, SANDESHA2_OUT_HANDLER_NAME);
}

