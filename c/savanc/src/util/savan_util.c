/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
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

#include <axis2_msg_info_headers.h>
#include <axis2_options.h>
#include <axis2_svc_client.h>
#include <axis2_endpoint_ref.h>
#include <platforms/axutil_platform_auto_sense.h>
#include <axiom_soap.h>

#include <savan_util.h>
#include <savan_error.h>

/******************************************************************************/

static axis2_status_t
add_subscriber_to_remote_subs_mgr(
    const axutil_env_t *env,
    savan_subscriber_t *subscriber,
    axis2_char_t *subs_mgr_url);

static axis2_status_t
remove_subscriber_from_remote_subs_mgr(
    const axutil_env_t *env,
    savan_subscriber_t *subscriber,
    axis2_char_t *subs_mgr_url);

static axiom_node_t *
build_add_subscriber_om_payload(
    const axutil_env_t *env,
    savan_subscriber_t *subscriber);

static axiom_node_t *
build_remove_subscriber_om_payload(
    const axutil_env_t *env,
    savan_subscriber_t *subscriber);

static axiom_node_t *
build_subscribers_request_om_payload(
    const axutil_env_t *env,
    axis2_char_t *topic);

static axutil_hash_t *
process_subscriber_list_node(
    const axutil_env_t *env,
    axiom_node_t *subs_list_node);

savan_message_types_t AXIS2_CALL
savan_util_get_message_type(
    axis2_msg_ctx_t *msg_ctx,
    const axutil_env_t *env)
{
    const axis2_char_t *action = NULL;
    axis2_msg_info_headers_t *info_header = NULL;

    info_header =  axis2_msg_ctx_get_msg_info_headers(msg_ctx, env);
    if (!info_header)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Cannot extract message "
            "info headers"); 
        return SAVAN_MSG_TYPE_UNKNOWN;
    }
    
    action = axis2_msg_info_headers_get_action(info_header, env);
    if( ! action)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Cannot extract soap "
            "action"); 
        AXIS2_ERROR_SET(env->error, SAVAN_ERROR_SOAP_ACTION_NULL, AXIS2_FAILURE);
        return SAVAN_MSG_TYPE_UNKNOWN;
    }
    
    if (axutil_strcmp(action, SAVAN_ACTIONS_SUB) == 0)
        return SAVAN_MSG_TYPE_SUB;
    else if (axutil_strcmp(action, SAVAN_ACTIONS_SUB_RESPONSE) == 0)
        return SAVAN_MSG_TYPE_SUB_RESPONSE;
    else if (axutil_strcmp(action, SAVAN_ACTIONS_UNSUB) == 0)
        return SAVAN_MSG_TYPE_UNSUB;
    else if (axutil_strcmp(action, SAVAN_ACTIONS_UNSUB_RESPONSE) == 0)
        return SAVAN_MSG_TYPE_UNSUB_RESPONSE;
    else if (axutil_strcmp(action, SAVAN_ACTIONS_GET_STATUS) == 0)
        return SAVAN_MSG_TYPE_GET_STATUS;
    else if (axutil_strcmp(action, SAVAN_ACTIONS_GET_STATUS_RESPONSE) == 0)
        return SAVAN_MSG_TYPE_GET_STATUS_RESPONSE;
    else if (axutil_strcmp(action, SAVAN_ACTIONS_RENEW) == 0)
        return SAVAN_MSG_TYPE_RENEW;
    else if (axutil_strcmp(action, SAVAN_ACTIONS_RENEW_RESPONSE) == 0)
        return SAVAN_MSG_TYPE_RENEW_RESPONSE;
    
    return SAVAN_MSG_TYPE_UNKNOWN;
}

/******************************************************************************/

