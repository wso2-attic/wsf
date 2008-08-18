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



#include "neethi_options.h"
#include <neethi_constants.h>
#include <rp_defines.h>


axiom_namespace_t *sp_ns;
axiom_namespace_t *wsp_ns;

struct neethi_options_t
{
    axis2_bool_t include_timestamp;
    axis2_bool_t is_username_token;
    axis2_bool_t token_protection;
    axis2_bool_t signature_protection;
    axis2_bool_t encrypt_before_sign;
    axis2_bool_t sign_body;
    axis2_bool_t encrypt_body;
    axis2_char_t *algorithmsuite;
    axis2_char_t *keyidentifier;
    axis2_bool_t server_side;
    axis2_char_t *binding;
    /*Sign and encrypt headers need to be added.*/
};


axis2_status_t
create_initiator_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node);

axis2_status_t
create_recipient_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node);

axis2_status_t
create_algo_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node);

axis2_status_t
create_layout_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node);

axis2_status_t
create_username_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node);

axis2_status_t
create_wss10_node(neethi_options_t *options,
               const axutil_env_t *env,
               axiom_node_t *parent_node);

axis2_status_t 
create_protection_node(
    neethi_options_t *options,
    const axutil_env_t *env,
    axiom_node_t *parent_node);



AXIS2_EXTERN neethi_options_t *AXIS2_CALL 
neethi_options_create(const axutil_env_t *env)
{
    neethi_options_t *options = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    options =  (neethi_options_t *) AXIS2_MALLOC (env->allocator,
    sizeof (neethi_options_t));

    if(options == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    options->include_timestamp = AXIS2_FALSE;
    options->is_username_token = AXIS2_FALSE;
    options->token_protection = AXIS2_FALSE;
    options->signature_protection = AXIS2_FALSE;
    options->encrypt_before_sign = AXIS2_FALSE;
    options->sign_body = AXIS2_FALSE;
    options->encrypt_body = AXIS2_FALSE;
    options->algorithmsuite = RP_ALGO_SUITE_BASIC256_RSA15;
    options->keyidentifier = NULL;
    options->server_side = AXIS2_FALSE;
    options->binding = RP_ASYMMETRIC_BINDING;

    return options;
}

AXIS2_EXTERN void AXIS2_CALL 
neethi_options_free(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(options)
    {
        AXIS2_FREE(env->allocator,options);           
        options = NULL;
    }
    return;
}


/* Implementations */
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
neethi_options_get_binding(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->binding;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_binding(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_char_t *binding)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->binding = binding; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_options_get_include_timestamp(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->include_timestamp;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_include_timestamp(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t include_timestamp)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->include_timestamp = include_timestamp; 
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_options_get_is_username_token(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->is_username_token;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_is_username_token(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t is_username_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->is_username_token = is_username_token; 
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_options_get_token_protection(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->token_protection;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_token_protection(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t token_protection)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->token_protection = token_protection; 
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_options_get_signature_protection(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->signature_protection;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_signature_protection(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t signature_protection)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->signature_protection = signature_protection; 
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_options_get_encrypt_before_sign(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->encrypt_before_sign;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_encrypt_before_sign(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t encrypt_before_sign)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->encrypt_before_sign = encrypt_before_sign; 
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_options_get_sign_body(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->sign_body;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_sign_body(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t sign_body)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->sign_body = sign_body; 
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_options_get_encrypt_body(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->encrypt_body;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_encrypt_body(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t encrypt_body)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->encrypt_body = encrypt_body; 
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_options_get_server_side(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return options->server_side;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_options_set_server_side(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t server_side)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    options->server_side = server_side;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
neethi_options_get_algorithmsuite(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->algorithmsuite;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_algorithmsuite(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_char_t *algorithmsuite)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->algorithmsuite = algorithmsuite; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
neethi_options_get_keyidentifier(
    neethi_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return options->keyidentifier;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_set_keyidentifier(
    neethi_options_t *options,
    const axutil_env_t *env,
    axis2_char_t *keyidentifier)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    options->keyidentifier = keyidentifier; 
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
neethi_options_get_root_node(
    neethi_options_t *options,
    const axutil_env_t *env)
{

    axiom_node_t *root_om_node = NULL;
    axiom_node_t* exact_om_node = NULL;
    axiom_node_t *all_om_node = NULL;

    axiom_element_t* root_om_ele = NULL;
    axiom_element_t * exact_om_ele = NULL;
    axiom_element_t *all_om_ele = NULL;

    axis2_status_t status = AXIS2_SUCCESS;

    sp_ns = NULL;
    wsp_ns = NULL;

    wsp_ns = axiom_namespace_create(env, NEETHI_NAMESPACE, NEETHI_PREFIX);
    sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);

    root_om_ele = axiom_element_create(env, NULL, NEETHI_POLICY, wsp_ns, &root_om_node);

    exact_om_ele = axiom_element_create(env, root_om_node, NEETHI_EXACTLYONE, wsp_ns, &exact_om_node);
    all_om_ele = axiom_element_create(env, exact_om_node, NEETHI_ALL, wsp_ns, &all_om_node);

    if(all_om_ele)
    {
        if(!axutil_strcmp(options->binding, RP_ASYMMETRIC_BINDING))
        {
            status = neethi_options_create_asym_node(options, env, all_om_node);
        }
        else
        {
            status = neethi_options_create_sym_node(options, env, all_om_node);
        }
        if(status != AXIS2_SUCCESS)
        {
            return NULL;
        }
        if(options->is_username_token)
        {
            status = create_username_node(options, env, all_om_node);
            if(status != AXIS2_SUCCESS)
            {
                return NULL;
            }
        }
        status = create_wss10_node(options, env, all_om_node);
        if(status != AXIS2_SUCCESS)
        {
            return NULL;
        }
        if(options->sign_body)/* Or if there are headers to be signed*/
        {    
            status = neethi_options_create_signed_parts_node(options, env, all_om_node);
            if(status != AXIS2_SUCCESS)
            {
                return NULL;
            }
        }    
        if(options->encrypt_body)/*Or if there are headers to be encrypt*/
        {    
            status = neethi_options_create_encrypted_parts_node(options, env, all_om_node);
            if(status != AXIS2_SUCCESS)
            {
                return NULL;
            }
        }    
        return root_om_node;
    }    
    else return NULL;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_options_create_asym_node(
    neethi_options_t *options,
    const axutil_env_t *env,
    axiom_node_t *parent_node)
{
    axiom_node_t *asymmetric_om_node = NULL;
    axiom_node_t *policy_asym_node = NULL;

    axiom_element_t *asymmetric_om_ele = NULL;

    axis2_status_t status = AXIS2_FAILURE;

    asymmetric_om_ele = axiom_element_create(env, parent_node, RP_ASYMMETRIC_BINDING, sp_ns, &asymmetric_om_node);
    if(!asymmetric_om_ele)
    {
        return AXIS2_FAILURE;
    }
    policy_asym_node = neethi_options_create_policy_node(env, asymmetric_om_node);
    if(!policy_asym_node)
    {
        return AXIS2_FAILURE;
    }
    status = create_initiator_node(options, env, policy_asym_node);      
    if(status != AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }
    status = create_recipient_node(options, env, policy_asym_node);
    if(status != AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }
    status = create_algo_node(options, env, policy_asym_node);
    if(status != AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }
    status = create_layout_node(options, env, policy_asym_node);
    if(status != AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }
    if(options->include_timestamp)
    {
        axiom_node_t *ts_node = NULL;
        axiom_element_t *ts_ele = NULL;

        /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
        ts_ele = axiom_element_create(env, policy_asym_node, RP_INCLUDE_TIMESTAMP, sp_ns, &ts_node);
        if(!ts_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    if(options->encrypt_before_sign)
    {
        axiom_node_t *ebs_node = NULL;
        axiom_element_t *ebs_ele = NULL;

        /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
        ebs_ele = axiom_element_create(env, policy_asym_node, RP_ENCRYPT_BEFORE_SIGNING, sp_ns, &ebs_node);
        if(!ebs_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    if(options->signature_protection)
    {
        axiom_node_t *sigpro_node = NULL;
        axiom_element_t *sigpro_ele = NULL;

        /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
        sigpro_ele = axiom_element_create(env, policy_asym_node, RP_ENCRYPT_SIGNATURE, sp_ns, &sigpro_node);
        if(!sigpro_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    if(options->token_protection)
    {
        axiom_node_t *tokpro_node = NULL;
        axiom_element_t *tokpro_ele = NULL;

        /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
        tokpro_ele = axiom_element_create(env, policy_asym_node, RP_PROTECT_TOKENS, sp_ns, &tokpro_node);
        if(!tokpro_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_options_create_sym_node(
    neethi_options_t *options,
    const axutil_env_t *env,
    axiom_node_t *parent_node)
{
    axiom_node_t *symmetric_om_node = NULL;
    axiom_node_t *policy_sym_node = NULL;

    axiom_element_t *symmetric_om_ele = NULL;

    axis2_status_t status = AXIS2_FAILURE;

    symmetric_om_ele = axiom_element_create(env, parent_node, RP_SYMMETRIC_BINDING, sp_ns, &symmetric_om_node);
    if(!symmetric_om_ele)
    {
        return AXIS2_FAILURE;
    }
    policy_sym_node = neethi_options_create_policy_node(env, symmetric_om_node);
    if(!policy_sym_node)
    {
        return AXIS2_FAILURE;
    }
    status = create_protection_node(options, env, policy_sym_node);      
    if(status != AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }

    status = create_algo_node(options, env, policy_sym_node);
    if(status != AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }
    status = create_layout_node(options, env, policy_sym_node);
    if(status != AXIS2_SUCCESS)
    {
        return AXIS2_FAILURE;
    }
    if(options->include_timestamp)
    {
        axiom_node_t *ts_node = NULL;
        axiom_element_t *ts_ele = NULL;

        /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
        ts_ele = axiom_element_create(env, policy_sym_node, RP_INCLUDE_TIMESTAMP, sp_ns, &ts_node);
        if(!ts_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    if(options->encrypt_before_sign)
    {
        axiom_node_t *ebs_node = NULL;
        axiom_element_t *ebs_ele = NULL;

        /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
        ebs_ele = axiom_element_create(env, policy_sym_node, RP_ENCRYPT_BEFORE_SIGNING, sp_ns, &ebs_node);
        if(!ebs_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    if(options->signature_protection)
    {
        axiom_node_t *sigpro_node = NULL;
        axiom_element_t *sigpro_ele = NULL;

        /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
        sigpro_ele = axiom_element_create(env, policy_sym_node, RP_ENCRYPT_SIGNATURE, sp_ns, &sigpro_node);
        if(!sigpro_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    if(options->token_protection)
    {
        axiom_node_t *tokpro_node = NULL;
        axiom_element_t *tokpro_ele = NULL;

        /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
        tokpro_ele = axiom_element_create(env, policy_sym_node, RP_PROTECT_TOKENS, sp_ns, &tokpro_node);
        if(!tokpro_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
neethi_options_create_policy_node(
    const axutil_env_t *env,
    axiom_node_t *parent_node)
{

    axiom_node_t *policy_node = NULL;
    axiom_element_t *policy_ele = NULL;
    /*axiom_namespace_t *wsp_ns = NULL;*/

    /*wsp_ns = axiom_namespace_create(env, NEETHI_NAMESPACE, NEETHI_PREFIX);*/
    policy_ele = axiom_element_create(env, parent_node, NEETHI_POLICY, wsp_ns, &policy_node);

    return policy_node;

}

axis2_status_t 
create_initiator_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node)
{
    axiom_node_t *in_token_node = NULL;
    axiom_node_t *in_policy_node = NULL;
    axiom_node_t *x509_node = NULL;
    axiom_node_t *x509_policy_node = NULL;
    axiom_node_t *x509_type_node = NULL;
    axiom_element_t *parent_ele = NULL;

    axiom_element_t *in_token_ele = NULL;
    axiom_element_t *x509_ele = NULL;

    axiom_attribute_t *attr = NULL;

    /*axiom_namespace_t *sp_ns = NULL;*/

    /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
    parent_ele = axiom_node_get_data_element(parent_node, env);
    if(!parent_ele)
    {
        return AXIS2_FAILURE;
    }    

    /*sp_ns = axiom_element_find_namespace(
            parent_ele, env, parent_node, RP_SP_NS_12, RP_SP_PREFIX);   */

    in_token_ele = axiom_element_create(env, parent_node, RP_INITIATOR_TOKEN, sp_ns, &in_token_node);
    if(!in_token_ele)
    {
        return AXIS2_FAILURE;
    }
    
    in_policy_node = neethi_options_create_policy_node(env, in_token_node);

    x509_ele = axiom_element_create(env, in_policy_node, RP_X509_TOKEN, sp_ns, &x509_node);

    if(!x509_ele)
    {
        return AXIS2_FAILURE;
    }

    attr = axiom_attribute_create(env, RP_INCLUDE_TOKEN,  RP_INCLUDE_ALWAYS_TO_RECIPIENT,
                                  sp_ns);
    axiom_element_add_attribute(x509_ele, env, attr, x509_node);
    x509_policy_node = neethi_options_create_policy_node(env, x509_node);

    if(x509_policy_node)
    {
        if(options->keyidentifier && options->server_side)
        {
            axiom_node_t *key_identifier_node = NULL;
            axiom_element_create(env, x509_policy_node, options->keyidentifier, sp_ns, &key_identifier_node);
        }
    }

    axiom_element_create(env, x509_policy_node, RP_WSS_X509_V3_TOKEN_10, sp_ns, &x509_type_node);
    return AXIS2_SUCCESS;
}


axis2_status_t 
create_recipient_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node)
{
    axiom_node_t *rec_token_node = NULL;
    axiom_node_t *rec_policy_node = NULL;
    axiom_node_t *x509_node = NULL;
    axiom_node_t *x509_policy_node = NULL;
    axiom_node_t *x509_type_node = NULL;

    axiom_element_t *rec_token_ele = NULL;
    axiom_element_t *x509_ele = NULL;
    axiom_element_t *parent_ele = NULL;

    axiom_attribute_t *attr = NULL;

    /*axiom_namespace_t *sp_ns = NULL;*/

    /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/

    parent_ele = axiom_node_get_data_element(parent_node, env);
    if(!parent_ele)
    {
        return AXIS2_FAILURE;
    }

    /*sp_ns = axiom_element_find_namespace(
            parent_ele, env, parent_node, RP_SP_NS_12, RP_SP_PREFIX);*/
    

    rec_token_ele = axiom_element_create(env, parent_node, RP_RECIPIENT_TOKEN, sp_ns, &rec_token_node);
    if(!rec_token_ele)
    {
        return AXIS2_FAILURE;
    }
    
    rec_policy_node = neethi_options_create_policy_node(env, rec_token_node);

    x509_ele = axiom_element_create(env, rec_policy_node, RP_X509_TOKEN, sp_ns, &x509_node);

    if(!x509_ele)
    {
        return AXIS2_FAILURE;
    }

    attr = axiom_attribute_create(env, RP_INCLUDE_TOKEN,  RP_INCLUDE_NEVER,
                                  sp_ns);
    axiom_element_add_attribute(x509_ele, env, attr, x509_node);
    x509_policy_node = neethi_options_create_policy_node(env, x509_node);
    if(x509_policy_node)
    {
        if(options->keyidentifier && !(options->server_side))
        {
            axiom_node_t *key_identifier_node = NULL;
            axiom_element_create(env, x509_policy_node, options->keyidentifier, sp_ns, &key_identifier_node);
        }
        axiom_element_create(env, x509_policy_node, RP_WSS_X509_V3_TOKEN_10, sp_ns, &x509_type_node);
        return AXIS2_SUCCESS;
    }
    else return AXIS2_FAILURE;
}

axis2_status_t 
create_protection_node(
    neethi_options_t *options,
    const axutil_env_t *env,
    axiom_node_t *parent_node)
{
    axiom_node_t *in_token_node = NULL;
    axiom_node_t *in_policy_node = NULL;
    axiom_node_t *x509_node = NULL;
    axiom_node_t *x509_policy_node = NULL;
    axiom_node_t *x509_type_node = NULL;
    axiom_element_t *parent_ele = NULL;

    axiom_element_t *in_token_ele = NULL;
    axiom_element_t *x509_ele = NULL;

    axiom_attribute_t *attr = NULL;

    parent_ele = axiom_node_get_data_element(parent_node, env);
    if(!parent_ele)
    {
        return AXIS2_FAILURE;
    }    

    in_token_ele = axiom_element_create(env, parent_node, RP_PROTECTION_TOKEN, sp_ns, &in_token_node);
    if(!in_token_ele)
    {
        return AXIS2_FAILURE;
    }
    
    in_policy_node = neethi_options_create_policy_node(env, in_token_node);

    x509_ele = axiom_element_create(env, in_policy_node, RP_X509_TOKEN, sp_ns, &x509_node);

    if(!x509_ele)
    {
        return AXIS2_FAILURE;
    }

    attr = axiom_attribute_create(env, RP_INCLUDE_TOKEN,  RP_INCLUDE_ALWAYS_TO_RECIPIENT,
                                  sp_ns);
    axiom_element_add_attribute(x509_ele, env, attr, x509_node);
    x509_policy_node = neethi_options_create_policy_node(env, x509_node);

    if(x509_policy_node)
    {
        if(options->keyidentifier && options->server_side)
        {
            axiom_node_t *key_identifier_node = NULL;
            axiom_element_create(env, x509_policy_node, options->keyidentifier, sp_ns, &key_identifier_node);
        }
    }

    axiom_element_create(env, x509_policy_node, RP_WSS_X509_V3_TOKEN_10, sp_ns, &x509_type_node);
    return AXIS2_SUCCESS;
}

axis2_status_t 
create_algo_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node)
{
    axiom_node_t *algo_node = NULL;
    axiom_node_t *algo_policy_node = NULL;
    axiom_node_t *algo_name_node = NULL;

    axiom_element_t *algo_ele = NULL;
    axiom_element_t *algo_name_ele = NULL;

    /*axiom_namespace_t *sp_ns = NULL;*/

    /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/

    algo_ele = axiom_element_create(env, parent_node, RP_ALGORITHM_SUITE, sp_ns, &algo_node);
    if(!algo_ele)
    {
        return AXIS2_FAILURE;
    }
    
    algo_policy_node = neethi_options_create_policy_node(env, algo_node);

    if(options->algorithmsuite)
    {
        algo_name_ele = axiom_element_create(env, algo_policy_node, options->algorithmsuite, sp_ns, &algo_name_node);
        if(!algo_name_ele)
        {
            return AXIS2_FAILURE;
        }
    }
    else
    {
        return AXIS2_FAILURE;
    }        
    return AXIS2_SUCCESS;
}

axis2_status_t 
create_layout_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node)
{
    axiom_node_t *layout_node = NULL;
    axiom_node_t *layout_policy_node = NULL;
    axiom_node_t *layout_name_node = NULL;

    axiom_element_t *layout_ele = NULL;
    axiom_element_t *layout_name_ele = NULL;

    /*axiom_namespace_t *sp_ns = NULL;*/

    /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/

    layout_ele = axiom_element_create(env, parent_node, RP_LAYOUT, sp_ns, &layout_node);
    if(!layout_ele)
    {
        return AXIS2_FAILURE;
    }
    
    layout_policy_node = neethi_options_create_policy_node(env, layout_node);

    layout_name_ele = axiom_element_create(env, layout_policy_node, RP_LAYOUT_STRICT, sp_ns, &layout_name_node);
    if(!layout_name_ele)
    {
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t 
create_username_node(neethi_options_t *options,
                       const axutil_env_t *env,
                       axiom_node_t *parent_node)
{
    axiom_node_t *signsupport_node = NULL;
    axiom_node_t *signsupport_policy_node = NULL;
    axiom_node_t *ut_node = NULL;

    axiom_element_t *ut_ele = NULL;
    axiom_attribute_t *attr = NULL;
    /*axiom_namespace_t *sp_ns = NULL;*/

    /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
    axiom_element_create(env, parent_node, RP_SIGNED_SUPPORTING_TOKENS, sp_ns, &signsupport_node);
    signsupport_policy_node = neethi_options_create_policy_node(env, signsupport_node);
    ut_ele = axiom_element_create(env, signsupport_policy_node, RP_USERNAME_TOKEN, sp_ns, &ut_node);
    if(ut_ele)
    {
        attr = axiom_attribute_create(env, RP_INCLUDE_TOKEN,  RP_INCLUDE_ALWAYS,
                                  sp_ns);
        axiom_element_add_attribute(ut_ele, env, attr, ut_node);
    }
    else
    {
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

axis2_status_t 
create_wss10_node(neethi_options_t *options,
               const axutil_env_t *env,
               axiom_node_t *parent_node)
{

    axiom_node_t *wss10_node = NULL;
    axiom_node_t *wss10_policy_node = NULL;
    axiom_node_t *must_key_node = NULL;
    axiom_node_t *must_issuer_node = NULL;
    axiom_node_t *must_embedded_node = NULL;

    /*axiom_namespace_t *sp_ns = NULL;*/
    axiom_element_t *wss10_ele = NULL;

    /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
    wss10_ele = axiom_element_create(env, parent_node, RP_WSS10, sp_ns, &wss10_node);
    if(wss10_ele)
    {
        wss10_policy_node = neethi_options_create_policy_node(env, wss10_node);
        if(wss10_policy_node)
        {
            axiom_element_create(env, wss10_policy_node, RP_MUST_SUPPORT_REF_KEY_IDENTIFIER, sp_ns, &must_key_node);
            axiom_element_create(env, wss10_policy_node, RP_MUST_SUPPORT_REF_ISSUER_SERIAL, sp_ns, &must_issuer_node);
            axiom_element_create(env, wss10_policy_node, RP_MUST_SUPPORT_REF_EMBEDDED_TOKEN, sp_ns, &must_embedded_node);

            return AXIS2_SUCCESS;
        }
        else return AXIS2_FAILURE;
    }
    else return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_create_signed_parts_node(
    neethi_options_t *options,
    const axutil_env_t *env,
    axiom_node_t *parent_node)
{

    axiom_node_t *signed_parts_node = NULL;
    axiom_node_t *body_node = NULL;
    
    /*axiom_namespace_t *sp_ns = NULL;*/
    axiom_element_t *signed_parts_ele = NULL;

    /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
    signed_parts_ele = axiom_element_create(env, parent_node, RP_SIGNED_PARTS, sp_ns, &signed_parts_node);
    if(signed_parts_ele)
    {
        if(options->sign_body)
        {
            axiom_element_t *ele = NULL;
            ele = axiom_element_create(env, signed_parts_node, RP_BODY, sp_ns, &body_node);
            return AXIS2_SUCCESS;
        }
        /*Adding Signed headers logic should come here*/
        else return AXIS2_FAILURE;
    }
    else return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_options_create_encrypted_parts_node(
        neethi_options_t *options,
        const axutil_env_t *env,
        axiom_node_t *parent_node)
{

    axiom_node_t *encrypted_parts_node = NULL;
    axiom_node_t *body_node = NULL;
    
    /*axiom_namespace_t *sp_ns = NULL;*/
    axiom_element_t *encrypted_parts_ele = NULL;

    /*sp_ns = axiom_namespace_create(env, RP_SP_NS_12, RP_SP_PREFIX);*/
    encrypted_parts_ele = axiom_element_create(env, parent_node, RP_ENCRYPTED_PARTS, sp_ns, &encrypted_parts_node);
    if(encrypted_parts_ele)
    {
        if(options->encrypt_body)
        {
            axiom_element_t *ele = NULL;
            ele = axiom_element_create(env, encrypted_parts_node, RP_BODY, sp_ns, &body_node);
            return AXIS2_SUCCESS;
        }
        /*Adding Encrypted headers logic should come here*/
        else return AXIS2_FAILURE;
    }
    else return AXIS2_FAILURE;
}


