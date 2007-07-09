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

#include <savan_msg_recv.h>
#include <string.h>
#include <axiom_element.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <axiom_soap_fault.h>
#include <axutil_property.h>
#include <axis2_addr.h>

#include <savan_util.h>
#include <savan_constants.h>
#include <savan_error.h>
#include <savan_subscriber.h>

/* Function Prototypes ********************************************************/


axis2_status_t AXIS2_CALL
savan_msg_recv_invoke_business_logic_sync(
    axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx);
    
axis2_status_t AXIS2_CALL
savan_msg_recv_handle_sub_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx);
    
axis2_status_t AXIS2_CALL
savan_msg_recv_handle_unsub_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx);
    
axis2_status_t AXIS2_CALL
savan_msg_recv_handle_renew_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx);

axis2_status_t AXIS2_CALL
savan_msg_recv_handle_get_status_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx);

axiom_soap_envelope_t * AXIS2_CALL
savan_msg_recv_build_soap_envelope(
    const axutil_env_t *env,
    axiom_node_t **body_node);

/* End of Function Prototypes *************************************************/

/******************************************************************************/

AXIS2_EXTERN axis2_msg_recv_t *AXIS2_CALL
savan_msg_recv_create(
    const axutil_env_t *env)
{
    axis2_msg_recv_t *msg_recv = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, NULL);
    
    msg_recv = axis2_msg_recv_create(env);
    if (!msg_recv)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to create "
            "axis2 message receiver"); 
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    status = axis2_msg_recv_set_scope(msg_recv, env, AXIS2_APPLICATION_SCOPE);
    if (status != AXIS2_TRUE)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to set "
            "message receiver scope"); 
        axis2_msg_recv_free(msg_recv, env);
        return NULL;
    }

	axis2_msg_recv_set_invoke_business_logic(msg_recv, env, 
		savan_msg_recv_invoke_business_logic_sync);
    return msg_recv;
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_msg_recv_invoke_business_logic_sync(
    axis2_msg_recv_t *msg_recv,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx)
{
    savan_message_types_t msg_type = SAVAN_MSG_TYPE_UNKNOWN;
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][msg recv] invoke called");

    /* this call will load and create the service object. */
    /*axis2_svc_skeleton_t* svc_obj = axis2_msg_recv_get_impl_obj(msg_recv, env,
        msg_ctx);
    if (!svc_obj)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][msg recv] service obj"
        " creation failed");         
    }*/
    
    /*AXIS2_SVC_SKELETON_SET_USER_DATA(svc_obj, env, (void*) axis2_msg_ctx_get_svc(msg_ctx, env));*/
        
    /* find the msg type and call the appropriate response function */
    msg_type = savan_util_get_message_type(msg_ctx, env);
    if (msg_type == SAVAN_MSG_TYPE_SUB)
        savan_msg_recv_handle_sub_request(env, msg_ctx, new_msg_ctx);
    else if (msg_type == SAVAN_MSG_TYPE_UNSUB)
        savan_msg_recv_handle_unsub_request(env, msg_ctx, new_msg_ctx);
    else if (msg_type == SAVAN_MSG_TYPE_RENEW)
        savan_msg_recv_handle_renew_request(env, msg_ctx, new_msg_ctx);
    else if (msg_type == SAVAN_MSG_TYPE_GET_STATUS)
        savan_msg_recv_handle_get_status_request(env, msg_ctx, new_msg_ctx);
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan][msg recv] Unhandled "
            "message type"); 
        AXIS2_ERROR_SET(env->error, SAVAN_ERROR_UNHANDLED_MSG_TYPE,
            AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    
    return AXIS2_SUCCESS;    
}

/******************************************************************************/

