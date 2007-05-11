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


#include <rp_token_builder.h>

AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_token_builder_build(
            const axutil_env_t *env,
            axiom_node_t *token)
{
    rp_property_t *property = NULL;
    axiom_node_t *policy = NULL;
    axiom_node_t *token_name = NULL;
    axiom_element_t *token_name_ele = NULL;
    axis2_char_t *token_value = NULL;
    axis2_status_t status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env,NULL);

    if(token)
    {
        property = rp_property_create(env);
        if(!property)
            return NULL;
        policy = axiom_node_get_first_element(token,env);
        if(policy)
        {
            token_name = axiom_node_get_first_element(policy,env);
            if(token_name)
            {
                if(axiom_node_get_node_type(token_name,env) == AXIOM_ELEMENT)
                {
                    token_name_ele = (axiom_element_t*)axiom_node_get_data_element(token_name, env);
                    if(token_name_ele)
                    {
                        token_value = axiom_element_get_localname(token_name_ele, env);
                        if(token_value)
                        {
                            status = rp_token_builder_set_token(token_name,token_name_ele,token_value,property,env);
                            if(status!=AXIS2_SUCCESS)
                            {
                                rp_property_free(property,env);
                                property = NULL;
                            }                                
                        } 
                    }
                }
            }
        }
    }
    return property;
}            

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_token_builder_set_token(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *value,
        rp_property_t *token,
        const axutil_env_t *env)

{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);
    
    if(axutil_strcmp(value,RP_USERNAME_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_USERNAME_TOKEN,node,element))
        {
            rp_username_token_t *username_token = NULL;
            username_token = rp_username_token_builder_build(env,node,element);
            if(!username_token)
                return AXIS2_FAILURE;

            return rp_property_set_value(token,env,username_token,RP_TOKEN_USERNAME);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(value,RP_X509_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_X509_TOKEN,node,element))
        {
            rp_x509_token_t *x509_token = NULL;
            x509_token = rp_x509_token_builder_build(env,node,element);
            if(!x509_token)
                return AXIS2_FAILURE;

            return rp_property_set_value(token,env,x509_token,RP_TOKEN_X509);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(value,RP_SECURITY_CONTEXT_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SECURITY_CONTEXT_TOKEN,node,element))
        {
            rp_security_context_token_t *security_context_token = NULL;
            security_context_token = rp_security_context_token_builder_build(env,node,element);
            if(!security_context_token)
                return AXIS2_FAILURE;

            return rp_property_set_value(token,env,security_context_token,RP_TOKEN_SECURITY_CONTEXT);
        }
        else
            return AXIS2_FAILURE;
    }        
    else if(axutil_strcmp(value,RP_HTTPS_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_HTTPS_TOKEN,node,element))
        {
            rp_https_token_t *https_token = NULL;
            https_token = rp_https_token_builder_build(env,node,element);
            if(!https_token)
                return AXIS2_FAILURE;

            return rp_property_set_value(token,env,https_token,RP_TOKEN_HTTPS);

        }
        else
            return AXIS2_FAILURE;
    }  
    else
        return AXIS2_FAILURE;
}    
