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
     * axis2_skel_ServiceAdmin.h
     *
     * This file was auto-generated from WSDL for "ServiceAdmin|http://mgt.service.carbon.wso2.org" service
     * by the Apache Axis2/C version: SNAPSHOT  Built on : Jan 19, 2010 (01:46:42 IST)
     * axis2_skel_ServiceAdmin Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_startService.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getExposedTransports.h"
    
     #include "adb_getExposedTransportsResponse.h"
    
     #include "adb_listServiceGroup.h"
    
     #include "adb_listServiceGroupResponse.h"
    
     #include "adb_addTransportBinding.h"
    
     #include "adb_addTransportBindingResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getWSDL.h"
    
     #include "adb_getWSDLResponse.h"
    
     #include "adb_getNumberOfFaultyServicesResponse.h"
    
     #include "adb_configureMTOM.h"
    
     #include "adb_setServicePolicy.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getPolicy.h"
    
     #include "adb_getPolicyResponse.h"
    
     #include "adb_getFaultyServiceArchives.h"
    
     #include "adb_getFaultyServiceArchivesResponse.h"
    
     #include "adb_addPoliciesToService.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getServiceParameters.h"
    
     #include "adb_getServiceParametersResponse.h"
    
     #include "adb_ServerExceptionE1.h"
    
     #include "adb_setBindingOperationMessagePolicy.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_setBindingPolicy.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_removeServicePoliciesByNamespace.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_setBindingOperationPolicy.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_setModulePolicy.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getBindingOperationMessagePolicy.h"
    
     #include "adb_getBindingOperationMessagePolicyResponse.h"
    
     #include "adb_changeServiceState.h"
    
     #include "adb_setServiceParameters.h"
    
     #include "adb_getOperationMessagePolicy.h"
    
     #include "adb_getOperationMessagePolicyResponse.h"
    
     #include "adb_getNumberOfActiveServicesResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getServiceData.h"
    
     #include "adb_getServiceDataResponse.h"
    
     #include "adb_removeTransportBinding.h"
    
     #include "adb_removeTransportBindingResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getPolicies.h"
    
     #include "adb_getPoliciesResponse.h"
    
     #include "adb_removeServiceParameter.h"
    
     #include "adb_getBindingOperationPolicy.h"
    
     #include "adb_getBindingOperationPolicyResponse.h"
    
     #include "adb_deleteServiceGroups.h"
    
     #include "adb_getNumberOfInactiveServicesResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_setServiceOperationPolicy.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_deleteFaultyServiceGroup.h"
    
     #include "adb_deleteFaultyServiceGroupResponse.h"
    
     #include "adb_engageModuleToService.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_deleteFaultyServiceGroups.h"
    
     #include "adb_removeBindingPolicy.h"
    
     #include "adb_ServerExceptionE1.h"
    
     #include "adb_getModulePolicy.h"
    
     #include "adb_getModulePolicyResponse.h"
    
     #include "adb_setPolicy.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_listServiceGroups.h"
    
     #include "adb_listServiceGroupsResponse.h"
    
     #include "adb_setServiceOperationMessagePolicy.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getBindingPolicy.h"
    
     #include "adb_getBindingPolicyResponse.h"
    
     #include "adb_getServiceBindings.h"
    
     #include "adb_getServiceBindingsResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_stopService.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getOperationPolicy.h"
    
     #include "adb_getOperationPolicyResponse.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "startService|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_startService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "startService|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _startService of the adb_startService_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_startService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_startService_t* _startService,
                                          axis2_skel_ServiceAdmin_startService_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getExposedTransports|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getExposedTransports of the adb_getExposedTransports_t*
         *
         * @return adb_getExposedTransportsResponse_t*
         */
        adb_getExposedTransportsResponse_t* axis2_skel_ServiceAdmin_getExposedTransports(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getExposedTransports_t* _getExposedTransports);


     

		 
        /**
         * auto generated function declaration
         * for "listServiceGroup|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listServiceGroup of the adb_listServiceGroup_t*
         *
         * @return adb_listServiceGroupResponse_t*
         */
        adb_listServiceGroupResponse_t* axis2_skel_ServiceAdmin_listServiceGroup(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listServiceGroup_t* _listServiceGroup);


     
            /**
             * the generated fault union for operation "addTransportBinding|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_addTransportBinding_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addTransportBinding|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addTransportBinding of the adb_addTransportBinding_t*
         *
         * @return adb_addTransportBindingResponse_t*
         */
        adb_addTransportBindingResponse_t* axis2_skel_ServiceAdmin_addTransportBinding(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addTransportBinding_t* _addTransportBinding,
                                          axis2_skel_ServiceAdmin_addTransportBinding_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getWSDL|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getWSDL of the adb_getWSDL_t*
         *
         * @return adb_getWSDLResponse_t*
         */
        adb_getWSDLResponse_t* axis2_skel_ServiceAdmin_getWSDL(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getWSDL_t* _getWSDL);


     

		 
        /**
         * auto generated function declaration
         * for "getNumberOfFaultyServices|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getNumberOfFaultyServicesResponse_t*
         */
        adb_getNumberOfFaultyServicesResponse_t* axis2_skel_ServiceAdmin_getNumberOfFaultyServices(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "configureMTOM|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _configureMTOM of the adb_configureMTOM_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_configureMTOM(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_configureMTOM_t* _configureMTOM);


     
            /**
             * the generated fault union for operation "setServicePolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_setServicePolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setServicePolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setServicePolicy of the adb_setServicePolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setServicePolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setServicePolicy_t* _setServicePolicy,
                                          axis2_skel_ServiceAdmin_setServicePolicy_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getPolicy of the adb_getPolicy_t*
         *
         * @return adb_getPolicyResponse_t*
         */
        adb_getPolicyResponse_t* axis2_skel_ServiceAdmin_getPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getPolicy_t* _getPolicy);


     

		 
        /**
         * auto generated function declaration
         * for "getFaultyServiceArchives|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getFaultyServiceArchives of the adb_getFaultyServiceArchives_t*
         *
         * @return adb_getFaultyServiceArchivesResponse_t*
         */
        adb_getFaultyServiceArchivesResponse_t* axis2_skel_ServiceAdmin_getFaultyServiceArchives(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getFaultyServiceArchives_t* _getFaultyServiceArchives);


     
            /**
             * the generated fault union for operation "addPoliciesToService|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_addPoliciesToService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addPoliciesToService|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addPoliciesToService of the adb_addPoliciesToService_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_addPoliciesToService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addPoliciesToService_t* _addPoliciesToService,
                                          axis2_skel_ServiceAdmin_addPoliciesToService_fault *fault);


     
            /**
             * the generated fault union for operation "getServiceParameters|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ServerExceptionE1_t* ServerException;
                
            } axis2_skel_ServiceAdmin_getServiceParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getServiceParameters|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceParameters of the adb_getServiceParameters_t*
         *
         * @return adb_getServiceParametersResponse_t*
         */
        adb_getServiceParametersResponse_t* axis2_skel_ServiceAdmin_getServiceParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceParameters_t* _getServiceParameters,
                                          axis2_skel_ServiceAdmin_getServiceParameters_fault *fault);


     
            /**
             * the generated fault union for operation "setBindingOperationMessagePolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_setBindingOperationMessagePolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setBindingOperationMessagePolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setBindingOperationMessagePolicy of the adb_setBindingOperationMessagePolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setBindingOperationMessagePolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setBindingOperationMessagePolicy_t* _setBindingOperationMessagePolicy,
                                          axis2_skel_ServiceAdmin_setBindingOperationMessagePolicy_fault *fault);


     
            /**
             * the generated fault union for operation "setBindingPolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_setBindingPolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setBindingPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setBindingPolicy of the adb_setBindingPolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setBindingPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setBindingPolicy_t* _setBindingPolicy,
                                          axis2_skel_ServiceAdmin_setBindingPolicy_fault *fault);


     
            /**
             * the generated fault union for operation "removeServicePoliciesByNamespace|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_removeServicePoliciesByNamespace_fault;
         

		 
        /**
         * auto generated function declaration
         * for "removeServicePoliciesByNamespace|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeServicePoliciesByNamespace of the adb_removeServicePoliciesByNamespace_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_removeServicePoliciesByNamespace(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeServicePoliciesByNamespace_t* _removeServicePoliciesByNamespace,
                                          axis2_skel_ServiceAdmin_removeServicePoliciesByNamespace_fault *fault);


     
            /**
             * the generated fault union for operation "setBindingOperationPolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_setBindingOperationPolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setBindingOperationPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setBindingOperationPolicy of the adb_setBindingOperationPolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setBindingOperationPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setBindingOperationPolicy_t* _setBindingOperationPolicy,
                                          axis2_skel_ServiceAdmin_setBindingOperationPolicy_fault *fault);


     
            /**
             * the generated fault union for operation "setModulePolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_setModulePolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setModulePolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setModulePolicy of the adb_setModulePolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setModulePolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setModulePolicy_t* _setModulePolicy,
                                          axis2_skel_ServiceAdmin_setModulePolicy_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getBindingOperationMessagePolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getBindingOperationMessagePolicy of the adb_getBindingOperationMessagePolicy_t*
         *
         * @return adb_getBindingOperationMessagePolicyResponse_t*
         */
        adb_getBindingOperationMessagePolicyResponse_t* axis2_skel_ServiceAdmin_getBindingOperationMessagePolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getBindingOperationMessagePolicy_t* _getBindingOperationMessagePolicy);


     

		 
        /**
         * auto generated function declaration
         * for "changeServiceState|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _changeServiceState of the adb_changeServiceState_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_changeServiceState(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_changeServiceState_t* _changeServiceState);


     

		 
        /**
         * auto generated function declaration
         * for "setServiceParameters|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setServiceParameters of the adb_setServiceParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setServiceParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setServiceParameters_t* _setServiceParameters);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationMessagePolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationMessagePolicy of the adb_getOperationMessagePolicy_t*
         *
         * @return adb_getOperationMessagePolicyResponse_t*
         */
        adb_getOperationMessagePolicyResponse_t* axis2_skel_ServiceAdmin_getOperationMessagePolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationMessagePolicy_t* _getOperationMessagePolicy);


     
            /**
             * the generated fault union for operation "getNumberOfActiveServices|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_getNumberOfActiveServices_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getNumberOfActiveServices|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getNumberOfActiveServicesResponse_t*
         */
        adb_getNumberOfActiveServicesResponse_t* axis2_skel_ServiceAdmin_getNumberOfActiveServices(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ServiceAdmin_getNumberOfActiveServices_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getServiceData|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceData of the adb_getServiceData_t*
         *
         * @return adb_getServiceDataResponse_t*
         */
        adb_getServiceDataResponse_t* axis2_skel_ServiceAdmin_getServiceData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceData_t* _getServiceData);


     
            /**
             * the generated fault union for operation "removeTransportBinding|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_removeTransportBinding_fault;
         

		 
        /**
         * auto generated function declaration
         * for "removeTransportBinding|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeTransportBinding of the adb_removeTransportBinding_t*
         *
         * @return adb_removeTransportBindingResponse_t*
         */
        adb_removeTransportBindingResponse_t* axis2_skel_ServiceAdmin_removeTransportBinding(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeTransportBinding_t* _removeTransportBinding,
                                          axis2_skel_ServiceAdmin_removeTransportBinding_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getPolicies|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getPolicies of the adb_getPolicies_t*
         *
         * @return adb_getPoliciesResponse_t*
         */
        adb_getPoliciesResponse_t* axis2_skel_ServiceAdmin_getPolicies(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getPolicies_t* _getPolicies);


     

		 
        /**
         * auto generated function declaration
         * for "removeServiceParameter|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeServiceParameter of the adb_removeServiceParameter_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_removeServiceParameter(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeServiceParameter_t* _removeServiceParameter);


     

		 
        /**
         * auto generated function declaration
         * for "getBindingOperationPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getBindingOperationPolicy of the adb_getBindingOperationPolicy_t*
         *
         * @return adb_getBindingOperationPolicyResponse_t*
         */
        adb_getBindingOperationPolicyResponse_t* axis2_skel_ServiceAdmin_getBindingOperationPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getBindingOperationPolicy_t* _getBindingOperationPolicy);


     

		 
        /**
         * auto generated function declaration
         * for "deleteServiceGroups|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _deleteServiceGroups of the adb_deleteServiceGroups_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_deleteServiceGroups(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_deleteServiceGroups_t* _deleteServiceGroups);


     
            /**
             * the generated fault union for operation "getNumberOfInactiveServices|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_getNumberOfInactiveServices_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getNumberOfInactiveServices|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getNumberOfInactiveServicesResponse_t*
         */
        adb_getNumberOfInactiveServicesResponse_t* axis2_skel_ServiceAdmin_getNumberOfInactiveServices(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ServiceAdmin_getNumberOfInactiveServices_fault *fault);


     
            /**
             * the generated fault union for operation "setServiceOperationPolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_setServiceOperationPolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setServiceOperationPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setServiceOperationPolicy of the adb_setServiceOperationPolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setServiceOperationPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setServiceOperationPolicy_t* _setServiceOperationPolicy,
                                          axis2_skel_ServiceAdmin_setServiceOperationPolicy_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "deleteFaultyServiceGroup|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _deleteFaultyServiceGroup of the adb_deleteFaultyServiceGroup_t*
         *
         * @return adb_deleteFaultyServiceGroupResponse_t*
         */
        adb_deleteFaultyServiceGroupResponse_t* axis2_skel_ServiceAdmin_deleteFaultyServiceGroup(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_deleteFaultyServiceGroup_t* _deleteFaultyServiceGroup);


     
            /**
             * the generated fault union for operation "engageModuleToService|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_engageModuleToService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "engageModuleToService|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _engageModuleToService of the adb_engageModuleToService_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_engageModuleToService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_engageModuleToService_t* _engageModuleToService,
                                          axis2_skel_ServiceAdmin_engageModuleToService_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "deleteFaultyServiceGroups|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _deleteFaultyServiceGroups of the adb_deleteFaultyServiceGroups_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_deleteFaultyServiceGroups(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_deleteFaultyServiceGroups_t* _deleteFaultyServiceGroups);


     
            /**
             * the generated fault union for operation "removeBindingPolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ServerExceptionE1_t* ServerException;
                
            } axis2_skel_ServiceAdmin_removeBindingPolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "removeBindingPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeBindingPolicy of the adb_removeBindingPolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_removeBindingPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeBindingPolicy_t* _removeBindingPolicy,
                                          axis2_skel_ServiceAdmin_removeBindingPolicy_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "deleteAllFaultyServiceGroups|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_deleteAllFaultyServiceGroups(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "deleteAllNonAdminServiceGroups|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_deleteAllNonAdminServiceGroups(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     

		 
        /**
         * auto generated function declaration
         * for "getModulePolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getModulePolicy of the adb_getModulePolicy_t*
         *
         * @return adb_getModulePolicyResponse_t*
         */
        adb_getModulePolicyResponse_t* axis2_skel_ServiceAdmin_getModulePolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getModulePolicy_t* _getModulePolicy);


     
            /**
             * the generated fault union for operation "setPolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_setPolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setPolicy of the adb_setPolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setPolicy_t* _setPolicy,
                                          axis2_skel_ServiceAdmin_setPolicy_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "listServiceGroups|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listServiceGroups of the adb_listServiceGroups_t*
         *
         * @return adb_listServiceGroupsResponse_t*
         */
        adb_listServiceGroupsResponse_t* axis2_skel_ServiceAdmin_listServiceGroups(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listServiceGroups_t* _listServiceGroups);


     
            /**
             * the generated fault union for operation "setServiceOperationMessagePolicy|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_setServiceOperationMessagePolicy_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setServiceOperationMessagePolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setServiceOperationMessagePolicy of the adb_setServiceOperationMessagePolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_setServiceOperationMessagePolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setServiceOperationMessagePolicy_t* _setServiceOperationMessagePolicy,
                                          axis2_skel_ServiceAdmin_setServiceOperationMessagePolicy_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getBindingPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getBindingPolicy of the adb_getBindingPolicy_t*
         *
         * @return adb_getBindingPolicyResponse_t*
         */
        adb_getBindingPolicyResponse_t* axis2_skel_ServiceAdmin_getBindingPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getBindingPolicy_t* _getBindingPolicy);


     
            /**
             * the generated fault union for operation "getServiceBindings|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_getServiceBindings_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getServiceBindings|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceBindings of the adb_getServiceBindings_t*
         *
         * @return adb_getServiceBindingsResponse_t*
         */
        adb_getServiceBindingsResponse_t* axis2_skel_ServiceAdmin_getServiceBindings(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceBindings_t* _getServiceBindings,
                                          axis2_skel_ServiceAdmin_getServiceBindings_fault *fault);


     
            /**
             * the generated fault union for operation "stopService|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceAdmin_stopService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "stopService|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _stopService of the adb_stopService_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceAdmin_stopService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_stopService_t* _stopService,
                                          axis2_skel_ServiceAdmin_stopService_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "getOperationPolicy|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationPolicy of the adb_getOperationPolicy_t*
         *
         * @return adb_getOperationPolicyResponse_t*
         */
        adb_getOperationPolicyResponse_t* axis2_skel_ServiceAdmin_getOperationPolicy(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationPolicy_t* _getOperationPolicy);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_SERVICEADMIN_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_SERVICEADMIN_ERROR_NONE = AXIS2_SKEL_SERVICEADMIN_ERROR_CODES_START,
        
        AXIS2_SKEL_SERVICEADMIN_STARTSERVICE_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_ADDTRANSPORTBINDING_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_SETSERVICEPOLICY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_ADDPOLICIESTOSERVICE_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_GETSERVICEPARAMETERS_FAULT_SERVEREXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_SETBINDINGOPERATIONMESSAGEPOLICY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_SETBINDINGPOLICY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_REMOVESERVICEPOLICIESBYNAMESPACE_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_SETBINDINGOPERATIONPOLICY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_SETMODULEPOLICY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_GETNUMBEROFACTIVESERVICES_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_REMOVETRANSPORTBINDING_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_GETNUMBEROFINACTIVESERVICES_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_SETSERVICEOPERATIONPOLICY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_ENGAGEMODULETOSERVICE_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_REMOVEBINDINGPOLICY_FAULT_SERVEREXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_SETPOLICY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_SETSERVICEOPERATIONMESSAGEPOLICY_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_GETSERVICEBINDINGS_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_STOPSERVICE_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEADMIN_ERROR_LAST
    } axis2_skel_ServiceAdmin_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

