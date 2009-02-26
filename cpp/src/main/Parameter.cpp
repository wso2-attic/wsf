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
#include <Parameter.h>
using namespace std;
using namespace wso2wsf;

/** @brief getScope
  *
  * @todo: document this function
  */
int Parameter::getType()
{
    return _type;
}

/** @brief getValue
  *
  * @todo: document this function
  */
void * Parameter::getValue()
{
    return _value;
}

/** @brief getName
  *
  * @todo: document this function
  */
string Parameter::getName()
{
    return _name;
}

/** @brief Property
  *
  * @todo: document this function
  */
 Parameter::Parameter(std::string name, void * value, int type)
{
    _name = name;
    _value = value;
    _type = type;
}
