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


#include <rp_header.h>

struct rp_header_t
{
    axis2_char_t *name;
    axis2_char_t *namespace;
};

AXIS2_EXTERN rp_header_t *AXIS2_CALL 
rp_header_create(const axutil_env_t *env)
{
    rp_header_t *header = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    header =  (rp_header_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_header_t));

    if(header == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    header->name = NULL;
    header->namespace = NULL;
    
    return header;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_header_free(rp_header_t *header,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(header)
    {
        AXIS2_FREE(env->allocator, header);
        header = NULL;
    }
    return AXIS2_SUCCESS;
}


/* Implementations */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_header_get_name(rp_header_t *header,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
   
    return header->name;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_header_set_name(rp_header_t *header,
            const axutil_env_t *env,
            axis2_char_t *name)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,name,AXIS2_FAILURE);   
    
    header->name = name;
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL 
rp_header_get_namespace(rp_header_t *header,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return header->namespace;
    
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_header_set_namespace(rp_header_t *header,
            const axutil_env_t *env,
            axis2_char_t *namespace)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,namespace,AXIS2_FAILURE);   

    header->namespace = namespace;

    return AXIS2_SUCCESS;

}


