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

#ifndef AXIS2_CTX_H
#define AXIS2_CTX_H

/**
 * @defgroup axis2_context context hierarchy
 * @ingroup axis2
 * @{
 * @}
 */

/** 
 * @defgroup axis2_ctx context
 * @ingroup axis2_context
 * context is the base struct of all the context related structs. This struct 
 * encapsulates the common operations and data for all context types. All the 
 * context types, configuration, service group, service and operation has the
 * base of type context. 
 * @{
 */

#include <axis2_defines.h>
#include <axutil_hash.h>
#include <axutil_env.h>
#include <axutil_property.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_ctx */
    typedef struct axis2_ctx axis2_ctx_t;

    /**
     * Creates a context struct.
     * @param env pointer to environment struct
     * @return pointer to newly created context
     */
    AXIS2_EXTERN axis2_ctx_t *AXIS2_CALL 
    axis2_ctx_create(const axutil_env_t *env);

    /**
     * Sets a property with the given key.
     * @param ctx pointer to context struct
     * @param env pointer to environment struct
     * @param key key string to store the property with
     * @param value pointer to property to be stored, context assumes the 
     * ownership of the property
     * @param persistent persist ency status, AXIS2_TRUE if the value is to 
     * be stored in the resistant store, AXIS2_FALSE if it is to be stored 
     * in the non-persistent store
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t  AXIS2_CALL
    axis2_ctx_set_property(struct axis2_ctx *ctx,
        const axutil_env_t *env,
        const axis2_char_t *key,
        axutil_property_t *value);

    /**
     * Gets the property with the given key.
     * @param ctx pointer to context struct
     * @param env pointer to environment struct
     * @param key key string
     * @param persistent persistence status, AXIS2_TRUE if the value is to 
     * be retrieved from the persistent store, AXIS2_FALSE if it is to be 
     * retrieved from the non-persistent store
     * @return pointer to property struct corresponding to the given key
     */
    AXIS2_EXTERN axutil_property_t *AXIS2_CALL
    axis2_ctx_get_property(const axis2_ctx_t *ctx,
        const axutil_env_t *env,
        const axis2_char_t *key);

    /**
     * Gets the non-persistent map of properties.
     * @param ctx pointer to context struct
     * @param env pointer to environment struct
     * @return pointer to the hash map which stores the non-persistent
     * properties
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_ctx_get_property_map(const axis2_ctx_t *ctx,
        const axutil_env_t *env);

    /**
     * Gets all properties stored within context. 
     * @param ctx pointer to context struct
     * @param env pointer to environment struct
     * @return pointer to hash table containing all properties
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_ctx_get_all_properties(const axis2_ctx_t *ctx,
        const axutil_env_t *env);


    /**
     * Frees context struct.
     * @param ctx pointer to context struct
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_ctx_free(axis2_ctx_t *ctx,
        const axutil_env_t *env);

    /**
     * Sets non-persistent map of properties.
     * @param ctx pointer to context struct
     * @param env pointer to environment struct
     * @param map pointer to hash map, context assumes ownership of the map
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */ 
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_ctx_set_property_map(struct axis2_ctx *ctx,
        const axutil_env_t *env,
        axutil_hash_t *map);

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_CTX_H */
