/*
* Copyright 2005-2009 WSO2, Inc. http://wso2.com
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


#include <string.h>
#include <axutil_thread.h>
#include <axiom_element.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <axiom_soap_fault.h>
#include <axiom_soap.h>
#include <axis2_msg_recv.h>
#include <axis2_thread_mutex.h>
#include <axis2_svc.h>
#include <axutil_class_loader.h>
#include <OMNode.h>
#include <WSFDefines.h>
#include <ServiceSkeleton.h>
#include <OMElement.h>
#include <MessageContext.h>
#include <Environment.h>

using namespace wso2wsf;


static axis2_status_t WSF_CALL
wsf_cpp_msg_recv_invoke_business_logic_sync(
    axis2_msg_recv_t * msg_recv,
    const axutil_env_t * env,
    axis2_msg_ctx_t * msg_ctx,
    axis2_msg_ctx_t * new_msg_ctx);

WSF_EXTERN ServiceSkeleton* WSF_CALL
wsf_cpp_msg_recv_get_svc_obj(
axis2_msg_recv_t * msg_recv,
const axutil_env_t * env,
struct axis2_msg_ctx * msg_ctx);

static axis2_status_t WSF_CALL
wsf_cpp_msg_recv_load_and_init_svc(
	axis2_msg_recv_t * msg_recv,
	const axutil_env_t * env,
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
	/** adding the environment */
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


WSF_EXTERN axis2_msg_recv_t *WSF_CALL
wsf_cpp_msg_recv_create(
    const axutil_env_t * env)
{
    axis2_msg_recv_t *msg_recv = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    msg_recv = axis2_msg_recv_create(env);
    if (!msg_recv)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    status = axis2_msg_recv_set_scope(msg_recv, env, AXIS2_APPLICATION_SCOPE);
    if (!status)
    {
        axis2_msg_recv_free(msg_recv, env);
        return NULL;
    }

    axis2_msg_recv_set_invoke_business_logic(msg_recv, env,
        wsf_cpp_msg_recv_invoke_business_logic_sync);
	axis2_msg_recv_set_load_and_init_svc(msg_recv, env, 
		wsf_cpp_msg_recv_load_and_init_svc);
    return msg_recv;
}