axis2_char_t * AXIS2_CALL
savan_util_get_subscription_id_from_msg(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_char_t *sub_id = NULL;
    axiom_soap_envelope_t *envelope = NULL;
    axiom_soap_header_t *header = NULL;
    axutil_qname_t *qname = NULL;
    axiom_node_t *header_node = NULL;
    axiom_node_t *id_node = NULL;
    axiom_element_t *header_elem = NULL;
    axiom_element_t *id_elem = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][util] "
        "get sub id from msg...");
    
    /* Get soap envelop and extract the subscription id */

    envelope =  axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
    if (!envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to extract the "
            "soap envelop");
        return NULL;
    }
    
    header = axiom_soap_envelope_get_header(envelope, env);
    if (!header)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to extract the "
            "soap header"); 
        return NULL;
    }
    
    /* Get header element from header node */
    header_node = axiom_soap_header_get_base_node(header, env);
    header_elem = (axiom_element_t*)axiom_node_get_data_element(header_node, env);
    
    /* Get Identifier element from header */
    qname = axutil_qname_create(env, ELEM_NAME_ID, EVENTING_NAMESPACE, NULL);
    id_elem = axiom_element_get_first_child_with_qname(header_elem, env, qname,
        header_node, &id_node);
    axutil_qname_free(qname, env);
    
    /* Now read the id */
    sub_id = axiom_element_get_text(id_elem, env, id_node);
    
    return sub_id;    
}

/******************************************************************************/

savan_subscriber_t * AXIS2_CALL
savan_util_get_subscriber_from_msg(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        axis2_char_t *sub_id)
{
    axutil_hash_t *store = NULL;
    savan_subscriber_t *subscriber = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][util] "
        "get subscriber from msg...");

    /* Extract subscription id from msg if not already given */
    if (!sub_id)
        sub_id = savan_util_get_subscription_id_from_msg(env, msg_ctx);

    store = savan_util_get_subscriber_store(env, msg_ctx);
    if (!store)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Subscriber store is "
            "null"); 
        return NULL;
    }

    subscriber = axutil_hash_get(store, sub_id, AXIS2_HASH_KEY_STRING);
    
    return subscriber;
}

/******************************************************************************/

axutil_hash_t * AXIS2_CALL
savan_util_get_subscriber_store(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_svc_t *subs_svc = NULL;
    axutil_param_t *param = NULL;
    axutil_hash_t *store = NULL;
    axis2_char_t *subs_svc_name = NULL;
    axis2_char_t *topic = NULL;
    axis2_endpoint_ref_t *topic_epr = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][util] "
        "get subscriber store...");

    subs_svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if (!subs_svc)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to extract the "
            "service"); 
        return NULL;
    }
    param = axis2_svc_get_param(subs_svc, env, "SubscriptionMgrName");
    if(param)
    {
        subs_svc_name = axutil_param_get_value(param, env);
    }
    if(subs_svc_name)
    {
        axis2_char_t *subs_mgr_url = NULL;
        param = axis2_svc_get_param(subs_svc, env, "SubscriptionMgrURL");
        subs_mgr_url = axutil_param_get_value(param, env);
        topic_epr = axis2_msg_ctx_get_to(msg_ctx, env);
        topic = (axis2_char_t *) axis2_endpoint_ref_get_address(topic_epr, env);
        store = savan_util_get_subscriber_list_from_remote_subs_mgr(env, topic, subs_mgr_url);
    }
    else
    {
        param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
        if (!param)
        {
            /* Store not found. Create and set it as a param */
            savan_util_set_sub_store(subs_svc, env);
            param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
        }
    
        store = (axutil_hash_t*)axutil_param_get_value(param, env);
    }
    return store;
}

