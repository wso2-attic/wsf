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
 
#include <sandesha2_client.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_create_seq_mgr.h>
#include <sandesha2_transaction.h>
#include "sandesha2_client_constants.h"
#include <sandesha2_spec_specific_consts.h>
#include <sandesha2_utils.h>
#include <sandesha2_ack_requested.h>
#include <sandesha2_identifier.h>
#include <sandesha2_close_seq.h>
#include <sandesha2_terminate_seq.h>
#include <sandesha2_ack_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_next_msg_mgr.h>

#include <axis2_callback_recv.h>
#include <axis2_svc_client.h>
#include <axis2_op_client.h>
#include <axis2_svc.h>
#include <axis2_op.h>
#include <axis2_svc_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_ctx.h>
#include <axutil_property.h>
#include <axutil_log.h>
#include <axis2_options.h>
#include <axutil_uuid_gen.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_body.h>
#include <axiom_soap_header.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axiom_soap_const.h>

static sandesha2_transaction_t *client_report_transaction = NULL;

/**
 * Caller must free the returned internal_seq_id
 * @param to
 * @param seq_key
 *
 * @return internal_seq_id
 */
static axis2_char_t *
sandesha2_client_get_internal_seq_id(
        const axutil_env_t *env,
        axis2_char_t *to,
        axis2_char_t *seq_key);

static axiom_soap_envelope_t *
sandesha2_client_configure_close_seq(
        const axutil_env_t *env,
        axis2_options_t *options, 
        axis2_conf_ctx_t *conf_ctx);

static axis2_bool_t
sandesha2_client_is_seq_terminated(
        const axutil_env_t *env,
        axis2_char_t *internal_seq_id,
        sandesha2_seq_property_mgr_t *seq_prop_mgr);

static axis2_bool_t
sandesha2_client_is_seq_timedout(
        const axutil_env_t *env,
        axis2_char_t *internal_seq_id,
        sandesha2_seq_property_mgr_t *seq_prop_mgr);

static axis2_status_t
sandesha2_client_fill_terminated_outgoing_seq_info(
        const axutil_env_t *env,
        sandesha2_seq_report_t *report,
        axis2_char_t *internal_seq_id,
        sandesha2_seq_property_mgr_t *seq_prop_mgr);

/*static axis2_status_t
sandesha2_client_fill_timedout_outgoing_seq_info(
        const axutil_env_t *env,
        sandesha2_seq_report_t *report,
        axis2_char_t *internal_seq_id,
        sandesha2_seq_property_mgr_t *seq_prop_mgr);*/

static axis2_status_t
sandesha2_client_fill_outgoing_seq_info(
        const axutil_env_t *env,
        sandesha2_seq_report_t *report,
        axis2_char_t *out_seq_id,
        sandesha2_seq_property_mgr_t *seq_prop_mgr);

static axis2_char_t
sandesha2_client_get_svr_seq_status(
        const axutil_env_t *env,
        axis2_char_t *seq_id,
        sandesha2_storage_mgr_t *storage_mgr);

static axis2_char_t *
sandesha2_client_generate_internal_seq_id_for_the_client_side(
        const axutil_env_t *env,
        axis2_char_t *to_epr,
        axis2_char_t *seq_key);

static sandesha2_seq_report_t *
sandesha2_client_get_incoming_seq_report(
        const axutil_env_t *env,
        axis2_char_t *seq_id,
        axis2_conf_ctx_t *conf_ctx);

static axiom_soap_envelope_t *
sandesha2_client_configure_terminate_seq(
    const axutil_env_t *env,
    axis2_options_t *options, 
    axis2_conf_ctx_t *conf_ctx);

static axis2_bool_t
fill_soap_envelope(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_options_t *options,
    const axiom_node_t *payload);


/**
 * Users can get a seq_report of the seq defined by the information
 * given from the passed svc_client object.
 * 
 * @param service_client
 * @return
 */
sandesha2_seq_report_t *AXIS2_CALL
sandesha2_client_get_outgoing_seq_report_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client)
{
    axis2_options_t *options = NULL;
    axis2_endpoint_ref_t *to_epr = NULL;
    axis2_char_t *to = NULL;
    axis2_char_t *seq_key = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_char_t *internal_seq_id = NULL;
    axutil_property_t *property = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, svc_client, NULL);

    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(options == NULL)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
            AXIS2_FAILURE);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "Options object of the service client not set.");
        return NULL;
    }
    to_epr = axis2_options_get_to(options, env);
    if(to_epr == NULL)
    {
        AXIS2_ERROR_SET(env->error, 
            SANDESHA2_ERROR_TO_ADDRESS_NOT_SET, AXIS2_FAILURE);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "To address is not set.");
    }
    to = (axis2_char_t*)axis2_endpoint_ref_get_address(to_epr, env);
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    seq_key = axutil_property_get_value(property, env);
    svc_ctx = (axis2_svc_ctx_t *)axis2_svc_client_get_svc_ctx(svc_client, env);
    if(svc_ctx == NULL)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SVC_CTX_NULL, 
            AXIS2_FAILURE);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "Service Context is NULL.");
        
    }
    conf_ctx =  axis2_svc_ctx_get_conf_ctx(svc_ctx, env);    
    internal_seq_id = sandesha2_client_get_internal_seq_id(env, to, seq_key);

    return (sandesha2_seq_report_t *) 
        sandesha2_client_get_outgoing_seq_report_with_internal_seq_id(env, 
        internal_seq_id, conf_ctx);

}

sandesha2_seq_report_t *AXIS2_CALL
sandesha2_client_get_outgoing_seq_report_with_seq_key(
    const axutil_env_t *env,
    axis2_char_t *to,
    axis2_char_t *seq_key,
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_char_t *internal_seq_id = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, to, NULL);
    AXIS2_PARAM_CHECK(env->error, seq_key, NULL);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, NULL);

    internal_seq_id = sandesha2_utils_get_internal_seq_id(env, to, seq_key);
    return (sandesha2_seq_report_t *) 
        sandesha2_client_get_outgoing_seq_report_with_internal_seq_id(env, 
        internal_seq_id, conf_ctx);
}

sandesha2_seq_report_t *AXIS2_CALL
sandesha2_client_get_outgoing_seq_report_with_internal_seq_id(
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id,
    axis2_conf_ctx_t *conf_ctx)
{
    sandesha2_seq_report_t *seq_report = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_create_seq_mgr_t *create_seq_mgr = NULL;
    sandesha2_create_seq_bean_t *create_seq_find_bean = NULL;
    sandesha2_create_seq_bean_t *create_seq_bean = NULL;
    axis2_conf_t *conf = NULL;
    axis2_ctx_t *ctx = NULL;
    axutil_property_t *property = NULL;
    axis2_bool_t within_transaction = AXIS2_FALSE;
    sandesha2_transaction_t *report_transaction = NULL;
    axis2_char_t *within_transaction_str = NULL;
    axis2_char_t *out_seq_id = NULL;
    axis2_bool_t commit = AXIS2_TRUE;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, internal_seq_id, NULL);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, NULL);

    seq_report = sandesha2_seq_report_create(env);
    sandesha2_seq_report_set_seq_direction(seq_report, env, 
        SANDESHA2_SEQ_DIRECTION_OUT);

    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf); 
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env); 
    create_seq_mgr = sandesha2_storage_mgr_get_create_seq_mgr(storage_mgr, env); 
    ctx = axis2_conf_ctx_get_base(conf_ctx, env);
    if(client_report_transaction)
    {
        report_transaction = client_report_transaction;
        commit = AXIS2_FALSE;
    }
    else
    {
        property = axis2_ctx_get_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION);
        if(property)
            within_transaction_str = (axis2_char_t *) axutil_property_get_value(
                property, env);
        if(within_transaction_str && 0 == axutil_strcmp(within_transaction_str, 
            AXIS2_VALUE_TRUE))
        {
            within_transaction = AXIS2_TRUE;
        }
        if(!within_transaction)
        {
            report_transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, 
                env);
        }
        client_report_transaction = report_transaction;
    }
    sandesha2_seq_report_set_internal_seq_id(seq_report, env, internal_seq_id);
    create_seq_find_bean = sandesha2_create_seq_bean_create(env);
    sandesha2_create_seq_bean_set_internal_seq_id(create_seq_find_bean, 
        env, internal_seq_id);
    create_seq_bean = sandesha2_create_seq_mgr_find_unique(create_seq_mgr, env, 
        create_seq_find_bean);
	/* if data is not available seq has to be terminated or timedOut.*/
    if(!create_seq_bean)
    {
	    /* check weather this is an terminated seq.*/
        if(sandesha2_client_is_seq_terminated(env, internal_seq_id, 
               seq_prop_mgr))
        {
            sandesha2_client_fill_terminated_outgoing_seq_info(env, seq_report, 
                internal_seq_id, seq_prop_mgr);
            return seq_report;
        }
        if(sandesha2_client_is_seq_timedout(env, internal_seq_id, 
            seq_prop_mgr))
        {
            /*sandesha2_client_fill_timedout_outgoing_seq_info(env, seq_report, 
                    internal_seq_id, seq_prop_mgr);*/
            return seq_report;
        }

        /* seq must have been timed out before establishing. No other
         * posibility I can think of.
         * this does not get recorded since there is no key (which is
         * normally the seqID) to store it.
         * (properties with key as the internalSequenceID get deleted in
         * timing out)
         */

        /* so, setting the seq status to INITIAL */
        sandesha2_seq_report_set_seq_status(seq_report, env, 
            SANDESHA2_SEQ_STATUS_INITIAL);
		/* returning the current seq report.*/
        return seq_report;
    }
    out_seq_id = sandesha2_create_seq_bean_get_seq_id(create_seq_bean, env);
    if(!out_seq_id)
    {
        sandesha2_seq_report_set_internal_seq_id(seq_report, env, 
            internal_seq_id);
        sandesha2_seq_report_set_seq_status(seq_report, env, 
            SANDESHA2_SEQ_STATUS_INITIAL);
        sandesha2_seq_report_set_seq_direction(seq_report, env, 
            SANDESHA2_SEQ_DIRECTION_OUT);
        return seq_report;
    }
    sandesha2_seq_report_set_seq_status(seq_report, env, 
        SANDESHA2_SEQ_STATUS_ESTABLISHED);
    sandesha2_client_fill_outgoing_seq_info(env, seq_report, out_seq_id, 
        seq_prop_mgr);
    if(report_transaction && commit)
    {
         sandesha2_transaction_commit(report_transaction, env);
         client_report_transaction = NULL;
    }
    return seq_report;
}

