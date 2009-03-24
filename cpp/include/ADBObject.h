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

#ifndef WSSOAPCLIENT_H
#define WSSOAPCLIENT_H

#include <WSFDefines.h>
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
     * @defgroup ADBObject ADBObject
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class ADBObject This object serves as the base class for the ADB Data binding objects generated
     */
    class ADBObject
    {
	
	
	private:

    public:
		/**
		*  Serialize the ADBObject                                                    
		*
		*/
		WSF_EXTERN virtual void WSF_CALL serialize(OMElement *element, int tagClosed,std::vector<OMNamespace *> namespaces,int *nextNsIndex);
		/**
		* Deserialize the ADB Object                                                   
		*
		*/
		WSF_EXTERN virtual void WSF_CALL deserialize(OMElement *parent, bool isEarlyNodeValid, bool dontCareMinoccurs);

		~ADBObject();

    };
    /** @} */
}
#endif // WSSOAPCLIENT_H
