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

#ifndef RP_SIGNED_ENCRYPTED_ELEMENTS_H
#define RP_SIGNED_ENCRYPTED_ELEMENTS_H

/** @defgroup rp_signed_encrypted_elements
 * @ingroup rp_signed_encrypted_elements
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_signed_encrypted_elements_t rp_signed_encrypted_elements_t;

    AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
    rp_signed_encrypted_elements_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_signed_encrypted_elements_free(rp_signed_encrypted_elements_t *signed_encrypted_elements,
                                      const axutil_env_t *env);


    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_signed_encrypted_elements_get_signedelements(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_signed_encrypted_elements_set_signedelements(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env,
            axis2_bool_t signedelements);

    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    rp_signed_encrypted_elements_get_xpath_expressions(
        rp_signed_encrypted_elements_t *signed_encrypted_elements,
        const axutil_env_t *env);


    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_signed_encrypted_elements_add_expression(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env,
            axis2_char_t *expression);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_signed_encrypted_elements_get_xpath_version(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_signed_encrypted_elements_set_xpath_version(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env,
            axis2_char_t *xpath_version);


#ifdef __cplusplus
}
#endif
#endif
