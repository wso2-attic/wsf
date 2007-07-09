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



#include <neethi_assertion_builder.h>


AXIS2_EXTERN neethi_assertion_t * AXIS2_CALL
neethi_assertion_builder_build(
    const axutil_env_t *env,
    axiom_node_t *node,
    axiom_element_t *element)
{
    
    axis2_char_t *localname = NULL;

    localname = axiom_element_get_localname(element,env);
    if(!localname)
    {
        return NULL;
    }        
    
    if(axutil_strcmp(localname, RP_TRANSPORT_BINDING) ==0 )
    {
        if(rp_match_secpolicy_qname(env, RP_TRANSPORT_BINDING, node, element))
        {
            return rp_transport_binding_builder_build(env, node, element);
        }
        else return NULL;
    }
   
    if(axutil_strcmp(localname, RP_ASYMMETRIC_BINDING) ==0 )
    {
        if(rp_match_secpolicy_qname(env, RP_ASYMMETRIC_BINDING, node, element))
        {
            return rp_asymmetric_binding_builder_build(env, node, element);
        }
        else return NULL;
    }        

    else if(axutil_strcmp(localname, RP_TRANSPORT_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_TRANSPORT_TOKEN, node, element))
        {
            return rp_transport_token_builder_build(env, node, element);
        }            
        else return NULL;
    }
    
    else if(axutil_strcmp(localname,RP_RECIPIENT_TOKEN )==0)
    {
        if(rp_match_secpolicy_qname(env, RP_RECIPIENT_TOKEN, node, element))
        {
            return rp_recipient_token_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_INITIATOR_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_INITIATOR_TOKEN, node, element))
        {
            return rp_initiator_token_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_X509_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_X509_TOKEN, node, element))
        {
            return rp_x509_token_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_ENCRYPT_BEFORE_SIGNING)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_ENCRYPT_BEFORE_SIGNING, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_ENCRYPT_BEFORE_SIGNING);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_SIGN_BEFORE_ENCRYPTING)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_SIGN_BEFORE_ENCRYPTING, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL,ASSERTION_TYPE_SIGN_BEFORE_ENCRYPTING);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_ENCRYPT_SIGNATURE)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_ENCRYPT_SIGNATURE, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_ENCRYPT_SIGNATURE);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_PROTECT_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_PROTECT_TOKENS, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_PROTECT_TOKENS);
            return assertion;
        }
        else return NULL;
    }    
    else if(axutil_strcmp(localname, RP_ONLY_SIGN_ENTIRE_HEADERS_AND_BODY)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_ONLY_SIGN_ENTIRE_HEADERS_AND_BODY, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_ONLY_SIGN_ENTIRE_HEADERS_AND_BODY);
            return assertion;
        }
        else return NULL;
    } 
    else if(axutil_strcmp(localname, RP_REQUIRE_KEY_IDENTIFIRE_REFERENCE)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_REQUIRE_KEY_IDENTIFIRE_REFERENCE, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_REQUIRE_KEY_IDENTIFIRE_REFERENCE);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_REQUIRE_ISSUER_SERIAL_REFERENCE)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_REQUIRE_ISSUER_SERIAL_REFERENCE, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_REQUIRE_ISSUER_SERIAL_REFERENCE);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_REQUIRE_EMBEDDED_TOKEN_REFERENCE)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_REQUIRE_EMBEDDED_TOKEN_REFERENCE, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_REQUIRE_EMBEDDED_TOKEN_REFERENCE);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_REQUIRE_THUMBPRINT_REFERENCE)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_REQUIRE_THUMBPRINT_REFERENCE, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_REQUIRE_THUMBPRINT_REFERENCE);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_WSS_X509_V1_TOKEN_10)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_WSS_X509_V1_TOKEN_10, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_WSS_X509_V1_TOKEN_10);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_WSS_X509_V3_TOKEN_10)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_WSS_X509_V3_TOKEN_10, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_WSS_X509_V3_TOKEN_10);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_ALGORITHM_SUITE)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_ALGORITHM_SUITE, node, element))
        {
            return rp_algorithmsuite_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_LAYOUT)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_LAYOUT, node, element))
        {
            return rp_layout_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_USERNAME_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_USERNAME_TOKEN, node, element))
        {
            return rp_username_token_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_SIGNED_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_SIGNED_SUPPORTING_TOKENS, node, element))
        {
            return rp_supporting_tokens_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_SIGNED_ENDORSING_SUPPORTING_TOKENS)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_SIGNED_ENDORSING_SUPPORTING_TOKENS, node, element))
        {
            return rp_supporting_tokens_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_WSS10)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_WSS10, node, element))
        {
            return rp_wss10_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_INCLUDE_TIMESTAMP)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_INCLUDE_TIMESTAMP, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_INCLUDE_TIMESTAMP);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_HTTPS_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_HTTPS_TOKEN, node, element))
        {
            return rp_https_token_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_WSS_USERNAME_TOKEN_10)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_WSS_USERNAME_TOKEN_10, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_WSS_USERNAME_TOKEN_10);
            return assertion;
        }
        else return NULL;
    }        
    else if(axutil_strcmp(localname, RP_WSS_USERNAME_TOKEN_11)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_WSS_USERNAME_TOKEN_11, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_WSS_USERNAME_TOKEN_11);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_MUST_SUPPORT_REF_KEY_IDENTIFIER)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_MUST_SUPPORT_REF_KEY_IDENTIFIER, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_MUST_SUPPORT_REF_KEY_IDENTIFIER);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_MUST_SUPPORT_REF_ISSUER_SERIAL)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_MUST_SUPPORT_REF_ISSUER_SERIAL, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_MUST_SUPPORT_REF_ISSUER_SERIAL);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_MUST_SUPPORT_REF_EXTERNAL_URI)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_MUST_SUPPORT_REF_EXTERNAL_URI, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_MUST_SUPPORT_REF_EXTERNAL_URI);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_MUST_SUPPORT_REF_EMBEDDED_TOKEN)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_MUST_SUPPORT_REF_EMBEDDED_TOKEN, node, element))
        {
            neethi_assertion_t *assertion = NULL;
            assertion = neethi_assertion_create(env);
            neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_MUST_SUPPORT_REF_EMBEDDED_TOKEN);
            return assertion;
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_SIGNED_PARTS)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_SIGNED_PARTS, node, element))
        {
            return rp_signed_encrypted_parts_builder_build(env, node, element);
        }
        else return NULL;
    }
    else if(axutil_strcmp(localname, RP_ENCRYPTED_PARTS)==0)
    {
        if(rp_match_secpolicy_qname(env, RP_ENCRYPTED_PARTS, node, element))
        {
            return rp_signed_encrypted_parts_builder_build(env, node, element);
        }
        else return NULL;
    }       
    else if(axutil_strcmp(localname, RP_RAMPART_CONFIG)==0)
    {
        if(rp_match_rampart_config_qname(env, RP_RAMPART_CONFIG, node, element))
        {
            return rp_rampart_config_builder_build(env, node, element);
        }
        else return NULL;
    }
    else 
    {
        neethi_assertion_t *assertion = NULL;
        assertion = neethi_assertion_create(env);
        neethi_assertion_set_value(assertion, env, NULL, ASSERTION_TYPE_UNKNOWN);
        neethi_assertion_set_element(assertion, env, element);        
        neethi_assertion_set_node(assertion, env, node);
        return assertion;
    }
}
