
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
