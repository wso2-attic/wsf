/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 #include <sandesha2_iom_rm_element.h>


axis2_status_t AXIS2_CALL
sandesha2_iom_rm_element_free(
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env)
{
    return ((sandesha2_iom_rm_element_t*)(element))->ops->free(
        (sandesha2_iom_rm_element_t*)element, env);
}
    
axis2_char_t* AXIS2_CALL
sandesha2_iom_rm_element_get_namespace_value( 
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env)
{
    return ((sandesha2_iom_rm_element_t*)(element))->ops->get_namespace_value(
        (sandesha2_iom_rm_element_t*)element, env);
}

void* AXIS2_CALL
sandesha2_iom_rm_element_from_om_node(
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env, 
    axiom_node_t *om_node)
{
    return ((sandesha2_iom_rm_element_t*)(element))->ops->from_om_node(
        (sandesha2_iom_rm_element_t*)element, env, om_node);
}

axiom_node_t * AXIS2_CALL
sandesha2_iom_rm_element_to_om_node(
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env, 
    void *om_node)
{
    return ((sandesha2_iom_rm_element_t*)(element))->ops->to_om_node(
        (sandesha2_iom_rm_element_t*)element, env, om_node);
}

axis2_bool_t AXIS2_CALL
sandesha2_iom_rm_element_is_namespace_supported( 
    sandesha2_iom_rm_element_t *element,
    const axutil_env_t *env, 
    axis2_char_t *ns)
{
    return ((sandesha2_iom_rm_element_t*)(element))->ops->
        is_namespace_supported((sandesha2_iom_rm_element_t*)element, env, ns);
}


