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

#include <axutil_types.h>
#include <axutil_string.h>
#include <axis2_endpoint_ref.h>
#include <axis2_addr.h>
#include <axiom.h>
#include <axiom_soap.h>
#include <axis2_svc_ctx.h>
#include <iksemel.h>
#include <axutil_url.h>
#include <axutil_generic_obj.h>

#include <axis2_xmpp_transport.h>
#include <axis2_xmpp_transport_sender.h>
#include <axis2_xmpp_transport_utils.h>
#include <axis2_xmpp_client.h>

/**
 * XMPP Transport Sender struct impl
 * Axis2 XMPP Transport Sender impl
 */

typedef struct axis2_xmpp_transport_sender_impl
{
    axis2_transport_sender_t sender;
}
axis2_xmpp_transport_sender_impl_t;

#define AXIS2_INTF_TO_IMPL(transport_sender)  \
    ((axis2_xmpp_transport_sender_impl_t *)   \
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

void AXIS2_CALL
axis2_xmpp_transport_sender_free(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env);

/* End of function headers ****************************************************/

static const axis2_transport_sender_ops_t xmpp_transport_sender_ops_var = {
    axis2_xmpp_transport_sender_init,
    axis2_xmpp_transport_sender_invoke,
    axis2_xmpp_transport_sender_clean_up,
    axis2_xmpp_transport_sender_free
};

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
    impl->sender.ops = &xmpp_transport_sender_ops_var;
    return &(impl->sender);
}


void AXIS2_CALL
axis2_xmpp_transport_sender_free(
    axis2_transport_sender_t *transport_sender,
    const axutil_env_t *env)
{
    axis2_xmpp_transport_sender_impl_t *impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    impl = AXIS2_INTF_TO_IMPL(transport_sender);

    AXIS2_FREE(env->allocator, impl);
}

