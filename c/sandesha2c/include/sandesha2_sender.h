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

#ifndef SANDESHA2_SENDER_H
#define SANDESHA2_SENDER_H

/**
 * @file sandesha2_sender.h
 * @brief Sandesha Sender Interface
 */

#include <axutil_allocator.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_utils.h>
#include <axis2_conf_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_sender_t sandesha2_sender_t;

AXIS2_EXTERN sandesha2_sender_t * AXIS2_CALL
sandesha2_sender_create(
    const axutil_env_t *env);
 
/**
 * Frees the sender given as a void pointer. This method would cast the 
 * void parameter to an sender pointer and then call free method.
 * @param sender pointer to sender as a void pointer
 * @param env pointer to environment struct
 * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_sender_free_void_arg(
    void *sender,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL 
sandesha2_sender_free(
    sandesha2_sender_t *sender, 
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL 
sandesha2_sender_stop_sender_for_seq(
    sandesha2_sender_t *sender, 
    const axutil_env_t *env, 
    axis2_char_t *seq_id);
            
axis2_status_t AXIS2_CALL 
sandesha2_sender_stop_sending (
    sandesha2_sender_t *sender,
    const axutil_env_t *env);
            
axis2_bool_t AXIS2_CALL 
sandesha2_sender_is_sender_started( 
    sandesha2_sender_t *sender, 
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_sender_run_for_seq 
    (sandesha2_sender_t *sender, 
    const axutil_env_t *env, 
    axis2_conf_ctx_t *conf_ctx, 
    axis2_char_t *seq_id,
    const axis2_bool_t persistent);
            
axis2_status_t AXIS2_CALL 
sandesha2_sender_run (
    sandesha2_sender_t *sender,
    const axutil_env_t *env);
                        
/** @} */
#ifdef __cplusplus
}
#endif
#endif /* SANDESHA2_SENDER_H */
