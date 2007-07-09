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



#include <neethi_reference.h>

struct neethi_reference_t
{
    axis2_char_t *uri;
};

AXIS2_EXTERN neethi_reference_t *AXIS2_CALL 
neethi_reference_create(const axutil_env_t *env)
{
    neethi_reference_t *neethi_reference = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    neethi_reference =  (neethi_reference_t *) AXIS2_MALLOC (env->allocator,
    sizeof (neethi_reference_t));

    if(neethi_reference == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    neethi_reference->uri = NULL;

    return neethi_reference;
}

AXIS2_EXTERN void AXIS2_CALL 
neethi_reference_free(neethi_reference_t *neethi_reference,
        const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(neethi_reference)
    {        
        AXIS2_FREE(env->allocator,neethi_reference);
        neethi_reference = NULL;
    }
    return;
}


/* Implementations */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
neethi_reference_get_uri(
    neethi_reference_t *neethi_reference,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    return neethi_reference->uri;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
neethi_reference_set_uri(
        neethi_reference_t *neethi_reference,
        const axutil_env_t *env,
        axis2_char_t *uri)
{

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    neethi_reference->uri = uri;
    return AXIS2_SUCCESS;
}



AXIS2_EXTERN axis2_status_t AXIS2_CALL
neethi_reference_serialize(
    neethi_reference_t *neethi_reference,
    axiom_node_t *parent,
    const axutil_env_t *env)
{

    axiom_node_t *ref_node = NULL;
    axiom_element_t *ref_ele = NULL;
    axiom_namespace_t *policy_ns = NULL;
    axiom_attribute_t *att_uri = NULL;
    

    policy_ns = axiom_namespace_create(env, NEETHI_NAMESPACE,
                                    NEETHI_PREFIX);

    ref_ele = axiom_element_create(env, parent, NEETHI_REFERENCE, policy_ns, &ref_node);
    if (!ref_node)
    {
        /*printf("Reference serialization failed\n");*/
        return AXIS2_FAILURE;
    }
        
    att_uri = axiom_attribute_create(env, NEETHI_URI, neethi_reference->uri, NULL);
    axiom_element_add_attribute(ref_ele, env, att_uri, ref_node);

    return AXIS2_SUCCESS;
        
}
