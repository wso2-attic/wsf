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



#include <neethi_engine.h>
#include <neethi_assertion_builder.h>

/*Private functions*/

neethi_all_t *AXIS2_CALL get_operator_all(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element);

neethi_exactlyone_t *AXIS2_CALL get_operator_exactlyone(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element);

neethi_reference_t *AXIS2_CALL get_operator_reference(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element);

neethi_policy_t *AXIS2_CALL get_operator_neethi_policy(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element);

axis2_status_t AXIS2_CALL process_operation_element(
        const axutil_env_t *env,
        neethi_operator_t *neethi_operator,
        axiom_node_t *node,
        axiom_element_t *element);

axis2_status_t AXIS2_CALL neethi_engine_add_policy_component(
        const axutil_env_t *env,
        neethi_operator_t *container_operator,
        neethi_operator_t *component);

axis2_bool_t AXIS2_CALL
operator_is_empty(
    neethi_operator_t *operator,
    const axutil_env_t *env);

neethi_exactlyone_t *AXIS2_CALL
compute_resultant_component(
    axutil_array_list_t *normalized_inner_components,
    neethi_operator_type_t type,
    const axutil_env_t *env);

axutil_array_list_t *AXIS2_CALL
operator_get_components(
    neethi_operator_t *operator,
    const axutil_env_t *env);

neethi_exactlyone_t *AXIS2_CALL
normalize_operator(
    neethi_operator_t *operator,
    neethi_registry_t *registry,
    axis2_bool_t deep,
    const axutil_env_t *env);

neethi_exactlyone_t *AXIS2_CALL
get_cross_product(
    neethi_exactlyone_t *exactlyone1,
    neethi_exactlyone_t *exactlyone2,
    const axutil_env_t *env);



/*Implementations*/


AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
neethi_engine_get_policy(const axutil_env_t *env,
    axiom_node_t *node,
    axiom_element_t *element)
{

    return get_operator_neethi_policy(env,node,element);    

}

neethi_all_t *AXIS2_CALL get_operator_all(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)
{
    neethi_all_t *all = NULL;
    neethi_operator_t *neethi_operator = NULL;

    all = neethi_all_create(env);

    if(!all)
    {
        return NULL;
    }
    neethi_operator = neethi_operator_create(env);
    if(!neethi_operator)
    {
        return NULL;
    }        
    neethi_operator_set_value(neethi_operator, env, all, OPERATOR_TYPE_ALL);
    process_operation_element(env, neethi_operator, node, element);

    neethi_operator_set_value_null(neethi_operator, env);
    neethi_operator_free(neethi_operator, env);
    neethi_operator = NULL;

    return all;
}   

neethi_exactlyone_t *AXIS2_CALL get_operator_exactlyone(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)
{
    neethi_exactlyone_t *exactlyone = NULL;
    neethi_operator_t *neethi_operator = NULL;

    exactlyone = neethi_exactlyone_create(env);

    if(!exactlyone)
    {
        return NULL;
    }
    neethi_operator = neethi_operator_create(env);
    if(!neethi_operator)
    {
        return NULL;
    }        
    neethi_operator_set_value(neethi_operator,env,exactlyone,OPERATOR_TYPE_EXACTLYONE);
    process_operation_element(env,neethi_operator,node,element);

    neethi_operator_set_value_null(neethi_operator, env);
    neethi_operator_free(neethi_operator, env);
    neethi_operator = NULL;

    return exactlyone;
}

neethi_reference_t *AXIS2_CALL get_operator_reference(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)
{
    neethi_reference_t *reference = NULL;
    axutil_qname_t *qname = NULL;
    axis2_char_t * attribute_value = NULL;

    reference = neethi_reference_create(env);

    if(!reference)
    {
        return NULL;
    }
    qname = axutil_qname_create(env,NEETHI_URI,NULL,NULL);

    if(!qname)
    {
        return NULL;
    }

    attribute_value = axiom_element_get_attribute_value(element,env,qname);
    if(attribute_value)
    {
        neethi_reference_set_uri(reference,env,attribute_value);
    }    
    return reference;
}



