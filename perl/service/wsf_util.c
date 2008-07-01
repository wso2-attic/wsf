#include "wsf_util.h"
#include "wsf_worker.h"
#include <stdlib.h>

static void* WSF_CALL
wsf_malloc_wrapper(axutil_allocator_t* allocator,
        size_t size);

static void* WSF_CALL
wsf_realloc_wrapper(axutil_allocator_t* allocator,
        void* ptr,
        size_t size);

static void WSF_CALL
wsf_free_wrapper(axutil_allocator_t* allocator,
        void* ptr);

static void* WSF_CALL
wsf_malloc_wrapper(axutil_allocator_t* allocator,
        size_t size)
{
    return malloc(size);
}

static void* WSF_CALL
wsf_realloc_wrapper(axutil_allocator_t* allocator,
        void* ptr,
        size_t size)
{
    return realloc(ptr, size);
}

static void WSF_CALL
wsf_free_wrapper(axutil_allocator_t* allocator,
        void* ptr)
{
    free(ptr);
}

axutil_env_t*
wsf_env_create(const axis2_char_t *path_to_log, int log_level)
{
    axutil_env_t *env;
    axutil_allocator_t *allocator = NULL;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;
    axis2_char_t log_path[256];

    axutil_thread_pool_t *thread_pool = NULL;
    const axis2_char_t *LOG_NAME = "wsf_perl_server.log";
    allocator = malloc(sizeof(axutil_allocator_t));

    allocator->free_fn = wsf_free_wrapper;
    allocator->malloc_fn = wsf_malloc_wrapper;
    allocator->realloc = wsf_realloc_wrapper;

    error = axutil_error_create(allocator);
    if (path_to_log && (
                (0 == strcmp(path_to_log, "")) ||
                (0 == strcmp(path_to_log, ".")) ||
                (0 == strcmp(path_to_log, "./"))))
    {
        snprintf(log_path, 256, "%s", LOG_NAME);
    }
    else
    {
        snprintf(log_path, 256, "%s/%s", path_to_log, LOG_NAME);
    }

    thread_pool = axutil_thread_pool_init(allocator);
    log = axutil_log_create(allocator, NULL, log_path);
    env = axutil_env_create_with_error_log_thread_pool(allocator, error, log, thread_pool);
    env->log->level = log_level;
    return env;
}

axutil_env_t*
wsf_env_create_svr(const axis2_char_t *path_to_log)
{
    axutil_allocator_t *allocator = NULL;
    axutil_env_t *env;
    axutil_error_t *error = NULL;
    axutil_log_t *log = NULL;
    axis2_char_t log_path[256];
    axutil_thread_pool_t *thread_pool = NULL;
    const axis2_char_t *LOG_NAME = "wsf_perl_server_svr.log";
    allocator = malloc(sizeof(axutil_allocator_t *));
    /* axis2_char_t *repo_path = "/opt/wso2/wsf_c"; */

    allocator->free_fn = wsf_free_wrapper;
    allocator->malloc_fn = wsf_malloc_wrapper;
    allocator->realloc = wsf_realloc_wrapper;

    error = axutil_error_create(allocator);
    if (path_to_log && (
                (0 == strcmp(path_to_log, "")) ||
                (0 == strcmp(path_to_log, ".")) ||
                (0 == strcmp(path_to_log, "./"))))
    {
        snprintf(log_path, 256, "%s", LOG_NAME);
    }
    else
    {
        snprintf(log_path, 256, "%s/%s", path_to_log, LOG_NAME);
    }

    thread_pool = axutil_thread_pool_init(allocator);
    log = axutil_log_create(allocator, NULL, log_path);
    env = axutil_env_create_with_error_log_thread_pool(allocator, error, log, thread_pool);
    return env;
}

void
wsf_util_create_svc_from_svc_info(wsf_svc_info_t * svc_info,
        axutil_env_t * env)
{
    axutil_qname_t *svc_qname = NULL;
    axis2_svc_t *svc = NULL;
    axis2_conf_t *conf = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;

    if (!svc_info->perl_worker)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "perl worker is not available for svc");
        return;
    }

    conf_ctx = (axis2_conf_ctx_t *)wsf_worker_get_conf_ctx(svc_info->perl_worker, env);

    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    if (!conf)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "conf is not available for svc");
        return;
    }

    svc = axis2_conf_get_svc(conf, env, svc_info->svc_name);
    if (svc)
    {
        svc_info->svc = svc;
    }
    else
    {
        svc_qname = axutil_qname_create(env, svc_info->svc_name, NULL, NULL);
        svc_info->svc = axis2_svc_create_with_qname(env, svc_qname);
        axutil_qname_free(svc_qname, env);
    }
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
            "svc creation successful for %s service", svc_info->svc_name);
    return;
}

