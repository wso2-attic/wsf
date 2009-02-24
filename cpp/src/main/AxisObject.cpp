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
#include <WSFError.h>
#include <AxisObject.h>
using namespace std;
using namespace wso2wsf;

/** @brief ~AxisObject
  *
  * @todo: document this function
  */
 AxisObject::~AxisObject()
{
	/*
    if (_refCount == 0)
    {
        if (_env)
        {
            axutil_env_free(_env);
        }
    }
    else
    {
        decrementRef();
    }
	*/
}

/** @brief enableLogging
  *
  * @todo: document this function
  */
void AxisObject::enableLogging(bool enable)
{
	axutil_env_t *_env = NULL;
    if (enable)
    {
		
        axutil_env_enable_log(_env, AXIS2_TRUE);
    }
    else
    {
        axutil_env_enable_log(_env, AXIS2_FALSE);
    }
}

/** @brief initialize
  *
  * @todo: document this function
  */
void AxisObject::initialize()
{
	const axutil_env_t* env = NULL;
	_envPro	 = Process::getInstance();

	env = _envPro->getEnv();
	if(!env)
	{   
		env = axutil_env_create_all(Process::_logFileName.c_str(), Process::_logLevel);
    	_envPro->setEnv(env);
    }
}

/** @brief AxisObject
  *
  * @todo: document this function
  */
 AxisObject::AxisObject()
{
    if (_refCount > 0)
    {
        incrementRef();
    }
	initialize();
}

/** @brief getEnv
  *
  * @todo: document this function
  */
const axutil_env_t * AxisObject::getEnv()
{
	return _envPro->getEnv();
}

/** @brief incrementRef
  *
  * @todo: document this function
  */
void AxisObject::incrementRef()
{
    _refCount++;
}

/** @brief decrementRef
  *
  * @todo: document this function
  */
void AxisObject::decrementRef()
{
    if (_refCount > 0)
    {
        _refCount--;
    }
}

/** @brief _env
*
* @todo: document this var
*/
Process * AxisObject::_envPro = NULL;

/** @brief _refCount
*
* @todo: document this var
*/
unsigned int AxisObject::_refCount = 0;
