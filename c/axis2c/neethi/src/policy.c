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



#include <neethi_policy.h>
#include <neethi_engine.h>

struct neethi_policy_t
{
    axutil_array_list_t *policy_components;
/*  axutil_hash_t *attributes_map;*/
    axis2_char_t *name;
    axis2_char_t *id;
};

AXIS2_EXTERN neethi_policy_t *AXIS2_CALL 
neethi_policy_create(const axutil_env_t *env)
{
    neethi_policy_t *neethi_policy = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    neethi_policy =  (neethi_policy_t *) AXIS2_MALLOC (env->allocator,
    sizeof (neethi_policy_t));

    if(neethi_policy == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    neethi_policy->policy_components = NULL;

    neethi_policy->policy_components = axutil_array_list_create(env, 0);
    if (!(neethi_policy->policy_components) )
    {
        neethi_policy_free(neethi_policy, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    /*
    neethi_policy->attributes_map = NULL;

    neethi_policy->attributes_map = axutil_hash_make(env);
    if (!(neethi_policy->attributes_map))
    {
        neethi_policy_free(neethi_policy, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    */
    neethi_policy->name = NULL;
    neethi_policy->id = NULL;

    return neethi_policy;
}

AXIS2_EXTERN void AXIS2_CALL 
neethi_policy_free(neethi_policy_t *neethi_policy,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(neethi_policy)
    {

        if(neethi_policy->policy_components)
        {
            int i = 0;
            for (i = 0; i < axutil_array_list_size(neethi_policy->policy_components,
                env); i++)
            {
                neethi_operator_t *operator = NULL;
                operator = (neethi_operator_t *)
                    axutil_array_list_get(neethi_policy->policy_components,env, i);
                if (operator)
                    neethi_operator_free(operator, env);

                operator = NULL;
            }
            axutil_array_list_free(neethi_policy->policy_components , env);
            neethi_policy->policy_components = NULL;
        }
        AXIS2_FREE(env->allocator, neethi_policy);
        neethi_policy = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
neethi_policy_get_policy_components(
    neethi_policy_t *neethi_policy,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return neethi_policy->policy_components;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_policy_add_policy_components(
        neethi_policy_t *neethi_policy,
        axutil_array_list_t *arraylist,
        const axutil_env_t *env)
{

    int size = axutil_array_list_size(arraylist,env);
    int i = 0;

    if (axutil_array_list_ensure_capacity(neethi_policy->policy_components , env, size + 1) != AXIS2_SUCCESS)
            return AXIS2_FAILURE;

    for(i=0; i<size; i++)
    {
        void *value = NULL;
        value = axutil_array_list_get(arraylist ,env ,i);
        neethi_operator_increment_ref((neethi_operator_t *)value, env);
        axutil_array_list_add(neethi_policy->policy_components, env, value);
    }
    return AXIS2_SUCCESS;
}



AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_policy_add_operator(neethi_policy_t *neethi_policy,
            const axutil_env_t *env,
            neethi_operator_t *operator)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    neethi_operator_increment_ref(operator, env);
    axutil_array_list_add(neethi_policy->policy_components, env, operator);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_policy_is_empty(neethi_policy_t *neethi_policy,
            const axutil_env_t *env)
            
{
    return axutil_array_list_is_empty(neethi_policy->policy_components , env);
}

AXIS2_EXTERN neethi_exactlyone_t *AXIS2_CALL 
neethi_policy_get_exactlyone(
    neethi_policy_t *normalized_neethi_policy,
    const axutil_env_t *env)
{
    neethi_exactlyone_t *exactlyone = NULL;
    axutil_array_list_t *list = NULL;

    list = neethi_policy_get_policy_components(normalized_neethi_policy,env);
    if(list)
    {
        if(axutil_array_list_size(list,env)==1)
        {
            neethi_operator_t *op = NULL;
            op = (neethi_operator_t *)axutil_array_list_get(list,env,0);
            if(!op)
            {
                /*printf("Error in normalized neethi_policy\n");*/
                return NULL;
            }               
            if(neethi_operator_get_type(op,env) != OPERATOR_TYPE_EXACTLYONE)
            {
                /*printf("Error in normalized neethi_policy\n");*/
                return NULL;
            }               
            exactlyone = (neethi_exactlyone_t *)neethi_operator_get_value(op,env);
            /*neethi_operator_set_value_null(op, env);
            neethi_operator_free(op, env);
            op = NULL;*/
            return exactlyone;
        }            
        else
            return NULL;
    }        
    else
        return NULL;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
neethi_policy_get_alternatives(
    neethi_policy_t *neethi_policy,
    const axutil_env_t *env)
{

    /*neethi_policy_t *normalized = NULL;*/
    neethi_exactlyone_t *exactlyone = NULL;

    /*normalized = neethi_engine_get_normalize(env, AXIS2_FALSE, neethi_policy);*/

    /*if(!normalized)
        return NULL;*/

    exactlyone = neethi_policy_get_exactlyone(neethi_policy, env);
    if(!exactlyone)
        return NULL;
    
   return neethi_exactlyone_get_policy_components(exactlyone, env);

}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
neethi_policy_get_name(
    neethi_policy_t *neethi_policy,
    const axutil_env_t *env)
{
    
    AXIS2_ENV_CHECK(env, NULL);
    return neethi_policy->name;    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_policy_set_name(
    neethi_policy_t *neethi_policy,
    const axutil_env_t *env,
    axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    neethi_policy->name = name;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
neethi_policy_get_id(
    neethi_policy_t *neethi_policy,
    const axutil_env_t *env)
{
    
    AXIS2_ENV_CHECK(env, NULL);
    return neethi_policy->id;    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_policy_set_id(
    neethi_policy_t *neethi_policy,
    const axutil_env_t *env,
    axis2_char_t *id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    neethi_policy->id = id;
    return AXIS2_SUCCESS;
}


/*This function is for serializing*/
AXIS2_EXTERN axiom_node_t *AXIS2_CALL
neethi_policy_serialize(
    neethi_policy_t *neethi_policy,
    axiom_node_t *parent,
    const axutil_env_t *env)
{

    axiom_node_t *policy_node = NULL;
    axiom_element_t *policy_ele = NULL;
    axiom_namespace_t *policy_ns = NULL;
    axutil_array_list_t *components = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    policy_ns = axiom_namespace_create(env, NEETHI_NAMESPACE,
                                        NEETHI_PREFIX);

    policy_ele = axiom_element_create(env, parent, NEETHI_POLICY, policy_ns, &policy_node);
    if (!policy_ele)
    {
        /*printf("Policy element serialization failed.\n");*/
        return NULL;
    }

    components = neethi_policy_get_policy_components(neethi_policy, env);

    if(components)
    {
        int i=0;
        for (i = 0; i < axutil_array_list_size(components ,
                env); i++)
        {
            neethi_operator_t *operator = NULL;
            operator = (neethi_operator_t *)axutil_array_list_get(components, env, i);           
            if(operator)
            {
                status = neethi_operator_serialize(operator, env, policy_node);
                if(status != AXIS2_SUCCESS)
                {
                    /*printf("Operator Serializing failed\n");*/
                    return NULL;
                }
            }
        }        
    } 
    return policy_node;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_policy_set_components_null(
    neethi_policy_t *policy,
    const axutil_env_t *env)
{
    policy->policy_components = NULL;
    return AXIS2_SUCCESS;
}




