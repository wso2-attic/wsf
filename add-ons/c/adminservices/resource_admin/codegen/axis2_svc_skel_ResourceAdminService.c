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
         * axis2_svc_skel_ResourceAdminService.c
         *
         * This file was auto-generated from WSDL for "ResourceAdminService|http://services.resource.ui.mgt.registry.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_ResourceAdminService
         */

        #include "axis2_skel_ResourceAdminService.h"
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
                axis2_skel_ResourceAdminService_getMediatypeDefinitions_fault getMediatypeDefinitions_fault;
                    axis2_skel_ResourceAdminService_getResourceTreeEntry_fault getResourceTreeEntry_fault;
                    axis2_skel_ResourceAdminService_createVersion_fault createVersion_fault;
                    axis2_skel_ResourceAdminService_addRemoteLink_fault addRemoteLink_fault;
                    axis2_skel_ResourceAdminService_changeUserPermissions_fault changeUserPermissions_fault;
                    axis2_skel_ResourceAdminService__delete_fault _delete_fault;
                    axis2_skel_ResourceAdminService_updateTextContent_fault updateTextContent_fault;
                    axis2_skel_ResourceAdminService_renameResource_fault renameResource_fault;
                    axis2_skel_ResourceAdminService_moveResource_fault moveResource_fault;
                    axis2_skel_ResourceAdminService_getResourceData_fault getResourceData_fault;
                    axis2_skel_ResourceAdminService_importResource_fault importResource_fault;
                    axis2_skel_ResourceAdminService_addUserPermission_fault addUserPermission_fault;
                    axis2_skel_ResourceAdminService_restoreVersion_fault restoreVersion_fault;
                    axis2_skel_ResourceAdminService_addRolePermission_fault addRolePermission_fault;
                    axis2_skel_ResourceAdminService_getSessionResourcePath_fault getSessionResourcePath_fault;
                    axis2_skel_ResourceAdminService_addSymbolicLink_fault addSymbolicLink_fault;
                    axis2_skel_ResourceAdminService_getTextContent_fault getTextContent_fault;
                    axis2_skel_ResourceAdminService_getCollectionMediatypeDefinitions_fault getCollectionMediatypeDefinitions_fault;
                    axis2_skel_ResourceAdminService_getCollectionContent_fault getCollectionContent_fault;
                    axis2_skel_ResourceAdminService_setSessionResourcePath_fault setSessionResourcePath_fault;
                    axis2_skel_ResourceAdminService_changeRolePermissions_fault changeRolePermissions_fault;
                    axis2_skel_ResourceAdminService_getVersionsBean_fault getVersionsBean_fault;
                    axis2_skel_ResourceAdminService_setDescription_fault setDescription_fault;
                    axis2_skel_ResourceAdminService_addTextResource_fault addTextResource_fault;
                    axis2_skel_ResourceAdminService_getProperty_fault getProperty_fault;
                    axis2_skel_ResourceAdminService_getContentDownloadBean_fault getContentDownloadBean_fault;
                    axis2_skel_ResourceAdminService_getContentBean_fault getContentBean_fault;
                    axis2_skel_ResourceAdminService_addCollection_fault addCollection_fault;
                    axis2_skel_ResourceAdminService_getMetadata_fault getMetadata_fault;
                    axis2_skel_ResourceAdminService_getPermissions_fault getPermissions_fault;
                    axis2_skel_ResourceAdminService_copyResource_fault copyResource_fault;
                    axis2_skel_ResourceAdminService_addResource_fault addResource_fault;
                    axis2_skel_ResourceAdminService_getCustomUIMediatypeDefinitions_fault getCustomUIMediatypeDefinitions_fault;
                    
            } fault;
          
        }axis2_svc_skel_ResourceAdminService_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ResourceAdminService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_ResourceAdminService_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ResourceAdminService_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_ResourceAdminService_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_ResourceAdminService_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_ResourceAdminService_svc_skeleton_ops_var = {
            axis2_svc_skel_ResourceAdminService_init,
            axis2_svc_skel_ResourceAdminService_invoke,
            axis2_svc_skel_ResourceAdminService_on_fault,
            axis2_svc_skel_ResourceAdminService_free
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
	axis2_svc_skel_ResourceAdminService_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_ResourceAdminService_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_ResourceAdminService_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_ResourceAdminService_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_ResourceAdminService_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_ResourceAdminService_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_ResourceAdminService */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_ResourceAdminService_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_ResourceAdminService_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_ResourceAdminService_t *svc_skeleton_wrapper = NULL;

          
            adb_getMediatypeDefinitionsResponse_t* ret_val1;
            
            adb_getResourceTreeEntryResponse_t* ret_val2;
            adb_getResourceTreeEntry_t* input_val2;
            
            axis2_status_t ret_val3;
            adb_createVersion_t* input_val3;
            
            axis2_status_t ret_val4;
            adb_addRemoteLink_t* input_val4;
            
            adb_changeUserPermissionsResponse_t* ret_val5;
            adb_changeUserPermissions_t* input_val5;
            
            axis2_status_t ret_val6;
            adb__delete_t* input_val6;
            
            axis2_status_t ret_val7;
            adb_updateTextContent_t* input_val7;
            
            axis2_status_t ret_val8;
            adb_renameResource_t* input_val8;
            
            axis2_status_t ret_val9;
            adb_moveResource_t* input_val9;
            
            adb_getResourceDataResponse_t* ret_val10;
            adb_getResourceData_t* input_val10;
            
            axis2_status_t ret_val11;
            adb_importResource_t* input_val11;
            
            adb_addUserPermissionResponse_t* ret_val12;
            adb_addUserPermission_t* input_val12;
            
            axis2_status_t ret_val13;
            adb_restoreVersion_t* input_val13;
            
            adb_addRolePermissionResponse_t* ret_val14;
            adb_addRolePermission_t* input_val14;
            
            adb_getSessionResourcePathResponse_t* ret_val15;
            
            axis2_status_t ret_val16;
            adb_addSymbolicLink_t* input_val16;
            
            adb_getTextContentResponse_t* ret_val17;
            adb_getTextContent_t* input_val17;
            
            adb_getCollectionMediatypeDefinitionsResponse_t* ret_val18;
            
            adb_getCollectionContentResponse_t* ret_val19;
            adb_getCollectionContent_t* input_val19;
            
            axis2_status_t ret_val20;
            adb_setSessionResourcePath_t* input_val20;
            
            adb_changeRolePermissionsResponse_t* ret_val21;
            adb_changeRolePermissions_t* input_val21;
            
            adb_getVersionsBeanResponse_t* ret_val22;
            adb_getVersionsBean_t* input_val22;
            
            axis2_status_t ret_val23;
            adb_setDescription_t* input_val23;
            
            axis2_status_t ret_val24;
            adb_addTextResource_t* input_val24;
            
            adb_getPropertyResponse_t* ret_val25;
            adb_getProperty_t* input_val25;
            
            adb_getContentDownloadBeanResponse_t* ret_val26;
            adb_getContentDownloadBean_t* input_val26;
            
            adb_getContentBeanResponse_t* ret_val27;
            adb_getContentBean_t* input_val27;
            
            adb_addCollectionResponse_t* ret_val28;
            adb_addCollection_t* input_val28;
            
            adb_getMetadataResponse_t* ret_val29;
            adb_getMetadata_t* input_val29;
            
            adb_getPermissionsResponse_t* ret_val30;
            adb_getPermissions_t* input_val30;
            
            axis2_status_t ret_val31;
            adb_copyResource_t* input_val31;
            
            axis2_status_t ret_val32;
            adb_addResource_t* input_val32;
            
            adb_getCustomUIMediatypeDefinitionsResponse_t* ret_val33;
            

          svc_skeleton_wrapper = (axis2_svc_skel_ResourceAdminService_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "getMediatypeDefinitions") == 0 )
                {

                    
                        ret_val1 =  axis2_skel_ResourceAdminService_getMediatypeDefinitions(env, msg_ctx,
                                                (axis2_skel_ResourceAdminService_getMediatypeDefinitions_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val1 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getMediatypeDefinitionsResponse_serialize(ret_val1, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getMediatypeDefinitionsResponse_free(ret_val1, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getResourceTreeEntry") == 0 )
                {

                    
                    input_val2 = adb_getResourceTreeEntry_create( env);
                        if( AXIS2_FAILURE == adb_getResourceTreeEntry_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getResourceTreeEntry_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getResourceTreeEntry_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_ResourceAdminService_getResourceTreeEntry(env, msg_ctx,input_val2,
                                                (axis2_skel_ResourceAdminService_getResourceTreeEntry_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val2 )
                        {
                            adb_getResourceTreeEntry_free(input_val2, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getResourceTreeEntryResponse_serialize(ret_val2, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getResourceTreeEntryResponse_free(ret_val2, env);
                                   adb_getResourceTreeEntry_free(input_val2, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "createVersion") == 0 )
                {

                    
                    input_val3 = adb_createVersion_create( env);
                        if( AXIS2_FAILURE == adb_createVersion_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_createVersion_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_createVersion_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_ResourceAdminService_createVersion(env, msg_ctx,input_val3,
                                                (axis2_skel_ResourceAdminService_createVersion_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val3 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from createVersion ");
                        }
                        adb_createVersion_free(input_val3, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addRemoteLink") == 0 )
                {

                    
                    input_val4 = adb_addRemoteLink_create( env);
                        if( AXIS2_FAILURE == adb_addRemoteLink_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addRemoteLink_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addRemoteLink_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_ResourceAdminService_addRemoteLink(env, msg_ctx,input_val4,
                                                (axis2_skel_ResourceAdminService_addRemoteLink_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val4 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addRemoteLink ");
                        }
                        adb_addRemoteLink_free(input_val4, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "changeUserPermissions") == 0 )
                {

                    
                    input_val5 = adb_changeUserPermissions_create( env);
                        if( AXIS2_FAILURE == adb_changeUserPermissions_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_changeUserPermissions_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_changeUserPermissions_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_ResourceAdminService_changeUserPermissions(env, msg_ctx,input_val5,
                                                (axis2_skel_ResourceAdminService_changeUserPermissions_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val5 )
                        {
                            adb_changeUserPermissions_free(input_val5, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_changeUserPermissionsResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_changeUserPermissionsResponse_free(ret_val5, env);
                                   adb_changeUserPermissions_free(input_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "delete") == 0 )
                {

                    
                    input_val6 = adb__delete_create( env);
                        if( AXIS2_FAILURE == adb__delete_deserialize(input_val6, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb__delete_free(input_val6, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb__delete_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val6 =  axis2_skel_ResourceAdminService__delete(env, msg_ctx,input_val6,
                                                (axis2_skel_ResourceAdminService__delete_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val6 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from _delete ");
                        }
                        adb__delete_free(input_val6, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateTextContent") == 0 )
                {

                    
                    input_val7 = adb_updateTextContent_create( env);
                        if( AXIS2_FAILURE == adb_updateTextContent_deserialize(input_val7, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateTextContent_free(input_val7, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateTextContent_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val7 =  axis2_skel_ResourceAdminService_updateTextContent(env, msg_ctx,input_val7,
                                                (axis2_skel_ResourceAdminService_updateTextContent_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val7 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateTextContent ");
                        }
                        adb_updateTextContent_free(input_val7, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "renameResource") == 0 )
                {

                    
                    input_val8 = adb_renameResource_create( env);
                        if( AXIS2_FAILURE == adb_renameResource_deserialize(input_val8, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_renameResource_free(input_val8, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_renameResource_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val8 =  axis2_skel_ResourceAdminService_renameResource(env, msg_ctx,input_val8,
                                                (axis2_skel_ResourceAdminService_renameResource_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val8 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from renameResource ");
                        }
                        adb_renameResource_free(input_val8, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "moveResource") == 0 )
                {

                    
                    input_val9 = adb_moveResource_create( env);
                        if( AXIS2_FAILURE == adb_moveResource_deserialize(input_val9, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_moveResource_free(input_val9, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_moveResource_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val9 =  axis2_skel_ResourceAdminService_moveResource(env, msg_ctx,input_val9,
                                                (axis2_skel_ResourceAdminService_moveResource_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val9 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from moveResource ");
                        }
                        adb_moveResource_free(input_val9, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getResourceData") == 0 )
                {

                    
                    input_val10 = adb_getResourceData_create( env);
                        if( AXIS2_FAILURE == adb_getResourceData_deserialize(input_val10, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getResourceData_free(input_val10, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getResourceData_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val10 =  axis2_skel_ResourceAdminService_getResourceData(env, msg_ctx,input_val10,
                                                (axis2_skel_ResourceAdminService_getResourceData_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val10 )
                        {
                            adb_getResourceData_free(input_val10, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getResourceDataResponse_serialize(ret_val10, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getResourceDataResponse_free(ret_val10, env);
                                   adb_getResourceData_free(input_val10, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "importResource") == 0 )
                {

                    
                    input_val11 = adb_importResource_create( env);
                        if( AXIS2_FAILURE == adb_importResource_deserialize(input_val11, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_importResource_free(input_val11, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_importResource_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val11 =  axis2_skel_ResourceAdminService_importResource(env, msg_ctx,input_val11,
                                                (axis2_skel_ResourceAdminService_importResource_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val11 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from importResource ");
                        }
                        adb_importResource_free(input_val11, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addUserPermission") == 0 )
                {

                    
                    input_val12 = adb_addUserPermission_create( env);
                        if( AXIS2_FAILURE == adb_addUserPermission_deserialize(input_val12, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addUserPermission_free(input_val12, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addUserPermission_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val12 =  axis2_skel_ResourceAdminService_addUserPermission(env, msg_ctx,input_val12,
                                                (axis2_skel_ResourceAdminService_addUserPermission_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val12 )
                        {
                            adb_addUserPermission_free(input_val12, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_addUserPermissionResponse_serialize(ret_val12, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_addUserPermissionResponse_free(ret_val12, env);
                                   adb_addUserPermission_free(input_val12, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "restoreVersion") == 0 )
                {

                    
                    input_val13 = adb_restoreVersion_create( env);
                        if( AXIS2_FAILURE == adb_restoreVersion_deserialize(input_val13, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_restoreVersion_free(input_val13, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_restoreVersion_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val13 =  axis2_skel_ResourceAdminService_restoreVersion(env, msg_ctx,input_val13,
                                                (axis2_skel_ResourceAdminService_restoreVersion_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val13 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from restoreVersion ");
                        }
                        adb_restoreVersion_free(input_val13, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addRolePermission") == 0 )
                {

                    
                    input_val14 = adb_addRolePermission_create( env);
                        if( AXIS2_FAILURE == adb_addRolePermission_deserialize(input_val14, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addRolePermission_free(input_val14, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addRolePermission_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val14 =  axis2_skel_ResourceAdminService_addRolePermission(env, msg_ctx,input_val14,
                                                (axis2_skel_ResourceAdminService_addRolePermission_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val14 )
                        {
                            adb_addRolePermission_free(input_val14, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_addRolePermissionResponse_serialize(ret_val14, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_addRolePermissionResponse_free(ret_val14, env);
                                   adb_addRolePermission_free(input_val14, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSessionResourcePath") == 0 )
                {

                    
                        ret_val15 =  axis2_skel_ResourceAdminService_getSessionResourcePath(env, msg_ctx,
                                                (axis2_skel_ResourceAdminService_getSessionResourcePath_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val15 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getSessionResourcePathResponse_serialize(ret_val15, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSessionResourcePathResponse_free(ret_val15, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "addSymbolicLink") == 0 )
                {

                    
                    input_val16 = adb_addSymbolicLink_create( env);
                        if( AXIS2_FAILURE == adb_addSymbolicLink_deserialize(input_val16, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addSymbolicLink_free(input_val16, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addSymbolicLink_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val16 =  axis2_skel_ResourceAdminService_addSymbolicLink(env, msg_ctx,input_val16,
                                                (axis2_skel_ResourceAdminService_addSymbolicLink_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val16 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addSymbolicLink ");
                        }
                        adb_addSymbolicLink_free(input_val16, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getTextContent") == 0 )
                {

                    
                    input_val17 = adb_getTextContent_create( env);
                        if( AXIS2_FAILURE == adb_getTextContent_deserialize(input_val17, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getTextContent_free(input_val17, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getTextContent_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val17 =  axis2_skel_ResourceAdminService_getTextContent(env, msg_ctx,input_val17,
                                                (axis2_skel_ResourceAdminService_getTextContent_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val17 )
                        {
                            adb_getTextContent_free(input_val17, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getTextContentResponse_serialize(ret_val17, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getTextContentResponse_free(ret_val17, env);
                                   adb_getTextContent_free(input_val17, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getCollectionMediatypeDefinitions") == 0 )
                {

                    
                        ret_val18 =  axis2_skel_ResourceAdminService_getCollectionMediatypeDefinitions(env, msg_ctx,
                                                (axis2_skel_ResourceAdminService_getCollectionMediatypeDefinitions_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val18 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getCollectionMediatypeDefinitionsResponse_serialize(ret_val18, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getCollectionMediatypeDefinitionsResponse_free(ret_val18, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getCollectionContent") == 0 )
                {

                    
                    input_val19 = adb_getCollectionContent_create( env);
                        if( AXIS2_FAILURE == adb_getCollectionContent_deserialize(input_val19, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getCollectionContent_free(input_val19, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getCollectionContent_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val19 =  axis2_skel_ResourceAdminService_getCollectionContent(env, msg_ctx,input_val19,
                                                (axis2_skel_ResourceAdminService_getCollectionContent_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val19 )
                        {
                            adb_getCollectionContent_free(input_val19, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getCollectionContentResponse_serialize(ret_val19, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getCollectionContentResponse_free(ret_val19, env);
                                   adb_getCollectionContent_free(input_val19, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setSessionResourcePath") == 0 )
                {

                    
                    input_val20 = adb_setSessionResourcePath_create( env);
                        if( AXIS2_FAILURE == adb_setSessionResourcePath_deserialize(input_val20, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setSessionResourcePath_free(input_val20, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setSessionResourcePath_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val20 =  axis2_skel_ResourceAdminService_setSessionResourcePath(env, msg_ctx,input_val20,
                                                (axis2_skel_ResourceAdminService_setSessionResourcePath_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val20 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setSessionResourcePath ");
                        }
                        adb_setSessionResourcePath_free(input_val20, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "changeRolePermissions") == 0 )
                {

                    
                    input_val21 = adb_changeRolePermissions_create( env);
                        if( AXIS2_FAILURE == adb_changeRolePermissions_deserialize(input_val21, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_changeRolePermissions_free(input_val21, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_changeRolePermissions_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val21 =  axis2_skel_ResourceAdminService_changeRolePermissions(env, msg_ctx,input_val21,
                                                (axis2_skel_ResourceAdminService_changeRolePermissions_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val21 )
                        {
                            adb_changeRolePermissions_free(input_val21, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_changeRolePermissionsResponse_serialize(ret_val21, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_changeRolePermissionsResponse_free(ret_val21, env);
                                   adb_changeRolePermissions_free(input_val21, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getVersionsBean") == 0 )
                {

                    
                    input_val22 = adb_getVersionsBean_create( env);
                        if( AXIS2_FAILURE == adb_getVersionsBean_deserialize(input_val22, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getVersionsBean_free(input_val22, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getVersionsBean_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val22 =  axis2_skel_ResourceAdminService_getVersionsBean(env, msg_ctx,input_val22,
                                                (axis2_skel_ResourceAdminService_getVersionsBean_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val22 )
                        {
                            adb_getVersionsBean_free(input_val22, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getVersionsBeanResponse_serialize(ret_val22, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getVersionsBeanResponse_free(ret_val22, env);
                                   adb_getVersionsBean_free(input_val22, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setDescription") == 0 )
                {

                    
                    input_val23 = adb_setDescription_create( env);
                        if( AXIS2_FAILURE == adb_setDescription_deserialize(input_val23, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setDescription_free(input_val23, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setDescription_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val23 =  axis2_skel_ResourceAdminService_setDescription(env, msg_ctx,input_val23,
                                                (axis2_skel_ResourceAdminService_setDescription_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val23 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setDescription ");
                        }
                        adb_setDescription_free(input_val23, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addTextResource") == 0 )
                {

                    
                    input_val24 = adb_addTextResource_create( env);
                        if( AXIS2_FAILURE == adb_addTextResource_deserialize(input_val24, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addTextResource_free(input_val24, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addTextResource_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val24 =  axis2_skel_ResourceAdminService_addTextResource(env, msg_ctx,input_val24,
                                                (axis2_skel_ResourceAdminService_addTextResource_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val24 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addTextResource ");
                        }
                        adb_addTextResource_free(input_val24, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getProperty") == 0 )
                {

                    
                    input_val25 = adb_getProperty_create( env);
                        if( AXIS2_FAILURE == adb_getProperty_deserialize(input_val25, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getProperty_free(input_val25, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getProperty_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val25 =  axis2_skel_ResourceAdminService_getProperty(env, msg_ctx,input_val25,
                                                (axis2_skel_ResourceAdminService_getProperty_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val25 )
                        {
                            adb_getProperty_free(input_val25, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getPropertyResponse_serialize(ret_val25, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getPropertyResponse_free(ret_val25, env);
                                   adb_getProperty_free(input_val25, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getContentDownloadBean") == 0 )
                {

                    
                    input_val26 = adb_getContentDownloadBean_create( env);
                        if( AXIS2_FAILURE == adb_getContentDownloadBean_deserialize(input_val26, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getContentDownloadBean_free(input_val26, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getContentDownloadBean_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val26 =  axis2_skel_ResourceAdminService_getContentDownloadBean(env, msg_ctx,input_val26,
                                                (axis2_skel_ResourceAdminService_getContentDownloadBean_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val26 )
                        {
                            adb_getContentDownloadBean_free(input_val26, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getContentDownloadBeanResponse_serialize(ret_val26, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getContentDownloadBeanResponse_free(ret_val26, env);
                                   adb_getContentDownloadBean_free(input_val26, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getContentBean") == 0 )
                {

                    
                    input_val27 = adb_getContentBean_create( env);
                        if( AXIS2_FAILURE == adb_getContentBean_deserialize(input_val27, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getContentBean_free(input_val27, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getContentBean_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val27 =  axis2_skel_ResourceAdminService_getContentBean(env, msg_ctx,input_val27,
                                                (axis2_skel_ResourceAdminService_getContentBean_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val27 )
                        {
                            adb_getContentBean_free(input_val27, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getContentBeanResponse_serialize(ret_val27, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getContentBeanResponse_free(ret_val27, env);
                                   adb_getContentBean_free(input_val27, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "addCollection") == 0 )
                {

                    
                    input_val28 = adb_addCollection_create( env);
                        if( AXIS2_FAILURE == adb_addCollection_deserialize(input_val28, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addCollection_free(input_val28, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addCollection_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val28 =  axis2_skel_ResourceAdminService_addCollection(env, msg_ctx,input_val28,
                                                (axis2_skel_ResourceAdminService_addCollection_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val28 )
                        {
                            adb_addCollection_free(input_val28, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_addCollectionResponse_serialize(ret_val28, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_addCollectionResponse_free(ret_val28, env);
                                   adb_addCollection_free(input_val28, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getMetadata") == 0 )
                {

                    
                    input_val29 = adb_getMetadata_create( env);
                        if( AXIS2_FAILURE == adb_getMetadata_deserialize(input_val29, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getMetadata_free(input_val29, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMetadata_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val29 =  axis2_skel_ResourceAdminService_getMetadata(env, msg_ctx,input_val29,
                                                (axis2_skel_ResourceAdminService_getMetadata_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val29 )
                        {
                            adb_getMetadata_free(input_val29, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getMetadataResponse_serialize(ret_val29, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getMetadataResponse_free(ret_val29, env);
                                   adb_getMetadata_free(input_val29, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getPermissions") == 0 )
                {

                    
                    input_val30 = adb_getPermissions_create( env);
                        if( AXIS2_FAILURE == adb_getPermissions_deserialize(input_val30, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getPermissions_free(input_val30, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getPermissions_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val30 =  axis2_skel_ResourceAdminService_getPermissions(env, msg_ctx,input_val30,
                                                (axis2_skel_ResourceAdminService_getPermissions_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val30 )
                        {
                            adb_getPermissions_free(input_val30, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getPermissionsResponse_serialize(ret_val30, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getPermissionsResponse_free(ret_val30, env);
                                   adb_getPermissions_free(input_val30, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "copyResource") == 0 )
                {

                    
                    input_val31 = adb_copyResource_create( env);
                        if( AXIS2_FAILURE == adb_copyResource_deserialize(input_val31, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_copyResource_free(input_val31, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_copyResource_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val31 =  axis2_skel_ResourceAdminService_copyResource(env, msg_ctx,input_val31,
                                                (axis2_skel_ResourceAdminService_copyResource_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val31 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from copyResource ");
                        }
                        adb_copyResource_free(input_val31, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "addResource") == 0 )
                {

                    
                    input_val32 = adb_addResource_create( env);
                        if( AXIS2_FAILURE == adb_addResource_deserialize(input_val32, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addResource_free(input_val32, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addResource_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val32 =  axis2_skel_ResourceAdminService_addResource(env, msg_ctx,input_val32,
                                                (axis2_skel_ResourceAdminService_addResource_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val32 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addResource ");
                        }
                        adb_addResource_free(input_val32, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getCustomUIMediatypeDefinitions") == 0 )
                {

                    
                        ret_val33 =  axis2_skel_ResourceAdminService_getCustomUIMediatypeDefinitions(env, msg_ctx,
                                                (axis2_skel_ResourceAdminService_getCustomUIMediatypeDefinitions_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val33 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getCustomUIMediatypeDefinitionsResponse_serialize(ret_val33, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getCustomUIMediatypeDefinitionsResponse_free(ret_val33, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_ResourceAdminService service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_ResourceAdminService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_ResourceAdminService_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_ResourceAdminService_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_RESOURCEADMINSERVICE_ERROR_NONE ||
                error_code >= AXIS2_SKEL_RESOURCEADMINSERVICE_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "ResourceAdminService|http://services.resource.ui.mgt.registry.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETMEDIATYPEDEFINITIONS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getMediatypeDefinitions_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getMediatypeDefinitions_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETRESOURCETREEENTRY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getResourceTreeEntry_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getResourceTreeEntry_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_CREATEVERSION_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.createVersion_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.createVersion_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_ADDREMOTELINK_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.addRemoteLink_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addRemoteLink_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_CHANGEUSERPERMISSIONS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.changeUserPermissions_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.changeUserPermissions_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE__DELETE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault._delete_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault._delete_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_UPDATETEXTCONTENT_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.updateTextContent_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateTextContent_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_RENAMERESOURCE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.renameResource_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.renameResource_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_MOVERESOURCE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.moveResource_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.moveResource_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETRESOURCEDATA_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getResourceData_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getResourceData_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_IMPORTRESOURCE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.importResource_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.importResource_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_ADDUSERPERMISSION_FAULT_RESOURCESERVICEEXCEPTION)
                {
                    /* found which error code */
                    adb_ResourceServiceExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ResourceServiceExceptionE0_t*)svc_skeleton_wrapper->fault.addUserPermission_fault.ResourceServiceException;
                    if(adb_obj)
                    {
                        error_node = adb_ResourceServiceExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ResourceServiceExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addUserPermission_fault.ResourceServiceException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_RESTOREVERSION_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.restoreVersion_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.restoreVersion_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_ADDROLEPERMISSION_FAULT_RESOURCESERVICEEXCEPTION)
                {
                    /* found which error code */
                    adb_ResourceServiceExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ResourceServiceExceptionE0_t*)svc_skeleton_wrapper->fault.addRolePermission_fault.ResourceServiceException;
                    if(adb_obj)
                    {
                        error_node = adb_ResourceServiceExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ResourceServiceExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addRolePermission_fault.ResourceServiceException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETSESSIONRESOURCEPATH_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getSessionResourcePath_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getSessionResourcePath_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_ADDSYMBOLICLINK_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.addSymbolicLink_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addSymbolicLink_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETTEXTCONTENT_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getTextContent_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getTextContent_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETCOLLECTIONMEDIATYPEDEFINITIONS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getCollectionMediatypeDefinitions_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getCollectionMediatypeDefinitions_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETCOLLECTIONCONTENT_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getCollectionContent_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getCollectionContent_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_SETSESSIONRESOURCEPATH_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.setSessionResourcePath_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setSessionResourcePath_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_CHANGEROLEPERMISSIONS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.changeRolePermissions_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.changeRolePermissions_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETVERSIONSBEAN_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getVersionsBean_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getVersionsBean_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_SETDESCRIPTION_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.setDescription_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setDescription_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_ADDTEXTRESOURCE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.addTextResource_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addTextResource_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETPROPERTY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getProperty_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getProperty_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETCONTENTDOWNLOADBEAN_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getContentDownloadBean_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getContentDownloadBean_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETCONTENTBEAN_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getContentBean_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getContentBean_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_ADDCOLLECTION_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.addCollection_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addCollection_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETMETADATA_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getMetadata_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getMetadata_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETPERMISSIONS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getPermissions_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getPermissions_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_COPYRESOURCE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.copyResource_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.copyResource_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_ADDRESOURCE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.addResource_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addResource_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_RESOURCEADMINSERVICE_GETCUSTOMUIMEDIATYPEDEFINITIONS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE1_t*)svc_skeleton_wrapper->fault.getCustomUIMediatypeDefinitions_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getCustomUIMediatypeDefinitions_fault.Exception = NULL;
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
		*inst = axis2_svc_skel_ResourceAdminService_create(env);

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


    

