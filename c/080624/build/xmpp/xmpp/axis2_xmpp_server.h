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

#ifndef AXIS2_XMPP_SERVER_H
#define AXIS2_XMPP_SERVER_H

/**
 * @defgroup axis2_xmpp_server xmpp server
 * @ingroup axis2_core_trans_xmpp
 * @{
 */

/**
  * @file axis2_xmpp_server.h
  * @brief axis2 XMPP Server implementation
  */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>
#include <axis2_transport_receiver.h>

#include <axis2_xmpp_worker.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int axis2_xmpp_socket_read_timeout = 0;

    AXIS2_EXTERN axis2_transport_receiver_t *AXIS2_CALL
    axis2_xmpp_server_create (
        const axutil_env_t *env,
        const axis2_char_t *repo,
        const int port,
        int use_sasl,
        int use_tls,
        int subscribe);

    axis2_status_t AXIS2_CALL
    axis2_xmpp_server_stop(
        axis2_transport_receiver_t *server,
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_XMPP_SERVER_H */
