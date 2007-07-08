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

#include <rp_supporting_tokens_builder.h>
#include <neethi_operator.h>
#include <neethi_policy.h>
#include <neethi_exactlyone.h>
#include <neethi_all.h>
#include <neethi_engine.h>

/*private functions*/

axis2_status_t AXIS2_CALL
supporting_tokens_process_alternatives(
        const axutil_env_t *env,
        neethi_all_t *all,
        rp_supporting_tokens_t *supporting_tokens);


axis2_bool_t AXIS2_CALL is_token_assertion(
        const axutil_env_t *env,
        neethi_assertion_type_t type);


/***********************************/


AXIS2_EXTERN neethi_assertion_t *AXIS2_CALL 
rp_supporting_tokens_builder_build(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)

{
    rp_supporting_tokens_t *supporting_tokens = NULL;
    neethi_policy_t *policy = NULL;
    axiom_node_t *child_node = NULL;
    axiom_element_t *child_element = NULL;
    axutil_array_list_t *alternatives = NULL;
    neethi_operator_t *component = NULL;
    neethi_all_t *all = NULL;
    neethi_assertion_t *assertion = NULL;
    axis2_char_t *local_name = NULL;
    neethi_policy_t *normalized_policy = NULL;

    supporting_tokens = rp_supporting_tokens_create(env);
    local_name = axiom_element_get_localname(element, env);

    if(local_name)
    {
        if(axutil_strcmp(local_name, RP_SIGNED_SUPPORTING_TOKENS) == 0)
        {
            rp_supporting_tokens_set_type(supporting_tokens, env, RP_SUPPORTING_SIGNED_SUPPORTING);
        }
        else if(axutil_strcmp(local_name, RP_SIGNED_ENDORSING_SUPPORTING_TOKENS)==0)
        {
            rp_supporting_tokens_set_type(supporting_tokens, env, RP_SUPPORTING_SIGNED_ENDORSING_SUPPORTING);
        } 
        else return NULL;
    }        
    else return NULL;

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
            normalized_policy = neethi_engine_get_normalize(env, AXIS2_FALSE,policy);
            alternatives = neethi_policy_get_alternatives(normalized_policy, env);
            neethi_policy_free(policy, env);
            policy = NULL;
            component = (neethi_operator_t *)axutil_array_list_get(alternatives, env, 0);            
            all = (neethi_all_t *)neethi_operator_get_value(component ,env);
            supporting_tokens_process_alternatives(env, all, supporting_tokens);

            assertion = neethi_assertion_create_with_args(env, (void *)rp_supporting_tokens_free, supporting_tokens, ASSERTION_TYPE_SUPPORTING_TOKENS);
            
            neethi_policy_free(normalized_policy, env);
            normalized_policy = NULL;
                        
            return assertion;
        }
        else return NULL;
    }
    else return NULL;
}

axis2_status_t AXIS2_CALL
supporting_tokens_process_alternatives(
        const axutil_env_t *env,
        neethi_all_t *all,
        rp_supporting_tokens_t *supporting_tokens)
{
    neethi_operator_t *operator = NULL;
    axutil_array_list_t *arraylist = NULL;
    neethi_assertion_t *assertion = NULL;
    neethi_assertion_type_t type;    
    void *value = NULL;

    int i = 0;

    arraylist = neethi_all_get_policy_components(all, env);

    for(i=0; i<axutil_array_list_size(arraylist, env); i++)
    {
        operator = (neethi_operator_t *)axutil_array_list_get(arraylist, env, i);
        assertion = (neethi_assertion_t *)neethi_operator_get_value(operator, env);
        value = neethi_assertion_get_value(assertion, env);
        type = neethi_assertion_get_type(assertion, env);

        if(value)
        {
            if(type == ASSERTION_TYPE_ALGORITHM_SUITE)
            {
                rp_algorithmsuite_t *algorithmsuite = NULL;
                algorithmsuite = (rp_algorithmsuite_t *)neethi_assertion_get_value(assertion, env);
                if(algorithmsuite)
                {
                    rp_supporting_tokens_set_algorithmsuite(supporting_tokens, env, algorithmsuite);
                }
                else return AXIS2_FAILURE;
            }
            else if(is_token_assertion(env, type))
            {
                rp_property_t *token = NULL;
                token = rp_property_create(env);
                rp_token_identifier_set_token(token, assertion, env);
                rp_supporting_tokens_add_token(supporting_tokens, env, token);                                
            }
            else return AXIS2_FAILURE;
        }        
        else return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}


axis2_bool_t AXIS2_CALL is_token_assertion(
        const axutil_env_t *env,
        neethi_assertion_type_t type)
{

    if(type == ASSERTION_TYPE_USERNAME_TOKEN)
    {
        return AXIS2_TRUE;
    }
    else if(type == ASSERTION_TYPE_X509_TOKEN)
    {
        return AXIS2_TRUE;
    }
    else return AXIS2_FALSE;
}

