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

#ifndef NEETHI_REFERENCE_H
#define NEETHI_REFERENCE_H


/**
  * @file neethi_reference.h
  * @struct for operator reference 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <neethi_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

        typedef struct neethi_reference_t neethi_reference_t; 

        AXIS2_EXTERN neethi_reference_t *AXIS2_CALL
        neethi_reference_create(const axutil_env_t *env);

        AXIS2_EXTERN void AXIS2_CALL
        neethi_reference_free(neethi_reference_t *neethi_reference,
                const axutil_env_t *env);

        AXIS2_EXTERN axis2_char_t *AXIS2_CALL
        neethi_reference_get_uri(
            neethi_reference_t *neethi_reference,
            const axutil_env_t *env);

        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_reference_set_uri(
            neethi_reference_t *neethi_reference,
            const axutil_env_t *env,
            axis2_char_t *uri);

        AXIS2_EXTERN axis2_status_t AXIS2_CALL
        neethi_reference_serialize(
            neethi_reference_t *neethi_reference,
            axiom_node_t *parent,
            const axutil_env_t *env);



    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* NEETHI_REFERENCE_H */
