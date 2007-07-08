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
#include <oxs_asym_ctx.h>
#include <oxs_x509_cert.h>
#include <oxs_error.h>

struct oxs_asym_ctx_t
{
    axis2_char_t *file_name;
    axis2_char_t *pem_buf;
    axis2_char_t *password;
    axis2_char_t *algorithm;
    axis2_char_t *st_ref_pattern;
    oxs_asym_ctx_operation_t operation;
    oxs_asym_ctx_format_t format;
    oxs_x509_cert_t *certificate;
    openssl_pkey_t *private_key;

};


/*Public functions*/

AXIS2_EXTERN
axis2_char_t *AXIS2_CALL
oxs_asym_ctx_get_file_name(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->file_name;
}

AXIS2_EXTERN
axis2_char_t *AXIS2_CALL
oxs_asym_ctx_get_pem_buf(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->pem_buf;
}
AXIS2_EXTERN
axis2_char_t *AXIS2_CALL
oxs_asym_ctx_get_password(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->password;
}
AXIS2_EXTERN
oxs_asym_ctx_format_t AXIS2_CALL
oxs_asym_ctx_get_format(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->format;
}

AXIS2_EXTERN
axis2_char_t *AXIS2_CALL
oxs_asym_ctx_get_algorithm(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->algorithm;
}

AXIS2_EXTERN
axis2_char_t *AXIS2_CALL
oxs_asym_ctx_get_st_ref_pattern(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->st_ref_pattern;
}

AXIS2_EXTERN
oxs_asym_ctx_operation_t AXIS2_CALL
oxs_asym_ctx_get_operation(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{
    return asym_ctx->operation;
}

AXIS2_EXTERN
openssl_pkey_t *AXIS2_CALL
oxs_asym_ctx_get_private_key(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{

    return asym_ctx->private_key;
}

AXIS2_EXTERN
oxs_x509_cert_t *AXIS2_CALL
oxs_asym_ctx_get_certificate(
    const oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env)
{

    return asym_ctx->certificate;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_file_name(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    axis2_char_t *file_name)
{

    if (asym_ctx->file_name)
    {
        AXIS2_FREE(env->allocator, asym_ctx->file_name);
        asym_ctx->file_name = NULL;
    }
    asym_ctx->file_name = axutil_strdup(env, file_name);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_pem_buf(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    axis2_char_t *pem_buf)
{

    if (asym_ctx->pem_buf)
    {
        AXIS2_FREE(env->allocator, asym_ctx->pem_buf);
        asym_ctx->pem_buf = NULL;
    }
    asym_ctx->pem_buf = axutil_strdup(env, pem_buf);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_password(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    axis2_char_t *password)
{

    if (asym_ctx->password)
    {
        AXIS2_FREE(env->allocator, asym_ctx->password);
        asym_ctx->password = NULL;
    }
    asym_ctx->password = axutil_strdup(env, password);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_format(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    oxs_asym_ctx_format_t format)
{

    asym_ctx->format = format;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_algorithm(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    axis2_char_t *algorithm)
{

    if (asym_ctx->algorithm)
    {
        AXIS2_FREE(env->allocator, asym_ctx->algorithm);
        asym_ctx->algorithm = NULL;
    }
    asym_ctx->algorithm = axutil_strdup(env, algorithm);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_st_ref_pattern(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    axis2_char_t *st_ref_pattern)
{
    if (asym_ctx->st_ref_pattern)
    {
        AXIS2_FREE(env->allocator, asym_ctx->st_ref_pattern);
        asym_ctx->st_ref_pattern = NULL;
    }
    asym_ctx->st_ref_pattern = axutil_strdup(env, st_ref_pattern);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_operation(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    oxs_asym_ctx_operation_t operation)
{

    asym_ctx->operation = operation;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_certificate(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    oxs_x509_cert_t *certificate)
{

    if (asym_ctx->certificate)
    {
        oxs_x509_cert_free(asym_ctx->certificate, env);
        asym_ctx->certificate = NULL;
    }
    asym_ctx->certificate = certificate;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_set_private_key(
    oxs_asym_ctx_t *asym_ctx,
    const axutil_env_t *env,
    openssl_pkey_t *private_key)
{

    if (asym_ctx->private_key)
    {
        /*openssl_pkey_free(asym_ctx->private_key, env);*/
        asym_ctx->private_key = NULL;
    }
    asym_ctx->private_key = private_key;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN
oxs_asym_ctx_t *AXIS2_CALL
oxs_asym_ctx_create(const axutil_env_t *env)
{
    oxs_asym_ctx_t *asym_ctx = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    asym_ctx = AXIS2_MALLOC(env->allocator, sizeof(oxs_asym_ctx_t));
    if (!asym_ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    asym_ctx->file_name= NULL;
    asym_ctx->pem_buf= NULL;
    asym_ctx->password= NULL;
    asym_ctx->format= -1;
    asym_ctx->algorithm = NULL;
    asym_ctx->st_ref_pattern = NULL;
    asym_ctx->operation = -1;
    asym_ctx->certificate = NULL;

    return asym_ctx;
}


AXIS2_EXTERN
axis2_status_t AXIS2_CALL
oxs_asym_ctx_free(oxs_asym_ctx_t *asym_ctx,
                  const axutil_env_t *env)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (asym_ctx->file_name)
    {
        AXIS2_FREE(env->allocator, asym_ctx->file_name);
        asym_ctx->file_name = NULL;
    }

    if (asym_ctx->pem_buf)
    {
        AXIS2_FREE(env->allocator, asym_ctx->pem_buf);
        asym_ctx->pem_buf = NULL;
    }

    if (asym_ctx->password)
    {
        AXIS2_FREE(env->allocator, asym_ctx->password);
        asym_ctx->password = NULL;
    }

    if (asym_ctx->algorithm)
    {
        AXIS2_FREE(env->allocator, asym_ctx->algorithm);
        asym_ctx->algorithm = NULL;
    }

    if (asym_ctx->st_ref_pattern)
    {
        AXIS2_FREE(env->allocator, asym_ctx->st_ref_pattern);
        asym_ctx->st_ref_pattern = NULL;
    }

    if (asym_ctx->certificate)
    {
        oxs_x509_cert_free(asym_ctx->certificate, env);
        asym_ctx->certificate = NULL;
    }

    AXIS2_FREE(env->allocator,  asym_ctx);
    asym_ctx = NULL;

    return AXIS2_SUCCESS;
}


