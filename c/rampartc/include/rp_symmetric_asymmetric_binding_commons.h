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

#ifndef RP_ASSYMMETRIC_SYMMETRIC_BINDING_COMMONS_H
#define RP_ASSYMMETRIC_SYMMETRIC_BINDING_COMMONS_H

/** @defgroup rp_assymmetric_symmetric_binding_commons
 * @ingroup rp_assymmetric_symmetric_binding_commons
 * @{
 */

#include <rp_includes.h>
#include <rp_binding_commons.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_symmetric_asymmetric_binding_commons_t rp_symmetric_asymmetric_binding_commons_t;

    AXIS2_EXTERN rp_symmetric_asymmetric_binding_commons_t *AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_create(const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_free(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN rp_binding_commons_t *AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_get_binding_commons(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_set_binding_commons(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env,
        rp_binding_commons_t *binding_commons);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_get_signature_protection(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_set_signature_protection(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env,
        axis2_bool_t signature_protection);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_get_token_protection(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_set_token_protection(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env,
        axis2_bool_t token_protection);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_get_entire_headers_and_body_signatures(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_set_entire_headers_and_body_signatures(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env,
        axis2_bool_t entire_headers_and_body_signatures);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_get_protection_order(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_asymmetric_binding_commons_set_protection_order(
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons,
        const axutil_env_t *env,
        axis2_char_t *protection_order);

#ifdef __cplusplus
}
#endif
#endif
