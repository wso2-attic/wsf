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
#include <AxisObject.h>
using namespace std;
using namespace wso2wsf;

 AxisObject::~AxisObject()
{
}

void AxisObject::enableLogging(bool enable)
{
	axutil_env_t *_env = (axutil_env_t*)Environment::getEnv();
    if (enable)
    {
        axutil_env_enable_log(_env, AXIS2_TRUE);
    }
    else
    {
        axutil_env_enable_log(_env, AXIS2_FALSE);
    }
}

AxisObject::AxisObject()
{
	/** Initialize the Process Object which keeps the system thread safe */
	Environment::getInstance();

	if(!Environment::getEnv())
	{
		axutil_env_t* env = axutil_env_create_all(Environment::_logFileName.c_str(), Environment::_logLevel);
		Environment::setEnv(env);
    }
}

const axutil_env_t * AxisObject::getEnv()
{
	return Environment::getEnv();
}

 