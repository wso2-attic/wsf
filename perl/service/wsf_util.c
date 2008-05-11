#include "wsf_util.h"
#include <stdlib.h>

static void* WSF_CALL 
wsf_malloc_wrapper (axutil_allocator_t* allocator,
					size_t size);

static void* WSF_CALL
wsf_realloc_wrapper (axutil_allocator_t* allocator,
					 void* ptr,
					 size_t size);

static void WSF_CALL
wsf_free_wrapper (axutil_allocator_t* allocator,
				  void* ptr);



static void* WSF_CALL 
wsf_malloc_wrapper (axutil_allocator_t* allocator,
					size_t size)
{
	return malloc (size);
}

static void* WSF_CALL
wsf_realloc_wrapper (axutil_allocator_t* allocator,
					 void* ptr,
					 size_t size)
{
	return realloc (ptr, size);
}

static void WSF_CALL
wsf_free_wrapper (axutil_allocator_t* allocator,
				  void* ptr)
{
	free (ptr);
}


axutil_env_t*
wsf_env_create (const axis2_char_t *path_to_log)
{
    axutil_env_t *env;
    axutil_allocator_t *allocator = NULL;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;
    axis2_char_t log_path[250];
    
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
    return env;
}

axutil_env_t*
wsf_env_create_svr (const axis2_char_t *path_to_log)
{
    axutil_allocator_t *allocator = NULL;
    axutil_env_t *env;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;
    axis2_char_t log_path[250];
    axutil_thread_pool_t *thread_pool = NULL;
    const axis2_char_t *LOG_NAME = "wsf_perl_server_svr.log";
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
    return env;
}

