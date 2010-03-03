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
#include <axis2_util.h>
#include <axis2_conf.h>
#include <axis2_svc_skeleton.h>
#include <axiom_element.h>

#include "statistics_svc.h"

#define WEATHER_STATUS "statistics_svc_status"
#define WEATHER "statistics_svc"

typedef struct statistics_svc_data
{
    axutil_env_t *env;
    axis2_conf_t *conf;
}statistics_svc_data_t;

int AXIS2_CALL
statistics_svc_free(axis2_svc_skeleton_t *svc_skeleton,
            const axutil_env_t *env);

axis2_status_t AXIS2_CALL
statistics_svc_free_void_arg(void *svc_skeleton,
                    const axutil_env_t *env);

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL 
statistics_svc_invoke(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx);
        

int AXIS2_CALL 
statistics_svc_init(
        axis2_svc_skeleton_t *svc_skeleton,
        const axutil_env_t *env);

int AXIS2_CALL 
statistics_svc_init_with_conf(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axis2_conf_t *conf);

axiom_node_t* AXIS2_CALL
statistics_svc_on_fault(axis2_svc_skeleton_t *svc_skeli, 
    const axutil_env_t *env, axiom_node_t *node);

static const axis2_svc_skeleton_ops_t statistics_svc_skeleton_ops_var = {
    statistics_svc_init,
    statistics_svc_invoke,
    statistics_svc_on_fault,
    statistics_svc_free,
    statistics_svc_init_with_conf
};
    
/*Create function */
axis2_svc_skeleton_t *
statistics_svc_create(const axutil_env_t *env)
{

	axis2_svc_skeleton_t *svc_skeleton = NULL;

    /* Allocate memory for the structs */
    svc_skeleton = AXIS2_MALLOC(env->allocator, 
        sizeof(axis2_svc_skeleton_t));

    svc_skeleton->ops = &statistics_svc_skeleton_ops_var;
    svc_skeleton->func_array = NULL;

    /* Assign function pointers */
    

    return svc_skeleton;
}

/* Initialize the service */
int AXIS2_CALL
statistics_svc_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env)
{
    svc_skeleton->func_array = axutil_array_list_create(env, 0);

    /* Add the implemented operation names of the service to  
     * the array list of functions 
     */

    axutil_array_list_add(svc_skeleton->func_array, env, "send");

    /* Any initialization stuff of service should go here */

    return AXIS2_SUCCESS;
}

int AXIS2_CALL 
statistics_svc_init_with_conf(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    statistics_svc_init(svc_skeleton, env);
    return AXIS2_SUCCESS;
}

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL
statistics_svc_invoke(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx)
{
    return NULL;
}

/* On fault, handle the fault */
axiom_node_t* AXIS2_CALL
statistics_svc_on_fault(axis2_svc_skeleton_t *svc_skeli, 
              const axutil_env_t *env, axiom_node_t *node)
{
   /* Here we are just setting a simple error message inside an element 
    * called 'EchoServiceError' 
    */
    axiom_node_t *error_node = NULL;
    axiom_node_t* text_node = NULL;
    axiom_element_t *error_ele = NULL;
    error_ele = axiom_element_create(env, node, "Statistics Service Error", NULL, 
        &error_node);
    axiom_element_set_text(error_ele, env, "Statistics Service failed ", 
        text_node);
    return error_node;
}

/* Free the resources used */
int AXIS2_CALL
statistics_svc_free(axis2_svc_skeleton_t *svc_skeleton,
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
   *inst = statistics_svc_create(env);
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
