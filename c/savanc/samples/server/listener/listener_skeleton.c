/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>
#include <axis2_svc_skeleton.h>
#include <axutil_array_list.h>
#include <axiom_element.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_header.h>
#include <axiom_soap_body.h>
#include <axiom_soap_fault.h>
#include <axis2_engine.h>
#include <axis2_conf_ctx.h>
#include <axis2_conf_init.h>
#include <axutil_thread_pool.h>
#include <axis2_util.h>
#include <axis2_svc_client.h>
#include <axis2_options.h>

#include "listener.h"

int AXIS2_CALL
listener_free(axis2_svc_skeleton_t *svc_skeleton,
            const axutil_env_t *env);

axis2_status_t AXIS2_CALL
listener_free_void_arg(void *svc_skeleton,
                    const axutil_env_t *env);

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL 
listener_invoke(axis2_svc_skeleton_t *svc_skeleton,
            const axutil_env_t *env,
            axiom_node_t *node,
            axis2_msg_ctx_t *msg_ctx);
            

int AXIS2_CALL 
listener_init(axis2_svc_skeleton_t *svc_skeleton,
          const axutil_env_t *env);

axiom_node_t* AXIS2_CALL
listener_on_fault(axis2_svc_skeleton_t *svc_skeli, 
              const axutil_env_t *env, axiom_node_t *node);

static const axis2_svc_skeleton_ops_t listener_skeleton_ops_var = {
    listener_init,
    listener_invoke,
    listener_on_fault,
    listener_free
};

/*Create function */
axis2_svc_skeleton_t *
axis2_listener_create(const axutil_env_t *env)
{

    axis2_svc_skeleton_t *svc_skeleton = NULL;

	
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "listener service create called");

	/* Allocate memory for the structs */
    svc_skeleton = AXIS2_MALLOC(env->allocator, sizeof(axis2_svc_skeleton_t));

    svc_skeleton->ops = &listener_skeleton_ops_var;
    svc_skeleton->func_array = NULL;

    /* Assign function pointers */
    
    return svc_skeleton;
}

/* Initialize the service */
int AXIS2_CALL
listener_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env)
{
    svc_skeleton->func_array = axutil_array_list_create(env, 0);

    /* Add the implemented operation names of the service to  
     * the array list of functions 
     */
    axutil_array_list_add(svc_skeleton->func_array, env, "notify");

    /* Any initialization stuff of service should go here */

    return AXIS2_SUCCESS;
}

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL
listener_invoke(axis2_svc_skeleton_t *svc_skeleton,
            const axutil_env_t *env,
            axiom_node_t *node,
            axis2_msg_ctx_t *msg_ctx)
{
    /* Invoke the business logic.
     * Depending on the function name invoke the correct impl method.
     */

    return axis2_listener_notify(env, node);
}

/* On fault, handle the fault */
axiom_node_t* AXIS2_CALL
listener_on_fault(axis2_svc_skeleton_t *svc_skeli, 
              const axutil_env_t *env, axiom_node_t *node)
{
   /* Here we are just setting a simple error message inside an element 
    * called 'EchoServiceError' 
    */
    axiom_node_t *error_node = NULL;
    axiom_node_t* text_node = NULL;
    axiom_element_t *error_ele = NULL;
    error_ele = axiom_element_create(env, node, "TestServiceError", NULL, 
        &error_node);
    axiom_element_set_text(error_ele, env, "Test service failed ", 
        text_node);
    return error_node;
}

/* Free the resources used */
int AXIS2_CALL
listener_free(axis2_svc_skeleton_t *svc_skeleton,
            const axutil_env_t *env)
{
    /* Free the function array */
    if(svc_skeleton->func_array)
    {
        axutil_array_list_free(svc_skeleton->func_array, env);
    }
    
    /* Free the service skeleton */
    if(svc_skeleton)
    {
        AXIS2_FREE(env->allocator, svc_skeleton);
    }

    return AXIS2_SUCCESS; 
}

/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int 
axis2_get_instance(axis2_svc_skeleton_t **inst,
                   const axutil_env_t *env)
{
   *inst = axis2_listener_create(env);
    if(!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int 
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
