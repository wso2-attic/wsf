

    /**
     * axis2_skel_SecurityAdminService.c
     *
     * This file was auto-generated from WSDL for "SecurityAdminService|http://service.config.security.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_SecurityAdminService Axis2/C skeleton for the axisService
     */

     #include "codegen/axis2_skel_SecurityAdminService.h"   

		 
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
			// Read senarios from config file
			axis2_conf_ctx_t* conf_ctx = NULL;
			axis2_char_t* repo_path = NULL;
			axis2_char_t* scenario_config_file_path = NULL;
			axiom_xml_reader_t* xml_reader = NULL;
			axiom_document_t* document = NULL;
			axiom_stax_builder_t* stax_builder = NULL;
			axiom_node_t* scenario_config_root_node = NULL;
			axiom_element_t* scenario_config_root_element = NULL;
			axiom_children_iterator_t* children_ite = NULL;
			adb_SecurityScenarioData_t* data = NULL;
			adb_getScenariosResponse_t* response = NULL;
			adb_SecurityScenarioDataWrapper_t* security_scenario_data_wrapper = NULL;
			
			// Form absolute path to config file
			conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
			repo_path = axis2_conf_ctx_get_root_dir(conf_ctx, env);
			scenario_config_file_path = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
				AXIS2_PATH_SEP_STR, "SecurityAdminService", AXIS2_PATH_SEP_STR, "scenario-config.xml", 
				NULL);

			xml_reader = axiom_xml_reader_create_for_file(env, scenario_config_file_path, NULL);
			AXIS2_FREE(env->allocator, scenario_config_file_path);
			if (!xml_reader)
				return NULL;

			stax_builder = axiom_stax_builder_create(env, xml_reader);
			if (!stax_builder)
				return NULL;

			document = axiom_stax_builder_get_document(stax_builder, env);
			if (!document)
				return NULL;

			// Create data wrapper
			security_scenario_data_wrapper = adb_SecurityScenarioDataWrapper_create(env);

			// Build XML document
			axiom_document_build_all(document, env);

			scenario_config_root_node = axiom_document_get_root_element(document, env);
			scenario_config_root_element = axiom_node_get_data_element(scenario_config_root_node, env);
			axiom_stax_builder_free_self(stax_builder, env);
			
			children_ite = axiom_element_get_children(scenario_config_root_element, env, 
				scenario_config_root_node);
			if (children_ite)
			{
				// Get Scenario nodes and build response
				while (axiom_children_iterator_has_next(children_ite, env))
				{
					axiom_node_t* node = NULL;

					node = axiom_children_iterator_next(children_ite, env);

					if (axiom_node_get_node_type(node, env) == AXIOM_ELEMENT)
					{
						axis2_char_t* localname = NULL;
						axiom_element_t* scenario_ele = NULL;
						axiom_children_iterator_t* ite = NULL;
	
						scenario_ele = axiom_node_get_data_element(node, env);

						localname = axiom_element_get_localname(scenario_ele, env);

						if (0 == axutil_strcmp(localname, "Scenario")) // Scenario
						{
							adb_SecurityScenarioData_t* data = NULL;

							data = adb_SecurityScenarioData_create(env);

							// Current scenario
							//adb_SecurityScenarioData_set_currentScenario(data, env, AXIS2_TRUE);
							//adb_SecurityScenarioDataWrapper_set_currentScenario(security_scenario_data_wrapper, 
							//	env, data);

							// id
							adb_SecurityScenarioData_set_scenarioId(data, env, 
								axutil_strdup(env, 
								axiom_element_get_attribute_value_by_name(scenario_ele, env, "id")));

							ite = axiom_element_get_children(scenario_ele, env, node);
							while (axiom_children_iterator_has_next(ite, env))
							{
								axiom_node_t* node = NULL;
								node = axiom_children_iterator_next(ite, env);

								if (axiom_node_get_node_type(node, env) == AXIOM_ELEMENT)
								{
									axiom_element_t* node_ele = NULL;
									axis2_char_t* localname = NULL;
									axis2_char_t* text = NULL;

									node_ele = axiom_node_get_data_element(node, env);

									localname = axiom_element_get_localname(node_ele, env);
									text = axiom_element_get_text(node_ele, env, node);
									
									if (0 == axutil_strcmp(localname, "Summary")) // Summary
									{
										adb_SecurityScenarioData_set_summary(data, env,
											axutil_strdup(env, text));
									}
									else if (0 == axutil_strcmp(localname, "Description")) // Description
									{
										adb_SecurityScenarioData_set_description(data, env,
											axutil_strdup(env, text));
									}
									else if (0 == axutil_strcmp(localname, "Category")) // Category
									{
										adb_SecurityScenarioData_set_category(data, env,
											axutil_strdup(env, text));
									}
									/*else if (0 == axutil_strcmp(localname, "WsuId") // WsuId
									{
									}*/
									else if (0 == axutil_strcmp(localname, "Type")) // Type
									{
										adb_SecurityScenarioData_set_type(data, env,
											axutil_strdup(env, text));
									}
									else if (0 == axutil_strcmp(localname, "Modules")) // Modules
									{
										
									}
								}
							}

							adb_SecurityScenarioDataWrapper_add_scenarios(security_scenario_data_wrapper, 
								env, data);
						}
					}
				}
			}

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
          /* TODO fill this with the necessary business logic */
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
          /* TODO fill this with the necessary business logic */
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
	
			// Create data
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

			// Create response
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
			// Read senarios from config file
			axis2_conf_ctx_t* conf_ctx = NULL;
			axis2_char_t* repo_path = NULL;
			axis2_char_t* scenario_config_file_path = NULL;
			axiom_xml_reader_t* xml_reader = NULL;
			axiom_document_t* document = NULL;
			axiom_stax_builder_t* stax_builder = NULL;
			axiom_node_t* scenario_config_root_node = NULL;
			axiom_element_t* scenario_config_root_element = NULL;
			axiom_children_iterator_t* children_ite = NULL;
			adb_SecurityScenarioData_t* data = NULL;
			adb_getSecurityScenarioResponse_t* response = NULL;
			axis2_char_t* scenario_id = NULL;
			
			// Form absolute path to config file
			conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
			repo_path = axis2_conf_ctx_get_root_dir(conf_ctx, env);
			scenario_config_file_path = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
				AXIS2_PATH_SEP_STR, "SecurityAdminService", AXIS2_PATH_SEP_STR, "scenario-config.xml", 
				NULL);

			xml_reader = axiom_xml_reader_create_for_file(env, scenario_config_file_path, NULL);
			AXIS2_FREE(env->allocator, scenario_config_file_path);
			if (!xml_reader)
				return NULL;

			stax_builder = axiom_stax_builder_create(env, xml_reader);
			if (!stax_builder)
				return NULL;

			document = axiom_stax_builder_get_document(stax_builder, env);
			if (!document)
				return NULL;

			// Get required scenario id
			scenario_id = adb_getSecurityScenario_get_sceneId(_getSecurityScenario, env);

			// Build XML document
			axiom_document_build_all(document, env);

			scenario_config_root_node = axiom_document_get_root_element(document, env);
			scenario_config_root_element = axiom_node_get_data_element(scenario_config_root_node, env);
			axiom_stax_builder_free_self(stax_builder, env);
			
			children_ite = axiom_element_get_children(scenario_config_root_element, env, 
				scenario_config_root_node);
			if (children_ite)
			{
				// Get Scenario nodes and build response
				while (axiom_children_iterator_has_next(children_ite, env))
				{
					axiom_node_t* node = NULL;

					node = axiom_children_iterator_next(children_ite, env);

					if (axiom_node_get_node_type(node, env) == AXIOM_ELEMENT)
					{
						axis2_char_t* localname = NULL;
						axiom_element_t* scenario_ele = NULL;
						axiom_children_iterator_t* ite = NULL;
	
						scenario_ele = axiom_node_get_data_element(node, env);

						localname = axiom_element_get_localname(scenario_ele, env);

						if (0 == axutil_strcmp(localname, "Scenario")) // Scenario
						{
							axis2_char_t* id = NULL;
							
							id = axiom_element_get_attribute_value_by_name(scenario_ele, env, "id");

							if (0 == axutil_strcmp(id, scenario_id)) // Required id found
							{
								// Create data
								data = adb_SecurityScenarioData_create(env);

								// id
								adb_SecurityScenarioData_set_scenarioId(data, env, axutil_strdup(env, id));

								ite = axiom_element_get_children(scenario_ele, env, node);
								while (axiom_children_iterator_has_next(ite, env))
								{
									axiom_node_t* node = NULL;
									node = axiom_children_iterator_next(ite, env);

									if (axiom_node_get_node_type(node, env) == AXIOM_ELEMENT)
									{
										axiom_element_t* node_ele = NULL;
										axis2_char_t* localname = NULL;
										axis2_char_t* text = NULL;

										node_ele = axiom_node_get_data_element(node, env);

										localname = axiom_element_get_localname(node_ele, env);
										text = axiom_element_get_text(node_ele, env, node);
										
										if (0 == axutil_strcmp(localname, "Summary")) // Summary
										{
											adb_SecurityScenarioData_set_summary(data, env,
												axutil_strdup(env, text));
										}
										else if (0 == axutil_strcmp(localname, "Description")) // Description
										{
											adb_SecurityScenarioData_set_description(data, env,
												axutil_strdup(env, text));
										}
										else if (0 == axutil_strcmp(localname, "Category")) // Category
										{
											adb_SecurityScenarioData_set_category(data, env,
												axutil_strdup(env, text));
										}
										/*else if (0 == axutil_strcmp(localname, "WsuId") // WsuId
										{
										}*/
										else if (0 == axutil_strcmp(localname, "Type")) // Type
										{
											adb_SecurityScenarioData_set_type(data, env,
												axutil_strdup(env, text));
										}
										else if (0 == axutil_strcmp(localname, "Modules")) // Modules
										{
											
										}
									}
								}
							}
						}
					}
				}
			}

			// Create response
			response = adb_getSecurityScenarioResponse_create(env);
			adb_getSecurityScenarioResponse_set_return(response, env, data);

			return response;
        }
     

