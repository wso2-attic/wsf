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
#include <axis2_svc_skeleton.h>
#include "rm_sample_svc.h"
#include <axutil_array_list.h>
#include <axis2_op.h>
#include <axiom_element.h>

int AXIS2_CALL
rm_sample_svc_free(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
rm_sample_svc_free_void_arg(
    void *svc_skeleton,
    const axutil_env_t *env);

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL 
rm_sample_svc_invoke(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx);
            

int AXIS2_CALL 
rm_sample_svc_init(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env);

axiom_node_t* AXIS2_CALL
rm_sample_svc_on_fault(
    axis2_svc_skeleton_t *svc_skeli, 
    const axutil_env_t *env, axiom_node_t *node);

static const axis2_svc_skeleton_ops_t rm_sample_svc_ops_var = {
    rm_sample_svc_init,
    rm_sample_svc_invoke,
    rm_sample_svc_on_fault,
    rm_sample_svc_free
};

/*Create function */
axis2_svc_skeleton_t *
rm_sample_svc_create(
    const axutil_env_t *env)
{
    axis2_svc_skeleton_t *svc_skeleton = NULL;
    /* Allocate memory for the structs */
    svc_skeleton = AXIS2_MALLOC(env->allocator, 
        sizeof(axis2_svc_skeleton_t));

    svc_skeleton->ops = AXIS2_MALLOC(
        env->allocator, sizeof(axis2_svc_skeleton_ops_t));
    svc_skeleton->ops = &rm_sample_svc_ops_var;
    svc_skeleton->func_array = NULL;

    return svc_skeleton;
}

/* Initialize the service */
int AXIS2_CALL
rm_sample_svc_init(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env)
{
    svc_skeleton->func_array = axutil_array_list_create(env, 0);
    /* Add the implemented operation names of the service to  
     * the array list of functions 
     */
    axutil_array_list_add(svc_skeleton->func_array, env, "echoString");
    axutil_array_list_add(svc_skeleton->func_array, env, "ping");
    axutil_array_list_add(svc_skeleton->func_array, env, "mtomSample");
    /* Any initialization stuff of echo service should go here */
    return AXIS2_SUCCESS;
}

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL
rm_sample_svc_invoke(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx)
{
    axis2_op_t *op = NULL;
    axutil_qname_t *op_qname = NULL;
    axis2_char_t *op_name = NULL;
    
    op = axis2_msg_ctx_get_op(msg_ctx, env);
    if(op)
    {
        op_qname = (axutil_qname_t *)axis2_op_get_qname(op, env);
        if(op_qname)
            op_name = axutil_qname_get_localpart(op_qname, env);
        if(op_name)
        {
            if (axutil_strcmp(op_name, "echoString") == 0)
                return rm_sample_svc_echo(env, node);
            if (axutil_strcmp(op_name, "ping") == 0)
            {
                rm_sample_svc_ping(env, node);
                return NULL;
            }
            if (axutil_strcmp(op_name, "mtomSample") == 0)
                return rm_sample_svc_mtom(env, node);
        }
    }
    return NULL;
}

/* On fault, handle the fault */
axiom_node_t* AXIS2_CALL
rm_sample_svc_on_fault(axis2_svc_skeleton_t *svc_skeli, 
              const axutil_env_t *env, axiom_node_t *node)
{
   /* Here we are just setting a simple error message inside an element 
    * called 'EchoServiceError' 
    */
    axiom_node_t *error_node = NULL;
    axiom_node_t* text_node = NULL;
    axiom_element_t *error_ele = NULL;
    error_ele = axiom_element_create(env, node, "EchoServiceError", NULL, 
        &error_node);
    axiom_element_set_text(error_ele, env, "Echo service failed ", 
        text_node);
    return error_node;
}

/* Free the resources used */
int AXIS2_CALL
rm_sample_svc_free(axis2_svc_skeleton_t *svc_skeleton,
            const axutil_env_t *env)
{
    /* Free the function array */
    if(svc_skeleton->func_array)
    {
        axutil_array_list_free(svc_skeleton->func_array, env);
        svc_skeleton->func_array = NULL;
    }
    
    /* Free the service skeleton */
    if(svc_skeleton)
    {
        AXIS2_FREE(env->allocator, svc_skeleton);
        svc_skeleton = NULL;
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
   *inst = rm_sample_svc_create(env);
    if(!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int 
axis2_remove_instance(
    axis2_svc_skeleton_t *inst,
    const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
   if (inst)
   {
        status = AXIS2_SVC_SKELETON_FREE(inst, env);
    }
    return status;
}

