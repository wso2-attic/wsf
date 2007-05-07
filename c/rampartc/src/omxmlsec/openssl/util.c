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

#include <stdio.h>
#include <axis2_util.h>
#include <openssl_util.h>
#include <openssl_constants.h>
#include <openssl_cipher_property.h>
#include <openssl_util.h>
#include <oxs_error.h>
#include <openssl/evp.h>
#include <openssl/rand.h>


AXIS2_EXTERN axis2_status_t AXIS2_CALL
generate_random_data(const axutil_env_t *env, oxs_buffer_t *buffer, int size)
{
    axis2_status_t status =  AXIS2_FAILURE;
    int ret;
    unsigned char temp_buffer[1024];

    ret = RAND_bytes(temp_buffer, size);
    if (ret < 0)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_DEFAULT, "RAND_bytes failed %d", size);
        return AXIS2_FAILURE;
    }
    /*Encoding make it easier to handle random data*/
#if 0
    int encodedlen;
    axis2_char_t *encoded_str = NULL;

    encodedlen = axutil_base64_encode_len(size);
    encoded_str = AXIS2_MALLOC(env->allocator, encodedlen);
    ret = axutil_base64_encode(encoded_str, (const char *)temp_buffer, size);
    status = oxs_buffer_populate(buffer, env, (unsigned char*)encoded_str, size);
    AXIS2_FREE(env->allocator, encoded_str);
    encoded_str = NULL;
#else
    status = oxs_buffer_populate(buffer, env, (unsigned char*)temp_buffer, size);

#endif
    return AXIS2_SUCCESS;
}



AXIS2_EXTERN axis2_status_t  AXIS2_CALL
openssl_populate_cipher_property(const axutil_env_t *env, openssl_cipher_property_t *cprop)
{
    EVP_CIPHER* cipher;
    EVP_CIPHER_CTX ctx;
    axis2_char_t* cipher_name = NULL;

    if (!cprop)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "openssl_cipher_property is NULL");

        return AXIS2_FAILURE;

    }

    cipher_name = openssl_cipher_property_get_name(cprop, env);
    if (!cipher_name)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "openssl_cipher_property name is NULL");

        return AXIS2_FAILURE;

    }

    cipher = (EVP_CIPHER*)openssl_get_evp_cipher_by_name(env, cipher_name);
    if (!cipher)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,
                  "openssl_get_evp_cipher_by_name failed");

        return AXIS2_FAILURE;
    }
    /*Initialize a cipher ctx*/
    EVP_CIPHER_CTX_init(&ctx);
    EVP_CipherInit_ex(&ctx, cipher, NULL, NULL, NULL, -1);

    openssl_cipher_property_set_cipher(cprop, env, cipher);
    openssl_cipher_property_set_key_size(cprop, env, EVP_CIPHER_CTX_key_length(&ctx));
    openssl_cipher_property_set_block_size(cprop, env, EVP_CIPHER_CTX_block_size(&ctx));
    openssl_cipher_property_set_iv_size(cprop, env, EVP_CIPHER_CTX_iv_length(&ctx));

    /*free ctx*/
    EVP_CIPHER_CTX_cleanup(&ctx);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN EVP_CIPHER*  AXIS2_CALL
openssl_get_evp_cipher_by_name(const axutil_env_t *env, axis2_char_t *cipher_name)
{
    EVP_CIPHER* cipher = NULL;

    if (0 == axutil_strcmp((char*)cipher_name, (char*)OPENSSL_EVP_des_ede3_cbc))
    {
        cipher = (EVP_CIPHER*) EVP_des_ede3_cbc();

    }
    else if (0 == axutil_strcmp((char*)cipher_name, (char*)OPENSSL_EVP_aes_128_cbc))
    {
        cipher = (EVP_CIPHER*)EVP_aes_128_cbc();

    }
    else if (0 == axutil_strcmp((char*)cipher_name, (char*)OPENSSL_EVP_aes_192_cbc))
    {
        cipher = (EVP_CIPHER*)EVP_aes_192_cbc();

    }
    else if (0 == axutil_strcmp((char*)cipher_name, (char*)OPENSSL_EVP_aes_256_cbc))
    {
        cipher = (EVP_CIPHER*)EVP_aes_256_cbc();

    }
    else
    {
        return NULL;
    }

    return cipher;
}


