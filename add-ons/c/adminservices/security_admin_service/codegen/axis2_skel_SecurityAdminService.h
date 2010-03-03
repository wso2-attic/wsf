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
     * axis2_skel_SecurityAdminService.h
     *
     * This file was auto-generated from WSDL for "SecurityAdminService|http://service.config.security.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_SecurityAdminService Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_getScenarios.h"
    
     #include "adb_getScenariosResponse.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_applySecurity.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_activateUsernameTokenAuthentication.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_disableSecurityOnService.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_getSecurityConfigData.h"
    
     #include "adb_getSecurityConfigDataResponse.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    
     #include "adb_getSecurityScenario.h"
    
     #include "adb_getSecurityScenarioResponse.h"
    
     #include "adb_SecurityConfigExceptionE0.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "getScenarios|http://service.config.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_SecurityAdminService_getScenarios_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getScenarios|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getScenarios of the adb_getScenarios_t*
         *
         * @return adb_getScenariosResponse_t*
         */
        adb_getScenariosResponse_t* axis2_skel_SecurityAdminService_getScenarios(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getScenarios_t* _getScenarios,
                                          axis2_skel_SecurityAdminService_getScenarios_fault *fault);


     
            /**
             * the generated fault union for operation "applySecurity|http://service.config.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_SecurityAdminService_applySecurity_fault;
         

		 
        /**
         * auto generated function declaration
         * for "applySecurity|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _applySecurity of the adb_applySecurity_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_SecurityAdminService_applySecurity(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_applySecurity_t* _applySecurity,
                                          axis2_skel_SecurityAdminService_applySecurity_fault *fault);


     
            /**
             * the generated fault union for operation "activateUsernameTokenAuthentication|http://service.config.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_SecurityAdminService_activateUsernameTokenAuthentication_fault;
         

		 
        /**
         * auto generated function declaration
         * for "activateUsernameTokenAuthentication|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _activateUsernameTokenAuthentication of the adb_activateUsernameTokenAuthentication_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_SecurityAdminService_activateUsernameTokenAuthentication(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_activateUsernameTokenAuthentication_t* _activateUsernameTokenAuthentication,
                                          axis2_skel_SecurityAdminService_activateUsernameTokenAuthentication_fault *fault);


     
            /**
             * the generated fault union for operation "disableSecurityOnService|http://service.config.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_SecurityAdminService_disableSecurityOnService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "disableSecurityOnService|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disableSecurityOnService of the adb_disableSecurityOnService_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_SecurityAdminService_disableSecurityOnService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_disableSecurityOnService_t* _disableSecurityOnService,
                                          axis2_skel_SecurityAdminService_disableSecurityOnService_fault *fault);


     
            /**
             * the generated fault union for operation "getSecurityConfigData|http://service.config.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_SecurityAdminService_getSecurityConfigData_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSecurityConfigData|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getSecurityConfigData of the adb_getSecurityConfigData_t*
         *
         * @return adb_getSecurityConfigDataResponse_t*
         */
        adb_getSecurityConfigDataResponse_t* axis2_skel_SecurityAdminService_getSecurityConfigData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getSecurityConfigData_t* _getSecurityConfigData,
                                          axis2_skel_SecurityAdminService_getSecurityConfigData_fault *fault);


     
            /**
             * the generated fault union for operation "getSecurityScenario|http://service.config.security.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_SecurityConfigExceptionE0_t* SecurityConfigException;
                
            } axis2_skel_SecurityAdminService_getSecurityScenario_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSecurityScenario|http://service.config.security.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getSecurityScenario of the adb_getSecurityScenario_t*
         *
         * @return adb_getSecurityScenarioResponse_t*
         */
        adb_getSecurityScenarioResponse_t* axis2_skel_SecurityAdminService_getSecurityScenario(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getSecurityScenario_t* _getSecurityScenario,
                                          axis2_skel_SecurityAdminService_getSecurityScenario_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_SECURITYADMINSERVICE_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_SECURITYADMINSERVICE_ERROR_NONE = AXIS2_SKEL_SECURITYADMINSERVICE_ERROR_CODES_START,
        
        AXIS2_SKEL_SECURITYADMINSERVICE_GETSCENARIOS_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_SECURITYADMINSERVICE_APPLYSECURITY_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_SECURITYADMINSERVICE_ACTIVATEUSERNAMETOKENAUTHENTICATION_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_SECURITYADMINSERVICE_DISABLESECURITYONSERVICE_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_SECURITYADMINSERVICE_GETSECURITYCONFIGDATA_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_SECURITYADMINSERVICE_GETSECURITYSCENARIO_FAULT_SECURITYCONFIGEXCEPTION,
            AXIS2_SKEL_SECURITYADMINSERVICE_ERROR_LAST
    } axis2_skel_SecurityAdminService_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

