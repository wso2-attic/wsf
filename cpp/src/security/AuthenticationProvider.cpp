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

#include <AuthenticationProvider.h>
using namespace std;
using namespace wso2wsf;

WSF_EXTERN rampart_authn_provider_status_t WSF_CALL AuthenticationProvider::callbackPasswordPlain(
    rampart_authn_provider_t * authn_provider, 
    const axutil_env_t* env, 
    axis2_msg_ctx_t *msg_ctx,
    const axis2_char_t *username,
    const axis2_char_t *password)
{
    wsf_authn_provider_t * cb = (wsf_authn_provider_t*) authn_provider;
    MessageContext* msgctx = new MessageContext(msg_ctx);
    string str_username;
    if(username)
        str_username = username;
    string str_password;
    if(password)
        str_password = password;
    bool status = cb->callback->checkPassword(str_username, str_password, msgctx);
    msgctx->setAxis2MessageContext(NULL);
    delete msgctx;
    return (status?RAMPART_AUTHN_PROVIDER_GRANTED:RAMPART_AUTHN_PROVIDER_DENIED);
}

WSF_EXTERN rampart_authn_provider_status_t WSF_CALL AuthenticationProvider::callbackPasswordDigest(
    rampart_authn_provider_t *authn_provider,
    const axutil_env_t* env,
    axis2_msg_ctx_t *msg_ctx,
    const axis2_char_t *username,
    const axis2_char_t *nonce,
    const axis2_char_t *created,
    const axis2_char_t *digest)
{
    wsf_authn_provider_t * cb = (wsf_authn_provider_t*) authn_provider;
    MessageContext* msgctx = new MessageContext(msg_ctx);
    string str_username;
    if(username)
        str_username = username;
    string str_nonce;
    if(nonce)
        str_nonce = nonce;
    string str_created;
    if(created)
        str_created = created;
    string str_digest;
    if(digest)
        str_digest = digest;
    bool status = cb->callback->checkDigestPassword(str_username, str_nonce, str_created, str_digest, msgctx);
    msgctx->setAxis2MessageContext(NULL);
    delete msgctx;
    return (status?RAMPART_AUTHN_PROVIDER_GRANTED:RAMPART_AUTHN_PROVIDER_DENIED);
}

WSF_EXTERN WSF_CALL AuthenticationProvider::~AuthenticationProvider()
{
}
