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
#include <oxs_token_encrypted_data.h>
#include <axiom_attribute.h>
#include <axiom_element.h>



AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_encrypted_data_element(const axutil_env_t *env,
                                       axiom_node_t *parent,
                                       axis2_char_t* type_attribute,
                                       axis2_char_t* id
                                      )
{
    axiom_node_t *encrypted_data_node = NULL;
    axiom_element_t *encrypted_data_ele = NULL;
    axiom_attribute_t *type_attr = NULL;
    axiom_attribute_t *id_attr = NULL;
    axiom_namespace_t *ns_obj = NULL;
    int ret;

    ns_obj = axiom_namespace_create(env, OXS_ENC_NS,
                                    OXS_XENC);

    encrypted_data_ele = axiom_element_create(env, parent, OXS_NODE_ENCRYPTED_DATA, ns_obj, &encrypted_data_node);
    if (!encrypted_data_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating encrypted data element");
        return NULL;
    }

    if (type_attribute)
    {
        type_attr =  axiom_attribute_create(env, OXS_ATTR_TYPE, type_attribute, NULL);
        ret = axiom_element_add_attribute(encrypted_data_ele, env, type_attr, encrypted_data_node);
    }

    if (id)
    {
        id_attr = axiom_attribute_create(env, OXS_ATTR_ID, id, NULL);
        ret = axiom_element_add_attribute(encrypted_data_ele, env, id_attr, encrypted_data_node);
    }
    else
    {
        /*TODO Get a unique value for this*/
        id_attr = axiom_attribute_create(env, OXS_ATTR_ID, "EncDataId-54321", NULL);
        ret = axiom_element_add_attribute(encrypted_data_ele, env, id_attr, encrypted_data_node);
    }

    return encrypted_data_node;

}

