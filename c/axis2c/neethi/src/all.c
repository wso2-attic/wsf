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



#include <neethi_all.h>

struct neethi_all_t
{
    axutil_array_list_t *policy_components;
};

AXIS2_EXTERN neethi_all_t *AXIS2_CALL 
neethi_all_create(const axutil_env_t *env)
{
    neethi_all_t *neethi_all = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    neethi_all =  (neethi_all_t *) AXIS2_MALLOC (env->allocator,
    sizeof (neethi_all_t));

    if(neethi_all == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    neethi_all->policy_components = NULL;

    neethi_all->policy_components = axutil_array_list_create(env, 0);
    if (!(neethi_all->policy_components) )
    {
        neethi_all_free(neethi_all, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    return neethi_all;
}

AXIS2_EXTERN void AXIS2_CALL 
neethi_all_free(neethi_all_t *neethi_all,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(neethi_all)
    {
        if(neethi_all->policy_components)
        {
            int i = 0;
            for (i = 0; i < axutil_array_list_size(neethi_all->policy_components,
                env); i++)
            {
                neethi_operator_t *operator = NULL;
                operator = (neethi_operator_t *)
                    axutil_array_list_get(neethi_all->policy_components, env, i);
                if (operator)
                    neethi_operator_free(operator, env);

                operator = NULL;
            }
            axutil_array_list_free(neethi_all->policy_components , env);
            neethi_all->policy_components = NULL;
        }
        AXIS2_FREE(env->allocator, neethi_all);
        neethi_all = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
neethi_all_get_policy_components(
    neethi_all_t *neethi_all,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return neethi_all->policy_components;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_all_add_policy_components(
        neethi_all_t *all,
        axutil_array_list_t *arraylist,
        const axutil_env_t *env)
{

    int size = axutil_array_list_size(arraylist,env);
    int i = 0;    

    if (axutil_array_list_ensure_capacity(all->policy_components , env, size + 1) != AXIS2_SUCCESS)
            return AXIS2_FAILURE;
    
    for(i=0; i<size; i++)
    {
        void *value = NULL;
        value = axutil_array_list_get(arraylist ,env ,i);
        neethi_operator_increment_ref((neethi_operator_t *)value, env);
        axutil_array_list_add(all->policy_components, env, value);
    }
    return AXIS2_SUCCESS;
}



AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_all_add_operator(neethi_all_t *neethi_all,
            const axutil_env_t *env,
            neethi_operator_t *operator)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    neethi_operator_increment_ref(operator, env);
    axutil_array_list_add(neethi_all->policy_components, env, operator);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
neethi_all_is_empty(neethi_all_t *all,
            const axutil_env_t *env)

{
    return axutil_array_list_is_empty(all->policy_components , env);
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_all_serialize(
    neethi_all_t *neethi_all,
    axiom_node_t *parent,
    const axutil_env_t *env)
{

    axiom_node_t *all_node = NULL;
    axiom_element_t *all_ele = NULL;
    axiom_namespace_t *policy_ns = NULL;
    axutil_array_list_t *components = NULL;
    axis2_status_t status = AXIS2_FAILURE;


    policy_ns = axiom_namespace_create(env, NEETHI_NAMESPACE,
                                    NEETHI_PREFIX);

    all_ele = axiom_element_create(env, parent, NEETHI_ALL, policy_ns, &all_node);
    if (!all_node)
    {
        /*printf("Exactlyone serialization failed\n");*/
        return AXIS2_FAILURE;
    }
    components = neethi_all_get_policy_components(neethi_all, env);

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
                status = neethi_operator_serialize(operator, env, all_node);
                if(status != AXIS2_SUCCESS)
                {
                    /*printf("Operator Serializing failed\n");*/
                    return status;
                }
            }
        }
    }
    return status;
}

