#include <axis2_xmpp_session.h>

AXIS2_EXTERN axis2_xmpp_session_data_t * AXIS2_CALL
axis2_xmpp_session_create (const axutil_env_t *env)

{
    axis2_xmpp_session_data_t *session = NULL;
    session = (axis2_xmpp_session_data_t*)AXIS2_MALLOC(env->allocator,
                                                       sizeof(axis2_xmpp_session_data_t));
    axis2_xmpp_session_data_init (session);
    return session;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_free (
    axis2_xmpp_session_data_t *session, 
    const axutil_env_t *env)
{
    if (session)
    {
        iks_disconnect (session->parser);
    }
    else
        return;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_free_void_arg (void *void_session,
                                  const axutil_env_t *env)
{
    axis2_xmpp_session_data_t *session = NULL;
    session = (axis2_xmpp_session_data_t *)void_session;
    axis2_xmpp_session_free (session, env);
}


AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_reset (axis2_xmpp_session_data_t *session,
                          const axutil_env_t *env)
{
		session->in_msg = 0;
        session->response = NULL;
}

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





