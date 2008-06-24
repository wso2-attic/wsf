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

#include <ctype.h>
#include <string.h>
#include <axutil_utils.h>
#include <axutil_hash.h>
#include <axutil_qname.h>
#include <axiom_soap.h>
#include <axiom.h>
#include <axutil_property.h>
#include <axis2_engine.h>
#include <axis2_endpoint_ref.h>

#include <axis2_xmpp_transport.h>
#include <axis2_xmpp_transport_utils.h>


/* Function headers ***********************************************************/

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_xmpp_transport_utils_process_message_server(
    const axutil_env_t *env,
    axis2_xmpp_session_data_t *session,
    axis2_char_t *soap_msg,
    axis2_char_t *from,
    axis2_char_t *request_uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_xmpp_transport_utils_process_message_client(
    const axutil_env_t *env,
    axis2_xmpp_session_data_t *session,
    axis2_char_t *soap_msg,
    axis2_char_t *from,
    axis2_char_t *request_uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_xmpp_transport_utils_process_presence_server(
    const axutil_env_t *env,
    axis2_xmpp_session_data_t *session,
    axis2_char_t *presence_str,
    axis2_char_t *request_uri);

/* End of function headers ****************************************************/

/*****************************************************************************/

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_xmpp_transport_utils_process_message_server(
    const axutil_env_t *env,
    axis2_xmpp_session_data_t *session,
    axis2_char_t *soap_msg,
    axis2_char_t *from,
    axis2_char_t *request_uri)
{
    axis2_status_t status = AXIS2_FAILURE;
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_soap_builder_t *soap_builder = NULL;
    axiom_soap_envelope_t *soap_envelope = NULL;
    axis2_engine_t *engine = NULL;
    axis2_conf_t *conf = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axutil_qname_t *qname = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
    axutil_hash_t *properties = NULL;
    axutil_property_t *property = NULL;
    
    reader = axiom_xml_reader_create_for_memory(env, soap_msg,
        axutil_strlen(soap_msg), NULL, AXIS2_XML_PARSER_TYPE_BUFFER);
    if (!reader)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create XML reader");
        return AXIS2_FAILURE;
    }

    builder = axiom_stax_builder_create(env, reader);
    if (!builder)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create Stax builder");
        return AXIS2_FAILURE;
    }

    soap_builder = axiom_soap_builder_create(env, builder,
        AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI);
    if (!soap_builder)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create SOAP builder");
        return AXIS2_FAILURE;
    }

    /* Find transport in and out descriptions from the conf. We need out context
     * on the sending side */
    qname = axutil_qname_create(env, AXIS2_TRANSPORT_XMPP, NULL, NULL);
    conf = axis2_conf_ctx_get_conf(session->conf_ctx, env);
    out_desc = axis2_conf_get_transport_out(conf, env, 3);
    in_desc = axis2_conf_get_transport_in(conf, env, 1);
    axutil_qname_free(qname, env);
    
    /* Create a new message ctx */
    msg_ctx = axis2_msg_ctx_create(env, session->conf_ctx, in_desc, out_desc);
    if (!msg_ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create a message context");
        return AXIS2_FAILURE;
    }
    axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);

    axis2_msg_ctx_set_to(msg_ctx, env,
        axis2_endpoint_ref_create(env, request_uri));

    soap_envelope = axiom_soap_builder_get_soap_envelope(soap_builder, env);
    if (!soap_builder)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to build a SOAP envelope "
            "from the incoming message");
        return AXIS2_FAILURE;
    }

    axis2_msg_ctx_set_soap_envelope(msg_ctx, env, soap_envelope);

    /* Create a hash table and attach the jid of the requesting cient and the
     * XMPP parser as values of this table. Then attach the hash table to the
     * msg ctx to access them inside engine.send(). [Note: we copy this hash table
     * when copying the in-msg ctx to the out-msg ctx] */

    properties = axutil_hash_make(env);
    if(properties)
    {
        /* jid of the requesting client */
        property = axutil_property_create(env);
        axutil_property_set_scope(property, env, AXIS2_SCOPE_APPLICATION);
        axutil_property_set_value(property, env, from);
        axutil_hash_set(properties, AXIS2_XMPP_CLIENT_JID, AXIS2_HASH_KEY_STRING,
            (void*)property);

        /* XMPP parser */
        property = axutil_property_create(env);
        axutil_property_set_scope(property, env, AXIS2_SCOPE_APPLICATION);
        axutil_property_set_value(property, env, session->parser);
        axutil_hash_set(properties, AXIS2_XMPP_PARSER, AXIS2_HASH_KEY_STRING,
            (void*)property);

        property = axutil_property_create(env);
        axutil_property_set_scope(property, env, AXIS2_SCOPE_APPLICATION);
        axutil_property_set_value(property, env, properties);
        axis2_msg_ctx_set_property(msg_ctx, env, AXIS2_XMPP_PROPERTIES,
                                   property);
    }    

    /* Now pass it to the engine */
    engine = axis2_engine_create(env, session->conf_ctx);
    status = axis2_engine_receive(engine, env, msg_ctx);

    return status;
}

