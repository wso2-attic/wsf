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
#include <axis2_op.h>
#include <axutil_qname.h>

#include <savan.h>

#include "publisher.h"

typedef struct publisher_data
{
    axutil_env_t *env;
    axis2_conf_t *conf;
}publisher_data_t;

int AXIS2_CALL
publisher_free(axis2_svc_skeleton_t *svc_skeleton,
            const axutil_env_t *env);

axis2_status_t AXIS2_CALL
publisher_free_void_arg(void *svc_skeleton,
                    const axutil_env_t *env);

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL 
publisher_invoke(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx);
        

int AXIS2_CALL 
publisher_init(axis2_svc_skeleton_t *svc_skeleton,
          const axutil_env_t *env);

static void
start_publisher_thread(
    const axutil_env_t *env,
    axis2_conf_t *conf);

int AXIS2_CALL 
publisher_init_with_conf(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axis2_conf_t *conf);

axiom_node_t* AXIS2_CALL
publisher_on_fault(axis2_svc_skeleton_t *svc_skeli, 
              const axutil_env_t *env, axiom_node_t *node);

static void * AXIS2_THREAD_FUNC
publisher_worker_func(
    axutil_thread_t *thrd,
    void* data);

static const axis2_svc_skeleton_ops_t publisher_skeleton_ops_var = {
    publisher_init,
    publisher_invoke,
    publisher_on_fault,
    publisher_free,
    publisher_init_with_conf
};
    
/*Create function */
axis2_svc_skeleton_t *
axis2_publisher_create(const axutil_env_t *env)
{

	axis2_svc_skeleton_t *svc_skeleton = NULL;

    /* Allocate memory for the structs */
    svc_skeleton = AXIS2_MALLOC(env->allocator, 
        sizeof(axis2_svc_skeleton_t));

    svc_skeleton->ops = &publisher_skeleton_ops_var;
    svc_skeleton->func_array = NULL;

    /* Assign function pointers */
    

    return svc_skeleton;
}

/* Initialize the service */
int AXIS2_CALL
publisher_init(axis2_svc_skeleton_t *svc_skeleton,
                        const axutil_env_t *env)
{
    svc_skeleton->func_array = axutil_array_list_create(env, 0);

    /* Add the implemented operation names of the service to  
     * the array list of functions 
     */

    axutil_array_list_add(svc_skeleton->func_array, env, "start");

    /* Any initialization stuff of service should go here */

    return AXIS2_SUCCESS;
}

int AXIS2_CALL 
publisher_init_with_conf(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    publisher_init(svc_skeleton, env);
    start_publisher_thread(env, conf); 
    return AXIS2_SUCCESS;
}

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL
publisher_invoke(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx)
{
    return NULL;
}

static void
start_publisher_thread(
    const axutil_env_t *env,
    axis2_conf_t *conf)
{

	axutil_thread_t *worker_thread = NULL;
	publisher_data_t *data = NULL;

    /* Invoke the business logic.
     * Depending on the function name invoke the correct impl method.
     */

    data = AXIS2_MALLOC(env->allocator, sizeof(publisher_data_t));
    data->env = (axutil_env_t*)env;
    data->conf = conf;
    
    worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
        publisher_worker_func, (void*)data);
    if(! worker_thread)
    {
        return;
    }
    axutil_thread_pool_thread_detach(env->thread_pool, worker_thread);
}

/* On fault, handle the fault */
axiom_node_t* AXIS2_CALL
publisher_on_fault(axis2_svc_skeleton_t *svc_skeli, 
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
publisher_free(axis2_svc_skeleton_t *svc_skeleton,
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


static void * AXIS2_THREAD_FUNC
publisher_worker_func(
    axutil_thread_t *thrd,
    void* data)
{
    axutil_env_t *main_env = NULL;
    axutil_env_t *env = NULL;
    axiom_namespace_t *test_ns = NULL;
    axiom_node_t *test_node = NULL;
    axiom_element_t* test_elem = NULL;
    axis2_conf_t *conf = NULL;
    axis2_svc_t *svc = NULL;
    axutil_param_t *param = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    
    publisher_data_t *mydata = (publisher_data_t*)data;
    main_env = mydata->env;
    conf = mydata->conf;
    
    env = axutil_init_thread_env(main_env);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "inside thread worker func...");


    svc = axis2_conf_get_svc(conf, env, "publisher");
    conf_ctx = axis2_conf_ctx_create(env, conf);
    while(1)
    {
        axutil_hash_t *subs_list = NULL;
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Inside while loop");

        param = axis2_svc_get_param(svc, env, SAVAN_SUBSCRIBER_LIST);
        if(param)
            subs_list = axutil_param_get_value(param, env);
        if(subs_list)
        {
            savan_publishing_client_t *pub_client = NULL;

            pub_client = savan_publishing_client_create(env, conf_ctx, svc);
            /* Build a payload and pass it to the savan publishing client */ 
            test_ns = axiom_namespace_create (env, "http://www.wso2.com/savan/c/publisher", "test");
            test_elem = axiom_element_create(env, NULL, "notify", test_ns, &test_node);
            axiom_element_set_text(test_elem, env, "test data", test_node);
            savan_publishing_client_publish(pub_client, env, test_node);
            savan_publishing_client_free(pub_client, env);
        }
        AXIS2_SLEEP(10);
    }
}

/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int 
axis2_get_instance(axis2_svc_skeleton_t **inst,
                   const axutil_env_t *env)
{
   *inst = axis2_publisher_create(env);
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
