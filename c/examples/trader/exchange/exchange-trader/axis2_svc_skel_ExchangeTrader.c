

        /**
         * axis2_svc_skel_ExchangeTrader.c
         *
         * This file was auto-generated from WSDL for "ExchangeTrader|http://www.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_ExchangeTrader
         */

        #include "axis2_skel_ExchangeTrader.h"
        #include <axis2_svc_skeleton.h>
        #include <axutil_array_list.h>
        #include <stdio.h>

        /**
         * functions prototypes
         */

        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ExchangeTrader_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_ExchangeTrader_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ExchangeTrader_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_ExchangeTrader_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_ExchangeTrader_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_ExchangeTrader_svc_skeleton_ops_var = {
            axis2_svc_skel_ExchangeTrader_init,
            axis2_svc_skel_ExchangeTrader_invoke,
            axis2_svc_skel_ExchangeTrader_on_fault,
            axis2_svc_skel_ExchangeTrader_free
        };


        /**
         * Implementations for the functions
         */

	axis2_svc_skeleton_t* AXIS2_CALL
	axis2_svc_skel_ExchangeTrader_create(const axutil_env_t *env)
	{
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        /* Allocate memory for the structs */
        svc_skeleton = AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skeleton_t));

        svc_skeleton->ops = &axis2_svc_skel_ExchangeTrader_svc_skeleton_ops_var;

	    svc_skeleton->func_array = NULL;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_ExchangeTrader_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /*svc_skeleton->func_array = axutil_array_list_create(env, 10);
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "buy");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "login");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "registerClient");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "registerFeedTarget");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "sell");
        */
          axis2_skel_ExchangeTrader_init(env);
          

	    /* Any initialization stuff of axis2_skel_ExchangeTrader goes here */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_ExchangeTrader_free(axis2_svc_skeleton_t *svc_skeleton,
				 const axutil_env_t *env)
	{
        /* Free the function array */
        if (svc_skeleton->func_array)
        {
            axutil_array_list_free(svc_skeleton->func_array, env);
            svc_skeleton->func_array = NULL;
        }

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
	axis2_svc_skel_ExchangeTrader_invoke(axis2_svc_skeleton_t *svc_skeleton,
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

          axiom_node_t *ret_node = NULL;

          
            axis2_status_t ret_val1 = AXIS2_SUCCESS;
            axis2_buyRequest_ex_t* input_val1_1;
            
            axis2_status_t ret_val2 = AXIS2_SUCCESS;
            axis2_loginRequest_t* input_val2_1;
            
            axis2_registerClientResponse_t* ret_val3 = NULL;
            axis2_registerClientRequest_t* input_val3_1;
            
            axis2_status_t ret_val4 = AXIS2_SUCCESS;
            axis2_registerFeedTargetRequest_t* input_val4_1;
            
            axis2_status_t ret_val5 = AXIS2_SUCCESS;
            axis2_sellRequest_ex_t* input_val5_1;
            

          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
            

                if ( axutil_strcmp(op_name, "buy") == 0 )
                {
                    
                    input_val1_1 = 
                        axis2_buyRequest_ex_create( env);
                        axis2_buyRequest_ex_deserialize(input_val1_1, env, content_node );
                        
                    ret_val1 =  axis2_skel_ExchangeTrader_buy(env,
                                                input_val1_1 );
                    if ( AXIS2_FAILURE == ret_val1 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from buy "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_ExchangeTrader_on_fault( svc_skeleton, env, NULL);
                    }
                    /*ret_node = 
                               axis2__serialize(ret_val1, env, NULL, AXIS2_FALSE);
                               axis2__free(ret_val1, env);
                               axis2_buyRequest_ex_free(input_val1_1, env);
                    */               
                    return NULL;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "login") == 0 )
                {
                    
                    input_val2_1 = 
                        axis2_loginRequest_create( env);
                        axis2_loginRequest_deserialize(input_val2_1, env, content_node );
                        
                    ret_val2 =  axis2_skel_ExchangeTrader_login(env,
                                                input_val2_1 );
                    if ( AXIS2_FAILURE == ret_val2 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from login "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_ExchangeTrader_on_fault( svc_skeleton, env, NULL);
                    }
                    /*ret_node = 
                               axis2__serialize(ret_val2, env, NULL, AXIS2_FALSE);
                               axis2__free(ret_val2, env);
                               axis2_loginRequest_free(input_val2_1, env);
                    */               
                    return NULL;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "registerClient") == 0 )
                {
                    
                    input_val3_1 = 
                        axis2_registerClientRequest_create( env);
                        axis2_registerClientRequest_deserialize(input_val3_1, env, content_node );
                        
                    ret_val3 =  axis2_skel_ExchangeTrader_registerClient(env,
                                                input_val3_1 );
                    if ( NULL == ret_val3 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from registerClient "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_ExchangeTrader_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_registerClientResponse_serialize(ret_val3, env, NULL, AXIS2_FALSE);
                               axis2_registerClientResponse_free(ret_val3, env);
                               axis2_registerClientRequest_free(input_val3_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "registerFeedTarget") == 0 )
                {
                    
                    input_val4_1 = 
                        axis2_registerFeedTargetRequest_create( env);
                        axis2_registerFeedTargetRequest_deserialize(input_val4_1, env, content_node );
                        
                    ret_val4 =  axis2_skel_ExchangeTrader_registerFeedTarget(env,
                                                input_val4_1 );
                    if ( AXIS2_FAILURE == ret_val4 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from registerFeedTarget "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_ExchangeTrader_on_fault( svc_skeleton, env, NULL);
                    }
                    /*ret_node = 
                               axis2__serialize(ret_val4, env, NULL, AXIS2_FALSE);
                               axis2__free(ret_val4, env);
                               axis2_registerFeedTargetRequest_free(input_val4_1, env);
                    */               
                    return NULL;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "sell") == 0 )
                {
                    
                    input_val5_1 = 
                        axis2_sellRequest_ex_create( env);
                        axis2_sellRequest_ex_deserialize(input_val5_1, env, content_node );
                        
                    ret_val5 =  axis2_skel_ExchangeTrader_sell(env,
                                                input_val5_1 );
                    if ( AXIS2_FAILURE == ret_val5 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from sell "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_ExchangeTrader_on_fault( svc_skeleton, env, NULL);
                    }
                    /*ret_node = 
                               axis2__serialize(ret_val5, env, NULL, AXIS2_FALSE);
                               axis2__free(ret_val5, env);
                               axis2_sellRequest_ex_free(input_val5_1, env);
                    */               
                    return NULL;
                    

                    
                    

                }
             
             }
          printf("axis2_svc_skel_ExchangeTrader service ERROR: invalid OM parameters in request\n");
          return content_node;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_ExchangeTrader_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
		error_ele = axiom_element_create(env, node, "fault", NULL,
    					&error_node);
		axiom_element_set_text(error_ele, env, "ExchangeTrader|http://www.wso2.org failed",
    					error_node);
		return error_node;
	}


	/**
	 * Following block distinguish the exposed part of the dll.
 	 */

    AXIS2_EXTERN int
    axis2_get_instance(struct axis2_svc_skeleton **inst,
	                        const axutil_env_t *env)
	{
		*inst = axis2_svc_skel_ExchangeTrader_create(env);

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


    

