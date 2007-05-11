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
#include <openssl_pkey.h>
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
struct openssl_pkey_t
{
    EVP_PKEY *key;
    axis2_char_t *name;
    int type;
};


AXIS2_EXTERN openssl_pkey_t *AXIS2_CALL
openssl_pkey_create(const axutil_env_t *env)
{
    openssl_pkey_t * pkey = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    pkey = (openssl_pkey_t *)AXIS2_MALLOC(env->allocator, sizeof(openssl_pkey_t));
    if (!pkey)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    pkey->key   = NULL;
    pkey->name = NULL ;
    pkey->type = OPENSSL_PKEY_TYPE_UNKNOWN;

    return pkey;
}


EVP_PKEY *AXIS2_CALL
openssl_pkey_get_key(
    const openssl_pkey_t *pkey,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return pkey->key ;
}

axis2_char_t *AXIS2_CALL
openssl_pkey_get_name(
    const openssl_pkey_t *pkey,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return pkey->name ;

}
int AXIS2_CALL
openssl_pkey_get_size(
    const openssl_pkey_t *pkey,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return sizeof(pkey->key) ;
}
int AXIS2_CALL
openssl_pkey_get_type(
    const openssl_pkey_t *pkey,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return pkey->type ;
}

axis2_status_t AXIS2_CALL
openssl_pkey_set_key(
    openssl_pkey_t *pkey,
    const axutil_env_t *env,
    EVP_PKEY *key
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (pkey->key)
    {
        AXIS2_FREE(env->allocator, pkey->key);
        pkey->key = NULL;
    }

    pkey->key = key;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_pkey_set_name(
    openssl_pkey_t *pkey,
    const axutil_env_t *env,
    axis2_char_t *name
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FAILURE);
    if (pkey->name)
    {
        AXIS2_FREE(env->allocator, pkey->name);
        pkey->name = NULL;
    }

    pkey->name = axutil_strdup(env, name);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_pkey_set_type(
    openssl_pkey_t *pkey,
    const axutil_env_t *env,
    int type
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    pkey->type = type;

    return AXIS2_SUCCESS;

}

axis2_status_t AXIS2_CALL
openssl_pkey_load(
    openssl_pkey_t *pkey,
    const axutil_env_t *env,
    axis2_char_t *filename,
    axis2_char_t *password
)
{
    EVP_PKEY *pk = NULL;
    BIO *bio;
    int type = OPENSSL_PKEY_TYPE_UNKNOWN;
    int ret ;
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    bio = BIO_new_file(filename, "rb");
    /*Try to read the prv key first*/
    pk = PEM_read_bio_PrivateKey(bio, NULL, 0 , password);
    if (!pk)
    {
        /*If prv key is not found then read the public key*/
        ret  = BIO_reset(bio);
        pk = PEM_read_bio_PUBKEY(bio, NULL, 0 , password);
        if (!pk)
        {
            /*If there is no key by now its an error*/
            oxs_error(env, ERROR_LOCATION, OXS_ERROR_ENCRYPT_FAILED,
                      "Cannot load key from %s", filename);

            return AXIS2_FAILURE;
        }
        type = OPENSSL_PKEY_TYPE_PUBLIC_KEY;
    }
    else
    {
        type = OPENSSL_PKEY_TYPE_PRIVATE_KEY;
    }

    status = openssl_pkey_populate(pkey, env,  pk, filename, type) ;
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_pkey_populate(
    openssl_pkey_t *pkey,
    const axutil_env_t *env,
    EVP_PKEY *key,
    axis2_char_t *name,
    int type
)
{
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    status = openssl_pkey_set_key(pkey, env, key);
    status = openssl_pkey_set_name(pkey, env, name);
    status = openssl_pkey_set_type(pkey, env, type);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_pkey_free(
    openssl_pkey_t *pkey,
    const axutil_env_t *env
)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (pkey->key)
    {
        AXIS2_FREE(env->allocator, pkey->key);
        pkey->key = NULL;
    }
    if (pkey->name)
    {
        AXIS2_FREE(env->allocator, pkey->name);
        pkey->name = NULL;
    }

    AXIS2_FREE(env->allocator, pkey);
    pkey = NULL;

    return AXIS2_SUCCESS;
}