/**
 * Users can get a list of seq_reports each describing a incoming
 * sequence, which are the sequences the client work as a RMD.
 * Caller must free the returned array.
 * 
 * @param config_ctx
 * @return
 */
axutil_array_list_t *AXIS2_CALL
sandesha2_client_get_incoming_seq_reports(
    axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    sandesha2_report_t *report = NULL;
    axutil_array_list_t *incoming_seq_ids = NULL;
    axutil_array_list_t *incoming_seq_reports = NULL;
    int i =0, size = 0;

    AXIS2_ENV_CHECK(env, NULL);

    report = sandesha2_client_get_report(env, conf_ctx);
    incoming_seq_reports = axutil_array_list_create(env, 0);
    if(!incoming_seq_reports)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    incoming_seq_ids = sandesha2_report_get_incoming_seq_list(report, env);
    for(i = 0; i < size; i++)
    {
        axis2_char_t *seq_id = NULL;
        sandesha2_seq_report_t *incoming_seq_report = NULL;
        
        seq_id = (axis2_char_t *) axutil_array_list_get(incoming_seq_ids, env, i);
        incoming_seq_report = sandesha2_client_get_incoming_seq_report(env, 
            seq_id, conf_ctx);
        if(!incoming_seq_report)
        {
            AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_INCOMING_SEQ_REPORT_NOT_PRESENT_FOR_GIVEN_SEQ_ID, 
                AXIS2_FAILURE);
            return NULL;
        }
        axutil_array_list_add(incoming_seq_reports, env, incoming_seq_report);
    }
    return incoming_seq_reports;
}

/**
 * sandesha2_report gives the details of all incoming and outgoing sequences.
 * The outgoing sequence have to pass the initial state (CS/CSR exchange) to
 * be included in a sandesha2_report
 * 
 * @param conf_ctx
 * @return
 */
sandesha2_report_t *AXIS2_CALL
sandesha2_client_get_report(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    axis2_conf_t *conf = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_report_t *sandesha2_report = NULL;
    sandesha2_seq_property_bean_t *internal_seq_find_bean = NULL;
    axis2_char_t *within_transaction_str = NULL;
    axis2_bool_t within_transaction = AXIS2_FALSE;
    sandesha2_transaction_t *report_transaction = NULL;
    axis2_bool_t rolled_back = AXIS2_FALSE;
    axutil_array_list_t *collection = NULL;
    axutil_array_list_t *svr_completed_msgs_beans = NULL;
    int i = 0, size = 0;
    sandesha2_seq_property_bean_t *svr_completed_msgs_find_bean = NULL;
    axis2_ctx_t *ctx = NULL;
    axutil_property_t *property = NULL;
    axis2_bool_t commit = AXIS2_TRUE;

    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    sandesha2_report = sandesha2_report_create(env);
    internal_seq_find_bean = sandesha2_seq_property_bean_create(env);
    ctx = axis2_conf_ctx_get_base(conf_ctx, env);
    if(client_report_transaction)
    {
        report_transaction = client_report_transaction;
        commit = AXIS2_FALSE;
    }
    else
    {
        property = (axutil_property_t *) axis2_ctx_get_property(ctx, env, 
            SANDESHA2_WITHIN_TRANSACTION);
        if(property)
            within_transaction_str = (axis2_char_t *) axutil_property_get_value(
                property, env);
        if(within_transaction_str && 0 == axutil_strcmp(within_transaction_str, 
            AXIS2_VALUE_TRUE))
        {
            within_transaction = AXIS2_TRUE;
        }
        if(AXIS2_TRUE != within_transaction)
        {
            report_transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, 
                env);
        }
        client_report_transaction = report_transaction;
    }
    if(internal_seq_find_bean) 
        sandesha2_seq_property_bean_set_name(internal_seq_find_bean, env, 
            SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
    collection = sandesha2_seq_property_mgr_find(seq_prop_mgr, env, 
        internal_seq_find_bean);
    if(collection)
        size = axutil_array_list_size(collection, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_seq_property_bean_t *bean = NULL;
        axis2_char_t *seq_id = NULL;
        sandesha2_seq_report_t *report = NULL;
        axis2_char_t *value = NULL;
        axutil_array_list_t *completed_msgs = NULL;
        long no_of_msgs = 0;
        axis2_char_t status = -1;

        bean = (sandesha2_seq_property_bean_t *) axutil_array_list_get(
            collection, env, i);
        seq_id = sandesha2_seq_property_bean_get_seq_id(bean, env);
        sandesha2_report_add_to_outgoing_seq_list(sandesha2_report, env, seq_id);
        value = sandesha2_seq_property_bean_get_value(bean, env);
        sandesha2_report_add_to_outgoing_internal_seq_map(sandesha2_report, env,  
            seq_id, value);
        report = sandesha2_client_get_outgoing_seq_report_with_internal_seq_id(
            env, value, conf_ctx);
        completed_msgs = sandesha2_seq_report_get_completed_msgs(report, env);
        if(completed_msgs)
            no_of_msgs = axutil_array_list_size(completed_msgs, env);
        sandesha2_report_add_to_no_of_completed_msgs_map(sandesha2_report, env, 
            seq_id, no_of_msgs);
        status = sandesha2_seq_report_get_seq_status(report, env);
        sandesha2_report_add_to_seq_status_map(sandesha2_report, env, seq_id, status);
    }
    size = 0;
	/* incoming sequences */
    svr_completed_msgs_find_bean = sandesha2_seq_property_bean_create(env);
    if(svr_completed_msgs_find_bean)
        sandesha2_seq_property_bean_set_name(svr_completed_msgs_find_bean, env, 
            SANDESHA2_SEQ_PROP_SERVER_COMPLETED_MESSAGES);
    svr_completed_msgs_beans = sandesha2_seq_property_mgr_find(seq_prop_mgr, 
        env, svr_completed_msgs_find_bean);
    if(svr_completed_msgs_beans)
        size = axutil_array_list_size(svr_completed_msgs_beans, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_seq_property_bean_t *svr_completed_msgs_bean = NULL;
        axis2_char_t *seq_id = NULL;
        sandesha2_seq_report_t *seq_report = NULL;
        axis2_char_t *value = NULL;
        axutil_array_list_t *completed_msgs = NULL;
        long no_of_msgs = -1;
        axis2_char_t status = -1;

        svr_completed_msgs_bean = (sandesha2_seq_property_bean_t *) 
            axutil_array_list_get(svr_completed_msgs_beans, env, i);
        seq_id = sandesha2_seq_property_bean_get_seq_id(svr_completed_msgs_bean, 
            env);
        sandesha2_report_add_to_incoming_seq_list(sandesha2_report, env, seq_id);
        value = sandesha2_seq_property_bean_get_value(svr_completed_msgs_bean, 
            env);
        seq_report = sandesha2_client_get_incoming_seq_report(env, value, 
            conf_ctx);
        if(seq_report)
            completed_msgs = sandesha2_seq_report_get_completed_msgs(seq_report, 
                env);
        if(completed_msgs)
            no_of_msgs = axutil_array_list_size(completed_msgs, env);
        sandesha2_report_add_to_no_of_completed_msgs_map(sandesha2_report, env, 
            seq_id, no_of_msgs);
        status = sandesha2_seq_report_get_seq_status(seq_report, env);
        sandesha2_report_add_to_seq_status_map(sandesha2_report, env, seq_id, status);
    }
    if (AXIS2_TRUE != within_transaction && AXIS2_TRUE != rolled_back && 
        report_transaction != NULL && commit) 
    {
        sandesha2_transaction_commit(report_transaction, env);
        client_report_transaction = NULL;
    }
	return sandesha2_report;
}

