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
#include <axis2_const.h>
#include <axis2_conf_ctx.h>
#include <axiom_soap_header.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_seq.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_transaction.h>
#include <sandesha2_msg_processor.h>
#include <sandesha2_msg_init.h>
#include <sandesha2_constants.h>
#include <sandesha2_utils.h>
#include <axiom_soap_fault.h>
#include <axiom_soap_body.h>
#include <axis2_relates_to.h>
#include <sandesha2_seq_property_mgr.h>
#include <stdlib.h>
#include <sandesha2_seq.h>
#include <sandesha2_msg_number.h>
#include <sandesha2_identifier.h>
#include <sandesha2_app_msg_processor.h>
/*
static axutil_qname_t *AXIS2_CALL
sandesha2_global_in_handler_get_qname(
    struct axis2_handler *handler, 
    const axutil_env_t *env);
*/
static axis2_status_t AXIS2_CALL
sandesha2_global_in_handler_invoke(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);
    
static axis2_bool_t AXIS2_CALL
sandesha2_global_in_handler_drop_if_duplicate(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_mgr);        
                                             

static axis2_status_t AXIS2_CALL
sandesha2_global_in_handler_process_dropped_msg(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_mgr);                                             
/******************************************************************************/                         

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
sandesha2_global_in_handler_create(
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
    axis2_handler_set_invoke(handler, env, sandesha2_global_in_handler_invoke);

    return handler;
}