axis2_status_t AXIS2_CALL
savan_util_add_subscriber(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    savan_subscriber_t *subscriber)
{
    axis2_svc_t *subs_svc = NULL;
    axutil_param_t *param = NULL;
    axutil_hash_t *store = NULL;
    axis2_char_t *subs_svc_name = NULL;

    subs_svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if (!subs_svc)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to extract "
            "the service"); 
        return AXIS2_FAILURE;
    }
    param = axis2_svc_get_param(subs_svc, env, "SubscriptionMgrName");
    if(param)
    {
        subs_svc_name = axutil_param_get_value(param, env);
    }
    if(subs_svc_name)
    {
        axis2_char_t *subs_mgr_url = NULL;
        param = axis2_svc_get_param(subs_svc, env, "SubscriptionMgrURL");
        subs_mgr_url = axutil_param_get_value(param, env);
        add_subscriber_to_remote_subs_mgr(env, subscriber, subs_mgr_url);
    }
    else
    {
        param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
        if (!param)
        {
            /* Store not found. Create and set it as a param */
            savan_util_set_sub_store(subs_svc, env);
            param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
        }
    
        store = (axutil_hash_t*)axutil_param_get_value(param, env);
        /* Store the created subscriber in the svc */
        axutil_hash_set(store, savan_subscriber_get_id(subscriber, env), 
            AXIS2_HASH_KEY_STRING, subscriber);
    } 
    
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
savan_util_remove_subscriber(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    savan_subscriber_t *subscriber)
{
    axis2_svc_t *subs_svc = NULL;
    axutil_param_t *param = NULL;
    axutil_hash_t *store = NULL;
    axis2_char_t *subs_svc_name = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "remove subscriber...");

    subs_svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if (!subs_svc)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to extract "
            "the service"); 
        return AXIS2_FAILURE;
    }
    param = axis2_svc_get_param(subs_svc, env, "SubscriptionMgrName");
    if(param)
    {
        subs_svc_name = axutil_param_get_value(param, env);
    }
    if(subs_svc_name)
    {
        axis2_char_t *subs_mgr_url = NULL;
        param = axis2_svc_get_param(subs_svc, env, "SubscriptionMgrURL");
        subs_mgr_url = axutil_param_get_value(param, env);
        remove_subscriber_from_remote_subs_mgr(env, subscriber, subs_mgr_url);
    }
    else
    {
        axis2_char_t *id = NULL;

        id = savan_subscriber_get_id(subscriber, env);
        /* Extract the store from the svc and remove the given subscriber */
        store = savan_util_get_subscriber_store(env, msg_ctx);
        if (!store)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Subscriber store is "
                "null"); 
            return AXIS2_FAILURE;
        }

        /* Setting NULL as value will remove the entry */
        axutil_hash_set(store, id, AXIS2_HASH_KEY_STRING, NULL);
    }
        return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL 
savan_util_set_sub_store(
    axis2_svc_t *svc,
    const axutil_env_t *env)
{
    axutil_hash_t *store = NULL;
    axutil_param_t *param = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "Start:set_sub_store");
    
    /* Create a hash map */
    store = axutil_hash_make(env);
    if (!store)
    {
        /* TODO : error reporting */
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "Could not create subscriber store");
        return AXIS2_FAILURE;
    }
    
    /* Add the hash map as a parameter to the given service */
    param = axutil_param_create(env, SAVAN_SUBSCRIBER_LIST, (void*)store);
    if (!param)
    {
        /* TODO : error reporting */
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "Could not create subscriber store param");
        return AXIS2_FAILURE;
    }
    
    axis2_svc_add_param(svc, env, param);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "End:set_sub_store");
    
    return AXIS2_SUCCESS;       
}

static axis2_status_t
add_subscriber_to_remote_subs_mgr(
    const axutil_env_t *env,
    savan_subscriber_t *subscriber,
    axis2_char_t *subs_mgr_url)
{
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t *payload = NULL;

    /* Set end point reference of echo service */
    address = subs_mgr_url;

    /* Create EPR with given address */
    endpoint_ref = axis2_endpoint_ref_create(env, address);

    /* Setup options */
    options = axis2_options_create(env);
    axis2_options_set_xml_parser_reset(options, env, AXIS2_FALSE);
    axis2_options_set_to(options, env, endpoint_ref);
    axis2_options_set_action(options, env,
        "http://ws.apache.org/axis2/c/subscription/add_subscriber");

    /* Set up deploy folder. It is from the deploy folder, the configuration is 
     * picked up using the axis2.xml file.
     * In this sample client_home points to the Axis2/C default deploy folder. 
     * The client_home can be different from this folder on your system. For 
     * example, you may have a different folder (say, my_client_folder) with its 
     * own axis2.xml file. my_client_folder/modules will have the modules that 
     * the client uses
     */
    client_home = (const axis2_char_t *) AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../deploy";

    /* Create service client */
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf("Error creating service client\n");
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
            " %d :: %s", env->error->error_number,
            AXIS2_ERROR_GET_MESSAGE(env->error));
        return AXIS2_FAILURE;
    }
    axis2_options_set_soap_version(options, env, AXIOM_SOAP11);
    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);    
    
    axis2_svc_client_engage_module(svc_client, env, AXIS2_MODULE_ADDRESSING);
    payload = build_add_subscriber_om_payload(env, subscriber);
    /* Send request */
    axis2_svc_client_send_robust(svc_client, env, payload);
    if(svc_client)
        axis2_svc_client_free(svc_client, env);

    return AXIS2_SUCCESS;
}

