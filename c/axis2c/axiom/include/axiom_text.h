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

#ifndef AXIOM_TEXT_H
#define AXIOM_TEXT_H

#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_output.h>
#include <axiom_data_handler.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_text text
     * @ingroup axiom_om
     * @{
     */

    typedef struct axiom_text axiom_text_t;


    /**
      * Creates a new text struct
      * @param env Environment. 
      * @param parent parent of the new node. Optinal, can be NULL. 
      * The parent element must be of type AXIOM_ELEMENT
      * @param value Text value. Optinal, can be NULL.
      * @param comment_node This is an out parameter.  cannot be NULL.
      * Returns the node corresponding to the text struct created.
      * Node type will be set to AXIOM_TEXT  
      * @return pointer to newly created text struct 
      */
    AXIS2_EXTERN axiom_text_t *AXIS2_CALL
    axiom_text_create(const axutil_env_t *env,
        axiom_node_t *parent,
        const axis2_char_t *value,
        axiom_node_t ** node);

	/**
      * Creates a new text struct
      * @param env Environment. 
      * @param parent parent of the new node. Optinal, can be NULL. 
      * The parent element must be of type AXIOM_ELEMENT
      * @param value Text value string. Optinal, can be NULL.
      * @param comment_node This is an out parameter.  cannot be NULL.
      * Returns the node corresponding to the text struct created.
      * Node type will be set to AXIOM_TEXT  
      * @return pointer to newly created text struct 
      */
    AXIS2_EXTERN axiom_text_t *AXIS2_CALL
    axiom_text_create_str(const axutil_env_t *env,
        axiom_node_t *parent,
        axutil_string_t *value,
        axiom_node_t ** node);

    /**
      * Creates a new text struct for binary data (MTOM)
      * @param env Environment. 
      * @param parent parent of the new node. Optinal, can be NULL. 
      * The parent element must be of type AXIOM_ELEMENT
      * @param data_handler data handler. Optinal, can be NULL.
      * @param comment_node This is an out parameter.  cannot be NULL.
      * Returns the node corresponding to the text struct created.
      * Node type will be set to AXIOM_TEXT  
      * @return pointer to newly created text struct 
      */
    AXIS2_EXTERN axiom_text_t *AXIS2_CALL
    axiom_text_create_with_data_handler(const axutil_env_t *env,
        axiom_node_t * parent,
        axiom_data_handler_t* data_handler,
        axiom_node_t **node);

    /**
      * Free an axiom_text struct
      * @param env environment. 
      * @param om_text pointer to om text struct to be freed.
      * @return satus of the op. AXIS2_SUCCESS on success
      * AXIS2_FAILURE on error.
      */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_text_free(struct axiom_text *om_text,
        const axutil_env_t *env);

    /**
      * Serialize op
      * @param env environment. 
      * @param om_text pointer to om text struct to be serialized.
      * @param om_output AXIOM output handler to be used in serializing.
      * @return satus of the op. AXIS2_SUCCESS on success,
      * AXIS2_FAILURE on error
      */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_text_serialize(struct axiom_text *om_text,
            const axutil_env_t *env,
            axiom_output_t *om_output);

   /**
     * Sets the text value
     * @param om_text om_text struct
     * @param env environment.
     * @param value text
     * @return status of the op. AXIS2_SUCCESS on success,
     * AXIS2_FAILURE on error.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_text_set_value(struct axiom_text *om_text,
        const axutil_env_t *env,
        const axis2_char_t *value);

   /**
     * Gets text value 
     * @param om_text om_text struct
     * @param env environment.
     * @return text value , NULL is returned if there is no text value.
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axiom_text_get_value(struct axiom_text *om_text,
        const axutil_env_t *env);

	/**
     * Sets the text value
     * @param om_text om_text struct
     * @param env environment.
     * @param value string
     * @return status of the op. AXIS2_SUCCESS on success,
     * AXIS2_FAILURE on error.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_text_set_value_str(struct axiom_text *om_text,
        const axutil_env_t *env,
        axutil_string_t *value);

   /**
     * Gets text value 
     * @param om_text om_text struct
     * @param env environment.
     * @return text valu stringe , NULL is returned if there is no text value.
     */
    AXIS2_EXTERN axutil_string_t *AXIS2_CALL
    axiom_text_get_value_str(struct axiom_text *om_text,
        const axutil_env_t *env);

   /**
     * Sets optimized 
     * @param om_text pointer to om_text struct
     * @param env environment
     * @optimize optimize value
     * @returns AXIS2_SUCCESS
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_text_set_optimize(struct axiom_text *om_text,
        const axutil_env_t *env,
        axis2_bool_t optimize);

    /**
     * @param om_text text value
     * @param env environment
     * @param is_binary
     * @returns AXIS2_SUCCESS
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_text_set_is_binary(struct axiom_text *om_text,
        const axutil_env_t *env,
        const axis2_bool_t is_binary);

    AXIS2_EXTERN axiom_data_handler_t *AXIS2_CALL
    axiom_text_get_data_handler(struct axiom_text *om_text,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_text_get_content_id(struct axiom_text *om_text,
        const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIOM_TEXT_H */
