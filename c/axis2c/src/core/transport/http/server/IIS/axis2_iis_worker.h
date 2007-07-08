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

#ifndef AXIS2_APACHE2_WORKER_H
#define AXIS2_APACHE2_WORKER_H

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct axis2_iis_worker axis2_iis_worker_t;
	
int AXIS2_CALL
axis2_iis_worker_process_request(axis2_iis_worker_t *iis_worker,
    const axutil_env_t *env, 
    void *r);

void AXIS2_CALL
axis2_iis_worker_free(axis2_iis_worker_t *iis_worker,
    const axutil_env_t *env);

axis2_iis_worker_t * AXIS2_CALL
axis2_iis_worker_create(
const axutil_env_t *env, 
axis2_char_t *repo_path);


#define AXIS2_IIS_WORKER_PROCESS_REQUEST(iis_worker, env, request)	\
                        axis2_iis_worker_process_request(		\
                        iis_worker, env, request)
#define AXIS2_IIS_WORKER_FREE(iis_worker, env)					\
                axis2_iis_worker_free(iis_worker, env)

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_IIS_WORKER_H */
