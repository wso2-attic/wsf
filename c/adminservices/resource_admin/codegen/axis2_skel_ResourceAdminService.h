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
     * axis2_skel_ResourceAdminService.h
     *
     * This file was auto-generated from WSDL for "ResourceAdminService|http://services.resource.ui.mgt.registry.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_ResourceAdminService Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_getMediatypeDefinitionsResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getResourceTreeEntry.h"
    
     #include "adb_getResourceTreeEntryResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_createVersion.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_addRemoteLink.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_changeUserPermissions.h"
    
     #include "adb_changeUserPermissionsResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb__delete.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_updateTextContent.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_renameResource.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_moveResource.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getResourceData.h"
    
     #include "adb_getResourceDataResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_importResource.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_addUserPermission.h"
    
     #include "adb_addUserPermissionResponse.h"
    
     #include "adb_ResourceServiceExceptionE0.h"
    
     #include "adb_restoreVersion.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_addRolePermission.h"
    
     #include "adb_addRolePermissionResponse.h"
    
     #include "adb_ResourceServiceExceptionE0.h"
    
     #include "adb_getSessionResourcePathResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_addSymbolicLink.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getTextContent.h"
    
     #include "adb_getTextContentResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getCollectionMediatypeDefinitionsResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getCollectionContent.h"
    
     #include "adb_getCollectionContentResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_setSessionResourcePath.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_changeRolePermissions.h"
    
     #include "adb_changeRolePermissionsResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getVersionsBean.h"
    
     #include "adb_getVersionsBeanResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_setDescription.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_addTextResource.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getProperty.h"
    
     #include "adb_getPropertyResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getContentDownloadBean.h"
    
     #include "adb_getContentDownloadBeanResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getContentBean.h"
    
     #include "adb_getContentBeanResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_addCollection.h"
    
     #include "adb_addCollectionResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getMetadata.h"
    
     #include "adb_getMetadataResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getPermissions.h"
    
     #include "adb_getPermissionsResponse.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_copyResource.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_addResource.h"
    
     #include "adb_ExceptionE1.h"
    
     #include "adb_getCustomUIMediatypeDefinitionsResponse.h"
    
     #include "adb_ExceptionE1.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     
            /**
             * the generated fault union for operation "getMediatypeDefinitions|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getMediatypeDefinitions_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getMediatypeDefinitions|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getMediatypeDefinitionsResponse_t*
         */
        adb_getMediatypeDefinitionsResponse_t* axis2_skel_ResourceAdminService_getMediatypeDefinitions(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ResourceAdminService_getMediatypeDefinitions_fault *fault);


     
            /**
             * the generated fault union for operation "getResourceTreeEntry|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getResourceTreeEntry_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getResourceTreeEntry|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getResourceTreeEntry of the adb_getResourceTreeEntry_t*
         *
         * @return adb_getResourceTreeEntryResponse_t*
         */
        adb_getResourceTreeEntryResponse_t* axis2_skel_ResourceAdminService_getResourceTreeEntry(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getResourceTreeEntry_t* _getResourceTreeEntry,
                                          axis2_skel_ResourceAdminService_getResourceTreeEntry_fault *fault);


     
            /**
             * the generated fault union for operation "createVersion|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_createVersion_fault;
         

		 
        /**
         * auto generated function declaration
         * for "createVersion|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _createVersion of the adb_createVersion_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_createVersion(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_createVersion_t* _createVersion,
                                          axis2_skel_ResourceAdminService_createVersion_fault *fault);


     
            /**
             * the generated fault union for operation "addRemoteLink|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_addRemoteLink_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addRemoteLink|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addRemoteLink of the adb_addRemoteLink_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_addRemoteLink(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addRemoteLink_t* _addRemoteLink,
                                          axis2_skel_ResourceAdminService_addRemoteLink_fault *fault);


     
            /**
             * the generated fault union for operation "changeUserPermissions|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_changeUserPermissions_fault;
         

		 
        /**
         * auto generated function declaration
         * for "changeUserPermissions|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _changeUserPermissions of the adb_changeUserPermissions_t*
         *
         * @return adb_changeUserPermissionsResponse_t*
         */
        adb_changeUserPermissionsResponse_t* axis2_skel_ResourceAdminService_changeUserPermissions(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_changeUserPermissions_t* _changeUserPermissions,
                                          axis2_skel_ResourceAdminService_changeUserPermissions_fault *fault);


     
            /**
             * the generated fault union for operation "delete|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService__delete_fault;
         

		 
        /**
         * auto generated function declaration
         * for "delete|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _delete of the adb__delete_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService__delete(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb__delete_t* _delete,
                                          axis2_skel_ResourceAdminService__delete_fault *fault);


     
            /**
             * the generated fault union for operation "updateTextContent|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_updateTextContent_fault;
         

		 
        /**
         * auto generated function declaration
         * for "updateTextContent|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _updateTextContent of the adb_updateTextContent_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_updateTextContent(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_updateTextContent_t* _updateTextContent,
                                          axis2_skel_ResourceAdminService_updateTextContent_fault *fault);


     
            /**
             * the generated fault union for operation "renameResource|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_renameResource_fault;
         

		 
        /**
         * auto generated function declaration
         * for "renameResource|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _renameResource of the adb_renameResource_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_renameResource(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_renameResource_t* _renameResource,
                                          axis2_skel_ResourceAdminService_renameResource_fault *fault);


     
            /**
             * the generated fault union for operation "moveResource|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_moveResource_fault;
         

		 
        /**
         * auto generated function declaration
         * for "moveResource|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _moveResource of the adb_moveResource_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_moveResource(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_moveResource_t* _moveResource,
                                          axis2_skel_ResourceAdminService_moveResource_fault *fault);


     
            /**
             * the generated fault union for operation "getResourceData|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getResourceData_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getResourceData|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getResourceData of the adb_getResourceData_t*
         *
         * @return adb_getResourceDataResponse_t*
         */
        adb_getResourceDataResponse_t* axis2_skel_ResourceAdminService_getResourceData(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getResourceData_t* _getResourceData,
                                          axis2_skel_ResourceAdminService_getResourceData_fault *fault);


     
            /**
             * the generated fault union for operation "importResource|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_importResource_fault;
         

		 
        /**
         * auto generated function declaration
         * for "importResource|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _importResource of the adb_importResource_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_importResource(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_importResource_t* _importResource,
                                          axis2_skel_ResourceAdminService_importResource_fault *fault);


     
            /**
             * the generated fault union for operation "addUserPermission|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ResourceServiceExceptionE0_t* ResourceServiceException;
                
            } axis2_skel_ResourceAdminService_addUserPermission_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addUserPermission|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addUserPermission of the adb_addUserPermission_t*
         *
         * @return adb_addUserPermissionResponse_t*
         */
        adb_addUserPermissionResponse_t* axis2_skel_ResourceAdminService_addUserPermission(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addUserPermission_t* _addUserPermission,
                                          axis2_skel_ResourceAdminService_addUserPermission_fault *fault);


     
            /**
             * the generated fault union for operation "restoreVersion|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_restoreVersion_fault;
         

		 
        /**
         * auto generated function declaration
         * for "restoreVersion|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _restoreVersion of the adb_restoreVersion_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_restoreVersion(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_restoreVersion_t* _restoreVersion,
                                          axis2_skel_ResourceAdminService_restoreVersion_fault *fault);


     
            /**
             * the generated fault union for operation "addRolePermission|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ResourceServiceExceptionE0_t* ResourceServiceException;
                
            } axis2_skel_ResourceAdminService_addRolePermission_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addRolePermission|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addRolePermission of the adb_addRolePermission_t*
         *
         * @return adb_addRolePermissionResponse_t*
         */
        adb_addRolePermissionResponse_t* axis2_skel_ResourceAdminService_addRolePermission(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addRolePermission_t* _addRolePermission,
                                          axis2_skel_ResourceAdminService_addRolePermission_fault *fault);


     
            /**
             * the generated fault union for operation "getSessionResourcePath|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getSessionResourcePath_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getSessionResourcePath|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSessionResourcePathResponse_t*
         */
        adb_getSessionResourcePathResponse_t* axis2_skel_ResourceAdminService_getSessionResourcePath(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ResourceAdminService_getSessionResourcePath_fault *fault);


     
            /**
             * the generated fault union for operation "addSymbolicLink|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_addSymbolicLink_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addSymbolicLink|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addSymbolicLink of the adb_addSymbolicLink_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_addSymbolicLink(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addSymbolicLink_t* _addSymbolicLink,
                                          axis2_skel_ResourceAdminService_addSymbolicLink_fault *fault);


     
            /**
             * the generated fault union for operation "getTextContent|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getTextContent_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getTextContent|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getTextContent of the adb_getTextContent_t*
         *
         * @return adb_getTextContentResponse_t*
         */
        adb_getTextContentResponse_t* axis2_skel_ResourceAdminService_getTextContent(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getTextContent_t* _getTextContent,
                                          axis2_skel_ResourceAdminService_getTextContent_fault *fault);


     
            /**
             * the generated fault union for operation "getCollectionMediatypeDefinitions|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getCollectionMediatypeDefinitions_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getCollectionMediatypeDefinitions|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getCollectionMediatypeDefinitionsResponse_t*
         */
        adb_getCollectionMediatypeDefinitionsResponse_t* axis2_skel_ResourceAdminService_getCollectionMediatypeDefinitions(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ResourceAdminService_getCollectionMediatypeDefinitions_fault *fault);


     
            /**
             * the generated fault union for operation "getCollectionContent|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getCollectionContent_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getCollectionContent|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getCollectionContent of the adb_getCollectionContent_t*
         *
         * @return adb_getCollectionContentResponse_t*
         */
        adb_getCollectionContentResponse_t* axis2_skel_ResourceAdminService_getCollectionContent(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getCollectionContent_t* _getCollectionContent,
                                          axis2_skel_ResourceAdminService_getCollectionContent_fault *fault);


     
            /**
             * the generated fault union for operation "setSessionResourcePath|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_setSessionResourcePath_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setSessionResourcePath|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setSessionResourcePath of the adb_setSessionResourcePath_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_setSessionResourcePath(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setSessionResourcePath_t* _setSessionResourcePath,
                                          axis2_skel_ResourceAdminService_setSessionResourcePath_fault *fault);


     
            /**
             * the generated fault union for operation "changeRolePermissions|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_changeRolePermissions_fault;
         

		 
        /**
         * auto generated function declaration
         * for "changeRolePermissions|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _changeRolePermissions of the adb_changeRolePermissions_t*
         *
         * @return adb_changeRolePermissionsResponse_t*
         */
        adb_changeRolePermissionsResponse_t* axis2_skel_ResourceAdminService_changeRolePermissions(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_changeRolePermissions_t* _changeRolePermissions,
                                          axis2_skel_ResourceAdminService_changeRolePermissions_fault *fault);


     
            /**
             * the generated fault union for operation "getVersionsBean|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getVersionsBean_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getVersionsBean|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getVersionsBean of the adb_getVersionsBean_t*
         *
         * @return adb_getVersionsBeanResponse_t*
         */
        adb_getVersionsBeanResponse_t* axis2_skel_ResourceAdminService_getVersionsBean(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getVersionsBean_t* _getVersionsBean,
                                          axis2_skel_ResourceAdminService_getVersionsBean_fault *fault);


     
            /**
             * the generated fault union for operation "setDescription|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_setDescription_fault;
         

		 
        /**
         * auto generated function declaration
         * for "setDescription|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setDescription of the adb_setDescription_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_setDescription(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_setDescription_t* _setDescription,
                                          axis2_skel_ResourceAdminService_setDescription_fault *fault);


     
            /**
             * the generated fault union for operation "addTextResource|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_addTextResource_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addTextResource|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addTextResource of the adb_addTextResource_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_addTextResource(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addTextResource_t* _addTextResource,
                                          axis2_skel_ResourceAdminService_addTextResource_fault *fault);


     
            /**
             * the generated fault union for operation "getProperty|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getProperty_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getProperty|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getProperty of the adb_getProperty_t*
         *
         * @return adb_getPropertyResponse_t*
         */
        adb_getPropertyResponse_t* axis2_skel_ResourceAdminService_getProperty(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getProperty_t* _getProperty,
                                          axis2_skel_ResourceAdminService_getProperty_fault *fault);


     
            /**
             * the generated fault union for operation "getContentDownloadBean|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getContentDownloadBean_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getContentDownloadBean|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getContentDownloadBean of the adb_getContentDownloadBean_t*
         *
         * @return adb_getContentDownloadBeanResponse_t*
         */
        adb_getContentDownloadBeanResponse_t* axis2_skel_ResourceAdminService_getContentDownloadBean(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getContentDownloadBean_t* _getContentDownloadBean,
                                          axis2_skel_ResourceAdminService_getContentDownloadBean_fault *fault);


     
            /**
             * the generated fault union for operation "getContentBean|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getContentBean_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getContentBean|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getContentBean of the adb_getContentBean_t*
         *
         * @return adb_getContentBeanResponse_t*
         */
        adb_getContentBeanResponse_t* axis2_skel_ResourceAdminService_getContentBean(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getContentBean_t* _getContentBean,
                                          axis2_skel_ResourceAdminService_getContentBean_fault *fault);


     
            /**
             * the generated fault union for operation "addCollection|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_addCollection_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addCollection|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addCollection of the adb_addCollection_t*
         *
         * @return adb_addCollectionResponse_t*
         */
        adb_addCollectionResponse_t* axis2_skel_ResourceAdminService_addCollection(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addCollection_t* _addCollection,
                                          axis2_skel_ResourceAdminService_addCollection_fault *fault);


     
            /**
             * the generated fault union for operation "getMetadata|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getMetadata_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getMetadata|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMetadata of the adb_getMetadata_t*
         *
         * @return adb_getMetadataResponse_t*
         */
        adb_getMetadataResponse_t* axis2_skel_ResourceAdminService_getMetadata(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getMetadata_t* _getMetadata,
                                          axis2_skel_ResourceAdminService_getMetadata_fault *fault);


     
            /**
             * the generated fault union for operation "getPermissions|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getPermissions_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getPermissions|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getPermissions of the adb_getPermissions_t*
         *
         * @return adb_getPermissionsResponse_t*
         */
        adb_getPermissionsResponse_t* axis2_skel_ResourceAdminService_getPermissions(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_getPermissions_t* _getPermissions,
                                          axis2_skel_ResourceAdminService_getPermissions_fault *fault);


     
            /**
             * the generated fault union for operation "copyResource|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_copyResource_fault;
         

		 
        /**
         * auto generated function declaration
         * for "copyResource|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _copyResource of the adb_copyResource_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_copyResource(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_copyResource_t* _copyResource,
                                          axis2_skel_ResourceAdminService_copyResource_fault *fault);


     
            /**
             * the generated fault union for operation "addResource|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_addResource_fault;
         

		 
        /**
         * auto generated function declaration
         * for "addResource|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _addResource of the adb_addResource_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_ResourceAdminService_addResource(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_addResource_t* _addResource,
                                          axis2_skel_ResourceAdminService_addResource_fault *fault);


     
            /**
             * the generated fault union for operation "getCustomUIMediatypeDefinitions|http://services.resource.ui.mgt.registry.carbon.wso2.org",
             * in a case you want to return a fault, put the appropriate adb object for
             * the union variable pointer comes as the last parameter of the method
             */
            typedef union
            {
                adb_ExceptionE1_t* Exception;
                
            } axis2_skel_ResourceAdminService_getCustomUIMediatypeDefinitions_fault;
         

		 
        /**
         * auto generated function declaration
         * for "getCustomUIMediatypeDefinitions|http://services.resource.ui.mgt.registry.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getCustomUIMediatypeDefinitionsResponse_t*
         */
        adb_getCustomUIMediatypeDefinitionsResponse_t* axis2_skel_ResourceAdminService_getCustomUIMediatypeDefinitions(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                          axis2_skel_ResourceAdminService_getCustomUIMediatypeDefinitions_fault *fault);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_RESOURCEADMINSERVICE_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_RESOURCEADMINSERVICE_ERROR_NONE = AXIS2_SKEL_RESOURCEADMINSERVICE_ERROR_CODES_START,
        
        AXIS2_SKEL_RESOURCEADMINSERVICE_GETMEDIATYPEDEFINITIONS_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETRESOURCETREEENTRY_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_CREATEVERSION_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_ADDREMOTELINK_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_CHANGEUSERPERMISSIONS_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE__DELETE_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_UPDATETEXTCONTENT_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_RENAMERESOURCE_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_MOVERESOURCE_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETRESOURCEDATA_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_IMPORTRESOURCE_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_ADDUSERPERMISSION_FAULT_RESOURCESERVICEEXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_RESTOREVERSION_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_ADDROLEPERMISSION_FAULT_RESOURCESERVICEEXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETSESSIONRESOURCEPATH_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_ADDSYMBOLICLINK_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETTEXTCONTENT_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETCOLLECTIONMEDIATYPEDEFINITIONS_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETCOLLECTIONCONTENT_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_SETSESSIONRESOURCEPATH_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_CHANGEROLEPERMISSIONS_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETVERSIONSBEAN_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_SETDESCRIPTION_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_ADDTEXTRESOURCE_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETPROPERTY_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETCONTENTDOWNLOADBEAN_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETCONTENTBEAN_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_ADDCOLLECTION_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETMETADATA_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETPERMISSIONS_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_COPYRESOURCE_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_ADDRESOURCE_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_GETCUSTOMUIMEDIATYPEDEFINITIONS_FAULT_EXCEPTION,
            AXIS2_SKEL_RESOURCEADMINSERVICE_ERROR_LAST
    } axis2_skel_ResourceAdminService_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

