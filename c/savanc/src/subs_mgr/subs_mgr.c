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

#include <axiom_xml_writer.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_body.h>
#include <axis2_svc.h>
#include <stdio.h>
#include <savan_subscriber.h>
#include <savan_util.h>
#include <savan_constants.h>

#include "savan_subs_mgr.h"

static axis2_char_t *
get_topic_from_url(
    const axutil_env_t *env,
    axis2_char_t *topic_url);

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
savan_subs_mgr_add_subscriber(
    const axutil_env_t *env,
    axiom_node_t *add_sub_node,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_svc_t *subs_svc = NULL;
    axis2_endpoint_ref_t *endto_epr = NULL;
    axis2_endpoint_ref_t *notify_epr = NULL;
    axutil_param_t *param = NULL;
    axutil_hash_t *store = NULL;
    axis2_char_t *topic_url = NULL;
    axis2_char_t *topic = NULL;
    savan_subs_mgr_info_t *sub_info = NULL;

    savan_subscriber_t *subscriber = NULL;
    axutil_qname_t *qname = NULL;
    
    axiom_node_t *sub_node = NULL;
    axiom_node_t *id_node = NULL;
    axiom_node_t *topic_node = NULL;
    axiom_node_t *endto_node = NULL;
    axiom_node_t *delivery_node = NULL;
    axiom_node_t *notify_node = NULL;
    axiom_node_t *filter_node = NULL;
    axiom_node_t *expires_node = NULL;
    
    axiom_element_t *sub_elem = NULL;
    axiom_element_t *id_elem = NULL;
    axiom_element_t *topic_elem = NULL;
    axiom_element_t *add_sub_elem = NULL;
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

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[ML] Start:savan_subs_mgr_add_subscriber");
    subs_svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
    if (!param)
    {
        /* Store not found. Create and set it as a param */
        savan_util_set_sub_store(subs_svc, env);
        param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
    }
    
    store = (axutil_hash_t*)axutil_param_get_value(param, env);
    if(!store)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[ML] Failed to extract the "
            "subscriber store"); 
        return NULL;
    }
    add_sub_elem = (axiom_element_t*)axiom_node_get_data_element(add_sub_node, env);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[ML] node:%s", axiom_node_to_string(add_sub_node, env));
    /*Get topic element from node */
    qname = axutil_qname_create(env, ELEM_NAME_TOPIC, SAVAN_NAMESPACE, NULL);
    topic_elem = axiom_element_get_first_child_with_qname(add_sub_elem, env, qname,
        add_sub_node, &topic_node);
    axutil_qname_free(qname, env);
    topic_url = axiom_element_get_text(topic_elem, env, topic_node);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[ML] Subscriber will be added to the topic:%s ", topic_url);
    topic = get_topic_from_url(env, topic_url);
    sub_info = axutil_hash_get(store, topic, AXIS2_HASH_KEY_STRING);
    if(!sub_info)
    {
        sub_info = AXIS2_MALLOC(env->allocator, 
            sizeof(struct savan_subs_mgr_info));
        sub_info->list = axutil_hash_make(env);
        axutil_hash_set(store, topic, AXIS2_HASH_KEY_STRING, sub_info);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[ML] Topic:%s is added to the store", topic);
    }
    subscriber = savan_subscriber_create(env);
    if (!subscriber)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[ML] Failed to create a"
            "subscriber instance"); 
        return NULL;
    }
    /* Set topic element */
    savan_subscriber_set_topic(subscriber, env, topic_url);

    /* Get Id element from AddSubscriber*/
    qname = axutil_qname_create(env, ELEM_NAME_ID, SAVAN_NAMESPACE, NULL);
    id_elem = axiom_element_get_first_child_with_qname(add_sub_elem, env, qname,
        add_sub_node, &id_node);
    axutil_qname_free(qname, env);
   
    id = axiom_element_get_text(id_elem, env, id_node);
    savan_subscriber_set_id(subscriber, env, id);
    id = savan_subscriber_get_id(subscriber, env);
    /* Get subscriber element from Body */
    qname = axutil_qname_create(env, ELEM_NAME_SUBSCRIBE, EVENTING_NAMESPACE, NULL);
    sub_elem = axiom_element_get_first_child_with_qname(add_sub_elem, env, qname,
        add_sub_node, &sub_node);
    axutil_qname_free(qname, env);
    
    /* Now read each sub element of Subscribe element */
        
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
    if(sub_info->list)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[ML] Subscriber %s added to the topic:%s", id, topic_url);
        axutil_hash_set(sub_info->list, id, AXIS2_HASH_KEY_STRING, subscriber);
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[ML] End:savan_subs_mgr_add_subscriber");
    return NULL;   
}

