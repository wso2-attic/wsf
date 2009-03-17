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
using namespace std;
using namespace wso2wsf;

axis2_status_t WSF_CALL ReplayDetector::checkValidity(
    rampart_replay_detector_t *rrd,
    const axutil_env_t* env,
    axis2_msg_ctx_t *msg_ctx,
    rampart_context_t *rampart_context)
{
    wsf_replay_detector_t * cb = (wsf_replay_detector_t*) rrd;
    MessageContext* msgctx = new MessageContext(msg_ctx);
    return cb->callback->isValid(msgctx);
}

WSF_CALL ReplayDetector::~ReplayDetector()
{
}

