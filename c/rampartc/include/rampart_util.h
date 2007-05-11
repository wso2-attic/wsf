/*
 *   Copyright 2003-2004 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */



#include <axutil_utils_defines.h>
#include <axis2_defines.h>
#include <axutil_date_time.h>
#include <axutil_env.h>
#include <axutil_property.h>
#include <axis2_msg_ctx.h>
#include <rampart_authn_provider.h>
#include <rampart_credentials.h>
#include <rampart_callback.h>
/**
  * @file rampart_util.h
  * @brief Utilities of rampart
  */
#ifndef RAMPART_UTIL_H
#define RAMPART_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
      * @defgroup Rampart_Util
      * @ingroup Rampart_Util
      */


    /**
     * Load a DLL or .SO module
     * @param env pointer to environment struct
     * @param module_name name of the module to be loaded
     * @return the loaded module
     */
    AXIS2_EXTERN void* AXIS2_CALL
    rampart_load_module(const axutil_env_t *env,
                        axis2_char_t *module_name);

    /**
     * Load the credentials module
     * @param env pointer to environment struct
     * @param cred_module_name name of the credentails module to be loaded
     * @return the loaded credentails module
     */
    AXIS2_EXTERN rampart_credentials_t* AXIS2_CALL
    rampart_load_credentials_module(const axutil_env_t *env,
                                    axis2_char_t *cred_module_name);

    /**
     * Call credentials module
     * @param env pointer to environment struct
     * @param cred_module the credentails module
     * @param ctx the message context
     * @param username reference to the returned username
     * @param password reference to the returned password
     * @return the status of the operation
     */
    AXIS2_EXTERN rampart_credentials_status_t AXIS2_CALL
    rampart_call_credentials(const axutil_env_t *env,
                             rampart_credentials_t *cred_module,
                             axis2_msg_ctx_t *ctx,
                             axis2_char_t **username,
                             axis2_char_t **password);

    /**
     * Load authentication module
     * @param env pointer to environment struct
     * @param auth_module_name name of the authentication module
     * @return creatd athenticaiton module
     */
    AXIS2_EXTERN rampart_authn_provider_t* AXIS2_CALL
    rampart_load_auth_module(const axutil_env_t *env,
                             axis2_char_t *auth_module_name);

    /**
     * Call auth module
     * @param env pointer to environment struct
     * @param authp the authentication module
     * @param  username the username in the UsernameToken
     * @param  password the password in the UsernameToken
     * @param  nonce the nonce in the UsernameToken
     * @param  created the created time in the UsernameToken
     * @param password_type  the type of the password. either plain text of digest
     * @param msg_ctx the message context
     */
    AXIS2_EXTERN rampart_authn_provider_status_t AXIS2_CALL
    rampart_authenticate_un_pw(const axutil_env_t *env,
                               rampart_authn_provider_t *authp,
                               const axis2_char_t *username,
                               const axis2_char_t *password,
                               const axis2_char_t *nonce,/*Can be NULL if plain text*/
                               const axis2_char_t *created,/*Can be NULL if plain text*/
                               const axis2_char_t *password_type,
                               axis2_msg_ctx_t *msg_ctx);

    /**
     * Load the password callback module
     * @param env pointer to environment struct
     * @callback_module_name the name of the callback module
     * @return the loaded callback module
     */
    AXIS2_EXTERN rampart_callback_t* AXIS2_CALL
    rampart_load_pwcb_module(const axutil_env_t *env,
                             axis2_char_t *callback_module_name);

    /**
       *@env the environment
       *@callback_module_name the file name of the callback module (.so or .DLL)
       *@username the name of the user to get the password
       *@ctx The axis2 context
       *@return the password for the user or NULL if failed
       */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    rampart_callback_password(const axutil_env_t *env,
                              rampart_callback_t *callback_module,
                              const axis2_char_t *username);

    /**
      * Generates the nonce. Nonce is a base64 encoded random string.
      * @param env pointer to environment struct
      * @return generated nonce
      */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_generate_nonce(const axutil_env_t *env);

    /**
      * Generates the nonce. Nonce is a base64 encoded random string.
      * @param ttl Time to live. The time difference between created and expired in mili seconds.
      * @return generated nonce
      **/
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    rampart_generate_time(const axutil_env_t *env, int ttl);

    /**
     * Check if @dt1 < @dt2. if not returns a false
     * @param env pointer to environment struct
     * @param dt1 date time 1
     * @param dt2 date time 2
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_compare_date_time(const axutil_env_t *env, axis2_char_t *dt1, axis2_char_t *dt2);

    /**
     * Print or log information (Only use for debugging)
     * @param env pointer to environment struct
     * @param info the information to be printed
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_print_info(const axutil_env_t *env, axis2_char_t* info);

    /* @} */
#ifdef __cplusplus
}
#endif

#endif    /* !RAMPART_UTIL_H */


