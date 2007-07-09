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

#ifndef AXIOM_SOAP_HEADER_BLOCK_H
#define AXIOM_SOAP_HEADER_BLOCK_H


/**
 * @file axiom_soap_header_block.h
 * @brief axiom_soap_header_block struct
 */
#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axutil_array_list.h>
#include <axiom_soap_header.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_soap_header_block axiom_soap_header_block_t;

    /**
     * @defgroup axiom_soap_header_block soap header block
     * @ingroup axiom_soap
     * @{
     */

    /**
    * creates a soap struct
    * @param env Environment. MUST NOT be NULL
    * this is an internal function.
    */
    AXIS2_EXTERN axiom_soap_header_block_t * AXIS2_CALL
    axiom_soap_header_block_create_with_parent(const axutil_env_t *env,
            const axis2_char_t *localname,
            axiom_namespace_t *ns,
            struct axiom_soap_header *parent);

    /**
      * Free an axiom_soap_header_block
      * @param  header_block pointer to soap_header_block struct
      * @param  env Environment. MUST NOT be NULL
      * @return satus of the op. AXIS2_SUCCESS on success 
      *         else AXIS2_FAILURE
      */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_soap_header_block_free(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_header_block_set_role(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env,
            axis2_char_t *uri);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_header_block_set_must_understand_with_bool(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env,
            axis2_bool_t must_understand);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_header_block_set_must_understand_with_string(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env,
            axis2_char_t *must_understand);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_soap_header_block_get_must_understand(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_soap_header_block_is_processed(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_header_block_set_processed(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_soap_header_block_get_role(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_header_block_set_attribute(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env,
            const axis2_char_t *attr_name,
            const axis2_char_t *attr_value,
            const axis2_char_t *soap_envelope_namespace_uri);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_soap_header_block_get_attribute(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env,
            const axis2_char_t *attr_name,
            const axis2_char_t *soap_envelope_namespace_uri);

    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_soap_header_block_get_base_node(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env);

    AXIS2_EXTERN int AXIS2_CALL
    axiom_soap_header_block_get_soap_version(axiom_soap_header_block_t *header_block,
            const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif
#endif /* AXIOM_SOAP_HEADER_BLOCK_H */
