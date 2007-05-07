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


#include <rp_username_token_builder.h>

AXIS2_EXTERN rp_username_token_t *AXIS2_CALL
rp_username_token_builder_build(
            const axutil_env_t *env,
            axiom_node_t *username,
            axiom_element_t *username_ele)
{
    rp_username_token_t *username_token = NULL;
    axiom_node_t *policy = NULL;
    axiom_element_t *pol_ele = NULL;
    axis2_status_t status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env,NULL);

    username_token = rp_username_token_create(env);
    if(!username_token)
        return NULL;

    status = rp_username_token_builder_set_inclusion_value(env,username_token,username_ele);
    if(status != AXIS2_SUCCESS )
    {
        rp_username_token_free(username_token,env);
        username_token = NULL;
        return NULL;
    }
    policy = axiom_node_get_first_element(username,env);
    if(!policy) 
        return username_token;

    if(axiom_node_get_node_type(policy, env) == AXIOM_ELEMENT)
    {
        pol_ele = (axiom_element_t*)axiom_node_get_data_element(policy, env);
        if(pol_ele)
        {
            axiom_children_iterator_t *children_iter = NULL;
            children_iter = axiom_element_get_children(pol_ele, env, policy);
            if(children_iter )
            {
                while(axiom_children_iterator_has_next(children_iter, env))
                {
                    axiom_node_t *node = NULL;
                    axiom_element_t *ele = NULL;
                    axis2_char_t *local_name = NULL;
                    node = axiom_children_iterator_next(children_iter, env);
                    if(node)
                    {
                        if(axiom_node_get_node_type(node, env) == AXIOM_ELEMENT)
                        {
                            ele = (axiom_element_t*)axiom_node_get_data_element(node, env);
                            if(ele)
                            {
                                local_name = axiom_element_get_localname(ele,env);
                                if(local_name)
                                {
                                    status = rp_username_token_builder_set_properties(node,ele,local_name,username_token,env);
                                    if(status != AXIS2_SUCCESS)
                                    {
                                        rp_username_token_free(username_token,env);
                                        username_token = NULL;
                                        break;
                                    }
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return username_token;
}            

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_username_token_builder_set_inclusion_value(
        const axutil_env_t *env,
        rp_username_token_t *token,
        axiom_element_t *element)
{
    axis2_char_t *inclusion_value = NULL;
    axutil_qname_t *qname = NULL;

	AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    qname = axutil_qname_create(env,RP_INCLUDE_TOKEN,RP_SP_NS,RP_SP_PREFIX);
    if(!qname)
        return AXIS2_FAILURE;
    
    inclusion_value = axiom_element_get_attribute_value(element,env,qname);
            
    axutil_qname_free(qname,env);
    qname = NULL;         

    return rp_username_token_set_inclusion(token,env,inclusion_value);    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_username_token_builder_set_properties(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *local_name,
        rp_username_token_t *username_token,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    if(strcmp(local_name,RP_WSS_USERNAME_TOKEN_10)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_WSS_USERNAME_TOKEN_10,node,element))
        {
            rp_username_token_set_useUTprofile10(username_token,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(local_name,RP_WSS_USERNAME_TOKEN_11)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_WSS_USERNAME_TOKEN_11,node,element))
        {
            rp_username_token_set_useUTprofile11(username_token,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(local_name,RP_REQUIRE_DERIVED_KEYS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_REQUIRE_DERIVED_KEYS,node,element))
        {
            rp_username_token_set_derivedkeys(username_token,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}
