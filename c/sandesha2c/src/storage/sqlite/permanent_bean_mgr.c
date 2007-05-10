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
 
#include "sandesha2_permanent_bean_mgr.h"
#include <sandesha2_permanent_storage_mgr.h>
#include <sandesha2_constants.h>
#include "sandesha2_permanent_bean_mgr.h"
#include <sandesha2_error.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_property_bean.h>
#include <sandesha2_utils.h>
#include <sandesha2_property_bean.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>
#include <axis2_conf_ctx.h>
#include <axutil_types.h>
#include <platforms/axutil_platform_auto_sense.h>

/** 
 * @brief Sandesha2 Permanent Bean Manager Struct Impl
 *   Sandesha2 Permanent Bean Manager
 */
typedef struct sandesha2_permanent_bean_mgr_impl
{
    sandesha2_permanent_bean_mgr_t bean_mgr;
    sandesha2_storage_mgr_t *storage_mgr;
    axutil_thread_mutex_t *mutex;

}sandesha2_permanent_bean_mgr_impl_t;

#define SANDESHA2_INTF_TO_IMPL(bean_mgr) \
    ((sandesha2_permanent_bean_mgr_impl_t *) bean_mgr)

static int 
sandesha2_permanent_bean_mgr_count_callback(
    void *not_used, 
    int argc, 
    char **argv, 
    char **col_name)
{
    int *count = (int *) not_used;
    *count = AXIS2_ATOI(argv[0]);
    return 0;
}

static int 
sandesha2_permanent_bean_mgr_response_retrieve_callback(
    void *not_used, 
    int argc, 
    char **argv, 
    char **col_name)
{
    int i = 0;
    sandesha2_response_t *response = NULL;
    sandesha2_bean_mgr_args_t *args = (sandesha2_bean_mgr_args_t *) not_used;
    const axutil_env_t *env = args->env;
    if(argc < 1)
    {
        args->data = NULL;
        return 0;
    }
    response = (sandesha2_response_t *) args->data;
    if(!response && argc > 0)
    {
        response = (sandesha2_response_t *) AXIS2_MALLOC(env->allocator, sizeof(
            sandesha2_response_t));
        args->data = response;
    }
    for(i = 0; i < argc; i++)
    {
        if(0 == axutil_strcmp(col_name[i], "response_str"))
            if(argv[i])
                response->response_str = axutil_strdup(env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "soap_version"))
            if(argv[i])
                response->soap_version = axutil_atoi(argv[i]);
    }
    return 0;
}


