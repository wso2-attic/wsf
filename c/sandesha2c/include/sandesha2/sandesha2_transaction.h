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
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axis2_conf_ctx.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup sandesha2_transaction
 * @{
 */
 
 typedef struct sandesha2_transaction_ops sandesha2_transaction_ops_t;
 typedef struct sandesha2_transaction sandesha2_transaction_t;
 /**
 * @brief Sandesha2 Transaction ops struct
 * Encapsulator struct for ops of sandesha2_transaction
 */
AXIS2_DECLARE_DATA struct sandesha2_transaction_ops
{
    
    axis2_status_t (AXIS2_CALL *
        commit) 
            (sandesha2_transaction_t *transaction,
            const axutil_env_t *env);
            
    axis2_status_t (AXIS2_CALL *
        rollback) 
            (sandesha2_transaction_t *transaction,
            const axutil_env_t *env);
            
    axis2_status_t (AXIS2_CALL *
        free) 
            (sandesha2_transaction_t *transaction,
            const axutil_env_t *env);
};

/**
 * @brief sandesha2_transaction_ops
 *    sandesha2_transaction_ops
 */
AXIS2_DECLARE_DATA struct sandesha2_transaction
{
    sandesha2_transaction_ops_t *ops;
};

AXIS2_EXTERN sandesha2_transaction_t* AXIS2_CALL
sandesha2_transaction_create(
						const axutil_env_t *env);
                        
/************************** Start of function macros **************************/
#define sandesha2_transaction_free(transaction, env) \
    ((transaction)->ops->free (transaction, env))
    
#define sandesha2_transaction_commit(transaction, env) \
    ((transaction)->ops->commit(transaction, env))
    
#define sandesha2_transaction_rollback(transaction, env) \
    ((transaction)->ops->rollback(transaction, env))
/************************** End of function macros ****************************/

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SANDESHA2_TRANSACTION_H*/
