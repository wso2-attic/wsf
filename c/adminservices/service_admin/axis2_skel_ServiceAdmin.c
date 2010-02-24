/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
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


/**
* axis2_skel_ServiceAdmin.c
*
* This file was auto-generated from WSDL for "ServiceAdmin|http://mgt.service.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_ServiceAdmin Axis2/C skeleton for the axisService
*/

#include "codegen/axis2_skel_ServiceAdmin.h"
#include "service_admin_constants.h"
#include "service_admin_util.h"
#include "axis2_policy_include.h"
#include "neethi_engine.h"
#include "axis2_msg.h"
#include "axis2_op.h"

static axis2_char_t *axis2_skel_ServiceAdmin_get_service_type(
    const axutil_env_t *env,
    axis2_svc_t *svc);

/**
* auto generated function definition signature
* for "startService|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _startService of the adb_startService_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_startService(const axutil_env_t *env , 
									 axis2_msg_ctx_t *msg_ctx,
									 adb_startService_t* _startService,
									 axis2_skel_ServiceAdmin_startService_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getExposedTransports|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getExposedTransports of the adb_getExposedTransports_t*
*
* @return adb_getExposedTransportsResponse_t*
*/
adb_getExposedTransportsResponse_t* 
axis2_skel_ServiceAdmin_getExposedTransports(const axutil_env_t *env , 
											 axis2_msg_ctx_t *msg_ctx,
											 adb_getExposedTransports_t* _getExposedTransports )
{
	/* TODO fill this with the necessary business logic */
	return (adb_getExposedTransportsResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "listServiceGroup|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _listServiceGroup of the adb_listServiceGroup_t*
*
* @return adb_listServiceGroupResponse_t*
*/
adb_listServiceGroupResponse_t* 
axis2_skel_ServiceAdmin_listServiceGroup(const axutil_env_t *env , 
										 axis2_msg_ctx_t *msg_ctx,
										 adb_listServiceGroup_t* _listServiceGroup )
{
	/* TODO fill this with the necessary business logic */
	return (adb_listServiceGroupResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "addTransportBinding|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _addTransportBinding of the adb_addTransportBinding_t*
*
* @return adb_addTransportBindingResponse_t*
*/
adb_addTransportBindingResponse_t* 
axis2_skel_ServiceAdmin_addTransportBinding(const axutil_env_t *env , 
											axis2_msg_ctx_t *msg_ctx,
											adb_addTransportBinding_t* _addTransportBinding,
											axis2_skel_ServiceAdmin_addTransportBinding_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return (adb_addTransportBindingResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "getWSDL|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getWSDL of the adb_getWSDL_t*
*
* @return adb_getWSDLResponse_t*
*/
adb_getWSDLResponse_t* 
axis2_skel_ServiceAdmin_getWSDL(const axutil_env_t *env , 
								axis2_msg_ctx_t *msg_ctx,
								adb_getWSDL_t* _getWSDL )
{
	axis2_char_t *service_name = NULL;
	adb_getWSDLResponse_t *wsdlResponse = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axiom_node_t *response_node = NULL;

	service_name = adb_getWSDL_get_serviceName(_getWSDL, env);
	if(service_name)
	{
		conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
		conf = axis2_conf_ctx_get_conf(conf_ctx, env);
		if(conf)
		{
			axis2_char_t *wsdlurl = service_admin_util_get_wsdl_for_service(env, service_name, conf);
			/**TODO READ WSDL and convert to an axiom node */
			wsdlResponse = adb_getWSDLResponse_create(env);
			adb_getWSDLResponse_set_return(wsdlResponse, env, NULL);
		}
	}
	return wsdlResponse;
}



/**
* auto generated function definition signature
* for "getNumberOfFaultyServices|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getNumberOfFaultyServicesResponse_t*
*/
adb_getNumberOfFaultyServicesResponse_t* 
axis2_skel_ServiceAdmin_getNumberOfFaultyServices(const axutil_env_t *env , 
												  axis2_msg_ctx_t *msg_ctx )
{
	/* TODO fill this with the necessary business logic */
	return (adb_getNumberOfFaultyServicesResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "configureMTOM|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _configureMTOM of the adb_configureMTOM_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_configureMTOM(const axutil_env_t *env , 
									  axis2_msg_ctx_t *msg_ctx,
									  adb_configureMTOM_t* _configureMTOM )
{
	axis2_char_t *service_name = NULL, *flag = NULL;
	axis2_svc_t *service = NULL;
	axutil_param_t *parameter = NULL;

	flag = adb_configureMTOM_get_flag(_configureMTOM, env);
	service_name = adb_configureMTOM_get_serviceName(_configureMTOM, env);
	if(!service_name)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service name null");
		return AXIS2_FAILURE;
	}
	service = service_admin_util_get_service(env, msg_ctx, service_name);
	
	if(service)
	{
		axutil_hash_index_t *hi = NULL;
		axutil_hash_t *ops = NULL;
		parameter = axutil_param_create(env, AXIS2_ENABLE_MTOM, flag);
		axis2_svc_add_param(service, env, parameter);

		ops = axis2_svc_get_all_ops(service, env);
		for(hi = axutil_hash_first(ops, env); hi; hi = axutil_hash_next(env, hi))
		{
			axutil_param_t *param = NULL;
			const void *key = NULL;
			axis2_op_t *op = NULL;
			const void *value = NULL;
			axutil_hash_this(hi, &key, NULL, &value);
			op = (axis2_op_t *)value;
			param = axutil_param_create(env, AXIS2_ENABLE_MTOM, flag);
			axis2_op_add_param(op, env, param);
		}
			return AXIS2_SUCCESS;
	}
	return AXIS2_FAILURE;
}



/**
* auto generated function definition signature
* for "setServicePolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setServicePolicy of the adb_setServicePolicy_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_setServicePolicy(const axutil_env_t *env , 
										 axis2_msg_ctx_t *msg_ctx,
										 adb_setServicePolicy_t* _setServicePolicy,
										 axis2_skel_ServiceAdmin_setServicePolicy_fault *fault)
{
	axis2_char_t *service_name = NULL;
	axis2_svc_t *svc = NULL;
	axis2_desc_t *desc = NULL;
	axis2_policy_include_t *policy_include = NULL;
	axis2_char_t *policy_str = NULL;
	service_name = adb_setServicePolicy_get_serviceName(_setServicePolicy,env);
	policy_str = adb_setServicePolicy_get_policyString(_setServicePolicy, env);

	if(!service_name)
	{
		/** TODO Return Fault */
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service name not found");
		return AXIS2_FAILURE;
	}
	if(!policy_str)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Policy string not present");
	}
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		/** TODO Return Fault */
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service not found");
		return AXIS2_FAILURE;
	}

	desc = axis2_svc_get_base(svc, env);
	if(!desc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"Serivce Desc not found ");
		return AXIS2_FAILURE;
	}
	policy_include = axis2_desc_get_policy_include(desc, env);
	
	if(policy_include)
	{

		axiom_node_t *policy_node = NULL;
		neethi_policy_t *policy = NULL;
		axiom_element_t *ele = NULL;
		neethi_policy_t *current_policy = NULL;
		policy_node = axiom_node_create_from_buffer(env, policy_str);
		if(!policy_node)
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Policy string serialization filed");
			return AXIS2_FAILURE;
		}		
		ele = (axiom_element_t *)axiom_node_get_data_element(policy_node, env);

		policy = neethi_engine_get_policy(env, policy_node, ele);
		if(!policy)
		{
			/** TODO return an exception */
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "policy deserialization filed");
			return AXIS2_FAILURE;
		}
		axis2_policy_include_set_policy(policy_include, env, policy);
		return AXIS2_SUCCESS;
	}
	return AXIS2_FAILURE;
}



