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

#ifndef AXIOM_NODE_H
#define AXIOM_NODE_H

/**
  * @defgroup axiom AXIOM project
  * @{
  * @}
  */

/**
  * @defgroup axiom_om AXIOM
  * @ingroup axiom
  * @{
  * @}
  */

/**
 * @file axiom_node.h
 * @brief defines axiom_node struct
 */
#include <axutil_env.h>
#include <axutil_utils.h>


#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_node axiom_node_t;
    struct axiom_output;
    struct axiom_document;
    struct axiom_stax_builder;
    /**
     * @defgroup axiom_node  node
     * @ingroup axiom_om
     * @{
     */

    /**
      * @brief AXIOM types
      */
    typedef enum axiom_types_t
    {
        /** Invalid node type */
        AXIOM_INVALID = 0,
        /** AXIOM document type */
        AXIOM_DOCUMENT,
        /** AXIOM element type */
        AXIOM_ELEMENT,
        /** AXIOM doctype type */
        AXIOM_DOCTYPE,
        /** AXIOM comment type */
        AXIOM_COMMENT,
        /** AXIOM attribute type */
        AXIOM_ATTRIBUTE,
        /** AXIOM namespace type */
        AXIOM_NAMESPACE,
        /** AXIOM processing instruction type */
        AXIOM_PROCESSING_INSTRUCTION,
        /** AXIOM text type */
        AXIOM_TEXT,
        /** AXIOM data source, represent a serialized XML fragment with a stream */
        AXIOM_DATA_SOURCE
    } axiom_types_t;

    /**
      * Creates a node struct.
      * @param env Environment. MUST NOT be NULL, .
      * @return a pointer to newly created node struct. NULL on error. 
      */
    AXIS2_EXTERN axiom_node_t * AXIS2_CALL
    axiom_node_create(const axutil_env_t *env);

    /**
    * Frees an om node and all of its children
    * @param om_node node to be freed.
    * @param env Environment. MUST NOT be NULL, .
    * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
    */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_node_free_tree(axiom_node_t *om_node,
            const axutil_env_t *env);
    /**
    * Adds given node as child to parent. child should not have a parent
    * if child has a parent it will be detached from existing parent
    * @param om_node parent node. cannot be NULL.
    * @param env Environment. MUST NOT be NULL, .
    * @param child child node.
    * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_node_add_child(axiom_node_t* om_node,
            const axutil_env_t *env,
            axiom_node_t *child);

    /**
    * Detaches given node from the parent and reset the links
    * @param om_node node to be detached, cannot be NULL.
    * @param env Environment. MUST NOT be NULL, .
    * @return a pointer to detached node,returns NULL on error with error
    *           code set to environment's error struct
    */
    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_node_detach(axiom_node_t  *om_node,
            const axutil_env_t *env);

    /**
    * Inserts a sibling node after the given node
    * @param om_node node to whom the sibling to be inserted. , cannot be NULL.
    * @param env Environment. MUST NOT be NULL, .
    * @param node_to_insert the node to be inserted. , cannot be NULL.
    * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_node_insert_sibling_after(axiom_node_t  *om_node,
            const axutil_env_t *env,
            axiom_node_t  * node_to_insert);

    /**
    * Inserts a sibling node before the given current node
    * @param om_node node to whom the sibling to be inserted. , cannot be NULL.
    * @param env Environment. MUST NOT be NULL, .
    * @param node_to_insert the node to be inserted. , cannot be NULL.
    * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_node_insert_sibling_before(axiom_node_t  *om_node,
            const axutil_env_t *env,
            axiom_node_t  * node_to_insert);

    /**
    * Serializes the given node. This op makes the node go
    * through its children and  serialize them in order.
    * @param om_node node to be serialized.  cannot be NULL.
    * @param env Environment .MUST NOT be NULL.    
    * @param om_output AXIOM output handler to be used in serializing
    * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_node_serialize(axiom_node_t  * om_node,
            const axutil_env_t *env,
            struct axiom_output *om_output);

    /** get parent of om_node
    *@om_node node 
    *@param env environment
    *@return pointer to parent node of om_node, return NULL if no parent exists or
    *        when an error occured.
    */

    AXIS2_EXTERN axiom_node_t * AXIS2_CALL
    axiom_node_get_parent(axiom_node_t  *om_node,
            const axutil_env_t *env);

    /**
    * get the first child of om_node
    * @param om_node node
    * @param env environment must not be null.
    * @returns pointer to first child node , NULL is returned on error with 
    *                     error code set in environments error
    */
    AXIS2_EXTERN axiom_node_t * AXIS2_CALL
    axiom_node_get_first_child(axiom_node_t  *om_node,
            const axutil_env_t *env);

	/**get the first AXIOM_ELEMENT in om_node
	 * @param om_node node
	 * @param env environment must not be null
	 * @returns pointer to first child om element, NULL is returned on error
	 * with error code set in environments error.
	 */
    AXIS2_EXTERN axiom_node_t * AXIS2_CALL
    axiom_node_get_first_element(axiom_node_t  *om_node,
            const axutil_env_t *env);

    /**
    * get the last child
    * @param om_node node
    * @param env environment, MUST NOT be NULL
    * @return pointer to last child of this node , return NULL on error.
    */
    AXIS2_EXTERN axiom_node_t * AXIS2_CALL
    axiom_node_get_last_child(axiom_node_t  *om_node,
            const axutil_env_t *env);
    /**
    * get the previous sibling 
    * @param om_node om_node struct 
    * @param env environment , must node be null
    * @returns a pointer to previous sibling , NULL if a previous sibling does not exits
    *                (happens when this node is the first child of a node )
    */
    AXIS2_EXTERN axiom_node_t * AXIS2_CALL
    axiom_node_get_previous_sibling(axiom_node_t  *om_node,
            const axutil_env_t *env);
    /**
    * get next sibling
    * @param om_node om_node struct
    * @param env environment, MUST NOT be NULL.
    * @return next sibling of this node.
    */
    AXIS2_EXTERN axiom_node_t * AXIS2_CALL
    axiom_node_get_next_sibling(axiom_node_t  *om_node,
            const axutil_env_t *env);
    /**
    * get the node type of this element
    * Node type can be one of AXIOM_ELEMENT, AXIOM_COMMENT, AXIOM_TEXT
    *      AXIOM_DOCTYPE, AXIOM_PROCESSING_INSTRUCTION
    * @param om_node  node of which node type is required
    * @param env environment
    * @return node type
    */
    AXIS2_EXTERN axiom_types_t AXIS2_CALL
    axiom_node_get_node_type(axiom_node_t  *om_node,
            const axutil_env_t *env);
    /**
    * get the struct contained in the node
    * IF the node is on type AXIOM_ELEMENT , this method returns
    * a pointer to  axiom_element_t struct contained
    * @param om_node node
    * @param env environment, MUST NOT be NULL.
    * @returns pointer to struct contained in the node
    *          returns NULL if no struct is contained 
    */
    AXIS2_EXTERN void* AXIS2_CALL
    axiom_node_get_data_element(axiom_node_t  *om_node,
            const axutil_env_t *env);
    /**
    * Indicates whether parser has parsed this information item completely or not 
    * @param om_node om_node struct
    * @param env environment, MUST NOT be NULL.
    * @returns AXIS2_TRUE if node is completly build, 
    *          AXIS2_FALSE if node is not completed
    */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_node_is_complete(axiom_node_t  *om_node,
            const axutil_env_t *env);
    /**
     * returns the associated document,
     * only valid if built using builder and for a node of type 
     * AXIOM_ELEMENT
     * returns null if no document is available
     * @param om_node 
     * @param env environment, MUST NOT be NULL.
     */
    AXIS2_EXTERN struct axiom_document* AXIS2_CALL
                axiom_node_get_document(axiom_node_t *om_node,
                        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_node_to_string(axiom_node_t *om_node,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_node_serialize_sub_tree(axiom_node_t *om_node,
        const axutil_env_t *env,
        struct axiom_output *om_output);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIOM_NODE_H */
