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
     * axis2_skel_ServiceGroupAdmin.h
     *
     * This file was auto-generated from WSDL for "ServiceGroupAdmin|http://mgt.service.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_ServiceGroupAdmin Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_listServiceGroup.h"
    
     #include "adb_listServiceGroupResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_setServiceGroupParameters.h"
    
     #include "adb_getServiceGroupParameter.h"
    
     #include "adb_getServiceGroupParameterResponse.h"
    
     #include "adb_ServerExceptionE1.h"
    
     #include "adb_configureServiceGroupMTOM.h"
    
     #include "adb_configureServiceGroupMTOMResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_removeServiceGroupParameter.h"
    
     #include "adb_updateServiceGroupParamters.h"
    
     #include "adb_ServerExceptionE1.h"
    
     #include "adb_dumpAAR.h"
    
     #include "adb_dumpAARResponse.h"
    
     #include "adb_setServiceGroupParameter.h"
    
     #include "adb_updateServiceGroupParameter.h"
    
     #include "adb_ServerExceptionE1.h"
    
     #include "adb_getServiceGroupParameters.h"
    
     #include "adb_getServiceGroupParametersResponse.h"
    
     #include "adb_ServerExceptionE1.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "listServiceGroup|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceGroupAdmin_listServiceGroup_fault;
         

		 
        /**
         * auto generated function declaration
         * for "listServiceGroup|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listServiceGroup of the adb_listServiceGroup_t*
         *
         * @return adb_listServiceGroupResponse_t*
         */
        adb_listServiceGroupResponse_t* axis2_skel_ServiceGroupAdmin_listServiceGroup(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listServiceGroup_t* _listServiceGroup,
                                          axis2_skel_ServiceGroupAdmin_listServiceGroup_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "setServiceGroupParameters|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setServiceGroupParameters of the adb_setServiceGroupParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceGroupAdmin_setServiceGroupParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setServiceGroupParameters_t* _setServiceGroupParameters);


     
            /**
             * the generated fault union for operation "getServiceGroupParameter|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ServerExceptionE1_t* ServerException;
                
            } axis2_skel_ServiceGroupAdmin_getServiceGroupParameter_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getServiceGroupParameter|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceGroupParameter of the adb_getServiceGroupParameter_t*
         *
         * @return adb_getServiceGroupParameterResponse_t*
         */
        adb_getServiceGroupParameterResponse_t* axis2_skel_ServiceGroupAdmin_getServiceGroupParameter(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceGroupParameter_t* _getServiceGroupParameter,
                                          axis2_skel_ServiceGroupAdmin_getServiceGroupParameter_fault *fault);


     
            /**
             * the generated fault union for operation "configureServiceGroupMTOM|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_ServiceGroupAdmin_configureServiceGroupMTOM_fault;
         

		 
        /**
         * auto generated function declaration
         * for "configureServiceGroupMTOM|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _configureServiceGroupMTOM of the adb_configureServiceGroupMTOM_t*
         *
         * @return adb_configureServiceGroupMTOMResponse_t*
         */
        adb_configureServiceGroupMTOMResponse_t* axis2_skel_ServiceGroupAdmin_configureServiceGroupMTOM(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_configureServiceGroupMTOM_t* _configureServiceGroupMTOM,
                                          axis2_skel_ServiceGroupAdmin_configureServiceGroupMTOM_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "removeServiceGroupParameter|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeServiceGroupParameter of the adb_removeServiceGroupParameter_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceGroupAdmin_removeServiceGroupParameter(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_removeServiceGroupParameter_t* _removeServiceGroupParameter);


     
            /**
             * the generated fault union for operation "updateServiceGroupParamters|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ServerExceptionE1_t* ServerException;
                
            } axis2_skel_ServiceGroupAdmin_updateServiceGroupParamters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateServiceGroupParamters|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateServiceGroupParamters of the adb_updateServiceGroupParamters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceGroupAdmin_updateServiceGroupParamters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateServiceGroupParamters_t* _updateServiceGroupParamters,
                                          axis2_skel_ServiceGroupAdmin_updateServiceGroupParamters_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "dumpAAR|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _dumpAAR of the adb_dumpAAR_t*
         *
         * @return adb_dumpAARResponse_t*
         */
        adb_dumpAARResponse_t* axis2_skel_ServiceGroupAdmin_dumpAAR(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_dumpAAR_t* _dumpAAR);


     

		 
        /**
         * auto generated function declaration
         * for "setServiceGroupParameter|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setServiceGroupParameter of the adb_setServiceGroupParameter_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceGroupAdmin_setServiceGroupParameter(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setServiceGroupParameter_t* _setServiceGroupParameter);


     
            /**
             * the generated fault union for operation "updateServiceGroupParameter|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ServerExceptionE1_t* ServerException;
                
            } axis2_skel_ServiceGroupAdmin_updateServiceGroupParameter_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateServiceGroupParameter|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateServiceGroupParameter of the adb_updateServiceGroupParameter_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceGroupAdmin_updateServiceGroupParameter(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateServiceGroupParameter_t* _updateServiceGroupParameter,
                                          axis2_skel_ServiceGroupAdmin_updateServiceGroupParameter_fault *fault);


     

		 
        /**
         * auto generated function declaration
         * for "listServiceGroups|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ServiceGroupAdmin_listServiceGroups(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx);


     
            /**
             * the generated fault union for operation "getServiceGroupParameters|http://mgt.service.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ServerExceptionE1_t* ServerException;
                
            } axis2_skel_ServiceGroupAdmin_getServiceGroupParameters_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getServiceGroupParameters|http://mgt.service.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceGroupParameters of the adb_getServiceGroupParameters_t*
         *
         * @return adb_getServiceGroupParametersResponse_t*
         */
        adb_getServiceGroupParametersResponse_t* axis2_skel_ServiceGroupAdmin_getServiceGroupParameters(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceGroupParameters_t* _getServiceGroupParameters,
                                          axis2_skel_ServiceGroupAdmin_getServiceGroupParameters_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_SERVICEGROUPADMIN_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_SERVICEGROUPADMIN_ERROR_NONE = AXIS2_SKEL_SERVICEGROUPADMIN_ERROR_CODES_START,
        
        AXIS2_SKEL_SERVICEGROUPADMIN_LISTSERVICEGROUP_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEGROUPADMIN_GETSERVICEGROUPPARAMETER_FAULT_SERVEREXCEPTION,
            AXIS2_SKEL_SERVICEGROUPADMIN_CONFIGURESERVICEGROUPMTOM_FAULT_EXCEPTION,
            AXIS2_SKEL_SERVICEGROUPADMIN_UPDATESERVICEGROUPPARAMTERS_FAULT_SERVEREXCEPTION,
            AXIS2_SKEL_SERVICEGROUPADMIN_UPDATESERVICEGROUPPARAMETER_FAULT_SERVEREXCEPTION,
            AXIS2_SKEL_SERVICEGROUPADMIN_GETSERVICEGROUPPARAMETERS_FAULT_SERVEREXCEPTION,
            AXIS2_SKEL_SERVICEGROUPADMIN_ERROR_LAST
    } axis2_skel_ServiceGroupAdmin_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