static axis2_status_t
remove_subscriber_from_remote_subs_mgr(
    const axutil_env_t *env,
    savan_subscriber_t *subscriber,
    axis2_char_t *subs_mgr_url)
{
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t *payload = NULL;

    /* Set end point reference of echo service */
    address = subs_mgr_url;

    /* Create EPR with given address */
    endpoint_ref = axis2_endpoint_ref_create(env, address);

    /* Setup options */
    options = axis2_options_create(env);
    axis2_options_set_xml_parser_reset(options, env, AXIS2_FALSE);
    axis2_options_set_to(options, env, endpoint_ref);
    axis2_options_set_action(options, env,
        "http://ws.apache.org/axis2/c/subscription/remove_subscriber");

    /* Set up deploy folder. It is from the deploy folder, the configuration is 
     * picked up using the axis2.xml file.
     * In this sample client_home points to the Axis2/C default deploy folder. 
     * The client_home can be different from this folder on your system. For 
     * example, you may have a different folder (say, my_client_folder) with its 
     * own axis2.xml file. my_client_folder/modules will have the modules that 
     * the client uses
     */
    client_home = (const axis2_char_t *) AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../deploy";

    /* Create service client */
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf("Error creating service client\n");
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
            " %d :: %s", env->error->error_number,
            AXIS2_ERROR_GET_MESSAGE(env->error));
        return AXIS2_FAILURE;
    }
    axis2_options_set_soap_version(options, env, AXIOM_SOAP11);
    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);    
    
    axis2_svc_client_engage_module(svc_client, env, AXIS2_MODULE_ADDRESSING);
    payload = build_remove_subscriber_om_payload(env, subscriber);
    /* Send request */
    axis2_svc_client_send_robust(svc_client, env, payload);
    if(svc_client)
        axis2_svc_client_free(svc_client, env);

    return AXIS2_SUCCESS;
}

axutil_hash_t *AXIS2_CALL
savan_util_get_subscriber_list_from_remote_subs_mgr(
    const axutil_env_t *env,
    axis2_char_t *topic,
    axis2_char_t *subs_mgr_url)
{
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t *payload = NULL;
    axiom_node_t *ret_node = NULL;
    axutil_hash_t *subscriber_list = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[savan] Start:savan_util_get_subscriber_list_from_remote_subs_mgr");
    options = axis2_options_create(env);
    axis2_options_set_xml_parser_reset(options, env, AXIS2_FALSE);
    axis2_options_set_action(options, env,
        "http://ws.apache.org/axis2/c/subscription/get_subscriber_list");

    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../deploy";

    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[savan] Stub invoke FAILED: Error code:"
            " %d :: %s", env->error->error_number,
            AXIS2_ERROR_GET_MESSAGE(env->error));
        return NULL;
    }
    endpoint_ref = axis2_endpoint_ref_create(env, subs_mgr_url);
    axis2_options_set_to(options, env, endpoint_ref);
    axis2_options_set_soap_version(options, env, AXIOM_SOAP11);
    axis2_svc_client_set_options(svc_client, env, options);    
    
    axis2_svc_client_engage_module(svc_client, env, AXIS2_MODULE_ADDRESSING);
    payload = build_subscribers_request_om_payload(env, topic);
    ret_node = axis2_svc_client_send_receive(svc_client, env, payload);
    if (ret_node)
    {
        subscriber_list = process_subscriber_list_node(env, ret_node);
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "[savan] Stub invoke FAILED: Error code:"
            " %d :: %s", env->error->error_number,
            AXIS2_ERROR_GET_MESSAGE(env->error));
    }
    if(svc_client)
        axis2_svc_client_free(svc_client, env);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[savan] End:savan_util_get_subscriber_list_from_remote_subs_mgr");
    return subscriber_list;
}

