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

#ifndef RP_WSS10_H
#define RP_WSS10_H

/** @defgroup wss10
 * @ingroup wss10
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_wss10_t rp_wss10_t;

    AXIS2_EXTERN rp_wss10_t *AXIS2_CALL
    rp_wss10_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_wss10_free(rp_wss10_t *wss10,
                  const axutil_env_t *env);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss10_get_must_support_ref_key_identifier(rp_wss10_t *wss10,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss10_set_must_support_ref_key_identifier(rp_wss10_t *wss10,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_key_identifier);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss10_get_must_support_ref_issuer_serial(rp_wss10_t *wss10,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss10_set_must_support_ref_issuer_serial(rp_wss10_t *wss10,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_issuer_serial);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss10_get_must_support_ref_external_uri(rp_wss10_t *wss10,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss10_set_must_support_ref_external_uri(rp_wss10_t *wss10,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_external_uri);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_wss10_get_must_support_ref_embedded_token(rp_wss10_t *wss10,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss10_set_must_support_ref_embedded_token(rp_wss10_t *wss10,
            const axutil_env_t *env,
            axis2_bool_t must_support_ref_embedded_token);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_wss10_increment_ref(rp_wss10_t *wss10,
            const axutil_env_t *env);


#ifdef __cplusplus
}
#endif
#endif
