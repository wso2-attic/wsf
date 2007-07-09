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

#ifndef AXUTIL_DLL_DESC_H
#define AXUTIL_DLL_DESC_H

/**
 * @file axutil_dll_desc.h
 * @brief Axis2 dll_desc interface
 */

#include <axutil_utils_defines.h>
#include <axutil_qname.h>
#include <axutil_error.h>
#include <axutil_utils.h>
#include <platforms/axutil_platform_auto_sense.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_dll_desc DLL description
     * @ingroup axis2_util
     * @{
     */

    typedef struct axutil_dll_desc axutil_dll_desc_t;

    typedef int(*CREATE_FUNCT)(void **inst, const axutil_env_t *env);

    typedef int(*DELETE_FUNCT)(void *inst, const axutil_env_t *env);

    typedef enum axis2_dll_type
    {
        /** service dll */
        AXIS2_SVC_DLL = 0,
        /** handler dll */
        AXIS2_HANDLER_DLL,
        /** message receiver dll */
        AXIS2_MSG_RECV_DLL,
        /** module dll */
        AXIS2_MODULE_DLL,
        /** transport receiver dll */
        AXIS2_TRANSPORT_RECV_DLL,
        /** transport sender dll */
        AXIS2_TRANSPORT_SENDER_DLL

    }
    axis2_dll_type_t;

    /**
     * creates dll_desc struct
     * @param qname qname, can be NULL
     */
    AXIS2_EXTERN axutil_dll_desc_t* AXIS2_CALL
    axutil_dll_desc_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_dll_desc_free_void_arg(void *dll_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_dll_desc_free(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);

    /**
     * Set path qualified platform specific dll name
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_dll_desc_set_name(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        axis2_char_t *name);

    /**
     * Return the path qualified platform specific dll name
     */
    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axutil_dll_desc_get_name(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_dll_desc_set_type(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        axis2_dll_type_t type);

    AXIS2_EXTERN axis2_dll_type_t AXIS2_CALL
    axutil_dll_desc_get_type(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_dll_desc_set_load_options(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        int options);

    AXIS2_EXTERN int AXIS2_CALL
    axutil_dll_desc_get_load_options(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_dll_desc_set_dl_handler(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        AXIS2_DLHANDLER dl_handler);

    AXIS2_EXTERN AXIS2_DLHANDLER AXIS2_CALL
    axutil_dll_desc_get_dl_handler(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_dll_desc_set_create_funct(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        CREATE_FUNCT funct);

    AXIS2_EXTERN CREATE_FUNCT AXIS2_CALL
    axutil_dll_desc_get_create_funct(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_dll_desc_set_delete_funct(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        DELETE_FUNCT funct);

    AXIS2_EXTERN DELETE_FUNCT AXIS2_CALL
    axutil_dll_desc_get_delete_funct(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_dll_desc_set_timestamp(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        AXIS2_TIME_T timestamp);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_dll_desc_set_error_code(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        axutil_error_codes_t error_code);

    AXIS2_EXTERN axutil_error_codes_t AXIS2_CALL
    axutil_dll_desc_get_error_code(
        axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);

    AXIS2_EXTERN AXIS2_TIME_T AXIS2_CALL
    axutil_dll_desc_get_timestamp(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env);
    /**
    * This function will accept the library name without any platform
    * dependant prefixes or suffixes. It then prefix and suffix
    * platform dependant prefix and suffix macros to the original name
    * and return the platform specific dll name
    *
    * @param class_name
    * @return platform specific dll name
    */
    AXIS2_EXTERN axis2_char_t * AXIS2_CALL 
    axutil_dll_desc_create_platform_specific_dll_name(axutil_dll_desc_t *dll_desc,
        const axutil_env_t *env,
        const axis2_char_t *class_name);

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_DLL_DESC_H */
