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
 
 #ifndef SAVAN_SUB_PROCESSOR_H
 #define SAVAN_SUB_PROCESSOR_H
 
 /**
 * @defgroup savan_core 
 * @ingroup savan_core
 * subcription processor is responsible for processing incoming eventing message
 * headers and is invoked from the savan_in_handler. This will create 'subcription'
 * objects
 * @{
 */

/**
  * @file savan_sub_processor.h
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>
#include <axutil_array_list.h>

#ifdef __cplusplus
extern "C"
{
#endif
    
    typedef struct savan_sub_processor_t savan_sub_processor_t;

    /**
    * This method creates a subcription object from the incoming message
    * and adds it to the internal list.
    * @param sub_processor pointer to subcription processor
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context representing current state
    * that is used when receiving message
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
    */
    axis2_status_t AXIS2_CALL
    savan_sub_processor_subscribe(
        savan_sub_processor_t *sub_processor,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
    * This method finds the subcription id from the incoming message and
    * removes that suscriber from the internal list.
    * @param sub_processor pointer to subcription processor
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context representing current state
    * that is used when receiving message
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
    */
    axis2_status_t AXIS2_CALL
    savan_sub_processor_unsubscribe(
        savan_sub_processor_t *sub_processor,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
    * This method finds the subcriptin id from the incoming message and
    * renews that subscription.
    * @param sub_processor pointer to subcription processor
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context representing current state
    * that is used when receiving message
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
    */
    axis2_status_t AXIS2_CALL
    savan_sub_processor_renew_subscription(
        savan_sub_processor_t *sub_processor,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
    * This method returns the status of a given subscription.
    * @param sub_processor pointer to subcription processor
    * @param env pointer to environment struct
    * @param msg_ctx pointer to message context representing current state
    * that is used when receiving message
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
    */
    axis2_status_t AXIS2_CALL
    savan_sub_processor_get_status(
        savan_sub_processor_t *sub_processor,
        const axutil_env_t *env,
        axis2_msg_ctx_t *msg_ctx);

    /**
    * Creates a subcription processor instance.
    * @param env pointer to environment struct
    * @return pointer to newly created subcription processor struct
    */
    AXIS2_EXTERN savan_sub_processor_t * AXIS2_CALL
    savan_sub_processor_create(
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif
  
#endif /* SAVAN_SUB_PROCESSOR_H */
