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
 
#include <axutil_hash.h>
#include <axis2_svc.h>
#include <axiom_element.h>
#include <axiom_node.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_body.h>
#include <axutil_uuid_gen.h>

#include <savan_sub_processor.h>
#include <savan_constants.h>
#include <savan_error.h>
#include <savan_subscriber.h>
#include <savan_util.h>

struct savan_sub_processor_t
{
    int dummy;
};

/* Function Prototypes ********************************************************/
     
savan_subscriber_t * AXIS2_CALL 
savan_sub_processor_create_subscriber_from_msg(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

axis2_status_t AXIS2_CALL
savan_sub_processor_set_sub_id_to_msg_ctx(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_char_t *id);

axis2_bool_t AXIS2_CALL
savan_sub_processor_is_subscription_renewable(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

/* End of Function Prototypes *************************************************/

/******************************************************************************/

AXIS2_EXTERN savan_sub_processor_t *AXIS2_CALL
savan_sub_processor_create(
    const axutil_env_t *env)
{
    savan_sub_processor_t *sub_processor = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    sub_processor = AXIS2_MALLOC( env->allocator, sizeof(savan_sub_processor_t));
     
    if (!sub_processor)
    { 
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;        
    }
    
    return sub_processor;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL 
savan_sub_processor_subscribe(
    savan_sub_processor_t *sub_processor,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    savan_subscriber_t *subscriber = NULL;
    axis2_char_t *expires = NULL;
    axis2_char_t *id = NULL;
    
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "subscribe...");
    
    /* Extract info from incoming msg and create a subscriber */
    subscriber = savan_sub_processor_create_subscriber_from_msg(env, msg_ctx);
    if (!subscriber)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to create a"
            "subscriber"); 
        AXIS2_ERROR_SET(env->error, SAVAN_ERROR_FAILED_TO_CREATE_SUBSCRIBER,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }    
    /* Set the expiry time on the subscription */
    /* TODO : For now we are ignoring the Expiry sent by the client. Add support
     * to consider this when setting the expiry time */
    expires = savan_util_get_expiry_time(env);
    savan_subscriber_set_expires(subscriber, env, expires);

    /* Store sub id in msg ctx to be used by the msg receiver */
    id = savan_subscriber_get_id(subscriber, env);
    savan_sub_processor_set_sub_id_to_msg_ctx(env, msg_ctx, id);
    savan_util_add_subscriber(env, msg_ctx, subscriber);
    
    return AXIS2_SUCCESS;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL 
savan_sub_processor_unsubscribe(
    savan_sub_processor_t *sub_processor,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    savan_subscriber_t *subscriber = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_char_t *id = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "unsubscribe...");

    subscriber = savan_util_get_subscriber_from_msg(env, msg_ctx, NULL);
    if (!subscriber)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to find the"
            "subscriber"); 
        return AXIS2_FAILURE;
    }

    /* Store sub id in msg ctx to be used by the msg receiver */
    id = savan_subscriber_get_id(subscriber, env);
    savan_sub_processor_set_sub_id_to_msg_ctx(env, msg_ctx, id);

    /* Remove from store */
    status = savan_util_remove_subscriber(env, msg_ctx, subscriber);
    if (status != AXIS2_SUCCESS)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to remove the"
            "subscriber"); 
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL 
savan_sub_processor_renew_subscription(
    savan_sub_processor_t *sub_processor,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    savan_subscriber_t *subscriber = NULL;
    axis2_char_t *id = NULL;
    axis2_bool_t renewable = AXIS2_TRUE;
    axis2_char_t *expires = NULL;
    axis2_char_t *renewed_expires = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "renew subscription...");

    subscriber = savan_util_get_subscriber_from_msg(env, msg_ctx, NULL);
    if (!subscriber)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to find the"
            "subscriber"); 
        return AXIS2_FAILURE;
    }

    /* Store sub id in msg ctx to be used by the msg receiver */
    id = savan_subscriber_get_id(subscriber, env);
    savan_sub_processor_set_sub_id_to_msg_ctx(env, msg_ctx, id);

    /* Check whether the subscription can be renewed. If renewable, set the new
     * expiry time in the subscriber */

    renewable = savan_sub_processor_is_subscription_renewable(env, msg_ctx);
    if (!renewable)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Subscription can not "
            "be renewed");
        savan_subscriber_set_renew_status(subscriber, env, AXIS2_FALSE);
        return AXIS2_FAILURE;
    }

    expires = savan_subscriber_get_expires(subscriber, env);
    renewed_expires = savan_util_get_renewed_expiry_time(env, expires);
    savan_subscriber_set_expires(subscriber, env, renewed_expires);
    savan_subscriber_set_renew_status(subscriber, env, AXIS2_TRUE);

    return AXIS2_SUCCESS;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL 
