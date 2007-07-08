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

#include <rp_wss10_builder.h>
#include <neethi_operator.h>
#include <neethi_policy.h>
#include <neethi_exactlyone.h>
#include <neethi_all.h>
#include <neethi_engine.h>

/*private functions*/

axis2_status_t AXIS2_CALL
wss10_process_alternatives(
        const axutil_env_t *env,
        neethi_all_t *all,
        rp_wss10_t *wss10);

/***********************************/


AXIS2_EXTERN neethi_assertion_t *AXIS2_CALL 
rp_wss10_builder_build(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)

{
    rp_wss10_t *wss10 = NULL;
    neethi_policy_t *policy = NULL;
    axiom_node_t *child_node = NULL;
    axiom_element_t *child_element = NULL;
    axutil_array_list_t *alternatives = NULL;
    neethi_operator_t *component = NULL;
    neethi_all_t *all = NULL;
    neethi_assertion_t *assertion = NULL;
    neethi_policy_t *normalized_policy = NULL;

    wss10 = rp_wss10_create(env);

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
            wss10_process_alternatives(env, all, wss10);

            assertion = neethi_assertion_create_with_args(env, (void *)rp_wss10_free, wss10, ASSERTION_TYPE_WSS10);

            neethi_policy_free(normalized_policy, env);
            normalized_policy = NULL;

            return assertion;
        }
        else return NULL;
    }
    else return NULL;
}

axis2_status_t AXIS2_CALL
wss10_process_alternatives(
        const axutil_env_t *env,
        neethi_all_t *all,
        rp_wss10_t *wss10)
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

        if(type == ASSERTION_TYPE_MUST_SUPPORT_REF_KEY_IDENTIFIER)
        {
            rp_wss10_set_must_support_ref_key_identifier(wss10,env,AXIS2_TRUE);
        }
        else if(type == ASSERTION_TYPE_MUST_SUPPORT_REF_ISSUER_SERIAL)
        {
            rp_wss10_set_must_support_ref_issuer_serial(wss10,env,AXIS2_TRUE);
        }
        else if(type == ASSERTION_TYPE_MUST_SUPPORT_REF_EXTERNAL_URI)
        {
            rp_wss10_set_must_support_ref_external_uri(wss10,env,AXIS2_TRUE);
        }
        else if(type == ASSERTION_TYPE_MUST_SUPPORT_REF_EMBEDDED_TOKEN)
        {
            rp_wss10_set_must_support_ref_embedded_token(wss10,env,AXIS2_TRUE);
        }                
        else return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}
