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

#ifndef OXS_TOKEN_REFERENCE_LIST_H
#define OXS_TOKEN_REFERENCE_LIST_H


/**
  * @file oxs_token_reference_list.h
  * @brief 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axutil_qname.h>
#ifdef __cplusplus
extern "C"
{
#endif

    /**
    * KeyInfo element
    */

    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    oxs_token_build_reference_list_element(const axutil_env_t *env,
                                           axiom_node_t *parent
                                          );

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_token_build_data_reference_list(const axutil_env_t *env, axiom_node_t *parent, axutil_array_list_t *id_list);

    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    oxs_token_get_reference_list_data(const axutil_env_t *env, axiom_node_t *ref_list_node);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_TOKEN_REFERENCE_LIST_H */
