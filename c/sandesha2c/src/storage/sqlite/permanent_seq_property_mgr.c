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
 
#include <sandesha2_seq_property_mgr.h>
#include "sandesha2_permanent_seq_property_mgr.h"
#include "sandesha2_permanent_bean_mgr.h"
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_utils.h>
#include <sandesha2_storage_mgr.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_rm_bean.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>
#include <axutil_types.h>

/** 
 * @brief Sandesha Permanent Sequence Property Manager Struct Impl
 *   Sandesha Permanent Sequence Property Manager 
 */ 
typedef struct sandesha2_permanent_seq_property_mgr
{
    sandesha2_seq_property_mgr_t seq_prop_mgr;
    sandesha2_permanent_bean_mgr_t *bean_mgr;
    axutil_array_list_t *values;
} sandesha2_permanent_seq_property_mgr_t;

#define SANDESHA2_INTF_TO_IMPL(seq_property_mgr) \
    ((sandesha2_permanent_seq_property_mgr_t *) seq_property_mgr)

static int 
sandesha2_seq_property_find_callback(
    void *not_used, 
    int argc, 
    char **argv, 
    char **col_name)
{
    int i = 0;
    sandesha2_seq_property_bean_t *bean = NULL; 
    sandesha2_bean_mgr_args_t *args = (sandesha2_bean_mgr_args_t *) not_used;
    const axutil_env_t *env = args->env;
    axutil_array_list_t *data_list = (axutil_array_list_t *) args->data;
    if(argc < 1)
    {
        args->data = NULL;
        return 0;
    }
    if(!data_list)
    {
        data_list = axutil_array_list_create(env, 0);
        args->data = data_list;
    }
    bean = sandesha2_seq_property_bean_create(env);
    for(i = 0; i < argc; i++)
    {
        if(0 == axutil_strcmp(col_name[i], "seq_id"))
            sandesha2_seq_property_bean_set_seq_id(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "name"))
            if(argv[i])
                sandesha2_seq_property_bean_set_name(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "value"))
            if(argv[i])
                sandesha2_seq_property_bean_set_value(bean, env, argv[i]);
    }
    axutil_array_list_add(data_list, env, bean);
    return 0;
}

static int 
sandesha2_seq_property_retrieve_callback(
    void *not_used, 
    int argc, 
    char **argv, 
    char **col_name)
{
    int i = 0;
    sandesha2_bean_mgr_args_t *args = (sandesha2_bean_mgr_args_t *) not_used;
    const axutil_env_t *env = args->env;
    sandesha2_seq_property_bean_t *bean = NULL;
    if(argc < 1)
    {
        args->data = NULL;
        return 0;
    }
    bean = (sandesha2_seq_property_bean_t *) args->data;
    if(!bean)
    {
        bean = sandesha2_seq_property_bean_create(env);
        args->data = bean;
    }
    for(i = 0; i < argc; i++)
    {
        if(0 == axutil_strcmp(col_name[i], "seq_id"))
            sandesha2_seq_property_bean_set_seq_id(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "name"))
            if(argv[i])
                sandesha2_seq_property_bean_set_name(bean, env, argv[i]);
        if(0 == axutil_strcmp(col_name[i], "value"))
            if(argv[i])
                sandesha2_seq_property_bean_set_value(bean, env, argv[i]);
    }
    return 0;
}

static int 
sandesha2_seq_property_count_callback(
    void *not_used, 
    int argc, 
    char **argv, 
    char **col_name)
{
    int *count = (int *) not_used;
    *count = AXIS2_ATOI(argv[0]);
    return 0;
}


