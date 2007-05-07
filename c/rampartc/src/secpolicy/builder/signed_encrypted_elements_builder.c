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


#include <rp_signed_encrypted_elements_builder.h>
#include <rp_qname_matcher.h>

AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL
rp_signed_encrypted_elements_builder_build(
            const axutil_env_t *env,
            axiom_node_t *elements)
{
    rp_signed_encrypted_elements_t *signed_encrypted_elements = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axiom_element_t *elements_ele = NULL;

    AXIS2_ENV_CHECK(env,NULL);

    signed_encrypted_elements = rp_signed_encrypted_elements_create(env);
    if(!signed_encrypted_elements)
        return NULL;

    if(axiom_node_get_node_type(elements, env) == AXIOM_ELEMENT)
    {
        elements_ele = (axiom_element_t*)axiom_node_get_data_element(elements, env);
        if(elements_ele)
        {
            axiom_children_iterator_t *children_iter = NULL;
            rp_signed_encrypted_elements_builder_set_xpath_version(elements_ele,signed_encrypted_elements,env);
            children_iter = axiom_element_get_children(elements_ele, env, elements);
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
                                    status = rp_signed_encrypted_elements_builder_set_properties(node,ele,local_name,signed_encrypted_elements,env);
                                    if(status!=AXIS2_SUCCESS)
                                    {
                                        rp_signed_encrypted_elements_free(signed_encrypted_elements,env);
                                        signed_encrypted_elements = NULL;
                                    }                           
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return signed_encrypted_elements;
}            


AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_signed_encrypted_elements_builder_set_properties(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *local_name,
        rp_signed_encrypted_elements_t *signed_encrypted_elements,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    if(strcmp(local_name,RP_XPATH)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_XPATH,node,element))
        {
            axis2_char_t *xpath = NULL;
            xpath = axiom_element_get_text(element,env,node);
            if(!xpath)
                return AXIS2_FAILURE;

            return rp_signed_encrypted_elements_add_expression(signed_encrypted_elements,env,xpath);
        }
        else
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_signed_encrypted_elements_builder_set_xpath_version(
    axiom_element_t *element,
    rp_signed_encrypted_elements_t *signed_encrypted_elements, 
    const axutil_env_t *env)
{
    axis2_char_t *xpath_version = NULL;

    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    xpath_version = axiom_element_get_attribute_value_by_name(element,env,RP_XPATH_VERSION);
    
    if(xpath_version)
        rp_signed_encrypted_elements_set_xpath_version(signed_encrypted_elements,env,RP_XPATH_VERSION); 
    
    return AXIS2_SUCCESS;
}
