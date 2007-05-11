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
#include <oxs_error.h>
#include <oxs_cipher.h>
#include <openssl_constants.h>
#include <openssl_util.h>


AXIS2_EXTERN openssl_cipher_property_t *AXIS2_CALL
oxs_get_cipher_property_for_url(const axutil_env_t *env,
                                axis2_char_t *url)
{
    openssl_cipher_property_t *cprop = NULL;
    axis2_char_t *cipher_name = NULL;
    axis2_status_t ret = AXIS2_SUCCESS;

    cprop = openssl_cipher_property_create(env);
    ret = openssl_cipher_property_set_url(cprop, env , url);

    cipher_name = oxs_get_cipher_name_for_url(env, url);
    if((!cipher_name) || (0 == axutil_strcmp(cipher_name, ""))){
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_INVALID_DATA, "Cannot populate cipher property");
        return NULL;
    }
    ret = openssl_cipher_property_set_name(cprop, env , cipher_name);

    ret = openssl_populate_cipher_property(env, cprop);
    if (ret == AXIS2_FAILURE)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_INVALID_DATA, "Cannot populate cipher property");
        return NULL;

    }
    return cprop;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
oxs_get_cipher_name_for_url(const axutil_env_t *env,
                            axis2_char_t *url)
{

    axis2_char_t *cipher_name = NULL;

    if (0 == axutil_strcmp(url, (axis2_char_t*)OXS_HREF_DES3_CBC))
    {
        cipher_name = OPENSSL_EVP_des_ede3_cbc;

    }
    else if (0 == axutil_strcmp(url, (axis2_char_t*)OXS_HREF_AES_128_CBC))
    {
        cipher_name = OPENSSL_EVP_aes_128_cbc;

    }
    else if (0 == axutil_strcmp(url, (axis2_char_t*)OXS_HREF_AES_192_CBC))
    {
        cipher_name = OPENSSL_EVP_aes_192_cbc;

    }
    else if (0 == axutil_strcmp(url, (axis2_char_t*)OXS_HREF_AES_256_CBC))
    {
        cipher_name = OPENSSL_EVP_aes_256_cbc;

    }
    else
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_UNSUPPORTED_ALGO, "Algorithm not supported");
        return NULL;
    }

    return cipher_name;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
oxs_get_cipher_url_for_name(const axutil_env_t *env,
                            axis2_char_t *name)
{

    axis2_char_t *cipher_url = NULL;

    if (0 == axutil_strcmp(name, (axis2_char_t*)OPENSSL_EVP_des_ede3_cbc))
    {
        cipher_url = OXS_HREF_DES3_CBC;

    }
    else if (0 == axutil_strcmp(name, (axis2_char_t*)OPENSSL_EVP_aes_128_cbc))
    {
        cipher_url = OXS_HREF_AES_128_CBC;

    }
    else if (0 == axutil_strcmp(name, (axis2_char_t*)OPENSSL_EVP_aes_192_cbc))
    {
        cipher_url = OXS_HREF_AES_192_CBC;

    }
    else if (0 == axutil_strcmp(name, (axis2_char_t*)OPENSSL_EVP_aes_256_cbc))
    {
        cipher_url = OXS_HREF_AES_256_CBC;

    }
    else
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_INVALID_DATA, "Name not supported");
        return NULL;
    }

    return cipher_url;
}

