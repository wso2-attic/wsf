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
#include <openssl_cipher_property.h>
#include <openssl_constants.h>
#include <oxs_error.h>
#include <openssl/evp.h>
#include <openssl/rand.h>


struct openssl_cipher_property_t
{
    EVP_CIPHER                  *cipher;
    axis2_char_t                *name;
    axis2_char_t                *url;
    int                         key_size;
    int                         block_size;
    int                         iv_size;
};


EVP_CIPHER * AXIS2_CALL
openssl_cipher_property_get_cipher(
    const openssl_cipher_property_t *cprop,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return cprop->cipher;
}

axis2_char_t * AXIS2_CALL
openssl_cipher_property_get_name(
    const openssl_cipher_property_t *cprop,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return cprop->name;
}

axis2_char_t * AXIS2_CALL
openssl_cipher_property_get_url(
    const openssl_cipher_property_t *cprop,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return cprop->url;
}


int AXIS2_CALL
openssl_cipher_property_get_key_size(
    const openssl_cipher_property_t *cprop,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return cprop->key_size;
}

int AXIS2_CALL
openssl_cipher_property_get_block_size(
    const openssl_cipher_property_t *cprop,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return cprop->block_size;
}

int AXIS2_CALL
openssl_cipher_property_get_iv_size(
    const openssl_cipher_property_t *cprop,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return cprop->iv_size;
}

axis2_status_t AXIS2_CALL
openssl_cipher_property_set_cipher(
    openssl_cipher_property_t *cprop,
    const axutil_env_t *env,
    EVP_CIPHER *cipher)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (cprop->cipher)
    {
        AXIS2_FREE(env->allocator, cprop->cipher);
        cprop->cipher = NULL;
    }
    cprop->cipher = cipher;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_cipher_property_set_name(
    openssl_cipher_property_t *cprop,
    const axutil_env_t *env,
    axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FAILURE);


    if (cprop->name)
    {
        AXIS2_FREE(env->allocator, cprop->name);
        cprop->name = NULL;
    }
    cprop->name = axutil_strdup(env, name);
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_cipher_property_set_url(
    openssl_cipher_property_t *cprop,
    const axutil_env_t *env,
    axis2_char_t *url)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, url, AXIS2_FAILURE);


    if (cprop->url)
    {
        AXIS2_FREE(env->allocator, cprop->url);
        cprop->url = NULL;
    }
    cprop->url = axutil_strdup(env, url);
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_cipher_property_set_key_size(
    openssl_cipher_property_t *cprop,
    const axutil_env_t *env,
    int   key_size)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    cprop->key_size = key_size;
    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
openssl_cipher_property_set_block_size(
    openssl_cipher_property_t *cprop,
    const axutil_env_t *env,
    int  block_size)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    cprop->block_size = block_size;
    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
openssl_cipher_property_set_iv_size(
    openssl_cipher_property_t *cprop,
    const axutil_env_t *env,
    int   iv_size)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    cprop->iv_size = iv_size;
    return AXIS2_SUCCESS;
}



AXIS2_EXTERN openssl_cipher_property_t *AXIS2_CALL
openssl_cipher_property_create(const axutil_env_t *env)
{
    openssl_cipher_property_t *cprop = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    cprop = (openssl_cipher_property_t *)AXIS2_MALLOC(env->allocator, sizeof(openssl_cipher_property_t));
    if (!cprop)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    cprop->cipher = NULL;
    cprop->name = NULL;
    cprop->url = NULL;
    cprop->key_size = -1;
    cprop->block_size = -1;
    cprop->iv_size = -1;

    return cprop;
}


axis2_status_t AXIS2_CALL
openssl_cipher_property_free(openssl_cipher_property_t * cprop, const axutil_env_t *env)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);


    if (cprop->cipher)
    {
        AXIS2_FREE(env->allocator, cprop->cipher);
        cprop->cipher = NULL;
    }

    if (cprop->name)
    {
        AXIS2_FREE(env->allocator, cprop->name);
        cprop->name = NULL;
    }

    if (cprop->url)
    {
        AXIS2_FREE(env->allocator, cprop->url);
        cprop->url = NULL;
    }

    AXIS2_FREE(env->allocator,  cprop);
    cprop = NULL;

    return AXIS2_SUCCESS;
}

