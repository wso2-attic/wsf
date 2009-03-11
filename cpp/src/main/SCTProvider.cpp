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

axis2_status_t WSF_CALL SCTProvider::storeToken(
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
        bool status = callback->storeToken(sct_global_id, msgctx, sct);
        delete msgctx;
        return status;
    }
    return AXIS2_FAILURE;
}

void* WSF_CALL SCTProvider::getToken(
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
        void* sct = callback->getToken(sct_id, msgctx);
        delete msgctx;
        return sct;
    }
    return NULL;
}

axis2_status_t WSF_CALL SCTProvider::removeToken(
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
        bool status = callback->removeToken(sct_id, msgctx);
        delete msgctx;
        return status;
    }
    return AXIS2_FAILURE;
}

axis2_status_t WSF_CALL SCTProvider::validateToken(
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
        delete msgctx;
        delete node;
        return status;
    }
    return AXIS2_FAILURE;
}

WSF_CALL SCTProvider::~SCTProvider()
{
}