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
#include <map>
#include <axutil_hash.h>
#include <Environment.h>

using namespace std;
using namespace wso2wsf;

typedef axutil_hash_t MapSCT_t;

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
	void* sct = axutil_hash_get(pmapSCT, sct_id.c_str(), AXIS2_HASH_KEY_STRING);
    return sct;
}

bool TokenProvider::storeToken(string& sct_id, MessageContext* msgctx, void* sct)
{
    MapSCT_t* pmapSCT = getSCTMap(msgctx);
    axutil_hash_set(pmapSCT, axutil_strdup(Environment::getEnv(), sct_id.c_str()), AXIS2_HASH_KEY_STRING, sct);
    return true;
}

bool TokenProvider::removeToken(string& sct_id, MessageContext* msgctx)
{
    return true;
}

bool TokenProvider::validateToken(OMNode* sct_node, MessageContext* msgctx)
{
    return true;
}

#define propertyName "Rampart_SCT_Prov_DB_Prop"

MapSCT_t* TokenProvider::getSCTMap(MessageContext* msgctx)
{
    MapSCT_t* pmapSCT = (MapSCT_t*)msgctx->getPropertyValue(propertyName);
	const axutil_env_t* env = Environment::getEnv();
    if(!pmapSCT)
    {
       //The property is not created yet. So we have to create it and store it in conf context
        pmapSCT = axutil_hash_make(env);
        axis2_conf_ctx_t *conf_ctx = axis2_msg_ctx_get_conf_ctx(
            msgctx->getAxis2MessageContext(), env);
        axutil_property_t* sct_map_prop = axutil_property_create_with_args(
            env, AXIS2_SCOPE_APPLICATION, AXIS2_TRUE, NULL, pmapSCT);
        axis2_conf_ctx_set_property(conf_ctx, env, propertyName, sct_map_prop); 
    }
	else
	{
		axutil_hash_set_env(pmapSCT, env);
	}
    
    return pmapSCT;
}
