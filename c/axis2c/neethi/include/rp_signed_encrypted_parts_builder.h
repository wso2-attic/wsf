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

#ifndef RP_SIGNED_ENCRYPTED_PARTS_BUILDER_H
#define RP_SIGNED_ENCRYPTED_PARTS_BUILDER_H

/** @defgroup rp_signed_encrypted_parts_builder
 * @ingroup rp_signed_encrypted_parts_builder
 * @{
 */

#include <rp_signed_encrypted_parts.h>
#include <rp_header.h>
#include <rp_includes.h>
#include <rp_property.h>
#include <neethi_assertion.h>

#ifdef __cplusplus
extern "C"
{
#endif

    AXIS2_EXTERN neethi_assertion_t *AXIS2_CALL
    rp_signed_encrypted_parts_builder_build(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element);
 

#ifdef __cplusplus
}
#endif
#endif