static  axis2_status_t WSF_CALL
wsf_cpp_msg_recv_invoke_business_logic_sync(
	axis2_msg_recv_t * msg_recv,
	const axutil_env_t * env,
	axis2_msg_ctx_t * msg_ctx,
	axis2_msg_ctx_t * new_msg_ctx)
{
	axis2_op_ctx_t *op_ctx = NULL;
	axis2_op_t *op_desc = NULL;
	const axis2_char_t *style = NULL;
	axiom_node_t *om_node = NULL;
	axiom_element_t *om_element = NULL;
	axis2_char_t *local_name = NULL;
	axiom_node_t *result_node = NULL;
	axiom_node_t *body_content_node = NULL;
	axiom_element_t *body_content_element = NULL;
	axiom_soap_envelope_t *default_envelope = NULL;
	axiom_soap_body_t *out_body = NULL;
	axiom_soap_header_t *out_header = NULL;
	axiom_soap_fault_t *soap_fault = NULL;
	axiom_node_t *out_node = NULL;
	axis2_status_t status = AXIS2_SUCCESS;
	axis2_bool_t skel_invoked = AXIS2_FALSE;
	const axis2_char_t *soap_ns = AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;
	int soap_version = AXIOM_SOAP12;
	axiom_namespace_t *env_ns = NULL;
	axiom_node_t *fault_node = NULL;
	axiom_soap_fault_detail_t *fault_detail;
	axis2_bool_t is_fault = AXIS2_FALSE;
	axis2_char_t *soapEnvelopePrefix = "soapenv";

	AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);
	AXIS2_PARAM_CHECK(env->error, new_msg_ctx, AXIS2_FAILURE);

	AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, 
		"[axis2]Entry:wsf_cpp_msg_recv_invoke_business_logic_sync");

	Environment::setEnv(env);
	
	/* get the implementation class for the Web Service */
	ServiceSkeleton *skel = wsf_cpp_msg_recv_get_svc_obj(msg_recv, env, msg_ctx);

	if (!skel)
	{
		const axis2_char_t *svc_name = NULL;
		axis2_svc_t *svc = axis2_msg_ctx_get_svc(msg_ctx, env);

		if (svc)
		{
			svc_name = axis2_svc_get_name(svc, env);
		}
		else
		{
			svc_name = "unknown";
		}

		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "IMPL object for service '%s' not set in message receiver. %d :: %s", svc_name, 
			env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
		status = AXIS2_FAILURE;
	}
	else
	{
		op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
		op_desc = axis2_op_ctx_get_op(op_ctx, env);

		style = axis2_op_get_style(op_desc, env);
		if (0 == axutil_strcmp(AXIS2_STYLE_DOC, style))
		{
			axiom_soap_envelope_t *envelope = NULL;
			axiom_soap_body_t *body = NULL;
			axiom_namespace_t *envNs = NULL;

			envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
			envNs = axiom_soap_envelope_get_namespace(envelope, env);
			soapEnvelopePrefix = axiom_namespace_get_prefix(envNs,env);

			body = axiom_soap_envelope_get_body(envelope, env);
			om_node = axiom_soap_body_get_base_node(body, env);
			om_element = (axiom_element_t*)axiom_node_get_data_element(om_node, env);
			om_node = axiom_node_get_first_element(om_node, env);
		}
		else if (0 == axutil_strcmp(AXIS2_STYLE_RPC, style))
		{

			axiom_soap_envelope_t *envelope = NULL;
			axiom_soap_body_t *body = NULL;
			axiom_node_t *op_node = NULL;
			axiom_element_t *op_element = NULL;
			axiom_namespace_t *envNs = NULL;
			axiom_element_t *om_ele = NULL;

			envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);
			envNs = axiom_soap_envelope_get_namespace(envelope, env);
			soapEnvelopePrefix = axiom_namespace_get_prefix(envNs, env);

			body = axiom_soap_envelope_get_body(envelope, env);
			om_node = axiom_soap_body_get_base_node(body, env);
			om_ele = (axiom_element_t*)axiom_node_get_data_element(om_node, env);
			local_name = axiom_element_get_localname(om_ele,env );
		}
		else
		{
			AXIS2_ERROR_SET(env->error, AXIS2_ERROR_UNKNOWN_STYLE, AXIS2_FAILURE);
			status = AXIS2_FAILURE;
		}

		if (status == AXIS2_SUCCESS)
		{
			skel_invoked = AXIS2_TRUE;

			OMElement *inputEle = NULL;
			if(om_node)
			{
				inputEle = new OMElement(NULL, om_node);
			}
			MessageContext *outCtx = new MessageContext(new_msg_ctx);
			OMElement *resultEle = NULL;

			resultEle = skel->invoke(inputEle, outCtx);
				/** Remove the newly created CPP Request Element wrapper */
			
			if(inputEle)
			{
				inputEle->setAxiomNode(NULL);
				delete inputEle;
			}
			
			/** Remove the resultant CPP Response Element after extracting the axiom node contained within */
			if(resultEle){
				result_node = resultEle->getAxiomNode();
				resultEle->setAxiomNode(NULL);
				delete resultEle;
			}
			outCtx->incrementRef();
			delete outCtx;
		}

		if (result_node)
		{
			if (0 == axutil_strcmp(style, AXIS2_STYLE_RPC))
			{
				axiom_namespace_t *ns = NULL;
				axis2_char_t *res_name = NULL;

				res_name = axutil_stracat(env, local_name, "Response");
				ns = axiom_namespace_create(env, "http://soapenc/", "res");
				if (!ns)
				{
					status = AXIS2_FAILURE;
				}
				else
				{
					body_content_element = axiom_element_create(env, NULL, res_name, ns, &body_content_node);
					axiom_node_add_child(body_content_node, env, result_node);
				}
			}
			else
			{
				body_content_node = result_node;
			}
		}
		else 
		{
			axis2_char_t *mep = (axis2_char_t *)axis2_op_get_msg_exchange_pattern(op_desc, env);
			if (axutil_strcmp(mep, AXIS2_MEP_URI_IN_ONLY) && 
				axutil_strcmp(mep, AXIS2_MEP_URI_ROBUST_IN_ONLY))
			{
				status = AXIS2_ERROR_GET_STATUS_CODE(env->error);
				if (status == AXIS2_SUCCESS)
				{
					axis2_msg_ctx_set_no_content(new_msg_ctx, env, AXIS2_TRUE);
				}
				else
				{
					axis2_msg_ctx_set_status_code(msg_ctx, env,	axis2_msg_ctx_get_status_code(new_msg_ctx, env));
				}

				OMElement *inputEle = NULL;
				if(om_node)
				{	
					inputEle = new OMElement(NULL,om_node);
				}

				if(skel)
				{
					OMElement *faultEle = skel->onFault(inputEle);
					if(faultEle)
					{
						fault_node = faultEle->getAxiomNode();
						faultEle->setAxiomNode(NULL);
						delete faultEle;
					}
				}
				if(inputEle)
				{
					inputEle->setAxiomNode(NULL);
					delete inputEle;
				}
				is_fault = AXIS2_TRUE;
			}
			else
			{	

				status = AXIS2_ERROR_GET_STATUS_CODE(env->error);
				if (status == AXIS2_SUCCESS)
				{
					axis2_msg_ctx_set_no_content(new_msg_ctx, env, AXIS2_TRUE);
				}
				else
				{
					axis2_msg_ctx_set_status_code(msg_ctx, env,
						axis2_msg_ctx_get_status_code(new_msg_ctx, env));
					if (!axutil_strcmp(mep, AXIS2_MEP_URI_ROBUST_IN_ONLY))
					{
						OMElement *inputEle = NULL;
						if(om_node)
						{
							inputEle = new OMElement(NULL,om_node);
						}

						if(skel)
						{
							OMElement *faultEle = skel->onFault(inputEle);
							if(faultEle)
							{
								fault_node = faultEle->getAxiomNode();
								faultEle->setAxiomNode(NULL);
								delete faultEle;
							}
						}
						if(inputEle)
						{
							inputEle->setAxiomNode(NULL);
							delete inputEle;
						}
						is_fault = AXIS2_TRUE;
					}
				}
			}
		}
	}

	if (msg_ctx && axis2_msg_ctx_get_is_soap_11(msg_ctx, env))
	{
		soap_ns = AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI; /* default is 1.2 */
		soap_version = AXIOM_SOAP11;
	}

	if (axis2_msg_ctx_get_soap_envelope(new_msg_ctx, env))
	{
		Environment::removeEnv();
		return AXIS2_SUCCESS;
	}
	env_ns = axiom_namespace_create(env, soap_ns, soapEnvelopePrefix );
	if (!env_ns)
	{
		Environment::removeEnv();
		return AXIS2_FAILURE;
	}

	default_envelope = axiom_soap_envelope_create(env, env_ns);

	if (!default_envelope)
	{
		Environment::removeEnv();
		return AXIS2_FAILURE;
	}

	out_header = axiom_soap_header_create_with_parent(env, default_envelope);
	if (!out_header)
	{
		Environment::removeEnv();
		return AXIS2_FAILURE;
	}

	out_body = axiom_soap_body_create_with_parent(env, default_envelope);
	if (!out_body)
	{
		Environment::removeEnv();
		return AXIS2_FAILURE;
	}

	out_node = axiom_soap_body_get_base_node(out_body, env);
	if (!out_node)
	{
		Environment::removeEnv();
		return AXIS2_FAILURE;
	}

	if (status != AXIS2_SUCCESS || is_fault)
	{
		const axis2_char_t *fault_value_str = axutil_stracat(Environment::getEnv(),soapEnvelopePrefix, ":Sender");
		const axis2_char_t *fault_reason_str = NULL;
		const axis2_char_t *err_msg = NULL;

		if (!skel_invoked)
		{
			if (axis2_msg_ctx_get_is_soap_11(msg_ctx, env))
			{
				fault_value_str =
					AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX ":"
					AXIOM_SOAP11_FAULT_CODE_RECEIVER;
			}
			else
			{
				fault_value_str =
					AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX ":"
					AXIOM_SOAP12_SOAP_FAULT_VALUE_RECEIVER;
			}
		}

		err_msg = AXIS2_ERROR_GET_MESSAGE(env->error);
		if (err_msg)
		{
			fault_reason_str = err_msg;
		}
		else
		{
			fault_reason_str = "An error has occurred, but could not determine exact details";
		}

		soap_fault = axiom_soap_fault_create_default_fault(env, out_body, fault_value_str, 
			fault_reason_str, soap_version);

		AXIS2_FREE((Environment::getEnv()->allocator), (void*)fault_value_str);

		if (fault_node)
		{
			axiom_node_t *fault_detail_node = NULL;

			fault_detail = axiom_soap_fault_detail_create_with_parent(env, soap_fault);
			fault_detail_node = axiom_soap_fault_detail_get_base_node(fault_detail, env);
			axiom_soap_fault_detail_add_detail_entry(fault_detail, env, fault_node);
		}
	}

	if (body_content_node)
	{
		axiom_node_add_child(out_node, env, body_content_node);
		status = axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, default_envelope);
	}
	else if (soap_fault)
	{
		axis2_msg_ctx_set_soap_envelope(new_msg_ctx, env, default_envelope);
		status = AXIS2_SUCCESS;
	}
	else
	{
		axiom_soap_envelope_free(default_envelope, env);
		default_envelope = NULL;
	}

	AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, 
		"[axis2]Exit:wsf_cpp_msg_recv_invoke_business_logic_sync");
	Environment::removeEnv();
	return AXIS2_SUCCESS;
}

