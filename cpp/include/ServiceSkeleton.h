/*
 * Copyright 2005,2009 WSO2, Inc. http://wso2.com
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


#define WSF_SERVICE_INIT(class_name) \
extern "C" \
{\
\
	WSF_EXTERN int \
		axis2_get_instance( \
		ServiceSkeleton ** inst, \
		const axutil_env_t * env) \
	{ \
		*inst = new class_name(); \
		if (!(*inst)) \
		{ \
			return AXIS2_FAILURE; \
		} \
\
		return AXIS2_SUCCESS; \
	} \
\
	WSF_EXTERN int \
		axis2_remove_instance( \
		ServiceSkeleton * inst, \
		const axutil_env_t * env) \
	{ \
		axis2_status_t status = AXIS2_SUCCESS; \
		if (inst) \
		{ \
			delete  inst; \
		} \
		return status; \
	} \
\
} \


/**
 * @file ServiceSkeleton.h
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
     * @brief class ServiceSkeleton represents the Interface that should be implemented by
	 * any CPP service to be deployed. This class defines 3 virtual methods which should be overridden
	 * by the implementation class of any service. 
     */
	class WSF_EXTERN ServiceSkeleton
    {
    public:
        /**
         * This method is called for handling the business logic of the service
		 * Services should implement this method in order to process the soap meesage's content.
		 * @param omEle is the first child of the SOAP Body element. The msgCtx is the message context of the
		 * out going message. The MessageContext object carries all the contextual details related to the soap message.
		 * Various details of the SOAP Message can be accessed using the MessageContext.
		 * This function should return the resultant OMElement which would be sent back to the message sender.
         * @param message Reference to message that is passed in.
         */
		virtual OMElement* WSF_CALL invoke(OMElement* omEle, MessageContext *msgCtx){ return NULL;};

        /**
         * This is the handler to be invoked when a Fault occurs. The Service implementor should implement any service specific fault
		 * handling here.
		 * @param omEle Fault OMElement
         * @param message Reference to message that is passed in.
         */
		virtual OMElement* WSF_CALL onFault(OMElement* omEle){return NULL;};

		/**
		*	Initialization method. Any service specific initialization can be done here.                                                    
		*
		*/
		virtual void WSF_CALL init(){};
		
        virtual WSF_CALL ~ServiceSkeleton();
    };
    /** @} */

    /* inline implementation of ICallback class. */
    inline WSF_CALL ServiceSkeleton::~ServiceSkeleton()
    {}
}
#endif // SERVICESKELETON_H
