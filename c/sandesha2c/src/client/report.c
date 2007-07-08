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
 
#include <sandesha2_report.h>
#include <sandesha2_seq_report.h>
#include <axutil_log.h>


/** 
 * @brief Sandesha Sequence Report Struct Impl
 *   Sandesha Sequence Report 
 */ 
struct sandesha2_report
{
    axutil_array_list_t *incoming_seq_list;
    axutil_array_list_t *outgoing_seq_list;
    axutil_hash_t *seq_status_map;
    axutil_hash_t *no_of_completed_msgs_map;
    axutil_hash_t *outgoing_internal_seq_id_map;
};

#define SANDESHA2_INTF_TO_IMPL(report) ((sandesha2_report_t *) report)

AXIS2_EXTERN sandesha2_report_t * AXIS2_CALL
sandesha2_report_create(
    const axutil_env_t *env)
{
    sandesha2_report_t *report = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    report = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_report_t));

    report->incoming_seq_list = NULL;
    report->outgoing_seq_list = NULL;
    report->seq_status_map = NULL;
    report->no_of_completed_msgs_map = NULL;
    report->outgoing_internal_seq_id_map = NULL;

    report->incoming_seq_list = axutil_array_list_create(env, 0);
    report->outgoing_seq_list = axutil_array_list_create(env, 0);
    if(!report->incoming_seq_list ||
       !report->outgoing_seq_list) 
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    report->seq_status_map = axutil_hash_make(env);
    report->no_of_completed_msgs_map = axutil_hash_make(env);
    report->outgoing_internal_seq_id_map = axutil_hash_make(env);
    if(!report->seq_status_map ||
        !report->no_of_completed_msgs_map ||
        !report->outgoing_internal_seq_id_map) 
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    return report;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_report_free(
    void *rep,
    const axutil_env_t *env)
{
    sandesha2_report_t *report = (sandesha2_report_t *) rep;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(report->incoming_seq_list)
    {
        axutil_array_list_free(report->incoming_seq_list, env);
        report->incoming_seq_list = NULL;
    }

    if(report->outgoing_seq_list)
    {
        axutil_array_list_free(report->outgoing_seq_list, env);
        report->outgoing_seq_list = NULL;
    }

    if(report->seq_status_map)
    {
        axutil_hash_free(report->seq_status_map, env);
        report->seq_status_map = NULL;
    }

    if(report->no_of_completed_msgs_map)
    {
        axutil_hash_free(report->no_of_completed_msgs_map, env);
        report->no_of_completed_msgs_map = NULL;
    }

    if(report->outgoing_internal_seq_id_map)
    {
        axutil_hash_free(report->outgoing_internal_seq_id_map, env);
        report->outgoing_internal_seq_id_map = NULL;
    }
    
    if(report)
    {
        AXIS2_FREE(env->allocator, report);
        report = NULL;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN long AXIS2_CALL
sandesha2_report_get_completed_msgs_count(
    sandesha2_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    long *lng = NULL;
    lng = (long *)axutil_hash_get(report->no_of_completed_msgs_map, seq_id, 
        AXIS2_HASH_KEY_STRING);
    if(!lng)
    {
        return -1;
    }
    return *lng;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
sandesha2_report_get_incoming_seq_list(
    sandesha2_report_t *report,
    const axutil_env_t *env)
{
    return report->incoming_seq_list;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
sandesha2_report_get_outgoing_seq_list(
    sandesha2_report_t *report,
    const axutil_env_t *env)
{
    return report->outgoing_seq_list;
}

AXIS2_EXTERN axis2_char_t AXIS2_CALL
sandesha2_report_get_seq_status_map(
    sandesha2_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    axis2_char_t *status = NULL;

    status = (axis2_char_t *) axutil_hash_get(report->seq_status_map, 
        seq_id, AXIS2_HASH_KEY_STRING);
    if(!status)
        return SANDESHA2_SEQ_STATUS_UNKNOWN;
    return *status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_report_add_to_incoming_seq_list(
    sandesha2_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *incoming_seq_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    axutil_array_list_add(report->incoming_seq_list, env, incoming_seq_id);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_report_add_to_outgoing_seq_list(
    sandesha2_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *out_seq_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    axutil_array_list_add(report->outgoing_seq_list, env, out_seq_id);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_report_add_to_no_of_completed_msgs_map(
    sandesha2_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *id,
    long no_of_msgs)
{
    long *no_of_msgs_l = AXIS2_MALLOC(env->allocator, sizeof(long));
    *no_of_msgs_l = no_of_msgs;
    axutil_hash_set(report->no_of_completed_msgs_map, id, 
        AXIS2_HASH_KEY_STRING, no_of_msgs_l);
    return AXIS2_SUCCESS;
}
	
AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_report_add_to_seq_status_map(
    sandesha2_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *id,
    axis2_char_t status)
{
    axutil_hash_set(report->seq_status_map, id, 
        AXIS2_HASH_KEY_STRING, &status);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_report_get_internal_seq_id_of_out_seq(
    sandesha2_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *out_seq_id)
{
    return (axis2_char_t *) axutil_hash_get(
        report->outgoing_internal_seq_id_map, out_seq_id, 
        AXIS2_HASH_KEY_STRING);
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_report_add_to_outgoing_internal_seq_map(
    sandesha2_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *out_seq_id,
    axis2_char_t *internal_seq_id)
{
    axutil_hash_set(report->outgoing_internal_seq_id_map, out_seq_id, 
        AXIS2_HASH_KEY_STRING, internal_seq_id);
    return AXIS2_SUCCESS;
}
	
