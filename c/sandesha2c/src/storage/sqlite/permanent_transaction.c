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
 
#include "sandesha2_permanent_transaction.h"
#include "sandesha2_permanent_storage_mgr.h"
#include <sandesha2_transaction.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_rm_bean.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_property_bean.h>
#include <sandesha2_utils.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>
#include <axis2_module_desc.h>
#include "sandesha2_permanent_bean_mgr.h"
#include <platforms/axutil_platform_auto_sense.h>
#include <sqlite3.h>

typedef struct sandesha2_permanent_transaction_impl 
    sandesha2_permanent_transaction_impl_t;

/** 
 * @brief Sandesha Permanent Transaction Struct Impl
 *   Sandesha2 Permanent Transaction 
 */ 
struct sandesha2_permanent_transaction_impl
{
    sandesha2_transaction_t trans;
    sandesha2_storage_mgr_t *storage_mgr;
    axutil_array_list_t *enlisted_beans;
    axutil_thread_mutex_t *mutex;
    sqlite3 *dbconn;
    axis2_bool_t is_active;
    unsigned long int thread_id;
};

#define SANDESHA2_INTF_TO_IMPL(trans) \
    ((sandesha2_permanent_transaction_impl_t *) trans)

axis2_status_t AXIS2_CALL
sandesha2_permanent_transaction_free(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_permanent_transaction_commit(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_permanent_transaction_rollback(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_permanent_transaction_enlist(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *rm_bean);

void AXIS2_CALL
sandesha2_permanent_transaction_release_locks(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

static const sandesha2_transaction_ops_t transaction_ops = 
{
    sandesha2_permanent_transaction_free,
    sandesha2_permanent_transaction_is_active,
    sandesha2_permanent_transaction_commit,
    sandesha2_permanent_transaction_rollback,
    sandesha2_permanent_transaction_enlist
};

AXIS2_EXTERN sandesha2_transaction_t* AXIS2_CALL
sandesha2_permanent_transaction_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr,
    unsigned long int thread_id)
{
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;
    axis2_char_t *error_msg = NULL;
    axis2_char_t *path = NULL;
    axis2_char_t *db_name = NULL;
    int rc = -1;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    sandesha2_property_bean_t *prop_bean = NULL;
    axis2_ctx_t *conf_ctx_base = NULL; 
    axutil_property_t *property = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    
    trans_impl =  (sandesha2_permanent_transaction_impl_t *)AXIS2_MALLOC 
        (env->allocator, sizeof(sandesha2_permanent_transaction_impl_t));

    trans_impl->mutex = sandesha2_permanent_storage_mgr_get_mutex(storage_mgr, env);
    trans_impl->storage_mgr = storage_mgr;
    trans_impl->thread_id = thread_id;
    trans_impl->dbconn = NULL;
    trans_impl->enlisted_beans = axutil_array_list_create(env, 0);
    trans_impl->trans.ops = &transaction_ops;
	conf_ctx = (axis2_conf_ctx_t *) sandesha2_storage_mgr_get_ctx(
        storage_mgr, env);
    if(conf_ctx)
        conf = axis2_conf_ctx_get_conf((const axis2_conf_ctx_t *) conf_ctx, env);
    else
    {
        return NULL;
    }
    prop_bean = (sandesha2_property_bean_t *)sandesha2_utils_get_property_bean(
        env, conf);
    /*path = sandesha2_property_bean_get_db_path(prop_bean, env);*/
    {
        axis2_module_desc_t *module_desc = NULL;
        axutil_qname_t *qname = NULL;
        qname = axutil_qname_create(env, "sandesha2", NULL, NULL);
        module_desc = axis2_conf_get_module(conf, env, qname);
        if(module_desc)
        {
            axutil_param_t *db_param = NULL;
            db_param = axis2_module_desc_get_param(module_desc, env, SANDESHA2_DB);
            if(db_param)
            {
                path = (axis2_char_t *) axutil_param_get_value(db_param, env);
            }
        }
        axutil_qname_free(qname, env);
    }
    conf_ctx_base = axis2_conf_ctx_get_base(conf_ctx, env);
    property = axis2_ctx_get_property(conf_ctx_base, env, 
        SANDESHA2_IS_SVR_SIDE);
    if(!property)
    {
        db_name = axutil_strcat(env, path, AXIS2_PATH_SEP_STR, 
            "sandesha2_svr_db", NULL);
    }
    else
    {
        db_name = axutil_strcat(env, path, AXIS2_PATH_SEP_STR, 
            "sandesha2_client_db", NULL);
    }
    rc = sqlite3_open(db_name, &(trans_impl->dbconn));
    if(rc != SQLITE_OK)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Can't open database: %s"
            " sqlite error: %s\n", db_name, sqlite3_errmsg(trans_impl->dbconn));
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_CANNOT_OPEN_DATABASE, 
            AXIS2_FAILURE);
        sqlite3_close(trans_impl->dbconn);
        return NULL;
    }
    rc = sqlite3_exec(trans_impl->dbconn, "BEGIN TRANSACTION;", 0, 0,
        &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(trans_impl->dbconn, 
            "BEGIN TRANSACTION", 0, 0, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "SQL Error %s",
            error_msg);
        printf("transaction begin error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
        sandesha2_transaction_free(&(trans_impl->trans), env);
        return NULL;
    }
    trans_impl->is_active = AXIS2_TRUE;
    return &(trans_impl->trans);
}

axis2_status_t AXIS2_CALL
sandesha2_permanent_transaction_free(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);

    if(trans_impl->enlisted_beans)
    {
        axutil_array_list_free(trans_impl->enlisted_beans, env);
        trans_impl->enlisted_beans = NULL;
    }
    if(trans_impl)
    {
        AXIS2_FREE(env->allocator, trans_impl);
        trans_impl = NULL;
    }
    return AXIS2_SUCCESS;
}

