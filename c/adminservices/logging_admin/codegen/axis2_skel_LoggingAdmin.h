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
     * axis2_skel_LoggingAdmin.h
     *
     * This file was auto-generated from WSDL for "LoggingAdmin|http://service.logging.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_LoggingAdmin Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_getAllLoggerData.h"
    
     #include "adb_getAllLoggerDataResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_updateSystemLog.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getSystemLogResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getAppenderData.h"
    
     #include "adb_getAppenderDataResponse.h"
    
     #include "adb_updateAllAppenderData.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getLoggerData.h"
    
     #include "adb_getLoggerDataResponse.h"
    
     #include "adb_updateLoggerData.h"
    
     #include "adb_ExceptionE0.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     

		 
        /**
         * auto generated function declaration
         * for "getAllLoggerData|http://service.logging.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getAllLoggerData of the adb_getAllLoggerData_t*
         *
         * @return adb_getAllLoggerDataResponse_t*
         */
        adb_getAllLoggerDataResponse_t* axis2_skel_LoggingAdmin_getAllLoggerData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getAllLoggerData_t* _getAllLoggerData);


     
            /**
             * the generated fault union for operation "restoreDefaults|http://service.logging.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_LoggingAdmin_restoreDefaults_fault;
         

		 
        /**
         * auto generated function declaration
         * for "restoreDefaults|http://service.logging.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return 
         */
        axis2_status_t  axis2_skel_LoggingAdmin_restoreDefaults(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_LoggingAdmin_restoreDefaults_fault *fault);


     
            /**
             * the generated fault union for operation "updateSystemLog|http://service.logging.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_LoggingAdmin_updateSystemLog_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateSystemLog|http://service.logging.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateSystemLog of the adb_updateSystemLog_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_LoggingAdmin_updateSystemLog(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateSystemLog_t* _updateSystemLog,
                                          axis2_skel_LoggingAdmin_updateSystemLog_fault *fault);


     
            /**
             * the generated fault union for operation "getSystemLog|http://service.logging.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_LoggingAdmin_getSystemLog_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSystemLog|http://service.logging.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemLogResponse_t*
         */
        adb_getSystemLogResponse_t* axis2_skel_LoggingAdmin_getSystemLog(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_LoggingAdmin_getSystemLog_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getAppenderData|http://service.logging.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getAppenderData of the adb_getAppenderData_t*
         *
         * @return adb_getAppenderDataResponse_t*
         */
        adb_getAppenderDataResponse_t* axis2_skel_LoggingAdmin_getAppenderData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getAppenderData_t* _getAppenderData);


     
            /**
             * the generated fault union for operation "updateAllAppenderData|http://service.logging.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_LoggingAdmin_updateAllAppenderData_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateAllAppenderData|http://service.logging.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateAllAppenderData of the adb_updateAllAppenderData_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_LoggingAdmin_updateAllAppenderData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateAllAppenderData_t* _updateAllAppenderData,
                                          axis2_skel_LoggingAdmin_updateAllAppenderData_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getLoggerData|http://service.logging.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getLoggerData of the adb_getLoggerData_t*
         *
         * @return adb_getLoggerDataResponse_t*
         */
        adb_getLoggerDataResponse_t* axis2_skel_LoggingAdmin_getLoggerData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getLoggerData_t* _getLoggerData);


     
            /**
             * the generated fault union for operation "updateLoggerData|http://service.logging.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_LoggingAdmin_updateLoggerData_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateLoggerData|http://service.logging.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateLoggerData of the adb_updateLoggerData_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_LoggingAdmin_updateLoggerData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateLoggerData_t* _updateLoggerData,
                                          axis2_skel_LoggingAdmin_updateLoggerData_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_LOGGINGADMIN_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_LOGGINGADMIN_ERROR_NONE = AXIS2_SKEL_LOGGINGADMIN_ERROR_CODES_START,
        
        AXIS2_SKEL_LOGGINGADMIN_RESTOREDEFAULTS_FAULT_EXCEPTION,
            AXIS2_SKEL_LOGGINGADMIN_UPDATESYSTEMLOG_FAULT_EXCEPTION,
            AXIS2_SKEL_LOGGINGADMIN_GETSYSTEMLOG_FAULT_EXCEPTION,
            AXIS2_SKEL_LOGGINGADMIN_UPDATEALLAPPENDERDATA_FAULT_EXCEPTION,
            AXIS2_SKEL_LOGGINGADMIN_UPDATELOGGERDATA_FAULT_EXCEPTION,
            AXIS2_SKEL_LOGGINGADMIN_ERROR_LAST
    } axis2_skel_LoggingAdmin_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