static axis2_status_t AXIS2_CALL
sandesha2_global_in_handler_invoke(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx)
{
    
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_ctx_t *ctx = NULL;
    axiom_soap_envelope_t *soap_envelope = NULL;
    axis2_bool_t within_transaction = AXIS2_FALSE;
    axis2_char_t *within_transaction_str = NULL;
    axiom_soap_fault_t *fault_part = NULL;
    axis2_char_t *reinjected_msg = AXIS2_FALSE;
    const axutil_string_t *str_soap_action = NULL;
    const axis2_char_t *wsa_action = NULL;
    const axis2_char_t *soap_action = NULL;
    axis2_bool_t is_rm_global_msg = AXIS2_FALSE;
    sandesha2_msg_ctx_t *rm_msg_ctx = NULL;
    axis2_bool_t dropped = AXIS2_FALSE;
    axis2_bool_t isolated_last_msg = AXIS2_FALSE;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_transaction_t *transaction = NULL;
    axutil_property_t *property = NULL;
    axis2_bool_t rolled_back = AXIS2_FALSE;
    AXIS2_ENV_CHECK( env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  "[sandesha2]Start:sandesha2_global_in_handler");
   /* This handler needs to identify messages which follow the WSRM 1.0 
    * convention for sending 'LastMessage' when the sender doesn't have a 
    * reliable message to piggyback the last message marker onto.
    * Normally they will identify this scenario with an action marker, but if
    * there is no action at all then we have to check the soap body.
    * Either way, all that this handler need do is set the action back onto
    * the message, so that the dispatchers can allow it to continue. The real
    * processing will be done in the app_msg_processor.
    */
    str_soap_action = axis2_msg_ctx_get_soap_action(msg_ctx, env);
    soap_action = axutil_string_get_buffer(str_soap_action, env);
    wsa_action = axis2_msg_ctx_get_wsa_action(msg_ctx, env);
    if(!soap_action && !wsa_action)
    {
        axiom_soap_envelope_t *envelope = NULL;
        envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
        if(envelope)
        {
            axis2_bool_t last_msg_header = AXIS2_FALSE;
            axiom_soap_header_t *header = NULL;
            header = axiom_soap_envelope_get_header(envelope, env);
            if(header)
            {
                sandesha2_seq_t *sequence = NULL;
                axiom_node_t *seq_node = NULL;
                sequence = sandesha2_seq_create(env, SANDESHA2_SPEC_2005_02_NS_URI);
                seq_node = axiom_soap_header_get_base_node(header, env);
                sandesha2_iom_rm_element_from_om_node((sandesha2_iom_rm_element_t *) 
                    sequence, env, seq_node);
                if(sandesha2_seq_get_last_msg(sequence, env))
                    last_msg_header = AXIS2_TRUE;
                 
            }
            if(last_msg_header)
            {
                axiom_soap_body_t *body = NULL;
                axiom_node_t *body_node = NULL;
                body = axiom_soap_envelope_get_body(envelope, env);
                body_node = axiom_soap_body_get_base_node(body, env);
                if(body && !axiom_node_get_first_element(body_node, env))
                {
                    axutil_string_t *temp_soap_action = axutil_string_create(env, 
                        SANDESHA2_SPEC_2005_02_SOAP_ACTION_LAST_MESSAGE);
                    /* There is an empty body so we know this is the kind of message
                     * that we are looking for.
                     */
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                        "Setting SOAP Action for a WSRM 1.0 last message");
                    axis2_msg_ctx_set_soap_action(msg_ctx, env, 
                        temp_soap_action);
                    isolated_last_msg = AXIS2_TRUE;
                }
            }
        }
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] soap::action and wsa::action are NULL. So return here");
        return AXIS2_SUCCESS;
    }
    is_rm_global_msg = sandesha2_utils_is_rm_global_msg(env, msg_ctx);
    if(!is_rm_global_msg)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] Not a global RM Message");
        return AXIS2_SUCCESS;
    }
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    if(!conf_ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]Configuration"
            " Context is NULL");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CONF_CTX_NULL, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    ctx = axis2_msg_ctx_get_base(msg_ctx, env);
    if(!axis2_msg_ctx_get_server_side(msg_ctx, env))
    {
        axis2_ctx_t *conf_ctx_base = axis2_conf_ctx_get_base(conf_ctx, env);
        axutil_property_t *property = axutil_property_create_with_args(env, 0, 0, 
            0, NULL);
        axis2_ctx_set_property(conf_ctx_base, env, SANDESHA2_IS_SVR_SIDE, 
            property);
    }
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    
    soap_envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
    if(!soap_envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2]SOAP envelope "
            "is NULL");
        return AXIS2_FAILURE;
    }
    property = axis2_ctx_get_property(ctx, env, SANDESHA2_REINJECTED_MESSAGE);
    if(property)
        reinjected_msg = (axis2_char_t *) axutil_property_get_value(property, env); 
    if(reinjected_msg && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, reinjected_msg))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Detected"
             " reinjected_msg. So return here.");
        return AXIS2_SUCCESS; /* Reinjected Messages are not processed by 
                                 sandesha2 inflow handlers */
    }
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    if(!storage_mgr)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[sandesha2] Cannot get the "
            "storage manager");
        return AXIS2_FAILURE;
    }
    property = axis2_ctx_get_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION);
    if(property)
        within_transaction_str = (axis2_char_t *) axutil_property_get_value(
            property, env);
    if(within_transaction_str && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, 
        within_transaction_str))
    {
        within_transaction = AXIS2_TRUE;
    }
    if(!within_transaction)
    {
        axutil_property_t *prop = NULL;
        
        transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, env);
        prop = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
            AXIS2_FALSE, 0, AXIS2_VALUE_TRUE);
        axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, prop);
    }
    fault_part = axiom_soap_body_get_fault(axiom_soap_envelope_get_body(
                        soap_envelope, env), env);
    if(fault_part)
    {
        axis2_relates_to_t *relates_to = NULL;
        if(!within_transaction)
        {
            axutil_property_t *prop = NULL;
            sandesha2_transaction_rollback(transaction, env);
            prop = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
                AXIS2_FALSE, 0, AXIS2_VALUE_FALSE);
            axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, prop);
            rolled_back = AXIS2_TRUE;
            
        }
        relates_to = axis2_msg_ctx_get_relates_to(msg_ctx, env);
        if(relates_to)
        {
            const axis2_char_t *relates_to_val = NULL;
            axis2_op_ctx_t *op_ctx = NULL;
            
            relates_to_val = axis2_relates_to_get_value(relates_to, env);
            op_ctx = axis2_conf_ctx_get_op_ctx(conf_ctx, env, relates_to_val);
            if(op_ctx)
            {
                axis2_msg_ctx_t *req_msg_ctx = NULL;
                req_msg_ctx =  axis2_op_ctx_get_msg_ctx(op_ctx, env, 
                    AXIS2_WSDL_MESSAGE_LABEL_OUT);
                if(req_msg_ctx)
                {
                    if(sandesha2_utils_is_retrievable_on_faults(env,
                        req_msg_ctx))
                    {
                        /* TODO we need to notify the listeners */
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "[sandesha2] soap fault generated");
                        axis2_msg_ctx_set_paused(msg_ctx, env, AXIS2_TRUE);
                        return AXIS2_SUCCESS;
                    }
                }
            }
        }
    }
    rm_msg_ctx = sandesha2_msg_init_init_msg(env, msg_ctx);
    if(!isolated_last_msg)
        dropped = sandesha2_global_in_handler_drop_if_duplicate(handler, env, 
            rm_msg_ctx, storage_mgr);
    if(dropped)
    {
        if(!within_transaction)
        {
            axutil_property_t *prop = NULL;
            sandesha2_transaction_rollback(transaction, env);
            prop = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
                AXIS2_FALSE, 0, AXIS2_VALUE_FALSE);
            axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, 
                prop);
            rolled_back = AXIS2_TRUE;
        }
        sandesha2_global_in_handler_process_dropped_msg(handler, env, rm_msg_ctx,
                        storage_mgr);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[sandesha2] msg_ctx dropped. So return here");
        return AXIS2_SUCCESS;
    }
    /*Process if global processing possible. - Currently none*/
    if(!within_transaction && !rolled_back)
    {
        axutil_property_t *prop = NULL;
        sandesha2_transaction_commit(transaction, env);
        prop = axutil_property_create_with_args(env, AXIS2_SCOPE_REQUEST, 
            AXIS2_FALSE, 0, AXIS2_VALUE_FALSE);
        axis2_ctx_set_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION, prop);
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  "[sandesha2] Exit:sandesha2_global_in_handler");
       
    return AXIS2_SUCCESS;
}
/*
static axutil_qname_t *AXIS2_CALL
sandesha2_global_in_handler_get_qname(
    struct axis2_handler *handler, 
    const axutil_env_t *env)
{
    return axutil_qname_create(env, SANDESHA2_GLOBAL_IN_HANDLER_NAME, NULL, NULL);
}
*/
static axis2_bool_t AXIS2_CALL
sandesha2_global_in_handler_drop_if_duplicate(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_mgr)
{
    axis2_bool_t drop = AXIS2_FALSE;
    
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FALSE);
    
    if(SANDESHA2_MSG_TYPE_APPLICATION == sandesha2_msg_ctx_get_msg_type(
        rm_msg_ctx, env))
    {
        sandesha2_seq_t *sequence = NULL;
        long msg_no = -1;
        axis2_char_t *seq_id = NULL;
        
        sequence = (sandesha2_seq_t*)sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, 
            env, SANDESHA2_MSG_PART_SEQ);
        if(sequence)
        {
            seq_id = sandesha2_identifier_get_identifier(
                        sandesha2_seq_get_identifier(sequence, env), env);
            msg_no = SANDESHA2_MSG_NUMBER_GET_MSG_NUM(sandesha2_seq_get_msg_num(
                        sequence, env), env);
        }
        if(seq_id && 0 < msg_no)
        {
            sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
            sandesha2_seq_property_bean_t *rcvd_msgs_bean = NULL;
            
            seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
                        storage_mgr, env);
            if(seq_prop_mgr)
                rcvd_msgs_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr,
                    env, seq_id, SANDESHA2_SEQ_PROP_SERVER_COMPLETED_MESSAGES);
            if(rcvd_msgs_bean)
            {
                axis2_char_t *rcvd_msgs_str = NULL;
                axutil_array_list_t *msg_no_list = NULL;
                int i = 0, size = 0;
                
                rcvd_msgs_str = sandesha2_seq_property_bean_get_value(
                        rcvd_msgs_bean, env);
                msg_no_list = sandesha2_utils_get_array_list_from_string(env,
                        rcvd_msgs_str);
                if(msg_no_list)
                    size = axutil_array_list_size(msg_no_list, env);
                for(i = 0; i < size; i++)
                {
                    axis2_char_t *temp = NULL;
                    
                    temp = axutil_array_list_get(msg_no_list, env, i);
                    if(atol(temp) == msg_no)
                        drop = AXIS2_TRUE;
                }
            }
            if(!drop)
            {
                axiom_soap_body_t *soap_body = NULL;
                axiom_node_t *body_node = NULL;
                axiom_element_t *body_element = NULL;
                axiom_children_iterator_t *children_iterator = NULL;
                axis2_bool_t empty_body = AXIS2_FALSE;
            
                soap_body = axiom_soap_envelope_get_body(
                    sandesha2_msg_ctx_get_soap_envelope(rm_msg_ctx, env), 
                    env);
                body_node = axiom_soap_body_get_base_node(soap_body, env);
                body_element = axiom_node_get_data_element(body_node, env);
                children_iterator = axiom_element_get_children(body_element, env, 
                    body_node);
                if(!axiom_children_iterator_has_next(children_iterator, env))
                    empty_body = AXIS2_TRUE;
                if(empty_body)
                {
                    axis2_char_t *rcvd_msgs_str1 = NULL;
                    axis2_char_t *bean_value = NULL;
                    axis2_char_t msg_no_str[32];
                    sandesha2_msg_processor_t *app_msg_processor = NULL;
                    
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Empty "
                        "body last msg recieved");
                    drop = AXIS2_TRUE;
                    if(!rcvd_msgs_bean)
                    {
                        rcvd_msgs_bean = sandesha2_seq_property_bean_create_with_data
                            (env, seq_id, 
                            SANDESHA2_SEQ_PROP_SERVER_COMPLETED_MESSAGES, "");
                        sandesha2_seq_property_mgr_insert(seq_prop_mgr, env,
                            rcvd_msgs_bean);
                    }
                    rcvd_msgs_str1 = sandesha2_seq_property_bean_get_value(
                            rcvd_msgs_bean, env);
                    sprintf(msg_no_str, "%ld", msg_no);
                    if(rcvd_msgs_str1 && 0 < axutil_strlen(rcvd_msgs_str1))
                        bean_value = axutil_strcat(env, rcvd_msgs_str1, ",",
                            msg_no_str, NULL);
                    else
                        bean_value = axutil_strdup(env, msg_no_str);
                    
                    sandesha2_seq_property_bean_set_value(rcvd_msgs_bean, env,
                        bean_value);
                    sandesha2_seq_property_mgr_update(seq_prop_mgr, env, 
                        rcvd_msgs_bean);
                    app_msg_processor = sandesha2_app_msg_processor_create(env);
                    sandesha2_app_msg_processor_send_ack_if_reqd(env, 
                            rm_msg_ctx, bean_value, storage_mgr);
                }
            }
        }        
    } 
    else if(SANDESHA2_MSG_TYPE_UNKNOWN == sandesha2_msg_ctx_get_msg_type(
        rm_msg_ctx, env))
    {
        axis2_relates_to_t *relates_to = NULL;
        axis2_conf_ctx_t *conf_ctx = NULL;
        
        
        relates_to = sandesha2_msg_ctx_get_relates_to(rm_msg_ctx, env);
        if(relates_to)
        {
            const axis2_char_t *relates_to_val = NULL;
            axis2_op_ctx_t *op_ctx = NULL;
            axis2_op_ctx_t *op_ctx1 = NULL;
            
            relates_to_val = axis2_relates_to_get_value(relates_to, env);
            conf_ctx = axis2_msg_ctx_get_conf_ctx(sandesha2_msg_ctx_get_msg_ctx(
                        rm_msg_ctx, env), env);
            op_ctx = axis2_conf_ctx_get_op_ctx(conf_ctx, env, relates_to_val);
            op_ctx1 = axis2_msg_ctx_get_op_ctx(sandesha2_msg_ctx_get_msg_ctx(
                        rm_msg_ctx, env), env);
            if(!op_ctx && !op_ctx1)
            {
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Dropping"
                        " duplicate RM message");
                drop = AXIS2_TRUE;
            }
        }
    }
    if(drop)
    {
        sandesha2_msg_ctx_set_paused(rm_msg_ctx, env, AXIS2_TRUE);
        return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
}


