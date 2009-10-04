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
#include <WSFault.h>
using namespace wso2wsf;

void WSFault::init()
{
	_detail = "";
	_role = "";
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
WSFault::WSFault(char const * reason)
    : Exception(reason)
{
	init();
}

WSFault::WSFault(char const *reason, char const *detail):Exception(reason)
{
	init();
	if(detail)
		_detail = detail;

}

WSFault::WSFault(char const *reason, char const *detail, char const *code):Exception(reason, code)
{
	init();
	if(detail)
		_detail = detail;
}

WSFault::WSFault(char const *reason, char const* detail, char const *code,  char const *role):Exception(reason, code)
{
	init();
	if(detail)
		_detail = detail;
	if(role)
		_role = role;

}

/**
* @returns Returns the soap fault detail string                                                  
*/
std::string WSFault::getFaultDetail()
{
	return _detail;
}

/**
* @returns Returns the soap fault role string                                                  
*/
std::string WSFault::getFaultRole()
{
	return _role;
}

/**
* Sets Soap Fault detail information
* @param detail SOAP Fault detail information.
*/
void WSFault::setFaultDetail(char const* detail)
{
	if(detail)
		_detail = detail;
}
/**
* Sets Soap Fault detail information
* @param role SOAPFault role information
*/
void WSFault::setFaultRole(char const* role)
{
	if(role)
		_role = role;
}

 /** @brief (one liner)
  *
  * (documentation goes here)
  */
void WSFault::process() const
{
}
