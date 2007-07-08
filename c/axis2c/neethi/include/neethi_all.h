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

#ifndef NEETHI_ALL_H
#define NEETHI_ALL_H


/**
  * @file neethi_all.h
  * @struct for operator all 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <neethi_operator.h>
#include <neethi_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

        typedef struct neethi_all_t neethi_all_t; 

        AXIS2_EXTERN neethi_all_t *AXIS2_CALL
        neethi_all_create(const axutil_env_t *env);

        AXIS2_EXTERN void AXIS2_CALL
        neethi_all_free(neethi_all_t *neethi_all,
                const axutil_env_t *env);
                
        AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
        neethi_all_get_policy_components(
            neethi_all_t *neethi_all,
            const axutil_env_t *env);
        
        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_all_add_policy_components(
            neethi_all_t *all,
            axutil_array_list_t *arraylist,
            const axutil_env_t *env);
            
        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_all_add_operator(neethi_all_t *neethi_all,
            const axutil_env_t *env,
            neethi_operator_t *op);

        AXIS2_EXTERN axis2_bool_t AXIS2_CALL
        neethi_all_is_empty(neethi_all_t *all,
            const axutil_env_t *env);

        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_all_serialize(
            neethi_all_t *neethi_all,
            axiom_node_t *parent,
            const axutil_env_t *env);
 


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* NEETHI_ALL_H */
