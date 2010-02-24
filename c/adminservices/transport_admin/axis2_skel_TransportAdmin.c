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
     * axis2_skel_TransportAdmin.c
     *
     * This file was auto-generated from WSDL for "TransportAdmin|http://mgt.transport.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_TransportAdmin Axis2/C skeleton for the axisService
     */

     #include "codegen/axis2_skel_TransportAdmin.h"

     

		 
        /**
         * auto generated function definition signature
         * for "updateServiceSpecificOutParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateServiceSpecificOutParameters of the adb_updateServiceSpecificOutParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_updateServiceSpecificOutParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_updateServiceSpecificOutParameters_t* _updateServiceSpecificOutParameters,
                                          axis2_skel_TransportAdmin_updateServiceSpecificOutParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getAllTransportData|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getAllTransportDataResponse_t*
         */
        adb_getAllTransportDataResponse_t* axis2_skel_TransportAdmin_getAllTransportData(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_TransportAdmin_getAllTransportData_fault *fault )
        {
			adb_getAllTransportDataResponse_t* response = NULL;

			response = adb_getAllTransportDataResponse_create(env);
			adb_getAllTransportDataResponse_add_return(response, env, NULL);

			return response;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getGloballyDefinedOutParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getGloballyDefinedOutParameters of the adb_getGloballyDefinedOutParameters_t*
         *
         * @return adb_getGloballyDefinedOutParametersResponse_t*
         */
        adb_getGloballyDefinedOutParametersResponse_t* axis2_skel_TransportAdmin_getGloballyDefinedOutParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getGloballyDefinedOutParameters_t* _getGloballyDefinedOutParameters,
                                          axis2_skel_TransportAdmin_getGloballyDefinedOutParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getGloballyDefinedOutParametersResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "addExposedTransports|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addExposedTransports of the adb_addExposedTransports_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_addExposedTransports(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_addExposedTransports_t* _addExposedTransports,
                                          axis2_skel_TransportAdmin_addExposedTransports_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "listTransports|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_listTransportsResponse_t*
         */
        adb_listTransportsResponse_t* axis2_skel_TransportAdmin_listTransports(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_listTransportsResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "listTransportsForService|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listTransportsForService of the adb_listTransportsForService_t*
         *
         * @return adb_listTransportsForServiceResponse_t*
         */
        adb_listTransportsForServiceResponse_t* axis2_skel_TransportAdmin_listTransportsForService(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_listTransportsForService_t* _listTransportsForService,
                                          axis2_skel_TransportAdmin_listTransportsForService_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_listTransportsForServiceResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getServiceSpecificInParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceSpecificInParameters of the adb_getServiceSpecificInParameters_t*
         *
         * @return adb_getServiceSpecificInParametersResponse_t*
         */
        adb_getServiceSpecificInParametersResponse_t* axis2_skel_TransportAdmin_getServiceSpecificInParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceSpecificInParameters_t* _getServiceSpecificInParameters,
                                          axis2_skel_TransportAdmin_getServiceSpecificInParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getServiceSpecificInParametersResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "removeExposedTransports|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeExposedTransports of the adb_removeExposedTransports_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_removeExposedTransports(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_removeExposedTransports_t* _removeExposedTransports,
                                          axis2_skel_TransportAdmin_removeExposedTransports_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "updateServiceSpecificInParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateServiceSpecificInParameters of the adb_updateServiceSpecificInParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_updateServiceSpecificInParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_updateServiceSpecificInParameters_t* _updateServiceSpecificInParameters,
                                          axis2_skel_TransportAdmin_updateServiceSpecificInParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "disableSender|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disableSender of the adb_disableSender_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_disableSender(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_disableSender_t* _disableSender,
                                          axis2_skel_TransportAdmin_disableSender_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getGloballyDefinedInParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getGloballyDefinedInParameters of the adb_getGloballyDefinedInParameters_t*
         *
         * @return adb_getGloballyDefinedInParametersResponse_t*
         */
        adb_getGloballyDefinedInParametersResponse_t* axis2_skel_TransportAdmin_getGloballyDefinedInParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getGloballyDefinedInParameters_t* _getGloballyDefinedInParameters,
                                          axis2_skel_TransportAdmin_getGloballyDefinedInParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getGloballyDefinedInParametersResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "disableListener|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _disableListener of the adb_disableListener_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_disableListener(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_disableListener_t* _disableListener,
                                          axis2_skel_TransportAdmin_disableListener_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "listExposedTransports|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listExposedTransports of the adb_listExposedTransports_t*
         *
         * @return adb_listExposedTransportsResponse_t*
         */
        adb_listExposedTransportsResponse_t* axis2_skel_TransportAdmin_listExposedTransports(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_listExposedTransports_t* _listExposedTransports,
                                          axis2_skel_TransportAdmin_listExposedTransports_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_listExposedTransportsResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getServiceSpecificOutParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceSpecificOutParameters of the adb_getServiceSpecificOutParameters_t*
         *
         * @return adb_getServiceSpecificOutParametersResponse_t*
         */
        adb_getServiceSpecificOutParametersResponse_t* axis2_skel_TransportAdmin_getServiceSpecificOutParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceSpecificOutParameters_t* _getServiceSpecificOutParameters,
                                          axis2_skel_TransportAdmin_getServiceSpecificOutParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getServiceSpecificOutParametersResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "updateGloballyDefinedOutParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateGloballyDefinedOutParameters of the adb_updateGloballyDefinedOutParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_updateGloballyDefinedOutParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_updateGloballyDefinedOutParameters_t* _updateGloballyDefinedOutParameters,
                                          axis2_skel_TransportAdmin_updateGloballyDefinedOutParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getTransportDetails|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getTransportDetails of the adb_getTransportDetails_t*
         *
         * @return adb_getTransportDetailsResponse_t*
         */
        adb_getTransportDetailsResponse_t* axis2_skel_TransportAdmin_getTransportDetails(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getTransportDetails_t* _getTransportDetails,
                                          axis2_skel_TransportAdmin_getTransportDetails_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getTransportDetailsResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "updateGloballyDefinedInParameters|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateGloballyDefinedInParameters of the adb_updateGloballyDefinedInParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_TransportAdmin_updateGloballyDefinedInParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_updateGloballyDefinedInParameters_t* _updateGloballyDefinedInParameters,
                                          axis2_skel_TransportAdmin_updateGloballyDefinedInParameters_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "dependenciesAvailable|http://mgt.transport.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _dependenciesAvailable of the adb_dependenciesAvailable_t*
         *
         * @return adb_dependenciesAvailableResponse_t*
         */
        adb_dependenciesAvailableResponse_t* axis2_skel_TransportAdmin_dependenciesAvailable(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_dependenciesAvailable_t* _dependenciesAvailable,
                                          axis2_skel_TransportAdmin_dependenciesAvailable_fault *fault )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_dependenciesAvailableResponse_t*)NULL;
        }
     

