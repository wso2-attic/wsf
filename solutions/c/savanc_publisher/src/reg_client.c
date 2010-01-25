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

#include "reg_client_remote_reg.h"
#include <reg_client_constants.h>
#include <reg_client.h>

/** 
 * @brief reg_client struct impl
 *	Registration Client Resource represent Resource
 */
  
axis2_status_t AXIS2_CALL
reg_client_init(
    const axutil_env_t *env,
    axis2_conf_t *conf,
    axis2_char_t *publisher_svc)
{
    axis2_status_t status = AXIS2_SUCCESS;
    reg_client_remote_reg_t *remote_reg = NULL;
    axis2_char_t *root = "/topics";

    reg_client_remote_reg_init(env);
    remote_reg = reg_client_remote_reg_create(env, conf, publisher_svc);
    reg_client_remote_reg_get(remote_reg, env, root, NULL, conf);  
    
    reg_client_remote_reg_free(remote_reg, env);

    return status;
}


axis2_status_t AXIS2_CALL 
reg_client_cleanup(
    const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_SUCCESS;
    
    reg_client_remote_reg_cleanup(env);
    return status;
}

