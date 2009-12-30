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

#include <MessageReceiver.h>
using namespace std;
using namespace wso2wsf;

WSF_EXTERN axis2_status_t WSF_CALL wso2wsf::MessageReceiver::processBusinessLogic(
            axis2_msg_recv_t * msg_recv,
			const axutil_env_t * env,
			axis2_msg_ctx_t * msg_ctx,
			axis2_msg_ctx_t * new_msg_ctx)
{
	bool status = false;
	void *derived = axis2_msg_recv_get_derived(msg_recv, env);
	MessageReceiver *receiver = (wso2wsf::MessageReceiver*)(derived);
	if(receiver)
	{
		MessageContext *inMsgCtx = new MessageContext(msg_ctx);
		MessageContext *outMsgCtx = new MessageContext(msg_ctx);
		status = receiver->invokeBusinessLogicSync(inMsgCtx, outMsgCtx);
		inMsgCtx->setAxis2MessageContext(NULL);
		outMsgCtx->setAxis2MessageContext(NULL);
		delete inMsgCtx;
		delete outMsgCtx;
	}
	return status ? AXIS2_SUCCESS : AXIS2_FAILURE;
}