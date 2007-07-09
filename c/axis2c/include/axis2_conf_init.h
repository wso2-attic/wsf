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

#ifndef AXIS2_CONF_INIT_H
#define AXIS2_CONF_INIT_H

/** @defgroup axis2_conf_init configuration initilizing functions
 * @ingroup axis2_deployment
 * @{
 */

#include <axutil_env.h>
#include <axutil_utils_defines.h>
#include <axis2_conf_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Builds the configuration for the Server
     * @param env Pointer to environment struct. MUST NOT be NULL
     * @param repo_name repository name
     * @return pointer to an instance of configuration context properly initialized
     */
    AXIS2_EXTERN axis2_conf_ctx_t *AXIS2_CALL 
    axis2_build_conf_ctx(const axutil_env_t *env,
        const axis2_char_t *repo_name);

    /**
     * Builds the Configuration for the Client
     * @param env Pointer to environment struct. MUST NOT be NULL
     * @param axis2_home axis2 home for client. 
     * @return pointer to an instance of configuration context properly initialized
     */
    AXIS2_EXTERN axis2_conf_ctx_t *AXIS2_CALL 
    axis2_build_client_conf_ctx(const axutil_env_t *env,
        const axis2_char_t *axis2_home);


/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIS2_CONF_INIT_H */
