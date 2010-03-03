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
     * axis2_skel_OperationAdmin.c
     *
     * This file was auto-generated from WSDL for "OperationAdmin|http://mgt.operation.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_OperationAdmin Axis2/C skeleton for the axisService
     */

#include "codegen/axis2_skel_OperationAdmin.h"
#include "service_admin_util.h"
#include "axis2_op.h"

     

		 
        /**
         * auto generated function definition signature
         * for "listOperationPhaseHandlers|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listOperationPhaseHandlers of the adb_listOperationPhaseHandlers_t*
         *
         * @return adb_listOperationPhaseHandlersResponse_t*
         */
adb_listOperationPhaseHandlersResponse_t* 
axis2_skel_OperationAdmin_listOperationPhaseHandlers(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_listOperationPhaseHandlers_t* _listOperationPhaseHandlers )
{
  /* TODO fill this with the necessary business logic */
  return (adb_listOperationPhaseHandlersResponse_t*)NULL;
}


		 
        /**
         * auto generated function definition signature
         * for "setPolicy|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setPolicy of the adb_setPolicy_t*
         *
         * @return 
         */
axis2_status_t  
	axis2_skel_OperationAdmin_setPolicy(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_setPolicy_t* _setPolicy )
{
  /* TODO fill this with the necessary business logic */
  return AXIS2_SUCCESS;
}
     

		 
        /**
         * auto generated function definition signature
         * for "listOperationPhases|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listOperationPhases of the adb_listOperationPhases_t*
         *
         * @return adb_listOperationPhasesResponse_t*
         */
adb_listOperationPhasesResponse_t* 
	axis2_skel_OperationAdmin_listOperationPhases(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_listOperationPhases_t* _listOperationPhases )
{
  /* TODO fill this with the necessary business logic */
  return (adb_listOperationPhasesResponse_t*)NULL;
}


		 
        /**
         * auto generated function definition signature
         * for "listControlOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listControlOperations of the adb_listControlOperations_t*
         *
         * @return adb_listControlOperationsResponse_t*
         */
adb_listControlOperationsResponse_t* 
	axis2_skel_OperationAdmin_listControlOperations(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_listControlOperations_t* _listControlOperations )
{
  /* TODO fill this with the necessary business logic */
  return (adb_listControlOperationsResponse_t*)NULL;
}
     

		 
        /**
         * auto generated function definition signature
         * for "getDeclaredOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getDeclaredOperationParameters of the adb_getDeclaredOperationParameters_t*
         *
         * @return adb_getDeclaredOperationParametersResponse_t*
         */
