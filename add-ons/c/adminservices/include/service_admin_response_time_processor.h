/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
 
#ifndef SERVICE_ADMIN_RESPONSE_TIME_PROCESSOR_H
#define SERVICE_ADMIN_RESPONSE_TIME_PROCESSOR_H

/**
  * @file service_admin_response_time_processor.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** 
 * @ingroup service_admin_response_time_processor
 * @{
 */
 
/** 
 * @brief response time processor struct impl
 *	Reponse Time Processor Struct
 */
typedef struct service_admin_response_time_processor
{
    long max_response_time;
    long min_response_time;
    double avg_response_time;
    double total_response_time;
} service_admin_response_time_processor_t;


AXIS2_EXTERN service_admin_response_time_processor_t* AXIS2_CALL
service_admin_response_time_processor_create(
    const axutil_env_t *env);

void AXIS2_CALL 
service_admin_response_time_processor_free(
    service_admin_response_time_processor_t *res_time_proc, 
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
service_admin_response_time_processor_add_response_time (
    service_admin_response_time_processor_t *res_time_proc,
    const axutil_env_t *env,
    long response_time,
    long request_count);

/** @} */
#ifdef __cplusplus
}
#endif

#endif /*SERVICE_ADMIN_RESPONSE_TIME_PROCESSOR_H*/
