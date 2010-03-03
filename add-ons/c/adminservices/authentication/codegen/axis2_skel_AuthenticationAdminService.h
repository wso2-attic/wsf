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
     * axis2_skel_AuthenticationAdminService.h
     *
     * This file was auto-generated from WSDL for "AuthenticationAdminService|http://authentication.services.core.carbon.wso2.org" service
     * by the Apache Axis2/C version: SNAPSHOT  Built on : Jan 19, 2010 (01:46:42 IST)
     * axis2_skel_AuthenticationAdminService Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_AuthenticationExceptionE1.h"
    
     #include "adb_login.h"
    
     #include "adb_loginResponse.h"
    
     #include "adb_AuthenticationExceptionE1.h"
    
     #include "adb_getSystemPermissionOfUser.h"
    
     #include "adb_getSystemPermissionOfUserResponse.h"
    
     #include "adb_ExceptionE0.h"
    
     #include "adb_loginWithDelegation.h"
    
     #include "adb_loginWithDelegationResponse.h"
    
     #include "adb_AuthenticationExceptionE1.h"
    
     #include "adb_getUserPermissions.h"
    
     #include "adb_getUserPermissionsResponse.h"
    
     #include "adb_ExceptionE0.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "logout|http://authentication.services.core.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_AuthenticationExceptionE1_t* AuthenticationException;
                
            } axis2_skel_AuthenticationAdminService_logout_fault;
         

		 
        /**
         * auto generated function declaration
         * for "logout|http://authentication.services.core.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return 
         */
        axis2_status_t  axis2_skel_AuthenticationAdminService_logout(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_AuthenticationAdminService_logout_fault *fault);


     
            /**
             * the generated fault union for operation "login|http://authentication.services.core.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_AuthenticationExceptionE1_t* AuthenticationException;
                
            } axis2_skel_AuthenticationAdminService_login_fault;
         

		 
        /**
         * auto generated function declaration
         * for "login|http://authentication.services.core.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _login of the adb_login_t*
         *
         * @return adb_loginResponse_t*
         */
        adb_loginResponse_t* axis2_skel_AuthenticationAdminService_login(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_login_t* _login,
                                          axis2_skel_AuthenticationAdminService_login_fault *fault);


     
            /**
             * the generated fault union for operation "getSystemPermissionOfUser|http://authentication.services.core.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_AuthenticationAdminService_getSystemPermissionOfUser_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSystemPermissionOfUser|http://authentication.services.core.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getSystemPermissionOfUser of the adb_getSystemPermissionOfUser_t*
         *
         * @return adb_getSystemPermissionOfUserResponse_t*
         */
        adb_getSystemPermissionOfUserResponse_t* axis2_skel_AuthenticationAdminService_getSystemPermissionOfUser(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getSystemPermissionOfUser_t* _getSystemPermissionOfUser,
                                          axis2_skel_AuthenticationAdminService_getSystemPermissionOfUser_fault *fault);


     
            /**
             * the generated fault union for operation "loginWithDelegation|http://authentication.services.core.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_AuthenticationExceptionE1_t* AuthenticationException;
                
            } axis2_skel_AuthenticationAdminService_loginWithDelegation_fault;
         

		 
        /**
         * auto generated function declaration
         * for "loginWithDelegation|http://authentication.services.core.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _loginWithDelegation of the adb_loginWithDelegation_t*
         *
         * @return adb_loginWithDelegationResponse_t*
         */
        adb_loginWithDelegationResponse_t* axis2_skel_AuthenticationAdminService_loginWithDelegation(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_loginWithDelegation_t* _loginWithDelegation,
                                          axis2_skel_AuthenticationAdminService_loginWithDelegation_fault *fault);


     
            /**
             * the generated fault union for operation "getUserPermissions|http://authentication.services.core.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE0_t* Exception;
                
            } axis2_skel_AuthenticationAdminService_getUserPermissions_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getUserPermissions|http://authentication.services.core.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getUserPermissions of the adb_getUserPermissions_t*
         *
         * @return adb_getUserPermissionsResponse_t*
         */
        adb_getUserPermissionsResponse_t* axis2_skel_AuthenticationAdminService_getUserPermissions(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getUserPermissions_t* _getUserPermissions,
                                          axis2_skel_AuthenticationAdminService_getUserPermissions_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_ERROR_NONE = AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_ERROR_CODES_START,
        
        AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_LOGOUT_FAULT_AUTHENTICATIONEXCEPTION,
            AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_LOGIN_FAULT_AUTHENTICATIONEXCEPTION,
            AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_GETSYSTEMPERMISSIONOFUSER_FAULT_EXCEPTION,
            AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_LOGINWITHDELEGATION_FAULT_AUTHENTICATIONEXCEPTION,
            AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_GETUSERPERMISSIONS_FAULT_EXCEPTION,
            AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_ERROR_LAST
    } axis2_skel_AuthenticationAdminService_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

