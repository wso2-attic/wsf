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
* axis2_skel_ServiceGroupAdmin.c
*
* This file was auto-generated from WSDL for "ServiceGroupAdmin|http://mgt.service.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_ServiceGroupAdmin Axis2/C skeleton for the axisService
*/

#include "codegen/axis2_skel_ServiceGroupAdmin.h"
#include "service_admin_constants.h"
#include "axis2_transport_receiver.h"
#include "service_admin_util.h"



/**
* auto generated function definition signature
* for "listServiceGroup|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _listServiceGroup of the adb_listServiceGroup_t*
*
* @return adb_listServiceGroupResponse_t*
*/

adb_listServiceGroupResponse_t* 
axis2_skel_ServiceGroupAdmin_listServiceGroup(const axutil_env_t *env , 
											  axis2_msg_ctx_t *msg_ctx,
											  adb_listServiceGroup_t* _listServiceGroup,
											  axis2_skel_ServiceGroupAdmin_listServiceGroup_fault *fault )
{
	axis2_char_t *svc_grp_name = NULL;
	adb_listServiceGroupResponse_t *response = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_svc_grp_t* svc_grp = NULL;
	axutil_hash_t *svc_map = NULL;
	axutil_array_list_t *adb_svc_list = NULL; /* contains a list of adb_ServiceMetaData_t */
	adb_ServiceGroupMetaData_t *svc_grp_metadata = NULL;
	axutil_hash_index_t *hi_svc = NULL;
	
	
	svc_grp_name = adb_listServiceGroup_get_serviceGroupName(_listServiceGroup, env);
	if(!svc_grp_name)
	{
		 AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Group name not given.");
        AXIS2_ERROR_SET(env->error,
			AXIS2_ERROR_SVC_SKEL_INVALID_OPERATION_PARAMETERS_IN_SOAP_REQUEST, AXIS2_FAILURE);
        return NULL;
	}
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	svc_grp = axis2_conf_get_svc_grp(conf, env, svc_grp_name);

	if(!svc_grp)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Group not found for %s.", svc_grp_name);
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_OPERATION_PARAMETERS_IN_SOAP_REQUEST, AXIS2_FAILURE);
        return NULL;
	}

	response = adb_listServiceGroupResponse_create(env);

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
			{
				axutil_param_t* param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_TYPE);
				if(!param)
				{
					service_type = AXIS2_DEFAULT_SERVICE_TYPE;
				}else{
					service_type = (axis2_char_t*)axutil_param_get_value(param, env);
				}
				
			}
			if(svc && service_admin_util_is_filtered_out_service(env, svc) == AXIS2_TRUE)
				continue;
			
            adb_svc = adb_ServiceMetaData_create(env);
            adb_ServiceMetaData_set_active(adb_svc, env, AXIS2_TRUE); /* TODO get this from somewhere */
            adb_ServiceMetaData_set_disableTryit(adb_svc, env, AXIS2_TRUE);
            /*adb_ServiceMetaData_set_tryitURL(adb_svc, env, "http://localhost:9090/test/tryit");*/
            adb_ServiceMetaData_set_name(adb_svc, env, svc_name);
            adb_ServiceMetaData_set_serviceType(adb_svc, env, service_type);

			
			adb_ServiceMetaData_add_wsdlURLs(adb_svc, env,service_admin_util_get_wsdl_for_service(env, svc_name, conf));
            adb_ServiceMetaData_add_wsdlURLs(adb_svc, env, " ");

            axutil_array_list_add(adb_svc_list, env, adb_svc);
    }

    /* check whether there are atleast one service for this group. There might be empty groups
     * due to the filters
     */
    if(axutil_array_list_size(adb_svc_list, env))
    {
        svc_grp_metadata = adb_ServiceGroupMetaData_create(env);
        adb_ServiceGroupMetaData_set_serviceGroupName(svc_grp_metadata, env, svc_grp_name);
        adb_ServiceGroupMetaData_set_services(svc_grp_metadata, env, adb_svc_list);
		adb_ServiceGroupMetaData_set_engagedModules_nil(svc_grp_metadata, env);
		adb_ServiceGroupMetaData_set_serviceContextPath(svc_grp_metadata, env ,"");
		adb_ServiceGroupMetaData_set_mtomStatus(svc_grp_metadata, env, "optional");
        
    }
    else
    {
        axutil_array_list_free(adb_svc_list, env);
    }
	{	
		axutil_param_t *param = axis2_svc_grp_get_param(svc_grp, env, AXIS2_ENABLE_MTOM);
		if(param && svc_grp_metadata)
		{
			adb_ServiceGroupMetaData_set_mtomStatus(svc_grp_metadata, env, axutil_param_get_value(param, env));
		}
	}
	adb_listServiceGroupResponse_set_return(response, env, svc_grp_metadata);
	return response;
}



