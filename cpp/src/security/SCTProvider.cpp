/*
 * Copyright 2005,2009 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <SCTProvider.h>
#include <OMElement.h>

using namespace std;
using namespace wso2wsf;

WSF_EXTERN axis2_status_t WSF_CALL SCTProvider::storeToken(
    const axutil_env_t *env, 
    axis2_msg_ctx_t* msg_ctx, 
    axis2_char_t *sct_global_id, 
    axis2_char_t *sct_local_id, 
    void *sct, 
    void *user_params)
{
    if(user_params)
    {
        SCTProvider* callback = (SCTProvider*)user_params;
        MessageContext* msgctx = new MessageContext(msg_ctx);
        string str_sct;
        if(sct_global_id)
            str_sct = sct_global_id;
        bool status = callback->storeToken(str_sct, msgctx, sct);
        msgctx->setAxis2MessageContext(NULL);
        delete msgctx;
        return status;
    }
    return AXIS2_FAILURE;
}

WSF_EXTERN void* WSF_CALL SCTProvider::getToken(
    const axutil_env_t *env, 
    axis2_bool_t is_encryption, 
    axis2_msg_ctx_t* msg_ctx, 
    axis2_char_t *sct_id, 
    int sct_id_type,
    void* user_params)
{
    if(user_params)
    {
        SCTProvider* callback = (SCTProvider*)user_params;
        MessageContext* msgctx = new MessageContext(msg_ctx);
        string str_sct;
        if(sct_id)
            str_sct = sct_id;
        void* sct = callback->getToken(str_sct, msgctx);
        msgctx->setAxis2MessageContext(NULL);
        delete msgctx;
        return sct;
    }
    return NULL;
}

WSF_EXTERN axis2_status_t WSF_CALL SCTProvider::removeToken(
    const axutil_env_t *env, 
    axis2_msg_ctx_t* msg_ctx, 
    axis2_char_t *sct_id, 
    int sct_id_type,
    void* user_params)
{
    if(user_params)
    {
        SCTProvider* callback = (SCTProvider*)user_params;
        MessageContext* msgctx = new MessageContext(msg_ctx);
        string str_sct;
        if(sct_id)
            str_sct = sct_id;
        bool status = callback->removeToken(str_sct, msgctx);
	msgctx->setAxis2MessageContext(NULL);
        delete msgctx;
        return status;
    }
    return AXIS2_FAILURE;
}

WSF_EXTERN axis2_status_t WSF_CALL SCTProvider::validateToken(
    const axutil_env_t *env, 
    axiom_node_t *sct_node, 
    axis2_msg_ctx_t *msg_ctx, 
    void *user_params)
{
    if(user_params)
    {
        SCTProvider* callback = (SCTProvider*)user_params;
        MessageContext* msgctx = new MessageContext(msg_ctx);
        OMElement *node = new OMElement(NULL, sct_node);
        bool status = callback->validateToken(node, msgctx);
        msgctx->setAxis2MessageContext(NULL);
        delete msgctx;
        node->setAxiomNode(NULL); //to prevent original node being deleted. 
        delete node;
        return status;
    }
    return AXIS2_FAILURE;
}

WSF_EXTERN WSF_CALL SCTProvider::~SCTProvider()
{
}
