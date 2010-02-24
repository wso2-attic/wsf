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
     * axis2_skel_ModuleAdminService.h
     *
     * This file was auto-generated from WSDL for "ModuleAdminService|http://service.mgt.module.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_ModuleAdminService Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_engageModuleForService.h"
    
     #include "adb_engageModuleForServiceResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_disengageModuleFromSystem.h"
    
     #include "adb_disengageModuleFromSystemResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_disengageModuleForService.h"
    
     #include "adb_disengageModuleForServiceResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_setModuleParameters.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_removeModule.h"
    
     #include "adb_removeModuleResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_removeModuleParameter.h"
    
     #include "adb_removeModuleParameterResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_getModuleParameters.h"
    
     #include "adb_getModuleParametersResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_engageModuleForOperation.h"
    
     #include "adb_engageModuleForOperationResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_listGloballyEngagedModulesResponse.h"
    
     #include "adb_globallyEngageModule.h"
    
     #include "adb_globallyEngageModuleResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_engageModuleForServiceGroup.h"
    
     #include "adb_engageModuleForServiceGroupResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_uploadModule.h"
    
     #include "adb_uploadModuleResponse.h"
    
     #include "adb_listModulesForOperation.h"
    
     #include "adb_listModulesForOperationResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_listModulesForService.h"
    
     #include "adb_listModulesForServiceResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_disengageModuleForServiceGroup.h"
    
     #include "adb_disengageModuleForServiceGroupResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_globallyDisengageModule.h"
    
     #include "adb_globallyDisengageModuleResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_listModulesResponse.h"
    
     #include "adb_listModulesForServiceGroup.h"
    
     #include "adb_listModulesForServiceGroupResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_disengageModuleForOperation.h"
    
     #include "adb_disengageModuleForOperationResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    
     #include "adb_getModuleInfo.h"
    
     #include "adb_getModuleInfoResponse.h"
    
     #include "adb_ModuleMgtExceptionE0.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "engageModuleForService|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_engageModuleForService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "engageModuleForService|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _engageModuleForService of the adb_engageModuleForService_t*
         *
         * @return adb_engageModuleForServiceResponse_t*
         */
        adb_engageModuleForServiceResponse_t* axis2_skel_ModuleAdminService_engageModuleForService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_engageModuleForService_t* _engageModuleForService,
                                          axis2_skel_ModuleAdminService_engageModuleForService_fault *fault);


     
            /**
             * the generated fault union for operation "disengageModuleFromSystem|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_disengageModuleFromSystem_fault;
         

		 
        /**
         * auto generated function declaration
         * for "disengageModuleFromSystem|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disengageModuleFromSystem of the adb_disengageModuleFromSystem_t*
         *
         * @return adb_disengageModuleFromSystemResponse_t*
         */
        adb_disengageModuleFromSystemResponse_t* axis2_skel_ModuleAdminService_disengageModuleFromSystem(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_disengageModuleFromSystem_t* _disengageModuleFromSystem,
                                          axis2_skel_ModuleAdminService_disengageModuleFromSystem_fault *fault);


     
            /**
             * the generated fault union for operation "disengageModuleForService|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_disengageModuleForService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "disengageModuleForService|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disengageModuleForService of the adb_disengageModuleForService_t*
         *
         * @return adb_disengageModuleForServiceResponse_t*
         */
        adb_disengageModuleForServiceResponse_t* axis2_skel_ModuleAdminService_disengageModuleForService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_disengageModuleForService_t* _disengageModuleForService,
                                          axis2_skel_ModuleAdminService_disengageModuleForService_fault *fault);


     
            /**
             * the generated fault union for operation "setModuleParameters|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_setModuleParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setModuleParameters|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setModuleParameters of the adb_setModuleParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ModuleAdminService_setModuleParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setModuleParameters_t* _setModuleParameters,
                                          axis2_skel_ModuleAdminService_setModuleParameters_fault *fault);


     
            /**
             * the generated fault union for operation "removeModule|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_removeModule_fault;
         

		 
        /**
         * auto generated function declaration
         * for "removeModule|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeModule of the adb_removeModule_t*
         *
         * @return adb_removeModuleResponse_t*
         */
        adb_removeModuleResponse_t* axis2_skel_ModuleAdminService_removeModule(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeModule_t* _removeModule,
                                          axis2_skel_ModuleAdminService_removeModule_fault *fault);


     
            /**
             * the generated fault union for operation "removeModuleParameter|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_removeModuleParameter_fault;
         

		 
        /**
         * auto generated function declaration
         * for "removeModuleParameter|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeModuleParameter of the adb_removeModuleParameter_t*
         *
         * @return adb_removeModuleParameterResponse_t*
         */
        adb_removeModuleParameterResponse_t* axis2_skel_ModuleAdminService_removeModuleParameter(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeModuleParameter_t* _removeModuleParameter,
                                          axis2_skel_ModuleAdminService_removeModuleParameter_fault *fault);


     
            /**
             * the generated fault union for operation "getModuleParameters|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_getModuleParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getModuleParameters|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getModuleParameters of the adb_getModuleParameters_t*
         *
         * @return adb_getModuleParametersResponse_t*
         */
        adb_getModuleParametersResponse_t* axis2_skel_ModuleAdminService_getModuleParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getModuleParameters_t* _getModuleParameters,
                                          axis2_skel_ModuleAdminService_getModuleParameters_fault *fault);


     
            /**
             * the generated fault union for operation "engageModuleForOperation|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_engageModuleForOperation_fault;
         

		 
        /**
         * auto generated function declaration
         * for "engageModuleForOperation|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _engageModuleForOperation of the adb_engageModuleForOperation_t*
         *
         * @return adb_engageModuleForOperationResponse_t*
         */
        adb_engageModuleForOperationResponse_t* axis2_skel_ModuleAdminService_engageModuleForOperation(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_engageModuleForOperation_t* _engageModuleForOperation,
                                          axis2_skel_ModuleAdminService_engageModuleForOperation_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "listGloballyEngagedModules|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_listGloballyEngagedModulesResponse_t*
         */
        adb_listGloballyEngagedModulesResponse_t* axis2_skel_ModuleAdminService_listGloballyEngagedModules(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     
            /**
             * the generated fault union for operation "globallyEngageModule|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_globallyEngageModule_fault;
         

		 
        /**
         * auto generated function declaration
         * for "globallyEngageModule|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _globallyEngageModule of the adb_globallyEngageModule_t*
         *
         * @return adb_globallyEngageModuleResponse_t*
         */
        adb_globallyEngageModuleResponse_t* axis2_skel_ModuleAdminService_globallyEngageModule(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_globallyEngageModule_t* _globallyEngageModule,
                                          axis2_skel_ModuleAdminService_globallyEngageModule_fault *fault);


     
            /**
             * the generated fault union for operation "engageModuleForServiceGroup|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_engageModuleForServiceGroup_fault;
         

		 
        /**
         * auto generated function declaration
         * for "engageModuleForServiceGroup|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _engageModuleForServiceGroup of the adb_engageModuleForServiceGroup_t*
         *
         * @return adb_engageModuleForServiceGroupResponse_t*
         */
        adb_engageModuleForServiceGroupResponse_t* axis2_skel_ModuleAdminService_engageModuleForServiceGroup(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_engageModuleForServiceGroup_t* _engageModuleForServiceGroup,
                                          axis2_skel_ModuleAdminService_engageModuleForServiceGroup_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "uploadModule|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _uploadModule of the adb_uploadModule_t*
         *
         * @return adb_uploadModuleResponse_t*
         */
        adb_uploadModuleResponse_t* axis2_skel_ModuleAdminService_uploadModule(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_uploadModule_t* _uploadModule);


     
            /**
             * the generated fault union for operation "listModulesForOperation|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_listModulesForOperation_fault;
         

		 
        /**
         * auto generated function declaration
         * for "listModulesForOperation|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listModulesForOperation of the adb_listModulesForOperation_t*
         *
         * @return adb_listModulesForOperationResponse_t*
         */
        adb_listModulesForOperationResponse_t* axis2_skel_ModuleAdminService_listModulesForOperation(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listModulesForOperation_t* _listModulesForOperation,
                                          axis2_skel_ModuleAdminService_listModulesForOperation_fault *fault);


     
            /**
             * the generated fault union for operation "listModulesForService|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_listModulesForService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "listModulesForService|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listModulesForService of the adb_listModulesForService_t*
         *
         * @return adb_listModulesForServiceResponse_t*
         */
        adb_listModulesForServiceResponse_t* axis2_skel_ModuleAdminService_listModulesForService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listModulesForService_t* _listModulesForService,
                                          axis2_skel_ModuleAdminService_listModulesForService_fault *fault);


     
            /**
             * the generated fault union for operation "disengageModuleForServiceGroup|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_disengageModuleForServiceGroup_fault;
         

		 
        /**
         * auto generated function declaration
         * for "disengageModuleForServiceGroup|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disengageModuleForServiceGroup of the adb_disengageModuleForServiceGroup_t*
         *
         * @return adb_disengageModuleForServiceGroupResponse_t*
         */
        adb_disengageModuleForServiceGroupResponse_t* axis2_skel_ModuleAdminService_disengageModuleForServiceGroup(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_disengageModuleForServiceGroup_t* _disengageModuleForServiceGroup,
                                          axis2_skel_ModuleAdminService_disengageModuleForServiceGroup_fault *fault);


     
            /**
             * the generated fault union for operation "globallyDisengageModule|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_globallyDisengageModule_fault;
         

		 
        /**
         * auto generated function declaration
         * for "globallyDisengageModule|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _globallyDisengageModule of the adb_globallyDisengageModule_t*
         *
         * @return adb_globallyDisengageModuleResponse_t*
         */
        adb_globallyDisengageModuleResponse_t* axis2_skel_ModuleAdminService_globallyDisengageModule(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_globallyDisengageModule_t* _globallyDisengageModule,
                                          axis2_skel_ModuleAdminService_globallyDisengageModule_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "listModules|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_listModulesResponse_t*
         */
        adb_listModulesResponse_t* axis2_skel_ModuleAdminService_listModules(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     
            /**
             * the generated fault union for operation "listModulesForServiceGroup|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_listModulesForServiceGroup_fault;
         

		 
        /**
         * auto generated function declaration
         * for "listModulesForServiceGroup|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listModulesForServiceGroup of the adb_listModulesForServiceGroup_t*
         *
         * @return adb_listModulesForServiceGroupResponse_t*
         */
        adb_listModulesForServiceGroupResponse_t* axis2_skel_ModuleAdminService_listModulesForServiceGroup(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listModulesForServiceGroup_t* _listModulesForServiceGroup,
                                          axis2_skel_ModuleAdminService_listModulesForServiceGroup_fault *fault);


     
            /**
             * the generated fault union for operation "disengageModuleForOperation|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_disengageModuleForOperation_fault;
         

		 
        /**
         * auto generated function declaration
         * for "disengageModuleForOperation|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disengageModuleForOperation of the adb_disengageModuleForOperation_t*
         *
         * @return adb_disengageModuleForOperationResponse_t*
         */
        adb_disengageModuleForOperationResponse_t* axis2_skel_ModuleAdminService_disengageModuleForOperation(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_disengageModuleForOperation_t* _disengageModuleForOperation,
                                          axis2_skel_ModuleAdminService_disengageModuleForOperation_fault *fault);


     
            /**
             * the generated fault union for operation "getModuleInfo|http://service.mgt.module.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ModuleMgtExceptionE0_t* ModuleMgtException;
                
            } axis2_skel_ModuleAdminService_getModuleInfo_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getModuleInfo|http://service.mgt.module.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getModuleInfo of the adb_getModuleInfo_t*
         *
         * @return adb_getModuleInfoResponse_t*
         */
        adb_getModuleInfoResponse_t* axis2_skel_ModuleAdminService_getModuleInfo(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getModuleInfo_t* _getModuleInfo,
                                          axis2_skel_ModuleAdminService_getModuleInfo_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_MODULEADMINSERVICE_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_MODULEADMINSERVICE_ERROR_NONE = AXIS2_SKEL_MODULEADMINSERVICE_ERROR_CODES_START,
        
        AXIS2_SKEL_MODULEADMINSERVICE_ENGAGEMODULEFORSERVICE_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_DISENGAGEMODULEFROMSYSTEM_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_DISENGAGEMODULEFORSERVICE_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_SETMODULEPARAMETERS_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_REMOVEMODULE_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_REMOVEMODULEPARAMETER_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_GETMODULEPARAMETERS_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_ENGAGEMODULEFOROPERATION_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_GLOBALLYENGAGEMODULE_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_ENGAGEMODULEFORSERVICEGROUP_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_LISTMODULESFOROPERATION_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_LISTMODULESFORSERVICE_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_DISENGAGEMODULEFORSERVICEGROUP_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_GLOBALLYDISENGAGEMODULE_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_LISTMODULESFORSERVICEGROUP_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_DISENGAGEMODULEFOROPERATION_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_GETMODULEINFO_FAULT_MODULEMGTEXCEPTION,
            AXIS2_SKEL_MODULEADMINSERVICE_ERROR_LAST
    } axis2_skel_ModuleAdminService_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

