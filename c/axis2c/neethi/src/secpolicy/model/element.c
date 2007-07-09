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


#include <rp_element.h>

struct rp_element_t
{
    axis2_char_t *name;
    axis2_char_t *namespace;
};

AXIS2_EXTERN rp_element_t *AXIS2_CALL 
rp_element_create(const axutil_env_t *env)
{
    rp_element_t *element = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    element =  (rp_element_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_element_t));

    if(element == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    element->name = NULL;
    element->namespace = NULL;
    
    return element;

}

AXIS2_EXTERN void AXIS2_CALL 
rp_element_free(rp_element_t *element,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(element)
    {
        AXIS2_FREE(env->allocator, element);
        element = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_element_get_name(rp_element_t *element,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
   
    return element->name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_element_set_name(rp_element_t *element,
            const axutil_env_t *env,
            axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,name,AXIS2_FAILURE);   
    
    element->name = name;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_element_get_namespace(rp_element_t *element,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return element->namespace;
    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_element_set_namespace(rp_element_t *element,
            const axutil_env_t *env,
            axis2_char_t *namespace)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,namespace,AXIS2_FAILURE);   

    element->namespace = namespace;

    return AXIS2_SUCCESS;

}


