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
#include <oxs_constants.h>
#include <oxs_error.h>
#include <oxs_token_cipher_value.h>
#include <axiom_element.h>
#include <oxs_axiom.h>


AXIS2_EXTERN axis2_char_t* AXIS2_CALL
oxs_token_get_cipher_value(const axutil_env_t *env,
                           axiom_node_t *cv_node)
{
    axis2_char_t *cv = NULL;
    /*TODO Verification*/
    cv = (axis2_char_t*)oxs_axiom_get_node_content(env, cv_node);
    return cv;

}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_cipher_value_element(const axutil_env_t *env,
                                     axiom_node_t *parent,
                                     axis2_char_t* cipher_val
                                    )
{
    axiom_node_t *cipher_value_node = NULL;
    axiom_element_t *cipher_value_ele = NULL;
    axis2_status_t ret;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_ENC_NS,
                                    OXS_XENC);

    cipher_value_ele = axiom_element_create(env, parent, OXS_NODE_CIPHER_VALUE, ns_obj, &cipher_value_node);
    if (!cipher_value_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating cipher value element");
        return NULL;
    }

    if (cipher_val)
    {
        ret  = axiom_element_set_text(cipher_value_ele, env, cipher_val, cipher_value_node);
    }

    return cipher_value_node;

}

