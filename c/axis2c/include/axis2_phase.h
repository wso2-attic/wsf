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

#ifndef AXIS2_PHASE_H
#define AXIS2_PHASE_H

/**
 * @defgroup axis2_phase phases
 * @ingroup axis2_engine
 * phase is a logical unit of execution in the Axis2 engine's execution flows.
 * A phase encapsulates one or more handlers in a given sequence to be invoked. 
 * The sequencing of handlers within a phase are often defined by module 
 * configuration which specifies where in the phase's handler chain a given 
 * handler should be placed.
 * Calling invoke on phase triggers invoke on the handlers stored within the 
 * phase in the sequence they are ordered. 
 * @{
 */

/**
 * @file axis2_phase.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_handler.h>
#include <axis2_handler_desc.h>
#include <axutil_array_list.h>
#include <axutil_qname.h>

/** 
 * A given handler's location within the list of handlers is before a particular
 * handler and after another particular handler. 
 */
#define AXIS2_PHASE_BOTH_BEFORE_AFTER  0

/** 
 * A given handler's location within the list of handlers is before another 
 * given handler.
 */
#define AXIS2_PHASE_BEFORE  1

/** 
 * A given handler's location within the list of handlers is after another 
 * given handler.
 */
#define AXIS2_PHASE_AFTER  2

/** 
 * A given handler's location within the list of handlers could be anywhere in
 * the list.
 */
#define AXIS2_PHASE_ANYWHERE  3

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for axis2_phase */
    typedef struct axis2_phase axis2_phase_t;
        
    struct axis2_msg_ctx;

    /**
     * Adds given handler to the specified position in the handler array list.
     * @param phase pointer to phase struct
     * @param env pointer to environment struct
     * @param index index
     * @param handler pointer to handler, phase does not assume the 
     * ownership of the handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_add_handler_at(axis2_phase_t *phase,
        const axutil_env_t *env,
        const int index,
        axis2_handler_t *handler);
    
    /**
     * Adds the given handler to the end of the handler list.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler pointer to handler, phase does not assume the 
     * ownership of the handler 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_add_handler(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_t *handler);


    /**
     * Remove the given handler from  the handler list.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler pointer to handler, phase does not assume the 
     * ownership of the handler 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_remove_handler(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_t *handler);
                
     /**
      * Invokes the phase. This function will in turn call invoke method of
      * each handler in the handler list, in sequence, starting from the 
      * beginning of the list to the end of the list.
      * @param phase pointer to phase
      * @param env pointer to environment struct
      * @param msg_ctx pointer to message context
      * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
      */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_invoke(axis2_phase_t *phase,
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);

    /**
     * Gets phase name.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @return returns name of phase
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_phase_get_name(const axis2_phase_t *phase,
        const axutil_env_t *env);

    /**
     * Gets handler count in the handler list.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @return the number of handlers in the handler list
     */
    AXIS2_EXTERN int AXIS2_CALL
    axis2_phase_get_handler_count(const axis2_phase_t *phase,
        const axutil_env_t *env);

    /**
     * Sets the first handler in the handler list.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler pointer to handler, phase does not assume the 
     * ownership of the handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_set_first_handler(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_t *handler);
                
    /**
     * Sets the last handler in the handler list.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler pointer to handler, phase does not assume the 
     * ownership of the handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_set_last_handler(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_t *handler);
                
    /**
     * Adds handler within the handler description to the list of handlers 
     * in the phase.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler_desc pointer to handler description, phase does not 
     * assume the ownership of neither the handler description not the handler
     * within the handler description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_add_handler_desc(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_desc_t *handler_desc);


    /**
     * Remove handler within the handler description from the list of handlers 
     * in the phase.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler_desc pointer to handler description, phase does not 
     * assume the ownership of neither the handler description not the handler
     * within the handler description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_remove_handler_desc(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_desc_t *handler_desc);
                
    /**
     * Inserts the handler into handler list of the phase based on the phase
     * rules associated with the handler. This function takes into account 
     * the before rules of the handler. Before rules specify the location
     * of a current handler in the handler list, before which the given 
     * handler is to be placed.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler pointer to handler, phase does not assume the 
     * ownership of the handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_insert_before(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_t *handler);

    /**
     * Inserts the handler into handler list of the phase based on the phase
     * rules associated with the handler. This function takes into account 
     * the after rules of the handler. After rules specify the location
     * of a current handler in the handler list, after which the given 
     * handler is to be placed.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler pointer to handler, phase does not assume the 
     * ownership of the handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_insert_after(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_t *handler);

    /**
     * Inserts the handler into handler list of the phase based on both 
     * before and after phase rules associated with the handler. 
     * This method assume that both the before and after cannot be the same 
     * handler . That condition is not checked by this function. 
     * It should be checked before calling this function
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler pointer to handler, phase does not assume the 
     * ownership of the handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_insert_before_and_after(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_t *handler);

    /**
     * Inserts the handler to the correct location in the handler list of 
     * the phase. Location is evaluated based on the phase rules.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param handler_desc pointer to handler description, phase does not 
     * assume the ownership of neither the handler description not the handler
     * within the handler description
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_insert_handler_desc(axis2_phase_t *phase,
        const axutil_env_t *env,
        axis2_handler_desc_t *handler_desc);

    /**
     * Gets all the handlers in the phase.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @return pointer to array list containing the list of handlers
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_phase_get_all_handlers(const axis2_phase_t *phase,
        const axutil_env_t *env);

    /**
     * Invokes handlers starting from the given handler index.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @param paused_handler_index index of the handler to start the 
     * invocation from
     * @param msg_ctx pointer to message context
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_invoke_start_from_handler(axis2_phase_t *phase,
        const axutil_env_t *env,
        const int paused_handler_index,
        struct axis2_msg_ctx *msg_ctx);

    /**
     * Frees phase struct.
     * @param phase pointer to phase
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_phase_free(axis2_phase_t *phase,
        const axutil_env_t *env);

    /**
     * creates phase struct instance.
     * @param env pointer to environment struct
     * @param phase_name name of the phase to be created
     * @return pointer to newly created phase
     */
    AXIS2_EXTERN axis2_phase_t *AXIS2_CALL
    axis2_phase_create(const axutil_env_t *env,
            const axis2_char_t *phase_name);

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_PHASE_H */
