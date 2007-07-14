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

#ifndef AXIS2_XMPP_SESSION_H
#define AXIS2_XMPP_SESSION_H

/**
 * @defgroup axis2_xmpp_session xmpp session
 * @ingroup axis2_core_trans_xmpp
 * @{
 */

/**
 * @file axis2_xmpp_session.h
 * @brief axis2 XMPP session
 */

#include <iksemel.h>

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>


#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct axis2_xmpp_session_data
    {
        char* id_str;           /* JID in string form */
        axis2_char_t *server;   /* XMPP server name */
        axis2_char_t *user;     /* User ID */
        axis2_char_t *password;

        char* subscribe_to;     /* JID to subscribe to receive presence */
        char* subscribe_type;   /* Type of the JID to subscribe (user|room) */
        char* subscribe_op;     /* Operation to recv presence notifications */

        char* session_id;       /* Session ID returned by server */
        iksparser *parser;      /* iksemel parser instance */
        iksfilter *filter;      /* iksemel filter */
        iksid *jid;             /* JID in iks form */

        int authorized;         /* Whether session authorized or not */
        int features;           /* Stream features */
        int use_sasl;           /* Whether to SASL or not */
        int use_tls;            /* Whether to use TLS or not */
        int subscribe;          /* Whether to subscribe for events or not */
		int bind;
		int in_msg;
        int session;

        axutil_env_t *env;
        axis2_conf_ctx_t* conf_ctx;
        axis2_svc_t *svc;
        axis2_msg_ctx_t *response;
    }axis2_xmpp_session_data_t;


AXIS2_EXTERN axis2_xmpp_session_data_t * AXIS2_CALL
axis2_xmpp_session_create (
    const axutil_env_t *env);

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_free (
    axis2_xmpp_session_data_t *session, 
    const axutil_env_t *env);

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_free_void_arg (
    void *void_session,
    const axutil_env_t *env);

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_reset (
    axis2_xmpp_session_data_t *session,
    const axutil_env_t *env);

AXIS2_EXTERN void AXIS2_CALL
axis2_xmpp_session_data_init (
    axis2_xmpp_session_data_t *data);

#ifdef __cplusplus
}
#endif

#endif /*AXIS2_XMPP_SESSION_DATA_T*/
