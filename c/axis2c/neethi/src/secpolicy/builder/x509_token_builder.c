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

#include <rp_x509_token_builder.h>
#include <neethi_operator.h>
#include <neethi_policy.h>
#include <neethi_exactlyone.h>
#include <neethi_all.h>
#include <neethi_engine.h>

/*private functions*/

axis2_status_t AXIS2_CALL
x509_token_process_alternatives(
        const axutil_env_t *env,
        neethi_all_t *all,
        rp_x509_token_t *x509_token);

/***********************************/


AXIS2_EXTERN neethi_assertion_t *AXIS2_CALL 
rp_x509_token_builder_build(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)

{
    rp_x509_token_t *x509_token = NULL;
    neethi_policy_t *policy = NULL;
    axiom_node_t *child_node = NULL;
    axiom_element_t *child_element = NULL;
    axutil_array_list_t *alternatives = NULL;
    neethi_operator_t *component = NULL;
    neethi_all_t *all = NULL;
    axis2_char_t *inclusion_value = NULL;
    axutil_qname_t *qname = NULL;
    neethi_assertion_t *assertion = NULL;
    neethi_policy_t *normalized_policy = NULL;
    /*axutil_array_list_t *temp = NULL;*/

    x509_token = rp_x509_token_create(env);
    qname = axutil_qname_create(env,RP_INCLUDE_TOKEN,RP_SP_NS,RP_SP_PREFIX);

    inclusion_value = axiom_element_get_attribute_value(element,env,qname);

    axutil_qname_free(qname,env);
    qname = NULL;

    rp_x509_token_set_inclusion(x509_token,env,inclusion_value);
    
    child_node = axiom_node_get_first_element(node,env);

    if(axiom_node_get_node_type(child_node, env) == AXIOM_ELEMENT)
    {
        child_element = (axiom_element_t*)axiom_node_get_data_element(child_node, env);
        if(child_element)
        {
            policy = neethi_engine_get_policy(env, child_node, child_element);
            if(!policy)
            {
                return NULL;
            }
            normalized_policy = neethi_engine_get_normalize(env, AXIS2_FALSE, policy);
            neethi_policy_free(policy, env);
            policy = NULL;
            alternatives = neethi_policy_get_alternatives(normalized_policy, env);
            component = (neethi_operator_t *)axutil_array_list_get(alternatives, env, 0);            
            all = (neethi_all_t *)neethi_operator_get_value(component ,env);
            x509_token_process_alternatives(env, all, x509_token);
            
            assertion = neethi_assertion_create_with_args(env, (void *)rp_x509_token_free, x509_token, ASSERTION_TYPE_X509_TOKEN);

            neethi_policy_free(normalized_policy, env);
            normalized_policy = NULL;

            return assertion;
        }
        else return NULL;
    }
    else return NULL;
}

axis2_status_t AXIS2_CALL
x509_token_process_alternatives(
        const axutil_env_t *env,
        neethi_all_t *all,
        rp_x509_token_t *x509_token)
{
    neethi_operator_t *operator = NULL;
    axutil_array_list_t *arraylist = NULL;
    neethi_assertion_t *assertion = NULL;
    neethi_assertion_type_t type;    

    int i = 0;

    arraylist = neethi_all_get_policy_components(all, env);

    for(i=0; i<axutil_array_list_size(arraylist, env); i++)
    {
        operator = (neethi_operator_t *)axutil_array_list_get(arraylist, env, i);
        assertion = (neethi_assertion_t *)neethi_operator_get_value(operator, env);
        type = neethi_assertion_get_type(assertion, env);

        if(type == ASSERTION_TYPE_REQUIRE_KEY_IDENTIFIRE_REFERENCE)
        {
            rp_x509_token_set_require_key_identifier_reference(x509_token, env, AXIS2_TRUE);
        }
        else if(type == ASSERTION_TYPE_REQUIRE_ISSUER_SERIAL_REFERENCE)
        {
            rp_x509_token_set_require_issuer_serial_reference(x509_token, env, AXIS2_TRUE);
        }
        if(type == ASSERTION_TYPE_REQUIRE_EMBEDDED_TOKEN_REFERENCE)
        {
            rp_x509_token_set_require_embedded_token_reference(x509_token, env, AXIS2_TRUE);
        }
        else if(type == ASSERTION_TYPE_REQUIRE_THUMBPRINT_REFERENCE)
        {
            rp_x509_token_set_require_thumb_print_reference(x509_token, env, AXIS2_TRUE);
        }            
        else if(type == ASSERTION_TYPE_WSS_X509_V1_TOKEN_10)
        {
            rp_x509_token_set_token_version_and_type(x509_token, env, RP_WSS_X509_V1_TOKEN_10);
        }
        else if(type == ASSERTION_TYPE_WSS_X509_V3_TOKEN_10)
        {
            /*neethi_assertion_free(assertion, env);
            assertion = NULL;*/
            /*neethi_operator_free(operator, env);
            operator = NULL;*/
            rp_x509_token_set_token_version_and_type(x509_token, env, RP_WSS_X509_V3_TOKEN_10);
        }
        else return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}
