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

#ifndef RP_X509_TOKEN_H
#define RP_X509_TOKEN_H

/** @defgroup rp_x509_token
 * @ingroup rp_x509_token
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_x509_token_t rp_x509_token_t;

    AXIS2_EXTERN rp_x509_token_t *AXIS2_CALL
    rp_x509_token_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_x509_token_free(rp_x509_token_t *x509_token,
                       const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_x509_token_get_inclusion(rp_x509_token_t *x509_token,
                                const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_x509_token_set_inclusion(rp_x509_token_t *x509_token,
                                const axutil_env_t *env,
                                axis2_char_t *inclusion);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_x509_token_get_derivedkeys(rp_x509_token_t *x509_token,
                                  const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_x509_token_set_derivedkeys(rp_x509_token_t *x509_token,
                                  const axutil_env_t *env,
                                  axis2_bool_t derivedkeys);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_x509_token_get_require_key_identifier_reference(rp_x509_token_t *x509_token,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_x509_token_set_require_key_identifier_reference(rp_x509_token_t *x509_token,
            const axutil_env_t *env,
            axis2_bool_t require_key_identifier_reference);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_x509_token_get_require_issuer_serial_reference(rp_x509_token_t *x509_token,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_x509_token_set_require_issuer_serial_reference(rp_x509_token_t *x509_token,
            const axutil_env_t *env,
            axis2_bool_t require_issuer_serial_reference);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_x509_token_get_require_embedded_token_reference(rp_x509_token_t *x509_token,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_x509_token_set_require_embedded_token_reference(rp_x509_token_t *x509_token,
            const axutil_env_t *env,
            axis2_bool_t require_embedded_token_reference);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_x509_token_get_require_thumb_print_reference(rp_x509_token_t *x509_token,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_x509_token_set_require_thumb_print_reference(rp_x509_token_t *x509_token,
            const axutil_env_t *env,
            axis2_bool_t require_thumb_print_reference);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_x509_token_get_token_version_and_type(rp_x509_token_t *x509_token,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_x509_token_set_token_version_and_type(rp_x509_token_t *x509_token,
            const axutil_env_t *env,
            axis2_char_t *token_version_and_type);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_x509_token_increment_ref(rp_x509_token_t *x509_token,
            const axutil_env_t *env);
    

#ifdef __cplusplus
}
#endif
#endif
