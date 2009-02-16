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
		_processObj =  new Process();
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
void WSF_CALL Process::setEnv(const axutil_env_t *env)
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
const axutil_env_t* WSF_CALL Process::getEnv() 
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

WSF_EXTERN void WSF_CALL Process::removeEnv()
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
WSF_CALL Process::~Process()
{
}

void WSF_CALL Process::switchToGlobalPool()
{
	std::map<int, const axutil_env_t*>::const_iterator _it;
	int threadId = AXIS2_PLATFORM_GET_THREAD_ID();
	_it = _envmap.find(threadId);
	if(_it != _envmap.end())
	{
		axutil_allocator_switch_to_global_pool((_it->second)->allocator);
	}
}

void WSF_CALL Process::switchToLocalPool()
{

	std::map<int, const axutil_env_t*>::const_iterator _it;
	int threadId = AXIS2_PLATFORM_GET_THREAD_ID();
	_it = _envmap.find(threadId);
	if(_it != _envmap.end())
	{
		axutil_allocator_switch_to_local_pool((_it->second)->allocator);
	}
}


Process* Process::_processObj = NULL;

std::map<int, const axutil_env_t*> Process::_envmap;

#ifdef WIN32

RWLock* Process::lock;

#else 

pthread_rwlock_t Process::rwlock = PTHREAD_RWLOCK_INITIALIZER;

#endif
