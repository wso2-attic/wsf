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
#include <axis2_util.h>

/**
  * @file 
  * @brief 
  */
#ifndef OPENSSL_CRYPT_H
#define OPENSSL_CRYPT_H

#ifdef __cplusplus
extern "C" {
#endif

    /** @defgroup
     * @ingroup
     * @{
     */

    /**
     * Encrypt or decrypts data in the @input_buf and place the result in the @output_buf.
     * This function works for block ciphers AES-128, AES-192, AES-256 and 3-DES
     * The key and the cipher name must be specified in the cipher context.
     * @env pointer to environment struct
     * @oc_ctx  openssl block cipher context
     * @input_buf the input buffer to en/decrypt
     * @output_buf the output buffer to place en/decrypted result
     * @encrypt For encryption encrypt=OPENSSL_ENCRYPT and for decryption encrypt=OPENSSL_DECRYPT
     * @return the length of the en/decrypted result OR -1 if failed
     */

    AXIS2_EXTERN int AXIS2_CALL
    openssl_bc_crypt(const axutil_env_t *env,
                     openssl_cipher_ctx_t *oc_ctx,
                     oxs_buffer_t *input_buf,
                     oxs_buffer_t *output_buf,
                     int encrypt);



    /** @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_CRYPT_H */
