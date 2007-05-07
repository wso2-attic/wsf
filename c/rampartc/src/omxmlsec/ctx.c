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
#include <oxs_constants.h>
#include <oxs_ctx.h>


struct oxs_ctx_t
{
    /*Encryption mode*/
    oxs_ctx_mode_t mode;

    /*transformation type */
    oxs_ctx_operation_t operation;

    /*key*/
    oxs_key_t* key;

    /* attributes from EncryptedData or EncryptedKey */
    axis2_char_t*           id;
    axis2_char_t*           type;
    axis2_char_t*           mime_type;
    axis2_char_t*           encoding;
    axis2_char_t*           recipient;
    axis2_char_t*           carried_key_name;

    /*attributes from EncryptionMethod*/
    axis2_char_t*           enc_mtd_algorithm;

    /*Used  in decryption process to keep the data to be decrypted*/
    axis2_char_t*           input_data;

};

/******************* function headers ******************************/
AXIS2_EXTERN oxs_ctx_t *AXIS2_CALL
oxs_ctx_create(const axutil_env_t *env)
{
    oxs_ctx_t *ctx = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    ctx = (oxs_ctx_t*)AXIS2_MALLOC(env->allocator, sizeof(oxs_ctx_t));
    if (!ctx)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    ctx->mode  = -1;
    ctx->operation  = -1;
    ctx->key  = NULL;
    ctx->id  = NULL;
    ctx->type  = NULL;
    ctx->mime_type  = NULL;
    ctx->encoding  = NULL;
    ctx->recipient  = NULL;
    ctx->carried_key_name  = NULL;
    ctx->enc_mtd_algorithm  = NULL;
    ctx->input_data  = NULL;

    return ctx;
}


/*public functions*/
axis2_status_t AXIS2_CALL
oxs_ctx_free(oxs_ctx_t *ctx,
             const axutil_env_t *env
            )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (ctx->id)
    {
        AXIS2_FREE(env->allocator, ctx->id);
        ctx->id = NULL;
    }

    if (ctx->type)
    {
        AXIS2_FREE(env->allocator, ctx->type);
        ctx->type = NULL;
    }

    if (ctx->mime_type)
    {
        AXIS2_FREE(env->allocator, ctx->mime_type);
        ctx->mime_type = NULL;
    }

    if (ctx->encoding)
    {
        AXIS2_FREE(env->allocator, ctx->encoding);
        ctx->encoding = NULL;
    }

    if (ctx->recipient)
    {
        AXIS2_FREE(env->allocator, ctx->recipient);
        ctx->recipient = NULL;
    }

    if (ctx->carried_key_name)
    {
        AXIS2_FREE(env->allocator, ctx->carried_key_name);
        ctx->carried_key_name = NULL;
    }

    if (ctx->enc_mtd_algorithm)
    {
        AXIS2_FREE(env->allocator, ctx->enc_mtd_algorithm);
        ctx->enc_mtd_algorithm = NULL;
    }

    if (ctx->input_data)
    {
        AXIS2_FREE(env->allocator, ctx->input_data);
        ctx->input_data = NULL;
    }

    /*TODO free nodes and key*/

    AXIS2_FREE(env->allocator,  ctx);
    ctx = NULL;

    return AXIS2_SUCCESS;
}

oxs_ctx_mode_t AXIS2_CALL
oxs_ctx_get_mode(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return ctx->mode ;
}

oxs_ctx_operation_t AXIS2_CALL
oxs_ctx_get_operation(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return ctx->operation ;
}


oxs_key_t *AXIS2_CALL
oxs_ctx_get_key(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->key ;
}


axis2_char_t *AXIS2_CALL
oxs_ctx_get_id(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->id ;
}


axis2_char_t *AXIS2_CALL
oxs_ctx_get_type(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->type ;
}


axis2_char_t *AXIS2_CALL
oxs_ctx_get_mime_type(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->mime_type ;
}


