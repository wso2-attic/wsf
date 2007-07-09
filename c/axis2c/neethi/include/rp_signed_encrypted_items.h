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

#ifndef RP_SIGNED_ENCRYPTED_ITEMS_H
#define RP_SIGNED_ENCRYPTED_ITEMS_H

/** @defgroup rp_signed_encrypted_items
 * @ingroup rp_signed_encrypted_itemss
 * @{
 */

#include <rp_includes.h>
#include <rp_element.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_signed_encrypted_items_t rp_signed_encrypted_items_t;

    AXIS2_EXTERN rp_signed_encrypted_items_t *AXIS2_CALL
    rp_signed_encrypted_items_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_signed_encrypted_items_free(rp_signed_encrypted_items_t *signed_encrypted_items,
                                   const axutil_env_t *env);


    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_signed_encrypted_items_get_signeditems(rp_signed_encrypted_items_t *signed_encrypted_items,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_signed_encrypted_items_set_signeditems(rp_signed_encrypted_items_t *signed_encrypted_items,
            const axutil_env_t *env,
            axis2_bool_t signeditems);

    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    rp_signed_encrypted_items_get_elements(
        rp_signed_encrypted_items_t *signed_encrypted_items,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_signed_encrypted_items_add_element(
        rp_signed_encrypted_items_t *signed_encrypted_items,
        const axutil_env_t *env,
        rp_element_t *element);

#ifdef __cplusplus
}
#endif
#endif