WSF_EXTERN ServiceSkeleton* WSF_CALL
wsf_cpp_msg_recv_get_svc_obj(
	axis2_msg_recv_t * msg_recv,
	const axutil_env_t * env,
	struct axis2_msg_ctx * msg_ctx)
{

	struct axis2_svc *svc = NULL;
	struct axis2_op_ctx *op_ctx = NULL;
	struct axis2_svc_ctx *svc_ctx = NULL;
	axutil_param_t *impl_info_param = NULL;
	ServiceSkeleton *impl_class = NULL;

	AXIS2_ENV_CHECK(env, NULL);
	AXIS2_PARAM_CHECK(env->error, msg_ctx, NULL);

	op_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
	svc_ctx = axis2_op_ctx_get_parent(op_ctx, env);
	svc = axis2_svc_ctx_get_svc(svc_ctx, env);
	if (!svc)
	{
		return NULL;
	}

	impl_class = (ServiceSkeleton*)axis2_svc_get_impl_class(svc, env);
	if (impl_class)
	{
		return impl_class;
	}
	else
	{
		axutil_thread_mutex_lock(axis2_svc_get_mutex(svc, env));
		impl_class = (ServiceSkeleton*)axis2_svc_get_impl_class(svc, env);
		if (impl_class)
		{
			axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));
			return impl_class;
		}
		impl_info_param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_CLASS);
		if (!impl_info_param)
		{
			AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_SVC,
				AXIS2_FAILURE);
			axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));
			return NULL;
		}

		axutil_allocator_switch_to_global_pool(env->allocator);

		axutil_class_loader_init(env);

		impl_class = (ServiceSkeleton*)axutil_class_loader_create_dll(env, impl_info_param);


		if (impl_class)
		{
			impl_class->setServiceContext(svc_ctx);
			bool value = impl_class->init();
			if(!value)
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Initinalization Failed");
		}
		axis2_svc_set_impl_class(svc, env, impl_class);
		axutil_allocator_switch_to_local_pool(env->allocator);
		axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));
		return impl_class;
	}
}



#ifdef __cplusplus
extern "C"
{
#endif

WSF_EXTERN int
axis2_get_instance(
    struct axis2_msg_recv **inst,
    const axutil_env_t * env)
{
    *inst = wsf_cpp_msg_recv_create(env);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

WSF_EXTERN int
axis2_remove_instance(
    struct axis2_msg_recv *inst,
    const axutil_env_t * env)
{
    if (inst)
    {
        axis2_msg_recv_free(inst, env);
    }
    return AXIS2_SUCCESS;
}

#ifdef __cplusplus
}
#endif