sqlite3 *AXIS2_CALL
sandesha2_permanent_transaction_get_dbconn(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    return trans_impl->dbconn;
}

unsigned long int AXIS2_CALL
sandesha2_permanent_transaction_get_thread_id(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    return trans_impl->thread_id;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_transaction_is_active(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    return trans_impl->is_active;

}

 void AXIS2_CALL
sandesha2_permanent_transaction_commit(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
   
    axutil_thread_mutex_lock(trans_impl->mutex);
    rc = sqlite3_exec(trans_impl->dbconn, "COMMIT TRANSACTION;", 0, 0, &error_msg);
    if(rc == SQLITE_BUSY)
    {
        rc = sandesha2_permanent_bean_mgr_busy_handler(trans_impl->dbconn, 
            "COMMIT TRANSACTION", 0, 0, &error_msg, rc);
    }
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(trans_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            error_msg);
        printf("commit error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
    }
    sqlite3_close(trans_impl->dbconn);
    trans_impl->is_active = AXIS2_FALSE;
    sandesha2_permanent_transaction_release_locks(trans, env);
    axutil_thread_mutex_unlock(trans_impl->mutex);
}

void AXIS2_CALL
sandesha2_permanent_transaction_rollback(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    axis2_char_t *error_msg = NULL;
    int rc = -1;
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    axutil_thread_mutex_lock(trans_impl->mutex);
    rc = sqlite3_exec(trans_impl->dbconn, "ROLLBACK TRANSACTION;", 0, 0,
        &error_msg);
    if(rc == SQLITE_BUSY)
        rc = sandesha2_permanent_bean_mgr_busy_handler(trans_impl->dbconn, 
            "ROLLBACK TRANSACTION", 0, 0, &error_msg, rc);
    if(rc != SQLITE_OK )
    {
        axutil_thread_mutex_unlock(trans_impl->mutex);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            error_msg);
        printf("sql_stmt_rollback:%s\n", "ROLLBACK TRANSACTION;");
        printf("rollback error_msg:%s\n", error_msg);
        sqlite3_free(error_msg);
    }
    sqlite3_close(trans_impl->dbconn);
    trans_impl->is_active = AXIS2_FALSE;
    sandesha2_permanent_transaction_release_locks(trans, env);
    axutil_thread_mutex_unlock(trans_impl->mutex);
}

void AXIS2_CALL
sandesha2_permanent_transaction_release_locks(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;
    int i = 0, size = 0;
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    
	sandesha2_permanent_storage_mgr_remove_transaction(trans_impl->storage_mgr, 
        env, trans);
    if(trans_impl->enlisted_beans)
        size = axutil_array_list_size(trans_impl->enlisted_beans, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_rm_bean_t *rm_bean_l = NULL;
        sandesha2_rm_bean_t *rm_bean = (sandesha2_rm_bean_t *) 
            axutil_array_list_get(trans_impl->enlisted_beans, env, i);
        rm_bean_l = sandesha2_rm_bean_get_base(rm_bean, env);
        sandesha2_rm_bean_set_transaction(rm_bean_l, env, NULL);
    }
    /*axutil_array_list_free(trans_impl->enlisted_beans, env);
    trans_impl->enlisted_beans = NULL;*/
}
   
void AXIS2_CALL
sandesha2_permanent_transaction_enlist(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *rm_bean)
{
    sandesha2_rm_bean_t *rm_bean_l = NULL;
    unsigned long int thread_id = -1;
    sandesha2_permanent_transaction_impl_t *trans_impl = NULL;
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2]Start:sandesha2_permanent_transaction_enlist");
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    rm_bean_l = sandesha2_rm_bean_get_base(rm_bean, env);
    thread_id = trans_impl->thread_id;
    if(rm_bean)
    {
        sandesha2_transaction_t *other = NULL;
        unsigned long int other_thread_id = -1;
        axutil_thread_mutex_lock(trans_impl->mutex);
        other = sandesha2_rm_bean_get_transaction(rm_bean_l, env);
        if(other)
            other_thread_id = sandesha2_permanent_transaction_get_thread_id(other, 
                env);
        while(other && other_thread_id != thread_id)
        {
            int size = 0;
            if(trans_impl->enlisted_beans)
                size = axutil_array_list_size(trans_impl->enlisted_beans, env);
            if(size > 0)
            {
                AXIS2_LOG_WARNING(env->log, AXIS2_LOG_SI, "Possible deadlock");
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_POSSIBLE_DEADLOCK, 
                    AXIS2_FAILURE);
            }
            AXIS2_SLEEP(6);
            other = sandesha2_rm_bean_get_transaction(rm_bean_l, env);
            if(other)
                other_thread_id = sandesha2_permanent_transaction_get_thread_id(
                other, env);
        }
        if(!other)
        {
            sandesha2_rm_bean_set_transaction(rm_bean_l, env, trans);
            axutil_array_list_add(trans_impl->enlisted_beans, env, rm_bean);
        }   
        axutil_thread_mutex_unlock(trans_impl->mutex);
    }    
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,  
        "[sandesha2] Exit:sandesha2_permanent_transaction_enlist");
}

