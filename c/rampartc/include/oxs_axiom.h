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

#ifndef OXS_AXIOM_H
#define OXS_AXIOM_H


/**
  * @file oxs_axiom.h
  * @brief Utility functions related to AXIOM. A place for common code.
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_util.h>
#include <axiom_node.h>
#include <axiom_util.h>
#include <axiom_document.h>
#include <axiom.h>

#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_axiom_add_attribute(const axutil_env_t *env,
                            axiom_node_t* node,
                            axis2_char_t* attribute_ns,
                            axis2_char_t* attribute_ns_uri,
                            axis2_char_t* attribute,
                            axis2_char_t* value);

    AXIS2_EXTERN int AXIS2_CALL
    oxs_axiom_get_number_of_children_with_qname(const axutil_env_t *env,
            axiom_node_t* parent,
            axis2_char_t* local_name,
            axis2_char_t* ns_uri,
            axis2_char_t* prefix);

    /**
     * Traverse thru the node and its children. Check if the localname is equal to the given name
     * */
    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    oxs_axiom_get_node_by_local_name(const axutil_env_t *env,
                                     axiom_node_t *node,
                                     axis2_char_t *local_name);

    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    oxs_axiom_get_node_by_id(const axutil_env_t *env,
                             axiom_node_t *node,
                             axis2_char_t *attr,
                             axis2_char_t *val);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    oxs_axiom_get_attribute_value_of_node_by_name(const axutil_env_t *env,
            axiom_node_t *node,
            axis2_char_t *attribute_name);


    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    oxs_axiom_get_first_child_node_by_name(const axutil_env_t *env,
                                           axiom_node_t* parent,
                                           axis2_char_t* local_name,
                                           axis2_char_t* ns_uri,
                                           axis2_char_t* prefix);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    oxs_axiom_get_node_content(const axutil_env_t *env, axiom_node_t* node);


    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    oxs_axiom_deserialize_node(const axutil_env_t *env,  axis2_char_t* buffer);
    /**
    * returns 1 sucess 0 otherwise
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_axiom_check_node_name(const axutil_env_t *env, axiom_node_t* node, axis2_char_t* name, axis2_char_t* ns);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_AXIOM_H */