/*****************************************************************************/
/* If one using svc client with xmpp transport , there are some
 * properties that they need to set
 * 1. XMPP_JID       client's jid that need to authenticate with jabber server.
 * 2. XMPP_PASSWORD  client's password corresponding to XMPP_JID.
 * 3. XMMP_SVC_JID   servers JID
 * 4. XMPP_SASL      enable/disable sasl authentication. default is
 * enabled  
 *        to disable  XMPP_SASL value should be "false"
 *
 *or can add parameter to the axis2.xml or services.xml
 *
 * <parameter name="XMPP" JID="din@localhost/Home" PASSWORD="123"
 * SASL="true"/>
 *
 *always programmatical method get priority.i.e axis2.xml or
 *services.xml value overridden by svc_client options.
 *
 *
 *****************************************************************************/
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
    int ret = 0;
    axiom_soap_envelope_t *response_soap_env = NULL;
    axis2_xmpp_session_data_t *session = NULL;
    axis2_bool_t is_server = AXIS2_TRUE;
    axis2_op_t *op = NULL;
    const axis2_char_t *mep_uri = NULL;
    axis2_endpoint_ref_t *to = NULL;
    const axis2_char_t *to_str = NULL;
    axutil_url_t *to_url = NULL;
    axutil_param_t *xmpp_param = NULL;
    axutil_hash_t *xmpp_hash = NULL;
    axutil_generic_obj_t *xmpp_gen_obj = NULL;
    axiom_attribute_t *xmpp_attr = NULL;
    axutil_param_t *xmpp_session = NULL;
    axis2_transport_out_desc_t *transport_out = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    op = axis2_msg_ctx_get_op (msg_ctx, env);
    mep_uri = axis2_op_get_msg_exchange_pattern(op, env);
    is_server = axis2_msg_ctx_get_server_side (msg_ctx, env);
    
    if(!is_server)
    {
        axutil_allocator_switch_to_global_pool(env->allocator);
        transport_out = axis2_msg_ctx_get_transport_out_desc(msg_ctx, env);
        xmpp_session = axis2_transport_out_desc_get_param(transport_out, env, "XMPP_SESSION");

        if(xmpp_session)
        {
            session = (axis2_xmpp_session_data_t *) axutil_param_get_value(xmpp_session, env);
            session->env = (axutil_env_t *) env;
            axis2_xmpp_session_reset(session, env);
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[xmpp]session reuse ");
        }
        else
        {
            axis2_char_t *sasl = NULL;
            axis2_char_t *tls = NULL;

            session = axis2_xmpp_session_create(env);
            session->id_str = (axis2_char_t *) axis2_msg_ctx_get_property_value(msg_ctx, env,
                "XMPP_JID");
            session->password = (axis2_char_t *) axis2_msg_ctx_get_property_value(msg_ctx, env,
                "XMPP_PASSWORD");
            sasl = (axis2_char_t *) axis2_msg_ctx_get_property_value(msg_ctx, env, "XMPP_SASL");
            tls = (axis2_char_t *) axis2_msg_ctx_get_property_value(msg_ctx, env, "XMPP_TLS");

            /* If JID, PASSWORD and SASL didn't give programatically then we will get them
             * from services.xml or axis2.xml */
            if(!(session->id_str && session->password))
            {
                xmpp_param = axis2_msg_ctx_get_parameter(msg_ctx, env, "XMPP");
                xmpp_hash = axutil_param_get_attributes(xmpp_param, env);

                xmpp_gen_obj = axutil_hash_get(xmpp_hash, "JID", AXIS2_HASH_KEY_STRING);
                xmpp_attr = (axiom_attribute_t *) axutil_generic_obj_get_value(xmpp_gen_obj, env);
                session->id_str = axiom_attribute_get_value(xmpp_attr, env);

                xmpp_gen_obj = axutil_hash_get(xmpp_hash, "PASSWORD", AXIS2_HASH_KEY_STRING);
                xmpp_attr = (axiom_attribute_t *) axutil_generic_obj_get_value(xmpp_gen_obj, env);
                session->password = axiom_attribute_get_value(xmpp_attr, env);

                xmpp_gen_obj = axutil_hash_get(xmpp_hash, "SASL", AXIS2_HASH_KEY_STRING);
                xmpp_attr = (axiom_attribute_t *) axutil_generic_obj_get_value(xmpp_gen_obj, env);
                sasl = axiom_attribute_get_value(xmpp_attr, env);

                xmpp_gen_obj = axutil_hash_get(xmpp_hash, "TLS", AXIS2_HASH_KEY_STRING);
                xmpp_attr = (axiom_attribute_t *) axutil_generic_obj_get_value(xmpp_gen_obj, env);
                tls = axiom_attribute_get_value(xmpp_attr, env);
            }

            if(!axutil_strcmp(sasl, "true"))
            {
                session->use_sasl = 1;
            }

            if(!axutil_strcmp(tls, "true"))
            {
                session->use_tls = 1;
            }

            session->env = (axutil_env_t *) env;
            session->conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            session->svc = axis2_msg_ctx_get_svc(msg_ctx, env);

            session->parser = iks_stream_new(IKS_NS_CLIENT, (void*) session,
                axis2_xmpp_client_on_data);

            iks_set_log_hook(session->parser, axis2_xmpp_client_on_log);
            axis2_xmpp_client_setup_filter(session);
            session->jid = iks_id_new(iks_parser_stack(session->parser), session->id_str);
            session->server = session->jid->server;
            session->user = session->jid->user;

            ret = iks_connect_tcp(session->parser, session->server, IKS_JABBER_PORT);
            if(ret != IKS_OK)
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                    "[xmpp]Failed to connect to server %s, error code %d", session->server, ret);
                axutil_allocator_switch_to_local_pool(env->allocator);
                return AXIS2_FAILURE;
            }

            while(!session->authorized || !session->session)
            {
                ret = iks_recv(session->parser, -1);
            }

            xmpp_session = axutil_param_create(env, "XMPP_SESSION", (void *) session);
            axutil_param_set_value_free(xmpp_session, env, axis2_xmpp_session_free_void_arg);
            axis2_transport_out_desc_add_param(transport_out, env, xmpp_session);

        }
        axutil_allocator_switch_to_local_pool(env->allocator);

        xmpp_parser = session->parser;
        to = axis2_msg_ctx_get_to(msg_ctx, env);
        if(to)
        {
            to_str = axis2_endpoint_ref_get_address(to, env);
            to_url = axutil_url_parse_string(env, to_str);
            if(to_url)
            {
                client_jid = axutil_url_get_server(to_url, env);
            }
        }
    }
    else
    {
        /* The XMPP parser and the client jid is set inside a hash table, which in
         * turn is set as a property in the msg ctx */
        properties = (axutil_hash_t *) axis2_msg_ctx_get_property_value(msg_ctx, env,
            AXIS2_XMPP_PROPERTIES);

        if(!properties)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "[xmpp]XMPP properties not set in message context");
            return AXIS2_FAILURE;
        }

        property = axutil_hash_get(properties, AXIS2_XMPP_PARSER, AXIS2_HASH_KEY_STRING);
        if(!property)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[xmpp]XMPP parser not set in message context");
            return AXIS2_FAILURE;
        }
        xmpp_parser = axutil_property_get_value(property, env);

        property = axutil_hash_get(properties, AXIS2_XMPP_CLIENT_JID, AXIS2_HASH_KEY_STRING);
        if(!property)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "[xmpp]JID of requesting client not set in message context");
            return AXIS2_FAILURE;
        }
        client_jid = axutil_property_get_value(property, env);
    }
    
    soap_envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);

    xml_writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0,
        AXIS2_XML_PARSER_TYPE_BUFFER);
    if(!xml_writer)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[xmpp]Failed to create XML writer");
        return AXIS2_FAILURE;
    }

    om_output = axiom_output_create(env, xml_writer);
    if(!om_output)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[xmpp]Failed to create OM output");
        axiom_xml_writer_free(xml_writer, env);
        xml_writer = NULL;
        return AXIS2_FAILURE;
    }

    axiom_soap_envelope_serialize(soap_envelope, env, om_output, AXIS2_FALSE);

    soap_str = (axis2_char_t *) axiom_xml_writer_get_xml(xml_writer, env);
    if(!soap_str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[xmpp]Failed to serialize the SOAP envelope");
        return AXIS2_FAILURE;
    }

    xmpp_msg = NULL;
    xmpp_msg = iks_make_msg(IKS_TYPE_CHAT, client_jid, soap_str);
    iks_send(xmpp_parser, xmpp_msg);

    /* Only client needs to terminate connection after recieving
     * response.
     */
    if(!is_server)
    {
        /* check MEP, SEND_ROBUST and OUT_ONLY method doesnt have any
         * response, Hence disconnected*/
        if(!axutil_strcmp(mep_uri, AXIS2_MEP_URI_OUT_ONLY) || !axutil_strcmp(mep_uri,
            AXIS2_MEP_URI_ROBUST_OUT_ONLY))
        {
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[xmpp]send robust completed.");
        }
        else
        {
            while(!session->in_msg)
                iks_recv(xmpp_parser, -1);
        }

        if(session->response)
        {
            response_soap_env = axis2_msg_ctx_get_soap_envelope(session->response, env);
            if(response_soap_env)
                axis2_msg_ctx_set_response_soap_envelope(msg_ctx, env, response_soap_env);
        }
    }
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
        printf("[xmpp]transport sender load not success\n");
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
        AXIS2_TRANSPORT_SENDER_FREE(inst, env);
    }
    return status;
}


