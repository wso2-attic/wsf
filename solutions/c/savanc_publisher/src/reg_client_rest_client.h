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
 
#ifndef REG_CLIENT_REST_CLIENT_H
#define REG_CLIENT_REST_CLIENT_H

/**
  * @file reg_client_rest_client.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include "reg_client_resource.h"
#include "reg_client_util.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup reg_client_rest_client
 * @ingroup reg_client
 * @{
 */
typedef struct reg_client_rest_client_t reg_client_rest_client_t;
 
/**
 * @brief reg_client_rest_client
 *    reg_client_rest_client
 */
AXIS2_EXTERN reg_client_rest_client_t* AXIS2_CALL
reg_client_rest_client_create(
    const axutil_env_t *env,  
    const axis2_char_t *reg_url, 
	const axis2_char_t *username,
    const axis2_char_t *password);
                        
axis2_status_t AXIS2_CALL 
reg_client_rest_client_free(
    reg_client_rest_client_t *rest_client, 
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL 
reg_client_rest_client_get(
    reg_client_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *path,
    const axutil_array_list_t *params);

axis2_status_t AXIS2_CALL 
reg_client_rest_client_post(
    reg_client_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *url,
    const axis2_char_t *data,
    const axis2_char_t *content_type);

axis2_status_t AXIS2_CALL 
reg_client_rest_client_delete(
    reg_client_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *url,
    const axutil_array_list_t *params);

long AXIS2_CALL
reg_client_rest_client_get_status(
        reg_client_rest_client_t *rest_client,
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REG_CLIENT_REST_CLIENT_H */

