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
         * axis2_svc_skel_UserManagementService.c
         *
         * This file was auto-generated from WSDL for "UserManagementService|http://service.mgt.user.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_UserManagementService
         */

        #include "axis2_skel_UserManagementService.h"
        #include <axis2_svc_skeleton.h>
        #include <stdio.h>
        #include <axis2_svc.h>

        #ifdef __cplusplus
        extern "C" {
        #endif

        /**
         * creating a custom structure to wrap the axis2_svc_skeleton class
         */
        typedef struct {
            axis2_svc_skeleton_t svc_skeleton;

            /* union to keep all the exception objects */
          
            union {
                axis2_skel_UserManagementService_deleteUserFromInternalStore_fault deleteUserFromInternalStore_fault;
                    axis2_skel_UserManagementService_addRoleToInternalStore_fault addRoleToInternalStore_fault;
                    axis2_skel_UserManagementService_deleteSpecialInternalRole_fault deleteSpecialInternalRole_fault;
                    axis2_skel_UserManagementService_getExternalUsers_fault getExternalUsers_fault;
                    axis2_skel_UserManagementService_deleteExternalUserStore_fault deleteExternalUserStore_fault;
                    axis2_skel_UserManagementService_updateExternalUserStoreConfig_fault updateExternalUserStoreConfig_fault;
                    axis2_skel_UserManagementService_addSystemPermissionsToRole_fault addSystemPermissionsToRole_fault;
                    axis2_skel_UserManagementService_getInternalRoles_fault getInternalRoles_fault;
                    axis2_skel_UserManagementService_getAllRolesNames_fault getAllRolesNames_fault;
                    axis2_skel_UserManagementService_getExternalGroups_fault getExternalGroups_fault;
                    axis2_skel_UserManagementService_updateRolesofResource_fault updateRolesofResource_fault;
                    axis2_skel_UserManagementService_listInternalUsers_fault listInternalUsers_fault;
                    axis2_skel_UserManagementService_testConnection_fault testConnection_fault;
                    axis2_skel_UserManagementService_updateUsersOfSpecialInternalRole_fault updateUsersOfSpecialInternalRole_fault;
                    axis2_skel_UserManagementService_getSystemPermissionsOfSpecialInternalRole_fault getSystemPermissionsOfSpecialInternalRole_fault;
                    axis2_skel_UserManagementService_addRolesToResource_fault addRolesToResource_fault;
                    axis2_skel_UserManagementService_deleteRoleFromInternalStore_fault deleteRoleFromInternalStore_fault;
                    axis2_skel_UserManagementService_getUserRoles_fault getUserRoles_fault;
                    axis2_skel_UserManagementService_updateUsersOfRole_fault updateUsersOfRole_fault;
                    axis2_skel_UserManagementService_getSystemPermissionsOfRole_fault getSystemPermissionsOfRole_fault;
                    axis2_skel_UserManagementService_updateSystemPermissionsOfSpecialInternalRole_fault updateSystemPermissionsOfSpecialInternalRole_fault;
                    axis2_skel_UserManagementService_updateSystemPermissionsOfRole_fault updateSystemPermissionsOfRole_fault;
                    axis2_skel_UserManagementService_getExternalUserStoreConfig_fault getExternalUserStoreConfig_fault;
                    axis2_skel_UserManagementService_getInternalUsers_fault getInternalUsers_fault;
                    axis2_skel_UserManagementService_hasExternalUserStore_fault hasExternalUserStore_fault;
                    axis2_skel_UserManagementService_getSystemPermissions_fault getSystemPermissions_fault;
                    axis2_skel_UserManagementService_updateRoleName_fault updateRoleName_fault;
                    axis2_skel_UserManagementService_updateSystemPermissionsOfExternalRole_fault updateSystemPermissionsOfExternalRole_fault;
                    axis2_skel_UserManagementService_updateUserName_fault updateUserName_fault;
                    axis2_skel_UserManagementService_addExternalUserStoreConfig_fault addExternalUserStoreConfig_fault;
                    axis2_skel_UserManagementService_addUserToInternalStore_fault addUserToInternalStore_fault;
                    axis2_skel_UserManagementService_listExternalUsers_fault listExternalUsers_fault;
                    axis2_skel_UserManagementService_getSpecialInternalRoles_fault getSpecialInternalRoles_fault;
                    axis2_skel_UserManagementService_getUsersInExternalRole_fault getUsersInExternalRole_fault;
                    axis2_skel_UserManagementService_changePassword_fault changePassword_fault;
                    axis2_skel_UserManagementService_getSystemPermissionsOfExternalRole_fault getSystemPermissionsOfExternalRole_fault;
                    axis2_skel_UserManagementService_getUsersOfSpecialInternalRole_fault getUsersOfSpecialInternalRole_fault;
                    axis2_skel_UserManagementService_getUsersInRole_fault getUsersInRole_fault;
                    axis2_skel_UserManagementService_addSpecialInternalRole_fault addSpecialInternalRole_fault;
                    
            } fault;
          
        }axis2_svc_skel_UserManagementService_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_UserManagementService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_UserManagementService_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_UserManagementService_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_UserManagementService_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_UserManagementService_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_UserManagementService_svc_skeleton_ops_var = {
            axis2_svc_skel_UserManagementService_init,
            axis2_svc_skel_UserManagementService_invoke,
            axis2_svc_skel_UserManagementService_on_fault,
            axis2_svc_skel_UserManagementService_free
        };


        /**
         * Following block distinguish the exposed part of the dll.
         * create the instance
         */

        AXIS2_EXTERN int
        axis2_get_instance(struct axis2_svc_skeleton **inst,
                                const axutil_env_t *env);

        AXIS2_EXTERN int 
        axis2_remove_instance(axis2_svc_skeleton_t *inst,
                                const axutil_env_t *env);


         /**
          * function to free any soap input headers
          */
         


        #ifdef __cplusplus
        }
        #endif


        /**
         * Implementations for the functions
         */

	axis2_svc_skeleton_t* AXIS2_CALL
	axis2_svc_skel_UserManagementService_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_UserManagementService_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_UserManagementService_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_UserManagementService_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_UserManagementService_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_UserManagementService_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_UserManagementService */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_UserManagementService_free(axis2_svc_skeleton_t *svc_skeleton,
				 const axutil_env_t *env)
	{

        /* Free the service skeleton */
        if (svc_skeleton)
        {
            AXIS2_FREE(env->allocator, svc_skeleton);
            svc_skeleton = NULL;
        }

        return AXIS2_SUCCESS;
	}



     




	/*
	 * This method invokes the right service method
	 */
	axiom_node_t* AXIS2_CALL
	axis2_svc_skel_UserManagementService_invoke(axis2_svc_skeleton_t *svc_skeleton,
				const axutil_env_t *env,
				axiom_node_t *content_node,
				axis2_msg_ctx_t *msg_ctx)
	{
         /* depending on the function name invoke the
          * corresponding  method
          */

          axis2_op_ctx_t *operation_ctx = NULL;
          axis2_op_t *operation = NULL;
          axutil_qname_t *op_qname = NULL;
          axis2_char_t *op_name = NULL;
          axis2_msg_ctx_t *in_msg_ctx = NULL;
          
          axiom_soap_envelope_t *req_soap_env = NULL;
          axiom_soap_header_t *req_soap_header = NULL;
          axiom_soap_envelope_t *res_soap_env = NULL;
          axiom_soap_header_t *res_soap_header = NULL;

          axiom_node_t *ret_node = NULL;
          axiom_node_t *input_header = NULL;
          axiom_node_t *output_header = NULL;
          axiom_node_t *header_base_node = NULL;
	    
          axis2_svc_skel_UserManagementService_t *svc_skeleton_wrapper = NULL;

          
            axis2_status_t ret_val1;
            adb_deleteUserFromInternalStore_t* input_val1;
            
            axis2_status_t ret_val2;
            adb_addRoleToInternalStore_t* input_val2;
            
            axis2_status_t ret_val3;
            adb_deleteSpecialInternalRole_t* input_val3;
            
            adb_getExternalUsersResponse_t* ret_val4;
            
            axis2_status_t ret_val5;
            
            axis2_status_t ret_val6;
            adb_updateExternalUserStoreConfig_t* input_val6;
            
            axis2_status_t ret_val7;
            adb_addSystemPermissionsToRole_t* input_val7;
            
            adb_getInternalRolesResponse_t* ret_val8;
            
            adb_getAllRolesNamesResponse_t* ret_val9;
            
            adb_getExternalGroupsResponse_t* ret_val10;
            
            axis2_status_t ret_val11;
            adb_updateRolesofResource_t* input_val11;
            
            adb_listInternalUsersResponse_t* ret_val12;
            adb_listInternalUsers_t* input_val12;
            
            adb_testConnectionResponse_t* ret_val13;
            
            axis2_status_t ret_val14;
            adb_updateUsersOfSpecialInternalRole_t* input_val14;
            
            adb_getSystemPermissionsOfSpecialInternalRoleResponse_t* ret_val15;
            adb_getSystemPermissionsOfSpecialInternalRole_t* input_val15;
            
            axis2_status_t ret_val16;
            adb_addRolesToResource_t* input_val16;
            
            axis2_status_t ret_val17;
            adb_deleteRoleFromInternalStore_t* input_val17;
            
            adb_getUserRolesResponse_t* ret_val18;
            adb_getUserRoles_t* input_val18;
            
            axis2_status_t ret_val19;
            adb_updateUsersOfRole_t* input_val19;
            
            adb_getSystemPermissionsOfRoleResponse_t* ret_val20;
            adb_getSystemPermissionsOfRole_t* input_val20;
            
            axis2_status_t ret_val21;
            adb_updateSystemPermissionsOfSpecialInternalRole_t* input_val21;
            
            axis2_status_t ret_val22;
            adb_updateSystemPermissionsOfRole_t* input_val22;
            
            adb_getExternalUserStoreConfigResponse_t* ret_val23;
            
            adb_getInternalUsersResponse_t* ret_val24;
            
            adb_hasExternalUserStoreResponse_t* ret_val25;
            
            adb_getSystemPermissionsResponse_t* ret_val26;
            
            axis2_status_t ret_val27;
            adb_updateRoleName_t* input_val27;
            
            axis2_status_t ret_val28;
            adb_updateSystemPermissionsOfExternalRole_t* input_val28;
            
            axis2_status_t ret_val29;
            adb_updateUserName_t* input_val29;
            
            axis2_status_t ret_val30;
            adb_addExternalUserStoreConfig_t* input_val30;
            
            axis2_status_t ret_val31;
            adb_addUserToInternalStore_t* input_val31;
            
            adb_listExternalUsersResponse_t* ret_val32;
            adb_listExternalUsers_t* input_val32;
            
            adb_getSpecialInternalRolesResponse_t* ret_val33;
            
            adb_getUsersInExternalRoleResponse_t* ret_val34;
            adb_getUsersInExternalRole_t* input_val34;
            
            axis2_status_t ret_val35;
            adb_changePassword_t* input_val35;
            
            adb_getSystemPermissionsOfExternalRoleResponse_t* ret_val36;
            adb_getSystemPermissionsOfExternalRole_t* input_val36;
            
            adb_getUsersOfSpecialInternalRoleResponse_t* ret_val37;
            adb_getUsersOfSpecialInternalRole_t* input_val37;
            
            adb_getUsersInRoleResponse_t* ret_val38;
            adb_getUsersInRole_t* input_val38;
            
            axis2_status_t ret_val39;
            adb_addSpecialInternalRole_t* input_val39;
            

          svc_skeleton_wrapper = (axis2_svc_skel_UserManagementService_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "deleteUserFromInternalStore") == 0 )
                {

                    
                    input_val1 = adb_deleteUserFromInternalStore_create( env);
                        if( AXIS2_FAILURE == adb_deleteUserFromInternalStore_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_deleteUserFromInternalStore_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_deleteUserFromInternalStore_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_UserManagementService_deleteUserFromInternalStore(env, msg_ctx,input_val1,
                                                (axis2_skel_UserManagementService_deleteUserFromInternalStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val1 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteUserFromInternalStore ");
                        }
                        adb_deleteUserFromInternalStore_free(input_val1, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addRoleToInternalStore") == 0 )
                {

                    
                    input_val2 = adb_addRoleToInternalStore_create( env);
                        if( AXIS2_FAILURE == adb_addRoleToInternalStore_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addRoleToInternalStore_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addRoleToInternalStore_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_UserManagementService_addRoleToInternalStore(env, msg_ctx,input_val2,
                                                (axis2_skel_UserManagementService_addRoleToInternalStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val2 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addRoleToInternalStore ");
                        }
                        adb_addRoleToInternalStore_free(input_val2, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "deleteSpecialInternalRole") == 0 )
                {

                    
                    input_val3 = adb_deleteSpecialInternalRole_create( env);
                        if( AXIS2_FAILURE == adb_deleteSpecialInternalRole_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_deleteSpecialInternalRole_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_deleteSpecialInternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_UserManagementService_deleteSpecialInternalRole(env, msg_ctx,input_val3,
                                                (axis2_skel_UserManagementService_deleteSpecialInternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val3 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteSpecialInternalRole ");
                        }
                        adb_deleteSpecialInternalRole_free(input_val3, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getExternalUsers") == 0 )
                {

                    
                        ret_val4 =  axis2_skel_UserManagementService_getExternalUsers(env, msg_ctx,
                                                (axis2_skel_UserManagementService_getExternalUsers_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val4 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getExternalUsersResponse_serialize(ret_val4, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getExternalUsersResponse_free(ret_val4, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "deleteExternalUserStore") == 0 )
                {

                    
                        ret_val5 =  axis2_skel_UserManagementService_deleteExternalUserStore(env, msg_ctx,
                                                (axis2_skel_UserManagementService_deleteExternalUserStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val5 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteExternalUserStore ");
                        }
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateExternalUserStoreConfig") == 0 )
                {

                    
                    input_val6 = adb_updateExternalUserStoreConfig_create( env);
                        if( AXIS2_FAILURE == adb_updateExternalUserStoreConfig_deserialize(input_val6, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateExternalUserStoreConfig_free(input_val6, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateExternalUserStoreConfig_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val6 =  axis2_skel_UserManagementService_updateExternalUserStoreConfig(env, msg_ctx,input_val6,
                                                (axis2_skel_UserManagementService_updateExternalUserStoreConfig_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val6 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateExternalUserStoreConfig ");
                        }
                        adb_updateExternalUserStoreConfig_free(input_val6, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addSystemPermissionsToRole") == 0 )
                {

                    
                    input_val7 = adb_addSystemPermissionsToRole_create( env);
                        if( AXIS2_FAILURE == adb_addSystemPermissionsToRole_deserialize(input_val7, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addSystemPermissionsToRole_free(input_val7, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addSystemPermissionsToRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val7 =  axis2_skel_UserManagementService_addSystemPermissionsToRole(env, msg_ctx,input_val7,
                                                (axis2_skel_UserManagementService_addSystemPermissionsToRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val7 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addSystemPermissionsToRole ");
                        }
                        adb_addSystemPermissionsToRole_free(input_val7, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getInternalRoles") == 0 )
                {

                    
                        ret_val8 =  axis2_skel_UserManagementService_getInternalRoles(env, msg_ctx,
                                                (axis2_skel_UserManagementService_getInternalRoles_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val8 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getInternalRolesResponse_serialize(ret_val8, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getInternalRolesResponse_free(ret_val8, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getAllRolesNames") == 0 )
                {

                    
                        ret_val9 =  axis2_skel_UserManagementService_getAllRolesNames(env, msg_ctx,
                                                (axis2_skel_UserManagementService_getAllRolesNames_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val9 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getAllRolesNamesResponse_serialize(ret_val9, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getAllRolesNamesResponse_free(ret_val9, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getExternalGroups") == 0 )
                {

                    
                        ret_val10 =  axis2_skel_UserManagementService_getExternalGroups(env, msg_ctx,
                                                (axis2_skel_UserManagementService_getExternalGroups_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val10 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getExternalGroupsResponse_serialize(ret_val10, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getExternalGroupsResponse_free(ret_val10, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateRolesofResource") == 0 )
                {

                    
                    input_val11 = adb_updateRolesofResource_create( env);
                        if( AXIS2_FAILURE == adb_updateRolesofResource_deserialize(input_val11, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateRolesofResource_free(input_val11, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateRolesofResource_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val11 =  axis2_skel_UserManagementService_updateRolesofResource(env, msg_ctx,input_val11,
                                                (axis2_skel_UserManagementService_updateRolesofResource_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val11 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateRolesofResource ");
                        }
                        adb_updateRolesofResource_free(input_val11, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "listInternalUsers") == 0 )
                {

                    
                    input_val12 = adb_listInternalUsers_create( env);
                        if( AXIS2_FAILURE == adb_listInternalUsers_deserialize(input_val12, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listInternalUsers_free(input_val12, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listInternalUsers_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val12 =  axis2_skel_UserManagementService_listInternalUsers(env, msg_ctx,input_val12,
                                                (axis2_skel_UserManagementService_listInternalUsers_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val12 )
                        {
                            adb_listInternalUsers_free(input_val12, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listInternalUsersResponse_serialize(ret_val12, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listInternalUsersResponse_free(ret_val12, env);
                                   adb_listInternalUsers_free(input_val12, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "testConnection") == 0 )
                {

                    
                        ret_val13 =  axis2_skel_UserManagementService_testConnection(env, msg_ctx,
                                                (axis2_skel_UserManagementService_testConnection_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val13 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_testConnectionResponse_serialize(ret_val13, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_testConnectionResponse_free(ret_val13, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateUsersOfSpecialInternalRole") == 0 )
                {

                    
                    input_val14 = adb_updateUsersOfSpecialInternalRole_create( env);
                        if( AXIS2_FAILURE == adb_updateUsersOfSpecialInternalRole_deserialize(input_val14, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateUsersOfSpecialInternalRole_free(input_val14, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateUsersOfSpecialInternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val14 =  axis2_skel_UserManagementService_updateUsersOfSpecialInternalRole(env, msg_ctx,input_val14,
                                                (axis2_skel_UserManagementService_updateUsersOfSpecialInternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val14 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateUsersOfSpecialInternalRole ");
                        }
                        adb_updateUsersOfSpecialInternalRole_free(input_val14, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getSystemPermissionsOfSpecialInternalRole") == 0 )
                {

                    
                    input_val15 = adb_getSystemPermissionsOfSpecialInternalRole_create( env);
                        if( AXIS2_FAILURE == adb_getSystemPermissionsOfSpecialInternalRole_deserialize(input_val15, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getSystemPermissionsOfSpecialInternalRole_free(input_val15, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getSystemPermissionsOfSpecialInternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val15 =  axis2_skel_UserManagementService_getSystemPermissionsOfSpecialInternalRole(env, msg_ctx,input_val15,
                                                (axis2_skel_UserManagementService_getSystemPermissionsOfSpecialInternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val15 )
                        {
                            adb_getSystemPermissionsOfSpecialInternalRole_free(input_val15, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemPermissionsOfSpecialInternalRoleResponse_serialize(ret_val15, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemPermissionsOfSpecialInternalRoleResponse_free(ret_val15, env);
                                   adb_getSystemPermissionsOfSpecialInternalRole_free(input_val15, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "addRolesToResource") == 0 )
                {

                    
                    input_val16 = adb_addRolesToResource_create( env);
                        if( AXIS2_FAILURE == adb_addRolesToResource_deserialize(input_val16, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addRolesToResource_free(input_val16, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addRolesToResource_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val16 =  axis2_skel_UserManagementService_addRolesToResource(env, msg_ctx,input_val16,
                                                (axis2_skel_UserManagementService_addRolesToResource_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val16 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addRolesToResource ");
                        }
                        adb_addRolesToResource_free(input_val16, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "deleteRoleFromInternalStore") == 0 )
                {

                    
                    input_val17 = adb_deleteRoleFromInternalStore_create( env);
                        if( AXIS2_FAILURE == adb_deleteRoleFromInternalStore_deserialize(input_val17, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_deleteRoleFromInternalStore_free(input_val17, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_deleteRoleFromInternalStore_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val17 =  axis2_skel_UserManagementService_deleteRoleFromInternalStore(env, msg_ctx,input_val17,
                                                (axis2_skel_UserManagementService_deleteRoleFromInternalStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val17 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteRoleFromInternalStore ");
                        }
                        adb_deleteRoleFromInternalStore_free(input_val17, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getUserRoles") == 0 )
                {

                    
                    input_val18 = adb_getUserRoles_create( env);
                        if( AXIS2_FAILURE == adb_getUserRoles_deserialize(input_val18, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getUserRoles_free(input_val18, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getUserRoles_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val18 =  axis2_skel_UserManagementService_getUserRoles(env, msg_ctx,input_val18,
                                                (axis2_skel_UserManagementService_getUserRoles_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val18 )
                        {
                            adb_getUserRoles_free(input_val18, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getUserRolesResponse_serialize(ret_val18, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getUserRolesResponse_free(ret_val18, env);
                                   adb_getUserRoles_free(input_val18, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateUsersOfRole") == 0 )
                {

                    
                    input_val19 = adb_updateUsersOfRole_create( env);
                        if( AXIS2_FAILURE == adb_updateUsersOfRole_deserialize(input_val19, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateUsersOfRole_free(input_val19, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateUsersOfRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val19 =  axis2_skel_UserManagementService_updateUsersOfRole(env, msg_ctx,input_val19,
                                                (axis2_skel_UserManagementService_updateUsersOfRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val19 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateUsersOfRole ");
                        }
                        adb_updateUsersOfRole_free(input_val19, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getSystemPermissionsOfRole") == 0 )
                {

                    
                    input_val20 = adb_getSystemPermissionsOfRole_create( env);
                        if( AXIS2_FAILURE == adb_getSystemPermissionsOfRole_deserialize(input_val20, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getSystemPermissionsOfRole_free(input_val20, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getSystemPermissionsOfRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val20 =  axis2_skel_UserManagementService_getSystemPermissionsOfRole(env, msg_ctx,input_val20,
                                                (axis2_skel_UserManagementService_getSystemPermissionsOfRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val20 )
                        {
                            adb_getSystemPermissionsOfRole_free(input_val20, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemPermissionsOfRoleResponse_serialize(ret_val20, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemPermissionsOfRoleResponse_free(ret_val20, env);
                                   adb_getSystemPermissionsOfRole_free(input_val20, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateSystemPermissionsOfSpecialInternalRole") == 0 )
                {

                    
                    input_val21 = adb_updateSystemPermissionsOfSpecialInternalRole_create( env);
                        if( AXIS2_FAILURE == adb_updateSystemPermissionsOfSpecialInternalRole_deserialize(input_val21, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateSystemPermissionsOfSpecialInternalRole_free(input_val21, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateSystemPermissionsOfSpecialInternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val21 =  axis2_skel_UserManagementService_updateSystemPermissionsOfSpecialInternalRole(env, msg_ctx,input_val21,
                                                (axis2_skel_UserManagementService_updateSystemPermissionsOfSpecialInternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val21 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateSystemPermissionsOfSpecialInternalRole ");
                        }
                        adb_updateSystemPermissionsOfSpecialInternalRole_free(input_val21, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateSystemPermissionsOfRole") == 0 )
                {

                    
                    input_val22 = adb_updateSystemPermissionsOfRole_create( env);
                        if( AXIS2_FAILURE == adb_updateSystemPermissionsOfRole_deserialize(input_val22, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateSystemPermissionsOfRole_free(input_val22, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateSystemPermissionsOfRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val22 =  axis2_skel_UserManagementService_updateSystemPermissionsOfRole(env, msg_ctx,input_val22,
                                                (axis2_skel_UserManagementService_updateSystemPermissionsOfRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val22 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateSystemPermissionsOfRole ");
                        }
                        adb_updateSystemPermissionsOfRole_free(input_val22, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getExternalUserStoreConfig") == 0 )
                {

                    
                        ret_val23 =  axis2_skel_UserManagementService_getExternalUserStoreConfig(env, msg_ctx,
                                                (axis2_skel_UserManagementService_getExternalUserStoreConfig_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val23 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getExternalUserStoreConfigResponse_serialize(ret_val23, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getExternalUserStoreConfigResponse_free(ret_val23, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getInternalUsers") == 0 )
                {

                    
                        ret_val24 =  axis2_skel_UserManagementService_getInternalUsers(env, msg_ctx,
                                                (axis2_skel_UserManagementService_getInternalUsers_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val24 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getInternalUsersResponse_serialize(ret_val24, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getInternalUsersResponse_free(ret_val24, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "hasExternalUserStore") == 0 )
                {

                    
                        ret_val25 =  axis2_skel_UserManagementService_hasExternalUserStore(env, msg_ctx,
                                                (axis2_skel_UserManagementService_hasExternalUserStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val25 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_hasExternalUserStoreResponse_serialize(ret_val25, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_hasExternalUserStoreResponse_free(ret_val25, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSystemPermissions") == 0 )
                {

                    
                        ret_val26 =  axis2_skel_UserManagementService_getSystemPermissions(env, msg_ctx,
                                                (axis2_skel_UserManagementService_getSystemPermissions_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val26 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemPermissionsResponse_serialize(ret_val26, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemPermissionsResponse_free(ret_val26, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateRoleName") == 0 )
                {

                    
                    input_val27 = adb_updateRoleName_create( env);
                        if( AXIS2_FAILURE == adb_updateRoleName_deserialize(input_val27, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateRoleName_free(input_val27, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateRoleName_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val27 =  axis2_skel_UserManagementService_updateRoleName(env, msg_ctx,input_val27,
                                                (axis2_skel_UserManagementService_updateRoleName_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val27 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateRoleName ");
                        }
                        adb_updateRoleName_free(input_val27, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateSystemPermissionsOfExternalRole") == 0 )
                {

                    
                    input_val28 = adb_updateSystemPermissionsOfExternalRole_create( env);
                        if( AXIS2_FAILURE == adb_updateSystemPermissionsOfExternalRole_deserialize(input_val28, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateSystemPermissionsOfExternalRole_free(input_val28, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateSystemPermissionsOfExternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val28 =  axis2_skel_UserManagementService_updateSystemPermissionsOfExternalRole(env, msg_ctx,input_val28,
                                                (axis2_skel_UserManagementService_updateSystemPermissionsOfExternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val28 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateSystemPermissionsOfExternalRole ");
                        }
                        adb_updateSystemPermissionsOfExternalRole_free(input_val28, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateUserName") == 0 )
                {

                    
                    input_val29 = adb_updateUserName_create( env);
                        if( AXIS2_FAILURE == adb_updateUserName_deserialize(input_val29, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateUserName_free(input_val29, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateUserName_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val29 =  axis2_skel_UserManagementService_updateUserName(env, msg_ctx,input_val29,
                                                (axis2_skel_UserManagementService_updateUserName_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val29 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateUserName ");
                        }
                        adb_updateUserName_free(input_val29, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addExternalUserStoreConfig") == 0 )
                {

                    
                    input_val30 = adb_addExternalUserStoreConfig_create( env);
                        if( AXIS2_FAILURE == adb_addExternalUserStoreConfig_deserialize(input_val30, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addExternalUserStoreConfig_free(input_val30, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addExternalUserStoreConfig_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val30 =  axis2_skel_UserManagementService_addExternalUserStoreConfig(env, msg_ctx,input_val30,
                                                (axis2_skel_UserManagementService_addExternalUserStoreConfig_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val30 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addExternalUserStoreConfig ");
                        }
                        adb_addExternalUserStoreConfig_free(input_val30, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addUserToInternalStore") == 0 )
                {

                    
                    input_val31 = adb_addUserToInternalStore_create( env);
                        if( AXIS2_FAILURE == adb_addUserToInternalStore_deserialize(input_val31, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addUserToInternalStore_free(input_val31, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addUserToInternalStore_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val31 =  axis2_skel_UserManagementService_addUserToInternalStore(env, msg_ctx,input_val31,
                                                (axis2_skel_UserManagementService_addUserToInternalStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val31 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addUserToInternalStore ");
                        }
                        adb_addUserToInternalStore_free(input_val31, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "listExternalUsers") == 0 )
                {

                    
                    input_val32 = adb_listExternalUsers_create( env);
                        if( AXIS2_FAILURE == adb_listExternalUsers_deserialize(input_val32, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listExternalUsers_free(input_val32, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listExternalUsers_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val32 =  axis2_skel_UserManagementService_listExternalUsers(env, msg_ctx,input_val32,
                                                (axis2_skel_UserManagementService_listExternalUsers_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val32 )
                        {
                            adb_listExternalUsers_free(input_val32, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listExternalUsersResponse_serialize(ret_val32, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listExternalUsersResponse_free(ret_val32, env);
                                   adb_listExternalUsers_free(input_val32, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSpecialInternalRoles") == 0 )
                {

                    
                        ret_val33 =  axis2_skel_UserManagementService_getSpecialInternalRoles(env, msg_ctx,
                                                (axis2_skel_UserManagementService_getSpecialInternalRoles_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val33 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getSpecialInternalRolesResponse_serialize(ret_val33, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSpecialInternalRolesResponse_free(ret_val33, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getUsersInExternalRole") == 0 )
                {

                    
                    input_val34 = adb_getUsersInExternalRole_create( env);
                        if( AXIS2_FAILURE == adb_getUsersInExternalRole_deserialize(input_val34, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getUsersInExternalRole_free(input_val34, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getUsersInExternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val34 =  axis2_skel_UserManagementService_getUsersInExternalRole(env, msg_ctx,input_val34,
                                                (axis2_skel_UserManagementService_getUsersInExternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val34 )
                        {
                            adb_getUsersInExternalRole_free(input_val34, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getUsersInExternalRoleResponse_serialize(ret_val34, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getUsersInExternalRoleResponse_free(ret_val34, env);
                                   adb_getUsersInExternalRole_free(input_val34, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "changePassword") == 0 )
                {

                    
                    input_val35 = adb_changePassword_create( env);
                        if( AXIS2_FAILURE == adb_changePassword_deserialize(input_val35, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_changePassword_free(input_val35, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_changePassword_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val35 =  axis2_skel_UserManagementService_changePassword(env, msg_ctx,input_val35,
                                                (axis2_skel_UserManagementService_changePassword_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val35 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from changePassword ");
                        }
                        adb_changePassword_free(input_val35, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getSystemPermissionsOfExternalRole") == 0 )
                {

                    
                    input_val36 = adb_getSystemPermissionsOfExternalRole_create( env);
                        if( AXIS2_FAILURE == adb_getSystemPermissionsOfExternalRole_deserialize(input_val36, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getSystemPermissionsOfExternalRole_free(input_val36, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getSystemPermissionsOfExternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val36 =  axis2_skel_UserManagementService_getSystemPermissionsOfExternalRole(env, msg_ctx,input_val36,
                                                (axis2_skel_UserManagementService_getSystemPermissionsOfExternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val36 )
                        {
                            adb_getSystemPermissionsOfExternalRole_free(input_val36, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemPermissionsOfExternalRoleResponse_serialize(ret_val36, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemPermissionsOfExternalRoleResponse_free(ret_val36, env);
                                   adb_getSystemPermissionsOfExternalRole_free(input_val36, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getUsersOfSpecialInternalRole") == 0 )
                {

                    
                    input_val37 = adb_getUsersOfSpecialInternalRole_create( env);
                        if( AXIS2_FAILURE == adb_getUsersOfSpecialInternalRole_deserialize(input_val37, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getUsersOfSpecialInternalRole_free(input_val37, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getUsersOfSpecialInternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val37 =  axis2_skel_UserManagementService_getUsersOfSpecialInternalRole(env, msg_ctx,input_val37,
                                                (axis2_skel_UserManagementService_getUsersOfSpecialInternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val37 )
                        {
                            adb_getUsersOfSpecialInternalRole_free(input_val37, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getUsersOfSpecialInternalRoleResponse_serialize(ret_val37, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getUsersOfSpecialInternalRoleResponse_free(ret_val37, env);
                                   adb_getUsersOfSpecialInternalRole_free(input_val37, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getUsersInRole") == 0 )
                {

                    
                    input_val38 = adb_getUsersInRole_create( env);
                        if( AXIS2_FAILURE == adb_getUsersInRole_deserialize(input_val38, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getUsersInRole_free(input_val38, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getUsersInRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val38 =  axis2_skel_UserManagementService_getUsersInRole(env, msg_ctx,input_val38,
                                                (axis2_skel_UserManagementService_getUsersInRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val38 )
                        {
                            adb_getUsersInRole_free(input_val38, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getUsersInRoleResponse_serialize(ret_val38, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getUsersInRoleResponse_free(ret_val38, env);
                                   adb_getUsersInRole_free(input_val38, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "addSpecialInternalRole") == 0 )
                {

                    
                    input_val39 = adb_addSpecialInternalRole_create( env);
                        if( AXIS2_FAILURE == adb_addSpecialInternalRole_deserialize(input_val39, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addSpecialInternalRole_free(input_val39, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addSpecialInternalRole_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val39 =  axis2_skel_UserManagementService_addSpecialInternalRole(env, msg_ctx,input_val39,
                                                (axis2_skel_UserManagementService_addSpecialInternalRole_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val39 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addSpecialInternalRole ");
                        }
                        adb_addSpecialInternalRole_free(input_val39, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_UserManagementService service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_UserManagementService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_UserManagementService_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_UserManagementService_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_USERMANAGEMENTSERVICE_ERROR_NONE ||
                error_code >= AXIS2_SKEL_USERMANAGEMENTSERVICE_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "UserManagementService|http://service.mgt.user.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_DELETEUSERFROMINTERNALSTORE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.deleteUserFromInternalStore_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.deleteUserFromInternalStore_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDROLETOINTERNALSTORE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.addRoleToInternalStore_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addRoleToInternalStore_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_DELETESPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.deleteSpecialInternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.deleteSpecialInternalRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETEXTERNALUSERS_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getExternalUsers_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getExternalUsers_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_DELETEEXTERNALUSERSTORE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.deleteExternalUserStore_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.deleteExternalUserStore_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEEXTERNALUSERSTORECONFIG_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateExternalUserStoreConfig_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateExternalUserStoreConfig_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDSYSTEMPERMISSIONSTOROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.addSystemPermissionsToRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addSystemPermissionsToRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETINTERNALROLES_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getInternalRoles_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getInternalRoles_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETALLROLESNAMES_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getAllRolesNames_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getAllRolesNames_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETEXTERNALGROUPS_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getExternalGroups_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getExternalGroups_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEROLESOFRESOURCE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateRolesofResource_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateRolesofResource_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_LISTINTERNALUSERS_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.listInternalUsers_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.listInternalUsers_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_TESTCONNECTION_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.testConnection_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.testConnection_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEUSERSOFSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateUsersOfSpecialInternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateUsersOfSpecialInternalRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSYSTEMPERMISSIONSOFSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getSystemPermissionsOfSpecialInternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getSystemPermissionsOfSpecialInternalRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDROLESTORESOURCE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.addRolesToResource_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addRolesToResource_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_DELETEROLEFROMINTERNALSTORE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.deleteRoleFromInternalStore_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.deleteRoleFromInternalStore_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETUSERROLES_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getUserRoles_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getUserRoles_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEUSERSOFROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateUsersOfRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateUsersOfRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSYSTEMPERMISSIONSOFROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getSystemPermissionsOfRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getSystemPermissionsOfRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATESYSTEMPERMISSIONSOFSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateSystemPermissionsOfSpecialInternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateSystemPermissionsOfSpecialInternalRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATESYSTEMPERMISSIONSOFROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateSystemPermissionsOfRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateSystemPermissionsOfRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETEXTERNALUSERSTORECONFIG_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getExternalUserStoreConfig_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getExternalUserStoreConfig_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETINTERNALUSERS_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getInternalUsers_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getInternalUsers_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_HASEXTERNALUSERSTORE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.hasExternalUserStore_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.hasExternalUserStore_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSYSTEMPERMISSIONS_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getSystemPermissions_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getSystemPermissions_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEROLENAME_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateRoleName_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateRoleName_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATESYSTEMPERMISSIONSOFEXTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateSystemPermissionsOfExternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateSystemPermissionsOfExternalRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_UPDATEUSERNAME_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.updateUserName_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateUserName_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDEXTERNALUSERSTORECONFIG_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.addExternalUserStoreConfig_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addExternalUserStoreConfig_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDUSERTOINTERNALSTORE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.addUserToInternalStore_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addUserToInternalStore_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_LISTEXTERNALUSERS_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.listExternalUsers_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.listExternalUsers_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSPECIALINTERNALROLES_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getSpecialInternalRoles_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getSpecialInternalRoles_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETUSERSINEXTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getUsersInExternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getUsersInExternalRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_CHANGEPASSWORD_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.changePassword_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.changePassword_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETSYSTEMPERMISSIONSOFEXTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getSystemPermissionsOfExternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getSystemPermissionsOfExternalRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETUSERSOFSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getUsersOfSpecialInternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getUsersOfSpecialInternalRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_GETUSERSINROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getUsersInRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getUsersInRole_fault.UserMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_USERMANAGEMENTSERVICE_ADDSPECIALINTERNALROLE_FAULT_USERMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_UserMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_UserMgtExceptionE0_t*)svc_skeleton_wrapper->fault.addSpecialInternalRole_fault.UserMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_UserMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_UserMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addSpecialInternalRole_fault.UserMgtException = NULL;
                    }

                }
            

		return error_node;
	}


	/**
	 * Following block distinguish the exposed part of the dll.
 	 */

    AXIS2_EXTERN int
    axis2_get_instance(struct axis2_svc_skeleton **inst,
	                        const axutil_env_t *env)
	{
		*inst = axis2_svc_skel_UserManagementService_create(env);

        if(!(*inst))
        {
            return AXIS2_FAILURE;
        }

  		return AXIS2_SUCCESS;
	}

	AXIS2_EXTERN int 
    axis2_remove_instance(axis2_svc_skeleton_t *inst,
                            const axutil_env_t *env)
	{
        axis2_status_t status = AXIS2_FAILURE;
       	if (inst)
        {
            status = AXIS2_SVC_SKELETON_FREE(inst, env);
        }
    	return status;
	}


    