neethi_policy_t *AXIS2_CALL get_operator_neethi_policy(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)
{
    neethi_policy_t *neethi_policy = NULL;
    neethi_operator_t *neethi_operator = NULL;

    neethi_policy = neethi_policy_create(env);

    if(!neethi_policy)
    {
        return NULL;
    }
    neethi_operator = neethi_operator_create(env);
    if(!neethi_operator)
    {
        return NULL;
    }        
    neethi_operator_set_value(neethi_operator, env, neethi_policy, OPERATOR_TYPE_POLICY);
    process_operation_element(env, neethi_operator, node, element);

    neethi_operator_set_value_null(neethi_operator, env);
    neethi_operator_free(neethi_operator, env);
    neethi_operator = NULL;

    return neethi_policy;
}


axis2_status_t AXIS2_CALL process_operation_element(
        const axutil_env_t *env,
        neethi_operator_t *neethi_operator,
        axiom_node_t *node,
        axiom_element_t *element)
{

    neethi_operator_type_t type;
    axiom_element_t *child_element = NULL;
    axiom_node_t *child_node = NULL;
    axiom_children_iterator_t *children_iter = NULL;
    void *value = NULL;

    type = neethi_operator_get_type(neethi_operator, env);
    value = neethi_operator_get_value(neethi_operator, env);
    if(type == OPERATOR_TYPE_POLICY)
    {
        /*Adding attribute values to the hashmap logic
         *comes here.Following is a little hack until we implement attribute
         hash map logic.*/
        
        axis2_char_t *id = NULL;
        axutil_qname_t *qname = NULL;
        axis2_char_t *name = NULL;

        qname = axutil_qname_create(env, NEETHI_ID, NEETHI_WSU_NS ,NEETHI_WSU_NS_PREFIX);
        if(!qname)
        {
            return AXIS2_FAILURE;
        }
        id = axiom_element_get_attribute_value(element, env, qname);
        axutil_qname_free(qname,env);
        qname = NULL;

        qname = axutil_qname_create(env, NEETHI_NAME, NULL, NULL); 
        if(!qname)
        {
            return AXIS2_FAILURE;
        }
        name = axiom_element_get_attribute_value(element, env, qname);
        axutil_qname_free(qname,env);
        qname = NULL;
        
        if(id)
        {
            neethi_policy_set_id((neethi_policy_t *)value, env, id);
        }                      
        if(name)
        {
            neethi_policy_set_name((neethi_policy_t *)value, env, name);
        }
    }
        
    children_iter = axiom_element_get_children(element, env, node);
    if(children_iter)
    {
        while(axiom_children_iterator_has_next(children_iter, env))
        {
            child_node = axiom_children_iterator_next(children_iter, env);
            if(child_node)
            {
                if(axiom_node_get_node_type(child_node , env) == AXIOM_ELEMENT)
                {    
                    child_element = (axiom_element_t*)axiom_node_get_data_element(child_node, env);
                    if(child_element)
                    {
                        axiom_namespace_t *namespace = NULL;
                        axis2_char_t *uri = NULL;
                        axis2_char_t *local_name = NULL;
                        neethi_operator_t *operator = NULL;
                        local_name = axiom_element_get_localname(child_element,env);

                        namespace = axiom_element_get_namespace(child_element, env, child_node);
                        if(!namespace)
                        {
                            return AXIS2_FAILURE;
                        }                            
                        uri = axiom_namespace_get_uri(namespace, env);
                        if(!uri)
                            return AXIS2_FAILURE;

                        if(axutil_strcmp(uri,NEETHI_NAMESPACE)==0)
                        {                            
                            if(axutil_strcmp(local_name,NEETHI_POLICY)==0)
                            {
                                neethi_policy_t *neethi_policy = get_operator_neethi_policy(env, child_node, child_element);
                                operator = neethi_operator_create(env);
                                neethi_operator_set_value(operator, env, neethi_policy, OPERATOR_TYPE_POLICY);
                                neethi_engine_add_policy_component(env, neethi_operator, operator);
                            }
                            else if(axutil_strcmp(local_name,NEETHI_ALL)==0)
                            {
                                neethi_all_t *all = get_operator_all(env, child_node, child_element);
                                operator = neethi_operator_create(env);
                                neethi_operator_set_value(operator,env, all, OPERATOR_TYPE_ALL);
                                neethi_engine_add_policy_component(env, neethi_operator, operator);
                            }
                            else if(axutil_strcmp(local_name,NEETHI_EXACTLYONE)==0)
                            {
                                neethi_exactlyone_t *exactlyone = get_operator_exactlyone(env, child_node, child_element);
                                operator = neethi_operator_create(env);
                                neethi_operator_set_value(operator, env, exactlyone, OPERATOR_TYPE_EXACTLYONE);
                                neethi_engine_add_policy_component(env, neethi_operator, operator);
                            }
                            else if(axutil_strcmp(local_name,NEETHI_REFERENCE)==0)
                            {
                                neethi_reference_t *reference = get_operator_reference(env, child_node, child_element);
                                operator = neethi_operator_create(env);
                                neethi_operator_set_value(operator, env, reference, OPERATOR_TYPE_REFERENCE);
                                neethi_engine_add_policy_component(env, neethi_operator, operator);
                            }
                        }                            
                        else
                        {                            
                            neethi_assertion_t *assertion = neethi_assertion_builder_build(env, child_node, child_element);
                            operator = neethi_operator_create(env);
                            neethi_operator_set_value(operator, env, assertion, OPERATOR_TYPE_ASSERTION);
                            neethi_engine_add_policy_component(env, neethi_operator, operator);
                        }                            
                    }
                }
            }
        }
        return AXIS2_SUCCESS;
    }
    else return AXIS2_FAILURE;        
}


