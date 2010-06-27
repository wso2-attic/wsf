/*
 * Copyright 2005,2010 WSO2, Inc. http://wso2.com
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
* Reads the complete XML stream using the provided XML reader and returns
* an axiom node. The builder used to construct is freed using axiom_stax_builder_free_self
* @param reader, XML reader
* @param env,    environment
* @returns axiom_node on success, NULL otherwise
*/
axiom_node_t *
wsf_util_read_payload (
    axiom_xml_reader_t * reader,
    const axutil_env_t * env);

/**
* Obtains the soap envelope from op client and serializes it to a string
* @param op_client, axis2_op_client_t struct
* @param env, environment
* @param message_label,  axis2_wsdl_msg_labels_t enum
* @returns serialize soap envelope string on success, NULL otherwise
*/
axis2_char_t *
wsf_util_get_soap_msg_from_op_client (
    axis2_op_client_t * op_client,
    axutil_env_t * env,
    axis2_wsdl_msg_labels_t message_label);

/**
* Extract the received HTTP headers from op client 
* @param op_client, 
* @param env, 
* @param message_label, 
* @returns HTTP Headers string on success, NULL Otherwise
*/
axis2_status_t
wsf_util_get_http_headers_from_op_client (
    axis2_op_client_t * op_client,
    const axutil_env_t * env,
	zval *return_val,
    axis2_wsdl_msg_labels_t message_label);

/**
* Generate a unique service name using the path. It also extract location string
* The string part after ".php". Eg http://localhost/sample.php/<location str>
* @param req_uri, the request uri
* @param svc_info, svc_info struct
* @param env, environment
* @returns generated service name string on success, NULL Otherwise
*/
char *
wsf_util_generate_svc_name_from_uri_and_set_loc_str (
    char *req_uri,
    wsf_svc_info_t * svc_info,
    axutil_env_t * env);

/**
* 
* @param svc_info, 
* @param TSRMLS_DC, 
*/
void 
wsf_util_create_svc_from_svc_info (
    wsf_svc_info_t * svc_info,
    axutil_env_t * env TSRMLS_DC);


/**
* 
* @param svc_info, 
* @param env, 
* @param op_name, 
*/
void 
wsf_util_create_op_and_add_to_svc (
    wsf_svc_info_t * svc_info,
    axutil_env_t * env,
    char *op_name,
    HashTable * meps TSRMLS_DC);

/**
* 
* @param conf, 
* @param module_name, 
* @param env, 
* @param svc, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int 
wsf_util_engage_module (
    axis2_conf_t * conf,
    axis2_char_t * module_name,
    const axutil_env_t * env,
    axis2_svc_t * svc);

/**
* 
*/
wsf_svc_info_t *
wsf_svc_info_create ();

void 
wsf_svc_info_free (
    wsf_svc_info_t * svc_info,
    axutil_env_t * env);

/**
* 
* @param req_info, 
*/
void 
wsf_request_info_init (
	wsf_request_info_t * req_info);

/**
* 
* @param response_info, 
*/
void 
wsf_response_info_init(
	wsf_response_info_t *response_info);

/**
* 
* @param response_info, 
* @param env, 
*/
void 
wsf_response_info_cleanup (
    wsf_response_info_t * response_info,
	axutil_env_t *env);

/**
* 
* @param env, 
* @param enable_mtom, 
* @param enable_swa, 
* @param payload_node, 
* @param attach_ht, 
*/
void 
wsf_util_set_attachments_with_cids (
    const axutil_env_t * env,
    int enable_mtom,
    int enable_swa,
    axiom_node_t * payload_node,
    HashTable * attach_ht,
    char *default_cnt_type TSRMLS_DC);

/**
* 
* @param env, 
* @param payload_node, 
* @param cid2str, 
*/
int 
wsf_util_get_attachments (
    const axutil_env_t * env,
    axiom_node_t * payload_node,
    zval * cid2str,
    zval * cid2contentType TSRMLS_DC);

