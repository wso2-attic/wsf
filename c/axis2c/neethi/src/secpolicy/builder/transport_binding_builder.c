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

#include <rp_transport_binding_builder.h>
#include <neethi_operator.h>
#include <neethi_policy.h>
#include <neethi_exactlyone.h>
#include <neethi_all.h>
#include <neethi_engine.h>

/*private functions*/

axis2_status_t AXIS2_CALL
transport_binding_process_alternatives(
        const axutil_env_t *env,
        neethi_all_t *all,
        rp_transport_binding_t *transport_binding);

/***********************************/


AXIS2_EXTERN neethi_assertion_t *AXIS2_CALL 
rp_transport_binding_builder_build(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)

{
    rp_transport_binding_t *transport_binding = NULL;
    neethi_policy_t *policy = NULL;
    axiom_node_t *child_node = NULL;
    axiom_element_t *child_element = NULL;
    axutil_array_list_t *alternatives = NULL;
    neethi_operator_t *component = NULL;
    neethi_all_t *all = NULL;
    neethi_assertion_t *assertion = NULL;
    neethi_policy_t *normalized_policy = NULL;

    transport_binding = rp_transport_binding_create(env);
    
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
            transport_binding_process_alternatives(env, all, transport_binding);

            assertion = neethi_assertion_create_with_args(env, (void *)rp_transport_binding_free, transport_binding, ASSERTION_TYPE_TRANSPORT_BINDING);
            
            neethi_policy_free(normalized_policy, env);
            normalized_policy = NULL;

            return assertion;
        }
        else return NULL;
    }
    else return NULL;
}

axis2_status_t AXIS2_CALL
transport_binding_process_alternatives(
        const axutil_env_t *env,
        neethi_all_t *all,
        rp_transport_binding_t *transport_binding)
{

    neethi_operator_t *operator = NULL;
    axutil_array_list_t *arraylist = NULL;
    neethi_assertion_t *assertion = NULL;
    neethi_assertion_type_t type;    
    void *value = NULL;
    rp_binding_commons_t *commons = NULL;

    int i = 0;

    arraylist = neethi_all_get_policy_components(all, env);
    commons = rp_binding_commons_create(env);    

    for(i=0; i<axutil_array_list_size(arraylist, env); i++)
    {
        operator = (neethi_operator_t *)axutil_array_list_get(arraylist, env, i);
        assertion = (neethi_assertion_t *)neethi_operator_get_value(operator, env);
        value = neethi_assertion_get_value(assertion, env);
        type = neethi_assertion_get_type(assertion, env);

        if(type == ASSERTION_TYPE_TRANSPORT_TOKEN)
        {
            rp_property_t *transport_token = NULL;    
            transport_token = (rp_property_t *)neethi_assertion_get_value(assertion, env);
            if(transport_token)
            {
                rp_transport_binding_set_transport_token(transport_binding, env, transport_token);
            }
            else return AXIS2_FAILURE;
        }
        else if(type == ASSERTION_TYPE_ALGORITHM_SUITE)
        {
            rp_algorithmsuite_t *algorithmsuite = NULL;
            algorithmsuite = (rp_algorithmsuite_t *)neethi_assertion_get_value(assertion, env);
            if(algorithmsuite)
            {
                rp_binding_commons_set_algorithmsuite(commons, env, algorithmsuite);
            }                
            else return AXIS2_FAILURE;
        }
        else if(type == ASSERTION_TYPE_INCLUDE_TIMESTAMP)
        {
            rp_binding_commons_set_include_timestamp(commons, env, AXIS2_TRUE);
        }
        else if(type == ASSERTION_TYPE_LAYOUT)
        {
            rp_layout_t *layout = NULL;
            layout = (rp_layout_t *)neethi_assertion_get_value(assertion, env);
            if(layout)
            {
                rp_binding_commons_set_layout(commons, env, layout);
            }                    
            else return AXIS2_FAILURE;
        }
        else if(type == ASSERTION_TYPE_SUPPORTING_TOKENS)
        {
            rp_supporting_tokens_t *supporting_tokens = NULL;
            supporting_tokens = (rp_supporting_tokens_t *)neethi_assertion_get_value(assertion, env);
            if(supporting_tokens)
            {
                int type = 0;
                type = rp_supporting_tokens_get_type(supporting_tokens, env);
                if(type == RP_SUPPORTING_SIGNED_SUPPORTING)
                {
                    rp_binding_commons_set_signed_supporting_tokens(commons, env, supporting_tokens);
                }    
                else if(type == RP_SUPPORTING_SIGNED_ENDORSING_SUPPORTING)
                {
                    rp_binding_commons_set_signed_endorsing_supporting_tokens(commons, env, supporting_tokens);
                }                       
                else return AXIS2_FAILURE;
            }                    
            else return AXIS2_FAILURE;
        }
        else return AXIS2_FAILURE;
    }

    rp_transport_binding_set_binding_commons(transport_binding, env, commons);
    return AXIS2_SUCCESS;
}
