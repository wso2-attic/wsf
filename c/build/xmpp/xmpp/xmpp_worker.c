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

#include <axutil_string.h>
#include <axis2_conf.h>
#include <axutil_string.h>
#include <axis2_msg_ctx.h>
#include <axis2_op_ctx.h>
#include <axis2_engine.h>
#include <axutil_uuid_gen.h>
#include <axutil_url.h>
#include <axutil_property.h>

#include <axis2_xmpp_transport.h>
#include <axis2_xmpp_worker.h>
#include <axis2_xmpp_session.h>

/**
 * @brief XMPP Worker struct impl
 * Axis2 XMPP Worker impl
 */

typedef struct axis2_xmpp_worker_impl
{
    axis2_xmpp_worker_t xmpp_worker;
    int svr_port;
    axis2_xmpp_session_data_t *session;
}
axis2_xmpp_worker_impl_t;

#define AXIS2_INTF_TO_IMPL(xmpp_worker) ((axis2_xmpp_worker_impl_t *)\
                                         (xmpp_worker))

/* Function headers ***********************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_worker_run(
    axis2_xmpp_worker_t *worker,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_xmpp_worker_free(
    axis2_xmpp_worker_t *xmpp_worker,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
axis2_xmpp_worker_set_svr_port(
    axis2_xmpp_worker_t *worker,
    const axutil_env_t *env,
    int port);

int axis2_xmpp_worker_on_start_node(
    axis2_xmpp_session_data_t *session,
    iks* node);

int axis2_xmpp_worker_on_normal_node(
    axis2_xmpp_session_data_t *session,
    iks* node);

void axis2_xmpp_worker_setup_filter(
    axis2_xmpp_session_data_t* session);

int axis2_xmpp_worker_on_message(
    void *user_data,
    ikspak *pak);

int axis2_xmpp_worker_on_presence(
    void *user_data,
    ikspak *pak);

int axis2_xmpp_worker_on_subscription(
    void *user_data,
    ikspak *pak);

int axis2_xmpp_worker_on_iq(
    void *user_data,
    ikspak *pak);


void AXIS2_CALL
axis2_xmpp_session_data_init (
    axis2_xmpp_session_data_t *data);

/* End of function headers ****************************************************/

/*****************************************************************************/

