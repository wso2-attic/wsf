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
#include <secconv_security_context_token.h>
#include <map>

using namespace std;
using namespace wso2wsf;

typedef map<string, void*> MapSCT_t;

class TokenProvider: public SCTProvider
{
public:
    WSF_CALL TokenProvider();
    WSF_CALL ~TokenProvider();

    virtual void* WSF_CALL getToken(string& sct_id, MessageContext* msgctx);
    virtual bool WSF_CALL storeToken(string& sct_id, MessageContext* msgctx, void* sct);
    virtual bool WSF_CALL removeToken(string& sct_id, MessageContext* msgctx);
    virtual bool WSF_CALL validateToken(OMNode* sct_node, MessageContext* msgctx);

private:
    MapSCT_t* getSCTMap(MessageContext* msgctx);
};

WSF_SCT_PROVIDER_INIT(TokenProvider);

TokenProvider::TokenProvider()
{
    //you can write any construction logic
}

TokenProvider::~TokenProvider()
{
    //you can write any destruction logic
}

void* TokenProvider::getToken(string& sct_id, MessageContext* msgctx)
{
    MapSCT_t* pmapSCT = getSCTMap(msgctx);
    MapSCT_t::iterator ite = pmapSCT->find(sct_id);
    if(ite != pmapSCT->end())
    {
        return ite->second;
    }
	else
	{
		const axutil_env_t* env = Environment::getEnv();
		Environment::switchToGlobalPool();
		security_context_token_t *sct = security_context_token_create(env);
        if(sct)
        {
            oxs_buffer_t* key_buffer = oxs_buffer_create(env);
            oxs_buffer_populate(
                key_buffer, env, (unsigned char*)"01234567012345670123456701234567", 32);
            security_context_token_set_secret(sct, env, key_buffer);
            if(sct_id == "")
            {
				axis2_char_t* sctid = oxs_util_generate_id(env,"urn:uuid:");
                sct_id = (const char*)sctid;
                AXIS2_FREE(env->allocator, sctid);
                
            }
            security_context_token_set_global_identifier(sct, env, (axis2_char_t*)axutil_strdup(env, sct_id.c_str()));
            security_context_token_set_local_identifier(
                sct, env, (axis2_char_t*)axutil_strdup(env, "#sctId-29530019"));
            security_context_token_set_is_sc10(sct, env, AXIS2_TRUE);
    
		}
		Environment::switchToLocalPool();
		return sct;
	}
}

bool TokenProvider::storeToken(string& sct_id, MessageContext* msgctx, void* sct)
{
    MapSCT_t* pmapSCT = getSCTMap(msgctx);
    pmapSCT->insert(std::make_pair(sct_id, sct));
    return true;
}

bool TokenProvider::removeToken(string& sct_id, MessageContext* msgctx)
{
    MapSCT_t* pmapSCT = getSCTMap(msgctx);
    pmapSCT->erase(sct_id);
    return true;
}

bool TokenProvider::validateToken(OMNode* sct_node, MessageContext* msgctx)
{
    return true;
}

MapSCT_t* TokenProvider::getSCTMap(MessageContext* msgctx)
{
    string propertyName = "SCTContainerMap";
    MapSCT_t* pmapSCT = (MapSCT_t*)msgctx->getPropertyValue(propertyName);
    if(!pmapSCT)
    {
       //The property is not created yet. So we have to create it and store it in conf context
        pmapSCT = new MapSCT_t;
        const axutil_env_t* env = Environment::getEnv();
        axis2_conf_ctx_t *conf_ctx = axis2_msg_ctx_get_conf_ctx(
            msgctx->getAxis2MessageContext(), env);
        axutil_property_t* sct_map_prop = axutil_property_create_with_args(
            env, AXIS2_SCOPE_APPLICATION, AXIS2_TRUE, NULL, pmapSCT);
        axis2_conf_ctx_set_property(conf_ctx, env, propertyName.c_str(), sct_map_prop); 
    }
    
    return pmapSCT;
}
