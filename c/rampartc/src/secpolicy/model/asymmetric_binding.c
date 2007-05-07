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


#include <rp_asymmetric_binding.h>

struct rp_asymmetric_binding_t
{
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons;
    rp_property_t *initiator_token;
    rp_property_t *recipient_token;
};

AXIS2_EXTERN rp_asymmetric_binding_t *AXIS2_CALL 
rp_asymmetric_binding_create(const axutil_env_t *env)
{
    rp_asymmetric_binding_t *asymmetric_binding = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    asymmetric_binding =  (rp_asymmetric_binding_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_asymmetric_binding_t));

    if(asymmetric_binding == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    asymmetric_binding->symmetric_asymmetric_binding_commons = NULL;
    asymmetric_binding->initiator_token = NULL;
    asymmetric_binding->recipient_token = NULL;
    
    return asymmetric_binding;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_asymmetric_binding_free(
    rp_asymmetric_binding_t *asymmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(asymmetric_binding)
    {
        if(asymmetric_binding->symmetric_asymmetric_binding_commons)
        {
            rp_symmetric_asymmetric_binding_commons_free(
                asymmetric_binding->symmetric_asymmetric_binding_commons,
                env);
            asymmetric_binding->symmetric_asymmetric_binding_commons=NULL;
        }
        if(asymmetric_binding->initiator_token)
        {
            rp_property_free(asymmetric_binding->initiator_token,env);
            asymmetric_binding->initiator_token = NULL;
        }
        if(asymmetric_binding->recipient_token)
        {
            rp_property_free(asymmetric_binding->recipient_token,env);            
            asymmetric_binding->recipient_token = NULL;
        }
        AXIS2_FREE(env->allocator,asymmetric_binding);           
    }

    return AXIS2_SUCCESS;
}


/* Implementations */

AXIS2_EXTERN rp_symmetric_asymmetric_binding_commons_t *AXIS2_CALL
rp_asymmetric_binding_get_symmetric_asymmetric_binding_commons(
    rp_asymmetric_binding_t *asymmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return asymmetric_binding->symmetric_asymmetric_binding_commons;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_asymmetric_binding_set_symmetric_asymmetric_binding_commons(
    rp_asymmetric_binding_t *asymmetric_binding,
    const axutil_env_t *env,
    rp_symmetric_asymmetric_binding_commons_t *symmetric_asymmetric_binding_commons)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,symmetric_asymmetric_binding_commons,AXIS2_FAILURE);
        
    asymmetric_binding->symmetric_asymmetric_binding_commons
            =symmetric_asymmetric_binding_commons;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_asymmetric_binding_get_initiator_token(
    rp_asymmetric_binding_t *asymmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
        
    return asymmetric_binding->initiator_token;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_asymmetric_binding_set_initiator_token(rp_asymmetric_binding_t *asymmetric_binding,
    const axutil_env_t *env,
    rp_property_t *initiator_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,initiator_token,AXIS2_FAILURE);
    asymmetric_binding->initiator_token =initiator_token; 
    return AXIS2_SUCCESS;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_asymmetric_binding_set_recipient_token(
    rp_asymmetric_binding_t *asymmetric_binding,
    const axutil_env_t *env,
    rp_property_t *recipient_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,recipient_token,AXIS2_FAILURE);
    
    asymmetric_binding->recipient_token = recipient_token; 
    return AXIS2_SUCCESS;
    
}

AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_asymmetric_binding_get_recipient_token(
    rp_asymmetric_binding_t *asymmetric_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
        
    return asymmetric_binding->recipient_token;
}
