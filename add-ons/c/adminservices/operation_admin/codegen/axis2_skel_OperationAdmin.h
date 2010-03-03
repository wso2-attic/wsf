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
     * axis2_skel_OperationAdmin.h
     *
     * This file was auto-generated from WSDL for "OperationAdmin|http://mgt.operation.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_OperationAdmin Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_listOperationPhaseHandlers.h"
    
     #include "adb_listOperationPhaseHandlersResponse.h"
    
     #include "adb_setPolicy.h"
    
     #include "adb_listOperationPhases.h"
    
     #include "adb_listOperationPhasesResponse.h"
    
     #include "adb_listControlOperations.h"
    
     #include "adb_listControlOperationsResponse.h"
    
     #include "adb_getDeclaredOperationParameters.h"
    
     #include "adb_getDeclaredOperationParametersResponse.h"
    
     #include "adb_listAllOperations.h"
    
     #include "adb_listAllOperationsResponse.h"
    
     #include "adb_configureMTOM.h"
    
     #include "adb_getOperationMetaData.h"
    
     #include "adb_getOperationMetaDataResponse.h"
    
     #include "adb_getOperationParameters.h"
    
     #include "adb_getOperationParametersResponse.h"
    
     #include "adb_removeOperationParameter.h"
    
     #include "adb_getOperationStatistics.h"
    
     #include "adb_getOperationStatisticsResponse.h"
    
     #include "adb_getPolicy.h"
    
     #include "adb_getPolicyResponse.h"
    
     #include "adb_listPublishedOperations.h"
    
     #include "adb_listPublishedOperationsResponse.h"
    
     #include "adb_setOperationParameters.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     

		 
        /**
         * auto generated function declaration
         * for "listOperationPhaseHandlers|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listOperationPhaseHandlers of the adb_listOperationPhaseHandlers_t*
         *
         * @return adb_listOperationPhaseHandlersResponse_t*
         */
        adb_listOperationPhaseHandlersResponse_t* axis2_skel_OperationAdmin_listOperationPhaseHandlers(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listOperationPhaseHandlers_t* _listOperationPhaseHandlers);


     

		 
        /**
         * auto generated function declaration
         * for "setPolicy|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setPolicy of the adb_setPolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_OperationAdmin_setPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setPolicy_t* _setPolicy);


     

		 
        /**
         * auto generated function declaration
         * for "listOperationPhases|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listOperationPhases of the adb_listOperationPhases_t*
         *
         * @return adb_listOperationPhasesResponse_t*
         */
        adb_listOperationPhasesResponse_t* axis2_skel_OperationAdmin_listOperationPhases(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listOperationPhases_t* _listOperationPhases);


     

		 
        /**
         * auto generated function declaration
         * for "listControlOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listControlOperations of the adb_listControlOperations_t*
         *
         * @return adb_listControlOperationsResponse_t*
         */
        adb_listControlOperationsResponse_t* axis2_skel_OperationAdmin_listControlOperations(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listControlOperations_t* _listControlOperations);


     

		 
        /**
         * auto generated function declaration
         * for "getDeclaredOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getDeclaredOperationParameters of the adb_getDeclaredOperationParameters_t*
         *
         * @return adb_getDeclaredOperationParametersResponse_t*
         */
        adb_getDeclaredOperationParametersResponse_t* axis2_skel_OperationAdmin_getDeclaredOperationParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getDeclaredOperationParameters_t* _getDeclaredOperationParameters);


     

		 
        /**
         * auto generated function declaration
         * for "listAllOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listAllOperations of the adb_listAllOperations_t*
         *
         * @return adb_listAllOperationsResponse_t*
         */
        adb_listAllOperationsResponse_t* axis2_skel_OperationAdmin_listAllOperations(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listAllOperations_t* _listAllOperations);


     

		 
        /**
         * auto generated function declaration
         * for "configureMTOM|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _configureMTOM of the adb_configureMTOM_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_OperationAdmin_configureMTOM(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_configureMTOM_t* _configureMTOM);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationMetaData|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationMetaData of the adb_getOperationMetaData_t*
         *
         * @return adb_getOperationMetaDataResponse_t*
         */
        adb_getOperationMetaDataResponse_t* axis2_skel_OperationAdmin_getOperationMetaData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationMetaData_t* _getOperationMetaData);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationParameters of the adb_getOperationParameters_t*
         *
         * @return adb_getOperationParametersResponse_t*
         */
        adb_getOperationParametersResponse_t* axis2_skel_OperationAdmin_getOperationParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationParameters_t* _getOperationParameters);


     

		 
        /**
         * auto generated function declaration
         * for "removeOperationParameter|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeOperationParameter of the adb_removeOperationParameter_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_OperationAdmin_removeOperationParameter(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeOperationParameter_t* _removeOperationParameter);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationStatistics|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationStatistics of the adb_getOperationStatistics_t*
         *
         * @return adb_getOperationStatisticsResponse_t*
         */
        adb_getOperationStatisticsResponse_t* axis2_skel_OperationAdmin_getOperationStatistics(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationStatistics_t* _getOperationStatistics);


     

		 
        /**
         * auto generated function declaration
         * for "getPolicy|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getPolicy of the adb_getPolicy_t*
         *
         * @return adb_getPolicyResponse_t*
         */
        adb_getPolicyResponse_t* axis2_skel_OperationAdmin_getPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getPolicy_t* _getPolicy);


     

		 
        /**
         * auto generated function declaration
         * for "listPublishedOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listPublishedOperations of the adb_listPublishedOperations_t*
         *
         * @return adb_listPublishedOperationsResponse_t*
         */
        adb_listPublishedOperationsResponse_t* axis2_skel_OperationAdmin_listPublishedOperations(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listPublishedOperations_t* _listPublishedOperations);


     

		 
        /**
         * auto generated function declaration
         * for "setOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setOperationParameters of the adb_setOperationParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_OperationAdmin_setOperationParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setOperationParameters_t* _setOperationParameters);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_OPERATIONADMIN_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_OPERATIONADMIN_ERROR_NONE = AXIS2_SKEL_OPERATIONADMIN_ERROR_CODES_START,
        
        AXIS2_SKEL_OPERATIONADMIN_ERROR_LAST
    } axis2_skel_OperationAdmin_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

