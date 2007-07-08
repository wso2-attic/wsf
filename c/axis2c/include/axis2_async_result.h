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

#ifndef AXIS2_ASYNC_RESULT_H
#define AXIS2_ASYNC_RESULT_H

/** 
 * @defgroup axis2_async_result async result
 * @ingroup axis2_client_api
 * async_result is used to capture the result of an asynchronous invocation.
 * async_result stores the result in the form of a message context instance,
 * the user can extract the resulting SOAP envelope from this message context.
 * @{
 */

/**
 * @file axis2_async_result.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_msg_ctx.h>
#include <axiom_soap_envelope.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_async_result */
    typedef struct axis2_async_result axis2_async_result_t;

    /**
     * Gets the SOAP envelope stored inside the resulting message context.        
     * @param async_result pointer to async result struct
     * @param env pointer to environment struct
     * @return pointer to the result SOAP envelope in the message context.
     */
    AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
    axis2_async_result_get_envelope(axis2_async_result_t *async_result,
        const axutil_env_t *env);


    /**
     * Gets the result in the form of message context.
     * @param async_result pointer to async result struct
     * @param env pointer to environment struct
     * @return pointer to result message context
     */
    AXIS2_EXTERN axis2_msg_ctx_t *AXIS2_CALL
    axis2_async_result_get_result(axis2_async_result_t *async_result,
        const axutil_env_t *env);

    /**
     * Frees the async result.
     * @param async_result pointer to async result struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_async_result_free(axis2_async_result_t *async_result,
        const axutil_env_t *env);

    /** Creates an async result struct to help deal with results of asynchronous
     * invocations.
     * @param env pointer to environment struct
     * @param result pointer to result message context into which the resulting
     * SOAP message is to be captured
     * @return newly created async_result struct
     */
    AXIS2_EXTERN axis2_async_result_t *AXIS2_CALL
    axis2_async_result_create(const axutil_env_t *env,
        axis2_msg_ctx_t *result);


/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_ASYNC_RESULT_H */
