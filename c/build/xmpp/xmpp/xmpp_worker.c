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
#include <axis2_xmpp_transport_utils.h>
#include <axis2_xmpp_worker.h>

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

int axis2_xmpp_worker_on_data(
    void* user_data,
    int type,
    iks* node);

int axis2_xmpp_worker_on_start_node(
    axis2_xmpp_session_data_t *session,
    iks* node);

int axis2_xmpp_worker_on_normal_node(
    axis2_xmpp_session_data_t *session,
    iks* node);

void axis2_xmpp_worker_on_log(
    void *user_data,
    const char* data,
    size_t size,
    int is_incoming);

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


    thread_env = axutil_init_thread_env(env);

    AXIS2_PARAM_CHECK(thread_env->error, worker, AXIS2_FALSE);

    impl = (axis2_xmpp_worker_impl_t*)worker;
    impl->session->env = thread_env;

    printf("Starting %s" , impl->session->id_str);
/*     AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Starting %s",impl->session->id_str); */
    /* Create an iks parser and connect to the XMPP server */
    /* We pass the session as user data, which we can access inside iksemel
     * callbacks */

    impl->session->parser = iks_stream_new(IKS_NS_CLIENT, (void*)impl->session,
        axis2_xmpp_worker_on_data);
/*     AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s create new stream",impl->session->id_str); */
    if (!impl->session->parser)
    {
        AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, "Failed to create XMPP parser");
        AXIS2_ERROR_SET(thread_env->error, AXIS2_XMPP_PARSER_CREATE_FAILED,
            AXIS2_FAILURE);
        return AXIS2_FAILURE; /* exit thread */
    }

    iks_set_log_hook(impl->session->parser, axis2_xmpp_worker_on_log);
/*     AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s log hook registered",impl->session->id_str); */
    axis2_xmpp_worker_setup_filter(impl->session);

    /* Create an iksid using the jid supplied. Give "Default" as the resource
     * if a resource is not given */

/*     AXIS2_LOG_DEBUG(thread_env->log, AXIS2_LOG_SI, "creating session id string %s", impl->session->id_str); */

    impl->session->jid = iks_id_new(iks_parser_stack(impl->session->parser), 
                                    impl->session->id_str);
/*     AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s get new jid iks_id_new",impl->session->id_str); */
    if ( (!impl->session->jid->server) || (!impl->session->jid->user))
    {
        AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, "Server and user name "
            "cannot be NULL in JID");
        return AXIS2_FAILURE; /* exit thread */
    }

    impl->session->server = impl->session->jid->server;
    impl->session->user = impl->session->jid->user;

    if (!impl->session->jid->resource) /* no resource given */
    {
        tmp = iks_malloc(strlen(impl->session->server) + strlen(impl->session->user) + 7 + 3);
        sprintf(tmp, "%s@%s/%s", impl->session->user, impl->session->server, "Default");
        impl->session->jid = iks_id_new(iks_parser_stack(impl->session->parser), tmp);
        iks_free(tmp);
    }

    /* Now connect to the XMPP server */
    ret = iks_connect_tcp(impl->session->parser, impl->session->server,
        IKS_JABBER_PORT);
