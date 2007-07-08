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

#include<openssl/evp.h>
#include<oxs_buffer.h>

/**
  * @file openssl_cipher_property.h 
  * @brief Bean class for cipher properties
  */
#ifndef OPENSSL_CIPHER_PROPERTY_H
#define OPENSSL_CIPHER_PROPERTY_H

#ifdef __cplusplus
extern "C" {
#endif


    /** Type name for struct  openssl_cipher_property */
    typedef struct openssl_cipher_property_t openssl_cipher_property_t;


    EVP_CIPHER * AXIS2_CALL
    openssl_cipher_property_get_cipher(
        const openssl_cipher_property_t *cprop,
        const axutil_env_t *env);

    axis2_char_t * AXIS2_CALL
    openssl_cipher_property_get_name(
        const openssl_cipher_property_t *cprop,
        const axutil_env_t *env);

    axis2_char_t * AXIS2_CALL
    openssl_cipher_property_get_url(
        const openssl_cipher_property_t *cprop,
        const axutil_env_t *env);

    int AXIS2_CALL
    openssl_cipher_property_get_key_size(
        const openssl_cipher_property_t *cprop,
        const axutil_env_t *env);

    int AXIS2_CALL
    openssl_cipher_property_get_block_size(
        const openssl_cipher_property_t *cprop,
        const axutil_env_t *env);

    int AXIS2_CALL
    openssl_cipher_property_get_iv_size(
        const openssl_cipher_property_t *cprop,
        const axutil_env_t *env);

    axis2_status_t AXIS2_CALL
    openssl_cipher_property_set_cipher(
        openssl_cipher_property_t *cprop,
        const axutil_env_t *env,
        EVP_CIPHER *cipher);

    axis2_status_t AXIS2_CALL
    openssl_cipher_property_set_name(
        openssl_cipher_property_t *cprop,
        const axutil_env_t *env,
        axis2_char_t *name);

    axis2_status_t AXIS2_CALL
    openssl_cipher_property_set_url(
        openssl_cipher_property_t *cprop,
        const axutil_env_t *env,
        axis2_char_t *name);

    axis2_status_t AXIS2_CALL
    openssl_cipher_property_set_key_size(
        openssl_cipher_property_t *cprop,
        const axutil_env_t *env,
        int   key_size);


    axis2_status_t AXIS2_CALL
    openssl_cipher_property_set_block_size(
        openssl_cipher_property_t *cprop,
        const axutil_env_t *env,
        int  block_size);

    axis2_status_t AXIS2_CALL
    openssl_cipher_property_set_iv_size(
        openssl_cipher_property_t *cprop,
        const axutil_env_t *env,
        int   iv_size);

    axis2_status_t AXIS2_CALL
    openssl_cipher_property_free(openssl_cipher_property_t * cprop, const axutil_env_t *env);


    /**
    * Create a fresh block cipher property
    *@return cipher_prop_ptr
    */
    AXIS2_EXTERN openssl_cipher_property_t *AXIS2_CALL
    openssl_cipher_property_create(const axutil_env_t *env);



    /* @} */
#ifdef __cplusplus
}
#endif

#endif    /* OPENSSL_CIPHER_PROPERTY_H */
