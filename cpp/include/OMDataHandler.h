/*
 * Copyright 2005-2009 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OMDATAHANDLER_H
#define OMDATAHANDLER_H

#include <WSFDefines.h>
#include <axiom_data_handler.h>

/**
 * @file OMDataHandler.h
 * @brief OMDataHandler class reperesents non xml data (text,binary) within axiom.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup om_data_handler OM Data Handler
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class OMDataHandler This class provides an interface to manipulate data in
     * different sources and formats. It provides mechanisms of obtaining streams, reading
     * and writing to files etc. This class has a great deal of importance with respect
     * to attachments.
     */
    class OMDataHandler 
    {
    private:
        /**
         * _wsf_axiom_data_handler protected variable holds reference for
         * axiom_data_handler struct.
         */
        axiom_data_handler_t * _wsf_axiom_data_handler;

    public:
        /**
         * Constructor for OMDataHandler.
         * @param file_name associated file name.
         * @param mime_type mime type.
         */
        WSF_EXTERN WSF_CALL OMDataHandler(std::string file_name, std::string mime_type);

        /**
         * Constructor for OMDataHandler. 
         * @param mime_type mime type.
         */
        WSF_EXTERN WSF_CALL OMDataHandler(std::string mime_type);

        /**
         * Constructor for  OMDataHandler with no arguments.
         */
        WSF_EXTERN WSF_CALL OMDataHandler();

        /**
         * Destructor that frees resources.
         */
        WSF_CALL ~OMDataHandler();

        /**
         * Method to get the reference to the axiom_data_handler struct.
         * @return reference to the axiom_data_handler struct.
         */
        axiom_data_handler_t * WSF_CALL getAxiomDataHandler();

        /**
         * Method to set the reference to the axiom_data_handler struct.
         * @param data_handler reference to the axiom_data_handler struct.
         */
        void WSF_CALL setAxiomDataHandler(axiom_data_handler_t * data_handler);

        /**
         * Gets content type.
         * @return content type.
         */
        WSF_EXTERN std::string WSF_CALL getContentType();

        /**
         * Method to get the input stream.
         * @return reference to input stream.
         */
        WSF_EXTERN axis2_byte_t * WSF_CALL getInputStream();

        /**
         * Method to get the input stream length.
         * @return length of input stream.
         */
        WSF_EXTERN int WSF_CALL getInputStreamLength();

        /**
         * Method to read into a stream.
         * @param output_stream reference to which the stream would be retrieved.
         * @param output_stream_length size of retrieved stream.
         * @return true if operation was successful, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL read(axis2_byte_t ** output_stream, size_t * output_stream_length);

        /**
         * Method to write to a stream.
         * @param input_stream stream to use.
         * @param input_stream_length size of input stream.
         * @return true if operation was successful, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL write(axis2_byte_t * input_stream, int input_stream_length);

        /**
         * Method to set file name.
         * @param file_name associated file name.
         * @return true if operation was successful, false otherwise.
         */
        WSF_EXTERN bool WSF_CALL setFileName(std::string file_name);
	/**
	* Returns whether the attachment is cached or not                                                   
	* @returns true if attachment is cached and false otherwise 
	*/
	WSF_EXTERN bool WSF_CALL isCached();
	/**
	* Write to a file.The filename is the file to be written.                  
	* @param filename Name of the file to which the binary content will be written by the DataHandler.
	* Returns the true if the operation is successful, false otherwise
	*/
	WSF_EXTERN bool WSF_CALL writeTo(std::string filename);

		
    };
    /** @} */
}
#endif // OMDATAHANDLER_H
