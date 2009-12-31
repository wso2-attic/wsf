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
#include <ServiceSkeleton.h>
#include <axutil_class_loader.h>

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
		Environment::setEnv(env);

		MessageContext *inMsgCtx = new MessageContext(msg_ctx);
		MessageContext *outMsgCtx = new MessageContext(msg_ctx);
		status = receiver->invokeBusinessLogicSync(inMsgCtx, outMsgCtx);
		inMsgCtx->setAxis2MessageContext(NULL);
		outMsgCtx->setAxis2MessageContext(NULL);
		delete inMsgCtx;
		delete outMsgCtx;
		Environment::removeEnv();
	}
	return status ? AXIS2_SUCCESS : AXIS2_FAILURE;
}

WSF_EXTERN  axis2_status_t WSF_CALL MessageReceiver::loadAndInitService(
			axis2_msg_recv_t *msg_recv,
			const axutil_env_t* env,
			struct axis2_svc *svc)
{
	ServiceSkeleton *impl_class = NULL;
	axutil_param_t *impl_info_param = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	AXIS2_ENV_CHECK(env, NULL);
	if (!svc)
	{
		return AXIS2_FAILURE;
	}
	Environment::setEnv(env);

	conf_ctx = axis2_msg_recv_get_conf_ctx(msg_recv, env);
	axutil_thread_mutex_lock(axis2_svc_get_mutex(svc, env));
	impl_class = (ServiceSkeleton*)axis2_svc_get_impl_class(svc, env);
	if (impl_class)
	{
		axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));
		return AXIS2_SUCCESS;
	}
	impl_info_param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_CLASS);
	if (!impl_info_param)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_SVC,
			AXIS2_FAILURE);
		axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));
		return AXIS2_FAILURE;
	}

	axutil_allocator_switch_to_global_pool(env->allocator);

	axutil_class_loader_init(env);
	
	impl_class = (ServiceSkeleton*)axutil_class_loader_create_dll(env, impl_info_param);
	

	if (impl_class)
	{
		const axis2_char_t *svc_name = axis2_svc_get_name(svc, env);
		axis2_svc_ctx_t *svc_ctx = axis2_conf_ctx_get_svc_ctx(conf_ctx, env, svc_name); 
		impl_class->setServiceContext(svc_ctx);
		bool value = impl_class->init();
		if(!value)
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Initinalization Failed");
	}

	axis2_svc_set_impl_class(svc, env, impl_class);
	axutil_allocator_switch_to_local_pool(env->allocator);
	axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));

	Environment::removeEnv();
	return AXIS2_SUCCESS;		

}