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

#ifndef AXIOM_SOAP_FAULT_CODE_H
#define AXIOM_SOAP_FAULT_CODE_H


/**
 * @file axiom_soap_fault_code.h
 * @brief axiom_soap_fault_code struct
 */
#include <axutil_env.h>
#include <axiom_soap_fault.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_soap_fault_code axiom_soap_fault_code_t;

    struct axiom_soap_fault_value;
    struct axiom_soap_fault_sub_code;
    struct axiom_soap_builder;
    /**
     * @defgroup axiom_soap_fault_code soap fault code
     * @ingroup axiom_soap
     * @{
     */


    /**
      * creates a soap struct 
      * @param env Environment. MUST NOT be NULL
      */
    AXIS2_EXTERN axiom_soap_fault_code_t * AXIS2_CALL
    axiom_soap_fault_code_create_with_parent(const axutil_env_t *env,
            axiom_soap_fault_t *fault);

    AXIS2_EXTERN axiom_soap_fault_code_t * AXIS2_CALL
    axiom_soap_fault_code_create_with_parent_value(const axutil_env_t *env,
            axiom_soap_fault_t *fault,
            axis2_char_t *value);

    /**
      * Free an axiom_soap_fault_code
      * @param  fault_code pointer to soap_fault_code struct
      * @param  env Environment. MUST NOT be NULL
      * @return satus of the op. AXIS2_SUCCESS on success 
      *         else AXIS2_FAILURE
      */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_soap_fault_code_free(axiom_soap_fault_code_t *fault_code,
            const axutil_env_t *env);
    /**
    * @returns axiom_soap_fault_sub_code struct if one is associated with
    * this fault_code struct , otherwise teturns NULL
    */

    AXIS2_EXTERN struct axiom_soap_fault_sub_code* AXIS2_CALL
    axiom_soap_fault_code_get_sub_code(axiom_soap_fault_code_t *fault_code,
            const axutil_env_t *env);

    /**
      * @returns soap_fault_value if available
    */
    AXIS2_EXTERN struct axiom_soap_fault_value* AXIS2_CALL
    axiom_soap_fault_code_get_value(axiom_soap_fault_code_t *fault_code,
            const axutil_env_t *env);

    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_soap_fault_code_get_base_node(axiom_soap_fault_code_t *fault_code,
            const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif
#endif /* AXIOM_SOAP_FAULT_CODE_H */
