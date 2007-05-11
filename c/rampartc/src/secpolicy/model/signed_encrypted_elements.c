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



#include <rp_signed_encrypted_elements.h>

struct rp_signed_encrypted_elements_t
{
    axis2_bool_t signedelements;
    axutil_array_list_t *xpath_expressions;
    axis2_char_t *xpath_version;

};

AXIS2_EXTERN rp_signed_encrypted_elements_t *AXIS2_CALL 
rp_signed_encrypted_elements_create(const axutil_env_t *env)
{
    rp_signed_encrypted_elements_t *signed_encrypted_elements = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    signed_encrypted_elements =  (rp_signed_encrypted_elements_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_signed_encrypted_elements_t));

    if(signed_encrypted_elements == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    signed_encrypted_elements->xpath_expressions = NULL;

    signed_encrypted_elements->xpath_expressions = axutil_array_list_create(env, 0);
    if (!(signed_encrypted_elements->xpath_expressions))
    {
        rp_signed_encrypted_elements_free(signed_encrypted_elements, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    signed_encrypted_elements->xpath_version = NULL;

    return signed_encrypted_elements;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_signed_encrypted_elements_free(rp_signed_encrypted_elements_t *signed_encrypted_elements,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(signed_encrypted_elements)
    {
        
        if(signed_encrypted_elements->xpath_expressions)
        {
            int i = 0;
            for (i = 0; i < axutil_array_list_size(signed_encrypted_elements->xpath_expressions,
                env); i++)
            {
                axis2_char_t *expression = NULL;
                expression = (axis2_char_t *)
                    axutil_array_list_get(signed_encrypted_elements->xpath_expressions,env, i);
                if (expression)
                    AXIS2_FREE(env->allocator,expression);

                expression = NULL;
            }
            axutil_array_list_free(signed_encrypted_elements->xpath_expressions, env);
            signed_encrypted_elements->xpath_expressions = NULL;

        }
        AXIS2_FREE(env->allocator,signed_encrypted_elements);
        signed_encrypted_elements = NULL;
    }
    return AXIS2_SUCCESS;
}


/* Implementations */

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_signed_encrypted_elements_get_signedelements(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
     return signed_encrypted_elements->signedelements;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_signed_encrypted_elements_set_signedelements(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env,
            axis2_bool_t signedelements)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signedelements,AXIS2_FAILURE);

    signed_encrypted_elements->signedelements = signedelements;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
rp_signed_encrypted_elements_get_xpath_expressions(
    rp_signed_encrypted_elements_t *signed_encrypted_elements,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return signed_encrypted_elements->xpath_expressions;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_signed_encrypted_elements_add_expression(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env,
            axis2_char_t *expression)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,expression,AXIS2_FAILURE);

    axutil_array_list_add(signed_encrypted_elements->xpath_expressions,env,expression);    
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_char_t *AXIS2_CALL
rp_signed_encrypted_elements_get_xpath_version(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return signed_encrypted_elements->xpath_version;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_signed_encrypted_elements_set_xpath_version(rp_signed_encrypted_elements_t *signed_encrypted_elements,
            const axutil_env_t *env,
            axis2_char_t *xpath_version)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,xpath_version,AXIS2_FAILURE);

    signed_encrypted_elements->xpath_version = xpath_version;
    return AXIS2_SUCCESS;
}
