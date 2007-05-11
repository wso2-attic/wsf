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
#include <oxs_transform.h>
#include <oxs_error.h>


struct oxs_transform_t
{
    axis2_char_t *id ;
    oxs_tr_dtype_t input_data_type;
    oxs_tr_dtype_t output_data_type;
    oxs_transform_tr_func transform_func; /*The function to implement the transform*/
};

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
oxs_transform_get_id(
    const oxs_transform_t *transform,
    const axutil_env_t *env)
{
    return transform->id;
}

AXIS2_EXTERN oxs_tr_dtype_t AXIS2_CALL
oxs_transform_get_input_data_type(
    const oxs_transform_t *transform,
    const axutil_env_t *env)
{
    return transform->input_data_type;
}

AXIS2_EXTERN oxs_tr_dtype_t AXIS2_CALL
oxs_transform_get_output_data_type(
    const oxs_transform_t *transform,
    const axutil_env_t *env)
{
    return transform->output_data_type;
}

AXIS2_EXTERN oxs_transform_tr_func AXIS2_CALL
oxs_transform_get_transform_function(
    const oxs_transform_t *transform,
    const axutil_env_t *env)
{
    return transform->transform_func;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_transform_set_id(
    oxs_transform_t *transform,
    const axutil_env_t *env,
    axis2_char_t *id)
{

    if (transform->id)
    {
        AXIS2_FREE(env->allocator, transform->id);
        transform->id = NULL;
    }
    transform->id = axutil_strdup(env, id);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_transform_set_input_data_type(
    oxs_transform_t *transform,
    const axutil_env_t *env,
    oxs_tr_dtype_t input_data_type)
{
    transform->input_data_type = input_data_type;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_transform_set_output_data_type(
    oxs_transform_t *transform,
    const axutil_env_t *env,
    oxs_tr_dtype_t output_data_type)
{
    transform->output_data_type = output_data_type;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_transform_set_transform_func(
    oxs_transform_t *transform,
    const axutil_env_t *env,
    oxs_transform_tr_func transform_func)
{
    transform->transform_func = transform_func;
    return AXIS2_SUCCESS;
}

/*Create function*/
AXIS2_EXTERN oxs_transform_t *AXIS2_CALL
oxs_transform_create(const axutil_env_t *env)
{
    oxs_transform_t *transform = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    transform = AXIS2_MALLOC(env->allocator, sizeof(oxs_transform_t));
    if (!transform)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    /*TODO Set defaults*/
    transform->id = NULL;

    return transform;
}

/*Free*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_transform_free(oxs_transform_t *transform,
                   const axutil_env_t *env)
{
    /*TODO free*/
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (transform->id)
    {
        AXIS2_FREE(env->allocator, transform->id);
        transform->id = NULL;
    }

    AXIS2_FREE(env->allocator,  transform);
    transform = NULL;

    return AXIS2_SUCCESS;
}