/*****************************************************************************/

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_xmpp_transport_utils_process_presence_server(
    const axutil_env_t *env,
    axis2_xmpp_session_data_t *session,
    axis2_char_t *presence_str,
    axis2_char_t *request_uri)
{
    axiom_document_t *doc = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_xml_reader_t *reader = NULL;
    axiom_namespace_t *soap_ns = NULL;
    axiom_soap_envelope_t *default_envelope = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axiom_node_t *body_node = NULL;
    axiom_node_t *op_node = NULL;
    axiom_node_t *pres_node = NULL;
    axiom_element_t *op_elem = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_engine_t *engine = NULL;
    axis2_conf_t *conf = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axutil_qname_t *qname = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
   
    if (!session->subscribe_op)
    {
        /* No operation name means that this is a presence event of something
         * that we didn't subscribe for */
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation name is not set. "
                "Ignored the presence element");
        return AXIS2_SUCCESS;
    }

    /* create the soap envelope here*/
    soap_ns = axiom_namespace_create(env, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI,
        "s12");
    if (!soap_ns)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create namespace");
        return IKS_FILTER_EAT;
    }

    default_envelope = axiom_soap_envelope_create(env, soap_ns);
    if (!default_envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create default soap envelope");
        return IKS_FILTER_EAT;
    }

    soap_header = axiom_soap_header_create_with_parent(env, default_envelope);
    if (!soap_header)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create soap header");
        return AXIS2_FAILURE;
    }

    soap_body = axiom_soap_body_create_with_parent(env, default_envelope);
    if (!soap_body)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create soap body");
        return AXIS2_FAILURE;
    }

    body_node = axiom_soap_body_get_base_node(soap_body, env);
    if (!body_node)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to get base node");
        return AXIS2_FAILURE;
    }

    /* Create an element by the operation name and put the whole 'presence' stanza
     * inside that. This will get the soap body based dispatching to work and
     * find the operation */

    op_elem = axiom_element_create(env, NULL, session->subscribe_op, NULL,
        &op_node);
    
    reader = axiom_xml_reader_create_for_memory(env, presence_str, 
        axutil_strlen(presence_str), NULL, AXIS2_XML_PARSER_TYPE_BUFFER);
    if (!reader)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create XML reader");
        return AXIS2_FAILURE;
    }

    builder = axiom_stax_builder_create(env, reader);
    if (!builder)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create Stax builder");
        return AXIS2_FAILURE;
    }

    doc = axiom_document_create(env, NULL, builder);
    if (!doc)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create OM document");
        return AXIS2_FAILURE;
    }

    pres_node = axiom_document_build_all(doc, env);
    if (!pres_node)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create OM node for "
                "presence stanza");
        return AXIS2_FAILURE;
    }

    axiom_node_add_child(op_node , env, pres_node);
    axiom_node_add_child(body_node , env, op_node);

    /* Find transport in and out descriptions from the conf. We need out context
     * on the sending side */
    qname = axutil_qname_create(env, AXIS2_TRANSPORT_XMPP, NULL, NULL);
    conf = axis2_conf_ctx_get_conf(session->conf_ctx, env);
    out_desc = axis2_conf_get_transport_out(conf, env, 3);
    in_desc = axis2_conf_get_transport_in(conf, env, 1);
    axutil_qname_free(qname, env);
    
    /* Create a new message ctx */
    msg_ctx = axis2_msg_ctx_create(env, session->conf_ctx, in_desc, out_desc);
    if (!msg_ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create a message context");
        return AXIS2_FAILURE;
    }
    axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);

    axis2_msg_ctx_set_to(msg_ctx, env,
        axis2_endpoint_ref_create(env, request_uri));
    axis2_msg_ctx_set_soap_envelope(msg_ctx, env, default_envelope);

    /* Now pass it to the engine */
    engine = axis2_engine_create(env, session->conf_ctx);
    status = axis2_engine_receive(engine, env, msg_ctx);

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_xmpp_transport_utils_process_message_client(
    const axutil_env_t *env,
    axis2_xmpp_session_data_t *session,
    axis2_char_t *soap_msg,
    axis2_char_t *from,
    axis2_char_t *request_uri)
{
    axis2_status_t status = AXIS2_FAILURE;
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_soap_builder_t *soap_builder = NULL;
    axiom_soap_envelope_t *soap_envelope = NULL;

    axis2_conf_t *conf = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axutil_qname_t *qname = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
            
    reader = axiom_xml_reader_create_for_memory(env, soap_msg,
        axutil_strlen(soap_msg), NULL, AXIS2_XML_PARSER_TYPE_BUFFER);
    if (!reader)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create XML reader");
        return AXIS2_FAILURE;
    }

    builder = axiom_stax_builder_create(env, reader);
    if (!builder)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create Stax builder");
        return AXIS2_FAILURE;
    }

    soap_builder = axiom_soap_builder_create(env, builder,
        AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI);
    if (!soap_builder)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create SOAP builder");
        return AXIS2_FAILURE;
    }

    /* Find transport in and out descriptions from the conf. We need out context
     * on the sending side */
    qname = axutil_qname_create(env, AXIS2_TRANSPORT_XMPP, NULL, NULL);
    conf = axis2_conf_ctx_get_conf(session->conf_ctx, env);
    out_desc = axis2_conf_get_transport_out(conf, env, 3);
    in_desc = axis2_conf_get_transport_in(conf, env, 1);
    axutil_qname_free(qname, env);
    
    /* Create a new message ctx */
    msg_ctx = axis2_msg_ctx_create(env, session->conf_ctx, in_desc, out_desc);
    if (!msg_ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create a message context");
        return AXIS2_FAILURE;
    }
    axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_FALSE);

    axis2_msg_ctx_set_to(msg_ctx, env,
        axis2_endpoint_ref_create(env, request_uri));

    soap_envelope = axiom_soap_builder_get_soap_envelope(soap_builder, env);
    if (!soap_builder)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to build a SOAP envelope "
            "from the incoming message");
        return AXIS2_FAILURE;
    }

    axis2_msg_ctx_set_soap_envelope(msg_ctx, env, soap_envelope);

    session->response = msg_ctx;
    status = AXIS2_SUCCESS;
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_xmpp_transport_utils_process_presence_client(
    const axutil_env_t *env,
    axis2_xmpp_session_data_t *session,
    axis2_char_t *presence_str,
    axis2_char_t *request_uri)
{
    axiom_document_t *doc = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_xml_reader_t *reader = NULL;
    axiom_namespace_t *soap_ns = NULL;
    axiom_soap_envelope_t *default_envelope = NULL;
    axiom_soap_body_t *soap_body = NULL;
    axiom_soap_header_t *soap_header = NULL;
    axiom_node_t *body_node = NULL;
    axiom_node_t *op_node = NULL;
    axiom_node_t *pres_node = NULL;
    axiom_element_t *op_elem = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axis2_conf_t *conf = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axutil_qname_t *qname = NULL;
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
   
    if (!session->subscribe_op)
    {
        /* No operation name means that this is a presence event of something
         * that we didn't subscribe for */
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation name is not set. "
                "Ignored the presence element");
        return AXIS2_SUCCESS;
    }

    /* create the soap envelope here*/
    soap_ns = axiom_namespace_create(env, AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI,
        "s12");
    if (!soap_ns)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create namespace");
        return IKS_FILTER_EAT;
    }

    default_envelope = axiom_soap_envelope_create(env, soap_ns);
    if (!default_envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create default soap envelope");
        return IKS_FILTER_EAT;
    }

    soap_header = axiom_soap_header_create_with_parent(env, default_envelope);
    if (!soap_header)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create soap header");
        return AXIS2_FAILURE;
    }

    soap_body = axiom_soap_body_create_with_parent(env, default_envelope);
    if (!soap_body)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create soap body");
        return AXIS2_FAILURE;
    }

    body_node = axiom_soap_body_get_base_node(soap_body, env);
    if (!body_node)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to get base node");
        return AXIS2_FAILURE;
    }

    /* Create an element by the operation name and put the whole 'presence' stanza
     * inside that. This will get the soap body based dispatching to work and
     * find the operation */

    op_elem = axiom_element_create(env, NULL, session->subscribe_op, NULL,
        &op_node);
    
    reader = axiom_xml_reader_create_for_memory(env, presence_str, 
        axutil_strlen(presence_str), NULL, AXIS2_XML_PARSER_TYPE_BUFFER);
    if (!reader)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create XML reader");
        return AXIS2_FAILURE;
    }

    builder = axiom_stax_builder_create(env, reader);
    if (!builder)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create Stax builder");
        return AXIS2_FAILURE;
    }

    doc = axiom_document_create(env, NULL, builder);
    if (!doc)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create OM document");
        return AXIS2_FAILURE;
    }

    pres_node = axiom_document_build_all(doc, env);
    if (!pres_node)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create OM node for "
                "presence stanza");
        return AXIS2_FAILURE;
    }

    axiom_node_add_child(op_node , env, pres_node);
    axiom_node_add_child(body_node , env, op_node);

    /* Find transport in and out descriptions from the conf. We need out context
     * on the sending side */
    qname = axutil_qname_create(env, AXIS2_TRANSPORT_XMPP, NULL, NULL);
    conf = axis2_conf_ctx_get_conf(session->conf_ctx, env);
    out_desc = axis2_conf_get_transport_out(conf, env, 3);
    in_desc = axis2_conf_get_transport_in(conf, env, 1);
    axutil_qname_free(qname, env);
    
    /* Create a new message ctx */
    msg_ctx = axis2_msg_ctx_create(env, session->conf_ctx, in_desc, out_desc);
    if (!msg_ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create a message context");
        return AXIS2_FAILURE;
    }
    axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_FALSE);

    axis2_msg_ctx_set_to(msg_ctx, env,
        axis2_endpoint_ref_create(env, request_uri));
    axis2_msg_ctx_set_soap_envelope(msg_ctx, env, default_envelope);
    session->response = msg_ctx;
    return status;
}
