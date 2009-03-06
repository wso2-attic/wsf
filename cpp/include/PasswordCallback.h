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
#include <OMElement.h>
#include <string>
#include <rampart_callback.h>

/**
 * @file PasswordCallback.h
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
     * @brief class PasswordCallback Represents an interface needed implement any user specific
     * password callback
     */
    class WSF_EXTERN PasswordCallback
    {
    public:
        /**
         * Handler to be invoked to get the password
         */
        virtual std::string WSF_CALL getPassword(std::string username) = 0;

        /**
         * Handler to be invoked to get the pkcs12 password
         */
        virtual std::string WSF_CALL getPKCS12Password(std::string username) = 0;

        /**
         * destructor that can be overridden.
         */
        virtual WSF_CALL ~PasswordCallback();

        /**
         * Static Handler to be invoked to get the password
         */
        static axis2_char_t* WSF_CALL callbackPassword(
            rampart_callback_t * callback, const axutil_env_t* env, const axis2_char_t *username, void *param);

        /**
         * Static Handler to be invoked to get the pkcs12 password
         */
        static axis2_char_t* WSF_CALL callbackPKCS12Password(
            rampart_callback_t * callback, const axutil_env_t* env, const axis2_char_t *username, void *param);
    };
    /** @} */
}

typedef struct wsf_rampart_callback
{
    rampart_callback_ops_t *ops;
    axutil_param_t *param;
    wso2wsf::PasswordCallback* callback;
}wsf_rampart_callback_t;


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
        return AXIS2_SUCCESS; \
    } \
} \


#endif // PASSWORD_CALLBACK_H
