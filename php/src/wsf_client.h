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

#ifndef WSF_CLIENT_H
#define WSF_CLIENT_H

#include <axis2_env.h>
#include <axiom.h>
#include <axis2_op_client.h>
#include <axis2_svc_client.h>
#include <axis2_options.h>
#include <php.h>
#include "wsf_common.h"
#include <axiom_soap_body.h>
#include <TSRM.h>
#include "ext/libxml/php_libxml.h"

int wsf_client_set_options(
		HashTable *client_ht, 
		HashTable *msg_ht, 
		axis2_env_t *env,
        axis2_options_t *options, 
		axis2_svc_client_t *svc_client,
		int is_send TSRMLS_DC);  
        
int wsf_client_set_headers(
		const axis2_env_t *env,
		axis2_svc_client_t *svc_client,
		zval *msg TSRMLS_DC);


int wsf_client_do_request(
		zval *this_ptr, 
		zval *param, 
		zval *return_value,
		axis2_env_t *env,
		axis2_svc_client_t *svc_client,
		int is_oneway TSRMLS_DC);

void wsf_client_enable_ssl(HashTable *ht, 
		axis2_env_t *env, 
		axis2_options_t *options,
		axis2_svc_client_t *svc_client TSRMLS_DC);



void wsf_client_add_properties(zval *this_ptr , HashTable *ht TSRMLS_DC);

#endif /* WS_UTIL_H */
