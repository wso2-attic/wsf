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

#ifndef AXIOM_PI_H
#define AXIOM_PI_H

#include <axiom_node.h>
#include <axiom_output.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_processing_instruction pocessing instruction
     * @ingroup axiom_om
     * @{
     */


    typedef struct axiom_processing_instruction axiom_processing_instruction_t;

    /**
      * Creates a processing instruction 
      * @param environment Environment. MUST NOT be NULL.
      * @param parent parent of the element node to be created. Optional, can be NULL.
      * @param target target of the processing instruction.cannot be NULL.
      * @param value value of the processing instruction.cannot be NULL.
      * @param node This is an out parameter. cannot be NULL.
      *     Returns the node corresponding to the comment created.
      *     Node type will be set to AXIOM_PROCESSING_INSTRUCTION
      * @return a pointer tonewly created processing instruction struct 
      */
    AXIS2_EXTERN axiom_processing_instruction_t * AXIS2_CALL
    axiom_processing_instruction_create(const axutil_env_t *env,
        axiom_node_t * parent,
        const axis2_char_t * target,
        const axis2_char_t * value,
        axiom_node_t ** node);

    /**
     * Frees an instance of axiom_processing_instruction
     * @param om_pi processing instruction to be freed.
     * @param env Environment. MUST NOT be NULL, .
     * @return satus of the op. AXIS2_SUCCESS on success else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_processing_instruction_free(struct axiom_processing_instruction * om_pi,
        const axutil_env_t *env);
    
    /**
     * Set processing instruction data
     * @param om_pi
     * @param env    
     * @param value 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_processing_instruction_set_value(struct axiom_processing_instruction *om_pi,
        const axutil_env_t *env,
        const axis2_char_t* value);

    /**
     * Set processing instruction target
     * @param om_pi processing_instruction struct
     * @param env environment, MUST NOT be NULL.
     * @param target 
     * @return status of the op AXIS2_SUCCESS on success,
     *     AXIS2_FAILURE on error.
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_processing_instruction_set_target(struct axiom_processing_instruction *om_pi,
        const axutil_env_t *env,
        const axis2_char_t* target);

    /**
     * Get PI target
     * @param om_pi processing_instruction struct
     * @param env environment 
     * @return target text , NULL on error or if target is null
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_processing_instruction_get_target(struct axiom_processing_instruction *om_pi,
        const axutil_env_t *env);

    /**
     * Get data part of processing_instruction
     * @param om_pi processing instruction 
     * @param env environment , MUST NOT be NULL.
     * @return data text , NULL if there is no data,
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_processing_instruction_get_value(struct axiom_processing_instruction *om_pi,
            const axutil_env_t *env);

    /**
     * Serialize function
     * @param om_pi processing_instruction struct
     * @param env environment, MUST NOT be NULL.
     * @param om_output om_output handler struct
     * @return status of the op, AXIS2_SUCCESS on success,
     *     AXIS2_FAILURE on error 
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_processing_instruction_serialize(struct axiom_processing_instruction *om_pi,
        const axutil_env_t *env,
        axiom_output_t *om_output);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIOM_PI_H */
