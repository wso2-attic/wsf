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

#include <WSFDefines.h>
#include <axutil_env.h>
#include <string>
#include <map>
#include <Process.h>
using namespace wso2wsf;
using namespace std;

Process* WSF_CALL Process::getInstance()
{
	if(_processObj)
	{
		return _processObj;
	}
	else
	{
		return new Process();
	}
}

/**
*	Method to store the current thread specific environment. 
*  @param env Pointer to the axutil_env
*/
void WSF_CALL Process::setEnv(const axutil_env_t *env)
{
	int threadId = AXIS2_PLATFORM_GET_THREAD_ID;
	_envmap[threadId] = env;
}

/**
*	
*/
const axutil_env_t* WSF_CALL Process::getEnv() 
{
	int threadId = AXIS2_PLATFORM_GET_THREAD_ID;
	_it = _envmap.find(threadId);
	if(_it != _envmap.end())
	{
		return _it->second;
	}
	return NULL;
}

/**
* destructor frees resources.
*/
WSF_CALL Process::~Process()
{
}

void WSF_CALL Process::switchToGlobalPool()
{
	int threadId = AXIS2_PLATFORM_GET_THREAD_ID;
	_it = _envmap.find(threadId);
	if(_it != _envmap.end())
	{
		axutil_allocator_switch_to_global_pool((_it->second)->allocator);
	}
}

void WSF_CALL Process::switchToLocalPool()
{
	int threadId = AXIS2_PLATFORM_GET_THREAD_ID;
	_it = _envmap.find(threadId);
	if(_it != _envmap.end())
	{
		axutil_allocator_switch_to_local_pool((_it->second)->allocator);
	}
}


Process* Process::_processObj = NULL;

map<int,const axutil_env_t *> Process::_envmap;
map<int,const axutil_env_t *>::const_iterator Process::_it;