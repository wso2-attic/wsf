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
         * axis2_svc_skel_ServiceGroupAdmin.c
         *
         * This file was auto-generated from WSDL for "ServiceGroupAdmin|http://mgt.service.carbon.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_ServiceGroupAdmin
         */

        #include "axis2_skel_ServiceGroupAdmin.h"
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
                axis2_skel_ServiceGroupAdmin_listServiceGroup_fault listServiceGroup_fault;
                    axis2_skel_ServiceGroupAdmin_getServiceGroupParameter_fault getServiceGroupParameter_fault;
                    axis2_skel_ServiceGroupAdmin_configureServiceGroupMTOM_fault configureServiceGroupMTOM_fault;
                    axis2_skel_ServiceGroupAdmin_updateServiceGroupParamters_fault updateServiceGroupParamters_fault;
                    axis2_skel_ServiceGroupAdmin_updateServiceGroupParameter_fault updateServiceGroupParameter_fault;
                    axis2_skel_ServiceGroupAdmin_getServiceGroupParameters_fault getServiceGroupParameters_fault;
                    
            } fault;
          
        }axis2_svc_skel_ServiceGroupAdmin_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ServiceGroupAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_ServiceGroupAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ServiceGroupAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_ServiceGroupAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_ServiceGroupAdmin_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_ServiceGroupAdmin_svc_skeleton_ops_var = {
            axis2_svc_skel_ServiceGroupAdmin_init,
            axis2_svc_skel_ServiceGroupAdmin_invoke,
            axis2_svc_skel_ServiceGroupAdmin_on_fault,
            axis2_svc_skel_ServiceGroupAdmin_free
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
	axis2_svc_skel_ServiceGroupAdmin_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_ServiceGroupAdmin_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_ServiceGroupAdmin_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_ServiceGroupAdmin_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_ServiceGroupAdmin_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_ServiceGroupAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_ServiceGroupAdmin */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_ServiceGroupAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_ServiceGroupAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_ServiceGroupAdmin_t *svc_skeleton_wrapper = NULL;

          
            adb_listServiceGroupResponse_t* ret_val1;
            adb_listServiceGroup_t* input_val1;
            
            axis2_status_t ret_val2;
            adb_setServiceGroupParameters_t* input_val2;
            
            adb_getServiceGroupParameterResponse_t* ret_val3;
            adb_getServiceGroupParameter_t* input_val3;
            
            adb_configureServiceGroupMTOMResponse_t* ret_val4;
            adb_configureServiceGroupMTOM_t* input_val4;
            
            axis2_status_t ret_val5;
            adb_removeServiceGroupParameter_t* input_val5;
            
            axis2_status_t ret_val6;
            adb_updateServiceGroupParamters_t* input_val6;
            
            adb_dumpAARResponse_t* ret_val7;
            adb_dumpAAR_t* input_val7;
            
            axis2_status_t ret_val8;
            adb_setServiceGroupParameter_t* input_val8;
            
            axis2_status_t ret_val9;
            adb_updateServiceGroupParameter_t* input_val9;
            
			adb_listServiceGroup_t* ret_val10;
            
            adb_getServiceGroupParametersResponse_t* ret_val11;
            adb_getServiceGroupParameters_t* input_val11;
            

          svc_skeleton_wrapper = (axis2_svc_skel_ServiceGroupAdmin_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "listServiceGroup") == 0 )
                {

                    
                    input_val1 = adb_listServiceGroup_create( env);
                        if( AXIS2_FAILURE == adb_listServiceGroup_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listServiceGroup_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listServiceGroup_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_ServiceGroupAdmin_listServiceGroup(env, msg_ctx,input_val1,
                                                (axis2_skel_ServiceGroupAdmin_listServiceGroup_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val1 )
                        {
                            adb_listServiceGroup_free(input_val1, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listServiceGroupResponse_serialize(ret_val1, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listServiceGroupResponse_free(ret_val1, env);
                                   adb_listServiceGroup_free(input_val1, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setServiceGroupParameters") == 0 )
                {

                    
                    input_val2 = adb_setServiceGroupParameters_create( env);
                        if( AXIS2_FAILURE == adb_setServiceGroupParameters_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setServiceGroupParameters_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setServiceGroupParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_ServiceGroupAdmin_setServiceGroupParameters(env, msg_ctx,input_val2);
                    
                        if( AXIS2_FAILURE == ret_val2 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setServiceGroupParameters ");
                        }
                        adb_setServiceGroupParameters_free(input_val2, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getServiceGroupParameter") == 0 )
                {

                    
                    input_val3 = adb_getServiceGroupParameter_create( env);
                        if( AXIS2_FAILURE == adb_getServiceGroupParameter_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceGroupParameter_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceGroupParameter_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_ServiceGroupAdmin_getServiceGroupParameter(env, msg_ctx,input_val3,
                                                (axis2_skel_ServiceGroupAdmin_getServiceGroupParameter_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val3 )
                        {
                            adb_getServiceGroupParameter_free(input_val3, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceGroupParameterResponse_serialize(ret_val3, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceGroupParameterResponse_free(ret_val3, env);
                                   adb_getServiceGroupParameter_free(input_val3, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "configureServiceGroupMTOM") == 0 )
                {

                    
                    input_val4 = adb_configureServiceGroupMTOM_create( env);
                        if( AXIS2_FAILURE == adb_configureServiceGroupMTOM_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_configureServiceGroupMTOM_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_configureServiceGroupMTOM_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_ServiceGroupAdmin_configureServiceGroupMTOM(env, msg_ctx,input_val4,
                                                (axis2_skel_ServiceGroupAdmin_configureServiceGroupMTOM_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val4 )
                        {
                            adb_configureServiceGroupMTOM_free(input_val4, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_configureServiceGroupMTOMResponse_serialize(ret_val4, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_configureServiceGroupMTOMResponse_free(ret_val4, env);
                                   adb_configureServiceGroupMTOM_free(input_val4, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "removeServiceGroupParameter") == 0 )
                {

                    
                    input_val5 = adb_removeServiceGroupParameter_create( env);
                        if( AXIS2_FAILURE == adb_removeServiceGroupParameter_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeServiceGroupParameter_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeServiceGroupParameter_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_ServiceGroupAdmin_removeServiceGroupParameter(env, msg_ctx,input_val5);
                    
                        if( AXIS2_FAILURE == ret_val5 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from removeServiceGroupParameter ");
                        }
                        adb_removeServiceGroupParameter_free(input_val5, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateServiceGroupParamters") == 0 )
                {

                    
                    input_val6 = adb_updateServiceGroupParamters_create( env);
                        if( AXIS2_FAILURE == adb_updateServiceGroupParamters_deserialize(input_val6, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateServiceGroupParamters_free(input_val6, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateServiceGroupParamters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val6 =  axis2_skel_ServiceGroupAdmin_updateServiceGroupParamters(env, msg_ctx,input_val6,
                                                (axis2_skel_ServiceGroupAdmin_updateServiceGroupParamters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val6 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateServiceGroupParamters ");
                        }
                        adb_updateServiceGroupParamters_free(input_val6, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "dumpAAR") == 0 )
                {

                    
                    input_val7 = adb_dumpAAR_create( env);
                        if( AXIS2_FAILURE == adb_dumpAAR_deserialize(input_val7, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_dumpAAR_free(input_val7, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_dumpAAR_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val7 =  axis2_skel_ServiceGroupAdmin_dumpAAR(env, msg_ctx,input_val7);
                    
                        if ( NULL == ret_val7 )
                        {
                            adb_dumpAAR_free(input_val7, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_dumpAARResponse_serialize(ret_val7, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_dumpAARResponse_free(ret_val7, env);
                                   adb_dumpAAR_free(input_val7, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setServiceGroupParameter") == 0 )
                {

                    
                    input_val8 = adb_setServiceGroupParameter_create( env);
                        if( AXIS2_FAILURE == adb_setServiceGroupParameter_deserialize(input_val8, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setServiceGroupParameter_free(input_val8, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setServiceGroupParameter_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val8 =  axis2_skel_ServiceGroupAdmin_setServiceGroupParameter(env, msg_ctx,input_val8);
                    
                        if( AXIS2_FAILURE == ret_val8 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setServiceGroupParameter ");
                        }
                        adb_setServiceGroupParameter_free(input_val8, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "updateServiceGroupParameter") == 0 )
                {

                    
                    input_val9 = adb_updateServiceGroupParameter_create( env);
                        if( AXIS2_FAILURE == adb_updateServiceGroupParameter_deserialize(input_val9, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_updateServiceGroupParameter_free(input_val9, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_updateServiceGroupParameter_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val9 =  axis2_skel_ServiceGroupAdmin_updateServiceGroupParameter(env, msg_ctx,input_val9,
                                                (axis2_skel_ServiceGroupAdmin_updateServiceGroupParameter_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val9 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from updateServiceGroupParameter ");
                        }
                        adb_updateServiceGroupParameter_free(input_val9, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "listServiceGroups") == 0 )
                {

                    
                        ret_val10 =  axis2_skel_ServiceGroupAdmin_listServiceGroups(env, msg_ctx);
                    
                        if ( NULL == ret_val10 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = ret_val10;

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getServiceGroupParameters") == 0 )
                {

                    
                    input_val11 = adb_getServiceGroupParameters_create( env);
                        if( AXIS2_FAILURE == adb_getServiceGroupParameters_deserialize(input_val11, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceGroupParameters_free(input_val11, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceGroupParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val11 =  axis2_skel_ServiceGroupAdmin_getServiceGroupParameters(env, msg_ctx,input_val11,
                                                (axis2_skel_ServiceGroupAdmin_getServiceGroupParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val11 )
                        {
                            adb_getServiceGroupParameters_free(input_val11, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceGroupParametersResponse_serialize(ret_val11, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceGroupParametersResponse_free(ret_val11, env);
                                   adb_getServiceGroupParameters_free(input_val11, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_ServiceGroupAdmin service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_ServiceGroupAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_ServiceGroupAdmin_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_ServiceGroupAdmin_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_SERVICEGROUPADMIN_ERROR_NONE ||
                error_code >= AXIS2_SKEL_SERVICEGROUPADMIN_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "ServiceGroupAdmin|http://mgt.service.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_SERVICEGROUPADMIN_LISTSERVICEGROUP_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.listServiceGroup_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.listServiceGroup_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEGROUPADMIN_GETSERVICEGROUPPARAMETER_FAULT_SERVEREXCEPTION)
                {
                    /* found which error code */
                    adb_ServerExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ServerExceptionE1_t*)svc_skeleton_wrapper->fault.getServiceGroupParameter_fault.ServerException;
                    if(adb_obj)
                    {
                        error_node = adb_ServerExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ServerExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getServiceGroupParameter_fault.ServerException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEGROUPADMIN_CONFIGURESERVICEGROUPMTOM_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.configureServiceGroupMTOM_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.configureServiceGroupMTOM_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEGROUPADMIN_UPDATESERVICEGROUPPARAMTERS_FAULT_SERVEREXCEPTION)
                {
                    /* found which error code */
                    adb_ServerExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ServerExceptionE1_t*)svc_skeleton_wrapper->fault.updateServiceGroupParamters_fault.ServerException;
                    if(adb_obj)
                    {
                        error_node = adb_ServerExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ServerExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateServiceGroupParamters_fault.ServerException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEGROUPADMIN_UPDATESERVICEGROUPPARAMETER_FAULT_SERVEREXCEPTION)
                {
                    /* found which error code */
                    adb_ServerExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ServerExceptionE1_t*)svc_skeleton_wrapper->fault.updateServiceGroupParameter_fault.ServerException;
                    if(adb_obj)
                    {
                        error_node = adb_ServerExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ServerExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.updateServiceGroupParameter_fault.ServerException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEGROUPADMIN_GETSERVICEGROUPPARAMETERS_FAULT_SERVEREXCEPTION)
                {
                    /* found which error code */
                    adb_ServerExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ServerExceptionE1_t*)svc_skeleton_wrapper->fault.getServiceGroupParameters_fault.ServerException;
                    if(adb_obj)
                    {
                        error_node = adb_ServerExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ServerExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getServiceGroupParameters_fault.ServerException = NULL;
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
		*inst = axis2_svc_skel_ServiceGroupAdmin_create(env);

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


    