AXIS2_EXTERN axis2_xmpp_worker_t *AXIS2_CALL
axis2_xmpp_worker_create(
    const axutil_env_t *env,
    axis2_xmpp_session_data_t *data)
{
    axis2_xmpp_worker_impl_t *impl = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    impl = (axis2_xmpp_worker_impl_t*)
        AXIS2_MALLOC(env->allocator, sizeof(axis2_xmpp_worker_impl_t));

    if (!impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    impl->session = data;

    impl->xmpp_worker.ops = AXIS2_MALLOC(env->allocator,
        sizeof(axis2_xmpp_worker_ops_t));
    if (!impl->xmpp_worker.ops)
    {
        axis2_xmpp_worker_free((axis2_xmpp_worker_t*)impl, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    impl->xmpp_worker.ops->run = axis2_xmpp_worker_run;
    impl->xmpp_worker.ops->free = axis2_xmpp_worker_free;
    impl->xmpp_worker.ops->set_svr_port = axis2_xmpp_worker_set_svr_port;

    return &(impl->xmpp_worker);
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_worker_free(
    axis2_xmpp_worker_t *xmpp_worker,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (xmpp_worker->ops)
        AXIS2_FREE(env->allocator, xmpp_worker->ops);

    AXIS2_FREE(env->allocator, AXIS2_INTF_TO_IMPL(xmpp_worker));

    return AXIS2_SUCCESS;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_worker_set_svr_port(
    axis2_xmpp_worker_t *worker,
    const axutil_env_t *env,
    int port)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_INTF_TO_IMPL(worker)->svr_port = port;
    return AXIS2_SUCCESS;
}

/*****************************************************************************/

axis2_status_t AXIS2_CALL
axis2_xmpp_worker_run(
    axis2_xmpp_worker_t *worker,
    const axutil_env_t *env)
{
    axis2_xmpp_worker_impl_t *impl = NULL;
    axutil_env_t *thread_env = NULL;
    int ret = IKS_OK;
    char* tmp = NULL;
    int server_len = 0;
    int user_len = 0;

    thread_env = axutil_init_thread_env(env);

    AXIS2_PARAM_CHECK(thread_env->error, worker, AXIS2_FALSE);

    impl = (axis2_xmpp_worker_impl_t*)worker;
    impl->session->env = thread_env;

    AXIS2_LOG_DEBUG(thread_env->log, AXIS2_LOG_SI, 
                    "[xmpp]Starting %s", impl->session->id_str);
    /* Create an iks parser and connect to the XMPP server */
    /* We pass the session as user data, which we can access inside iksemel
     * callbacks */

    impl->session->parser = iks_stream_new(IKS_NS_CLIENT, (void*)impl->session,
        axis2_xmpp_worker_on_data);
    if (!impl->session->parser)
    {
        AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, 
                        "[xmpp]Failed to create XMPP parser");
        AXIS2_ERROR_SET(thread_env->error, AXIS2_XMPP_PARSER_CREATE_FAILED,
            AXIS2_FAILURE);
        return AXIS2_FAILURE; /* exit thread */
    }

    iks_set_log_hook(impl->session->parser, axis2_xmpp_worker_on_log);
    axis2_xmpp_worker_setup_filter(impl->session);

    /* Create an iksid using the jid supplied. Give "Default" as the resource
     * if a resource is not given */

    impl->session->jid = iks_id_new(iks_parser_stack(impl->session->parser), 
                                    impl->session->id_str);
    if ( (!impl->session->jid->server) || (!impl->session->jid->user))
    {
        AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, "[xmpp]Server and user name "
            "cannot be NULL in JID");
        return AXIS2_FAILURE; /* exit thread */
    }

    impl->session->server = impl->session->jid->server;
    impl->session->user = impl->session->jid->user;

    if (!impl->session->jid->resource) /* no resource given */
    {
        server_len = strlen(impl->session->server);
        user_len = strlen(impl->session->user);
        tmp = iks_malloc( server_len + user_len + 7 + 3);
        sprintf(tmp, "%s@%s/%s", impl->session->user, impl->session->server, 
                "Default");
        impl->session->jid = iks_id_new(iks_parser_stack(impl->session->parser),
                                        tmp);
        iks_free(tmp);
    }

    /* Now connect to the XMPP server */
    ret = iks_connect_tcp(impl->session->parser, impl->session->server,
                          IKS_JABBER_PORT);

    if (ret != IKS_OK)
    {
        AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, 
                        "[xmpp]Failed to connect to XMPP server. "
                        "Error code: %d", ret);
        AXIS2_ERROR_SET(thread_env->error, AXIS2_XMPP_SERVER_CONNECT_FAILED,
                        AXIS2_FAILURE);
	    return AXIS2_FAILURE; /* exit thread */
    }
   
	/* Call iks_recv() in a loop. This will call our on_data hook function as
     * and when data arrives */

	ret = IKS_OK;
    while (1)
    {

        ret = iks_recv(impl->session->parser, -1);

        if (ret != IKS_OK)
        {
            switch(ret)
            {
            case IKS_HOOK:
                AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, 
                                "[xmpp]Hook function returned an error");
	            return AXIS2_FAILURE;

            case IKS_NET_TLSFAIL:
                AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, 
                                "[xmpp]TLS handshake failed");
	            return AXIS2_FAILURE;

            default:
                AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, 
                                "[xmpp]I/O error");
	            return AXIS2_FAILURE;
            }
        }
    }

    return AXIS2_FAILURE; /* exit thread */
}

/*****************************************************************************/

