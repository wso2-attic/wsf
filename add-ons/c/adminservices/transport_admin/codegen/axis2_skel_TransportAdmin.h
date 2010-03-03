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
     * axis2_skel_TransportAdmin.h
     *
     * This file was auto-generated from WSDL for "TransportAdmin|http://mgt.transport.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_TransportAdmin Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_updateServiceSpecificOutParameters.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getAllTransportDataResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getGloballyDefinedOutParameters.h"
    
     #include "adb_getGloballyDefinedOutParametersResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_addExposedTransports.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_listTransportsResponse.h"
    
     #include "adb_listTransportsForService.h"
    
     #include "adb_listTransportsForServiceResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getServiceSpecificInParameters.h"
    
     #include "adb_getServiceSpecificInParametersResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_removeExposedTransports.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_updateServiceSpecificInParameters.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_disableSender.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getGloballyDefinedInParameters.h"
    
     #include "adb_getGloballyDefinedInParametersResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_disableListener.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_listExposedTransports.h"
    
     #include "adb_listExposedTransportsResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getServiceSpecificOutParameters.h"
    
     #include "adb_getServiceSpecificOutParametersResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_updateGloballyDefinedOutParameters.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_getTransportDetails.h"
    
     #include "adb_getTransportDetailsResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_updateGloballyDefinedInParameters.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_dependenciesAvailable.h"
    
     #include "adb_dependenciesAvailableResponse.h"
    
     #include "adb_ExceptionE0.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "updateServiceSpecificOutParameters|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_updateServiceSpecificOutParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateServiceSpecificOutParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateServiceSpecificOutParameters of the adb_updateServiceSpecificOutParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_updateServiceSpecificOutParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateServiceSpecificOutParameters_t* _updateServiceSpecificOutParameters,
                                          axis2_skel_TransportAdmin_updateServiceSpecificOutParameters_fault *fault);


     
            /**
             * the generated fault union for operation "getAllTransportData|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_getAllTransportData_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getAllTransportData|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getAllTransportDataResponse_t*
         */
        adb_getAllTransportDataResponse_t* axis2_skel_TransportAdmin_getAllTransportData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_TransportAdmin_getAllTransportData_fault *fault);


     
            /**
             * the generated fault union for operation "getGloballyDefinedOutParameters|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_getGloballyDefinedOutParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getGloballyDefinedOutParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getGloballyDefinedOutParameters of the adb_getGloballyDefinedOutParameters_t*
         *
         * @return adb_getGloballyDefinedOutParametersResponse_t*
         */
        adb_getGloballyDefinedOutParametersResponse_t* axis2_skel_TransportAdmin_getGloballyDefinedOutParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getGloballyDefinedOutParameters_t* _getGloballyDefinedOutParameters,
                                          axis2_skel_TransportAdmin_getGloballyDefinedOutParameters_fault *fault);


     
            /**
             * the generated fault union for operation "addExposedTransports|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_addExposedTransports_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addExposedTransports|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addExposedTransports of the adb_addExposedTransports_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_addExposedTransports(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addExposedTransports_t* _addExposedTransports,
                                          axis2_skel_TransportAdmin_addExposedTransports_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "listTransports|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_listTransportsResponse_t*
         */
        adb_listTransportsResponse_t* axis2_skel_TransportAdmin_listTransports(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     
            /**
             * the generated fault union for operation "listTransportsForService|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_listTransportsForService_fault;
         

		 
        /**
         * auto generated function declaration
         * for "listTransportsForService|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listTransportsForService of the adb_listTransportsForService_t*
         *
         * @return adb_listTransportsForServiceResponse_t*
         */
        adb_listTransportsForServiceResponse_t* axis2_skel_TransportAdmin_listTransportsForService(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listTransportsForService_t* _listTransportsForService,
                                          axis2_skel_TransportAdmin_listTransportsForService_fault *fault);


     
            /**
             * the generated fault union for operation "getServiceSpecificInParameters|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_getServiceSpecificInParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getServiceSpecificInParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceSpecificInParameters of the adb_getServiceSpecificInParameters_t*
         *
         * @return adb_getServiceSpecificInParametersResponse_t*
         */
        adb_getServiceSpecificInParametersResponse_t* axis2_skel_TransportAdmin_getServiceSpecificInParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceSpecificInParameters_t* _getServiceSpecificInParameters,
                                          axis2_skel_TransportAdmin_getServiceSpecificInParameters_fault *fault);


     
            /**
             * the generated fault union for operation "removeExposedTransports|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_removeExposedTransports_fault;
         

		 
        /**
         * auto generated function declaration
         * for "removeExposedTransports|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeExposedTransports of the adb_removeExposedTransports_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_removeExposedTransports(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeExposedTransports_t* _removeExposedTransports,
                                          axis2_skel_TransportAdmin_removeExposedTransports_fault *fault);


     
            /**
             * the generated fault union for operation "updateServiceSpecificInParameters|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_updateServiceSpecificInParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateServiceSpecificInParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateServiceSpecificInParameters of the adb_updateServiceSpecificInParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_updateServiceSpecificInParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                                          axis2_skel_TransportAdmin_updateServiceSpecificInParameters_fault *fault);


     
            /**
             * the generated fault union for operation "disableSender|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_disableSender_fault;
         

		 
        /**
         * auto generated function declaration
         * for "disableSender|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disableSender of the adb_disableSender_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_disableSender(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_disableSender_t* _disableSender,
                                          axis2_skel_TransportAdmin_disableSender_fault *fault);


     
            /**
             * the generated fault union for operation "getGloballyDefinedInParameters|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_getGloballyDefinedInParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getGloballyDefinedInParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getGloballyDefinedInParameters of the adb_getGloballyDefinedInParameters_t*
         *
         * @return adb_getGloballyDefinedInParametersResponse_t*
         */
        adb_getGloballyDefinedInParametersResponse_t* axis2_skel_TransportAdmin_getGloballyDefinedInParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getGloballyDefinedInParameters_t* _getGloballyDefinedInParameters,
                                          axis2_skel_TransportAdmin_getGloballyDefinedInParameters_fault *fault);


     
            /**
             * the generated fault union for operation "disableListener|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_disableListener_fault;
         

		 
        /**
         * auto generated function declaration
         * for "disableListener|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disableListener of the adb_disableListener_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_disableListener(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_disableListener_t* _disableListener,
                                          axis2_skel_TransportAdmin_disableListener_fault *fault);


     
            /**
             * the generated fault union for operation "listExposedTransports|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_listExposedTransports_fault;
         

		 
        /**
         * auto generated function declaration
         * for "listExposedTransports|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listExposedTransports of the adb_listExposedTransports_t*
         *
         * @return adb_listExposedTransportsResponse_t*
         */
        adb_listExposedTransportsResponse_t* axis2_skel_TransportAdmin_listExposedTransports(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listExposedTransports_t* _listExposedTransports,
                                          axis2_skel_TransportAdmin_listExposedTransports_fault *fault);


     
            /**
             * the generated fault union for operation "getServiceSpecificOutParameters|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_getServiceSpecificOutParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getServiceSpecificOutParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceSpecificOutParameters of the adb_getServiceSpecificOutParameters_t*
         *
         * @return adb_getServiceSpecificOutParametersResponse_t*
         */
        adb_getServiceSpecificOutParametersResponse_t* axis2_skel_TransportAdmin_getServiceSpecificOutParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceSpecificOutParameters_t* _getServiceSpecificOutParameters,
                                          axis2_skel_TransportAdmin_getServiceSpecificOutParameters_fault *fault);


     
            /**
             * the generated fault union for operation "updateGloballyDefinedOutParameters|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_updateGloballyDefinedOutParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateGloballyDefinedOutParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateGloballyDefinedOutParameters of the adb_updateGloballyDefinedOutParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_updateGloballyDefinedOutParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateGloballyDefinedOutParameters_t* _updateGloballyDefinedOutParameters,
                                          axis2_skel_TransportAdmin_updateGloballyDefinedOutParameters_fault *fault);


     
            /**
             * the generated fault union for operation "getTransportDetails|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_getTransportDetails_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getTransportDetails|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getTransportDetails of the adb_getTransportDetails_t*
         *
         * @return adb_getTransportDetailsResponse_t*
         */
        adb_getTransportDetailsResponse_t* axis2_skel_TransportAdmin_getTransportDetails(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getTransportDetails_t* _getTransportDetails,
                                          axis2_skel_TransportAdmin_getTransportDetails_fault *fault);


     
            /**
             * the generated fault union for operation "updateGloballyDefinedInParameters|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_updateGloballyDefinedInParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateGloballyDefinedInParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateGloballyDefinedInParameters of the adb_updateGloballyDefinedInParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_updateGloballyDefinedInParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateGloballyDefinedInParameters_t* _updateGloballyDefinedInParameters,
                                          axis2_skel_TransportAdmin_updateGloballyDefinedInParameters_fault *fault);


     
            /**
             * the generated fault union for operation "dependenciesAvailable|http://mgt.transport.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_TransportAdmin_dependenciesAvailable_fault;
         

		 
        /**
         * auto generated function declaration
         * for "dependenciesAvailable|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _dependenciesAvailable of the adb_dependenciesAvailable_t*
         *
         * @return adb_dependenciesAvailableResponse_t*
         */
        adb_dependenciesAvailableResponse_t* axis2_skel_TransportAdmin_dependenciesAvailable(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_dependenciesAvailable_t* _dependenciesAvailable,
                                          axis2_skel_TransportAdmin_dependenciesAvailable_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_TRANSPORTADMIN_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_TRANSPORTADMIN_ERROR_NONE = AXIS2_SKEL_TRANSPORTADMIN_ERROR_CODES_START,
        
        AXIS2_SKEL_TRANSPORTADMIN_UPDATESERVICESPECIFICOUTPARAMETERS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_GETALLTRANSPORTDATA_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_GETGLOBALLYDEFINEDOUTPARAMETERS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_ADDEXPOSEDTRANSPORTS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_LISTTRANSPORTSFORSERVICE_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_GETSERVICESPECIFICINPARAMETERS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_REMOVEEXPOSEDTRANSPORTS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_UPDATESERVICESPECIFICINPARAMETERS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_DISABLESENDER_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_GETGLOBALLYDEFINEDINPARAMETERS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_DISABLELISTENER_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_LISTEXPOSEDTRANSPORTS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_GETSERVICESPECIFICOUTPARAMETERS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_UPDATEGLOBALLYDEFINEDOUTPARAMETERS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_GETTRANSPORTDETAILS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_UPDATEGLOBALLYDEFINEDINPARAMETERS_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_DEPENDENCIESAVAILABLE_FAULT_EXCEPTION,
            AXIS2_SKEL_TRANSPORTADMIN_ERROR_LAST
    } axis2_skel_TransportAdmin_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