AXIS2_EXTERN void * AXIS2_CALL
savan_subs_mgr_remove_subscriber(
    const axutil_env_t *env,
    axiom_node_t *remove_sub_node,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_svc_t *subs_svc = NULL;
    axutil_param_t *param = NULL;
    axutil_hash_t *store = NULL;
    axis2_char_t *topic = NULL;
    axis2_char_t *topic_url = NULL;
    savan_subs_mgr_info_t *sub_info = NULL;

    axutil_qname_t *qname = NULL;
    
    axiom_node_t *id_node = NULL;
    axiom_node_t *topic_node = NULL;
    
    axiom_element_t *id_elem = NULL;
    axiom_element_t *topic_elem = NULL;
    axiom_element_t *remove_sub_elem = NULL;
    
    axis2_char_t *id = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[ML] Start:savan_subs_mgr_remove_subscriber");
    subs_svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
    if (!param)
    {
        /* Store not found. Create and set it as a param */
        savan_util_set_sub_store(subs_svc, env);
        param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
    }
    
    store = (axutil_hash_t*)axutil_param_get_value(param, env);
    if(!store)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[ML] Failed to extract the "
            "subscriber store"); 
        return NULL;
    }
    remove_sub_elem = (axiom_element_t*)axiom_node_get_data_element(remove_sub_node, env);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[ML] node:%s", axiom_node_to_string(remove_sub_node, env));
    /*Get topic element from node */
    qname = axutil_qname_create(env, ELEM_NAME_TOPIC, SAVAN_NAMESPACE, NULL);
    topic_elem = axiom_element_get_first_child_with_qname(remove_sub_elem, env, qname,
        remove_sub_node, &topic_node);
    axutil_qname_free(qname, env);
    topic_url = axiom_element_get_text(topic_elem, env, topic_node);
    topic = get_topic_from_url(env, topic_url);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[ML] Subscriber will be removed from the topic:%s ", topic);
    sub_info = axutil_hash_get(store, topic, AXIS2_HASH_KEY_STRING);
    if(!sub_info)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[ML] There are no subscribers for the ", topic_url);
        return NULL;
    }

    /* Get Id element from RemoveSubscriber*/
    qname = axutil_qname_create(env, ELEM_NAME_ID, SAVAN_NAMESPACE, NULL);
    id_elem = axiom_element_get_first_child_with_qname(remove_sub_elem, env, qname,
        remove_sub_node, &id_node);
    axutil_qname_free(qname, env);
    
    id = axiom_element_get_text(id_elem, env, id_node);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[ML] Removing subscriber with id %s from topic %s", id, topic_url);
    
    if(sub_info->list)
    {
        savan_subscriber_t *subscriber = NULL;
        axutil_hash_set(sub_info->list, id, AXIS2_HASH_KEY_STRING, NULL);
        subscriber = axutil_hash_get(sub_info->list, id, AXIS2_HASH_KEY_STRING);
        if(subscriber)
            savan_subscriber_free(subscriber, env);
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "[ML] Subscriber %s removed from the topic:%s", id, topic_url);
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "[ML] End:savan_subs_mgr_remove_subscriber");
    return NULL;   
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
savan_subs_mgr_get_subscriber_list(
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx)
{

    axis2_svc_t *subs_svc = NULL;
    axutil_param_t *param = NULL;
    axis2_char_t *topic_url = NULL;
    axis2_char_t *topic = NULL;
    savan_subs_mgr_info_t *sub_info = NULL;
    axutil_hash_t *sub_list = NULL;
    axutil_hash_t *store = NULL;
    axutil_hash_index_t *hi = NULL;
    axis2_char_t *sub_url = NULL;
    axiom_namespace_t *ns = NULL;
    axiom_namespace_t *ns1 = NULL;
    axiom_node_t *subs_list_node = NULL;
    axiom_node_t *topic_parent_node = NULL;
    axiom_node_t *topic_node = NULL;
    axiom_element_t* subs_list_elem = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "Start:savan_subs_mgr_get_subscriber_list");
    subs_svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
    if (!param)
    {
        /* Store not found. Create and set it as a param */
        savan_util_set_sub_store(subs_svc, env);
        param = axis2_svc_get_param(subs_svc, env, SAVAN_SUBSCRIBER_LIST);
    }
    
    store = (axutil_hash_t*)axutil_param_get_value(param, env);
    if(!store)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[ML] Failed to extract the "
            "subscriber store"); 
        return NULL;
    }

    /* Expected request format is :-
     * <ns1:Subscribers xmlns:ns1="http://ws.apache.org/savan">
     *      <Topic>topic_url</Topic>
     *      <ns:Susbscriber xmlns:ns="http://schemas.xmlsoap.org/ws/2004/08/eventing">
     *      ...
     *      </ns:Subscriber>
     *      <ns:Susbscriber xmlns:ns="http://schemas.xmlsoap.org/ws/2004/08/eventing">
     *      ...
     *      </ns:Subscriber>
     * </ns1:Subscribers>
     */
    if (!node) /* 'Subscribers' node */
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INPUT_OM_NODE_NULL, 
            AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "Echo client ERROR: input parameter NULL");
        return NULL;
    }

    topic_parent_node = axiom_node_get_first_element(node, env);
    if (!topic_parent_node) 
    {
        AXIS2_ERROR_SET(env->error, 
            AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
            "Echo client ERROR 1: invalid XML in request");
        return NULL;
    }

    topic_node = axiom_node_get_first_child(topic_parent_node, env);
    if (!topic_node) /* actual topic text */
    {
        AXIS2_ERROR_SET(env->error, 
            AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "invalid XML in request");
        return NULL;
    }

    if (axiom_node_get_node_type(topic_node, env) == AXIOM_TEXT)
    {
        axiom_text_t *topic_text = (axiom_text_t *)axiom_node_get_data_element(
            topic_node, env);
        if (topic_text && axiom_text_get_value(topic_text , env))
        {
            topic_url = (axis2_char_t *)axiom_text_get_value(topic_text, env);
            topic = get_topic_from_url(env, topic_url);
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Requested Topic:%s", topic);
        }
    }
    else
    {
        AXIS2_ERROR_SET(env->error, 
            AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Invalid XML in request");
        return NULL;
    }

    /* Retrive subscribers for the topic */
    sub_info = axutil_hash_get(store, topic, AXIS2_HASH_KEY_STRING);
    if(sub_info)
    {
        sub_url = sub_info->url;
        sub_list = sub_info->list;
    }
    /* create the body of the subscribers element */
    ns = axiom_namespace_create (env, EVENTING_NAMESPACE, EVENTING_NS_PREFIX);
    ns1 = axiom_namespace_create (env, SAVAN_NAMESPACE, SAVAN_NS_PREFIX);
    subs_list_elem = axiom_element_create(env, NULL, ELEM_NAME_SUBSCRIBERS, ns1, 
        &subs_list_node);
    if(!sub_list)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "No subscribers regirsterd for"
            " the topic:%s", topic_url);
        return subs_list_node;
    }
    for (hi = axutil_hash_first(sub_list, env); hi; hi =
        axutil_hash_next(env, hi))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
            "subscribers not empty for topic :%s", topic_url);
        void *val = NULL;
        savan_subscriber_t * subscriber = NULL;
        axutil_hash_this(hi, NULL, NULL, &val);
        subscriber = (savan_subscriber_t *)val;

        if (subscriber)
        {
            axiom_node_t *topic_node = NULL;
            axiom_node_t *sub_node = NULL;
            axiom_node_t *endto_node = NULL;
            axiom_node_t *id_node = NULL;
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
            const axis2_char_t *filter = NULL;
            const axis2_char_t *expires = NULL;
            axis2_char_t *id = NULL;
            axis2_char_t *topic = NULL;

            axis2_endpoint_ref_t *endto_ref = savan_subscriber_get_end_to(subscriber, env);
            endto = axis2_endpoint_ref_get_address(endto_ref, env);
            axis2_endpoint_ref_t *notify_ref = savan_subscriber_get_notify_to(subscriber, env);
            notify = axis2_endpoint_ref_get_address(notify_ref, env);
            filter = savan_subscriber_get_filter(subscriber, env); 
            expires = savan_subscriber_get_expires(subscriber, env);
            id = savan_subscriber_get_id(subscriber, env);
          
            /* create the topic element */
            topic_elem = axiom_element_create(env, subs_list_node, 
                ELEM_NAME_TOPIC, ns1, &topic_node);
            topic = savan_subscriber_get_topic(subscriber, env);
            if(topic)
                axiom_element_set_text(topic_elem, env, topic, topic_node); 
            /* create the subscriber element */

            sub_elem = axiom_element_create(env, subs_list_node, 
                ELEM_NAME_SUBSCRIBE, ns, &sub_node);
            
            /* Id element */
            id_elem = axiom_element_create(env, sub_node, ELEM_NAME_ID, ns1,
                &id_node);
            axiom_element_set_text(id_elem, env, id, id_node);

            /* EndTo element */
            endto_elem = axiom_element_create(env, sub_node, ELEM_NAME_ENDTO, ns,
                &endto_node);
            axiom_element_set_text(endto_elem, env, endto, endto_node);
            
            /* Delivery element */
            delivery_elem = axiom_element_create(env, sub_node, 
                ELEM_NAME_DELIVERY, ns, &delivery_node);
                
            notify_elem = axiom_element_create(env, delivery_node, 
                ELEM_NAME_NOTIFYTO, ns, &notify_node);
            axiom_element_set_text(notify_elem, env, notify, notify_node);
            
            /* Expires element */
            expires_elem = axiom_element_create(env, sub_node, 
                ELEM_NAME_EXPIRES, ns, &expires_node);
            axiom_element_set_text(expires_elem, env, expires, expires_node);
            /* Filter element */
            filter_elem = axiom_element_create(env, sub_node, ELEM_NAME_FILTER, 
                ns, &endto_node);
            axiom_element_set_text(filter_elem, env, filter, filter_node);
        }

        val = NULL;
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
        "End:savan_subs_mgr_get_subscriber_list");
    return subs_list_node;
}

static axis2_char_t *
get_topic_from_url(
    const axutil_env_t *env,
    axis2_char_t *topic_url)
{
    axis2_char_t *topic = NULL;
    topic  = axutil_strdup(env, axutil_rindex(topic_url, '/') + 1);
    return topic;
}

