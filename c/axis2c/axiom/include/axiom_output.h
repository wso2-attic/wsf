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

#ifndef AXIOM_OUTPUT_H
#define AXIOM_OUTPUT_H

#include <axutil_utils_defines.h>
#include <axutil_utils.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_xml_writer.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_output output
     * @ingroup axiom_om
     * @{
     */

    /**
     * \brief output struct
     * The XML writer interface struct of om
     */
    typedef struct axiom_output axiom_output_t;
    struct axiom_text;

    /**
     * Creates AXIOM output struct 
     * @param env Environment. MUST NOT be NULL, .
     * @param xml_writer XML writer. 
     * @return a pointer to newly created output struct.
     */
    AXIS2_EXTERN axiom_output_t *AXIS2_CALL
    axiom_output_create(const axutil_env_t *env,
        axiom_xml_writer_t *xml_writer);

    /**
     *  Performs xml writing.
     *  Accepts variable number of args depending on the on AXIOM type to be serialized
     *  @param om_output Output struct to be used 
     *  @param env Environment. MUST NOT be NULL, 
     *  @param type one of the AXIOM types
     *  @param no_of_args number of arguments passed in the variable parameter list
     *  @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_output_write(axiom_output_t * om_output,
        const axutil_env_t *env,
        axiom_types_t type,
        int no_of_args, ...);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_output_write_optimized(axiom_output_t *om_output,
        const axutil_env_t *env,
        struct axiom_text *om_text);

    /**
     * Free om_output 
     * @param om_output om_output struct
     * @param env environment
     * @return status code AXIS2_SUCCESS on success,
     *  AXIS2_FAILURE otherwise 
     */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_output_free(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     * If the xml to be serialized is soap 11, this property is set to true
     * @param om_output pointer to om_output struct
     * @param env environment must not be NULL
     * @returns the output soap version 
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_output_is_soap11(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     * @returns true if the ignore_xml_declaration property is true   
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_output_is_ignore_xml_declaration(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     * Sets the ignore_xml_declaration property is true
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_output_set_ignore_xml_declaration(axiom_output_t *om_output,
        const axutil_env_t *env,
        axis2_bool_t ignore_xml_dec);

    /**
     * Sets the soap11  property to true
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_output_set_soap11(axiom_output_t *om_output,
        const axutil_env_t *env,
        axis2_bool_t soap11);

    /**
     * Sets xml_version property
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_output_set_xml_version(axiom_output_t *om_output,
        const axutil_env_t *env,
        axis2_char_t *xml_version);

    /**
     * @returns xml version property
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_output_get_xml_version(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     * Sets the char set encoding property
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_output_set_char_set_encoding(axiom_output_t *om_output,
        const axutil_env_t *env,
        axis2_char_t *char_set_encoding);

    /**
     * @returns the char set encoding property
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_output_get_char_set_encoding(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     * Sets the do optimize property true
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_output_set_do_optimize(axiom_output_t *om_output,
        const axutil_env_t *env,
        axis2_bool_t optimize);

    /**
     * Returns the xml writer
     */
    AXIS2_EXTERN axiom_xml_writer_t *AXIS2_CALL
    axiom_output_get_xml_writer(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     *  Returns the content type
     *  for soap11 'text/xml' etc..
     *  @param om_output
     *  @param env environemnt
     *  @returns content id
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axiom_output_get_content_type(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     * Writes the xml versio encoding 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_output_write_xml_version_encoding(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     * @returns whether the output is to be optimized 
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_output_is_optimized(axiom_output_t *om_output,
        const axutil_env_t *env);

    /** 
     * Returns the next content id
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_output_get_next_content_id(axiom_output_t *om_output,
        const axutil_env_t *env);

    /**
     * root content id
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_output_get_root_content_id(axiom_output_t *om_output,
        const axutil_env_t *env);


    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_output_get_mime_boundry(axiom_output_t *om_output,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_byte_t *AXIS2_CALL
    axiom_output_flush(axiom_output_t *om_output,
        const axutil_env_t *env,
        axis2_byte_t **output_stream,
        int *output_stream_size);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif                          /* AXIOM_OUTPUT_H */
