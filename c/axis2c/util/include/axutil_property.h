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

#ifndef AXUTIL_PROPERTY_H
#define AXUTIL_PROPERTY_H

#include <axutil_utils_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <axutil_utils.h>


#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_property property
     * @ingroup axis2_util
     * @{
     */

    typedef struct axutil_property axutil_property_t;

    /**
     * create new property
     * @return property newly created property
     */
    AXIS2_EXTERN axutil_property_t * AXIS2_CALL
    axutil_property_create(
        const axutil_env_t *env);

    /**
     * create new property
     * @param env axis2 environment
     * @param scope scope can be one of following
     *              AXIS2_SCOPE_REQUEST
     *              AXIS2_SCOPE_SESSION
     *              AXIS2_SCOPE_APPLICATION
     *              pass 0 to use default scope of AXIS2_SCOPE_REQUEST
     * @param free_func free function for the value freeing. Pass 0 if
     *              param value is a string
     * @param value value of the property
     * @return property newly created property
     */
    AXIS2_EXTERN axutil_property_t * AXIS2_CALL
    axutil_property_create_with_args(
        const axutil_env_t *env,
        axis2_scope_t scope,
        axis2_bool_t own_value,
        AXIS2_FREE_VOID_ARG free_func,
        void *value);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_property_free(axutil_property_t *property,
        const axutil_env_t *env);

    /**
     * Default scope is AXIS2_SCOPE_REQUEST
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_property_set_scope(axutil_property_t *property,
        const axutil_env_t *env,
        axis2_scope_t scope);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_property_set_free_func(axutil_property_t *property,
        const axutil_env_t *env,
        AXIS2_FREE_VOID_ARG free_func);

/*************************** Function macros **********************************/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_property_set_value(axutil_property_t *property,
        const axutil_env_t *env,
        void *value);
        
    AXIS2_EXTERN void * AXIS2_CALL
    axutil_property_get_value(axutil_property_t *property,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_property_set_own_value(
        axutil_property_t *property,
        const axutil_env_t *env,
        axis2_bool_t own_value);

    AXIS2_EXTERN axutil_property_t* AXIS2_CALL
    axutil_property_clone(axutil_property_t *property,
        const axutil_env_t *env);


/*************************** End of function macros ***************************/

    /** @} */

#ifdef __cplusplus
}
#endif

#endif  /* AXIS2_PROPERTY_H */
