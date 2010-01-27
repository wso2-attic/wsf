

/**
* axis2_skel_ServiceGroupAdmin.c
*
* This file was auto-generated from WSDL for "ServiceGroupAdmin|http://mgt.service.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_ServiceGroupAdmin Axis2/C skeleton for the axisService
*/

#include "service_admin_util.h"


AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
service_admin_util_get_wsdl_for_service(axutil_env_t *env, 
									   axis2_char_t *service_name, 
									   axis2_conf_t *conf)
{
	axis2_transport_in_desc_t *transport_in = axis2_conf_get_transport_in(conf, env, AXIS2_TRANSPORT_ENUM_HTTP);
	
	if(transport_in)
	{
		axis2_endpoint_ref_t *epr = NULL;
		axis2_char_t *address = NULL;
		axis2_transport_receiver_t *receiver = axis2_transport_in_desc_get_recv(transport_in, env);
		if(!receiver)
		{
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Transport Receiver Not found ");
			return NULL;
		}
		epr = axis2_transport_receiver_get_epr_for_service(receiver, env, service_name);
		if(!epr)
		{
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Endpoint reference null");
			return NULL;
		}
		address = (axis2_char_t*)axis2_endpoint_ref_get_address(epr,env);
		if(address)
		{
			int length = axutil_strlen(address);
			if(address[length -1 ] == '\\')
			{
				address = axutil_stracat(env, address,"?wsdl");
			}else{
					address = axutil_stracat(env, address,"\?wsdl");
			}

		}
		return address;
	}
	return NULL;
}

AXIS2_EXTERN axis2_svc_t* AXIS2_CALL
service_admin_util_get_service(
	axutil_env_t *env,
	axis2_msg_ctx_t *msg_ctx,
	axis2_char_t *service_name)
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_svc_t *service = NULL;
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	service = axis2_conf_get_svc(conf, env, service_name);
	if(service)
	{
		return service;
	}else
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI , "service not found");
	}
	return NULL;
}
