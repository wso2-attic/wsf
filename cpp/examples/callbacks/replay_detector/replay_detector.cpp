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

#include <ReplayDetector.h>
#include <set>
#include <rampart_sec_processed_result.h>
#include <WSFError.h>

using namespace std;
using namespace wso2wsf;

typedef set<string> ReplaySet_t;

class RDetect: public ReplayDetector
{
public:
    WSF_CALL RDetect();
    WSF_CALL ~RDetect();
    
    bool WSF_CALL isValid(MessageContext* msgctx);

private:
    ReplaySet_t* getReplaySet(MessageContext* msgctx);
};

WSF_REPLAY_DETECTOR_INIT(RDetect);

RDetect::RDetect()
{
    //you can write any construction logic
}

RDetect::~RDetect()
{
    //you can write any destruction logic
}

//this replay detection is based on timestamp + message id
bool RDetect::isValid(MessageContext* msgctx)
{
    //Get the message id
    string msgID = msgctx->getMessageId();

    //Get the time stamp
    axutil_hash_t *sec_process_result = rampart_get_all_security_processed_results(
        Environment::getEnv(), msgctx->getAxis2MessageContext());
    string timestamp = (char*) axutil_hash_get(
        sec_process_result, RAMPART_SPR_TS_CREATED, AXIS2_HASH_KEY_STRING);

    //Concatenate the two to check for replay
    string replayStr = msgID + timestamp;
    
    //get the replay string storage and search for above key
    ReplaySet_t* psetReplay = getReplaySet(msgctx);
    ReplaySet_t::iterator ite = psetReplay->find(replayStr);
    if(ite != psetReplay->end())
    {
        //above key is in the container, so this message is a replay
	WSF_LOG_ERROR_MSG(Environment::getEnv()->log, WSF_LOG_SI  ,"Message is a replay");
        return false;
    }
    
    //message is not a replay. so has to store it. 
    psetReplay->insert(replayStr);

    return true;
}

ReplaySet_t* RDetect::getReplaySet(MessageContext* msgctx)
{
    string propertyName = "ReplayDetectorSet";
    ReplaySet_t* psetReplay = (ReplaySet_t*)msgctx->getPropertyValue(propertyName);
    if(!psetReplay)
    {
       //The property is not created yet. So we have to create it and store it in conf context
        psetReplay = new ReplaySet_t;
        const axutil_env_t* env = Environment::getEnv();
        axis2_conf_ctx_t *conf_ctx = axis2_msg_ctx_get_conf_ctx(
            msgctx->getAxis2MessageContext(), env);
        axutil_property_t* replay_set_prop = axutil_property_create_with_args(
            env, AXIS2_SCOPE_APPLICATION, AXIS2_TRUE, NULL, psetReplay);
        axis2_conf_ctx_set_property(conf_ctx, env, propertyName.c_str(), replay_set_prop); 
    }
    
    return psetReplay;
}