/**
* auto generated function definition signature
* for "setServiceGroupParameters|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setServiceGroupParameters of the adb_setServiceGroupParameters_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceGroupAdmin_setServiceGroupParameters(
	const axutil_env_t *env , 
    axis2_msg_ctx_t *msg_ctx,
    adb_setServiceGroupParameters_t* _setServiceGroupParameters )
{
	axis2_char_t *service_name = NULL;
	axis2_char_t *svc_grp_name = NULL;
	axutil_array_list_t *param_list = NULL;
	axis2_char_t *param_str = NULL;
	axis2_svc_grp_t *svc_grp = NULL;
	axutil_param_t *param = NULL;
	int size = 0, i;

	svc_grp_name = adb_setServiceGroupParameters_get_serviceGroupId(_setServiceGroupParameters, env);
	param_list	 = adb_setServiceGroupParameters_get_parameterElement(_setServiceGroupParameters, env);
	if(!svc_grp_name)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service name not found");
		return AXIS2_FAILURE;
	}
	
	svc_grp = service_admin_util_get_service_group(env, msg_ctx, svc_grp_name);
	if(!svc_grp)
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
				param = axis2_svc_grp_get_param(svc_grp, env, name_val);
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
					axis2_svc_grp_add_param(svc_grp, env, param);
				}
			}
		}
	}
	return AXIS2_SUCCESS;

}



/**
* auto generated function definition signature
* for "getServiceGroupParameter|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getServiceGroupParameter of the adb_getServiceGroupParameter_t*
*
* @return adb_getServiceGroupParameterResponse_t*
*/
adb_getServiceGroupParameterResponse_t* 
axis2_skel_ServiceGroupAdmin_getServiceGroupParameter(const axutil_env_t *env , 
													  axis2_msg_ctx_t *msg_ctx,
													  adb_getServiceGroupParameter_t* _getServiceGroupParameter,
													  axis2_skel_ServiceGroupAdmin_getServiceGroupParameter_fault *fault )
{
	adb_getServiceGroupParameterResponse_t *response = NULL;

	return (adb_getServiceGroupParameterResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "configureServiceGroupMTOM|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _configureServiceGroupMTOM of the adb_configureServiceGroupMTOM_t*
*
* @return adb_configureServiceGroupMTOMResponse_t*
*/
adb_configureServiceGroupMTOMResponse_t* 
axis2_skel_ServiceGroupAdmin_configureServiceGroupMTOM(
	const axutil_env_t *env ,
	axis2_msg_ctx_t *msg_ctx,
	adb_configureServiceGroupMTOM_t* _configureServiceGroupMTOM,
	axis2_skel_ServiceGroupAdmin_configureServiceGroupMTOM_fault *fault )
{
	axis2_char_t *svc_grp_name = NULL;
	adb_configureServiceGroupMTOMResponse_t *response = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_svc_grp_t* svc_grp = NULL;
	axutil_hash_t *svc_map = NULL;
	axutil_array_list_t *adb_svc_list = NULL; /* contains a list of adb_ServiceMetaData_t */
	adb_ServiceGroupMetaData_t *svc_grp_metadata = NULL;
	axutil_hash_index_t *hi_svc = NULL;
	axis2_char_t *flag = NULL;
	
	svc_grp_name = adb_configureServiceGroupMTOM_get_serviceGroupName(_configureServiceGroupMTOM, env);
	if(!svc_grp_name)
	{
		 AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Group name not given.");
        AXIS2_ERROR_SET(env->error,
			AXIS2_ERROR_SVC_SKEL_INVALID_OPERATION_PARAMETERS_IN_SOAP_REQUEST, AXIS2_FAILURE);
        return NULL;
	}
	flag = adb_configureServiceGroupMTOM_get_flag(_configureServiceGroupMTOM, env);
	
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	svc_grp = axis2_conf_get_svc_grp(conf, env, svc_grp_name);
	
	if(!svc_grp)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Group not found for %s.", svc_grp_name);
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_OPERATION_PARAMETERS_IN_SOAP_REQUEST, AXIS2_FAILURE);
        return NULL;
	}

	response = adb_configureServiceGroupMTOMResponse_create(env);

	svc_map = axis2_svc_grp_get_all_svcs(svc_grp, env);
	adb_svc_list = axutil_array_list_create(env, 0);
    for(hi_svc = axutil_hash_first(svc_map, env); hi_svc; hi_svc = axutil_hash_next(env, hi_svc))
    {
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            adb_ServiceMetaData_t *adb_svc = NULL;
            axis2_char_t *service_type = NULL;
			axutil_param_t *param = NULL;	

            axutil_hash_this(hi_svc, &svc_name, NULL, &svc);
            /* Get the service type and filter using the given service type */
			{
				axutil_param_t* param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_TYPE);
				if(!param)
				{
					service_type = AXIS2_DEFAULT_SERVICE_TYPE;
				}else{
					service_type = (axis2_char_t*)axutil_param_get_value(param, env);
				}
				
			}
			if(flag)
			{
				param = axutil_param_create(env, AXIS2_ENABLE_MTOM, flag);
				axis2_svc_add_param(svc, env, param);
			}
			
			if(svc && service_admin_util_is_filtered_out_service(env, svc) == AXIS2_TRUE)
				continue;
			
            adb_svc = adb_ServiceMetaData_create(env);
            adb_ServiceMetaData_set_active(adb_svc, env, AXIS2_TRUE); /* TODO get this from somewhere */
            adb_ServiceMetaData_set_disableTryit(adb_svc, env, AXIS2_TRUE);
            /*adb_ServiceMetaData_set_tryitURL(adb_svc, env, "http://localhost:9090/test/tryit");*/
            adb_ServiceMetaData_set_name(adb_svc, env, svc_name);
            adb_ServiceMetaData_set_serviceType(adb_svc, env, service_type);

			
			adb_ServiceMetaData_add_wsdlURLs(adb_svc, env,service_admin_util_get_wsdl_for_service(env, svc_name, conf));
            adb_ServiceMetaData_add_wsdlURLs(adb_svc, env, " ");

            axutil_array_list_add(adb_svc_list, env, adb_svc);
    }

    /* check whether there are atleast one service for this group. There might be empty groups
     * due to the filters
     */
    if(axutil_array_list_size(adb_svc_list, env))
    {
        svc_grp_metadata = adb_ServiceGroupMetaData_create(env);
        adb_ServiceGroupMetaData_set_serviceGroupName(svc_grp_metadata, env, svc_grp_name);
        adb_ServiceGroupMetaData_set_services(svc_grp_metadata, env, adb_svc_list);
		adb_ServiceGroupMetaData_set_engagedModules_nil(svc_grp_metadata, env);
		adb_ServiceGroupMetaData_set_serviceContextPath(svc_grp_metadata, env ,"");
		adb_ServiceGroupMetaData_set_mtomStatus(svc_grp_metadata, env, (flag!= NULL) ? flag : "optional");
        
    }
    else
    {
        axutil_array_list_free(adb_svc_list, env);
    }
	{	
		axutil_param_t *param = axis2_svc_grp_get_param(svc_grp, env, AXIS2_ENABLE_MTOM);
		if(param && svc_grp_metadata)
		{
			adb_ServiceGroupMetaData_set_mtomStatus(svc_grp_metadata, env, axutil_param_get_value(param, env));
		}
	}
	adb_configureServiceGroupMTOMResponse_set_return(response, env, svc_grp_metadata);
	return response;
}



