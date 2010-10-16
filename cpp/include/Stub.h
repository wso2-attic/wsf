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

#ifndef STUB_H
#define STUB_H

#include <WSFDefines.h>
#include <axis2_svc_client.h>
#include <ServiceClient.h>

/**
 * @file Stub.h
 * @brief Stub is the client side interface for defining clients. Used primarily by the Code Generator.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup Stub Stub
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class Stub This object serves as the primary client API for consuming SOAP services.
     * This is the base class for the codegenerated client side stub classes.
     */
    class Stub
    {
	
	
	protected:
		/**
		 * ServiceClient object instance associated with the stub
		 */
		ServiceClient *serviceClient;

		/**
		 * Options object instance associated with the stub
		 */
		Options *clientOptions;
		
    public:
        
      	
      	/**
		 * Initialize the Stub. 
		 * @param client_home string referring to the client repository location.
		 * @param endpointUri The endpoint URI of the service which will be invoked using this stub.
		 */ 	 
		WSF_EXTERN void WSF_CALL init(std::string& client_home, std::string& endpointUri);

		/**
		 * getOptions method is used to obtain a pointer to the Stub Object's underlying options instance.
		 * @returns A pointer to the Options Object instance
		 *
		*/
		WSF_EXTERN Options* WSF_CALL getOptions();

		/**
		* getServiceClient method is used to obtain a pointer to the Stub Object's Underlying ServiceClient
		* Object instance.
		* @returns A pointer to the ServiceClient Object instance
		*/
		WSF_EXTERN ServiceClient* WSF_CALL getServiceClient();
		
		/**
		* setServiceClient() Used to set ServiceClient instance to the stub and configure stub.
		* @param client Pointer to a ServiceClient instance
		* @returns true on success, false otherwise.
		*/
 		

		WSF_EXTERN bool WSF_CALL setServiceClient(ServiceClient *client);
		
		/**
		 *  engageModule Engage an Axis2/C module to this Stub
		 *  @param moduleName identifying name for the module
		 *  @returns true on success, false otherwise
		 */
		WSF_EXTERN bool WSF_CALL engageModule(std::string moduleName);

		/**
		 * addAnnonymousOperations
		 */ 
		WSF_EXTERN void WSF_CALL addAnonymousOperations();

		/**
		 * Destroy the Stub. 
		 */ 	 
		WSF_EXTERN virtual WSF_CALL ~Stub();


    };
    /** @} */
}
#endif // STUB_H
