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

#include "axis2_ws_info.h"
#include <string.h>

struct axis2_ws_info
{
    axis2_char_t *file_name;
    long last_modified_date;
    /**
     * To check whether the file is a module or a servise
     */
    int type;
};

AXIS2_EXTERN axis2_ws_info_t *AXIS2_CALL
axis2_ws_info_create_with_file_name_and_last_modified_date(const axutil_env_t *env,
    axis2_char_t *file_name,
    long last_modified_date)
{
    axis2_ws_info_t *ws_info = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, file_name, NULL);

    ws_info = (axis2_ws_info_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axis2_ws_info_t));

    if (! ws_info)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    ws_info->file_name = NULL;
    ws_info->last_modified_date = 0;
    ws_info->type = 0;

    ws_info->file_name = axutil_strdup(env, file_name);
    if (!ws_info->file_name)
    {
        axis2_ws_info_free(ws_info, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    ws_info->last_modified_date = last_modified_date;

    return ws_info;
}

AXIS2_EXTERN axis2_ws_info_t *AXIS2_CALL
axis2_ws_info_create_with_file_name_and_last_modified_date_and_type(const axutil_env_t *env,
    axis2_char_t *file_name,
    long last_modified_date,
    int type)
{
    axis2_ws_info_t *ws_info = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, file_name, NULL);

    ws_info = (axis2_ws_info_t *)
        axis2_ws_info_create_with_file_name_and_last_modified_date(env,
            file_name, last_modified_date);
    if (!ws_info)
    {
        axis2_ws_info_free(ws_info, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    ws_info->type = type;
    return ws_info;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_ws_info_free(axis2_ws_info_t *ws_info,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (ws_info->file_name)
    {
        AXIS2_FREE(env->allocator, ws_info->file_name);
    }

    if (ws_info)
    {
        AXIS2_FREE(env->allocator, ws_info);
    }

    return;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
axis2_ws_info_get_file_name(const axis2_ws_info_t *ws_info,
    const axutil_env_t *env)
{
    return ws_info->file_name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_ws_info_set_file_name(axis2_ws_info_t *ws_info,
    const axutil_env_t *env,
    axis2_char_t *file_name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, file_name, AXIS2_FAILURE);

    if (ws_info->file_name)
    {
        AXIS2_FREE(env->allocator, ws_info->file_name);
        ws_info->file_name = NULL;
    }
    ws_info->file_name = file_name;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN long AXIS2_CALL
axis2_ws_info_get_last_modified_date(const axis2_ws_info_t *ws_info,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return ws_info->last_modified_date;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_ws_info_set_last_modified_date(axis2_ws_info_t *ws_info,
    const axutil_env_t *env,
    long last_modified_date)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    ws_info->last_modified_date = last_modified_date;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_ws_info_get_type(const axis2_ws_info_t *ws_info,
    const axutil_env_t *env)
{
    return ws_info->type;
}

