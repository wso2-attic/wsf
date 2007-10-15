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


#ifndef WSF_WSDL_H
#define WSF_WSDL_H

#include <axutil_env.h>
#include <axiom.h>
#include <axis2_svc_client.h>
#include <php.h>
#include "wsf_common.h"
#include "wsf_policy.h"
#include <axiom_soap_body.h>
#include <TSRM.h>
#include "ext/libxml/php_libxml.h"


void create_dynamic_client(zval *this_ptr, char *fn_name, int fn_name_len, int arg_count,
                      zval *args, zval *return_value, axutil_env_t * env TSRMLS_DC);

#define WS_WSDL_FILE_PATH       "/scripts/dynamic_invocation/wsf_wsdl.php"
#define WS_WSDL_XSLT_PATH            "/scripts/dynamic_invocation/xslt"

#define WS_WSDL_WSCLIENT        "wsclient"
#define WS_WSDL_ENDPOINT        "endpoint"
#define WS_WSDL_CLASSMAP        "classmap"
#define WS_WSDL_XSLT_LOCATION   "xslt_location"
#define WS_WSDL_ARG_COUNT       "arg_count"
#define WS_WSDL_ARG_ARRAY       "arg_array"
#define WS_WSDL_INVOKE_FUNCTION "invoke_function"

#define WS_WSDL_REQ_FUNCTION    "wsf_process_wsdl"
#define WS_WSDL_RES_FUNCTION    "wsf_process_response"

#define WS_WSDL_ENDPOINT_URI    "endpoint_uri"
#define WS_WSDL_BINDING_DETAILS "binding_details"
#define WS_WSDL_WSA             "wsa"
#define WS_WSDL_SOAP            "soap"
#define WS_WSDL_SOAP_VERSION    "soap_version"
#define WS_WSDL_REQ_PAYLOAD     "request_payload"
#define WS_WSDL_POLICY_NODE     "policy_node"
#define WS_WSDL_RES_SIG_NODEL   "response_sig_model"
#define WS_WSDL_ARGS            "args"

#define WS_WSDL_OP_POLICY       "operation_policy"
#define WS_WSDL_IN_POLICY       "input_policy"
#define WS_WSDL_OUT_POLICY      "output_policy"

#define WS_WSDL_ENV_UTF         "UTF-8"
#define WS_WSDL_ENV_1_0         "1.0"

#define WS_WSDL_DOM          "wsdl_dom"

#endif /* WSF_WSDL_H */

