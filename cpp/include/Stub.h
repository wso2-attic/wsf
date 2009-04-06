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
     * @brief class Stub This object serves as the primary client
     * for consuming SOAP services.
     */
    class Stub
    {
	
	
	private:
		/** service client */
		ServiceClient *serviceClient;
		/** Options */
		
		Options *options;
		
    public:
       
		WSF_EXTERN void WSF_CALL init(std::string& client_home, std::string& endpointUri);

		//************************************
		// Method:    _getOptions
		// FullName:  wso2wsf::Stub::_getOptions
		// Access:    public 
		// Returns:   WSF_EXTERN Options* WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN Options* WSF_CALL getOptions();

		//************************************
		// Method:    _getServiceClient
		// FullName:  wso2wsf::Stub::_getServiceClient
		// Access:    public 
		// Returns:   WSF_EXTERN ServiceClient* WSF_CALL
		// Qualifier:
		// Returns the service client associated with this stub
		//************************************
		WSF_EXTERN ServiceClient* WSF_CALL getServiceClient();
		
		//************************************
		// Method:    _setServiceClient
		// FullName:  wso2wsf::Stub::_setServiceClient
		// Access:    public 
		// Returns:   WSF_EXTERN bool WSF_CALL
		// Qualifier:
		// Parameter: ServiceClient * client
		//************************************
		WSF_EXTERN bool WSF_CALL setServiceClient(ServiceClient *client);
		
		//************************************
		// Method:    _engageModule
		// FullName:  wso2wsf::Stub::_engageModule
		// Access:    public 
		// Returns:   WSF_EXTERN bool WSF_CALL
		// Qualifier:
		// Parameter: std::string moduleName
		//************************************
		WSF_EXTERN bool WSF_CALL engageModule(std::string moduleName);

		//************************************
		// Method:    _addAnonymousOperations
		// FullName:  wso2wsf::Stub::_addAnonymousOperations
		// Access:    public 
		// Returns:   WSF_EXTERN void WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN void WSF_CALL addAnonymousOperations();


    };
    /** @} */
}
#endif // STUB_H
