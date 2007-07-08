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

#ifndef RP_RAMPART_CONFIG_H
#define RP_RAMPART_CONFIG_H

/** @defgroup rp_rampart_config
 * @ingroup rp_rampart_config
 * @{
 */

#include <rp_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct rp_rampart_config_t rp_rampart_config_t;

    AXIS2_EXTERN rp_rampart_config_t *AXIS2_CALL
    rp_rampart_config_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    rp_rampart_config_free(rp_rampart_config_t *rampart_config,
                           const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_user(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_user(rp_rampart_config_t *rampart_config,
                               const axutil_env_t *env,
                               axis2_char_t *user);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_encryption_user(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_encryption_user(rp_rampart_config_t *rampart_config,
                                          const axutil_env_t *env,
                                          axis2_char_t *encryption_user);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_password_callback_class(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_password_callback_class(rp_rampart_config_t *rampart_config,
            const axutil_env_t *env,
            axis2_char_t *passwprd_callback_class);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_authenticate_module(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_authenticate_module(rp_rampart_config_t *rampart_config,
            const axutil_env_t *env,
            axis2_char_t *authenticate_module);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_password_type(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_password_type(rp_rampart_config_t *rampart_config,
                                        const axutil_env_t *env,
                                        axis2_char_t *password_type);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_private_key_file(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_private_key_file(rp_rampart_config_t *rampart_config,
                                           const axutil_env_t *env,
                                           axis2_char_t *private_key_file);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_receiver_certificate_file(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_receiver_certificate_file(rp_rampart_config_t *rampart_config,
            const axutil_env_t *env,
            axis2_char_t *receiver_certificate_file);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_certificate_file(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_certificate_file(rp_rampart_config_t *rampart_config,
                                           const axutil_env_t *env,
                                           axis2_char_t *certificate_file);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_time_to_live(
        rp_rampart_config_t *rampart_config,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_time_to_live(rp_rampart_config_t *rampart_config,
                                       const axutil_env_t *env,
                                       axis2_char_t *time_to_live);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    rp_rampart_config_get_rd_val(rp_rampart_config_t *rampart_config,
                                 const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rp_rampart_config_set_rd_val(rp_rampart_config_t *rampart_config,
                                const axutil_env_t *env,
                                axis2_char_t *rd_val);


#ifdef __cplusplus
}
#endif
#endif
