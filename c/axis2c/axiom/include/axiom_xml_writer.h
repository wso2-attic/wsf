/*
 *   Copyright 2004,2005 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

#ifndef AXIOM_XML_WRITER_H
#define AXIOM_XML_WRITER_H

/**
 *@file axiom_xml_writer.h
 *@brief this is the parser abstraction layer for axis2
 */

#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_xml_writer_ops axiom_xml_writer_ops_t;
    typedef struct axiom_xml_writer axiom_xml_writer_t;

    /**
     * @defgroup axiom_xml_writer XML writer
     * @ingroup axiom_parser
     * @{
     */



    /**
      * \brief axiom_xml_writer ops
      * Encapsulator struct for ops of axiom_xml_writer
      */

    struct axiom_xml_writer_ops
    {
        /**
         * Free xml writer
         * @param writer pointer to xml_writer struct to be freed
         * @param env environment, MUST NOT be NULL.
         * @returns status of the op. 
         *       AXIS2_SUCCESS on success and AXIS2_FAILURE on error
         */

        void (AXIS2_CALL *
        free)(axiom_xml_writer_t *writer,
            const axutil_env_t *env);
        /**
         *  Write a start tag to output stream with localname.
         *  Internally the writer keeps track of the opened tags 
         *  @param writer pointer to xml writer struct
         *  @param env environment. MUST NOT be NULL.
         *  @param localname localname of the tag, May not be NULL.
         *  @return the status of the op, AXIS2_SUCCESS on success
                     AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_start_element)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname);
        /**
         *  write an end tag to the output relying on the internal
         *  state of writer to determine the prefix and localname of
         *  the element
         *  @param writer xml_writer struct
         *  @param env environment, MUST NOT be NULL.
         *  @return status of the op. AXIS2_SUCCESS on success.
         *           AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                end_start_element)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env);
        /**
         * Write an element tag with localname and namespace uri 
         * @param writer pointer to xml writer struct
         * @param env environment struct
         * @param localname localname of the tag, May not be null.
         * @param namespace_uri the namespace URI of the the pefix
         *        to use.may not be null.
         * @returns status of the op, AXIS2_SUCCESS on success.
         *          AXIS2_FAILURE on error
         */
        axis2_status_t(AXIS2_CALL *
                write_start_element_with_namespace)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname,
                        axis2_char_t *namespace_uri);

        /**
         * write a start tag to output
         * @param writer pointer to xml_writer struct
         * @param environment, MUST NOT be NULL.
         * @param localname localname of the tag, May not be null.
         * @param namespace_uri namespace to bind the prefix to
         * @param prefix the prefix to the tag.May not be NULL.
         * @return status of the op 
                   AXIS2_SUCCESS on success. AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_start_element_with_namespace_prefix)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname,
                        axis2_char_t *namespace_uri,
                        axis2_char_t *prefix);
        /**
         * write an element tag with localname 
         * @param writer xml_writer
         * @param env environment
         * @param localname localname 
         * @return status of the op AXIS2_SUCCESS on success,
         *                AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_empty_element)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname);
        /**
         * write empty_element with localname and namespace uri.
         * @param writer xml writer
         * @param env environment
         * @param localname localname 
         * @param namespace uri
         * @return status of the op, AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */

        axis2_status_t(AXIS2_CALL *
                write_empty_element_with_namespace)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname,
                        axis2_char_t *namespace_uri);
        /**
         * write empty element with namespace uri and prefix 
         * @param writer xml_writer
         * @param env environment
         * @param localname localname
         * @param namespace_uri namespace uri 
         * @param prefix prefix
         * @return status of the op, AXIS2_SUCCESS on success,
         *                    AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_empty_element_with_namespace_prefix)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname,
                        axis2_char_t *namespace_uri,
                        axis2_char_t *prefix);
        /**
         * write end tag with correct localname prefix resolved internally 
         * @param writer xml writer
         * @param env environment
         * @return status of the op, AXIS2_SUCCESS on success,
         *            AXIS2_FAILURE on failure 
         */
        axis2_status_t(AXIS2_CALL *
                write_end_element)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env);
        /**
         * write end document
         * @param writer xml writer
         * @param env environment
         * @return status of the op AXIS2_SUCCESS on success,
         *              AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_end_document)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env);
        /**
         * write attribute with localname and value
         * @param writer writer
         * @param env environment
         * @param localname localname 
         * @param value text value of attribute
         * @return status of the op AXIS2_SUCCESS on success,
         *                 AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_attribute)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname,
                        axis2_char_t *value);
        /**
         *  @param writer
         *  @param env environment
         *  @param localname
         *  @param value text value of attribute
         *  @param namespace uri namespace uri
         *  @return status code of the op AXIS2_SUCCESS on success,
         *                    AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_attribute_with_namespace)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname,
                        axis2_char_t *value,
                        axis2_char_t *namespace_uri);
        /**
         * @param writer xml_writer
         * @param env environment
         * @param localname localname
         * @param value text value of attribute
         * @param namespace uri namespaceuri
         * @param prefix prefix 
         */
        axis2_status_t(AXIS2_CALL *
                write_attribute_with_namespace_prefix)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *localname,
                        axis2_char_t *value,
                        axis2_char_t *namespace_uri,
                        axis2_char_t *prefix);
        /**
         * @param writer xml_writer
         * @param env environment
         * @param prefix prefix 
         * @param namespace uri namespaceuri
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */

        axis2_status_t(AXIS2_CALL *
                write_namespace)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *prefix,
                        axis2_char_t *namespace_uri);
        /**
         * @param writer xml_writer
         * @param env environment
         * @param namespace uri namespaceuri
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */

        axis2_status_t(AXIS2_CALL *
                write_default_namespace)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *namespace_uri);
        /**
         * @param writer xml_writer
         * @param env environment
         * @param value value
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */


        axis2_status_t(AXIS2_CALL *
                write_comment)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *value);
        /**
         * @param writer xml_writer
         * @param env environment
         * @param target pi target 
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */


        axis2_status_t(AXIS2_CALL *
                write_processing_instruction)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *target);

        /**
         * @param writer xml_writer
         * @param env environment
         * @param target pi target
         * @param data  pi data
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */

        axis2_status_t(AXIS2_CALL *
                write_processing_instruction_data)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *target,
                        axis2_char_t *data);

        /**
         * @param writer xml_writer
         * @param env environment
         * @param data  cdata
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_cdata)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *data);


        /**
         * @param writer xml_writer
         * @param env environment
         * @param dtd  dtd
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_dtd)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *dtd);


        /**
         * @param writer xml_writer
         * @param env environment
         * @param name name
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_entity_ref)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *name);

        /**
         * @param writer xml_writer
         * @param env environment
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_start_document)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env);


        /**
         * @param writer xml_writer
         * @param env environment
         * @param version version 
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_start_document_with_version)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *version);

        /**
         * @param writer xml_writer
         * @param env environment
         * @param version version
         * @param encoding encoding
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_start_document_with_version_encoding)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *version,
                        axis2_char_t *encoding);

        /**
         * @param writer xml_writer
         * @param env environment
         * @param text text 
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_characters)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *text);

        /**
         * @param writer xml_writer
         * @param env environment
         * @param uri uri
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_char_t*(AXIS2_CALL *
                get_prefix)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *uri);

        /**
         * @param writer xml_writer
         * @param env environment
         * @param prefix prefix
         * @param uri uri
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                set_prefix)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *prefix,
                        axis2_char_t *uri);

        /**
         * @param writer xml_writer
         * @param env environment
         * @param uri uri
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                set_default_prefix)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *uri);

        /**
         * @param writer xml_writer
         * @param env environment
         * @param text text
         * @param in_attr 
         * @return status of op AXIS2_SUCCESS on success,
         *               AXIS2_FAILURE on error.
         */
        axis2_status_t(AXIS2_CALL *
                write_encoded)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *text,
                        int in_attr);

        void*(AXIS2_CALL *
                get_xml)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env);

        unsigned int(AXIS2_CALL *
                get_xml_size)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env);

        int(AXIS2_CALL *
                get_type)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env);

        axis2_status_t(AXIS2_CALL *
                write_raw)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env,
                        axis2_char_t *content);
        axis2_status_t (AXIS2_CALL *
                flush)(axiom_xml_writer_t *writer,
                        const axutil_env_t *env);

    };

    /**
     * @brief axis2_pull_parser struct
      *   Axis2 OM pull_parser
     */

    struct axiom_xml_writer
    {
        const axiom_xml_writer_ops_t *ops;
    };

    /**
     *  create function for axiom_xml_writer
     *
     */
    AXIS2_EXTERN axiom_xml_writer_t * AXIS2_CALL
    axiom_xml_writer_create(const axutil_env_t *env,
            axis2_char_t *filename,
            axis2_char_t *encoding,
            int is_prefix_default,
            int compression);

    AXIS2_EXTERN axiom_xml_writer_t * AXIS2_CALL
    axiom_xml_writer_create_for_memory(const axutil_env_t *env,
            axis2_char_t *encoding,
            int is_prefix_default,
            int compression,
            int type);

