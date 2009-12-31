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

#ifndef SERVICESKELETON_H
#define SERVICESKELETON_H

#include <WSFDefines.h>
#include <OMElement.h>
#include <string>
#include <MessageContext.h>
#include <axis2_conf_ctx.h>

/**
 * WSF_SERVICE_INIT Macro. This macro is used to pass the class name to the class loading methods
 * for loading the service class to the engine for execution. The service implementor should have
 * this macro with the appropriate class name as the argument for successful deployment of the service.
 */

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
 * @brief ServiceSkeleton, the interface for implementing c++ Web Services with WSF/CPP is defined here.
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

	enum ContextType
	{
		SERVICE_CONTEXT = 0,
		CONFIGURATION_CONTEXT
	};

    /**
     * @brief class ServiceSkeleton represents the Interface that should be implemented by
     * any CPP service to be deployed with WSF/CPP. This class defines 3 virtual methods which should be overridden
     * by the implementation class. They are init() which performs any initialization required, invoke() which should handle
     * the business logic processing for the services, and onFault() which should implement the fault handling. 
	 * A service can be loaded at startup by setting the parameter 	loadServiceAtStartup.
     */
    class WSF_EXTERN ServiceSkeleton
    {
	protected :
		/**
		 * Stores the service context from axis2 inorder to allow users to store any service specific data.
		 */
		axis2_svc_ctx_t *serviceContext;

    public:
		/**
		 * This method is used to set the service context to the service skeleton. This method should only be used
		 * by the framework.
		 * @param svcCtx axis2 service context object.
		 */
		void WSF_CALL setServiceContext(axis2_svc_ctx_t *svcCtx);
		/**
		 * Stores Property to a given context. This axis2 context hirachy is used for this activitity. 
		 * @param ContextType ContextType can be one of SERVICE_CONTEXT or CONFIGURATION_CONTEXT.
		 * @param Parameter Pointer to a parameter instance.
		 */
		bool WSF_CALL setProperty(ContextType type,std::string key, Property *prop);
		/**
		 * Returns an stored Property from the context hierachy.Specify the property name. 
		 */
		Property* WSF_CALL getProperty(std::string key);

        /**
         * This method is called for handling the business logic of the service
	 * Services should implement this method in order to process the soap meesage's content.
	 * @param omEle is the first child of the SOAP Body element. The msgCtx is the message context of the
	 * out going message flow. The MessageContext object carries all the contextual details related to the soap message.
	 * Various details of the SOAP Message can be accessed using the MessageContext.
	 * This function should return the resultant OMElement which would be sent back to the message sender.
         * @param omEle pointer to message that is passed in.
         * @param msgCtx  pointer to the Out Message Context.
         * @returns Returns the response OMElement constructed.
         */
	virtual OMElement* WSF_CALL invoke(OMElement* omEle, MessageContext *msgCtx){ return NULL;};

        /**
         * This is the handler to be invoked when a Fault occurs. The Service implementor should implement any service specific fault
	 * handling here. This method is called, when the message exchange pattern is Request,Response and the invoke() method has already failed.
	 * @param omEle omEle is the received SOAP Body's first child element. 
         * @returns OMElement Constructed Fault OMElement.
         */
	virtual OMElement* WSF_CALL onFault(OMElement* omEle){return NULL;};

     /**
         *Initialization method. Any service specific initialization can be done here.                                                    
	 */
	virtual bool WSF_CALL init(){ return true;};
	
	/**
	 * Destructor for ServiceSkeleton.			
	 */ 			
        virtual WSF_CALL ~ServiceSkeleton();
    };
    /** @} */

    /* inline implementation of the service skeleton destructor. */
    inline WSF_CALL ServiceSkeleton::~ServiceSkeleton()
    {}
}
#endif // SERVICESKELETON_H
