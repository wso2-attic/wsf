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


/**
*	Method to store the current thread specific environment. 
*  @param env Pointer to the axutil_env
*/
void WSF_CALL Environment::setEnv(const axutil_env_t *env)
{
#ifdef WIN32
	if(!TlsSetValue(key.getTLSKey(),(void*)env))
	{
		printf("TLS Set Value Error");
		ExitProcess(0);
	}
#else 
	int rc;
	rc = pthread_setspecific(key.getTLSKey(), env);
	if(rc != 0)
	{
		printf("Error Setting the environment");
	}
#endif
}

/**
*	
*/
const axutil_env_t* WSF_CALL Environment::getEnv() 
{
	const axutil_env_t *env = NULL;
#ifdef WIN32
	env = (axutil_env_t*)TlsGetValue(key.getTLSKey());
#else
	env = (axutil_env_t*)pthread_getspecific(key.getTLSKey());
#endif
	if(!env)
	{
		env = axutil_env_create_all(_logFileName.c_str(), _logLevel);
		if(env)
		{
			setEnv(env);		
		}else
		{
			printf("Environment creation failed");
			exit(0);
		}
	}		
	return env;
}

WSF_EXTERN void WSF_CALL Environment::removeEnv()
{
#ifdef WIN32
	TlsSetValue(key.getTLSKey(), NULL);
#else 
         int rc;
        rc = pthread_setspecific(key.getTLSKey(), NULL);
        if(rc != 0)
        {
                printf("Error Setting the environment to NULL");
        }
#endif
}

/**
* destructor frees resources.
*/
WSF_CALL Environment::~Environment()
{
}

void WSF_CALL Environment::switchToGlobalPool()
{
	const axutil_env_t *env = NULL;
	env = getEnv();
	if(env)
	{
		axutil_allocator_switch_to_global_pool(env->allocator);
	}
}

void WSF_CALL Environment::switchToLocalPool()
{
	const axutil_env_t *env = NULL;
        env = getEnv();
	if(env)
	{
		axutil_allocator_switch_to_local_pool(env->allocator);
	}
}

void WSF_CALL Environment::initialize(std::string logFileName, axutil_log_levels_t logLevel)
{
	_logFileName = logFileName;
	_logLevel = logLevel;

	axutil_env_t *env = axutil_env_create_all(logFileName.c_str(), logLevel);
	if(env){
		setEnv(env);
	}else{
		exit(0);
	}
}

std::string Environment::_logFileName;

axutil_log_levels_t Environment::_logLevel;

TLSKey Environment::key;
