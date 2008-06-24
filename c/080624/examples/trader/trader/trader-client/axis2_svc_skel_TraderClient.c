

        /**
         * axis2_svc_skel_TraderClient.c
         *
         * This file was auto-generated from WSDL for "TraderClient|http://www.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_TraderClient
         */

        #include "axis2_skel_TraderClient.h"
        #include <axis2_svc_skeleton.h>
        #include <axutil_array_list.h>
        #include <stdio.h>

        /**
         * functions prototypes
         */

        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_TraderClient_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_TraderClient_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_TraderClient_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_TraderClient_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_TraderClient_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_TraderClient_svc_skeleton_ops_var = {
            axis2_svc_skel_TraderClient_init,
            axis2_svc_skel_TraderClient_invoke,
            axis2_svc_skel_TraderClient_on_fault,
            axis2_svc_skel_TraderClient_free
        };


        /**
         * Implementations for the functions
         */

	axis2_svc_skeleton_t* AXIS2_CALL
	axis2_svc_skel_TraderClient_create(const axutil_env_t *env)
	{
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        /* Allocate memory for the structs */
        svc_skeleton = AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skeleton_t));

        svc_skeleton->ops = &axis2_svc_skel_TraderClient_svc_skeleton_ops_var;

	    svc_skeleton->func_array = NULL;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_TraderClient_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    /*svc_skeleton->func_array = axutil_array_list_create(env, 10);
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "buy");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "getPortfolio");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "deposit");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "getSymbols");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "getQuote");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "createAccount");
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "sell");
        */
        axis2_skel_TraderClient_init(env);

	    /* Any initialization stuff of axis2_skel_TraderClient goes here */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_TraderClient_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_TraderClient_invoke(axis2_svc_skeleton_t *svc_skeleton,
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

          
            axis2_buyResponse_t* ret_val1 = NULL;
            axis2_buyRequest_t* input_val1_1;
            
            axis2_getPortfolioResponse_t* ret_val2 = NULL;
            axis2_getPortfolioRequest_t* input_val2_1;
            
            axis2_depositResponse_t* ret_val3 = NULL;
            axis2_depositRequest_t* input_val3_1;
            
            axis2_getSymbolsResponse_t* ret_val4 = NULL;
            axis2_getSymbolsRequest_t* input_val4_1;
            
            axis2_getQuoteResponse_t* ret_val5 = NULL;
            axis2_getQuoteRequest_t* input_val5_1;
            
            axis2_createAccountResponse_t* ret_val6 = NULL;
            axis2_createAccountRequest_t* input_val6_1;
            
            axis2_sellResponse_t* ret_val7 = NULL;
            axis2_sellRequest_t* input_val7_1;
            

          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
            

                if ( axutil_strcmp(op_name, "buy") == 0 )
                {
                    
                    input_val1_1 = 
                        axis2_buyRequest_create( env);
                        axis2_buyRequest_deserialize(input_val1_1, env, content_node );
                        
                    ret_val1 =  axis2_skel_TraderClient_buy(env,
                                                input_val1_1 );
                    if ( NULL == ret_val1 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from buy "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_TraderClient_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_buyResponse_serialize(ret_val1, env, NULL, AXIS2_FALSE);
                               axis2_buyResponse_free(ret_val1, env);
                               axis2_buyRequest_free(input_val1_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getPortfolio") == 0 )
                {
                    
                    input_val2_1 = 
                        axis2_getPortfolioRequest_create( env);
                        axis2_getPortfolioRequest_deserialize(input_val2_1, env, content_node );
                        
                    ret_val2 =  axis2_skel_TraderClient_getPortfolio(env,
                                                input_val2_1 );
                    if ( NULL == ret_val2 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from getPortfolio "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_TraderClient_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_getPortfolioResponse_serialize(ret_val2, env, NULL, AXIS2_FALSE);
                               axis2_getPortfolioResponse_free(ret_val2, env);
                               axis2_getPortfolioRequest_free(input_val2_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "deposit") == 0 )
                {
                    
                    input_val3_1 = 
                        axis2_depositRequest_create( env);
                        axis2_depositRequest_deserialize(input_val3_1, env, content_node );
                        
                    ret_val3 =  axis2_skel_TraderClient_deposit(env,
                                                input_val3_1 );
                    if ( NULL == ret_val3 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from deposit "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_TraderClient_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_depositResponse_serialize(ret_val3, env, NULL, AXIS2_FALSE);
                               axis2_depositResponse_free(ret_val3, env);
                               axis2_depositRequest_free(input_val3_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getSymbols") == 0 )
                {
                    
                    input_val4_1 = 
                        axis2_getSymbolsRequest_create( env);
                        axis2_getSymbolsRequest_deserialize(input_val4_1, env, content_node );
                        
                    ret_val4 =  axis2_skel_TraderClient_getSymbols(env,
                                                input_val4_1 );
                    if ( NULL == ret_val4 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from getSymbols "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_TraderClient_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_getSymbolsResponse_serialize(ret_val4, env, NULL, AXIS2_FALSE);
                               axis2_getSymbolsResponse_free(ret_val4, env);
                               axis2_getSymbolsRequest_free(input_val4_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "getQuote") == 0 )
                {
                    
                    input_val5_1 = 
                        axis2_getQuoteRequest_create( env);
                        axis2_getQuoteRequest_deserialize(input_val5_1, env, content_node );
                        
                    ret_val5 =  axis2_skel_TraderClient_getQuote(env,
                                                input_val5_1 );
                    if ( NULL == ret_val5 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from getQuote "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_TraderClient_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_getQuoteResponse_serialize(ret_val5, env, NULL, AXIS2_FALSE);
                               axis2_getQuoteResponse_free(ret_val5, env);
                               axis2_getQuoteRequest_free(input_val5_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "createAccount") == 0 )
                {
                    
                    input_val6_1 = 
                        axis2_createAccountRequest_create( env);
                        axis2_createAccountRequest_deserialize(input_val6_1, env, content_node );
                        
                    ret_val6 =  axis2_skel_TraderClient_createAccount(env,
                                                input_val6_1 );
                    if ( NULL == ret_val6 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from createAccount "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_TraderClient_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_createAccountResponse_serialize(ret_val6, env, NULL, AXIS2_FALSE);
                               axis2_createAccountResponse_free(ret_val6, env);
                               axis2_createAccountRequest_free(input_val6_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             

                if ( axutil_strcmp(op_name, "sell") == 0 )
                {
                    
                    input_val7_1 = 
                        axis2_sellRequest_create( env);
                        axis2_sellRequest_deserialize(input_val7_1, env, content_node );
                        
                    ret_val7 =  axis2_skel_TraderClient_sell(env,
                                                input_val7_1 );
                    if ( NULL == ret_val7 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from sell "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_TraderClient_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_sellResponse_serialize(ret_val7, env, NULL, AXIS2_FALSE);
                               axis2_sellResponse_free(ret_val7, env);
                               axis2_sellRequest_free(input_val7_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             
             }
          printf("axis2_svc_skel_TraderClient service ERROR: invalid OM parameters in request\n");
          return content_node;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_TraderClient_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
		error_ele = axiom_element_create(env, node, "fault", NULL,
    					&error_node);
		axiom_element_set_text(error_ele, env, "TraderClient|http://www.wso2.org failed",
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
		*inst = axis2_svc_skel_TraderClient_create(env);

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


    

