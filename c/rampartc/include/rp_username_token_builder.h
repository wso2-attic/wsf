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

#ifndef RP_USERNAME_TOKEN_BUILDER_H
#define RP_USERNAME_TOKEN_BUILDER_H

/** @defgroup rp_username_token_builder
 * @ingroup rp_username_token_builder
 * @{
 */

#include <rp_includes.h>
#include <rp_qname_matcher.h>
#include <rp_username_token.h>


#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN rp_username_token_t *AXIS2_CALL
    rp_username_token_builder_build(
        const axutil_env_t *env,
        axiom_node_t *username,
        axiom_element_t *username_ele);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_username_token_builder_set_inclusion_value(
        const axutil_env_t *env,
        rp_username_token_t *token,
        axiom_element_t *element);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_username_token_builder_set_properties(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *local_name,
        rp_username_token_t *username_token,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif
#endif