axis2_status_t AXIS2_CALL
sandesha2_client_create_seq_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_bool_t offer)
{
    axis2_options_t *options = NULL;
    axis2_endpoint_ref_t *to_epr = NULL;
    axis2_char_t *to = NULL;
    axis2_char_t *seq_key = NULL;
    axutil_property_t *property = NULL;

    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    to_epr = axis2_options_get_to(options, env);
    if(!to_epr)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_EPR_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    to = (axis2_char_t*)axis2_endpoint_ref_get_address(to_epr, env);
    if(!to)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_EPR_NOT_SET, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    if(AXIS2_TRUE == offer)
    {
        axis2_char_t *offered_seq_id = NULL;
    
        offered_seq_id = axutil_uuid_gen(env);
        axis2_options_set_property(options, env, SANDESHA2_CLIENT_OFFERED_SEQ_ID, 
                offered_seq_id);
    }

	/* setting a new squence key if not already set.*/
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
            SANDESHA2_CLIENT_SEQ_KEY);
    if(property)
        seq_key = axutil_property_get_value(property, env);
	if (seq_key == NULL) 
    {
		seq_key = axutil_uuid_gen(env);
        property = axutil_property_create_with_args(env, 0, 0, 0, seq_key);
        axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, 
            property);
	}
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_DUMMY_MESSAGE, 
            AXIS2_VALUE_TRUE);
    axis2_svc_client_fire_and_forget(svc_client, env, NULL);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_DUMMY_MESSAGE, 
            AXIS2_VALUE_FALSE);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
sandesha2_client_create_seq_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_bool_t offer,
    axis2_char_t *seq_key)
{
    axis2_options_t *options = NULL;
    axutil_property_t *property = NULL;
    axutil_property_t *old_property = NULL;

    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    old_property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    property = axutil_property_create_with_args(env, 0, 0, 0, seq_key);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, property);
    sandesha2_client_create_seq_with_svc_client(env, svc_client, offer);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, old_property);

    return AXIS2_SUCCESS;
}

/**
 * User can terminate the sequence defined by the passed svc_client.
 * 
 * @param svc_client
 */
axis2_status_t AXIS2_CALL
sandesha2_client_terminate_seq_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_callback_t *callback,
    axis2_listener_manager_t *listener_manager)
{
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_options_t *options = NULL;
    axutil_property_t *property = NULL;
    axis2_char_t *rm_spec_version = NULL;
    axis2_char_t *rm_namespc_value = NULL;
    axis2_char_t *old_action = NULL;
    axis2_char_t *action = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL; 
    axiom_soap_envelope_t *terminate_envelope = NULL;
    axiom_soap_body_t *body = NULL;
    axiom_node_t *node = NULL;
    axiom_node_t *terminate_body_node = NULL;
    axiom_element_t *terminate_body_element = NULL;
    axiom_element_t *element = NULL;
    axutil_qname_t *qname = NULL;

    if(!svc_client)
        return AXIS2_FAILURE;
    svc_ctx = (axis2_svc_ctx_t *) axis2_svc_client_get_svc_ctx(svc_client, 
        env);
    if(!svc_ctx)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SVC_CTX_NULL, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
            SANDESHA2_CLIENT_RM_SPEC_VERSION);
    if(property)
        rm_spec_version = axutil_property_get_value(property, env);
    if(!rm_spec_version)
    {
        rm_spec_version = 
            sandesha2_spec_specific_consts_get_default_spec_version(env);
    }
    rm_namespc_value = sandesha2_spec_specific_consts_get_rm_ns_val(env, 
            rm_spec_version);
    conf_ctx =  axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
    terminate_envelope = sandesha2_client_configure_terminate_seq(env, options, 
            conf_ctx);
    if (!terminate_envelope)
        return AXIS2_FAILURE;
    body = axiom_soap_envelope_get_body(terminate_envelope, env);
    node = axiom_soap_body_get_base_node(body, env);
    element = axiom_node_get_data_element(node, env);
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_TERMINATE_SEQ, 
            rm_namespc_value, NULL);
    terminate_body_element = axiom_element_get_first_child_with_qname(element, 
        env, qname, node, &terminate_body_node);
    old_action = axutil_strdup(env, axis2_options_get_action(options, env));
    action = sandesha2_spec_specific_consts_get_terminate_seq_action(env, 
            rm_spec_version);
    if(action)
        axis2_options_set_action(options, env, action);
    sandesha2_client_fire_and_forget(env, svc_client, options, NULL, callback, 
        terminate_body_node, listener_manager);
    if(!AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        AXIS2_ERROR_SET(env->error, 
            SANDESHA2_ERROR_COULD_NOT_SEND_TERMINATE_MESSAGE, AXIS2_FAILURE);
        axis2_options_set_action(options, env, old_action);
        return AXIS2_FAILURE;
    }
    if(old_action)
        axis2_options_set_action(options, env, old_action);
    AXIS2_FREE(env->allocator, old_action);
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
sandesha2_client_terminate_seq_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_char_t *seq_key)
{
    axis2_options_t *options = NULL;
    axutil_property_t *property = NULL;
    axutil_property_t *old_property = NULL;
    
    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    old_property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    property = axutil_property_create_with_args(env, 0, 0, 0, seq_key);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, property);
    sandesha2_client_terminate_seq_with_svc_client(env, svc_client, NULL, NULL);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, old_property);
    return AXIS2_SUCCESS;
}

/**
 * User can close the seq defined by the passed svc_client.
 * 
 * @param svc_client
 */
