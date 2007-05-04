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

#ifndef AXUTIL_PARAM_H
#define AXUTIL_PARAM_H

/**
 * @file axutil_param.h
 * @brief Axis2 param interface
 */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_hash.h>
#include <axutil_array_list.h>

#ifdef __cplusplus
extern "C"
{
#endif


    /**
     * @defgroup axutil_param parameter
     * @ingroup axis2_util
     * @{
     */

    /**
      * TEXT PARAM
      */
    static const int AXIS2_TEXT_PARAM = 0;

    /**
     * Field DOM_PARAM
     */
    static const int AXIS2_DOM_PARAM = 1;

    typedef struct axutil_param axutil_param_t;

    /**
     * creates param struct
     */
    AXIS2_EXTERN axutil_param_t* AXIS2_CALL
    axutil_param_create(const axutil_env_t *env,
        axis2_char_t *name,
        void *value);

    /**
     * Parameter name accessor
     * @return name of the param
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_param_get_name(struct axutil_param *param,
        const axutil_env_t *env);

    /**
     * Parameter value accessor
     * @return Object
     */
    AXIS2_EXTERN void* AXIS2_CALL
    axutil_param_get_value(struct axutil_param *param,
        const axutil_env_t *env);

    /**
     * param name mutator
     * @param name
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_param_set_name(struct axutil_param *param,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /**
     * Method setValue
     *
     * @param value
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_param_set_value(struct axutil_param *param,
        const axutil_env_t *env,
        const void *value);

    /**
     * Method isLocked
     *
     * @return boolean
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axutil_param_is_locked(struct axutil_param *param,
        const axutil_env_t *env);

    /**
     * Method setLocked
     *
     * @param value
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_param_set_locked(struct axutil_param *param,
        const axutil_env_t *env,
        axis2_bool_t value);

    /**
     * Method getParameterType
     *
     * @return int
     */
    AXIS2_EXTERN int AXIS2_CALL
    axutil_param_get_param_type(struct axutil_param *param,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_param_set_param_type(struct axutil_param *param,
        const axutil_env_t *env,
        int type);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_param_free(struct axutil_param *param,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_param_set_attributes(struct axutil_param *param,
        const axutil_env_t *env,
        axutil_hash_t *attrs);

    AXIS2_EXTERN axutil_hash_t* AXIS2_CALL
    axutil_param_get_attributes(struct axutil_param *param,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_param_set_value_list(struct axutil_param *param,
        const axutil_env_t *env,
        axutil_array_list_t *value_list);

    AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
    axutil_param_get_value_list(struct axutil_param *param,
        const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_param_value_free(void *param_value,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_param_set_value_free(struct axutil_param *param,
        const axutil_env_t *env,
        void *free_fn);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_PARAM_H */
