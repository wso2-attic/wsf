
#ifndef SERVICE_ADMIN_UTIL_H_
#define SERVICE_ADMIN_UTIL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "axutil_string.h"
#include "axis2_conf.h"
#include "axutil_url.h"
#include "axis2_transport_receiver.h"
#include "axiom_element.h"

AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
service_admin_util_get_wsdl_for_service(axutil_env_t *env, 
									   axis2_char_t *service_name, 
									   axis2_conf_t *conf);

AXIS2_EXTERN axis2_svc_t* AXIS2_CALL
service_admin_util_get_service(axutil_env_t *env,
							   axis2_msg_ctx_t *msg_ctx,
							   axis2_char_t *service_name);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
service_admin_util_get_epr_address(const axutil_env_t *env,
						   axis2_msg_ctx_t *msg_ctx,
						   axis2_char_t *service_name);

AXIS2_EXTERN axutil_url_t* AXIS2_CALL
service_admin_util_get_server_url(
	const axutil_env_t *env,
	axis2_msg_ctx_t *msg_ctx);

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
service_admin_util_serialize_param(
	   axutil_env_t *env,
	   axutil_param_t *param);

AXIS2_EXTERN axis2_svc_grp_t* AXIS2_CALL
service_admin_util_get_service_group(
	axutil_env_t *env,
	axis2_msg_ctx_t *msg_ctx,
	axis2_char_t *svc_grp_name);

AXIS2_EXTERN long AXIS2_CALL
service_admin_util_get_current_time_in_millis(
    const axutil_env_t *env);

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
service_admin_util_is_filtered_out_service(
	axutil_env_t *env,
	axis2_svc_t *svc);

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
service_admin_util_is_filtered_out_service_group(
	axutil_env_t *env,
	axis2_svc_grp_t *svc);

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
service_admin_util_get_uname(axutil_env_t *env,char mode);



#ifdef __cplusplus
}
#endif

#endif /* SERVICE_ADMIN_UTIL_H_ */
