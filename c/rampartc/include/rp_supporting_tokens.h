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

#ifndef RP_SUPPORTING_TOKENS_H
#define RP_SUPPORTING_TOKENS_H

/** @defgroup rp_supporting_tokens
 * @ingroup rp_supporting_tokens
 * @{
 */
#include <rp_includes.h>
#include <rp_algorithmsuite.h>
#include <rp_signed_encrypted_parts.h>
#include <rp_signed_encrypted_elements.h>
#include <rp_property.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_supporting_tokens_t rp_supporting_tokens_t;

    AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL
    rp_supporting_tokens_create(const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_free(rp_supporting_tokens_t *supporting_tokens,
                              const axutil_env_t *env);

    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    rp_supporting_tokens_get_tokens(
        rp_supporting_tokens_t *supporting_tokens,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_add_token(rp_supporting_tokens_t *supporting_tokens,
                                   const axutil_env_t *env,
                                   rp_property_t *token);

    AXIS2_EXTERN rp_algorithmsuite_t *AXIS2_CALL
    rp_supporting_tokens_get_algorithmsuite(
        rp_supporting_tokens_t *supporting_tokens,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_set_algorithmsuite(rp_supporting_tokens_t *supporting_tokens,
                                            const axutil_env_t *env,
                                            rp_algorithmsuite_t *algorithmsuite);

    AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
    rp_supporting_tokens_get_signed_parts(
        rp_supporting_tokens_t *supporting_tokens,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_set_signed_parts(rp_supporting_tokens_t *supporting_tokens,
                                          const axutil_env_t *env,
                                          rp_signed_encrypted_parts_t *signed_parts);

    AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
    rp_supporting_tokens_get_signed_elements(
        rp_supporting_tokens_t *supporting_tokens,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_set_signed_elements(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_signed_encrypted_elements_t *signed_elements);

    AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
    rp_supporting_tokens_get_encrypted_parts(
        rp_supporting_tokens_t *supporting_tokens,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_set_encrypted_parts(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_signed_encrypted_parts_t *encrypted_parts);

    AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
    rp_supporting_tokens_get_encrypted_elements(
        rp_supporting_tokens_t *supporting_tokens,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_set_encrypted_elements(rp_supporting_tokens_t *supporting_tokens,
            const axutil_env_t *env,
            rp_signed_encrypted_elements_t *encrypted_elements);

    AXIS2_EXTERN int AXIS2_CALL
    rp_supporting_tokens_get_type(
        rp_supporting_tokens_t *supporting_tokens,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_supporting_tokens_set_type(rp_supporting_tokens_t *supporting_tokens,
                                  const axutil_env_t *env,
                                  int type);


#ifdef __cplusplus
}
#endif
#endif
