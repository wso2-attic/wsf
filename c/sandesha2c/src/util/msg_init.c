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
 
#include <sandesha2_msg_init.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_utils.h>
#include <sandesha2_ack_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_msg_ctx.h>
#include <sandesha2_acks_to.h>
#include <sandesha2_address.h>
#include <sandesha2_seq_offer.h>
#include <sandesha2_accept.h>
#include <sandesha2_create_seq.h>
#include <sandesha2_create_seq_res.h>
#include <sandesha2_seq.h>
#include <sandesha2_terminate_seq.h>
#include <sandesha2_terminate_seq_res.h>
#include <sandesha2_ack_requested.h>
#include <sandesha2_close_seq.h>
#include <sandesha2_close_seq_res.h>
#include <sandesha2_make_connection.h>
#include <sandesha2_msg_pending.h>
#include <sandesha2_rm_elements.h>
#include <sandesha2_client_constants.h>

#include <axis2_conf_ctx.h>
#include <axis2_ctx.h>
#include <axis2_msg_ctx.h>
#include <axutil_property.h>
#include <axutil_log.h>
#include <axutil_uuid_gen.h>
#include <axis2_addr.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_body.h>
#include <axiom_node.h>

/**
 * Adds the message parts to the sandesha2_msg_ctx.
 * 
 * @param msg_ctx
 * @param rm_msg_ctx
 */
static axis2_status_t
populate_rm_msg_ctx(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    sandesha2_msg_ctx_t *rm_msg_ctx);

/**
 * This is used to validate the message.
 * Also set an Message type. Possible types are given in the sandesha2_constants
 * 
 * @param rm_msg_ctx
 * @return
 */
static axis2_bool_t validate_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx);