savan_sub_processor_get_status(
    savan_sub_processor_t *sub_processor,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_char_t *id = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "get status...");

    /* Extract the sub id and store it in msg ctx to be used by the msg
     * receiver */
    id = savan_util_get_subscription_id_from_msg(env, msg_ctx);
    savan_sub_processor_set_sub_id_to_msg_ctx(env, msg_ctx, id);

    return AXIS2_SUCCESS;
}

/******************************************************************************/

/******************************************************************************/

savan_subscriber_t * AXIS2_CALL 
savan_sub_processor_create_subscriber_from_msg(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    savan_subscriber_t *subscriber = NULL;
    axis2_char_t *sub_id = NULL;
    axiom_soap_envelope_t *envelope = NULL;
    axiom_soap_body_t *body = NULL;
    axutil_qname_t *qname = NULL;
    
    axiom_node_t *body_node = NULL;
    axiom_node_t *sub_node = NULL;
    axiom_node_t *endto_node = NULL;
    axiom_node_t *delivery_node = NULL;
    axiom_node_t *notify_node = NULL;
    axiom_node_t *filter_node = NULL;
    axiom_node_t *expires_node = NULL;
    
    axiom_element_t *body_elem = NULL;
    axiom_element_t *sub_elem = NULL;
    axiom_element_t *endto_elem = NULL;
    axiom_element_t *delivery_elem = NULL;
    axiom_element_t *notify_elem = NULL;
    axiom_element_t *expires_elem = NULL;
    axiom_element_t *filter_elem = NULL;
    
    axis2_char_t *endto = NULL;
    axis2_char_t *notify = NULL;
    axis2_char_t *expires = NULL;
    axis2_char_t *filter = NULL;
    axis2_char_t *topic = NULL;
    
    axis2_endpoint_ref_t *endto_epr = NULL;
    axis2_endpoint_ref_t *notify_epr = NULL;
    axis2_endpoint_ref_t *topic_epr = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][sub processor] "
        "get sub from msg...");
    
    subscriber = savan_subscriber_create(env);
    if (!subscriber)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to create a"
            "subscriber instance"); 
        return NULL;
    }
    
    /* Assign a unique id to subscriber */
    sub_id = axutil_uuid_gen(env);
    if (sub_id)
    {
        savan_subscriber_set_id(subscriber, env, sub_id);
        /* Don't free the sub_id here. we use it inside msg recv */
    }
    
    /* Get soap envelop and extract relevant elements */
   
    envelope =  axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
    if (!envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to extract the "
            "soap envelop"); 
        return NULL;
    }
    
    body = axiom_soap_envelope_get_body(envelope, env);
    if (!body)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to extract the "
            "soap body"); 
        return NULL;
    }
    
    /* Get Body element from body node */
    body_node = axiom_soap_body_get_base_node(body, env);
    body_elem = (axiom_element_t*)axiom_node_get_data_element(body_node, env);
    
    /* Get Subscribe element from Body */
    qname = axutil_qname_create(env, ELEM_NAME_SUBSCRIBE, EVENTING_NAMESPACE, NULL);
    sub_elem = axiom_element_get_first_child_with_qname(body_elem, env, qname,
        body_node, &sub_node);
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
    
    topic_epr = axis2_msg_ctx_get_to(msg_ctx, env);
    topic = (axis2_char_t *)axis2_endpoint_ref_get_address(topic_epr, env);
    savan_subscriber_set_topic(subscriber, env, topic);
    return subscriber;    
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_sub_processor_set_sub_id_to_msg_ctx(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_char_t *id)
{
    axutil_property_t *property = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /* Set the subscription id as a property in the msg_ctx. We use this inside
     * savan_msg_recv to send the wse:Identifier
     * Pass a copy because msg ctx free function frees all properties */
    property = axutil_property_create(env);
    axutil_property_set_value(property, env, (void*)axutil_strdup(env, id));
     axis2_msg_ctx_set_property(msg_ctx, env, SAVAN_KEY_SUB_ID, property);

    return AXIS2_SUCCESS;
}

/******************************************************************************/

/******************************************************************************/

axis2_bool_t AXIS2_CALL
savan_sub_processor_is_subscription_renewable(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    /* TODO: */

    return AXIS2_TRUE;
}