axis2_status_t AXIS2_CALL
savan_msg_recv_handle_sub_request(
    const axutil_env_t *env, 
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx)
{
    axiom_namespace_t *ns = NULL;
    axiom_namespace_t *addr_ns = NULL;
    axis2_msg_info_headers_t* info_header = NULL;
    axis2_msg_info_headers_t* old_info_header = NULL;
    axutil_param_t *subs_mgr_url_param = NULL;
    axutil_qname_t *qname = NULL;
    axiom_soap_envelope_t *default_envelope = NULL;
    axiom_node_t *body_node = NULL;
    axutil_property_t *property = NULL;
    axiom_node_t *response_node = NULL;
    axiom_node_t *submgr_node = NULL;
    axiom_node_t *addr_node = NULL;
    axiom_node_t *refparam_node = NULL;
    axiom_node_t *id_node = NULL;
    axiom_node_t *expires_node = NULL;
    axiom_element_t *response_elem = NULL;
    axiom_element_t *submgr_elem = NULL;
    axiom_element_t *addr_elem = NULL;
    axiom_element_t *refparam_elem = NULL;
    axiom_element_t *id_elem = NULL;
    axiom_element_t *expires_elem = NULL;
    axis2_endpoint_ref_t *submgr_epr = NULL;
    const axis2_char_t *submgr_addr = NULL;
    axis2_char_t *id = NULL;
    axis2_char_t *expires = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_module_desc_t *module_desc = NULL;
    savan_subscriber_t *subscriber = NULL;
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][msg recv] "
        "handle sub request...");
    
    /* set wsa action as SubscribeResponse. */
    info_header =  axis2_msg_ctx_get_msg_info_headers(new_msg_ctx, env);
    axis2_msg_info_headers_set_action(info_header, env, SAVAN_ACTIONS_SUB_RESPONSE);
    
    default_envelope = savan_msg_recv_build_soap_envelope(env, &body_node);
    if (!default_envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to build "
            "soap envelope for response message"); 
        AXIS2_ERROR_SET(env->error, SAVAN_ERROR_FAILED_TO_BUILD_SOAP_ENV, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    /* Create body elements and attach */
    
    ns = axiom_namespace_create (env, EVENTING_NAMESPACE, EVENTING_NS_PREFIX);
    addr_ns = axiom_namespace_create(env, AXIS2_WSA_NAMESPACE_SUBMISSION, "wsa");
    
    /* SubscribeResponse element */
    response_elem = axiom_element_create(env, NULL, ELEM_NAME_SUB_RESPONSE, ns,
        &response_node);
    
    /* SubscriptionManager element */
    submgr_elem = axiom_element_create(env, response_node, ELEM_NAME_SUB_MGR, ns,
        &submgr_node);
    addr_elem = axiom_element_create(env, submgr_node, ELEM_NAME_ADDR, addr_ns,
        &addr_node);
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    qname = axutil_qname_create(env, "savan", NULL, NULL);
    module_desc = axis2_conf_get_module(conf, env, qname);
    axutil_qname_free(qname, env);
    subs_mgr_url_param = axis2_module_desc_get_param(module_desc, env, 
        "SubscriptionMgrURL");
    if(subs_mgr_url_param)
    {
        submgr_addr = axutil_param_get_value(subs_mgr_url_param, env);
    }
    else 
    {
        old_info_header =  axis2_msg_ctx_get_msg_info_headers(msg_ctx, env);
        submgr_epr = axis2_msg_info_headers_get_to(old_info_header, env);
        submgr_addr = axis2_endpoint_ref_get_address(submgr_epr, env);
    }
    axiom_element_set_text(addr_elem, env, submgr_addr, addr_node);
    
    /* Get subscriber id from the msg ctx */
    property =  axis2_msg_ctx_get_property(msg_ctx, env, SAVAN_KEY_SUB_ID);
    id = (axis2_char_t*)axutil_property_get_value(property, env);
    
    /* Set sub id as a ref param */
    refparam_elem = axiom_element_create(env, submgr_node, ELEM_NAME_REF_PARAM,
        addr_ns, &refparam_node);
    id_elem = axiom_element_create(env, refparam_node, ELEM_NAME_ID, ns, &id_node);
    axiom_element_set_text(id_elem, env, id, id_node);
    
    /* Expires element. Get expiry time from subscriber and set */
    subscriber = savan_util_get_subscriber_from_msg(env, msg_ctx, id);
    if(subscriber)
        expires = savan_subscriber_get_expires(subscriber, env);
    else
    {
        printf("subscriber not found \n");
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Subscriber not found");
        return AXIS2_FAILURE;
    }
    
    expires_elem = axiom_element_create(env, response_node, ELEM_NAME_EXPIRES, ns,
        &expires_node);
    axiom_element_set_text(expires_elem, env, expires, expires_node);
    
    axiom_node_add_child(body_node , env, response_node);
     axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, default_envelope);
    
    return AXIS2_SUCCESS;
}