/*     AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s iks_connect_tcp",impl->session->id_str); */
    if (ret != IKS_OK)
    {
        AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, "Failed to connect to XMPP server. "
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
/*         axutil_thread_mutex_lock (impl->session->mutex); */
/*         AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s iks_recv mutex locked",impl->session->id_str); */
        ret = iks_recv(impl->session->parser, -1);
/*         AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s iks_recv",impl->session->id_str); */
/*         axutil_thread_mutex_unlock (impl->session->mutex); */
/*         AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s iks_recv mutex unlocked",impl->session->id_str); */
        if (ret != IKS_OK)
        {
            switch(ret)
            {
            case IKS_HOOK:
                AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, "Hook function "
                    "returned an error");
	            return AXIS2_FAILURE; /* exit thread */

            case IKS_NET_TLSFAIL:
                AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, "TLS handshake"
                    "failed");
	            return AXIS2_FAILURE; /* exit thread */

            default:
                AXIS2_LOG_ERROR(thread_env->log, AXIS2_LOG_SI, "I/O error");
	            return AXIS2_FAILURE; /* exit thread */
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
/*     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s on_data_node",session->id_str); */
    switch(type)
    {
        case IKS_NODE_START:
        {
/*             AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s iks node start",session->id_str); */
            return axis2_xmpp_worker_on_start_node(session, node);
        }
        break;
        case IKS_NODE_NORMAL:
        {
/*             AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s iks node normal",session->id_str); */
            return axis2_xmpp_worker_on_normal_node(session, node);
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
/*             AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s error node:stream error",session->id_str); */
            return IKS_HOOK;
        }
        break;

        default:
        {
/*             AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s unknow node",session->id_str); */
            printf("unknown node");
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
/*     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s inside start node",session->id_str); */
    if ( session->use_tls && (!iks_is_secure(session->parser)) )
    {
/*         AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s on start node tls",session->id_str); */
        iks_start_tls(session->parser);
        return IKS_OK;
    }

    if (!session->use_sasl) /* basic authentication */
    {
/*         AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s basic authentication",session->id_str); */
        iks *x;
        session->session_id = iks_find_attrib(node, "id"); /* get id given from svr */
        x = iks_make_auth (session->jid, session->password, session->session_id);
        iks_insert_attrib (x, "id", "auth");
        iks_send (session->parser, x);
        iks_delete (x);  
    }
    return IKS_OK;
}

/*****************************************************************************/

int axis2_xmpp_worker_on_normal_node(
    axis2_xmpp_session_data_t *session,
    iks* node)
{
    iks *t = NULL;
/*     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s inside normal node",session->id_str); */
    if (strcmp("stream:features", iks_name(node)) == 0) /* features node */
    {
        session->features = iks_stream_features (node); /* save features */

        if (session->use_sasl)
        {
/*             AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s use sasl enabled",session->id_str); */
            if (session->use_tls && !iks_is_secure (session->parser))
            {
                return IKS_HOOK;
            }

            if (session->authorized)
            {
/*                 AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s session authorized",session->id_str); */
                /* Bind a resource if required */
                if (session->features & IKS_STREAM_BIND)
                {
/*                     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s going to resource bind",session->id_str); */
                    t = iks_make_resource_bind (session->jid);
                    iks_send (session->parser, t);
                    iks_delete (t);
/*                     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s Resource binded",session->id_str); */
                }

                /* Send a session if required */
                if (session->features & IKS_STREAM_SESSION)
                {
/*                     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s going to send session",session->id_str); */
                    t = iks_make_session ();
                    iks_insert_attrib (t, "id", "auth");
                    iks_send (session->parser, t);
                    iks_delete (t);
/*                     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s Session sent",session->id_str); */
                }

                /* Say that we are online */
                iks_send(session->parser, iks_make_pres(IKS_SHOW_AVAILABLE,
                    "Online"));
/*                 AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s Send presance",session->id_str); */

                /* Subscribe if the service is configured to do so */
                if ( (session->subscribe) && (session->subscribe_to) )
                {
                    /* Check whether the type of subscription is user or room
                     * and send the subscription request accordingly */

                    if (axutil_strcmp(session->subscribe_type, AXIS2_XMPP_SUB_TYPE_USER) == 0)
                    {
                        iks_send(session->parser, iks_make_s10n(IKS_TYPE_SUBSCRIBE,
                            session->subscribe_to, ""));
/*                         AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s send subcription to user",session->id_str); */
                    }
                    else if (axutil_strcmp(session->subscribe_type, AXIS2_XMPP_SUB_TYPE_ROOM) == 0)
                    {
                        axis2_char_t *id = axutil_uuid_gen(session->env);

                        iks *x = iks_make_pres(IKS_SHOW_AVAILABLE, "");
                        iks_insert_attrib(x, "to", session->subscribe_to);
                        iks_insert_attrib(x, "id", id);
                        iks_send(session->parser, x);
/*                         AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s send subscription to room",session->id_str); */
                        AXIS2_FREE(session->env->allocator, id);
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(session->env->log, AXIS2_LOG_SI,
                            "Unknown subscription type. No subscription done");
                    }
                }

            }
            else
            {
                if (session->features & IKS_STREAM_SASL_MD5)
                {
/*                     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s sasl md5",session->id_str); */
                    iks_start_sasl(session->parser, IKS_SASL_DIGEST_MD5,
                        session->jid->user, session->password);
                }
                else if (session->features & IKS_STREAM_SASL_PLAIN)
                {
/*                     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s sasl plain",session->id_str); */
                    iks_start_sasl (session->parser, IKS_SASL_PLAIN,
                        session->jid->user, session->password);
                }
            }
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
/*         AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s Authentication successful",session->id_str); */
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
    char *buf = (char*)malloc(size+1);
    char* svc_name = NULL;

    session = (axis2_xmpp_session_data_t*)user_data;
    svc_name = (char*)axis2_svc_get_name(session->svc, session->env);

    memcpy(buf, data, size);
    buf[size] = 0;
    if (is_incoming)
        printf("\nINCOMING [%s]: %s\n", svc_name, buf);
    else
        printf("\nOUTGOING [%s]: %s\n", svc_name, buf);
}

/*****************************************************************************/

void axis2_xmpp_worker_setup_filter(
    axis2_xmpp_session_data_t* session)
{
    session->filter = iks_filter_new();
/*     AXIS2_LOG_DEBUG(session->env->log, AXIS2_LOG_SI, " %s setting up filter",session->id_str); */
    /* Handler for 'message' stanzas */
    iks_filter_add_rule(session->filter, axis2_xmpp_worker_on_message, session,
        IKS_RULE_TYPE, IKS_PAK_MESSAGE,
        IKS_RULE_DONE);

    /* Handler for 'presence' stanzas */
    iks_filter_add_rule(session->filter, axis2_xmpp_worker_on_presence, session,
        IKS_RULE_TYPE, IKS_PAK_PRESENCE,
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
/*     AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s inside on message",session->id_str); */
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
    status = axis2_xmpp_transport_utils_process_message(session->env, session,
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
/*     AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, " %s inside on presance",session->id_str); */
    presence_str = iks_string(iks_stack(pak->x), pak->x);
    if (!presence_str)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to serialize the "
                "presence envelope");
        return IKS_FILTER_EAT;
    }

    snprintf(request_uri, 500, "xmpp://localhost/axis2/services/%s",
           axis2_svc_get_name(session->svc, env));

    status = axis2_xmpp_transport_utils_process_presence(session->env, session,
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
        AXIS2_LOG_INFO(env->log, "Subscription successful");
    }

    return IKS_FILTER_EAT; /* no need to pass to other filters */
}

/*****************************************************************************/

void AXIS2_CALL
axis2_xmpp_session_data_init (
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

    data->env = NULL;
    data->conf_ctx = NULL;
    data->svc = NULL;
}