axis2_status_t AXIS2_CALL
sandesha2_client_close_seq_with_svc_client(
        const axutil_env_t *env,
        axis2_svc_client_t *svc_client)
{
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_options_t *options = NULL;
    axis2_char_t *rm_spec_version = NULL;
    axis2_char_t *rm_namespc_value = NULL;
    axis2_char_t *old_action = NULL;
    axis2_char_t *action = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL; 
    axiom_soap_envelope_t *close_envelope = NULL;
    axiom_soap_body_t *body = NULL;
    axiom_node_t *node = NULL;
    axiom_node_t *close_body_node = NULL;
    axiom_element_t *close_body_element = NULL;
    axiom_element_t *element = NULL;
    axutil_qname_t *qname = NULL;
    axutil_property_t *property = NULL;
    
    svc_ctx = (axis2_svc_ctx_t *) axis2_svc_client_get_svc_ctx(svc_client, env);
    if(!svc_ctx)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SVC_CTX_NULL, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
            SANDESHA2_CLIENT_RM_SPEC_VERSION);
    if(property)
        rm_spec_version = axutil_property_get_value(property, env);
    if(!rm_spec_version)
    {
        rm_spec_version = 
            sandesha2_spec_specific_consts_get_default_spec_version(env);
    }
    rm_namespc_value = sandesha2_spec_specific_consts_get_rm_ns_val(env, 
            rm_spec_version);
    conf_ctx =  axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
    close_envelope = sandesha2_client_configure_close_seq(env, options, 
            conf_ctx);
    body = axiom_soap_envelope_get_body(close_envelope, env);
    node = axiom_soap_body_get_base_node(body, env);
    element = axiom_node_get_data_element(node, env);
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_CLOSE_SEQ, 
            rm_namespc_value, NULL);
    close_body_element = axiom_element_get_first_child_with_qname(element, env, 
            qname, node, &close_body_node);
    old_action = (axis2_char_t*)axis2_options_get_action(options, env);
    action = sandesha2_spec_specific_consts_get_close_seq_action(env, 
            rm_spec_version);
    axis2_options_set_action(options, env, action);

    axis2_svc_client_fire_and_forget(svc_client, env, close_body_node);
    if(AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_COULD_NOT_SEND_THE_CLOSE_SEQ_MESSAGE, 
                AXIS2_FAILURE);
        axis2_options_set_action(options, env, old_action);
        return AXIS2_FAILURE;
    }
    axis2_options_set_action(options, env, old_action);
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
sandesha2_client_close_seq_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_char_t *seq_key)
{
    axis2_options_t *options = NULL;
    axis2_char_t *spec_version = NULL;
    axutil_property_t *property = NULL;
    axutil_property_t *old_property = NULL;
    
    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    spec_version = (axis2_char_t *) axis2_options_get_property(options, env, 
            SANDESHA2_CLIENT_RM_SPEC_VERSION);
    if(0 != axutil_strcmp(SANDESHA2_SPEC_VERSION_1_1, spec_version))
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_CLOSE_SEQ_FEATURE_ONLY_AVAILABLE_FOR_WSRM1_1, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    old_property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    property = axutil_property_create_with_args(env, 0, 0, 0, seq_key);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, property);
    sandesha2_client_close_seq_with_svc_client(env, svc_client);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, old_property);
    return AXIS2_SUCCESS;
}

/**
 * This blocks the system until the messages sent have been completed.
 * 
 * @param svc_client
 */
axis2_status_t AXIS2_CALL
sandesha2_client_wait_until_seq_completed_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client)
{
    return sandesha2_client_wait_until_seq_completed_with_svc_client_and_max_waiting_time(env, 
            svc_client, -1);
}

axis2_status_t AXIS2_CALL
sandesha2_client_wait_until_seq_completed_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_char_t *seq_key)
{
    axis2_options_t *options = NULL;
    axutil_property_t *property = NULL;
    axutil_property_t *old_property = NULL;
    
    options = (axis2_options_t *)axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    old_property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, property);
    sandesha2_client_wait_until_seq_completed_with_svc_client(env, svc_client);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, old_property);
    return AXIS2_SUCCESS;
}

/**
 * This blocks the system until the messages sent have been completed
 * or until the given time interval exceeds. (the time is taken in seconds)
 * 
 * @param svc_client
 * @param max_waiting_time
 */
axis2_status_t AXIS2_CALL
sandesha2_client_wait_until_seq_completed_with_svc_client_and_max_waiting_time(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    long max_waiting_time)
{
    long start_time = -1;
    sandesha2_seq_report_t *seq_report = NULL;
    axis2_bool_t done = AXIS2_FALSE;
    
    start_time = sandesha2_utils_get_current_time_in_millis(env);
    seq_report = sandesha2_client_get_outgoing_seq_report_with_svc_client(env, svc_client);
    if(!seq_report)
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_CANNOT_FIND_SEQ_REPORT_FOR_GIVEN_DATA, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    while(AXIS2_TRUE != done)
    {
        int status = -1;

        seq_report = sandesha2_client_get_outgoing_seq_report_with_svc_client(env, svc_client);
        status = sandesha2_seq_report_get_seq_status(seq_report, env);
        if(status == SANDESHA2_SEQ_STATUS_TERMINATED)
            done = AXIS2_TRUE;
        if(status == SANDESHA2_SEQ_STATUS_TIMED_OUT)
            done = AXIS2_TRUE;
        if(max_waiting_time >= 0)
        {
            long time_now = sandesha2_utils_get_current_time_in_millis(env);
            if(time_now > (start_time + max_waiting_time))
                done = AXIS2_TRUE;
        }
    }
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
sandesha2_client_wait_until_seq_completed_with_svc_client_and_max_waiting_time_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    long max_waiting_time,
    axis2_char_t *seq_key)
{
    axis2_options_t *options = NULL;
    axutil_property_t *property = NULL;
    axutil_property_t *old_property = NULL;
    
    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    old_property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, property);
    sandesha2_client_wait_until_seq_completed_with_svc_client_and_max_waiting_time(
        env, svc_client, max_waiting_time);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, old_property);
    return AXIS2_SUCCESS;
}

/* 
 * gives the out seqID if CS/CSR exchange is done. Otherwise an error
 */
axis2_char_t *AXIS2_CALL
sandesha2_client_get_seq_id(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client)
{
    axis2_options_t *options = NULL;
    axis2_endpoint_ref_t *to_epr = NULL;
    axis2_char_t *to = NULL;
    axis2_char_t *seq_key = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_char_t *internal_seq_id = NULL;
    sandesha2_seq_report_t *seq_report = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *seq_id_bean = NULL;
    axis2_char_t *seq_id = NULL;
    axis2_char_t status = -1;
    axis2_conf_t *conf = NULL;
    axutil_property_t *property = NULL;

    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return NULL;
    }
    to_epr = axis2_options_get_to(options, env);
    if(!to_epr)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_EPR_NOT_SET, 
                AXIS2_FAILURE);
        return NULL;
    }
    to = (axis2_char_t*)axis2_endpoint_ref_get_address(to_epr, env);
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    seq_key = axutil_property_get_value(property, env);
   svc_ctx = (axis2_svc_ctx_t *) axis2_svc_client_get_svc_ctx(svc_client, env);
   if(!svc_ctx)
   {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SVC_CTX_NULL, AXIS2_FAILURE);
        return NULL;
   }
   conf_ctx =  axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
   internal_seq_id = 
       sandesha2_client_generate_internal_seq_id_for_the_client_side(env, to, 
               seq_key);
   seq_report = sandesha2_client_get_outgoing_seq_report_with_svc_client(env, svc_client);
    if(!seq_report)
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_CANNOT_FIND_SEQ_REPORT_FOR_GIVEN_DATA, 
                AXIS2_FAILURE);
        return NULL;
    }
    status = sandesha2_seq_report_get_seq_status(seq_report, env);
    if(status != SANDESHA2_SEQ_STATUS_ESTABLISHED)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SEQ_NOT_IN_ACTIVE_STATE, AXIS2_FAILURE);
        return NULL;
    }
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    seq_id_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
            internal_seq_id, SANDESHA2_SEQ_PROP_OUT_SEQ_ID);
    if(!seq_id_bean)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SEQ_ID_BEAN_NOT_SET, 
                AXIS2_FAILURE);
        return NULL;
    }
    seq_id = sandesha2_seq_property_bean_get_value(seq_id_bean, env);
    return seq_id;
}

