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
 
#include <sandesha2_inmemory_transaction.h>
#include <sandesha2_transaction.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_rm_bean.h>
#include <sandesha2_storage_mgr.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>
#include <platforms/axutil_platform_auto_sense.h>

typedef struct sandesha2_inmemory_transaction_impl 
    sandesha2_inmemory_transaction_impl_t;

/** 
 * @brief Sandesha Inmemory Transaction Struct Impl
 *   Sandesha2 Inmemory Transaction 
 */ 
struct sandesha2_inmemory_transaction_impl
{
    sandesha2_transaction_t trans;
    sandesha2_storage_mgr_t *storage_mgr;
    axutil_array_list_t *enlisted_beans;
    axutil_thread_mutex_t *mutex;
};

#define SANDESHA2_INTF_TO_IMPL(trans) \
    ((sandesha2_inmemory_transaction_impl_t *) trans)

axis2_status_t AXIS2_CALL
sandesha2_inmemory_transaction_free(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_transaction_is_active(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_inmemory_transaction_commit(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_inmemory_transaction_rollback(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_inmemory_transaction_enlist(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *rm_bean);

static void 
sandesha2_inmemory_transaction_release_locks(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env);

static const sandesha2_transaction_ops_t transaction_ops = 
{
    sandesha2_inmemory_transaction_free,
    sandesha2_inmemory_transaction_is_active,
    sandesha2_inmemory_transaction_commit,
    sandesha2_inmemory_transaction_rollback,
    sandesha2_inmemory_transaction_enlist
};

AXIS2_EXTERN sandesha2_transaction_t* AXIS2_CALL
sandesha2_inmemory_transaction_create(
    const axutil_env_t *env,
    sandesha2_storage_mgr_t *storage_mgr)
{
    sandesha2_inmemory_transaction_impl_t *trans_impl = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    
    trans_impl =  (sandesha2_inmemory_transaction_impl_t *)AXIS2_MALLOC 
        (env->allocator, sizeof(sandesha2_inmemory_transaction_impl_t));

    trans_impl->storage_mgr = storage_mgr;
    trans_impl->enlisted_beans = axutil_array_list_create(env, 0);
    trans_impl->mutex = axutil_thread_mutex_create(env->allocator,
        AXIS2_THREAD_MUTEX_DEFAULT);
    trans_impl->trans.ops = &transaction_ops;

    return &(trans_impl->trans);
}

axis2_status_t AXIS2_CALL
sandesha2_inmemory_transaction_free(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_inmemory_transaction_impl_t *trans_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);

    if(trans_impl->mutex)
    {
        axutil_thread_mutex_destroy(trans_impl->mutex);
        trans_impl->mutex = NULL;
    } 
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

axis2_bool_t AXIS2_CALL
sandesha2_inmemory_transaction_is_active(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    int size = 0;
    sandesha2_inmemory_transaction_impl_t *trans_impl = NULL;
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    if(trans_impl->enlisted_beans)
        size = axutil_array_list_size(trans_impl->enlisted_beans, env);
    if(size > 0)
        return AXIS2_TRUE;
    else
        return AXIS2_FALSE;
}

void AXIS2_CALL
sandesha2_inmemory_transaction_commit(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_inmemory_transaction_release_locks(trans, env);
}

void AXIS2_CALL
sandesha2_inmemory_transaction_rollback(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_inmemory_transaction_release_locks(trans, env);
}

static void 
sandesha2_inmemory_transaction_release_locks(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    sandesha2_inmemory_transaction_impl_t *trans_impl = NULL;
    int i = 0, size = 0;
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    if(trans_impl->enlisted_beans)
        size = axutil_array_list_size(trans_impl->enlisted_beans, env);
    for(i = 0; i < size; i++)
    {
        sandesha2_rm_bean_t *rm_bean_l = NULL;
        sandesha2_rm_bean_t *rm_bean = (sandesha2_rm_bean_t *) 
            axutil_array_list_get(trans_impl->enlisted_beans, env, i);
        rm_bean_l = sandesha2_rm_bean_get_base(rm_bean, env);
        axutil_thread_mutex_lock(trans_impl->mutex);
        sandesha2_rm_bean_set_transaction(rm_bean_l, env, NULL);
        axutil_thread_mutex_unlock(trans_impl->mutex);
    }
    axutil_array_list_free(trans_impl->enlisted_beans, env);
    trans_impl->enlisted_beans = NULL;
}
   
void AXIS2_CALL
sandesha2_inmemory_transaction_enlist(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *rm_bean)
{
    sandesha2_rm_bean_t *rm_bean_l = NULL;
    sandesha2_inmemory_transaction_impl_t *trans_impl = NULL;
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Start:sandesha2_inmemory_transaction_enlist");
    trans_impl = SANDESHA2_INTF_TO_IMPL(trans);
    rm_bean_l = sandesha2_rm_bean_get_base(rm_bean, env);
    if(rm_bean)
    {
        sandesha2_transaction_t *other = NULL;
        axutil_thread_mutex_lock(trans_impl->mutex);
        other = sandesha2_rm_bean_get_transaction(rm_bean_l, env);
        /*while(other && other != trans)
        {
            int size = 0;
            if(trans_impl->enlisted_beans)
                size = axutil_array_list_size(trans_impl->enlisted_beans, env);
            AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "size:%d", size);
            if(size > 0)
            {
                AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Possible deadlock");
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_POSSIBLE_DEADLOCK, 
                    AXIS2_FAILURE);
            }
            AXIS2_SLEEP(6);
            other = sandesha2_rm_bean_get_transaction(rm_bean_l, env);
        }*/
        if(!other)
        {
            sandesha2_rm_bean_set_transaction(rm_bean_l, env, trans);
            axutil_array_list_add(trans_impl->enlisted_beans, env, rm_bean);
        }   
        axutil_thread_mutex_unlock(trans_impl->mutex);
    }    
    AXIS2_LOG_INFO(env->log, 
        "[sandesha2]Exit:sandesha2_inmemory_transaction_enlist");
}

