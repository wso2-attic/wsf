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

#ifndef AXIS2_PHASE_RULE_H
#define AXIS2_PHASE_RULE_H

/**
 * @defgroup axis2_phase_rule phase rule
 * @ingroup axis2_desc
 * phase rule encapsulates data and operations related to phase rules for a 
 * given handler. phase rule lives within a handler. 
 * phase rules of a handler specify the relative location of the 
 * handler within the phase to which it belongs, with respect to other handlers 
 * in the phase or first and last positions of the handler chain of the phase.
 * @{
 */

/**
 * @file axis2_phase_rule.h
 */

#include <axis2_defines.h>
#include <axutil_qname.h>
#include <axutil_param.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_phase_rule */
    typedef struct axis2_phase_rule axis2_phase_rule_t;

    /**
     * Gets the name of the handler before which the handler associated with 
     * this rule should be placed.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @return name of handler before which the handler should be placed
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_phase_rule_get_before(const axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env);

    /**
     * Sets the name of the handler before which the handler associated with 
     * this rule should be placed.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @param before name of handler before which the handler should be placed
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_rule_set_before(axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env,
        const axis2_char_t *before);

    /**
     * Gets the name of the handler after which the handler associated with 
     * this rule should be placed.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @return name of handler after which the handler should be placed
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_phase_rule_get_after(const axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env);

    /**
     * Sets the name of the handler after which the handler associated with 
     * this rule should be placed.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @param after name of handler after which the handler should be placed
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_rule_set_after(axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env,
        const axis2_char_t *after);

    /**
     * Gets name.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @return name string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_phase_rule_get_name(const axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env);

    /**
     * Sets name.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @param name name string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_rule_set_name(axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env,
        const axis2_char_t *name);

    /**
     * Checks if the handler is the first in phase. 
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if the handler associated with this rule is the 
     * first in phase, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_phase_rule_is_first(const axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env);

    /**
     * Sets handler to be the first in phase.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @param first AXIS2_TRUE if the handler associated with this rule is the 
     * first in phase, else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_rule_set_first(axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env,
        axis2_bool_t first);

    /**
     * Checks if the handler is the last in phase. 
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @return AXIS2_TRUE if the handler associated with this rule is the 
     * last in phase, else AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axis2_phase_rule_is_last(const axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env);

    /**
     * Sets handler to be the last in phase.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @param last AXIS2_TRUE if the handler associated with this rule is the 
     * last in phase, else AXIS2_FALSE
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_phase_rule_set_last(axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env,
        axis2_bool_t last);

    /**
     * Frees phase rule.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_phase_rule_free(axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env);

    /**
     * Clones phase rule.
     * @param phase_rule pointer to phase rule
     * @param env pointer to environment struct
     * @return pointer to newly cloned phase rule
     */
    AXIS2_EXTERN axis2_phase_rule_t *AXIS2_CALL
    axis2_phase_rule_clone(axis2_phase_rule_t *phase_rule,
        const axutil_env_t *env);

    /**
     * Creates a phase rule struct instance.
     * @param env pointer to environment struct
     * @param phase_name name of the phase rule 
     * @return pointer to newly created phase rule
     */
    AXIS2_EXTERN axis2_phase_rule_t *AXIS2_CALL
    axis2_phase_rule_create(const axutil_env_t *env,
        const axis2_char_t *name);

/** @} */

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_PHASE_RULE_H */
