/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OXS_SIGN_CTX_H
#define OXS_SIGN_CTX_H


/**
  * @file oxs_sign_ctx.h
  * @brief Keeps information relavent for a single node of signing. 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <oxs_x509_cert.h>
#include <openssl_pkey.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /*The type of operation*/
    typedef enum  {
        OXS_SIGN_OPERATION_NONE = 0,
        OXS_SIGN_OPERATION_SIGN,
        OXS_SIGN_OPERATION_VERIFY
    } oxs_sign_operation_t;


    typedef struct oxs_sign_ctx_t oxs_sign_ctx_t;

    /**
     * Create a signature context
     * @env the environemnt struct
     * @return created signature context
     * */
    AXIS2_EXTERN oxs_sign_ctx_t *AXIS2_CALL
    oxs_sign_ctx_create(const axutil_env_t *env);

    /**
     * Free a signature context.
     * @ctx signature context
     * @env the environemnt struct
     * @return AXIS2_SUCCESS on success or AXIS2_FAILURE on failure
     *
     **/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_free(oxs_sign_ctx_t *ctx,
                      const axutil_env_t *env);


    /**********************Getter functions******************************************/
    /**
     * Get signature algorithm of the signature context
     * @sign_ctx the signature context
     * @env the environemnt struct 
     * @return signature algorithm
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_sign_ctx_get_sign_mtd_algo(
        const oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env);

    /**
     * Get cannocanicalization method of the signature context
     * @sign_ctx the signature context
     * @env the environemnt struct 
     * @return cannocanicalization method
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_sign_ctx_get_c14n_mtd(
        const oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env);

    /**
     * Get sginature valueof the signature context
     * @sign_ctx the signature context
     * @env the environemnt struct 
     * @return signature value
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_sign_ctx_get_sig_val(
        const oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env);

    /**
     * Get signature parts of the signature context
     * @sign_ctx the signature context
     * @env the environemnt struct 
     * @return sgnature parts as a list
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    oxs_sign_ctx_get_sign_parts(
        const oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env);

    /**
     * Get x509 certificate of the signature context
     * @sign_ctx the signature context
     * @env the environemnt struct 
     * @return x509 certificate
     */
    AXIS2_EXTERN oxs_x509_cert_t *AXIS2_CALL
    oxs_sign_ctx_get_certificate(
        const oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env);
    /**
     * Get private key of the signature context
     * @sign_ctx the signature context
     * @env the environemnt struct 
     * @return private key 
     */

    AXIS2_EXTERN openssl_pkey_t *AXIS2_CALL
    oxs_sign_ctx_get_private_key(
        const oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env);

    /**
     * Get public key of the signature context
     * @sign_ctx the signature context
     * @env the environemnt struct 
     * @return public key
     */
    AXIS2_EXTERN openssl_pkey_t *AXIS2_CALL
    oxs_sign_ctx_get_public_key(
        const oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env);

    /**
     * Get the operation of the signature context
     * @sign_ctx the signature context
     * @env the environemnt struct 
     * @return operation SIGN/VERIFY/NONE
     */
    AXIS2_EXTERN oxs_sign_operation_t AXIS2_CALL
    oxs_sign_ctx_get_operation(
        const oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env);

    /**********************Setter functions******************************************/
    /**
     * Set Signature algorithm  of the signature context @sign_ctx
     * @sign_ctx the signature context
     * @env the environemnt struct
     * @sign_mtd_algo Signature algorithm
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_set_sign_mtd_algo(
        oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env,
        axis2_char_t *sign_mtd_algo);

    /**
     * Set Cannocanicalization method of the signature context @sign_ctx
     * @sign_ctx the signature context
     * @env the environemnt struct
     * @c14n_mtd Cannocanicalization method
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_set_c14n_mtd(
        oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env,
        axis2_char_t *c14n_mtd);

    /**
     * Set signature value of the signature context @sign_ctx
     * @sign_ctx the signature context
     * @env the environemnt struct
     * @sig_val signature value
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_set_sig_val(
        oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env,
        axis2_char_t *sig_val);

    /**
     * Set signature parts of the signature context @sign_ctx
     * @sign_ctx the signature context
     * @env the environemnt struct
     * @sign_parts signature parts 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_set_sign_parts(
        oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env,
        axutil_array_list_t *sign_parts);

    /**
     * Set the x509 certificate of the signature context @sign_ctx
     * @sign_ctx the signature context
     * @env the environemnt struct
     * @certificate the x509 certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_set_certificate(
        oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env,
        oxs_x509_cert_t *certificate);

    /**
     * Set private key of the signature context @sign_ctx
     * @sign_ctx the signature context
     * @env the environemnt struct
     * @prv_key private key
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_set_private_key(
        oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env,
        openssl_pkey_t *prv_key);

    /**
     * Set the public key of the signature context @sign_ctx
     * @sign_ctx the signature context
     * @env the environemnt struct
     * @pub_key the public key
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_set_public_key(
        oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env,
        openssl_pkey_t *pub_key);

    /**
     * Set the operation of the signature context @sign_ctx
     * @sign_ctx the signature context
     * @env the environemnt struct
     * @operation the operation 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_sign_ctx_set_operation(
        oxs_sign_ctx_t *sign_ctx,
        const axutil_env_t *env,
        oxs_sign_operation_t operation);
    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_SIGN_CTX_H */
