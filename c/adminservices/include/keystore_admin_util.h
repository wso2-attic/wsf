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

#ifndef KEYSTORE_ADMIN_UTIL_H_
#define KEYSTORE_ADMIN_UTIL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "axutil_string.h"
#include "axutil_utils_defines.h"

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
keystore_admin_util_format_date(const axutil_env_t* env,
								axis2_char_t* src,
								axis2_char_t* result);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
keystore_admin_util_get_keystore_details(const axutil_env_t* env,
										 axis2_char_t* repo_path,
										 axis2_char_t* keystore_name,
										 axis2_char_t* password,
										 axis2_char_t* provider,
									     axis2_char_t* pvt_key_pass);

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
keystore_admin_util_get_private_store(const axutil_env_t* env, 
									  axis2_char_t* repo_path,
									  axis2_char_t* keystore_name,
									  axis2_char_t* password);

AXIS2_EXTERN axutil_array_list_t* AXIS2_CALL
keystore_admin_util_get_keystore_filenames(const axutil_env_t* env,
										   axis2_char_t* repo_path);

#ifdef __cplusplus
}
#endif

#endif /* KEYSTORE_ADMIN_UTIL_H_ */