axis2_status_t AXIS2_CALL
sandesha2_client_send_ack_request_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client)
{
    axis2_options_t *options = NULL;
    axis2_endpoint_ref_t *to_epr = NULL;
    axis2_char_t *to = NULL;
    axis2_char_t *seq_key = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_char_t *internal_seq_id = NULL;
    sandesha2_seq_report_t *seq_report = NULL;
    axis2_char_t status = -1;
    axis2_char_t *out_seq_id = NULL;
    axis2_char_t *soap_ns_uri = NULL;
    axis2_char_t *rm_ns_value = NULL;
    axis2_char_t *rm_spec_version = NULL;
    axiom_soap_envelope_t *dummy_envelope = NULL;
    sandesha2_ack_requested_t *ack_requested = NULL;
    sandesha2_identifier_t *identifier = NULL;
    axiom_soap_header_t *header = NULL;
    axiom_node_t *node = NULL;
    axiom_element_t *element = NULL;
    axutil_qname_t *qname = NULL;
    axiom_element_t *ack_requested_header_block = NULL;
    axiom_node_t *ack_requested_header_block_node = NULL;
    axis2_char_t *old_action = NULL;
    axis2_char_t *action = NULL;
    axutil_property_t *property = NULL;
    
    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    svc_ctx = (axis2_svc_ctx_t *) axis2_svc_client_get_svc_ctx(svc_client, env);
    if(!svc_ctx)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SVC_CTX_NULL, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    conf_ctx =  axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
    to_epr = axis2_options_get_to(options, env);
    if(!to_epr)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_EPR_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    to = (axis2_char_t*)axis2_endpoint_ref_get_address(to_epr, env);
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    seq_key = axutil_property_get_value(property, env);
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_RM_SPEC_VERSION);
    if(property)
        rm_spec_version = axutil_property_get_value(property, env);
    if(!rm_spec_version)
    {
        rm_spec_version = axutil_strdup(env, SANDESHA2_SPEC_VERSION_1_0); 
    }
    if(0  == axutil_strcmp(rm_spec_version, SANDESHA2_SPEC_VERSION_1_0))
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_EMPTY_ACK_REQUEST_MESSAGE, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    internal_seq_id = sandesha2_client_get_internal_seq_id(env, to, seq_key);
    seq_report = sandesha2_client_get_outgoing_seq_report_with_internal_seq_id(
            env, internal_seq_id, conf_ctx);
    if(!seq_report)
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_CANNOT_GENERATE_SEQ_REPORT_FOR_GIVEN_INTERNAL_SEQ_ID, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    status = sandesha2_seq_report_get_seq_status(seq_report, env);
    if(status != SANDESHA2_SEQ_STATUS_ESTABLISHED)
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_CANNOT_SEND_ACK_REQUEST_MESSAGE_SINCE_IS_NOT_ACTIVE, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    out_seq_id = sandesha2_client_get_seq_id(env, svc_client);
    soap_ns_uri = (axis2_char_t *) axis2_options_get_soap_version_uri(options, env);
    if(0 == axutil_strcmp(AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI, soap_ns_uri))
    {
        dummy_envelope = axiom_soap_envelope_create_default_soap_envelope(env, 
                AXIOM_SOAP11); 
    }
    else
    {
        dummy_envelope = axiom_soap_envelope_create_default_soap_envelope(env, 
                AXIOM_SOAP12); 
    }
    rm_ns_value = sandesha2_spec_specific_consts_get_rm_ns_val(env, rm_spec_version);
    ack_requested = sandesha2_ack_requested_create(env, rm_ns_value);
    identifier = sandesha2_identifier_create(env, rm_ns_value);
    sandesha2_identifier_set_identifier(identifier, env, out_seq_id);
    sandesha2_ack_requested_set_identifier(ack_requested, env, identifier);
    sandesha2_iom_rm_part_to_soap_envelope((sandesha2_iom_rm_part_t *) 
            ack_requested, env, dummy_envelope);
    header = axiom_soap_envelope_get_header(dummy_envelope, env);
    node = axiom_soap_header_get_base_node(header, env);
    element = axiom_node_get_data_element(node, env);
    qname = axutil_qname_create(env, SANDESHA2_WSRM_COMMON_ACK_REQUESTED, 
            rm_ns_value, NULL);
    ack_requested_header_block = axiom_element_get_first_child_with_qname(
            element, env, qname, node, &ack_requested_header_block_node);
    old_action = (axis2_char_t*)axis2_options_get_action(options, env);
    action = sandesha2_spec_specific_consts_get_ack_req_action(env, 
            rm_spec_version);
    axis2_options_set_action(options, env, action);
    axis2_svc_client_add_header(svc_client, env, ack_requested_header_block_node); 
    axis2_svc_client_fire_and_forget(svc_client, env, NULL);
    axis2_svc_client_remove_all_headers(svc_client, env);
    axis2_options_set_action(options, env, old_action);
    
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
sandesha2_client_send_ack_request_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_char_t *seq_key)
{
    axis2_options_t *options = NULL;
    axutil_property_t *property = NULL;
    axutil_property_t *old_property = NULL;

    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    old_property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    property = axutil_property_create_with_args(env, 0, 0, 0, seq_key);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, property);
    sandesha2_client_send_ack_request_with_svc_client(env, svc_client);
    axis2_options_set_property(options, env, SANDESHA2_CLIENT_SEQ_KEY, old_property);
    return AXIS2_SUCCESS;
}

/**
 * Caller must free the returned internal_seq_id
 * @param to
 * @param seq_key
 *
 * @return internal_seq_id
 */
static axis2_char_t *
sandesha2_client_get_internal_seq_id(
    const axutil_env_t *env,
    axis2_char_t *to,
    axis2_char_t *seq_key)
{
    return (axis2_char_t *) sandesha2_utils_get_internal_seq_id(env, to, seq_key);
}

static axiom_soap_envelope_t *
sandesha2_client_configure_close_seq(
    const axutil_env_t *env,
    axis2_options_t *options, 
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_endpoint_ref_t *to_epr = NULL;
    axis2_char_t *to = NULL;
    axis2_char_t *seq_key = NULL;
    axis2_char_t *internal_seq_id = NULL;
    sandesha2_close_seq_t *close_seq = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *seq_id_bean = NULL;
    axis2_char_t *seq_id = NULL;
    axis2_char_t status = -1;
    axis2_char_t *soap_ns_uri = NULL;
    axis2_char_t *rm_ns_value = NULL;
    axis2_char_t *rm_spec_version = NULL;
    axiom_soap_envelope_t *dummy_envelope = NULL;
    sandesha2_identifier_t *identifier = NULL;
    sandesha2_seq_report_t *seq_report = NULL;
    axis2_conf_t *conf = NULL;
    axutil_property_t *property = NULL;

    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    to_epr = axis2_options_get_to(options, env);
    if(!to_epr)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_EPR_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    to = (axis2_char_t*)axis2_endpoint_ref_get_address(to_epr, env);
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
            SANDESHA2_CLIENT_SEQ_KEY);
    seq_key = axutil_property_get_value(property, env);
    internal_seq_id = sandesha2_utils_get_internal_seq_id(env, to, seq_key);

    seq_report = sandesha2_client_get_outgoing_seq_report_with_internal_seq_id(
            env, internal_seq_id, conf_ctx);
    if(!seq_report)
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_CANNOT_FIND_SEQ_REPORT_FOR_GIVEN_SEQ_ID, 
                AXIS2_FAILURE);
        return NULL;
    }
    status = sandesha2_seq_report_get_seq_status(seq_report, env);
    if(status != SANDESHA2_SEQ_STATUS_ESTABLISHED)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SEQ_NOT_IN_ACTIVE_STATE, AXIS2_FAILURE);
        return NULL;
    }
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    seq_id_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
            internal_seq_id, SANDESHA2_SEQ_PROP_OUT_SEQ_ID);
    if(!seq_id_bean)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SEQ_ID_BEAN_NOT_SET, 
                AXIS2_FAILURE);
        return NULL;
    }
    seq_id = sandesha2_seq_property_bean_get_value(seq_id_bean, env);
    if(!seq_id)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CANNOT_FIND_SEQ_ID, 
                AXIS2_FAILURE);
        return NULL;
    }
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
            SANDESHA2_CLIENT_RM_SPEC_VERSION);
    if(property)
        rm_spec_version = axutil_property_get_value(property, env);
    if(!rm_spec_version)
    {
        rm_spec_version = 
            sandesha2_spec_specific_consts_get_default_spec_version(env);
    }
    if(AXIS2_TRUE != sandesha2_spec_specific_consts_is_seq_closing_allowed(env, 
                rm_spec_version))
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_RM_VERSION_DOES_NOT_ALLOW_SEQ_CLOSING, 
                AXIS2_FAILURE);
        return NULL;
    }
    soap_ns_uri = (axis2_char_t *) axis2_options_get_soap_version_uri(options, env);
    if(0 == axutil_strcmp(AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI, soap_ns_uri))
    {
        dummy_envelope = axiom_soap_envelope_create_default_soap_envelope(env, 
                AXIOM_SOAP12); 
    }
    else
    {
        dummy_envelope = axiom_soap_envelope_create_default_soap_envelope(env, 
                AXIOM_SOAP11); 
    }
    rm_ns_value = sandesha2_spec_specific_consts_get_rm_ns_val(env, rm_spec_version);
    close_seq = sandesha2_close_seq_create(env, rm_ns_value);
    identifier = sandesha2_identifier_create(env, rm_ns_value);
    sandesha2_identifier_set_identifier(identifier, env, seq_id);
    sandesha2_close_seq_set_identifier(close_seq, env, identifier);
    sandesha2_iom_rm_part_to_soap_envelope((sandesha2_iom_rm_part_t *) close_seq, 
            env, dummy_envelope);

    return dummy_envelope;

}