adb_getDeclaredOperationParametersResponse_t* 
	axis2_skel_OperationAdmin_getDeclaredOperationParameters(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_getDeclaredOperationParameters_t* _getDeclaredOperationParameters )
{
	axis2_char_t *operation_name = NULL;
	axis2_char_t *service_name = NULL;
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;
	int i =0, size = 0;
	axutil_array_list_t* params = NULL;
	adb_getDeclaredOperationParametersResponse_t *response = NULL;
	service_name = adb_getDeclaredOperationParameters_get_serviceName(_getDeclaredOperationParameters, env);
	operation_name = adb_getDeclaredOperationParameters_get_operationName(_getDeclaredOperationParameters, env);
	response = adb_getDeclaredOperationParametersResponse_create(env);
	if(!service_name && !operation_name)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service name or operation name null");
		return response;
	}
		
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	op = axis2_svc_get_op_with_name(svc, env, operation_name);
	
	params = axis2_op_get_all_params(op, env);	
	size = axutil_array_list_size(params, env);
	for(i = 0; i<size; i++)
	{
		axiom_node_t *param_node = NULL;
		axutil_param_t *param = NULL;
		param = axutil_array_list_get(params, env, i );
		if(param)
		{
			param_node = service_admin_util_serialize_param(env, param);

			if(param_node)
			{
				axis2_char_t *param_str = NULL;
				param_str = axiom_node_to_string(param_node, env);
				if(param_str)
				{
					adb_getDeclaredOperationParametersResponse_add_return(response, env, param_str);
				}			
			}
		}
	}
	return response;
}


		 
        /**
         * auto generated function definition signature
         * for "listAllOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listAllOperations of the adb_listAllOperations_t*
         *
         * @return adb_listAllOperationsResponse_t*
         */
        adb_listAllOperationsResponse_t* 
			axis2_skel_OperationAdmin_listAllOperations(
			const axutil_env_t *env , 
			axis2_msg_ctx_t *msg_ctx,
            adb_listAllOperations_t* _listAllOperations )
        {
            adb_OperationMetaDataWrapper_t *op_metadata_wrapper = NULL;
            axis2_char_t *service_name = NULL;
			axis2_svc_t *svc = NULL;
			adb_listAllOperationsResponse_t *response = NULL;
			axutil_hash_t *op_map = NULL;
			axutil_hash_index_t *index = NULL;
			
			service_name = adb_listAllOperations_get_serviceName(_listAllOperations, env);
			if(!service_name)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service not found");
				return NULL;
			}
			
			svc = service_admin_util_get_service(env, msg_ctx, service_name);
			
            if(svc)
            {
				response = adb_listAllOperationsResponse_create(env);
				op_metadata_wrapper = adb_OperationMetaDataWrapper_create(env);
				op_map = axis2_svc_get_all_ops(svc, env);
                for (index = axutil_hash_first(op_map, env); index; index = axutil_hash_next(env, index))
                {
                    void *v = NULL;
                    axis2_op_t *op = NULL;
                    axis2_char_t *op_name = NULL;
					adb_OperationMetaData_t *op_metadata = NULL;
                    axutil_hash_this(index, NULL, NULL, &v);
                    op = (axis2_op_t *) v;
                    op_name = axutil_qname_get_localpart(axis2_op_get_qname(op, env), env);
			        
					op_metadata = adb_OperationMetaData_create(env);
					adb_OperationMetaData_set_name(op_metadata, env,op_name);
					/** TODO Get it from a param */
					adb_OperationMetaData_set_enableMTOM(op_metadata, env, AXIS2_FALSE);
					adb_OperationMetaDataWrapper_add_publishedOperations(op_metadata_wrapper, env, op_metadata);
                }
				adb_listAllOperationsResponse_set_return(response, env, op_metadata_wrapper);
				return response;
			}
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,"Service  not available");
			return NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "configureMTOM|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _configureMTOM of the adb_configureMTOM_t*
         *
         * @return 
         */
