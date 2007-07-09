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



#include <rp_transport_binding.h>

struct rp_transport_binding_t
{
    rp_binding_commons_t *binding_commons;
    rp_property_t *transport_token;
};

AXIS2_EXTERN rp_transport_binding_t *AXIS2_CALL 
rp_transport_binding_create(const axutil_env_t *env)
{
    rp_transport_binding_t *transport_binding = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    transport_binding =  (rp_transport_binding_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_transport_binding_t));

    if(transport_binding == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    transport_binding->binding_commons = NULL;
    transport_binding->transport_token = NULL;
    
    return transport_binding;

}

AXIS2_EXTERN void AXIS2_CALL 
rp_transport_binding_free(
    rp_transport_binding_t *transport_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(transport_binding)
    {
        if(transport_binding->binding_commons)
        {
            rp_binding_commons_free(transport_binding->binding_commons,env);
            transport_binding->binding_commons=NULL;
        }
        if(transport_binding->transport_token)
        {
            rp_property_free(transport_binding->transport_token,env);
            transport_binding->transport_token = NULL;
        }
        AXIS2_FREE(env->allocator,transport_binding);           
    }

    return;
}


/* Implementations */

AXIS2_EXTERN rp_binding_commons_t *AXIS2_CALL
rp_transport_binding_get_binding_commons(
    rp_transport_binding_t *transport_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return transport_binding->binding_commons;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_transport_binding_set_binding_commons(
    rp_transport_binding_t *transport_binding,
    const axutil_env_t *env,
    rp_binding_commons_t *binding_commons)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,binding_commons,AXIS2_FAILURE);
        
    transport_binding->binding_commons=binding_commons;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN rp_property_t *AXIS2_CALL
rp_transport_binding_get_transport_token(
    rp_transport_binding_t *transport_binding,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    
    return transport_binding->transport_token;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_transport_binding_set_transport_token(
    rp_transport_binding_t *transport_binding,
    const axutil_env_t *env,
    rp_property_t *transport_token)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,transport_token,AXIS2_FAILURE);
    
    transport_binding->transport_token = transport_token; 
    return AXIS2_SUCCESS;
}
