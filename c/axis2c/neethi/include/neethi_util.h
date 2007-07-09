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

#ifndef NEETHI_UTIL_H
#define NEETHI_UTIL_H


/**
  * @file neethi_util.h
  * @policy creation utilities 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <neethi_includes.h>
#include <neethi_policy.h>
#include <neethi_engine.h>

#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
    neethi_util_create_policy_from_file(
            const axutil_env_t *env,
            axis2_char_t *file_name);
    
    AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
    neethi_util_create_policy_from_om(
        const axutil_env_t *env,
        axiom_node_t *root_node);



    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* NEETHI_UTIL_H */
