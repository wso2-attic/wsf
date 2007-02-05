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

#ifndef AXIS2_WSCLIENT_STUB_H
#define AXIS2_WSCLIENT_STUB_H

#include <axis2_utils.h>
#include <axis2_utils_defines.h>
#include <axis2_env.h>
#include <axis2_array_list.h>
#include <axis2_hash.h>
#include <platforms/axis2_platform_auto_sense.h>
#include <axiom_node.h>


#ifdef __cplusplus
extern "C"
{
#endif

axis2_status_t AXIS2_CALL
wsclient_stub_invoke(
    const axis2_env_t *env,
    axis2_array_list_t *all_opt_list,
    axis2_char_t *dest_uri,
    axis2_char_t *input);

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_WSCLIENT_STUB_H */