axis2_status_t AXIS2_CALL neethi_engine_add_policy_component(
        const axutil_env_t *env,
        neethi_operator_t *container_operator,
        neethi_operator_t *component)
{

    neethi_operator_type_t type;
    void *value = NULL;
    neethi_policy_t *neethi_policy = NULL;
    neethi_exactlyone_t *exactlyone = NULL;
    neethi_all_t *all = NULL;
    neethi_assertion_t *assertion = NULL;

    type = neethi_operator_get_type(container_operator, env);
    value = neethi_operator_get_value(container_operator, env);        
    
    if(value)
    {
        switch(type)
        {
            case OPERATOR_TYPE_POLICY:
                neethi_policy = (neethi_policy_t *)value;
                neethi_policy_add_operator(neethi_policy, env, component);   
                /*printf("neethi_policy\n");*/
                break;

            case OPERATOR_TYPE_ALL:
                all = (neethi_all_t *)value;
                neethi_all_add_operator(all, env, component);
                /*printf("all\n");*/
                break;

            case OPERATOR_TYPE_EXACTLYONE:
                exactlyone = (neethi_exactlyone_t *)value;
                neethi_exactlyone_add_operator(exactlyone, env, component);
                /*printf("exactlyone\n");*/
                break;

            case OPERATOR_TYPE_UNKNOWN:
                return AXIS2_FAILURE;
                break;

            case OPERATOR_TYPE_ASSERTION:
                assertion = (neethi_assertion_t *)value;
                neethi_assertion_add_operator(assertion, env, component);
                /*printf("assertion\n");*/
                break;

            case OPERATOR_TYPE_REFERENCE:
                break;
        }
        return AXIS2_SUCCESS;
    }
    else return AXIS2_FAILURE;
}

/***************************************/
/*This function is only for testing*
 *Remove it later*/
