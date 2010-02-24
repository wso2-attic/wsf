 
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
