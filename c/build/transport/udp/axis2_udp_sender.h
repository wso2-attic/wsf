
/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXIS2_UDP_TRANSPORT_SENDER_H
#define AXIS2_UDP_TRANSPORT_SENDER_H

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_msg_ctx.h>
#include <axis2_conf_ctx.h>
#include <axis2_transport_out_desc.h>
#include <axis2_transport_sender.h>
#include <axiom.h>
#include <axiom_soap_envelope.h>
#include <axutil_network_handler.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
	 * Creates a udp transport sender. 
     * @param env pointer to environment struct 
     */
    AXIS2_EXTERN axis2_transport_sender_t *AXIS2_CALL
    axis2_udp_ender_create(
        const axutil_env_t * env);

	AXIS2_EXTERN axis2_status_t AXIS2_CALL
	axis2_udp_sender_set_socket(
		axis2_transport_sender_t * transport_sender,
		const axutil_env_t * env,
		axis2_socket_t socket);

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_UDP_TRANSPORT_SENDER_H */

