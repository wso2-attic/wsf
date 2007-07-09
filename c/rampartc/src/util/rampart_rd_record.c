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

#include <rampart_rd_record.h>
#include <rampart_constants.h>

struct rampart_rd_record_t
{
    axis2_char_t *id;
    axis2_char_t *timestamp;

};
/*Public functions*/

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
rampart_rd_record_get_id(
    const rampart_rd_record_t *rd_record,
    const axutil_env_t *env)
{
    return rd_record->id;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
rampart_rd_record_get_timestamp(
    const rampart_rd_record_t *rd_record,
    const axutil_env_t *env)
{
    return rd_record->timestamp;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_rd_record_set_id(
    rampart_rd_record_t *rd_record,
    const axutil_env_t *env,
    axis2_char_t *id)
{

    if (rd_record->id)
    {
        AXIS2_FREE(env->allocator, rd_record->id );
        rd_record->id = NULL;
    }
    rd_record->id = axutil_strdup(env, id);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_rd_record_set_timestamp(
    rampart_rd_record_t *rd_record,
    const axutil_env_t *env,
    axis2_char_t *timestamp)
{

    if (rd_record->timestamp)
    {
        AXIS2_FREE(env->allocator, rd_record->timestamp );
        rd_record->timestamp = NULL;
    }
    rd_record->timestamp = axutil_strdup(env, timestamp);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN rampart_rd_record_t *AXIS2_CALL
rampart_rd_record_create(const axutil_env_t *env)
{
    rampart_rd_record_t *rd_record = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    rd_record = AXIS2_MALLOC(env->allocator, sizeof(rampart_rd_record_t));
    if (!rd_record)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    rd_record->id = NULL;
    rd_record->timestamp = NULL;

    return rd_record;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_rd_record_free(rampart_rd_record_t *rd_record,
                       const axutil_env_t *env)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (rd_record->id)
    {
        AXIS2_FREE(env->allocator, rd_record->id);
        rd_record->id = NULL;
    }

    if (rd_record->timestamp)
    {
        AXIS2_FREE(env->allocator, rd_record->timestamp);
        rd_record->timestamp = NULL;
    }

    AXIS2_FREE(env->allocator,  rd_record);
    rd_record = NULL;

    return AXIS2_SUCCESS;
}
