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
 
#ifndef REMOTE_REGISTRY_CONF_H
#define REMOTE_REGISTRY_CONF_H

/**
  * @file remote_registry_conf.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_array_list.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup remote_registry_conf
 * @ingroup remote_registry
 * @{
 */
typedef struct remote_registry_conf remote_registry_conf_t;
 
/**
 * @brief remote_registry_conf
 *    remote_registry_conf
 */
AXIS2_EXTERN remote_registry_conf_t* AXIS2_CALL
remote_registry_conf_create(
    const axutil_env_t *env);
                        
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_conf_free(
    remote_registry_conf_t *rest_client, 
    const axutil_env_t *env);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_conf_set_username(
    remote_registry_conf_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *username);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_conf_set_password(
    remote_registry_conf_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *password);

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
remote_registry_conf_set_reg_url(
    remote_registry_conf_t *rest_client,
	const axutil_env_t *env,
    const axis2_char_t *reg_url);


AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_conn_timeout(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    int conn_timeout);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_cache_timeout(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    int cache_timeout);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
remote_registry_conf_set_cache_entries_limit(
    remote_registry_conf_t *conf,
    const axutil_env_t *env,
    int cache_entries_limit);


AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
remote_registry_conf_get_username(
    remote_registry_conf_t *rest_client,
	const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
remote_registry_conf_get_password(
    remote_registry_conf_t *rest_client,
	const axutil_env_t *env);

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
remote_registry_conf_get_reg_url(
    remote_registry_conf_t *rest_client,
	const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_conf_get_conn_timeout(
    remote_registry_conf_t *conf,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_conf_get_cache_timeout(
    remote_registry_conf_t *conf,
    const axutil_env_t *env);

AXIS2_EXTERN int AXIS2_CALL
remote_registry_conf_get_cache_entries_limit(
    remote_registry_conf_t *conf,
    const axutil_env_t *env);



/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REMOTE_REGISTRY_CONF_H */