static axis2_bool_t
sandesha2_client_is_seq_terminated(
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id,
    sandesha2_seq_property_mgr_t *seq_prop_mgr)
{
    sandesha2_seq_property_bean_t *internal_seq_find_bean = NULL;
    sandesha2_seq_property_bean_t *internal_seq_bean = NULL;
    axis2_char_t *out_seq_id = NULL;
    sandesha2_seq_property_bean_t *seq_terminated_bean = NULL;
    axis2_char_t *value = NULL;

    internal_seq_find_bean =sandesha2_seq_property_bean_create(env);
    if(!internal_seq_find_bean)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FALSE;
    }
    sandesha2_seq_property_bean_set_value(internal_seq_find_bean, env, 
            internal_seq_id);
    sandesha2_seq_property_bean_set_name(internal_seq_find_bean, env, 
           SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
    internal_seq_bean = sandesha2_seq_property_mgr_find_unique(seq_prop_mgr, 
            env, internal_seq_find_bean);
    if(!internal_seq_bean)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "Internal sequence bean is not available for the given sequence.");
        return AXIS2_FALSE;
    }
    out_seq_id = sandesha2_seq_property_bean_get_seq_id(internal_seq_bean, env);
    seq_terminated_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
            out_seq_id, SANDESHA2_SEQ_PROP_SEQ_TERMINATED);
    if(seq_terminated_bean)
    {
        value = sandesha2_seq_property_bean_get_value(seq_terminated_bean, env);
        if(0 == axutil_strcmp(AXIS2_VALUE_TRUE, value))
        {
            return AXIS2_TRUE;
        }
    }
    return AXIS2_FALSE;
    
}

static axis2_bool_t
sandesha2_client_is_seq_timedout(
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id,
    sandesha2_seq_property_mgr_t *seq_prop_mgr)
{
    sandesha2_seq_property_bean_t *internal_seq_find_bean = NULL;
    sandesha2_seq_property_bean_t *internal_seq_bean = NULL;
    axis2_char_t *out_seq_id = NULL;
    sandesha2_seq_property_bean_t *seq_terminated_bean = NULL;
    axis2_char_t *value = NULL;

    internal_seq_find_bean =sandesha2_seq_property_bean_create(env);
    if(!internal_seq_find_bean)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FALSE;
    }
    sandesha2_seq_property_bean_set_value(internal_seq_find_bean, env, 
            internal_seq_id);
    sandesha2_seq_property_bean_set_name(internal_seq_find_bean, env, 
           SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
    internal_seq_bean = sandesha2_seq_property_mgr_find_unique(seq_prop_mgr, 
            env, internal_seq_find_bean);
    if(!internal_seq_bean)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "Internal sequence bean is not available for the given sequence.");
        return AXIS2_FALSE;
    }
    out_seq_id = sandesha2_seq_property_bean_get_seq_id(internal_seq_bean, env);
    seq_terminated_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
            out_seq_id, SANDESHA2_SEQ_PROP_SEQ_TIMED_OUT);
    if(seq_terminated_bean)
        value = sandesha2_seq_property_bean_get_value(seq_terminated_bean, env);
    if(seq_terminated_bean != NULL && 0 == axutil_strcmp(AXIS2_VALUE_TRUE, value))
    {
        return AXIS2_TRUE;
    }
    return AXIS2_FALSE;
    
}

static axis2_status_t
sandesha2_client_fill_terminated_outgoing_seq_info(
    const axutil_env_t *env,
    sandesha2_seq_report_t *report,
    axis2_char_t *internal_seq_id,
    sandesha2_seq_property_mgr_t *seq_prop_mgr)
{
    sandesha2_seq_property_bean_t *internal_seq_find_bean = NULL;
    sandesha2_seq_property_bean_t *internal_seq_bean = NULL;
    axis2_char_t *out_seq_id = NULL;

    internal_seq_find_bean =sandesha2_seq_property_bean_create(env);
    if(!internal_seq_find_bean)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FALSE;
    }
    sandesha2_seq_property_bean_set_value(internal_seq_find_bean, env, 
            internal_seq_id);
    sandesha2_seq_property_bean_set_name(internal_seq_find_bean, env, 
           SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
    internal_seq_bean = sandesha2_seq_property_mgr_find_unique(seq_prop_mgr, 
            env, internal_seq_find_bean);
    if(!internal_seq_bean)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "Not a valid terminated sequence. Internal sequence bean is not \
                available for the given sequence.");
        AXIS2_ERROR_SET(env->error, NOT_A_VALID_TERMINATED_SEQ, AXIS2_FAILURE); 
        return AXIS2_FAILURE;
    }
    sandesha2_seq_report_set_seq_status(report, env, 
            SANDESHA2_SEQ_STATUS_TERMINATED);
    out_seq_id = sandesha2_seq_property_bean_get_seq_id(internal_seq_bean, env);
    sandesha2_client_fill_outgoing_seq_info(env, report, out_seq_id, seq_prop_mgr);
    return AXIS2_SUCCESS; 
}

/*static axis2_status_t
sandesha2_client_fill_timedout_outgoing_seq_info(
    const axutil_env_t *env,
    sandesha2_seq_report_t *report,
    axis2_char_t *internal_seq_id,
    sandesha2_seq_property_mgr_t *seq_prop_mgr)
{
    sandesha2_seq_property_bean_t *internal_seq_find_bean = NULL;
    sandesha2_seq_property_bean_t *internal_seq_bean = NULL;
    axis2_char_t *out_seq_id = NULL;

    internal_seq_find_bean =sandesha2_seq_property_bean_create(env);
    if(!internal_seq_find_bean)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FALSE;
    }
    sandesha2_seq_property_bean_set_value(internal_seq_find_bean, env, 
            internal_seq_id);
    sandesha2_seq_property_bean_set_name(internal_seq_find_bean, env, 
           SANDESHA2_SEQ_PROP_INTERNAL_SEQ_ID);
    internal_seq_bean = sandesha2_seq_property_mgr_find_UNIQUE(seq_prop_mgr, 
            env, internal_seq_find_bean);
    if(!internal_seq_bean)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
                "Not a valid terminated sequence. Internal sequence bean is not \
                available for the given sequence.");
        AXIS2_ERROR_SET(env->error, NOT_A_VALID_TERMINATED_SEQ, AXIS2_FAILURE); 
        return AXIS2_FAILURE;
    }
    sandesha2_seq_report_set_seq_status(report, env, 
            SANDESHA2_SEQ_STATUS_TIMED_OUT);
    out_seq_id = sandesha2_seq_property_bean_get_seq_id(internal_seq_bean, env);
    sandesha2_client_fill_outgoing_seq_info(env, report, out_seq_id, seq_prop_mgr);
    return AXIS2_SUCCESS; 
}*/

static axis2_status_t
sandesha2_client_fill_outgoing_seq_info(
    const axutil_env_t *env,
    sandesha2_seq_report_t *report,
    axis2_char_t *out_seq_id,
    sandesha2_seq_property_mgr_t *seq_prop_mgr)
{
    axutil_array_list_t *completed_msg_list = NULL;
    int i = 0, size = 0;
    
    sandesha2_seq_report_set_seq_id(report, env, out_seq_id);
    completed_msg_list = sandesha2_ack_mgr_get_client_completed_msgs_list(env,
            out_seq_id, seq_prop_mgr);
    if(completed_msg_list)
        size = axutil_array_list_size(completed_msg_list, env);
    for(i = 0; i < size; i++)
    {
        axis2_char_t *value = NULL;
        long *lng = AXIS2_MALLOC(env->allocator, sizeof(long));
        value =  axutil_array_list_get(completed_msg_list, env, i);
        *lng = atol(value);
        sandesha2_seq_report_add_completed_msg(report, env, lng);
    }
    return AXIS2_SUCCESS; 
}

static axis2_char_t
sandesha2_client_get_svr_seq_status(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    sandesha2_seq_property_bean_t *terminated_bean = NULL;
    sandesha2_seq_property_bean_t *timedout_bean = NULL;
    sandesha2_next_msg_mgr_t *next_msg_mgr = NULL;
    sandesha2_next_msg_bean_t *next_msg_bean = NULL;
    
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env);
    terminated_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
        seq_id, SANDESHA2_SEQ_PROP_SEQ_TERMINATED);
    if(terminated_bean != NULL)
    {
        return SANDESHA2_SEQ_STATUS_TERMINATED;
    }
    timedout_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
        seq_id, SANDESHA2_SEQ_PROP_SEQ_TIMED_OUT);
    if(timedout_bean)
    {
        return SANDESHA2_SEQ_STATUS_TIMED_OUT;
    }
    next_msg_mgr = sandesha2_storage_mgr_get_next_msg_mgr(storage_mgr, env);
    next_msg_bean = sandesha2_next_msg_mgr_retrieve(next_msg_mgr, env, seq_id);
    if(next_msg_bean)
    {
        return SANDESHA2_SEQ_STATUS_ESTABLISHED;
    }
    AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_UNRECORDED_SEQ_ID, AXIS2_FAILURE);
    return -1;
}

