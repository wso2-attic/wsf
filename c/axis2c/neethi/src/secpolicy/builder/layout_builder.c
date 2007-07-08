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
#include <neethi_operator.h>
#include <neethi_policy.h>
#include <neethi_exactlyone.h>
#include <neethi_all.h>
#include <neethi_engine.h>



AXIS2_EXTERN neethi_assertion_t *AXIS2_CALL 
rp_layout_builder_build(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)

{
    rp_layout_t *layout = NULL;
    axiom_node_t *child_node = NULL;
    axiom_node_t *layout_node = NULL;
    axiom_element_t *layout_element = NULL;
    neethi_assertion_t *assertion = NULL;

    layout = rp_layout_create(env);
    
    child_node = axiom_node_get_first_element(node,env);

    if(child_node)
    {
        layout_node = axiom_node_get_first_element(child_node, env);
    }        

    if(axiom_node_get_node_type(layout_node, env) == AXIOM_ELEMENT)
    {
        layout_element = (axiom_element_t*)axiom_node_get_data_element(layout_node, env);
        if(layout_element)
        {
            axis2_char_t *local_name = NULL;

            local_name = axiom_element_get_localname(layout_element, env);
            if(!local_name)
                return NULL;
            rp_layout_set_value(layout, env, local_name);
            assertion = neethi_assertion_create_with_args(env, (void *)rp_layout_free, layout, ASSERTION_TYPE_LAYOUT);
            return assertion;
        }
        else return NULL;
    }
    else return NULL;
}

