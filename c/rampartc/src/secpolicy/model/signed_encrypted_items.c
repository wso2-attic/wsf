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



#include <rp_signed_encrypted_items.h>

struct rp_signed_encrypted_items_t
{
    axis2_bool_t signeditems;
    axutil_array_list_t *elements;

};

AXIS2_EXTERN rp_signed_encrypted_items_t *AXIS2_CALL 
rp_signed_encrypted_items_create(const axutil_env_t *env)
{
    rp_signed_encrypted_items_t *signed_encrypted_items = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    signed_encrypted_items =  (rp_signed_encrypted_items_t *) AXIS2_MALLOC (env->allocator,
    sizeof (rp_signed_encrypted_items_t));

    if(signed_encrypted_items == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    signed_encrypted_items->elements = NULL;

    signed_encrypted_items->elements = axutil_array_list_create(env, 0);
    if (!(signed_encrypted_items->elements) )
    {
        rp_signed_encrypted_items_free(signed_encrypted_items, env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return signed_encrypted_items;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_signed_encrypted_items_free(rp_signed_encrypted_items_t *signed_encrypted_items,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    if(signed_encrypted_items)
    {
        
        if(signed_encrypted_items->elements)
        {
            int i = 0;
            for (i = 0; i < axutil_array_list_size(signed_encrypted_items->elements,
                env); i++)
            {
                rp_element_t *element = NULL;
                element = (rp_element_t *)
                    axutil_array_list_get(signed_encrypted_items->elements,env, i);
                if (element)
                    rp_element_free(element, env);

                element = NULL;
            }
            axutil_array_list_free(signed_encrypted_items->elements, env);
            signed_encrypted_items->elements = NULL;

        }
        AXIS2_FREE(env->allocator,signed_encrypted_items);
        signed_encrypted_items = NULL;
    }
    return AXIS2_SUCCESS;
}


/* Implementations */

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
rp_signed_encrypted_items_get_signeditems(rp_signed_encrypted_items_t *signed_encrypted_items,
            const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
        
    return signed_encrypted_items->signeditems;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_signed_encrypted_items_set_signeditems(rp_signed_encrypted_items_t *signed_encrypted_items,
            const axutil_env_t *env,
            axis2_bool_t signeditems)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,signeditems,AXIS2_FAILURE);
    signed_encrypted_items->signeditems = signeditems;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
rp_signed_encrypted_items_get_elements(
    rp_signed_encrypted_items_t *signed_encrypted_items,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    
    return signed_encrypted_items->elements;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_signed_encrypted_items_add_element(rp_signed_encrypted_items_t *signed_encrypted_items,
            const axutil_env_t *env,
            rp_element_t *element)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,element,AXIS2_FAILURE);
        
    axutil_array_list_add(signed_encrypted_items->elements,env,element);    
    return AXIS2_SUCCESS;
}

