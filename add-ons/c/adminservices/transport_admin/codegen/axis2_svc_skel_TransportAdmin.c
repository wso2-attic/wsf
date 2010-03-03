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
         * axis2_svc_skel_TransportAdmin.c
         *
         * This file was auto-generated from WSDL for "TransportAdmin|http://mgt.transport.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_TransportAdmin
         */

        #include "axis2_skel_TransportAdmin.h"
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
                axis2_skel_TransportAdmin_updateServiceSpecificOutParameters_fault updateServiceSpecificOutParameters_fault;
                    axis2_skel_TransportAdmin_getAllTransportData_fault getAllTransportData_fault;
                    axis2_skel_TransportAdmin_getGloballyDefinedOutParameters_fault getGloballyDefinedOutParameters_fault;
                    axis2_skel_TransportAdmin_addExposedTransports_fault addExposedTransports_fault;
                    axis2_skel_TransportAdmin_listTransportsForService_fault listTransportsForService_fault;
                    axis2_skel_TransportAdmin_getServiceSpecificInParameters_fault getServiceSpecificInParameters_fault;
                    axis2_skel_TransportAdmin_removeExposedTransports_fault removeExposedTransports_fault;
                    axis2_skel_TransportAdmin_updateServiceSpecificInParameters_fault updateServiceSpecificInParameters_fault;
                    axis2_skel_TransportAdmin_disableSender_fault disableSender_fault;
                    axis2_skel_TransportAdmin_getGloballyDefinedInParameters_fault getGloballyDefinedInParameters_fault;
                    axis2_skel_TransportAdmin_disableListener_fault disableListener_fault;
                    axis2_skel_TransportAdmin_listExposedTransports_fault listExposedTransports_fault;
                    axis2_skel_TransportAdmin_getServiceSpecificOutParameters_fault getServiceSpecificOutParameters_fault;
                    axis2_skel_TransportAdmin_updateGloballyDefinedOutParameters_fault updateGloballyDefinedOutParameters_fault;
                    axis2_skel_TransportAdmin_getTransportDetails_fault getTransportDetails_fault;
                    axis2_skel_TransportAdmin_updateGloballyDefinedInParameters_fault updateGloballyDefinedInParameters_fault;
                    axis2_skel_TransportAdmin_dependenciesAvailable_fault dependenciesAvailable_fault;
                    
            } fault;
          
        }axis2_svc_skel_TransportAdmin_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_TransportAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_TransportAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_TransportAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_TransportAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_TransportAdmin_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_TransportAdmin_svc_skeleton_ops_var = {
            axis2_svc_skel_TransportAdmin_init,
            axis2_svc_skel_TransportAdmin_invoke,
            axis2_svc_skel_TransportAdmin_on_fault,
            axis2_svc_skel_TransportAdmin_free
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
	axis2_svc_skel_TransportAdmin_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_TransportAdmin_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_TransportAdmin_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_TransportAdmin_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_TransportAdmin_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_TransportAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_TransportAdmin */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_TransportAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_TransportAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_TransportAdmin_t *svc_skeleton_wrapper = NULL;

          
            axis2_status_t ret_val1;
            adb_updateServiceSpecificOutParameters_t* input_val1;
            
            adb_getAllTransportDataResponse_t* ret_val2;
            
            adb_getGloballyDefinedOutParametersResponse_t* ret_val3;
            adb_getGloballyDefinedOutParameters_t* input_val3;
            
            axis2_status_t ret_val4;
            adb_addExposedTransports_t* input_val4;
            
            adb_listTransportsResponse_t* ret_val5;
            
            adb_listTransportsForServiceResponse_t* ret_val6;
            adb_listTransportsForService_t* input_val6;
            
            adb_getServiceSpecificInParametersResponse_t* ret_val7;
            adb_getServiceSpecificInParameters_t* input_val7;
            
            axis2_status_t ret_val8;
            adb_removeExposedTransports_t* input_val8;
            
            axis2_status_t ret_val9;
            adb_updateServiceSpecificInParameters_t* input_val9;
            
            axis2_status_t ret_val10;
            adb_disableSender_t* input_val10;
            
            adb_getGloballyDefinedInParametersResponse_t* ret_val11;
            adb_getGloballyDefinedInParameters_t* input_val11;
            
            axis2_status_t ret_val12;
            adb_disableListener_t* input_val12;
            
            adb_listExposedTransportsResponse_t* ret_val13;
            adb_listExposedTransports_t* input_val13;
            
            adb_getServiceSpecificOutParametersResponse_t* ret_val14;
            adb_getServiceSpecificOutParameters_t* input_val14;
            
            axis2_status_t ret_val15;
            adb_updateGloballyDefinedOutParameters_t* input_val15;
            
            adb_getTransportDetailsResponse_t* ret_val16;
            adb_getTransportDetails_t* input_val16;
            
            axis2_status_t ret_val17;
            adb_updateGloballyDefinedInParameters_t* input_val17;
            
            adb_dependenciesAvailableResponse_t* ret_val18;
            adb_dependenciesAvailable_t* input_val18;
            

          svc_skeleton_wrapper = (axis2_svc_skel_TransportAdmin_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "updateServiceSpecificOutParameters") == 0 )
                {

                    
                    input_val1 = adb_updateServiceSpecificOutParameters_create( env);
                        if( AXIS2_FAILURE == adb_updateServiceSpecificOutParameters_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateServiceSpecificOutParameters_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateServiceSpecificOutParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_TransportAdmin_updateServiceSpecificOutParameters(env, msg_ctx,input_val1,
                                                (axis2_skel_TransportAdmin_updateServiceSpecificOutParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val1 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateServiceSpecificOutParameters ");
                        }
                        adb_updateServiceSpecificOutParameters_free(input_val1, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getAllTransportData") == 0 )
                {

                    
                        ret_val2 =  axis2_skel_TransportAdmin_getAllTransportData(env, msg_ctx,
                                                (axis2_skel_TransportAdmin_getAllTransportData_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val2 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getAllTransportDataResponse_serialize(ret_val2, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getAllTransportDataResponse_free(ret_val2, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getGloballyDefinedOutParameters") == 0 )
                {

                    
                    input_val3 = adb_getGloballyDefinedOutParameters_create( env);
                        if( AXIS2_FAILURE == adb_getGloballyDefinedOutParameters_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getGloballyDefinedOutParameters_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getGloballyDefinedOutParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_TransportAdmin_getGloballyDefinedOutParameters(env, msg_ctx,input_val3,
                                                (axis2_skel_TransportAdmin_getGloballyDefinedOutParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val3 )
                        {
                            adb_getGloballyDefinedOutParameters_free(input_val3, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getGloballyDefinedOutParametersResponse_serialize(ret_val3, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getGloballyDefinedOutParametersResponse_free(ret_val3, env);
                                   adb_getGloballyDefinedOutParameters_free(input_val3, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "addExposedTransports") == 0 )
                {

                    
                    input_val4 = adb_addExposedTransports_create( env);
                        if( AXIS2_FAILURE == adb_addExposedTransports_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addExposedTransports_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addExposedTransports_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_TransportAdmin_addExposedTransports(env, msg_ctx,input_val4,
                                                (axis2_skel_TransportAdmin_addExposedTransports_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val4 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addExposedTransports ");
                        }
                        adb_addExposedTransports_free(input_val4, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "listTransports") == 0 )
                {

                    
                        ret_val5 =  axis2_skel_TransportAdmin_listTransports(env, msg_ctx);
                    
                        if ( NULL == ret_val5 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_listTransportsResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listTransportsResponse_free(ret_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listTransportsForService") == 0 )
                {

                    
                    input_val6 = adb_listTransportsForService_create( env);
                        if( AXIS2_FAILURE == adb_listTransportsForService_deserialize(input_val6, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listTransportsForService_free(input_val6, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listTransportsForService_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val6 =  axis2_skel_TransportAdmin_listTransportsForService(env, msg_ctx,input_val6,
                                                (axis2_skel_TransportAdmin_listTransportsForService_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val6 )
                        {
                            adb_listTransportsForService_free(input_val6, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listTransportsForServiceResponse_serialize(ret_val6, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listTransportsForServiceResponse_free(ret_val6, env);
                                   adb_listTransportsForService_free(input_val6, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServiceSpecificInParameters") == 0 )
                {

                    
                    input_val7 = adb_getServiceSpecificInParameters_create( env);
                        if( AXIS2_FAILURE == adb_getServiceSpecificInParameters_deserialize(input_val7, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceSpecificInParameters_free(input_val7, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceSpecificInParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val7 =  axis2_skel_TransportAdmin_getServiceSpecificInParameters(env, msg_ctx,input_val7,
                                                (axis2_skel_TransportAdmin_getServiceSpecificInParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val7 )
                        {
                            adb_getServiceSpecificInParameters_free(input_val7, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceSpecificInParametersResponse_serialize(ret_val7, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceSpecificInParametersResponse_free(ret_val7, env);
                                   adb_getServiceSpecificInParameters_free(input_val7, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "removeExposedTransports") == 0 )
                {

                    
                    input_val8 = adb_removeExposedTransports_create( env);
                        if( AXIS2_FAILURE == adb_removeExposedTransports_deserialize(input_val8, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeExposedTransports_free(input_val8, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeExposedTransports_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val8 =  axis2_skel_TransportAdmin_removeExposedTransports(env, msg_ctx,input_val8,
                                                (axis2_skel_TransportAdmin_removeExposedTransports_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val8 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from removeExposedTransports ");
                        }
                        adb_removeExposedTransports_free(input_val8, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateServiceSpecificInParameters") == 0 )
                {

                    
                    input_val9 = adb_updateServiceSpecificInParameters_create( env);
                        if( AXIS2_FAILURE == adb_updateServiceSpecificInParameters_deserialize(input_val9, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateServiceSpecificInParameters_free(input_val9, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateServiceSpecificInParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val9 =  axis2_skel_TransportAdmin_updateServiceSpecificInParameters(env, msg_ctx,input_val9,
                                                (axis2_skel_TransportAdmin_updateServiceSpecificInParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val9 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateServiceSpecificInParameters ");
                        }
                        adb_updateServiceSpecificInParameters_free(input_val9, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "disableSender") == 0 )
                {

                    
                    input_val10 = adb_disableSender_create( env);
                        if( AXIS2_FAILURE == adb_disableSender_deserialize(input_val10, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_disableSender_free(input_val10, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_disableSender_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val10 =  axis2_skel_TransportAdmin_disableSender(env, msg_ctx,input_val10,
                                                (axis2_skel_TransportAdmin_disableSender_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val10 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from disableSender ");
                        }
                        adb_disableSender_free(input_val10, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getGloballyDefinedInParameters") == 0 )
                {

                    
                    input_val11 = adb_getGloballyDefinedInParameters_create( env);
                        if( AXIS2_FAILURE == adb_getGloballyDefinedInParameters_deserialize(input_val11, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getGloballyDefinedInParameters_free(input_val11, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getGloballyDefinedInParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val11 =  axis2_skel_TransportAdmin_getGloballyDefinedInParameters(env, msg_ctx,input_val11,
                                                (axis2_skel_TransportAdmin_getGloballyDefinedInParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val11 )
                        {
                            adb_getGloballyDefinedInParameters_free(input_val11, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getGloballyDefinedInParametersResponse_serialize(ret_val11, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getGloballyDefinedInParametersResponse_free(ret_val11, env);
                                   adb_getGloballyDefinedInParameters_free(input_val11, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "disableListener") == 0 )
                {

                    
                    input_val12 = adb_disableListener_create( env);
                        if( AXIS2_FAILURE == adb_disableListener_deserialize(input_val12, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_disableListener_free(input_val12, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_disableListener_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val12 =  axis2_skel_TransportAdmin_disableListener(env, msg_ctx,input_val12,
                                                (axis2_skel_TransportAdmin_disableListener_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val12 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from disableListener ");
                        }
                        adb_disableListener_free(input_val12, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "listExposedTransports") == 0 )
                {

                    
                    input_val13 = adb_listExposedTransports_create( env);
                        if( AXIS2_FAILURE == adb_listExposedTransports_deserialize(input_val13, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listExposedTransports_free(input_val13, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listExposedTransports_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val13 =  axis2_skel_TransportAdmin_listExposedTransports(env, msg_ctx,input_val13,
                                                (axis2_skel_TransportAdmin_listExposedTransports_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val13 )
                        {
                            adb_listExposedTransports_free(input_val13, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listExposedTransportsResponse_serialize(ret_val13, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listExposedTransportsResponse_free(ret_val13, env);
                                   adb_listExposedTransports_free(input_val13, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServiceSpecificOutParameters") == 0 )
                {

                    
                    input_val14 = adb_getServiceSpecificOutParameters_create( env);
                        if( AXIS2_FAILURE == adb_getServiceSpecificOutParameters_deserialize(input_val14, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceSpecificOutParameters_free(input_val14, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceSpecificOutParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val14 =  axis2_skel_TransportAdmin_getServiceSpecificOutParameters(env, msg_ctx,input_val14,
                                                (axis2_skel_TransportAdmin_getServiceSpecificOutParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val14 )
                        {
                            adb_getServiceSpecificOutParameters_free(input_val14, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceSpecificOutParametersResponse_serialize(ret_val14, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceSpecificOutParametersResponse_free(ret_val14, env);
                                   adb_getServiceSpecificOutParameters_free(input_val14, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateGloballyDefinedOutParameters") == 0 )
                {

                    
                    input_val15 = adb_updateGloballyDefinedOutParameters_create( env);
                        if( AXIS2_FAILURE == adb_updateGloballyDefinedOutParameters_deserialize(input_val15, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateGloballyDefinedOutParameters_free(input_val15, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateGloballyDefinedOutParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val15 =  axis2_skel_TransportAdmin_updateGloballyDefinedOutParameters(env, msg_ctx,input_val15,
                                                (axis2_skel_TransportAdmin_updateGloballyDefinedOutParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val15 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateGloballyDefinedOutParameters ");
                        }
                        adb_updateGloballyDefinedOutParameters_free(input_val15, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getTransportDetails") == 0 )
                {

                    
                    input_val16 = adb_getTransportDetails_create( env);
                        if( AXIS2_FAILURE == adb_getTransportDetails_deserialize(input_val16, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getTransportDetails_free(input_val16, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getTransportDetails_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val16 =  axis2_skel_TransportAdmin_getTransportDetails(env, msg_ctx,input_val16,
                                                (axis2_skel_TransportAdmin_getTransportDetails_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val16 )
                        {
                            adb_getTransportDetails_free(input_val16, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getTransportDetailsResponse_serialize(ret_val16, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getTransportDetailsResponse_free(ret_val16, env);
                                   adb_getTransportDetails_free(input_val16, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateGloballyDefinedInParameters") == 0 )
                {

                    
                    input_val17 = adb_updateGloballyDefinedInParameters_create( env);
                        if( AXIS2_FAILURE == adb_updateGloballyDefinedInParameters_deserialize(input_val17, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateGloballyDefinedInParameters_free(input_val17, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateGloballyDefinedInParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val17 =  axis2_skel_TransportAdmin_updateGloballyDefinedInParameters(env, msg_ctx,input_val17,
                                                (axis2_skel_TransportAdmin_updateGloballyDefinedInParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val17 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateGloballyDefinedInParameters ");
                        }
                        adb_updateGloballyDefinedInParameters_free(input_val17, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "dependenciesAvailable") == 0 )
                {

                    
                    input_val18 = adb_dependenciesAvailable_create( env);
                        if( AXIS2_FAILURE == adb_dependenciesAvailable_deserialize(input_val18, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_dependenciesAvailable_free(input_val18, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_dependenciesAvailable_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val18 =  axis2_skel_TransportAdmin_dependenciesAvailable(env, msg_ctx,input_val18,
                                                (axis2_skel_TransportAdmin_dependenciesAvailable_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val18 )
                        {
                            adb_dependenciesAvailable_free(input_val18, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_dependenciesAvailableResponse_serialize(ret_val18, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_dependenciesAvailableResponse_free(ret_val18, env);
                                   adb_dependenciesAvailable_free(input_val18, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_TransportAdmin service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_TransportAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_TransportAdmin_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_TransportAdmin_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_TRANSPORTADMIN_ERROR_NONE ||
                error_code >= AXIS2_SKEL_TRANSPORTADMIN_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "TransportAdmin|http://mgt.transport.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_UPDATESERVICESPECIFICOUTPARAMETERS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.updateServiceSpecificOutParameters_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateServiceSpecificOutParameters_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_GETALLTRANSPORTDATA_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getAllTransportData_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getAllTransportData_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_GETGLOBALLYDEFINEDOUTPARAMETERS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getGloballyDefinedOutParameters_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getGloballyDefinedOutParameters_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_ADDEXPOSEDTRANSPORTS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.addExposedTransports_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addExposedTransports_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_LISTTRANSPORTSFORSERVICE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.listTransportsForService_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.listTransportsForService_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_GETSERVICESPECIFICINPARAMETERS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getServiceSpecificInParameters_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getServiceSpecificInParameters_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_REMOVEEXPOSEDTRANSPORTS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.removeExposedTransports_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.removeExposedTransports_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_UPDATESERVICESPECIFICINPARAMETERS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.updateServiceSpecificInParameters_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateServiceSpecificInParameters_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_DISABLESENDER_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.disableSender_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.disableSender_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_GETGLOBALLYDEFINEDINPARAMETERS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getGloballyDefinedInParameters_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getGloballyDefinedInParameters_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_DISABLELISTENER_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.disableListener_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.disableListener_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_LISTEXPOSEDTRANSPORTS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.listExposedTransports_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.listExposedTransports_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_GETSERVICESPECIFICOUTPARAMETERS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getServiceSpecificOutParameters_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getServiceSpecificOutParameters_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_UPDATEGLOBALLYDEFINEDOUTPARAMETERS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.updateGloballyDefinedOutParameters_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateGloballyDefinedOutParameters_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_GETTRANSPORTDETAILS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getTransportDetails_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getTransportDetails_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_UPDATEGLOBALLYDEFINEDINPARAMETERS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.updateGloballyDefinedInParameters_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateGloballyDefinedInParameters_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_TRANSPORTADMIN_DEPENDENCIESAVAILABLE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.dependenciesAvailable_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.dependenciesAvailable_fault.Exception = NULL;
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
		*inst = axis2_svc_skel_TransportAdmin_create(env);

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


    

