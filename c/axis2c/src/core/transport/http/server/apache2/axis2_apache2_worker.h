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

/**
 * @brief Apache2 Worker ops struct
 * Encapsulator struct for ops of axis2_apache2_worker
 */

/**
 * @ingroup axis2_core_transport_http
 * @{
 */

/**
  * @file axis2_apache2_worker.h
  * @brief axis2 Apache2 Worker
  */

#include <axis2_const.h>
#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>
#include "apache2_stream.h"


#ifdef __cplusplus
extern "C"
{
#endif


    typedef struct axis2_apache2_worker axis2_apache2_worker_t;

    AXIS2_EXTERN int AXIS2_CALL
    axis2_apache2_worker_process_request(axis2_apache2_worker_t *apache2_worker,
        const axutil_env_t *env, 
        request_rec *r);

    AXIS2_EXTERN void AXIS2_CALL
    axis2_apache2_worker_free(axis2_apache2_worker_t *apache2_worker,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_apache2_worker_t * AXIS2_CALL
    axis2_apache2_worker_create(
        const axutil_env_t *env, 
        axis2_char_t *repo_path);

#define AXIS2_APACHE2_WORKER_PROCESS_REQUEST(apache2_worker, env, request) \
                        axis2_apache2_worker_process_request(\
                        apache2_worker, env, request)
#define AXIS2_APACHE2_WORKER_FREE(apache2_worker, env) \
                axis2_apache2_worker_free(apache2_worker, env)

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_APACHE2_WORKER_H */
