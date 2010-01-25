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
 
#ifndef REG_CLIENT_ENTRY_H
#define REG_CLIENT_ENTRY_H

/**
  * @file reg_client_entry.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include "reg_client_resource.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup reg_client_entry
 * @ingroup reg_client
 * @{
 */
 
typedef struct reg_client_entry 
{
    axis2_char_t *title;
    axutil_array_list_t *link_list;
} reg_client_entry_t;

/**
 * @brief reg_client_resource
 *    reg_client_resource
 */
AXIS2_EXTERN reg_client_entry_t* AXIS2_CALL
reg_client_entry_create(
    const axutil_env_t *env);  
                        
void AXIS2_CALL 
reg_client_entry_free(
    reg_client_entry_t *entry, 
    const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REG_CLIENT_ENTRY_H */

