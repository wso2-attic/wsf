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
#include <oxs_token_signature.h>
#include <axiom_attribute.h>
#include <axiom_element.h>



AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_signature_element(const axutil_env_t *env,
                                  axiom_node_t *parent,
                                  axis2_char_t* id)
{
    axiom_node_t *signature_node = NULL;
    axiom_element_t *signature_ele = NULL;
    axiom_attribute_t *id_attr = NULL;
    axiom_namespace_t *ns_obj = NULL;
    int ret;

    ns_obj = axiom_namespace_create(env, OXS_DSIG_NS,
                                    OXS_DS);

    signature_ele = axiom_element_create(env, parent, OXS_NODE_SIGNATURE, ns_obj, &signature_node);
    if (!signature_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating ds:Signature element");
        return NULL;
    }

    /*If id is not NULL then add it as an attribute*/
    if (id)
    {
        id_attr = axiom_attribute_create(env, OXS_ATTR_ID, id, NULL);
        ret = axiom_element_add_attribute(signature_ele, env, id_attr, signature_node);
    }

    return signature_node;

}