static void add_op_if_null(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

/**
 * Called to create a rm_msg_ctx out of an message context. Finds out things 
 * like rm version and message type as well.
 * 
 * @param ctx
 * @param assumed_rm_ns
 * this is used for validation (to find out weather the rm_ns of the current 
 * message is equal to the regietered rm_ns of the sequence). 
 * If NULL validation will not happen.
 * 
 * @return
 */
sandesha2_msg_ctx_t *
sandesha2_msg_init_init_msg(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    sandesha2_msg_ctx_t *rm_msg_ctx = NULL;

    rm_msg_ctx = sandesha2_msg_ctx_create(env, msg_ctx);
    populate_rm_msg_ctx(env, msg_ctx, rm_msg_ctx);
    validate_msg(env, rm_msg_ctx);
    return rm_msg_ctx;
}

static axis2_status_t
populate_rm_msg_ctx(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    axis2_char_t *addressing_ns = NULL;
    axis2_char_t *addressing_ns_value = NULL;
    axis2_char_t *rm_ns = NULL;
    axis2_char_t *action = NULL;
    axutil_property_t *prop = NULL;
    axis2_ctx_t *ctx = NULL;
    axiom_soap_envelope_t *envelope = NULL;
    sandesha2_rm_elements_t *rm_elements = NULL;
    sandesha2_create_seq_t *create_seq = NULL;
    sandesha2_create_seq_res_t *create_seq_res = NULL;
    sandesha2_seq_t *seq = NULL;
    sandesha2_seq_ack_t *seq_ack = NULL;
    sandesha2_terminate_seq_t *terminate_seq = NULL;
    sandesha2_terminate_seq_res_t *terminate_seq_res = NULL;
    sandesha2_ack_requested_t *ack_request = NULL;
    sandesha2_close_seq_t *close_seq = NULL;
    sandesha2_close_seq_res_t *close_seq_res = NULL;
    sandesha2_make_connection_t *make_conn = NULL;
    sandesha2_msg_pending_t *msg_pending = NULL;
    
    /* If client side and the addressing version is not set. 
     * Assuming the default addressing version.
     */
    if(msg_ctx)
        ctx = axis2_msg_ctx_get_base(msg_ctx, env);
    prop = axis2_ctx_get_property(ctx, env, AXIS2_WSA_VERSION);
    if(prop)
        addressing_ns = (axis2_char_t *) axutil_property_get_value(prop, env);
    
    if(!addressing_ns && !axis2_msg_ctx_get_server_side(msg_ctx, env))
    {
        addressing_ns = axutil_strdup(env, AXIS2_WSA_NAMESPACE);
    }
    if(addressing_ns)
        rm_elements = sandesha2_rm_elements_create(env, addressing_ns);
    if(!rm_elements)
        return AXIS2_FAILURE;
    envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
    action = (axis2_char_t*)axis2_msg_ctx_get_wsa_action(msg_ctx, env);
    sandesha2_rm_elements_from_soap_envelope(rm_elements, env, envelope, action);
    create_seq = sandesha2_rm_elements_get_create_seq(rm_elements, env);
    if(create_seq)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_CREATE_SEQ, (sandesha2_iom_rm_part_t *) 
                create_seq);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) create_seq, env);
    }
    create_seq_res = sandesha2_rm_elements_get_create_seq_res(rm_elements, env);
    if(create_seq_res)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_CREATE_SEQ_RESPONSE, 
                (sandesha2_iom_rm_part_t *) create_seq_res);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) create_seq_res, env);
        add_op_if_null(env, msg_ctx);
    }
    seq = sandesha2_rm_elements_get_seq(rm_elements, env);
    if(seq)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_SEQ, (sandesha2_iom_rm_part_t *) seq);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) seq, env);
    }
    seq_ack = sandesha2_rm_elements_get_seq_ack(rm_elements, env);
    if(seq_ack)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT, 
                (sandesha2_iom_rm_part_t *) seq_ack);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) seq_ack, env);
        add_op_if_null(env, msg_ctx);
    }
    terminate_seq = sandesha2_rm_elements_get_terminate_seq(rm_elements, env);
    if(terminate_seq)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_TERMINATE_SEQ, 
                (sandesha2_iom_rm_part_t *) terminate_seq);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) terminate_seq, env);
        add_op_if_null(env, msg_ctx);
    }
    terminate_seq_res = sandesha2_rm_elements_get_terminate_seq_res(rm_elements, 
        env);
    if(terminate_seq_res)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_TERMINATE_SEQ_RESPONSE, 
                (sandesha2_iom_rm_part_t *) terminate_seq_res);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) terminate_seq_res, env);
        add_op_if_null(env, msg_ctx);
    }
    ack_request = sandesha2_rm_elements_get_ack_requested(rm_elements, env);
    if(ack_request)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_ACK_REQUEST, 
                (sandesha2_iom_rm_part_t *) ack_request);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) ack_request, env);
        add_op_if_null(env, msg_ctx);
    }
    close_seq = sandesha2_rm_elements_get_close_seq(rm_elements, env);
    if(close_seq)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_CLOSE_SEQ, 
                (sandesha2_iom_rm_part_t *) close_seq);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) close_seq, env);
        add_op_if_null(env, msg_ctx);
    }
    close_seq_res = sandesha2_rm_elements_get_close_seq_res(rm_elements, env);
    if(close_seq_res)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_CLOSE_SEQ_RESPONSE, 
                (sandesha2_iom_rm_part_t *) close_seq_res);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) close_seq_res, env);
        add_op_if_null(env, msg_ctx);
    }
    make_conn = sandesha2_rm_elements_get_make_connection(rm_elements, env);
    if(make_conn)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_MAKE_CONNECTION, 
                (sandesha2_iom_rm_part_t *) make_conn);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) make_conn, env);
        add_op_if_null(env, msg_ctx);
    }
    msg_pending = sandesha2_rm_elements_get_msg_pending(rm_elements, env);
    if(msg_pending)
    {
        sandesha2_msg_ctx_set_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_MESSAGE_PENDING, 
                (sandesha2_iom_rm_part_t *) msg_pending);
        rm_ns = sandesha2_iom_rm_element_get_namespace_value(
                (sandesha2_iom_rm_element_t *) msg_pending, env);
        add_op_if_null(env, msg_ctx);
    }
    sandesha2_msg_ctx_set_rm_ns_val(rm_msg_ctx, env, rm_ns);
    addressing_ns_value = sandesha2_rm_elements_get_addr_ns_val(
            rm_elements, env);
    if(addressing_ns_value)
    {
        sandesha2_msg_ctx_set_addr_ns_val(rm_msg_ctx, env, 
                addressing_ns_value);
    }
    return AXIS2_SUCCESS;
}