static axis2_char_t *
sandesha2_client_generate_internal_seq_id_for_the_client_side(
    const axutil_env_t *env,
    axis2_char_t *to_epr,
    axis2_char_t *seq_key)
{
    return sandesha2_utils_get_internal_seq_id(env, to_epr, seq_key); 
}

static sandesha2_seq_report_t *
sandesha2_client_get_incoming_seq_report(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_conf_ctx_t *conf_ctx)
{
    sandesha2_seq_report_t *seq_report = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    axis2_conf_t *conf = NULL;
    axis2_ctx_t *ctx = NULL;
    axutil_property_t *property = NULL;
    axis2_bool_t within_transaction = AXIS2_FALSE;
    sandesha2_transaction_t *report_transaction = NULL;
    axutil_array_list_t *completed_msg_list = NULL;
    axis2_char_t *within_transaction_str = NULL;
    axis2_char_t status = -1;
    axis2_bool_t commit = AXIS2_TRUE;
    int i = 0, size = 0;
    
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, seq_id, NULL);
    AXIS2_PARAM_CHECK(env->error, conf_ctx, NULL);

    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf); 
    seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(storage_mgr, env); 
    ctx = axis2_conf_ctx_get_base(conf_ctx, env);
    if(client_report_transaction)
    {
        report_transaction = client_report_transaction;
        commit = AXIS2_FALSE;
    }
    else
    {
        property = axis2_ctx_get_property(ctx, env, SANDESHA2_WITHIN_TRANSACTION);
        if(property)
            within_transaction_str = (axis2_char_t *) axutil_property_get_value(
                property, env);
        if(within_transaction_str && 0 == axutil_strcmp(within_transaction_str, 
            AXIS2_VALUE_TRUE))
        {
            within_transaction = AXIS2_TRUE;
        }
        if(!within_transaction)
        {
            report_transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, 
                env);
        }
    }
    seq_report = sandesha2_seq_report_create(env);
    completed_msg_list = sandesha2_ack_mgr_get_svr_completed_msgs_list(env, 
        seq_id, seq_prop_mgr);
    if(completed_msg_list)
        size = axutil_array_list_size(completed_msg_list, env);
    for(i = 0; i < size; i++)
    {
        long *lng = NULL;
        axis2_char_t *value = axutil_array_list_get(completed_msg_list, env, i);
        
        *lng = atol(value);
        sandesha2_seq_report_add_completed_msg(seq_report, env, lng);
    }
    sandesha2_seq_report_set_seq_id(seq_report, env, seq_id);
    sandesha2_seq_report_set_internal_seq_id(seq_report, env, seq_id); /* For
        incoming side internal_seq_id = seq_id*/
    sandesha2_seq_report_set_seq_direction(seq_report, env, 
        SANDESHA2_SEQ_DIRECTION_IN);
    status = sandesha2_client_get_svr_seq_status(env, seq_id, storage_mgr);
    sandesha2_seq_report_set_seq_status(seq_report, env, 
        status);
    if(commit)
        sandesha2_transaction_commit(report_transaction, env);
   
    return seq_report;
}

static axiom_soap_envelope_t *
sandesha2_client_configure_terminate_seq(
    const axutil_env_t *env,
    axis2_options_t *options, 
    axis2_conf_ctx_t *conf_ctx)
{
    axis2_endpoint_ref_t *to_epr = NULL;
    axis2_char_t *to = NULL;
    axis2_char_t *seq_key = NULL;
    axis2_char_t *internal_seq_id = NULL;
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    sandesha2_seq_property_mgr_t *seq_prop_mgr = NULL;
    axis2_char_t status = -1;
    axis2_char_t *soap_ns_uri = NULL;
    axiom_soap_envelope_t *dummy_envelope = NULL;
    axis2_char_t *action = NULL;
    sandesha2_seq_report_t *seq_report = NULL;
    axis2_conf_t *conf = NULL;
    axutil_property_t *property = NULL;
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    to_epr = axis2_options_get_to(options, env);
    if(!to_epr)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_TO_EPR_NOT_SET, 
                AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    to = (axis2_char_t*)axis2_endpoint_ref_get_address(to_epr, env);
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    if(property)
        seq_key = axutil_property_get_value(property, env);
    internal_seq_id = sandesha2_utils_get_internal_seq_id(env, to, seq_key);

    seq_report = sandesha2_client_get_outgoing_seq_report_with_internal_seq_id(
            env, internal_seq_id, conf_ctx);
    if(!seq_report)
    {
        AXIS2_ERROR_SET(env->error, 
                SANDESHA2_ERROR_CANNOT_FIND_SEQ_REPORT_FOR_GIVEN_SEQ_ID, 
                AXIS2_FAILURE);
        return NULL;
    }
    status = sandesha2_seq_report_get_seq_status(seq_report, env);
    if(status != SANDESHA2_SEQ_STATUS_ESTABLISHED)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SEQ_NOT_IN_ACTIVE_STATE, 
            AXIS2_FAILURE);
        return NULL;
    }
    if(conf_ctx)
    {
        axutil_property_t *property = NULL;
        axis2_char_t *rm_spec_version = NULL;
        axis2_char_t *rm_ns_value = NULL;
        sandesha2_terminate_seq_t *terminate_seq = NULL;
        sandesha2_identifier_t *identifier = NULL;
        sandesha2_seq_property_bean_t *seq_id_bean = NULL;
        axis2_char_t *seq_id = NULL;
        sandesha2_transaction_t *transaction = NULL;

        conf = axis2_conf_ctx_get_conf(conf_ctx, env);
        storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
        if(storage_mgr)
        {
            seq_prop_mgr = sandesha2_storage_mgr_get_seq_property_mgr(
                storage_mgr, env);
            transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, 
                env);
        }
        if(seq_prop_mgr)
            seq_id_bean = sandesha2_seq_property_mgr_retrieve(seq_prop_mgr, env, 
                internal_seq_id, SANDESHA2_SEQ_PROP_OUT_SEQ_ID);
        if(transaction)
        {
            sandesha2_transaction_commit(transaction, env);
            client_report_transaction = NULL;
        }
        if(!seq_id_bean)
        {
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SEQ_ID_BEAN_NOT_SET, 
                AXIS2_FAILURE);
            return NULL;
        }
        seq_id = sandesha2_seq_property_bean_get_value(seq_id_bean, env);
        if(!seq_id)
        {
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CANNOT_FIND_SEQ_ID, 
                AXIS2_FAILURE);
            return NULL;
        }
        property = axis2_options_get_property(options, env, 
            SANDESHA2_CLIENT_RM_SPEC_VERSION);
        if(property)
            rm_spec_version = axutil_property_get_value(property, env);
        if(!rm_spec_version)
        {
            rm_spec_version = 
                sandesha2_spec_specific_consts_get_default_spec_version(env);
        }
        action = sandesha2_spec_specific_consts_get_terminate_seq_action(env, 
            rm_spec_version);
        axis2_options_set_action(options, env, action);
        soap_ns_uri = (axis2_char_t *) axis2_options_get_soap_version_uri(options, 
            env);
        if(0 == axutil_strcmp(AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI, soap_ns_uri))
        {
            dummy_envelope = axiom_soap_envelope_create_default_soap_envelope(env, 
                AXIOM_SOAP12); 
        }
        else
        {
            dummy_envelope = axiom_soap_envelope_create_default_soap_envelope(env, 
                AXIOM_SOAP11); 
        }
        rm_ns_value = sandesha2_spec_specific_consts_get_rm_ns_val(env, 
            rm_spec_version);
        terminate_seq = sandesha2_terminate_seq_create(env, rm_ns_value);
        identifier = sandesha2_identifier_create(env, rm_ns_value);
        if(identifier)
            sandesha2_identifier_set_identifier(identifier, env, seq_id);
        if(terminate_seq)
        {
            sandesha2_terminate_seq_set_identifier(terminate_seq, env, 
                identifier);
            sandesha2_iom_rm_part_to_soap_envelope((sandesha2_iom_rm_part_t *)  
                terminate_seq, env, dummy_envelope);
        }
        return dummy_envelope;
    }
    else
        return NULL;
}

