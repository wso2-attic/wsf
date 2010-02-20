

    /**
     * axis2_skel_ModuleAdminService.c
     *
     * This file was auto-generated from WSDL for "ModuleAdminService|http://service.mgt.module.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_ModuleAdminService Axis2/C skeleton for the axisService
     */

#include "codegen/axis2_skel_ModuleAdminService.h"
#include "service_admin_util.h"
#include "service_admin_constants.h"
#include "axis2_module.h"
#include "axutil_version.h"
     

		 
        /**
         * auto generated function definition signature
         * for "engageModuleForService|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _engageModuleForService of the adb_engageModuleForService_t*
         *
         * @return adb_engageModuleForServiceResponse_t*
         */
adb_engageModuleForServiceResponse_t* 
axis2_skel_ModuleAdminService_engageModuleForService(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_engageModuleForService_t* _engageModuleForService,
    axis2_skel_ModuleAdminService_engageModuleForService_fault *fault )
{
	axis2_char_t *service_name = NULL;
	axis2_svc_t *svc  = NULL;
	axis2_char_t *module_name = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_module_desc_t *module_desc = NULL;
	axutil_qname_t *qname = NULL;
	adb_engageModuleForServiceResponse_t *response = NULL;

	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf  = axis2_conf_ctx_get_conf(conf_ctx, env);

	service_name = adb_engageModuleForService_get_serviceName(_engageModuleForService, env);
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	module_name = adb_engageModuleForService_get_moduleId(_engageModuleForService, env);
	qname = axutil_qname_create(env, module_name, NULL, NULL);

	module_desc = axis2_conf_get_module(conf, env, qname);
	
	axis2_svc_engage_module(svc, env, module_desc, conf);
	if(axutil_strcmp(module_name, "rahas") == 0)
	{
		axis2_module_desc_t *rampart = NULL;
		axutil_qname_t *mod_qname = axutil_qname_create(env, "rampart", NULL, NULL);
		rampart = axis2_conf_get_module(conf, env, mod_qname);
		axis2_svc_engage_module(svc, env, rampart, conf);
		axutil_qname_free(mod_qname, env);
	}

	axutil_qname_free(qname, env);
	
	response = adb_engageModuleForServiceResponse_create(env);
	
	adb_engageModuleForServiceResponse_set_return(response, env, AXIS2_TRUE);

  return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "disengageModuleFromSystem|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disengageModuleFromSystem of the adb_disengageModuleFromSystem_t*
         *
         * @return adb_disengageModuleFromSystemResponse_t*
         */
        adb_disengageModuleFromSystemResponse_t* axis2_skel_ModuleAdminService_disengageModuleFromSystem(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_disengageModuleFromSystem_t* _disengageModuleFromSystem,
                                          axis2_skel_ModuleAdminService_disengageModuleFromSystem_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_disengageModuleFromSystemResponse_t*)NULL;
        }
     

		 
/**
 * auto generated function definition signature
 * for "disengageModuleForService|http://service.mgt.module.carbon.wso2.org" operation.
 * @param env environment ( mandatory)* @param MessageContext the outmessage context
 * @param _disengageModuleForService of the adb_disengageModuleForService_t*
 *
 * @return adb_disengageModuleForServiceResponse_t*
 */
