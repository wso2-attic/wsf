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

#ifndef AXIS2_POLICY_INCLUDE_H
#define AXIS2_POLICY_INCLUDE_H

/** 
 * @defgroup axis2_policy_include policy include
 * @ingroup axis2_desc
 * @{
 */

#include <axutil_array_list.h>
#include <axis2_desc.h>
#include <neethi_policy.h>
#include <neethi_registry.h>
#include <neethi_reference.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_policy_include */
    typedef struct axis2_policy_include axis2_policy_include_t;

    typedef enum axis2_policy_types
    {
        AXIS2_POLICY = 0,
        AXIS2_MODULE_POLICY,
        AXIS2_SERVICE_POLICY,
        AXIS2_OPERATION_POLICY,
        AXIS2_MESSAGE_POLICY,
        AXIS2_PORT_POLICY,
        AXIS2_PORT_TYPE_POLICY,
        AXIS2_BINDING_POLICY,
        AXIS2_BINDING_OPERATION_POLICY,
        AXIS2_INPUT_POLICY,
        AXIS2_OUTPUT_POLICY,
        AXIS2_BINDING_INPUT_POLICY,
        AXIS2_BINDING_OUTPUT_POLICY,
        AXIS2_MODULE_OPERATION_POLICY,
        AXIS2_POLICY_REF,
        AXIS2_ANON_POLICY
    } axis2_policy_types;

   
    /**
     * Creates policy include struct.
     * @param env pointer to environment struct
     * @return pointer to newly created policy include
     */
    AXIS2_EXTERN axis2_policy_include_t *AXIS2_CALL
    axis2_policy_include_create(const axutil_env_t *env);

    AXIS2_EXTERN axis2_policy_include_t *AXIS2_CALL
    axis2_policy_include_create_with_desc(const axutil_env_t *env,
        axis2_desc_t *desc);

    /**
     * Frees policy include.
     * @param policy_include pointer to policy include
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_policy_include_free(axis2_policy_include_t *policy_include,
        const axutil_env_t *env);


    AXIS2_EXTERN void AXIS2_CALL
    axis2_policy_include_free(
        axis2_policy_include_t *policy_include,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_set_registry(axis2_policy_include_t *policy_include,
        const axutil_env_t *env, 
        neethi_registry_t *registry);

    AXIS2_EXTERN neethi_registry_t *AXIS2_CALL
    axis2_policy_include_get_registry(axis2_policy_include_t *policy_include,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_set_policy(axis2_policy_include_t *policy_include,
        const axutil_env_t *env, 
        neethi_policy_t *policy);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_update_policy(axis2_policy_include_t *policy_include,
        const axutil_env_t *env, 
        neethi_policy_t *policy);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_set_effective_policy(axis2_policy_include_t *policy_include,
        const axutil_env_t *env, 
        neethi_policy_t *effective_policy);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_set_desc(axis2_policy_include_t *policy_include,
        const axutil_env_t *env, 
        axis2_desc_t *desc);

    AXIS2_EXTERN axis2_desc_t *AXIS2_CALL
    axis2_policy_include_get_desc(axis2_policy_include_t *policy_include,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_policy_include_t *AXIS2_CALL
    axis2_policy_include_get_parent(axis2_policy_include_t *policy_include,
        const axutil_env_t *env);

    AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
    axis2_policy_include_get_policy(axis2_policy_include_t *policy_include,
        const axutil_env_t *env);

    AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
    axis2_policy_include_get_effective_policy(axis2_policy_include_t *policy_include,
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_policy_include_get_policy_elements(axis2_policy_include_t *policy_include,
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_policy_include_get_policy_elements_with_type(axis2_policy_include_t *policy_include,
        const axutil_env_t *env,
        int type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_register_policy(axis2_policy_include_t *policy_include,
        const axutil_env_t *env,
        axis2_char_t *key,
        neethi_policy_t *effective_policy);

    AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
    axis2_policy_include_get_policy_with_key(axis2_policy_include_t *policy_include,
        const axutil_env_t *env,
        axis2_char_t *key);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_add_policy_element(axis2_policy_include_t *policy_include,
        const axutil_env_t *env,
        int type,
        neethi_policy_t *policy);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_add_policy_reference_element(axis2_policy_include_t *policy_include,
        const axutil_env_t *env,
        int type,
        neethi_reference_t *reference);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_remove_policy_element(axis2_policy_include_t *policy_include,
        const axutil_env_t *env,
        axis2_char_t *policy_uri);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_policy_include_remove_all_policy_element(axis2_policy_include_t *policy_include,
        const axutil_env_t *env);


/** @} */
#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_POLICY_INCLUDE_H */
