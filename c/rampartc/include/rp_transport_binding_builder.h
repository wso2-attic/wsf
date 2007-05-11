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

#ifndef RP_TRANSPORT_BINDING_BUILDER_H
#define RP_TRANSPORT_BINDING_BUILDER_H

/** @defgroup rp_transport_binding_builder
 * @ingroup rp_transport_binding_builder
 * @{
 */

#include <rp_includes.h>
#include <rp_property.h>
#include <rp_transport_binding.h>


#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN rp_transport_binding_t *AXIS2_CALL
    rp_transport_binding_builder_build(
        const axutil_env_t *env,
        axiom_node_t *transport);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_transport_binding_builder_set_token_type(
        const axutil_env_t *env,
        rp_transport_binding_t *transport_binding,
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *local_name);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_transport_binding_builder_istoken(
        const axutil_env_t *env,
        axis2_char_t *local_name);


#ifdef __cplusplus
}
#endif
#endif
