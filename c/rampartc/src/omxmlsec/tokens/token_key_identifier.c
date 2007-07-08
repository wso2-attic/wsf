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
#include <oxs_token_key_identifier.h>
#include <axiom_attribute.h>
#include <axiom_element.h>


AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_key_identifier_element(const axutil_env_t *env,
                                       axiom_node_t *parent,
                                       axis2_char_t* encoding_type,
                                       axis2_char_t* value_type,
                                       axis2_char_t* value  )
{
    axiom_node_t *ki_node = NULL;
    axiom_element_t *ki_ele = NULL;
    axiom_attribute_t *encoding_type_att = NULL;
    axiom_attribute_t *value_type_att = NULL;
    int ret;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_WSSE_NS,
                                    OXS_WSSE);

    ki_ele = axiom_element_create(env, parent, OXS_NODE_KEY_IDENTIFIER, ns_obj, &ki_node);
    if (!ki_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating KeyIdentifier element");
        return NULL;
    }

    encoding_type_att =  axiom_attribute_create(env, OXS_ATTR_ENCODING_TYPE, encoding_type, NULL);
    value_type_att =  axiom_attribute_create(env, OXS_ATTR_VALUE_TYPE, value_type, NULL);

    ret = axiom_element_add_attribute(ki_ele, env, encoding_type_att, ki_node);
    ret = axiom_element_add_attribute(ki_ele, env, value_type_att, ki_node);

    if (value)
    {
        ret  = axiom_element_set_text(ki_ele, env, value, ki_node);
    }


    return ki_node;

}

