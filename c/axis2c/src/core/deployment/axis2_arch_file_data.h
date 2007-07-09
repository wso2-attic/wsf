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

#ifndef AXIS2_ARCH_FILE_DATA_H
#define AXIS2_ARCH_FILE_DATA_H

/** @defgroup axis2_arch_file_data Arch File Data
 * @ingroup axis2_deployment
 * @{
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_qname.h>
#include <axis2_conf.h>
#include <axutil_array_list.h>
#include <axutil_dir_handler.h>
#include <axutil_file.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct axis2_conf;

    /** Type name for struct axis2_arch_fila_data */
    typedef struct axis2_arch_file_data axis2_arch_file_data_t;

    /** 
     * De-allocate memory
     * @param arch_file_data pointer to arch_file_data
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_arch_file_data_free(axis2_arch_file_data_t *arch_file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_arch_file_data_get_msg_recv(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     * @param msg_recv pointer to message receiver
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_arch_file_data_set_msg_recv(axis2_arch_file_data_t *file_data,
        const axutil_env_t *env,
        axis2_char_t *msg_recv);

    /**
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     * @return the name of the contained file.
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_arch_file_data_get_name(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /**
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     * @return the service name. if contained file is not null this is the
     * file name. else this is the name property
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_arch_file_data_get_svc_name(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_arch_file_data_get_type(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axutil_file_t *AXIS2_CALL
    axis2_arch_file_data_get_file(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_arch_file_data_get_module_name(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     * @param module_name pointer to module_name
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_arch_file_data_set_module_name(axis2_arch_file_data_t *file_data,
        const axutil_env_t *env,
        axis2_char_t *module_name);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axis2_arch_file_data_get_module_dll_name(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_arch_file_data_set_module_dll_name(axis2_arch_file_data_t *file_data,
        const axutil_env_t *env,
        axis2_char_t *module_dll_name);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_arch_file_data_add_svc(axis2_arch_file_data_t *file_data,
        const axutil_env_t *env,
        struct axis2_svc *svc_desc);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN struct axis2_svc *AXIS2_CALL
    axis2_arch_file_data_get_svc(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env,
        axis2_char_t *svc_name);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    axis2_arch_file_data_get_svc_map(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_arch_file_data_get_deployable_svcs(const axis2_arch_file_data_t *file_data,
        const axutil_env_t *env);

    /** 
     * @param file_data pointer to arch_file_data
     * @param env pointer to environment struct
     * @param deployable_svcs pointer to deployable services
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_arch_file_data_set_deployable_svcs(axis2_arch_file_data_t *file_data,
        const axutil_env_t *env,
        axutil_array_list_t *deployable_svcs);

    /**
     * Creates arch file data struct
     * @param env pointer to environment struct
     * @return pointer to newly created arch file data
     */
    AXIS2_EXTERN axis2_arch_file_data_t *AXIS2_CALL
    axis2_arch_file_data_create(const axutil_env_t *env);

    /**
     * Creates arch file data struct
     * @param env pointer to environment struct
     * @param type type
     * @param file folder name of service or module
     * @return pointer to newly created arch file data
     */
    AXIS2_EXTERN axis2_arch_file_data_t *AXIS2_CALL
    axis2_arch_file_data_create_with_type_and_file(const axutil_env_t *env,
        int type,
        axutil_file_t *file);

    /**
     * Creates arch file data struct
     * @param env pointer to environment struct
     * @param type type
     * @param name pointer to name
     * @return pointer to newly created arch file data
     */
    AXIS2_EXTERN axis2_arch_file_data_t *AXIS2_CALL
    axis2_arch_file_data_create_with_type_and_name(const axutil_env_t *env,
        int type,
        const axis2_char_t *name);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_ARCH_FILE_DATA_H */
