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

#ifndef AXUTIL_FILE_H
#define AXUTIL_FILE_H

#include <axutil_utils_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <axutil_utils.h>
#include <platforms/axutil_platform_auto_sense.h>


#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axutil_file axutil_file_t;

    /**
     * @defgroup axutil_file file
     * @ingroup axis2_util
     * @{
     */

    /**
     * create new file
     * @return file newly created file
     */
    AXIS2_EXTERN axutil_file_t * AXIS2_CALL
    axutil_file_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_file_free(axutil_file_t *file,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_file_set_name(axutil_file_t *file,
        const axutil_env_t *env,
        axis2_char_t *name);

    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axutil_file_get_name(axutil_file_t *file,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_file_set_path(axutil_file_t *file,
        const axutil_env_t *env,
        axis2_char_t *path);

    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axutil_file_get_path(axutil_file_t *file,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_file_set_timestamp(axutil_file_t *file,
        const axutil_env_t *env,
        AXIS2_TIME_T timestamp);

    AXIS2_EXTERN AXIS2_TIME_T AXIS2_CALL
    axutil_file_get_timestamp(axutil_file_t *file,
        const axutil_env_t *env);

    /**
     * create a newly allocated clone of the argument file
     */
    AXIS2_EXTERN axutil_file_t * AXIS2_CALL
    axutil_file_clone(axutil_file_t *file,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_FILE_H */


