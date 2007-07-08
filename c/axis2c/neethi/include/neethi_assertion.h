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

#ifndef NEETHI_ASSERTION_H
#define NEETHI_ASSERTION_H


/**
  * @file neethi_assertion.h
  * @common struct for policy assertions. 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <neethi_includes.h>
#include <neethi_operator.h>

#ifdef __cplusplus
extern "C"
{
#endif


    typedef enum  {
        ASSERTION_TYPE_TRANSPORT_BINDING = 0,
        ASSERTION_TYPE_TRANSPORT_TOKEN,
        ASSERTION_TYPE_ALGORITHM_SUITE,
        ASSERTION_TYPE_INCLUDE_TIMESTAMP,
        ASSERTION_TYPE_LAYOUT,
        ASSERTION_TYPE_SUPPORTING_TOKENS,
        ASSERTION_TYPE_HTTPS_TOKEN,
        ASSERTION_TYPE_WSS_USERNAME_TOKEN_10,
        ASSERTION_TYPE_WSS_USERNAME_TOKEN_11,
        ASSERTION_TYPE_USERNAME_TOKEN,
        ASSERTION_TYPE_X509_TOKEN,
        ASSERTION_TYPE_MUST_SUPPORT_REF_KEY_IDENTIFIER,
        ASSERTION_TYPE_MUST_SUPPORT_REF_ISSUER_SERIAL,
        ASSERTION_TYPE_MUST_SUPPORT_REF_EXTERNAL_URI,
        ASSERTION_TYPE_MUST_SUPPORT_REF_EMBEDDED_TOKEN,
        ASSERTION_TYPE_WSS10,
        ASSERTION_TYPE_RAMPART_CONFIG,
        ASSERTION_TYPE_ASSYMMETRIC_BINDING,
        ASSERTION_TYPE_INITIATOR_TOKEN,
        ASSERTION_TYPE_RECIPIENT_TOKEN,
        ASSERTION_TYPE_ENCRYPT_BEFORE_SIGNING,
        ASSERTION_TYPE_SIGN_BEFORE_ENCRYPTING,
        ASSERTION_TYPE_ENCRYPT_SIGNATURE,
        ASSERTION_TYPE_PROTECT_TOKENS,
        ASSERTION_TYPE_ONLY_SIGN_ENTIRE_HEADERS_AND_BODY,
        ASSERTION_TYPE_REQUIRE_KEY_IDENTIFIRE_REFERENCE,
        ASSERTION_TYPE_REQUIRE_ISSUER_SERIAL_REFERENCE,
        ASSERTION_TYPE_REQUIRE_EMBEDDED_TOKEN_REFERENCE,
        ASSERTION_TYPE_REQUIRE_THUMBPRINT_REFERENCE,
        ASSERTION_TYPE_WSS_X509_V1_TOKEN_10,
        ASSERTION_TYPE_WSS_X509_V3_TOKEN_10,
        ASSERTION_TYPE_SIGNED_ENCRYPTED_PARTS,
        ASSERTION_TYPE_UNKNOWN
    }neethi_assertion_type_t;

    typedef struct neethi_assertion_t neethi_assertion_t;

    AXIS2_EXTERN neethi_assertion_t *AXIS2_CALL
    neethi_assertion_create(const axutil_env_t *env);

    neethi_assertion_t *AXIS2_CALL
    neethi_assertion_create_with_args(const axutil_env_t *env,
        AXIS2_FREE_VOID_ARG free_func,
        void *value,
        neethi_assertion_type_t type);

    AXIS2_EXTERN void AXIS2_CALL
    neethi_assertion_free(neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env);

    AXIS2_EXTERN neethi_assertion_type_t AXIS2_CALL
    neethi_assertion_get_type(neethi_assertion_t *neethi_assertion,
            const axutil_env_t *env);

    AXIS2_EXTERN void *AXIS2_CALL
    neethi_assertion_get_value(
        neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_assertion_set_value(neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env,
        void *value,
        neethi_assertion_type_t type);

    AXIS2_EXTERN axiom_element_t *AXIS2_CALL
    neethi_assertion_get_element(
        neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_assertion_set_element(neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env,
        axiom_element_t *element);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_assertion_get_is_optional(
        neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_assertion_set_is_optional(neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env,
        axis2_bool_t is_optional);
        
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    neethi_assertion_get_policy_components(
        neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_assertion_add_policy_components(
        neethi_assertion_t *neethi_assertion,
        axutil_array_list_t *arraylist,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_assertion_add_operator(neethi_assertion_t *neethi_assertion,
        const axutil_env_t *env,
        neethi_operator_t *op);

    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    neethi_assertion_is_empty(neethi_assertion_t *neethi_assertion,
            const axutil_env_t *env);

    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    neethi_assertion_get_node(
            neethi_assertion_t *neethi_assertion,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_assertion_set_node(neethi_assertion_t *neethi_assertion,
            const axutil_env_t *env,
            axiom_node_t *node);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    neethi_assertion_serialize(
            neethi_assertion_t *assertion,
            axiom_node_t *parent,
            const axutil_env_t *env);
    


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* NEETHI_ASSERTION_H */