void check_neethi_policy(neethi_policy_t *neethi_policy , const axutil_env_t *env)
{
    axutil_array_list_t *list = NULL;
    neethi_operator_t *op = NULL;
    neethi_operator_type_t type;

    list = neethi_policy_get_policy_components(neethi_policy,env);

    if(axutil_array_list_size(list,env)>1)
    {
        /*printf("Error with Normalized neethi_policy\n");*/
        return;
    }        
    op = (neethi_operator_t *)axutil_array_list_get(list,env,0);
    type = neethi_operator_get_type(op,env);
    if(type == OPERATOR_TYPE_EXACTLYONE)
    {
        void *value = neethi_operator_get_value(op,env);
        if(value)
        {
            /*printf("Check is ok\n");*/
            return;
        }          
    }
    else 
    {
        /*printf("Not properly normalized\n");*/
        return;
    }        
}    

/************************************************/

AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
neethi_engine_get_normalize(const axutil_env_t *env,
        axis2_bool_t deep,
        neethi_policy_t *neethi_policy)
{
    return neethi_engine_normalize(env, neethi_policy, NULL, deep);
}


AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
neethi_engine_normalize(const axutil_env_t *env,
    neethi_policy_t *neethi_policy,
    neethi_registry_t *registry,
    axis2_bool_t deep)
{
    neethi_policy_t *resultant_neethi_policy = NULL;
    neethi_operator_t *operator = NULL;
    neethi_operator_t *component = NULL;
    neethi_exactlyone_t *exactlyone = NULL;
    axis2_char_t *policy_name = NULL;
    axis2_char_t *policy_id = NULL;

    resultant_neethi_policy = neethi_policy_create(env);

    policy_name = neethi_policy_get_name(neethi_policy, env);
    if(policy_name)
    {
        neethi_policy_set_name(resultant_neethi_policy, env, policy_name);
    }        
    policy_id = neethi_policy_get_id(neethi_policy, env);
    if(policy_id)
    {
        neethi_policy_set_id(resultant_neethi_policy, env, policy_id);
    }        

    operator = neethi_operator_create(env);
    neethi_operator_set_value(operator, env, neethi_policy, OPERATOR_TYPE_POLICY);

    exactlyone = normalize_operator(operator, registry, deep, env);

    neethi_operator_set_value_null(operator, env);
    neethi_operator_free(operator, env);
    operator = NULL;
   
    if(exactlyone)
    {
        component = neethi_operator_create(env);
        neethi_operator_set_value(component, env, exactlyone, OPERATOR_TYPE_EXACTLYONE);
        neethi_policy_add_operator(resultant_neethi_policy, env, component);
        
        /*check_neethi_policy(resultant_neethi_policy,env);*/
        return resultant_neethi_policy;
    }        
    else
        return NULL;
}

AXIS2_EXTERN neethi_policy_t *AXIS2_CALL
neethi_engine_merge(const axutil_env_t *env,
    neethi_policy_t *neethi_policy1,
    neethi_policy_t *neethi_policy2)
{

    neethi_exactlyone_t *exactlyone1 = NULL;
    neethi_exactlyone_t *exactlyone2 = NULL;
    neethi_exactlyone_t *exactlyone = NULL;
    neethi_policy_t *neethi_policy = NULL;
    neethi_operator_t *component = NULL;

    exactlyone1 = neethi_policy_get_exactlyone(neethi_policy1, env);
    exactlyone2 = neethi_policy_get_exactlyone(neethi_policy2, env);    

    if(!exactlyone1 || !exactlyone2)
    {
        /*printf("Merged fail Input wrong \n");*/
        return NULL;
    }
    exactlyone = get_cross_product(exactlyone1, exactlyone2, env);
    
    neethi_policy = neethi_policy_create(env);

    component = neethi_operator_create(env);
    neethi_operator_set_value(component, env, exactlyone, OPERATOR_TYPE_EXACTLYONE);
    neethi_policy_add_operator(neethi_policy, env, component);

    return neethi_policy;
}



