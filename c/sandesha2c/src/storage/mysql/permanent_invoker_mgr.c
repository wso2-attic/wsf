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
 
#include "sandesha2_permanent_invoker_mgr.h"
#include "sandesha2_permanent_bean_mgr.h"
#include <sandesha2_invoker_mgr.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>
#include <axutil_types.h>

/** 
 * @brief Sandesha2 Permanent Invoker Manager Struct Impl
 *   Sandesha2 Permanent Invoker Manager 
 */ 
typedef struct sandesha2_permanent_invoker_mgr
{
    sandesha2_invoker_mgr_t invoker_mgr;
    sandesha2_permanent_bean_mgr_t *bean_mgr;
}sandesha2_permanent_invoker_mgr_t;

#define SANDESHA2_INTF_TO_IMPL(invoker_mgr) \
    ((sandesha2_permanent_invoker_mgr_t *) invoker_mgr)

static int 
sandesha2_invoker_find_callback(
    MYSQL_RES *res,
    void *data)
{
    MYSQL_ROW row;
    int num_rows, i = 0;
    sandesha2_invoker_bean_t *bean = NULL;
    sandesha2_bean_mgr_args_t *args = (sandesha2_bean_mgr_args_t *) data;
    const axutil_env_t *env = args->env;
    axutil_array_list_t *data_list = (axutil_array_list_t *) args->data;
    num_rows = mysql_num_rows(res);
    if(num_rows > 0)
    {
        if(!data_list)
        {
            data_list = axutil_array_list_create(env, 0);
            args->data = data_list;
        }
    }
    else
    {
        args->data = NULL;
        return 0;
    }
    for(i = 0; i < num_rows; i++)
    {
        if((row = mysql_fetch_row(res)) != NULL)
        {
            unsigned long *lengths = NULL;
            lengths = mysql_fetch_lengths(res);
            bean = sandesha2_invoker_bean_create(env);
            if(0 < (int) lengths[0])
                sandesha2_invoker_bean_set_msg_ctx_ref_key(bean, env, row[0]);
            if(0 < (int) lengths[1])
                sandesha2_invoker_bean_set_msg_no(bean, env, atol(row[1]));
            if(0 < (int) lengths[2])
                sandesha2_invoker_bean_set_seq_id(bean, env, row[2]);
            if(0 < (int) lengths[3])
                sandesha2_invoker_bean_set_invoked(bean, env, AXIS2_ATOI(row[3]));
            axutil_array_list_add(data_list, env, bean);
        }
    }
    return 0;
}

static int 
sandesha2_invoker_retrieve_callback(
    MYSQL_RES *res,
    void *data)
{
    MYSQL_ROW row;
    sandesha2_bean_mgr_args_t *args = (sandesha2_bean_mgr_args_t *) data;
    const axutil_env_t *env = args->env;
    sandesha2_invoker_bean_t *bean = (sandesha2_invoker_bean_t *) args->data;
    if((row = mysql_fetch_row(res)) != NULL)
    {
        unsigned long *lengths = NULL;
        lengths = mysql_fetch_lengths(res);
        if(!bean)
        {
            bean = sandesha2_invoker_bean_create(env);
            args->data = bean;
        }
        if(0 < (int) lengths[0])
            sandesha2_invoker_bean_set_msg_ctx_ref_key(bean, env, row[0]);
        if(0 < (int) lengths[1])
            sandesha2_invoker_bean_set_msg_no(bean, env, atol(row[1]));
        if(0 < (int) lengths[2])
            sandesha2_invoker_bean_set_seq_id(bean, env, row[2]);
        if(0 < (int) lengths[3])
            sandesha2_invoker_bean_set_invoked(bean, env, AXIS2_ATOI(row[3]));
    }
    else
    {
        args->data = NULL;
    }
    return 0;
}

static int 
sandesha2_invoker_count_callback(
    MYSQL_RES *res,
    void *data)
{
    MYSQL_ROW row;
    int *count = (int *) data;
    if((row = mysql_fetch_row(res)) != NULL)
        *count = AXIS2_ATOI(row[0]);
    return 0;
}

