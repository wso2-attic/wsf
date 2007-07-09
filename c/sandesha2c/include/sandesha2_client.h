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

#ifndef SANDESHA2_CLIENT_H
#define SANDESHA2_CLIENT_H

/**
 * @file sandesha2_client.h
 * @brief Sandesha Client Interface
 */

#include <axutil_allocator.h>
#include <axutil_env.h>
#include <axutil_error.h>
#include <axutil_string.h>
#include <axutil_utils.h>
#include <axutil_hash.h>
#include <axutil_uri.h>
#include <axutil_array_list.h>
#include <axis2_svc_client.h>
#include <axis2_callback.h>
#include <axis2_listener_manager.h>

#include <sandesha2_seq_report.h>
#include <sandesha2_report.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_client Client
  * @ingroup sandesha2
  * @{
  */
AXIS2_EXTERN sandesha2_seq_report_t *AXIS2_CALL
sandesha2_client_get_outgoing_seq_report_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client);

AXIS2_EXTERN sandesha2_seq_report_t *AXIS2_CALL
sandesha2_client_get_outgoing_seq_report_with_seq_key(
    const axutil_env_t *env,
    axis2_char_t *to,
    axis2_char_t *seq_key,
    axis2_conf_ctx_t *conf_ctx);

AXIS2_EXTERN sandesha2_seq_report_t *AXIS2_CALL
sandesha2_client_get_outgoing_seq_report_with_internal_seq_id(
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id,
    axis2_conf_ctx_t *conf_ctx);

/**
 * Users can get a list of seq_reports each describing a incoming
 * sequence, which are the sequences the client work as a RMD.
 * Caller must free the returned array.
 * 
 * @param config_ctx
 * @return
 */
AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
sandesha2_client_get_incoming_seq_reports(
    axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx);

/**
 * sandesha2_report gives the details of all incoming and outgoing sequences.
 * The outgoing sequence have to pass the initial state (CS/CSR exchange) to
 * be included in a sandesha2_report
 * 
 * @param conf_ctx
 * @return
 */
AXIS2_EXTERN sandesha2_report_t *AXIS2_CALL
sandesha2_client_get_report(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_create_seq_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_bool_t offer);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_create_seq_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_bool_t offer,
    axis2_char_t *seq_key);

/**
 * User can terminate the sequence defined by the passed svc_client.
 * 
 * @param svc_client
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_terminate_seq_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_callback_t *callback,
    axis2_listener_manager_t *listener_manager);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_terminate_seq_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_char_t *seq_key);

/**
 * User can close the seq defined by the passed svc_client.
 * 
 * @param svc_client
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_close_seq_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_close_seq_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_char_t *seq_key);

/**
 * This blocks the system until the messages sent have been completed.
 * 
 * @param svc_client
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_wait_until_seq_completed_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_wait_until_seq_completed_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_char_t *seq_key);

/**
 * This blocks the system until the messages sent have been completed
 * or until the given time interval exceeds. (the time is taken in seconds)
 * 
 * @param svc_client
 * @param max_waiting_time
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_wait_until_seq_completed_with_svc_client_and_max_waiting_time(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    long max_waiting_time);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_wait_until_seq_completed_with_svc_client_and_max_waiting_time_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    long max_waiting_time,
    axis2_char_t *seq_key);

/* 
 * gives the out seqID if CS/CSR exchange is done. Otherwise an error
 */
AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_client_get_seq_id(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_send_ack_request_with_svc_client(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_send_ack_request_with_svc_client_and_seq_key(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_char_t *seq_key);

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_client_send_non_blocking(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_options_t *options,
    axutil_qname_t *op_qname,
    axis2_callback_t *callback,
    axiom_node_t *payload,
    axis2_listener_manager_t *listener_manager);

AXIS2_EXTERN void AXIS2_CALL
sandesha2_client_fire_and_forget(
    const axutil_env_t *env,
    axis2_svc_client_t *svc_client,
    axis2_options_t *options,
    axutil_qname_t *op_qname,
    axis2_callback_t *callback,
    axiom_node_t *payload,
    axis2_listener_manager_t *listener_manager);

/**
 * In RM 1.0 two way single channel messaging user need
 * to call for the response envelope.
 *
 * @param conf_ctx
 * @param svc_client
 * @param msg_no
 * @return response soap envelope
 */
axiom_node_t *AXIS2_CALL
sandesha2_client_get_response_envelope(
    const axutil_env_t *env,
    axis2_conf_ctx_t *conf_ctx,
    axis2_svc_client_t *svc_client,
    int msg_no);

#ifdef __cplusplus
}
#endif
#endif /* SANDESHA2_CLIENT_H */
