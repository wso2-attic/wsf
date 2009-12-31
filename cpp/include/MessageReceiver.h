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

#ifndef MESSAGE_RECEIVER_H
#define MESSAGE_RECEIVER_H

#include <WSFDefines.h>
#include <string>
#include <rampart_authn_provider.h>
#include <MessageContext.h>
#include <Environment.h>

/**
 * @file MessageReceiver.h
 * @brief  MessageReceiver class, the interface for implementing a message receiver
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup MessageReceiver
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class MessageReceiver Represents an interface needed implement any user specific
     * message receiver. Extend from this class and implement the abstract methods defined here to
     * implement a message receiver.
     */
    class MessageReceiver
    {
    public:
        /**
         * Handler to be invoked process the business logic
         * @param InMessageContext
         * @param OutMessageContext
         */
        virtual bool WSF_CALL invokeBusinessLogicSync(
			MessageContext *inMessageContext,
			MessageContext *outMessageContext) = 0;

        /**
         * destructor that can be overridden.
         */
		WSF_EXTERN virtual WSF_CALL ~MessageReceiver(){};

        /**
         * Static Handler to be invoked to call invokeMusinessLogicSync
         */
		WSF_EXTERN static axis2_status_t WSF_CALL processBusinessLogic(
            axis2_msg_recv_t * msg_recv,
			const axutil_env_t * env,
			axis2_msg_ctx_t * msg_ctx,
			axis2_msg_ctx_t * new_msg_ctx);

		WSF_EXTERN static axis2_status_t WSF_CALL loadAndInitService(
			axis2_msg_recv_t *msg_recv,
			const axutil_env_t* env,
			struct axis2_svc *svc);


    };
    /** @} */
}

/**
 * Macro used to load the message receiver shared lib to the engine. The authentication provider
 * code should include this macro and provide the class extended from authentication provider as the
 * argument to the macro.
 */
#define WSF_MESSAGE_RECEIVER_INIT(class_name) \
extern "C" \
{ \
    WSF_EXTERN int \
    axis2_remove_instance( \
        axis2_msg_recv_t *inst, \
        const axutil_env_t *env) \
    { \
        if(inst) \
		{  \
			void *derived = axis2_msg_recv_get_derived(inst, env); \
			if(derived) {\
				delete (MessageReceiver*)derived; \
			}\
			axis2_msg_recv_free(inst, env); \
		} \
        return AXIS2_SUCCESS; \
    }  \
\
    WSF_EXTERN int \
    axis2_get_instance( \
        axis2_msg_recv_t **inst, \
        const axutil_env_t *env) \
    { \
		wso2wsf::MessageReceiver *receiver = new class_name(); \
		axis2_status_t status = AXIS2_FAILURE; \
	    axis2_msg_recv_t *msg_recv = axis2_msg_recv_create(env);  \
		if (!msg_recv)  \
		{	\
			AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);	\
			return AXIS2_FAILURE;	\
		}	\
		status = axis2_msg_recv_set_scope(msg_recv, env, AXIS2_APPLICATION_SCOPE);	\
		if (!status)	\
		{	\
			axis2_msg_recv_free(msg_recv, env);	\
			return AXIS2_FAILURE;	\
		}	\
		axis2_msg_recv_set_derived(msg_recv, env,  (void*)receiver);	\
		axis2_msg_recv_set_invoke_business_logic(msg_recv, env, wso2wsf::MessageReceiver::processBusinessLogic); \
		axis2_msg_recv_set_load_and_init_svc(msg_recv, env,	wso2wsf::MessageReceiver::loadAndInitService);	\
		*inst = msg_recv;	\
		return AXIS2_SUCCESS; \
    } \
} \


#endif // MESSAGE_RECEIVER_H
