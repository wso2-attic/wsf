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
 
#ifndef SANDESHA2_MSG_PROCESSOR_H
#define SANDESHA2_MSG_PROCESSOR_H

/**
  * @file sandesha2_msg_processor.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axiom_soap_envelope.h>
#include <axiom_element.h>
#include <sandesha2_msg_ctx.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup sandesha2_msgprocessors
 * @{
 */
 
 typedef struct sandesha2_msg_processor_ops sandesha2_msg_processor_ops_t;
 typedef struct sandesha2_msg_processor sandesha2_msg_processor_t;
 /**
 * @brief Sandesha2 Msg Processor ops struct
 * Encapsulator struct for ops of sandesha2_msg_processor
 */
AXIS2_DECLARE_DATA struct sandesha2_msg_processor_ops
{
    axis2_status_t (AXIS2_CALL *
                process_in_msg)(
                    sandesha2_msg_processor_t *proc,
                    const axutil_env_t *env,
                    sandesha2_msg_ctx_t *rm_msg_ctx);
                    
    axis2_status_t (AXIS2_CALL *
                process_out_msg)(
                    sandesha2_msg_processor_t *proc,
                    const axutil_env_t *env,
                    sandesha2_msg_ctx_t *rm_msg_ctx);

    axis2_status_t (AXIS2_CALL *free) (sandesha2_msg_processor_t *proc,
                    const axutil_env_t *env);
};

/**
 * @brief sandesha2_msg_processor_ops
 *    sandesha2_msg_processor_ops
 */
AXIS2_DECLARE_DATA struct sandesha2_msg_processor
{
    sandesha2_msg_processor_ops_t *ops;
};

/** 
 * @brief Application Message Processor Creator struct impl
 *	Sandesha2 App Msg Processor Creator
 */
sandesha2_msg_processor_t *AXIS2_CALL   
sandesha2_msg_processor_create_msg_processor(
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx);
                        
axis2_status_t AXIS2_CALL 
sandesha2_msg_processor_free (
    sandesha2_msg_processor_t *msg_processor, 
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL 
sandesha2_msg_processor_process_in_msg (
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env,
    sandesha2_msg_ctx_t *rm_msg_ctx);
    
axis2_status_t AXIS2_CALL 
sandesha2_msg_processor_process_out_msg(
    sandesha2_msg_processor_t *msg_processor,
    const axutil_env_t *env, 
    sandesha2_msg_ctx_t *rm_msg_ctx);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SANDESHA2_MSG_PROCESSOR_H*/
