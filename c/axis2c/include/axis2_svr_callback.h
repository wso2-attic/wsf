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

#ifndef AXIS2_SVR_CALLBACK_H
#define AXIS2_SVR_CALLBACK_H

/** @defgroup axis2_svr_callback server callback
 * @ingroup axis2_svc_api
 * @{
 */

/**
 * @file axis2_svr_callback.h
 * @brief axis Server Callback interface
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include <axis2_defines.h>
#include <axis2_const.h>
#include <axis2_msg_ctx.h>

    /** Type name for struct axis2_svr_callback */
    typedef struct axis2_svr_callback axis2_svr_callback_t;

    /**
     * Deallocate memory
     * @param svr_callback pointer to server callback struct
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svr_callback_free(axis2_svr_callback_t *svr_callback,
        const axutil_env_t *env);

    /**
     * Handle result
     * @param svr_callback pointer to server callback struct
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svr_callback_handle_result(axis2_svr_callback_t *svr_callback,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
     * Handle fault
     * @param svr_callback pointer to server callback struct
     * @param env pointer to environment struct
     * @param msg_ctx pointer to message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svr_callback_handle_fault(axis2_svr_callback_t *svr_callback,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
     * Create Server Callback struct
     * @param env pointer to environment struct
     * @return newly created server callback object
     */
    AXIS2_EXTERN axis2_svr_callback_t *AXIS2_CALL
    axis2_svr_callback_create(const axutil_env_t *env);


/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_SVR_CALLBACK_H */
