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

#include <axis2_xmpp_session.h>
#include <axutil_url.h>

typedef struct xmpp_msg_exchange_data
{
    iks* xmpp_msg;
    pthread_cond_t* conditional_variable;
    axis2_msg_ctx_t *response;
}xmpp_msg_exchange_data_t;

AXIS2_EXTERN axis2_xmpp_session_data_t * AXIS2_CALL
axis2_xmpp_session_create(
    const axutil_env_t *env)

{
    axis2_xmpp_session_data_t *session = NULL;
    session = (axis2_xmpp_session_data_t*) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_xmpp_session_data_t));
    if(!session)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Cannot create xmpp session. Insufficient memory.");
        return NULL;
    }
    axis2_xmpp_session_data_init(session);

    session->session_mutex = axutil_thread_mutex_create(env->allocator, AXIS2_THREAD_MUTEX_DEFAULT);
    if(!session->session_mutex)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
            "Cannot create xmpp session. Creating session mutex failed.");
        axis2_xmpp_session_free(session, env);
        return NULL;
    }

    session->msg_container = axutil_hash_make(env);
    if(!session->msg_container)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
            "Cannot create xmpp session. Creating message container failed.");
        axis2_xmpp_session_free(session, env);
        return NULL;
    }

    return session;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_free(
    axis2_xmpp_session_data_t *session,
    const axutil_env_t *env)
{
    iks_disconnect(session->parser);
    if(session->session_mutex)
    {
        axutil_thread_mutex_destroy(session->session_mutex);
    }

    if(session->msg_container)
    {
        axutil_hash_free(session->msg_container, env);
    }
}

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_free_void_arg(
    void *void_session,
    const axutil_env_t *env)
{
    axis2_xmpp_session_data_t *session = NULL;
    session = (axis2_xmpp_session_data_t *) void_session;
    axis2_xmpp_session_free(session, env);
}

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_reset(
    axis2_xmpp_session_data_t *session,
    const axutil_env_t *env)
{
    session->in_msg = 0;
    session->response = NULL;
}

void AXIS2_CALL
axis2_xmpp_session_data_init(
    axis2_xmpp_session_data_t *data)
{
    data->id_str = NULL;
    data->server = NULL;
    data->user = NULL;
    data->password = NULL;

    data->subscribe_to = NULL;
    data->subscribe_type = NULL;
    data->subscribe_op = NULL;

    data->session_id = NULL;
    data->parser = NULL;
    data->filter = NULL;
    data->jid = NULL;

    data->authorized = 0;
    data->features = 0;
    data->use_sasl = 0;
    data->use_tls = 0;
    data->subscribe = 0;
    data->bind = 0;
    data->in_msg = 0;
    data->session = 0;

    data->env = NULL;
    data->conf_ctx = NULL;
    data->svc = NULL;
    data->response = NULL;

    data->session_mutex = NULL;
    data->msg_container = NULL;
}

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_xmpp_session_send(
    axis2_xmpp_session_data_t * xmpp_session,
    const axutil_env_t *env,
    axis2_msg_ctx_t *msg_ctx,
    const axis2_char_t *mep_uri)
{
    axiom_soap_envelope_t *soap_envelope = NULL;
    axis2_char_t* soap_str = NULL;
    axiom_xml_writer_t *xml_writer = NULL;
    axiom_output_t *om_output = NULL;
    iks* xmpp_msg = NULL;
    axis2_endpoint_ref_t *to = NULL;
    axis2_char_t *client_jid = NULL;
    axiom_soap_envelope_t * response = NULL;

    to = axis2_msg_ctx_get_to(msg_ctx, env);
    if(to)
    {
        axis2_char_t *to_str = NULL;
        axutil_url_t *to_url = NULL;
        to_str = axis2_endpoint_ref_get_address(to, env);
        to_url = axutil_url_parse_string(env, to_str);
        if(to_url)
        {
            client_jid = axutil_url_get_server(to_url, env);
        }
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

    xmpp_msg = iks_make_msg(IKS_TYPE_CHAT, client_jid, soap_str);

    axutil_thread_mutex_lock(xmpp_session->session_mutex);
    axis2_xmpp_session_reset(xmpp_session, env);


    TODO


    iks_send(xmpp_session->parser, xmpp_msg);

    /* check MEP, SEND_ROBUST and OUT_ONLY method doesnt have any
     * response, Hence disconnected*/
    if(!axutil_strcmp(mep_uri, AXIS2_MEP_URI_OUT_ONLY) || !axutil_strcmp(mep_uri,
        AXIS2_MEP_URI_ROBUST_OUT_ONLY))
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[xmpp]send robust completed.");
    }
    else
    {
        while(!xmpp_session->in_msg)
        {
            iks_recv(xmpp_session->parser, -1);
        }
    }

    if(xmpp_session->response)
    {
        response = axis2_msg_ctx_get_soap_envelope(xmpp_session->response, env);
    }
    axutil_thread_mutex_unlock(xmpp_session->session_mutex);
    return response;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_start(
    axis2_xmpp_session_data_t * xmpp_session,
    const axutil_env_t *env)
{
}


pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

