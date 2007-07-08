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

#ifndef AXIOM_SOAP_FAULT_TEXT_H
#define AXIOM_SOAP_FAULT_TEXT_H

/**
 * @file axiom_soap_fault_text.h
 * @brief axiom_soap_fault_text 
 */
#include <axutil_env.h>
#include <axiom_soap_fault_reason.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct axiom_soap_fault_text axiom_soap_fault_text_t;
    /**
     * @defgroup axiom_soap_fault_text soap fault text
     * @ingroup axiom_soap
     * @{
     */

    /**
      * creates a soap struct 
      * @param env Environment. MUST NOT be NULL
      */
    AXIS2_EXTERN axiom_soap_fault_text_t * AXIS2_CALL
    axiom_soap_fault_text_create_with_parent(const axutil_env_t *env,
            axiom_soap_fault_reason_t *fault);

    /**
      * Free an axiom_soap_fault_text
      * @param  fault_text pointer to soap_fault_text struct
      * @param  env Environment. MUST NOT be NULL
      * @return satus of the op. AXIS2_SUCCESS on success 
      *         else AXIS2_FAILURE
      */

    AXIS2_EXTERN void AXIS2_CALL
    axiom_soap_fault_text_free(axiom_soap_fault_text_t *fault_text,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_fault_text_set_lang(axiom_soap_fault_text_t *fault_text,
            const axutil_env_t *env,
            const axis2_char_t* lang);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axiom_soap_fault_text_get_lang(axiom_soap_fault_text_t *fault_text,
            const axutil_env_t *env);

    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_soap_fault_text_get_base_node(axiom_soap_fault_text_t *fault_text,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_fault_text_set_text(axiom_soap_fault_text_t *fault_text,
            const axutil_env_t *env,
            axis2_char_t *value,
            axis2_char_t *lang);

    AXIS2_EXTERN axis2_char_t * AXIS2_CALL
    axiom_soap_fault_text_get_text(axiom_soap_fault_text_t *fault_text,
            const axutil_env_t *env);

    /** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIOM_SOAP_FAULT_TEXT_H */
