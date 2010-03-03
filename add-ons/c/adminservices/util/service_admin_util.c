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
#include "axutil_url.h"
#include <sys/timeb.h>

#if WIN32 
#define snprintf sprintf_s 
#endif


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
		return NULL;
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


AXIS2_EXTERN axis2_char_t* AXIS2_CALL
service_admin_util_get_uname(axutil_env_t *env,char mode)
{
	char *unameval;
	char tmp_uname[256];
#ifdef WIN32
	DWORD dwBuild=0;
	DWORD dwVersion = GetVersion();
	DWORD dwWindowsMajorVersion =  (DWORD)(LOBYTE(LOWORD(dwVersion)));
	DWORD dwWindowsMinorVersion =  (DWORD)(HIBYTE(LOWORD(dwVersion)));
	DWORD dwSize = MAX_COMPUTERNAME_LENGTH + 1;
	TCHAR ComputerName[MAX_COMPUTERNAME_LENGTH + 1];
	SYSTEM_INFO SysInfo;

	GetComputerName(ComputerName, &dwSize);
	GetSystemInfo(&SysInfo);

	if (mode == 's') {
		if (dwVersion < 0x80000000) {
			unameval = "Windows NT";
		} else {
			unameval = "Windows 9x";
		}
	} else if (mode == 'r') {
		snprintf(tmp_uname, sizeof(tmp_uname), "%d.%d", dwWindowsMajorVersion, dwWindowsMinorVersion);
		unameval = tmp_uname;
	} else if (mode == 'n') {
		unameval = ComputerName;
	} else if (mode == 'v') {
		dwBuild = (DWORD)(HIWORD(dwVersion));
		snprintf(tmp_uname, sizeof(tmp_uname), "build %d", dwBuild);
		unameval = tmp_uname;
	} else if (mode == 'm') {
		switch (SysInfo.wProcessorArchitecture) {
			case PROCESSOR_ARCHITECTURE_INTEL :
				snprintf(tmp_uname, sizeof(tmp_uname), "i%d", SysInfo.dwProcessorType);
				unameval = tmp_uname;
				break;
			case PROCESSOR_ARCHITECTURE_MIPS :
				snprintf(tmp_uname, sizeof(tmp_uname), "MIPS R%d000", SysInfo.wProcessorLevel);
				unameval = tmp_uname;
				break;
			case PROCESSOR_ARCHITECTURE_ALPHA :
				snprintf(tmp_uname, sizeof(tmp_uname), "Alpha %d", SysInfo.wProcessorLevel);
				unameval = tmp_uname;
				break;
			case PROCESSOR_ARCHITECTURE_PPC :
				snprintf(tmp_uname, sizeof(tmp_uname), "PPC 6%02d", SysInfo.wProcessorLevel);
				unameval = tmp_uname;
				break;
			case PROCESSOR_ARCHITECTURE_IA64 :
				unameval = "IA64";
				break;
#if defined(PROCESSOR_ARCHITECTURE_IA32_ON_WIN64)
			case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 :
				unameval = "IA32";
				break;
#endif
#if defined(PROCESSOR_ARCHITECTURE_AMD64)
			case PROCESSOR_ARCHITECTURE_AMD64 :
				unameval = "AMD64";
				break;
#endif
			case PROCESSOR_ARCHITECTURE_UNKNOWN :
			default :
				unameval = "Unknown";
				break;
		}
	} else { /* assume mode == 'a' */
		/* Get build numbers for Windows NT or Win95 */
		if (dwVersion < 0x80000000){
			dwBuild = (DWORD)(HIWORD(dwVersion));
			snprintf(tmp_uname, sizeof(tmp_uname), "%s %d.%d build %d",
					 "Windows NT", 
					 dwWindowsMajorVersion, dwWindowsMinorVersion, dwBuild);
		} else {
			snprintf(tmp_uname, sizeof(tmp_uname), "%s %s %d.%d",
					 "Windows 9x",
					 dwWindowsMajorVersion, dwWindowsMinorVersion);
		}
		unameval = tmp_uname;
	}
#else
#ifdef HAVE_SYS_UTSNAME_H
	struct utsname buf;
	if (uname((struct utsname *)&buf) == -1) {
		unameval = "Linux";
	} else {
		if (mode == 's') {
			unameval = buf.sysname;
		} else if (mode == 'r') {
			unameval = buf.release;
		} else if (mode == 'n') {
			unameval = buf.nodename;
		} else if (mode == 'v') {
			unameval = buf.version;
		} else if (mode == 'm') {
			unameval = buf.machine;
		} else { /* assume mode == 'a' */
			snprintf(tmp_uname, sizeof(tmp_uname), "%s %s %s %s %s",
					 buf.sysname, buf.nodename, buf.release, buf.version,
					 buf.machine);
			unameval = tmp_uname;
		}

	}
#endif
#endif
	return axutil_strdup(env,unameval);

}

AXIS2_EXTERN axutil_url_t* AXIS2_CALL
service_admin_util_get_server_url(
	const axutil_env_t *env,
	axis2_msg_ctx_t *msg_ctx)
{

	axis2_endpoint_ref_t *epr = NULL;
	axis2_char_t *address = NULL;
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	axis2_transport_in_desc_t *transport_in = NULL;
	axis2_svc_t *svc = NULL;
	axis2_char_t *svc_name = NULL;
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	
	svc = axis2_msg_ctx_get_svc(msg_ctx, env);
	svc_name = axis2_svc_get_name(svc, env);

	transport_in = axis2_conf_get_transport_in(conf, env, AXIS2_TRANSPORT_ENUM_HTTP);

	if(transport_in)
	{
		axutil_url_t *url = NULL;
		axis2_transport_receiver_t *receiver = NULL;
		receiver = axis2_transport_in_desc_get_recv(transport_in, env);
		if(!receiver)
		{
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Transport Receiver Not found ");
			return NULL;
		}
		epr = axis2_transport_receiver_get_epr_for_service(receiver, env, svc_name);
		if(!epr)
		{
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Endpoint reference null");
			return NULL;
		}
		address = (axis2_char_t*)axis2_endpoint_ref_get_address(epr,env);
return axutil_url_parse_string(env, address);
		
	}
	return NULL;



}