axis2_bool_t AXIS2_CALL 
operator_is_empty(
    neethi_operator_t *operator,
    const axutil_env_t *env)
{
    
    neethi_operator_type_t type;
    void *value = NULL;
    neethi_policy_t *neethi_policy = NULL;
    neethi_exactlyone_t *exactlyone = NULL;
    neethi_all_t *all = NULL;
    neethi_assertion_t *assertion = NULL;

    type = neethi_operator_get_type(operator,env);
    value = neethi_operator_get_value(operator,env);

    if(value)
    {
        switch(type)
        {
            case OPERATOR_TYPE_POLICY:
                neethi_policy = (neethi_policy_t *)value;
                return neethi_policy_is_empty(neethi_policy,env);
                break;

            case OPERATOR_TYPE_ALL:
                all = (neethi_all_t *)value;
                return neethi_all_is_empty(all,env);
                break;

            case OPERATOR_TYPE_EXACTLYONE:
                exactlyone = (neethi_exactlyone_t *)value;
                return neethi_exactlyone_is_empty(exactlyone,env);
                break;

            case OPERATOR_TYPE_UNKNOWN:
                return AXIS2_FALSE;
                break;

            case OPERATOR_TYPE_ASSERTION:
                assertion = (neethi_assertion_t *)value;
                return neethi_assertion_is_empty(assertion, env);
                break;

            case OPERATOR_TYPE_REFERENCE:
                break;
                            
        }
        return AXIS2_FALSE;
    }
    else return AXIS2_FALSE;
}

axutil_array_list_t *AXIS2_CALL 
operator_get_components(
    neethi_operator_t *operator,
    const axutil_env_t *env)
{
    
    neethi_operator_type_t type;
    void *value = NULL;
    neethi_policy_t *neethi_policy = NULL;
    neethi_exactlyone_t *exactlyone = NULL;
    neethi_all_t *all = NULL;
    neethi_assertion_t *assertion = NULL;

    type = neethi_operator_get_type(operator,env);
    value = neethi_operator_get_value(operator,env);

    if(value)
    {
        switch(type)
        {
            case OPERATOR_TYPE_POLICY:
                neethi_policy = (neethi_policy_t *)value;
                return neethi_policy_get_policy_components(neethi_policy,env);
                break;

            case OPERATOR_TYPE_ALL:
                all = (neethi_all_t *)value;
                return neethi_all_get_policy_components(all,env);
                break;

            case OPERATOR_TYPE_EXACTLYONE:
                exactlyone = (neethi_exactlyone_t *)value;
                return neethi_exactlyone_get_policy_components(exactlyone,env);
                break;

            case OPERATOR_TYPE_UNKNOWN:
                return NULL;
                break;

            case OPERATOR_TYPE_ASSERTION:
                assertion = (neethi_assertion_t *)value;
                return neethi_assertion_get_policy_components(assertion, env);
                break;

            case OPERATOR_TYPE_REFERENCE:
                break;
        }
    }
    
    return NULL;
}