AXIS2_EXTERN void AXIS2_CALL
axiom_xml_writer_free(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_end_start_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_element_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_element_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_empty_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_empty_element_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_empty_element_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_end_element(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_end_document(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_attribute(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_attribute_with_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value,
    axis2_char_t *namespace_uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_attribute_with_namespace_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *localname,
    axis2_char_t *value,
    axis2_char_t *namespace_uri,
    axis2_char_t *prefix);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *prefix,
    axis2_char_t *namespace_uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_default_namespace(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *namespace_uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_comment(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *value);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_processing_instruction(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *target);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_processing_instruction_data(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *target,
    axis2_char_t *data);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_cdata(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *data);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_dtd(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *dtd);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_entity_ref(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *name);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_document(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_document_with_version(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *version);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_start_document_with_version_encoding(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *version,
    axis2_char_t *encoding);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_characters(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *text);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
axiom_xml_writer_get_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_set_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *prefix,
    axis2_char_t *uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_set_default_prefix(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *uri);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_encoded(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *text,
    int in_attr);

AXIS2_EXTERN void* AXIS2_CALL
axiom_xml_writer_get_xml(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

AXIS2_EXTERN unsigned int AXIS2_CALL
axiom_xml_writer_get_xml_size(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
axiom_xml_writer_get_type(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_xml_writer_write_raw(axiom_xml_writer_t *writer,
    const axutil_env_t *env,
    axis2_char_t *content);

AXIS2_EXTERN axis2_status_t  AXIS2_CALL
axiom_xml_writer_flush(axiom_xml_writer_t *writer,
    const axutil_env_t *env);

    /** @} */


#ifdef __cplusplus
}
#endif

#endif /* AXIOM_XML_WRITER_H */
