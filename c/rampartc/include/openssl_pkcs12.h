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

/**
  * @file 
  * @brief 
  */
#ifndef OPENSSL_PKCS12_H
#define OPENSSL_PKCS12_H

#ifdef __cplusplus
extern "C" {
#endif

    /** @defgroup
     * @ingroup
     * @{
     */

    /*Load*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_pkcs12_load(const axutil_env_t *env,
                        axis2_char_t *filename,
                        PKCS12 **p12);

    /*Parse*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_pkcs12_parse(const axutil_env_t *env,
                         axis2_char_t *password ,
                         PKCS12 *p12,
                         EVP_PKEY **prvkey,
                         X509 **cert,
                         STACK_OF(X509) **ca);

    /*Free*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_pkcs12_free(const axutil_env_t *env,
                        PKCS12 *p12);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_PKCS12_H */
