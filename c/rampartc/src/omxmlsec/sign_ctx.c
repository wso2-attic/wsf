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
#include <oxs_sign_ctx.h>
#include <oxs_error.h>

struct oxs_sign_ctx_t
{
    axis2_char_t *sign_mtd_algo;
    axis2_char_t *c14n_mtd ;
    axis2_char_t *sig_val ;
    axutil_array_list_t *sign_parts;
    oxs_x509_cert_t *certificate ;
    openssl_pkey_t *prv_key ;
    openssl_pkey_t *pub_key ;
    oxs_sign_operation_t operation;
};

/*Public functions*/


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_sign_ctx_get_sign_mtd_algo(
    const oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env)
{
    return sign_ctx->sign_mtd_algo;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_sign_ctx_get_c14n_mtd(
    const oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env)
{
    return sign_ctx->c14n_mtd;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_sign_ctx_get_sig_val(
    const oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env)
{
    return sign_ctx->sig_val;
}


AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
oxs_sign_ctx_get_sign_parts(
    const oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env)
{
    return sign_ctx->sign_parts;
}

AXIS2_EXTERN oxs_x509_cert_t *AXIS2_CALL
oxs_sign_ctx_get_certificate(
    const oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env)
{
    return sign_ctx->certificate ;
}

AXIS2_EXTERN openssl_pkey_t *AXIS2_CALL
oxs_sign_ctx_get_private_key(
    const oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env)
{
    return sign_ctx->prv_key ;
}

AXIS2_EXTERN openssl_pkey_t *AXIS2_CALL
oxs_sign_ctx_get_public_key(
    const oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env)
{
    /*If the public key is set then use it. Else get the public key from the certificate.*/
    if(sign_ctx->pub_key){
        AXIS2_LOG_INFO(env->log, "[oxs][sign_ctx] Public key is available directly");
        return sign_ctx->pub_key ;
    }else if(sign_ctx->certificate){
        AXIS2_LOG_INFO(env->log, "[oxs][sign_ctx] Public key is not available directly. Extracting the certificate");
        return oxs_x509_cert_get_public_key(sign_ctx->certificate, env);
    }else{
        AXIS2_LOG_INFO(env->log, "[oxs][sign_ctx] Public key is available neither in the ctx nor in the certificate");
        return NULL;
    }
}

AXIS2_EXTERN oxs_sign_operation_t AXIS2_CALL
oxs_sign_ctx_get_operation(
    const oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env)
{
    return sign_ctx->operation;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_set_certificate(
    oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env,
    oxs_x509_cert_t *certificate)
{
    if (sign_ctx->certificate )
    {
        sign_ctx->certificate = NULL;
    }
    sign_ctx->certificate =  certificate;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_set_private_key(
    oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env,
    openssl_pkey_t *prv_key)
{
    if (sign_ctx->prv_key )
    {
        sign_ctx->prv_key = NULL;
    }
    sign_ctx->prv_key = prv_key;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_set_public_key(
    oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env,
    openssl_pkey_t *pub_key)
{
    if (sign_ctx->pub_key )
    {
        sign_ctx->pub_key = NULL;
    }
    sign_ctx->pub_key = pub_key;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_set_sign_mtd_algo(
    oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env,
    axis2_char_t *sign_mtd_algo)
{

    if (sign_ctx->sign_mtd_algo)
    {
        AXIS2_FREE(env->allocator, sign_ctx->sign_mtd_algo);
        sign_ctx->sign_mtd_algo = NULL;
    }
    sign_ctx->sign_mtd_algo = axutil_strdup(env,sign_mtd_algo);
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_set_c14n_mtd(
    oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env,
    axis2_char_t *c14n_mtd)
{

    if (sign_ctx->c14n_mtd)
    {
        AXIS2_FREE(env->allocator, sign_ctx->c14n_mtd);
        sign_ctx->c14n_mtd = NULL;
    }
    sign_ctx->c14n_mtd = axutil_strdup(env, c14n_mtd);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_set_sig_val(
    oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env,
    axis2_char_t *sig_val)
{

    if (sign_ctx->sig_val)
    {
        AXIS2_FREE(env->allocator, sign_ctx->sig_val);
        sign_ctx->sig_val = NULL;
    }
    sign_ctx->sig_val = axutil_strdup(env, sig_val);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_set_sign_parts(
    oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env,
    axutil_array_list_t *sign_parts)
{
    if(sign_ctx->sign_parts){
        sign_ctx->sign_parts = NULL;
    }
    sign_ctx->sign_parts = sign_parts;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_set_operation(
    oxs_sign_ctx_t *sign_ctx,
    const axutil_env_t *env,
    oxs_sign_operation_t operation
)
{
    sign_ctx->operation = operation;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN oxs_sign_ctx_t *AXIS2_CALL
oxs_sign_ctx_create(const axutil_env_t *env)
{
    oxs_sign_ctx_t *sign_ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    sign_ctx = AXIS2_MALLOC(env->allocator, sizeof(oxs_sign_ctx_t));
    if (!sign_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    sign_ctx->sign_mtd_algo= NULL;
    sign_ctx->c14n_mtd = NULL;
    sign_ctx->sig_val = NULL;
    sign_ctx->sign_parts = NULL;
    sign_ctx->certificate = NULL;
    sign_ctx->prv_key = NULL;
    sign_ctx->pub_key = NULL;
    sign_ctx->operation = OXS_SIGN_OPERATION_NONE;
    return sign_ctx;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_ctx_free(oxs_sign_ctx_t *sign_ctx,
                  const axutil_env_t *env)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (sign_ctx->sign_mtd_algo)
    {
        AXIS2_FREE(env->allocator, sign_ctx->sign_mtd_algo);
        sign_ctx->sign_mtd_algo = NULL;
    }

    if (sign_ctx->c14n_mtd)
    {
        AXIS2_FREE(env->allocator, sign_ctx->c14n_mtd);
        sign_ctx->c14n_mtd = NULL;
    }

    if (sign_ctx->sig_val)
    {
        AXIS2_FREE(env->allocator, sign_ctx->sig_val);
        sign_ctx->sig_val = NULL;
    }

    sign_ctx->sign_parts = NULL;
    sign_ctx->certificate = NULL;
    sign_ctx->prv_key = NULL;
    sign_ctx->pub_key = NULL;
    sign_ctx->operation = OXS_SIGN_OPERATION_NONE;

    AXIS2_FREE(env->allocator,  sign_ctx);
    sign_ctx = NULL;

    return AXIS2_SUCCESS;
}


