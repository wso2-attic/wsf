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
#include "security_admin_util.h"
#include "axutil_dll_desc.h"
#include "axiom.h"

#define SEC_ADMIN_SCENARIO_COUNT 15

struct security_admin_scenario_data
{
	axis2_char_t* id;
	axis2_char_t* summary;
	axis2_char_t* description;
	axis2_char_t* category;
	axis2_char_t* type;
	axis2_bool_t current_scenario;
};

AXIS2_EXTERN security_admin_scenario_data_t* 
AXIS2_CALL security_admin_scenario_data_create(
	const axutil_env_t* env)
{
	security_admin_scenario_data_t* data = NULL;

	data = (security_admin_scenario_data_t*)
		AXIS2_MALLOC(env->allocator, sizeof(
		security_admin_scenario_data_t));

	if (!data)
	{
		AXIS2_ERROR_SET(env->error, 
			AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}

	data->id = NULL;
	data->summary = NULL;
	data->description = NULL;
	data->category = NULL;
	data->type = NULL;
	data->current_scenario = AXIS2_FALSE;

	return data;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_id(
	const security_admin_scenario_data_t* data)
{
	return data->id;
}

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_id(
	security_admin_scenario_data_t* data,
	axis2_char_t* id)
{
	data->id = id;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_summary(
	const security_admin_scenario_data_t* data)
{
	return data->summary;
}

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_summary(
	security_admin_scenario_data_t* data,
	axis2_char_t* summary)
{
	data->summary = summary;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_description(
	const security_admin_scenario_data_t* data)
{
	return data->description;
}

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_description(
	security_admin_scenario_data_t* data,
	axis2_char_t* description)
{
	data->description = description;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_category(
	const security_admin_scenario_data_t* data)
{
	return data->category;
}

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_category(
	security_admin_scenario_data_t* data,
	axis2_char_t* category)
{
	data->category = category;
}

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_type(
	const security_admin_scenario_data_t* data)
{
	return data->type;
}

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_type(
	security_admin_scenario_data_t* data,
	axis2_char_t* type)
{
	data->type = type;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
security_admin_scenario_data_get_current_scenario(
	const security_admin_scenario_data_t* data)
{
	return data->current_scenario;
}

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_current_scenario(
	security_admin_scenario_data_t* data,
	axis2_bool_t current_scenario)
{
	data->current_scenario = current_scenario;
}

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_free(
	  const axutil_env_t* env,
	  security_admin_scenario_data_t* data)
{
	if (data)
	{
		if (data->id)
			AXIS2_FREE(env->allocator, data->id);
		if (data->summary)
			AXIS2_FREE(env->allocator, data->summary);
		if (data->description)
			AXIS2_FREE(env->allocator, data->description);
		if (data->category)
			AXIS2_FREE(env->allocator, data->category);
		if (data->type)
			AXIS2_FREE(env->allocator, data->type);
	}
}

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
security_admin_load_scenarios(
		const axutil_env_t* env, 
		axis2_msg_ctx_t* msg_ctx)
{
	/* Read senarios from config file*/
	axis2_conf_ctx_t* conf_ctx = NULL;
	axis2_char_t* repo_path = NULL;
	axis2_char_t* scenario_config_file_path = NULL;
	axiom_xml_reader_t* xml_reader = NULL;
	axiom_document_t* document = NULL;
	axiom_stax_builder_t* stax_builder = NULL;
	axiom_node_t* scenario_config_root_node = NULL;
	axiom_element_t* scenario_config_root_element = NULL;
	axiom_children_iterator_t* children_ite = NULL;
	axutil_array_list_t* scenarios = NULL;
			
	/* Form absolute path to config file*/
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	repo_path = axis2_conf_ctx_get_root_dir(conf_ctx, env);
	scenario_config_file_path = axutil_strcat(env, repo_path, AXIS2_PATH_SEP_STR, "services", 
		AXIS2_PATH_SEP_STR, "SecurityAdminService", AXIS2_PATH_SEP_STR, "scenario-config.xml", 
		NULL);

	xml_reader = axiom_xml_reader_create_for_file(env, scenario_config_file_path, NULL);
	AXIS2_FREE(env->allocator, scenario_config_file_path);
	if (!xml_reader) return NULL;

	stax_builder = axiom_stax_builder_create(env, xml_reader);
	if (!stax_builder) return NULL;

	document = axiom_stax_builder_get_document(stax_builder, env);
	if (!document) return NULL;

	/* Build XML document*/
	axiom_document_build_all(document, env);

	scenario_config_root_node = axiom_document_get_root_element(document, env);
	scenario_config_root_element = axiom_node_get_data_element(scenario_config_root_node, env);
	axiom_stax_builder_free_self(stax_builder, env);
			
	children_ite = axiom_element_get_children(scenario_config_root_element, env, 
		scenario_config_root_node);
	if (children_ite)
	{
		/* Get Scenario nodes and build hash*/
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

				if (0 == axutil_strcmp(localname, "Scenario")) /* Scenario */
				{
					axis2_char_t* id = NULL;
					security_admin_scenario_data_t* data = NULL;

					/* Create scenarios hash*/
					if (!scenarios)
						scenarios = axutil_array_list_create(env, SEC_ADMIN_SCENARIO_COUNT);

					data = security_admin_scenario_data_create(env);

					/* Current scenario*/
					security_admin_scenario_data_set_current_scenario(data, AXIS2_TRUE);

					/* id*/
					id = axiom_element_get_attribute_value_by_name(scenario_ele, env, "id");
					security_admin_scenario_data_set_id(data, axutil_strdup(env, id));

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
									
							if (0 == axutil_strcmp(localname, "Summary")) /* Summary */
							{
								security_admin_scenario_data_set_summary(data, 
									axutil_strdup(env, text));
							}
							else if (0 == axutil_strcmp(localname, "Description")) /* Description */
							{
								security_admin_scenario_data_set_description(data, 
									axutil_strdup(env, text));
							}
							else if (0 == axutil_strcmp(localname, "Category")) /* Category */
							{
								security_admin_scenario_data_set_category(data, 
									axutil_strdup(env, text));
							}
							/*else if (0 == axutil_strcmp(localname, "WsuId")*/ /* WsuId */
							/*{
							}*/
							else if (0 == axutil_strcmp(localname, "Type")) /* Type */
							{
								security_admin_scenario_data_set_type(data, 
									axutil_strdup(env, text));
							}
							else if (0 == axutil_strcmp(localname, "Modules")) /* Modules */
							{
										
							}
						}
					}

					/* Add scenario data into the hash map*/
					axutil_array_list_add(scenarios, env, data);
				}
			}
		}
	}

	return scenarios;
}
