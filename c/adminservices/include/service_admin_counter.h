/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
 
#ifndef SERVICE_ADMIN_COUNTER_H
#define SERVICE_ADMIN_COUNTER_H

/**
  * @file service_admin_counter.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup service_admin_counter
 * @{
 */
 
/** 
 * @brief counter struct impl
 *	Counter Struct
 */

#define SERVICE_ADMIN_COUNTER_LAST_SERVICE_COUNT "last_svc_count"
#define SERVICE_ADMIN_COUNTER_LAST_OPERATION_COUNT "last_op_count"

typedef struct service_admin_counter_t service_admin_counter_t;
struct axis2_msg_ctx;

AXIS2_EXTERN service_admin_counter_t* AXIS2_CALL
service_admin_counter_create(
    const axutil_env_t *env,
    const axis2_char_t *svc_name,
    const axis2_char_t *op_name);

void AXIS2_CALL 
service_admin_counter_free(
    service_admin_counter_t *counter, 
    const axutil_env_t *env);

void AXIS2_CALL
service_admin_counter_increment (
    service_admin_counter_t *counter,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);

int AXIS2_CALL
service_admin_counter_get_count (
    service_admin_counter_t *counter,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);

int AXIS2_CALL
service_admin_counter_get_last_count (
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx,
    axis2_char_t *svc_name,
    axis2_char_t *op_name);

void AXIS2_CALL
service_admin_counter_set_last_count (
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx,
    axis2_char_t *svc_name,
    axis2_char_t *op_name,
    int last_count);

 
/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SERVICE_ADMIN_COUNTER_H*/
