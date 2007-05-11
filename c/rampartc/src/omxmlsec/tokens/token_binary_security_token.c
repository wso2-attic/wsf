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

#include <oxs_constants.h>
#include <oxs_error.h>
#include <oxs_token_binary_security_token.h>
#include <oxs_utility.h>
#include <axiom_attribute.h>
#include <axiom_element.h>
#include <rampart_constants.h>

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_binary_security_token_element(const axutil_env_t *env,
        axiom_node_t *parent,
        axis2_char_t* id,
        axis2_char_t* encoding_type,
        axis2_char_t* value_type,
        axis2_char_t* data)
{
    axiom_node_t *binary_security_token_node = NULL;
    axiom_node_t *first_child_of_parent = NULL;
    axiom_element_t *binary_security_token_ele = NULL;
    axiom_attribute_t *encoding_type_att = NULL;
    axiom_attribute_t *value_type_att = NULL;
    axiom_attribute_t *id_attr = NULL;
    int ret;
    axiom_namespace_t *ns_obj = NULL;
    axiom_namespace_t *ns = NULL;

    ns_obj = axiom_namespace_create(env, OXS_WSSE_NS,
                                    OXS_WSSE);

    ns = axiom_namespace_create(env,RAMPART_WSU_XMLNS,OXS_WSU);

    binary_security_token_ele = axiom_element_create(env, parent, OXS_NODE_BINARY_SECURITY_TOKEN, ns_obj, &binary_security_token_node);
    if (!binary_security_token_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating Binary Security Token element");
        return NULL;
    }

    /*Binary security token must be added as the first child of the paretn*/
    binary_security_token_node = axiom_node_detach(binary_security_token_node, env);
    first_child_of_parent = axiom_node_get_first_element(parent, env);
    if(first_child_of_parent){
        /*If there is a child add bst before it*/
        axiom_node_insert_sibling_before(first_child_of_parent, env, binary_security_token_node);
    }else{
        /*If there are no children just add the bst*/
        axiom_node_add_child(parent, env, binary_security_token_node);
    }
    if (!id)
    {
        id = oxs_util_generate_id(env,(axis2_char_t*)OXS_CERT_ID);
    }


    id_attr = axiom_attribute_create(env, OXS_ATTR_ID, id,ns);
    encoding_type_att =  axiom_attribute_create(env, OXS_ATTR_ENCODING_TYPE, encoding_type, NULL);
    value_type_att =  axiom_attribute_create(env, OXS_ATTR_VALUE_TYPE, value_type, NULL);

    ret = axiom_element_add_attribute(binary_security_token_ele, env, id_attr, binary_security_token_node);
    ret = axiom_element_add_attribute(binary_security_token_ele, env, encoding_type_att, binary_security_token_node);
    ret = axiom_element_add_attribute(binary_security_token_ele, env, value_type_att, binary_security_token_node);

    if(data){
        ret  = axiom_element_set_text(binary_security_token_ele, env, data, binary_security_token_node);
    }

    return binary_security_token_node;

}


