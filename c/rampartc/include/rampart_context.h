/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef RAMPART_CONTEXT_H
#define RAMPART_CONTEXT_H

/** @defgroup rampart_context
 * @ingroup rampart_context
 * @{
 */

#include <rp_includes.h>
#include <rp_secpolicy.h>
#include <rampart_authn_provider.h>
#include <rampart_util.h>
#include <axutil_property.h>
#include <rampart_constants.h>
#include <rampart_callback.h>
#include <rampart_authn_provider.h>
#include <axis2_key_type.h>
#include <axis2_msg_ctx.h>
#include <oxs_key.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rampart_context_t rampart_context_t;
    
    typedef axis2_char_t *(AXIS2_CALL*
                           password_callback_fn)(const axutil_env_t *env,
                                                 const axis2_char_t *username,
                                                 void *ctx);

    typedef axis2_status_t (AXIS2_CALL*
                            rampart_is_replayed_fn)(const axutil_env_t *env,
                                            axis2_msg_ctx_t* msg_ctx,
                                            rampart_context_t *rampart_context);

    typedef rampart_authn_provider_status_t (AXIS2_CALL*
            auth_password_func)(const axutil_env_t* env,
                                const axis2_char_t *username,
                                const axis2_char_t *password);

    typedef rampart_authn_provider_status_t (AXIS2_CALL*
            auth_digest_func)(const axutil_env_t* env,
                              const axis2_char_t *username,
                              const axis2_char_t *nonce,
                              const axis2_char_t *created,
                              const char *digest);



    /**
    * Create a rampart_context.rampart_context is the wrapper
    * of secpolicy and the main configuration for rampart.
    * @env pointer to environment struct
    * @return ramaprt_context_t* on successful creation.Else NULL; 
    */

    AXIS2_EXTERN rampart_context_t *AXIS2_CALL
    rampart_context_create(const axutil_env_t *env);


    /**
    * Frees a rampart_context.
    * @rampart_context the rampart_context
    * @env pointer to environment struct
    */

    AXIS2_EXTERN void AXIS2_CALL
    rampart_context_free(rampart_context_t *rampart_context,
                         const axutil_env_t *env);


    /****************************************************************/

    /**
    * Sets the policy node which is an om_node containing policy.This om_node
    * can be build outside rampart. 
    * @rampart_context the rampart_context
    * @env pointer to environment struct
    * @policy_node is an axiom_node.
    * @return AXIS2_SUCCESS on success else AXIS2_FAILURE. 
    */

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_policy_node(rampart_context_t *rampart_context,
                                    const axutil_env_t *env,
                                    axiom_node_t *policy_node);

    /**
    * Sets private key of sender as a buffer.This can be
    * set from outside rampart.  
    * @rampart_context the rampart_context
    * @env pointer to environment struct
    * @prv_key is a void buffer.
    * @return AXIS2_SUCCESS on success else AXIS2_FAILURE. 
    */

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_prv_key(rampart_context_t *rampart_context,
                                const axutil_env_t *env,
                                void *prv_key);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_prv_key_type(rampart_context_t *rampart_context,
                                     const axutil_env_t *env,
                                     axis2_key_type_t type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_certificate(rampart_context_t *rampart_context,
                                    const axutil_env_t *env,
                                    void *certificate);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_certificate_type(rampart_context_t *rampart_context,
                                         const axutil_env_t *env,
                                         axis2_key_type_t type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_receiver_certificate(rampart_context_t *rampart_context,
            const axutil_env_t *env,
            void *receiver_certificate);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_receiver_certificate_type(rampart_context_t *rampart_context,
            const axutil_env_t *env,
            axis2_key_type_t type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_user(rampart_context_t *rampart_context,
                             const axutil_env_t *env,
                             axis2_char_t *user);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_password(rampart_context_t *rampart_context,
                                 const axutil_env_t *env,
                                 axis2_char_t *password);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_prv_key_password(rampart_context_t *rampart_context,
                                         const axutil_env_t *env,
                                         axis2_char_t *prv_key_password);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_pwcb_function(rampart_context_t *rampart_context,
                                      const axutil_env_t *env,
                                      password_callback_fn pwcb_function,
                                      void *ctx);
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_replay_detect_function(rampart_context_t *rampart_context,
                                  const axutil_env_t *env,
                                  rampart_is_replayed_fn is_replayed_function);


    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_password_type(rampart_context_t *rampart_context,
                                      const axutil_env_t *env,
                                      axis2_char_t *password_type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_ttl(rampart_context_t *rampart_context,
                            const axutil_env_t *env,
                            int ttl);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_rd_val(rampart_context_t *rampart_context,
                            const axutil_env_t *env,
                            axis2_char_t *rd_val);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_private_key_file(rampart_context_t *rampart_context,
                           const axutil_env_t *env,
                           axis2_char_t *private_key_file);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_certificate_file(rampart_context_t *rampart_context,
                           const axutil_env_t *env,
                           axis2_char_t *certificate_file);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_reciever_certificate_file(rampart_context_t *rampart_context,
                           const axutil_env_t *env,
                           axis2_char_t *reciever_certificate_file);



    /**********************************************************8*/

    /*Getters of the above set functions*/

    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    rampart_context_get_policy_node(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN void *AXIS2_CALL
    rampart_context_get_prv_key(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_key_type_t AXIS2_CALL
    rampart_context_get_prv_key_type(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN void *AXIS2_CALL
    rampart_context_get_certificate(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_key_type_t AXIS2_CALL
    rampart_context_get_certificate_type(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN void *AXIS2_CALL
    rampart_context_get_receiver_certificate(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_key_type_t AXIS2_CALL
    rampart_context_get_receiver_certificate_type(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_user(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_password(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_prv_key_password(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN password_callback_fn AXIS2_CALL
    rampart_context_get_pwcb_function(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN rampart_is_replayed_fn AXIS2_CALL
    rampart_context_get_replay_detect_function(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);
 
    AXIS2_EXTERN void* AXIS2_CALL
    rampart_context_get_ctx(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN int AXIS2_CALL
    rampart_context_get_ttl(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);
    
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    rampart_context_get_rd_val(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_password_type(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    /*End of Getters */

    /*Rampart specific functions */
    AXIS2_EXTERN rp_secpolicy_t *AXIS2_CALL
    rampart_context_get_secpolicy(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_secpolicy(rampart_context_t *rampart_context,
                                  const axutil_env_t *env,
                                  rp_secpolicy_t *secpolicy);

    AXIS2_EXTERN rampart_callback_t *AXIS2_CALL
    rampart_context_get_password_callback(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_password_callback(rampart_context_t *rampart_context,
                                          const axutil_env_t *env,
                                          rampart_callback_t *password_callback_module);

    AXIS2_EXTERN auth_password_func AXIS2_CALL
    rampart_context_get_auth_password_function(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_auth_password_function(rampart_context_t *rampart_context,
            const axutil_env_t *env,
            auth_password_func authenticate_with_password);

    AXIS2_EXTERN auth_digest_func AXIS2_CALL
    rampart_context_get_auth_digest_function(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_auth_digest_function(rampart_context_t *rampart_context,
            const axutil_env_t *env,
            auth_digest_func authenticate_with_digest);

    AXIS2_EXTERN rampart_authn_provider_t *AXIS2_CALL
    rampart_context_get_authn_provider(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_authn_provider(rampart_context_t *rampart_context,
                                       const axutil_env_t *env,
                                       rampart_authn_provider_t *authn_provider);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_get_require_timestamp(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_get_require_ut(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN int AXIS2_CALL
    rampart_context_get_binding_type(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_is_include_timestamp(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_is_include_username_token(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_password_callback_class(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_authn_module_name(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_is_encrypt_before_sign(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_is_encrypt_signature(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);
    
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_get_nodes_to_encrypt(
        rampart_context_t *rampart_context,
        const axutil_env_t *env,
        axiom_soap_envelope_t *soap_envelope,
        axutil_array_list_t *nodes_to_encrypt);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_get_nodes_to_sign(
        rampart_context_t *rampart_context,
        const axutil_env_t *env,
        axiom_soap_envelope_t *soap_envelope,
        axutil_array_list_t *nodes_to_sign);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_get_elements_to_encrypt(
        rampart_context_t *rampart_context,
        const axutil_env_t *env,
        axiom_soap_envelope_t *soap_envelope,
        axutil_array_list_t *nodes_to_encrypt);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_get_elements_to_sign(
        rampart_context_t *rampart_context,
        const axutil_env_t *env,
        axiom_soap_envelope_t *soap_envelope,
        axutil_array_list_t *nodes_to_sign);

    AXIS2_EXTERN rp_property_t *AXIS2_CALL
    rampart_context_get_token(
        rampart_context_t *rampart_context,
        const axutil_env_t *env,
        axis2_bool_t for_encryption,
        axis2_bool_t server_side,
        axis2_bool_t is_inpath);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_check_is_derived_keys(
        const axutil_env_t *env,
        rp_property_t *token);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_enc_sym_algo(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_enc_asym_algo(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_asym_sig_algo(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_digest_mtd(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_encryption_user(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_is_token_include(
        rampart_context_t *rampart_context,
        rp_property_t *token,
        int token_type,
        axis2_bool_t server_side,
        axis2_bool_t is_inpath,
        const axutil_env_t *env);
    /*
        AXIS2_EXTERN axis2_char_t *AXIS2_CALL
        rampart_context_get_enc_key_identifier(
                rampart_context_t *rampart_context,
                rp_property_t *token,
                axis2_bool_t server_side,
                const axutil_env_t *env);
    */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_key_identifier(
        rampart_context_t *rampart_context,
        rp_property_t *token,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_is_token_type_supported(
        int token_type,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_is_key_identifier_type_supported(
        rampart_context_t *rampart_context,
        rp_property_t *token,
        axis2_char_t *identifier,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_layout(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_check_whether_to_encrypt(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_context_check_whether_to_sign(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_user_from_file(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_password_type_from_file(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_certificate_file(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_receiver_certificate_file(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rampart_context_get_private_key_file(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_ttl_from_file(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_rd_val_from_file(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN oxs_key_t *AXIS2_CALL
    rampart_context_get_session_key(
        rampart_context_t *rampart_context,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_context_set_session_key(
        rampart_context_t *rampart_context,
        const axutil_env_t *env,
        oxs_key_t *session_key);

    


#ifdef __cplusplus
}
#endif
#endif
