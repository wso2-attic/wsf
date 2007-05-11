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
#include <oxs_token_reference_list.h>
#include <axiom_element.h>
#include <oxs_token_data_reference.h>
#include <axutil_array_list.h>

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_reference_list_element(const axutil_env_t *env,
                                       axiom_node_t *parent )
{
    axiom_node_t *reference_list_node = NULL;
    axiom_element_t *reference_list_ele = NULL;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_ENC_NS,
                                    OXS_XENC);


    reference_list_ele = axiom_element_create(env, parent, OXS_NODE_REFERENCE_LIST, ns_obj, &reference_list_node);
    if (!reference_list_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating ReferenceList element");
        return NULL;
    }

    return reference_list_node;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_token_build_data_reference_list(const axutil_env_t *env, axiom_node_t *parent, axutil_array_list_t *id_list)
{
    axiom_node_t *ref_list_node = NULL;
    int i=0;

    if(!id_list){
        return AXIS2_SUCCESS;
    }
    /*Build the ReferenceList element*/
    ref_list_node = oxs_token_build_reference_list_element(env, parent);
    if(!ref_list_node) {return AXIS2_FAILURE;}

    /*Build the list*/
    for(i=0 ; i < axutil_array_list_size(id_list, env); i++){
        axiom_node_t *data_ref_node = NULL;
        axis2_char_t *id = NULL;

        /*We need to prepend # to the id in the list to create the reference*/
        id = axutil_stracat(env, "#",(axis2_char_t*)axutil_array_list_get(id_list, env, i));
        data_ref_node = oxs_token_build_data_reference_element(env, ref_list_node, id);

        if(!data_ref_node) {return AXIS2_FAILURE;}

    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
oxs_token_get_reference_list_data(const axutil_env_t *env, axiom_node_t *ref_list_node)
{
    axutil_array_list_t *list = NULL;
    axiom_children_qname_iterator_t *iter = NULL;
    axiom_element_t *ref_list_ele = NULL;
    axutil_qname_t *qname = NULL;

    if (!ref_list_node)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "reference list node is NULL");
        return NULL;
    }
    ref_list_ele = axiom_node_get_data_element(ref_list_node, env);

    /*Get children*/
    qname = axutil_qname_create(env, OXS_NODE_DATA_REFERENCE,OXS_ENC_NS,OXS_ENC_NS);
    iter = axiom_element_get_children_with_qname(ref_list_ele, env, qname, ref_list_node);
    axutil_qname_free(qname, env);
    qname = NULL;

    if(!iter){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "There are no children for %s", OXS_NODE_DATA_REFERENCE);
        return NULL;
    }

    list = axutil_array_list_create(env, 0);

    /*Insert UIDs of nodes to the list*/
    while (AXIS2_TRUE == axiom_children_qname_iterator_has_next(iter, env))
    {
        axiom_node_t *dref_node = NULL;
        axis2_char_t *dref_val = NULL;

        dref_node = axiom_children_qname_iterator_next(iter, env);
        dref_val = oxs_token_get_data_reference(env, dref_node);

        axutil_array_list_add(list, env, dref_val);
    }

    return list;
}

