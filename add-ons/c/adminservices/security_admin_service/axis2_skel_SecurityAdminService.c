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
     * axis2_skel_SecurityAdminService.c
     *
     * This file was auto-generated from WSDL for "SecurityAdminService|http://service.config.security.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_SecurityAdminService Axis2/C skeleton for the axisService
     */

     #include "codegen/axis2_skel_SecurityAdminService.h"
	 #include <neethi_engine.h>
	 #include <axis2_policy_include.h>
     #include <rampart_context.h>
	 #include <neethi_util.h>
	 #include "../include/security_admin_util.h"

		axutil_array_list_t* scenarios = NULL;
		 
        /**
         * auto generated function definition signature
         * for "getScenarios|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getScenarios of the adb_getScenarios_t*
         *
         * @return adb_getScenariosResponse_t*
         */
        adb_getScenariosResponse_t* axis2_skel_SecurityAdminService_getScenarios(const axutil_env_t *env , 
													axis2_msg_ctx_t *msg_ctx,
													adb_getScenarios_t* _getScenarios,
													axis2_skel_SecurityAdminService_getScenarios_fault *fault )
        {
			adb_getScenariosResponse_t* response = NULL;
			adb_SecurityScenarioDataWrapper_t* security_scenario_data_wrapper = NULL;
			int scenario_count = 0;
			int scenario_index = 0;

			/* Load scenarios if not loaded already*/
			if (!scenarios)
			{
				scenarios = security_admin_load_scenarios(env, msg_ctx);
				if (!scenarios) return NULL;
			}

			security_scenario_data_wrapper = adb_SecurityScenarioDataWrapper_create(env);

			/* Iterate through the hash and add scenarios into the data wrapper*/
			scenario_count = axutil_array_list_size(scenarios, env);
			for (scenario_index = 0; scenario_index < scenario_count; ++scenario_index)
			{
				security_admin_scenario_data_t* array_data = NULL;
				adb_SecurityScenarioData_t* data = NULL;

				/* Get current data element*/
				array_data = (security_admin_scenario_data_t*)
					axutil_array_list_get(scenarios, env, scenario_index);

				/* Create response data element*/
				data = adb_SecurityScenarioData_create(env);

				/* Current scenario*/
				adb_SecurityScenarioData_set_currentScenario(data, env, AXIS2_TRUE);
				
				/* id*/
				adb_SecurityScenarioData_set_scenarioId(data, env, 
					(const axis2_char_t*)axutil_strdup(env, 
					security_admin_scenario_data_get_id(array_data)));

				/* Summary*/
				adb_SecurityScenarioData_set_summary(data, env,
					(const axis2_char_t*)axutil_strdup(env,
					security_admin_scenario_data_get_summary(array_data)));

				/* Description*/
				adb_SecurityScenarioData_set_description(data, env,
					(const axis2_char_t*)axutil_strdup(env,
					security_admin_scenario_data_get_description(array_data)));

				/* Category*/
				adb_SecurityScenarioData_set_category(data, env,
					(const axis2_char_t*)axutil_strdup(env,
					security_admin_scenario_data_get_category(array_data)));

				/* Type*/
				adb_SecurityScenarioData_set_type(data, env,
					(const axis2_char_t*)axutil_strdup(env,
					security_admin_scenario_data_get_type(array_data)));

				adb_SecurityScenarioDataWrapper_add_scenarios(
					security_scenario_data_wrapper, env, data);
			}

			/* Build response and return*/
			response = adb_getScenariosResponse_create(env);
			adb_getScenariosResponse_set_return(response, env, security_scenario_data_wrapper);

			return response;
        }
    		 
        /**
         * auto generated function definition signature
         * for "applySecurity|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _applySecurity of the adb_applySecurity_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_SecurityAdminService_applySecurity(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_applySecurity_t* _applySecurity,
                                          axis2_skel_SecurityAdminService_applySecurity_fault *fault )
        {
			axis2_char_t* service_name = NULL;
			axis2_char_t* scenario_id = NULL;
			axis2_conf_ctx_t* conf_ctx = NULL;
			axis2_conf_t* conf = NULL;
			axis2_svc_t* svc = NULL;
			axis2_char_t* repo_path = NULL;
			axis2_char_t* policy_file_name = NULL;
			neethi_policy_t* neethi_policy = NULL;
			axis2_desc_t* desc = NULL;
			axis2_policy_include_t* policy_include = NULL;
			axutil_qname_t* module_qname = NULL;
			axis2_module_desc_t* module_desc = NULL;

			/* Get parameters */
			service_name = adb_applySecurity_get_serviceName(_applySecurity, env);
			scenario_id = adb_applySecurity_get_policyId(_applySecurity, env);

			/* Load neethi policy */
			conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
			repo_path = axis2_conf_ctx_get_root_dir(conf_ctx, env);
			policy_file_name = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services",
				AXIS2_PATH_SEP_STR, "SecurityAdminService", AXIS2_PATH_SEP_STR, "policies",
				AXIS2_PATH_SEP_STR, scenario_id, "-policy.xml", NULL);

			neethi_policy = neethi_util_create_policy_from_file(env, policy_file_name);
			AXIS2_FREE(env->allocator, policy_file_name);
			if (!neethi_policy) return AXIS2_FAILURE;
			
			/* Get service instance*/
			conf = axis2_conf_ctx_get_conf(conf_ctx, env);
			svc = axis2_conf_get_svc(conf, env, service_name);
			if (!svc) return AXIS2_FAILURE;

			desc = axis2_svc_get_base(svc, env);
			if (!desc) return AXIS2_FAILURE;

			policy_include = axis2_desc_get_policy_include(desc, env);
			if (!policy_include) return AXIS2_FAILURE;

			/* Attach policy*/
			axis2_policy_include_add_policy_element(policy_include, env, 
				AXIS2_SERVICE_POLICY, neethi_policy);

			/* Enagage modules*/
			module_qname = axutil_qname_create(env, "rampart", NULL, NULL);
			module_desc = axis2_conf_get_module(conf, env, module_qname);
			axutil_qname_free(module_qname, env);

			axis2_svc_disengage_module(svc, env, module_desc, conf);
			axis2_svc_engage_module(svc, env, module_desc, conf);

			return AXIS2_SUCCESS;
        }

		 
        /**
         * auto generated function definition signature
         * for "activateUsernameTokenAuthentication|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _activateUsernameTokenAuthentication of the adb_activateUsernameTokenAuthentication_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_SecurityAdminService_activateUsernameTokenAuthentication(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_activateUsernameTokenAuthentication_t* _activateUsernameTokenAuthentication,
                                          axis2_skel_SecurityAdminService_activateUsernameTokenAuthentication_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "disableSecurityOnService|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disableSecurityOnService of the adb_disableSecurityOnService_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_SecurityAdminService_disableSecurityOnService(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_disableSecurityOnService_t* _disableSecurityOnService,
                                          axis2_skel_SecurityAdminService_disableSecurityOnService_fault *fault )
        {
			axis2_char_t* service_name = NULL;
			axis2_conf_ctx_t* conf_ctx = NULL;
			axis2_conf_t* conf = NULL;
			axis2_svc_t* svc = NULL;
			neethi_policy_t* neethi_policy = NULL;
			axis2_char_t* policy_name = NULL;
			axis2_desc_t* desc = NULL;
			axis2_policy_include_t* policy_include = NULL;
			axutil_qname_t* module_qname = NULL;
			axis2_module_desc_t* module_desc = NULL;

			/* Get parameters*/
			service_name = adb_disableSecurityOnService_get_serviceName(
				_disableSecurityOnService, env);
			
			/* Get service instance*/
			conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
			conf = axis2_conf_ctx_get_conf(conf_ctx, env);
			svc = axis2_conf_get_svc(conf, env, service_name);
			if (!svc) return AXIS2_FAILURE;

			desc = axis2_svc_get_base(svc, env);
			if (!desc) return AXIS2_FAILURE;

			policy_include = axis2_desc_get_policy_include(desc, env);
			if (!policy_include) return AXIS2_FAILURE;

			/* Detach policy*/
			neethi_policy = axis2_policy_include_get_policy(policy_include, env);
			if (!neethi_policy) return AXIS2_FAILURE;

			policy_name = neethi_policy_get_name(neethi_policy, env);
			if (!policy_name)
				policy_name = neethi_policy_get_id(neethi_policy, env);
			axis2_policy_include_remove_policy_element(policy_include, env,
				policy_name);

			/* Disenagage modules*/
			module_qname = axutil_qname_create(env, "rampart", NULL, NULL);
			module_desc = axis2_conf_get_module(conf, env, module_qname);
			axutil_qname_free(module_qname, env);

			axis2_svc_disengage_module(svc, env, module_desc, conf);

			return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getSecurityConfigData|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getSecurityConfigData of the adb_getSecurityConfigData_t*
         *
         * @return adb_getSecurityConfigDataResponse_t*
         */
        adb_getSecurityConfigDataResponse_t* axis2_skel_SecurityAdminService_getSecurityConfigData(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getSecurityConfigData_t* _getSecurityConfigData,
                                          axis2_skel_SecurityAdminService_getSecurityConfigData_fault *fault )
        {
			adb_getSecurityConfigDataResponse_t* response = NULL;
			adb_SecurityConfigData_t* data = NULL;
			axutil_array_list_t* key_stores = NULL;
			axutil_array_list_t* user_groups = NULL;
	
			/* Create data */
			key_stores = axutil_array_list_create(env, 1);
			axutil_array_list_add(key_stores, env, axutil_string_get_buffer(
				axutil_string_create(env, "test"), env));

			user_groups = axutil_array_list_create(env, 1);
			axutil_array_list_add(user_groups, env, axutil_string_get_buffer(
				axutil_string_create(env, "admin"), env));
			axutil_array_list_add(user_groups, env, axutil_string_get_buffer(
				axutil_string_create(env, "everyone"), env));

			data = adb_SecurityConfigData_create(env);
			adb_SecurityConfigData_set_privateStore(data, env, "test");
			adb_SecurityConfigData_set_trustedKeyStores(data, env, key_stores);
			adb_SecurityConfigData_set_userGroups(data, env, user_groups);

			/* Create response */
			response = adb_getSecurityConfigDataResponse_create(env);
			adb_getSecurityConfigDataResponse_set_return(response, env, data);

			return response;
        }

		 
        /**
         * auto generated function definition signature
         * for "getSecurityScenario|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getSecurityScenario of the adb_getSecurityScenario_t*
         *
         * @return adb_getSecurityScenarioResponse_t*
         */
        adb_getSecurityScenarioResponse_t* axis2_skel_SecurityAdminService_getSecurityScenario(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getSecurityScenario_t* _getSecurityScenario,
                                          axis2_skel_SecurityAdminService_getSecurityScenario_fault *fault )
        {
			axis2_char_t* scenario_id = NULL;
			int scenario_count = 0;
			int scenario_index = 0;

			/* Load scenarios if not loaded already*/
			if (!scenarios)
			{
				scenarios = security_admin_load_scenarios(env, msg_ctx);
				if (!scenarios) return NULL;
			}

			/* Get required scenario id*/
			scenario_id = adb_getSecurityScenario_get_sceneId(_getSecurityScenario, env);

			/* Iterate through the hash and add scenarios into the data wrapper*/
			scenario_count = axutil_array_list_size(scenarios, env);
			for (scenario_index = 0; scenario_index < scenario_count; ++scenario_index)
			{
				security_admin_scenario_data_t* array_data = NULL;

				/* Get current data element*/
				array_data = (security_admin_scenario_data_t*)
					axutil_array_list_get(scenarios, env, scenario_index);

				if (0 == axutil_strcmp(security_admin_scenario_data_get_id(array_data), 
					scenario_id)) /* Required scenario found */
				{
					adb_SecurityScenarioData_t* data = NULL;
					adb_getSecurityScenarioResponse_t* response = NULL;

					/* Create response data element*/
					data = adb_SecurityScenarioData_create(env);

					/* Current scenario*/
					/*adb_SecurityScenarioData_set_currentScenario(data, env, AXIS2_TRUE);*/
					
					/* id*/
					adb_SecurityScenarioData_set_scenarioId(data, env, 
						(const axis2_char_t*)axutil_strdup(env, 
						security_admin_scenario_data_get_id(array_data)));

					/* Summary*/
					adb_SecurityScenarioData_set_summary(data, env,
						(const axis2_char_t*)axutil_strdup(env,
						security_admin_scenario_data_get_summary(array_data)));

					/* Description*/
					adb_SecurityScenarioData_set_description(data, env,
						(const axis2_char_t*)axutil_strdup(env,
						security_admin_scenario_data_get_description(array_data)));

					/* Category*/
					adb_SecurityScenarioData_set_category(data, env,
						(const axis2_char_t*)axutil_strdup(env,
						security_admin_scenario_data_get_category(array_data)));

					/* Type*/
					adb_SecurityScenarioData_set_type(data, env,
						(const axis2_char_t*)axutil_strdup(env,
						security_admin_scenario_data_get_type(array_data)));

					/* Create response*/
					response = adb_getSecurityScenarioResponse_create(env);
					adb_getSecurityScenarioResponse_set_return(response, env, data);

					return response;
				}
			}

			return NULL;
        }
     

