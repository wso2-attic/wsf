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


#include <rp_signed_encrypted_items_builder.h>
#include <rp_qname_matcher.h>
/*
AXIS2_EXTERN rp_header_t *AXIS2_CALL
rp_signed_encrypted_items_builder_build_header(
    axiom_element_t *element,
    const axutil_env_t *env);
*/

AXIS2_EXTERN rp_signed_encrypted_items_t *AXIS2_CALL
rp_signed_encrypted_items_builder_build(
            const axutil_env_t *env,
            axiom_node_t *items)
{
    rp_signed_encrypted_items_t *signed_encrypted_items = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axiom_element_t *items_ele = NULL;

    AXIS2_ENV_CHECK(env,NULL);

    signed_encrypted_items = rp_signed_encrypted_items_create(env);
    if(!signed_encrypted_items)
        return NULL;

    if(axiom_node_get_node_type(items, env) == AXIOM_ELEMENT)
    {
        items_ele = (axiom_element_t*)axiom_node_get_data_element(items, env);
        if(items_ele)
        {
            axiom_children_iterator_t *children_iter = NULL;
            children_iter = axiom_element_get_children(items_ele, env, items);
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
                                    status = rp_signed_encrypted_items_builder_set_properties(node,ele,local_name,signed_encrypted_items,env);
                                    if(status!=AXIS2_SUCCESS)
                                    {
                                        rp_signed_encrypted_items_free(signed_encrypted_items,env);
                                        signed_encrypted_items = NULL;
                                    }                           
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return signed_encrypted_items;
}            


AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_signed_encrypted_items_builder_set_properties(
        axiom_node_t *node,
        axiom_element_t *ele,
        axis2_char_t *local_name,
        rp_signed_encrypted_items_t *signed_encrypted_items,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    if(strcmp(local_name,RP_ELEMENT)==0)
    {
        if(rp_match_rampart_config_qname(env,RP_ELEMENT,node,ele))
        {
            rp_element_t *element = NULL;
            element = rp_signed_encrypted_items_builder_build_element(ele,env);
            if(!element)
                return AXIS2_FAILURE;
            
            return rp_signed_encrypted_items_add_element(signed_encrypted_items,env,element);    
        }
        else 
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}

AXIS2_EXTERN rp_element_t *AXIS2_CALL 
rp_signed_encrypted_items_builder_build_element(
    axiom_element_t *ele,
    const axutil_env_t *env)
{
    rp_element_t *element = NULL;
    axis2_char_t *name = NULL;
    axis2_char_t *namespace = NULL;    

    AXIS2_ENV_CHECK(env,NULL);

    element = rp_element_create(env);    
    if(!element)
        return NULL;

    name = axiom_element_get_attribute_value_by_name(ele,env,RP_NAME);
    namespace = axiom_element_get_attribute_value_by_name(ele,env,RP_NAMESPACE);
    if(!namespace)
    {
        rp_element_free(element,env);
        element = NULL;
        return NULL;    
    }     
    if(name)
        rp_element_set_name(element,env,name); 
    
    rp_element_set_namespace(element,env,namespace);    
    
    return element;
}