/**
* auto generated function definition signature
* for "getPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getPolicy of the adb_getPolicy_t*
*
* @return adb_getPolicyResponse_t*
*/
adb_getPolicyResponse_t* 
axis2_skel_ServiceAdmin_getPolicy(const axutil_env_t *env , 
								  axis2_msg_ctx_t *msg_ctx,
								  adb_getPolicy_t* _getPolicy)
{
	axis2_char_t *service_name = NULL;
	axis2_svc_t *svc = NULL;
	axis2_desc_t *desc = NULL;
	axis2_policy_include_t *policy_include = NULL;
	adb_getPolicyResponse_t *response = NULL;
	neethi_policy_t *effective_policy = NULL;

	service_name = adb_getPolicy_get_serviceName(_getPolicy,env);
	if(!service_name)
	{
		/** TODO Return Fault */
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service name not found");
		return NULL;
	}
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		/** TODO Return Fault */
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service not found");
		return NULL;
	}

	desc = axis2_svc_get_base(svc, env);
	if(!desc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"Serivce Desc not found ");
		return NULL;
	}
	policy_include = axis2_desc_get_policy_include(desc, env);
	response = adb_getPolicyResponse_create(env);
	if(policy_include)
	{

		axiom_node_t *policy_node = NULL;
		
		effective_policy = axis2_policy_include_get_effective_policy(policy_include, env);

		if(effective_policy)
		{
			axis2_char_t *policy_str = NULL;
			policy_node = neethi_policy_serialize(effective_policy, NULL, env);
			if(policy_node)
			{
				policy_str = axiom_node_to_string(policy_node, env);
				if(policy_str)
				{
					adb_getPolicyResponse_set_return(response, env, policy_str);
					return response;
				}
			}
		}
	}
	adb_getPolicyResponse_set_return(response, env, ADMIN_SERVICE_EMPTY_POLICY);
	return response;
}



