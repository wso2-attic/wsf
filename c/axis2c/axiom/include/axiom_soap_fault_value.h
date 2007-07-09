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

#ifndef AXIOM_SOAP_FAULT_VALUE_H
#define AXIOM_SOAP_FAULT_VALUE_H

/**
* @file axiom_soap_fault_value.h
* @brief axiom_soap_fault_value 
*/
#include <axutil_env.h>
#include <axiom_soap_fault.h>
#include <axiom_soap_fault_sub_code.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_soap_fault_value axiom_soap_fault_value_t;
    /**
     * @defgroup axiom_soap_fault_value soap fault value
     * @ingroup axiom_soap
     * @{
     */

    /**
      * creates a soap struct 
      * @param env Environment. MUST NOT be NULL
      */
    AXIS2_EXTERN axiom_soap_fault_value_t * AXIS2_CALL
    axiom_soap_fault_value_create_with_subcode(const axutil_env_t *env,
            axiom_soap_fault_sub_code_t *parent);

    AXIS2_EXTERN axiom_soap_fault_value_t * AXIS2_CALL
    axiom_soap_fault_value_create_with_code(const axutil_env_t *env,
            axiom_soap_fault_code_t *parent);

    /**
      * Free an axiom_soap_fault_value
      * @param  fault_value pointer to soap_fault_value struct
      * @param  env Environment. MUST NOT be NULL
      * @return satus of the op. AXIS2_SUCCESS on success 
      *         else AXIS2_FAILURE
      */

    AXIS2_EXTERN void AXIS2_CALL
    axiom_soap_fault_value_free(axiom_soap_fault_value_t *fault_value,
            const axutil_env_t *env);

    /**
      * Get the text value of the env:Value element directly under env:Code element
      * @param fault_value pointer to axiom_soap_fault_t
      * @param env Environment. MUST NOT BE NULL
      * @return text value 
      */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_soap_fault_value_get_text(axiom_soap_fault_value_t *fault_value,
            const axutil_env_t *env);

    /**
      * Set the text value of the env:Value element directly under env:Code element
      * @param fault_value pointer to axiom_soap_fault_t
      * @param env Environment. MUST NOT BE NULL
      * @param text value to be set
      */
    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_soap_fault_value_get_base_node(axiom_soap_fault_value_t *fault_value,
            const axutil_env_t *env);
    /**
     * set the text value of soap_fault_value element 
     * @param fault_value pointer to soap fault value struct
     * @param env environment MUST not be NULL
     * @param text Text value to be set
     */

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_fault_value_set_text(axiom_soap_fault_value_t *fault_value,
            const axutil_env_t *env, axis2_char_t *text);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIOM_SOAP_FAULT_VALUE_H */
