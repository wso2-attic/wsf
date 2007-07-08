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

#ifndef RP_SECPOLICY_H
#define RP_SECPOLICY_H

/** @defgroup rp_secpolicy
 * @ingroup rp_secpolicy
 * @{
 */

#include <rp_includes.h>
#include <rp_property.h>
#include <rp_asymmetric_binding.h>
#include <rp_symmetric_binding.h>
#include <rp_transport_binding.h>
#include <rp_signed_encrypted_parts.h>
#include <rp_signed_encrypted_elements.h>
#include <rp_signed_encrypted_items.h>
#include <rp_supporting_tokens.h>
#include <rp_rampart_config.h>
#include <rp_wss10.h>
#include <rp_wss11.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_secpolicy_t rp_secpolicy_t;

    AXIS2_EXTERN rp_secpolicy_t *AXIS2_CALL
    rp_secpolicy_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_secpolicy_free(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_binding(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_property_t *binding);

    AXIS2_EXTERN rp_property_t *AXIS2_CALL
    rp_secpolicy_get_binding(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_supporting_tokens(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_supporting_tokens_t *supporting_tokens);

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_secpolicy_get_supporting_tokens(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_signed_supporting_tokens(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_supporting_tokens_t *signed_supporting_tokens);

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_secpolicy_get_signed_supporting_tokens(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_endorsing_supporting_tokens(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_supporting_tokens_t *endorsing_supporting_tokens);

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_secpolicy_get_endorsing_supporting_tokens(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_signed_endorsing_supporting_tokens(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_supporting_tokens_t *signed_endorsing_supporting_tokens);

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_secpolicy_get_signed_endorsing_supporting_tokens(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_signed_parts(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_signed_encrypted_parts_t *signed_parts);

    AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
    rp_secpolicy_get_signed_parts(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_encrypted_parts(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_signed_encrypted_parts_t *encrypted_parts);

    AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
    rp_secpolicy_get_encrypted_parts(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_signed_elements(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_signed_encrypted_elements_t *signed_elements);

    AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
    rp_secpolicy_get_signed_elements(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_encrypted_elements(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_signed_encrypted_elements_t *encrypted_elements);

    AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
    rp_secpolicy_get_encrypted_elements(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_signed_items(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_signed_encrypted_items_t *signed_items);

    AXIS2_EXTERN rp_signed_encrypted_items_t *AXIS2_CALL
        rp_secpolicy_get_signed_items(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_encrypted_items(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_signed_encrypted_items_t *encrypted_items);
    
    AXIS2_EXTERN rp_signed_encrypted_items_t *AXIS2_CALL
    rp_secpolicy_get_encrypted_items(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_wss(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_property_t *wss);

    AXIS2_EXTERN rp_property_t *AXIS2_CALL
    rp_secpolicy_get_wss(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_secpolicy_set_rampart_config(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env,
        rp_rampart_config_t *rampart_config);

    AXIS2_EXTERN rp_rampart_config_t *AXIS2_CALL
    rp_secpolicy_get_rampart_config(
        rp_secpolicy_t *secpolicy,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif
#endif