int axis2_xmpp_worker_on_data(
    void* user_data,
    int type,
    iks* node)
{
    axis2_xmpp_session_data_t *session = (axis2_xmpp_session_data_t*)user_data;
    switch(type)
    {
        case IKS_NODE_START:
        {
            return axis2_xmpp_worker_on_start_node(session, node);
        }
        break;
        case IKS_NODE_NORMAL:
        {
            return axis2_xmpp_worker_on_normal_node(session, node);
        }
        break;
        case IKS_NODE_STOP:
        {
            AXIS2_LOG_ERROR(session->env->log, AXIS2_LOG_SI,
                            "[xmpp]stop node: server disconnected");
            return IKS_HOOK;
        }
        break;

        case IKS_NODE_ERROR:
        {
            AXIS2_LOG_ERROR(session->env->log, AXIS2_LOG_SI,
                            "[xmpp]error node: stream error");
            return IKS_HOOK;
        }
        break;

        default:
        {
            AXIS2_LOG_ERROR(session->env->log, AXIS2_LOG_SI,
                            "[xmpp]unknown node");
            return IKS_HOOK;
        }
    }

    if (node)
        iks_delete(node);

    return IKS_OK;
}

/*****************************************************************************/

int axis2_xmpp_worker_on_start_node(
    axis2_xmpp_session_data_t *session,
    iks* node)
{
    AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI,
                                "[xmpp]axis2_xmpp_worker_on_start_node");
    if(session->use_tls && (!iks_is_secure(session->parser)))
    {
        int return_val = IKS_OK;
        return_val = iks_start_tls(session->parser);
        return return_val;
    }

    if(!session->use_sasl) /* basic authentication */
    {
        iks *x;
        session->session_id = iks_find_attrib(node, "id");
        x = iks_make_auth(session->jid, session->password, session->session_id);
        iks_insert_attrib(x, "id", "auth");
        iks_send(session->parser, x);
        iks_delete(x);
    }
    return IKS_OK;
}

/*****************************************************************************/

int axis2_xmpp_worker_on_normal_node(
    axis2_xmpp_session_data_t *session,
    iks* node)
{
    iks *t = NULL;
    if (!strcmp("stream:features", iks_name(node))) 
    {
        session->features = iks_stream_features (node);

        if (session->use_sasl)
        {
            if (session->use_tls && !iks_is_secure (session->parser))
            {
                if(!session->authorized)
                {
                    /* We might be in the process of establishing TLS. So should return OK */
                    return IKS_OK;
                }
                return IKS_HOOK;
            }

            if (session->authorized)
            {
                /* Bind a resource if required */
                if (session->features & IKS_STREAM_BIND)
                {
                    t = iks_make_resource_bind (session->jid);
                    iks_send (session->parser, t);
                    iks_delete (t);
					session->bind = 1;
                }

                /* Send a session if required */
                if (session->features & IKS_STREAM_SESSION)
                {
                    t = iks_make_session ();
                    iks_insert_attrib (t, "id", "auth");
                    iks_send (session->parser, t);
                    iks_delete (t);
                }


                /* Subscribe if the service is configured to do so */
                if ( (session->subscribe) && (session->subscribe_to) )
                {
                    /* Check whether the type of subscription is user or room
                     * and send the subscription request accordingly */

                    if (!axutil_strcmp(session->subscribe_type, 
                                       AXIS2_XMPP_SUB_TYPE_USER))
                    {
                        iks_send(session->parser, 
                                 iks_make_s10n(IKS_TYPE_SUBSCRIBE,
                                               session->subscribe_to, ""));
                    }
                    else if (!axutil_strcmp(session->subscribe_type, 
                                            AXIS2_XMPP_SUB_TYPE_ROOM))
                    {
                        axis2_char_t *id = axutil_uuid_gen(session->env);

                        iks *x = iks_make_pres(IKS_SHOW_AVAILABLE, "");
                        iks_insert_attrib(x, "to", session->subscribe_to);
                        iks_insert_attrib(x, "id", id);
                        iks_send(session->parser, x);
                        AXIS2_FREE(session->env->allocator, id);
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(session->env->log, AXIS2_LOG_SI,
                            "[xmpp]Unknown subscription type. "
                                        "No subscription done");
                    }
                }

            }
            else
            {
                if (session->features & IKS_STREAM_SASL_MD5)
                {
                    iks_start_sasl(session->parser, IKS_SASL_DIGEST_MD5,
                        session->jid->user, session->password);
                }
                else if (session->features & IKS_STREAM_SASL_PLAIN)
                {
                    iks_start_sasl (session->parser, IKS_SASL_PLAIN,
                        session->jid->user, session->password);
                }
#ifdef AXIS2_XMPP_GSSAPI
                else if (session->features & IKS_STREAM_SASL_GSSAPI)
                {
                    iks_start_sasl (session->parser, IKS_SASL_GSSAPI,
                                    session->jid->user, session->password);
                }
#endif  /* AXIS2_XMPP_GSSAPI */

            }
        }
    }
    else if (!strcmp("failure", iks_name(node)))
    {
        AXIS2_LOG_ERROR(session->env->log, AXIS2_LOG_SI, 
                        "[xmpp]Authentication failed.");
        return IKS_HOOK;
    }
    else if (!strcmp("success", iks_name(node)))
    {
        AXIS2_LOG_INFO(session->env->log, "[xmpp]Authentication successful.");
        session->authorized = 1;
        iks_send_header(session->parser, session->server);
    }
    else
    {
        ikspak *pak;
        pak = iks_packet(node);
        iks_filter_packet(session->filter, pak); /* pass for filtering */
    }

    return IKS_OK;
}

