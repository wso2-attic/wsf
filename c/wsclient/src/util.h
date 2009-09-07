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

#ifndef WSCLIENT_UTIL_H
#define WSCLIENT_UTIL_H
#include <axis2_util.h>
#include <axiom.h>
#include <axis2_client.h>
#include <axis2_http_transport_sender.h>

#define array_sizeof(x) (sizeof (x) / sizeof ((x)[0]))

axiom_node_t *
wsclient_payload (
    const axutil_env_t *env, 
    char *input_buffer);

axiom_node_t *
wsclient_soap_header (
    const axutil_env_t *env, 
    char *input_buffer);

axis2_char_t *
wsclient_get_password (const axutil_env_t *env, 
					   const axis2_char_t *username,
					   axis2_char_t *password_file_name);

axis2_status_t
wsclient_soap_out (const axutil_env_t *env,
				   axis2_svc_client_t *svc_client,
				   int soap_out);

axis2_status_t
wsclient_set_attachment (const axutil_env_t *env,
						 axiom_node_t *payload,
						 axis2_char_t *base_dir,
						 int is_mtom_enabled);

axis2_status_t
wsclient_get_attachment (const axutil_env_t *env,
						 axiom_node_t *node,
						 axis2_char_t *base_dir,
						 int is_mtom_enabled);

axis2_char_t *
wsclient_get_relative_path (const axutil_env_t *env,
							axis2_char_t *pwd,
							axis2_char_t *guest);

axis2_char_t *
wsclient_content_type (const axutil_env_t *env,
					   axis2_char_t *content_type);

axis2_status_t 
wsclient_output_http_headers (const axutil_env_t *env,
							  axis2_svc_client_t *svc_client,
							  axis2_char_t *file_name);

axis2_status_t
wsclient_set_https_transport_parameretes (const axutil_env_t *env,
										  axis2_svc_client_t *svc_client);

#endif /* WSCLIENT_UTIL_H */
