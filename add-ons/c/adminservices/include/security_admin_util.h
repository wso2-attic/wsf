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

#ifndef SECURITY_ADMIN_UTIL_H_
#define SECURITY_ADMIN_UTIL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "axutil_string.h"
#include "axis2_conf.h"
#include "axis2_transport_receiver.h"
#include "axiom_element.h"

typedef struct security_admin_scenario_data security_admin_scenario_data_t;

AXIS2_EXTERN security_admin_scenario_data_t* 
AXIS2_CALL security_admin_scenario_data_create(
	const axutil_env_t* env);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_id(
	const security_admin_scenario_data_t* data);

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_id(
	security_admin_scenario_data_t* data,
	axis2_char_t* id);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_summary(
	const security_admin_scenario_data_t* data);

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_summary(
	security_admin_scenario_data_t* data,
	axis2_char_t* summary);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_description(
	const security_admin_scenario_data_t* data);

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_description(
	security_admin_scenario_data_t* data,
	axis2_char_t* description);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_category(
	const security_admin_scenario_data_t* data);

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_category(
	security_admin_scenario_data_t* data,
	axis2_char_t* category);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
security_admin_scenario_data_get_type(
	const security_admin_scenario_data_t* data);

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_type(
	security_admin_scenario_data_t* data,
	axis2_char_t* type);

AXIS2_EXTERN axis2_bool_t AXIS2_CALL 
security_admin_scenario_data_get_current_scenario(
	const security_admin_scenario_data_t* data);

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_set_current_scenario(
	security_admin_scenario_data_t* data,
	axis2_bool_t current_scenario);

AXIS2_EXTERN void AXIS2_CALL 
security_admin_scenario_data_free(
	  const axutil_env_t* env,
	  security_admin_scenario_data_t* data);

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
security_admin_load_scenarios(
		const axutil_env_t* env, 
		axis2_msg_ctx_t* msg_ctx);

#ifdef __cplusplus
}
#endif

#endif /* SECURITY_ADMIN_UTIL_H_ */
