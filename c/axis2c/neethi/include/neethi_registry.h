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

#ifndef NEETHI_REGISTRY_H
#define NEETHI_REGISTRY_H


/**
  * @file neethi_registry.h
  * @struct for operator registry 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <neethi_includes.h>
#include <neethi_policy.h>

#ifdef __cplusplus
extern "C"
{
#endif

        typedef struct neethi_registry_t neethi_registry_t; 

        AXIS2_EXTERN neethi_registry_t *AXIS2_CALL
        neethi_registry_create(const axutil_env_t *env);

        AXIS2_EXTERN neethi_registry_t *AXIS2_CALL
        neethi_registry_create_with_parent(
            const axutil_env_t *env,
            neethi_registry_t *parent);
        
        AXIS2_EXTERN void AXIS2_CALL
        neethi_registry_free(neethi_registry_t *neethi_registry,
                const axutil_env_t *env);
                
        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_registry_register(
            neethi_registry_t *neethi_registry,
            const axutil_env_t *env,
            axis2_char_t *key,
            neethi_policy_t *value);

        AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
        neethi_registry_lookup(
            neethi_registry_t *neethi_registry,
            const axutil_env_t *env,
            axis2_char_t *key);



    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* NEETHI_REGISTRY_H*/
