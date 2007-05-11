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


#include <rp_signed_encrypted_parts_builder.h>
#include <rp_qname_matcher.h>
/*
AXIS2_EXTERN rp_header_t *AXIS2_CALL
rp_signed_encrypted_parts_builder_build_header(
    axiom_element_t *element,
    const axutil_env_t *env);
*/

AXIS2_EXTERN rp_signed_encrypted_parts_t *AXIS2_CALL
rp_signed_encrypted_parts_builder_build(
            const axutil_env_t *env,
            axiom_node_t *parts)
{
    rp_signed_encrypted_parts_t *signed_encrypted_parts = NULL;
    axis2_status_t status = AXIS2_SUCCESS;
    axiom_element_t *parts_ele = NULL;

    AXIS2_ENV_CHECK(env,NULL);

    signed_encrypted_parts = rp_signed_encrypted_parts_create(env);
    if(!signed_encrypted_parts)
        return NULL;

    if(axiom_node_get_node_type(parts, env) == AXIOM_ELEMENT)
    {
        parts_ele = (axiom_element_t*)axiom_node_get_data_element(parts, env);
        if(parts_ele)
        {
            axiom_children_iterator_t *children_iter = NULL;
            children_iter = axiom_element_get_children(parts_ele, env, parts);
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
                                    status = rp_signed_encrypted_parts_builder_set_properties(node,ele,local_name,signed_encrypted_parts,env);
                                    if(status!=AXIS2_SUCCESS)
                                    {
                                        rp_signed_encrypted_parts_free(signed_encrypted_parts,env);
                                        signed_encrypted_parts = NULL;
                                    }                           
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return signed_encrypted_parts;
}            


AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_signed_encrypted_parts_builder_set_properties(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *local_name,
        rp_signed_encrypted_parts_t *signed_encrypted_parts,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    if(strcmp(local_name,RP_BODY)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_BODY,node,element))
        {
            rp_signed_encrypted_parts_set_body(signed_encrypted_parts,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(local_name,RP_HEADER)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_HEADER,node,element))
        {
            rp_header_t *header = NULL;
            header = rp_signed_encrypted_parts_builder_build_header(element,env);
            if(!header)
                return AXIS2_FAILURE;
            
            return rp_signed_encrypted_parts_add_header(signed_encrypted_parts,env,header);    
        }
        else 
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}

AXIS2_EXTERN rp_header_t *AXIS2_CALL 
rp_signed_encrypted_parts_builder_build_header(
    axiom_element_t *element,
    const axutil_env_t *env)
{
    rp_header_t *header = NULL;
    axis2_char_t *name = NULL;
    axis2_char_t *namespace = NULL;    

    AXIS2_ENV_CHECK(env,NULL);

    header = rp_header_create(env);    
    if(!header)
        return NULL;

    name = axiom_element_get_attribute_value_by_name(element,env,RP_NAME);
    namespace = axiom_element_get_attribute_value_by_name(element,env,RP_NAMESPACE);
    if(!namespace)
    {
        rp_header_free(header,env);
        header = NULL;
        return NULL;    
    }     
    if(name)
        rp_header_set_name(header,env,name); 
    
    rp_header_set_namespace(header,env,namespace);    
    
    return header;
}