neethi_exactlyone_t *AXIS2_CALL
normalize_operator(
    neethi_operator_t *operator,
    neethi_registry_t *registry,
    axis2_bool_t deep,
    const axutil_env_t *env)
{
    axutil_array_list_t *child_component_list = NULL;
    neethi_operator_t *child_component = NULL;
    axutil_array_list_t *arraylist = NULL;
    int i = 0;

    neethi_operator_type_t type = neethi_operator_get_type(operator, env);
    
    if(operator_is_empty(operator, env))
    {
        neethi_exactlyone_t *exactlyone = NULL;
        exactlyone = neethi_exactlyone_create(env);
        if(type != OPERATOR_TYPE_EXACTLYONE)
        {
            neethi_all_t *all = NULL;
            neethi_operator_t *component = NULL;
            all = neethi_all_create(env);
            component = neethi_operator_create(env);
            neethi_operator_set_value(component, env, all, OPERATOR_TYPE_ALL);
            neethi_exactlyone_add_operator(exactlyone, env, component);
        }                        
        return exactlyone;
    }
    
    child_component_list = axutil_array_list_create(env, 0);     
    arraylist = operator_get_components(operator, env);

    for (i = 0; i < axutil_array_list_size(arraylist, env); i++)
    {
        neethi_operator_type_t component_type;
        child_component = (neethi_operator_t *)axutil_array_list_get(arraylist ,env ,i);
        component_type = neethi_operator_get_type(child_component, env);
        
        if(component_type == OPERATOR_TYPE_ASSERTION)
        {
            /*Assertion normalization part comes here*/
            if(deep)
            {
                /*printf("We still not handling deep normalization of assertions");*/
                return NULL;
            }               
            else
            {
                neethi_exactlyone_t *exactlyone = NULL;
                neethi_all_t *all = NULL;
                neethi_operator_t *op = NULL;

                exactlyone = neethi_exactlyone_create(env);
                all = neethi_all_create(env);
                op = neethi_operator_create(env);

                neethi_all_add_operator(all, env, child_component);
                neethi_operator_set_value(op, env, all, OPERATOR_TYPE_ALL);
                neethi_exactlyone_add_operator(exactlyone, env, op);
                axutil_array_list_add(child_component_list, env, exactlyone);
            }                
        }
        else if(component_type == OPERATOR_TYPE_POLICY)
        {
            neethi_policy_t *neethi_policy = NULL;
            neethi_all_t *all = NULL;
            axutil_array_list_t *children = NULL;            
            neethi_operator_t *to_normalize = NULL;
            neethi_exactlyone_t *exactlyone = NULL;

            all = neethi_all_create(env);
            neethi_policy = (neethi_policy_t *)neethi_operator_get_value(child_component, env);
            children =  neethi_policy_get_policy_components(neethi_policy, env);
            neethi_all_add_policy_components(all, children, env);
            to_normalize = neethi_operator_create(env);
            neethi_operator_set_value(to_normalize, env, all, OPERATOR_TYPE_ALL);
            exactlyone = normalize_operator(to_normalize, registry, deep, env);
            axutil_array_list_add(child_component_list, env, exactlyone);                    
        }
        else if(component_type == OPERATOR_TYPE_REFERENCE)
        {
            neethi_reference_t *policy_ref = NULL;
            axis2_char_t *uri = NULL;
            neethi_policy_t *policy = NULL;
            neethi_all_t *all = NULL;
            axutil_array_list_t *children = NULL;
            neethi_operator_t *to_normalize = NULL;
            neethi_exactlyone_t *exactlyone = NULL;

            policy_ref = (neethi_reference_t *)neethi_operator_get_value(child_component, env);
            uri = neethi_reference_get_uri(policy_ref, env);
            if(!uri)
            {
                /*printf("NO policy Reference\n");*/
                return NULL;
            }    
            policy = neethi_registry_lookup(registry, env, uri);
            if(!policy)
            {
                /*printf("Cannot get policy from uri\n");*/
                return NULL;
            }  
            neethi_operator_set_value(child_component, env, policy, OPERATOR_TYPE_POLICY);

            all = neethi_all_create(env);
            policy = (neethi_policy_t *)neethi_operator_get_value(child_component, env);
            children =  neethi_policy_get_policy_components(policy, env);
            neethi_all_add_policy_components(all, children, env);
            to_normalize = neethi_operator_create(env);
            neethi_operator_set_value(to_normalize, env, all, OPERATOR_TYPE_ALL);
            exactlyone = normalize_operator(to_normalize, registry, deep, env);
            axutil_array_list_add(child_component_list, env, exactlyone);
        }            
        else
        {
            neethi_exactlyone_t *exactlyone = NULL;
            exactlyone = normalize_operator(child_component, registry, deep, env);
            axutil_array_list_add(child_component_list, env, exactlyone);
        }
    }

    return compute_resultant_component(child_component_list, type, env);
}


