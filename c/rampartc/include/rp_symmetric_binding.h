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

#ifndef RP_SYMMETRIC_BINDING_H
#define RP_SYMMETRIC_BINDING_H

/** @defgroup rp_symmetric_binding
 * @ingroup rp_symmetric_binding
 * @{
 */

#include <rp_includes.h>
#include <rp_symmetric_asymmetric_binding_commons.h>
#include <rp_property.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_symmetric_binding_t rp_symmetric_binding_t;

    AXIS2_EXTERN rp_symmetric_binding_t *AXIS2_CALL
    rp_symmetric_binding_create(const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_binding_free(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env);

    AXIS2_EXTERN rp_symmetric_asymmetric_binding_commons_t *AXIS2_CALL
    rp_symmetric_binding_get_symmetric_asymmetric_binding_commons(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_binding_set_symmetric_asymmetric_binding_commons(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env,
        rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_binding_set_protection_token(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env,
        rp_property_t *protection_token);

    AXIS2_EXTERN rp_property_t *AXIS2_CALL
    rp_symmetric_binding_get_protection_token(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_binding_set_encryption_token(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env,
        rp_property_t *encryption_token);

    AXIS2_EXTERN rp_property_t *AXIS2_CALL
    rp_symmetric_binding_get_encryption_token(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_symmetric_binding_set_signature_token(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env,
        rp_property_t *signature_token);

    AXIS2_EXTERN rp_property_t *AXIS2_CALL
    rp_symmetric_binding_get_signature_token(
        rp_symmetric_binding_t *symmetric_binding,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif
#endif
