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

#ifndef AXIS2_DESC_H
#define AXIS2_DESC_H

/** 
 * @defgroup axis2_description description
 * @ingroup axis2_desc
 * Base struct of description hierarchy. Encapsulates common data and functions
 * of the description hierarchy.
 * @{
 */

#include <axutil_param_container.h>
#include <axutil_hash.h>
#include <axis2_description.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name of struct axis2_desc */
    typedef struct axis2_desc axis2_desc_t;

	/**
     * Creates a description struct instance.    
     * @param env pointer to environment struct
     * @return pointer to newly created description
     */
    AXIS2_EXTERN axis2_desc_t *AXIS2_CALL
    axis2_desc_create (const axutil_env_t *env);

    /** 
     * Frees description struct.
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_desc_free(axis2_desc_t *desc,
        const axutil_env_t *env);

    /**
     * Adds given parameter to the list of parameters.
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @param param pointer to parameter
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_desc_add_param(axis2_desc_t *desc,
        const axutil_env_t *env,
        axutil_param_t *param);

    /**
     * Gets named parameter.
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @param param_name parameter name string
     * @return pointer to named parameter, NULL if it does not exist
     */
    AXIS2_EXTERN axutil_param_t *AXIS2_CALL
    axis2_desc_get_param(const axis2_desc_t *desc,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /**
     * Gets all parameters stored in description.
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @return pointer to array list containing the list of parameters
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_desc_get_all_params(const axis2_desc_t *desc,
        const axutil_env_t *env);

    /**
     * Checks if a named parameter is locked.
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @param param_name parameter name string
     * @return AXIS2_TRUE if parameter is locked, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_desc_is_param_locked(const axis2_desc_t *desc,
        const axutil_env_t *env,
        const axis2_char_t *param_name);

    /**
     * Adds child to the description. The type of children is based on the
     * level of the description hierarchy. As an example, service has 
     * children of type operation, service group has children of type 
     * service
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @param key key with which the child is to be added
     * @param child child to be added
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_desc_add_child(const axis2_desc_t *desc,
        const axutil_env_t *env,
        const axis2_char_t *key,
        const void *child);

    /**
     * Gets all children. 
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @return pointer to hash map containing children
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_desc_get_all_children(const axis2_desc_t *desc,
        const axutil_env_t *env);

    /**
     * Gets child with given key.
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @param key key with which the child is stored
     * @return pointer to child, returned as a void* value, need to cast to 
     * correct type
     */
    AXIS2_EXTERN void *AXIS2_CALL
    axis2_desc_get_child(const axis2_desc_t *desc,
        const axutil_env_t *env,
        const axis2_char_t *key);

    /**
     * Removes the name child.
     * @param desc pointer to description
     * @param env pointer to environment struct
     * @param key key that represents the child to be removed
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_desc_remove_child(const axis2_desc_t *desc,
        const axutil_env_t *env,
        const axis2_char_t *key);
    
/** @} */
#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_DESC_H */
