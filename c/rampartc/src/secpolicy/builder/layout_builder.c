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


#include <rp_layout_builder.h>

AXIS2_EXTERN rp_layout_t *AXIS2_CALL
rp_layout_builder_build(
            const axutil_env_t *env,
            axiom_node_t *layout)
{
    rp_layout_t *lay_out = NULL;
    axiom_node_t *policy = NULL;
    axiom_node_t *name = NULL;
    axiom_element_t *name_ele = NULL;
    axis2_char_t * value = NULL;
    axis2_status_t status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env,NULL);

    if(layout)
    {
        policy = axiom_node_get_first_element(layout,env);
        if(policy)
        {
            name = axiom_node_get_first_element(policy,env);
            if(name)
            {
                if(axiom_node_get_node_type(name,env) == AXIOM_ELEMENT)
                {
                    name_ele = (axiom_element_t*)axiom_node_get_data_element(name, env);
                    if(name_ele)
                    {
                        value = axiom_element_get_localname(name_ele, env);
                        if(value)
                        {
                            lay_out = rp_layout_create(env);
                            if(!lay_out)
                                return NULL;
                           
                            status = rp_layout_builder_set_value(name,name_ele,value,lay_out,env); 
                            if(status!=AXIS2_SUCCESS)
                            {
                                rp_layout_free(lay_out,env);
                                layout = NULL;
                            }
                        }                            
                    }
                }
            }
        }
    }   
    return lay_out;
}            

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_layout_builder_set_value(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *value,
        rp_layout_t *layout,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    if(strcmp(value,RP_LAYOUT_STRICT)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_LAYOUT_STRICT,node,element))
        {
            rp_layout_set_value(layout,env,value);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(value,RP_LAYOUT_LAX)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_LAYOUT_LAX,node,element))
        {
            rp_layout_set_value(layout,env,value);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(value,RP_LAYOUT_LAX_TIMESTAMP_FIRST)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_LAYOUT_LAX_TIMESTAMP_FIRST,node,element))
        {
            rp_layout_set_value(layout,env,value);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(value,RP_LAYOUT_STRICT)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_LAYOUT_LAX_TIMESTAMP_LAST,node,element))
        {
            rp_layout_set_value(layout,env,value);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}
