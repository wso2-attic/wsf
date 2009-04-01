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

#include <WSFDefines.h>
#include <axutil_env.h>
#include <string>
#include <map>
#include <Environment.h>
using namespace wso2wsf;
using namespace std;

Environment* WSF_CALL Environment::getInstance()
{
	if(_processObj)
	{
		return _processObj;
	}
	else
	{
		_processObj =  new Environment();
#ifdef WIN32
		lock = new RWLock();
		lock->init();
#endif
		return _processObj;
	}
}

/**
*	Method to store the current thread specific environment. 
*  @param env Pointer to the axutil_env
*/
void WSF_CALL Environment::setEnv(const axutil_env_t *env)
{
#ifdef WIN32
	lock->writeLock();
#else 
	int rc;
	 rc = pthread_rwlock_wrlock(&rwlock);
#endif

	int threadId = AXIS2_PLATFORM_GET_THREAD_ID();
	_envmap[threadId] = env;
#ifdef WIN32
	lock->unlock();
#else
	 rc = pthread_rwlock_unlock(&rwlock);
#endif

}

/**
*	
*/
const axutil_env_t* WSF_CALL Environment::getEnv() 
{
	const axutil_env_t *env = NULL;
#ifdef WIN32
	lock->readLock();
#else
	pthread_rwlock_rdlock(&rwlock);
#endif

	int threadId = AXIS2_PLATFORM_GET_THREAD_ID();
	std::map<int, const axutil_env_t*>::iterator _it;
	_it = _envmap.find(threadId);
	if(_it != _envmap.end())
	{
		env = _it->second;
	}
#ifdef WIN32
	lock->unlock();
#else
	pthread_rwlock_unlock(&rwlock);
#endif

	return env;
}

WSF_EXTERN void WSF_CALL Environment::removeEnv()
{
#ifdef WIN32
	lock->writeLock();
#else 
     int rc;
	 rc =  pthread_rwlock_wrlock(&rwlock);
#endif

	 int threadId = AXIS2_PLATFORM_GET_THREAD_ID();
		_envmap.erase(threadId);

#ifdef WIN32
	lock->unlock();
#else
	rc = pthread_rwlock_unlock(&rwlock);
#endif

}

/**
* destructor frees resources.
*/
WSF_CALL Environment::~Environment()
{
	std::map<int, const axutil_env_t*>::iterator _it;
	for(_it = _envmap.begin(); _it != _envmap.end(); ++_it)
	{
		axutil_env_free((axutil_env_t*)_it->second);
	}
}

void WSF_CALL Environment::switchToGlobalPool()
{
	std::map<int, const axutil_env_t*>::const_iterator _it;
	int threadId = AXIS2_PLATFORM_GET_THREAD_ID();
	_it = _envmap.find(threadId);
	if(_it != _envmap.end())
	{
		axutil_allocator_switch_to_global_pool((_it->second)->allocator);
	}
}

void WSF_CALL Environment::switchToLocalPool()
{

	std::map<int, const axutil_env_t*>::const_iterator _it;
	int threadId = AXIS2_PLATFORM_GET_THREAD_ID();
	_it = _envmap.find(threadId);
	if(_it != _envmap.end())
	{
		axutil_allocator_switch_to_local_pool((_it->second)->allocator);
	}
}

void WSF_CALL Environment::initialize(std::string logFileName, axutil_log_levels_t logLevel)
{
	_logFileName = logFileName;
	_logLevel = logLevel;
}

std::string Environment::_logFileName;

axutil_log_levels_t Environment::_logLevel;

Environment* Environment::_processObj = NULL;

std::map<int, const axutil_env_t*> Environment::_envmap;

#ifdef WIN32

RWLock* Environment::lock;

#else 

pthread_rwlock_t Environment::rwlock = PTHREAD_RWLOCK_INITIALIZER;

#endif
