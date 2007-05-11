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

#include <stdio.h>
#include <axiom_element.h>
#include <oxs_constants.h>
#include <oxs_error.h>
#include <oxs_token_cipher_data.h>
#include <oxs_token_cipher_value.h>
#include <oxs_axiom.h>


AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_cipher_data_element(const axutil_env_t *env,
                                    axiom_node_t *parent
                                   )
{
    axiom_node_t *cipher_data_node = NULL;
    axiom_element_t *cipher_data_ele = NULL;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_ENC_NS,
                                    OXS_XENC);

    cipher_data_ele = axiom_element_create(env, parent, OXS_NODE_CIPHER_DATA, ns_obj, &cipher_data_node);
    if (!cipher_data_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating cipher data element");
        return NULL;
    }

    return cipher_data_node;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_token_get_cipher_value_from_cipher_data(const axutil_env_t *env,
        axiom_node_t *cd_node)
{
    axiom_node_t *cv_node = NULL;
    axis2_char_t *value = NULL;
    /*First check direct <CipherValue>*/
    cv_node = oxs_axiom_get_first_child_node_by_name(env, cd_node, OXS_NODE_CIPHER_VALUE, OXS_ENC_NS, OXS_XENC);
    if(cv_node){
        value = oxs_token_get_cipher_value(env, cv_node);
    }else{
        /*If not then check for <CipherReference URI?>*/
    }

    return value;
}
