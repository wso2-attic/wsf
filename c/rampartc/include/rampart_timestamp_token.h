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

#ifndef RAMPART_TIMESTAMP_TOKEN_H
#define RAMPART_TIMESTAMP_TOKEN_H

/**
  * @file rampart_timestamp.h
  * @brief Timestamp token 
  */
#ifdef __cplusplus
extern "C"
{
#endif

#define RAMPART_TIMESTAMP_TOKEN_DEFAULT_TIME_TO_LIVE 300

#include <axutil_env.h>
#include <rampart_constants.h>

    /**
     * Builds timestamp token.
     * @param env pointer to environment struct
     * @param ctx axis2 context
     * @param sec_node security node
     * @param sec_ns_obj Security namespace object
     * @param ttl Time to live. The time difference btwn Created and Expired
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */

    axis2_status_t AXIS2_CALL
    rampart_timestamp_token_build(
        const axutil_env_t *env,
        axiom_node_t *sec_node,
        const  axiom_namespace_t *sec_ns_obj,
        int ttl);
    /**
     * Validates time stamp token. Validation is based in expiration time of the
     * Expired element.
     * @param env pointer to environment struct
     * @param ts_node Timestamp node
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    rampart_timestamp_token_validate(
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx,
        axiom_node_t *ts_node );


#ifdef __cplusplus
}
#endif


#endif /*RAMPART_TIMESTAMP_TOKEN_H*/