/*****************************************************************************/
 
axis2_status_t AXIS2_CALL
savan_msg_recv_handle_unsub_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx)
{
    axiom_namespace_t *ns = NULL;
    axis2_msg_info_headers_t* info_header = NULL;
    axiom_soap_envelope_t *default_envelope = NULL;
    axiom_node_t *body_node = NULL;
    axiom_node_t *response_node = NULL;
    axiom_element_t *response_elem = NULL;
    savan_subscriber_t *subscriber = NULL;
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][msg recv] "
        "handle unsub request...");

    
    /* Send a UnsubscribeResponse. This has an empty body. Before sending the
     * reply we will need to check whether the subscriber has been removed from
     * the store */
    
    subscriber = savan_util_get_subscriber_from_msg(env, msg_ctx, NULL);
    if (subscriber)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to remove "
            "the subscriber from local store");
        return AXIS2_FAILURE;
    }

    /* Set wsa action as UnsubscribeResponse. */
    info_header =  axis2_msg_ctx_get_msg_info_headers(new_msg_ctx, env);
    axis2_msg_info_headers_set_action(info_header, env, SAVAN_ACTIONS_UNSUB_RESPONSE);
    
    default_envelope = savan_msg_recv_build_soap_envelope(env, &body_node);
    if (!default_envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to build "
            "soap envelope for response message"); 
        AXIS2_ERROR_SET(env->error, SAVAN_ERROR_FAILED_TO_BUILD_SOAP_ENV, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    /* Create body elements and attach */
    
    ns = axiom_namespace_create (env, EVENTING_NAMESPACE, EVENTING_NS_PREFIX);
    
    /* UnsubscribeResponse element */
    response_elem = axiom_element_create(env, NULL, ELEM_NAME_UNSUB_RESPONSE, ns,
        &response_node);

    axiom_node_add_child(body_node , env, response_node);
     axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, default_envelope);
    
    return AXIS2_SUCCESS;
}


/*****************************************************************************/
 
axis2_status_t AXIS2_CALL
savan_msg_recv_handle_renew_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx)
{
    axiom_namespace_t *ns = NULL;
    axis2_msg_info_headers_t* info_header = NULL;
    axiom_soap_envelope_t *default_envelope = NULL;
    axiom_node_t *body_node = NULL;
    axiom_node_t *response_node = NULL;
    axiom_node_t *expires_node = NULL;
    axiom_element_t *response_elem = NULL;
    axiom_element_t *expires_elem = NULL;
    axis2_char_t *expires = NULL;
    savan_subscriber_t *subscriber = NULL;
    axis2_bool_t renewed = AXIS2_FALSE;
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][msg recv] "
        "handle renew request...");

    subscriber = savan_util_get_subscriber_from_msg(env, msg_ctx, NULL);
    if (!subscriber)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to find "
            "the subscriber from local store");
        return AXIS2_FAILURE;
    }

    renewed = savan_subscriber_get_renew_status(subscriber, env);
    if (!renewed)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Subscription is "
            "not renewed");
        return AXIS2_FAILURE;
    }

    /* Set wsa action as RenewResponse. */
    info_header =  axis2_msg_ctx_get_msg_info_headers(new_msg_ctx, env);
    axis2_msg_info_headers_set_action(info_header, env, SAVAN_ACTIONS_RENEW_RESPONSE);
    
    default_envelope = savan_msg_recv_build_soap_envelope(env, &body_node);
    if (!default_envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to build "
            "soap envelope for response message"); 
        AXIS2_ERROR_SET(env->error, SAVAN_ERROR_FAILED_TO_BUILD_SOAP_ENV, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    /* create body elements and attach */
    
    ns = axiom_namespace_create (env, EVENTING_NAMESPACE, EVENTING_NS_PREFIX);
    
    /* RenewResponse element */
    response_elem = axiom_element_create(env, NULL, ELEM_NAME_RENEW_RESPONSE, ns,
        &response_node);

    /* Expires element */
    expires = savan_subscriber_get_expires(subscriber, env);
    
    expires_elem = axiom_element_create(env, response_node, ELEM_NAME_EXPIRES, ns,
        &expires_node);
    axiom_element_set_text(expires_elem, env, expires, expires_node);
    
    axiom_node_add_child(body_node , env, response_node);
     axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, default_envelope);
    
    return AXIS2_SUCCESS;
}

