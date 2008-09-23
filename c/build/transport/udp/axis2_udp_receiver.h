
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

#ifndef AXIS2_UDP_SERVER_H
#define AXIS2_UDP_SERVER_H


#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>
#include <axis2_transport_receiver.h>
#include <axutil_network_handler.h>

#ifdef __cplusplus
extern "C"
{
#endif
	
	/* 
	 * Create the receiver.
	 * @param env pointer to axutil_env struct
	 * @param file configuration file name
	 * @param repo path to the repository location
	 * @param port port to listen
	 * @param multicast_group multicast group to listen on
	 */
    AXIS2_EXTERN axis2_transport_receiver_t *AXIS2_CALL
	axis2_udp_receiver_create(
		const axutil_env_t * env,
		const axis2_char_t * repo,
		const int port,
		axis2_char_t *multicast_group);
	
	/* 
	 * Create the receiver with the configuration file.
	 * @param env pointer to axutil_env struct
	 * @param file configuration file name
	 * @param port port to listen 
	 */
	AXIS2_EXTERN axis2_transport_receiver_t *AXIS2_CALL
	axis2_udp_receiver_create_with_file(
    	const axutil_env_t * env,
    	const axis2_char_t * file,
    	const int port);

	/* Stop the UDP receiver 
	 * @param receiver axis2_transport receiver
	 * @param env pointer to axutil_env struct
	 */
	AXIS2_EXTERN axis2_status_t AXIS2_CALL
	axis2_udp_receiver_stop(
		axis2_transport_receiver_t * receiver,
		const axutil_env_t * env);
	
	/* Set the receiving socket. Receiver will directly use this socket for listening. 
	 * A binding to specific port won't happen. 
	 * @param receiver axis2_transport receiver
	 * @param env pointer to axutil_env struct
	 * @param socket datagram socket
	 */
	AXIS2_EXTERN axis2_status_t AXIS2_CALL
	axis2_udp_receiver_set_socket(
		axis2_transport_receiver_t * receiver,
		const axutil_env_t * env,
		axis2_socket_t socket);
#ifdef __cplusplus
}
#endif

#endif  