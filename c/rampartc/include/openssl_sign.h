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

#include <openssl/evp.h>
#include <openssl_cipher_ctx.h>
#include <openssl_constants.h>
#include <oxs_sign_ctx.h>
#include <axis2_util.h>

/**
  * @file openssl_sign.h 
  * @brief 
  */
#ifndef OPENSSL_SIGN_H
#define OPENSSL_SIGN_H

#ifdef __cplusplus
extern "C" {
#endif

    /** @defgroup
     * @ingroup
     * @{
     */
    /**
     * Signs a content a @input_buf using the private key @prvkey
     * The result would be placed in the @output_buf
     */
    AXIS2_EXTERN int AXIS2_CALL
    openssl_sig_sign(const axutil_env_t *env,
                     openssl_pkey_t *prvkey,
                     oxs_buffer_t *input_buf,
                     oxs_buffer_t *output_buf);
    /**
     * Verifies a signature placed in @sig_buf with 
     * the content placed in the @input_buf 
     * using the public key @pubkey
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_sig_verify(const axutil_env_t *env,
                       openssl_pkey_t *pubkey,
                       oxs_buffer_t *input_buf,
                       oxs_buffer_t *sig_buf);
    /** @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_SIGN_H */