static int 
sandesha2_msg_store_bean_retrieve_callback(
    void *not_used, 
    int argc, 
    char **argv, 
    char **col_name)
{
    int i = 0;
    sandesha2_bean_mgr_args_t *args = (sandesha2_bean_mgr_args_t *) not_used;
    const axutil_env_t *env = args->env;
    sandesha2_msg_store_bean_t *bean = NULL;
    if(argc < 1)
    {
        args->data = NULL;
        return 0;
    }
    bean = (sandesha2_msg_store_bean_t *) args->data;
    if(!bean && argc > 0)
    {
        bean = sandesha2_msg_store_bean_create(env);
        args->data = bean;
    }
    for(i = 0; i < argc; i++)
    {
        if(0 == axutil_strcmp(col_name[i], "stored_key"))
            if(argv[i])
            {
                sandesha2_msg_store_bean_set_stored_key(bean, env, argv[i]);
            }
        if(0 == axutil_strcmp(col_name[i], "msg_id"))
            if(argv[i])
                sandesha2_msg_store_bean_set_msg_id(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "soap_env_str"))
            if(argv[i])
                sandesha2_msg_store_bean_set_soap_envelope_str(bean, env, 
                    argv[i]);
        if(0 == axutil_strcmp(col_name[i], "soap_version"))
            if(argv[i])
                sandesha2_msg_store_bean_set_soap_version(bean, env, AXIS2_ATOI(argv[i]));
        if(0 == axutil_strcmp(col_name[i], "transport_out"))
            if(argv[i])
                sandesha2_msg_store_bean_set_transport_out(bean, env, AXIS2_ATOI(argv[i]));
        if(0 == axutil_strcmp(col_name[i], "op"))
            if(argv[i])
                sandesha2_msg_store_bean_set_op(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "svc"))
            if(argv[i])
                sandesha2_msg_store_bean_set_svc(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "svc_grp"))
            if(argv[i])
                sandesha2_msg_store_bean_set_svc_grp(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "op_mep"))
            if(argv[i])
                sandesha2_msg_store_bean_set_op_mep(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "to_url"))
            if(argv[i])
                sandesha2_msg_store_bean_set_to_url(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "transport_to"))
            if(argv[i] && 0 != axutil_strcmp("(null)", argv[i]))
            {
                sandesha2_msg_store_bean_set_transport_to(bean, env, argv[i]);
            }
        if(0 == axutil_strcmp(col_name[i], "execution_chain_str"))
            if(argv[i])
                sandesha2_msg_store_bean_set_execution_chain_str(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "flow"))
            if(argv[i])
                sandesha2_msg_store_bean_set_flow(bean, env, AXIS2_ATOI(argv[i]));
        if(0 == axutil_strcmp(col_name[i], "msg_recv_str"))
            if(argv[i])
                sandesha2_msg_store_bean_set_msg_recv_str(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "svr_side"))
            if(argv[i])
                sandesha2_msg_store_bean_set_svr_side(bean, env, AXIS2_ATOI(argv[i]));
        if(0 == axutil_strcmp(col_name[i], "in_msg_store_key"))
            if(argv[i])
                sandesha2_msg_store_bean_set_in_msg_store_key(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "prop_str"))
            if(argv[i])
                sandesha2_msg_store_bean_set_persistent_property_str(bean, 
                    env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "action"))
            if(argv[i])
                sandesha2_msg_store_bean_set_action(bean, env, argv[i]);
    }
    return 0;
}


axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_match(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate)
{
    return bean_mgr->ops.match(bean_mgr, env, bean, candidate);
}

AXIS2_EXTERN sandesha2_permanent_bean_mgr_t * AXIS2_CALL
sandesha2_permanent_bean_mgr_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr,
    axis2_conf_ctx_t *conf_ctx,
    axis2_char_t *key)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    bean_mgr_impl = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_permanent_bean_mgr_impl_t));

    bean_mgr_impl->storage_mgr = storage_mgr;
    bean_mgr_impl->mutex = sandesha2_permanent_storage_mgr_get_mutex(storage_mgr, env);
    return &(bean_mgr_impl->bean_mgr);
}

