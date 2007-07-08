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

#ifndef NEETHI_POLICY_H
#define NEETHI_POLICY_H


/**
  * @file neethi_policy.h
  * @struct for operator neethi_policy 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <neethi_operator.h>
#include <neethi_includes.h>
#include <neethi_exactlyone.h>

#ifdef __cplusplus
extern "C"
{
#endif

        typedef struct neethi_policy_t neethi_policy_t; 

        AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
        neethi_policy_create(const axutil_env_t *env);

        AXIS2_EXTERN void AXIS2_CALL
        neethi_policy_free(neethi_policy_t *neethi_policy,
                const axutil_env_t *env);
                
        AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
        neethi_policy_get_policy_components(
            neethi_policy_t *neethi_policy,
            const axutil_env_t *env);

        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_policy_add_policy_components(
            neethi_policy_t *neethi_policy,
            axutil_array_list_t *arraylist,
            const axutil_env_t *env);
        
        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_policy_add_operator(neethi_policy_t *neethi_policy,
            const axutil_env_t *env,
            neethi_operator_t *op);

        AXIS2_EXTERN axis2_bool_t AXIS2_CALL
        neethi_policy_is_empty(neethi_policy_t *neethi_policy,
            const axutil_env_t *env);

        AXIS2_EXTERN neethi_exactlyone_t *AXIS2_CALL
        neethi_policy_get_exactlyone(
        neethi_policy_t *normalized_neethi_policy,
            const axutil_env_t *env);
        
        AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
        neethi_policy_get_alternatives(
            neethi_policy_t *neethi_policy,
            const axutil_env_t *env);
       
        AXIS2_EXTERN axis2_char_t *AXIS2_CALL
        neethi_policy_get_name(
            neethi_policy_t *neethi_policy,
            const axutil_env_t *env);

        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_policy_set_name(
            neethi_policy_t *neethi_policy,
            const axutil_env_t *env,
            axis2_char_t *name);

        AXIS2_EXTERN axis2_char_t *AXIS2_CALL
        neethi_policy_get_id(
            neethi_policy_t *neethi_policy,
            const axutil_env_t *env);

        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_policy_set_id(
            neethi_policy_t *neethi_policy,
            const axutil_env_t *env,
            axis2_char_t *id);

        AXIS2_EXTERN axiom_node_t *AXIS2_CALL
        neethi_policy_serialize(
            neethi_policy_t *neethi_policy,
            axiom_node_t *parent,
            const axutil_env_t *env);
        
        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_policy_set_components_null(
            neethi_policy_t *policy,
            const axutil_env_t *env);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* NEETHI_POLICY_H */
