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
#include <openssl_cipher_ctx.h>
#include <openssl_constants.h>
#include <openssl_cipher_property.h>
#include <oxs_error.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl_util.h>


struct openssl_cipher_ctx_t
{
    const EVP_CIPHER*   cipher;
    oxs_key_t *key;
    axis2_char_t  *iv;
    axis2_char_t  *pad;
};


/******************* end of function headers ******************************/
AXIS2_EXTERN openssl_cipher_ctx_t *AXIS2_CALL
openssl_cipher_ctx_create(const axutil_env_t *env)
{
    openssl_cipher_ctx_t *ctx = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    ctx = (openssl_cipher_ctx_t *)AXIS2_MALLOC(env->allocator, sizeof(openssl_cipher_ctx_t));
    if (!ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    ctx->cipher  = NULL;
    ctx->key  = NULL;
    ctx->iv  = NULL;
    ctx->pad  = NULL;

    return ctx;
}


/* public functions*/
axis2_status_t AXIS2_CALL
openssl_cipher_ctx_free(openssl_cipher_ctx_t *ctx,
                        const axutil_env_t *env
                       )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (ctx->iv)
    {
        AXIS2_FREE(env->allocator, ctx->iv);
        ctx->iv = NULL;
    }

    if (ctx->pad)
    {
        AXIS2_FREE(env->allocator, ctx->pad);
        ctx->pad = NULL;
    }

    AXIS2_FREE(env->allocator,  ctx);
    ctx = NULL;

    return AXIS2_SUCCESS;
}

const EVP_CIPHER* AXIS2_CALL
openssl_cipher_ctx_get_cipher(openssl_cipher_ctx_t *ctx,
                              const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->cipher ;
}

oxs_key_t *AXIS2_CALL
openssl_cipher_ctx_get_key(openssl_cipher_ctx_t *ctx,
                           const axutil_env_t *env
                          )
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->key ;
}

axis2_char_t *AXIS2_CALL
openssl_cipher_ctx_get_iv(openssl_cipher_ctx_t *ctx,
                          const axutil_env_t *env
                         )
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->iv ;
}

axis2_char_t *AXIS2_CALL
openssl_cipher_ctx_get_pad(openssl_cipher_ctx_t *ctx,
                           const axutil_env_t *env
                          )
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->pad;
}

axis2_status_t AXIS2_CALL
openssl_cipher_ctx_set_cipher(openssl_cipher_ctx_t *ctx,
                              const axutil_env_t *env,
                              const EVP_CIPHER *cipher
                             )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /*if (ctx->cipher){
        AXIS2_FREE(env->allocator, ctx->cipher);
        ctx->cipher = NULL;
    }
    */
    ctx->cipher = cipher;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_cipher_ctx_set_key(openssl_cipher_ctx_t *ctx,
                           const axutil_env_t *env,
                           oxs_key_t *key
                          )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, key, AXIS2_FAILURE);

    if (ctx->key)
    {
        oxs_key_free(ctx->key, env);
        ctx->key = NULL;
    }
    ctx->key = key ;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
openssl_cipher_ctx_set_iv(openssl_cipher_ctx_t *ctx,
                          const axutil_env_t *env,
                          axis2_char_t *iv
                         )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, iv, AXIS2_FAILURE);

    if (ctx->iv)
    {
        AXIS2_FREE(env->allocator, ctx->iv);
        ctx->iv = NULL;
    }
    ctx->iv = axutil_strdup(env, iv);

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
openssl_cipher_ctx_set_pad(openssl_cipher_ctx_t *ctx,
                           const axutil_env_t *env,
                           axis2_char_t *pad
                          )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, pad, AXIS2_FAILURE);

    if (ctx->pad)
    {
        AXIS2_FREE(env->allocator, ctx->pad);
        ctx->pad = NULL;
    }
    ctx->pad = axutil_strdup(env, pad);

    return AXIS2_SUCCESS;
}















