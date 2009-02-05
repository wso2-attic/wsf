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

#ifndef ServiceSkeleton_H
#define ServiceSkeleton_H

#include <WSFDefines.h>
#include <OMElement.h>
#include <string>
#include <MessageContext.h>

/**
 * @file ICallback.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup ServiceSkeleton ServiceSkeleton
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class ICallback Represents an interface needed to be implemented by
     * an object that is used for passing callbacks for the request
     * method in the ServiceClient Class, in a non-blocking scenario.
     */
	class WSF_EXTERN ServiceSkeleton
    {
    public:
        /**
         * This method is called for handling the business logic of the service
		 * Any service should 
         * @param message Reference to message that is passed in.
         */
		virtual OMElement* WSF_CALL invoke(OMElement* message, MessageContext *msgCtx){ return NULL;};

        /**
         * Handler to be invoked in a Fault Event.
         * @param message Reference to message that is passed in.
         */
		virtual OMElement* WSF_CALL onFault(OMElement* message){return NULL;};

        /**
         * destructor that can be overridden.
         */

		virtual void WSF_CALL init() throw (AxisFault){};

        virtual WSF_CALL ~ServiceSkeleton();
    };
    /** @} */

    /* inline implementation of ICallback class. */
    inline WSF_CALL ServiceSkeleton::~ServiceSkeleton()
    {}
}
#endif // ICALLBACK_H
