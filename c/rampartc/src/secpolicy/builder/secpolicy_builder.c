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


#include <rp_layout.h>
#include <rp_secpolicy_builder.h>



AXIS2_EXTERN rp_secpolicy_t *AXIS2_CALL 
rp_secpolicy_builder_build(const axutil_env_t *env, axiom_node_t *all)
{
    rp_secpolicy_t *secpolicy = NULL;
    axiom_element_t *all_ele = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if(all)
    {
        if(axiom_node_get_node_type(all, env) == AXIOM_ELEMENT)
        {
            all_ele = (axiom_element_t*)axiom_node_get_data_element (all, env);
            secpolicy = rp_secpolicy_create(env);
            if(!secpolicy)
                return NULL;                        
            if(all_ele)
            {
                axiom_children_iterator_t *children_iter = NULL;
                children_iter = axiom_element_get_children(all_ele, env, all);
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
                                ele = (axiom_element_t*)axiom_node_get_data_element (node, env);
                                if(ele)
                                {
                                    local_name = axiom_element_get_localname(ele, env);
                                    if(local_name)
                                        rp_secpolicy_builder_set_properties(env,secpolicy,node,ele,local_name);                                            
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return secpolicy;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_secpolicy_builder_set_properties(
            const axutil_env_t *env,
            rp_secpolicy_t *secpolicy,
            axiom_node_t *node,
            axiom_element_t *element,
            axis2_char_t *local_name)    
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);
    
    if(axutil_strcmp(local_name,RP_SYMMETRIC_BINDING)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SYMMETRIC_BINDING,node,element))
        {
            rp_symmetric_binding_t *symmetric_binding = NULL;
            rp_property_t *binding = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            
            symmetric_binding = rp_symmetric_binding_builder_build(env,node);
            if(!symmetric_binding)
                return AXIS2_FAILURE;
            
            binding = rp_property_create(env);
            if(!binding)
                return AXIS2_FAILURE;

            status = rp_property_set_value(binding,env,symmetric_binding,RP_BINDING_SYMMETRIC);
            if(status != AXIS2_SUCCESS)
            {
                rp_property_free(binding,env);
                binding = NULL;
                return AXIS2_FAILURE;              
            }
            return rp_secpolicy_set_binding(secpolicy,env,binding);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_ASYMMETRIC_BINDING)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ASYMMETRIC_BINDING,node,element))
        {
            rp_asymmetric_binding_t *asymmetric_binding = NULL;
            rp_property_t *binding = NULL;
            axis2_status_t status = AXIS2_SUCCESS;
            
            asymmetric_binding = rp_asymmetric_binding_builder_build(env,node);
            if(!asymmetric_binding)
                return AXIS2_FAILURE;
            
            binding = rp_property_create(env);
            if(!binding)
                return AXIS2_FAILURE;

            status = rp_property_set_value(binding,env,asymmetric_binding,RP_BINDING_ASYMMETRIC);
            if(status != AXIS2_SUCCESS)
            {
                rp_property_free(binding,env);
                binding = NULL;
                return AXIS2_FAILURE;              
            }
            return rp_secpolicy_set_binding(secpolicy,env,binding);
        }
        else
            return AXIS2_FAILURE;
  
    }
    else if(axutil_strcmp(local_name,RP_TRANSPORT_BINDING)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_TRANSPORT_BINDING,node,element))
        {
            rp_transport_binding_t *transport_binding = NULL;
            rp_property_t *binding = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            transport_binding = rp_transport_binding_builder_build(env,node);
            if(!transport_binding)
                return AXIS2_FAILURE;

            binding = rp_property_create(env);
            if(!binding)
                return AXIS2_FAILURE;

            status = rp_property_set_value(binding,env,transport_binding,RP_BINDING_TRANSPORT);
            if(status != AXIS2_SUCCESS)
            {
                rp_property_free(binding,env);
                binding = NULL;
                return AXIS2_FAILURE;
            }
            return rp_secpolicy_set_binding(secpolicy,env,binding);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_SIGNED_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SIGNED_SUPPORTING_TOKENS,node,element))
        {
            rp_supporting_tokens_t *signed_supporting_tokens = NULL;

            signed_supporting_tokens = rp_supporting_tokens_builder_build(env,node);
            if(!signed_supporting_tokens)
                return AXIS2_FAILURE;

            rp_supporting_tokens_set_type(signed_supporting_tokens,env,RP_SUPPORTING_SIGNED_SUPPORTING);

            return rp_secpolicy_set_signed_supporting_tokens(secpolicy,env,signed_supporting_tokens);
        }
        else
            return AXIS2_FAILURE;

    }
    else if(axutil_strcmp(local_name,RP_SIGNED_ENDORSING_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SIGNED_ENDORSING_SUPPORTING_TOKENS,node,element))
        {
            rp_supporting_tokens_t *signed_endorsing_supporting_tokens = NULL;

            signed_endorsing_supporting_tokens = rp_supporting_tokens_builder_build(env,node);
            if(!signed_endorsing_supporting_tokens)
                return AXIS2_FAILURE;

            rp_supporting_tokens_set_type(signed_endorsing_supporting_tokens,env,RP_SUPPORTING_SIGNED_ENDORSING_SUPPORTING);

            return rp_secpolicy_set_signed_endorsing_supporting_tokens(secpolicy,env,signed_endorsing_supporting_tokens);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SUPPORTING_TOKENS,node,element))
        {
            rp_supporting_tokens_t *supporting_tokens = NULL;

            supporting_tokens = rp_supporting_tokens_builder_build(env,node);
            if(!supporting_tokens)
                return AXIS2_FAILURE;

            rp_supporting_tokens_set_type(supporting_tokens,env,RP_SUPPORTING_SUPPORTING);

            return rp_secpolicy_set_supporting_tokens(secpolicy,env,supporting_tokens);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_ENDORSING_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ENDORSING_SUPPORTING_TOKENS,node,element))
        {
            rp_supporting_tokens_t *endorsing_supporting_tokens = NULL;

            endorsing_supporting_tokens = rp_supporting_tokens_builder_build(env,node);
            if(!endorsing_supporting_tokens)
                return AXIS2_FAILURE;

            rp_supporting_tokens_set_type(endorsing_supporting_tokens,env,RP_SUPPORTING_ENDORSING_SUPPORTING);

            return rp_secpolicy_set_endorsing_supporting_tokens(secpolicy,env,endorsing_supporting_tokens);
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

            return rp_secpolicy_set_signed_parts(secpolicy,env,signed_parts);
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

            return rp_secpolicy_set_encrypted_parts(secpolicy,env,encrypted_parts);
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

            return rp_secpolicy_set_signed_elements(secpolicy,env,signed_elements);
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

            return rp_secpolicy_set_encrypted_elements(secpolicy,env,encrypted_elements);
        }
        else
            return AXIS2_FAILURE;
    }

    else if(axutil_strcmp(local_name,RP_SIGNED_ITEMS)==0)
    {
        if( rp_match_rampart_config_qname(env,RP_SIGNED_ITEMS,node,element))
        {
            rp_signed_encrypted_items_t *signed_items = NULL;
            signed_items = rp_signed_encrypted_items_builder_build(env,node);
            if(!signed_items)
                return AXIS2_FAILURE;

            rp_signed_encrypted_items_set_signeditems(signed_items,env,AXIS2_TRUE);

            return rp_secpolicy_set_signed_items(secpolicy,env,signed_items);
        }
        else
            return AXIS2_FAILURE;
    }
    
    else if(axutil_strcmp(local_name,RP_ENCRYPTED_ITEMS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ENCRYPTED_ITEMS,node,element))
        {
            rp_signed_encrypted_items_t *encrypted_items = NULL;
            encrypted_items = rp_signed_encrypted_items_builder_build(env,node);
            if(!encrypted_items)
                return AXIS2_FAILURE;

            rp_signed_encrypted_items_set_signeditems(encrypted_items,env,AXIS2_FALSE);

            return rp_secpolicy_set_encrypted_items(secpolicy,env,encrypted_items);
        }
        else return AXIS2_FAILURE;
    }
    
    else if(axutil_strcmp(local_name,RP_WSS10)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_WSS10,node,element)) 
        {           
            rp_wss10_t *wss10 = NULL;
            rp_property_t *wss = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            wss10 = rp_wss10_builder_build(env,node);
            if(!wss10)
                return AXIS2_FAILURE;

            wss = rp_property_create(env);
            if(!wss)
                return AXIS2_FAILURE;

            status = rp_property_set_value(wss,env,wss10,RP_WSS_WSS10);
            if(status != AXIS2_SUCCESS)
            {
                rp_property_free(wss,env);
                wss = NULL;
                return AXIS2_FAILURE;
            }
            return rp_secpolicy_set_wss(secpolicy,env,wss);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_WSS11)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_WSS11,node,element)) 
        {           
            rp_wss11_t *wss11 = NULL;
            rp_property_t *wss = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            wss11 = rp_wss11_builder_build(env,node);
            if(!wss11)
                return AXIS2_FAILURE;

            wss = rp_property_create(env);
            if(!wss)
                return AXIS2_FAILURE;

            status = rp_property_set_value(wss,env,wss11,RP_WSS_WSS11);
            if(status != AXIS2_SUCCESS)
            {
                rp_property_free(wss,env);
                wss = NULL;
                return AXIS2_FAILURE;
            }
            return rp_secpolicy_set_wss(secpolicy,env,wss);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_RAMPART_CONFIG)==0)
    {
        if(rp_match_rampart_config_qname(env,RP_RAMPART_CONFIG,node,element))
        {
            rp_rampart_config_t *rampart_config = NULL;
            rampart_config = rp_rampart_config_builder_build(env,node);
            if(!rampart_config)
                return AXIS2_FAILURE;

            return rp_secpolicy_set_rampart_config(secpolicy,env,rampart_config);
        }
        else
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}
