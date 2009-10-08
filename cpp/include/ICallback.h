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

#ifndef ICALLBACK_H
#define ICALLBACK_H

#include <WSFDefines.h>
#include <OMElement.h>
#include <string>

/**
 * @file ICallback.h
 * @brief ICallback Defines the interface for implementing asynchrounus interactions.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup icallback ICallback
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class ICallback Represents an interface needed to be implemented by
     * an object that is used for passing callbacks for the request
     * method in the ServiceClient Class, in a non-blocking scenario.
     */
    class WSF_EXTERN ICallback
    {
    public:
        /**
         * Handler to be invoked in a Complete Event.
         * @param message Reference to message that is passed in.
         */
        virtual void WSF_CALL onComplete(OMElement* message) = 0;

        /**
         * Handler to be invoked in a Fault Event.
         * @param message Reference to message that is passed in.
         */
        virtual void WSF_CALL onFault(OMElement* message) = 0;

        /**
         * destructor that can be overridden.
         */
        virtual WSF_CALL ~ICallback();
    };
    /** @} */

    /* inline implementation of ICallback class. */
    inline WSF_CALL ICallback::~ICallback()
    {}
}
#endif // ICALLBACK_H
