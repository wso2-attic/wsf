/*
 * Copyright 2005,2008 WSO2, Inc. http://wso2.com
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

#ifndef WSF_CLIENT_H
#define WSF_CLIENT_H

#include <axutil_env.h>
#include <axiom.h>
#include <axis2_op_client.h>
#include <axis2_svc_client.h>
#include <axis2_options.h>
#include <php.h>
#include "wsf_common.h"
#include <axiom_soap_body.h>
#include <TSRM.h>
#include "ext/libxml/php_libxml.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/**
*
* @param client_ht, WSClient options array
* @param msg_ht,  WSMessage options array
* @param env,	  axis2 environment
* @param options, axis2 options
* @param svc_client, axis2 service client
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int wsf_client_set_options (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * options,
    axis2_svc_client_t * svc_client,
    int *rest_enabled TSRMLS_DC);

/**
* 
* @param env, 
* @param svc_client, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int wsf_client_set_headers (
    const axutil_env_t * env,
    axis2_svc_client_t * svc_client,
    zval * msg TSRMLS_DC);


/**
* 
* @param this_ptr, 
* @param param, 
* @param return_value, 
* @param env, 
* @param svc_client, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void wsf_client_do_request (
    zval * this_ptr,
    zval * param,
    zval * return_value,
    axutil_env_t * env,
    axis2_svc_client_t * svc_client,
    int is_oneway TSRMLS_DC);

/**
* 
* @param ht, 
* @param env, 
* @param options, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void wsf_client_enable_ssl (
    HashTable * ht,
    axutil_env_t * env,
    axis2_options_t * options,
    axis2_svc_client_t * svc_client TSRMLS_DC);

/**
* 
* @param ht, 
* @param env, 
* @param options, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void wsf_client_enable_proxy (
    HashTable * ht,
    axutil_env_t * env,
    axis2_options_t * options,
    axis2_svc_client_t * svc_client TSRMLS_DC);

/**
* 
* @param this_ptr, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void wsf_client_add_properties (
    zval * this_ptr,
    HashTable * ht TSRMLS_DC);

/**
* 
* @param client_ht, Hash table of WSClient options array
* @param msg_ht, HashTable of WSMessage options array
* @param env,    axis2 environment struct 
* @param client_options axis2_options struct
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int wsf_client_set_endpoint_and_soap_action (
    HashTable * client_ht,
    HashTable * msg_ht,
    axutil_env_t * env,
    axis2_options_t * client_options TSRMLS_DC);

/**
* 
* @param env, 
* @param is_rm_engaged, 
* @param will_continue_sequence, 
* @param rm_spec_version, 
* @param sequence_key, 
* @param svc_client, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void wsf_client_send_terminate_sequence (
    axutil_env_t * env,
    int is_rm_engaged,
    int will_continue_sequence,
    int rm_spec_version,
    char *sequence_key,
    axis2_svc_client_t * svc_client);


#ifdef __cplusplus
}
#endif

#endif /* WSF_CLIENT_H */
