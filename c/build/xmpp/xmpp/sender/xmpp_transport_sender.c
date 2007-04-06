/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      xmpp://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <axutil_types.h>
#include <axutil_string.h>
#include <axis2_endpoint_ref.h>
#include <axis2_addr.h>
#include <axiom.h>
#include <axiom_soap.h>
#include <axis2_svc_ctx.h>
#include <iksemel.h>

#include <axis2_xmpp_transport.h>
#include <axis2_xmpp_transport_sender.h>
#include <axis2_xmpp_transport_utils.h>

/**
 * XMPP Transport Sender struct impl
 * Axis2 XMPP Transport Sender impl
 */

typedef struct axis2_xmpp_transport_sender_impl
{
    axis2_transport_sender_t sender;
}
axis2_xmpp_transport_sender_impl_t;

#define AXIS2_INTF_TO_IMPL(transport_sender) \
                         ((axis2_xmpp_transport_sender_impl_t *)\
                     (transport_sender))

/* Function headers ***********************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_transport_sender_invoke(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

axis2_status_t AXIS2_CALL
axis2_xmpp_transport_sender_clean_up(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx);

axis2_status_t AXIS2_CALL
axis2_xmpp_transport_sender_init(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_out_desc_t *out_desc);

axis2_status_t AXIS2_CALL
axis2_xmpp_transport_sender_free(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env);

/* End of function headers ****************************************************/

/******************************************************************************/

axis2_transport_sender_t *AXIS2_CALL
axis2_xmpp_transport_sender_create(
    const axutil_env_t *env)
{
    axis2_xmpp_transport_sender_impl_t *impl = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);

    impl = (axis2_xmpp_transport_sender_impl_t *)
        AXIS2_MALLOC(env->allocator, sizeof(axis2_xmpp_transport_sender_impl_t));

    if (!impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    impl->sender.ops = AXIS2_MALLOC(env->allocator,
        sizeof(axis2_transport_sender_ops_t));
    if (!impl->sender.ops)
    {
        axis2_xmpp_transport_sender_free((axis2_transport_sender_t *)impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    impl->sender.ops->invoke = axis2_xmpp_transport_sender_invoke;
    impl->sender.ops->cleanup = axis2_xmpp_transport_sender_clean_up;
    impl->sender.ops->init = axis2_xmpp_transport_sender_init;
    impl->sender.ops->free = axis2_xmpp_transport_sender_free;

    return &(impl->sender);
}


axis2_status_t AXIS2_CALL
axis2_xmpp_transport_sender_free(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env)
{
    axis2_xmpp_transport_sender_impl_t *impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    impl = AXIS2_INTF_TO_IMPL(transport_sender);

    if (transport_sender->ops)
        AXIS2_FREE(env->allocator, transport_sender->ops);

    AXIS2_FREE(env->allocator, impl);
    
    return AXIS2_SUCCESS;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_transport_sender_invoke(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    axutil_hash_t *properties = NULL;
    axutil_property_t *property = NULL;
    iksparser *xmpp_parser = NULL;
    char* client_jid = NULL;
    axiom_soap_envelope_t *soap_envelope = NULL;
    axis2_char_t* soap_str = NULL;
    axiom_xml_writer_t *xml_writer = NULL;
    axiom_output_t *om_output = NULL;
    iks* xmpp_msg = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    /* The XMPP parser and the client jid is set inside a hash table, which in
     * turn is set as a property in the msg ctx */

    property = AXIS2_MSG_CTX_GET_PROPERTY(msg_ctx, env, AXIS2_XMPP_PROPERTIES,
        AXIS2_FALSE);
    if (!property)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "XMPP properties not set in "
            "message context");
        return AXIS2_FAILURE;
    }
    
    properties = AXIS2_PROPERTY_GET_VALUE(property, env);
    if (!properties)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "XMPP properties not set in "
            "message context");
        return AXIS2_FAILURE;
    }

    property = axutil_hash_get(properties, AXIS2_XMPP_PARSER,
        AXIS2_HASH_KEY_STRING);
    if (!property)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "XMPP parser not set in "
            "message context");
        return AXIS2_FAILURE;
    }
    xmpp_parser = AXIS2_PROPERTY_GET_VALUE(property, env);

    property = axutil_hash_get(properties, AXIS2_XMPP_CLIENT_JID,
        AXIS2_HASH_KEY_STRING);
    if (!property)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "JID of requesting client not "
            "set in message context");
        return AXIS2_FAILURE;
    }
    client_jid = AXIS2_PROPERTY_GET_VALUE(property, env);
    
    soap_envelope = AXIS2_MSG_CTX_GET_SOAP_ENVELOPE(msg_ctx, env);
    
    xml_writer = axiom_xml_writer_create_for_memory(env, NULL,
            AXIS2_TRUE, 0, AXIS2_XML_PARSER_TYPE_BUFFER);
    if (NULL == xml_writer)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create XML writer");
        return AXIS2_FAILURE;
    }

    om_output = axiom_output_create(env, xml_writer);
    if (NULL == om_output)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create OM output");
        AXIOM_XML_WRITER_FREE(xml_writer, env);
        xml_writer = NULL;
        return AXIS2_FAILURE;
    }

    AXIOM_SOAP_ENVELOPE_SERIALIZE(soap_envelope, env, om_output, AXIS2_FALSE);

    soap_str = (axis2_char_t *)AXIOM_XML_WRITER_GET_XML(xml_writer, env);
    if (!soap_str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to serialize the SOAP "
            "envelope");
        return AXIS2_FAILURE;
    }

    xmpp_msg = NULL;
    xmpp_msg = iks_make_msg(IKS_TYPE_CHAT, client_jid, soap_str);

    iks_send(xmpp_parser, xmpp_msg);

    return AXIS2_SUCCESS;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_transport_sender_clean_up(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
    /*
     * Clean up is not used. If the xmpp sender needs
     * to be cleaned up it should be done here.
     */
    return AXIS2_SUCCESS;
}


/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_transport_sender_init(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_transport_out_desc_t *out_desc)
{
    return AXIS2_SUCCESS;
}

/*****************************************************************************/

/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int
axis2_get_instance(
    struct axis2_transport_sender **inst,
    const axutil_env_t *env)
{
    *inst = axis2_xmpp_transport_sender_create(env);
    if (!(*inst))
    {
        printf("transport sender load not success\n");
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

/*****************************************************************************/

AXIS2_EXPORT int
axis2_remove_instance(
    axis2_transport_sender_t *inst,
    const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (inst)
    {
        status = AXIS2_TRANSPORT_SENDER_FREE(inst, env);
    }
    return status;
}
