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

#ifndef AXIOM_STAX_BUILDER_H
#define AXIOM_STAX_BUILDER_H

#include <axiom_node.h>
#include <axiom_xml_reader.h>
#include <axiom_document.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_stax_builder stax builder
     * @ingroup axiom_om
     * @{
     */

    typedef struct axiom_stax_builder axiom_stax_builder_t;


    /**
      * Creates an stax builder
      * @param environment Environment. MUST NOT be NULL, .
      * @return a pointer to the newly created builder struct. 
      */
    AXIS2_EXTERN axiom_stax_builder_t * AXIS2_CALL
    axiom_stax_builder_create(const axutil_env_t *env,
        axiom_xml_reader_t *parser);

    /**
      * Builds the next node from stream. Moves pull parser forward and reacts 
      * to events.
      * @param environment Environment. MUST NOT be NULL.
      * @param builder pointer to stax builder struct to be used
      * @return a pointer to the next node, or NULL if there are no more nodes.
      *     On erros sets the error and returns NULL.
      */
    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_stax_builder_next(struct axiom_stax_builder *builder,
        const axutil_env_t *env);

    /**
      * Discards the element that is being built currently.
      * @param environment Environment. MUST NOT be NULL, .
      * @param builder pointer to stax builder struct to be used
      * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE.
      */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_stax_builder_discard_current_element(struct axiom_stax_builder *builder,
            const axutil_env_t *env);
   
   /**
     * Free op
     * @param builder pointer to builder struct
     * @param env environment, MUST NOT be NULL
     * @return status of the op AXIS2_SUCCESS on success,
     *     AXIS2_FAILURE on error.
     */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_stax_builder_free(struct axiom_stax_builder *builder,
        const axutil_env_t *env);

   /** Gets the document associated with the builder
     * @param builder axiom_stax_builder 
     * @param env environment 
     * @return pointer to document struct associated with builder
     *     NULL if there is no document associated with the builder,
     *     NULL if an error occured.
     */
    AXIS2_EXTERN axiom_document_t *AXIS2_CALL
    axiom_stax_builder_get_document(struct axiom_stax_builder *builder,
        const axutil_env_t *env);

   /**
     * builder is finished building om structure
     */

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_stax_builder_is_complete(struct axiom_stax_builder* builder,
        const axutil_env_t *env);

   /**
     * moves the reader to next event and returns the token returned
     * by the xml_reader , returns -1 on error 
     */
    AXIS2_EXTERN int AXIS2_CALL
    axiom_stax_builder_next_with_token(struct axiom_stax_builder *builder,
        const axutil_env_t *env);

    /** @} */


#ifdef __cplusplus
}
#endif


#endif                          /* AXIOM_STAX_BUILDER_H */
