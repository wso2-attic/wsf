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

#include <rp_token_identifier.h>
#include <neethi_operator.h>
#include <neethi_policy.h>
#include <neethi_assertion.h>
#include <neethi_exactlyone.h>
#include <neethi_all.h>
#include <neethi_engine.h>

/*private functions*/


/***********************************/


AXIS2_EXTERN axis2_status_t AXIS2_CALL 
rp_token_identifier_set_token(
        rp_property_t *token,
        neethi_assertion_t *assertion,
        const axutil_env_t *env)
{
    void *value = NULL;
    neethi_assertion_type_t type;

    value = neethi_assertion_get_value(assertion, env);
    type = neethi_assertion_get_type(assertion, env);

    if(value)
    {
        if(type == ASSERTION_TYPE_USERNAME_TOKEN)
        {
            rp_username_token_t *username_token = NULL;
            username_token = (rp_username_token_t *)value;
            rp_property_set_value(token, env, username_token, RP_TOKEN_USERNAME);
            return AXIS2_SUCCESS;
        }            
        else if(type == ASSERTION_TYPE_X509_TOKEN)
        {
            rp_x509_token_t *x509_token = NULL;
            x509_token = (rp_x509_token_t *)value;
            rp_property_set_value(token, env, x509_token, RP_TOKEN_X509);
            return AXIS2_SUCCESS;
        }
        else
            return AXIS2_FAILURE;
    }        
    else return AXIS2_FAILURE;
}
