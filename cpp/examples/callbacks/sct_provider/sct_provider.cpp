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

using namespace std;
using namespace wso2wsf;

typedef map<string, void*> MapSCT_t;

class TokenProvider: public SCTProvider
{
public:
    WSF_CALL TokenProvider();
    WSF_CALL ~TokenProvider();

    virtual void* WSF_CALL getToken(string sct_id, MessageContext* msgctx);
    virtual bool WSF_CALL storeToken(string sct_id, MessageContext* msgctx, void* sct);
    virtual bool WSF_CALL removeToken(string sct_id, MessageContext* msgctx);
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

void* TokenProvider::getToken(string sct_id, MessageContext* msgctx)
{
    MapSCT_t* pmapSCT = getSCTMap(msgctx);
    MapSCT_t::iterator ite = pmapSCT->find(sct_id);
    if(ite != pmapSCT->end())
    {
        return ite->second;
    }
    return NULL;
}

bool TokenProvider::storeToken(string sct_id, MessageContext* msgctx, void* sct)
{
    MapSCT_t* pmapSCT = getSCTMap(msgctx);
    pmapSCT->insert(std::make_pair(sct_id, sct));
    return true;
}

bool TokenProvider::removeToken(string sct_id, MessageContext* msgctx)
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
        const axutil_env_t* env = Process::getEnv();
        axis2_conf_ctx_t *conf_ctx = axis2_msg_ctx_get_conf_ctx(
            msgctx->getAxis2MessageContext(), env);
        axutil_property_t* sct_map_prop = axutil_property_create_with_args(
            env, AXIS2_SCOPE_APPLICATION, AXIS2_TRUE, NULL, pmapSCT);
        axis2_conf_ctx_set_property(conf_ctx, env, propertyName.c_str(), sct_map_prop); 
    }
    
    return pmapSCT;
}