void AXIS2_CALL
sandesha2_permanent_invoker_mgr_free(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_invoker_mgr_insert(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_invoker_mgr_remove(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    axis2_char_t *key);

sandesha2_invoker_bean_t *AXIS2_CALL
sandesha2_permanent_invoker_mgr_retrieve(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    axis2_char_t *key);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_invoker_mgr_update(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean);

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_invoker_mgr_find(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean);

sandesha2_invoker_bean_t *AXIS2_CALL
sandesha2_permanent_invoker_mgr_find_unique(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_create_invoker_mgr_match(
    sandesha2_permanent_bean_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate);

static const sandesha2_invoker_mgr_ops_t invoker_mgr_ops = 
{
    sandesha2_permanent_invoker_mgr_free,
    sandesha2_permanent_invoker_mgr_insert,
    sandesha2_permanent_invoker_mgr_remove,
    sandesha2_permanent_invoker_mgr_retrieve,
    sandesha2_permanent_invoker_mgr_update,
    sandesha2_permanent_invoker_mgr_find,
    sandesha2_permanent_invoker_mgr_find_unique
};

AXIS2_EXTERN sandesha2_invoker_mgr_t * AXIS2_CALL
sandesha2_permanent_invoker_mgr_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr,
    axis2_conf_ctx_t *ctx)
{
    sandesha2_permanent_invoker_mgr_t *invoker_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    invoker_mgr_impl = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_permanent_invoker_mgr_t));
    invoker_mgr_impl->bean_mgr = sandesha2_permanent_bean_mgr_create(env,
        storage_mgr, ctx, SANDESHA2_BEAN_MAP_STORAGE_MAP);
    invoker_mgr_impl->bean_mgr->ops.match = 
        sandesha2_permanent_create_invoker_mgr_match;
    invoker_mgr_impl->invoker_mgr.ops = invoker_mgr_ops;

    return &(invoker_mgr_impl->invoker_mgr);
}

