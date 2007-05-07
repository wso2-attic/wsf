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

#ifndef RP_POLICY_CREATOR_H
#define RP_POLICY_CREATOR_H

/** @defgroup rp_policy_creator
 * @ingroup rp_policy_creator
 * @{
 */

#include <axiom.h>
#include <axis2_util.h>
#include <axutil_env.h>
#include <axutil_log_default.h>
#include <axutil_error_default.h>
#include <stdio.h>
#include <axiom_xml_reader.h>

#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN rp_secpolicy_t *AXIS2_CALL
    rp_policy_create_from_file(
        const axutil_env_t *env,
        axis2_char_t *filename);

    AXIS2_EXTERN rp_secpolicy_t *AXIS2_CALL
    rp_policy_create_from_om_node(
        const axutil_env_t *env,
        axiom_node_t *root);


#ifdef __cplusplus
}
#endif
#endif
