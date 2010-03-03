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
         * axis2_svc_skel_StatisticsAdmin.c
         *
         * This file was auto-generated from WSDL for "StatisticsAdmin|http://services.statistics.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_StatisticsAdmin
         */

        #include "axis2_skel_StatisticsAdmin.h"
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
          
        }axis2_svc_skel_StatisticsAdmin_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_StatisticsAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_StatisticsAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_StatisticsAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_StatisticsAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_StatisticsAdmin_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_StatisticsAdmin_svc_skeleton_ops_var = {
            axis2_svc_skel_StatisticsAdmin_init,
            axis2_svc_skel_StatisticsAdmin_invoke,
            axis2_svc_skel_StatisticsAdmin_on_fault,
            axis2_svc_skel_StatisticsAdmin_free
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
	axis2_svc_skel_StatisticsAdmin_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_StatisticsAdmin_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_StatisticsAdmin_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_StatisticsAdmin_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_StatisticsAdmin_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_StatisticsAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_StatisticsAdmin */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_StatisticsAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_StatisticsAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_StatisticsAdmin_t *svc_skeleton_wrapper = NULL;

          
            adb_getMaxServiceResponseTimeResponse_t* ret_val1;
            adb_getMaxServiceResponseTime_t* input_val1;
            
            adb_getServiceRequestCountResponse_t* ret_val2;
            adb_getServiceRequestCount_t* input_val2;
            
            adb_getSystemResponseCountResponse_t* ret_val3;
            
            adb_getOperationResponseCountResponse_t* ret_val4;
            adb_getOperationResponseCount_t* input_val4;
            
            adb_getAvgOperationResponseTimeResponse_t* ret_val5;
            adb_getAvgOperationResponseTime_t* input_val5;
            
            adb_getOperationStatisticsResponse_t* ret_val6;
            adb_getOperationStatistics_t* input_val6;
            
            adb_getMinSystemResponseTimeResponse_t* ret_val7;
            
            adb_getSystemFaultCountResponse_t* ret_val8;
            
            adb_getMaxSystemResponseTimeResponse_t* ret_val9;
            
            adb_getServiceFaultCountResponse_t* ret_val10;
            adb_getServiceFaultCount_t* input_val10;
            
            adb_getMinServiceResponseTimeResponse_t* ret_val11;
            adb_getMinServiceResponseTime_t* input_val11;
            
            adb_getMaxOperationResponseTimeResponse_t* ret_val12;
            adb_getMaxOperationResponseTime_t* input_val12;
            
            adb_getServiceStatisticsResponse_t* ret_val13;
            adb_getServiceStatistics_t* input_val13;
            
            adb_getOperationFaultCountResponse_t* ret_val14;
            adb_getOperationFaultCount_t* input_val14;
            
            adb_getAvgServiceResponseTimeResponse_t* ret_val15;
            adb_getAvgServiceResponseTime_t* input_val15;
            
            adb_getServiceResponseCountResponse_t* ret_val16;
            adb_getServiceResponseCount_t* input_val16;
            
            adb_getSystemRequestCountResponse_t* ret_val17;
            
            adb_getMinOperationResponseTimeResponse_t* ret_val18;
            adb_getMinOperationResponseTime_t* input_val18;
            
            adb_getAvgSystemResponseTimeResponse_t* ret_val19;
            
            adb_getSystemStatisticsResponse_t* ret_val20;
            
            adb_getOperationRequestCountResponse_t* ret_val21;
            adb_getOperationRequestCount_t* input_val21;
            

          svc_skeleton_wrapper = (axis2_svc_skel_StatisticsAdmin_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "getMaxServiceResponseTime") == 0 )
                {

                    
                    input_val1 = adb_getMaxServiceResponseTime_create( env);
                        if( AXIS2_FAILURE == adb_getMaxServiceResponseTime_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getMaxServiceResponseTime_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMaxServiceResponseTime_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_StatisticsAdmin_getMaxServiceResponseTime(env, msg_ctx,input_val1);
                    
                        if ( NULL == ret_val1 )
                        {
                            adb_getMaxServiceResponseTime_free(input_val1, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getMaxServiceResponseTimeResponse_serialize(ret_val1, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getMaxServiceResponseTimeResponse_free(ret_val1, env);
                                   adb_getMaxServiceResponseTime_free(input_val1, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServiceRequestCount") == 0 )
                {

                    
                    input_val2 = adb_getServiceRequestCount_create( env);
                        if( AXIS2_FAILURE == adb_getServiceRequestCount_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceRequestCount_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceRequestCount_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_StatisticsAdmin_getServiceRequestCount(env, msg_ctx,input_val2);
                    
                        if ( NULL == ret_val2 )
                        {
                            adb_getServiceRequestCount_free(input_val2, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceRequestCountResponse_serialize(ret_val2, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceRequestCountResponse_free(ret_val2, env);
                                   adb_getServiceRequestCount_free(input_val2, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSystemResponseCount") == 0 )
                {

                    
                        ret_val3 =  axis2_skel_StatisticsAdmin_getSystemResponseCount(env, msg_ctx);
                    
                        if ( NULL == ret_val3 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemResponseCountResponse_serialize(ret_val3, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemResponseCountResponse_free(ret_val3, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getOperationResponseCount") == 0 )
                {

                    
                    input_val4 = adb_getOperationResponseCount_create( env);
                        if( AXIS2_FAILURE == adb_getOperationResponseCount_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationResponseCount_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationResponseCount_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_StatisticsAdmin_getOperationResponseCount(env, msg_ctx,input_val4);
                    
                        if ( NULL == ret_val4 )
                        {
                            adb_getOperationResponseCount_free(input_val4, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationResponseCountResponse_serialize(ret_val4, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationResponseCountResponse_free(ret_val4, env);
                                   adb_getOperationResponseCount_free(input_val4, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getAvgOperationResponseTime") == 0 )
                {

                    
                    input_val5 = adb_getAvgOperationResponseTime_create( env);
                        if( AXIS2_FAILURE == adb_getAvgOperationResponseTime_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getAvgOperationResponseTime_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getAvgOperationResponseTime_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_StatisticsAdmin_getAvgOperationResponseTime(env, msg_ctx,input_val5);
                    
                        if ( NULL == ret_val5 )
                        {
                            adb_getAvgOperationResponseTime_free(input_val5, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getAvgOperationResponseTimeResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getAvgOperationResponseTimeResponse_free(ret_val5, env);
                                   adb_getAvgOperationResponseTime_free(input_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getOperationStatistics") == 0 )
                {

                    
                    input_val6 = adb_getOperationStatistics_create( env);
                        if( AXIS2_FAILURE == adb_getOperationStatistics_deserialize(input_val6, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationStatistics_free(input_val6, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationStatistics_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val6 =  axis2_skel_StatisticsAdmin_getOperationStatistics(env, msg_ctx,input_val6);
                    
                        if ( NULL == ret_val6 )
                        {
                            adb_getOperationStatistics_free(input_val6, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationStatisticsResponse_serialize(ret_val6, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationStatisticsResponse_free(ret_val6, env);
                                   adb_getOperationStatistics_free(input_val6, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getMinSystemResponseTime") == 0 )
                {

                    
                        ret_val7 =  axis2_skel_StatisticsAdmin_getMinSystemResponseTime(env, msg_ctx);
                    
                        if ( NULL == ret_val7 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getMinSystemResponseTimeResponse_serialize(ret_val7, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getMinSystemResponseTimeResponse_free(ret_val7, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSystemFaultCount") == 0 )
                {

                    
                        ret_val8 =  axis2_skel_StatisticsAdmin_getSystemFaultCount(env, msg_ctx);
                    
                        if ( NULL == ret_val8 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemFaultCountResponse_serialize(ret_val8, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemFaultCountResponse_free(ret_val8, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getMaxSystemResponseTime") == 0 )
                {

                    
                        ret_val9 =  axis2_skel_StatisticsAdmin_getMaxSystemResponseTime(env, msg_ctx);
                    
                        if ( NULL == ret_val9 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getMaxSystemResponseTimeResponse_serialize(ret_val9, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getMaxSystemResponseTimeResponse_free(ret_val9, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServiceFaultCount") == 0 )
                {

                    
                    input_val10 = adb_getServiceFaultCount_create( env);
                        if( AXIS2_FAILURE == adb_getServiceFaultCount_deserialize(input_val10, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceFaultCount_free(input_val10, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceFaultCount_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val10 =  axis2_skel_StatisticsAdmin_getServiceFaultCount(env, msg_ctx,input_val10);
                    
                        if ( NULL == ret_val10 )
                        {
                            adb_getServiceFaultCount_free(input_val10, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceFaultCountResponse_serialize(ret_val10, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceFaultCountResponse_free(ret_val10, env);
                                   adb_getServiceFaultCount_free(input_val10, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getMinServiceResponseTime") == 0 )
                {

                    
                    input_val11 = adb_getMinServiceResponseTime_create( env);
                        if( AXIS2_FAILURE == adb_getMinServiceResponseTime_deserialize(input_val11, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getMinServiceResponseTime_free(input_val11, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMinServiceResponseTime_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val11 =  axis2_skel_StatisticsAdmin_getMinServiceResponseTime(env, msg_ctx,input_val11);
                    
                        if ( NULL == ret_val11 )
                        {
                            adb_getMinServiceResponseTime_free(input_val11, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getMinServiceResponseTimeResponse_serialize(ret_val11, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getMinServiceResponseTimeResponse_free(ret_val11, env);
                                   adb_getMinServiceResponseTime_free(input_val11, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getMaxOperationResponseTime") == 0 )
                {

                    
                    input_val12 = adb_getMaxOperationResponseTime_create( env);
                        if( AXIS2_FAILURE == adb_getMaxOperationResponseTime_deserialize(input_val12, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getMaxOperationResponseTime_free(input_val12, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMaxOperationResponseTime_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val12 =  axis2_skel_StatisticsAdmin_getMaxOperationResponseTime(env, msg_ctx,input_val12);
                    
                        if ( NULL == ret_val12 )
                        {
                            adb_getMaxOperationResponseTime_free(input_val12, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getMaxOperationResponseTimeResponse_serialize(ret_val12, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getMaxOperationResponseTimeResponse_free(ret_val12, env);
                                   adb_getMaxOperationResponseTime_free(input_val12, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServiceStatistics") == 0 )
                {

                    
                    input_val13 = adb_getServiceStatistics_create( env);
                        if( AXIS2_FAILURE == adb_getServiceStatistics_deserialize(input_val13, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceStatistics_free(input_val13, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceStatistics_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val13 =  axis2_skel_StatisticsAdmin_getServiceStatistics(env, msg_ctx,input_val13);
                    
                        if ( NULL == ret_val13 )
                        {
                            adb_getServiceStatistics_free(input_val13, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceStatisticsResponse_serialize(ret_val13, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceStatisticsResponse_free(ret_val13, env);
                                   adb_getServiceStatistics_free(input_val13, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getOperationFaultCount") == 0 )
                {

                    
                    input_val14 = adb_getOperationFaultCount_create( env);
                        if( AXIS2_FAILURE == adb_getOperationFaultCount_deserialize(input_val14, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationFaultCount_free(input_val14, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationFaultCount_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val14 =  axis2_skel_StatisticsAdmin_getOperationFaultCount(env, msg_ctx,input_val14);
                    
                        if ( NULL == ret_val14 )
                        {
                            adb_getOperationFaultCount_free(input_val14, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationFaultCountResponse_serialize(ret_val14, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationFaultCountResponse_free(ret_val14, env);
                                   adb_getOperationFaultCount_free(input_val14, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getAvgServiceResponseTime") == 0 )
                {

                    
                    input_val15 = adb_getAvgServiceResponseTime_create( env);
                        if( AXIS2_FAILURE == adb_getAvgServiceResponseTime_deserialize(input_val15, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getAvgServiceResponseTime_free(input_val15, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getAvgServiceResponseTime_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val15 =  axis2_skel_StatisticsAdmin_getAvgServiceResponseTime(env, msg_ctx,input_val15);
                    
                        if ( NULL == ret_val15 )
                        {
                            adb_getAvgServiceResponseTime_free(input_val15, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getAvgServiceResponseTimeResponse_serialize(ret_val15, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getAvgServiceResponseTimeResponse_free(ret_val15, env);
                                   adb_getAvgServiceResponseTime_free(input_val15, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServiceResponseCount") == 0 )
                {

                    
                    input_val16 = adb_getServiceResponseCount_create( env);
                        if( AXIS2_FAILURE == adb_getServiceResponseCount_deserialize(input_val16, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceResponseCount_free(input_val16, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceResponseCount_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val16 =  axis2_skel_StatisticsAdmin_getServiceResponseCount(env, msg_ctx,input_val16);
                    
                        if ( NULL == ret_val16 )
                        {
                            adb_getServiceResponseCount_free(input_val16, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceResponseCountResponse_serialize(ret_val16, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceResponseCountResponse_free(ret_val16, env);
                                   adb_getServiceResponseCount_free(input_val16, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSystemRequestCount") == 0 )
                {

                    
                        ret_val17 =  axis2_skel_StatisticsAdmin_getSystemRequestCount(env, msg_ctx);
                    
                        if ( NULL == ret_val17 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemRequestCountResponse_serialize(ret_val17, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemRequestCountResponse_free(ret_val17, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getMinOperationResponseTime") == 0 )
                {

                    
                    input_val18 = adb_getMinOperationResponseTime_create( env);
                        if( AXIS2_FAILURE == adb_getMinOperationResponseTime_deserialize(input_val18, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getMinOperationResponseTime_free(input_val18, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getMinOperationResponseTime_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val18 =  axis2_skel_StatisticsAdmin_getMinOperationResponseTime(env, msg_ctx,input_val18);
                    
                        if ( NULL == ret_val18 )
                        {
                            adb_getMinOperationResponseTime_free(input_val18, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getMinOperationResponseTimeResponse_serialize(ret_val18, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getMinOperationResponseTimeResponse_free(ret_val18, env);
                                   adb_getMinOperationResponseTime_free(input_val18, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getAvgSystemResponseTime") == 0 )
                {

                    
                        ret_val19 =  axis2_skel_StatisticsAdmin_getAvgSystemResponseTime(env, msg_ctx);
                    
                        if ( NULL == ret_val19 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getAvgSystemResponseTimeResponse_serialize(ret_val19, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getAvgSystemResponseTimeResponse_free(ret_val19, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSystemStatistics") == 0 )
                {

                    
                        ret_val20 =  axis2_skel_StatisticsAdmin_getSystemStatistics(env, msg_ctx);
                    
                        if ( NULL == ret_val20 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemStatisticsResponse_serialize(ret_val20, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemStatisticsResponse_free(ret_val20, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getOperationRequestCount") == 0 )
                {

                    
                    input_val21 = adb_getOperationRequestCount_create( env);
                        if( AXIS2_FAILURE == adb_getOperationRequestCount_deserialize(input_val21, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationRequestCount_free(input_val21, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationRequestCount_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val21 =  axis2_skel_StatisticsAdmin_getOperationRequestCount(env, msg_ctx,input_val21);
                    
                        if ( NULL == ret_val21 )
                        {
                            adb_getOperationRequestCount_free(input_val21, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationRequestCountResponse_serialize(ret_val21, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationRequestCountResponse_free(ret_val21, env);
                                   adb_getOperationRequestCount_free(input_val21, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_StatisticsAdmin service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_StatisticsAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_StatisticsAdmin_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_StatisticsAdmin_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_STATISTICSADMIN_ERROR_NONE ||
                error_code >= AXIS2_SKEL_STATISTICSADMIN_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "StatisticsAdmin|http://services.statistics.carbon.wso2.org failed",
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
		*inst = axis2_svc_skel_StatisticsAdmin_create(env);

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


    

