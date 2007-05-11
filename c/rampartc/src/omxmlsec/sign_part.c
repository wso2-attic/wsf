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
#include <oxs_sign_part.h>
#include <oxs_error.h>

struct oxs_sign_part_t
{
    axis2_char_t *id;
    axis2_char_t *digest_mtd;
    axis2_char_t *digest_val;
    axiom_node_t *node ; /*Shallow copies*/
    axutil_array_list_t *transforms; /*Shallow copies*/
};


/*Public functions*/
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_sign_part_get_id(
    const oxs_sign_part_t *sign_part,
    const axutil_env_t *env)
{
    return sign_part->id;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_sign_part_get_digest_mtd(
    const oxs_sign_part_t *sign_part,
    const axutil_env_t *env)
{
    return sign_part->digest_mtd;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_sign_part_get_digest_val(
    const oxs_sign_part_t *sign_part,
    const axutil_env_t *env)
{
    return sign_part->digest_val;
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
oxs_sign_part_get_node(
    const oxs_sign_part_t *sign_part,
    const axutil_env_t *env)
{
    return sign_part->node;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
oxs_sign_part_get_transforms(
    const oxs_sign_part_t *sign_part,
    const axutil_env_t *env)
{
    return sign_part->transforms;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_part_set_id(
    oxs_sign_part_t *sign_part,
    const axutil_env_t *env,
    axis2_char_t *id)
{

    if (sign_part->id)
    {
        AXIS2_FREE(env->allocator, sign_part->id);
        sign_part->id = NULL;
    }
    sign_part->id = axutil_strdup(env, id);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_part_set_digest_mtd(
    oxs_sign_part_t *sign_part,
    const axutil_env_t *env,
    axis2_char_t *digest_mtd)
{

    if (sign_part->digest_mtd)
    {
        AXIS2_FREE(env->allocator, sign_part->digest_mtd);
        sign_part->digest_mtd = NULL;
    }
    sign_part->digest_mtd = axutil_strdup(env, digest_mtd);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_part_set_digest_val(
    oxs_sign_part_t *sign_part,
    const axutil_env_t *env,
    axis2_char_t *digest_val)
{

    if (sign_part->digest_val)
    {
        AXIS2_FREE(env->allocator, sign_part->digest_val);
        sign_part->digest_val = NULL;
    }
    sign_part->digest_val = axutil_strdup(env, digest_val);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_part_set_node(
    oxs_sign_part_t *sign_part,
    const axutil_env_t *env,
    axiom_node_t *node)
{
    if(sign_part->node){
        sign_part->node = NULL;
    }
    sign_part->node = node;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_part_set_transforms(
    oxs_sign_part_t *sign_part,
    const axutil_env_t *env,
    axutil_array_list_t *transforms)
{
    if(sign_part->transforms){
        sign_part->transforms = NULL;
    }
    sign_part->transforms = transforms;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN oxs_sign_part_t *AXIS2_CALL
oxs_sign_part_create(const axutil_env_t *env)
{
    oxs_sign_part_t *sign_part = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    sign_part = AXIS2_MALLOC(env->allocator, sizeof(oxs_sign_part_t));
    if (!sign_part)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    sign_part->id= NULL;
    sign_part->digest_mtd = NULL;
    sign_part->digest_val = NULL;
    sign_part->node = NULL;
    sign_part->transforms = NULL;

    return sign_part;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_sign_part_free(oxs_sign_part_t *sign_part,
                   const axutil_env_t *env)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (sign_part->id)
    {
        AXIS2_FREE(env->allocator, sign_part->id);
        sign_part->id = NULL;
    }

    if (sign_part->digest_mtd)
    {
        AXIS2_FREE(env->allocator, sign_part->digest_mtd);
        sign_part->digest_mtd = NULL;
    }

    if (sign_part->digest_val)
    {
        AXIS2_FREE(env->allocator, sign_part->digest_val);
        sign_part->digest_val = NULL;
    }

    sign_part->node = NULL;
    sign_part->transforms = NULL;

    AXIS2_FREE(env->allocator,  sign_part);
    sign_part = NULL;

    return AXIS2_SUCCESS;
}