/**
* auto generated function definition signature
* for "removeServiceGroupParameter|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _removeServiceGroupParameter of the adb_removeServiceGroupParameter_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceGroupAdmin_removeServiceGroupParameter(const axutil_env_t *env , 
														 axis2_msg_ctx_t *msg_ctx,
														  adb_removeServiceGroupParameter_t* _removeServiceGroupParameter )
{
	axis2_char_t *service_group_name = NULL;
	axis2_char_t *param_name = NULL;
	axis2_svc_grp_t *svc_grp = NULL;
	axutil_param_t *param = NULL;
	
	service_group_name = adb_removeServiceGroupParameter_get_serviceGroupId(_removeServiceGroupParameter, env);
	param_name = adb_removeServiceGroupParameter_get_parameterName(_removeServiceGroupParameter, env);
	if(!service_group_name)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Group null");
		return AXIS2_FAILURE;
	}
	svc_grp = service_admin_util_get_service_group(env, msg_ctx, service_group_name);
	if(!svc_grp)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Group does not exist");
		return AXIS2_FAILURE;
	}
		
	return axis2_svc_grp_remove_param(svc_grp, env, param_name);
}



/**
* auto generated function definition signature
* for "updateServiceGroupParamters|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _updateServiceGroupParamters of the adb_updateServiceGroupParamters_t*
*
* @return 
*/
axis2_status_t  
	axis2_skel_ServiceGroupAdmin_updateServiceGroupParamters(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_updateServiceGroupParamters_t* _updateServiceGroupParamters,
	axis2_skel_ServiceGroupAdmin_updateServiceGroupParamters_fault *fault )
{
	axis2_char_t *svc_grp_name = NULL;
	axis2_svc_grp_t *svc_grp = NULL;
	axutil_array_list_t *param_list = NULL;
	
	svc_grp_name = adb_updateServiceGroupParamters_get_serviceGroupName(_updateServiceGroupParamters, env);
	if(!svc_grp_name)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service group null");
		return AXIS2_FAILURE;
	}
	svc_grp = service_admin_util_get_service_group(env, msg_ctx, svc_grp_name);
	if(!svc_grp)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service group null");
		return AXIS2_FAILURE;
	}

		 
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "dumpAAR|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _dumpAAR of the adb_dumpAAR_t*
*
* @return adb_dumpAARResponse_t*
*/
adb_dumpAARResponse_t* axis2_skel_ServiceGroupAdmin_dumpAAR(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_dumpAAR_t* _dumpAAR )
{
	axis2_char_t *grp_name = adb_dumpAAR_get_serviceGroupName(_dumpAAR, env);
	adb_dumpAARResponse_t *dump_res = adb_dumpAARResponse_create(env);
	adb_dumpAARResponse_set_return(dump_res, env, grp_name);
	/** TODO: Fill with a correct respone */
	return dump_res;
}



