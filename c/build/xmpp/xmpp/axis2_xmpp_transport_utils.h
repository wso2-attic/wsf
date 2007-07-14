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

#ifndef AXIS2_XMPP_TRANSPORT_UTILS_H
#define AXIS2_XMPP_TRANSPORT_UTILS_H

/**
 * @ingroup axis2_core_transport_xmpp
 * @{
 */


/**
  * @file axis2_xmpp_transport_utils.h
  * @brief axis2 XMPP Transport Utility class
  */

#include <axis2_const.h>
#include <axutil_stream.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_hash.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axiom.h>
#include <axiom_soap.h>

#include <axis2_xmpp_session.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /**
     * @param env pointer to environment struct
     * @param data struct holding XMPP session data
     * @param soap_msg serialized soap message
     * @param from JID of requesting client
        */

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

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_xmpp_transport_utils_process_presence_client(
        const axutil_env_t *env,
        axis2_xmpp_session_data_t *session,
        axis2_char_t *presence_str,
        axis2_char_t *request_uri);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* AXIS2_XMPP_TRANSPORT_UTILS_H */
