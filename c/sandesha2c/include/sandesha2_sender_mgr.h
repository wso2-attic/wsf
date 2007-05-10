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

#ifndef SANDESHA2_SENDER_MGR_H
#define SANDESHA2_SENDER_MGR_H

/**
 * @file sandesha2_sender_mgr.h
 * @brief Sandesha Inmemory Sender Manager Interface
 */

#include <axutil_allocator.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_utils.h>
#include <axis2_ctx.h>
#include <axutil_array_list.h>
#include <sandesha2_sender_bean.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct sandesha2_sender_mgr sandesha2_sender_mgr_t;
typedef struct sandesha2_sender_mgr_ops sandesha2_sender_mgr_ops_t;

/** @defgroup sandesha2_sender_mgr In Memory Sender Manager
  * @ingroup sandesha2
  * @{
  */
AXIS2_DECLARE_DATA struct sandesha2_sender_mgr_ops
{
   /** 
     * Deallocate memory
     * @return status code
     */
    void (AXIS2_CALL * 
            free)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env);

    axis2_bool_t (AXIS2_CALL *
            insert)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env,
                sandesha2_sender_bean_t *bean);

    axis2_bool_t (AXIS2_CALL *
            remove)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env,
                axis2_char_t *msg_id);

    sandesha2_sender_bean_t *(AXIS2_CALL *
            retrieve)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env,
                axis2_char_t *msg_id);

    axis2_bool_t (AXIS2_CALL *
            update)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env,
                sandesha2_sender_bean_t *bean);

    axutil_array_list_t *(AXIS2_CALL *
            find_by_internal_seq_id)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env,
                axis2_char_t *internal_seq_id);

    axutil_array_list_t *(AXIS2_CALL *
            find_by_sender_bean)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env,
                sandesha2_sender_bean_t *bean);

    sandesha2_sender_bean_t *(AXIS2_CALL *
            find_unique)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env,
                sandesha2_sender_bean_t *bean);

    sandesha2_sender_bean_t *(AXIS2_CALL *
            get_next_msg_to_send)(
                sandesha2_sender_mgr_t *sender,
                const axutil_env_t *env,
                const axis2_char_t *seq_id);
};

AXIS2_DECLARE_DATA struct sandesha2_sender_mgr
{
    sandesha2_sender_mgr_ops_t ops;
};

AXIS2_EXTERN sandesha2_sender_mgr_t * AXIS2_CALL
sandesha2_sender_mgr_create(
    const axutil_env_t *env,
    axis2_ctx_t *ctx);

void AXIS2_CALL 
sandesha2_sender_mgr_free(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *envv);

axis2_bool_t AXIS2_CALL
sandesha2_sender_mgr_insert(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean);

axis2_bool_t AXIS2_CALL
sandesha2_sender_mgr_remove(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    axis2_char_t *msg_id);

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_sender_mgr_retrieve(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    axis2_char_t *msg_id);

axis2_bool_t AXIS2_CALL
sandesha2_sender_mgr_update(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean);

axutil_array_list_t *AXIS2_CALL
sandesha2_sender_mgr_find_by_internal_seq_id(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id);

axutil_array_list_t *AXIS2_CALL
sandesha2_sender_mgr_find_by_sender_bean(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean);

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_sender_mgr_find_unique(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    sandesha2_sender_bean_t *bean);

sandesha2_sender_bean_t *AXIS2_CALL
sandesha2_sender_mgr_get_next_msg_to_send(
    sandesha2_sender_mgr_t *sender,
    const axutil_env_t *env,
    const axis2_char_t *seq_id);

/** @} */
#ifdef __cplusplus
}
#endif
#endif /* SANDESHA2_SENDER_MGR_H */
