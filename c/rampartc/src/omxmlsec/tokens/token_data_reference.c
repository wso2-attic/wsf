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
#include <oxs_token_data_reference.h>
#include <axiom_attribute.h>
#include <axiom_element.h>


AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_data_reference_element(const axutil_env_t *env,
                                       axiom_node_t *parent,
                                       axis2_char_t *data_ref)
{
    axiom_node_t *data_reference_node = NULL;
    axiom_element_t *data_reference_ele = NULL;
    axiom_attribute_t *data_ref_attr = NULL;
    int ret;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_ENC_NS,
                                    OXS_XENC);

    data_reference_ele = axiom_element_create(env, parent, OXS_NODE_DATA_REFERENCE, ns_obj, &data_reference_node);
    if (!data_reference_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating data reference element");
        return NULL;
    }
    /*attach empty string*/
    if (!data_ref)
    {
        data_ref = "";
    }

    data_ref_attr =  axiom_attribute_create(env, OXS_ATTR_URI , data_ref, NULL);

    ret = axiom_element_add_attribute(data_reference_ele, env, data_ref_attr, data_reference_node);

    return data_reference_node;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_token_get_data_reference(const axutil_env_t *env, axiom_node_t *data_ref_node)
{
    axis2_char_t *data_ref = NULL;
    axiom_element_t *data_reference_ele = NULL;

    data_reference_ele = axiom_node_get_data_element(data_ref_node, env);
    if (!data_reference_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error retrieving data reference element");
        return NULL;
    }

    data_ref = axiom_element_get_attribute_value_by_name(data_reference_ele, env, OXS_ATTR_URI);
    return data_ref;

}

