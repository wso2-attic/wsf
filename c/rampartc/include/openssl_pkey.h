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
#include <axis2_util.h>

/**
  * @file openssl_pkey 
  * @brief holds either a public key or a private key. 
  * The type is determined by the type attribute
  */
#ifndef OPENSSL_PKEY_H
#define OPENSSL_PKEY_H

#ifdef __cplusplus
extern "C" {
#endif

    /** @defgroup
     * @ingroup
     * @{
     */

#define OPENSSL_PKEY_TYPE_UNKNOWN        0
#define OPENSSL_PKEY_TYPE_PUBLIC_KEY     1
#define OPENSSL_PKEY_TYPE_PRIVATE_KEY    2


    /** Type name for struct openssl_pkey */
    typedef struct openssl_pkey_t openssl_pkey_t;



    EVP_PKEY *AXIS2_CALL
    openssl_pkey_get_key(
        const openssl_pkey_t *pkey,
        const axutil_env_t *env
    );

    axis2_char_t *AXIS2_CALL
    openssl_pkey_get_name(
        const openssl_pkey_t *pkey,
        const axutil_env_t *env
    );

    int AXIS2_CALL
    openssl_pkey_get_size(
        const openssl_pkey_t *pkey,
        const axutil_env_t *env
    );

    int AXIS2_CALL
    openssl_pkey_get_type(
        const openssl_pkey_t *pkey,
        const axutil_env_t *env
    );


    axis2_status_t AXIS2_CALL
    openssl_pkey_set_key(
        openssl_pkey_t *pkey,
        const axutil_env_t *env,
        EVP_PKEY *key
    );

    axis2_status_t AXIS2_CALL
    openssl_pkey_set_name(
        openssl_pkey_t *pkey,
        const axutil_env_t *env,
        axis2_char_t *name
    );

    axis2_status_t AXIS2_CALL
    openssl_pkey_set_type(
        openssl_pkey_t *pkey,
        const axutil_env_t *env,
        int type
    );

    axis2_status_t AXIS2_CALL
    openssl_pkey_load(
        openssl_pkey_t *pkey,
        const axutil_env_t *env,
        axis2_char_t *filename,
        axis2_char_t *password
    );

    axis2_status_t AXIS2_CALL
    openssl_pkey_populate(
        openssl_pkey_t *pkey,
        const axutil_env_t *env,
        EVP_PKEY *key,
        axis2_char_t *name,
        int type
    );

    axis2_status_t AXIS2_CALL
    openssl_pkey_free(
        openssl_pkey_t *pkey,
        const axutil_env_t *env
    );

    /*Create function*/
    AXIS2_EXTERN openssl_pkey_t *AXIS2_CALL
    openssl_pkey_create(const axutil_env_t *env);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_PKEY_H */