void
wsf_util_process_ws_service_operations_and_actions(wsf_svc_info_t * svc_info,
        axutil_env_t * env)
{
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
            "processing operations and actions for svc");
    axutil_hash_index_t *hi;
    if (svc_info->ops_to_functions)
    {
        for (hi = axutil_hash_first(svc_info->ops_to_functions, env);
                hi; hi = axutil_hash_next(env, hi))
        {
            void *v = NULL;
            const void *k = NULL;
            char *key = NULL;
            char *val = NULL;
            /* char *function_name = NULL; */
            /* int key_len = 0; */

            axutil_hash_this(hi, &k, NULL, &v);
            key = (axis2_char_t *) k;
            val = (axis2_char_t *) v;
            if (key && val)
            {
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                        "processing operations %s key and %s value", key, val);

                /* function is there, add the operation to service */
                if (strcmp(key, val) == 0)
                {
                    /*  wsf_util_create_op_and_add_to_svc (svc_info, NULL, */
                    /*                         env, key, ht_ops_to_mep); */
                }
                else
                {
                    /*                     char *action_for_op = NULL; */
                    /*                     action_for_op = axutil_hash_get (svc_info->ops_to_actions, key, */
                    /*                         AXIS2_HASH_KEY_STRING); */

                    /*                     if (!action_for_op)  */
                    /*                     { */
                    /* There was no mapping WSA action for this operation.
                    So this operation was not yet added, hence add. */
                    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                            "processing operations %s key", key);
                    wsf_util_create_op_and_add_to_svc(svc_info, NULL,
                            env, key, NULL);
                    /*                     } */
                }
            }
        }
    }
}

void
wsf_util_create_op_and_add_to_svc(
    wsf_svc_info_t * svc_info,
    char *action,
    axutil_env_t * env,
    char *op_name,
    char *ht_mep)
{
    axis2_svc_t *svc = NULL;
    axis2_op_t *op = NULL;
    axutil_qname_t *op_qname = NULL;
    op_qname = axutil_qname_create(env, op_name, NULL, NULL);
    svc = svc_info->svc;
    if (!svc)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "svc not available for svc name %s", svc_info->svc_name);
        return;
    }

    if (svc && op_name)
    {
        op = axis2_svc_get_op_with_name(svc_info->svc, env, op_name);
        if (!op)
        {
            axis2_conf_t *conf = NULL;
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_phases_info_t *info = NULL;

            op_qname = axutil_qname_create(env, op_name, NULL, NULL);

            op = axis2_op_create_with_qname(env, op_qname);

            axis2_op_set_msg_recv(op, env, svc_info->msg_recv);

            conf_ctx = wsf_worker_get_conf_ctx(svc_info->perl_worker, env);

            conf = axis2_conf_ctx_get_conf(conf_ctx, env);

            info = axis2_conf_get_phases_info(conf, env);
            axis2_phases_info_set_op_phases(info, env, op);
            axis2_svc_add_op(svc_info->svc, env, op);
            axis2_op_set_msg_exchange_pattern(op, env,
                    AXIS2_MEP_URI_IN_OUT);
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "AXIS2_MEP_URI_IN_OUT");
            if (action)
            {
                axis2_svc_add_mapping(svc_info->svc, env, action, op);
            }
        }
    }

    if (op_qname)
    {
        axutil_qname_free(op_qname, env);
    }

    return;
}

void
wsf_util_conf_add_svc(wsf_svc_info_t * svc_info,
        axutil_env_t * env)
{
    axis2_svc_t *svc = NULL;
    axis2_conf_t *conf = NULL;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_phases_info_t *info = NULL;
    conf_ctx = wsf_worker_get_conf_ctx(svc_info->perl_worker, env);
    conf = axis2_conf_ctx_get_conf(conf_ctx, env);
    svc = axis2_conf_get_svc(conf, env, svc_info->svc_name);
    if (!svc)
    {
        svc = svc_info->svc;
        if (!svc)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                    "svc not available for svc name %s", svc_info->svc_name);
            return;
        }
        axis2_conf_add_svc(conf, env, svc);
    }
    return;
}

axiom_node_t *
wsf_util_deserialize_buffer(const axutil_env_t * env,
        char *buffer)
{
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_document_t *document = NULL;
    axiom_node_t *payload = NULL;

    reader = axiom_xml_reader_create_for_memory(env, buffer, axutil_strlen(buffer),
            AXIS2_UTF_8, AXIS2_XML_PARSER_TYPE_BUFFER);
    if (!reader)
    {
        return NULL;
    }

    builder = axiom_stax_builder_create(env, reader);

    if (!builder)
    {
        return NULL;
    }
    document = axiom_stax_builder_get_document(builder, env);
    if (!document)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Document is not found");
        return NULL;
    }

    payload = axiom_document_get_root_element(document, env);

    if (!payload)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Root element of the document is not found");
        return NULL;
    }
    axiom_document_build_all(document, env);

    axiom_stax_builder_free_self(builder, env);

    return payload;
}
