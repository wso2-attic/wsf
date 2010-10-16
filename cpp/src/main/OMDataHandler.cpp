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

#include <stdio.h>
#include <WSFError.h>
#include <OMDataHandler.h>
using namespace std;
using namespace wso2wsf;

/** @brief setFileName
  *
  * @todo: document this function
  */
bool OMDataHandler::setFileName(std::string file_name)
{
    if (!_wsf_axiom_data_handler)
    {
        return false;
    }
// TODO (senaka#4#): report bug 2 axis and remove const_cast
    axis2_status_t status =
        axiom_data_handler_set_file_name(_wsf_axiom_data_handler, Environment::getEnv(), const_cast<char *>(file_name.c_str()));
    return (status == AXIS2_SUCCESS);
}

/** @brief write
  *
  * @todo: document this function
  */
bool OMDataHandler::write(axis2_byte_t * input_stream, int input_stream_length)
{
    if (!_wsf_axiom_data_handler)
    {
        return false;
    }
	/** the provided stream is duplicated here and set to the data handler since data handler owns the stream */
	axis2_byte_t *new_input_stream = (axis2_byte_t*)AXIS2_MALLOC(Environment::getEnv()->allocator, sizeof(axis2_byte_t)*input_stream_length);
	memcpy(new_input_stream, input_stream, input_stream_length);
    axis2_status_t status =
        axiom_data_handler_set_binary_data(_wsf_axiom_data_handler, Environment::getEnv(), new_input_stream, input_stream_length);
    if (status != AXIS2_SUCCESS)
    {
        return false;
    }
    return (status == AXIS2_SUCCESS);
}

/** @brief read
  *
  * @todo: document this function
  */
bool OMDataHandler::read(axis2_byte_t ** output_stream, size_t * output_stream_length)
{
    axis2_status_t status =
        axiom_data_handler_read_from(_wsf_axiom_data_handler, Environment::getEnv(), output_stream,output_stream_length);
    return (status == AXIS2_SUCCESS);
}

/** @brief getInputStreamLength
  *
  * @todo: document this function
  */
int OMDataHandler::getInputStreamLength()
{
    return (int)axiom_data_handler_get_input_stream_len(_wsf_axiom_data_handler, Environment::getEnv());
}

/** @brief getInputStream
  *
  * @todo: document this function
  */
axis2_byte_t * OMDataHandler::getInputStream()
{
    return axiom_data_handler_get_input_stream(_wsf_axiom_data_handler, Environment::getEnv());
}

/** @brief getContentType
  *
  * @todo: document this function
  */
string OMDataHandler::getContentType()
{
    axis2_char_t *contentType = axiom_data_handler_get_content_type(_wsf_axiom_data_handler, Environment::getEnv());
	if(contentType)
		return contentType;
	else 
		return "";
}

/** @brief ~OMDataHandler
  *
  * @todo: document this function
  */
 OMDataHandler::~OMDataHandler()
{
    if (_wsf_axiom_data_handler)
    {
        axiom_data_handler_free(_wsf_axiom_data_handler, Environment::getEnv());
    }
}

/** @brief OMDataHandler
  *
  * @todo: document this function
  */
 OMDataHandler::OMDataHandler()
{
    _wsf_axiom_data_handler = axiom_data_handler_create(Environment::getEnv(), NULL, NULL);
}

/** @brief OMDataHandler
  *
  * @todo: document this function
  */
 OMDataHandler::OMDataHandler(std::string mime_type)
{
    _wsf_axiom_data_handler = axiom_data_handler_create(Environment::getEnv(), NULL, mime_type.c_str());
}

/** @brief OMDataHandler
  *
  * @todo: document this function
  */
 OMDataHandler::OMDataHandler(std::string file_name, std::string mime_type)
{
    _wsf_axiom_data_handler = axiom_data_handler_create(Environment::getEnv(), file_name.c_str(), mime_type.c_str());
}

/** @brief getAxiomDataHandler
  *
  * @todo: document this function
  */
axiom_data_handler_t * OMDataHandler::getAxiomDataHandler()
{
    return _wsf_axiom_data_handler;
}

/** @brief setAxiomDataHandler
  *
  * @todo: document this function
  */
void OMDataHandler::setAxiomDataHandler(axiom_data_handler_t * data_handler)
{
    _wsf_axiom_data_handler = data_handler;
}

bool OMDataHandler::isCached()
{
	if(axiom_data_handler_get_cached(_wsf_axiom_data_handler, Environment::getEnv()))
	{
		return true;
	}
	return false;
}

bool OMDataHandler::writeTo(std::string filename)
{
	axiom_data_handler_set_file_name (_wsf_axiom_data_handler, Environment::getEnv(),(char *)filename.c_str());
	if(axiom_data_handler_write_to(_wsf_axiom_data_handler, Environment::getEnv()))
	{
		return true;
	}
	return false;
}

