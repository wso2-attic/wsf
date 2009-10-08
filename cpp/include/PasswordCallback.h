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

#ifndef PASSWORD_CALLBACK_H
#define PASSWORD_CALLBACK_H

#include <WSFDefines.h>
#include <string>
#include <rampart_callback.h>
#include <Environment.h>

/**
 * @file PasswordCallback.h
 * @brief PasswordCallback class, the interface for implementing callbacks to validate users is defined here
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup passwordcallback PasswordCallback
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class PasswordCallback Represents an interface that should be implemented by a user specific
     * password callback. Extend from the PasswordCallback class and implement the abstract methods defined here.
     */
    class PasswordCallback
    {
    public:
        /**
         * Handler to be invoked to get the password
         * @param username Username associated with the password
         * @return The corresponding password if successful. 
         */
        virtual std::string WSF_CALL getPassword(std::string& username) = 0;

        /**
         * Handler to be invoked to get the pkcs12 password
         * @param username Username
         * @return Password associated with the provided username
         */
        virtual std::string WSF_CALL getPKCS12Password(std::string& username) = 0;

        /**
         * destructor that can be overridden.
         */
        WSF_EXTERN virtual WSF_CALL ~PasswordCallback();

        /**
         * Static Handler to be invoked to get the password
         */
        static WSF_EXTERN axis2_char_t* WSF_CALL callbackPassword(
            rampart_callback_t * callback, const axutil_env_t* env, const axis2_char_t *username, void *param);

        /**
         * Static Handler to be invoked to get the pkcs12 password
         */
        static WSF_EXTERN axis2_char_t* WSF_CALL callbackPKCS12Password(
            rampart_callback_t * callback, const axutil_env_t* env, const axis2_char_t *username, void *param);
    };
    /** @} */
}
/**
 * @brief stucture wsf_rampart_callback.
 * This callback is used to pass data and invoke c++ level callback
 */
typedef struct wsf_rampart_callback
{
    /**
     * Operations stuct pointer
     */ 
    rampart_callback_ops_t *ops;
    /**
     * pointer to corresponding axis2 parameter
     */ 
    axutil_param_t *param;
    /**
     * C++ Level Callback pointer
     */ 	
    wso2wsf::PasswordCallback* callback;
}wsf_rampart_callback_t;

/**
 * Macro used to load the password callback shared library to the engine. The implementor should 
 * include this macro in the code and the appropriate class name should be passed as the argument
 * for proper deployment and functioning of the service associated with this password callback.
 *
 */
#define WSF_PASSWORD_CALLBACK_INIT(class_name) \
extern "C" \
{ \
    WSF_EXTERN int \
    axis2_remove_instance( \
        wsf_rampart_callback_t *inst, \
        const axutil_env_t *env) \
    { \
        if (inst) \
        { \
            delete inst->callback; \
            AXIS2_FREE(env->allocator, inst->ops); \
            AXIS2_FREE(env->allocator, inst); \
        } \
        return AXIS2_SUCCESS; \
    } \
\
    axis2_status_t WSF_CALL \
    wsf_rampart_callback_free( \
        rampart_callback_t *inst, \
        const axutil_env_t *env) \
    { \
        return axis2_remove_instance((wsf_rampart_callback_t *)inst, env);\
    } \
\
    WSF_EXTERN int \
    axis2_get_instance( \
        wsf_rampart_callback_t **inst, \
        const axutil_env_t *env) \
    { \
        wsf_rampart_callback_t* rcb = NULL; \
    \
        rcb = (wsf_rampart_callback_t*)AXIS2_MALLOC(env->allocator, sizeof(wsf_rampart_callback_t)); \
    \
        rcb->ops = (rampart_callback_ops_t *)AXIS2_MALLOC(env->allocator, sizeof(rampart_callback_ops_t)); \
        rcb->ops->callback_password = wso2wsf::PasswordCallback::callbackPassword; \
        rcb->ops->callback_pkcs12_password = wso2wsf::PasswordCallback::callbackPKCS12Password; \
        rcb->ops->free = wsf_rampart_callback_free; \
    \
        rcb->callback = new class_name; \
    \
        *inst = rcb; \
        if (!(*inst)) \
        { \
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf_rampart]Cannot initialize the PWCB module"); \
            return AXIS2_FAILURE; \
        } \
\
        wso2wsf::Environment::setEnv(env); \
\
    \
        return AXIS2_SUCCESS; \
    } \
} \


#endif // PASSWORD_CALLBACK_H
