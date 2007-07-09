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

#ifndef RP_TRANSPORT_BINDING_H
#define RP_TRANSPORT_BINDING_H

/** @defgroup rp_transport_binding
 * @ingroup rp_transport_binding
 * @{
 */

#include <rp_includes.h>
#include <rp_binding_commons.h>
#include <rp_property.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_transport_binding_t rp_transport_binding_t;

    AXIS2_EXTERN rp_transport_binding_t *AXIS2_CALL
    rp_transport_binding_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_transport_binding_free(
        rp_transport_binding_t *transport_binding,
        const axutil_env_t *env);

    AXIS2_EXTERN rp_binding_commons_t *AXIS2_CALL
    rp_transport_binding_get_binding_commons(
        rp_transport_binding_t *transport_binding,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_transport_binding_set_binding_commons(
        rp_transport_binding_t *transport_binding,
        const axutil_env_t *env,
        rp_binding_commons_t *binding_commons);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_transport_binding_set_transport_token(
        rp_transport_binding_t *transport_binding,
        const axutil_env_t *env,
        rp_property_t *transport_token);

    AXIS2_EXTERN rp_property_t *AXIS2_CALL
    rp_transport_binding_get_transport_token(
        rp_transport_binding_t *transport_binding,
        const axutil_env_t *env);

#ifdef __cplusplus
}
#endif
#endif