void AXIS2_CALL
sandesha2_permanent_invoker_mgr_free(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env)
{
    sandesha2_permanent_invoker_mgr_t *invoker_mgr_impl = NULL;
    invoker_mgr_impl = SANDESHA2_INTF_TO_IMPL(invoker_mgr);
    if(invoker_mgr_impl->bean_mgr)
    {
        sandesha2_permanent_bean_mgr_free(invoker_mgr_impl->bean_mgr, env);
        invoker_mgr_impl->bean_mgr = NULL;
    }
    if(invoker_mgr_impl)
    {
        AXIS2_FREE(env->allocator, invoker_mgr_impl);
        invoker_mgr_impl = NULL;
    }
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_invoker_mgr_insert(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean)
{
    axis2_char_t sql_insert[1024];
    axis2_char_t sql_retrieve[256];
    axis2_char_t sql_update[1024];
    axis2_bool_t ret = AXIS2_FALSE;
    sandesha2_permanent_invoker_mgr_t *invoker_mgr_impl = NULL;

    axis2_char_t *msg_ctx_ref_key = sandesha2_invoker_bean_get_msg_ctx_ref_key(
        (sandesha2_rm_bean_t *) bean, env);
    long msg_no = sandesha2_invoker_bean_get_msg_no(bean, env);
    axis2_char_t *seq_id = sandesha2_invoker_bean_get_seq_id(bean, env);
    axis2_bool_t is_invoked = sandesha2_invoker_bean_is_invoked(bean, env);

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    invoker_mgr_impl = SANDESHA2_INTF_TO_IMPL(invoker_mgr);

    sprintf(sql_retrieve, "select msg_ctx_ref_key, msg_no, "\
        "seq_id, is_invoked from invoker where msg_ctx_ref_key='%s'", 
        msg_ctx_ref_key);
    sprintf(sql_update, "update invoker set msg_no=%ld, seq_id='%s',"\
        "is_invoked=%d where msg_ctx_ref_key='%s';", msg_no, seq_id, is_invoked, 
        msg_ctx_ref_key);
    sprintf(sql_insert, "insert into invoker(msg_ctx_ref_key, msg_no, seq_id,"\
        "is_invoked) values('%s', %ld, '%s', %d);", msg_ctx_ref_key, msg_no, 
        seq_id, is_invoked);
    ret = sandesha2_permanent_bean_mgr_insert(invoker_mgr_impl->bean_mgr, env,
        (sandesha2_rm_bean_t *) bean, sandesha2_invoker_retrieve_callback, 
        sql_retrieve, sql_update, sql_insert);
    return ret;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_invoker_mgr_remove(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    axis2_char_t sql_remove[256];
    axis2_char_t sql_retrieve[256];
    sandesha2_permanent_invoker_mgr_t *invoker_mgr_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, key, AXIS2_FALSE);
    invoker_mgr_impl = SANDESHA2_INTF_TO_IMPL(invoker_mgr);
    sprintf(sql_remove, "delete from invoker where msg_ctx_ref_key='%s';", key);
    sprintf(sql_retrieve, "select msg_ctx_ref_key, msg_no, seq_id, is_invoked"\
        " from invoker where msg_ctx_ref_key='%s'", key);
    return sandesha2_permanent_bean_mgr_remove(invoker_mgr_impl->bean_mgr, env, 
        sandesha2_invoker_retrieve_callback, sql_retrieve, sql_remove);
}

sandesha2_invoker_bean_t *AXIS2_CALL
sandesha2_permanent_invoker_mgr_retrieve(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
    axis2_char_t sql_retrieve[256];
    sandesha2_invoker_bean_t *bean = NULL;
    sandesha2_permanent_invoker_mgr_t *invoker_mgr_impl = NULL;
    AXIS2_PARAM_CHECK(env->error, key, AXIS2_FALSE);
    invoker_mgr_impl = SANDESHA2_INTF_TO_IMPL(invoker_mgr);
    sprintf(sql_retrieve, "select msg_ctx_ref_key, msg_no, seq_id, is_invoked"\
        " from invoker where msg_ctx_ref_key='%s'", key);
    sandesha2_permanent_bean_mgr_retrieve(invoker_mgr_impl->bean_mgr, env, 
        sandesha2_invoker_retrieve_callback, sql_retrieve);
    return bean;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_invoker_mgr_update(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean)
{
    /*axis2_char_t *ref_key = NULL;*/
    axis2_char_t *sql_update = NULL;
    axis2_char_t *sql_retrieve = NULL;
    axis2_bool_t ret = AXIS2_FALSE;
    sandesha2_permanent_invoker_mgr_t *invoker_mgr_impl = NULL;

    axis2_char_t *msg_ctx_ref_key = sandesha2_invoker_bean_get_msg_ctx_ref_key(
        (sandesha2_rm_bean_t *) bean, env);
    long msg_no = sandesha2_invoker_bean_get_msg_no(bean, env);
    axis2_char_t *seq_id = sandesha2_invoker_bean_get_seq_id(bean, env);
    axis2_bool_t is_invoked = sandesha2_invoker_bean_is_invoked(bean, env);

    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    invoker_mgr_impl = SANDESHA2_INTF_TO_IMPL(invoker_mgr);

    sprintf(sql_retrieve, "select msg_ctx_ref_key, msg_no, "\
        "seq_id, is_invoked from invoker where msg_ctx_ref_key='%s'", 
        msg_ctx_ref_key);
    sprintf(sql_update, "update invoker set msg_no=%ld, seq_id='%s',"\
        "is_invoked=%d where msg_ctx_ref_key='%s';", msg_no, seq_id, is_invoked, 
        msg_ctx_ref_key);
    ret = sandesha2_permanent_bean_mgr_update(invoker_mgr_impl->bean_mgr, env, 
        (sandesha2_rm_bean_t *)bean, sandesha2_invoker_retrieve_callback, 
        sql_retrieve, sql_update);

    return ret;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_invoker_mgr_find(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean)
{
    axis2_char_t *sql_find = NULL;
    axis2_char_t *sql_count = NULL;
    axutil_array_list_t *ret = NULL;
    sandesha2_permanent_invoker_mgr_t *invoker_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    invoker_mgr_impl = SANDESHA2_INTF_TO_IMPL(invoker_mgr);
    sql_find = "select msg_ctx_ref_key,msg_no, seq_id,is_invoked from invoker;";
    sql_count = "select count(*) as no_recs from invoker;";
    ret = sandesha2_permanent_bean_mgr_find(invoker_mgr_impl->bean_mgr, env, 
        (sandesha2_rm_bean_t *) bean, sandesha2_invoker_find_callback,
        sandesha2_invoker_count_callback, sql_find, sql_count);
    return ret;
}

sandesha2_invoker_bean_t *AXIS2_CALL
sandesha2_permanent_invoker_mgr_find_unique(
    sandesha2_invoker_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_invoker_bean_t *bean)
{
    axis2_char_t *sql_find = NULL;
    axis2_char_t *sql_count = NULL;
    sandesha2_permanent_invoker_mgr_t *invoker_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    invoker_mgr_impl = SANDESHA2_INTF_TO_IMPL(invoker_mgr);
    sql_find = "select msg_ctx_ref_key,msg_no,seq_id,is_invoked from invoker;";
    sql_count = "select count(*) as no_recs from invoker;";
    return (sandesha2_invoker_bean_t *) sandesha2_permanent_bean_mgr_find_unique(
        invoker_mgr_impl->bean_mgr, env, (sandesha2_rm_bean_t *) bean, 
        sandesha2_invoker_find_callback, sandesha2_invoker_count_callback, 
        sql_find, sql_count);
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_create_invoker_mgr_match(
    sandesha2_permanent_bean_mgr_t *invoker_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate)
{
    axis2_bool_t select = AXIS2_TRUE;
    axis2_char_t *ref_key = NULL;
    axis2_char_t *temp_ref_key = NULL;
    axis2_char_t *seq_id = NULL;
    axis2_char_t *temp_seq_id = NULL;
    long msg_no = 0;
    long temp_msg_no = 0;
    axis2_bool_t is_invoked = AXIS2_FALSE;
    axis2_bool_t temp_is_invoked = AXIS2_FALSE;
    
    ref_key = sandesha2_invoker_bean_get_msg_ctx_ref_key(bean, env);
    temp_ref_key = sandesha2_invoker_bean_get_msg_ctx_ref_key(candidate, env);
    if(ref_key && temp_ref_key && 0 != axutil_strcmp(ref_key, temp_ref_key))
    {
        select = AXIS2_FALSE;
    }
    seq_id = sandesha2_invoker_bean_get_seq_id(
        (sandesha2_invoker_bean_t *) bean, env);
    temp_seq_id = sandesha2_invoker_bean_get_seq_id(
        (sandesha2_invoker_bean_t *) candidate, env);
    if(seq_id && temp_seq_id && 0 != axutil_strcmp(seq_id, temp_seq_id))
    {
        select = AXIS2_FALSE;
    }
    msg_no = sandesha2_invoker_bean_get_msg_no(
        (sandesha2_invoker_bean_t *) bean, env);
    temp_msg_no = sandesha2_invoker_bean_get_msg_no(
        (sandesha2_invoker_bean_t *) candidate, env);
    if(msg_no != 0 && (msg_no != temp_msg_no))
    {
        select = AXIS2_FALSE;
    }
    is_invoked = sandesha2_invoker_bean_is_invoked(
        (sandesha2_invoker_bean_t *) bean, env);
    temp_is_invoked = sandesha2_invoker_bean_is_invoked(
        (sandesha2_invoker_bean_t *) candidate, env);
    if(is_invoked != temp_is_invoked)
    {
        select = AXIS2_FALSE;
    }
    return select;
}

