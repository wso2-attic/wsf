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

/** 
 * @brief Sandesha2 Permanent Bean Manager Struct Impl
 *   Sandesha2 Permanent Bean Manager
 */
typedef struct sandesha2_permanent_bean_mgr_impl
{
    sandesha2_permanent_bean_mgr_t bean_mgr;
    sandesha2_storage_mgr_t *storage_mgr;

}sandesha2_permanent_bean_mgr_impl_t;

#define SANDESHA2_INTF_TO_IMPL(bean_mgr) \
    ((sandesha2_permanent_bean_mgr_impl_t *) bean_mgr)

static int 
sandesha2_permanent_bean_mgr_count_callback(
    MYSQL_RES *res,
    void *data)
{
    MYSQL_ROW row;
    int *count = (int *) data;
    if((row = mysql_fetch_row(res)) != NULL)
        *count = AXIS2_ATOI(row[0]);
    return 0;
}

static int 
sandesha2_permanent_bean_mgr_response_retrieve_callback(
    MYSQL_RES *res,
    void *data)
{
    MYSQL_ROW row;
    sandesha2_response_t *response = NULL;
    sandesha2_bean_mgr_args_t *args = (sandesha2_bean_mgr_args_t *) data;
    const axutil_env_t *env = args->env;
    response = (sandesha2_response_t *) args->data;
    if((row = mysql_fetch_row(res)) != NULL)
    {
        if(!response)
        {
            response = (sandesha2_response_t *) AXIS2_MALLOC(env->allocator, 
                sizeof(sandesha2_response_t));
            args->data = response;
        }
        response->response_str = axutil_strdup(env, row[1]);
        response->soap_version = axutil_atoi(row[3]);
    }
    else
    {
        args->data = NULL;
    }
    return 0;
}


static int 
sandesha2_msg_store_bean_retrieve_callback(
    MYSQL_RES *res,
    void *data)
{
    MYSQL_ROW row;
    sandesha2_bean_mgr_args_t *args = (sandesha2_bean_mgr_args_t *) data;
    const axutil_env_t *env = args->env;
    sandesha2_msg_store_bean_t *bean = NULL;
    bean = (sandesha2_msg_store_bean_t *) args->data;
    if((row = mysql_fetch_row(res)) != NULL)
    {
        unsigned long *lengths = NULL;
        if(!bean)
        {
            bean = sandesha2_msg_store_bean_create(env);
            args->data = bean;
        }
        lengths = mysql_fetch_lengths(res);
        if(0 < (int) lengths[0])
            sandesha2_msg_store_bean_set_stored_key(bean, env, row[0]);
        if(0 < (int) lengths[1])
            sandesha2_msg_store_bean_set_msg_id(bean, env, row[1]);
        if(0 < (int) lengths[2])
            sandesha2_msg_store_bean_set_soap_envelope_str(bean, env, row[2]);
        sandesha2_msg_store_bean_set_soap_version(bean, env, AXIS2_ATOI(row[3]));
        sandesha2_msg_store_bean_set_transport_out(bean, env, AXIS2_ATOI(row[4]));
        if(0 < (int) lengths[5])
            sandesha2_msg_store_bean_set_op(bean, env, row[5]);
        if(0 < (int) lengths[6])
            sandesha2_msg_store_bean_set_svc(bean, env, row[6]);
        if(0 < (int) lengths[7])
            sandesha2_msg_store_bean_set_svc_grp(bean, env, row[7]);
        if(0 < (int) lengths[8])
            sandesha2_msg_store_bean_set_op_mep(bean, env, row[8]);
        if(0 < (int) lengths[9])
            sandesha2_msg_store_bean_set_to_url(bean, env, row[9]);
        if(0 < (int) lengths[10])
            sandesha2_msg_store_bean_set_reply_to(bean, env, row[10]);
        if(0 < (int) lengths[11])
            sandesha2_msg_store_bean_set_transport_to(bean, env, row[11]);
        if(0 < (int) lengths[12])
            sandesha2_msg_store_bean_set_execution_chain_str(bean, env, row[12]);
        sandesha2_msg_store_bean_set_flow(bean, env, AXIS2_ATOI(row[13]));
        if(0 < (int) lengths[14])
            sandesha2_msg_store_bean_set_msg_recv_str(bean, env, row[14]);
        sandesha2_msg_store_bean_set_svr_side(bean, env, AXIS2_ATOI(row[15]));
        if(0 < (int) lengths[16])
            sandesha2_msg_store_bean_set_in_msg_store_key(bean, env, row[16]);
        if(0 < (int) lengths[17])
            sandesha2_msg_store_bean_set_persistent_property_str(bean, env, row[17]);
        if(0 < (int) lengths[18])
            sandesha2_msg_store_bean_set_action(bean, env, row[18]);

    }
    else
    {
        args->data = NULL;
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
    return &(bean_mgr_impl->bean_mgr);
}

void AXIS2_CALL
sandesha2_permanent_bean_mgr_free(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);

    if(bean_mgr_impl)
    {
        AXIS2_FREE(env->allocator, bean_mgr_impl);
        bean_mgr_impl = NULL;
    }
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_insert(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    int (*retrieve_func)(MYSQL_RES *, void *),
    axis2_char_t *sql_stmt_retrieve,
    axis2_char_t *sql_stmt_update,
    axis2_char_t *sql_stmt_insert)
{
    int rc = -1;
    MYSQL *dbconn = NULL;
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    
    sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return AXIS2_FALSE;
    }
    rc = mysql_query(dbconn, sql_stmt_insert);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql stmt: %s. sql error: %s", 
            sql_stmt_insert, mysql_error(dbconn));
        printf("sql_stmt_insert:%s\n", sql_stmt_insert);
        printf("insert error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    return AXIS2_TRUE;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_remove(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    int (*retrieve_func)(MYSQL_RES *, void *),
    axis2_char_t *sql_stmt_retrieve,
    axis2_char_t *sql_stmt_remove)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    MYSQL *dbconn = NULL;
    int rc = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return AXIS2_FALSE;
    }
    rc = mysql_query(dbconn, sql_stmt_remove);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql stmt: %s. sql error: %s",
            sql_stmt_remove, mysql_error(dbconn));
        printf("sql_stmt_remove:%s\n", sql_stmt_remove);
        printf("remove error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    return AXIS2_TRUE;
}

sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_retrieve(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    int (*retrieve_func)(MYSQL_RES *, void *),
    axis2_char_t *sql_stmt_retrieve)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_bean_mgr_args_t *args = NULL;
    sandesha2_rm_bean_t *bean = NULL;
    MYSQL *dbconn = NULL;
    MYSQL_RES *res;
    int rc = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return NULL;
    }
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    rc = mysql_query(dbconn, sql_stmt_retrieve);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql stmt: %s. sql error: %s",
            sql_stmt_retrieve, mysql_error(dbconn));
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    res = mysql_store_result(dbconn);
    if(res)
    {
        retrieve_func(res, args);
        /* mysql_free_result(res); */
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql stmt: %s. sql error: %s",
            sql_stmt_retrieve, mysql_error(dbconn));
        printf("retrieve error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    if(args->data)
        bean = (sandesha2_rm_bean_t *) args->data;
    if(args)
        AXIS2_FREE(env->allocator, args);
    return bean;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_bean_mgr_update(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    int (*retrieve_func)(MYSQL_RES *, void *),
    axis2_char_t *sql_stmt_retrieve_old_bean,
    axis2_char_t *sql_stmt_update)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    MYSQL *dbconn = NULL;
    int rc = -1;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    if(bean)
        sandesha2_storage_mgr_enlist_bean(bean_mgr_impl->storage_mgr, env, bean);
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return AXIS2_FALSE;
    }
    rc = mysql_query(dbconn, sql_stmt_update);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
            mysql_error(dbconn));
        printf("sql_stmt_update:%s\n", sql_stmt_update);
        printf("update error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    return AXIS2_TRUE;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_find(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    int (*find_func)(MYSQL_RES *, void *),
    int (*count_func)(MYSQL_RES *, void *),
    axis2_char_t *sql_stmt_find,
    axis2_char_t *sql_stmt_count)
{
    sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    sandesha2_bean_mgr_args_t *args = NULL;
    axutil_array_list_t *beans = NULL;
    int i = 0, size = 0, rc = -1;
    MYSQL *dbconn = NULL;
    MYSQL_RES *res;
    axutil_array_list_t *data_array = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    beans = axutil_array_list_create(env, 0);
    if(!beans)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return NULL;
    }
    rc = mysql_query(dbconn, sql_stmt_find);
    if(rc)
    {
        if(data_array)
            axutil_array_list_free(data_array, env);
        if(args)
            AXIS2_FREE(env->allocator, args);
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
            mysql_error(dbconn));
        printf("sql_stmt_find:%s\n", sql_stmt_find);
        printf("retrieve error_msg:%s\n", mysql_error(dbconn));
        return NULL;
    }
    res = mysql_store_result(dbconn);
    find_func(res, args);
    /* mysql_free_result(res); */
    if(args->data)
    {
        data_array = (axutil_array_list_t *) args->data;
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
    /* Finally remove any beans that are no longer in the table */
    size = axutil_array_list_size(beans, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_rm_bean_t *temp = axutil_array_list_get(beans, env, i);
        if(temp)
        {
            int count = -1;

            rc = mysql_query(dbconn, sql_stmt_count);
            if(rc)
            {
                AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
                    mysql_error(dbconn));
                printf("sql_stmt_count:%s\n", sql_stmt_count);
                printf("retrieve error_msg:%s\n", mysql_error(dbconn));
                return NULL;
            }
            res = mysql_store_result(dbconn);
            count_func(res, &count);
            /* mysql_free_result(res); */
            if(count == 0)
            {
                axutil_array_list_remove(beans, env, i);
            }
        }
    }
    return beans;
}

