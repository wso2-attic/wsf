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
#ifndef OPENSSL_X509_H
#define OPENSSL_X509_H

#ifdef __cplusplus
extern "C" {
#endif

    /** @defgroup
     * @ingroup
     * @{
     */

    typedef enum {
        OPENSSL_X509_FORMAT_PEM = 0,
        OPENSSL_X509_FORMAT_DER,
        OPENSSL_X509_FORMAT_PKCS12
    } openssl_x509_format_t;

    typedef enum {
        OPENSSL_X509_INFO_SUBJECT = 0,
        OPENSSL_X509_INFO_ISSUER ,
        OPENSSL_X509_INFO_VALID_FROM ,
        OPENSSL_X509_INFO_VALID_TO ,
        OPENSSL_X509_INFO_FINGER ,
        OPENSSL_X509_INFO_SIGNATURE ,
        OPENSSL_X509_INFO_VERSION ,
        OPENSSL_X509_INFO_PUBKEY ,
        OPENSSL_X509_INFO_PUBKEY_ALGO ,
        OPENSSL_X509_INFO_DATA_CERT
    } openssl_x509_info_type_t;

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_x509_load_from_buffer(const axutil_env_t *env,
                                  axis2_char_t *b64_encoded_buf,
                                  X509 **cert);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_x509_load_from_pem(const axutil_env_t *env,
                               axis2_char_t *filename,
                               X509 **cert);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_x509_load_from_pkcs12(const axutil_env_t *env,
                                  axis2_char_t *filename,
                                  axis2_char_t *password,
                                  X509 **cert,
                                  EVP_PKEY **pkey,
                                  STACK_OF(X509) **ca);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_x509_load_certificate(const axutil_env_t *env,
                                  openssl_x509_format_t format,
                                  axis2_char_t *filename,
                                  axis2_char_t *password,
                                  X509 **cert);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    openssl_x509_get_cert_data(const axutil_env_t *env,
                               X509 *cert);


    AXIS2_EXTERN int AXIS2_CALL
    openssl_x509_get_serial(const axutil_env_t *env,
                            X509 *cert);

    AXIS2_EXTERN unsigned long AXIS2_CALL
    openssl_x509_get_subject_name_hash(const axutil_env_t *env,
                                       X509 *cert);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    openssl_x509_get_pubkey(const axutil_env_t *env,
                            X509 *cert,
                            EVP_PKEY **pubkey);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    openssl_x509_get_subject_key_identifier(const axutil_env_t *env,
                                            X509 *cert);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    openssl_x509_get_info(const axutil_env_t *env,
                          openssl_x509_info_type_t type,
                          X509 *cert);

    AXIS2_EXTERN void AXIS2_CALL
    openssl_x509_print(const axutil_env_t *env,
                       X509 *cert);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_X509_H */
