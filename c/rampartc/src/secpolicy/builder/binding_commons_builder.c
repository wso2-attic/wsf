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


#include <rp_binding_commons_builder.h>
#include <rp_qname_matcher.h>
#include <rp_supporting_tokens_builder.h>

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_binding_commons_builder_build(
            const axutil_env_t *env,
            axiom_node_t *node,
            axiom_element_t *element,
            axis2_char_t *local_name,    
            rp_binding_commons_t *commons)
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,node,AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,element,AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,local_name,AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error,commons,AXIS2_FAILURE);

    if(axutil_strcmp(local_name,RP_ALGORITHM_SUITE)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ALGORITHM_SUITE,node,element))
        {            
            rp_algorithmsuite_t *algo_suite = NULL;
            algo_suite = rp_algorithmsuite_builder_build(env,node);
            if(algo_suite)
            {   
                rp_binding_commons_set_algorithmsuite(commons,env,algo_suite);
                return AXIS2_SUCCESS;
            } 
            else return AXIS2_FAILURE;
        }
        return AXIS2_FAILURE;
    }        
    else if(axutil_strcmp(local_name,RP_LAYOUT)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_LAYOUT,node,element))
        {            
            rp_layout_t *layout = NULL;
            layout = rp_layout_builder_build(env,node);
            if(layout)
            {                
                rp_binding_commons_set_layout(commons,env,layout);
                return AXIS2_SUCCESS;
            } 
            else return AXIS2_FAILURE;
        }
        return AXIS2_FAILURE;
    }        
    else if(axutil_strcmp(local_name,RP_INCLUDE_TIMESTAMP)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_INCLUDE_TIMESTAMP,node,element))
        {
            rp_binding_commons_set_include_timestamp(commons,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        } 
        return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_SIGNED_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SIGNED_SUPPORTING_TOKENS,node,element))
        {
            rp_supporting_tokens_t *signed_supporting_tokens = NULL;

            signed_supporting_tokens = rp_supporting_tokens_builder_build(env,node);
            if(!signed_supporting_tokens)
                return AXIS2_FAILURE;

            rp_supporting_tokens_set_type(signed_supporting_tokens,env,RP_SUPPORTING_SIGNED_SUPPORTING);

            return rp_binding_commons_set_signed_supporting_tokens(commons,env,signed_supporting_tokens);
        }
        else
            return AXIS2_FAILURE;

    }
    else if(axutil_strcmp(local_name,RP_SIGNED_ENDORSING_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SIGNED_ENDORSING_SUPPORTING_TOKENS,node,element))
        {
            rp_supporting_tokens_t *signed_endorsing_supporting_tokens = NULL;

            signed_endorsing_supporting_tokens = rp_supporting_tokens_builder_build(env,node);
            if(!signed_endorsing_supporting_tokens)
                return AXIS2_FAILURE;

            rp_supporting_tokens_set_type(signed_endorsing_supporting_tokens,env,RP_SUPPORTING_SIGNED_ENDORSING_SUPPORTING);

            return rp_binding_commons_set_signed_endorsing_supporting_tokens(commons,env,signed_endorsing_supporting_tokens);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_ENDORSING_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ENDORSING_SUPPORTING_TOKENS,node,element))
        {
            rp_supporting_tokens_t *endorsing_supporting_tokens = NULL;

            endorsing_supporting_tokens = rp_supporting_tokens_builder_build(env,node);
            if(!endorsing_supporting_tokens)
                return AXIS2_FAILURE;

            rp_supporting_tokens_set_type(endorsing_supporting_tokens,env,RP_SUPPORTING_ENDORSING_SUPPORTING);

            return rp_binding_commons_set_endorsing_supporting_tokens(commons,env,endorsing_supporting_tokens);
        }
        else
            return AXIS2_FAILURE;
    }
    else if(axutil_strcmp(local_name,RP_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_SUPPORTING_TOKENS,node,element))
        {
            rp_supporting_tokens_t *supporting_tokens = NULL;

            supporting_tokens = rp_supporting_tokens_builder_build(env,node);
            if(!supporting_tokens)
                return AXIS2_FAILURE;

            rp_supporting_tokens_set_type(supporting_tokens,env,RP_SUPPORTING_SUPPORTING);

            return rp_binding_commons_set_supporting_tokens(commons,env,supporting_tokens);
        }
        else
            return AXIS2_FAILURE;
    }    

    else
        return AXIS2_FAILURE;
}