axis2_status_t  
axis2_skel_OperationAdmin_configureMTOM(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_configureMTOM_t* _configureMTOM )
{
	axis2_char_t *operation_name = NULL, *service_name = NULL, *flag = NULL;
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;

	operation_name = adb_configureMTOM_get_operationName(_configureMTOM, env);
	service_name = adb_configureMTOM_get_serviceName(_configureMTOM, env);
	flag = adb_configureMTOM_get_flag(_configureMTOM, env);
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		return AXIS2_FAILURE;
	}
	op = axis2_svc_get_op_with_name(svc, env, operation_name);
	if(!op)
	{
		return AXIS2_FAILURE;
	}
	if(flag)
	{
		axutil_param_t *param = axutil_param_create(env, AXIS2_ENABLE_MTOM, flag);
		axis2_op_add_param(op, env, param);
		return AXIS2_SUCCESS;
	}
	return AXIS2_FAILURE;
}
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationMetaData|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationMetaData of the adb_getOperationMetaData_t*
         *
         * @return adb_getOperationMetaDataResponse_t*
         */
        adb_getOperationMetaDataResponse_t* axis2_skel_OperationAdmin_getOperationMetaData(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationMetaData_t* _getOperationMetaData )
        {
            axis2_char_t *svc_name = NULL;
            axis2_char_t *op_name = NULL;
            adb_OperationMetaData_t * op_metadata = NULL;
            adb_getOperationMetaDataResponse_t * get_op_metadata_res = NULL;

            if(!_getOperationMetaData)
            {
                return NULL;
            }
            svc_name = adb_getOperationMetaData_get_serviceName(_getOperationMetaData, env);
            op_name = adb_getOperationMetaData_get_operationName(_getOperationMetaData, env);
			
			

            op_metadata = adb_OperationMetaData_create(env);
            adb_OperationMetaData_set_name(op_metadata, env, op_name);
			adb_OperationMetaData_set_controlOperation(op_metadata, env, AXIS2_FALSE);
            adb_OperationMetaData_set_enableMTOM(op_metadata, env, "false");
            get_op_metadata_res = adb_getOperationMetaDataResponse_create_with_values (env, op_metadata); 
            return  get_op_metadata_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationParameters of the adb_getOperationParameters_t*
         *
         * @return adb_getOperationParametersResponse_t*
         */
 adb_getOperationParametersResponse_t* 
	 axis2_skel_OperationAdmin_getOperationParameters(
	 const axutil_env_t *env , 
	 axis2_msg_ctx_t *msg_ctx,
     adb_getOperationParameters_t* _getOperationParameters )
{
          return (adb_getOperationParametersResponse_t*) NULL;
}
     

		 
/**
 * auto generated function definition signature
 * for "removeOperationParameter|http://mgt.operation.carbon.wso2.org" operation.
 * @param env environment ( mandatory)* @param MessageContext the outmessage context
 * @param _removeOperationParameter of the adb_removeOperationParameter_t*
 *
 * @return 
 */
axis2_status_t  
axis2_skel_OperationAdmin_removeOperationParameter(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_removeOperationParameter_t* _removeOperationParameter )
{
	axis2_char_t *service_name = NULL;
	axis2_char_t *op_name = NULL;
	axis2_char_t *param_name = NULL;
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;

	service_name = adb_removeOperationParameter_get_serviceName(_removeOperationParameter, env);
	op_name = adb_removeOperationParameter_get_operationName(_removeOperationParameter, env);
	param_name = adb_removeOperationParameter_get_parameterName(_removeOperationParameter, env);
	
	svc = service_admin_util_get_service(env, msg_ctx, service_name);

	if(!svc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "service not found");
		return AXIS2_FAILURE;
	}

	op = axis2_svc_get_op_with_name(svc, env, op_name);
	if(op)
	{
		return axis2_op_remove_param(op, env, param_name);
	}

	return AXIS2_FAILURE;
}
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationStatistics|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationStatistics of the adb_getOperationStatistics_t*
         *
         * @return adb_getOperationStatisticsResponse_t*
         */
        adb_getOperationStatisticsResponse_t* axis2_skel_OperationAdmin_getOperationStatistics(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationStatistics_t* _getOperationStatistics )
        {
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            adb_getOperationStatisticsResponse_t* get_op_stat_res = NULL;
            axutil_array_list_t *op_list = NULL;

            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            svc_name = adb_getOperationStatistics_get_serviceName(_getOperationStatistics, env);
            svc = axis2_conf_get_svc(conf, env, svc_name);
            if(svc)
            {
                axis2_char_t *op_name = NULL;
                adb_getOperationMetaData_t *get_op_meta_data = NULL;
                adb_getOperationMetaDataResponse_t *get_op_meta_data_res = NULL;
                adb_OperationMetaData_t *op_meta_data = NULL;

                op_list = axutil_array_list_create(env, 0);
                op_name = adb_getOperationStatistics_get_operationName(_getOperationStatistics, env);
                get_op_meta_data = adb_getOperationMetaData_create_with_values(env, svc_name, op_name);
                if(get_op_meta_data)
                {
                    get_op_meta_data_res = axis2_skel_OperationAdmin_getOperationMetaData(env, msg_ctx, get_op_meta_data); 
                    if(get_op_meta_data_res)
                    {
                        op_meta_data = adb_getOperationMetaDataResponse_get_return(get_op_meta_data_res, env);
                        adb_getOperationMetaDataResponse_free(get_op_meta_data_res, env);
                    }
                    adb_getOperationMetaData_free(get_op_meta_data, env);
                    get_op_stat_res = adb_getOperationStatisticsResponse_create_with_values(env, op_meta_data);
                }
            }

            return (adb_getOperationStatisticsResponse_t*) get_op_stat_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getPolicy|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getPolicy of the adb_getPolicy_t*
         *
         * @return adb_getPolicyResponse_t*
         */
adb_getPolicyResponse_t* 
axis2_skel_OperationAdmin_getPolicy(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getPolicy_t* _getPolicy )
{
          /* TODO fill this with the necessary business logic */
          return (adb_getPolicyResponse_t*)NULL;
}
     

		 
        /**
         * auto generated function definition signature
         * for "listPublishedOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listPublishedOperations of the adb_listPublishedOperations_t*
         *
         * @return adb_listPublishedOperationsResponse_t*
         */
        adb_listPublishedOperationsResponse_t* axis2_skel_OperationAdmin_listPublishedOperations(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_listPublishedOperations_t* _listPublishedOperations )
        {
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            axutil_hash_t *op_map = NULL;
            axutil_hash_index_t *index;
            int count = 0;
            adb_listPublishedOperationsResponse_t* published_op_list_res = NULL;
            axutil_array_list_t *op_list = NULL;

            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            svc_name = adb_listPublishedOperations_get_serviceName(_listPublishedOperations, env);
            svc = axis2_conf_get_svc(conf, env, svc_name);
            if(svc)
            {
                op_list = axutil_array_list_create(env, 0);
                op_map = axis2_svc_get_all_ops(svc, env);
                for (index = axutil_hash_first(op_map, env); index; index = axutil_hash_next(env, index))
                {
                    adb_getOperationMetaData_t *get_op_meta_data = NULL;
                    adb_getOperationMetaDataResponse_t *get_op_meta_data_res = NULL;
                    void *v = NULL;
                    axis2_op_t *op = NULL;
                    axis2_char_t *op_name = NULL;

                    axutil_hash_this(index, NULL, NULL, &v);
                    op = (axis2_op_t *) v;
                    op_name = axutil_qname_get_localpart(axis2_op_get_qname(op, env), env);
                    get_op_meta_data = adb_getOperationMetaData_create_with_values(env, svc_name, op_name);
                    if(get_op_meta_data)
                    {
                        get_op_meta_data_res = axis2_skel_OperationAdmin_getOperationMetaData(env, msg_ctx, get_op_meta_data);
                        if(get_op_meta_data_res)
                        {
                            axutil_array_list_add(op_list, env, adb_getOperationMetaDataResponse_get_return(get_op_meta_data_res, env));
                        }
                    }
                }
                published_op_list_res = adb_listPublishedOperationsResponse_create_with_values(env, op_list);
            }
            return (adb_listPublishedOperationsResponse_t*) published_op_list_res;
        }
     

		 
/**
 * auto generated function definition signature
 * for "setOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
 * @param env environment ( mandatory)* @param MessageContext the outmessage context
 * @param _setOperationParameters of the adb_setOperationParameters_t*
 *
 * @return 
 */
axis2_status_t  axis2_skel_OperationAdmin_setOperationParameters(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_setOperationParameters_t* _setOperationParameters )
{
	axis2_char_t *svc_name = NULL, *op_name = NULL;
	axutil_array_list_t *parameters = NULL;
	int i =0, size = 0;
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;
	svc_name = adb_setOperationParameters_get_serviceId(_setOperationParameters, env);
	op_name = adb_setOperationParameters_get_operationId(_setOperationParameters, env);
	parameters = adb_setOperationParameters_get_parameters(_setOperationParameters, env);
	
	svc = service_admin_util_get_service(env, msg_ctx, svc_name);
	if(!svc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service not found");
		return AXIS2_FAILURE;
	}
	op = axis2_svc_get_op_with_name(svc, env, op_name);
	if(!op)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation not found");
		return AXIS2_FAILURE;
	}
	

	size = axutil_array_list_size(parameters, env);
	for(i =0; i < size; i++)
	{
		axiom_node_t *node = NULL;
		axutil_param_t *param = NULL;
		axiom_element_t *element = NULL;
		axis2_char_t *name_val = NULL, *locked_val = NULL, *param_str = NULL;
		param_str = axutil_array_list_get(parameters, env, i);
	
		node = axiom_node_create_from_buffer(env, param_str);
		if(axiom_node_get_node_type(node,env) == AXIOM_ELEMENT)
		{
			element = (axiom_element_t*)axiom_node_get_data_element(node, env);
			if(!element)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "param axiom element null");
			}
			name_val = axiom_element_get_attribute_value_by_name(element, env, "name");
			locked_val = axiom_element_get_attribute_value_by_name(element, env, "locked");
			param_str = axiom_element_get_text(element, env, node);

			if(name_val)
			{
				param = axis2_op_get_param(op, env, name_val);
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
					axis2_op_add_param(op, env, param);
				}
			}
		}
	
	}
	return AXIS2_SUCCESS;
}
     

