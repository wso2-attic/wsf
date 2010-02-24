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
         * axis2_svc_skel_ServiceAdmin.c
         *
         * This file was auto-generated from WSDL for "ServiceAdmin|http://mgt.service.carbon.wso2.org" service
         * by the Apache Axis2 version: SNAPSHOT  Built on : Jan 19, 2010 (01:46:42 IST)
         *  axis2_svc_skel_ServiceAdmin
         */

        #include "axis2_skel_ServiceAdmin.h"
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
                axis2_skel_ServiceAdmin_startService_fault startService_fault;
                    axis2_skel_ServiceAdmin_addTransportBinding_fault addTransportBinding_fault;
                    axis2_skel_ServiceAdmin_setServicePolicy_fault setServicePolicy_fault;
                    axis2_skel_ServiceAdmin_addPoliciesToService_fault addPoliciesToService_fault;
                    axis2_skel_ServiceAdmin_getServiceParameters_fault getServiceParameters_fault;
                    axis2_skel_ServiceAdmin_setBindingOperationMessagePolicy_fault setBindingOperationMessagePolicy_fault;
                    axis2_skel_ServiceAdmin_setBindingPolicy_fault setBindingPolicy_fault;
                    axis2_skel_ServiceAdmin_removeServicePoliciesByNamespace_fault removeServicePoliciesByNamespace_fault;
                    axis2_skel_ServiceAdmin_setBindingOperationPolicy_fault setBindingOperationPolicy_fault;
                    axis2_skel_ServiceAdmin_setModulePolicy_fault setModulePolicy_fault;
                    axis2_skel_ServiceAdmin_getNumberOfActiveServices_fault getNumberOfActiveServices_fault;
                    axis2_skel_ServiceAdmin_removeTransportBinding_fault removeTransportBinding_fault;
                    axis2_skel_ServiceAdmin_getNumberOfInactiveServices_fault getNumberOfInactiveServices_fault;
                    axis2_skel_ServiceAdmin_setServiceOperationPolicy_fault setServiceOperationPolicy_fault;
                    axis2_skel_ServiceAdmin_engageModuleToService_fault engageModuleToService_fault;
                    axis2_skel_ServiceAdmin_removeBindingPolicy_fault removeBindingPolicy_fault;
                    axis2_skel_ServiceAdmin_setPolicy_fault setPolicy_fault;
                    axis2_skel_ServiceAdmin_setServiceOperationMessagePolicy_fault setServiceOperationMessagePolicy_fault;
                    axis2_skel_ServiceAdmin_getServiceBindings_fault getServiceBindings_fault;
                    axis2_skel_ServiceAdmin_stopService_fault stopService_fault;
                    
            } fault;
          
        }axis2_svc_skel_ServiceAdmin_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ServiceAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_ServiceAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ServiceAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_ServiceAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_ServiceAdmin_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_ServiceAdmin_svc_skeleton_ops_var = {
            axis2_svc_skel_ServiceAdmin_init,
            axis2_svc_skel_ServiceAdmin_invoke,
            axis2_svc_skel_ServiceAdmin_on_fault,
            axis2_svc_skel_ServiceAdmin_free
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
	axis2_svc_skel_ServiceAdmin_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_ServiceAdmin_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_ServiceAdmin_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_ServiceAdmin_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_ServiceAdmin_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_ServiceAdmin_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_ServiceAdmin */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_ServiceAdmin_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_ServiceAdmin_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_ServiceAdmin_t *svc_skeleton_wrapper = NULL;

          
            axis2_status_t ret_val1;
            adb_startService_t* input_val1;
            
            adb_getExposedTransportsResponse_t* ret_val2;
            adb_getExposedTransports_t* input_val2;
            
            adb_listServiceGroupResponse_t* ret_val3;
            adb_listServiceGroup_t* input_val3;
            
            adb_addTransportBindingResponse_t* ret_val4;
            adb_addTransportBinding_t* input_val4;
            
            adb_getWSDLResponse_t* ret_val5;
            adb_getWSDL_t* input_val5;
            
            adb_getNumberOfFaultyServicesResponse_t* ret_val6;
            
            axis2_status_t ret_val7;
            adb_configureMTOM_t* input_val7;
            
            axis2_status_t ret_val8;
            adb_setServicePolicy_t* input_val8;
            
            adb_getPolicyResponse_t* ret_val9;
            adb_getPolicy_t* input_val9;
            
            adb_getFaultyServiceArchivesResponse_t* ret_val10;
            adb_getFaultyServiceArchives_t* input_val10;
            
            axis2_status_t ret_val11;
            adb_addPoliciesToService_t* input_val11;
            
            adb_getServiceParametersResponse_t* ret_val12;
            adb_getServiceParameters_t* input_val12;
            
            axis2_status_t ret_val13;
            adb_setBindingOperationMessagePolicy_t* input_val13;
            
            axis2_status_t ret_val14;
            adb_setBindingPolicy_t* input_val14;
            
            axis2_status_t ret_val15;
            adb_removeServicePoliciesByNamespace_t* input_val15;
            
            axis2_status_t ret_val16;
            adb_setBindingOperationPolicy_t* input_val16;
            
            axis2_status_t ret_val17;
            adb_setModulePolicy_t* input_val17;
            
            adb_getBindingOperationMessagePolicyResponse_t* ret_val18;
            adb_getBindingOperationMessagePolicy_t* input_val18;
            
            axis2_status_t ret_val19;
            adb_changeServiceState_t* input_val19;
            
            axis2_status_t ret_val20;
            adb_setServiceParameters_t* input_val20;
            
            adb_getOperationMessagePolicyResponse_t* ret_val21;
            adb_getOperationMessagePolicy_t* input_val21;
            
            adb_getNumberOfActiveServicesResponse_t* ret_val22;
            
            adb_getServiceDataResponse_t* ret_val23;
            adb_getServiceData_t* input_val23;
            
            adb_removeTransportBindingResponse_t* ret_val24;
            adb_removeTransportBinding_t* input_val24;
            
            adb_getPoliciesResponse_t* ret_val25;
            adb_getPolicies_t* input_val25;
            
            axis2_status_t ret_val26;
            adb_removeServiceParameter_t* input_val26;
            
            adb_getBindingOperationPolicyResponse_t* ret_val27;
            adb_getBindingOperationPolicy_t* input_val27;
            
            axis2_status_t ret_val28;
            adb_deleteServiceGroups_t* input_val28;
            
            adb_getNumberOfInactiveServicesResponse_t* ret_val29;
            
            axis2_status_t ret_val30;
            adb_setServiceOperationPolicy_t* input_val30;
            
            adb_deleteFaultyServiceGroupResponse_t* ret_val31;
            adb_deleteFaultyServiceGroup_t* input_val31;
            
            axis2_status_t ret_val32;
            adb_engageModuleToService_t* input_val32;
            
            axis2_status_t ret_val33;
            adb_deleteFaultyServiceGroups_t* input_val33;
            
            axis2_status_t ret_val34;
            adb_removeBindingPolicy_t* input_val34;
            
            axis2_status_t ret_val35;
            
            axis2_status_t ret_val36;
            
            adb_getModulePolicyResponse_t* ret_val37;
            adb_getModulePolicy_t* input_val37;
            
            axis2_status_t ret_val38;
            adb_setPolicy_t* input_val38;
            
            adb_listServiceGroupsResponse_t* ret_val39;
            adb_listServiceGroups_t* input_val39;
            
            axis2_status_t ret_val40;
            adb_setServiceOperationMessagePolicy_t* input_val40;
            
            adb_getBindingPolicyResponse_t* ret_val41;
            adb_getBindingPolicy_t* input_val41;
            
            adb_getServiceBindingsResponse_t* ret_val42;
            adb_getServiceBindings_t* input_val42;
            
            axis2_status_t ret_val43;
            adb_stopService_t* input_val43;
            
            adb_getOperationPolicyResponse_t* ret_val44;
            adb_getOperationPolicy_t* input_val44;
            

          svc_skeleton_wrapper = (axis2_svc_skel_ServiceAdmin_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "startService") == 0 )
                {

                    
                    input_val1 = adb_startService_create( env);
                        if( AXIS2_FAILURE == adb_startService_deserialize(input_val1, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_startService_free(input_val1, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_startService_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val1 =  axis2_skel_ServiceAdmin_startService(env, msg_ctx,input_val1,
                                                (axis2_skel_ServiceAdmin_startService_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val1 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from startService ");
                        }
                        adb_startService_free(input_val1, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getExposedTransports") == 0 )
                {

                    
                    input_val2 = adb_getExposedTransports_create( env);
                        if( AXIS2_FAILURE == adb_getExposedTransports_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getExposedTransports_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getExposedTransports_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_ServiceAdmin_getExposedTransports(env, msg_ctx,input_val2);
                    
                        if ( NULL == ret_val2 )
                        {
                            adb_getExposedTransports_free(input_val2, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getExposedTransportsResponse_serialize(ret_val2, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getExposedTransportsResponse_free(ret_val2, env);
                                   adb_getExposedTransports_free(input_val2, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "listServiceGroup") == 0 )
                {

                    
                    input_val3 = adb_listServiceGroup_create( env);
                        if( AXIS2_FAILURE == adb_listServiceGroup_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listServiceGroup_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listServiceGroup_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_ServiceAdmin_listServiceGroup(env, msg_ctx,input_val3);
                    
                        if ( NULL == ret_val3 )
                        {
                            adb_listServiceGroup_free(input_val3, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listServiceGroupResponse_serialize(ret_val3, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listServiceGroupResponse_free(ret_val3, env);
                                   adb_listServiceGroup_free(input_val3, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "addTransportBinding") == 0 )
                {

                    
                    input_val4 = adb_addTransportBinding_create( env);
                        if( AXIS2_FAILURE == adb_addTransportBinding_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addTransportBinding_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addTransportBinding_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_ServiceAdmin_addTransportBinding(env, msg_ctx,input_val4,
                                                (axis2_skel_ServiceAdmin_addTransportBinding_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val4 )
                        {
                            adb_addTransportBinding_free(input_val4, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_addTransportBindingResponse_serialize(ret_val4, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_addTransportBindingResponse_free(ret_val4, env);
                                   adb_addTransportBinding_free(input_val4, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getWSDL") == 0 )
                {

                    
                    input_val5 = adb_getWSDL_create( env);
                        if( AXIS2_FAILURE == adb_getWSDL_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getWSDL_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getWSDL_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_ServiceAdmin_getWSDL(env, msg_ctx,input_val5);
                    
                        if ( NULL == ret_val5 )
                        {
                            adb_getWSDL_free(input_val5, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getWSDLResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getWSDLResponse_free(ret_val5, env);
                                   adb_getWSDL_free(input_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getNumberOfFaultyServices") == 0 )
                {

                    
                        ret_val6 =  axis2_skel_ServiceAdmin_getNumberOfFaultyServices(env, msg_ctx);
                    
                        if ( NULL == ret_val6 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getNumberOfFaultyServicesResponse_serialize(ret_val6, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getNumberOfFaultyServicesResponse_free(ret_val6, env);
                                   

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
                        
                        ret_val7 =  axis2_skel_ServiceAdmin_configureMTOM(env, msg_ctx,input_val7);
                    
                        if( AXIS2_FAILURE == ret_val7 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from configureMTOM ");
                        }
                        adb_configureMTOM_free(input_val7, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "setServicePolicy") == 0 )
                {

                    
                    input_val8 = adb_setServicePolicy_create( env);
                        if( AXIS2_FAILURE == adb_setServicePolicy_deserialize(input_val8, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setServicePolicy_free(input_val8, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setServicePolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val8 =  axis2_skel_ServiceAdmin_setServicePolicy(env, msg_ctx,input_val8,
                                                (axis2_skel_ServiceAdmin_setServicePolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val8 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setServicePolicy ");
                        }
                        adb_setServicePolicy_free(input_val8, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getPolicy") == 0 )
                {

                    
                    input_val9 = adb_getPolicy_create( env);
                        if( AXIS2_FAILURE == adb_getPolicy_deserialize(input_val9, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getPolicy_free(input_val9, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val9 =  axis2_skel_ServiceAdmin_getPolicy(env, msg_ctx,input_val9);
                    
                        if ( NULL == ret_val9 )
                        {
                            adb_getPolicy_free(input_val9, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getPolicyResponse_serialize(ret_val9, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getPolicyResponse_free(ret_val9, env);
                                   adb_getPolicy_free(input_val9, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getFaultyServiceArchives") == 0 )
                {

                    
                    input_val10 = adb_getFaultyServiceArchives_create( env);
                        if( AXIS2_FAILURE == adb_getFaultyServiceArchives_deserialize(input_val10, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getFaultyServiceArchives_free(input_val10, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getFaultyServiceArchives_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val10 =  axis2_skel_ServiceAdmin_getFaultyServiceArchives(env, msg_ctx,input_val10);
                    
                        if ( NULL == ret_val10 )
                        {
                            adb_getFaultyServiceArchives_free(input_val10, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getFaultyServiceArchivesResponse_serialize(ret_val10, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getFaultyServiceArchivesResponse_free(ret_val10, env);
                                   adb_getFaultyServiceArchives_free(input_val10, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "addPoliciesToService") == 0 )
                {

                    
                    input_val11 = adb_addPoliciesToService_create( env);
                        if( AXIS2_FAILURE == adb_addPoliciesToService_deserialize(input_val11, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_addPoliciesToService_free(input_val11, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_addPoliciesToService_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val11 =  axis2_skel_ServiceAdmin_addPoliciesToService(env, msg_ctx,input_val11,
                                                (axis2_skel_ServiceAdmin_addPoliciesToService_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val11 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from addPoliciesToService ");
                        }
                        adb_addPoliciesToService_free(input_val11, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getServiceParameters") == 0 )
                {

                    
                    input_val12 = adb_getServiceParameters_create( env);
                        if( AXIS2_FAILURE == adb_getServiceParameters_deserialize(input_val12, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceParameters_free(input_val12, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val12 =  axis2_skel_ServiceAdmin_getServiceParameters(env, msg_ctx,input_val12,
                                                (axis2_skel_ServiceAdmin_getServiceParameters_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val12 )
                        {
                            adb_getServiceParameters_free(input_val12, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceParametersResponse_serialize(ret_val12, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceParametersResponse_free(ret_val12, env);
                                   adb_getServiceParameters_free(input_val12, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setBindingOperationMessagePolicy") == 0 )
                {

                    
                    input_val13 = adb_setBindingOperationMessagePolicy_create( env);
                        if( AXIS2_FAILURE == adb_setBindingOperationMessagePolicy_deserialize(input_val13, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setBindingOperationMessagePolicy_free(input_val13, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setBindingOperationMessagePolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val13 =  axis2_skel_ServiceAdmin_setBindingOperationMessagePolicy(env, msg_ctx,input_val13,
                                                (axis2_skel_ServiceAdmin_setBindingOperationMessagePolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val13 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setBindingOperationMessagePolicy ");
                        }
                        adb_setBindingOperationMessagePolicy_free(input_val13, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "setBindingPolicy") == 0 )
                {

                    
                    input_val14 = adb_setBindingPolicy_create( env);
                        if( AXIS2_FAILURE == adb_setBindingPolicy_deserialize(input_val14, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setBindingPolicy_free(input_val14, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setBindingPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val14 =  axis2_skel_ServiceAdmin_setBindingPolicy(env, msg_ctx,input_val14,
                                                (axis2_skel_ServiceAdmin_setBindingPolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val14 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setBindingPolicy ");
                        }
                        adb_setBindingPolicy_free(input_val14, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "removeServicePoliciesByNamespace") == 0 )
                {

                    
                    input_val15 = adb_removeServicePoliciesByNamespace_create( env);
                        if( AXIS2_FAILURE == adb_removeServicePoliciesByNamespace_deserialize(input_val15, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeServicePoliciesByNamespace_free(input_val15, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeServicePoliciesByNamespace_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val15 =  axis2_skel_ServiceAdmin_removeServicePoliciesByNamespace(env, msg_ctx,input_val15,
                                                (axis2_skel_ServiceAdmin_removeServicePoliciesByNamespace_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val15 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from removeServicePoliciesByNamespace ");
                        }
                        adb_removeServicePoliciesByNamespace_free(input_val15, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "setBindingOperationPolicy") == 0 )
                {

                    
                    input_val16 = adb_setBindingOperationPolicy_create( env);
                        if( AXIS2_FAILURE == adb_setBindingOperationPolicy_deserialize(input_val16, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setBindingOperationPolicy_free(input_val16, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setBindingOperationPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val16 =  axis2_skel_ServiceAdmin_setBindingOperationPolicy(env, msg_ctx,input_val16,
                                                (axis2_skel_ServiceAdmin_setBindingOperationPolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val16 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setBindingOperationPolicy ");
                        }
                        adb_setBindingOperationPolicy_free(input_val16, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "setModulePolicy") == 0 )
                {

                    
                    input_val17 = adb_setModulePolicy_create( env);
                        if( AXIS2_FAILURE == adb_setModulePolicy_deserialize(input_val17, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setModulePolicy_free(input_val17, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setModulePolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val17 =  axis2_skel_ServiceAdmin_setModulePolicy(env, msg_ctx,input_val17,
                                                (axis2_skel_ServiceAdmin_setModulePolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val17 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setModulePolicy ");
                        }
                        adb_setModulePolicy_free(input_val17, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getBindingOperationMessagePolicy") == 0 )
                {

                    
                    input_val18 = adb_getBindingOperationMessagePolicy_create( env);
                        if( AXIS2_FAILURE == adb_getBindingOperationMessagePolicy_deserialize(input_val18, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getBindingOperationMessagePolicy_free(input_val18, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getBindingOperationMessagePolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val18 =  axis2_skel_ServiceAdmin_getBindingOperationMessagePolicy(env, msg_ctx,input_val18);
                    
                        if ( NULL == ret_val18 )
                        {
                            adb_getBindingOperationMessagePolicy_free(input_val18, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getBindingOperationMessagePolicyResponse_serialize(ret_val18, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getBindingOperationMessagePolicyResponse_free(ret_val18, env);
                                   adb_getBindingOperationMessagePolicy_free(input_val18, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "changeServiceState") == 0 )
                {

                    
                    input_val19 = adb_changeServiceState_create( env);
                        if( AXIS2_FAILURE == adb_changeServiceState_deserialize(input_val19, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_changeServiceState_free(input_val19, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_changeServiceState_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val19 =  axis2_skel_ServiceAdmin_changeServiceState(env, msg_ctx,input_val19);
                    
                        if( AXIS2_FAILURE == ret_val19 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from changeServiceState ");
                        }
                        adb_changeServiceState_free(input_val19, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "setServiceParameters") == 0 )
                {

                    
                    input_val20 = adb_setServiceParameters_create( env);
                        if( AXIS2_FAILURE == adb_setServiceParameters_deserialize(input_val20, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setServiceParameters_free(input_val20, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setServiceParameters_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val20 =  axis2_skel_ServiceAdmin_setServiceParameters(env, msg_ctx,input_val20);
                    
                        if( AXIS2_FAILURE == ret_val20 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setServiceParameters ");
                        }
                        adb_setServiceParameters_free(input_val20, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getOperationMessagePolicy") == 0 )
                {

                    
                    input_val21 = adb_getOperationMessagePolicy_create( env);
                        if( AXIS2_FAILURE == adb_getOperationMessagePolicy_deserialize(input_val21, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationMessagePolicy_free(input_val21, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationMessagePolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val21 =  axis2_skel_ServiceAdmin_getOperationMessagePolicy(env, msg_ctx,input_val21);
                    
                        if ( NULL == ret_val21 )
                        {
                            adb_getOperationMessagePolicy_free(input_val21, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationMessagePolicyResponse_serialize(ret_val21, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationMessagePolicyResponse_free(ret_val21, env);
                                   adb_getOperationMessagePolicy_free(input_val21, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getNumberOfActiveServices") == 0 )
                {

                    
                        ret_val22 =  axis2_skel_ServiceAdmin_getNumberOfActiveServices(env, msg_ctx,
                                                (axis2_skel_ServiceAdmin_getNumberOfActiveServices_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val22 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getNumberOfActiveServicesResponse_serialize(ret_val22, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getNumberOfActiveServicesResponse_free(ret_val22, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServiceData") == 0 )
                {

                    
                    input_val23 = adb_getServiceData_create( env);
                        if( AXIS2_FAILURE == adb_getServiceData_deserialize(input_val23, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceData_free(input_val23, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceData_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val23 =  axis2_skel_ServiceAdmin_getServiceData(env, msg_ctx,input_val23);
                    
                        if ( NULL == ret_val23 )
                        {
                            adb_getServiceData_free(input_val23, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceDataResponse_serialize(ret_val23, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceDataResponse_free(ret_val23, env);
                                   adb_getServiceData_free(input_val23, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "removeTransportBinding") == 0 )
                {

                    
                    input_val24 = adb_removeTransportBinding_create( env);
                        if( AXIS2_FAILURE == adb_removeTransportBinding_deserialize(input_val24, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeTransportBinding_free(input_val24, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeTransportBinding_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val24 =  axis2_skel_ServiceAdmin_removeTransportBinding(env, msg_ctx,input_val24,
                                                (axis2_skel_ServiceAdmin_removeTransportBinding_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val24 )
                        {
                            adb_removeTransportBinding_free(input_val24, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_removeTransportBindingResponse_serialize(ret_val24, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_removeTransportBindingResponse_free(ret_val24, env);
                                   adb_removeTransportBinding_free(input_val24, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getPolicies") == 0 )
                {

                    
                    input_val25 = adb_getPolicies_create( env);
                        if( AXIS2_FAILURE == adb_getPolicies_deserialize(input_val25, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getPolicies_free(input_val25, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getPolicies_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val25 =  axis2_skel_ServiceAdmin_getPolicies(env, msg_ctx,input_val25);
                    
                        if ( NULL == ret_val25 )
                        {
                            adb_getPolicies_free(input_val25, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getPoliciesResponse_serialize(ret_val25, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getPoliciesResponse_free(ret_val25, env);
                                   adb_getPolicies_free(input_val25, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "removeServiceParameter") == 0 )
                {

                    
                    input_val26 = adb_removeServiceParameter_create( env);
                        if( AXIS2_FAILURE == adb_removeServiceParameter_deserialize(input_val26, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeServiceParameter_free(input_val26, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeServiceParameter_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val26 =  axis2_skel_ServiceAdmin_removeServiceParameter(env, msg_ctx,input_val26);
                    
                        if( AXIS2_FAILURE == ret_val26 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from removeServiceParameter ");
                        }
                        adb_removeServiceParameter_free(input_val26, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getBindingOperationPolicy") == 0 )
                {

                    
                    input_val27 = adb_getBindingOperationPolicy_create( env);
                        if( AXIS2_FAILURE == adb_getBindingOperationPolicy_deserialize(input_val27, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getBindingOperationPolicy_free(input_val27, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getBindingOperationPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val27 =  axis2_skel_ServiceAdmin_getBindingOperationPolicy(env, msg_ctx,input_val27);
                    
                        if ( NULL == ret_val27 )
                        {
                            adb_getBindingOperationPolicy_free(input_val27, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getBindingOperationPolicyResponse_serialize(ret_val27, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getBindingOperationPolicyResponse_free(ret_val27, env);
                                   adb_getBindingOperationPolicy_free(input_val27, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "deleteServiceGroups") == 0 )
                {

                    
                    input_val28 = adb_deleteServiceGroups_create( env);
                        if( AXIS2_FAILURE == adb_deleteServiceGroups_deserialize(input_val28, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_deleteServiceGroups_free(input_val28, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_deleteServiceGroups_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val28 =  axis2_skel_ServiceAdmin_deleteServiceGroups(env, msg_ctx,input_val28);
                    
                        if( AXIS2_FAILURE == ret_val28 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteServiceGroups ");
                        }
                        adb_deleteServiceGroups_free(input_val28, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getNumberOfInactiveServices") == 0 )
                {

                    
                        ret_val29 =  axis2_skel_ServiceAdmin_getNumberOfInactiveServices(env, msg_ctx,
                                                (axis2_skel_ServiceAdmin_getNumberOfInactiveServices_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val29 )
                        {
                            
                            return NULL; 
                        }
                        ret_node = adb_getNumberOfInactiveServicesResponse_serialize(ret_val29, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getNumberOfInactiveServicesResponse_free(ret_val29, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setServiceOperationPolicy") == 0 )
                {

                    
                    input_val30 = adb_setServiceOperationPolicy_create( env);
                        if( AXIS2_FAILURE == adb_setServiceOperationPolicy_deserialize(input_val30, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setServiceOperationPolicy_free(input_val30, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setServiceOperationPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val30 =  axis2_skel_ServiceAdmin_setServiceOperationPolicy(env, msg_ctx,input_val30,
                                                (axis2_skel_ServiceAdmin_setServiceOperationPolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val30 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setServiceOperationPolicy ");
                        }
                        adb_setServiceOperationPolicy_free(input_val30, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "deleteFaultyServiceGroup") == 0 )
                {

                    
                    input_val31 = adb_deleteFaultyServiceGroup_create( env);
                        if( AXIS2_FAILURE == adb_deleteFaultyServiceGroup_deserialize(input_val31, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_deleteFaultyServiceGroup_free(input_val31, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_deleteFaultyServiceGroup_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val31 =  axis2_skel_ServiceAdmin_deleteFaultyServiceGroup(env, msg_ctx,input_val31);
                    
                        if ( NULL == ret_val31 )
                        {
                            adb_deleteFaultyServiceGroup_free(input_val31, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_deleteFaultyServiceGroupResponse_serialize(ret_val31, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_deleteFaultyServiceGroupResponse_free(ret_val31, env);
                                   adb_deleteFaultyServiceGroup_free(input_val31, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "engageModuleToService") == 0 )
                {

                    
                    input_val32 = adb_engageModuleToService_create( env);
                        if( AXIS2_FAILURE == adb_engageModuleToService_deserialize(input_val32, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_engageModuleToService_free(input_val32, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_engageModuleToService_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val32 =  axis2_skel_ServiceAdmin_engageModuleToService(env, msg_ctx,input_val32,
                                                (axis2_skel_ServiceAdmin_engageModuleToService_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val32 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from engageModuleToService ");
                        }
                        adb_engageModuleToService_free(input_val32, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "deleteFaultyServiceGroups") == 0 )
                {

                    
                    input_val33 = adb_deleteFaultyServiceGroups_create( env);
                        if( AXIS2_FAILURE == adb_deleteFaultyServiceGroups_deserialize(input_val33, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_deleteFaultyServiceGroups_free(input_val33, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_deleteFaultyServiceGroups_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val33 =  axis2_skel_ServiceAdmin_deleteFaultyServiceGroups(env, msg_ctx,input_val33);
                    
                        if( AXIS2_FAILURE == ret_val33 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteFaultyServiceGroups ");
                        }
                        adb_deleteFaultyServiceGroups_free(input_val33, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "removeBindingPolicy") == 0 )
                {

                    
                    input_val34 = adb_removeBindingPolicy_create( env);
                        if( AXIS2_FAILURE == adb_removeBindingPolicy_deserialize(input_val34, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_removeBindingPolicy_free(input_val34, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_removeBindingPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val34 =  axis2_skel_ServiceAdmin_removeBindingPolicy(env, msg_ctx,input_val34,
                                                (axis2_skel_ServiceAdmin_removeBindingPolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val34 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from removeBindingPolicy ");
                        }
                        adb_removeBindingPolicy_free(input_val34, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "deleteAllFaultyServiceGroups") == 0 )
                {

                    
                        ret_val35 =  axis2_skel_ServiceAdmin_deleteAllFaultyServiceGroups(env, msg_ctx);
                    
                        if( AXIS2_FAILURE == ret_val35 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteAllFaultyServiceGroups ");
                        }
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "deleteAllNonAdminServiceGroups") == 0 )
                {

                    
                        ret_val36 =  axis2_skel_ServiceAdmin_deleteAllNonAdminServiceGroups(env, msg_ctx);
                    
                        if( AXIS2_FAILURE == ret_val36 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deleteAllNonAdminServiceGroups ");
                        }
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getModulePolicy") == 0 )
                {

                    
                    input_val37 = adb_getModulePolicy_create( env);
                        if( AXIS2_FAILURE == adb_getModulePolicy_deserialize(input_val37, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getModulePolicy_free(input_val37, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getModulePolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val37 =  axis2_skel_ServiceAdmin_getModulePolicy(env, msg_ctx,input_val37);
                    
                        if ( NULL == ret_val37 )
                        {
                            adb_getModulePolicy_free(input_val37, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getModulePolicyResponse_serialize(ret_val37, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getModulePolicyResponse_free(ret_val37, env);
                                   adb_getModulePolicy_free(input_val37, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setPolicy") == 0 )
                {

                    
                    input_val38 = adb_setPolicy_create( env);
                        if( AXIS2_FAILURE == adb_setPolicy_deserialize(input_val38, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setPolicy_free(input_val38, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val38 =  axis2_skel_ServiceAdmin_setPolicy(env, msg_ctx,input_val38,
                                                (axis2_skel_ServiceAdmin_setPolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val38 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setPolicy ");
                        }
                        adb_setPolicy_free(input_val38, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "listServiceGroups") == 0 )
                {

                    
                    input_val39 = adb_listServiceGroups_create( env);
                        if( AXIS2_FAILURE == adb_listServiceGroups_deserialize(input_val39, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_listServiceGroups_free(input_val39, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_listServiceGroups_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val39 =  axis2_skel_ServiceAdmin_listServiceGroups(env, msg_ctx,input_val39);
                    
                        if ( NULL == ret_val39 )
                        {
                            adb_listServiceGroups_free(input_val39, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_listServiceGroupsResponse_serialize(ret_val39, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_listServiceGroupsResponse_free(ret_val39, env);
                                   adb_listServiceGroups_free(input_val39, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "setServiceOperationMessagePolicy") == 0 )
                {

                    
                    input_val40 = adb_setServiceOperationMessagePolicy_create( env);
                        if( AXIS2_FAILURE == adb_setServiceOperationMessagePolicy_deserialize(input_val40, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_setServiceOperationMessagePolicy_free(input_val40, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_setServiceOperationMessagePolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val40 =  axis2_skel_ServiceAdmin_setServiceOperationMessagePolicy(env, msg_ctx,input_val40,
                                                (axis2_skel_ServiceAdmin_setServiceOperationMessagePolicy_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val40 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from setServiceOperationMessagePolicy ");
                        }
                        adb_setServiceOperationMessagePolicy_free(input_val40, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getBindingPolicy") == 0 )
                {

                    
                    input_val41 = adb_getBindingPolicy_create( env);
                        if( AXIS2_FAILURE == adb_getBindingPolicy_deserialize(input_val41, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getBindingPolicy_free(input_val41, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getBindingPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val41 =  axis2_skel_ServiceAdmin_getBindingPolicy(env, msg_ctx,input_val41);
                    
                        if ( NULL == ret_val41 )
                        {
                            adb_getBindingPolicy_free(input_val41, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getBindingPolicyResponse_serialize(ret_val41, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getBindingPolicyResponse_free(ret_val41, env);
                                   adb_getBindingPolicy_free(input_val41, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getServiceBindings") == 0 )
                {

                    
                    input_val42 = adb_getServiceBindings_create( env);
                        if( AXIS2_FAILURE == adb_getServiceBindings_deserialize(input_val42, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getServiceBindings_free(input_val42, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceBindings_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val42 =  axis2_skel_ServiceAdmin_getServiceBindings(env, msg_ctx,input_val42,
                                                (axis2_skel_ServiceAdmin_getServiceBindings_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val42 )
                        {
                            adb_getServiceBindings_free(input_val42, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getServiceBindingsResponse_serialize(ret_val42, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getServiceBindingsResponse_free(ret_val42, env);
                                   adb_getServiceBindings_free(input_val42, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "stopService") == 0 )
                {

                    
                    input_val43 = adb_stopService_create( env);
                        if( AXIS2_FAILURE == adb_stopService_deserialize(input_val43, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_stopService_free(input_val43, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_stopService_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val43 =  axis2_skel_ServiceAdmin_stopService(env, msg_ctx,input_val43,
                                                (axis2_skel_ServiceAdmin_stopService_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val43 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from stopService ");
                        }
                        adb_stopService_free(input_val43, env);
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "getOperationPolicy") == 0 )
                {

                    
                    input_val44 = adb_getOperationPolicy_create( env);
                        if( AXIS2_FAILURE == adb_getOperationPolicy_deserialize(input_val44, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getOperationPolicy_free(input_val44, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationPolicy_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val44 =  axis2_skel_ServiceAdmin_getOperationPolicy(env, msg_ctx,input_val44);
                    
                        if ( NULL == ret_val44 )
                        {
                            adb_getOperationPolicy_free(input_val44, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getOperationPolicyResponse_serialize(ret_val44, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getOperationPolicyResponse_free(ret_val44, env);
                                   adb_getOperationPolicy_free(input_val44, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_ServiceAdmin service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_ServiceAdmin_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_ServiceAdmin_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_ServiceAdmin_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_SERVICEADMIN_ERROR_NONE ||
                error_code >= AXIS2_SKEL_SERVICEADMIN_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "ServiceAdmin|http://mgt.service.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_STARTSERVICE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.startService_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.startService_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_ADDTRANSPORTBINDING_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.addTransportBinding_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addTransportBinding_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_SETSERVICEPOLICY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.setServicePolicy_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setServicePolicy_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_ADDPOLICIESTOSERVICE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.addPoliciesToService_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.addPoliciesToService_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_GETSERVICEPARAMETERS_FAULT_SERVEREXCEPTION)
                {
                    /* found which error code */
                    adb_ServerExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ServerExceptionE1_t*)svc_skeleton_wrapper->fault.getServiceParameters_fault.ServerException;
                    if(adb_obj)
                    {
                        error_node = adb_ServerExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ServerExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getServiceParameters_fault.ServerException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_SETBINDINGOPERATIONMESSAGEPOLICY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.setBindingOperationMessagePolicy_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setBindingOperationMessagePolicy_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_SETBINDINGPOLICY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.setBindingPolicy_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setBindingPolicy_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_REMOVESERVICEPOLICIESBYNAMESPACE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.removeServicePoliciesByNamespace_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.removeServicePoliciesByNamespace_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_SETBINDINGOPERATIONPOLICY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.setBindingOperationPolicy_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setBindingOperationPolicy_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_SETMODULEPOLICY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.setModulePolicy_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setModulePolicy_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_GETNUMBEROFACTIVESERVICES_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getNumberOfActiveServices_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getNumberOfActiveServices_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_REMOVETRANSPORTBINDING_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.removeTransportBinding_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.removeTransportBinding_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_GETNUMBEROFINACTIVESERVICES_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getNumberOfInactiveServices_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getNumberOfInactiveServices_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_SETSERVICEOPERATIONPOLICY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.setServiceOperationPolicy_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setServiceOperationPolicy_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_ENGAGEMODULETOSERVICE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.engageModuleToService_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.engageModuleToService_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_REMOVEBINDINGPOLICY_FAULT_SERVEREXCEPTION)
                {
                    /* found which error code */
                    adb_ServerExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ServerExceptionE1_t*)svc_skeleton_wrapper->fault.removeBindingPolicy_fault.ServerException;
                    if(adb_obj)
                    {
                        error_node = adb_ServerExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ServerExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.removeBindingPolicy_fault.ServerException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_SETPOLICY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.setPolicy_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setPolicy_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_SETSERVICEOPERATIONMESSAGEPOLICY_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.setServiceOperationMessagePolicy_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.setServiceOperationMessagePolicy_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_GETSERVICEBINDINGS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getServiceBindings_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getServiceBindings_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_SERVICEADMIN_STOPSERVICE_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.stopService_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.stopService_fault.Exception = NULL;
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
		*inst = axis2_svc_skel_ServiceAdmin_create(env);

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


    

