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

#ifndef OXS_ASYM_CTX_H
#define OXS_ASYM_CTX_H


/**
  * @file oxs_asym_ctx.h
  * @brief Keeps information relavent for asymmetric encryption. 
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

    /** @defgroup oxs_asym_ctx Message Context
     * @ingroup 
     * @{
     */

    typedef enum  {
        OXS_ASYM_CTX_FORMAT_UNKNOWN=0,
        OXS_ASYM_CTX_FORMAT_PEM,
        OXS_ASYM_CTX_FORMAT_PKCS12
    }oxs_asym_ctx_format_t;

    typedef enum  {
        OXS_ASYM_CTX_OPERATION_PUB_ENCRYPT=0,
        OXS_ASYM_CTX_OPERATION_PRV_DECRYPT,
        OXS_ASYM_CTX_OPERATION_PUB_DECRYPT,
        OXS_ASYM_CTX_OPERATION_PRV_ENCRYPT
    }oxs_asym_ctx_operation_t;

    typedef struct oxs_asym_ctx_t oxs_asym_ctx_t;

    /*Create function*/
    AXIS2_EXTERN oxs_asym_ctx_t *AXIS2_CALL
    oxs_asym_ctx_create(const axutil_env_t *env);

    /*Free*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_free(oxs_asym_ctx_t *ctx,
                      const axutil_env_t *env);


    /**********************Getter functions******************************************/

    /**
    * Free function for the asymmetric context struct
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_free(oxs_asym_ctx_t *ctx,
                      const axutil_env_t *env);

    /**
    *Returns the filename. This is usually the filename of the certificate or the PKCS12 file
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    oxs_asym_ctx_get_file_name(const oxs_asym_ctx_t *ctx,
                               const axutil_env_t *env);

    /**
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    oxs_asym_ctx_get_pem_buf(const oxs_asym_ctx_t *ctx,
                             const axutil_env_t *env);
    /**
    *Returns the password. Usually the password for the keystore. But alternatively may kepe the
    *password for the private key in a PEM file.
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    oxs_asym_ctx_get_password(const oxs_asym_ctx_t *ctx,
                              const axutil_env_t *env);

    /**
    *Get the format. Can be either PEM or PKCS12
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN oxs_asym_ctx_format_t AXIS2_CALL
    oxs_asym_ctx_get_format(const oxs_asym_ctx_t *ctx,
                            const axutil_env_t *env);

    /**
    *Get the algorithm used to encrypt
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    oxs_asym_ctx_get_algorithm(const oxs_asym_ctx_t *ctx,
                               const axutil_env_t *env);

    /**
    *Get the SecurityTokenReference pattern. For ex: IssuerSerial
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    oxs_asym_ctx_get_st_ref_pattern(const oxs_asym_ctx_t *ctx,
                                    const axutil_env_t *env);

    /**
    *Get the operation. For ex: Public Key encrypt, Private Key Decrypt
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN oxs_asym_ctx_operation_t AXIS2_CALL
    oxs_asym_ctx_get_operation(const oxs_asym_ctx_t *ctx,
                               const axutil_env_t *env);

    /**
    *Get the private key used
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN openssl_pkey_t* AXIS2_CALL
    oxs_asym_ctx_get_private_key(const oxs_asym_ctx_t *ctx,
                                 const axutil_env_t *env);

    /**
    * Get the x509 crtificate used.
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN oxs_x509_cert_t* AXIS2_CALL
    oxs_asym_ctx_get_certificate(const oxs_asym_ctx_t *ctx,
                                 const axutil_env_t *env);

    /**
    * Set the file name. May be a PKCS12 file or a X509 certificate in PEM format.
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_file_name(oxs_asym_ctx_t *ctx,
                               const axutil_env_t *env,
                               axis2_char_t *file_name);
    /**
    *Set the base46 encoded certificate/key.
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_pem_buf(oxs_asym_ctx_t *ctx,
                             const axutil_env_t *env,
                             axis2_char_t *pem_buf);
    /**
    * Set the password. Usually the password for the keystore. But alternatively may kepe the
    *password for the private key in a PEM file.
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@password the password
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_password(oxs_asym_ctx_t *ctx,
                              const axutil_env_t *env,
                              axis2_char_t *password);
    /**
    * Sets the format. Can be either PEM or PKCS12
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@format Can be either PEM or PKCS12
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_format(oxs_asym_ctx_t *ctx,
                            const axutil_env_t *env,
                            oxs_asym_ctx_format_t format);
    /**
    * Sets the algorithm   used to encrypt
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@algorithm  used to encrypt
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_algorithm(oxs_asym_ctx_t *ctx,
                               const axutil_env_t *env,
                               axis2_char_t *algorithm);
    /**
    * Set the SecurityTokenReference pattern. For ex: IssuerSerial
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@st_ref_pattern SecurityTokenReference pattern. For ex: IssuerSerial
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_st_ref_pattern(oxs_asym_ctx_t *ctx,
                                    const axutil_env_t *env,
                                    axis2_char_t *st_ref_pattern);
    /**
    * Sets the operation. For ex: Public Key encrypt, Private Key Decrypt
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@operation the operation. For ex: Public Key encrypt, Private Key Decrypt
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_operation(oxs_asym_ctx_t *ctx,
                               const axutil_env_t *env,
                               oxs_asym_ctx_operation_t operation);
    /**
    * Sets the x509 crtificate used.
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@certificate the x509 crtificate used.
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_certificate(oxs_asym_ctx_t *ctx,
                                 const axutil_env_t *env,
                                 oxs_x509_cert_t *certificate);
    /**
    * Sets private key used
    *@ctx pointer to the OMXMLSec asymmetric context struct
    *@env pointer to environment struct
    *@private_key private key used
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE	
    */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_asym_ctx_set_private_key(oxs_asym_ctx_t *asym_ctx,
                                 const axutil_env_t *env,
                                 openssl_pkey_t *private_key);
    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_ASYM_CTX_H */