/*****************************************************************************/

void axis2_xmpp_worker_on_log(
    void *user_data,
    const char* data,
    size_t size,
    int is_incoming)
{
    axis2_xmpp_session_data_t *session = NULL;
    session = (axis2_xmpp_session_data_t*)user_data;
    char *buf = (char*)AXIS2_MALLOC (session->env->allocator, (size+1));
    memcpy(buf, data, size);
    buf[size] = 0;

    if (is_incoming)
        AXIS2_LOG_INFO(session->env->log, "\n[xmpp server]INCOMING : %s\n", buf);
    else
        AXIS2_LOG_INFO(session->env->log, "\n[xmpp server]OUTGOING : %s\n", buf);
    AXIS2_FREE (session->env->allocator, buf);
}

/*****************************************************************************/

void axis2_xmpp_worker_setup_filter(
    axis2_xmpp_session_data_t* session)
{
    session->filter = iks_filter_new();

    /* Handler for 'message' stanzas */
    iks_filter_add_rule(session->filter, axis2_xmpp_worker_on_message, session,
        IKS_RULE_TYPE, IKS_PAK_MESSAGE,
        IKS_RULE_DONE);

    /* Handler for 'iq' stanzas */
    iks_filter_add_rule(session->filter, axis2_xmpp_worker_on_iq, session,
        IKS_RULE_TYPE, IKS_PAK_IQ,
        IKS_RULE_DONE);

    /* Handler for 'presence' stanzas which give subscription notifications */
    iks_filter_add_rule(session->filter, axis2_xmpp_worker_on_subscription, session,
        IKS_RULE_TYPE, IKS_PAK_S10N,
        IKS_RULE_DONE);
}

/*****************************************************************************/

