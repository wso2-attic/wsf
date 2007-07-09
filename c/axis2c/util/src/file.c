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

#include <axutil_file.h>
#include <axutil_string.h>

struct axutil_file
{
    axis2_char_t *name;
    axis2_char_t *path;
    AXIS2_TIME_T timestamp;
};

AXIS2_EXTERN axutil_file_t *AXIS2_CALL
axutil_file_create(const axutil_env_t *env)
{
    axutil_file_t *file = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    file = (axutil_file_t *) AXIS2_MALLOC(env->allocator,
            sizeof(axutil_file_t));

    if (! file)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    file->name = NULL;
    file->path = NULL;
    file->timestamp = 0;

    return file;
}

AXIS2_EXTERN void AXIS2_CALL
axutil_file_free(axutil_file_t *file,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (file->name)
    {
        AXIS2_FREE(env->allocator, file->name);
    }

    if (file->path)
    {
        AXIS2_FREE(env->allocator, file->path);
    }

    if (file)
    {
        AXIS2_FREE(env->allocator, file);
    }
    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_file_set_name(axutil_file_t *file,
        const axutil_env_t *env,
        axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FAILURE);

    if (file->name)
    {
        AXIS2_FREE(env->allocator, file->name);
        file->name = NULL;
    }
    file->name = axutil_strdup(env, name);
    if (!file->name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axutil_file_get_name(axutil_file_t *file,
        const axutil_env_t *env)
{
    if (!file->name)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_FILE_NAME_NOT_SET,
                AXIS2_FAILURE);
        return NULL;
    }
    return (file->name);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_file_set_path(axutil_file_t *file,
        const axutil_env_t *env,
        axis2_char_t *path)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if (!path)
    {
        return AXIS2_SUCCESS;
    }

    if (file->path)
    {
        AXIS2_FREE(env->allocator, file->path);
        file->path = NULL;
    }
    file->path = axutil_strdup(env, path);
    if (!(file->path))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axutil_file_get_path(axutil_file_t *file,
        const axutil_env_t *env)
{
    if (!(file->path))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_FILE_NAME_NOT_SET,
                AXIS2_FAILURE);
        return NULL;
    }

    return (file->path);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_file_set_timestamp(axutil_file_t *file,
        const axutil_env_t *env,
        AXIS2_TIME_T timestamp)
{
    file->timestamp = timestamp;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN AXIS2_TIME_T AXIS2_CALL
axutil_file_get_timestamp(axutil_file_t *file,
        const axutil_env_t *env)
{
    return file->timestamp;
}

AXIS2_EXTERN axutil_file_t *AXIS2_CALL
axutil_file_clone(axutil_file_t *file,
        const axutil_env_t *env)
{
    axutil_file_t *new_file = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    AXIS2_ENV_CHECK(env, NULL);
    new_file = axutil_file_create(env);
    status =  axutil_file_set_name(new_file, env, file->name);
    if (AXIS2_SUCCESS != status)
    {
        return NULL;
    }
    status =  axutil_file_set_path(new_file, env, file->path);
    if (AXIS2_SUCCESS != status)
    {
        return NULL;
    }
     axutil_file_set_timestamp(new_file, env, file->timestamp);
    return new_file;
}