static axiom_node_t *
build_subscribers_request_om_payload(
    const axutil_env_t *env,
    axis2_char_t *topic)
{
    axiom_node_t *om_node = NULL;
    axiom_element_t* om_ele = NULL;
    axiom_node_t* topic_om_node = NULL;
    axiom_element_t * topic_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;
    axis2_char_t *om_str = NULL;

    ns1 = axiom_namespace_create (env, SAVAN_NAMESPACE, SAVAN_NS_PREFIX);
    om_ele = axiom_element_create(env, NULL, ELEM_NAME_SUBSCRIBERS, ns1, &om_node);
    topic_om_ele = axiom_element_create(env, om_node, ELEM_NAME_TOPIC, ns1, 
        &topic_om_node);
    axiom_element_set_text(topic_om_ele, env, topic, topic_om_node);

    om_str = axiom_node_to_string(om_node, env);
    if (om_str)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Sending OM : %s", om_str);
        AXIS2_FREE(env->allocator, om_str);
        om_str =  NULL;
    }
    return om_node;
}

static axutil_hash_t *
process_subscriber_list_node(
    const axutil_env_t *env,
    axiom_node_t *subs_list_node)
{
    axiom_element_t *subs_list_element = NULL;
    axiom_children_qname_iterator_t *subs_iter = NULL;
    axutil_hash_t *subscriber_list = axutil_hash_make(env);
    axutil_qname_t *qname = NULL;
    axiom_node_t *topic_node = NULL;
    axiom_element_t *topic_elem = NULL;
    axis2_char_t *topic_url = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[savan] Start:process_subscriber_list_node");
    subs_list_element = axiom_node_get_data_element(subs_list_node, env); 
         
    /* Topic */
    qname = axutil_qname_create(env, ELEM_NAME_TOPIC, SAVAN_NAMESPACE, NULL);
    topic_elem = axiom_element_get_first_child_with_qname(subs_list_element, 
        env, qname, subs_list_node, &topic_node);
    axutil_qname_free(qname, env);
    topic_url = axiom_element_get_text(topic_elem, env, topic_node);
   
    /* Get Subscriber elements from subscriber list */
    qname = axutil_qname_create(env, ELEM_NAME_SUBSCRIBE, EVENTING_NAMESPACE, 
        NULL);
    subs_iter = axiom_element_get_children_with_qname(subs_list_element, env,
        qname, subs_list_node);
    axutil_qname_free(qname, env);
    if(!subs_iter)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[savan] Subscribers list is empty");
        return NULL;
    }
    while(axiom_children_qname_iterator_has_next(subs_iter, env))
    {
        savan_subscriber_t *subscriber = NULL;
        axiom_node_t *sub_node = NULL;
        axiom_node_t *id_node = NULL;
        axiom_node_t *endto_node = NULL;
        axiom_node_t *delivery_node = NULL;
        axiom_node_t *notify_node = NULL;
        axiom_node_t *filter_node = NULL;
        axiom_node_t *expires_node = NULL;

        axiom_element_t *sub_elem = NULL;
        axiom_element_t *id_elem = NULL;
        axiom_element_t *endto_elem = NULL;
        axiom_element_t *delivery_elem = NULL;
        axiom_element_t *notify_elem = NULL;
        axiom_element_t *expires_elem = NULL;
        axiom_element_t *filter_elem = NULL;

        axis2_char_t *id = NULL;
        axis2_char_t *endto = NULL;
        axis2_char_t *notify = NULL;
        axis2_char_t *expires = NULL;
        axis2_char_t *filter = NULL;

        axis2_endpoint_ref_t *endto_epr = NULL;
        axis2_endpoint_ref_t *notify_epr = NULL;
     
        sub_node = axiom_children_qname_iterator_next(subs_iter, env);
        if(sub_node)
        {
            subscriber = savan_subscriber_create(env);
            if (!subscriber)
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to create a"
                    "subscriber instance");
                return NULL;
            }
            /* Now read each sub element of Subscribe element */

            /* Topic */
            savan_subscriber_set_topic(subscriber, env, topic_url);

            /* Id */
            qname = axutil_qname_create(env, ELEM_NAME_ID, SAVAN_NAMESPACE, NULL);
            id_elem = axiom_element_get_first_child_with_qname(sub_elem, env, qname,
                sub_node, &id_node);
            axutil_qname_free(qname, env);
            id = axiom_element_get_text(id_elem, env, id_node);
            savan_subscriber_set_id(subscriber, env, id);

            /* EndTo */
            qname = axutil_qname_create(env, ELEM_NAME_ENDTO, EVENTING_NAMESPACE, NULL);
            endto_elem = axiom_element_get_first_child_with_qname(sub_elem, env, qname,
                sub_node, &endto_node);
            axutil_qname_free(qname, env);

            endto = axiom_element_get_text(endto_elem, env, endto_node);

            endto_epr = axis2_endpoint_ref_create(env, endto);

            savan_subscriber_set_end_to(subscriber, env, endto_epr);

            /* Get Delivery element and read NotifyTo */
            qname = axutil_qname_create(env, ELEM_NAME_DELIVERY, EVENTING_NAMESPACE, NULL);
            delivery_elem = axiom_element_get_first_child_with_qname(sub_elem, env, qname,
                sub_node, &delivery_node);
            axutil_qname_free(qname, env);

            qname = axutil_qname_create(env, ELEM_NAME_NOTIFYTO, EVENTING_NAMESPACE, NULL);
            notify_elem = axiom_element_get_first_child_with_qname(delivery_elem, env, qname,
                delivery_node, &notify_node);
            axutil_qname_free(qname, env);
            notify = axiom_element_get_text(notify_elem, env, notify_node);

            notify_epr = axis2_endpoint_ref_create(env, notify);

            savan_subscriber_set_notify_to(subscriber, env, notify_epr);

            /* Expires */
            qname = axutil_qname_create(env, ELEM_NAME_EXPIRES, EVENTING_NAMESPACE, NULL);
            expires_elem = axiom_element_get_first_child_with_qname(sub_elem, env, qname,
                sub_node, &expires_node);
            axutil_qname_free(qname, env);

            expires = axiom_element_get_text(expires_elem, env, expires_node);

            savan_subscriber_set_expires(subscriber, env, expires);

            /* Filter */
            qname = axutil_qname_create(env, ELEM_NAME_FILTER, EVENTING_NAMESPACE, NULL);
            filter_elem = axiom_element_get_first_child_with_qname(sub_elem, env, qname,
                sub_node, &filter_node);
            axutil_qname_free(qname, env);

            filter = axiom_element_get_text(filter_elem, env, filter_node);

            savan_subscriber_set_filter(subscriber, env, filter);
            axutil_hash_set(subscriber_list, savan_subscriber_get_id(subscriber, 
                env), AXIS2_HASH_KEY_STRING, subscriber);
        }
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[savan] End:process_subscriber_list_node");
    return subscriber_list;
}

