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



#include <neethi_operator.h>
#include <neethi_policy.h>
#include <neethi_exactlyone.h>
#include <neethi_all.h>
#include <neethi_reference.h>
#include <neethi_assertion.h>

struct neethi_operator_t
{
    void *value;
    neethi_operator_type_t type;
    int ref;
};

AXIS2_EXTERN neethi_operator_t *AXIS2_CALL 
neethi_operator_create(const axutil_env_t *env)
{
    neethi_operator_t *neethi_operator = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    neethi_operator =  (neethi_operator_t *) AXIS2_MALLOC (env->allocator,
    sizeof (neethi_operator_t));

    if(neethi_operator == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    neethi_operator->value = NULL;
    neethi_operator->type = OPERATOR_TYPE_UNKNOWN;
    neethi_operator->ref = 0;
    return neethi_operator;

}

AXIS2_EXTERN void AXIS2_CALL 
neethi_operator_free(neethi_operator_t *neethi_operator,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(neethi_operator)
    {
        if (--(neethi_operator->ref) > 0)
        {
            return;
        }
               
        if(neethi_operator->value)
        {
            switch(neethi_operator->type)
            {
                case OPERATOR_TYPE_POLICY:
                    neethi_policy_free((neethi_policy_t *)neethi_operator->value,env);
                    neethi_operator->value = NULL;
                    break;

                case OPERATOR_TYPE_ALL:
                    neethi_all_free((neethi_all_t *)neethi_operator->value,env);
                    neethi_operator->value = NULL;
                    break;

                case OPERATOR_TYPE_EXACTLYONE:
                    neethi_exactlyone_free((neethi_exactlyone_t *)neethi_operator->value,env);
                    neethi_operator->value = NULL;
                    break;
                
                case OPERATOR_TYPE_REFERENCE:
                    neethi_reference_free((neethi_reference_t *)neethi_operator->value,env);
                    neethi_operator->value = NULL;
                    break;
   
                case OPERATOR_TYPE_ASSERTION:
                    neethi_assertion_free((neethi_assertion_t *)neethi_operator->value,env);
                    neethi_operator->value = NULL;
                    break;
                
                case OPERATOR_TYPE_UNKNOWN:
                    break;
            }
            /*AXIS2_FREE(env->allocator,neethi_operator->value);*/     
        }
        AXIS2_FREE(env->allocator, neethi_operator);
    }
    return; 
}


/* Implementations */

AXIS2_EXTERN neethi_operator_type_t AXIS2_CALL 
neethi_operator_get_type(neethi_operator_t *neethi_operator,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return neethi_operator->type;
}

AXIS2_EXTERN void *AXIS2_CALL
neethi_operator_get_value(
    neethi_operator_t *neethi_operator,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return neethi_operator->value;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_operator_set_value(neethi_operator_t *neethi_operator,
    const axutil_env_t *env,
    void *value,
    neethi_operator_type_t type)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    neethi_operator->type = type;
    neethi_operator->value =(void *)value;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_operator_serialize(
    neethi_operator_t *neethi_operator,
    const axutil_env_t *env,
    axiom_node_t *parent)
{

    neethi_policy_t *policy = NULL;
    neethi_all_t *all = NULL;
    neethi_exactlyone_t *exactlyone = NULL;
    neethi_reference_t *reference = NULL;
    neethi_assertion_t *assertion = NULL;

    if(neethi_operator->value)
    {
        switch(neethi_operator->type)
        {
            case OPERATOR_TYPE_POLICY:
                policy = (neethi_policy_t *)neethi_operator_get_value(neethi_operator, env);
                if(!neethi_policy_serialize(policy, parent, env))
                {                    
                    return AXIS2_FAILURE;
                }    
                else
                {    
                    return AXIS2_SUCCESS;
                }    
                break;

            case OPERATOR_TYPE_ALL:
                all = (neethi_all_t *)neethi_operator_get_value(neethi_operator, env);
                return neethi_all_serialize(all, parent, env);
                break;

            case OPERATOR_TYPE_EXACTLYONE:
                exactlyone = (neethi_exactlyone_t *)neethi_operator_get_value(neethi_operator, env);
                return neethi_exactlyone_serialize(exactlyone, parent, env);
                break;

            case OPERATOR_TYPE_REFERENCE:
                reference = (neethi_reference_t *)neethi_operator_get_value(neethi_operator, env);
                return neethi_reference_serialize(reference, parent, env);
                break;

            case OPERATOR_TYPE_ASSERTION:
                assertion = (neethi_assertion_t *)neethi_operator_get_value(neethi_operator, env);
                return neethi_assertion_serialize(assertion, parent, env);
                break;

            case OPERATOR_TYPE_UNKNOWN:
                break;
        }
        return AXIS2_SUCCESS;
    }
    else return AXIS2_FAILURE;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_operator_set_value_null(
    neethi_operator_t *neethi_operator,
    const axutil_env_t *env)
{
    neethi_operator->value = NULL;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_operator_increment_ref(neethi_operator_t *operator,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    operator->ref++;
    return AXIS2_SUCCESS;
}
