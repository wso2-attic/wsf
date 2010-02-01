/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef AXIS2_COUNTER_H
#define AXIS2_COUNTER_H

/**
  * @file axis2_counter.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup axis2_counter
 * @{
 */
 
/** 
 * @brief counter struct impl
 *	Counter Struct
 */
typedef struct axis2_counter_t axis2_counter_t;
struct axis2_msg_ctx;

AXIS2_EXTERN axis2_counter_t* AXIS2_CALL
axis2_counter_create(
    const axutil_env_t *env,
    const axis2_char_t *svc_name,
    const axis2_char_t *op_name);

void AXIS2_CALL 
axis2_counter_free(
    axis2_counter_t *counter, 
    const axutil_env_t *env);

void AXIS2_CALL
axis2_counter_increment (
    axis2_counter_t *counter,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);

int AXIS2_CALL
axis2_counter_get_count (
    axis2_counter_t *counter,
    const axutil_env_t *env,
    struct axis2_msg_ctx *msg_ctx);
 
/** @} */
#ifdef __cplusplus
}
#endif

#endif /*AXIS2_COUNTER_H*/
