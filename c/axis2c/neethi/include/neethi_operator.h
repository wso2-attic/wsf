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

#ifndef NEETHI_OPERATOR_H
#define NEETHI_OPERATOR_H


/**
  * @file neethi_operator.h
  * @common struct for policy operators. 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <neethi_includes.h>


#ifdef __cplusplus
extern "C"
{
#endif


    typedef enum  {
        OPERATOR_TYPE_POLICY = 0,
        OPERATOR_TYPE_ALL,
        OPERATOR_TYPE_EXACTLYONE,
        OPERATOR_TYPE_REFERENCE,
        OPERATOR_TYPE_ASSERTION,
        OPERATOR_TYPE_UNKNOWN
    }neethi_operator_type_t;

    typedef struct neethi_operator_t neethi_operator_t;


    AXIS2_EXTERN neethi_operator_t *AXIS2_CALL
    neethi_operator_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    neethi_operator_free(neethi_operator_t *neethi_operator,
            const axutil_env_t *env);

    AXIS2_EXTERN neethi_operator_type_t AXIS2_CALL
    neethi_operator_get_type(neethi_operator_t *neethi_operator,
            const axutil_env_t *env);

    AXIS2_EXTERN void *AXIS2_CALL
    neethi_operator_get_value(
            neethi_operator_t *neethi_operator,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_operator_set_value(neethi_operator_t *neethi_operator,
            const axutil_env_t *env,
            void *value,
            neethi_operator_type_t type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_operator_serialize(
            neethi_operator_t *neethi_operator,
            const axutil_env_t *env,
            axiom_node_t *parent);
   
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_operator_set_value_null(
            neethi_operator_t *neethi_operator,
            const axutil_env_t *env);
    
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_operator_increment_ref(
        neethi_operator_t *neethi_operator,
        const axutil_env_t *env);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* NEETHI_OPERATOR_H */
