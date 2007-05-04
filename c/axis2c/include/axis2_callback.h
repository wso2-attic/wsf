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

#ifndef AXIS2_CALLBACK_H
#define AXIS2_CALLBACK_H

/** 
 * @defgroup axis2_callback callback
 * @ingroup axis2_client_api
 * callback represents the callback mechanisms to be used in case of asynchronous
 * invocations. It holds the complete status of the invocation, the resulting 
 * SOAP envelope and also callback specific data. One can define a function
 * to be called on complete of the callback as well as a function to be called 
 * on error. 
 * @{
 */

/**
 * @file axis2_callback.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_async_result.h>
#include <axiom_soap_envelope.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for axis2_callback */
    typedef struct axis2_callback axis2_callback_t;
    /** Type name for function pointer to be called on complete of callback  */
    typedef axis2_status_t AXIS2_CALL
            axis2_on_complete_func_ptr(axis2_callback_t *,
                    const axutil_env_t *);
    /** Type name for function pointer to be called on error of callback  */
    typedef axis2_status_t AXIS2_CALL
            axis2_on_error_func_ptr(axis2_callback_t *,
                    const axutil_env_t *, int);

    /**
     * This function is called once the asynchronous operation is successfully 
     * completed and the result is available.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @param result pointer to async result
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_callback_invoke_on_complete(axis2_callback_t *callback,
        const axutil_env_t *env,
        axis2_async_result_t *result);

    /**
     * This function is called once the asynchronous operation fails and 
     * the failure code returns. 
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @param exception error code representing the error
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_callback_report_error(axis2_callback_t *callback,
        const axutil_env_t *env,
        const int exception);

    /**
     * Gets the complete status for the callback. This method is useful 
     * for polling (busy waiting).
     * e.g.
     * <code>
     *      <pre>
     *          while(!AXIS2_CALLBACK_GET_COMPLETE(callback, env)
     *          {
     *             sleep(10);
     *          }
     *          // do whatever you need here 
     *      </pre>
     * </code>
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if callback is complete, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_callback_get_complete(const axis2_callback_t *callback,
        const axutil_env_t *env);

    /**
     * Sets the complete status.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @param complete bool value representing the status
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_callback_set_complete(axis2_callback_t *callback,
        const axutil_env_t *env,
        const axis2_bool_t complete);

    /**
     * Gets the resulting SOAP envelope.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @return result SOAP envelope if present, else NULL
     */
    AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
    axis2_callback_get_envelope(const axis2_callback_t *callback,
        const axutil_env_t *env);

    /**
     * Sets the SOAP envelope.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @param envelope pointer to SOAP envelope
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_callback_set_envelope(axis2_callback_t *callback,
        const axutil_env_t *env,
        axiom_soap_envelope_t *envelope);

    /**
     * Gets error code representing the error.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @return error code representing the error
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_callback_get_error(const axis2_callback_t *callback,
        const axutil_env_t *env);

    /**
     * Sets the error code.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @param error error code representing the error
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_callback_set_error(axis2_callback_t *callback,
        const axutil_env_t *env,
        const int error);

    /**
     * Sets the callback data.
     * @param callback pointer to callback struct
     * @param data pointer to data
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_callback_set_data(axis2_callback_t *callback,
        void *data);

    /**
     * Gets the callback data.
     * @param callback pointer to callback struct
     * @return pointer to callback data
     */
    AXIS2_EXTERN void *AXIS2_CALL
    axis2_callback_get_data(const axis2_callback_t *callback);

    /**
     * Sets the on complete callback function.
     * @param callback pointer to callback struct
     * @param f on complete callback function pointer
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_callback_set_on_complete(axis2_callback_t *callback,
        axis2_on_complete_func_ptr f);

    /**
     * Sets the on error callback function.
     * @param callback pointer to callback struct
     * @param f on error callback function pointer
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_callback_set_on_error(axis2_callback_t *callback,
        axis2_on_error_func_ptr f);

    /**
     * Frees callback struct.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_callback_free(axis2_callback_t *callback,
        const axutil_env_t *env);

    /**
     * Creates a callback struct.
     * @param env pointer to environment struct
     * @return pointer to newly created callback struct
     */
    AXIS2_EXTERN axis2_callback_t *AXIS2_CALL 
    axis2_callback_create(const axutil_env_t *env);


/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_CALLBACK_H */