adb_disengageModuleForServiceResponse_t* 
	axis2_skel_ModuleAdminService_disengageModuleForService(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_disengageModuleForService_t* _disengageModuleForService,
    axis2_skel_ModuleAdminService_disengageModuleForService_fault *fault )
{
	axis2_char_t *service_name = NULL, *module_name = NULL;
	axis2_svc_t *svc = NULL;
	axis2_conf_t *conf = NULL;
	axis2_module_desc_t *desc = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axutil_qname_t *qname = NULL;
	adb_disengageModuleForServiceResponse_t *response = NULL;

	service_name = adb_disengageModuleForService_get_serviceName(_disengageModuleForService, env);
	module_name = adb_disengageModuleForService_get_moduleId(_disengageModuleForService, env);
	qname = axutil_qname_create(env, module_name, NULL, NULL);
	
	
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	
	desc = axis2_conf_get_module(conf, env, qname);

	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		/** TODO FIll the exceptions */
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service with name %s not found", service_name);
		fault->ModuleMgtException = adb_ModuleMgtExceptionE0_create(env);
		return NULL;
	}

	response  = adb_disengageModuleForServiceResponse_create(env);
	
	if(axis2_svc_is_module_engaged(svc, env, qname))
	{
		axis2_status_t status  = AXIS2_FAILURE;
		status = axis2_svc_disengage_module(svc, env, desc, conf); 
		adb_disengageModuleForServiceResponse_set_return(response, env, (status == AXIS2_SUCCESS) ? AXIS2_TRUE : AXIS2_FALSE);
	}
	else
	{
		adb_disengageModuleForServiceResponse_set_return(response, env, AXIS2_FALSE);
	}
	return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "setModuleParameters|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setModuleParameters of the adb_setModuleParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ModuleAdminService_setModuleParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_setModuleParameters_t* _setModuleParameters,
                                          axis2_skel_ModuleAdminService_setModuleParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "removeModule|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeModule of the adb_removeModule_t*
         *
         * @return adb_removeModuleResponse_t*
         */
        adb_removeModuleResponse_t* axis2_skel_ModuleAdminService_removeModule(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_removeModule_t* _removeModule,
                                          axis2_skel_ModuleAdminService_removeModule_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_removeModuleResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "removeModuleParameter|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeModuleParameter of the adb_removeModuleParameter_t*
         *
         * @return adb_removeModuleParameterResponse_t*
         */
        adb_removeModuleParameterResponse_t* axis2_skel_ModuleAdminService_removeModuleParameter(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_removeModuleParameter_t* _removeModuleParameter,
                                          axis2_skel_ModuleAdminService_removeModuleParameter_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_removeModuleParameterResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getModuleParameters|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getModuleParameters of the adb_getModuleParameters_t*
         *
         * @return adb_getModuleParametersResponse_t*
         */
adb_getModuleParametersResponse_t* 
axis2_skel_ModuleAdminService_getModuleParameters(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_getModuleParameters_t* _getModuleParameters,
    axis2_skel_ModuleAdminService_getModuleParameters_fault *fault )
{
	axis2_char_t *module_name = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_module_desc_t *module_desc = NULL;
	axutil_qname_t *module_qname = NULL;
	axutil_array_list_t *param_list = NULL;
	int size = 0, i = 0;
	adb_getModuleParametersResponse_t *response = NULL;

	module_name = adb_getModuleParameters_get_moduleName(_getModuleParameters, env);
	if(!module_name)
	{
		/** TODO Return fault */
		return NULL;
	}
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	module_qname = axutil_qname_create(env, module_name, NULL, NULL);
	
	module_desc = axis2_conf_get_module(conf, env, module_qname);

	param_list = axis2_module_desc_get_all_params(module_desc, env);
	if(!param_list)
	{
		return NULL;
	}
	response  = adb_getModuleParametersResponse_create(env);
	size = axutil_array_list_size(param_list, env);
	for(i = 0; i < size; i++)
	{
		axis2_char_t *param_str = NULL;
		axiom_node_t *param_node = NULL;
		axutil_param_t *param = NULL;

		param = axutil_array_list_get(param_list, env, i);
		if(param)
		{
			param_node = service_admin_util_serialize_param(env, param);
			if(param_node)
			{
				param_str = axiom_node_to_string(param_node, env);
				adb_getModuleParametersResponse_add_return(response, env, param_str);
			}
		}
	}
	return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "engageModuleForOperation|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _engageModuleForOperation of the adb_engageModuleForOperation_t*
         *
         * @return adb_engageModuleForOperationResponse_t*
         */
adb_engageModuleForOperationResponse_t* 
axis2_skel_ModuleAdminService_engageModuleForOperation(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_engageModuleForOperation_t* _engageModuleForOperation,
    axis2_skel_ModuleAdminService_engageModuleForOperation_fault *fault )
{
	axis2_op_t *op = NULL;
	axis2_svc_t *svc = NULL;
	axis2_char_t *operation_name = NULL, *module_id = NULL, *service_name = NULL;
	adb_engageModuleForOperationResponse_t *response = NULL; 
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;

	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);


	operation_name = adb_engageModuleForOperation_get_operationName(_engageModuleForOperation, env);
	service_name = adb_engageModuleForOperation_get_serviceName(_engageModuleForOperation, env);
	
	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		/** TODO handle error */
		return NULL;
	}
	module_id = adb_engageModuleForOperation_get_moduleId(_engageModuleForOperation, env);
	
	op = axis2_svc_get_op_with_name(svc, env, operation_name);
	if(!op)
	{
		/** TODO handle error */
		return NULL;
	}
	response = adb_engageModuleForOperationResponse_create(env);

	if(module_id)
	{
		axutil_qname_t *qname = axutil_qname_create(env, module_id, NULL , NULL);
		
		if(axis2_op_is_module_engaged(op, env, qname))
		{
			adb_engageModuleForOperationResponse_set_return(response, env, AXIS2_FALSE);
		}else
		{
			axis2_module_desc_t *module_desc = NULL;
			/** Engage this module to operation */
			module_desc = axis2_conf_get_module(conf, env, qname);
			if(!module_desc)
			{
				/** TODO handle error */
				return NULL;
			}
			axis2_op_engage_module(op, env, module_desc, conf);
			if(axutil_strcmp("rahas", module_id) == 0)
			{
				axutil_qname_t *rampart_qname = axutil_qname_create(env, "rampart", NULL, NULL);
				module_desc = axis2_conf_get_module(conf, env, rampart_qname);
				axis2_op_engage_module(op, env, module_desc, conf);
				axutil_qname_free(rampart_qname, env);
			
			}
			adb_engageModuleForOperationResponse_set_return(response, env, AXIS2_TRUE);
		}
		axutil_qname_free(qname,env);
	}

	return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "listGloballyEngagedModules|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_listGloballyEngagedModulesResponse_t*
         */
        adb_listGloballyEngagedModulesResponse_t* axis2_skel_ModuleAdminService_listGloballyEngagedModules(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_listGloballyEngagedModulesResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "globallyEngageModule|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _globallyEngageModule of the adb_globallyEngageModule_t*
         *
         * @return adb_globallyEngageModuleResponse_t*
         */
        adb_globallyEngageModuleResponse_t* axis2_skel_ModuleAdminService_globallyEngageModule(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_globallyEngageModule_t* _globallyEngageModule,
                                          axis2_skel_ModuleAdminService_globallyEngageModule_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_globallyEngageModuleResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "engageModuleForServiceGroup|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _engageModuleForServiceGroup of the adb_engageModuleForServiceGroup_t*
         *
         * @return adb_engageModuleForServiceGroupResponse_t*
         */
adb_engageModuleForServiceGroupResponse_t* 
	axis2_skel_ModuleAdminService_engageModuleForServiceGroup(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_engageModuleForServiceGroup_t* _engageModuleForServiceGroup,
    axis2_skel_ModuleAdminService_engageModuleForServiceGroup_fault *fault )
{
	adb_engageModuleForServiceGroupResponse_t *response = NULL;
	axis2_char_t *svc_grp_name = NULL;
	axis2_char_t *module_id = NULL;
	axis2_svc_grp_t *svc_grp = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axutil_qname_t *qname = NULL;
	axis2_status_t status = AXIS2_FAILURE;
		

	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	module_id = adb_engageModuleForServiceGroup_get_moduleID(_engageModuleForServiceGroup, env);
	svc_grp_name = adb_engageModuleForServiceGroup_get_serviceGroupName(_engageModuleForServiceGroup, env);
	svc_grp = service_admin_util_get_service_group(env, msg_ctx, svc_grp_name);
	if(!svc_grp)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service group with name %s not available", svc_grp_name);
		return NULL;
	}
	qname = axutil_qname_create(env, module_id, NULL, NULL);
	response = adb_engageModuleForServiceGroupResponse_create(env);
	
	status = axis2_svc_grp_engage_module(svc_grp, env, qname);
	if(status == AXIS2_SUCCESS)
	{
		if(axutil_strcmp(module_id,"rahas") == 0)
		{
				axutil_qname_t *rampartqname = axutil_qname_create(env, "rampart", NULL, NULL);
				if(axis2_svc_grp_engage_module(svc_grp, env, rampartqname) != AXIS2_SUCCESS);
					axutil_qname_free(rampartqname, env);
		}
			adb_engageModuleForServiceGroupResponse_set_return(response, env, AXIS2_TRUE);
	}else{
		adb_engageModuleForServiceGroupResponse_set_return(response, env, AXIS2_FALSE);
		axutil_qname_free(qname, env);
	}
		
	
	
    return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "uploadModule|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _uploadModule of the adb_uploadModule_t*
         *
         * @return adb_uploadModuleResponse_t*
         */
adb_uploadModuleResponse_t* 
axis2_skel_ModuleAdminService_uploadModule(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_uploadModule_t* _uploadModule )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_uploadModuleResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "listModulesForOperation|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listModulesForOperation of the adb_listModulesForOperation_t*
         *
         * @return adb_listModulesForOperationResponse_t*
         */
adb_listModulesForOperationResponse_t* 
axis2_skel_ModuleAdminService_listModulesForOperation(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_listModulesForOperation_t* _listModulesForOperation,
    axis2_skel_ModuleAdminService_listModulesForOperation_fault *fault )
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf  = NULL;
	axutil_hash_t *all_modules = NULL;
	axutil_hash_index_t *index = NULL;
	axis2_op_t *op = NULL;
	adb_listModulesForOperationResponse_t *response = NULL;

	axis2_char_t *operation_name = NULL, *service_name = NULL;
	axis2_svc_t *svc = NULL;

	operation_name = adb_listModulesForOperation_get_operationName(_listModulesForOperation, env);
	service_name   = adb_listModulesForOperation_get_serviceName(_listModulesForOperation, env);

	svc = service_admin_util_get_service(env, msg_ctx, service_name);
	if(!svc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service with service name %s not found ", service_name);
		/** TODO handle errors */
		return NULL;
	}
	op  = axis2_svc_get_op_with_name(svc, env, operation_name);
	if(!op)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "operation with op name %s not found ", operation_name);
		return NULL;
	}
	
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	response = adb_listModulesForOperationResponse_create(env);
	all_modules = axis2_conf_get_all_modules(conf, env);
	if(!all_modules)
	{
		/** Returning empty response */
		return	response;
	}
	for(index = axutil_hash_first(all_modules, env); index; index = axutil_hash_next(env, index))
	{
		adb_ModuleMetaData_t *meta_data = NULL;
		axis2_char_t *module_name = NULL, *mdescription = NULL;
		axis2_module_t *module = NULL;
		void *v = NULL;
		axis2_module_desc_t *module_desc = NULL;
		axutil_hash_this(index, &module_name, NULL, &v);
		module_desc = (axis2_module_desc_t *)v;
		
		if(module_desc)
		{
			axutil_qname_t *mod_qname = axis2_module_desc_get_qname(module_desc, env);
			meta_data = adb_ModuleMetaData_create(env);
			adb_ModuleMetaData_set_modulename(meta_data, env, module_name);
			adb_ModuleMetaData_set_description(meta_data, env, module_name);

			adb_ModuleMetaData_set_moduleVersion(meta_data, env, ADMIN_DEFAULT_MODULE_VERSION);
			adb_ModuleMetaData_set_moduleId(meta_data, env, module_name);
			adb_ModuleMetaData_set_engagedGlobalLevel(meta_data, env, axis2_conf_is_engaged(conf, env, mod_qname));
			adb_ModuleMetaData_set_engagedServiceLevel(meta_data, env, axis2_svc_is_module_engaged(svc, env, mod_qname));
			adb_ModuleMetaData_set_engagedOperationLevel(meta_data, env, axis2_op_is_module_engaged(op, env, mod_qname));
			adb_listModulesForOperationResponse_add_return(response, env, meta_data);
		}
	}
	return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "listModulesForService|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listModulesForService of the adb_listModulesForService_t*
         *
         * @return adb_listModulesForServiceResponse_t*
         */
adb_listModulesForServiceResponse_t* 
axis2_skel_ModuleAdminService_listModulesForService(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_listModulesForService_t* _listModulesForService,
	axis2_skel_ModuleAdminService_listModulesForService_fault *fault )
{

	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf  = NULL;
	axutil_hash_t *all_modules = NULL;
	axutil_hash_index_t *index = NULL;
	axis2_char_t *service_name = NULL;
	adb_listModulesForServiceResponse_t *response = NULL;
	axis2_svc_t *svc = NULL;
	axis2_svc_grp_t *svc_grp = NULL;



	service_name = adb_listModulesForService_get_serviceName(_listModulesForService, env);
	
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	svc = axis2_conf_get_svc(conf, env, service_name);

	if(svc)
		svc_grp = axis2_svc_get_parent(svc, env);
	response = adb_listModulesForServiceResponse_create(env);
	all_modules = axis2_conf_get_all_modules(conf, env);
	if(!all_modules)
	{
		/** Returning empty response */
		return	response;
	}
	for(index = axutil_hash_first(all_modules, env); index; index = axutil_hash_next(env, index))
	{
		adb_ModuleMetaData_t *meta_data = NULL;
		axis2_char_t *module_name = NULL, *mdescription = NULL;
		axis2_module_t *module = NULL;
		void *v = NULL;
		axis2_module_desc_t *module_desc = NULL;
		axutil_hash_this(index, &module_name, NULL, &v);
		module_desc = (axis2_module_desc_t *)v;
		
		if(module_desc)
		{
			axutil_qname_t *mod_qname = axis2_module_desc_get_qname(module_desc, env);
			meta_data = adb_ModuleMetaData_create(env);
			adb_ModuleMetaData_set_modulename(meta_data, env, module_name);
			adb_ModuleMetaData_set_description(meta_data, env, module_name);
			adb_ModuleMetaData_set_moduleVersion(meta_data, env, ADMIN_DEFAULT_MODULE_VERSION);
			adb_ModuleMetaData_set_moduleId(meta_data, env, module_name);
			adb_ModuleMetaData_set_engagedGlobalLevel(meta_data, env, axis2_conf_is_engaged(conf, env, mod_qname));
			adb_ModuleMetaData_set_engagedServiceLevel(meta_data, env, axis2_svc_is_module_engaged(svc, env, mod_qname));
			/** Fix hard coded values */
			adb_ModuleMetaData_set_engagedOperationLevel(meta_data, env, AXIS2_FALSE);
			if(svc_grp)
			{
				adb_ModuleMetaData_set_engagedServiceGroupLevel(meta_data,env, axis2_svc_grp_is_module_engaged(svc_grp, env, mod_qname));
			}
			else
			{	/** Default value set to false */
				adb_ModuleMetaData_set_engagedServiceGroupLevel(meta_data,env, AXIS2_FALSE);
			}

			adb_listModulesForServiceResponse_add_return(response, env, meta_data);
		}
	}
	return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "disengageModuleForServiceGroup|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disengageModuleForServiceGroup of the adb_disengageModuleForServiceGroup_t*
         *
         * @return adb_disengageModuleForServiceGroupResponse_t*
         */
adb_disengageModuleForServiceGroupResponse_t* 
	axis2_skel_ModuleAdminService_disengageModuleForServiceGroup(
		const axutil_env_t *env , 
		axis2_msg_ctx_t *msg_ctx,
        adb_disengageModuleForServiceGroup_t* _disengageModuleForServiceGroup,
        axis2_skel_ModuleAdminService_disengageModuleForServiceGroup_fault *fault )
{
	axis2_char_t *svc_grp_name = NULL, *module_id = NULL;
	axis2_svc_grp_t *svc_grp = NULL;
	axis2_conf_t *conf = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_module_desc_t *module_desc = NULL;
	axutil_qname_t *module_qname = NULL;
	axis2_status_t status = AXIS2_FAILURE;
	adb_disengageModuleForServiceGroupResponse_t* response  = NULL;

	svc_grp_name = adb_disengageModuleForServiceGroup_get_serviceGroupName(_disengageModuleForServiceGroup, env);
	module_id = adb_disengageModuleForServiceGroup_get_moduleId(_disengageModuleForServiceGroup, env);

	svc_grp = service_admin_util_get_service_group(env, msg_ctx, svc_grp_name);
	if(!svc_grp)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "%s service group not found");
		return NULL;
	}
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	
	module_qname = axutil_qname_create(env, module_id, NULL, NULL);

	module_desc = axis2_conf_get_module(conf, env, module_qname);
	if(!module_desc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "%s module does not exist", module_id);
		return NULL;
	}
	
	status = axis2_svc_grp_disengage_module(svc_grp, env, module_desc, conf);
	response = adb_disengageModuleForServiceGroupResponse_create(env);

	if(status == AXIS2_SUCCESS)
		adb_disengageModuleForServiceGroupResponse_set_return(response, env, AXIS2_TRUE);
	else
		adb_disengageModuleForServiceGroupResponse_set_return(response, env, AXIS2_FALSE);
	
	return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "globallyDisengageModule|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _globallyDisengageModule of the adb_globallyDisengageModule_t*
         *
         * @return adb_globallyDisengageModuleResponse_t*
         */
adb_globallyDisengageModuleResponse_t* 
axis2_skel_ModuleAdminService_globallyDisengageModule(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_globallyDisengageModule_t* _globallyDisengageModule,
    axis2_skel_ModuleAdminService_globallyDisengageModule_fault *fault )
{
          /* TODO fill this with the necessary business logic */
          return (adb_globallyDisengageModuleResponse_t*)NULL;
}
     

		 
/**
 * auto generated function definition signature
 * for "listModules|http://service.mgt.module.carbon.wso2.org" operation.
 * @param env environment ( mandatory)* @param MessageContext the outmessage context
 *
 * @return adb_listModulesResponse_t*
 */
adb_listModulesResponse_t* 
axis2_skel_ModuleAdminService_listModules(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx )
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf  = NULL;
	axutil_hash_t *all_modules = NULL;
	axutil_hash_index_t *index = NULL;
	

	adb_listModulesResponse_t *response = NULL;
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	response = adb_listModulesResponse_create(env);
	all_modules = axis2_conf_get_all_modules(conf, env);
	if(!all_modules)
	{
		/** Returning empty response */
		return	response;
	}
	for(index = axutil_hash_first(all_modules, env); index; index = axutil_hash_next(env, index))
	{
		adb_ModuleMetaData_t *meta_data = NULL;
		axis2_char_t *module_name = NULL, *mdescription = NULL;
		axis2_module_t *module = NULL;
		void *v = NULL;
		axis2_module_desc_t *module_desc = NULL;
		axutil_hash_this(index, &module_name, NULL, &v);
		module_desc = (axis2_module_desc_t *)v;
		
		if(module_desc)
		{
			axutil_qname_t *mod_qname = axis2_module_desc_get_qname(module_desc, env);
			meta_data = adb_ModuleMetaData_create(env);
			adb_ModuleMetaData_set_modulename(meta_data, env, module_name);
			adb_ModuleMetaData_set_description(meta_data, env, module_name);
			/*axis2_conf_get_default_module_version(conf, env, module_name) */
			adb_ModuleMetaData_set_moduleVersion(meta_data, env, ADMIN_DEFAULT_MODULE_VERSION);
			adb_ModuleMetaData_set_moduleId(meta_data, env, module_name);
			adb_ModuleMetaData_set_engagedGlobalLevel(meta_data, env, axis2_conf_is_engaged(conf, env, mod_qname));
			
			adb_listModulesResponse_add_return(response, env, meta_data);
		}
	}
	return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "listModulesForServiceGroup|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listModulesForServiceGroup of the adb_listModulesForServiceGroup_t*
         *
         * @return adb_listModulesForServiceGroupResponse_t*
         */
adb_listModulesForServiceGroupResponse_t* 
	axis2_skel_ModuleAdminService_listModulesForServiceGroup(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_listModulesForServiceGroup_t* _listModulesForServiceGroup,
    axis2_skel_ModuleAdminService_listModulesForServiceGroup_fault *fault )
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf  = NULL;
	axutil_hash_t *all_modules = NULL;
	axutil_hash_index_t *index = NULL;
	axis2_char_t *service_grp_name = NULL;
	adb_listModulesForServiceGroupResponse_t *response = NULL;
	axis2_svc_t *svc = NULL;
	axis2_svc_grp_t *svc_grp = NULL;


	service_grp_name = adb_listModulesForServiceGroup_get_serviceGroupName(_listModulesForServiceGroup, env);
	svc_grp = service_admin_util_get_service_group(env, msg_ctx ,service_grp_name);

	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	
	response = adb_listModulesForServiceGroupResponse_create(env);
	all_modules = axis2_conf_get_all_modules(conf, env);
	if(!all_modules)
	{
			return	response;
	}
	for(index = axutil_hash_first(all_modules, env); index; index = axutil_hash_next(env, index))
	{
		adb_ModuleMetaData_t *meta_data = NULL;
		axis2_char_t *module_name = NULL, *mdescription = NULL;
		axis2_module_t *module = NULL;
		void *v = NULL;
		axis2_module_desc_t *module_desc = NULL;
		axutil_hash_this(index, &module_name, NULL, &v);
		module_desc = (axis2_module_desc_t *)v;
		
	if(module_desc)
		{
			axutil_qname_t *mod_qname = axis2_module_desc_get_qname(module_desc, env);
			meta_data = adb_ModuleMetaData_create(env);
			adb_ModuleMetaData_set_modulename(meta_data, env, module_name);
			adb_ModuleMetaData_set_description(meta_data, env, module_name);
			adb_ModuleMetaData_set_moduleVersion(meta_data, env, ADMIN_DEFAULT_MODULE_VERSION);
			adb_ModuleMetaData_set_moduleId(meta_data, env, module_name);
			adb_ModuleMetaData_set_engagedGlobalLevel(meta_data, env, axis2_conf_is_engaged(conf, env, mod_qname));
			adb_ModuleMetaData_set_engagedServiceLevel(meta_data,env, AXIS2_FALSE);
			adb_ModuleMetaData_set_engagedOperationLevel(meta_data, env, AXIS2_FALSE);
			if(svc_grp)
			{
				adb_ModuleMetaData_set_engagedServiceGroupLevel(meta_data,env, axis2_svc_grp_is_module_engaged(svc_grp, env, mod_qname));
			}
			else
				adb_ModuleMetaData_set_engagedServiceGroupLevel(meta_data,env, AXIS2_FALSE);
			}

			adb_listModulesForServiceGroupResponse_add_return(response, env, meta_data);
		}
	return response;
}
     

		 
        /**
         * auto generated function definition signature
         * for "disengageModuleForOperation|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disengageModuleForOperation of the adb_disengageModuleForOperation_t*
         *
         * @return adb_disengageModuleForOperationResponse_t*
         */
