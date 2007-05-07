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
#include <oxs_token_c14n_method.h>
#include <axiom_attribute.h>
#include <axiom_element.h>


AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_c14n_method_element(const axutil_env_t *env,
                                    axiom_node_t *parent,
                                    axis2_char_t* algorithm
                                   )
{
    axiom_node_t *c14n_method_node = NULL;
    axiom_element_t *c14n_method_ele = NULL;
    axiom_attribute_t *algo_attr = NULL;
    int ret;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_DSIG_NS,
                                    OXS_DS);

    c14n_method_ele = axiom_element_create(env, parent, OXS_NODE_CANONICALIZATION_METHOD, ns_obj, &c14n_method_node);
    if (!c14n_method_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating c14n method element");
        return NULL;
    }
    /*If c14n algorithm is NULL then use the default*/
    if (!algorithm)
    {
        algorithm = (axis2_char_t*)OXS_HREF_XML_EXC_C14N;
    }

    algo_attr =  axiom_attribute_create(env, OXS_ATTR_ALGORITHM, algorithm, NULL);

    ret = axiom_element_add_attribute(c14n_method_ele, env, algo_attr, c14n_method_node);

    return c14n_method_node;

}



AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_token_get_c14n_method(const axutil_env_t *env, axiom_node_t *c14n_mtd_node)
{
    axis2_char_t *c14n_mtd = NULL;
    axiom_element_t *c14n_mtd_ele = NULL;

    if(!c14n_mtd_node){
        return NULL;
    }

    c14n_mtd_ele = axiom_node_get_data_element(c14n_mtd_node, env);
    if (!c14n_mtd_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error retrieving c14n method element");
        return NULL;
    }

    c14n_mtd = axiom_element_get_attribute_value_by_name(c14n_mtd_ele, env, OXS_ATTR_ALGORITHM);
    if((!c14n_mtd) ||(0 == axutil_strcmp("", c14n_mtd))){
        return NULL;
    }

    return c14n_mtd;

}