axis2_char_t *AXIS2_CALL
oxs_ctx_get_encoding(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->encoding ;
}


axis2_char_t *AXIS2_CALL
oxs_ctx_get_recipient(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->recipient ;
}


axis2_char_t *AXIS2_CALL
oxs_ctx_get_carried_key_name(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->carried_key_name ;
}


axis2_char_t *AXIS2_CALL
oxs_ctx_get_enc_mtd_algorithm(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->enc_mtd_algorithm ;
}


axis2_char_t *AXIS2_CALL
oxs_ctx_get_input_data(
    oxs_ctx_t *ctx,
    const axutil_env_t *env
)
{
    AXIS2_ENV_CHECK(env, NULL);

    return ctx->input_data ;
}


axis2_status_t AXIS2_CALL
oxs_ctx_set_mode(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    oxs_ctx_mode_t mode
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    ctx->mode = mode ;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_operation(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    oxs_ctx_operation_t operation
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    ctx->operation = operation ;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_key(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    oxs_key_t *key
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (ctx->key)
    {
        AXIS2_FREE(env->allocator, ctx->key);
        ctx->key = NULL;
    }
    ctx->key = key;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_id(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    axis2_char_t *id
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, id, AXIS2_FAILURE);

    if (ctx->id)
    {
        AXIS2_FREE(env->allocator, ctx->id);
        ctx->id = NULL;
    }
    ctx->id = axutil_strdup(env, id);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_type(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    axis2_char_t *type
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, type, AXIS2_FAILURE);

    if (ctx->type)
    {
        AXIS2_FREE(env->allocator, ctx->type);
        ctx->type = NULL;
    }
    ctx->type = axutil_strdup(env, type);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_mime_type(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    axis2_char_t *mime_type
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, mime_type, AXIS2_FAILURE);

    if (ctx->mime_type)
    {
        AXIS2_FREE(env->allocator, ctx->mime_type);
        ctx->mime_type = NULL;
    }
    ctx->mime_type = axutil_strdup(env, mime_type);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_encoding(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    axis2_char_t *encoding
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, encoding, AXIS2_FAILURE);

    if (ctx->encoding)
    {
        AXIS2_FREE(env->allocator, ctx->encoding);
        ctx->encoding = NULL;
    }
    ctx->encoding = axutil_strdup(env, encoding);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_recipient(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    axis2_char_t *recipient
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, recipient, AXIS2_FAILURE);

    if (ctx->recipient)
    {
        AXIS2_FREE(env->allocator, ctx->recipient);
        ctx->recipient = NULL;
    }
    ctx->recipient = axutil_strdup(env, recipient);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_carried_key_name(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    axis2_char_t *carried_key_name
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, carried_key_name, AXIS2_FAILURE);

    if (ctx->carried_key_name)
    {
        AXIS2_FREE(env->allocator, ctx->carried_key_name);
        ctx->carried_key_name = NULL;
    }
    ctx->carried_key_name = axutil_strdup(env, carried_key_name);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_enc_mtd_algorithm(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    axis2_char_t *enc_mtd_algorithm
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, enc_mtd_algorithm, AXIS2_FAILURE);

    if (ctx->enc_mtd_algorithm)
    {
        AXIS2_FREE(env->allocator, ctx->enc_mtd_algorithm);
        ctx->enc_mtd_algorithm = NULL;
    }
    ctx->enc_mtd_algorithm = axutil_strdup(env, enc_mtd_algorithm);

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
oxs_ctx_set_input_data(
    oxs_ctx_t *ctx,
    const axutil_env_t *env,
    axis2_char_t *input_data
)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, input_data, AXIS2_FAILURE);

    if (ctx->input_data)
    {
        AXIS2_FREE(env->allocator, ctx->input_data);
        ctx->input_data = NULL;
    }
    ctx->input_data = axutil_strdup(env, input_data) ;

    return AXIS2_SUCCESS;
}

