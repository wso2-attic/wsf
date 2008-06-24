

        /**
         * axis2_svc_skel_ExchangeClient.c
         *
         * This file was auto-generated from WSDL for "ExchangeClient|http://www.wso2.org" service
         * by the Apache Axis2 version: #axisVersion# #today#
         *  axis2_svc_skel_ExchangeClient
         */

        #include "axis2_skel_ExchangeClient.h"
        #include <axis2_svc_skeleton.h>
        #include <axutil_array_list.h>
        #include <stdio.h>

        /**
         * functions prototypes
         */

        /* On fault, handle the fault */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ExchangeClient_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node);

        /* Free the service */
        int AXIS2_CALL
        axis2_svc_skel_ExchangeClient_free(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env);

        /* This method invokes the right service method */
        axiom_node_t* AXIS2_CALL
        axis2_svc_skel_ExchangeClient_invoke(axis2_svc_skeleton_t *svc_skeleton,
                    const axutil_env_t *env,
                    axiom_node_t *node,
                    axis2_msg_ctx_t *msg_ctx);

        /* Initializing the environment  */
        int AXIS2_CALL
        axis2_svc_skel_ExchangeClient_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env);

        /* Create the service  */
        axis2_svc_skeleton_t* AXIS2_CALL
        axis2_svc_skel_ExchangeClient_create(const axutil_env_t *env);

        static const axis2_svc_skeleton_ops_t axis2_svc_skel_ExchangeClient_svc_skeleton_ops_var = {
            axis2_svc_skel_ExchangeClient_init,
            axis2_svc_skel_ExchangeClient_invoke,
            axis2_svc_skel_ExchangeClient_on_fault,
            axis2_svc_skel_ExchangeClient_free
        };


        /**
         * Implementations for the functions
         */

	axis2_svc_skeleton_t* AXIS2_CALL
	axis2_svc_skel_ExchangeClient_create(const axutil_env_t *env)
	{
	    axis2_svc_skeleton_t *svc_skeleton = NULL;
        /* Allocate memory for the structs */
        svc_skeleton = AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skeleton_t));

        svc_skeleton->ops = &axis2_svc_skel_ExchangeClient_svc_skeleton_ops_var;

	    svc_skeleton->func_array = NULL;

	    return svc_skeleton;
	}


	int AXIS2_CALL
	axis2_svc_skel_ExchangeClient_init(axis2_svc_skeleton_t *svc_skeleton,
	                        const axutil_env_t *env)
	{
	    svc_skeleton->func_array = axutil_array_list_create(env, 10);
        
	      axutil_array_list_add(svc_skeleton->func_array, env, "getInfo");
        

	    /* Any initialization stuff of axis2_skel_ExchangeClient goes here */
	    return AXIS2_SUCCESS;
	}

	int AXIS2_CALL
	axis2_svc_skel_ExchangeClient_free(axis2_svc_skeleton_t *svc_skeleton,
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
	axis2_svc_skel_ExchangeClient_invoke(axis2_svc_skeleton_t *svc_skeleton,
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

          
            axis2_getInfoResponse_t* ret_val1 = NULL;
            axis2_getInfoRequest_t* input_val1_1;
            

          operation_ctx = axis2_msg_ctx_get_op_ctx(msg_ctx, env);
          operation = axis2_op_ctx_get_op(operation_ctx, env);
          op_qname = (axutil_qname_t *)axis2_op_get_qname(operation, env);
          op_name = axutil_qname_get_localpart(op_qname, env);

          if (op_name)
          {
            

                if ( axutil_strcmp(op_name, "getInfo") == 0 )
                {
                    
                    input_val1_1 = 
                        axis2_getInfoRequest_create( env);
                        axis2_getInfoRequest_deserialize(input_val1_1, env, content_node );
                        
                    ret_val1 =  axis2_skel_ExchangeClient_getInfo(env,
                                                input_val1_1 );
                    if ( NULL == ret_val1 )
                    {
                        AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the business logic from getInfo "
                                        " %d :: %s", env->error->error_number,
                                        AXIS2_ERROR_GET_MESSAGE(env->error));
                        return axis2_svc_skel_ExchangeClient_on_fault( svc_skeleton, env, NULL);
                    }
                    ret_node = 
                               axis2_getInfoResponse_serialize(ret_val1, env, NULL, AXIS2_FALSE);
                               axis2_getInfoResponse_free(ret_val1, env);
                               axis2_getInfoRequest_free(input_val1_1, env);
                                   
                    return ret_node;
                    

                    
                    

                }
             
             }
          printf("axis2_svc_skel_ExchangeClient service ERROR: invalid OM parameters in request\n");
          return content_node;
    }

    axiom_node_t* AXIS2_CALL
    axis2_svc_skel_ExchangeClient_on_fault(axis2_svc_skeleton_t *svc_skeleton,
                  const axutil_env_t *env, axiom_node_t *node)
	{
		axiom_node_t *error_node = NULL;
		axiom_element_t *error_ele = NULL;
		error_ele = axiom_element_create(env, node, "fault", NULL,
    					&error_node);
		axiom_element_set_text(error_ele, env, "ExchangeClient|http://www.wso2.org failed",
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
		*inst = axis2_svc_skel_ExchangeClient_create(env);

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


    

