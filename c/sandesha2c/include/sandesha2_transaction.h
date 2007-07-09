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

#ifndef SANDESHA2_TRANSACTION_H
#define SANDESHA2_TRANSACTION_H

/**
 * @file sandesha2_transaction.h
 * @brief Sandesha In Memory Transaction  Interface
 */

#include <axutil_allocator.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_transaction sandesha2_transaction_t;
typedef struct sandesha2_transaction_ops sandesha2_transaction_ops_t;
struct sandesha2_storage_mgr;
struct sandesha2_rm_bean;

/** @defgroup sandesha2_transaction In Memory Transaction 
  * @ingroup sandesha2
  * @{
  */

AXIS2_DECLARE_DATA struct sandesha2_transaction_ops
{
   /** 
     * Deallocate memory
     * @return status code
     */
    axis2_status_t (AXIS2_CALL *
            free) (
                sandesha2_transaction_t *transaction,
                const axutil_env_t *env);

    axis2_bool_t (AXIS2_CALL *
            is_active)(
                sandesha2_transaction_t *transaction,
                const axutil_env_t *env);
     
    void (AXIS2_CALL *
            commit) (
                sandesha2_transaction_t *transaction,
                const axutil_env_t *env);

    void (AXIS2_CALL *
            rollback) (
                sandesha2_transaction_t *transaction,
                const axutil_env_t *env);

    void (AXIS2_CALL *
            enlist)(
                sandesha2_transaction_t *trans,
                const axutil_env_t *env,
                struct sandesha2_rm_bean *rm_bean);
};

AXIS2_DECLARE_DATA struct sandesha2_transaction
{
    const sandesha2_transaction_ops_t *ops;
};

AXIS2_EXTERN sandesha2_transaction_t* AXIS2_CALL
sandesha2_transaction_create(
    const axutil_env_t *env,
    struct sandesha2_storage_mgr *storage_mgr);

axis2_status_t AXIS2_CALL 
sandesha2_transaction_free(
    sandesha2_transaction_t *transaction,
    const axutil_env_t *env);

axis2_bool_t AXIS2_CALL
sandesha2_transaction_is_active(
    sandesha2_transaction_t *transaction,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_transaction_commit(
    sandesha2_transaction_t *transaction,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_transaction_rollback(
    sandesha2_transaction_t *transaction,
    const axutil_env_t *env);

void AXIS2_CALL
sandesha2_transaction_enlist(
    sandesha2_transaction_t *trans,
    const axutil_env_t *env,
    struct sandesha2_rm_bean *rm_bean);

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* SANDESHA2_TRANSACTION_H */
