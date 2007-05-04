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
 
 #ifndef AXIOM_NODE_INTERNAL_H
 #define AXIOM_NODE_INTERNAL_H
 
 
 /** @defgroup axiom AXIOM (Axis Object Model)
  * @ingroup axis2
  * @{
  */
  
/** @} */

#include <axiom_node.h>

#ifdef __cplusplus
extern "C"
{
#endif
  
/**
 * @defgroup axiom_node  OM Node
 * @ingroup axiom 
 * @{
 */
struct axiom_document;
struct axiom_stax_builder;

/**
 * Sets a parent node to a given node, if a parent already exist for this node
 * then it is detached before seting the parent internal function;
 * @param om_node child node to whom a parent to be added. , cannot be NULL.
 * @param env Environment. MUST NOT be NULL, .
 * @param parent_node the node that will be set as parent. , cannot be NULL.
 * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_node_set_parent (axiom_node_t * om_node,
    const axutil_env_t *env,
    axiom_node_t * parent);

/**
 * Sets a node as first child of om_node
 * @param om_node om_node
 * @param env environment, MUST NOT be NULL.
 * @param first_child child to be set as first child
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_node_set_first_child(axiom_node_t *om_node,
    const axutil_env_t *env,
    axiom_node_t *first_child);

/**
 * Sets previous sibling
 * @param om_node 
 * @param env environment, MUST NOT be NULL.
 * @param prev_sibling 
 * @return status of the op, AXIS2_SUCCESS on success
 *     AXIS2_FAILURE on error
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL  
axiom_node_set_previous_sibling(axiom_node_t *om_node,
    const axutil_env_t *env,
    axiom_node_t *prev_sibling); 

/**
 * Sets next sibling
 * @param om_node 
 * @param env environment, MUST NOT be NULL.
 * @param last_sibling 
 * @return status of the op, AXIS2_SUCCESS on success,
 *     AXIS2_FAILURE on error
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_node_set_next_sibling(axiom_node_t *om_node,
    const axutil_env_t *env,
    axiom_node_t *next_sibling);

/**
 * Sets node type
 * @param om_node    
 * @param env environment, MUST NOT be NULL.
 * @param type type of the node
 * @return status code of the op AXIS2_SUCCESS on success,
 *     AXIS2_FAILURE on error
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axiom_node_set_node_type(axiom_node_t *om_node,
    const axutil_env_t *env,
    axiom_types_t type);

/**
 * Sets data element
 * @param om_node  node struct  
 * @param env environment, MUST NOT be NULL.
 * @param data_element 
 * @return status code of the op AXIS2_SUCCESS on success,
 *     AXIS2_FAILURE on error
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axiom_node_set_data_element(axiom_node_t *om_node,
    const axutil_env_t *env,
    void* data_element);

/**
 * Sets the build status , if the node if completety build, this attribute  is
 * set to AXIS2_TRUE , otherwise AXIS2_FALSE  
 * @param om_node 
 * @param env environment, MUST NOT be NULL.
 * @param done
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_node_set_complete(axiom_node_t *om_node,
    const axutil_env_t *env,
    axis2_bool_t done);

/**
 * This functions is only to be used by builder
 * do not use this function
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_node_set_document(axiom_node_t *om_node,
    const axutil_env_t *env,
    struct axiom_document *om_doc);

/**
 * Sets the builder
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_node_set_builder(axiom_node_t *om_node,
    const axutil_env_t *env,
    struct axiom_stax_builder *builder);

AXIS2_EXTERN struct axiom_stax_builder *AXIS2_CALL
axiom_node_get_builder(axiom_node_t *om_node,
    const axutil_env_t *env);

/** @} */
    
#ifdef __cplusplus
}
#endif

#endif /** AXIOM_NODE_INTERNAL_H */
