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

#include <rp_https_token_builder.h>
#include <neethi_operator.h>
#include <neethi_policy.h>
#include <neethi_exactlyone.h>
#include <neethi_all.h>
#include <neethi_engine.h>



AXIS2_EXTERN neethi_assertion_t *AXIS2_CALL 
rp_https_token_builder_build(
        const axutil_env_t *env,
        axiom_node_t *node,
        axiom_element_t *element)
{
    rp_https_token_t *https_token = NULL;
    neethi_assertion_t *assertion = NULL;
    axis2_char_t *value = NULL;

    https_token = rp_https_token_create(env);

    value = axiom_element_get_attribute_value_by_name(element, env, RP_REQUIRE_CLIENT_CERTIFICATE);

    if(value)
    {
        if(axutil_strcmp(value,"true")==0)
        {
            rp_https_token_set_require_client_certificate(https_token,env,AXIS2_TRUE);
        }
        else if(axutil_strcmp(value,"false")==0)
        {
            rp_https_token_set_require_client_certificate(https_token,env,AXIS2_FALSE);
        }
        else return NULL;
    }
    /*assertion = neethi_assertion_create(env);
    neethi_assertion_set_value(assertion, env, https_token, ASSERTION_TYPE_HTTPS_TOKEN);
    */
    assertion = neethi_assertion_create_with_args(env, (void *)rp_https_token_free, https_token, ASSERTION_TYPE_HTTPS_TOKEN);    
    return assertion;
}
