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

#ifndef AXIOM_XML_READER_H
#define AXIOM_XML_READER_H

/**
 *@file axiom_xml_reader.h
 *@brief this is the parser abstraction layer for axis2
 */

#include <axutil_env.h>
#include <axutil_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_xml_reader_ops axiom_xml_reader_ops_t;
    typedef struct axiom_xml_reader axiom_xml_reader_t;

    /**
      * @defgroup axiom_parser parser
      * @ingroup axiom
      * @{
      * @}
      */

    /**
     * @defgroup axiom_xml_reader XML reader
     * @ingroup axiom_parser
     * @{
     */

    typedef enum axiom_xml_reader_event_types
    {
        AXIOM_XML_READER_START_DOCUMENT = 0,
        AXIOM_XML_READER_START_ELEMENT,
        AXIOM_XML_READER_END_ELEMENT,
        AXIOM_XML_READER_SPACE,
        AXIOM_XML_READER_EMPTY_ELEMENT,
        AXIOM_XML_READER_CHARACTER,
        AXIOM_XML_READER_ENTITY_REFERENCE,
        AXIOM_XML_READER_COMMENT,
        AXIOM_XML_READER_PROCESSING_INSTRUCTION,
        AXIOM_XML_READER_CDATA,
        AXIOM_XML_READER_DOCUMENT_TYPE
    }axiom_xml_reader_event_types;

    /**
      * \brief AXIOM_XML_READER ops
      * Encapsulator struct for ops of axiom_xml_reader
      */

    struct axiom_xml_reader_ops
    {
        /**
         * causes the reader to read the next parse event. 
         * returns the event just read
         * @param parser axiom_xml_reader struct 
         * @param env    axutil_environment, MUST NOT be NULL
         * @returns one of the events defined in 
         *          axiom_xml_reader_event_types
         */

        int(AXIS2_CALL *
            next)(axiom_xml_reader_t *parser,
                const axutil_env_t *env);

        /**
        * free pull_parser
        * @param parser axiom_xml_reader struct 
        * @param env    axutil_environment MUST NOT be NULL 
        * @returns axis2_status_code
        */

        void (AXIS2_CALL *
        free)(axiom_xml_reader_t *parser,
                const axutil_env_t *env);
        /**
         * Get the Number of attributes in the current element 
         * @param parser axiom_xml_reader  
         * @param env    axutil_environment, MUST NOT be NULL.
         * @returns Number of attributes , AXIS2_FAILURE on error 
         */

        int(AXIS2_CALL *
            get_attribute_count)(axiom_xml_reader_t *parser,
                const axutil_env_t *env);


        /** This is used to get an attribute's localname using an index relative to
          * current element.The iterations are not zero based. 
          * To access the first attribute use 1 for parameter i
          * @param parser parser struct 
          * @param env environment struct
          * @param i attribute index
          * @returns the attribute localname 
          *          caller must free the value using axiom_xml_reader_xml_free macro       
          */
        axis2_char_t*(AXIS2_CALL *
            get_attribute_name_by_number)(axiom_xml_reader_t *parser,
                const axutil_env_t *env,
                int i);

        /** This is used to get an attribute's prefix using an index relative to
          * current element. The iterations are not zero based. 
          * To access the first attribute use 1 for parameter i
          * @param parser parser struct 
          * @param env environment, MUST NOT be NULL
          * @param i attribute index.
          * @returns the attribute prefix, returns NULL on error,  
          *          caller must free the value using axiom_xml_reader_xml_free macro       
          */

        axis2_char_t*(AXIS2_CALL *
            get_attribute_prefix_by_number)(axiom_xml_reader_t *parser,
                const axutil_env_t *env,
                int i);

        /** Gets an attribute's value using an index relative to
         * current element. The iterations are not zero based. 
         * To access the first attribute use 1 for parameter i
         * @param parser parser struct 
         * @param env environment, MUST NOT be NULL.
         * @param i attribute index
         * @returns the attribute value, returns NULL on error,
         *          caller must free the value using axiom_xml_reader_xml_free macro        
         */

        axis2_char_t*(AXIS2_CALL *
            get_attribute_value_by_number)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env,
                 int i);

        /** Gets an attribute's namespace uri using an index relative to
         * current element. The iterations are not zero based. 
         * To access the first attribute use 1 for parameter i
         * @param parser parser struct 
         * @param env environment struct
         * @param i attribute index
         * @returns the attribute value, returns NULL on error  
         *          caller must free the value using axiom_xml_reader_xml_free macro        
         */

        axis2_char_t*(AXIS2_CALL *
            get_attribute_namespace_by_number)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env,
                 int i);

        /** Returns the text value of current element
          * @param parser pointer to parser
          * @param env environment, MUST not be NULL
          * @returns Text Value, NULL on error 
          *          caller must free the value using axiom_xml_reader_xml_free macro 
          */
        axis2_char_t*(AXIS2_CALL *
            get_value)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env);

        /**
         * Returns the namespace count of current element 
         * @param parser parser struct 
         * @param env environment
         * @returns namespace count of current element,
         */
        int(AXIS2_CALL *
            get_namespace_count)(axiom_xml_reader_t *parser,
                const axutil_env_t *env);
        /**
         * Accesses the namespace uri of the namespaces declared in current element 
         * using an index 
         * @param parser parser struct 
         * @param env environment 
         * @param i index
         * @returns namespace uri of corresponding namespace
         * caller must free the value using axiom_xml_reader_xml_free macro        
         */
        axis2_char_t*(AXIS2_CALL *
            get_namespace_uri_by_number)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env,
                 int i);
        /**
         * Accesses the namespace prefix of the namespaces declared in current element 
         * using an index 
         * @param parser parser struct 
         * @param env environment 
         * @param i index
         * @returns namespace prefix of corresponding namespace 
         * caller must free the value using axiom_xml_reader_xml_free macro        
         */
        axis2_char_t*(AXIS2_CALL *
            get_namespace_prefix_by_number)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env,
                 int i);

        /**
         * Used to obtain the current element prefix
         * @param parser parser struct 
         * @param env environment struct
         * @returns prefix , NULL on error 
         * caller must free the value using axiom_xml_reader_xml_free macro
         */
        axis2_char_t*(AXIS2_CALL *
            get_prefix)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env);

        /**
         * Used to obtain the current element localname
         * @param parser parser struct 
         * @param env environment struct
         * @returns localname , NULL on error 
         *          caller must free the value using axiom_xml_reader_xml_free macro
         */
        axis2_char_t*(AXIS2_CALL *
            get_name)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env);

        /**
         * Used to get the processingInstruction target
         * @param parser parser struct
         * @param env environment, MUST NOT be NULL.
         * @returns target value of processingInstruction
         * caller must free the value using axiom_xml_reader_xml_free macro
         */
        axis2_char_t*(AXIS2_CALL *
             get_pi_target)(axiom_xml_reader_t *parser,
                  const axutil_env_t *env);

        /**
         * Gets the processingInstruction data
         * @param parser parser struct
         * @param env environment, MUST NOT be NULL.
         * @returns data of processingInstruction
         * caller must free the value using axiom_xml_reader_xml_free macro
         */
        axis2_char_t*(AXIS2_CALL *
            get_pi_data)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env);

        /**
         * Used to get the DTD 
         * @param parser pointer to pull parser struct
         * @param env environment, MUST NOT be NULL.
         * @return text of doctype declaration. NULL is returns of no data 
         * exists.
         */
        axis2_char_t*(AXIS2_CALL *
            get_dtd)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env);

        /**
         *  Free function , this function wraps the underlying parser's 
         *  xml free function. For freeing values obatined by calling
         *  pull parser api methods, This function must be used.
         * @param parser pointer to axiom_xml_reader
         * @param env environment, MUST NOT be NULL.
         * @param data data values to be destroyed
         * @return status of the op, AXIS2_SUCCESS on success,
         * AXIS2_FAILURE on error.
         */
        void(AXIS2_CALL *
            xml_free)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env,
                 void *data);

        /**
         * Gets the char set encoding of the parser 
         * @param parser xml parser
         * @param env environment
         * @returns char set encoding string or NULL in failure
         */

        axis2_char_t*(AXIS2_CALL *
            get_char_set_encoding)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env);

        /** Returns the namespace uri associated with current node */
        axis2_char_t*(AXIS2_CALL *
            get_namespace_uri)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env);

        axis2_char_t*(AXIS2_CALL *
            get_namespace_uri_by_prefix)(axiom_xml_reader_t *parser,
                 const axutil_env_t *env,
                 axis2_char_t *prefix);
    };

    /**
     * @brief axiom_xml_reader struct
      *   Axis2 OM pull_parser
     */
    struct axiom_xml_reader
    {
        const axiom_xml_reader_ops_t *ops;
    };

    /**
     * Creates an instance of axiom_xml_reader to parse
     * a file using an xml document in a file system
     * @param env environment struct, must not be null
     * @param filename url of an xml document
     * @returns a pointer to xml_pull_parser_t struct
     * NULL on error with error code set in the environment's error
     */
    AXIS2_EXTERN axiom_xml_reader_t *AXIS2_CALL
    axiom_xml_reader_create_for_file(const axutil_env_t *env,
        char *filename,
        const axis2_char_t *encoding);

    /**
     * This create an instance of axiom_xml_reader to
     * parse a xml document in a buffer. It takes a callback
     * function that takes a buffer and the size of the buffer
     * The user must implement a function that takes in buffer
     * and size and fill the buffer with specified size
     * with xml stream, parser will call this function to fill the
     * buffer on the fly while parsing.
     * @param env environment MUST NOT be NULL.
     * @param read_input_callback() callback function that fills
     * a char buffer with size @size
     * @param buffer a character buffer
     * @param size size of the buffer to be filled
     * @param encoding encoding scheme of the xml stream
     */
    AXIS2_EXTERN axiom_xml_reader_t *AXIS2_CALL
    axiom_xml_reader_create_for_io(const axutil_env_t *env,
        AXIS2_READ_INPUT_CALLBACK,
        AXIS2_CLOSE_INPUT_CALLBACK,
        void *ctx,
        const axis2_char_t *encoding);

    /**
     * Create an axiom_xml_reader_t using a buffer, which is the xml input
     * @param env environment, MUST not be NULL
     * @param buffer xml input string in a char buffer
     * @param size size of the @buffer
     * @param encoding encoding of the xml
     * @return pointer to axiom_xml_reader_t struct on success , NULL otherwise
     */
    AXIS2_EXTERN axiom_xml_reader_t *AXIS2_CALL
    axiom_xml_reader_create_for_memory(const axutil_env_t *env,
        void *container,
        int size,
        const axis2_char_t *encoding,
        int type);

    /**
     * init function initializes the parser
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_xml_reader_init();

    /**
     * parser cleanup function
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_xml_reader_cleanup();


AXIS2_EXTERN int AXIS2_CALL
axiom_xml_reader_next(axiom_xml_reader_t *parser,
    const axutil_env_t *env);

AXIS2_EXTERN void AXIS2_CALL 
axiom_xml_reader_free(axiom_xml_reader_t *parser,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
axiom_xml_reader_get_attribute_count(axiom_xml_reader_t *parser,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axiom_xml_reader_get_attribute_name_by_number(axiom_xml_reader_t *parser,
    const axutil_env_t *env,
    int i);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_attribute_prefix_by_number(axiom_xml_reader_t *parser,
    const axutil_env_t *env,
    int i);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_attribute_value_by_number(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     int i);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_attribute_namespace_by_number(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     int i);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_value(axiom_xml_reader_t *parser,
     const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL 
axiom_xml_reader_get_namespace_count(axiom_xml_reader_t *parser,
    const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_namespace_uri_by_number(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     int i);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_namespace_prefix_by_number(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     int i);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_prefix(axiom_xml_reader_t *parser,
     const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_name(axiom_xml_reader_t *parser,
     const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_pi_target(axiom_xml_reader_t *parser,
      const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_pi_data(axiom_xml_reader_t *parser,
     const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_dtd(axiom_xml_reader_t *parser,
     const axutil_env_t *env);

AXIS2_EXTERN void AXIS2_CALL 
axiom_xml_reader_xml_free(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     void *data);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_char_set_encoding(axiom_xml_reader_t *parser,
     const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_namespace_uri(axiom_xml_reader_t *parser,
     const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
axiom_xml_reader_get_namespace_uri_by_prefix(axiom_xml_reader_t *parser,
     const axutil_env_t *env,
     axis2_char_t *prefix);

    /** @} */


#ifdef __cplusplus
}
#endif

#endif  /* AXIOM_XML_READER_H */