static axis2_bool_t validate_msg(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx)
{
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_msg_ctx_t *temp_msg_ctx = NULL;
    axis2_char_t *seq_id = NULL;
    axis2_char_t *rm_ns = NULL;
    axis2_char_t *prop_key = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_create_seq_t *create_seq = NULL;
    sandesha2_create_seq_res_t *create_seq_res = NULL;
    sandesha2_terminate_seq_t *terminate_seq = NULL;
    sandesha2_terminate_seq_res_t *terminate_seq_res = NULL;
    sandesha2_seq_ack_t *seq_ack = NULL;
    sandesha2_seq_t *seq = NULL;
    sandesha2_ack_requested_t *ack_request = NULL;
    sandesha2_close_seq_t *close_seq = NULL;
    sandesha2_close_seq_res_t *close_seq_res = NULL;
    sandesha2_make_connection_t *make_conn = NULL;
    int temp_flow = -1;

    temp_msg_ctx = sandesha2_msg_ctx_get_msg_ctx(rm_msg_ctx, env);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(temp_msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    create_seq = (sandesha2_create_seq_t *) sandesha2_msg_ctx_get_msg_part(
            rm_msg_ctx, env, SANDESHA2_MSG_PART_CREATE_SEQ);
    create_seq_res = (sandesha2_create_seq_res_t *) 
        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_CREATE_SEQ_RESPONSE);
    terminate_seq = (sandesha2_terminate_seq_t *) 
        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_TERMINATE_SEQ);
    terminate_seq_res = (sandesha2_terminate_seq_res_t *) 
        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_TERMINATE_SEQ_RESPONSE);
    seq_ack = (sandesha2_seq_ack_t *) 
        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_SEQ_ACKNOWLEDGEMENT);
    seq = (sandesha2_seq_t *) sandesha2_msg_ctx_get_msg_part(
            rm_msg_ctx, env, SANDESHA2_MSG_PART_SEQ);
    ack_request = (sandesha2_ack_requested_t *) 
        sandesha2_msg_ctx_get_msg_part(rm_msg_ctx, env, 
                SANDESHA2_MSG_PART_ACK_REQUEST);
    close_seq = (sandesha2_close_seq_t *) sandesha2_msg_ctx_get_msg_part(
            rm_msg_ctx, env, SANDESHA2_MSG_PART_CLOSE_SEQ);
    close_seq_res = (sandesha2_close_seq_res_t *) sandesha2_msg_ctx_get_msg_part(
            rm_msg_ctx, env, SANDESHA2_MSG_PART_CLOSE_SEQ_RESPONSE);
    make_conn = (sandesha2_make_connection_t *) sandesha2_msg_ctx_get_msg_part(
            rm_msg_ctx, env, SANDESHA2_MSG_PART_MAKE_CONNECTION);
    /* Setting message type */
    if(create_seq)
    {
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_CREATE_SEQ);
    }
    else if(create_seq_res)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_CREATE_SEQ_RESPONSE);
        idf = sandesha2_create_seq_res_get_identifier(create_seq_res, env);
        seq_id = sandesha2_identifier_get_identifier(idf, env);
    }
    else if(terminate_seq)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_TERMINATE_SEQ);
        idf = sandesha2_terminate_seq_get_identifier(terminate_seq, env);
        seq_id = sandesha2_identifier_get_identifier(idf, env);
    }
    else if(terminate_seq_res)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_TERMINATE_SEQ_RESPONSE);
        idf = sandesha2_terminate_seq_res_get_identifier(terminate_seq_res, env);
        seq_id = sandesha2_identifier_get_identifier(idf, env);
    }
    else if(seq)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_APPLICATION);
        idf = sandesha2_seq_get_identifier(seq, env);
        seq_id = sandesha2_identifier_get_identifier(idf, env);
    }
    else if(seq_ack)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_ACK);
        idf = sandesha2_seq_ack_get_identifier(seq_ack, env);
        seq_id = sandesha2_identifier_get_identifier(idf, env);
    }
    else if(ack_request)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_ACK_REQUEST);
        idf = sandesha2_ack_requested_get_identifier(ack_request, env);
        seq_id = sandesha2_identifier_get_identifier(idf, env);
    }
    else if(close_seq)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_CLOSE_SEQ);
        idf = sandesha2_close_seq_get_identifier(close_seq, env);
        seq_id = sandesha2_identifier_get_identifier(idf, env);
    }
    else if(close_seq_res)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_CLOSE_SEQ_RESPONSE);
        idf = sandesha2_close_seq_res_get_identifier(close_seq_res, env);
        seq_id = sandesha2_identifier_get_identifier(idf, env);
    }
    else if(make_conn)
    {
        sandesha2_identifier_t *idf = NULL;
        sandesha2_address_t *address = NULL;
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, 
                SANDESHA2_MSG_TYPE_MAKE_CONNECTION_MSG);
        idf = sandesha2_make_connection_get_identifier(make_conn, env);
        address = sandesha2_make_connection_get_address(make_conn, env);
        if(idf)
        {
            seq_id = sandesha2_identifier_get_identifier(idf, env);
        }
        else if(address)
        {
            /* TODO Get seq_id based on the anonymous address */
        }
        else
        {
            AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_INVALID_MAKE_CONNECTION_MSG, AXIS2_FAILURE);
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                " Invalid MakeConnection message. Either Address or Identifier" \
                " must be present");
            return AXIS2_FALSE;
        } 
    }
    else
    {
        sandesha2_msg_ctx_set_msg_type(rm_msg_ctx, env, SANDESHA2_MSG_TYPE_UNKNOWN);
    }
    temp_flow = axis2_msg_ctx_get_flow(temp_msg_ctx, env);
    if(temp_flow == AXIS2_IN_FLOW)
    {
        prop_key = axutil_strdup(env, seq_id);
    }
    else
    {
        sandesha2_seq_property_bean_t *internal_seq_id_bean = NULL;

        internal_seq_id_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, 
                env, seq_id, SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
        if(internal_seq_id_bean)
        {
            prop_key = sandesha2_seq_property_bean_get_value(
                    internal_seq_id_bean, env);
        }
    }
    rm_ns = sandesha2_msg_ctx_get_rm_ns_val(rm_msg_ctx, env);
    if(seq_id)
    {
        axis2_char_t *spec_version = NULL;
        axis2_char_t *seq_rm_ns = NULL;
        
        spec_version = sandesha2_utils_get_rm_version(env, prop_key, storage_mgr);
        if(spec_version)
        {
            seq_rm_ns = sandesha2_spec_specific_consts_get_rm_ns_val(env, 
                    spec_version);
        }
        if(seq_rm_ns && rm_ns)
        {
            if(0 != axutil_strcmp(seq_rm_ns, rm_ns))
            {
                AXIS2_ERROR_SET(env->error, 
                    SANDESHA2_ERROR_RM_NS_VALUE_IS_DIFFERENT_FROM_REGISTERED_NS_FOR_SEQ, 
                    AXIS2_FAILURE);
                return AXIS2_FALSE;
            }
        }
    }
    return AXIS2_TRUE; 
}