axis2_status_t AXIS2_CALL
sandesha2_client_send_non_blocking(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_options_t *options,
    axutil_qname_t *op_qname,
    axis2_callback_t *callback,
    axiom_node_t *payload,
    axis2_listener_manager_t *listener_manager)
{
    axis2_op_client_t *op_client = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_svc_t *svc = NULL;
    axis2_op_t *op = NULL;
    axis2_callback_recv_t *callback_recv = NULL;
    AXIS2_TRANSPORT_ENUMS transport_in_protocol = -1;

    if(!op_qname)
        op_qname = axutil_qname_create(env, AXIS2_ANON_OUT_IN_OP, NULL, NULL);
    svc_ctx = axis2_svc_client_get_svc_ctx(svc_client, env);
    conf_ctx =  axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
    msg_ctx = axis2_msg_ctx_create(env, conf_ctx, NULL, NULL);
    svc = axis2_svc_client_get_svc(svc_client, env);
    op = axis2_svc_get_op_with_qname(svc, env,
            op_qname);
    op_client = axis2_op_client_create(env, op, svc_ctx, options);
    if (!op_client)
    {
        return AXIS2_FAILURE;
    }
    if (!fill_soap_envelope(env, msg_ctx, options, payload))
        return AXIS2_FAILURE;
    axis2_op_client_set_callback(op_client, env, callback);
    axis2_op_client_add_out_msg_ctx(op_client, env, msg_ctx);
    transport_in_protocol = axis2_options_get_transport_in_protocol(
        options, env);
    axis2_listener_manager_make_sure_started(listener_manager, env, 
            transport_in_protocol, conf_ctx);
    callback_recv = axis2_callback_recv_create(env);
    if (!(callback_recv))
    {
        axis2_svc_client_free(svc_client, env);
        return AXIS2_FAILURE;
    }

    axis2_op_set_msg_recv(op, env,
            AXIS2_CALLBACK_RECV_GET_BASE(callback_recv, env));
    axis2_op_client_set_callback_recv(op_client, env, callback_recv);
    return axis2_op_client_execute(op_client, env, AXIS2_FALSE);
}

void AXIS2_CALL
sandesha2_client_fire_and_forget(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_options_t *options,
    axutil_qname_t *op_qname,
    axis2_callback_t *callback,
    axiom_node_t *payload,
    axis2_listener_manager_t *listener_manager)
{
    axis2_op_client_t *op_client = NULL;
    axis2_svc_ctx_t *svc_ctx = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axis2_svc_t *svc = NULL;
    axis2_op_t *op = NULL;
    axis2_callback_recv_t *callback_recv = NULL;
    AXIS2_TRANSPORT_ENUMS transport_in_protocol = -1;
    axis2_bool_t block = AXIS2_TRUE;

    if (!op_qname)
    {
        op_qname = axutil_qname_create(env, AXIS2_ANON_OUT_ONLY_OP, NULL, NULL);
    }
    svc_ctx = axis2_svc_client_get_svc_ctx(svc_client, env);
    conf_ctx =  axis2_svc_ctx_get_conf_ctx(svc_ctx, env);
    msg_ctx = axis2_msg_ctx_create(env, conf_ctx, NULL, NULL);
	svc = axis2_svc_client_get_svc(svc_client, env);
    op = axis2_svc_get_op_with_qname(svc, env, op_qname);
    if (!fill_soap_envelope(env, msg_ctx, options, payload))
    {
        return;
    }
    op_client = axis2_op_client_create(env, op, svc_ctx, options);
    if (!op_client)
    {
        return;
    }
    if(callback)
    {
        axis2_op_client_set_callback(op_client, env, callback);
        /*axis2_op_client_add_out_msg_ctx(op_client, env, msg_ctx);*/
        transport_in_protocol = axis2_options_get_transport_in_protocol(
            options, env);
        axis2_listener_manager_make_sure_started(listener_manager, env,
            transport_in_protocol, conf_ctx);
        callback_recv = axis2_callback_recv_create(env);
        if (!(callback_recv))
        {
            axis2_svc_client_free(svc_client, env);
        }
        axis2_op_set_msg_recv(op, env, AXIS2_CALLBACK_RECV_GET_BASE(callback_recv, 
            env));
        axis2_op_client_set_callback_recv(op_client, env, callback_recv);
        block = AXIS2_FALSE;
    }
    axis2_op_client_add_out_msg_ctx(op_client, env, msg_ctx);
    axis2_op_client_execute(op_client, env, block);
}

static axis2_bool_t
fill_soap_envelope(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_options_t *options,
    const axiom_node_t *payload)
{
    const axis2_char_t *soap_version_uri;
    int soap_version;
    axiom_soap_envelope_t *envelope = NULL;

    soap_version_uri = axis2_options_get_soap_version_uri(options, env);

    if (!soap_version_uri)
    {
        return AXIS2_FALSE;
    }

    if (axutil_strcmp(soap_version_uri,
            AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI) == 0)
        soap_version = AXIOM_SOAP11;
    else
        soap_version = AXIOM_SOAP12;

    envelope = axiom_soap_envelope_create_default_soap_envelope(env,
            soap_version);
    if (!envelope)
    {
        return AXIS2_FALSE;
    }
    if (payload)
    {
        axiom_soap_body_t *soap_body = NULL;
        soap_body = axiom_soap_envelope_get_body(envelope, env);
        if (soap_body)
        {
            axiom_node_t *node = NULL;
            node = axiom_soap_body_get_base_node(soap_body, env);
            if (node)
            {
                axiom_node_add_child(node, env, (axiom_node_t *)payload);
            }
        }
    }
    axis2_msg_ctx_set_soap_envelope(msg_ctx, env, envelope);

    return AXIS2_TRUE;
}

/**
 * In RM 1.0 two way single channel messaging user need
 * to call for the response envelope.
 *
 * @param conf_ctx
 * @param svc_client
 * @param msg_no
 * @return response soap envelope
 */
axiom_node_t *AXIS2_CALL
sandesha2_client_get_response_envelope(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_svc_client_t *svc_client,
    int msg_no)
{
    sandesha2_storage_mgr_t *storage_mgr = NULL;
    axis2_conf_t *conf = NULL;
    axis2_char_t *within_transaction_str = NULL;
    axis2_bool_t within_transaction = AXIS2_FALSE;
    sandesha2_transaction_t *transaction = NULL;
    axis2_ctx_t *ctx = NULL;
    axutil_property_t *property = NULL;
    axis2_options_t *options = NULL;
    axis2_char_t *client_seq_key = NULL;
    axiom_soap_envelope_t *response_envelope = NULL;
    axiom_soap_body_t *body = NULL;
    axiom_node_t *result = NULL;

    options = (axis2_options_t *) axis2_svc_client_get_options(svc_client, env);
    if(!options)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_OPTIONS_OBJECT_NOT_SET, 
            AXIS2_FAILURE);
        return NULL;
    }
    property = (axutil_property_t *) axis2_options_get_property(options, env, 
        SANDESHA2_CLIENT_SEQ_KEY);
    client_seq_key = axutil_property_get_value(property, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    storage_mgr = sandesha2_utils_get_storage_mgr(env, conf_ctx, conf);
    ctx = axis2_conf_ctx_get_base(conf_ctx, env);
    property = (axutil_property_t *) axis2_ctx_get_property(ctx, env, 
        SANDESHA2_WITHIN_TRANSACTION);
    if(property)
        within_transaction_str = (axis2_char_t *) axutil_property_get_value(
            property, env);
    if(within_transaction_str && 0 == axutil_strcmp(within_transaction_str, 
        AXIS2_VALUE_TRUE))
    {
        within_transaction = AXIS2_TRUE;
    }
    if(AXIS2_TRUE != within_transaction)
    {
        transaction = sandesha2_storage_mgr_get_transaction(storage_mgr, env);
    }
    response_envelope = sandesha2_storage_mgr_retrieve_response(storage_mgr, env, 
        client_seq_key, msg_no);
    if(response_envelope)
        body = axiom_soap_envelope_get_body(response_envelope, env);
    if(body)
        result = axiom_soap_body_get_base_node(body, env);
    sandesha2_storage_mgr_remove_response(storage_mgr, env, client_seq_key, 
        msg_no);
    sandesha2_transaction_commit(transaction, env);
    client_report_transaction = NULL;
    return result;
}

