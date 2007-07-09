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
 
#include <sandesha2_storage_mgr.h>
#include <sandesha2_create_seq_mgr.h>
#include <sandesha2_invoker_mgr.h>
#include <sandesha2_next_msg_mgr.h>
#include <sandesha2_sender_mgr.h>
#include <sandesha2_seq_property_mgr.h>
#include <sandesha2_transaction.h>
#include <sandesha2_constants.h>
#include <sandesha2_error.h>
#include <sandesha2_utils.h>
#include <sandesha2_rm_bean.h>
#include <axutil_log.h>
#include <axutil_hash.h>
#include <axutil_thread.h>
#include <axutil_property.h>
#include <axis2_msg_ctx.h>
#include <axutil_uuid_gen.h>
#include <axis2_conf_ctx.h>

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_free_void_arg(
    void *storage_mgr,
    const axutil_env_t *env)
{
     return ((sandesha2_storage_mgr_t *) storage_mgr)->ops->free_void_arg(
         storage_mgr, env);
}

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_free(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env)
{
     return storage_mgr->ops->free(storage_mgr, env);
}

sandesha2_transaction_t *AXIS2_CALL
sandesha2_storage_mgr_get_transaction(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env)
{
     return storage_mgr->ops->get_transaction(storage_mgr, env);
}

void AXIS2_CALL
sandesha2_storage_mgr_enlist_bean(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    sandesha2_rm_bean_t *rm_bean)
{
     storage_mgr->ops->enlist_bean(storage_mgr, env, rm_bean); 
}

sandesha2_create_seq_mgr_t *AXIS2_CALL
sandesha2_storage_mgr_get_create_seq_mgr(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env)
{
     return storage_mgr->ops->get_create_seq_mgr(storage_mgr, env);
}

sandesha2_next_msg_mgr_t *AXIS2_CALL
sandesha2_storage_mgr_get_next_msg_mgr(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env)
{
     return storage_mgr->ops->get_next_msg_mgr(storage_mgr, env);
}

sandesha2_sender_mgr_t *AXIS2_CALL
sandesha2_storage_mgr_get_retrans_mgr(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env)
{
     return storage_mgr->ops->get_retrans_mgr(storage_mgr, env);
}

sandesha2_seq_property_mgr_t *AXIS2_CALL
sandesha2_storage_mgr_get_seq_property_mgr(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env)
{
     return storage_mgr->ops->get_seq_property_mgr(storage_mgr, env);
}

sandesha2_invoker_mgr_t *AXIS2_CALL
sandesha2_storage_mgr_get_storage_map_mgr(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env)
{
     return storage_mgr->ops->get_storage_map_mgr(storage_mgr, env);
}

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_set_ctx(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
     return storage_mgr->ops->set_ctx(storage_mgr, env, conf_ctx);
}

axis2_conf_ctx_t *AXIS2_CALL
sandesha2_storage_mgr_get_ctx(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env)
{
     return storage_mgr->ops->get_ctx(storage_mgr, env);
}

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_init(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx)
{
     return storage_mgr->ops->init(storage_mgr, env, conf_ctx);
}

axis2_msg_ctx_t *AXIS2_CALL
sandesha2_storage_mgr_retrieve_msg_ctx(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    axis2_conf_ctx_t *conf_ctx,
    const axis2_bool_t persistent)
{
     return storage_mgr->ops->retrieve_msg_ctx(storage_mgr, env, key, conf_ctx, 
         persistent);
}
		
axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_store_msg_ctx(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    axis2_msg_ctx_t *msg_ctx)
{
     return storage_mgr->ops->store_msg_ctx(storage_mgr, env, key, msg_ctx);
}
			
axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_update_msg_ctx(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_char_t *key,
    axis2_msg_ctx_t *msg_ctx)
{
     return storage_mgr->ops->update_msg_ctx(storage_mgr, env, key, msg_ctx);
}

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_remove_msg_ctx(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
     return storage_mgr->ops->remove_msg_ctx(storage_mgr, env, key);
}

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_init_storage(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_module_desc_t *module_desc)
{
     return storage_mgr->ops->init_storage(storage_mgr, env, module_desc);
}

axiom_soap_envelope_t *AXIS2_CALL
sandesha2_storage_mgr_retrieve_soap_envelope(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_char_t *key)
{
     return storage_mgr->ops->retrieve_soap_envelope(storage_mgr, env, key); 
}

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_store_soap_envelope(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axiom_soap_envelope_t *soap_env,
    axis2_char_t *key)
{
     return storage_mgr->ops->store_soap_envelope(storage_mgr, env, soap_env, key);
}

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_store_response(
    sandesha2_storage_mgr_t *storage_mgr,
    const axutil_env_t *env,
    axis2_char_t *seq_id,
    axiom_soap_envelope_t *response,
    int msg_no,
    int soap_version)
{
     return storage_mgr->ops->store_response(storage_mgr, env, seq_id, response, 
         msg_no, soap_version);
}

axiom_soap_envelope_t * AXIS2_CALL
sandesha2_storage_mgr_retrieve_response(
    sandesha2_storage_mgr_t *storage_mgr, 
    const axutil_env_t *env, 
    axis2_char_t *seq_id,
    int msg_no)
{
     return storage_mgr->ops->retrieve_response(storage_mgr, env, seq_id, 
         msg_no);
}

axis2_status_t AXIS2_CALL
sandesha2_storage_mgr_remove_response(
    sandesha2_storage_mgr_t *storage_mgr, 
    const axutil_env_t *env, 
    axis2_char_t *seq_id,
    int msg_no)
{
     return storage_mgr->ops->remove_response(storage_mgr, env, seq_id, msg_no);
}
