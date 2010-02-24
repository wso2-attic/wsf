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
     * axis2_skel_ServerAdmin.h
     *
     * This file was auto-generated from WSDL for "ServerAdmin|http://service.admin.server.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_ServerAdmin Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_getServerStatusResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_shutdownResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getServerDataAsStringResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_isAliveResponse.h"
    
     #include "adb_getServerDataResponse.h"
    
     #include "adb_restartGracefullyResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getServerVersionResponse.h"
    
     #include "adb_restartResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_shutdownGracefullyResponse.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "getServerStatus|http://service.admin.server.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServerAdmin_getServerStatus_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getServerStatus|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getServerStatusResponse_t*
         */
        adb_getServerStatusResponse_t* axis2_skel_ServerAdmin_getServerStatus(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ServerAdmin_getServerStatus_fault *fault);


     
            /**
             * the generated fault union for operation "startMaintenance|http://service.admin.server.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServerAdmin_startMaintenance_fault;
         

		 
        /**
         * auto generated function declaration
         * for "startMaintenance|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServerAdmin_startMaintenance(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ServerAdmin_startMaintenance_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "shutdown|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_shutdownResponse_t*
         */
        adb_shutdownResponse_t* axis2_skel_ServerAdmin_shutdown(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     
            /**
             * the generated fault union for operation "endMaintenance|http://service.admin.server.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServerAdmin_endMaintenance_fault;
         

		 
        /**
         * auto generated function declaration
         * for "endMaintenance|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServerAdmin_endMaintenance(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ServerAdmin_endMaintenance_fault *fault);


     
            /**
             * the generated fault union for operation "getServerDataAsString|http://service.admin.server.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServerAdmin_getServerDataAsString_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getServerDataAsString|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getServerDataAsStringResponse_t*
         */
        adb_getServerDataAsStringResponse_t* axis2_skel_ServerAdmin_getServerDataAsString(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ServerAdmin_getServerDataAsString_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "isAlive|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_isAliveResponse_t*
         */
        adb_isAliveResponse_t* axis2_skel_ServerAdmin_isAlive(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getServerData|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getServerDataResponse_t*
         */
        adb_getServerDataResponse_t* axis2_skel_ServerAdmin_getServerData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     
            /**
             * the generated fault union for operation "restartGracefully|http://service.admin.server.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServerAdmin_restartGracefully_fault;
         

		 
        /**
         * auto generated function declaration
         * for "restartGracefully|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_restartGracefullyResponse_t*
         */
        adb_restartGracefullyResponse_t* axis2_skel_ServerAdmin_restartGracefully(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ServerAdmin_restartGracefully_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getServerVersion|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getServerVersionResponse_t*
         */
        adb_getServerVersionResponse_t* axis2_skel_ServerAdmin_getServerVersion(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     
            /**
             * the generated fault union for operation "restart|http://service.admin.server.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServerAdmin_restart_fault;
         

		 
        /**
         * auto generated function declaration
         * for "restart|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_restartResponse_t*
         */
        adb_restartResponse_t* axis2_skel_ServerAdmin_restart(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ServerAdmin_restart_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "shutdownGracefully|http://service.admin.server.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_shutdownGracefullyResponse_t*
         */
        adb_shutdownGracefullyResponse_t* axis2_skel_ServerAdmin_shutdownGracefully(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_SERVERADMIN_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_SERVERADMIN_ERROR_NONE = AXIS2_SKEL_SERVERADMIN_ERROR_CODES_START,
        
        AXIS2_SKEL_SERVERADMIN_GETSERVERSTATUS_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVERADMIN_STARTMAINTENANCE_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVERADMIN_ENDMAINTENANCE_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVERADMIN_GETSERVERDATAASSTRING_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVERADMIN_RESTARTGRACEFULLY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVERADMIN_RESTART_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVERADMIN_ERROR_LAST
    } axis2_skel_ServerAdmin_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

