/*
 * Copyright 2005,2010 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WSF_WORKER_H
#define WSF_WORKER_H

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>
#include <SAPI.h>
#include "wsf_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct wsf_worker_t wsf_worker_t;

/**
* 
* @param env, 
* @param repo_path, 
* @param rm_db_dir, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
wsf_worker_t *wsf_worker_create (
    const axutil_env_t * env,
    axis2_char_t * repo_path,
    axis2_char_t * rm_db_dir);

/**
* 
* @param worker, 
* @param env, 
* @param req_info, 
* @param res_info, 
* @param TSRMLS_DC, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
int wsf_worker_process_request (
    wsf_worker_t * worker,
    axutil_env_t * env,
    wsf_request_info_t *req_info,
	wsf_response_info_t *res_info,
    wsf_svc_info_t *svc_info TSRMLS_DC);

/**
* 
* @param worker, 
* @param env, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
void wsf_worker_free (
    wsf_worker_t * worker,
    const axutil_env_t * env);


/**
* 
* @param worker, 
* @param env, 
* @returns AXIS2_SUCCESS on success, AXIS2_FAILURE Otherwise
*/
axis2_conf_ctx_t *
wsf_worker_get_conf_ctx (
    wsf_worker_t * worker,
    const axutil_env_t * env);


#ifdef __cplusplus
}
#endif

#endif /* WSF_WORKER_H */
