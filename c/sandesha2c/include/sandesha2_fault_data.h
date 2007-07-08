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
 
#ifndef SANDESHA2_FAULT_DATA_H
#define SANDESHA2_FAULT_DATA_H

/**
  * @file sandesha2_fault_data.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>
#include <axiom_node.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup sandesha2_util
 * @{
 */
 
typedef struct sandesha2_fault_data_t sandesha2_fault_data_t;

AXIS2_EXTERN sandesha2_fault_data_t* AXIS2_CALL
sandesha2_fault_data_create(
	const axutil_env_t *env);
  
axiom_node_t *AXIS2_CALL 
sandesha2_fault_data_get_detail(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_detail(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axiom_node_t *detail);
            
axis2_char_t *AXIS2_CALL 
sandesha2_fault_data_get_reason(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_reason(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axis2_char_t *reason);

axis2_char_t *AXIS2_CALL 
sandesha2_fault_data_get_sub_code(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_sub_code(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axis2_char_t *sub_code);
            
axis2_char_t *AXIS2_CALL 
sandesha2_fault_data_get_code(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_code(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axis2_char_t *code);
            
int AXIS2_CALL 
sandesha2_fault_data_get_type(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_type(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    int type);
            
axis2_char_t *AXIS2_CALL 
sandesha2_fault_data_get_seq_id(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env);
            
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_set_seq_id(
    sandesha2_fault_data_t *data,
    const axutil_env_t *env,
    axis2_char_t *seq_id);
    
axis2_status_t AXIS2_CALL 
sandesha2_fault_data_free(
    sandesha2_fault_data_t *data, 
    const axutil_env_t *env);								

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SANDESHA2_FAULT_DATA_H*/