/**
* auto generated function definition signature
* for "setServiceGroupParameter|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _setServiceGroupParameter of the adb_setServiceGroupParameter_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceGroupAdmin_setServiceGroupParameter(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_setServiceGroupParameter_t* _setServiceGroupParameter )
{
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "updateServiceGroupParameter|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _updateServiceGroupParameter of the adb_updateServiceGroupParameter_t*
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceGroupAdmin_updateServiceGroupParameter(
const axutil_env_t *env , 
axis2_msg_ctx_t *msg_ctx,
adb_updateServiceGroupParameter_t* _updateServiceGroupParameter,
axis2_skel_ServiceGroupAdmin_updateServiceGroupParameter_fault *fault )
{
	axis2_char_t *service_group_name = NULL;
	adb_ParameterMetaData_t *meta_data = NULL;
	axis2_char_t *param_value = NULL, *param_name = NULL;
	axis2_bool_t editable = AXIS2_FALSE, locked = AXIS2_FALSE;
	axis2_svc_grp_t *svc_grp = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	
	service_group_name = adb_updateServiceGroupParameter_get_serviceGroupName(_updateServiceGroupParameter, env);
	meta_data = adb_updateServiceGroupParameter_get_paramMetaData(_updateServiceGroupParameter, env);
	if(meta_data)
	{
		editable =	adb_ParameterMetaData_get_editable(meta_data, env);
		locked   =  adb_ParameterMetaData_get_locked(meta_data, env);
		param_name = adb_ParameterMetaData_get_name(meta_data, env);
		param_value = adb_ParameterMetaData_get_value(meta_data, env);
	}else{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Paramater Meta Data not present in the message");
		return AXIS2_FAILURE;
	}	
	if(service_group_name)
	{
		axutil_param_t *param = NULL;
		conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
		conf = axis2_conf_ctx_get_conf(conf_ctx, env);
		svc_grp = axis2_conf_get_svc_grp(conf, env, service_group_name);
		if(svc_grp){
			param = axis2_svc_grp_get_param(svc_grp, env, param_name);
			if(!param)
			{
				param = axutil_param_create(env, param_name, param_value);
				axis2_svc_grp_add_param(svc_grp, env, param);
				return AXIS2_SUCCESS;
			}else
			{
				axis2_bool_t is_locked = AXIS2_FALSE;
				is_locked = axutil_param_is_locked(param,env);
				if(!is_locked)
				{
					axutil_param_set_value(param,env,param_value);
				}
			}
		}else{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"service group not found ");
			return AXIS2_FAILURE;
		}
	}else{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service group name not found");
		return AXIS2_FAILURE;
	}
	return AXIS2_FAILURE;
}



/**
* auto generated function definition signature
* for "listServiceGroups|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return 
*/
axis2_status_t  
axis2_skel_ServiceGroupAdmin_listServiceGroups(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
{
	
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getServiceGroupParameters|http://mgt.service.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
* @param _getServiceGroupParameters of the adb_getServiceGroupParameters_t*
*
* @return adb_getServiceGroupParametersResponse_t*
*/
adb_getServiceGroupParametersResponse_t* 
axis2_skel_ServiceGroupAdmin_getServiceGroupParameters(const axutil_env_t *env , 
													   axis2_msg_ctx_t *msg_ctx,
													   adb_getServiceGroupParameters_t* _getServiceGroupParameters,
													   axis2_skel_ServiceGroupAdmin_getServiceGroupParameters_fault *fault )
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_svc_grp_t* svc_grp = NULL;
	axutil_array_list_t *param_list = NULL;
	adb_getServiceGroupParametersResponse_t *response = NULL;
	int i = 0;
	int size = 0;
	axis2_char_t *svc_grp_name = adb_getServiceGroupParameters_get_serviceGroupName(_getServiceGroupParameters, env);
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	svc_grp = axis2_conf_get_svc_grp(conf, env, svc_grp_name);
	if(!svc_grp)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service Group Not found ");
		return NULL;
	}
	param_list = axis2_svc_grp_get_all_params(svc_grp, env);
	if(!param_list)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Parameter List Not found ");
		return NULL;
	}
	response = adb_getServiceGroupParametersResponse_create(env);
	size = axutil_array_list_size(param_list, env);
	for(i =0; i < size; i++)
	{
		axis2_char_t *param_str = NULL;
		axiom_node_t *param_node = NULL;
		axutil_param_t *param = NULL;
		param = axutil_array_list_get(param_list,env, i);
		if(axutil_param_get_param_type(param, env) == AXIS2_DLL_PARAM)
						continue;
		if(param)
		{	
			param_node = service_admin_util_serialize_param(env, param);
			if(param_node)
			{
				param_str = axiom_node_to_string(param_node, env);
				adb_getServiceGroupParametersResponse_add_return(response, env, param_str);
			}
		}
	}
	return response;
}

