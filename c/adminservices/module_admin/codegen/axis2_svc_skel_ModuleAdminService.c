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
         * axis2_svc_skel_ModuleAdminService.c
         *
         * This file was auto-generated from WSDL for "ModuleAdminService|http://service.mgt.module.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_ModuleAdminService
         */

        #include "axis2_skel_ModuleAdminService.h"
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
                axis2_skel_ModuleAdminService_engageModuleForService_fault engageModuleForService_fault;
                    axis2_skel_ModuleAdminService_disengageModuleFromSystem_fault disengageModuleFromSystem_fault;
                    axis2_skel_ModuleAdminService_disengageModuleForService_fault disengageModuleForService_fault;
                    axis2_skel_ModuleAdminService_setModuleParameters_fault setModuleParameters_fault;
                    axis2_skel_ModuleAdminService_removeModule_fault removeModule_fault;
                    axis2_skel_ModuleAdminService_removeModuleParameter_fault removeModuleParameter_fault;
                    axis2_skel_ModuleAdminService_getModuleParameters_fault getModuleParameters_fault;
                    axis2_skel_ModuleAdminService_engageModuleForOperation_fault engageModuleForOperation_fault;
                    axis2_skel_ModuleAdminService_globallyEngageModule_fault globallyEngageModule_fault;
                    axis2_skel_ModuleAdminService_engageModuleForServiceGroup_fault engageModuleForServiceGroup_fault;
                    axis2_skel_ModuleAdminService_listModulesForOperation_fault listModulesForOperation_fault;
                    axis2_skel_ModuleAdminService_listModulesForService_fault listModulesForService_fault;
                    axis2_skel_ModuleAdminService_disengageModuleForServiceGroup_fault disengageModuleForServiceGroup_fault;
                    axis2_skel_ModuleAdminService_globallyDisengageModule_fault globallyDisengageModule_fault;
                    axis2_skel_ModuleAdminService_listModulesForServiceGroup_fault listModulesForServiceGroup_fault;
                    axis2_skel_ModuleAdminService_disengageModuleForOperation_fault disengageModuleForOperation_fault;
                    axis2_skel_ModuleAdminService_getModuleInfo_fault getModuleInfo_fault;
                    
            } fault;
          
        }axis2_svc_skel_ModuleAdminService_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ModuleAdminService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_ModuleAdminService_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ModuleAdminService_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_ModuleAdminService_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_ModuleAdminService_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_ModuleAdminService_svc_skeleton_ops_var = {
            axis2_svc_skel_ModuleAdminService_init,
            axis2_svc_skel_ModuleAdminService_invoke,
            axis2_svc_skel_ModuleAdminService_on_fault,
            axis2_svc_skel_ModuleAdminService_free
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
	axis2_svc_skel_ModuleAdminService_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_ModuleAdminService_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_ModuleAdminService_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_ModuleAdminService_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_ModuleAdminService_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_ModuleAdminService_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_ModuleAdminService */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_ModuleAdminService_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_ModuleAdminService_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_ModuleAdminService_t *svc_skeleton_wrapper = NULL;

          
            adb_engageModuleForServiceResponse_t* ret_val1;
            adb_engageModuleForService_t* input_val1;
            
            adb_disengageModuleFromSystemResponse_t* ret_val2;
            adb_disengageModuleFromSystem_t* input_val2;
            
            adb_disengageModuleForServiceResponse_t* ret_val3;
            adb_disengageModuleForService_t* input_val3;
            
            axis2_status_t ret_val4;
            adb_setModuleParameters_t* input_val4;
            
            adb_removeModuleResponse_t* ret_val5;
            adb_removeModule_t* input_val5;
            
            adb_removeModuleParameterResponse_t* ret_val6;
            adb_removeModuleParameter_t* input_val6;
            
            adb_getModuleParametersResponse_t* ret_val7;
            adb_getModuleParameters_t* input_val7;
            
            adb_engageModuleForOperationResponse_t* ret_val8;
            adb_engageModuleForOperation_t* input_val8;
            
            adb_listGloballyEngagedModulesResponse_t* ret_val9;
            
            adb_globallyEngageModuleResponse_t* ret_val10;
            adb_globallyEngageModule_t* input_val10;
            
            adb_engageModuleForServiceGroupResponse_t* ret_val11;
            adb_engageModuleForServiceGroup_t* input_val11;
            
            adb_uploadModuleResponse_t* ret_val12;
            adb_uploadModule_t* input_val12;
            
            adb_listModulesForOperationResponse_t* ret_val13;
            adb_listModulesForOperation_t* input_val13;
            
            adb_listModulesForServiceResponse_t* ret_val14;
            adb_listModulesForService_t* input_val14;
            
            adb_disengageModuleForServiceGroupResponse_t* ret_val15;
            adb_disengageModuleForServiceGroup_t* input_val15;
            
            adb_globallyDisengageModuleResponse_t* ret_val16;
            adb_globallyDisengageModule_t* input_val16;
            
            adb_listModulesResponse_t* ret_val17;
            
            adb_listModulesForServiceGroupResponse_t* ret_val18;
            adb_listModulesForServiceGroup_t* input_val18;
            
            adb_disengageModuleForOperationResponse_t* ret_val19;
            adb_disengageModuleForOperation_t* input_val19;
            
            adb_getModuleInfoResponse_t* ret_val20;
            adb_getModuleInfo_t* input_val20;
            

          svc_skeleton_wrapper = (axis2_svc_skel_ModuleAdminService_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "engageModuleForService") == 0 )
                {

                    
                    input_val1 = adb_engageModuleForService_create( env);
                        if( AXIS2_FAILURE == adb_engageModuleForService_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_engageModuleForService_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_engageModuleForService_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_ModuleAdminService_engageModuleForService(env, msg_ctx,input_val1,
                                                (axis2_skel_ModuleAdminService_engageModuleForService_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val1 )
                        {
                            adb_engageModuleForService_free(input_val1, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_engageModuleForServiceResponse_serialize(ret_val1, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_engageModuleForServiceResponse_free(ret_val1, env);
                                   adb_engageModuleForService_free(input_val1, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "disengageModuleFromSystem") == 0 )
                {

                    
                    input_val2 = adb_disengageModuleFromSystem_create( env);
                        if( AXIS2_FAILURE == adb_disengageModuleFromSystem_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_disengageModuleFromSystem_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_disengageModuleFromSystem_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_ModuleAdminService_disengageModuleFromSystem(env, msg_ctx,input_val2,
                                                (axis2_skel_ModuleAdminService_disengageModuleFromSystem_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val2 )
                        {
                            adb_disengageModuleFromSystem_free(input_val2, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_disengageModuleFromSystemResponse_serialize(ret_val2, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_disengageModuleFromSystemResponse_free(ret_val2, env);
                                   adb_disengageModuleFromSystem_free(input_val2, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "disengageModuleForService") == 0 )
                {

                    
                    input_val3 = adb_disengageModuleForService_create( env);
                        if( AXIS2_FAILURE == adb_disengageModuleForService_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_disengageModuleForService_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_disengageModuleForService_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_ModuleAdminService_disengageModuleForService(env, msg_ctx,input_val3,
                                                (axis2_skel_ModuleAdminService_disengageModuleForService_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val3 )
                        {
                            adb_disengageModuleForService_free(input_val3, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_disengageModuleForServiceResponse_serialize(ret_val3, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_disengageModuleForServiceResponse_free(ret_val3, env);
                                   adb_disengageModuleForService_free(input_val3, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setModuleParameters") == 0 )
                {

                    
                    input_val4 = adb_setModuleParameters_create( env);
                        if( AXIS2_FAILURE == adb_setModuleParameters_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setModuleParameters_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setModuleParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_ModuleAdminService_setModuleParameters(env, msg_ctx,input_val4,
                                                (axis2_skel_ModuleAdminService_setModuleParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val4 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setModuleParameters ");
                        }
                        adb_setModuleParameters_free(input_val4, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "removeModule") == 0 )
                {

                    
                    input_val5 = adb_removeModule_create( env);
                        if( AXIS2_FAILURE == adb_removeModule_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeModule_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeModule_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_ModuleAdminService_removeModule(env, msg_ctx,input_val5,
                                                (axis2_skel_ModuleAdminService_removeModule_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val5 )
                        {
                            adb_removeModule_free(input_val5, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_removeModuleResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_removeModuleResponse_free(ret_val5, env);
                                   adb_removeModule_free(input_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "removeModuleParameter") == 0 )
                {

                    
                    input_val6 = adb_removeModuleParameter_create( env);
                        if( AXIS2_FAILURE == adb_removeModuleParameter_deserialize(input_val6, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeModuleParameter_free(input_val6, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeModuleParameter_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val6 =  axis2_skel_ModuleAdminService_removeModuleParameter(env, msg_ctx,input_val6,
                                                (axis2_skel_ModuleAdminService_removeModuleParameter_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val6 )
                        {
                            adb_removeModuleParameter_free(input_val6, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_removeModuleParameterResponse_serialize(ret_val6, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_removeModuleParameterResponse_free(ret_val6, env);
                                   adb_removeModuleParameter_free(input_val6, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getModuleParameters") == 0 )
                {

                    
                    input_val7 = adb_getModuleParameters_create( env);
                        if( AXIS2_FAILURE == adb_getModuleParameters_deserialize(input_val7, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getModuleParameters_free(input_val7, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getModuleParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val7 =  axis2_skel_ModuleAdminService_getModuleParameters(env, msg_ctx,input_val7,
                                                (axis2_skel_ModuleAdminService_getModuleParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val7 )
                        {
                            adb_getModuleParameters_free(input_val7, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getModuleParametersResponse_serialize(ret_val7, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getModuleParametersResponse_free(ret_val7, env);
                                   adb_getModuleParameters_free(input_val7, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "engageModuleForOperation") == 0 )
                {

                    
                    input_val8 = adb_engageModuleForOperation_create( env);
                        if( AXIS2_FAILURE == adb_engageModuleForOperation_deserialize(input_val8, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_engageModuleForOperation_free(input_val8, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_engageModuleForOperation_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val8 =  axis2_skel_ModuleAdminService_engageModuleForOperation(env, msg_ctx,input_val8,
                                                (axis2_skel_ModuleAdminService_engageModuleForOperation_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val8 )
                        {
                            adb_engageModuleForOperation_free(input_val8, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_engageModuleForOperationResponse_serialize(ret_val8, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_engageModuleForOperationResponse_free(ret_val8, env);
                                   adb_engageModuleForOperation_free(input_val8, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listGloballyEngagedModules") == 0 )
                {

                    
                        ret_val9 =  axis2_skel_ModuleAdminService_listGloballyEngagedModules(env, msg_ctx);
                    
                        if ( NULL == ret_val9 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_listGloballyEngagedModulesResponse_serialize(ret_val9, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listGloballyEngagedModulesResponse_free(ret_val9, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "globallyEngageModule") == 0 )
                {

                    
                    input_val10 = adb_globallyEngageModule_create( env);
                        if( AXIS2_FAILURE == adb_globallyEngageModule_deserialize(input_val10, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_globallyEngageModule_free(input_val10, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_globallyEngageModule_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val10 =  axis2_skel_ModuleAdminService_globallyEngageModule(env, msg_ctx,input_val10,
                                                (axis2_skel_ModuleAdminService_globallyEngageModule_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val10 )
                        {
                            adb_globallyEngageModule_free(input_val10, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_globallyEngageModuleResponse_serialize(ret_val10, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_globallyEngageModuleResponse_free(ret_val10, env);
                                   adb_globallyEngageModule_free(input_val10, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "engageModuleForServiceGroup") == 0 )
                {

                    
                    input_val11 = adb_engageModuleForServiceGroup_create( env);
                        if( AXIS2_FAILURE == adb_engageModuleForServiceGroup_deserialize(input_val11, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_engageModuleForServiceGroup_free(input_val11, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_engageModuleForServiceGroup_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val11 =  axis2_skel_ModuleAdminService_engageModuleForServiceGroup(env, msg_ctx,input_val11,
                                                (axis2_skel_ModuleAdminService_engageModuleForServiceGroup_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val11 )
                        {
                            adb_engageModuleForServiceGroup_free(input_val11, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_engageModuleForServiceGroupResponse_serialize(ret_val11, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_engageModuleForServiceGroupResponse_free(ret_val11, env);
                                   adb_engageModuleForServiceGroup_free(input_val11, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "uploadModule") == 0 )
                {

                    
                    input_val12 = adb_uploadModule_create( env);
                        if( AXIS2_FAILURE == adb_uploadModule_deserialize(input_val12, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_uploadModule_free(input_val12, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_uploadModule_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val12 =  axis2_skel_ModuleAdminService_uploadModule(env, msg_ctx,input_val12);
                    
                        if ( NULL == ret_val12 )
                        {
                            adb_uploadModule_free(input_val12, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_uploadModuleResponse_serialize(ret_val12, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_uploadModuleResponse_free(ret_val12, env);
                                   adb_uploadModule_free(input_val12, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listModulesForOperation") == 0 )
                {

                    
                    input_val13 = adb_listModulesForOperation_create( env);
                        if( AXIS2_FAILURE == adb_listModulesForOperation_deserialize(input_val13, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listModulesForOperation_free(input_val13, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listModulesForOperation_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val13 =  axis2_skel_ModuleAdminService_listModulesForOperation(env, msg_ctx,input_val13,
                                                (axis2_skel_ModuleAdminService_listModulesForOperation_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val13 )
                        {
                            adb_listModulesForOperation_free(input_val13, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listModulesForOperationResponse_serialize(ret_val13, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listModulesForOperationResponse_free(ret_val13, env);
                                   adb_listModulesForOperation_free(input_val13, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listModulesForService") == 0 )
                {

                    
                    input_val14 = adb_listModulesForService_create( env);
                        if( AXIS2_FAILURE == adb_listModulesForService_deserialize(input_val14, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listModulesForService_free(input_val14, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listModulesForService_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val14 =  axis2_skel_ModuleAdminService_listModulesForService(env, msg_ctx,input_val14,
                                                (axis2_skel_ModuleAdminService_listModulesForService_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val14 )
                        {
                            adb_listModulesForService_free(input_val14, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listModulesForServiceResponse_serialize(ret_val14, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listModulesForServiceResponse_free(ret_val14, env);
                                   adb_listModulesForService_free(input_val14, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "disengageModuleForServiceGroup") == 0 )
                {

                    
                    input_val15 = adb_disengageModuleForServiceGroup_create( env);
                        if( AXIS2_FAILURE == adb_disengageModuleForServiceGroup_deserialize(input_val15, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_disengageModuleForServiceGroup_free(input_val15, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_disengageModuleForServiceGroup_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val15 =  axis2_skel_ModuleAdminService_disengageModuleForServiceGroup(env, msg_ctx,input_val15,
                                                (axis2_skel_ModuleAdminService_disengageModuleForServiceGroup_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val15 )
                        {
                            adb_disengageModuleForServiceGroup_free(input_val15, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_disengageModuleForServiceGroupResponse_serialize(ret_val15, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_disengageModuleForServiceGroupResponse_free(ret_val15, env);
                                   adb_disengageModuleForServiceGroup_free(input_val15, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "globallyDisengageModule") == 0 )
                {

                    
                    input_val16 = adb_globallyDisengageModule_create( env);
                        if( AXIS2_FAILURE == adb_globallyDisengageModule_deserialize(input_val16, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_globallyDisengageModule_free(input_val16, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_globallyDisengageModule_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val16 =  axis2_skel_ModuleAdminService_globallyDisengageModule(env, msg_ctx,input_val16,
                                                (axis2_skel_ModuleAdminService_globallyDisengageModule_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val16 )
                        {
                            adb_globallyDisengageModule_free(input_val16, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_globallyDisengageModuleResponse_serialize(ret_val16, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_globallyDisengageModuleResponse_free(ret_val16, env);
                                   adb_globallyDisengageModule_free(input_val16, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listModules") == 0 )
                {

                    
                        ret_val17 =  axis2_skel_ModuleAdminService_listModules(env, msg_ctx);
                    
                        if ( NULL == ret_val17 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_listModulesResponse_serialize(ret_val17, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listModulesResponse_free(ret_val17, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listModulesForServiceGroup") == 0 )
                {

                    
                    input_val18 = adb_listModulesForServiceGroup_create( env);
                        if( AXIS2_FAILURE == adb_listModulesForServiceGroup_deserialize(input_val18, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listModulesForServiceGroup_free(input_val18, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listModulesForServiceGroup_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val18 =  axis2_skel_ModuleAdminService_listModulesForServiceGroup(env, msg_ctx,input_val18,
                                                (axis2_skel_ModuleAdminService_listModulesForServiceGroup_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val18 )
                        {
                            adb_listModulesForServiceGroup_free(input_val18, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listModulesForServiceGroupResponse_serialize(ret_val18, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listModulesForServiceGroupResponse_free(ret_val18, env);
                                   adb_listModulesForServiceGroup_free(input_val18, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "disengageModuleForOperation") == 0 )
                {

                    
                    input_val19 = adb_disengageModuleForOperation_create( env);
                        if( AXIS2_FAILURE == adb_disengageModuleForOperation_deserialize(input_val19, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_disengageModuleForOperation_free(input_val19, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_disengageModuleForOperation_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val19 =  axis2_skel_ModuleAdminService_disengageModuleForOperation(env, msg_ctx,input_val19,
                                                (axis2_skel_ModuleAdminService_disengageModuleForOperation_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val19 )
                        {
                            adb_disengageModuleForOperation_free(input_val19, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_disengageModuleForOperationResponse_serialize(ret_val19, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_disengageModuleForOperationResponse_free(ret_val19, env);
                                   adb_disengageModuleForOperation_free(input_val19, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getModuleInfo") == 0 )
                {

                    
                    input_val20 = adb_getModuleInfo_create( env);
                        if( AXIS2_FAILURE == adb_getModuleInfo_deserialize(input_val20, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getModuleInfo_free(input_val20, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getModuleInfo_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val20 =  axis2_skel_ModuleAdminService_getModuleInfo(env, msg_ctx,input_val20,
                                                (axis2_skel_ModuleAdminService_getModuleInfo_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val20 )
                        {
                            adb_getModuleInfo_free(input_val20, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getModuleInfoResponse_serialize(ret_val20, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getModuleInfoResponse_free(ret_val20, env);
                                   adb_getModuleInfo_free(input_val20, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_ModuleAdminService service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_ModuleAdminService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_ModuleAdminService_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_ModuleAdminService_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_MODULEADMINSERVICE_ERROR_NONE ||
                error_code >= AXIS2_SKEL_MODULEADMINSERVICE_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "ModuleAdminService|http://service.mgt.module.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_ENGAGEMODULEFORSERVICE_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.engageModuleForService_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.engageModuleForService_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_DISENGAGEMODULEFROMSYSTEM_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.disengageModuleFromSystem_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.disengageModuleFromSystem_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_DISENGAGEMODULEFORSERVICE_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.disengageModuleForService_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.disengageModuleForService_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_SETMODULEPARAMETERS_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.setModuleParameters_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setModuleParameters_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_REMOVEMODULE_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.removeModule_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.removeModule_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_REMOVEMODULEPARAMETER_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.removeModuleParameter_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.removeModuleParameter_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_GETMODULEPARAMETERS_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getModuleParameters_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getModuleParameters_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_ENGAGEMODULEFOROPERATION_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.engageModuleForOperation_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.engageModuleForOperation_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_GLOBALLYENGAGEMODULE_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.globallyEngageModule_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.globallyEngageModule_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_ENGAGEMODULEFORSERVICEGROUP_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.engageModuleForServiceGroup_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.engageModuleForServiceGroup_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_LISTMODULESFOROPERATION_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.listModulesForOperation_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.listModulesForOperation_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_LISTMODULESFORSERVICE_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.listModulesForService_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.listModulesForService_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_DISENGAGEMODULEFORSERVICEGROUP_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.disengageModuleForServiceGroup_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.disengageModuleForServiceGroup_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_GLOBALLYDISENGAGEMODULE_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.globallyDisengageModule_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.globallyDisengageModule_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_LISTMODULESFORSERVICEGROUP_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.listModulesForServiceGroup_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.listModulesForServiceGroup_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_DISENGAGEMODULEFOROPERATION_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.disengageModuleForOperation_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.disengageModuleForOperation_fault.ModuleMgtException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_MODULEADMINSERVICE_GETMODULEINFO_FAULT_MODULEMGTEXCEPTION)
                {
                    /* found which error code */
                    adb_ModuleMgtExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ModuleMgtExceptionE0_t*)svc_skeleton_wrapper->fault.getModuleInfo_fault.ModuleMgtException;
                    if(adb_obj)
                    {
                        error_node = adb_ModuleMgtExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ModuleMgtExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getModuleInfo_fault.ModuleMgtException = NULL;
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
		*inst = axis2_svc_skel_ModuleAdminService_create(env);

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


    

