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



#include <rp_wss11_builder.h>

AXIS2_EXTERN rp_wss11_t *AXIS2_CALL
rp_wss11_builder_build(
            const axutil_env_t *env,
            axiom_node_t *wss)
{
    rp_wss11_t *wss11 = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axiom_node_t *policy = NULL;
    axiom_element_t *pol_ele = NULL;

    AXIS2_ENV_CHECK(env,NULL);

    wss11 = rp_wss11_create(env);
    if(!wss11)
        return NULL;

    policy = axiom_node_get_first_element(wss,env);

    if(axiom_node_get_node_type(policy, env) == AXIOM_ELEMENT)
    {
        pol_ele = (axiom_element_t*)axiom_node_get_data_element(policy, env);
        if(pol_ele)
        {
            axiom_children_iterator_t *children_iter = NULL;
            children_iter = axiom_element_get_children(pol_ele,env,policy);
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
                                    status = rp_wss11_builder_set_properties(node,ele,local_name,wss11,env);
                                    if(status!=AXIS2_SUCCESS)
                                    {
                                        rp_wss11_free(wss11,env);
                                        wss11 = NULL;
                                    }                           
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return wss11;
}            


AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_wss11_builder_set_properties(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *local_name,
        rp_wss11_t *wss11,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    if(strcmp(local_name,RP_MUST_SUPPORT_REF_KEY_IDENTIFIER)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_MUST_SUPPORT_REF_KEY_IDENTIFIER,node,element))
        {
            rp_wss11_set_must_support_ref_key_identifier(wss11,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(local_name,RP_MUST_SUPPORT_REF_ISSUER_SERIAL)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_MUST_SUPPORT_REF_ISSUER_SERIAL,node,element))
        {
            rp_wss11_set_must_support_ref_issuer_serial(wss11,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(local_name,RP_MUST_SUPPORT_REF_EXTERNAL_URI)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_MUST_SUPPORT_REF_EXTERNAL_URI,node,element))
        {
            rp_wss11_set_must_support_ref_external_uri(wss11,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(local_name,RP_MUST_SUPPORT_REF_EMBEDDED_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_MUST_SUPPORT_REF_EMBEDDED_TOKEN,node,element))
        {
            rp_wss11_set_must_support_ref_embedded_token(wss11,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
 /*   else if(strcmp(local_name,RP_MUST_SUPPORT_REF_THUMBPRINT)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_MUST_SUPPORT_REF_THUMBPRINT,node,element))
        {
            rp_wss11_set_must_support_ref_thumbprint(wss11,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
   */ else if(strcmp(local_name,RP_MUST_SUPPORT_REF_ENCRYPTED_KEY)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_MUST_SUPPORT_REF_ENCRYPTED_KEY,node,element))
        {
            rp_wss11_set_must_support_ref_encryptedkey(wss11,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(local_name,RP_REQUIRE_SIGNATURE_CONFIRMATION)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_REQUIRE_SIGNATURE_CONFIRMATION,node,element))
        {
            rp_wss11_set_require_signature_confirmation(wss11,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;

}
