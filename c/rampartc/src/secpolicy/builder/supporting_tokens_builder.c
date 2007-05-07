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

AXIS2_EXTERN rp_supporting_tokens_t *AXIS2_CALL 
rp_supporting_tokens_builder_build(const axutil_env_t *env, axiom_node_t *supporting)
  
{
    rp_supporting_tokens_t *supporting_tokens = NULL;
    axiom_element_t *pol_ele = NULL;
    axiom_node_t *policy = NULL;
    rp_property_t *property = NULL;
    axis2_status_t status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env, NULL);

    if(supporting)
    {
        policy = axiom_node_get_first_element(supporting,env);

        if(axiom_node_get_node_type(policy, env) == AXIOM_ELEMENT)
        {
            pol_ele = (axiom_element_t*)axiom_node_get_data_element(policy, env);

            supporting_tokens = rp_supporting_tokens_create(env);
            if(!supporting_tokens)
                return NULL;

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
                                        if(rp_supporting_tokens_builder_istoken(env,local_name))
                                        {
                                            property = rp_property_create(env);
                                            if(!property)
                                                return NULL;
                                            status = rp_token_builder_set_token(node,ele,local_name,property,env);
                                            if(status!=AXIS2_SUCCESS)
                                            {
                                                rp_property_free(property,env);
                                                property = NULL;
                                                return NULL; 
                                            }
                                            status = rp_supporting_tokens_add_token(supporting_tokens,env,property);  
                                            if(status!=AXIS2_SUCCESS)
                                            {
                                                rp_property_free(property,env);
                                                property = NULL;
                                                return NULL;
                                            }
                                        }
                                        else
                                        {
                                            status = rp_supporting_tokens_builder_set_other_properties(env,supporting_tokens,node,ele,local_name);
                                            if(status!=AXIS2_SUCCESS)
                                                return NULL;
                                        }
                                            
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return supporting_tokens;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_supporting_tokens_builder_set_other_properties(
            const axutil_env_t *env,
            rp_supporting_tokens_t *supporting_tokens,
            axiom_node_t *node,
            axiom_element_t *element,
            axis2_char_t *local_name)    
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);
    
    if(axutil_strcmp(local_name,RP_ALGORITHM_SUITE)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGORITHM_SUITE,node,element))
        {
            rp_algorithmsuite_t *algorithmsuite = NULL;
            algorithmsuite = rp_algorithmsuite_builder_build(env,node);
            if(!algorithmsuite)
                return AXIS2_FAILURE;

            return rp_supporting_tokens_set_algorithmsuite(supporting_tokens,env,algorithmsuite);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_SIGNED_PARTS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SIGNED_PARTS,node,element))
        {
            rp_signed_encrypted_parts_t *signed_parts = NULL;
            signed_parts = rp_signed_encrypted_parts_builder_build(env,node);
            if(!signed_parts)
                return AXIS2_FAILURE;
            
            rp_signed_encrypted_parts_set_signedparts(signed_parts,env,AXIS2_TRUE);

            return rp_supporting_tokens_set_signed_parts(supporting_tokens,env,signed_parts);
        }
        else
            return AXIS2_FAILURE;
    }    
    else if(axutil_strcmp(local_name,RP_SIGNED_ELEMENTS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SIGNED_ELEMENTS,node,element))
        {
            rp_signed_encrypted_elements_t *signed_elements = NULL;
            signed_elements = rp_signed_encrypted_elements_builder_build(env,node);
            if(!signed_elements)
                return AXIS2_FAILURE;
            
            rp_signed_encrypted_elements_set_signedelements(signed_elements,env,AXIS2_TRUE);

            return rp_supporting_tokens_set_signed_elements(supporting_tokens,env,signed_elements);
        }
        else
            return AXIS2_FAILURE;

    }
    else if(axutil_strcmp(local_name,RP_ENCRYPTED_PARTS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ENCRYPTED_PARTS,node,element))
        {
            rp_signed_encrypted_parts_t *encrypted_parts = NULL;
            encrypted_parts = rp_signed_encrypted_parts_builder_build(env,node);
            if(!encrypted_parts)
                return AXIS2_FAILURE;

            rp_signed_encrypted_parts_set_signedparts(encrypted_parts,env,AXIS2_FALSE);

            return rp_supporting_tokens_set_encrypted_parts(supporting_tokens,env,encrypted_parts);
        }
        else
            return AXIS2_FAILURE;
            
    }
    else if(axutil_strcmp(local_name,RP_ENCRYPTED_ELEMENTS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ENCRYPTED_ELEMENTS,node,element))
        {
            rp_signed_encrypted_elements_t *encrypted_elements = NULL;
            encrypted_elements = rp_signed_encrypted_elements_builder_build(env,node);
            if(!encrypted_elements)
                return AXIS2_FAILURE;

            rp_signed_encrypted_elements_set_signedelements(encrypted_elements,env,AXIS2_FALSE);

            return rp_supporting_tokens_set_encrypted_elements(supporting_tokens,env,encrypted_elements);
        }
        else
            return AXIS2_FAILURE;
    }
    else return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
rp_supporting_tokens_builder_istoken(
        const axutil_env_t *env,
        axis2_char_t *local_name)
{
    AXIS2_ENV_CHECK(env,AXIS2_FALSE);

    if(axutil_strcmp(local_name,RP_USERNAME_TOKEN)==0)
        return AXIS2_TRUE;
    
    else if(axutil_strcmp(local_name,RP_X509_TOKEN)==0)
        return AXIS2_TRUE;

    else if(axutil_strcmp(local_name,RP_SECURITY_CONTEXT_TOKEN)==0)
        return AXIS2_TRUE;

    else
        return AXIS2_FALSE;
}
