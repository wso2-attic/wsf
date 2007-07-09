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

#ifndef AXUTIL_UTILS_H
#define AXUTIL_UTILS_H

#include <axutil_utils_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <axutil_date_time.h>
#include <axutil_base64_binary.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup axutil_utils utils
 * @ingroup axis2_util
 * @{
 */

/**
 * @file axutil_utils.h
 */


/** This macro is called to check whether structure on which function is called
 *  is NULL and to check whether the environment structure passed is valid.
 * @param object structure on which function is called
 * @param env environment to be checked for validity
 * @param error_return If function return a status it should pass here 
 *        AXIS2_FAILURE. If function return a type pointer it should
 *        pass NULL
 * @return If function return a status code return AXIS2_SUCCESS. Else if
 *         function return a type pointer return NULL
 */
#define AXIS2_FUNC_PARAM_CHECK(object, env, error_return) \
    AXIS2_ENV_CHECK(env, error_return);\
    if (!object) \
    { \
        AXIS2_ERROR_SET_ERROR_NUMBER(env->error, AXIS2_ERROR_INVALID_NULL_PARAM); \
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_FAILURE); \
        return error_return; \
    } \
    else \
    { \
        AXIS2_ERROR_SET_STATUS_CODE(env->error, AXIS2_SUCCESS); \
    }
 
/**This macro is called to check whether an object is NULL.
 * if object is NULL error number and status code is set
 * @param object object to be check for NULL
 * @param error_return If function return a status it should pass here 
 *        AXIS2_FAILURE. If function return a type pointer it should
 *        pass NULL
 * @return If function return a status code return AXIS2_SUCCESS. Else if
 *         function return a type pointer return NULL
 */
#define AXIS2_PARAM_CHECK(error, object, error_return) \
    if (!object) \
    { \
        AXIS2_ERROR_SET_ERROR_NUMBER(error, AXIS2_ERROR_INVALID_NULL_PARAM); \
        AXIS2_ERROR_SET_STATUS_CODE(error, AXIS2_FAILURE); \
        return error_return; \
    } \
    else \
    { \
        AXIS2_ERROR_SET_STATUS_CODE(error, AXIS2_SUCCESS); \
    } 

/**This macro is used to handle error situation. 
 * @param error_number Error number for the error occured
 * @param error_return If function return a status it should pass here 
 *        AXIS2_FAILURE. If function return a type pointer it should
 *        pass NULL
 * @return If function return a status code return AXIS2_SUCCESS. Else if
 *         function return a type pointer return NULL
 */    
#define AXIS2_ERROR_SET(error, error_number, status_code) \
    { \
        AXIS2_ERROR_SET_ERROR_NUMBER(error, error_number); \
        AXIS2_ERROR_SET_STATUS_CODE(error, status_code); \
    }      


/** Method names in the loadable libraries */

#define AXIS2_CREATE_FUNCTION "axis2_get_instance"
#define AXIS2_DELETE_FUNCTION "axis2_remove_instance"

typedef void (AXIS2_CALL *AXIS2_FREE_VOID_ARG) (void *obj_to_be_freed, 
    const axutil_env_t *env);
    
/* Function pointer typedef for read callback */
typedef int (AXIS2_CALL *AXIS2_READ_INPUT_CALLBACK)(char *buffer, int size, 
    void* ctx);
/* Function pointer typedef for close callback */    
typedef int (AXIS2_CALL *AXIS2_CLOSE_INPUT_CALLBACK)(void *ctx);
    
/** 
    * \brief Axis2 scopes
    *
    * Possible scope value for Axis2
    */
    enum axis2_scopes
    {
        /** Request scope */
        AXIS2_SCOPE_REQUEST = 0,
        /** Session scope */
        AXIS2_SCOPE_SESSION,
        /** Application scope */
        AXIS2_SCOPE_APPLICATION
    };

#define AXIS2_REQUEST_URL_PREFIX "/services"
#define AXIS2_TARGET_EPR "target_epr"
#define AXIS2_DUMP_INPUT_MSG_TRUE "dump"

    /**
     * This function allows users to reolve the service and op from the 
     * url. It returns an array of 2 elements of axis2_char_t arrays (strings).
     * The caller is responsible to free the memory allocated by the function
     * for the return value.
     *
     * @param request url
     * @return axis2_char_t ** <code>axis2_char_t **<code>
     */
    AXIS2_EXTERN axis2_char_t** AXIS2_CALL
    axutil_parse_request_url_for_svc_and_op(const axutil_env_t *env, const axis2_char_t *request);
    
/** @} */
    
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_UTILS_H */