/**
* auto generated function definition signature
* for "getFaultyServiceArchives|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getFaultyServiceArchives of the adb_getFaultyServiceArchives_t*
*
* @return adb_getFaultyServiceArchivesResponse_t*
*/
adb_getFaultyServiceArchivesResponse_t* 
axis2_skel_ServiceAdmin_getFaultyServiceArchives(const axutil_env_t *env , 
												 axis2_msg_ctx_t *msg_ctx,
												 adb_getFaultyServiceArchives_t* _getFaultyServiceArchives )
{
	/* TODO fill this with the necessary business logic */
	return (adb_getFaultyServiceArchivesResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "addPoliciesToService|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _addPoliciesToService of the adb_addPoliciesToService_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_addPoliciesToService(const axutil_env_t *env , 
											 axis2_msg_ctx_t *msg_ctx,
											 adb_addPoliciesToService_t* _addPoliciesToService,
											 axis2_skel_ServiceAdmin_addPoliciesToService_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getServiceParameters|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getServiceParameters of the adb_getServiceParameters_t*
*
* @return adb_getServiceParametersResponse_t*
*/
adb_getServiceParametersResponse_t* 
axis2_skel_ServiceAdmin_getServiceParameters(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_getServiceParameters_t* _getServiceParameters,
	axis2_skel_ServiceAdmin_getServiceParameters_fault *fault )
{
	adb_getServiceParametersResponse_t *response = NULL;
	axis2_char_t *service_name = NULL;
	axis2_svc_t *svc = NULL;
	service_name = adb_getServiceParameters_get_serviceName(_getServiceParameters, env);
	if(!service_name)
	{
		axiom_node_t *node = NULL;
		axiom_text_t *text = NULL;
		adb_ServerException_t *server_exp = NULL;

		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service name is empty");
		server_exp = adb_ServerException_create(env);
		
		fault->ServerException = adb_ServerExceptionE1_create(env);
		text = axiom_text_create(env, NULL, "Service name is empty", &node);
		
		adb_ServerException_set_Exception(server_exp,env, node);
		adb_ServerExceptionE1_set_ServerException(fault->ServerException, env, server_exp);
		return NULL;
	}
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		axiom_node_t *node = NULL;
		axiom_text_t *text = NULL;
		adb_ServerException_t *server_exp = NULL;

		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service does not exist");
		
		server_exp = adb_ServerException_create(env);
		fault->ServerException = adb_ServerExceptionE1_create(env);
		text = axiom_text_create(env, NULL, "Service does not exist", &node);
		adb_ServerException_set_Exception(server_exp,env, node); 
			
		adb_ServerExceptionE1_set_ServerException(fault->ServerException, env, server_exp);
		return NULL;
	}

	response = adb_getServiceParametersResponse_create(env);
	{
		axutil_array_list_t *param_list = NULL;
		int size = 0;
		param_list = axis2_svc_get_all_params(svc, env);
		if(param_list)
		{
			axis2_char_t *param_str = NULL;
			axiom_node_t *param_node = NULL;
			axutil_param_t *param = NULL;
			int i = 0;
			size = axutil_array_list_size(param_list,env);
			for(i = 0; i < size; i++)
			{
				param = axutil_array_list_get(param_list,env, i);
				if(param)
				{	
					if(axutil_param_get_param_type(param, env) == AXIS2_DLL_PARAM)
						continue;
					param_node = service_admin_util_serialize_param(env, param);
					if(param_node)
					{
						param_str = axiom_node_to_string(param_node, env);
						adb_getServiceParametersResponse_add_return(response, env, param_str);
					}
				}
			}
		}
	
	
	}

	return response;
}



/**
* auto generated function definition signature
* for "setBindingOperationMessagePolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setBindingOperationMessagePolicy of the adb_setBindingOperationMessagePolicy_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_setBindingOperationMessagePolicy(const axutil_env_t *env , 
														 axis2_msg_ctx_t *msg_ctx,
														 adb_setBindingOperationMessagePolicy_t* _setBindingOperationMessagePolicy,
														 axis2_skel_ServiceAdmin_setBindingOperationMessagePolicy_fault *fault )
{
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "setBindingPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setBindingPolicy of the adb_setBindingPolicy_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_setBindingPolicy(const axutil_env_t *env , 
										 axis2_msg_ctx_t *msg_ctx,
										 adb_setBindingPolicy_t* _setBindingPolicy,
										 axis2_skel_ServiceAdmin_setBindingPolicy_fault *fault )
{
	axis2_char_t *binding_policy = NULL;
	axis2_char_t *binding_policy_string = NULL;
	axis2_char_t *binding_service_name = NULL;
	
	binding_policy			= adb_setBindingPolicy_get_bindingName(_setBindingPolicy, env);
	binding_policy_string	= adb_setBindingPolicy_get_policyString(_setBindingPolicy, env);
	binding_service_name	= adb_setBindingPolicy_get_serviceName(_setBindingPolicy, env);

	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "removeServicePoliciesByNamespace|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _removeServicePoliciesByNamespace of the adb_removeServicePoliciesByNamespace_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_removeServicePoliciesByNamespace(const axutil_env_t *env , 
														 axis2_msg_ctx_t *msg_ctx,
														 adb_removeServicePoliciesByNamespace_t* _removeServicePoliciesByNamespace,
														 axis2_skel_ServiceAdmin_removeServicePoliciesByNamespace_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "setBindingOperationPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setBindingOperationPolicy of the adb_setBindingOperationPolicy_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_setBindingOperationPolicy(const axutil_env_t *env , 
												  axis2_msg_ctx_t *msg_ctx,
												  adb_setBindingOperationPolicy_t* _setBindingOperationPolicy,
												  axis2_skel_ServiceAdmin_setBindingOperationPolicy_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "setModulePolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setModulePolicy of the adb_setModulePolicy_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_setModulePolicy(const axutil_env_t *env , 
										axis2_msg_ctx_t *msg_ctx,
										adb_setModulePolicy_t* _setModulePolicy,
										axis2_skel_ServiceAdmin_setModulePolicy_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getBindingOperationMessagePolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getBindingOperationMessagePolicy of the adb_getBindingOperationMessagePolicy_t*
*
* @return adb_getBindingOperationMessagePolicyResponse_t*
*/
adb_getBindingOperationMessagePolicyResponse_t* 
axis2_skel_ServiceAdmin_getBindingOperationMessagePolicy(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_getBindingOperationMessagePolicy_t* _getBindingOperationMessagePolicy )
{
	/* Binding Policies are not supported by axis2/c */
	adb_getBindingOperationMessagePolicyResponse_t *response = NULL;
	response = adb_getBindingOperationMessagePolicyResponse_create(env);
	adb_getBindingOperationMessagePolicyResponse_set_return(response, env, ADMIN_SERVICE_EMPTY_POLICY);
	return response;
}



/**
* auto generated function definition signature
* for "changeServiceState|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _changeServiceState of the adb_changeServiceState_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_changeServiceState(const axutil_env_t *env , 
										   axis2_msg_ctx_t *msg_ctx,
										   adb_changeServiceState_t* _changeServiceState )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "setServiceParameters|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setServiceParameters of the adb_setServiceParameters_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_setServiceParameters(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_setServiceParameters_t* _setServiceParameters )
{
	axis2_char_t *service_name = NULL;
	axutil_array_list_t *param_list = NULL;
	axis2_char_t *param_str = NULL;
	axis2_svc_t *svc = NULL;
	axutil_param_t *param = NULL;
	int size = 0, i;

	

	service_name = adb_setServiceParameters_get_serviceName(_setServiceParameters, env);
	param_list	 = adb_setServiceParameters_get_parameters(_setServiceParameters, env);
	if(!service_name)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service name not found");
		return AXIS2_FAILURE;
	}
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service not found");
		return AXIS2_FAILURE;
	}
	if(!param_list)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"Parameter list not found");
		return AXIS2_FAILURE;
	}
	size = axutil_array_list_size(param_list, env);
	for(i =0; i <size; i++)
	{
		axiom_node_t *node = NULL;
		axiom_element_t *element = NULL;
		axis2_char_t *name_val = NULL, *locked_val = NULL;
		param_str = axutil_array_list_get(param_list, env, i);
	
		node = axiom_node_create_from_buffer(env, param_str);
		if(axiom_node_get_node_type(node,env) == AXIOM_ELEMENT)
		{
			element = (axiom_element_t*)axiom_node_get_data_element(node, env);
			if(!element)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Param axiom element null");
			}
			name_val = axiom_element_get_attribute_value_by_name(element, env, "name");
			locked_val = axiom_element_get_attribute_value_by_name(element, env, "locked");
			param_str = axiom_element_get_text(element, env, node);

			if(name_val)
			{
				param = axis2_svc_get_param(svc, env, name_val);
				/** Parameter exist */
				if(param)
				{
					if((locked_val && strcmp(locked_val,"false") == 0) || !locked_val)
					{
						axutil_param_set_value(param, env, param_str);
					}
				}else
				{
					/** create and add param */
					param = axutil_param_create(env, name_val, param_str);
					axutil_param_set_locked(param, env, AXIS2_FALSE);
					axis2_svc_add_param(svc, env, param);
				}
			}
		}
	}
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getOperationMessagePolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getOperationMessagePolicy of the adb_getOperationMessagePolicy_t*
*
* @return adb_getOperationMessagePolicyResponse_t*
*/
adb_getOperationMessagePolicyResponse_t* 
axis2_skel_ServiceAdmin_getOperationMessagePolicy(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_getOperationMessagePolicy_t* _getOperationMessagePolicy )
{
	axis2_char_t *svc_name = NULL, *op_name = NULL, *message_type = NULL;
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;
	adb_getOperationMessagePolicyResponse_t *response = NULL;
	svc_name = adb_getOperationMessagePolicy_get_serviceName(_getOperationMessagePolicy, env);
	op_name = adb_getOperationMessagePolicy_get_operationName(_getOperationMessagePolicy, env);
	message_type = adb_getOperationMessagePolicy_get_messageType(_getOperationMessagePolicy, env);

	svc = service_admin_util_get_service(env, msg_ctx, svc_name);
	response  = adb_getOperationMessagePolicyResponse_create(env);
	if(svc)
	{
		op = axis2_svc_get_op_with_name(svc, env, op_name);
		if(op)
		{
			axis2_msg_t * msg = NULL;
			msg = axis2_op_get_msg(op, env, message_type);
			if(msg)
			{
				axis2_desc_t *desc = NULL;
				axis2_policy_include_t *policy_include = NULL;
				
				desc = axis2_msg_get_base(msg, env);
				policy_include = axis2_desc_get_policy_include(desc, env);
				if(policy_include)
				{
					axiom_node_t *policy_node = NULL;
					neethi_policy_t *effective_policy = NULL;
					effective_policy = axis2_policy_include_get_effective_policy(policy_include, env);
					if(effective_policy)
					{
						axis2_char_t *policy_str = NULL;
						policy_node = neethi_policy_serialize(effective_policy, NULL, env);
						if(policy_node)
						{
							policy_str = axiom_node_to_string(policy_node, env);
							if(policy_str)
							{
								adb_getOperationMessagePolicyResponse_set_return(response, env, policy_str);
								return response;
							}
						}
					}
				}

			}
		}
	}
	adb_getOperationMessagePolicyResponse_set_return(response, env, ADMIN_SERVICE_EMPTY_POLICY);
	return response;
}



