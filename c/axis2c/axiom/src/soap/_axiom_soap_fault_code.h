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
 
 #ifndef _AXIOM_SOAP_FAULT_CODE_H
 #define _AXIOM_SOAP_FAULT_CODE_H
 
 
 /** @defgroup axiom_soap AXIOM (Axis Object Model)
  * @ingroup axis2
  * @{
  */
  
/** @} */

#include <axiom_soap_fault_code.h>

#ifdef __cplusplus
extern "C"
{
#endif
  
/**
 * @defgroup axiom_soap_fault_code Soap fault code
 * @ingroup axiom_soap 
 * @{
 */

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axiom_soap_fault_code_set_value(axiom_soap_fault_code_t *fault_code,
    const axutil_env_t *env,
    struct axiom_soap_fault_value *fault_val);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axiom_soap_fault_code_set_sub_code(axiom_soap_fault_code_t *fault_code,
    const axutil_env_t *env,
    struct axiom_soap_fault_sub_code *fault_subcode);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axiom_soap_fault_code_set_base_node(axiom_soap_fault_code_t *fault_code,
    const axutil_env_t *env,
    axiom_node_t *node);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_code_set_builder(axiom_soap_fault_code_t *fault_code,
    const axutil_env_t *env,
    struct axiom_soap_builder *soap_builder);
                                  
AXIS2_EXTERN int AXIS2_CALL
axiom_soap_fault_code_get_soap_version(axiom_soap_fault_code_t  *fault_code,
    const axutil_env_t *env);
                                       
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_soap_fault_code_set_soap_version(axiom_soap_fault_code_t *fault_code,
    const axutil_env_t *env,
    int soap_version);
                                                                              
   
AXIS2_EXTERN axiom_soap_fault_code_t * AXIS2_CALL
axiom_soap_fault_code_create(const axutil_env_t *env);      
    
/** @} */
    
#ifdef __cplusplus
}
#endif

#endif /** _AXIOM_SOAP_FAULT_CODE_H  */
