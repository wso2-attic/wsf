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
         * axis2_svc_skel_OperationAdmin.c
         *
         * This file was auto-generated from WSDL for "OperationAdmin|http://mgt.operation.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_OperationAdmin
         */

        #include "axis2_skel_OperationAdmin.h"
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
          
        }axis2_svc_skel_OperationAdmin_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_OperationAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_OperationAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_OperationAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_OperationAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_OperationAdmin_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_OperationAdmin_svc_skeleton_ops_var = {
            axis2_svc_skel_OperationAdmin_init,
            axis2_svc_skel_OperationAdmin_invoke,
            axis2_svc_skel_OperationAdmin_on_fault,
            axis2_svc_skel_OperationAdmin_free
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
	axis2_svc_skel_OperationAdmin_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_OperationAdmin_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_OperationAdmin_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_OperationAdmin_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_OperationAdmin_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_OperationAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_OperationAdmin */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_OperationAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_OperationAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_OperationAdmin_t *svc_skeleton_wrapper = NULL;

          
            adb_listOperationPhaseHandlersResponse_t* ret_val1;
            adb_listOperationPhaseHandlers_t* input_val1;
            
            axis2_status_t ret_val2;
            adb_setPolicy_t* input_val2;
            
            adb_listOperationPhasesResponse_t* ret_val3;
            adb_listOperationPhases_t* input_val3;
            
            adb_listControlOperationsResponse_t* ret_val4;
            adb_listControlOperations_t* input_val4;
            
            adb_getDeclaredOperationParametersResponse_t* ret_val5;
            adb_getDeclaredOperationParameters_t* input_val5;
            
            adb_listAllOperationsResponse_t* ret_val6;
            adb_listAllOperations_t* input_val6;
            
            axis2_status_t ret_val7;
            adb_configureMTOM_t* input_val7;
            
            adb_getOperationMetaDataResponse_t* ret_val8;
            adb_getOperationMetaData_t* input_val8;
            
            adb_getOperationParametersResponse_t* ret_val9;
            adb_getOperationParameters_t* input_val9;
            
            axis2_status_t ret_val10;
            adb_removeOperationParameter_t* input_val10;
            
            adb_getOperationStatisticsResponse_t* ret_val11;
            adb_getOperationStatistics_t* input_val11;
            
            adb_getPolicyResponse_t* ret_val12;
            adb_getPolicy_t* input_val12;
            
            adb_listPublishedOperationsResponse_t* ret_val13;
            adb_listPublishedOperations_t* input_val13;
            
            axis2_status_t ret_val14;
            adb_setOperationParameters_t* input_val14;
            

          svc_skeleton_wrapper = (axis2_svc_skel_OperationAdmin_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "listOperationPhaseHandlers") == 0 )
                {

                    
                    input_val1 = adb_listOperationPhaseHandlers_create( env);
                        if( AXIS2_FAILURE == adb_listOperationPhaseHandlers_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listOperationPhaseHandlers_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listOperationPhaseHandlers_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_OperationAdmin_listOperationPhaseHandlers(env, msg_ctx,input_val1);
                    
                        if ( NULL == ret_val1 )
                        {
                            adb_listOperationPhaseHandlers_free(input_val1, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listOperationPhaseHandlersResponse_serialize(ret_val1, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listOperationPhaseHandlersResponse_free(ret_val1, env);
                                   adb_listOperationPhaseHandlers_free(input_val1, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setPolicy") == 0 )
                {

                    
                    input_val2 = adb_setPolicy_create( env);
                        if( AXIS2_FAILURE == adb_setPolicy_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setPolicy_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_OperationAdmin_setPolicy(env, msg_ctx,input_val2);
                    
                        if( AXIS2_FAILURE == ret_val2 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setPolicy ");
                        }
                        adb_setPolicy_free(input_val2, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "listOperationPhases") == 0 )
                {

                    
                    input_val3 = adb_listOperationPhases_create( env);
                        if( AXIS2_FAILURE == adb_listOperationPhases_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listOperationPhases_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listOperationPhases_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_OperationAdmin_listOperationPhases(env, msg_ctx,input_val3);
                    
                        if ( NULL == ret_val3 )
                        {
                            adb_listOperationPhases_free(input_val3, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listOperationPhasesResponse_serialize(ret_val3, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listOperationPhasesResponse_free(ret_val3, env);
                                   adb_listOperationPhases_free(input_val3, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listControlOperations") == 0 )
                {

                    
                    input_val4 = adb_listControlOperations_create( env);
                        if( AXIS2_FAILURE == adb_listControlOperations_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listControlOperations_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listControlOperations_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_OperationAdmin_listControlOperations(env, msg_ctx,input_val4);
                    
                        if ( NULL == ret_val4 )
                        {
                            adb_listControlOperations_free(input_val4, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listControlOperationsResponse_serialize(ret_val4, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listControlOperationsResponse_free(ret_val4, env);
                                   adb_listControlOperations_free(input_val4, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getDeclaredOperationParameters") == 0 )
                {

                    
                    input_val5 = adb_getDeclaredOperationParameters_create( env);
                        if( AXIS2_FAILURE == adb_getDeclaredOperationParameters_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getDeclaredOperationParameters_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getDeclaredOperationParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_OperationAdmin_getDeclaredOperationParameters(env, msg_ctx,input_val5);
                    
                        if ( NULL == ret_val5 )
                        {
                            adb_getDeclaredOperationParameters_free(input_val5, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getDeclaredOperationParametersResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getDeclaredOperationParametersResponse_free(ret_val5, env);
                                   adb_getDeclaredOperationParameters_free(input_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listAllOperations") == 0 )
                {

                    
                    input_val6 = adb_listAllOperations_create( env);
                        if( AXIS2_FAILURE == adb_listAllOperations_deserialize(input_val6, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listAllOperations_free(input_val6, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listAllOperations_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val6 =  axis2_skel_OperationAdmin_listAllOperations(env, msg_ctx,input_val6);
                    
                        if ( NULL == ret_val6 )
                        {
                            adb_listAllOperations_free(input_val6, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listAllOperationsResponse_serialize(ret_val6, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listAllOperationsResponse_free(ret_val6, env);
                                   adb_listAllOperations_free(input_val6, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "configureMTOM") == 0 )
                {

                    
                    input_val7 = adb_configureMTOM_create( env);
                        if( AXIS2_FAILURE == adb_configureMTOM_deserialize(input_val7, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_configureMTOM_free(input_val7, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_configureMTOM_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val7 =  axis2_skel_OperationAdmin_configureMTOM(env, msg_ctx,input_val7);
                    
                        if( AXIS2_FAILURE == ret_val7 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from configureMTOM ");
                        }
                        adb_configureMTOM_free(input_val7, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getOperationMetaData") == 0 )
                {

                    
                    input_val8 = adb_getOperationMetaData_create( env);
                        if( AXIS2_FAILURE == adb_getOperationMetaData_deserialize(input_val8, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationMetaData_free(input_val8, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationMetaData_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val8 =  axis2_skel_OperationAdmin_getOperationMetaData(env, msg_ctx,input_val8);
                    
                        if ( NULL == ret_val8 )
                        {
                            adb_getOperationMetaData_free(input_val8, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationMetaDataResponse_serialize(ret_val8, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationMetaDataResponse_free(ret_val8, env);
                                   adb_getOperationMetaData_free(input_val8, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getOperationParameters") == 0 )
                {

                    
                    input_val9 = adb_getOperationParameters_create( env);
                        if( AXIS2_FAILURE == adb_getOperationParameters_deserialize(input_val9, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationParameters_free(input_val9, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val9 =  axis2_skel_OperationAdmin_getOperationParameters(env, msg_ctx,input_val9);
                    
                        if ( NULL == ret_val9 )
                        {
                            adb_getOperationParameters_free(input_val9, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationParametersResponse_serialize(ret_val9, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationParametersResponse_free(ret_val9, env);
                                   adb_getOperationParameters_free(input_val9, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "removeOperationParameter") == 0 )
                {

                    
                    input_val10 = adb_removeOperationParameter_create( env);
                        if( AXIS2_FAILURE == adb_removeOperationParameter_deserialize(input_val10, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeOperationParameter_free(input_val10, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeOperationParameter_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val10 =  axis2_skel_OperationAdmin_removeOperationParameter(env, msg_ctx,input_val10);
                    
                        if( AXIS2_FAILURE == ret_val10 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from removeOperationParameter ");
                        }
                        adb_removeOperationParameter_free(input_val10, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getOperationStatistics") == 0 )
                {

                    
                    input_val11 = adb_getOperationStatistics_create( env);
                        if( AXIS2_FAILURE == adb_getOperationStatistics_deserialize(input_val11, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationStatistics_free(input_val11, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationStatistics_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val11 =  axis2_skel_OperationAdmin_getOperationStatistics(env, msg_ctx,input_val11);
                    
                        if ( NULL == ret_val11 )
                        {
                            adb_getOperationStatistics_free(input_val11, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationStatisticsResponse_serialize(ret_val11, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationStatisticsResponse_free(ret_val11, env);
                                   adb_getOperationStatistics_free(input_val11, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getPolicy") == 0 )
                {

                    
                    input_val12 = adb_getPolicy_create( env);
                        if( AXIS2_FAILURE == adb_getPolicy_deserialize(input_val12, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getPolicy_free(input_val12, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val12 =  axis2_skel_OperationAdmin_getPolicy(env, msg_ctx,input_val12);
                    
                        if ( NULL == ret_val12 )
                        {
                            adb_getPolicy_free(input_val12, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getPolicyResponse_serialize(ret_val12, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getPolicyResponse_free(ret_val12, env);
                                   adb_getPolicy_free(input_val12, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listPublishedOperations") == 0 )
                {

                    
                    input_val13 = adb_listPublishedOperations_create( env);
                        if( AXIS2_FAILURE == adb_listPublishedOperations_deserialize(input_val13, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listPublishedOperations_free(input_val13, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listPublishedOperations_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val13 =  axis2_skel_OperationAdmin_listPublishedOperations(env, msg_ctx,input_val13);
                    
                        if ( NULL == ret_val13 )
                        {
                            adb_listPublishedOperations_free(input_val13, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listPublishedOperationsResponse_serialize(ret_val13, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listPublishedOperationsResponse_free(ret_val13, env);
                                   adb_listPublishedOperations_free(input_val13, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setOperationParameters") == 0 )
                {

                    
                    input_val14 = adb_setOperationParameters_create( env);
                        if( AXIS2_FAILURE == adb_setOperationParameters_deserialize(input_val14, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setOperationParameters_free(input_val14, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setOperationParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val14 =  axis2_skel_OperationAdmin_setOperationParameters(env, msg_ctx,input_val14);
                    
                        if( AXIS2_FAILURE == ret_val14 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setOperationParameters ");
                        }
                        adb_setOperationParameters_free(input_val14, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_OperationAdmin service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_OperationAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_OperationAdmin_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_OperationAdmin_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_OPERATIONADMIN_ERROR_NONE ||
                error_code >= AXIS2_SKEL_OPERATIONADMIN_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "OperationAdmin|http://mgt.operation.carbon.wso2.org failed",
                            error_node);
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
		*inst = axis2_svc_skel_OperationAdmin_create(env);

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


    

