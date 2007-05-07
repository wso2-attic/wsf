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
#include <oxs_token_reference.h>
#include <axiom_attribute.h>
#include <axiom_element.h>


AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_reference_element(const axutil_env_t *env,
                                  axiom_node_t *parent,
                                  axis2_char_t *ref,
                                  axis2_char_t *value_type)
{
    axiom_node_t *reference_node = NULL;
    axiom_element_t *reference_ele = NULL;
    axiom_attribute_t *ref_attr = NULL;
    axiom_attribute_t *value_type_attr = NULL;
    int ret;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_WSSE_NS,
                                    OXS_WSSE);

    reference_ele = axiom_element_create(env, parent, OXS_NODE_REFERENCE, ns_obj, &reference_node);
    if (!reference_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating Reference element");
        return NULL;
    }
    /*attach empty string*/
    if (!ref)
    {
        ref = "";
    }

    ref_attr =  axiom_attribute_create(env, OXS_ATTR_URI , ref, NULL);
    value_type_attr =  axiom_attribute_create(env, OXS_ATTR_VALUE_TYPE , value_type, NULL);

    ret = axiom_element_add_attribute(reference_ele, env, ref_attr, reference_node);
    ret = axiom_element_add_attribute(reference_ele, env, value_type_attr, reference_node);

    return reference_node;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_token_get_reference(const axutil_env_t *env, axiom_node_t *ref_node)
{
    axis2_char_t *ref = NULL;
    axiom_element_t *reference_ele = NULL;

    reference_ele = axiom_node_get_data_element(ref_node, env);
    if (!reference_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error retrieving data reference element");
        return NULL;
    }

    ref = axiom_element_get_attribute_value_by_name(reference_ele, env, OXS_ATTR_URI);
    return ref;

}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_token_get_reference_value_type(const axutil_env_t *env, axiom_node_t *ref_node)
{
    axis2_char_t *val_type = NULL;
    axiom_element_t *reference_ele = NULL;

    reference_ele = axiom_node_get_data_element(ref_node, env);
    if (!reference_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error retrieving data reference element");
        return NULL;
    }

    val_type = axiom_element_get_attribute_value_by_name(reference_ele, env, OXS_ATTR_VALUE_TYPE);
    return val_type;
}
