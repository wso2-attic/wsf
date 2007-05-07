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
#include <oxs_token_ds_reference.h>
#include <axiom_attribute.h>
#include <axiom_element.h>


AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_ds_reference_element(const axutil_env_t *env,
                                     axiom_node_t *parent,
                                     axis2_char_t *id,
                                     axis2_char_t *uri,
                                     axis2_char_t *type)
{
    axiom_node_t *ds_reference_node = NULL;
    axiom_element_t *ds_reference_ele = NULL;
    int ret;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_DSIG_NS,
                                    OXS_DS);

    ds_reference_ele = axiom_element_create(env, parent, OXS_NODE_REFERENCE, ns_obj, &ds_reference_node);
    if (!ds_reference_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating ds:Reference element");
        return NULL;
    }

    if(id){
        axiom_attribute_t *id_attr = NULL;
        id_attr =  axiom_attribute_create(env, OXS_ATTR_ID , id, NULL);
        ret = axiom_element_add_attribute(ds_reference_ele, env, id_attr, ds_reference_node);
    }

    if(uri){
        axiom_attribute_t *uri_attr = NULL;
        uri_attr =  axiom_attribute_create(env, OXS_ATTR_URI , uri, NULL);
        ret = axiom_element_add_attribute(ds_reference_ele, env, uri_attr, ds_reference_node);
    }

    if(type){
        axiom_attribute_t *type_attr = NULL;
        type_attr =  axiom_attribute_create(env, OXS_ATTR_TYPE , type, NULL);
        ret = axiom_element_add_attribute(ds_reference_ele, env, type_attr, ds_reference_node);
    }

    return ds_reference_node;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_token_get_ds_reference(const axutil_env_t *env, axiom_node_t *ref_node)
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

