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

#ifndef AXIOM_NAMESPACE_H
#define AXIOM_NAMESPACE_H

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axiom_output.h>
#include <axutil_string.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_namespace namespace
     * @ingroup axiom_om
     * @{
     */

    typedef struct axiom_namespace axiom_namespace_t;

    /**
      * Creates a namespace struct
      * @param uri namespace URI
      * @param prefix namespace prefix
      * @return a pointer to newly created namespace struct
      */
    AXIS2_EXTERN axiom_namespace_t *AXIS2_CALL
    axiom_namespace_create(const axutil_env_t *env,
        const axis2_char_t * uri,
        const axis2_char_t *prefix);

    /**
      * Frees given AXIOM namespcae
      * @param om_namespace namespace to be freed.
      * @param env Environment. MUST NOT be NULL.
      * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE.
      */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_namespace_free(struct axiom_namespace *om_namespace,
        const axutil_env_t *env);

    /**
      * Compares two namepsaces
      * @param om_namespace first namespase to be compared
      * @param env Environment. MUST NOT be NULL.
      * @param om_namespace1 second namespace to be compared
      * @return AXIS2_TRUE if the two namespaces are equal,AXIS2_FALSE otherwise
      */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_namespace_equals(struct axiom_namespace *om_namespace,
        const axutil_env_t *env,
        struct axiom_namespace *om_namespace1);

    /**
      * Serializes given namespace 
      * @param om_namespace namespace to be serialized.
      * @param env Environment. MUST NOT be NULL.
      * @param om_output AXIOM output handler to be used in serializing
      * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE.
      */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_namespace_serialize(struct axiom_namespace *om_namespace,
        const axutil_env_t *env,
        axiom_output_t * om_output);

    /**
      * @param om_namespace pointer to om_namespace struct
      * @param env environment , MUST NOT be NULL.
      * @returns namespace uri , NULL on error
      */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_namespace_get_uri(struct axiom_namespace *om_namespace,
        const axutil_env_t *env);

    /**
      * @param om_namespace pointer to om namespace struct
      * @param env  environment, MUST NOT be NULL
      * @return prefix , NULL on error
      */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_namespace_get_prefix(struct axiom_namespace *om_namespace,
        const axutil_env_t *env);

    /**
      * Clones an om_namespace struct
      * @param om_namespace pointer to namespace struct
      * @param env environment
      * @returns axiom_namespace on success , NULL on error
      */
    AXIS2_EXTERN struct axiom_namespace *AXIS2_CALL
    axiom_namespace_clone(struct axiom_namespace *om_namespace,
        const axutil_env_t *env);

    /**
      * to string , returns the string by combining namespace_uri,
      * and prefix seperated by a '|' character
      * @param om_namespace 
      * @param env environment
      * @returns pointer to string , This is a property of namespace,
      * should not be freed by user
      */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_namespace_to_string(struct axiom_namespace *om_namespace,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_namespace_increment_ref(struct axiom_namespace *om_namespace,
        const axutil_env_t *env);

    AXIS2_EXTERN axiom_namespace_t *AXIS2_CALL
    axiom_namespace_create_str(const axutil_env_t *env,
        axutil_string_t * uri,
        axutil_string_t * prefix);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_namespace_set_uri_str(axiom_namespace_t *om_namespace,
        const axutil_env_t *env,
        axutil_string_t *uri);

    AXIS2_EXTERN axutil_string_t *AXIS2_CALL
    axiom_namespace_get_uri_str(axiom_namespace_t *om_namespace,
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_string_t *AXIS2_CALL
    axiom_namespace_get_prefix_str(axiom_namespace_t *om_namespace,
        const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIOM_NAMESPACE */
