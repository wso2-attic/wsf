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

#ifndef OXS_X509_CERT
#define OXS_X509_CERT


/**
  * @file oxs_x509_cert.h
  * @brief the OMXMLSecurity representation of an X509 certificate
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <openssl_pkey.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** @defgroup oxs_x509_cert
     * @ingroup 
     * @{
     */


    typedef struct oxs_x509_cert_t oxs_x509_cert_t;

    /**
     * Create function of the X509 certificate 
     * @param env pointer to environment struct
     * @return created X509 certificate
     **/
    AXIS2_EXTERN oxs_x509_cert_t *AXIS2_CALL
    oxs_x509_cert_create( const axutil_env_t *env);

    /**
     * Free function of the X509 certificate 
     * @param x509_cert the X509 certificate to be freed
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     **/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_free(oxs_x509_cert_t *x509_cert,
                       const axutil_env_t *env);

    /*Getters*/
    /**
     * Get the serial number of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the serial number of X509 certificate
     */
    AXIS2_EXTERN int AXIS2_CALL
    oxs_x509_cert_get_serial_number(oxs_x509_cert_t *x509_cert,
                                    const axutil_env_t *env);

    /**
     * Get the subject of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the subject of X509 certificate
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_x509_cert_get_subject(oxs_x509_cert_t *x509_cert,
                              const axutil_env_t *env);

    /**
     * Get the issuer of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the issuer of X509 certificate
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_x509_cert_get_issuer(oxs_x509_cert_t *x509_cert,
                             const axutil_env_t *env);

    /**
     * Get the key identifier of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the key identifier of X509 certificate
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_x509_cert_get_key_identifier(oxs_x509_cert_t *x509_cert,
                                     const axutil_env_t *env);

    /**
     * Get the finger print  of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the finger print of X509 certificate
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_x509_cert_get_fingerprint(oxs_x509_cert_t *x509_cert,
                                  const axutil_env_t *env);

    /**
     * Get the expiration date  of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the expiration date of X509 certificate
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_x509_cert_get_date(oxs_x509_cert_t *x509_cert,
                           const axutil_env_t *env);

    /**
     * Get the hash of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the hash of X509 certificate
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_x509_cert_get_hash(oxs_x509_cert_t *x509_cert,
                           const axutil_env_t *env);

    /**
     * Get the data of X509 Certificate
     * This is the base64 encoded string in between the  --BEGIN CERTIFICATE- --END CERTIFICATE-- lines
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the data of X509 certificate
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_x509_cert_get_data(oxs_x509_cert_t *x509_cert,
                           const axutil_env_t *env);

    /**
     * Get the public key of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @return the public key of X509 certificate
     */
    AXIS2_EXTERN openssl_pkey_t *AXIS2_CALL
    oxs_x509_cert_get_public_key(oxs_x509_cert_t *x509_cert,
                                 const axutil_env_t *env);

    /*Setters*/
    /**
     * Set the serial number of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param value  the serial number of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_serial_number(oxs_x509_cert_t *x509_cert,
                                    const axutil_env_t *env,
                                    int value);

    /**
     * Set the issuer of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param value  the issuer of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_issuer(oxs_x509_cert_t *x509_cert,
                             const axutil_env_t *env,
                             axis2_char_t *value);

    /**
     * Set the key identifier of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param value  the key identifier of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_key_identifier(oxs_x509_cert_t *x509_cert,
                                     const axutil_env_t *env,
                                     axis2_char_t *value);

    /**
     * Set the subject of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param value  the subject of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_subject(oxs_x509_cert_t *x509_cert,
                              const axutil_env_t *env,
                              axis2_char_t *value);

    /**
     * Set the finger print of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param value  the fingerprint of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_fingerprint(oxs_x509_cert_t *x509_cert,
                                  const axutil_env_t *env,
                                  axis2_char_t *value);

    /**
     * Set the expiration date of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param value  the expiration date of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_date(oxs_x509_cert_t *x509_cert,
                           const axutil_env_t *env,
                           axis2_char_t *value);

    /**
     * Set the hash of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param value   the hash of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_hash(oxs_x509_cert_t *x509_cert,
                           const axutil_env_t *env,
                           axis2_char_t *value);

    /**
     * Set the data of X509 Certificate. 
     * This is the base64 encoded string in between the  --BEGIN CERTIFICATE- --END CERTIFICATE-- lines
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param value  the data of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_data(oxs_x509_cert_t *x509_cert,
                           const axutil_env_t *env,
                           axis2_char_t *value);

    /**
     * Set the public key of X509 Certificate
     * @param x509_cert the X509 certificate
     * @param env pointer to environment struct
     * @param public_key public key of X509 Certificate
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_set_public_key(oxs_x509_cert_t *x509_cert,
                                 const axutil_env_t *env,
                                 openssl_pkey_t *public_key);
    /**
     * Copy contents of a certificate to another
     * @param x509_cert the X509 certificate, the source
     * @param env pointer to environment struct
     * @param to, another x509 certificate, the target
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_x509_cert_copy_to(oxs_x509_cert_t *x509_cert,
                          const axutil_env_t *env,
                          oxs_x509_cert_t *to);
    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_X509_CERT */
