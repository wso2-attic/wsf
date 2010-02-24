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
     * axis2_skel_UserManagementService.h
     *
     * This file was auto-generated from WSDL for "UserManagementService|http://service.mgt.user.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_UserManagementService Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_deleteUserFromInternalStore.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_addRoleToInternalStore.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_deleteSpecialInternalRole.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getExternalUsersResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateExternalUserStoreConfig.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_addSystemPermissionsToRole.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getInternalRolesResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getAllRolesNamesResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getExternalGroupsResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateRolesofResource.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_listInternalUsers.h"
    
     #include "adb_listInternalUsersResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_testConnectionResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateUsersOfSpecialInternalRole.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getSystemPermissionsOfSpecialInternalRole.h"
    
     #include "adb_getSystemPermissionsOfSpecialInternalRoleResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_addRolesToResource.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_deleteRoleFromInternalStore.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getUserRoles.h"
    
     #include "adb_getUserRolesResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateUsersOfRole.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getSystemPermissionsOfRole.h"
    
     #include "adb_getSystemPermissionsOfRoleResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateSystemPermissionsOfSpecialInternalRole.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateSystemPermissionsOfRole.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getExternalUserStoreConfigResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getInternalUsersResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_hasExternalUserStoreResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getSystemPermissionsResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateRoleName.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateSystemPermissionsOfExternalRole.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_updateUserName.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_addExternalUserStoreConfig.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_addUserToInternalStore.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_listExternalUsers.h"
    
     #include "adb_listExternalUsersResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getSpecialInternalRolesResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getUsersInExternalRole.h"
    
     #include "adb_getUsersInExternalRoleResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_changePassword.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getSystemPermissionsOfExternalRole.h"
    
     #include "adb_getSystemPermissionsOfExternalRoleResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getUsersOfSpecialInternalRole.h"
    
     #include "adb_getUsersOfSpecialInternalRoleResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_getUsersInRole.h"
    
     #include "adb_getUsersInRoleResponse.h"
    
     #include "adb_UserMgtExceptionE0.h"
    
     #include "adb_addSpecialInternalRole.h"
    
     #include "adb_UserMgtExceptionE0.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "deleteUserFromInternalStore|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_deleteUserFromInternalStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "deleteUserFromInternalStore|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _deleteUserFromInternalStore of the adb_deleteUserFromInternalStore_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_deleteUserFromInternalStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_deleteUserFromInternalStore_t* _deleteUserFromInternalStore,
                                          axis2_skel_UserManagementService_deleteUserFromInternalStore_fault *fault);


     
            /**
             * the generated fault union for operation "addRoleToInternalStore|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_addRoleToInternalStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addRoleToInternalStore|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addRoleToInternalStore of the adb_addRoleToInternalStore_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_addRoleToInternalStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addRoleToInternalStore_t* _addRoleToInternalStore,
                                          axis2_skel_UserManagementService_addRoleToInternalStore_fault *fault);


     
            /**
             * the generated fault union for operation "deleteSpecialInternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_deleteSpecialInternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "deleteSpecialInternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _deleteSpecialInternalRole of the adb_deleteSpecialInternalRole_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_deleteSpecialInternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_deleteSpecialInternalRole_t* _deleteSpecialInternalRole,
                                          axis2_skel_UserManagementService_deleteSpecialInternalRole_fault *fault);


     
            /**
             * the generated fault union for operation "getExternalUsers|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getExternalUsers_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getExternalUsers|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getExternalUsersResponse_t*
         */
        adb_getExternalUsersResponse_t* axis2_skel_UserManagementService_getExternalUsers(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_getExternalUsers_fault *fault);


     
            /**
             * the generated fault union for operation "deleteExternalUserStore|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_deleteExternalUserStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "deleteExternalUserStore|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_deleteExternalUserStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_deleteExternalUserStore_fault *fault);


     
            /**
             * the generated fault union for operation "updateExternalUserStoreConfig|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateExternalUserStoreConfig_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateExternalUserStoreConfig|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateExternalUserStoreConfig of the adb_updateExternalUserStoreConfig_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateExternalUserStoreConfig(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateExternalUserStoreConfig_t* _updateExternalUserStoreConfig,
                                          axis2_skel_UserManagementService_updateExternalUserStoreConfig_fault *fault);


     
            /**
             * the generated fault union for operation "addSystemPermissionsToRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_addSystemPermissionsToRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addSystemPermissionsToRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addSystemPermissionsToRole of the adb_addSystemPermissionsToRole_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_addSystemPermissionsToRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addSystemPermissionsToRole_t* _addSystemPermissionsToRole,
                                          axis2_skel_UserManagementService_addSystemPermissionsToRole_fault *fault);


     
            /**
             * the generated fault union for operation "getInternalRoles|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getInternalRoles_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getInternalRoles|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getInternalRolesResponse_t*
         */
        adb_getInternalRolesResponse_t* axis2_skel_UserManagementService_getInternalRoles(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_getInternalRoles_fault *fault);


     
            /**
             * the generated fault union for operation "getAllRolesNames|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getAllRolesNames_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getAllRolesNames|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getAllRolesNamesResponse_t*
         */
        adb_getAllRolesNamesResponse_t* axis2_skel_UserManagementService_getAllRolesNames(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_getAllRolesNames_fault *fault);


     
            /**
             * the generated fault union for operation "getExternalGroups|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getExternalGroups_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getExternalGroups|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getExternalGroupsResponse_t*
         */
        adb_getExternalGroupsResponse_t* axis2_skel_UserManagementService_getExternalGroups(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_getExternalGroups_fault *fault);


     
            /**
             * the generated fault union for operation "updateRolesofResource|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateRolesofResource_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateRolesofResource|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateRolesofResource of the adb_updateRolesofResource_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateRolesofResource(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateRolesofResource_t* _updateRolesofResource,
                                          axis2_skel_UserManagementService_updateRolesofResource_fault *fault);


     
            /**
             * the generated fault union for operation "listInternalUsers|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_listInternalUsers_fault;
         

		 
        /**
         * auto generated function declaration
         * for "listInternalUsers|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listInternalUsers of the adb_listInternalUsers_t*
         *
         * @return adb_listInternalUsersResponse_t*
         */
        adb_listInternalUsersResponse_t* axis2_skel_UserManagementService_listInternalUsers(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listInternalUsers_t* _listInternalUsers,
                                          axis2_skel_UserManagementService_listInternalUsers_fault *fault);


     
            /**
             * the generated fault union for operation "testConnection|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_testConnection_fault;
         

		 
        /**
         * auto generated function declaration
         * for "testConnection|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_testConnectionResponse_t*
         */
        adb_testConnectionResponse_t* axis2_skel_UserManagementService_testConnection(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_testConnection_fault *fault);


     
            /**
             * the generated fault union for operation "updateUsersOfSpecialInternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateUsersOfSpecialInternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateUsersOfSpecialInternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateUsersOfSpecialInternalRole of the adb_updateUsersOfSpecialInternalRole_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateUsersOfSpecialInternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateUsersOfSpecialInternalRole_t* _updateUsersOfSpecialInternalRole,
                                          axis2_skel_UserManagementService_updateUsersOfSpecialInternalRole_fault *fault);


     
            /**
             * the generated fault union for operation "getSystemPermissionsOfSpecialInternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getSystemPermissionsOfSpecialInternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSystemPermissionsOfSpecialInternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getSystemPermissionsOfSpecialInternalRole of the adb_getSystemPermissionsOfSpecialInternalRole_t*
         *
         * @return adb_getSystemPermissionsOfSpecialInternalRoleResponse_t*
         */
        adb_getSystemPermissionsOfSpecialInternalRoleResponse_t* axis2_skel_UserManagementService_getSystemPermissionsOfSpecialInternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getSystemPermissionsOfSpecialInternalRole_t* _getSystemPermissionsOfSpecialInternalRole,
                                          axis2_skel_UserManagementService_getSystemPermissionsOfSpecialInternalRole_fault *fault);


     
            /**
             * the generated fault union for operation "addRolesToResource|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_addRolesToResource_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addRolesToResource|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addRolesToResource of the adb_addRolesToResource_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_addRolesToResource(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addRolesToResource_t* _addRolesToResource,
                                          axis2_skel_UserManagementService_addRolesToResource_fault *fault);


     
            /**
             * the generated fault union for operation "deleteRoleFromInternalStore|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_deleteRoleFromInternalStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "deleteRoleFromInternalStore|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _deleteRoleFromInternalStore of the adb_deleteRoleFromInternalStore_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_deleteRoleFromInternalStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_deleteRoleFromInternalStore_t* _deleteRoleFromInternalStore,
                                          axis2_skel_UserManagementService_deleteRoleFromInternalStore_fault *fault);


     
            /**
             * the generated fault union for operation "getUserRoles|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getUserRoles_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getUserRoles|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getUserRoles of the adb_getUserRoles_t*
         *
         * @return adb_getUserRolesResponse_t*
         */
        adb_getUserRolesResponse_t* axis2_skel_UserManagementService_getUserRoles(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getUserRoles_t* _getUserRoles,
                                          axis2_skel_UserManagementService_getUserRoles_fault *fault);


     
            /**
             * the generated fault union for operation "updateUsersOfRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateUsersOfRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateUsersOfRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateUsersOfRole of the adb_updateUsersOfRole_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateUsersOfRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateUsersOfRole_t* _updateUsersOfRole,
                                          axis2_skel_UserManagementService_updateUsersOfRole_fault *fault);


     
            /**
             * the generated fault union for operation "getSystemPermissionsOfRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getSystemPermissionsOfRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSystemPermissionsOfRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getSystemPermissionsOfRole of the adb_getSystemPermissionsOfRole_t*
         *
         * @return adb_getSystemPermissionsOfRoleResponse_t*
         */
        adb_getSystemPermissionsOfRoleResponse_t* axis2_skel_UserManagementService_getSystemPermissionsOfRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getSystemPermissionsOfRole_t* _getSystemPermissionsOfRole,
                                          axis2_skel_UserManagementService_getSystemPermissionsOfRole_fault *fault);


     
            /**
             * the generated fault union for operation "updateSystemPermissionsOfSpecialInternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateSystemPermissionsOfSpecialInternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateSystemPermissionsOfSpecialInternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateSystemPermissionsOfSpecialInternalRole of the adb_updateSystemPermissionsOfSpecialInternalRole_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateSystemPermissionsOfSpecialInternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateSystemPermissionsOfSpecialInternalRole_t* _updateSystemPermissionsOfSpecialInternalRole,
                                          axis2_skel_UserManagementService_updateSystemPermissionsOfSpecialInternalRole_fault *fault);


     
            /**
             * the generated fault union for operation "updateSystemPermissionsOfRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateSystemPermissionsOfRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateSystemPermissionsOfRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateSystemPermissionsOfRole of the adb_updateSystemPermissionsOfRole_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateSystemPermissionsOfRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateSystemPermissionsOfRole_t* _updateSystemPermissionsOfRole,
                                          axis2_skel_UserManagementService_updateSystemPermissionsOfRole_fault *fault);


     
            /**
             * the generated fault union for operation "getExternalUserStoreConfig|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getExternalUserStoreConfig_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getExternalUserStoreConfig|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getExternalUserStoreConfigResponse_t*
         */
        adb_getExternalUserStoreConfigResponse_t* axis2_skel_UserManagementService_getExternalUserStoreConfig(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_getExternalUserStoreConfig_fault *fault);


     
            /**
             * the generated fault union for operation "getInternalUsers|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getInternalUsers_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getInternalUsers|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getInternalUsersResponse_t*
         */
        adb_getInternalUsersResponse_t* axis2_skel_UserManagementService_getInternalUsers(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_getInternalUsers_fault *fault);


     
            /**
             * the generated fault union for operation "hasExternalUserStore|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_hasExternalUserStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "hasExternalUserStore|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_hasExternalUserStoreResponse_t*
         */
        adb_hasExternalUserStoreResponse_t* axis2_skel_UserManagementService_hasExternalUserStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_hasExternalUserStore_fault *fault);


     
            /**
             * the generated fault union for operation "getSystemPermissions|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getSystemPermissions_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSystemPermissions|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemPermissionsResponse_t*
         */
        adb_getSystemPermissionsResponse_t* axis2_skel_UserManagementService_getSystemPermissions(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_getSystemPermissions_fault *fault);


     
            /**
             * the generated fault union for operation "updateRoleName|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateRoleName_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateRoleName|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateRoleName of the adb_updateRoleName_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateRoleName(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateRoleName_t* _updateRoleName,
                                          axis2_skel_UserManagementService_updateRoleName_fault *fault);


     
            /**
             * the generated fault union for operation "updateSystemPermissionsOfExternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateSystemPermissionsOfExternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateSystemPermissionsOfExternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateSystemPermissionsOfExternalRole of the adb_updateSystemPermissionsOfExternalRole_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateSystemPermissionsOfExternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateSystemPermissionsOfExternalRole_t* _updateSystemPermissionsOfExternalRole,
                                          axis2_skel_UserManagementService_updateSystemPermissionsOfExternalRole_fault *fault);


     
            /**
             * the generated fault union for operation "updateUserName|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_updateUserName_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateUserName|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateUserName of the adb_updateUserName_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_updateUserName(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateUserName_t* _updateUserName,
                                          axis2_skel_UserManagementService_updateUserName_fault *fault);


     
            /**
             * the generated fault union for operation "addExternalUserStoreConfig|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_addExternalUserStoreConfig_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addExternalUserStoreConfig|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addExternalUserStoreConfig of the adb_addExternalUserStoreConfig_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_addExternalUserStoreConfig(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addExternalUserStoreConfig_t* _addExternalUserStoreConfig,
                                          axis2_skel_UserManagementService_addExternalUserStoreConfig_fault *fault);


     
            /**
             * the generated fault union for operation "addUserToInternalStore|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_addUserToInternalStore_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addUserToInternalStore|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addUserToInternalStore of the adb_addUserToInternalStore_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_addUserToInternalStore(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addUserToInternalStore_t* _addUserToInternalStore,
                                          axis2_skel_UserManagementService_addUserToInternalStore_fault *fault);


     
            /**
             * the generated fault union for operation "listExternalUsers|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_listExternalUsers_fault;
         

		 
        /**
         * auto generated function declaration
         * for "listExternalUsers|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listExternalUsers of the adb_listExternalUsers_t*
         *
         * @return adb_listExternalUsersResponse_t*
         */
        adb_listExternalUsersResponse_t* axis2_skel_UserManagementService_listExternalUsers(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_listExternalUsers_t* _listExternalUsers,
                                          axis2_skel_UserManagementService_listExternalUsers_fault *fault);


     
            /**
             * the generated fault union for operation "getSpecialInternalRoles|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getSpecialInternalRoles_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSpecialInternalRoles|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSpecialInternalRolesResponse_t*
         */
        adb_getSpecialInternalRolesResponse_t* axis2_skel_UserManagementService_getSpecialInternalRoles(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_UserManagementService_getSpecialInternalRoles_fault *fault);


     
            /**
             * the generated fault union for operation "getUsersInExternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getUsersInExternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getUsersInExternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getUsersInExternalRole of the adb_getUsersInExternalRole_t*
         *
         * @return adb_getUsersInExternalRoleResponse_t*
         */
        adb_getUsersInExternalRoleResponse_t* axis2_skel_UserManagementService_getUsersInExternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getUsersInExternalRole_t* _getUsersInExternalRole,
                                          axis2_skel_UserManagementService_getUsersInExternalRole_fault *fault);


     
            /**
             * the generated fault union for operation "changePassword|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_changePassword_fault;
         

		 
        /**
         * auto generated function declaration
         * for "changePassword|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _changePassword of the adb_changePassword_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_changePassword(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_changePassword_t* _changePassword,
                                          axis2_skel_UserManagementService_changePassword_fault *fault);


     
            /**
             * the generated fault union for operation "getSystemPermissionsOfExternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getSystemPermissionsOfExternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSystemPermissionsOfExternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getSystemPermissionsOfExternalRole of the adb_getSystemPermissionsOfExternalRole_t*
         *
         * @return adb_getSystemPermissionsOfExternalRoleResponse_t*
         */
        adb_getSystemPermissionsOfExternalRoleResponse_t* axis2_skel_UserManagementService_getSystemPermissionsOfExternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getSystemPermissionsOfExternalRole_t* _getSystemPermissionsOfExternalRole,
                                          axis2_skel_UserManagementService_getSystemPermissionsOfExternalRole_fault *fault);


     
            /**
             * the generated fault union for operation "getUsersOfSpecialInternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getUsersOfSpecialInternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getUsersOfSpecialInternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getUsersOfSpecialInternalRole of the adb_getUsersOfSpecialInternalRole_t*
         *
         * @return adb_getUsersOfSpecialInternalRoleResponse_t*
         */
        adb_getUsersOfSpecialInternalRoleResponse_t* axis2_skel_UserManagementService_getUsersOfSpecialInternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getUsersOfSpecialInternalRole_t* _getUsersOfSpecialInternalRole,
                                          axis2_skel_UserManagementService_getUsersOfSpecialInternalRole_fault *fault);


     
            /**
             * the generated fault union for operation "getUsersInRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_getUsersInRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getUsersInRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getUsersInRole of the adb_getUsersInRole_t*
         *
         * @return adb_getUsersInRoleResponse_t*
         */
        adb_getUsersInRoleResponse_t* axis2_skel_UserManagementService_getUsersInRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getUsersInRole_t* _getUsersInRole,
                                          axis2_skel_UserManagementService_getUsersInRole_fault *fault);


     
            /**
             * the generated fault union for operation "addSpecialInternalRole|http://service.mgt.user.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_UserMgtExceptionE0_t* UserMgtException;
                
            } axis2_skel_UserManagementService_addSpecialInternalRole_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addSpecialInternalRole|http://service.mgt.user.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addSpecialInternalRole of the adb_addSpecialInternalRole_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_UserManagementService_addSpecialInternalRole(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addSpecialInternalRole_t* _addSpecialInternalRole,
                                          axis2_skel_UserManagementService_addSpecialInternalRole_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_USERMANAGEMENTSERVICE_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_USERMANAGEMENTSERVICE_ERROR_NONE = AXIS2_SKEL_USERMANAGEMENTSERVICE_ERROR_CODES_START,
        
        AXIS2_SKEL_USERMANAGEMENTSERVICE_DELETEUSERFROMINTERNALSTORE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDROLETOINTERNALSTORE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_DELETESPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETEXTERNALUSERS_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_DELETEEXTERNALUSERSTORE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEEXTERNALUSERSTORECONFIG_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDSYSTEMPERMISSIONSTOROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETINTERNALROLES_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETALLROLESNAMES_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETEXTERNALGROUPS_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEROLESOFRESOURCE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_LISTINTERNALUSERS_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_TESTCONNECTION_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEUSERSOFSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSYSTEMPERMISSIONSOFSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDROLESTORESOURCE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_DELETEROLEFROMINTERNALSTORE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETUSERROLES_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEUSERSOFROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSYSTEMPERMISSIONSOFROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATESYSTEMPERMISSIONSOFSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATESYSTEMPERMISSIONSOFROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETEXTERNALUSERSTORECONFIG_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETINTERNALUSERS_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_HASEXTERNALUSERSTORE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSYSTEMPERMISSIONS_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEROLENAME_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATESYSTEMPERMISSIONSOFEXTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEUSERNAME_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDEXTERNALUSERSTORECONFIG_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDUSERTOINTERNALSTORE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_LISTEXTERNALUSERS_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSPECIALINTERNALROLES_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETUSERSINEXTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_CHANGEPASSWORD_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSYSTEMPERMISSIONSOFEXTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETUSERSOFSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_GETUSERSINROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION,
            AXIS2_SKEL_USERMANAGEMENTSERVICE_ERROR_LAST
    } axis2_skel_UserManagementService_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

