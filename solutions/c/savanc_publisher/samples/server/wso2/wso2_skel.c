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
#include <axis2_svc_skeleton.h>
#include <axiom_element.h>
#include <savan_publishing_client.h>
#include <savan_db_mgr.h>
#include <savan_util.h>

#include "wso2.h"
#include "../../../src/reg_client.h"

typedef struct wso2_data
{
    axutil_env_t *env;
    axis2_conf_t *conf;
}wso2_data_t;

int AXIS2_CALL
wso2_free(axis2_svc_skeleton_t *svc_skeleton,
            const axutil_env_t *env);

axis2_status_t AXIS2_CALL
wso2_free_void_arg(void *svc_skeleton,
                    const axutil_env_t *env);

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL 
wso2_invoke(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx);
        

int AXIS2_CALL 
wso2_init(axis2_svc_skeleton_t *svc_skeleton,
          const axutil_env_t *env);

static void
start_wso2_thread(
    const axutil_env_t *env,
    axis2_conf_t *conf);

int AXIS2_CALL 
wso2_init_with_conf(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axis2_conf_t *conf);

axiom_node_t* AXIS2_CALL
wso2_on_fault(axis2_svc_skeleton_t *svc_skeli, 
    const axutil_env_t *env, axiom_node_t *node);

static void * AXIS2_THREAD_FUNC
wso2_worker_func(
    axutil_thread_t *thrd,
    void* data);

static const axis2_svc_skeleton_ops_t wso2_skeleton_ops_var = {
    wso2_init,
    wso2_invoke,
    wso2_on_fault,
    wso2_free,
    wso2_init_with_conf
};
    
/*Create function */
axis2_svc_skeleton_t *
wso2_create(const axutil_env_t *env)
{

	axis2_svc_skeleton_t *svc_skeleton = NULL;

    /* Allocate memory for the structs */
    svc_skeleton = AXIS2_MALLOC(env->allocator, 
        sizeof(axis2_svc_skeleton_t));

    svc_skeleton->ops = &wso2_skeleton_ops_var;
    svc_skeleton->func_array = NULL;

    /* Assign function pointers */
    

    return svc_skeleton;
}

/* Initialize the service */
int AXIS2_CALL
wso2_init(axis2_svc_skeleton_t *svc_skeleton,
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
wso2_init_with_conf(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axis2_conf_t *conf)
{
    const axis2_char_t *dbname = NULL;

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wso2] Entry:wso2_init_with_conf");

    dbname = savan_util_get_dbname(env, conf);

    if(!savan_db_mgr_create_db(env, dbname))
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                "[savan] Could not create the database for name %s. Check whether database path "\
                "is correct and accessible. Exit loading the Savan module", dbname);
        
        return AXIS2_FAILURE;
    }

    reg_client_init(env, conf, "wso2");
    wso2_init(svc_skeleton, env);
    start_wso2_thread(env, conf);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wso2] Exit:wso2_init_with_conf");

    return AXIS2_SUCCESS;

}

/*
 * This method invokes the right service method 
 */
axiom_node_t* AXIS2_CALL
wso2_invoke(
    axis2_svc_skeleton_t *svc_skeleton,
    const axutil_env_t *env,
    axiom_node_t *node,
    axis2_msg_ctx_t *msg_ctx)
{
    return NULL;
}

static void
start_wso2_thread(
    const axutil_env_t *env,
    axis2_conf_t *conf)
{

	axutil_thread_t *worker_thread = NULL;
	wso2_data_t *data = NULL;

    /* Invoke the business logic.
     * Depending on the function name invoke the correct impl method.
     */

    data = AXIS2_MALLOC(env->allocator, sizeof(wso2_data_t));
    data->env = (axutil_env_t*)env;
    data->conf = conf;
    
    worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
        wso2_worker_func, (void*)data);
    if(! worker_thread)
    {
        return;
    }
    axutil_thread_pool_thread_detach(env->thread_pool, worker_thread);
}

/* On fault, handle the fault */
axiom_node_t* AXIS2_CALL
wso2_on_fault(axis2_svc_skeleton_t *svc_skeli, 
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
wso2_free(axis2_svc_skeleton_t *svc_skeleton,
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
    
    reg_client_cleanup(env);

    return AXIS2_SUCCESS; 
}


static void * AXIS2_THREAD_FUNC
wso2_worker_func(
    axutil_thread_t *thrd,
    void* data)
{
    axutil_env_t *main_env = NULL;
    axutil_env_t *env = NULL;
    axiom_namespace_t *test_ns = NULL;
    axiom_element_t* test_elem = NULL;
    axiom_node_t *test_node = NULL;
    axiom_element_t* test_elem1 = NULL;
    axiom_node_t *test_node1 = NULL;
    axiom_element_t* test_elem2 = NULL;
    axiom_node_t *test_node2 = NULL;
    axis2_conf_t *conf = NULL;
    axis2_svc_t *svc = NULL;
    axis2_char_t *topic_url = "http://localhost:9090/axis2/services/wso2";
    
    wso2_data_t *mydata = (wso2_data_t*)data;
    main_env = mydata->env;
    conf = mydata->conf;
    
    env = axutil_init_thread_env(main_env);

    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Start:wso2_worker_func");

    svc = axis2_conf_get_svc(conf, env, "wso2");
    while(1)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wso2] Inside while loop");
        {
            savan_publishing_client_t *pub_client = NULL;

            pub_client = savan_publishing_client_create(env, conf, svc);
            /* Build a payload and pass it to the savan publishing client */ 
            test_ns = axiom_namespace_create (env, 
                "http://www.wso2.com/savan/c/wso2", "test");
            test_elem = axiom_element_create(env, NULL, "notify", test_ns, &test_node);
            test_elem1 = axiom_element_create(env, test_node, "wso2", NULL, &test_node1);
            test_elem2 = axiom_element_create(env, test_node1, "wsfc", NULL, &test_node2);
			axiom_element_set_text(test_elem2, env, "wsfc", test_node2);
		
			/*printf("%s\n", axiom_node_to_string(test_node, env));*/
            savan_publishing_client_publish(pub_client, env, test_node, topic_url);
            savan_publishing_client_free(pub_client, env);
        }
        AXIS2_SLEEP(5);
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "End:wso2_worker_func");
}

/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int 
axis2_get_instance(axis2_svc_skeleton_t **inst,
                   const axutil_env_t *env)
{
   *inst = wso2_create(env);
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
