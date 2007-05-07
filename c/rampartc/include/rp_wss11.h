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

#ifndef RP_WSS11_H
#define RP_WSS11_H

/** @defgroup wss11
 * @ingroup wss11
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_wss11_t rp_wss11_t;

    AXIS2_EXTERN rp_wss11_t *AXIS2_CALL
    rp_wss11_create(const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss11_free(rp_wss11_t *wss11,
                  const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss11_get_must_support_ref_key_identifier(rp_wss11_t *wss11,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss11_set_must_support_ref_key_identifier(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_key_identifier);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss11_get_must_support_ref_issuer_serial(rp_wss11_t *wss11,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss11_set_must_support_ref_issuer_serial(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_issuer_serial);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss11_get_must_support_ref_external_uri(rp_wss11_t *wss11,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss11_set_must_support_ref_external_uri(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_external_uri);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss11_get_must_support_ref_embedded_token(rp_wss11_t *wss11,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss11_set_must_support_ref_embedded_token(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_embedded_token);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss11_get_must_support_ref_thumbprint(rp_wss11_t *wss11,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss11_set_must_support_ref_thumbprint(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_thumbprint);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss11_set_must_support_ref_encryptedkey(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_encryptedkey);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss11_get_must_support_ref_encryptedkey(rp_wss11_t *wss11,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss11_set_require_signature_confirmation(rp_wss11_t *wss11,
            const axutil_env_t *env,
            axis2_bool_t require_signature_confirmation);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss11_get_require_signature_confirmation(rp_wss11_t *wss11,
            const axutil_env_t *env);


#ifdef __cplusplus
}
#endif
#endif
