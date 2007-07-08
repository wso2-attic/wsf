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
 
#include <sandesha2_seq_report.h>
#include <axutil_log.h>

/** 
 * @brief Sandesha Sequence Report Struct Impl
 *   Sandesha Sequence Report 
 */ 
struct sandesha2_seq_report
{
    axis2_char_t seq_status;
	axis2_char_t seq_direction;
	axis2_char_t *seq_id;
	axis2_char_t *internal_seq_id;   /* only for outgoing seqs */
	axutil_array_list_t *completed_msgs; /* no of messages acked (both for incoming and outgoing)*/
};

AXIS2_EXTERN sandesha2_seq_report_t * AXIS2_CALL
sandesha2_seq_report_create(
    const axutil_env_t *env)
{
    sandesha2_seq_report_t *report = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    report = AXIS2_MALLOC(env->allocator, 
        sizeof(sandesha2_seq_report_t));

    report->seq_status = SANDESHA2_SEQ_STATUS_UNKNOWN;
    report->seq_direction = SANDESHA2_SEQ_DIRECTION_UNKNOWN;
    report->completed_msgs = NULL;
    report->internal_seq_id = NULL;
    report->seq_id = NULL;

    report->completed_msgs = axutil_array_list_create(env, 0);
    if(!report->completed_msgs) 
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    return report;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_seq_report_free(
    void *seq_report,
    const axutil_env_t *env)
{
    sandesha2_seq_report_t *report = (sandesha2_seq_report_t *)seq_report;
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if(report->completed_msgs)
    {
        axutil_array_list_free(report->completed_msgs, env);
        report->completed_msgs = NULL;
    }

    if(report->seq_id)
    {
        AXIS2_FREE(env->allocator, report->seq_id);
        report->seq_id = NULL;
    }
    
    if(report)
    {
        AXIS2_FREE(env->allocator, report);
        report = NULL;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_seq_report_set_seq_status(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env,
    axis2_char_t seq_status)
{
    if (seq_status >= SANDESHA2_SEQ_STATUS_UNKNOWN && 
        seq_status <= SANDESHA2_MAX_SEQ_STATUS) 
    {
        report->seq_status = seq_status;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_seq_report_set_seq_direction(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env,
    axis2_char_t seq_direction)
{
    if (seq_direction >= SANDESHA2_SEQ_DIRECTION_UNKNOWN && 
        seq_direction <= SANDESHA2_MAX_SEQ_DIRECTION) 
    {
        report->seq_direction = seq_direction;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t AXIS2_CALL
sandesha2_seq_report_get_seq_status(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env)
{
    return report->seq_status;
}

AXIS2_EXTERN axis2_char_t AXIS2_CALL
sandesha2_seq_report_get_seq_direction(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env)
{
    return report->seq_direction;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_seq_report_get_seq_id(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env)
{
    return report->seq_id;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_seq_report_set_seq_id(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *seq_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    if(report->seq_id)
    {
        AXIS2_FREE(env->allocator, report->seq_id);
        report->seq_id = NULL;
    }
    report->seq_id = axutil_strdup(env ,seq_id);
    if(!report->seq_id)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
sandesha2_seq_report_get_completed_msgs(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env)
{
    return report->completed_msgs;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_seq_report_add_completed_msg(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env,
    long *msg_no)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    axutil_array_list_add(report->completed_msgs, env, msg_no);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_seq_report_set_completed_msgs(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env,
    axutil_array_list_t *completed_msgs)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(report->completed_msgs)
    {
        int i = 0, size = 0;
        
        size = axutil_array_list_size(report->completed_msgs, env);
        for(i = 0; i < size; i++)
        {
            long *msg_no = NULL;
        
            msg_no = axutil_array_list_get(report->completed_msgs, env, i);
            AXIS2_FREE(env->allocator, msg_no);
        }
        axutil_array_list_free(report->completed_msgs, env);
        report->completed_msgs = NULL;
    }
    report->completed_msgs = completed_msgs;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
sandesha2_seq_report_get_internal_seq_id(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env,
    long *msg_no)
{
    return report->internal_seq_id;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
sandesha2_seq_report_set_internal_seq_id(
    sandesha2_seq_report_t *report,
    const axutil_env_t *env,
    axis2_char_t *internal_seq_id)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(report->internal_seq_id)
    {
        AXIS2_FREE(env->allocator, report->internal_seq_id);
        report->internal_seq_id = NULL;
    }
    report->internal_seq_id = axutil_strdup(env, internal_seq_id);
    if(!report->internal_seq_id)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

