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

#ifndef AXIOM_COMMENT_H
#define AXIOM_COMMENT_H

/**
 * @file axiom_comment.h
 * @brief defines axiom_comment_t struct, and manipulation functions
 */

#include <axiom_node.h>
#include <axiom_output.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /**
     * @defgroup axiom_comment comment
     * @ingroup axiom_om
     * @{
     */


    typedef struct axiom_comment axiom_comment_t;

    /**
      * Creates a comment struct
      * @param env Environment. MUST NOT be NULL,
      * @param parent This is the parent node of the comment is any, can be NULL.
      * @param value comment text
      * @param node This is an out parameter.cannot be NULL.
      *        Returns the node corresponding to the comment created.
      *        Node type will be set to AXIOM_COMMENT
      * @return a pointer to the newly created comment struct
      */
    AXIS2_EXTERN axiom_comment_t * AXIS2_CALL
    axiom_comment_create(const axutil_env_t *env,
            axiom_node_t *parent,
            const axis2_char_t *value,
            axiom_node_t **node);

    /**
      * Free a axis2_comment_t struct
      * @param om_comment pointer to axis2_commnet_t struct to be freed
      * @param env Environment. MUST NOT be NULL.
      * @return satus of the op. 
      *                AXIS2_SUCCESS on success ,AXIS2_FAILURE on error.
      */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_comment_free(struct axiom_comment *om_comment,
            const axutil_env_t *env);
    /** get the comments data
     * @param om_comment a pointer to axiom_comment_t struct
     * @param env environment, MUST NOT be NULL 
     * @returns comment text
     */

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_comment_get_value(struct axiom_comment *om_comment,
            const axutil_env_t *env);
    /**
     * set comment data
     * @param om_comment pointer to axiom_comment_t struct
     * @param env environment, MUST NOT be NULL.
     * @param value comment text
     * @returns AXIS2_SUCCESS on success , AXIS2_FAILURE on error
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_comment_set_value(struct axiom_comment *om_comment,
            const axutil_env_t *env,
            const axis2_char_t* value);
    /**
     *  serialize function 
     *  @param om_comment pointer to axiom_comment_t struct
     *  @param env environment, MUST NOT be NULL.
     *  @param om_output pointer to om_output_t struct
     *  @return AXIS2_SUCCESS on success, AXIS2_FAILURE on error.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_comment_serialize(struct axiom_comment *om_comment,
            const axutil_env_t *env,
            axiom_output_t *om_output);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIOM_COMMENT_H */
