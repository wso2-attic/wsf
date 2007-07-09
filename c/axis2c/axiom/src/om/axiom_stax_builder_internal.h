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
 
 #ifndef AXIOM_STAX_BUILDER_INTERNAL_H
 #define AXIOM_STAX_BUILDER_INTERNAL_H
 
 
 /** @defgroup axiom AXIOM (Axis Object Model)
  * @ingroup axis2
  * @{
  */
  
/** @} */

#include <axiom_stax_builder.h>

#ifdef __cplusplus
extern "C"
{
#endif
  
/**
 * @defgroup axiom_stax builder
 * @ingroup axiom 
 * @{
 */
    
AXIS2_EXTERN int AXIS2_CALL
axiom_stax_builder_get_current_event(axiom_stax_builder_t *builder,
                                        const axutil_env_t *env);
                                        
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_stax_builder_set_lastnode(axiom_stax_builder_t *builder,
                                    const axutil_env_t *env,
                                    axiom_node_t *om_node);
                                    
AXIS2_EXTERN int AXIS2_CALL
axiom_stax_builder_get_element_level(axiom_stax_builder_t* builder,
                                        const axutil_env_t *env); 
                                            
AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_stax_builder_set_element_level(axiom_stax_builder_t* builder,
                                        const axutil_env_t *env,
                                        int element_level);  
AXIS2_EXTERN axiom_node_t* AXIS2_CALL
axiom_stax_builder_get_lastnode(axiom_stax_builder_t *builder,
                                   const axutil_env_t *env);
  
/** @} */
    
#ifdef __cplusplus
}
#endif

#endif /** AXIOM_STAX_BUILDER_INTERNAL_H */