/**
* auto generated function definition signature
* for "getNumberOfActiveServices|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getNumberOfActiveServicesResponse_t*
*/
adb_getNumberOfActiveServicesResponse_t* 
axis2_skel_ServiceAdmin_getNumberOfActiveServices(const axutil_env_t *env , 
												  axis2_msg_ctx_t *msg_ctx,
												  axis2_skel_ServiceAdmin_getNumberOfActiveServices_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return (adb_getNumberOfActiveServicesResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "getServiceData|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getServiceData of the adb_getServiceData_t*
*
* @return adb_getServiceDataResponse_t*
*/
adb_getServiceDataResponse_t* 
axis2_skel_ServiceAdmin_getServiceData(const axutil_env_t *env , 
									   axis2_msg_ctx_t *msg_ctx,
									   adb_getServiceData_t* _getServiceData )
{
	adb_getServiceDataResponse_t *response = NULL;
    axis2_char_t *service_name = NULL;
    adb_ServiceMetaData_t *adb_svc = NULL;


    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *axis2_conf = NULL;
    axis2_svc_t *service = NULL;

    service_name = adb_getServiceData_get_serviceName(_getServiceData, env);
    if(!service_name)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service name is not given.");
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_SVC_SKEL_INVALID_OPERATION_PARAMETERS_IN_SOAP_REQUEST, AXIS2_FAILURE);
        return NULL;
    }
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    axis2_conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    service = axis2_conf_get_svc(axis2_conf, env, service_name);

    if(!service)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Cannot find service %s", service_name);
        AXIS2_ERROR_SET(env->error,
            AXIS2_ERROR_SVC_SKEL_INVALID_OPERATION_PARAMETERS_IN_SOAP_REQUEST, AXIS2_FAILURE);
        return NULL;
    }

    adb_svc = adb_ServiceMetaData_create(env);
    adb_ServiceMetaData_set_active(adb_svc, env, AXIS2_TRUE); /* TODO get this from somewhere */
	{
		axis2_char_t *description = axis2_svc_get_svc_desc(service, env); 
		adb_ServiceMetaData_set_description(adb_svc, env, description);
	}
    
    adb_ServiceMetaData_set_disableTryit(adb_svc, env, AXIS2_TRUE);
    adb_ServiceMetaData_add_eprs(adb_svc, env, service_admin_util_get_epr_address(env, msg_ctx, service_name )); /* TODO fix the epr, get it from somewhere */
    adb_ServiceMetaData_set_foundWebResources(adb_svc, env, AXIS2_FALSE);
	

    adb_ServiceMetaData_set_mtomStatus(adb_svc, env, "optional");
    adb_ServiceMetaData_set_name(adb_svc, env, service_name);
	{
		axutil_hash_t *op_map = NULL;
		axutil_hash_index_t *index = NULL;
		op_map = axis2_svc_get_all_ops(service, env);
        for (index = axutil_hash_first(op_map, env); index; index = axutil_hash_next(env, index))
        {
            void *v = NULL;
            axis2_op_t *op = NULL;
            axis2_char_t *op_name = NULL;
					
            axutil_hash_this(index, NULL, NULL, &v);
            op = (axis2_op_t *) v;
            op_name = axutil_qname_get_localpart(axis2_op_get_qname(op, env), env);
			if(op_name)
				adb_ServiceMetaData_add_operations(adb_svc, env,op_name);
		}
	}


    adb_ServiceMetaData_set_scope(adb_svc, env, "application");
	{
		axis2_svc_grp_t *svc_grp = NULL;
		svc_grp = axis2_svc_get_parent(service, env);
		if(svc_grp)
		{
			axis2_char_t *svc_grp_name = NULL;
			svc_grp_name = axis2_svc_grp_get_name(svc_grp, env);
			adb_ServiceMetaData_set_serviceGroupName(adb_svc, env, svc_grp_name);
		}
	}
    adb_ServiceMetaData_set_serviceId(adb_svc, env, service_name);
    adb_ServiceMetaData_set_serviceVersion(adb_svc, env, " ");
    adb_ServiceMetaData_set_serviceType(adb_svc, env,
    axis2_skel_ServiceAdmin_get_service_type(env, service));
    adb_ServiceMetaData_set_tryitURL(adb_svc, env, "http://localhost:9090/tryit");
    adb_ServiceMetaData_add_wsdlURLs(adb_svc, env, service_admin_util_get_wsdl_for_service(env, service_name, axis2_conf));
    adb_ServiceMetaData_add_wsdlURLs(adb_svc, env, "");
    response = adb_getServiceDataResponse_create_with_values(env, adb_svc);
    return response;
}



