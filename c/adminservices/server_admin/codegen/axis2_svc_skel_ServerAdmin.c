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
         * axis2_svc_skel_ServerAdmin.c
         *
         * This file was auto-generated from WSDL for "ServerAdmin|http://service.admin.server.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_ServerAdmin
         */

        #include "axis2_skel_ServerAdmin.h"
        #include <axis2_svc_skeleton.h>
        #include <stdio.h>
        #include <axis2_svc.h>

		time_t start_time = NULL;		

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
                axis2_skel_ServerAdmin_getServerStatus_fault getServerStatus_fault;
                    axis2_skel_ServerAdmin_startMaintenance_fault startMaintenance_fault;
                    axis2_skel_ServerAdmin_endMaintenance_fault endMaintenance_fault;
                    axis2_skel_ServerAdmin_getServerDataAsString_fault getServerDataAsString_fault;
                    axis2_skel_ServerAdmin_restartGracefully_fault restartGracefully_fault;
                    axis2_skel_ServerAdmin_restart_fault restart_fault;
                    
            } fault;
          
        }axis2_svc_skel_ServerAdmin_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ServerAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_ServerAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ServerAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_ServerAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_ServerAdmin_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_ServerAdmin_svc_skeleton_ops_var = {
            axis2_svc_skel_ServerAdmin_init,
            axis2_svc_skel_ServerAdmin_invoke,
            axis2_svc_skel_ServerAdmin_on_fault,
            axis2_svc_skel_ServerAdmin_free
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
	axis2_svc_skel_ServerAdmin_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_ServerAdmin_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_ServerAdmin_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_ServerAdmin_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_ServerAdmin_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_ServerAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
		/* Set server start time */
		time(&start_time);

	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_ServerAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_ServerAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_ServerAdmin_t *svc_skeleton_wrapper = NULL;

          
            adb_getServerStatusResponse_t* ret_val1;
            
            axis2_status_t ret_val2;
            
            adb_shutdownResponse_t* ret_val3;
            
            axis2_status_t ret_val4;
            
            adb_getServerDataAsStringResponse_t* ret_val5;
            
            adb_isAliveResponse_t* ret_val6;
            
            adb_getServerDataResponse_t* ret_val7;
            
            adb_restartGracefullyResponse_t* ret_val8;
            
            adb_getServerVersionResponse_t* ret_val9;
            
            adb_restartResponse_t* ret_val10;
            
            adb_shutdownGracefullyResponse_t* ret_val11;
            

          svc_skeleton_wrapper = (axis2_svc_skel_ServerAdmin_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "getServerStatus") == 0 )
                {

                    
                        ret_val1 =  axis2_skel_ServerAdmin_getServerStatus(env, msg_ctx,
                                                (axis2_skel_ServerAdmin_getServerStatus_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val1 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getServerStatusResponse_serialize(ret_val1, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServerStatusResponse_free(ret_val1, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "startMaintenance") == 0 )
                {

                    
                        ret_val2 =  axis2_skel_ServerAdmin_startMaintenance(env, msg_ctx,
                                                (axis2_skel_ServerAdmin_startMaintenance_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val2 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from startMaintenance ");
                        }
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "shutdown") == 0 )
                {

                    
                        ret_val3 =  axis2_skel_ServerAdmin_shutdown(env, msg_ctx);
                    
                        if ( NULL == ret_val3 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_shutdownResponse_serialize(ret_val3, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_shutdownResponse_free(ret_val3, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "endMaintenance") == 0 )
                {

                    
                        ret_val4 =  axis2_skel_ServerAdmin_endMaintenance(env, msg_ctx,
                                                (axis2_skel_ServerAdmin_endMaintenance_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val4 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from endMaintenance ");
                        }
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getServerDataAsString") == 0 )
                {

                    
                        ret_val5 =  axis2_skel_ServerAdmin_getServerDataAsString(env, msg_ctx,
                                                (axis2_skel_ServerAdmin_getServerDataAsString_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val5 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getServerDataAsStringResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServerDataAsStringResponse_free(ret_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "isAlive") == 0 )
                {

                    
                        ret_val6 =  axis2_skel_ServerAdmin_isAlive(env, msg_ctx);
                    
                        if ( NULL == ret_val6 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_isAliveResponse_serialize(ret_val6, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_isAliveResponse_free(ret_val6, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServerData") == 0 )
                {

                    
                        ret_val7 =  axis2_skel_ServerAdmin_getServerData(env, msg_ctx);
                    
                        if ( NULL == ret_val7 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getServerDataResponse_serialize(ret_val7, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServerDataResponse_free(ret_val7, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "restartGracefully") == 0 )
                {

                    
                        ret_val8 =  axis2_skel_ServerAdmin_restartGracefully(env, msg_ctx,
                                                (axis2_skel_ServerAdmin_restartGracefully_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val8 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_restartGracefullyResponse_serialize(ret_val8, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_restartGracefullyResponse_free(ret_val8, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServerVersion") == 0 )
                {

                    
                        ret_val9 =  axis2_skel_ServerAdmin_getServerVersion(env, msg_ctx);
                    
                        if ( NULL == ret_val9 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getServerVersionResponse_serialize(ret_val9, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServerVersionResponse_free(ret_val9, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "restart") == 0 )
                {

                    
                        ret_val10 =  axis2_skel_ServerAdmin_restart(env, msg_ctx,
                                                (axis2_skel_ServerAdmin_restart_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val10 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_restartResponse_serialize(ret_val10, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_restartResponse_free(ret_val10, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "shutdownGracefully") == 0 )
                {

                    
                        ret_val11 =  axis2_skel_ServerAdmin_shutdownGracefully(env, msg_ctx);
                    
                        if ( NULL == ret_val11 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_shutdownGracefullyResponse_serialize(ret_val11, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_shutdownGracefullyResponse_free(ret_val11, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_ServerAdmin service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_ServerAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_ServerAdmin_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_ServerAdmin_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_SERVERADMIN_ERROR_NONE ||
                error_code >= AXIS2_SKEL_SERVERADMIN_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "ServerAdmin|http://service.admin.server.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_SERVERADMIN_GETSERVERSTATUS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getServerStatus_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getServerStatus_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVERADMIN_STARTMAINTENANCE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.startMaintenance_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.startMaintenance_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVERADMIN_ENDMAINTENANCE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.endMaintenance_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.endMaintenance_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVERADMIN_GETSERVERDATAASSTRING_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getServerDataAsString_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getServerDataAsString_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVERADMIN_RESTARTGRACEFULLY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.restartGracefully_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.restartGracefully_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVERADMIN_RESTART_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.restart_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.restart_fault.Exception = NULL;
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
		*inst = axis2_svc_skel_ServerAdmin_create(env);

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


    