void AXIS2_CALL
sandesha2_permanent_bean_mgr_free(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Start:sandesha2_permanent_bean_mgr_free_impl");
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);

    if(bean_mgr_impl)
    {
        AXIS2_FREE(env->allocator, bean_mgr_impl);
        bean_mgr_impl = NULL;
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_bean_mgr_free_impl");
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_insert(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    int (*retrieve_func)(void *, int, char **, char **),
    axis2_char_t *sql_stmt_retrieve,
    axis2_char_t *sql_stmt_update,
    axis2_char_t *sql_stmt_insert)
{
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    sqlite3 *dbconn = NULL;
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
   
    sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return AXIS2_FALSE;
    rc = sqlite3_exec(dbconn, sql_stmt_insert, 0, 0, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_insert, 
            0, 0, &error_msg, rc);
    if( rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql stmt: %s. sql error: %s", 
            sql_stmt_insert, error_msg);
        printf("sql_stmt_insert:%s\n", sql_stmt_insert);
        printf("insert error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return AXIS2_TRUE;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_remove(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    int (*retrieve_func)(void *, int, char **, char **),
    axis2_char_t *sql_stmt_retrieve,
    axis2_char_t *sql_stmt_remove)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_bean_mgr_args_t *args = NULL;
    axis2_char_t *error_msg = NULL;
    sandesha2_rm_bean_t *bean = NULL;
    sqlite3 *dbconn = NULL;
    int rc = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return AXIS2_FALSE;
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = env;
    args->data = NULL;
    rc = sqlite3_exec(dbconn, sql_stmt_retrieve, retrieve_func, args, 
        &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_retrieve, 
            retrieve_func, args, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql stmt: %s. sql error: %s",
            sql_stmt_retrieve, error_msg);
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    if(args->data)
        bean = (sandesha2_rm_bean_t *) args->data;
    if(args)
        AXIS2_FREE(env->allocator, args);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    if(bean)
    {
        if(sandesha2_rm_bean_get_key(bean, env))
            sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, 
                bean);
    }
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    rc = sqlite3_exec(dbconn, sql_stmt_remove, 0, 0, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_remove, 
            0, 0, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql stmt: %s. sql error: %s",
            sql_stmt_remove, error_msg);
        printf("sql_stmt_remove:%s\n", sql_stmt_remove);
        printf("remove error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return AXIS2_TRUE;
}

sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_retrieve(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    int (*retrieve_func)(void *, int, char **, char **),
    axis2_char_t *sql_stmt_retrieve)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_bean_mgr_args_t *args = NULL;
    axis2_char_t *error_msg = NULL;
    sandesha2_rm_bean_t *bean = NULL;
    sqlite3 *dbconn = NULL;
    int rc = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return NULL;
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    rc = sqlite3_exec(dbconn, sql_stmt_retrieve, retrieve_func, args, 
        &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_retrieve, 
            retrieve_func, args, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql stmt: %s. sql error: %s",
            sql_stmt_retrieve, error_msg);
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    if(args->data)
        bean = (sandesha2_rm_bean_t *) args->data;
    if(args)
        AXIS2_FREE(env->allocator, args);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    if(bean)
        sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    rc = sqlite3_exec(dbconn, sql_stmt_retrieve, retrieve_func, args, 
        &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_retrieve, 
            retrieve_func, args, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            error_msg);
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    if(args->data)
        bean = (sandesha2_rm_bean_t *) args->data;
    if(args)
        AXIS2_FREE(env->allocator, args);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return bean;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_update(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    int (*retrieve_func)(void *, int, char **, char **),
    axis2_char_t *sql_stmt_retrieve_old_bean,
    axis2_char_t *sql_stmt_update)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sqlite3 *dbconn = NULL;
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    if(bean)
        sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return AXIS2_FALSE;
    rc = sqlite3_exec(dbconn, sql_stmt_update, 0, 0, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_update, 
            0, 0, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
            error_msg);
        printf("sql_stmt_update:%s\n", sql_stmt_update);
        printf("update error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return AXIS2_TRUE;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_find(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    int (*find_func)(void *, int, char **, char **),
    int (*count_func)(void *, int, char **, char **),
    axis2_char_t *sql_stmt_find,
    axis2_char_t *sql_stmt_count)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_bean_mgr_args_t *args = NULL;
    axutil_array_list_t *beans = NULL;
    int i = 0, size = 0, rc = -1;
    sqlite3 *dbconn = NULL;
    axutil_array_list_t *data_array = NULL;
    axis2_char_t *error_msg = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    beans = axutil_array_list_create(env, 0);
    if(!beans)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        return NULL;
    }
    rc = sqlite3_exec(dbconn, sql_stmt_find, find_func, args, 
        &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_find, 
            find_func, args, &error_msg, rc);
    if(args->data)
        data_array = (axutil_array_list_t *) args->data;
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        if(data_array)
            axutil_array_list_free(data_array, env);
        if(args)
            AXIS2_FREE(env->allocator, args);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
            error_msg);
        printf("sql_stmt_find:%s\n", sql_stmt_find);
        printf("retrieve error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return NULL;
    }
    if(data_array)
        size = axutil_array_list_size(data_array, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_rm_bean_t *candidate = NULL;
        candidate = (sandesha2_rm_bean_t *) axutil_array_list_get(data_array, 
            env, i);
         if(!candidate)
            continue;
        if(bean && sandesha2_permanent_bean_mgr_match(bean_mgr, env, bean,
            candidate))
        {
            axutil_array_list_add(beans, env, candidate);
        }
        if(!bean)
            axutil_array_list_add(beans, env, candidate);
    }
    if(data_array)
        axutil_array_list_free(data_array, env);
    if(args)
        AXIS2_FREE(env->allocator, args);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    /* Now we have a point-in-time view of the beans, lock them all.*/
    size = axutil_array_list_size(beans, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_rm_bean_t *temp = axutil_array_list_get(beans, env, i);
        if(temp)
            sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, 
                temp);
    }
    /* Finally remove any beans that are no longer in the table */
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    size = axutil_array_list_size(beans, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_rm_bean_t *temp = axutil_array_list_get(beans, env, i);
        if(temp)
        {
            int count = -1;

            rc = sqlite3_exec(dbconn, sql_stmt_count, count_func, &count, 
                &error_msg);
            if(rc == SQLITE_BUSY)
                rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_count, 
                    count_func, &count, &error_msg, rc);
            if(rc != SQLITE_OK )
            {
                axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
                AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
                    error_msg);
                printf("sql_stmt_count:%s\n", sql_stmt_count);
                printf("retrieve error_msg:%s\n", error_msg);
                sqlite3_free(error_msg);
                return NULL;
            }
            if(count == 0)
            {
                axutil_array_list_remove(beans, env, i);
            }
        }
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return beans;
}

sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_find_unique(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    int (*find_func)(void *, int, char **, char **),
    int (*count_func)(void *, int, char **, char **),
    axis2_char_t *sql_stmt_find,
    axis2_char_t *sql_stmt_count)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    axutil_array_list_t *beans = NULL;
    int size = 0;
    sandesha2_rm_bean_t *ret = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    beans = sandesha2_permanent_bean_mgr_find(bean_mgr, env, bean, find_func, 
        count_func, sql_stmt_find, sql_stmt_count);
    if(beans)
        size = axutil_array_list_size(beans, env);
    if( size > 1)
    {
        AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[sandesha2] Non-Unique result");
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_NON_UNIQUE_RESULT, 
            AXIS2_FAILURE);
        return NULL;
    }
    if(size == 1)
       ret = axutil_array_list_get(beans, env, 0);
    return ret;
}

sandesha2_msg_store_bean_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_retrieve_msg_store_bean(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_bean_mgr_args_t *args = NULL;
    axis2_char_t *error_msg = NULL;
    sandesha2_msg_store_bean_t *msg_store_bean = NULL;
    int rc = -1;
    sqlite3 *dbconn = NULL;
    axis2_char_t sql_stmt_retrieve[512];
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return NULL;
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    sprintf(sql_stmt_retrieve, "select stored_key, msg_id, soap_env_str,"\
        "soap_version, transport_out, op, svc, svc_grp, op_mep, to_url, "\
        "transport_to, execution_chain_str, flow, msg_recv_str, svr_side, "\
        "in_msg_store_key, prop_str, action from msg where stored_key='%s'", 
        key);
    rc = sqlite3_exec(dbconn, sql_stmt_retrieve, 
        sandesha2_msg_store_bean_retrieve_callback, args, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_retrieve, 
            sandesha2_msg_store_bean_retrieve_callback, args, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            error_msg);
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    if(args->data)
        msg_store_bean = (sandesha2_msg_store_bean_t *) args->data;
    if(args)
        AXIS2_FREE(env->allocator, args);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return msg_store_bean;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_insert_msg_store_bean(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    sandesha2_msg_store_bean_t *bean)
{
    axis2_char_t sql_stmt_retrieve[512];
    axis2_char_t *sql_stmt_update = NULL;
    axis2_char_t *sql_stmt_insert = NULL;
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    int sql_size = -1;
    sqlite3 *dbconn = NULL;
    sandesha2_bean_mgr_args_t *args = NULL;
    sandesha2_msg_store_bean_t *msg_store_bean = NULL;
	axis2_char_t *msg_id = NULL;
	axis2_char_t *stored_key = NULL;
	axis2_char_t *soap_env_str = NULL;
	int soap_version;
	axis2_char_t *svc_grp = NULL;
	axis2_char_t *svc = NULL;
	axis2_char_t *op  = NULL;
	AXIS2_TRANSPORT_ENUMS transport_out = -1;
	axis2_char_t *op_mep = NULL;
	axis2_char_t *to_url = NULL;
	axis2_char_t *reply_to = NULL;
	axis2_char_t *transport_to = NULL;
	axis2_char_t *execution_chain_str = NULL;
	sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
	int flow;	
	axis2_char_t *msg_recv_str = NULL;
	axis2_bool_t svr_side = AXIS2_FALSE;
	axis2_char_t *in_msg_store_key = NULL;
	axis2_char_t *prop_str = NULL;
	axis2_char_t *action = NULL;

	bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
	msg_id = sandesha2_msg_store_bean_get_msg_id(bean, env);
	stored_key = sandesha2_msg_store_bean_get_stored_key(bean, env);
	soap_env_str =  sandesha2_msg_store_bean_get_soap_envelope_str(bean, env);
	soap_version = sandesha2_msg_store_bean_get_soap_version(bean, env);
	transport_out = sandesha2_msg_store_bean_get_transport_out(bean, env);
	op = sandesha2_msg_store_bean_get_op(bean, env);
    svc = sandesha2_msg_store_bean_get_svc(bean, env);
	svc_grp = sandesha2_msg_store_bean_get_svc_grp(bean, env);
    op_mep = sandesha2_msg_store_bean_get_op_mep(bean, env);;
    to_url = sandesha2_msg_store_bean_get_to_url(bean, env);
	reply_to = sandesha2_msg_store_bean_get_reply_to(bean, env);
	transport_to = sandesha2_msg_store_bean_get_transport_to(bean, env);
	execution_chain_str = sandesha2_msg_store_bean_get_execution_chain_str(bean, env);
	flow = sandesha2_msg_store_bean_get_flow(bean, env);
	msg_recv_str = sandesha2_msg_store_bean_get_msg_recv_str(bean, env);
    svr_side = sandesha2_msg_store_bean_is_svr_side(bean, env);
	in_msg_store_key = sandesha2_msg_store_bean_get_in_msg_store_key(bean, env);
	prop_str = sandesha2_msg_store_bean_get_persistent_property_str(bean, env);
	action = sandesha2_msg_store_bean_get_action(bean, env);

    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_permanent_bean_mgr_insert_msg_store_bean");
    sql_size = axutil_strlen(msg_id) + axutil_strlen(stored_key) + 
        axutil_strlen(soap_env_str) + sizeof(int) + sizeof(int) + 
        axutil_strlen(op) + axutil_strlen(svc) + axutil_strlen(svc_grp) + 
        axutil_strlen(op_mep) + axutil_strlen(to_url) + axutil_strlen(reply_to) +
        axutil_strlen(transport_to) + axutil_strlen(execution_chain_str) + sizeof(int) + 
        axutil_strlen(msg_recv_str) + sizeof(int) + axutil_strlen(in_msg_store_key) +
        axutil_strlen(prop_str) + axutil_strlen(action) + 512;

    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        return AXIS2_FALSE;
    }

    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = env;
    args->data = NULL;
    sprintf(sql_stmt_retrieve, "select stored_key, msg_id, soap_env_str,"\
        "soap_version, transport_out, op, svc, svc_grp, op_mep, to_url, reply_to, "\
        "transport_to, execution_chain_str, flow, msg_recv_str, svr_side, "\
        "in_msg_store_key, prop_str, action from msg where stored_key = '%s'", 
        key);
    rc = sqlite3_exec(dbconn, sql_stmt_retrieve,
        sandesha2_msg_store_bean_retrieve_callback, args, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_retrieve, 
            sandesha2_msg_store_bean_retrieve_callback, args, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            error_msg);
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    if(args->data)
        msg_store_bean = (sandesha2_msg_store_bean_t *) args->data;
    if(args)
        AXIS2_FREE(env->allocator, args);
    if(msg_store_bean)
    {
        sql_stmt_update = AXIS2_MALLOC(env->allocator, sql_size);
        sprintf(sql_stmt_update, "update msg set msg_id='%s',"\
            "soap_env_str='%s', soap_version=%d, transport_out='%d', op='%s',"\
            "svc='%s', svc_grp='%s', op_mep='%s', to_url='%s',"\
            "transport_to='%s', reply_to='%s', execution_chain_str='%s',"\
            "flow=%d, msg_recv_str='%s', svr_side='%d', in_msg_store_key='%s',"\
            "prop_str='%s', action='%s' where stored_key='%s'", msg_id, 
            soap_env_str, soap_version, transport_out, op, svc, svc_grp, op_mep, 
            to_url, transport_to, reply_to, execution_chain_str, flow, 
            msg_recv_str, svr_side, in_msg_store_key, prop_str, action, key);
        rc = sqlite3_exec(dbconn, sql_stmt_update, 0, 0, &error_msg);
        if(rc == SQLITE_BUSY)
            rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_update, 
                0, 0, &error_msg, rc);
        if( rc != SQLITE_OK )
        {
            axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, 
                AXIS2_FAILURE);
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
                error_msg);
            printf("sql_stmt_update:%s\n", sql_stmt_update);
            printf("update error_msg:%s\n", error_msg);
            AXIS2_FREE(env->allocator, sql_stmt_update);
            sqlite3_free(error_msg);
            return AXIS2_FALSE;
        }
        AXIS2_FREE(env->allocator, sql_stmt_update);
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        return AXIS2_TRUE;
    }
    sql_stmt_insert = AXIS2_MALLOC(env->allocator, sql_size);
    sprintf(sql_stmt_insert, "insert into msg(stored_key, msg_id, "\
        "soap_env_str, soap_version, transport_out, op, svc, svc_grp, op_mep,"\
        "to_url, reply_to,transport_to, execution_chain_str, flow,"\
        "msg_recv_str, svr_side, in_msg_store_key, prop_str, action) "\
        "values('%s', '%s', '%s', %d, '%d', '%s', '%s', '%s', '%s', '%s',"\
        "'%s', '%s', '%s', %d, '%s', %d, '%s', '%s', '%s')", stored_key, msg_id, 
        soap_env_str, soap_version, transport_out, op, svc, svc_grp, op_mep, 
        to_url, reply_to, transport_to, execution_chain_str, flow, msg_recv_str, 
        svr_side, in_msg_store_key, prop_str, action);
    rc = sqlite3_exec(dbconn, sql_stmt_insert, 0, 0, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_insert, 
            0, 0, &error_msg, rc);
    if( rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", error_msg);
        printf("sql_stmt_insert:%s\n", sql_stmt_insert);
        printf("insert error_msg:%s\n", error_msg);
        AXIS2_FREE(env->allocator, sql_stmt_insert);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    AXIS2_FREE(env->allocator, sql_stmt_insert);
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_bean_mgr_insert_msg_store_bean");
    return AXIS2_TRUE;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_remove_msg_store_bean(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    axis2_char_t sql_stmt_remove[256];
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    sqlite3 *dbconn = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_permanent_bean_mgr_remove_msg_store_bean");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return AXIS2_FALSE;
    sprintf(sql_stmt_remove, "delete from msg where stored_key='%s'", key);
    rc = sqlite3_exec(dbconn, sql_stmt_remove, 0, 0, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_remove, 
            0, 0, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            error_msg);
        printf("sql_stmt_remove:%s\n", sql_stmt_remove);
        printf("remove error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_bean_mgr_remove_msg_store_bean");
    return AXIS2_TRUE;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_store_response(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *response,
    int msg_no,
    int soap_version)
{
    axis2_char_t sql_stmt_count[512];
    axis2_char_t *sql_stmt_update;
    axis2_char_t *sql_stmt_insert;
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    int sql_size = -1;
    sqlite3 *dbconn = NULL;
	sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    int count = -1;

	bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Start:sandesha2_permanent_bean_mgr_store_response");
    sql_size = axutil_strlen(seq_id) + axutil_strlen(response) + 
        sizeof(int) + sizeof(int) + 512;
    sprintf(sql_stmt_count, "select count(seq_id)"\
        " from response where seq_id = '%s' and msg_no=%d", seq_id, msg_no);

    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return AXIS2_FALSE;
    rc = sqlite3_exec(dbconn, sql_stmt_count, 
        sandesha2_permanent_bean_mgr_count_callback, &count, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_count, 
            sandesha2_permanent_bean_mgr_count_callback, &count, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
            error_msg);
        printf("sql_stmt_count:%s\n", sql_stmt_count);
        printf("retrieve error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    if(count > 0)
    {
        sql_stmt_update = AXIS2_MALLOC(env->allocator, sql_size);
        sprintf(sql_stmt_update, "update response set response_str='%s',"\
            "soap_version=%d where seq_id='%s' and msg_no=%d", response, 
            soap_version, seq_id, msg_no);
        rc = sqlite3_exec(dbconn, sql_stmt_update, 0, 0, &error_msg);
        if(rc == SQLITE_BUSY)
            rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_update, 
                0, 0, &error_msg, rc);
        if( rc != SQLITE_OK )
        {
            axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, 
                AXIS2_FAILURE);
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
                error_msg);
            printf("sql_stmt_update:%s\n", sql_stmt_update);
            printf("update error_msg:%s\n", error_msg);
            AXIS2_FREE(env->allocator, sql_stmt_update);
            sqlite3_free(error_msg);
            return AXIS2_FALSE;
        }
        AXIS2_FREE(env->allocator, sql_stmt_update);
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        return AXIS2_TRUE;
    }
    else
    {
        sql_stmt_insert = AXIS2_MALLOC(env->allocator, sql_size);
        sprintf(sql_stmt_insert, "insert into response(seq_id, response_str,"\
            "msg_no, soap_version) values('%s', '%s', %d, %d)", seq_id, 
            response, msg_no, soap_version);
        rc = sqlite3_exec(dbconn, sql_stmt_insert, 0, 0, &error_msg);
        if(rc == SQLITE_BUSY)
            rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_insert, 
                0, 0, &error_msg, rc);
        if( rc != SQLITE_OK )
        {
            axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", error_msg);
            printf("sql_stmt_insert:%s\n", sql_stmt_insert);
            printf("insert error_msg:%s\n", error_msg);
            AXIS2_FREE(env->allocator, sql_stmt_insert);
            sqlite3_free(error_msg);
            return AXIS2_FALSE;
        }
        AXIS2_FREE(env->allocator, sql_stmt_insert);
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_bean_mgr_store_response");
    return AXIS2_TRUE;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_remove_response(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    int msg_no)
{
    axis2_char_t sql_stmt_remove[256];
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    sqlite3 *dbconn = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_permanent_bean_mgr_remove_response");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return AXIS2_FALSE;
    sprintf(sql_stmt_remove, 
        "delete from response where seq_id='%s' and msg_no=%d", seq_id, msg_no);
    rc = sqlite3_exec(dbconn, sql_stmt_remove, 0, 0, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_remove, 
            0, 0, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            error_msg);
        printf("sql_stmt_remove:%s\n", sql_stmt_remove);
        printf("remove error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_bean_mgr_remove_response");
    return AXIS2_TRUE;
}

sandesha2_response_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_retrieve_response(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    int msg_no)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_bean_mgr_args_t *args = NULL;
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    sqlite3 *dbconn = NULL;
    axis2_char_t sql_stmt_retrieve[512];
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    axutil_thread_mutex_lock(bean_mgr_impl->mutex);
    dbconn = (sqlite3 *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
        return NULL;
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    sprintf(sql_stmt_retrieve, "select response_str, soap_version from response"\
        " where seq_id='%s' and msg_no=%d", seq_id, msg_no);
    rc = sqlite3_exec(dbconn, sql_stmt_retrieve, 
        sandesha2_permanent_bean_mgr_response_retrieve_callback, args, &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(dbconn, sql_stmt_retrieve, 
            sandesha2_permanent_bean_mgr_response_retrieve_callback, args, 
            &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            error_msg);
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        return AXIS2_FALSE;
    }
    axutil_thread_mutex_unlock(bean_mgr_impl->mutex);
    return (sandesha2_response_t *) args->data;
}

int
sandesha2_permanent_bean_mgr_busy_handler(
    sqlite3* dbconn,
    char *sql_stmt,
    int (*callback_func)(void *, int, char **, char **),
    void *args,
    char **error_msg,
    int rc)
{
    int counter = 0;
    printf("in busy handler1\n");
    while(rc == SQLITE_BUSY && counter < 512)
    {
        printf("in busy handler\n");
        if(*error_msg)
             sqlite3_free(*error_msg);
        counter++;
        /*AXIS2_SLEEP(SANDESHA2_BUSY_WAIT_TIME);*/
        AXIS2_USLEEP(100000);
        rc = sqlite3_exec(dbconn, sql_stmt, callback_func, args, error_msg);
    }
    printf("in busy handler2\n");
    return rc;
}


