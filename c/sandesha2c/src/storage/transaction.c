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

axis2_status_t AXIS2_CALL 
sandesha2_transaction_free(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    return trans->ops->free (trans, env);
}

axis2_bool_t AXIS2_CALL
sandesha2_transaction_is_active(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    return trans->ops->is_active(trans, env);
}

void AXIS2_CALL
sandesha2_transaction_commit(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    trans->ops->commit(trans, env);
}

void AXIS2_CALL
sandesha2_transaction_rollback(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env)
{
    trans->ops->rollback(trans, env);
}

void AXIS2_CALL
sandesha2_transaction_enlist(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *rm_bean)
{
    trans->ops->enlist(trans, env, rm_bean);
}

