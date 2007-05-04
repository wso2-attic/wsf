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

#ifndef AXIS2_PHASE_HOLDER_H
#define AXIS2_PHASE_HOLDER_H

/** 
 * @defgroup axis2_phase_holder phase holder
 * @ingroup axis2_phase_resolver
 * phase holder is used by phase resolver to hold information related to
 * phases and handlers within a phase. This struct hold the list of phases 
 * found in the services.xml and axis2.xml.
 * @{
 */

/**
 * @file axis2_phase_holder.h
 */

#include <axis2_const.h>
#include <axutil_error.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_qname.h>
#include <axutil_array_list.h>
#include <axis2_handler_desc.h>
#include <axis2_phase.h>
#include <axis2_phase_rule.h>
#include <axis2_handler.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_phase_holder */
    typedef struct axis2_phase_holder axis2_phase_holder_t;

    struct axis2_phase;
    struct axis2_handler_desc;
    struct axis2_handler;
    struct axis2_phase_rule;

    /** 
     * Frees phase holder.
     * @param phase_holder pointer to phase holder
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_phase_holder_free(axis2_phase_holder_t *phase_holder,
        const axutil_env_t *env);

    /**
     * Checks if the named phase exist.
     * @param phase_holder pointer to phase holder
     * @param env pointer to environment struct
     * @param phase_name phase name string
     * @return AXIS2_TRUE if the named phase exist, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_phase_holder_is_phase_exist(axis2_phase_holder_t *phase_holder,
        const axutil_env_t *env,
        const axis2_char_t *phase_name);

    /**
     * Adds given handler to phase holder.
     * @param phase_holder pointer to phase holder
     * @param env pointer to environment struct
     * @para handler pointer to handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_holder_add_handler(axis2_phase_holder_t *phase_holder,
        const axutil_env_t *env,
        struct axis2_handler_desc *handler);


    /**
     * Removes given handler from phase holder.
     * @param phase_holder pointer to phase holder
     * @param env pointer to environment struct
     * @para handler pointer to handler
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_holder_remove_handler(axis2_phase_holder_t *phase_holder,
        const axutil_env_t *env,
        struct axis2_handler_desc *handler);

    /**
     * Gets the named phase from phase array list.
     * @param phase_holder pointer to phase holder
     * @param env pointer to environment struct
     * @param phase_name pointer to phase name
     * @return pointer to named phase if it exists, else NULL. Returns a 
     * reference, not a cloned copy 
     */
    AXIS2_EXTERN struct axis2_phase *AXIS2_CALL
    axis2_phase_holder_get_phase(const axis2_phase_holder_t *phase_holder,
        const axutil_env_t *env,
        const axis2_char_t *phase_name);

    /**
     * Builds the transport phase. This method loads the corresponding 
     * handlers and added them into correct phase. 
     * @param phase_holder pointer to phase holder
     * @param env pointer to environment struct
     * @param phase pointer to phase, phase holder does not assume the 
     * ownership the phase
     * @param handlers pointer to array list of handlers, phase holder does 
     * not assume the ownership of the list
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_holder_build_transport_handler_chain(axis2_phase_holder_t *phase_holder,
        const axutil_env_t *env,
        struct axis2_phase *phase,
        axutil_array_list_t *handlers);

    /**
     * Creates phase holder struct.
     * @param env pointer to environment struct
     * @return pointer to newly created phase holder
     */
    AXIS2_EXTERN axis2_phase_holder_t *AXIS2_CALL
    axis2_phase_holder_create (const axutil_env_t *env);

    /**
     * Creates phase holder struct with given list of phases.
     * @param env pointer to environment struct
     * @param phases pointer to array list of phases
     * @return pointer to newly created phase holder
     */
    AXIS2_EXTERN axis2_phase_holder_t *AXIS2_CALL
    axis2_phase_holder_create_with_phases(const axutil_env_t *env,
        axutil_array_list_t *phases);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_PHASE_HOLDER_H */
