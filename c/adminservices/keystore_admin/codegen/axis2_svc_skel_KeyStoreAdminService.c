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
         * axis2_svc_skel_KeyStoreAdminService.c
         *
         * This file was auto-generated from WSDL for "KeyStoreAdminService|http://service.keystore.security.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_KeyStoreAdminService
         */

        #include "axis2_skel_KeyStoreAdminService.h"
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
                axis2_skel_KeyStoreAdminService_getStoreEntries_fault getStoreEntries_fault;
                    axis2_skel_KeyStoreAdminService_addKeyStore_fault addKeyStore_fault;
                    axis2_skel_KeyStoreAdminService_importCertToStore_fault importCertToStore_fault;
                    axis2_skel_KeyStoreAdminService_getKeystoreInfo_fault getKeystoreInfo_fault;
                    axis2_skel_KeyStoreAdminService_deleteStore_fault deleteStore_fault;
                    axis2_skel_KeyStoreAdminService_getKeyStores_fault getKeyStores_fault;
                    
            } fault;
          
        }axis2_svc_skel_KeyStoreAdminService_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_KeyStoreAdminService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_KeyStoreAdminService_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_KeyStoreAdminService_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_KeyStoreAdminService_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_KeyStoreAdminService_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_KeyStoreAdminService_svc_skeleton_ops_var = {
            axis2_svc_skel_KeyStoreAdminService_init,
            axis2_svc_skel_KeyStoreAdminService_invoke,
            axis2_svc_skel_KeyStoreAdminService_on_fault,
            axis2_svc_skel_KeyStoreAdminService_free
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
	axis2_svc_skel_KeyStoreAdminService_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_KeyStoreAdminService_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_KeyStoreAdminService_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_KeyStoreAdminService_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_KeyStoreAdminService_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_KeyStoreAdminService_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_KeyStoreAdminService */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_KeyStoreAdminService_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_KeyStoreAdminService_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_KeyStoreAdminService_t *svc_skeleton_wrapper = NULL;

          
            adb_getStoreEntriesResponse_t* ret_val1;
            adb_getStoreEntries_t* input_val1;
            
            axis2_status_t ret_val2;
            adb_addKeyStore_t* input_val2;
            
            axis2_status_t ret_val3;
            adb_importCertToStore_t* input_val3;
            
            adb_getKeystoreInfoResponse_t* ret_val4;
            adb_getKeystoreInfo_t* input_val4;
            
            axis2_status_t ret_val5;
            adb_deleteStore_t* input_val5;
            
            adb_getKeyStoresResponse_t* ret_val6;
            

          svc_skeleton_wrapper = (axis2_svc_skel_KeyStoreAdminService_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "getStoreEntries") == 0 )
                {

                    
                    input_val1 = adb_getStoreEntries_create( env);
                        if( AXIS2_FAILURE == adb_getStoreEntries_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getStoreEntries_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getStoreEntries_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_KeyStoreAdminService_getStoreEntries(env, msg_ctx,input_val1,
                                                (axis2_skel_KeyStoreAdminService_getStoreEntries_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val1 )
                        {
                            adb_getStoreEntries_free(input_val1, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getStoreEntriesResponse_serialize(ret_val1, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getStoreEntriesResponse_free(ret_val1, env);
                                   adb_getStoreEntries_free(input_val1, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "addKeyStore") == 0 )
                {

                    
                    input_val2 = adb_addKeyStore_create( env);
                        if( AXIS2_FAILURE == adb_addKeyStore_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addKeyStore_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addKeyStore_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_KeyStoreAdminService_addKeyStore(env, msg_ctx,input_val2,
                                                (axis2_skel_KeyStoreAdminService_addKeyStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val2 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addKeyStore ");
                        }
                        adb_addKeyStore_free(input_val2, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "importCertToStore") == 0 )
                {

                    
                    input_val3 = adb_importCertToStore_create( env);
                        if( AXIS2_FAILURE == adb_importCertToStore_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_importCertToStore_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_importCertToStore_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_KeyStoreAdminService_importCertToStore(env, msg_ctx,input_val3,
                                                (axis2_skel_KeyStoreAdminService_importCertToStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val3 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from importCertToStore ");
                        }
                        adb_importCertToStore_free(input_val3, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getKeystoreInfo") == 0 )
                {

                    
                    input_val4 = adb_getKeystoreInfo_create( env);
                        if( AXIS2_FAILURE == adb_getKeystoreInfo_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getKeystoreInfo_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getKeystoreInfo_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_KeyStoreAdminService_getKeystoreInfo(env, msg_ctx,input_val4,
                                                (axis2_skel_KeyStoreAdminService_getKeystoreInfo_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val4 )
                        {
                            adb_getKeystoreInfo_free(input_val4, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getKeystoreInfoResponse_serialize(ret_val4, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getKeystoreInfoResponse_free(ret_val4, env);
                                   adb_getKeystoreInfo_free(input_val4, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "deleteStore") == 0 )
                {

                    
                    input_val5 = adb_deleteStore_create( env);
                        if( AXIS2_FAILURE == adb_deleteStore_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_deleteStore_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_deleteStore_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_KeyStoreAdminService_deleteStore(env, msg_ctx,input_val5,
                                                (axis2_skel_KeyStoreAdminService_deleteStore_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val5 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteStore ");
                        }
                        adb_deleteStore_free(input_val5, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getKeyStores") == 0 )
                {

                    
                        ret_val6 =  axis2_skel_KeyStoreAdminService_getKeyStores(env, msg_ctx,
                                                (axis2_skel_KeyStoreAdminService_getKeyStores_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val6 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getKeyStoresResponse_serialize(ret_val6, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getKeyStoresResponse_free(ret_val6, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_KeyStoreAdminService service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_KeyStoreAdminService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_KeyStoreAdminService_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_KeyStoreAdminService_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_KEYSTOREADMINSERVICE_ERROR_NONE ||
                error_code >= AXIS2_SKEL_KEYSTOREADMINSERVICE_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "KeyStoreAdminService|http://service.keystore.security.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_KEYSTOREADMINSERVICE_GETSTOREENTRIES_FAULT_SECURITYCONFIGEXCEPTION)
                {
                    /* found which error code */
                    adb_SecurityConfigExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_SecurityConfigExceptionE0_t*)svc_skeleton_wrapper->fault.getStoreEntries_fault.SecurityConfigException;
                    if(adb_obj)
                    {
                        error_node = adb_SecurityConfigExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_SecurityConfigExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getStoreEntries_fault.SecurityConfigException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_KEYSTOREADMINSERVICE_ADDKEYSTORE_FAULT_SECURITYCONFIGEXCEPTION)
                {
                    /* found which error code */
                    adb_SecurityConfigExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_SecurityConfigExceptionE0_t*)svc_skeleton_wrapper->fault.addKeyStore_fault.SecurityConfigException;
                    if(adb_obj)
                    {
                        error_node = adb_SecurityConfigExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_SecurityConfigExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addKeyStore_fault.SecurityConfigException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_KEYSTOREADMINSERVICE_IMPORTCERTTOSTORE_FAULT_SECURITYCONFIGEXCEPTION)
                {
                    /* found which error code */
                    adb_SecurityConfigExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_SecurityConfigExceptionE0_t*)svc_skeleton_wrapper->fault.importCertToStore_fault.SecurityConfigException;
                    if(adb_obj)
                    {
                        error_node = adb_SecurityConfigExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_SecurityConfigExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.importCertToStore_fault.SecurityConfigException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_KEYSTOREADMINSERVICE_GETKEYSTOREINFO_FAULT_SECURITYCONFIGEXCEPTION)
                {
                    /* found which error code */
                    adb_SecurityConfigExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_SecurityConfigExceptionE0_t*)svc_skeleton_wrapper->fault.getKeystoreInfo_fault.SecurityConfigException;
                    if(adb_obj)
                    {
                        error_node = adb_SecurityConfigExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_SecurityConfigExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getKeystoreInfo_fault.SecurityConfigException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_KEYSTOREADMINSERVICE_DELETESTORE_FAULT_SECURITYCONFIGEXCEPTION)
                {
                    /* found which error code */
                    adb_SecurityConfigExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_SecurityConfigExceptionE0_t*)svc_skeleton_wrapper->fault.deleteStore_fault.SecurityConfigException;
                    if(adb_obj)
                    {
                        error_node = adb_SecurityConfigExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_SecurityConfigExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.deleteStore_fault.SecurityConfigException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_KEYSTOREADMINSERVICE_GETKEYSTORES_FAULT_SECURITYCONFIGEXCEPTION)
                {
                    /* found which error code */
                    adb_SecurityConfigExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_SecurityConfigExceptionE0_t*)svc_skeleton_wrapper->fault.getKeyStores_fault.SecurityConfigException;
                    if(adb_obj)
                    {
                        error_node = adb_SecurityConfigExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_SecurityConfigExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getKeyStores_fault.SecurityConfigException = NULL;
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
		*inst = axis2_svc_skel_KeyStoreAdminService_create(env);

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


    

