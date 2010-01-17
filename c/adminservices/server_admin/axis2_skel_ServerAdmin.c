

/**
* axis2_skel_ServerAdmin.c
*
* This file was auto-generated from WSDL for "ServerAdmin|http://service.admin.server.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_ServerAdmin Axis2/C skeleton for the axisService
*/

#include "codegen/axis2_skel_ServerAdmin.h"




/**
* auto generated function definition signature
* for "getServerStatus|http://service.admin.server.carbon.wso2.org" operation.
* @param env environment ( mandatory)* @param MessageContext the outmessage context
*
* @return adb_getServerStatusResponse_t*
*/
adb_getServerStatusResponse_t* axis2_skel_ServerAdmin_getServerStatus(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
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
axis2_status_t  axis2_skel_ServerAdmin_startMaintenance(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
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
adb_shutdownResponse_t* axis2_skel_ServerAdmin_shutdown(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
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
axis2_status_t  axis2_skel_ServerAdmin_endMaintenance(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
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
axis2_skel_ServerAdmin_getServerDataAsString(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
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
axis2_skel_ServerAdmin_isAlive(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
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
adb_getServerDataResponse_t* axis2_skel_ServerAdmin_getServerData(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
{
	adb_getServerDataResponse_t *serverDataRes = adb_getServerDataResponse_create(env);
	return serverDataRes;
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
adb_getServerVersionResponse_t* axis2_skel_ServerAdmin_getServerVersion(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
{
	adb_getServerVersionResponse_t *response = adb_getServerVersionResponse_create(env);
	/* TODO fill this with the necessary business logic */
	return (adb_getServerVersionResponse_t*)NULL;
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


