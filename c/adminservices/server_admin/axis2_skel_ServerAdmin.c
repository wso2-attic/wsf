

/**
* axis2_skel_ServerAdmin.c
*
* This file was auto-generated from WSDL for "ServerAdmin|http://service.admin.server.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_ServerAdmin Axis2/C skeleton for the axisService
*/

#include "codegen/axis2_skel_ServerAdmin.h"
#include "service_admin_util.h"
#include "service_admin_constants.h"
#include "axutil_version.h"



/**
* auto generated function definition signature
* for "getServerStatus|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getServerStatusResponse_t*
*/
adb_getServerStatusResponse_t* 
axis2_skel_ServerAdmin_getServerStatus(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	axis2_skel_ServerAdmin_getServerStatus_fault *fault )
{
	adb_getServerStatusResponse_t* response = adb_getServerStatusResponse_create(env);
	return response;
}



/**
* auto generated function definition signature
* for "startMaintenance|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return 
*/
axis2_status_t  
axis2_skel_ServerAdmin_startMaintenance(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	axis2_skel_ServerAdmin_startMaintenance_fault *fault )
{
	
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "shutdown|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_shutdownResponse_t*
*/
adb_shutdownResponse_t* 
axis2_skel_ServerAdmin_shutdown(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx )
{
	adb_shutdownResponse_t *shutdown_res = adb_shutdownResponse_create(env);

	return shutdown_res;
}



/**
* auto generated function definition signature
* for "endMaintenance|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return 
*/
axis2_status_t  
axis2_skel_ServerAdmin_endMaintenance(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	axis2_skel_ServerAdmin_endMaintenance_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return AXIS2_SUCCESS;
}



/**
* auto generated function definition signature
* for "getServerDataAsString|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getServerDataAsStringResponse_t*
*/
adb_getServerDataAsStringResponse_t* 
axis2_skel_ServerAdmin_getServerDataAsString(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx,
	axis2_skel_ServerAdmin_getServerDataAsString_fault *fault )
{
	adb_getServerDataAsStringResponse_t *response = adb_getServerDataAsStringResponse_create(env);
	return response;
}



/**
* auto generated function definition signature
* for "isAlive|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_isAliveResponse_t*
*/
adb_isAliveResponse_t* 
axis2_skel_ServerAdmin_isAlive(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx )
{
	adb_isAliveResponse_t *aliveResponse = adb_isAliveResponse_create(env);
	return aliveResponse;
}



/**
* auto generated function definition signature
* for "getServerData|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getServerDataResponse_t*
*/
adb_getServerDataResponse_t* 
axis2_skel_ServerAdmin_getServerData(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx )
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_conf_t *conf = NULL;
	adb_ServerData_t *server_data = NULL;
	adb_getServerDataResponse_t *server_data_res  = NULL;
	axis2_char_t *repo_location = NULL;
	axutil_url_t *url = NULL;
	
	server_data = adb_ServerData_create(env);
	
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	conf = axis2_conf_ctx_get_conf(conf_ctx, env);
	repo_location = axis2_conf_get_repo(conf, env);
	
	
	adb_ServerData_set_osName(server_data, env, service_admin_util_get_uname(env, 'a'));
	adb_ServerData_set_osVersion(server_data, env, service_admin_util_get_uname(env,'r'));

	adb_ServerData_set_dbDriverName(server_data, env, "testdriver");
	adb_ServerData_set_dbDriverVersion(server_data, env, "1.0");
	adb_ServerData_set_dbURL(server_data, env,"http://test");
	adb_ServerData_set_dbName(server_data,env,"test");
	adb_ServerData_set_dbVersion(server_data, env, "5.1");

	adb_ServerData_set_javaHome(server_data, env,AXIS2_GETENV("JAVA_HOME"));
	adb_ServerData_set_javaRuntimeName(server_data, env, "JRE");
	adb_ServerData_set_javaVersion(server_data, env, "1.6.0");
	adb_ServerData_set_javaVMVendor(server_data, env, "java.sun.com");
	adb_ServerData_set_javaVMVersion(server_data, env, "1.6.0");

	adb_ServerData_set_userHome(server_data, env, AXIS2_GETENV(USERHOME));
	adb_ServerData_set_axis2Location(server_data, env, repo_location);
	adb_ServerData_set_userCountry(server_data, env, "LK");
	adb_ServerData_set_userName(server_data, env, AXIS2_GETENV(USERNAME));

	adb_ServerData_set_userTimezone(server_data, env, "Test");

	adb_ServerData_set_wso2wsasVersion(server_data,env,"3.1");

	url = service_admin_util_get_server_url(env, msg_ctx);
	adb_ServerData_set_serverIp(server_data, env,axutil_url_get_host(url, env));
	adb_ServerData_set_serverName(server_data, env, "Server1");
	adb_ServerData_set_systemUpTime(server_data, env, "10:10");
	adb_ServerData_set_serverStartTime(server_data, env, "1");
	adb_ServerData_set_registryType(server_data,env, "local");
	adb_ServerData_set_remoteRegistryChroot_nil(server_data,env);
	adb_ServerData_set_remoteRegistryURL_nil(server_data, env);

	server_data_res = adb_getServerDataResponse_create(env);
	adb_getServerDataResponse_set_return(server_data_res, env, server_data);
	return server_data_res;
}



/**
* auto generated function definition signature
* for "restartGracefully|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_restartGracefullyResponse_t*
*/
adb_restartGracefullyResponse_t* axis2_skel_ServerAdmin_restartGracefully(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
																		  axis2_skel_ServerAdmin_restartGracefully_fault *fault )
{
	adb_restartGracefullyResponse_t *response = adb_restartGracefullyResponse_create(env);
	return response;
}



/**
* auto generated function definition signature
* for "getServerVersion|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getServerVersionResponse_t*
*/
adb_getServerVersionResponse_t* 
axis2_skel_ServerAdmin_getServerVersion(
	const axutil_env_t *env , 
	axis2_msg_ctx_t *msg_ctx )
{
	axis2_char_t *version = NULL;
	adb_getServerVersionResponse_t *response = adb_getServerVersionResponse_create(env);
	version = axis2_version_string();
	adb_getServerVersionResponse_set_return(response,env, version);
	return response;
}



/**
* auto generated function definition signature
* for "restart|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_restartResponse_t*
*/
adb_restartResponse_t* axis2_skel_ServerAdmin_restart(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
													  axis2_skel_ServerAdmin_restart_fault *fault )
{
	/* TODO fill this with the necessary business logic */
	return (adb_restartResponse_t*)NULL;
}



/**
* auto generated function definition signature
* for "shutdownGracefully|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_shutdownGracefullyResponse_t*
*/
adb_shutdownGracefullyResponse_t* axis2_skel_ServerAdmin_shutdownGracefully(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
{
	/* TODO fill this with the necessary business logic */
	return (adb_shutdownGracefullyResponse_t*)NULL;
}


