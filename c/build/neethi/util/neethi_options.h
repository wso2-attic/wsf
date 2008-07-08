/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NEETHI_OPTIONS_H
#define NEETHI_OPTIONS_H


/**
  * @file neethi_options.h
  * @build a om from a client options. 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <neethi_includes.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct neethi_options_t neethi_options_t;

    AXIS2_EXTERN neethi_options_t *AXIS2_CALL
    neethi_options_create(const axutil_env_t *env);

    AXIS2_EXTERN void AXIS2_CALL
    neethi_options_free(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    neethi_options_get_binding(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    neethi_options_set_binding(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_char_t *binding);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_options_get_include_timestamp(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_include_timestamp(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_bool_t include_timestamp);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_options_get_is_username_token(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_is_username_token(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_bool_t is_username_token);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_options_get_token_protection(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_token_protection(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_bool_t token_protection);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_options_get_signature_protection(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_signature_protection(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_bool_t signature_protection);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_options_get_encrypt_before_sign(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_encrypt_before_sign(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_bool_t encrypt_before_sign);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_options_get_sign_body(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_sign_body(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_bool_t sign_body);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_options_get_encrypt_body(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_encrypt_body(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_bool_t encrypt_body);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    neethi_options_get_algorithmsuite(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_algorithmsuite(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_char_t *algorithmsuite);

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    neethi_options_get_keyidentifier(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_keyidentifier(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_char_t *keyidentifier);

    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    neethi_options_get_root_node(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    neethi_options_create_policy_node(
        const axutil_env_t *env,
        axiom_node_t *parent_node);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_create_signed_parts_node(
        neethi_options_t *options,
        const axutil_env_t *env,
        axiom_node_t *parent_node);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_create_encrypted_parts_node(
        neethi_options_t *options,
        const axutil_env_t *env,
        axiom_node_t *parent_node);

	AXIS2_EXTERN axis2_status_t AXIS2_CALL
	neethi_options_create_asym_node(
        neethi_options_t *options,
        const axutil_env_t *env,
        axiom_node_t *parent_node);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
	neethi_options_create_sym_node(
        neethi_options_t *options,
        const axutil_env_t *env,
        axiom_node_t *parent_node);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_options_get_server_side(
        neethi_options_t *options,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_options_set_server_side(
        neethi_options_t *options,
        const axutil_env_t *env,
        axis2_bool_t server_side);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* NEETHI_OPTIONS_H */
