/*
 * Copyright 2005 - 2008 WSO2, Inc. http://wso2.com
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

#include "wsf.h"
#include "wsf_worker.h"

static axutil_env_t *env;
static axutil_env_t *ws_env_svr;
static int ws_is_svr;
axis2_msg_recv_t *wsf_msg_recv;
wsf_worker_t *worker;


/* malloc wrapper */
static void* WSF_CALL 
wsf_malloc_wrapper (axutil_allocator_t* allocator,
					size_t size)
{
	return malloc (size);
}

/* realloc wrapper */
static void* WSF_CALL
wsf_realloc_wrapper (axutil_allocator_t* allocator,
					 void* ptr,
					 size_t size)
{
	return realloc (ptr, size);
}

/* free wrapper */
static void WSF_CALL
wsf_free_wrapper (axutil_allocator_t* allocator,
				  void* ptr)
{
	free (ptr);
}

void
wsf_init (axis2_char_t *path_to_log,
               int log_level)
{
    axutil_allocator_t *allocator = NULL;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;
    axis2_char_t log_path[250];
    axutil_thread_pool_t *thread_pool = NULL;
    const axis2_char_t *LOG_NAME = "wsf_perl_server.log";
    allocator = malloc (sizeof (axutil_allocator_t));
    axis2_char_t *repo_path = "/home/dinesh/wsf_c/deploy";

    allocator->free_fn = wsf_free_wrapper;
    allocator->malloc_fn = wsf_malloc_wrapper;
    allocator->realloc = wsf_realloc_wrapper;

    error = axutil_error_create (allocator);
    if (path_to_log && (
            (0 == strcmp (path_to_log, "")) ||
            (0 == strcmp (path_to_log, ".")) ||
            (0 == strcmp (path_to_log, "./")))) {
        snprintf (log_path, 256, "%s", LOG_NAME);
    }
	else
	{
        snprintf (log_path, 256, "%s/%s", path_to_log, LOG_NAME);
    }

    thread_pool = axutil_thread_pool_init (allocator);
    log = axutil_log_create (allocator, NULL, log_path);
    env = axutil_env_create_with_error_log_thread_pool (allocator, error, log, thread_pool);

    if (!env)
    {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, 
                         "unable to create environment, given log path is %s \
and log level is %d", log_path, log_level);
        return;
    }
	env->log->level = log_level;
    wsf_msg_recv = (axis2_msg_recv_t* )wsf_xml_msg_recv_create (env);

    if (!wsf_msg_recv)
    {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
                         "wsf perl msg receiver creation failed \n");
        return;
    }
    axiom_xml_reader_init ();

    /* repo path need to be given for worker creation */
    worker = wsf_worker_create (env, 
                                repo_path);
    if (!worker)
    {
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI,
                         "wsf perl worker creation failed for repo path %s", 
                         repo_path);
        return;
    }
    AXIS2_LOG_INFO (env->log, "wsf perl successfully initialized");
}

/* To create WSFC environment */
axutil_env_t*
wsf_env_create (axis2_char_t* path_to_log,
				int log_level)
{
    axutil_allocator_t *allocator = NULL;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;
    axis2_char_t log_path[250];
    axutil_env_t *env = NULL;
    axutil_thread_pool_t *thread_pool = NULL;
    const axis2_char_t *LOG_NAME = "wsf_perl_server.log";
    allocator = malloc (sizeof (axutil_allocator_t));

    allocator->free_fn = wsf_free_wrapper;
    allocator->malloc_fn = wsf_malloc_wrapper;
    allocator->realloc = wsf_realloc_wrapper;

    error = axutil_error_create (allocator);
    if (path_to_log && (
            (0 == strcmp (path_to_log, "")) ||
            (0 == strcmp (path_to_log, ".")) ||
            (0 == strcmp (path_to_log, "./")))) {
        snprintf (log_path, 256, "%s", LOG_NAME);
    }
	else
	{
        snprintf (log_path, 256, "%s/%s", path_to_log, LOG_NAME);
    }

    thread_pool = axutil_thread_pool_init (allocator);
    log = axutil_log_create (allocator, NULL, log_path);
    env = axutil_env_create_with_error_log_thread_pool (allocator, error, log, thread_pool);
    env->log->level = log_level;

    return env;
}
