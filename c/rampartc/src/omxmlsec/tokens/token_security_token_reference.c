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
#include <oxs_token_security_token_reference.h>
#include <axiom_attribute.h>
#include <axiom_element.h>

/*TODO These names should be changed to oxs_token_build_XXX_node*/

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_security_token_reference_element(const axutil_env_t *env,
        axiom_node_t *parent)
{
    axiom_node_t *security_token_reference_node = NULL;
    axiom_element_t *security_token_reference_ele = NULL;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_WSSE_NS,
                                    OXS_WSSE);

    security_token_reference_ele = axiom_element_create(env, parent, OXS_NODE_SECURITY_TOKEN_REFRENCE, ns_obj, &security_token_reference_node);
    if (!security_token_reference_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating SecurityTokenReference element");
        return NULL;
    }

    return security_token_reference_node;
}


