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

#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/rand.h>
#include <openssl_constants.h>
#include <openssl_pkey.h>
#include <axis2_util.h>
#include <openssl/pkcs12.h>
#include <oxs_error.h>
/**
  * @file openssl_x509.h 
  * @brief Extracts information from a X509 certificate.
  */
#ifndef OPENSSL_PEM_H
#define OPENSSL_PEM_H

#ifdef __cplusplus
extern "C" {
#endif

    /** @defgroup
     * @ingroup
     * @{
     */

    typedef enum {
        OPENSSL_PEM_PKEY_TYPE_PRIVATE_KEY = 0,
        OPENSSL_PEM_PKEY_TYPE_PUBLIC_KEY,
        OPENSSL_PEM_PKEY_TYPE_UNKNOWN
    } openssl_pem_pkey_type_t;

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_pem_buf_read_pkey(const axutil_env_t *env,
                              axis2_char_t *b64_encoded_buf,
                              axis2_char_t *password,
                              openssl_pem_pkey_type_t type,
                              EVP_PKEY **pkey);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_pem_read_pkey(const axutil_env_t *env,
                          axis2_char_t *filename,
                          axis2_char_t *password,
                          openssl_pem_pkey_type_t type,
                          EVP_PKEY **pkey);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_PEM_H */
