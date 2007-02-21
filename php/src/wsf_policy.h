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


#ifndef WSF_POLICY_H
#define WSF_POLICY_H

#include <axis2_env.h>
#include <axiom.h>
#include <axis2_options.h>
#include <php.h>
#include "wsf_common.h"
#include <axiom_soap_body.h>
#include <TSRM.h>
#include "ext/libxml/php_libxml.h"


#define WS_SIGN "sign"
#define WS_ENCRYPT "encrypt"
#define WS_ALGORITHM "algorithmSuite"
#define WS_LAYOUT "layOut"
#define WS_TIMESTAMP "includeTimeStamp"
#define WS_PROTECTION_ORDER "protectionOrder"
#define WS_UT "useUsernameToken"
#define WS_TOKEN_REFERENCE "securityTokenReference"


#define BASIC256 "Basic256"
#define BASIC192 "Basic192"
#define BASIC128 "Basic128"
#define TRIPLEDES "TripleDes"
#define BASIC256_RSA15 "Basic256RSA15"
#define BASIC192_RSA15 "Basic192RSA15"
#define BASIC128_RSA15 "Basic128RSA15"
#define TRIPLEDES_RSA15 "TripleDesRSA15"




int set_policy_options(zval *this_ptr,
		       HashTable *ht,
		       const axis2_env_t *env TSRMLS_DC);
/* int set_policy_options(const axis2_env_t *env, */
/*                        HashTable *ht TSRMLS_DC); */

axiom_node_t *get_security_policy_node();

#endif /* WSF_POLICY_H*/





