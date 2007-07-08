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

#include <axis2_util.h>
#include <stdio.h>
#include <oxs_constants.h>
#include <oxs_error.h>
#include <oxs_token_embedded.h>
#include <axiom_attribute.h>
#include <axiom_element.h>
#include <oxs_utility.h>



AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_embedded_element(const axutil_env_t *env,
                                 axiom_node_t *parent,
                                 axis2_char_t* id)
{
    axiom_node_t *embedded_node = NULL;
    axiom_element_t *embedded_ele = NULL;
    axiom_attribute_t *id_attr = NULL;
    int ret;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_WSSE_NS,
                                    OXS_WSSE);

    embedded_ele = axiom_element_create(env, parent, OXS_NODE_EMBEDDED, ns_obj, &embedded_node);
    if (!embedded_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating embedded element");
        return NULL;
    }
    if (!id)
    {
        id = oxs_util_generate_id(env,(axis2_char_t*)OXS_EMBEDDED_ID);
    }

    id_attr =  axiom_attribute_create(env, OXS_ATTR_ID, id, NULL);

    ret = axiom_element_add_attribute(embedded_ele, env, id_attr, embedded_node);

    return embedded_node;

}



AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_token_get_embedded_id(const axutil_env_t *env, axiom_node_t *embedded_node)
{
    axis2_char_t *embedded = NULL;
    axiom_element_t *embedded_ele = NULL;

    embedded_ele = axiom_node_get_data_element(embedded_node, env);
    if (!embedded_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error retrieving embedded element");
        return NULL;
    }

    embedded = axiom_element_get_attribute_value_by_name(embedded_ele, env, OXS_ATTR_ID);
    return embedded;

}