adb_disengageModuleForOperationResponse_t* 
axis2_skel_ModuleAdminService_disengageModuleForOperation(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	adb_disengageModuleForOperation_t* _disengageModuleForOperation,
	axis2_skel_ModuleAdminService_disengageModuleForOperation_fault *fault )
{
	axis2_svc_t *svc = NULL;
	axis2_op_t *op =NULL;
	axis2_char_t *op_name = NULL, *svc_name = NULL, *module_id = NULL;
	adb_disengageModuleForOperationResponse_t *response = NULL;
	axis2_module_desc_t *module_desc = NULL;
	axutil_qname_t *mod_qname = NULL;
	axis2_conf_t *conf = NULL;
	axis2_conf_ctx_t *conf_ctx =  NULL;

	op_name = adb_disengageModuleForOperation_get_operationName(_disengageModuleForOperation, env);
	svc_name = adb_disengageModuleForOperation_get_serviceName(_disengageModuleForOperation, env);
	module_id = adb_disengageModuleForOperation_get_moduleId(_disengageModuleForOperation,env);
	response = adb_disengageModuleForOperationResponse_create(env);
	svc = service_admin_util_get_service(env, msg_ctx, svc_name);
	if(!svc)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Service with name %s not found", svc_name);
		return NULL;
	}

	op = axis2_svc_get_op_with_name(svc, env, op_name);
	if(!op)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Operation with name %s not found", op_name);
		return NULL;
	}
	
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);

	conf = axis2_conf_ctx_get_conf(conf_ctx, env);

	mod_qname = axutil_qname_create(env, module_id, NULL, NULL);
	
	if(axis2_op_is_module_engaged(op, env, mod_qname))
	{
		module_desc = axis2_conf_get_module(conf, env, mod_qname);
		if(!module_desc)
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "module description not found");
			return NULL;
		}
		axis2_op_disengage_module(op, env, module_desc, conf);
		adb_disengageModuleForOperationResponse_set_return(response, env, AXIS2_TRUE);
	}
	adb_disengageModuleForOperationResponse_set_return(response, env, AXIS2_FALSE);

	return response;
}


		 
/**
 * auto generated function definition signature
 * for "getModuleInfo|http://service.mgt.module.carbon.wso2.org" operation.
 * @param env environment ( mandatory)* @param MessageContext the outmessage context
 * @param _getModuleInfo of the adb_getModuleInfo_t*
 *
 * @return adb_getModuleInfoResponse_t*
 */
