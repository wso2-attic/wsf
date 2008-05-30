/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WSF_UTIL_H
#define WSF_UTIL_H

#include <axutil_env.h>
#include <axiom.h>
#include <axis2_op_client.h>
#include <axis2_svc_client.h>
#include <axis2_options.h>
#include "wsf_common.h"
#include <axiom_soap_body.h>

#include <ruby.h>

typedef struct wsservice
{
    wsf_svc_info_t *svc_info;
    axutil_env_t *ws_env_svr;

    char *request_uri;

    VALUE ht_actions;
    VALUE ht_ops_to_funcs;
    VALUE ht_ops_to_mep;
    VALUE ht_op_params;
    VALUE ht_classes;

    axis2_char_t *temp_ops_class;

} wsservice_t;

axiom_node_t *wsf_util_read_payload (
    axiom_xml_reader_t * reader,
    const axutil_env_t * env);

axis2_char_t *wsf_util_get_soap_msg_from_op_client (
    axis2_op_client_t * op_client,
    axutil_env_t * env,
    axis2_wsdl_msg_labels_t message_label);

axis2_char_t *wsf_util_get_http_headers_from_op_client (
    axis2_op_client_t * op_client,
    axutil_env_t * env,
    axis2_wsdl_msg_labels_t message_label);

char *wsf_util_generate_svc_name_from_uri (
    char *req_uri,
    wsf_svc_info_t * svc_info,
    axutil_env_t * env);

void wsf_util_create_svc_from_svc_info (
    wsf_svc_info_t * svc_info,
    axutil_env_t * env);


void wsf_util_create_op_and_add_to_svc (
    wsf_svc_info_t * svc_info,
    char *options,
    axutil_env_t * env,
    char *op_name,
    VALUE meps);

int wsf_util_engage_module (
    axis2_conf_t * conf,
    axis2_char_t * module_name,
    axutil_env_t * env,
    axis2_svc_t * svc);

wsf_svc_info_t *wsf_svc_info_create ();

void wsf_svc_info_free (
    wsf_svc_info_t * svc_info,
    axutil_env_t * env);

void wsf_ruby_req_info_init (wsf_req_info_t * req_info);

void wsf_ruby_req_info_cleanup (
    wsf_req_info_t * req_info,
	axutil_env_t *env);

void wsf_util_pack_attachments (
	axutil_env_t * env,
    axiom_node_t * payload_node,
    VALUE attach_ht,
    int enable_mtom,
    char *default_cnt_type);

void wsf_util_unpack_attachments (
	const axutil_env_t * env,
	axiom_node_t * payload_node,
	VALUE* message);

char *wsf_util_serialize_om (
    const axutil_env_t * env,
    axiom_node_t * ret_node);

/*
xmlDocPtr wsf_util_serialize_om_to_doc (
    const axutil_env_t * env,
    axiom_node_t * ret_node);

xmlNodePtr wsf_util_get_xml_node (
    zval * node TSRMLS_DC);
*/

axutil_env_t *wsf_env_create (
    axis2_char_t * logpath);

axutil_env_t *wsf_env_create_svr (
    axis2_char_t *logpath,
    int loglevel);

void wsf_env_free (
    axutil_env_t * env);

/*
axiom_node_t *wsf_util_construct_header_node (
    const axutil_env_t * env,
    zval * header TSRMLS_DC);

char *wsf_util_read_file_to_buffer (
    char *filename);*/

axiom_node_t *wsf_util_deserialize_buffer (
    const axutil_env_t * env,
    char *buffer);

/*void wsf_util_set_soap_fault (
    zval * this_ptr,
    char *fault_code_ns,
    char *fault_code,
    char *fault_reason,
    char *fault_role,
    zval * fault_detail,
    char *name TSRMLS_DC);

void wsf_util_handle_soap_fault(
	zval *fault_zval,
	axutil_env_t *env,
	axiom_node_t *fault_node,
	int soap_version TSRMLS_DC);
*/

void wsf_util_process_ws_service_operations_and_actions(VALUE self);

void wsf_util_engage_modules_to_svc(
    axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    wsf_svc_info_t *svc_info);


void wsf_util_process_ws_service_classes(VALUE self);

void
wsf_evaluate_security_token_and_insert_to_hash(
    axutil_env_t* env,
    VALUE security_token,
    axutil_hash_t* hash);

void
wsf_evaluate_policy_options_and_insert_to_hash(
    axutil_env_t* env,
    VALUE policy,
    axutil_hash_t* hash);

void
wsf_evaluate_policy_and_insert_to_hash(
    axutil_env_t* env,
    VALUE policy,
    axutil_hash_t* hash);

#endif /* WSF_UTIL_H */
