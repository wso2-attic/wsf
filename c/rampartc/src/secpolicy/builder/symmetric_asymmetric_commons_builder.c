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


#include <rp_symmetric_asymmetric_commons_builder.h>
#include <rp_qname_matcher.h>

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rp_symmetric_asymmetric_commons_builder_build(
            const axutil_env_t *env,
            axiom_node_t *node,
            axiom_element_t *element,
            axis2_char_t *local_name,    
            rp_symmetric_asymmetric_binding_commons_t *as_commons,
            rp_binding_commons_t *commons)
{
    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);

    if(axutil_strcmp(local_name,RP_ENCRYPT_BEFORE_SIGNING)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ENCRYPT_BEFORE_SIGNING,node,element))
        {            
            rp_symmetric_asymmetric_binding_commons_set_protection_order(as_commons,env,local_name);
            return AXIS2_SUCCESS;
        }
        return AXIS2_FAILURE;
    }        
    
    else if(axutil_strcmp(local_name,RP_ENCRYPT_SIGNATURE)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ENCRYPT_SIGNATURE,node,element))
        {
            rp_symmetric_asymmetric_binding_commons_set_signature_protection(as_commons,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        return AXIS2_FAILURE;
    }
    
    else if(axutil_strcmp(local_name,RP_PROTECT_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_PROTECT_TOKENS,node,element))
        {
            rp_symmetric_asymmetric_binding_commons_set_token_protection(as_commons,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        return AXIS2_FAILURE;
    }

    else if(axutil_strcmp(local_name,RP_ONLY_SIGN_ENTIRE_HEADERS_AND_BODY)==0)
    {
        if(rp_match_secpolicy_qname(env,RP_ONLY_SIGN_ENTIRE_HEADERS_AND_BODY,node,element))
        {
            rp_symmetric_asymmetric_binding_commons_set_entire_headers_and_body_signatures(as_commons,env,AXIS2_TRUE);
            return AXIS2_SUCCESS;
        }
        return AXIS2_FAILURE;
    }
    else  
        return rp_binding_commons_builder_build(env,node,element,local_name,commons);
}

