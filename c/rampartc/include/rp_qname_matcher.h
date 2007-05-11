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

#ifndef RP_QNAME_MATCHER_H
#define RP_QNAME_MATCHER_H

/** @defgroup rp_qname_matcher
 * @ingroup rp_qname_matcher
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_match_secpolicy_qname(
        const axutil_env_t *env,
        const axis2_char_t *local_name,
        axiom_node_t *node,
        axiom_element_t *element);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_match_policy_qname(
        const axutil_env_t *env,
        const axis2_char_t *local_name,
        axiom_node_t *node,
        axiom_element_t *element);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_match_rampart_config_qname(
        const axutil_env_t *env,
        const axis2_char_t *local_name,
        axiom_node_t *node,
        axiom_element_t *element);



#ifdef __cplusplus
}
#endif
#endif
