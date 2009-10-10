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
#include <string>
#include <map>

/**
* @file Environment.h
* @brief Environment wraps the axis2 environment used within axis2/c and wsf/c and manages it with thread local storage
*/

/**
* @brief namespace wso2wsf namespace of WSO2 Web Services Framework.
*/
namespace wso2wsf
{
	/**
	* @defgroup Environment Environment
	* @ingroup wso2wsf
	* @{
	*/
	/**
	* @brief class TLSKey. This is an internal class for keeping managing the allocation and deallocation of thread local
	* Storage which is used to store the axis2/c environment associated with each thread.
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
		/**
		 *  Constructor for the TLSKey class.
		 */
		TLSKey()
		{
#ifdef WIN32
			 if ((tls_key = TlsAlloc()) == TLS_OUT_OF_INDEXES) 
				 ExitProcess(0);
#else
			pthread_key_create(&tls_key, NULL);
#endif
		}
		/**
		 * Returns the unique key associated with the index created for thread local storage.
		 */
#ifdef WIN32 
		DWORD getTLSKey()
#else
		pthread_key_t getTLSKey()
#endif
		{
			return tls_key;
		}
		/**
		 * Destructor for TLSKey class.
		 */
		~TLSKey()
		{
#ifdef WIN32
			TlsFree(tls_key);
#else
			pthread_key_delete(tls_key);
#endif
		}
	};

	/**
	 *@brief Class Environment wraps the underlying axis2_environment which deals with memory allocation,
	 * threading, logging and error handling within the framework. Environment class hides all the complexcities of 
	 * these  and provides a simple interface. All the methods defined within the environment class are static. The method
	 * Environment::initialize() must be called before invoking any other methods from the WSF/CPP Framework for client side.
  	 */

	class Environment
	{

	private:
		/**
		 * variable to store to the thread local storage key.
		 */
		static TLSKey key;
	public:
		/** 
		 * keeps the log file name 
		 */
		static std::string _logFileName;
		/** 
 		* keeps the log level 
 		*/
		static axutil_log_levels_t _logLevel;
		/**
		 * Constructor for the Environment class 
		*/ 
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
		* Initialize with log file and log level. This function must be called prior to using the framework for client
		* side. For the server, calling the method for initialization is not required 
		* @param logFileName name of the log file name which will be created by the environment and used to write logs.
		* @param logLevel The level of details that should be written to the log file. There are several log levels available.
		* 1. WSF_LOG_LEVEL_CRITICAL Only Critical level logs will be written. Suitable for production deployment.
		* 2. WSF_LOG_LEVEL_ERROR  Only Error messages will be written to the log.
		* 3. WSF_LOG_LEVEL_INFO   Logs information 
		* 4. WSF_LOG_LEVEL_DEBUG  logs everything
		* 5. WSF_LOG_LEVEL_USER   log user level messages.
		* 6. WSF_LOG_LEVEL_TRACE  Trace Level logging.
		*/
		static WSF_EXTERN void WSF_CALL initialize(std::string logFileName,  axutil_log_levels_t logLevel);
		/**
		 * Destructor for Environment Object
		 */
		WSF_CALL ~Environment(); 
	};
	/** @} */
}

#endif // ENVIRONMENT_H
