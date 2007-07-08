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
 
#ifndef SANDESHA2_IN_ORDER_INVOKER_H
#define SANDESHA2_IN_ORDER_INVOKER_H

/**
  * @file sandesha2_in_order_invoker.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup sandesha2_in_order_invoker
 * @{
 */
 
typedef struct sandesha2_in_order_invoker_t sandesha2_in_order_invoker_t;

AXIS2_EXTERN sandesha2_in_order_invoker_t* AXIS2_CALL
sandesha2_in_order_invoker_create(
    const axutil_env_t *env);
 
/**
 * Frees the in_order_invoker given as a void pointer. This method would cast the 
 * void parameter to an in_order_invoker pointer and then call free method.
 * @param invoker pointer to in_order_invoker as a void pointer
 * @param env pointer to environment struct
 * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_in_order_invoker_free_void_arg(
    void *invoker,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_stop_invoker_for_seq(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env, axis2_char_t *seq_id);
            
axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_stop_invoking (
    sandesha2_in_order_invoker_t *invoker,
    const axutil_env_t *env);
            
axis2_bool_t AXIS2_CALL 
sandesha2_in_order_invoker_is_invoker_started(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_run_for_seq(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env, axis2_conf_ctx_t *conf_ctx, 
    axis2_char_t *seq_id);
            
axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_run (
    sandesha2_in_order_invoker_t *invoker,
    const axutil_env_t *env);
                        
axis2_status_t AXIS2_CALL
sandesha2_in_order_invoker_make_msg_ready_for_reinjection(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env, axis2_msg_ctx_t *msg_ctx);

void * AXIS2_THREAD_FUNC
sandesha2_in_order_invoker_worker_func(
    axutil_thread_t *thd, void *data);

axis2_status_t AXIS2_CALL 
sandesha2_in_order_invoker_free(
    sandesha2_in_order_invoker_t *invoker, 
    const axutil_env_t *env);								


/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SANDESHA2_IN_ORDER_INVOKER_H*/
