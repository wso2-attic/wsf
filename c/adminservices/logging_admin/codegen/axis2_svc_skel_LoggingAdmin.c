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
         * axis2_svc_skel_LoggingAdmin.c
         *
         * This file was auto-generated from WSDL for "LoggingAdmin|http://service.logging.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_LoggingAdmin
         */

        #include "axis2_skel_LoggingAdmin.h"
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
                axis2_skel_LoggingAdmin_restoreDefaults_fault restoreDefaults_fault;
                    axis2_skel_LoggingAdmin_updateSystemLog_fault updateSystemLog_fault;
                    axis2_skel_LoggingAdmin_getSystemLog_fault getSystemLog_fault;
                    axis2_skel_LoggingAdmin_updateAllAppenderData_fault updateAllAppenderData_fault;
                    axis2_skel_LoggingAdmin_updateLoggerData_fault updateLoggerData_fault;
                    
            } fault;
          
        }axis2_svc_skel_LoggingAdmin_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_LoggingAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_LoggingAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_LoggingAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_LoggingAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_LoggingAdmin_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_LoggingAdmin_svc_skeleton_ops_var = {
            axis2_svc_skel_LoggingAdmin_init,
            axis2_svc_skel_LoggingAdmin_invoke,
            axis2_svc_skel_LoggingAdmin_on_fault,
            axis2_svc_skel_LoggingAdmin_free
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
	axis2_svc_skel_LoggingAdmin_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_LoggingAdmin_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_LoggingAdmin_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_LoggingAdmin_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_LoggingAdmin_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_LoggingAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_LoggingAdmin */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_LoggingAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_LoggingAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_LoggingAdmin_t *svc_skeleton_wrapper = NULL;

          
            adb_getAllLoggerDataResponse_t* ret_val1;
            adb_getAllLoggerData_t* input_val1;
            
            axis2_status_t ret_val2;
            
            axis2_status_t ret_val3;
            adb_updateSystemLog_t* input_val3;
            
            adb_getSystemLogResponse_t* ret_val4;
            
            adb_getAppenderDataResponse_t* ret_val5;
            adb_getAppenderData_t* input_val5;
            
            axis2_status_t ret_val6;
            adb_updateAllAppenderData_t* input_val6;
            
            adb_getLoggerDataResponse_t* ret_val7;
            adb_getLoggerData_t* input_val7;
            
            axis2_status_t ret_val8;
            adb_updateLoggerData_t* input_val8;
            

          svc_skeleton_wrapper = (axis2_svc_skel_LoggingAdmin_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "getAllLoggerData") == 0 )
                {

                    
                    input_val1 = adb_getAllLoggerData_create( env);
                        if( AXIS2_FAILURE == adb_getAllLoggerData_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getAllLoggerData_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getAllLoggerData_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_LoggingAdmin_getAllLoggerData(env, msg_ctx,input_val1);
                    
                        if ( NULL == ret_val1 )
                        {
                            adb_getAllLoggerData_free(input_val1, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getAllLoggerDataResponse_serialize(ret_val1, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getAllLoggerDataResponse_free(ret_val1, env);
                                   adb_getAllLoggerData_free(input_val1, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "restoreDefaults") == 0 )
                {

                    
                        ret_val2 =  axis2_skel_LoggingAdmin_restoreDefaults(env, msg_ctx,
                                                (axis2_skel_LoggingAdmin_restoreDefaults_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val2 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from restoreDefaults ");
                        }
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateSystemLog") == 0 )
                {

                    
                    input_val3 = adb_updateSystemLog_create( env);
                        if( AXIS2_FAILURE == adb_updateSystemLog_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateSystemLog_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateSystemLog_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_LoggingAdmin_updateSystemLog(env, msg_ctx,input_val3,
                                                (axis2_skel_LoggingAdmin_updateSystemLog_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val3 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateSystemLog ");
                        }
                        adb_updateSystemLog_free(input_val3, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getSystemLog") == 0 )
                {

                    
                        ret_val4 =  axis2_skel_LoggingAdmin_getSystemLog(env, msg_ctx,
                                                (axis2_skel_LoggingAdmin_getSystemLog_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val4 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemLogResponse_serialize(ret_val4, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemLogResponse_free(ret_val4, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getAppenderData") == 0 )
                {

                    
                    input_val5 = adb_getAppenderData_create( env);
                        if( AXIS2_FAILURE == adb_getAppenderData_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getAppenderData_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getAppenderData_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_LoggingAdmin_getAppenderData(env, msg_ctx,input_val5);
                    
                        if ( NULL == ret_val5 )
                        {
                            adb_getAppenderData_free(input_val5, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getAppenderDataResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getAppenderDataResponse_free(ret_val5, env);
                                   adb_getAppenderData_free(input_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateAllAppenderData") == 0 )
                {

                    
                    input_val6 = adb_updateAllAppenderData_create( env);
                        if( AXIS2_FAILURE == adb_updateAllAppenderData_deserialize(input_val6, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateAllAppenderData_free(input_val6, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateAllAppenderData_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val6 =  axis2_skel_LoggingAdmin_updateAllAppenderData(env, msg_ctx,input_val6,
                                                (axis2_skel_LoggingAdmin_updateAllAppenderData_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val6 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateAllAppenderData ");
                        }
                        adb_updateAllAppenderData_free(input_val6, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getLoggerData") == 0 )
                {

                    
                    input_val7 = adb_getLoggerData_create( env);
                        if( AXIS2_FAILURE == adb_getLoggerData_deserialize(input_val7, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getLoggerData_free(input_val7, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getLoggerData_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val7 =  axis2_skel_LoggingAdmin_getLoggerData(env, msg_ctx,input_val7);
                    
                        if ( NULL == ret_val7 )
                        {
                            adb_getLoggerData_free(input_val7, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getLoggerDataResponse_serialize(ret_val7, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getLoggerDataResponse_free(ret_val7, env);
                                   adb_getLoggerData_free(input_val7, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "updateLoggerData") == 0 )
                {

                    
                    input_val8 = adb_updateLoggerData_create( env);
                        if( AXIS2_FAILURE == adb_updateLoggerData_deserialize(input_val8, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateLoggerData_free(input_val8, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateLoggerData_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val8 =  axis2_skel_LoggingAdmin_updateLoggerData(env, msg_ctx,input_val8,
                                                (axis2_skel_LoggingAdmin_updateLoggerData_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val8 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateLoggerData ");
                        }
                        adb_updateLoggerData_free(input_val8, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_LoggingAdmin service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_LoggingAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_LoggingAdmin_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_LoggingAdmin_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_LOGGINGADMIN_ERROR_NONE ||
                error_code >= AXIS2_SKEL_LOGGINGADMIN_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "LoggingAdmin|http://service.logging.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_LOGGINGADMIN_RESTOREDEFAULTS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.restoreDefaults_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.restoreDefaults_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_LOGGINGADMIN_UPDATESYSTEMLOG_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.updateSystemLog_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateSystemLog_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_LOGGINGADMIN_GETSYSTEMLOG_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getSystemLog_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getSystemLog_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_LOGGINGADMIN_UPDATEALLAPPENDERDATA_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.updateAllAppenderData_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateAllAppenderData_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_LOGGINGADMIN_UPDATELOGGERDATA_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.updateLoggerData_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateLoggerData_fault.Exception = NULL;
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
		*inst = axis2_svc_skel_LoggingAdmin_create(env);

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


    