static axis2_status_t AXIS2_CALL
sandesha2_global_in_handler_process_dropped_msg(
    struct axis2_handler *handler, 
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx,
    sandesha2_storage_mgr_t *storage_mgr)
{
    
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, rm_msg_ctx, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, storage_mgr, AXIS2_FALSE);
    
    if(SANDESHA2_MSG_TYPE_APPLICATION == sandesha2_msg_ctx_get_msg_type(
                        rm_msg_ctx, env))
    {
        sandesha2_seq_t *sequence = NULL;
        axis2_char_t *seq_id = NULL;
        
        sequence = (sandesha2_seq_t*)sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, 
            env, SANDESHA2_MSG_PART_SEQ);
        if(sequence)
            seq_id = sandesha2_identifier_get_identifier(
                sandesha2_seq_get_identifier(sequence, env), env);
            
        if(seq_id)
        {
            sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
            sandesha2_seq_property_bean_t *rcvd_msgs_bean = NULL;
            axis2_char_t *rcvd_msgs_str = NULL;
            sandesha2_msg_processor_t *app_msg_processor = NULL;
            
            seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
                storage_mgr, env);
            rcvd_msgs_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr,
                env, seq_id, SANDESHA2_SEQ_PROP_SERVER_COMPLETED_MESSAGES);
            if(rcvd_msgs_bean)
            {
                rcvd_msgs_str = sandesha2_seq_property_bean_get_value(
                    rcvd_msgs_bean, env);
                app_msg_processor = sandesha2_app_msg_processor_create(env);
                sandesha2_app_msg_processor_send_ack_if_reqd(env, rm_msg_ctx, 
                    rcvd_msgs_str, storage_mgr);
            }
            
        }
    }
    return AXIS2_SUCCESS;
}

