/*
 * Copyright 2005,2006 WSO2, Inc. http://wso2.com
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

#include <axiom_data_handler.h>
#include <AxisObject.h>

/**
 * @file OMDataHandler.h
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
    class OMDataHandler : public AxisObject
    {
    private:
        /**
         * @var _wsf_axiom_data_handler protected variable holds reference for
         * axiom_data_handler struct.
         */
        axiom_data_handler_t * _wsf_axiom_data_handler;

    public:
        /**
         * Creates data_handler struct.
         * @param file_name associated file name.
         * @param mime_type mime type.
         */
        OMDataHandler(std::string file_name, std::string mime_type);

        /**
         * Creates data_handler struct.
         * @param mime_type mime type.
         */
        OMDataHandler(std::string mime_type);

        /**
         * Creates data_handler struct.
         * @param mime_type mime type.
         */
        OMDataHandler();

        /**
         * Desctructor that frees resources.
         */
        ~OMDataHandler();

        /**
         * Method to get the reference to the axiom_data_handler struct.
         * @return reference to the axiom_data_handler struct.
         */
        axiom_data_handler_t * getAxiomDataHandler();

        /**
         * Method to set the reference to the axiom_data_handler struct.
         * @param data_handler reference to the axiom_data_handler struct.
         */
        void setAxiomDataHandler(axiom_data_handler_t * data_handler);

        /**
         * Gets content type.
         * @return content type.
         */
        std::string getContentType();

        /**
         * Method to get the input stream.
         * @return reference to input stream.
         */
        axis2_byte_t * getInputStream();

        /**
         * Method to get the input stream length.
         * @return length of input stream.
         */
        int getInputStreamLength();

        /**
         * Method to read into a stream.
         * @param output_stream reference to which the stream would be retrieved.
         * @param output_stream_length size of retrieved stream.
         * @return true if operation was successful, false otherwise.
         */
        bool read(axis2_byte_t ** output_stream, int * output_stream_length);

        /**
         * Method to write to a stream.
         * @param input_stream stream to use.
         * @param input_stream_len size of input stream.
         * @return true if operation was successful, false otherwise.
         */
        bool write(axis2_byte_t * input_stream, int input_stream_length);

        /**
         * Method to set file name.
         * @param file_name associated file name.
         * @return true if operation was successful, false otherwise.
         */
        bool setFileName(std::string file_name);
    };
    /** @} */
}
#endif // OMDATAHANDLER_H
