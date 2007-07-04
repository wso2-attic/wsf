#include <axis2_xmpp_client.h>

static void 
xmpp_process_msg (axis2_xmpp_session_data_t *session, iks *node);

int axis2_xmpp_client_on_data(
    void* user_data,
    int type,
    iks* node)
{
    axis2_xmpp_session_data_t *session = (axis2_xmpp_session_data_t*)user_data;
    switch(type)
    {
        case IKS_NODE_START:
        {
            return axis2_xmpp_client_on_start_node(session, node);
        }
        break;
        case IKS_NODE_NORMAL:
        {
            return axis2_xmpp_client_on_normal_node(session, node);
        }
        break;
        case IKS_NODE_STOP:
        {
            printf("stop node: server disconnected");
            return IKS_HOOK;
        }
        break;

        case IKS_NODE_ERROR:
        {
            printf("error node: stream error");
            return IKS_HOOK;
        }
        break;

        default:
        {
            printf("unknown node");
            return IKS_HOOK;
        }
    }

    if (node)
        iks_delete(node);

    return IKS_OK;
}


int axis2_xmpp_client_on_start_node(
    axis2_xmpp_session_data_t *session,
    iks* node)
{
    if ( session->use_tls && (!iks_is_secure(session->parser)) )
    {
        iks_start_tls(session->parser);
        return IKS_OK;
    }

    if (!session->use_sasl) /* basic authentication */
    {
        iks *x;
        session->bind = 1;
        session->session = 1;
        session->authorized = 1;
        session->session_id = iks_find_attrib(node, "id"); /* get id given from svr */
        x = iks_make_auth (session->jid, session->password, session->session_id);
        iks_insert_attrib (x, "id", "auth");
        iks_send (session->parser, x);
        iks_delete (x);
    }
    return IKS_OK;
}

int axis2_xmpp_client_on_normal_node(
    axis2_xmpp_session_data_t *session,
    iks* node)
{
    if (strcmp("stream:features", iks_name(node)) == 0) /* features node */
    {
        session->features = iks_stream_features (node); /* save features */

        if (session->use_sasl)
        {
            if (session->use_tls && !iks_is_secure (session->parser))
            {
                return IKS_HOOK;
            }

            if (session->authorized)
            {
                /* Bind a resource if required */
                xmpp_process_msg (session, node);
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
            }
        }
        else
        {
            if (strcmp("stream:features", iks_name(node)) == 0) /* features node */
            {
                if (session->authorized)
                    xmpp_process_msg (session, node);

            }
            iks_send(session->parser, iks_make_pres(IKS_SHOW_AVAILABLE,
                                                    "Online"));
            iks_recv (session->parser, -1);
        }
    }
    else if (strcmp("failure", iks_name(node)) == 0)
    {
        AXIS2_LOG_ERROR(session->env->log, AXIS2_LOG_SI, "Authentication failed.");
        return IKS_HOOK;
    }
    else if (strcmp("success", iks_name(node)) == 0)
    {
        AXIS2_LOG_INFO(session->env->log, "Authentication successful.");
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

/********************************************************************** */
void axis2_xmpp_client_on_log(
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
        AXIS2_LOG_INFO(session->env->log, "\n[xmpp client]INCOMING : %s\n", buf);
    else
        AXIS2_LOG_INFO(session->env->log, "\n[xmpp client]OUTGOING : %s\n", buf);
    AXIS2_FREE (session->env->allocator, buf);
}


/*****************************************************************************/
void axis2_xmpp_client_setup_filter(
    axis2_xmpp_session_data_t* session)
{
    session->filter = iks_filter_new();

    iks_filter_add_rule(session->filter, axis2_xmpp_client_on_iq, session,
                        IKS_RULE_TYPE, IKS_PAK_IQ,
                        IKS_RULE_DONE);
    /* Handler for 'message' stanzas */
    iks_filter_add_rule(session->filter, axis2_xmpp_client_on_message, session,
                        IKS_RULE_TYPE, IKS_PAK_MESSAGE,
                        IKS_RULE_DONE);
}
/*****************************************************************************/

int axis2_xmpp_client_on_message(
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

    body_elem = iks_find(pak->x, "body"); /* extract the body of message */
    if (!body_elem)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to extract body of "
                        "message stanza");
        return IKS_FILTER_EAT;
    }

    soap_elem = iks_child(body_elem);
    if (!soap_elem)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to extract soap envelope"
                        "from message stanza");
        return IKS_FILTER_EAT;
    }

    soap_str = iks_string(iks_stack(soap_elem), soap_elem);
    if (!soap_str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to serialize the soap "
                        "envelope");
        return IKS_FILTER_EAT;
    }

    snprintf(request_uri, 500, "xmpp://localhost/axis2/services/%s",
             axis2_svc_get_name(session->svc, env));

    from = iks_find_attrib(pak->x, "from");
    status = axis2_xmpp_transport_utils_process_message_client(session->env, session,
                                                               soap_str, from, request_uri);

    /* TODO: Check whether we need to return IKS_HOOK on failure. I think not,
     * because, failure here means the failure of a single request. We should
     * keep running for other requests */
	session->in_msg = 1;

    return IKS_FILTER_EAT; /* no need to pass to other filters */
}

