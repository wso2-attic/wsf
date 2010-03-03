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

#ifndef AXIS2_MOD_STATISTICS_ADMIN_H
#define AXIS2_MOD_STATISTICS_ADMIN_H

/**
 * @file mod_statistics_admin.h
 * @brief Axis2 Statistics Admin module interface
 */

#include <axis2_handler.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define AXIS2_MOD_STATISTICS_GLOBAL_REQUEST_COUNT_HANDLER "GlobalRequestCounter"
#define AXIS2_MOD_STATISTICS_SERVICE_REQUEST_COUNT_HANDLER "ServiceRequestCounter"
#define AXIS2_MOD_STATISTICS_IN_OP_COUNT_HANDLER "OperationInCounter"
#define AXIS2_MOD_STATISTICS_OUT_OP_COUNT_HANDLER "OperationOutCounter"
#define AXIS2_MOD_STATISTICS_FAULT_COUNT_HANDLER "FaultCounter"
#define AXIS2_MOD_STATISTICS_RESPONSE_TIME_HANDLER "ResponseTimeHandler"

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_global_request_count_handler_create(
        const axutil_env_t *env, 
        axutil_qname_t *qname);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_svc_request_count_handler_create(
        const axutil_env_t *env, 
        axutil_qname_t *qname);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_in_op_count_handler_create(
        const axutil_env_t *env, 
        axutil_qname_t *qname);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_out_op_count_handler_create(
        const axutil_env_t *env, 
        axutil_qname_t *qname);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_fault_count_handler_create(
        const axutil_env_t *env, 
        axutil_qname_t *qname);

AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_response_time_handler_create(
        const axutil_env_t *env, 
        axutil_qname_t *qname);
    
/** @} */
    
#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_MOD_STATISTICS_ADMIN_H */
