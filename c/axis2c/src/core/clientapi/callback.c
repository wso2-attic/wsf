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

#include <axis2_callback.h>
#include <axis2_const.h>
#include <axutil_hash.h>

struct axis2_callback
{
    /** callback complete? */
    axis2_bool_t complete;
    /** envelope corresponding to the result */
    axiom_soap_envelope_t *envelope;
    /** error code */
    int error;
    /** to store callback specific data */
    void *data;
    axutil_thread_mutex_t *mutex;

    /**
     * This function is called by invoke_on_complete.
     * Users could provide this method so that they can define what to be 
     * done when the callback returns on completion.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t (AXIS2_CALL *
    on_complete)(axis2_callback_t *callback,
        const axutil_env_t *env);

    /**
     * This function is called by report_error.
     * Users could provide this method so that they can define what to be done
     * when the callback returns an error.
     * @param callback pointer to callback struct
     * @param env pointer to environment struct
     * @param exception error code representing the error
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    axis2_status_t (AXIS2_CALL *
    on_error)(axis2_callback_t *callback,
        const axutil_env_t *env,
        const int exception);
};

static axis2_status_t AXIS2_CALL
axis2_callback_on_complete(axis2_callback_t *callback,
    const axutil_env_t *env);

static axis2_status_t AXIS2_CALL
axis2_callback_on_error(axis2_callback_t *callback,
    const axutil_env_t *env,
    int exception);

AXIS2_EXTERN axis2_callback_t *AXIS2_CALL
axis2_callback_create(const axutil_env_t *env)
{
    axis2_callback_t *callback = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    callback = AXIS2_MALLOC(env->allocator, sizeof(axis2_callback_t));
    if (!callback)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    callback->complete = AXIS2_FALSE;
    callback->envelope = NULL;
    callback->error = AXIS2_ERROR_NONE;
    callback->data = NULL;
    callback->mutex = NULL;
    callback->on_complete = axis2_callback_on_complete;
    callback->on_error = axis2_callback_on_error;

    callback->mutex = axutil_thread_mutex_create(env->allocator,
                                 AXIS2_THREAD_MUTEX_DEFAULT);
    return callback;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_callback_invoke_on_complete(axis2_callback_t *callback,
    const axutil_env_t *env,
    axis2_async_result_t *result)
{
    axis2_status_t status = AXIS2_FAILURE;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    axis2_callback_set_envelope(callback, env,
        axis2_async_result_get_envelope(result, env));
    status = callback->on_complete(callback, env);

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_callback_report_error(axis2_callback_t *callback,
    const axutil_env_t *env,
    int exception)
{
    axis2_callback_set_error(callback, env, exception);
    return callback->on_error(callback, env, exception);
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_callback_get_complete(const axis2_callback_t *callback,
    const axutil_env_t *env)
{
    return callback->complete;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_callback_set_complete(axis2_callback_t *callback,
    const axutil_env_t *env,
    axis2_bool_t complete)
{
    callback->complete = complete;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_soap_envelope_t *AXIS2_CALL
axis2_callback_get_envelope(const axis2_callback_t *callback,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return callback->envelope;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_callback_set_envelope(axis2_callback_t *callback,
    const axutil_env_t *env,
    axiom_soap_envelope_t *envelope)
{
    callback->envelope = envelope;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_callback_get_error(const axis2_callback_t *callback,
    const axutil_env_t *env)
{
    return callback->error;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_callback_set_error(axis2_callback_t *callback,
    const axutil_env_t *env,
    int error)
{
    callback->error = error;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_callback_free(axis2_callback_t *callback,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if(callback->mutex)
    {
        axutil_thread_mutex_destroy(callback->mutex);
    }

    AXIS2_FREE(env->allocator, callback);

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_callback_set_data(axis2_callback_t *callback,
    void *data)
{
    callback->data = (void*)data;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN void *AXIS2_CALL
axis2_callback_get_data(const axis2_callback_t *callback)
{
    return callback->data;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_callback_set_on_complete(axis2_callback_t *callback,
    axis2_on_complete_func_ptr func)
{
    callback->on_complete = func;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_callback_set_on_error(axis2_callback_t *callback,
    axis2_on_error_func_ptr func)
{
    callback->on_error = func;
}

static axis2_status_t AXIS2_CALL
axis2_callback_on_complete(axis2_callback_t *callback,
    const axutil_env_t *env)
{
    return AXIS2_SUCCESS;
}

static axis2_status_t AXIS2_CALL
axis2_callback_on_error(axis2_callback_t *callback,
    const axutil_env_t *env, int exception)
{
    return AXIS2_SUCCESS;
}


