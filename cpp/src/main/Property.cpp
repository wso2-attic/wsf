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
#include <Property.h>
using namespace std;
using namespace wso2wsf;

/** @brief getScope
  *
  * @todo: document this function
  */
axis2_scope_t Property::getScope()
{
    return _scope;
}

/** @brief getValue
  *
  * @todo: document this function
  */
void * Property::getValue()
{
    return _value;
}

/** @brief getName
  *
  * @todo: document this function
  */
string Property::getName()
{
    return _name;
}

/** @brief Property
  *
  * @todo: document this function
  */
 Property::Property(std::string name, void * value, axis2_scope_t scope)
{
    _name = name;
    _value = value;
    _scope = scope;
	_ownValue = false;
}

  Property::Property(std::string name, void * value, axis2_scope_t scope, bool ownValue)
{
    _name = name;
    _value = value;
    _scope = scope;
	_ownValue = ownValue;
}

/** @brief Property
  *
  * @todo: document this function
  */
 Property::Property(std::string name, void * value)
{
    _name = name;
    _value = value;
    _scope = AXIS2_SCOPE_APPLICATION;
	_ownValue = false;
}

 Property::~Property()
 {
	if(_value && _ownValue)
		delete _value;
 }
