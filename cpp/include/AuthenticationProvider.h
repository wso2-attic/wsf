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

#ifndef AUTHENTICATION_PROVIDER_H
#define AUTHENTICATION_PROVIDER_H

#include <WSFDefines.h>
#include <string>
#include <rampart_authn_provider.h>
#include <MessageContext.h>
#include <Environment.h>

/**
 * @file AuthenticationProvider.h
 * @brief  AuthenticationProvider class, the interface for implementing authentication with WS-Security
 * is defined here.
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
     * @defgroup AuthenticationProvider AuthenticationProvider
     * @ingroup wso2wsf
     * @{
     */

    /**
     * @brief class AuthenticationProvider Represents an interface needed implement any user specific
     * authentication module. Extend from this class and implement the abstract methods defined here to
     * implement a authentication provider.
     */
    class AuthenticationProvider
    {
    public:
        /**
         * Handler to be invoked to check plain password
         * @param username username
         * @param password password
         * @return msgctx pointer to message context
         */
        virtual bool WSF_CALL checkPassword(
            std::string& username, 
            std::string& password, 
            MessageContext* msgctx) = 0;

        /**
         * Handler to be invoked to check digest password
         * @param username Username
         * @param nonce    nonce value
         * @param created  created time
         * @param digest digest value
         * @param msgctx pointer to message context
         * @return true if successful, false otherwise
         *
         */
        virtual bool WSF_CALL checkDigestPassword(
            std::string& username, 
            std::string& nonce, 
            std::string& created, 
            std::string& digest, 
            MessageContext* msgctx) = 0;

        /**
         * destructor that can be overridden.
         */
        WSF_EXTERN virtual WSF_CALL ~AuthenticationProvider();

        /**
         * Static Handler to be invoked to check plain password
         */
        WSF_EXTERN static rampart_authn_provider_status_t WSF_CALL callbackPasswordPlain(
            rampart_authn_provider_t * authn_provider, 
            const axutil_env_t* env, 
            axis2_msg_ctx_t *msg_ctx,
            const axis2_char_t *username,
            const axis2_char_t *password);

        /**
         * Static Handler to be invoked to check digest password
         */
        WSF_EXTERN static rampart_authn_provider_status_t WSF_CALL callbackPasswordDigest(
            rampart_authn_provider_t *authn_provider,
            const axutil_env_t* env,
            axis2_msg_ctx_t *msg_ctx,
            const axis2_char_t *username,
            const axis2_char_t *nonce,
            const axis2_char_t *created,
            const char *digest);

    };
    /** @} */
}

typedef struct wsf_authn_provider
{
    rampart_authn_provider_ops_t *ops;
    axutil_param_t *param;
    wso2wsf::AuthenticationProvider* callback;
}wsf_authn_provider_t;

/**
 * Macro used to load the authentication provider shared lib to the engine. The authentication provider
 * code should include this macro and provide the class extended from authentication provider as the
 * argument to the macro.
 */
#define WSF_AUTHENTICATION_PROVIDER_INIT(class_name) \
extern "C" \
{ \
    WSF_EXTERN int \
    axis2_remove_instance( \
        wsf_authn_provider_t *inst, \
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
    wsf_rampart_authn_provider_free( \
        rampart_authn_provider_t *inst, \
        const axutil_env_t *env) \
    { \
        return axis2_remove_instance((wsf_authn_provider_t *)inst, env);\
    } \
\
    WSF_EXTERN int \
    axis2_get_instance( \
        wsf_authn_provider_t **inst, \
        const axutil_env_t *env) \
    { \
        wsf_authn_provider_t* authn_callback = NULL; \
    \
        authn_callback = (wsf_authn_provider_t*)AXIS2_MALLOC(env->allocator, sizeof(wsf_authn_provider_t)); \
    \
        authn_callback->ops = (rampart_authn_provider_ops_t *)AXIS2_MALLOC(env->allocator, sizeof(rampart_authn_provider_ops_t)); \
        authn_callback->ops->rampart_authn_provider_check_password = wso2wsf::AuthenticationProvider::callbackPasswordPlain; \
        authn_callback->ops->rampart_authn_provider_check_password_digest = wso2wsf::AuthenticationProvider::callbackPasswordDigest; \
        authn_callback->ops->free = wsf_rampart_authn_provider_free; \
    \
        authn_callback->callback = new class_name; \
    \
        *inst = authn_callback; \
        if (!(*inst)) \
        { \
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[wsf_rampart]Cannot initialize the Authentication provider module"); \
            return AXIS2_FAILURE; \
        } \
\
        wso2wsf::Environment::setEnv(env); \
\
        return AXIS2_SUCCESS; \
    } \
} \


#endif // AUTHENTICATION_PROVIDER_H