static axiom_node_t *
build_add_subscriber_om_payload(
    const axutil_env_t *env,
    savan_subscriber_t *subscriber)
{
    axiom_node_t *add_node = NULL;
    axiom_element_t* add_ele = NULL;
    axiom_namespace_t *ns = NULL;
    axiom_namespace_t *ns1 = NULL;
    axiom_node_t *sub_node = NULL;
    axiom_node_t *id_node = NULL;
    axiom_node_t *topic_node = NULL;
    axiom_node_t *endto_node = NULL;
    axiom_node_t *delivery_node = NULL;
    axiom_node_t *notify_node = NULL;
    axiom_node_t *filter_node = NULL;
    axiom_node_t *expires_node = NULL;
    axiom_element_t* sub_elem = NULL;
    axiom_element_t* id_elem = NULL;
    axiom_element_t* topic_elem = NULL;
    axiom_element_t* endto_elem = NULL;
    axiom_element_t* delivery_elem = NULL;
    axiom_element_t* notify_elem = NULL;
    axiom_element_t* filter_elem = NULL;
    axiom_element_t* expires_elem = NULL;
    const axis2_char_t *endto = NULL;
    const axis2_char_t *notify = NULL;
    axis2_char_t *filter = NULL;
    const axis2_char_t *expires = NULL;
    axis2_char_t *topic = NULL;
    axis2_char_t *id = NULL;
	axis2_endpoint_ref_t *notify_ref = NULL;
    axis2_endpoint_ref_t *endto_ref = savan_subscriber_get_end_to(subscriber, env);
    endto = axis2_endpoint_ref_get_address(endto_ref, env);
    notify_ref = savan_subscriber_get_notify_to(subscriber, env);
    notify = axis2_endpoint_ref_get_address(notify_ref, env);
    filter = savan_subscriber_get_filter(subscriber, env); 
    expires = savan_subscriber_get_expires(subscriber, env); 
    id = savan_subscriber_get_id(subscriber, env);

    ns = axiom_namespace_create (env, EVENTING_NAMESPACE, EVENTING_NS_PREFIX);
    ns1 = axiom_namespace_create (env, SAVAN_NAMESPACE, SAVAN_NS_PREFIX);
    add_ele = axiom_element_create(env, NULL, ELEM_NAME_ADD_SUBSCRIBER, ns1, &add_node);
    
    /* create the id element */
    if(id)
    {
        id_elem = axiom_element_create(env, add_node, ELEM_NAME_ID, ns1, &id_node);
            axiom_element_set_text(id_elem, env, id, id_node);
    }
    /* create the topic element */
    topic_elem = axiom_element_create(env, add_node, ELEM_NAME_TOPIC, ns1, &topic_node);
    topic = savan_subscriber_get_topic(subscriber, env);
    if(topic)
        axiom_element_set_text(topic_elem, env, topic, topic_node);
    /* create the subscriber element */
    sub_elem = axiom_element_create(env, add_node, ELEM_NAME_SUBSCRIBE, ns, &sub_node);
    
    /* EndTo element */
    endto_elem = axiom_element_create(env, sub_node, ELEM_NAME_ENDTO, ns,
        &endto_node);
    axiom_element_set_text(endto_elem, env, endto, endto_node);
    
    /* Delivery element */
    delivery_elem = axiom_element_create(env, sub_node, ELEM_NAME_DELIVERY, ns,
        &delivery_node);
        
    notify_elem = axiom_element_create(env, delivery_node, ELEM_NAME_NOTIFYTO, ns,
        &notify_node);
    axiom_element_set_text(notify_elem, env, notify, notify_node);
    
    /* Expires element */
    expires_elem = axiom_element_create(env, sub_node, ELEM_NAME_EXPIRES, ns,
        &expires_node);
    axiom_element_set_text(expires_elem, env, expires, expires_node);
    /* Filter element */
    filter_elem = axiom_element_create(env, sub_node, ELEM_NAME_FILTER, ns,
        &endto_node);
    axiom_element_set_text(filter_elem, env, filter, filter_node);
    
    return add_node;
}

