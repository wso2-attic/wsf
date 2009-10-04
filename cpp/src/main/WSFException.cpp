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
#include <WSFException.h>
using namespace wso2wsf;

Exception::~Exception()
{}

Exception::operator std::string() const
{
	return _reason;
}

Exception::Exception(char const * reason)
    : _reason(reason)
{}

Exception::Exception(char const *reason, char const *code)
:_reason(reason), _code(code)
{

}

std::string Exception::getFaultCode()
{
	return _code;
}

std::string Exception::getFaultReason()
{
	return _reason;
}