void AXIS2_CALL
sandesha2_permanent_seq_property_mgr_free(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_seq_property_mgr_insert(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_seq_property_mgr_remove(
        sandesha2_seq_property_mgr_t *seq_prop_mgr,
        const axutil_env_t *env,
        axis2_char_t *seq_id,
        axis2_char_t *name);

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_permanent_seq_property_mgr_retrieve(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name);

axis2_bool_t AXIS2_CALL
sandesha2_permanent_seq_property_mgr_update(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_seq_property_mgr_find(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_permanent_seq_property_mgr_find_unique(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

static axis2_bool_t AXIS2_CALL
sandesha2_permanent_seq_property_mgr_match(
    sandesha2_permanent_bean_mgr_t *seq_prop,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate);

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_seq_property_mgr_retrieve_all(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env);

static axis2_char_t *
sandesha2_permanent_seq_property_mgr_get_id_with_bean(
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean);

static axis2_char_t *
sandesha2_permanent_seq_property_mgr_get_id_with_seq_id_and_name(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name);

static const sandesha2_seq_property_mgr_ops_t seq_property_mgr_ops = 
{
    sandesha2_permanent_seq_property_mgr_free,
    sandesha2_permanent_seq_property_mgr_insert,
    sandesha2_permanent_seq_property_mgr_remove,
    sandesha2_permanent_seq_property_mgr_retrieve,
    sandesha2_permanent_seq_property_mgr_update,
    sandesha2_permanent_seq_property_mgr_find,
    sandesha2_permanent_seq_property_mgr_find_unique,
    sandesha2_permanent_seq_property_mgr_retrieve_all,
};

AXIS2_EXTERN sandesha2_seq_property_mgr_t * AXIS2_CALL
sandesha2_permanent_seq_property_mgr_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr,
    axis2_conf_ctx_t *ctx)
{
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    seq_prop_mgr_impl = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_permanent_seq_property_mgr_t));

    seq_prop_mgr_impl->values = NULL;
    seq_prop_mgr_impl->bean_mgr = sandesha2_permanent_bean_mgr_create(env,
        storage_mgr, ctx, SANDESHA2_BEAN_MAP_SEQ_PROPERTY);
    seq_prop_mgr_impl->bean_mgr->ops.match = sandesha2_permanent_seq_property_mgr_match;
    seq_prop_mgr_impl->seq_prop_mgr.ops = seq_property_mgr_ops;
    return &(seq_prop_mgr_impl->seq_prop_mgr);
}

void AXIS2_CALL
sandesha2_permanent_seq_property_mgr_free(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env)
{
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);

    if(seq_prop_mgr_impl->values)
    {
        axutil_array_list_free(seq_prop_mgr_impl->values, env);
        seq_prop_mgr_impl->values = NULL;
    }
    if(seq_prop_mgr_impl->bean_mgr)
    {
        sandesha2_permanent_bean_mgr_free(seq_prop_mgr_impl->bean_mgr, env);
        seq_prop_mgr_impl->bean_mgr = NULL;
    }
    if(seq_prop_mgr_impl)
    {
        AXIS2_FREE(env->allocator, seq_prop_mgr_impl);
        seq_prop_mgr_impl = NULL;
    }
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_seq_property_mgr_insert(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    axis2_char_t sql_insert[1024];
    axis2_char_t sql_update[1024];
    axis2_char_t sql_retrieve[256];
    axis2_bool_t ret = AXIS2_FALSE;
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;

    axis2_char_t *id = sandesha2_permanent_seq_property_mgr_get_id_with_bean(env, bean);
    axis2_char_t *seq_id = sandesha2_seq_property_bean_get_seq_id(bean, env);
    axis2_char_t *name = sandesha2_seq_property_bean_get_name(bean, env);
    axis2_char_t *value = sandesha2_seq_property_bean_get_value(bean, env);

    AXIS2_LOG_INFO(env->log, 
        "Entry:[sandesha2]sandesha2_permanent_seq_property_mgr_insert");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);

    sprintf(sql_retrieve, "select seq_id, name, value from seq_property "\
        "where id='%s'", id);
    sprintf(sql_update, "update seq_property set seq_id='%s', name='%s',"\
        "value='%s' where id='%s'", seq_id, name, value, id);
    sprintf(sql_insert, "insert into seq_property(id, seq_id, name, value) "\
        "values('%s', '%s', '%s', '%s')", id, seq_id, name, value);
    ret = sandesha2_permanent_bean_mgr_insert(seq_prop_mgr_impl->bean_mgr, env, 
        (sandesha2_rm_bean_t *) bean,  sandesha2_seq_property_retrieve_callback, 
        sql_retrieve, sql_update, sql_insert);
    AXIS2_LOG_INFO(env->log, 
        "Exit:[sandesha2]sandesha2_permanent_seq_property_mgr_insert:return%d", 
            ret);
    return ret;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_seq_property_mgr_remove(
        sandesha2_seq_property_mgr_t *seq_prop_mgr,
        const axutil_env_t *env,
        axis2_char_t *seq_id,
        axis2_char_t *name)
{
    axis2_char_t *key = NULL;
    axis2_char_t sql_remove[256];
    axis2_char_t sql_retrieve[256];
    axis2_status_t status = AXIS2_FAILURE;
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_permanent_seq_property_mgr_remove");

    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    key = sandesha2_permanent_seq_property_mgr_get_id_with_seq_id_and_name(env, 
        seq_id, name);
    sprintf(sql_remove, "delete from seq_property where id='%s'", key);
    sprintf(sql_retrieve, "select seq_id, name, value from seq_property "\
        "where id='%s'", key);
    status = sandesha2_permanent_bean_mgr_remove(seq_prop_mgr_impl->bean_mgr, env, 
        sandesha2_seq_property_retrieve_callback, sql_retrieve, sql_remove);
    AXIS2_FREE(env->allocator, key);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_seq_property_mgr_remove");
    return status;
}

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_permanent_seq_property_mgr_retrieve(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name)
{
    axis2_char_t *key = NULL;
    axis2_char_t sql_retrieve[256];
    sandesha2_seq_property_bean_t *ret = NULL;
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;

    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_permanent_seq_property_mgr_retrieve");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, seq_id, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, name, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    key = sandesha2_permanent_seq_property_mgr_get_id_with_seq_id_and_name(env, 
        seq_id, name);
    sprintf(sql_retrieve, "select seq_id, name, value from seq_property "\
        "where id='%s'", key);
    ret = (sandesha2_seq_property_bean_t *) sandesha2_permanent_bean_mgr_retrieve(
        seq_prop_mgr_impl->bean_mgr, env, sandesha2_seq_property_retrieve_callback, 
        sql_retrieve);
    AXIS2_FREE(env->allocator, key);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_seq_property_mgr_retrieve");
    return ret;
}

axis2_bool_t AXIS2_CALL
sandesha2_permanent_seq_property_mgr_update(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    axis2_char_t sql_update[1024];
    axis2_char_t sql_retrieve[256];
    axis2_bool_t ret = AXIS2_FALSE;
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;

    axis2_char_t *id = sandesha2_permanent_seq_property_mgr_get_id_with_bean(env, bean);
    axis2_char_t *seq_id = sandesha2_seq_property_bean_get_seq_id(bean, env);
    axis2_char_t *name = sandesha2_seq_property_bean_get_name(bean, env);
    axis2_char_t *value = sandesha2_seq_property_bean_get_value(bean, env);

    AXIS2_LOG_INFO(env->log, 
        "Entry:[sandesha2]sandesha2_permanent_seq_property_mgr_update");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);

    sprintf(sql_retrieve, "select seq_id, name, value from seq_property "\
        "where id='%s'", id);
    sprintf(sql_update, "update seq_property set seq_id='%s', name='%s',"\
        "value='%s' where id='%s'", seq_id, name, value, id);
    ret = sandesha2_permanent_bean_mgr_update(seq_prop_mgr_impl->bean_mgr, env, 
        (sandesha2_rm_bean_t *) bean, sandesha2_seq_property_retrieve_callback, 
        sql_retrieve, sql_update);
    AXIS2_LOG_INFO(env->log, 
        "Exit:[sandesha2]sandesha2_permanent_seq_property_mgr_update:return:%d", ret);
    return ret;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_seq_property_mgr_find(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    axis2_char_t *sql_find = NULL;
    axis2_char_t *sql_count = NULL;
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    axutil_array_list_t *ret = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_permanent_seq_property_mgr_find");
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    sql_find = "select seq_id, name,value from seq_property";
    sql_count = "select count(*) as no_recs from seq_property";
    ret = sandesha2_permanent_bean_mgr_find(seq_prop_mgr_impl->bean_mgr, env, 
        (sandesha2_rm_bean_t *) bean, sandesha2_seq_property_find_callback,
        sandesha2_seq_property_count_callback, sql_find, sql_count);
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_seq_property_mgr_find");
    return ret;
}

sandesha2_seq_property_bean_t *AXIS2_CALL
sandesha2_permanent_seq_property_mgr_find_unique(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    axis2_char_t *sql_find = NULL;
    axis2_char_t *sql_count = NULL;
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    AXIS2_PARAM_CHECK(env->error, bean, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    sql_find = "select seq_id, name,value from seq_property";
    sql_count = "select count(*) as no_recs from seq_property";
    return (sandesha2_seq_property_bean_t *) 
        sandesha2_permanent_bean_mgr_find_unique(seq_prop_mgr_impl->bean_mgr, 
        env, (sandesha2_rm_bean_t *) bean, sandesha2_seq_property_find_callback,
        sandesha2_seq_property_count_callback, sql_find, sql_count);
}

static axis2_bool_t AXIS2_CALL
sandesha2_permanent_seq_property_mgr_match(
    sandesha2_permanent_bean_mgr_t *seq_prop_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *bean,
    sandesha2_rm_bean_t *candidate)
{
    axis2_bool_t equal = AXIS2_TRUE;
    axis2_char_t *seq_id = NULL;
    axis2_char_t *temp_seq_id = NULL;
    axis2_char_t *name = NULL;
    axis2_char_t *temp_name = NULL;
    axis2_char_t *value = NULL;
    axis2_char_t *temp_value = NULL;
    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Entry:sandesha2_permanent_seq_property_mgr_match");
    seq_id = sandesha2_seq_property_bean_get_seq_id(
        (sandesha2_seq_property_bean_t *) bean, env);
    temp_seq_id = sandesha2_seq_property_bean_get_seq_id(
        (sandesha2_seq_property_bean_t *) candidate, env);
    if(seq_id && temp_seq_id && 0 != axutil_strcmp(seq_id, temp_seq_id))
    {
        equal = AXIS2_FALSE;
    }
    name = sandesha2_seq_property_bean_get_name(
        (sandesha2_seq_property_bean_t *) bean, env);
    temp_name = sandesha2_seq_property_bean_get_name(
        (sandesha2_seq_property_bean_t *) candidate, env);
    if(name && temp_name && 0 != axutil_strcmp(name, temp_name))
    {
        equal = AXIS2_FALSE;
    }
    value = sandesha2_seq_property_bean_get_value(
        (sandesha2_seq_property_bean_t *) bean, env);
    temp_value = sandesha2_seq_property_bean_get_value(
        (sandesha2_seq_property_bean_t *) candidate, env);
    if(value && temp_value && 0 != axutil_strcmp(value, temp_value))
    {
        equal = AXIS2_FALSE;
    }
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_permanent_seq_property_mgr_match:equal:%d", 
            equal);
    return equal;
}

axutil_array_list_t *AXIS2_CALL
sandesha2_permanent_seq_property_mgr_retrieve_all(
    sandesha2_seq_property_mgr_t *seq_prop_mgr,
    const axutil_env_t *env)
{
    sandesha2_permanent_seq_property_mgr_t *seq_prop_mgr_impl = NULL;
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);
    seq_prop_mgr_impl = SANDESHA2_INTF_TO_IMPL(seq_prop_mgr);
    return sandesha2_seq_property_mgr_find(seq_prop_mgr, env, NULL);
}

static axis2_char_t *
sandesha2_permanent_seq_property_mgr_get_id_with_seq_id_and_name(
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axis2_char_t *name)
{
    axis2_char_t *id = NULL;

    id = axutil_strcat(env, seq_id, ":", name, NULL);
    return id;
}

static axis2_char_t *
sandesha2_permanent_seq_property_mgr_get_id_with_bean(
    const axutil_env_t *env,
    sandesha2_seq_property_bean_t *bean)
{
    axis2_char_t *seq_id = NULL;
    axis2_char_t *name = NULL;
    axis2_char_t *id = NULL;

    seq_id = sandesha2_seq_property_bean_get_seq_id(bean, env);
    name = sandesha2_seq_property_bean_get_name(bean, env);
    id = axutil_strcat(env, seq_id, ":", name, NULL);

    return id;
}