/**
* auto generated function definition signature
* for "removeTransportBinding|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _removeTransportBinding of the adb_removeTransportBinding_t*
*
* @return adb_removeTransportBindingResponse_t*
*/
adb_removeTransportBindingResponse_t* 
axis2_skel_ServiceAdmin_removeTransportBinding(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
												adb_removeTransportBinding_t* _removeTransportBinding,
												axis2_skel_ServiceAdmin_removeTransportBinding_fault *fault )
{
	adb_removeTransportBindingResponse_t *response = NULL;
	response = adb_removeTransportBindingResponse_create(env);
	adb_removeTransportBindingResponse_set_return(response, env, "TODO");
	return response;
}



/**
* auto generated function definition signature
* for "getPolicies|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getPolicies of the adb_getPolicies_t*
*
* @return adb_getPoliciesResponse_t*
*/
adb_getPoliciesResponse_t* 
axis2_skel_ServiceAdmin_getPolicies(const axutil_env_t *env , 
									axis2_msg_ctx_t *msg_ctx,
									adb_getPolicies_t* _getPolicies )
{
	/* TODO fill this with the necessary business logic */
	return (adb_getPoliciesResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "removeServiceParameter|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _removeServiceParameter of the adb_removeServiceParameter_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_removeServiceParameter(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_removeServiceParameter_t* _removeServiceParameter )
{
	axis2_svc_t *svc = NULL;
	axis2_char_t *service_name = NULL;
	axis2_char_t *param_name = NULL;
	
	service_name = adb_removeServiceParameter_get_serviceName(_removeServiceParameter, env);
	param_name = adb_removeServiceParameter_get_parameterName(_removeServiceParameter, env);
	if(!service_name)
		return AXIS2_FAILURE;
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(svc)
	{
		return axis2_svc_remove_param(svc, env, param_name);
	}
	return AXIS2_FAILURE;
}



/**
* auto generated function definition signature
* for "getBindingOperationPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getBindingOperationPolicy of the adb_getBindingOperationPolicy_t*
*
* @return adb_getBindingOperationPolicyResponse_t*
*/
adb_getBindingOperationPolicyResponse_t* 
axis2_skel_ServiceAdmin_getBindingOperationPolicy(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_getBindingOperationPolicy_t* _getBindingOperationPolicy )
{
	/** Binding Policies are not yet supported, hence returning an empty policy */
	adb_getBindingOperationPolicyResponse_t *response = NULL;
	response = adb_getBindingOperationPolicyResponse_create(env);
	adb_getBindingOperationPolicyResponse_set_return(response, env, ADMIN_SERVICE_EMPTY_POLICY);
	return response;
}



/**
* auto generated function definition signature
* for "deleteServiceGroups|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _deleteServiceGroups of the adb_deleteServiceGroups_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_deleteServiceGroups(const axutil_env_t *env , 
											axis2_msg_ctx_t *msg_ctx,
											adb_deleteServiceGroups_t* _deleteServiceGroups )
{
	return AXIS2_FAILURE;
}



/**
* auto generated function definition signature
* for "getNumberOfInactiveServices|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getNumberOfInactiveServicesResponse_t*
*/
adb_getNumberOfInactiveServicesResponse_t* 
axis2_skel_ServiceAdmin_getNumberOfInactiveServices(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	axis2_skel_ServiceAdmin_getNumberOfInactiveServices_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return (adb_getNumberOfInactiveServicesResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "setServiceOperationPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setServiceOperationPolicy of the adb_setServiceOperationPolicy_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_setServiceOperationPolicy(
	const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
	adb_setServiceOperationPolicy_t* _setServiceOperationPolicy,
	axis2_skel_ServiceAdmin_setServiceOperationPolicy_fault *fault )
{
	axis2_char_t *service_name = NULL,*operation_policy = NULL, *op_name = NULL;
	axis2_op_t *op = NULL;
	axis2_svc_t *svc = NULL;
	axis2_char_t *policy_str = NULL;
	axis2_policy_include_t *policy_include = NULL;
	axiom_node_t *policy_node = NULL;
	axis2_desc_t *desc = NULL;

	service_name = adb_setServiceOperationPolicy_get_serviceName(_setServiceOperationPolicy, env);
	operation_policy = adb_setServiceOperationPolicy_get_operationName(_setServiceOperationPolicy, env);
	policy_str = adb_setServiceOperationPolicy_get_policyString(_setServiceOperationPolicy, env);
	op_name = adb_setServiceOperationPolicy_get_operationName(_setServiceOperationPolicy, env);
	if(!service_name || !policy_str || !policy_str || !op_name)
	{
		AXIS2_LOG_ERROR(env->log, 
			AXIS2_LOG_SI, "incomplete parameters provided for method setServiceOperationPolicy");
		return	AXIS2_FAILURE;
	}
	
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Undefined Service requested as %s", service_name);
		return AXIS2_FAILURE;
	}
	
	op = axis2_svc_get_op_with_name(svc, env, op_name);
	if(!op)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Undefined operation requested as %s", op_name);
		return AXIS2_FAILURE;
	}
	desc = axis2_op_get_base(op, env);
	policy_include = axis2_desc_get_policy_include(desc, env);
	if(policy_include)
	{

		axiom_node_t *policy_node = NULL;
		neethi_policy_t *policy = NULL;
		axiom_element_t *ele = NULL;
		neethi_policy_t *current_policy = NULL;
		policy_node = axiom_node_create_from_buffer(env, policy_str);
		if(!policy_node)
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Policy string serialization filed");
			return AXIS2_FAILURE;
		}		
		ele = (axiom_element_t *)axiom_node_get_data_element(policy_node, env);

		policy = neethi_engine_get_policy(env, policy_node, ele);
		if(!policy)
		{
			/** TODO return an exception */
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "policy deserialization filed");
			return AXIS2_FAILURE;
		}
		axis2_policy_include_set_policy(policy_include, env, policy);
		return AXIS2_SUCCESS;
	}
	return AXIS2_FAILURE;
}



