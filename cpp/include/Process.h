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

#ifndef  PROCESS_H
#define  PROCESS_H

#include <axutil_platform_auto_sense.h>
#include <WSFDefines.h>
#include <axutil_env.h>
#include <RWLock.h>
#include <string>
#include <map>

/**
* @file Process.h
*/

/**
* @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
*/
namespace wso2wsf
{
	/**
	* @defgroup axis
	* @ingroup wso2wsf
	* @{
	*/
	/**
	* @brief class Process. This keeps track of axis2_env_t when running with threads.
	*/
	class Process
	{

	private:
		/**
		* @var _env private variable holds reference for
		* axutil_env struct.
		*/
		static Process *_processObj;
		
		static std::map<int, const axutil_env_t*> _envmap;
		
#ifdef WIN32
		static RWLock *lock;		
#else 
		pthread_rwlock_t       rwlock; 
#endif
		/**
		* @var _refCount stores the number of references to axutil_env.
		*/

	public:
		/**
		* Return an instance of the Static Process Object
		*
		*/
		static WSF_EXTERN Process* WSF_CALL getInstance();
		/**
		*	Method to store the current thread specific environment. 
		*  @param env Pointer to the axutil_env
		*/
		static WSF_EXTERN void WSF_CALL setEnv(const axutil_env_t *env);
		/**
		* Get the environment related to current thread context                                                   
		*/
		static WSF_EXTERN const axutil_env_t* WSF_CALL getEnv();
		/**
		* Remove the environment related to current thread context.                                                   
		*/
		static WSF_EXTERN void WSF_CALL removeEnv();
		/**
		* Switch to global memory pool
		*/
		static WSF_EXTERN void WSF_CALL switchToGlobalPool();
		/**
		 * Switch to local memory pool                                                                  
		 */
		static WSF_EXTERN void WSF_CALL switchToLocalPool();
	
		WSF_CALL ~Process();
	};
	/** @} */
}

#endif // PROCESS_H
