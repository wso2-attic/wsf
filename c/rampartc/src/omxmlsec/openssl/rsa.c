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
#include <openssl_rsa.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/rand.h>
#include <oxs_buffer.h>
#include <oxs_error.h>

/**
struct _evp_pkey{
    EVP_PKEY *key;
    unsigned char *name;
    int size;
    int type;
}
*/

int AXIS2_CALL
openssl_rsa_pub_encrypt(
    const axutil_env_t *env,
    const openssl_pkey_t *pkey,
    const axis2_char_t *padding,
    oxs_buffer_t *in,
    oxs_buffer_t *out)
{
    unsigned char *encrypted = NULL;
    int ret;
    EVP_PKEY *key = NULL;
    int pad = RSA_PKCS1_PADDING;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    key = (EVP_PKEY *)openssl_pkey_get_key(pkey, env);
    if(0 == axutil_strcmp(padding, OPENSSL_RSA_PKCS1_OAEP_PADDING  ) ){
        pad = RSA_PKCS1_OAEP_PADDING;
    }else if(0 == axutil_strcmp(padding, OPENSSL_RSA_PKCS1_PADDING  ) ){
        pad = RSA_PKCS1_PADDING;
    }

    encrypted = AXIS2_MALLOC(env->allocator, RSA_size(key->pkey.rsa));
    ret = RSA_public_encrypt(oxs_buffer_get_size(in, env),
                             oxs_buffer_get_data(in, env),
                             encrypted,
                             key->pkey.rsa ,
                             pad);

    if (ret < 0)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_OPENSSL_FUNC_FAILED,
                  "RSA encryption failed");
        return (-1);
    }
    oxs_buffer_populate(out, env, encrypted, ret);
    return ret;
}

int AXIS2_CALL
openssl_rsa_pub_decrypt(
    const axutil_env_t *env,
    const openssl_pkey_t *pkey,
    const axis2_char_t *padding,
    oxs_buffer_t *in,
    oxs_buffer_t *out)
{
    unsigned char *decrypted = NULL;
    int ret;
    EVP_PKEY *key = NULL;
    int pad = RSA_PKCS1_PADDING;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    key = (EVP_PKEY *)openssl_pkey_get_key(pkey, env);
    if(0 == axutil_strcmp(padding, OPENSSL_RSA_PKCS1_OAEP_PADDING  ) ){
        pad = RSA_PKCS1_OAEP_PADDING;
    }else if(0 == axutil_strcmp(padding, OPENSSL_RSA_PKCS1_PADDING  ) ){
        pad = RSA_PKCS1_PADDING;
    }

    decrypted = AXIS2_MALLOC(env->allocator, RSA_size(key->pkey.rsa));
    ret = RSA_public_decrypt(oxs_buffer_get_size(in, env),
                             oxs_buffer_get_data(in, env),
                             decrypted,
                             key->pkey.rsa ,
                             pad);

    if (ret < 0)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_OPENSSL_FUNC_FAILED,
                  "PUBKEY decrypt (signature verification) failed");
        return (-1);
    }
    oxs_buffer_populate(out, env, decrypted, ret);
    return ret;
}


int AXIS2_CALL
openssl_rsa_prv_decrypt(
    const axutil_env_t *env,
    const openssl_pkey_t *pkey,
    const axis2_char_t *padding,
    oxs_buffer_t *in,
    oxs_buffer_t *out)
{
    unsigned char *decrypted = NULL;
    int ret;
    EVP_PKEY *key = NULL;
    int pad = RSA_PKCS1_PADDING;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    key = (EVP_PKEY *)openssl_pkey_get_key(pkey, env);

    /*Set padding. This is the only diff btwn RSA-v1.5 and RSA-OAEP*/
    if(0 == axutil_strcmp(padding, OPENSSL_RSA_PKCS1_OAEP_PADDING  ) ){
        pad = RSA_PKCS1_OAEP_PADDING;
    }else if(0 == axutil_strcmp(padding, OPENSSL_RSA_PKCS1_PADDING  ) ){
        pad = RSA_PKCS1_PADDING;
    }

    decrypted =  AXIS2_MALLOC(env->allocator, RSA_size(key->pkey.rsa));
    ret = RSA_private_decrypt(RSA_size(key->pkey.rsa),
                              oxs_buffer_get_data(in, env),
                              decrypted,
                              key->pkey.rsa,
                              pad);

    if (ret < 0)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_OPENSSL_FUNC_FAILED,
                  "RSA decryption failed");
        return (-1);
    }
    oxs_buffer_populate(out, env, decrypted, ret);
    return ret;
}

int AXIS2_CALL
openssl_rsa_prv_encrypt(
    const axutil_env_t *env,
    const openssl_pkey_t *pkey,
    const axis2_char_t *padding,
    oxs_buffer_t *in,
    oxs_buffer_t *out)
{
    unsigned char *encrypted = NULL;
    int ret;
    EVP_PKEY *key = NULL;
    int pad = RSA_PKCS1_PADDING;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /*Get the private key*/
    key = (EVP_PKEY *)openssl_pkey_get_key(pkey, env);

    /*Set padding. This is the only diff btwn RSA-v1.5 and RSA-OAEP*/
    if(0 == axutil_strcmp(padding, OPENSSL_RSA_PKCS1_OAEP_PADDING  ) ){
        pad = RSA_PKCS1_OAEP_PADDING;
    }else if(0 == axutil_strcmp(padding, OPENSSL_RSA_PKCS1_PADDING  ) ){
        pad = RSA_PKCS1_PADDING;
    }

    encrypted =  AXIS2_MALLOC(env->allocator, RSA_size(key->pkey.rsa));
    ret = RSA_private_encrypt(RSA_size(key->pkey.rsa),
                              oxs_buffer_get_data(in, env),
                              encrypted,
                              key->pkey.rsa,
                              pad);

    if (ret < 0)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_OPENSSL_FUNC_FAILED,
                  "RSA private encryption(Signing) failed. Error code %d: %s",ERR_get_error(), ERR_reason_error_string(ERR_get_error()));
        return (-1);
    }
    oxs_buffer_populate(out, env, encrypted, ret);
    return ret;
}

