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

#ifndef AXUTIL_GENERIC_OBJ_H
#define AXUTIL_GENERIC_OBJ_H

#include <axutil_utils_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <axutil_utils.h>


#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axutil_generic_obj axutil_generic_obj_t;

    /**
     * @defgroup axutil_generic_obj generic object
     * @ingroup axis2_util
     * @{
     */

    /**
     * create new generic_obj
     * @return generic_obj newly created generic_obj
     */
    AXIS2_EXTERN axutil_generic_obj_t * AXIS2_CALL
    axutil_generic_obj_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_generic_obj_free(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_generic_obj_set_free_func(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env,
        AXIS2_FREE_VOID_ARG free_func);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_generic_obj_set_value(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env,
        void *value);

    AXIS2_EXTERN void * AXIS2_CALL
    axutil_generic_obj_get_value(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_generic_obj_set_type(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env,
        int type);

    AXIS2_EXTERN int AXIS2_CALL
    axutil_generic_obj_get_type(axutil_generic_obj_t *generic_obj,
        const axutil_env_t *env);


#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_GENERIC_OBJ_H */