static axiom_node_t *
build_remove_subscriber_om_payload(
    const axutil_env_t *env,
    savan_subscriber_t *subscriber)
{
    axiom_node_t *remove_node = NULL;
    axiom_element_t* remove_ele = NULL;
    axiom_namespace_t *ns = NULL;
    axiom_namespace_t *ns1 = NULL;
    axiom_node_t *id_node = NULL;
    axiom_node_t *topic_node = NULL;
    axiom_element_t* id_elem = NULL;
    axiom_element_t* topic_elem = NULL;
    axis2_char_t *topic = NULL;
    axis2_char_t *id = NULL;

    id = savan_subscriber_get_id(subscriber, env);

    ns = axiom_namespace_create (env, EVENTING_NAMESPACE, EVENTING_NS_PREFIX);
    ns1 = axiom_namespace_create (env, SAVAN_NAMESPACE, SAVAN_NS_PREFIX);
    remove_ele = axiom_element_create(env, NULL, ELEM_NAME_REMOVE_SUBSCRIBER, 
        ns1, &remove_node);
    
    /* create the id element */
    if(id)
    {
        id_elem = axiom_element_create(env, remove_node, ELEM_NAME_ID, ns1, &id_node);
            axiom_element_set_text(id_elem, env, id, id_node);
    }
    /* create the topic element */
    topic_elem = axiom_element_create(env, remove_node, ELEM_NAME_TOPIC, ns1, &topic_node);
    topic = savan_subscriber_get_topic(subscriber, env);
    if(topic)
        axiom_element_set_text(topic_elem, env, topic, topic_node);
    
    return remove_node;
}

/******************************************************************************/

axis2_char_t * AXIS2_CALL
savan_util_get_expiry_time(
    const axutil_env_t *env)
{
    /* TODO: decide how to set expiry time */
    
    return NULL;
}

/******************************************************************************/

axis2_char_t * AXIS2_CALL
savan_util_get_renewed_expiry_time(
    const axutil_env_t *env,
    axis2_char_t *expiry)
{
    /* TODO: decide how to renew expiry time */
    
    return NULL;
}
