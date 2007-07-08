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

#ifndef RP_USERNAME_TOKEN_H
#define RP_USERNAME_TOKEN_H

/** @defgroup rp_username_token
 * @ingroup rp_username_token
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_username_token_t rp_username_token_t;

    AXIS2_EXTERN rp_username_token_t *AXIS2_CALL
    rp_username_token_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_username_token_free(
        rp_username_token_t *username_token,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_username_token_get_inclusion(
        rp_username_token_t *username_token,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_username_token_set_inclusion(
        rp_username_token_t *username_token,
        const axutil_env_t *env,
        axis2_char_t *inclusion);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_username_token_get_derivedkeys(
        rp_username_token_t *username_token,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_username_token_set_derivedkeys(
        rp_username_token_t *username_token,
        const axutil_env_t *env,
        axis2_bool_t derivedkeys);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_username_token_get_useUTprofile10(
        rp_username_token_t *username_token,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_username_token_set_useUTprofile10(
        rp_username_token_t *username_token,
        const axutil_env_t *env,
        axis2_bool_t useUTprofile10);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rp_username_token_get_useUTprofile11(
        rp_username_token_t *username_token,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_username_token_set_useUTprofile11(
        rp_username_token_t *username_token,
        const axutil_env_t *env,
        axis2_bool_t useUTprofile11);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_username_token_increment_ref(
        rp_username_token_t *username_token,
        const axutil_env_t *env);
    

#ifdef __cplusplus
}
#endif
#endif