sandesha2_rm_bean_t *AXIS2_CALL
sandesha2_permanent_bean_mgr_find_unique(
    sandesha2_permanent_bean_mgr_t *bean_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    int (*find_func)(MYSQL_RES *, void *),
    int (*count_func)(MYSQL_RES *, void *),
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
    sandesha2_msg_store_bean_t *msg_store_bean = NULL;
    int rc = -1;
    MYSQL *dbconn = NULL;
    MYSQL_RES *res;
    axis2_char_t sql_stmt_retrieve[512];
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return NULL;
    }
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    sprintf(sql_stmt_retrieve, "select stored_key, msg_id, soap_env_str,"\
        "soap_version, transport_out, op, svc, svc_grp, op_mep, to_url, reply_to,"\
        "transport_to, execution_chain_str, flow, msg_recv_str, svr_side, "\
        "in_msg_store_key, prop_str, action from msg where stored_key='%s'", 
        key);
    rc = mysql_query(dbconn, sql_stmt_retrieve);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            mysql_error(dbconn));
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    res = mysql_store_result(dbconn);
    sandesha2_msg_store_bean_retrieve_callback(res, args);
    /* mysql_free_result(res); */
    if(args->data)
        msg_store_bean = (sandesha2_msg_store_bean_t *) args->data;
    if(args)
        AXIS2_FREE(env->allocator, args);
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
    int rc = -1;
    int sql_size = -1;
    MYSQL *dbconn = NULL;
    MYSQL_RES *res;
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
    int num_rows = -1;
	axis2_char_t *msg_recv_str = NULL;
	axis2_bool_t svr_side = AXIS2_FALSE;
	axis2_char_t *in_msg_store_key = NULL;
	axis2_char_t *prop_str = NULL;
	axis2_char_t *action = NULL;

	bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
	msg_id = sandesha2_msg_store_bean_get_msg_id(bean, env);
    if(!msg_id) msg_id = "";
	stored_key = sandesha2_msg_store_bean_get_stored_key(bean, env);
    if(!stored_key) stored_key = "";
	soap_env_str =  sandesha2_msg_store_bean_get_soap_envelope_str(bean, env);
    if(!soap_env_str) soap_env_str = "";
	soap_version = sandesha2_msg_store_bean_get_soap_version(bean, env);
	transport_out = sandesha2_msg_store_bean_get_transport_out(bean, env);
	op = sandesha2_msg_store_bean_get_op(bean, env);
    if(!op) op = "";
    svc = sandesha2_msg_store_bean_get_svc(bean, env);
    if(!svc) svc = "";
	svc_grp = sandesha2_msg_store_bean_get_svc_grp(bean, env);
    if(!svc_grp) svc_grp = "";
    op_mep = sandesha2_msg_store_bean_get_op_mep(bean, env);;
    if(!op_mep) op_mep = "";
    to_url = sandesha2_msg_store_bean_get_to_url(bean, env);
    if(!to_url) to_url = "";
	reply_to = sandesha2_msg_store_bean_get_reply_to(bean, env);
    if(!reply_to) reply_to = "";
	transport_to = sandesha2_msg_store_bean_get_transport_to(bean, env);
    if(!transport_to) transport_to = "";
	execution_chain_str = sandesha2_msg_store_bean_get_execution_chain_str(bean, env);
    if(!execution_chain_str) execution_chain_str = "";
	flow = sandesha2_msg_store_bean_get_flow(bean, env);
	msg_recv_str = sandesha2_msg_store_bean_get_msg_recv_str(bean, env);
    if(!msg_recv_str) msg_recv_str = "";
    svr_side = sandesha2_msg_store_bean_is_svr_side(bean, env);
	in_msg_store_key = sandesha2_msg_store_bean_get_in_msg_store_key(bean, env);
    if(!in_msg_store_key) in_msg_store_key = "";
	prop_str = sandesha2_msg_store_bean_get_persistent_property_str(bean, env);
    if(!prop_str) prop_str = "";
	action = sandesha2_msg_store_bean_get_action(bean, env);
    if(!action) action = "";

    sql_size = axutil_strlen(msg_id) + axutil_strlen(stored_key) + 
        axutil_strlen(soap_env_str) + sizeof(int) + sizeof(int) + 
        axutil_strlen(op) + axutil_strlen(svc) + axutil_strlen(svc_grp) + 
        axutil_strlen(op_mep) + axutil_strlen(to_url) + axutil_strlen(reply_to) +
        axutil_strlen(transport_to) + axutil_strlen(execution_chain_str) + sizeof(int) + 
        axutil_strlen(msg_recv_str) + sizeof(int) + axutil_strlen(in_msg_store_key) +
        axutil_strlen(prop_str) + axutil_strlen(action) + 512;

    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return AXIS2_FALSE;
    }

    sprintf(sql_stmt_retrieve, "select stored_key, msg_id, soap_env_str,"\
        "soap_version, transport_out, op, svc, svc_grp, op_mep, to_url, reply_to, "\
        "transport_to, execution_chain_str, flow, msg_recv_str, svr_side, "\
        "in_msg_store_key, prop_str, action from msg where stored_key = '%s'", 
        key);
    rc = mysql_query(dbconn, sql_stmt_retrieve);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            mysql_error(dbconn));
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    res = mysql_store_result(dbconn);
    num_rows = mysql_num_rows(res);
    /* mysql_free_result(res); */
    if(num_rows > 0)
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
        rc = mysql_query(dbconn, sql_stmt_update);
        if(rc)
        {
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, 
                AXIS2_FAILURE);
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
                mysql_error(dbconn));
            printf("sql_stmt_update:%s\n", sql_stmt_update);
            printf("update error_msg:%s\n", mysql_error(dbconn));
            AXIS2_FREE(env->allocator, sql_stmt_update);
            return AXIS2_FALSE;
        }
        AXIS2_FREE(env->allocator, sql_stmt_update);
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
    rc = mysql_query(dbconn, sql_stmt_insert);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", mysql_error(dbconn));
        printf("sql_stmt_insert:%s\n", sql_stmt_insert);
        printf("insert error_msg:%s\n", mysql_error(dbconn));
        AXIS2_FREE(env->allocator, sql_stmt_insert);
        return AXIS2_FALSE;
    }
    AXIS2_FREE(env->allocator, sql_stmt_insert);
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
    int rc = -1;
    MYSQL *dbconn = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return AXIS2_FALSE;
    }
    sprintf(sql_stmt_remove, "delete from msg where stored_key='%s'", key);
    rc = mysql_query(dbconn, sql_stmt_remove);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            mysql_error(dbconn));
        printf("sql_stmt_remove:%s\n", sql_stmt_remove);
        printf("remove error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
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
    int rc = -1;
    int sql_size = -1;
    MYSQL *dbconn = NULL;
    MYSQL_RES *res;
	sandesha2_permanent_bean_mgr_impl_t *bean_mgr_impl = NULL;
    int count = -1;

	bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    sql_size = axutil_strlen(seq_id) + axutil_strlen(response) + 
        sizeof(int) + sizeof(int) + 512;
    sprintf(sql_stmt_count, "select count(seq_id)"\
        " from response where seq_id = '%s' and msg_no=%d", seq_id, msg_no);

    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return AXIS2_FALSE;
    }
    rc = mysql_query(dbconn, sql_stmt_count);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
            mysql_error(dbconn));
        printf("sql_stmt_count:%s\n", sql_stmt_count);
        printf("retrieve error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    res = mysql_store_result(dbconn);
    sandesha2_permanent_bean_mgr_count_callback(res, &count);
    /* mysql_free_result(res); */
    if(count > 0)
    {
        sql_stmt_update = AXIS2_MALLOC(env->allocator, sql_size);
        sprintf(sql_stmt_update, "update response set response_str='%s',"\
            "soap_version=%d where seq_id='%s' and msg_no=%d", response, 
            soap_version, seq_id, msg_no);
        rc = mysql_query(dbconn, sql_stmt_update);
        if(rc)
        {
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, 
                AXIS2_FAILURE);
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", 
                mysql_error(dbconn));
            printf("sql_stmt_update:%s\n", sql_stmt_update);
            printf("update error_msg:%s\n", mysql_error(dbconn));
            AXIS2_FREE(env->allocator, sql_stmt_update);
            return AXIS2_FALSE;
        }
        AXIS2_FREE(env->allocator, sql_stmt_update);
        return AXIS2_TRUE;
    }
    else
    {
        sql_stmt_insert = AXIS2_MALLOC(env->allocator, sql_size);
        sprintf(sql_stmt_insert, "insert into response(seq_id, response_str,"\
            "msg_no, soap_version) values('%s', '%s', %d, %d)", seq_id, 
            response, msg_no, soap_version);
        rc = mysql_query(dbconn, sql_stmt_insert);
        if(rc)
        {
            AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s", mysql_error(dbconn));
            printf("sql_stmt_insert:%s\n", sql_stmt_insert);
            printf("insert error_msg:%s\n", mysql_error(dbconn));
            AXIS2_FREE(env->allocator, sql_stmt_insert);
            return AXIS2_FALSE;
        }
        AXIS2_FREE(env->allocator, sql_stmt_insert);
    }
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
    int rc = -1;
    MYSQL *dbconn = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return AXIS2_FALSE;
    }
    sprintf(sql_stmt_remove, 
        "delete from response where seq_id='%s' and msg_no=%d", seq_id, msg_no);
    rc = mysql_query(dbconn, sql_stmt_remove);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            mysql_error(dbconn));
        printf("sql_stmt_remove:%s\n", sql_stmt_remove);
        printf("remove error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
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
    int rc = -1;
    MYSQL *dbconn = NULL;
    MYSQL_RES *res;
    axis2_char_t sql_stmt_retrieve[512];
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    bean_mgr_impl = SANDESHA2_INTF_TO_IMPL(bean_mgr);
    dbconn = (MYSQL *) sandesha2_permanent_storage_mgr_get_dbconn(
        bean_mgr_impl->storage_mgr, env);
    if(!dbconn)
    {
        return NULL;
    }
    args = AXIS2_MALLOC(env->allocator, sizeof(sandesha2_bean_mgr_args_t));
    args->env = (axutil_env_t*)env;
    args->data = NULL;
    sprintf(sql_stmt_retrieve, "select response_str, soap_version from response"\
        " where seq_id='%s' and msg_no=%d", seq_id, msg_no);
    rc = mysql_query(dbconn, sql_stmt_retrieve);
    if(rc)
    {
        AXIS2_ERROR_SET(env->error, SANDESHA2_ERROR_SQL_ERROR, AXIS2_FAILURE);
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "sql error %s",
            mysql_error(dbconn));
        printf("sql_stmt_retrieve:%s\n", sql_stmt_retrieve);
        printf("retrieve error_msg:%s\n", mysql_error(dbconn));
        return AXIS2_FALSE;
    }
    res = mysql_store_result(dbconn);
    sandesha2_permanent_bean_mgr_response_retrieve_callback(res, args);
    /* mysql_free_result(res); */
    return (sandesha2_response_t *) args->data;
}

