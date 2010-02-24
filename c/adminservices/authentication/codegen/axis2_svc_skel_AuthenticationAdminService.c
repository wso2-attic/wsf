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
         * axis2_svc_skel_AuthenticationAdminService.c
         *
         * This file was auto-generated from WSDL for "AuthenticationAdminService|http://authentication.services.core.carbon.wso2.org" service
         * by the Apache Axis2 version: SNAPSHOT  Built on : Jan 19, 2010 (01:46:42 IST)
         *  axis2_svc_skel_AuthenticationAdminService
         */

        #include "axis2_skel_AuthenticationAdminService.h"
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
                axis2_skel_AuthenticationAdminService_logout_fault logout_fault;
                    axis2_skel_AuthenticationAdminService_login_fault login_fault;
                    axis2_skel_AuthenticationAdminService_getSystemPermissionOfUser_fault getSystemPermissionOfUser_fault;
                    axis2_skel_AuthenticationAdminService_loginWithDelegation_fault loginWithDelegation_fault;
                    axis2_skel_AuthenticationAdminService_getUserPermissions_fault getUserPermissions_fault;
                    
            } fault;
          
        }axis2_svc_skel_AuthenticationAdminService_t;
       
        /**
         * functions prototypes
         */
        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_AuthenticationAdminService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_AuthenticationAdminService_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_AuthenticationAdminService_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_AuthenticationAdminService_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_AuthenticationAdminService_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_AuthenticationAdminService_svc_skeleton_ops_var = {
            axis2_svc_skel_AuthenticationAdminService_init,
            axis2_svc_skel_AuthenticationAdminService_invoke,
            axis2_svc_skel_AuthenticationAdminService_on_fault,
            axis2_svc_skel_AuthenticationAdminService_free
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
	axis2_svc_skel_AuthenticationAdminService_create(const axutil_env_t *env)
	{
	    axis2_svc_skel_AuthenticationAdminService_t *svc_skeleton_wrapper = NULL;
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        
        /* Allocate memory for the structs */
        svc_skeleton_wrapper = (axis2_svc_skel_AuthenticationAdminService_t *)AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skel_AuthenticationAdminService_t));

        svc_skeleton = (axis2_svc_skeleton_t*)svc_skeleton_wrapper;

        svc_skeleton->ops = &axis2_svc_skel_AuthenticationAdminService_svc_skeleton_ops_var;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_AuthenticationAdminService_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /* Nothing special in initialization  axis2_skel_AuthenticationAdminService */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_AuthenticationAdminService_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_AuthenticationAdminService_invoke(axis2_svc_skeleton_t *svc_skeleton,
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
	    
          axis2_svc_skel_AuthenticationAdminService_t *svc_skeleton_wrapper = NULL;

          
            axis2_status_t ret_val1;
            
            adb_loginResponse_t* ret_val2;
            adb_login_t* input_val2;
            
            adb_getSystemPermissionOfUserResponse_t* ret_val3;
            adb_getSystemPermissionOfUser_t* input_val3;
            
            adb_loginWithDelegationResponse_t* ret_val4;
            adb_loginWithDelegation_t* input_val4;
            
            adb_getUserPermissionsResponse_t* ret_val5;
            adb_getUserPermissions_t* input_val5;
            

          svc_skeleton_wrapper = (axis2_svc_skel_AuthenticationAdminService_t*)svc_skeleton;
          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
               

                if ( axutil_strcmp(op_name, "logout") == 0 )
                {

                    
                        ret_val1 =  axis2_skel_AuthenticationAdminService_logout(env, msg_ctx,
                                                (axis2_skel_AuthenticationAdminService_logout_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if( AXIS2_FAILURE == ret_val1 )
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from logout ");
                        }
                        

                    /* since this has no output params it just returns NULL */                    
                    return NULL;

                }
             

                if ( axutil_strcmp(op_name, "login") == 0 )
                {

                    
                    input_val2 = adb_login_create( env);
                        if( AXIS2_FAILURE == adb_login_deserialize(input_val2, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_login_free(input_val2, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_login_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val2 =  axis2_skel_AuthenticationAdminService_login(env, msg_ctx,input_val2,
                                                (axis2_skel_AuthenticationAdminService_login_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val2 )
                        {
                            adb_login_free(input_val2, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_loginResponse_serialize(ret_val2, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_loginResponse_free(ret_val2, env);
                                   adb_login_free(input_val2, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSystemPermissionOfUser") == 0 )
                {

                    
                    input_val3 = adb_getSystemPermissionOfUser_create( env);
                        if( AXIS2_FAILURE == adb_getSystemPermissionOfUser_deserialize(input_val3, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getSystemPermissionOfUser_free(input_val3, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getSystemPermissionOfUser_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val3 =  axis2_skel_AuthenticationAdminService_getSystemPermissionOfUser(env, msg_ctx,input_val3,
                                                (axis2_skel_AuthenticationAdminService_getSystemPermissionOfUser_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val3 )
                        {
                            adb_getSystemPermissionOfUser_free(input_val3, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getSystemPermissionOfUserResponse_serialize(ret_val3, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getSystemPermissionOfUserResponse_free(ret_val3, env);
                                   adb_getSystemPermissionOfUser_free(input_val3, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "loginWithDelegation") == 0 )
                {

                    
                    input_val4 = adb_loginWithDelegation_create( env);
                        if( AXIS2_FAILURE == adb_loginWithDelegation_deserialize(input_val4, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_loginWithDelegation_free(input_val4, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_loginWithDelegation_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val4 =  axis2_skel_AuthenticationAdminService_loginWithDelegation(env, msg_ctx,input_val4,
                                                (axis2_skel_AuthenticationAdminService_loginWithDelegation_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val4 )
                        {
                            adb_loginWithDelegation_free(input_val4, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_loginWithDelegationResponse_serialize(ret_val4, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_loginWithDelegationResponse_free(ret_val4, env);
                                   adb_loginWithDelegation_free(input_val4, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getUserPermissions") == 0 )
                {

                    
                    input_val5 = adb_getUserPermissions_create( env);
                        if( AXIS2_FAILURE == adb_getUserPermissions_deserialize(input_val5, env, &content_node, NULL, AXIS2_FALSE))
                        {
                            adb_getUserPermissions_free(input_val5, env);
                      
                            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_DATA_ELEMENT_IS_NULL, AXIS2_FAILURE);
                            AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getUserPermissions_deserialize: "
                                        "This should be due to an invalid XML");
                            return NULL;      
                        }
                        
                        ret_val5 =  axis2_skel_AuthenticationAdminService_getUserPermissions(env, msg_ctx,input_val5,
                                                (axis2_skel_AuthenticationAdminService_getUserPermissions_fault*)&(svc_skeleton_wrapper->fault));
                    
                        if ( NULL == ret_val5 )
                        {
                            adb_getUserPermissions_free(input_val5, env);
                            
                            return NULL; 
                        }
                        ret_node = adb_getUserPermissionsResponse_serialize(ret_val5, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                                   adb_getUserPermissionsResponse_free(ret_val5, env);
                                   adb_getUserPermissions_free(input_val5, env);
                                   

                        return ret_node;
                    

                    /* since this has no output params it just returns NULL */                    
                    

                }
             
             }
            
          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "axis2_svc_skel_AuthenticationAdminService service ERROR: invalid OM parameters in request\n");
          return NULL;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_AuthenticationAdminService_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
        axutil_error_codes_t error_code;
        axis2_svc_skel_AuthenticationAdminService_t *svc_skeleton_wrapper = NULL;

        svc_skeleton_wrapper = (axis2_svc_skel_AuthenticationAdminService_t*)svc_skeleton;

        error_code = env->error->error_number;

        if(error_code <= AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_ERROR_NONE ||
                error_code >= AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_ERROR_LAST )
        {
            error_ele = axiom_element_create(env, node, "fault", NULL,
                            &error_node);
            axiom_element_set_text(error_ele, env, "AuthenticationAdminService|http://authentication.services.core.carbon.wso2.org failed",
                            error_node);
        }
        

                else if(error_code == AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_LOGOUT_FAULT_AUTHENTICATIONEXCEPTION)
                {
                    /* found which error code */
                    adb_AuthenticationExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_AuthenticationExceptionE1_t*)svc_skeleton_wrapper->fault.logout_fault.AuthenticationException;
                    if(adb_obj)
                    {
                        error_node = adb_AuthenticationExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_AuthenticationExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.logout_fault.AuthenticationException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_LOGIN_FAULT_AUTHENTICATIONEXCEPTION)
                {
                    /* found which error code */
                    adb_AuthenticationExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_AuthenticationExceptionE1_t*)svc_skeleton_wrapper->fault.login_fault.AuthenticationException;
                    if(adb_obj)
                    {
                        error_node = adb_AuthenticationExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_AuthenticationExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.login_fault.AuthenticationException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_GETSYSTEMPERMISSIONOFUSER_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getSystemPermissionOfUser_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getSystemPermissionOfUser_fault.Exception = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_LOGINWITHDELEGATION_FAULT_AUTHENTICATIONEXCEPTION)
                {
                    /* found which error code */
                    adb_AuthenticationExceptionE1_t* adb_obj = NULL;
                   
                    adb_obj = (adb_AuthenticationExceptionE1_t*)svc_skeleton_wrapper->fault.loginWithDelegation_fault.AuthenticationException;
                    if(adb_obj)
                    {
                        error_node = adb_AuthenticationExceptionE1_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_AuthenticationExceptionE1_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.loginWithDelegation_fault.AuthenticationException = NULL;
                    }

                }
            

                else if(error_code == AXIS2_SKEL_AUTHENTICATIONADMINSERVICE_GETUSERPERMISSIONS_FAULT_EXCEPTION)
                {
                    /* found which error code */
                    adb_ExceptionE0_t* adb_obj = NULL;
                   
                    adb_obj = (adb_ExceptionE0_t*)svc_skeleton_wrapper->fault.getUserPermissions_fault.Exception;
                    if(adb_obj)
                    {
                        error_node = adb_ExceptionE0_serialize(adb_obj, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
                        adb_ExceptionE0_free(adb_obj, env);
                        svc_skeleton_wrapper->fault.getUserPermissions_fault.Exception = NULL;
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
		*inst = axis2_svc_skel_AuthenticationAdminService_create(env);

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


    