/**
* auto generated function definition signature
* for "deleteFaultyServiceGroup|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _deleteFaultyServiceGroup of the adb_deleteFaultyServiceGroup_t*
*
* @return adb_deleteFaultyServiceGroupResponse_t*
*/
adb_deleteFaultyServiceGroupResponse_t* axis2_skel_ServiceAdmin_deleteFaultyServiceGroup(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
																						 adb_deleteFaultyServiceGroup_t* _deleteFaultyServiceGroup )
{
	/* TODO fill this with the necessary business logic */
	return (adb_deleteFaultyServiceGroupResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "engageModuleToService|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _engageModuleToService of the adb_engageModuleToService_t*
*
* @return 
*/
axis2_status_t  axis2_skel_ServiceAdmin_engageModuleToService(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
															  adb_engageModuleToService_t* _engageModuleToService,
															  axis2_skel_ServiceAdmin_engageModuleToService_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "deleteFaultyServiceGroups|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _deleteFaultyServiceGroups of the adb_deleteFaultyServiceGroups_t*
*
* @return 
*/
axis2_status_t  axis2_skel_ServiceAdmin_deleteFaultyServiceGroups(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
																  adb_deleteFaultyServiceGroups_t* _deleteFaultyServiceGroups )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "removeBindingPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _removeBindingPolicy of the adb_removeBindingPolicy_t*
*
* @return 
*/
axis2_status_t  axis2_skel_ServiceAdmin_removeBindingPolicy(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
															adb_removeBindingPolicy_t* _removeBindingPolicy,
															axis2_skel_ServiceAdmin_removeBindingPolicy_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "deleteAllFaultyServiceGroups|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return 
*/
axis2_status_t  axis2_skel_ServiceAdmin_deleteAllFaultyServiceGroups(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "deleteAllNonAdminServiceGroups|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return 
*/
axis2_status_t  axis2_skel_ServiceAdmin_deleteAllNonAdminServiceGroups(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getModulePolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getModulePolicy of the adb_getModulePolicy_t*
*
* @return adb_getModulePolicyResponse_t*
*/
adb_getModulePolicyResponse_t* 
axis2_skel_ServiceAdmin_getModulePolicy(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_getModulePolicy_t* _getModulePolicy )
{
	axis2_char_t *module_name =  NULL;
	axis2_char_t *module_version = NULL;
	adb_getModulePolicyResponse_t *module_policy_response = NULL;
	module_name = adb_getModulePolicy_get_moduleName(_getModulePolicy, env);
	module_version = adb_getModulePolicy_get_moduleVersion(_getModulePolicy, env);

	module_policy_response = adb_getModulePolicyResponse_create(env);
	adb_getModulePolicyResponse_set_return(module_policy_response, env, ADMIN_SERVICE_EMPTY_POLICY);
	return module_policy_response;
}



/**
* auto generated function definition signature
* for "setPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setPolicy of the adb_setPolicy_t*
*
* @return 
*/
axis2_status_t  axis2_skel_ServiceAdmin_setPolicy(
	const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
	adb_setPolicy_t* _setPolicy,
	axis2_skel_ServiceAdmin_setPolicy_fault *fault )
{
	
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "listServiceGroups|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _listServiceGroups of the adb_listServiceGroups_t*
*
* @return adb_listServiceGroupsResponse_t*
*/
adb_listServiceGroupsResponse_t* 
axis2_skel_ServiceAdmin_listServiceGroups(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
										adb_listServiceGroups_t* _listServiceGroups )
{
adb_listServiceGroupsResponse_t *response = NULL;
    adb_ServiceGroupMetaDataWrapper_t *metadata = NULL;
    axutil_array_list_t *adb_svc_grps = NULL; /* contains list of adb_ServiceGroupMetaData_t */
    axutil_array_list_t *adb_svc_types = NULL; /* contains list of service types(char*) */
    axutil_hash_t *service_types = NULL; /* to get the unique set of service types */
    int no_of_correct_service_grp = 0;
    int no_of_faulty_service_grp = 0;
    int no_of_pages = 1;

    axis2_char_t *service_type_filter = NULL;
    axis2_char_t *svc_grp_filter = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *axis2_conf = NULL;
    axutil_hash_t *svc_grp_map = NULL;
    axutil_hash_index_t *hi;
    adb_svc_grps = axutil_array_list_create(env, 0);
    service_types = axutil_hash_make(env);

    /* if the service type filter is not set, set it to default value */
    service_type_filter = adb_listServiceGroups_get_serviceTypeFilter(_listServiceGroups, env);
    if((!service_type_filter) || (!axutil_strcmp(service_type_filter, "")))
    {
        service_type_filter = DEFAULT_SERVICE_TYPE_FILTER;
    }

    svc_grp_filter = adb_listServiceGroups_get_serviceGroupSearchString(_listServiceGroups,env);

    /* get the service groups and populate it */
    conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
    axis2_conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    svc_grp_map = axis2_conf_get_all_svc_grps(axis2_conf, env);

    for(hi = axutil_hash_first(svc_grp_map, env); hi; hi = axutil_hash_next(env, hi))
    {
        axis2_svc_grp_t *svc_grp = NULL;
        axis2_char_t *svc_grp_name = NULL;
        axutil_hash_t *svc_map = NULL;
        adb_ServiceGroupMetaData_t *adb_svc_grp = NULL;
        axutil_array_list_t *adb_svc_list = NULL; /* contains list of adb_ServiceMetaData_t */
        axutil_hash_index_t *hi_svc;
        axutil_array_list_t *engaged_module  = NULL;

        axutil_hash_this(hi, &svc_grp_name, NULL, &svc_grp);

        /* Check whether service group filter is satisfied */
		if(svc_grp && service_admin_util_is_filtered_out_service_group(env, svc_grp) == AXIS2_TRUE)
		{
			continue;
		}

        svc_map = axis2_svc_grp_get_all_svcs(svc_grp, env);
        adb_svc_list = axutil_array_list_create(env, 0);
        for(hi_svc = axutil_hash_first(svc_map, env); hi_svc; hi_svc = axutil_hash_next(env, hi_svc))
        {
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            adb_ServiceMetaData_t *adb_svc = NULL;
            axis2_char_t *service_type = NULL;

            axutil_hash_this(hi_svc, &svc_name, NULL, &svc);
            /* Get the service type and filter using the given service type */
            service_type = axis2_skel_ServiceAdmin_get_service_type(env, svc);
            if(axutil_strcmp(service_type_filter, DEFAULT_SERVICE_TYPE_FILTER) &&
                axutil_strcmp(service_type, service_type_filter))
            {
                /* filter is not satisfied */
                continue;
            }
			if(svc && service_admin_util_is_filtered_out_service(env, svc) == AXIS2_TRUE)
			{
			continue;
			}

            /* check whether service type is already added, if not add it */
            if(!axutil_hash_get(service_types, service_type, AXIS2_HASH_KEY_STRING))
            {
                axutil_hash_set(service_types, service_type, AXIS2_HASH_KEY_STRING, service_type);
            }

            adb_svc = adb_ServiceMetaData_create(env);
            adb_ServiceMetaData_set_active(adb_svc, env, AXIS2_TRUE); /* TODO get this from somewhere */
            adb_ServiceMetaData_set_disableTryit(adb_svc, env, AXIS2_TRUE);
            /*adb_ServiceMetaData_set_tryitURL(adb_svc, env, "http://localhost:9090/test/tryit");*/
            adb_ServiceMetaData_set_name(adb_svc, env, svc_name);
            adb_ServiceMetaData_set_serviceType(adb_svc, env, service_type);

            /* TODO fix the wsdl endpoints */
			adb_ServiceMetaData_add_wsdlURLs(adb_svc, env, service_admin_util_get_wsdl_for_service(env, svc_name, axis2_conf));
            adb_ServiceMetaData_add_wsdlURLs(adb_svc, env, "");

            axutil_array_list_add(adb_svc_list, env, adb_svc);
        }

        /* check whether there are atleast one service for this group. There might be empty groups
         * due to the filters
         */
        if(axutil_array_list_size(adb_svc_list, env))
        {
            adb_svc_grp = adb_ServiceGroupMetaData_create(env);
            adb_ServiceGroupMetaData_set_serviceGroupName(adb_svc_grp, env, svc_grp_name);
            adb_ServiceGroupMetaData_set_services(adb_svc_grp, env, adb_svc_list);
            axutil_array_list_add(adb_svc_grps, env, adb_svc_grp);
        }
        else
        {
            axutil_array_list_free(adb_svc_list, env);
        }
    }

    no_of_correct_service_grp = axutil_array_list_size(adb_svc_grps, env);
    adb_svc_types = axutil_array_list_create(env, 0);
    for(hi = axutil_hash_first(service_types, env); hi; hi = axutil_hash_next(env, hi))
    {
        axis2_char_t *service_type = NULL;
        axutil_hash_this(hi, &service_type, NULL, NULL);
        axutil_array_list_add(adb_svc_types, env, axutil_strdup(env, service_type));
    }
    axutil_hash_free(service_types, env);

    metadata = adb_ServiceGroupMetaDataWrapper_create_with_values(env, adb_svc_grps,
        no_of_correct_service_grp, no_of_faulty_service_grp, no_of_pages, adb_svc_types);
    response = adb_listServiceGroupsResponse_create_with_values(env, metadata);
    return response;
}



/**
* auto generated function definition signature
* for "setServiceOperationMessagePolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setServiceOperationMessagePolicy of the adb_setServiceOperationMessagePolicy_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceAdmin_setServiceOperationMessagePolicy(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_setServiceOperationMessagePolicy_t* _setServiceOperationMessagePolicy,
	axis2_skel_ServiceAdmin_setServiceOperationMessagePolicy_fault *fault )
{
	axis2_char_t *svc_name = NULL, *op_name = NULL, *message_type = NULL;
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;
	axis2_char_t *policy_string = NULL;

	svc_name = adb_setServiceOperationMessagePolicy_get_serviceName(_setServiceOperationMessagePolicy, env);
	op_name = adb_setServiceOperationMessagePolicy_get_operationName(_setServiceOperationMessagePolicy, env);
	message_type = adb_setServiceOperationMessagePolicy_get_messageType(_setServiceOperationMessagePolicy, env);
	svc = service_admin_util_get_service(env, msg_ctx, svc_name);
	policy_string = adb_setServiceOperationMessagePolicy_get_policyString(_setServiceOperationMessagePolicy, env);
	if(!policy_string)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"Null policy string specified");
		return AXIS2_FAILURE;
	}
	if(svc)
	{
		op = axis2_svc_get_op_with_name(svc, env, op_name);
		if(op)
		{
			axis2_msg_t * msg = NULL;
			msg = axis2_op_get_msg(op, env, message_type);
			if(msg)
			{
				axis2_desc_t *desc = NULL;
				axis2_policy_include_t *policy_include = NULL;
				
				desc = axis2_msg_get_base(msg, env);
				policy_include = axis2_desc_get_policy_include(desc, env);
				if(policy_include)
				{
					axiom_node_t *policy_node = NULL;
					policy_node = axiom_node_create_from_buffer(env, policy_string);
					if(policy_node)
					{
						axiom_element_t *ele = NULL;
						neethi_policy_t *neethi_policy = NULL;
						
						ele = axiom_node_get_data_element(policy_node, env);
						neethi_policy = neethi_engine_get_policy(env, policy_node, ele);
						if(neethi_policy)
						{
							axis2_policy_include_set_policy(policy_include, env, neethi_policy);
							return AXIS2_SUCCESS;
						}
					}
				}
			}
		}
	}
	return AXIS2_FAILURE;
}



/**
* auto generated function definition signature
* for "getBindingPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getBindingPolicy of the adb_getBindingPolicy_t*
*
* @return adb_getBindingPolicyResponse_t*
*/
adb_getBindingPolicyResponse_t* 
axis2_skel_ServiceAdmin_getBindingPolicy(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_getBindingPolicy_t* _getBindingPolicy )
{
	/** TODO Axis2 does not have binding policies at the moment, returning empty policy */

	adb_getBindingPolicyResponse_t *response  = NULL;
	response = adb_getBindingPolicyResponse_create(env);
	adb_getBindingPolicyResponse_set_return(response, env, ADMIN_SERVICE_EMPTY_POLICY);
	return response;
}



/**
* auto generated function definition signature
* for "getServiceBindings|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getServiceBindings of the adb_getServiceBindings_t*
*
* @return adb_getServiceBindingsResponse_t*
*/
adb_getServiceBindingsResponse_t* 
axis2_skel_ServiceAdmin_getServiceBindings(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_getServiceBindings_t* _getServiceBindings,
	axis2_skel_ServiceAdmin_getServiceBindings_fault *fault )
{
	axis2_char_t *service_name = NULL;
	axis2_svc_t *svc = NULL;
	axis2_desc_t *desc = NULL;
	axis2_policy_include_t *policy_include = NULL;
	adb_getServiceBindingsResponse_t *response = NULL;
	neethi_policy_t *effective_policy = NULL;

	service_name = adb_getServiceBindings_get_serviceName(_getServiceBindings,env);
	if(!service_name)
	{
		/** TODO Return Fault */
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service name not found");
		return NULL;
	}
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		/** TODO Return Fault */
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service not found");
		return NULL;
	}

	desc = axis2_svc_get_base(svc, env);
	if(!desc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"Serivce Desc not found ");
		return NULL;
	}
	policy_include = axis2_desc_get_policy_include(desc, env);
	response = adb_getServiceBindingsResponse_create(env);
	if(policy_include)
	{
		axiom_node_t *policy_node = NULL;
		effective_policy = axis2_policy_include_get_effective_policy(policy_include, env);
		if(effective_policy)
		{
			axis2_char_t *policy_str = NULL;
			policy_node = neethi_policy_serialize(effective_policy, NULL, env);
			if(policy_node)
			{
				policy_str = axiom_node_to_string(policy_node, env);
				if(policy_str)
				{
					adb_getServiceBindingsResponse_add_return(response, env, policy_str);
					return response;
				}
			}
		}
	}
	
	adb_getServiceBindingsResponse_add_return(response, env, " ");
	return response;
}



/**
* auto generated function definition signature
* for "stopService|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _stopService of the adb_stopService_t*
*
* @return 
*/
axis2_status_t  axis2_skel_ServiceAdmin_stopService(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
													adb_stopService_t* _stopService,
													axis2_skel_ServiceAdmin_stopService_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getOperationPolicy|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getOperationPolicy of the adb_getOperationPolicy_t*
*
* @return adb_getOperationPolicyResponse_t*
*/
adb_getOperationPolicyResponse_t* 
axis2_skel_ServiceAdmin_getOperationPolicy(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_getOperationPolicy_t* _getOperationPolicy )
{
	axis2_char_t *op_name = NULL;
	axis2_char_t *service_name = NULL;
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;
	adb_getOperationPolicyResponse_t *response = NULL;
	service_name = adb_getOperationPolicy_get_serviceName(_getOperationPolicy, env);
	op_name = adb_getOperationPolicy_get_operationName(_getOperationPolicy, env);
	response = adb_getOperationPolicyResponse_create(env);
	
	if(!service_name || !op_name)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service name or operation name empty");
		return NULL;
	}
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(svc)
	{
		op = axis2_svc_get_op_with_name(svc, env, op_name);
		if(op)
		{
			axis2_desc_t *desc = NULL;
			axis2_policy_include_t *policy_include = NULL;
			neethi_policy_t *policy = NULL;
			axiom_node_t *policy_node = NULL;
			axis2_char_t *policy_str = NULL;

			desc = axis2_op_get_base(op, env);
			if(desc)
			{
				policy_include = axis2_desc_get_policy_include(desc, env);
				if(policy_include)
				{
					policy = axis2_policy_include_get_effective_policy(policy_include, env);
					if(policy)
					{
						policy_node = neethi_engine_serialize(policy, env);
						policy_str = axiom_node_to_string(policy_node, env);
						adb_getOperationPolicyResponse_set_return(response, env, policy_str);
						return response;
					}
				
				}
			}		
		}
	}
	adb_getOperationPolicyResponse_set_return(response, env, ADMIN_SERVICE_EMPTY_POLICY);
	return response;
}


static axis2_char_t *axis2_skel_ServiceAdmin_get_service_type(
    const axutil_env_t *env,
    axis2_svc_t *svc)
{
    axutil_param_t* param = NULL;

    param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_TYPE);
    if(!param)
    {
        /* Send default service type */
        return AXIS2_DEFAULT_SERVICE_TYPE;
    }

    return (axis2_char_t*)axutil_param_get_value(param, env);
}