/**
* 
* @param env, 
* @param ret_node, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
char *
wsf_util_serialize_om (
    const axutil_env_t * env,
    axiom_node_t * ret_node);

/**
* 
* @param logpath, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
axutil_env_t *
wsf_env_create (
    axis2_char_t * logpath);

/**
* 
* @param logpath, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
axutil_env_t *
wsf_env_create_svr (
    axis2_char_t * logpath);

/**
* 
* @param env, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void 
wsf_env_free (
    axutil_env_t * env);

/**
* 
* @param env, 
* @param parent, 
* @param soap_uri, 
* @param soap_version, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
axiom_node_t *
wsf_util_construct_header_node (
    const axutil_env_t * env,
    axiom_node_t *parent,
	axis2_char_t *soap_uri,
	int soap_version,
    zval * header TSRMLS_DC);

/**
* 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
char *
wsf_util_read_file_to_buffer (
    char *filename TSRMLS_DC);

/**
* 
* @param env, 
* @param buffer, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
axiom_node_t *
wsf_util_deserialize_buffer (
    const axutil_env_t * env,
    char *buffer);

/**
* 
* @param this_ptr, 
* @param fault_code_ns, 
* @param fault_code, 
* @param fault_reason, 
* @param fault_role, 
* @param fault_detail, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void 
wsf_util_set_soap_fault (
    zval * this_ptr,
    char *fault_code_ns,
    char *fault_code,
    char *fault_reason,
    char *fault_role,
    zval * fault_detail,
    char *name TSRMLS_DC);

/**
* 
* @param fault_zval, 
* @param env, 
* @param fault_node, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void 
wsf_util_handle_soap_fault(
	zval *fault_zval,
	axutil_env_t *env,
	axiom_node_t *fault_node,
	int soap_version TSRMLS_DC);

/**
* 
* @param svc_client, 
* @param env, 
* @param module_name, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int 
wsf_util_is_module_engaged_to_svc_client(
	const axis2_svc_client_t *svc_client,
	axutil_env_t *env,
	char *module_name);

/**
* 
* @param env, 
* @param conf_ctx, 
* @param svc_info, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void 
wsf_util_engage_modules_to_svc(
    axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    wsf_svc_info_t *svc_info);

/**
* 
* @param ht_actions, 
* @param svc_info, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void 
wsf_util_process_ws_service_op_actions(
     HashTable *ht_actions,
     wsf_svc_info_t *svc_info,
     axutil_env_t *ws_env_svr TSRMLS_DC);

/**
* 
* @param ht_ops_to_funcs, 
* @param ht_ops_to_mep, 
* @param svc_info, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void 
wsf_util_process_ws_service_operations(
        HashTable *ht_ops_to_funcs,
        HashTable *ht_ops_to_mep,
        wsf_svc_info_t *svc_info,
        axutil_env_t *ws_env_svr TSRMLS_DC);

/**
* 
* @param ht_classes, 
* @param ht_ops_to_mep, 
* @param svc_info, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void 
wsf_util_process_ws_service_classes(
	HashTable *ht_classes,
	HashTable *ht_ops_to_mep,
	wsf_svc_info_t *svc_info,
	axutil_env_t *ws_env_svr TSRMLS_DC);

/**
* 
* @param env, 
* @param om_node, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void
wsf_util_find_xop_content_and_convert_to_base64 (
    const axutil_env_t * env,
    axiom_node_t * om_node);

/**
* 
* @param env, 
* @param soap_envelope, 
* @param cid2str, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int 
wsf_util_get_attachments_from_soap_envelope (
    const axutil_env_t * env,
    axiom_soap_envelope_t *soap_envelope,
    zval * cid2str,
    zval * cid2contentType TSRMLS_DC);

/**
* 
* @param env, 
* @param svc_info, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void 
wsf_util_process_rest_params(
	axutil_env_t *env, 
	wsf_svc_info_t *svc_info,
	HashTable *ht_rest_map TSRMLS_DC);

/**
* 
* @param env, 
* @param svc_info, 
* @param conf_ctx, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int
wsf_util_add_svc_to_conf(
	axutil_env_t *env,
	wsf_svc_info_t *svc_info,
	axis2_conf_ctx_t *conf_ctx);

/**
* 
* @param env, 
* @param svc_info, 
* @param conf_ctx, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int
wsf_util_find_and_set_svc_ctx(
	const axutil_env_t *env,
	wsf_svc_info_t *svc_info,
	axis2_conf_ctx_t *conf_ctx);

/**
* Set Values obtained using the array("address"=>,"referencePrameters"=> .. to endpoint ref 
* @param env, environment struct 
* @param ht HashTable containing the endpoint ref information
* @returns axis2_endpoint_ref_t on SUCCESS, NULL otherwise
*/
axis2_endpoint_ref_t *
wsf_util_set_values_to_endpoint_ref(
	const axutil_env_t *env,
	HashTable *ht TSRMLS_DC);

/**
* obtains the real path from a relative path
* @param env, environment struct 
* @returns real path
*/
char *
wsf_util_get_real_path(
	const axutil_env_t *env,
	char *path TSRMLS_DC);


#ifdef __cplusplus
}
#endif

#endif /* WSF_UTIL_H */
