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

#ifndef SANDESHA2_MODULE_H
#define SANDESHA2_MODULE_H

/**
 * @file axis2_addr_mod.h
 * @brief Axis2 addressing module interface
 */

#include <axis2_handler.h>

#ifdef __cplusplus
extern "C"
{
#endif
AXIS2_EXTERN axis2_module_t * AXIS2_CALL
mod_sandesha2_create(
    const axutil_env_t *env);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL 
sandesha2_global_in_handler_create(
    const axutil_env_t *env, 
    axutil_qname_t *qname);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL 
sandesha2_in_handler_create(
    const axutil_env_t *env, 
    axutil_qname_t *qname);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL 
sandesha2_out_handler_create(
    const axutil_env_t *env, 
    axutil_qname_t *qname);
    
/** @} */
    
#ifdef __cplusplus
}
#endif

#endif    /* SANDESHA2_MODULE_H */
