

/**
* axis2_skel_ServiceGroupAdmin.c
*
* This file was auto-generated from WSDL for "ServiceGroupAdmin|http://mgt.service.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_ServiceGroupAdmin Axis2/C skeleton for the axisService
*/

#include "service_admin_util.h"
#include "service_admin_constants.h"
#include "axutil_dll_desc.h"
#include "axiom.h"


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


AXIS2_EXTERN axis2_char_t* AXIS2_CALL
service_admin_util_get_epr_address(const axutil_env_t *env,
						   axis2_msg_ctx_t *msg_ctx,
						   axis2_char_t *service_name)
{
	axis2_endpoint_ref_t *epr = NULL;
	axis2_char_t *address = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_transport_in_desc_t *transport_in = NULL;

	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	
	transport_in = axis2_conf_get_transport_in(conf, env, AXIS2_TRANSPORT_ENUM_HTTP);

	if(transport_in)
	{
		axis2_transport_receiver_t *receiver = NULL;
		receiver = axis2_transport_in_desc_get_recv(transport_in, env);
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
	}
	return address;
}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
service_admin_util_serialize_param(axutil_env_t *env,
								   axutil_param_t *param)
{
	axis2_char_t *name = NULL;
	axis2_char_t *value = NULL;
	void *param_value = NULL;
	axiom_node_t *param_node = NULL;
	axiom_element_t *param_ele = NULL;
	axiom_attribute_t *attri = NULL;

	name = axutil_param_get_name(param, env);
	param_value = axutil_param_get_value(param, env);
	if(name && axutil_strcmp(name, "ServiceClass") ==0)
	{
	}else
	{
		value = (axis2_char_t*)param_value;
	}

	param_ele = axiom_element_create(env, NULL, "parameter", NULL, &param_node);
	
	attri = axiom_attribute_create(env, "name", name, NULL);
	axiom_element_add_attribute(param_ele, env, attri, param_node);
	if(value)
		axiom_element_set_text(param_ele, env, value, param_node);
	return param_node;
}

AXIS2_EXTERN axis2_svc_grp_t* AXIS2_CALL
service_admin_util_get_service_group(
	axutil_env_t *env,
	axis2_msg_ctx_t *msg_ctx,
	axis2_char_t *svc_grp_name)
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_svc_grp_t *service_grp = NULL;
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	service_grp = axis2_conf_get_svc_grp(conf, env, svc_grp_name);
	if(service_grp)
	{
		return service_grp;
	}else
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI , "service not found");
	}
	return NULL;

}

AXIS2_EXTERN long AXIS2_CALL
service_admin_util_get_current_time_in_millis(
    const axutil_env_t *env)
{
    long seconds = -1;
    struct timeb *tp = AXIS2_MALLOC(env->allocator, sizeof(struct timeb));
    ftime(tp);
    /* To prevent an overflow we substract a contstant from seconds value
     * This value is taken as 18.23.xx seconds on 26 Jul 2006
     */
    seconds = tp->time;
    if(tp)
        AXIS2_FREE(env->allocator, tp);
    return seconds;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
service_admin_util_is_filtered_out_service(
	axutil_env_t *env,
	axis2_svc_t *svc)
{
	axutil_param_t *param =  NULL;
	if(!svc)
		return AXIS2_FALSE;

	param = axis2_svc_get_param(svc, env, ADMIN_SERVICE_PARAM_NAME);
	if(param)
	{
		axis2_char_t *value = NULL;
		value = axutil_param_get_value(param, env);
		if(value && axutil_strcmp(value, "true") == 0)
			return AXIS2_TRUE;
	}
	
	param = axis2_svc_get_param(svc, env, HIDDEN_SERVICE_PARAM_NAME);
	if(param)
	{
		axis2_char_t *value = NULL;
		value = axutil_param_get_value(param, env);
		if(value && axutil_strcmp(value, "true") == 0)
			return AXIS2_TRUE;
	}
	return AXIS2_FALSE;

}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
service_admin_util_is_filtered_out_service_group(
	axutil_env_t *env,
	axis2_svc_grp_t *svc_grp)
{
	axutil_param_t *param =  NULL;
	if(!svc_grp)
		return AXIS2_FALSE;

	param = axis2_svc_grp_get_param(svc_grp, env, ADMIN_SERVICE_PARAM_NAME);
	if(param)
	{
		axis2_char_t *value = NULL;
		value = axutil_param_get_value(param, env);
		if(value && axutil_strcmp(value, "true") == 0)
			return AXIS2_TRUE;
	}
	
	param = axis2_svc_grp_get_param(svc_grp, env, HIDDEN_SERVICE_PARAM_NAME);
	if(param)
	{
		axis2_char_t *value = NULL;
		value = axutil_param_get_value(param, env);
		if(value && axutil_strcmp(value, "true") == 0)
			return AXIS2_TRUE;
	}
	return AXIS2_FALSE;

}