/*****************************************************************************/
 
axis2_status_t AXIS2_CALL
savan_msg_recv_handle_get_status_request(
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    axis2_msg_ctx_t *new_msg_ctx)
{
    axiom_namespace_t *ns = NULL;
    axis2_msg_info_headers_t* info_header = NULL;
    axiom_soap_envelope_t *default_envelope = NULL;
    axiom_node_t *body_node = NULL;
    axiom_node_t *response_node = NULL;
    axiom_node_t *expires_node = NULL;
    axiom_element_t *response_elem = NULL;
    axiom_element_t *expires_elem = NULL;
    axis2_char_t *expires = NULL;
    savan_subscriber_t *subscriber = NULL;
    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[savan][msg recv] "
        "handle get status request...");

    /* set wsa action as GetStatusResponse. */
    info_header =  axis2_msg_ctx_get_msg_info_headers(new_msg_ctx, env);
    axis2_msg_info_headers_set_action(info_header, env, SAVAN_ACTIONS_GET_STATUS_RESPONSE);
    
    default_envelope = savan_msg_recv_build_soap_envelope(env, &body_node);
    if (!default_envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[savan] Failed to build "
            "soap envelope for response message"); 
        AXIS2_ERROR_SET(env->error, SAVAN_ERROR_FAILED_TO_BUILD_SOAP_ENV, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    /* create body elements and attach */
    
    ns = axiom_namespace_create (env, EVENTING_NAMESPACE, EVENTING_NS_PREFIX);
    
    /* GetStatusResponse element */
    response_elem = axiom_element_create(env, NULL, ELEM_NAME_GETSTATUS_RESPONSE, ns,
        &response_node);

    /* Expires element */
    subscriber = savan_util_get_subscriber_from_msg(env, msg_ctx, NULL);
    expires = savan_subscriber_get_expires(subscriber, env);

    expires_elem = axiom_element_create(env, response_node, ELEM_NAME_EXPIRES, ns,
        &expires_node);
    axiom_element_set_text(expires_elem, env, expires, expires_node);
    
    axiom_node_add_child(body_node , env, response_node);
     axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, default_envelope);
    
    return AXIS2_SUCCESS;
}

/******************************************************************************/

axiom_soap_envelope_t *AXIS2_CALL
savan_msg_recv_build_soap_envelope(
    const axutil_env_t *env,
    axiom_node_t **body_node)
{
    axiom_namespace_t *soap_ns = NULL;
    axiom_soap_envelope_t *default_envelope = NULL;
    axiom_soap_body_t *body = NULL;
    axiom_soap_header_t *header = NULL;

    /* create the soap envelope here */
    soap_ns = axiom_namespace_create(env, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI,
        "s12");
    if (!soap_ns)
    {
        return NULL;
    }

    default_envelope = axiom_soap_envelope_create(env, soap_ns);
    if (!default_envelope)
    {
        return NULL;
    }

    header = axiom_soap_header_create_with_parent(env, default_envelope);
    if (!header)
    {
        return NULL;
    }

    body = axiom_soap_body_create_with_parent(env, default_envelope);
    if (!body)
    {
        return NULL;
    }

    *body_node = axiom_soap_body_get_base_node(body, env);
    if (!(*body_node))
    {
        return NULL;
    }

    return default_envelope;
}

/******************************************************************************/
/*
AXIS2_EXPORT int axis2_get_instance(
    struct axis2_msg_recv **inst,
    const axutil_env_t *env)
{
    *inst = savan_msg_recv_create(env);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}
*/
/******************************************************************************/
/*
AXIS2_EXPORT int axis2_remove_instance(
    struct axis2_msg_recv *inst,
    const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (inst)
    {
        status = axis2_msg_recv_free(inst, env);
    }
    
    return status;
}
*/
