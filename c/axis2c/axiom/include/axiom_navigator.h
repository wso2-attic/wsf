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

#ifndef AXIOM_NAVIGATOR_H
#define AXIOM_NAVIGATOR_H

#include <axutil_utils.h>
#include <axutil_env.h>
#include <axiom_node.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_navigator  navigator
     * @ingroup axiom_om
     * @{
     */

    typedef struct axiom_navigator axiom_navigator_t;

    /** Creates an axiom_navigator
     * @param env environment MUST not be NULL
     * @param node a pointer to axiom_node_t struct 
     * which is to be navigated
     * @returns a pointer to axiom_navigator_t struct
     * or returns NULL on error
     */
    AXIS2_EXTERN axiom_navigator_t *AXIS2_CALL
    axiom_navigator_create(const axutil_env_t *env,
        axiom_node_t *node);

    /**
     * free function , free the axiom_navigator struct
     * @param om_navigator axiom_navigator_struct
     * @param env environment MUST not be NULL
     * @returns AXIS2_SUCCESS 
     */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_navigator_free(axiom_navigator_t *om_navigator,
        const axutil_env_t *env);

    /**
     * Returns the navigable status 
     * @param  om_navigator axiom_navigator_struct
     * @param env environment MUST not be NULL
     * @returns AXIS2_TRUE if the om is navigable 
     * otherwise returns AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_navigator_is_navigable(axiom_navigator_t *om_navigator,
        const axutil_env_t *env);

    /**
     * Returns the build status of this node 
     * if the node is completly build returns AXIS2_TRUE
     * otherwise AXIS2_FALSE
     * @param om_navigator axiom_navigator struct
     * @param env environment MUST not be NULL
     * @return AXIS2_TRUE if this node is completly built
     * otherwise return AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_navigator_is_completed(axiom_navigator_t *om_navigator,
        const axutil_env_t *env);

    /**
     * gets the next node 
     * @param om_navigator om_navigaot struct 
     * @param env environment MUST not be NULL
     * @returns axiom_node_t pointer in the sequence of preorder travasal 
     * however the an element node is treated slightly differently
     * Once the om_element type om node is passed it returns the same om_node 
     * pointer in the next , returns NULL on error or if there is no more nodes
     */

    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_navigator_next(axiom_navigator_t *om_navigator,
        const axutil_env_t *env);

    /**
     * method visited 
     * @param om_navigator om_navigaot struct
     * @param env environment MUST not be NULL
     * @returns AXIS2_TRUE if this node is alrady visited
     * otherwise AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_navigator_visited(axiom_navigator_t *om_navigator,
        const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIOM_NAVIGATOR_H */