static void add_op_if_null(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_op_t *op = NULL;
        
    op = axis2_msg_ctx_get_op(msg_ctx, env);
    if(!op)
    {
        axis2_svc_t *svc = NULL;
        axutil_qname_t *tmp_qname = NULL;
    
        tmp_qname = axutil_qname_create(env, "__OPERATION_OUT_IN__", NULL, 
                NULL);
        if (!tmp_qname)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, 
                    AXIS2_FAILURE);
            return;
        }
        svc = axis2_msg_ctx_get_svc(msg_ctx, env);
        op = axis2_svc_get_op_with_qname(svc, env, tmp_qname);
        if(!op)
        {
            axis2_status_t status = AXIS2_FAILURE;
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_phases_info_t *info = NULL;

            op = axis2_op_create_with_qname(env, tmp_qname);
            axis2_op_set_msg_exchange_pattern(op, env, AXIS2_MEP_URI_OUT_IN);
            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            info = axis2_conf_get_phases_info(conf, env);
            axis2_phases_info_set_op_phases(info, env, op);
            status = axis2_svc_add_op(svc, env, op);
            if(AXIS2_SUCCESS == status)
            {
                status = axis2_msg_ctx_set_op(msg_ctx, env, op);
                if(AXIS2_SUCCESS != status)
                {
                    axis2_op_free(op, env);
                    op = NULL;
                }
            }
            else
            {
                axis2_op_free(op, env);
                op = NULL;
            }
        }
        axutil_qname_free(tmp_qname, env);
        axis2_msg_ctx_set_op(msg_ctx, env, op);
    }
}


