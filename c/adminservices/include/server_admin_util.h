
#ifndef SERVER_ADMIN_UTIL_H_
#define SERVER_ADMIN_UTIL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "axutil_utils_defines.h"
#include <time.h>

AXIS2_EXTERN void AXIS2_CALL 
server_admin_util_get_up_time(time_t start_time, 
							  axis2_char_t* buffer);

AXIS2_EXTERN void AXIS2_CALL 
server_admin_util_get_timezone(axis2_char_t* buffer);

#ifdef __cplusplus
}
#endif

#endif /* SERVER_ADMIN_UTIL_H_ */
