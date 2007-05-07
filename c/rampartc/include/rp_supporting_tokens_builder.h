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

#ifndef RP_SUPPORTING_TOKEN_BUILDER_H
#define RP_SUPPORTING_TOKEN_BUILDER_H

/** @defgroup rp_supporting_tokens_builder
 * @ingroup rp_supporting_tokens_builder
 * @{
 */

#include <rp_supporting_tokens.h>
#include <rp_includes.h>
#include <rp_property.h>
#include <rp_qname_matcher.h>
#include <rp_x509_token_builder.h>
#include <rp_username_token_builder.h>
#include <rp_security_context_token_builder.h>
#include <rp_token_builder.h>
#include <rp_algorithmsuite_builder.h>
#include <rp_signed_encrypted_parts_builder.h>
#include <rp_signed_encrypted_elements_builder.h>

#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_supporting_tokens_builder_build(const axutil_env_t *env, axiom_node_t *supporting);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_builder_set_other_properties(
        const axutil_env_t *env,
        rp_supporting_tokens_t *supporting_tokens,
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *local_name);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_supporting_tokens_builder_istoken(
        const axutil_env_t *env,
        axis2_char_t *local_name);


#ifdef __cplusplus
}
#endif
#endif
