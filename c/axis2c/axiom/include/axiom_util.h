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

#ifndef AXIOM_UTIL_H
#define AXIOM_UTIL_H

#include <axutil_array_list.h>
#include <axutil_string.h>
#include <axiom.h>
#include <axutil_uri.h>

#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_first_child_element_with_uri(
        axiom_node_t *ele_node,
        const axutil_env_t *env,
        axis2_char_t *uri,
        axiom_node_t **child);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_next_sibling_element_with_uri(
        axiom_node_t *ele_node,
        const axutil_env_t *env,
        axis2_char_t *uri,
        axiom_node_t **next_node);



    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_first_child_element(
        axiom_element_t *ele,
        const axutil_env_t *env,
        axiom_node_t *ele_node,
        axiom_node_t **child_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_last_child_element(
        axiom_element_t *ele,
        const axutil_env_t *env,
        axiom_node_t *ele_node,
        axiom_node_t **child_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_next_sibling_element(
        axiom_element_t *ele,
        const axutil_env_t *env,
        axiom_node_t *ele_node,
        axiom_node_t **next_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_first_child_element_with_localname(
        axiom_element_t *ele,
        const axutil_env_t  *env,
        axiom_node_t *ele_node,
        axis2_char_t *localname,
        axiom_node_t **child_node);


    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_last_child_element_with_localname(
        axiom_element_t *ele,
        const axutil_env_t  *env,
        axiom_node_t *ele_node,
        axis2_char_t *localname,
        axiom_node_t **child_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_next_siblng_element_with_localname(
        axiom_element_t *ele,
        const axutil_env_t  *env,
        axiom_node_t *ele_node,
        axis2_char_t *localname,
        axiom_node_t **next_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_first_child_element_with_uri_localname(
        axiom_element_t *ele,
        const axutil_env_t  *env,
        axiom_node_t *ele_node,
        axis2_char_t *localname,
        axis2_char_t *uri,
        axiom_node_t **child_node);
    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_last_child_element_with_uri_localname(axiom_element_t *ele,
            const axutil_env_t  *env,
            axiom_node_t *ele_node,
            axis2_char_t *localname,
            axis2_char_t *uri,
            axiom_node_t **child_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_next_sibling_element_with_uri_localname(axiom_element_t *ele,
            const axutil_env_t  *env,
            axiom_node_t *ele_node,
            axis2_char_t *localname,
            axis2_char_t *uri,
            axiom_node_t **next_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_first_child_element_with_localnames(axiom_element_t *ele,
            const axutil_env_t  *env,
            axiom_node_t *ele_node,
            axutil_array_list_t *names,
            axiom_node_t **child_node);


    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_last_child_element_with_localnames(axiom_element_t *ele,
            const axutil_env_t  *env,
            axiom_node_t *ele_node,
            axutil_array_list_t *names,
            axiom_node_t **child_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_next_siblng_element_with_localnames(axiom_element_t *ele,
            const axutil_env_t  *env,
            axiom_node_t *ele_node,
            axutil_array_list_t *names,
            axiom_node_t **next_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_first_child_element_with_localname_attr(axiom_element_t *ele,
            const axutil_env_t  *env,
            axiom_node_t *ele_node,
            axis2_char_t *localname,
            axis2_char_t *attr_name,
            axis2_char_t *attr_value,
            axiom_node_t **child_node);


    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_last_child_element_with_localname_attr(axiom_element_t *ele,
            const axutil_env_t  *env,
            axiom_node_t *ele_node,
            axis2_char_t *localname,
            axis2_char_t *attr_name,
            axis2_char_t *attr_value,
            axiom_node_t **child_node);

    AXIS2_EXTERN axiom_element_t * AXIS2_CALL
    axiom_util_get_next_siblng_element_with_localname_attr(axiom_element_t *ele,
            const axutil_env_t  *env,
            axiom_node_t *ele_node,
            axis2_char_t *localname,
            axis2_char_t *attr_name,
            axis2_char_t *attr_value,
            axiom_node_t **next_node);

    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axiom_util_get_child_text(axiom_node_t *node,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axiom_util_get_localname(axiom_node_t *node,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axiom_util_get_node_namespace_uri(axiom_node_t *om_node,
            const axutil_env_t *env);


    AXIS2_EXTERN axiom_child_element_iterator_t* AXIS2_CALL
    axiom_util_get_child_elements(axiom_element_t *om_ele,
            const axutil_env_t *env,
            axiom_node_t *om_node);

    AXIS2_EXTERN axiom_document_t* AXIS2_CALL
    axiom_util_new_document(
        const axutil_env_t *env,
        const axutil_uri_t *uri);

#ifdef __cplusplus
}
#endif
#endif /* AXIOM_UTIL_H */