/*****************************************************************************/

int axis2_xmpp_client_on_presence(
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
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to serialize the "
                        "presence envelope");
        return IKS_FILTER_EAT;
    }

    snprintf(request_uri, 500, "xmpp://localhost/axis2/services/%s",
             axis2_svc_get_name(session->svc, env));

    status = axis2_xmpp_transport_utils_process_presence_client(session->env, 
                                                                session,
                                                                presence_str, 
                                                                request_uri);

    return IKS_FILTER_EAT; /* no need to pass to other filters */
}

/*****************************************************************************/

int axis2_xmpp_client_on_subscription(
    void *user_data,
    ikspak *pak)
{
    axis2_xmpp_session_data_t *session = NULL;
    axutil_env_t *env = NULL;

    session = (axis2_xmpp_session_data_t*)user_data;
    env = session->env;

    if (pak->subtype == IKS_TYPE_SUBSCRIBED)
    {
        AXIS2_LOG_INFO(env->log, "Subscription successful");
    }

    return IKS_FILTER_EAT; /* no need to pass to other filters */
}


int axis2_xmpp_client_on_iq(
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
            if (!axutil_strcmp (pak->ns, "urn:ietf:params:xml:ns:xmpp-bind"))
            {
                session->bind = 1;
                AXIS2_LOG_INFO(env->log, "Bind iq recieved");
            }
            else if (!axutil_strcmp (pak->ns, "urn:ietf:params:xml:ns:xmpp-session"))
            {
                session->session = 1;
                AXIS2_LOG_INFO(env->log, "Session iq recieved");
            }
                
        }
        else if (pak->id)
        {
            if (!axutil_strcmp (pak->id, "auth"))
            {
                session->session = 1;
                AXIS2_LOG_INFO(env->log, "Session iq recieved");
            }
        }
    }

    if (session->bind && session->session)
        iks_send(session->parser, iks_make_pres(IKS_SHOW_AVAILABLE,
                                                "Online"));

    return IKS_FILTER_EAT; /* no need to pass to other filters */
}

static void 
xmpp_process_msg (axis2_xmpp_session_data_t *session, iks *node)
{
    iks *t = NULL;
    session->features = iks_stream_features (node); /* save features */
    if (session->features & IKS_STREAM_BIND)
    {
        t = iks_make_resource_bind (session->jid);
        iks_send (session->parser, t);
        iks_delete (t);
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

        if (axutil_strcmp(session->subscribe_type, AXIS2_XMPP_SUB_TYPE_USER) == 0)
        {
            iks_send(session->parser, iks_make_s10n(IKS_TYPE_SUBSCRIBE,
                                                    session->subscribe_to, ""));
        }
        else if (axutil_strcmp(session->subscribe_type, AXIS2_XMPP_SUB_TYPE_ROOM) == 0)
        {
            axis2_char_t *id = (axis2_char_t *)axutil_uuid_gen(session->env);

            iks *x = iks_make_pres(IKS_SHOW_AVAILABLE, "");
            iks_insert_attrib(x, "to", session->subscribe_to);
            iks_insert_attrib(x, "id", id);
            iks_send(session->parser, x);
            AXIS2_FREE(session->env->allocator, id);
        }
        else
        {
            AXIS2_LOG_ERROR(session->env->log, AXIS2_LOG_SI,
                            "Unknown subscription type. No subscription done");
        }
    }

}
