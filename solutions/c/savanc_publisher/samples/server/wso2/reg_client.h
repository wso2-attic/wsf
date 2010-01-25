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
 
#ifndef REG_CLIENT_H
#define REG_CLIENT_H

/**
  * @file reg_client.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_utils.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axis2_conf.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup reg_client
 * @ingroup reg_client
 * @{
 */
 
/**
 * @brief reg_client
 *    reg_client
 */
axis2_status_t AXIS2_CALL
reg_client_init(
    const axutil_env_t *env,
    axis2_conf_t *conf);  
                        
axis2_status_t AXIS2_CALL 
reg_client_cleanup(
    const axutil_env_t *env);

/** @} */
#ifdef __cplusplus
}
#endif

#endif  /* REG_CLIENT_H */

