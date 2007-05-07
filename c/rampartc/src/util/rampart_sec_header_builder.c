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

#include <stdio.h>
#include <rampart_encryption.h>
#include <rampart_constants.h>
#include <rampart_sec_header_builder.h>
#include <rampart_username_token.h>
#include <rampart_timestamp_token.h>
#include <rampart_util.h>
#include <rampart_sec_processed_result.h>
#include <rampart_handler_util.h>
#include <oxs_error.h>
#include <oxs_utility.h>
#include <oxs_key.h>
#include <oxs_axiom.h>
#include <oxs_asym_ctx.h>
#include <oxs_tokens.h>
#include <axutil_utils.h>
#include <axutil_array_list.h>
#include <rampart_signature.h>

/*Private functions*/
axis2_status_t AXIS2_CALL
rampart_interchange_nodes(const axutil_env_t *env,
                          axiom_node_t *node_to_move,
                          axiom_node_t *node_before)
{
    axis2_status_t status = AXIS2_FAILURE;

    axiom_node_t *temp_node = NULL;

    temp_node = axiom_node_detach(node_to_move,env);
    status = axiom_node_insert_sibling_before(node_before,env,temp_node);

    return status;
}



/*Public functions*/


AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_shb_build_message(const axutil_env_t *env,
                          axis2_msg_ctx_t *msg_ctx,
                          rampart_context_t *rampart_context,
                          axiom_soap_envelope_t *soap_envelope)
{

    axis2_status_t status = AXIS2_FAILURE;
    axiom_soap_header_t *soap_header = NULL;
    axiom_node_t *soap_header_node = NULL;
    axiom_element_t *soap_header_ele = NULL;
    axiom_soap_header_block_t *sec_header_block = NULL;
    axiom_namespace_t *sec_ns_obj = NULL;
    axiom_node_t *sec_node =  NULL;
    axiom_element_t *sec_ele = NULL;
    axis2_bool_t is_encrypt_before_sign = AXIS2_FALSE;
    axiom_node_t *sig_node = NULL;
    axiom_node_t *enc_key_node = NULL;

    AXIS2_ENV_CHECK(env,AXIS2_FAILURE);
    soap_header  = axiom_soap_envelope_get_header(soap_envelope, env);
    soap_header_node = axiom_soap_header_get_base_node(soap_header, env);
    soap_header_ele = (axiom_element_t *)axiom_node_get_data_element(
                          soap_header_node, env);


    sec_ns_obj =  axiom_namespace_create(env, RAMPART_WSSE_XMLNS,
                                         RAMPART_WSSE);

    sec_header_block = axiom_soap_header_add_header_block(soap_header,
                       env, RAMPART_SECURITY, sec_ns_obj);

    if(!sec_header_block)
    {
        AXIS2_LOG_INFO(env->log, "[rampart][shb] Security header block is NULL");
        return AXIS2_SUCCESS;
    }

    axiom_soap_header_block_set_must_understand_with_bool(sec_header_block,
            env, AXIS2_TRUE);

    sec_node = axiom_soap_header_block_get_base_node(sec_header_block, env);
    sec_ele = (axiom_element_t *)
              axiom_node_get_data_element(sec_node, env);

    /*check the binding*/
    if((rampart_context_get_binding_type(rampart_context,env)) == RP_BINDING_ASYMMETRIC)
    {
        /*Do Asymmetric Binding specific things*/

        /*Timestamp Inclusion*/
        if(rampart_context_is_include_timestamp(rampart_context,env))
        {
            int ttl = -1;
            AXIS2_LOG_INFO(env->log, "[rampart][shb]  building Timestamp Token");
            AXIS2_LOG_INFO(env->log, "[rampart][shb]  Using default timeToLive value %d",
                           RAMPART_TIMESTAMP_TOKEN_DEFAULT_TIME_TO_LIVE);
            /*ttl = RAMPART_TIMESTAMP_TOKEN_DEFAULT_TIME_TO_LIVE;*/
            ttl = rampart_context_get_ttl(rampart_context,env);

            status = rampart_timestamp_token_build(env,
                                                   sec_node, sec_ns_obj, ttl);
            if (status == AXIS2_FAILURE)
            {
                AXIS2_LOG_INFO(env->log, "[rampart][shb] Timestamp Token build failed. ERROR");
                return AXIS2_FAILURE;
            }
        }

        /*Check whether we need username token*/
        /*User name tokens includes in messages sent from client to server*/
        if(!axis2_msg_ctx_get_server_side(msg_ctx,env))
        {
            if(rampart_context_is_include_username_token(rampart_context,env))
            {

                /*Now we are passing rampart_context here so inside this method
                relevant parameters are extracted. */

                AXIS2_LOG_INFO(env->log, "[rampart][shb]  building UsernmaeToken");
                status =rampart_username_token_build(
                            env,
                            rampart_context,
                            sec_node,
                            sec_ns_obj);
                if (status == AXIS2_FAILURE)
                {
                    AXIS2_LOG_INFO(env->log, "[rampart][shb] UsernmaeToken build failed. ERROR");
                    return AXIS2_FAILURE;
                }
            }
        }
        /*Check the encryption and signature order*/
        if(rampart_context_is_encrypt_before_sign(rampart_context,env))
        {
            is_encrypt_before_sign = AXIS2_TRUE;
            /*Check what are the parts to encrypt and send them to the encrypt method*/
            status = rampart_enc_encrypt_message(env, msg_ctx,rampart_context,soap_envelope,sec_node);
            if(status != AXIS2_SUCCESS)
                return AXIS2_FAILURE;

            /*Then do signature specific things*/
            status = rampart_sig_sign_message(env,msg_ctx,rampart_context,soap_envelope,sec_node);
            if(status != AXIS2_SUCCESS)
                return AXIS2_FAILURE;

            /*Then Handle Supporting token stuff  */
        }
        else
        {
            is_encrypt_before_sign = AXIS2_FALSE;
            /*First do signature specific stuff*/
            status = rampart_sig_sign_message(env,msg_ctx,rampart_context,soap_envelope,sec_node);
            if(status != AXIS2_SUCCESS)
                return AXIS2_FAILURE;

            /*Then Handle Encryption stuff*/

            status = rampart_enc_encrypt_message(env, msg_ctx,rampart_context,soap_envelope,sec_node);
            if(status!=AXIS2_SUCCESS )
                return AXIS2_FAILURE;
        }

        /*If both encryption and signature is done we should interchange them.
         * because the a-ction done last should appear first in the header. */
        sig_node = oxs_axiom_get_node_by_local_name(env,sec_node,OXS_NODE_SIGNATURE);
        enc_key_node = oxs_axiom_get_node_by_local_name(env,sec_node,OXS_NODE_ENCRYPTED_KEY);
        if(sig_node && enc_key_node)
        {
            if(is_encrypt_before_sign)
            {
                status = rampart_interchange_nodes(env,sig_node,enc_key_node);
                if(status!=AXIS2_SUCCESS)
                {
                    AXIS2_LOG_INFO(env->log,"[rampart][shb]Node interchange failed.");
                    return status;
                }
            }
            else
            {
                status = rampart_interchange_nodes(env,enc_key_node,sig_node);
                if(status!=AXIS2_SUCCESS)
                {
                    AXIS2_LOG_INFO(env->log,"[rampart][shb]Node interchange failed.");
                    return status;
                }
            }
        }
        return AXIS2_SUCCESS;
    }
    else if((rampart_context_get_binding_type(rampart_context,env)) == RP_BINDING_SYMMETRIC)
    {
        /*Do Symmetric_binding specific things*/
        AXIS2_LOG_INFO(env->log, "[rampart][shb] Symmetric Binding. We do not support yet");
        return AXIS2_FAILURE;
    }
    else if((rampart_context_get_binding_type(rampart_context,env)) == RP_BINDING_TRANSPORT)
    {
        /*Do Transport Binding specific things */
        AXIS2_LOG_INFO(env->log, "[rampart][shb] Transport Binding. We do not support yet");
        return AXIS2_FAILURE;
    }
    else
        return AXIS2_FAILURE;
}