int axis2_xmpp_worker_on_message(
    void *user_data,
    ikspak *pak)
{
    axis2_xmpp_session_data_t *session = NULL;
    axutil_env_t *env = NULL;
    iks* body_elem = NULL;
    iks* soap_elem = NULL;
    char *soap_str = NULL;
    char *from = NULL;
    char request_uri[500] = "";
    axis2_status_t status = AXIS2_SUCCESS;
    
    session = (axis2_xmpp_session_data_t*)user_data;
    env = session->env;
    /* Serialize the message and pass it up */

    body_elem = iks_find(pak->x, "body"); 
    if (!body_elem)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                        "[xmpp]Failed to extract body of message stanza");
        return IKS_FILTER_EAT;
    }

    soap_elem = iks_child(body_elem);
    if (!soap_elem)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                        "[xmpp]Failed to extract soap envelope"
                        "from message stanza");
        return IKS_FILTER_EAT;
    }

    soap_str = iks_string(iks_stack(soap_elem), soap_elem);
    if (!soap_str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                        "[xmpp]Failed to serialize the soap envelope");
        return IKS_FILTER_EAT;
    }

    snprintf(request_uri, 500, "xmpp://localhost/axis2/services/%s",
           axis2_svc_get_name(session->svc, env));

    from = iks_find_attrib(pak->x, "from");
    status = axis2_xmpp_transport_utils_process_message_server(session->env, session,
        soap_str, from, request_uri);

    /* TODO: Check whether we need to return IKS_HOOK on failure. I think not,
     * because, failure here means the failure of a single request. We should
     * keep running for other requests */

    return IKS_FILTER_EAT; /* no need to pass to other filters */
}

/*****************************************************************************/

int axis2_xmpp_worker_on_presence(
    void *user_data,
    ikspak *pak)
{
    axis2_xmpp_session_data_t *session = NULL;
    axutil_env_t *env = NULL;
    char* presence_str = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    char request_uri[500] = "";

    session = (axis2_xmpp_session_data_t*)user_data;
    env = session->env;
    presence_str = iks_string(iks_stack(pak->x), pak->x);
    if (!presence_str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[xmpp]Failed to serialize the"
                "presence envelope");
        return IKS_FILTER_EAT;
    }

    snprintf(request_uri, 500, "xmpp://localhost/axis2/services/%s",
           axis2_svc_get_name(session->svc, env));

    status = axis2_xmpp_transport_utils_process_presence_server(session->env, session,
        presence_str, request_uri);

    return IKS_FILTER_EAT; /* no need to pass to other filters */
}

/*****************************************************************************/

int axis2_xmpp_worker_on_subscription(
    void *user_data,
    ikspak *pak)
{
    axis2_xmpp_session_data_t *session = NULL;
    axutil_env_t *env = NULL;

    session = (axis2_xmpp_session_data_t*)user_data;
    env = session->env;

    if (pak->subtype == IKS_TYPE_SUBSCRIBED)
    {
        AXIS2_LOG_INFO(env->log, "[xmpp]Subscription successful");
    }

    return IKS_FILTER_EAT; /* no need to pass to other filters */
}


int axis2_xmpp_worker_on_iq(
    void *user_data,
    ikspak *pak)
{
	axis2_xmpp_session_data_t *session = NULL;
    axutil_env_t *env = NULL;

    session = (axis2_xmpp_session_data_t*)user_data;
    env = session->env;

    if (pak->subtype == IKS_TYPE_RESULT)
    {

        if (pak->ns)
        {
            if (!axutil_strcmp (pak->ns, IKS_NS_XMPP_BIND))
            {
                session->bind = 1;
                AXIS2_LOG_INFO(env->log, "[xmpp]Bind iq recieved");
            }
            else if (!axutil_strcmp (pak->ns, IKS_NS_XMPP_SESSION))
            {
                session->session = 1;
                AXIS2_LOG_INFO(env->log, "[xmpp]Session iq recieved");
            }
                
        }
        else if (pak->id)
        {
            if (!axutil_strcmp (pak->id, "auth"))
            {
                session->session = 1;
                AXIS2_LOG_INFO(env->log, "[xmpp]Session iq recieved");
            }
        }
    }

    if (session->session)
        iks_send(session->parser, iks_make_pres(IKS_SHOW_AVAILABLE,
                                                "Online"));


    return IKS_FILTER_EAT; /* no need to pass to other filters */
}

/*****************************************************************************/