adb_getModuleInfoResponse_t* 
axis2_skel_ModuleAdminService_getModuleInfo(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
    adb_getModuleInfo_t* _getModuleInfo,
    axis2_skel_ModuleAdminService_getModuleInfo_fault *fault )
{
	axis2_char_t *module_name = NULL, *module_version = NULL;
	adb_getModuleInfoResponse_t *response = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	module_name = adb_getModuleInfo_get_moduleName(_getModuleInfo, env);
	module_version = adb_getModuleInfo_get_moduleVersion(_getModuleInfo, env);
	
	if(module_name)
	{
		conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
		if(conf_ctx)
		{
			adb_ModuleMetaData_t *meta_data = NULL;
			axutil_qname_t *mod_qname = NULL;
			axis2_module_desc_t *mod_desc = NULL;
			conf  = axis2_conf_ctx_get_conf(conf_ctx, env);
			mod_qname = axutil_qname_create(env, module_name, NULL, NULL);
			mod_desc = axis2_conf_get_module(conf, env, mod_qname);
			if(mod_desc)
			{
				meta_data = adb_ModuleMetaData_create(env);
				adb_ModuleMetaData_set_modulename(meta_data, env, module_name);
				adb_ModuleMetaData_set_engagedGlobalLevel(meta_data, env, axis2_conf_is_engaged(conf, env, mod_qname));
				adb_ModuleMetaData_set_description(meta_data, env, module_name);
				adb_ModuleMetaData_set_moduleId(meta_data, env, module_name);
				adb_ModuleMetaData_set_moduleVersion(meta_data,env, module_version);
				response = adb_getModuleInfoResponse_create(env);
				adb_getModuleInfoResponse_set_return(response, env, meta_data);
				return response;
			}
		}
	}
	/** TODO return proper exception */
	return NULL;
}
     

