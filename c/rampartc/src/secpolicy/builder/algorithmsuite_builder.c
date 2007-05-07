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


#include <rp_algorithmsuite_builder.h>
#include <rp_qname_matcher.h>


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_builder_set_algosuite(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *algosuite_string,
        rp_algorithmsuite_t *algorithmsuite,
        const axutil_env_t *env);


AXIS2_EXTERN rp_algorithmsuite_t *AXIS2_CALL
rp_algorithmsuite_builder_build(
            const axutil_env_t *env,
            axiom_node_t *algorithmsuite)
{
    rp_algorithmsuite_t *algorithm_suite = NULL;
    axiom_node_t *policy = NULL;
    axiom_node_t *name = NULL;
    axiom_element_t *name_ele = NULL;
    axis2_char_t * algosuite_string = NULL;
    axis2_status_t status = AXIS2_SUCCESS;

    AXIS2_ENV_CHECK(env,NULL);
    AXIS2_PARAM_CHECK(env->error,algorithmsuite,NULL);

    if(algorithmsuite)
    {
        policy = axiom_node_get_first_element(algorithmsuite,env);
        if(policy)
        {
            name = axiom_node_get_first_element(policy,env);
            if(name)
            {
                if(axiom_node_get_node_type(name,env) == AXIOM_ELEMENT)
                {
                    name_ele = (axiom_element_t*)axiom_node_get_data_element(name, env);
                    if(name_ele)
                    {
                        algosuite_string = axiom_element_get_localname(name_ele, env);
                        if(algosuite_string)
                        {   
                            algorithm_suite = rp_algorithmsuite_create(env);
                            if(!algorithm_suite)
                                return NULL;
                            
                            status = rp_algorithmsuite_builder_set_algosuite(name,name_ele,algosuite_string,algorithm_suite,env);                                       if(status!=AXIS2_SUCCESS)
                            {
                                rp_algorithmsuite_free(algorithm_suite,env);
                                algorithm_suite = NULL;
                            }                                
                        }
                    }
                }
            }
        }
   }
   return algorithm_suite;
}            

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_algorithmsuite_builder_set_algosuite(
        axiom_node_t *node,
        axiom_element_t *element,
        axis2_char_t *algosuite_string,
        rp_algorithmsuite_t *algorithmsuite,
        const axutil_env_t *env)

{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);
    
    if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC256)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC256,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC192)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC192,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else 
            return AXIS2_FAILURE;
    }
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC128)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC128,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }        
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_TRIPLE_DES)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_TRIPLE_DES,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }       
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC256_RSA15)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC256_RSA15,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC192_RSA15)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC192_RSA15,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC128_RSA15)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC128_RSA15,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else  if(strcmp(algosuite_string,RP_ALGO_SUITE_TRIPLE_DES_RSA15)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_TRIPLE_DES_RSA15,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC256_SHA256)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC256_SHA256,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC192_SHA256)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC192_SHA256,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC128_SHA256)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC128_SHA256,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_TRIPLE_DES_SHA256)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_TRIPLE_DES_SHA256,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC256_SHA256_RSA15)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC256_SHA256_RSA15,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC192_SHA256_RSA15)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC192_SHA256_RSA15,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_BASIC128_SHA256_RSA15)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC128_SHA256_RSA15,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_ALGO_SUITE_TRIPLE_DES_SHA256_RSA15)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGO_SUITE_BASIC256_RSA15,node,element))
        {
            rp_algorithmsuite_set_algosuite(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }
    else if(strcmp(algosuite_string,RP_INCLUSIVE_C14N)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_INCLUSIVE_C14N,node,element))
        {
            rp_algorithmsuite_set_c14n(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_SOAP_NORMALIZATION_10)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SOAP_NORMALIZATION_10,node,element))
        {
            rp_algorithmsuite_set_soap_normalization(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_STR_TRANSFORM_10)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_STR_TRANSFORM_10,node,element))
        {
            rp_algorithmsuite_set_str_transformation(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else if(strcmp(algosuite_string,RP_XPATH10)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_XPATH10,node,element))
        {
            rp_algorithmsuite_set_xpath(algorithmsuite,env,algosuite_string);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    } 
    else
        return AXIS2_FAILURE;
}
