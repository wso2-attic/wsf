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

#ifndef  ENVIRONMENT_H
#define  ENVIRONMENT_H

#include <axutil_platform_auto_sense.h>
#include <WSFDefines.h>
#include <axutil_env.h>
#ifdef WIN32
#include <RWLock.h>
#endif
#include <string>
#include <map>

/**
* @file Environment.h
*/

/**
* @brief namespace wso2wsf namespace of WSO2 Web Services Framework.
*/
namespace wso2wsf
{
	/**
	* @defgroup axis
	* @ingroup wso2wsf
	* @{
	*/
	/**
	* @brief class Environment. This keeps track of axis2_env_t when running with threads.
	*/
	class TLSKey
	{
		private: 	
#ifdef WIN32
		DWORD tls_key;
#else				
		pthread_key_t tls_key;
#endif		
		public:

		TLSKey()
		{
#ifdef WIN32
			 if ((tls_key = TlsAlloc()) == TLS_OUT_OF_INDEXES) 
				 ExitProcess(0);
#else
			pthread_key_create(&tls_key, NULL);
#endif
		}

#ifdef WIN32 
		DWORD getTLSKey()
#else
		pthread_key_t getTLSKey()
#endif
		{
			return tls_key;
		}
	};

	class Environment
	{

	private:
		
		static TLSKey key;
		/**
		* @var _refCount stores the number of references to axutil_env.
		*/

	public:
		/** keeps the log file name */
		static std::string _logFileName;
		/** keeps the log level */
		static axutil_log_levels_t _logLevel;
		
		Environment();
		/**
		*  Method to store the current thread specific environment. 
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
		/**
		* Initialize with log file and log level                                                   
		*
		*/
		static WSF_EXTERN void WSF_CALL initialize(std::string logFileName,  axutil_log_levels_t logLevel);
	
		WSF_CALL ~Environment(); 
	};
	/** @} */
}

#endif // ENVIRONMENT_H
