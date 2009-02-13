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

#include <stdio.h>
#include <OMException.h>
using namespace wso2wsf;

/** @brief OMException
  *
  * @todo: document this function
  */
 OMException::OMException(char const * reason)
    : Exception(reason)
{
    _sender = NULL;
}

/** @brief OMException
  *
  * @todo: document this function
  */
 /*OMException::OMException(char const * reason, OMObject * sender)
    : Exception(reason)
{
    _sender = sender;
}*/

/** @brief process
  *
  * @todo: document this function
  */
void OMException::process() const
{
    //processing...
}

/** @brief process
  *
  * @todo: document this function
  */
OMException::~OMException()
{
    if (_sender)
    {
        _sender = NULL;
    }
}