neethi_exactlyone_t *AXIS2_CALL
compute_resultant_component(
    axutil_array_list_t *normalized_inner_components,
    neethi_operator_type_t type,
    const axutil_env_t *env)
{
    neethi_exactlyone_t *exactlyone = NULL;
    /*exactlyone = neethi_exactlyone_create(env);*/

    if(type == OPERATOR_TYPE_EXACTLYONE)
    {
        int i = 0;
        neethi_exactlyone_t *inner_exactlyone = NULL;
        
        for(i=0; i<axutil_array_list_size(normalized_inner_components,env); i++ )
        {
            inner_exactlyone = (neethi_exactlyone_t *)axutil_array_list_get(normalized_inner_components, env, i);
            neethi_exactlyone_add_policy_components(exactlyone,
                           neethi_exactlyone_get_policy_components(inner_exactlyone, env), env);
            
        }
    }
    else if(type == OPERATOR_TYPE_POLICY ||
                type == OPERATOR_TYPE_ALL)
    {
        if(axutil_array_list_size(normalized_inner_components, env)>1)
        {
            int i = 0;
            exactlyone = (neethi_exactlyone_t *)axutil_array_list_get(normalized_inner_components, env, 0);
            if(!neethi_exactlyone_is_empty(exactlyone, env))
            {
                neethi_exactlyone_t *current_exactlyone = NULL;
                i = 1;
                for(i=1; i<axutil_array_list_size(normalized_inner_components, env); i++)
                {
                    current_exactlyone = (neethi_exactlyone_t *)axutil_array_list_get(normalized_inner_components, env, i);
                    if(neethi_exactlyone_is_empty(current_exactlyone, env)) 
                    {
                        exactlyone = current_exactlyone;
                        break;    
                    } 
                    else
                    {
                        neethi_exactlyone_t *temp = NULL;
                        neethi_exactlyone_t *temp1 = NULL;
                        temp = exactlyone;
                        temp1 = current_exactlyone;
                        exactlyone = get_cross_product(exactlyone, current_exactlyone, env);
                        neethi_exactlyone_free(temp, env);
                        neethi_exactlyone_free(temp1, env);
                        temp = NULL;
                        temp1 = NULL;
                    }
                }
            }
        }
        else
        {
            exactlyone = (neethi_exactlyone_t *)axutil_array_list_get(normalized_inner_components, env, 0);   
        }
    }
    axutil_array_list_free(normalized_inner_components, env);
    normalized_inner_components = NULL;
    
    return exactlyone;
}


neethi_exactlyone_t *AXIS2_CALL
get_cross_product(
    neethi_exactlyone_t *exactlyone1,
    neethi_exactlyone_t *exactlyone2,
    const axutil_env_t *env)
{
    neethi_exactlyone_t *cross_product = NULL;
    neethi_all_t *cross_product_all = NULL;
    neethi_all_t *current_all1 = NULL;
    neethi_all_t *current_all2 = NULL;
    axutil_array_list_t *array_list1 = NULL;
    axutil_array_list_t *array_list2 = NULL;
    neethi_operator_t *component = NULL;
    int i = 0;
    int j = 0;

    cross_product = neethi_exactlyone_create(env);
    array_list1 = neethi_exactlyone_get_policy_components(exactlyone1, env);
    array_list2 = neethi_exactlyone_get_policy_components(exactlyone2, env);

    for(i=0; i<axutil_array_list_size(array_list1, env); i++)
    {
        current_all1 = (neethi_all_t *)neethi_operator_get_value(
           (neethi_operator_t *)axutil_array_list_get(array_list1, env, i), env );
        
        for(j=0; j<axutil_array_list_size(array_list2,env); j++ )
        {
            current_all2 = (neethi_all_t *)neethi_operator_get_value(
                (neethi_operator_t *)axutil_array_list_get(array_list2, env, j), env);
            
            cross_product_all = neethi_all_create(env);
            neethi_all_add_policy_components(cross_product_all,
                           neethi_all_get_policy_components(current_all1, env), env);
            
            neethi_all_add_policy_components(cross_product_all,
                           neethi_all_get_policy_components(current_all2, env), env);
            
            component = neethi_operator_create(env);
            neethi_operator_set_value(component, env, cross_product_all, OPERATOR_TYPE_ALL);
            neethi_exactlyone_add_operator(cross_product, env, component);
        }

    }
    return cross_product;
}

/*These functions are for serializing a policy object*/

AXIS2_EXTERN axiom_node_t *AXIS2_CALL
neethi_engine_serialize(neethi_policy_t *policy,
                   const axutil_env_t *env)
{
    
    return neethi_policy_serialize(policy, NULL, env);
}
