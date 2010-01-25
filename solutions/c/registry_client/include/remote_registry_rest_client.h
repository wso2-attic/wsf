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
 
#ifndef REMOTE_REGISTRY_REST_CLIENT_H
#define REMOTE_REGISTRY_REST_CLIENT_H

/**
  * @file remote_registry_rest_client.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include <remote_registry_conf.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup remote_registry_rest_client
 * @ingroup remote_registry
 * @{
 */
typedef struct remote_registry_rest_client remote_registry_rest_client_t;
 
/**
 * @brief remote_registry_rest_client
 *    remote_registry_rest_client
 */
AXIS2_EXTERN remote_registry_rest_client_t* AXIS2_CALL
remote_registry_rest_client_create(
    const axutil_env_t *env,  
    remote_registry_conf_t *conf);
                        
/**
 * freeing the rest client
 * @param env axutil_env_t*
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rest_client_free(
    remote_registry_rest_client_t *rest_client, 
    const axutil_env_t *env);
                        
/**
 * Do an http get
 * @param rest_client remote_registry_rest_client_t*
 * @param env axutil_env_t*
 * @param path axis2_char_t*
 * @param params axutil_array_list_t*
 * @return axis2_char_t* response as char
 */
AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
remote_registry_rest_client_get(
    remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *path,
    const axutil_array_list_t *params,
    int relative,
    int *buffer_len);

/**
 * Do an http head
 * @param rest_client remote_registry_rest_client_t*
 * @param env axutil_env_t*
 * @param path axis2_char_t*
 */
AXIS2_EXTERN long AXIS2_CALL 
remote_registry_rest_client_head(
    remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *path,
	int relative);

/**
 * Do a rest client post
 * @param rest_client remote_registry_rest_client_t*
 * @param env axutil_env_t*
 * @param url axis2_char_t*
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rest_client_post(
    remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *url,
    const axis2_char_t *data,
	int data_len,
    const axis2_char_t *custom_headers);

/**
 * Do a rest client put
 * @param rest_client remote_registry_rest_client_t*
 * @param env axutil_env_t*
 * @param url axis2_char_t*
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rest_client_put(
    remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *url,
    const axis2_char_t *data,
	int data_len,
    const axis2_char_t *custom_headers);

/**
 * Do a rest client delete
 * @param rest_client remote_registry_rest_client_t*
 * @param env axutil_env_t*
 * @param url axis2_char_t*
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_rest_client_delete(
    remote_registry_rest_client_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *url,
    const axutil_array_list_t *params);

/**
 * Retrieve the last response status on the http invocations
 * @param rest_client remote_registry_rest_client_t*
 * @param env axutil_env_t*
 * @param url axis2_char_t*
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_rest_client_get_last_response_status(
        remote_registry_rest_client_t *rest_client,
        const axutil_env_t *env);

/**
 * Retrieve the last response content type
 * @param rest_client remote_registry_rest_client_t*
 * @param env axutil_env_t*
 * @param url axis2_char_t*
 */
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
remote_registry_rest_client_get_last_response_content_type(
        remote_registry_rest_client_t *rest_client,
        const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REMOTE_REGISTRY_REST_CLIENT_H */

