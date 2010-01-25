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
 
#ifndef REG_CLIENT_UTIL_H
#define REG_CLIENT_UTIL_H

/**
  * @file reg_client_util.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include "reg_client_resource.h"
#include "reg_client_entry.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup reg_client_util
 * @ingroup reg_client
 * @{
 */
 
typedef struct reg_client_url_param
{
    axis2_char_t *key;
    axis2_char_t *value;
} reg_client_url_param_t;

typedef struct reg_client_util
{
    const axutil_env_t *env;
    struct reg_client_resource *resource;
    axis2_bool_t parse_entries;
    axis2_bool_t parse_entry;
    reg_client_entry_t *entry;
} reg_client_util_t;

/**
 * @brief reg_client_resource
 *    reg_client_resource
 */
AXIS2_EXTERN reg_client_util_t* AXIS2_CALL
reg_client_util_create(
    const axutil_env_t *env);  
                        
void AXIS2_CALL 
reg_client_util_free(
    reg_client_util_t *util, 
    const axutil_env_t *env);

reg_client_resource_t* AXIS2_CALL 
reg_client_util_populate_resource(
	const axutil_env_t *env,
    const axis2_char_t *file_name);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REG_CLIENT_UTIL_H */

