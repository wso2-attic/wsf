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

#ifndef OXS_KEY_MGR_H
#define OXS_KEY_MGR_H


/**
  * @file oxs_key_mgr.h
  * @brief the Key Manager responsible for loading keys for OMXMLSecurity
  */

#include <axis2_defines.h>
#include <oxs_ctx.h>
#include <oxs_asym_ctx.h>
#include <axutil_env.h>
#include <axutil_qname.h>
#include <oxs_x509_cert.h>
#include <openssl_pkey.h>
#include <openssl_x509.h>
#include <openssl_pkcs12.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Loads keys/certificates from a keystore or a PEm file depending on information available in the @ctx
     * @ctx pointer to the OMXMLSec asymmetric encryption context struct
     * @env pointer to environment struct
     * @password the password for the key store
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_key_mgr_load_key(const axutil_env_t *env,
                         oxs_asym_ctx_t *ctx,
                         axis2_char_t *password);
    /**
     * Loads a private key from a string buffer @pem_buf which of PEM format.
     * -----BEGIN RSA PRIVATE KEY-----
     *  @pem_buf
     *  -----END RSA PRIVATE KEY-----
     * @env pointer to environment struct
     * @pem_buf the string buffer which of PEM format
     * @password the password for the key file
     * @return the generated key
     */
    AXIS2_EXTERN openssl_pkey_t* AXIS2_CALL
    oxs_key_mgr_load_private_key_from_string(const axutil_env_t *env,
            axis2_char_t *pem_buf, /*in PEM format*/
            axis2_char_t *password);
    /**
     * Loads a private key from a file (in PEM format)
     *  @env pointer to environment struct
     *  @file_name the name of the file
     *  @password the passowrd for the file
     *  @return the generated key
     */
    AXIS2_EXTERN openssl_pkey_t* AXIS2_CALL
    oxs_key_mgr_load_private_key_from_pem_file(const axutil_env_t *env,
            axis2_char_t *file_name,
            axis2_char_t *password);

    /**
     * Loads an X509 certificate from a string buffer @pem_buf 
     * -----BEGIN CERTIFICATE-----
     *  @pem_buf
     * -----END CERTIFICATE-----
     * @env pointer to environment struct
     * @pem_buf PEM formatted string buffer
     * @return the generated X509 certificate
     */
    AXIS2_EXTERN oxs_x509_cert_t* AXIS2_CALL
    oxs_key_mgr_load_x509_cert_from_string(const axutil_env_t *env,
                                           axis2_char_t *pem_buf);

    /**
     * Loads an X509 certificate from a file
     * @env pointer to environment struct
     * @file_name the name of the file
     * @return the generated X509 certificate
     */
    AXIS2_EXTERN oxs_x509_cert_t* AXIS2_CALL
    oxs_key_mgr_load_x509_cert_from_pem_file(const axutil_env_t *env,
            axis2_char_t *filename);

    /**
     * Read a PKCS12 key store and populate a key and a certificate.
     * @env pointer to environment struct
     * @pkcs12_file name of the pkcs12 file
     * @password password for the key/certificate pair in the key store
     * @cert the certificate
     * @prv_key the private key
     * @return the generated X509 certificate
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_key_mgr_read_pkcs12_key_store(const axutil_env_t *env,
                                      axis2_char_t *pkcs12_file,
                                      axis2_char_t *password,
                                      oxs_x509_cert_t **cert,
                                      openssl_pkey_t **prv_key);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_KEY_MGR_H */
