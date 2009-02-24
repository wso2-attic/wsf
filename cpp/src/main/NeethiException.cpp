/*
 * Copyright 2005,2009 WSO2, Inc. http://wso2.com
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
#include <NeethiException.h>
using namespace wso2wsf;

/** @brief NeethiException
  *
  * @todo: document this function
  */
 NeethiException::NeethiException(char const * reason)
    : Exception(reason)
{
    _sender = NULL;
}

/** @brief NeethiException
  *
  * @todo: document this function
  */
 /*NeethiException::NeethiException(char const * reason, NeethiObject * sender)
    : Exception(reason)
{
    _sender = sender;
}*/

/** @brief process
  *
  * @todo: document this function
  */
void NeethiException::process() const
{
    //processing...
}

/** @brief process
  *
  * @todo: document this function
  */
NeethiException::~NeethiException()
{
    if (_sender)
    {
        _sender = NULL;
    }
}
