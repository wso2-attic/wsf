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
    /**
    * statistics.c
    *
    * This file was auto-generated from WSDL for "StatisticsAdmin|http://services.statistics.carbon.wso2.org" service
    * by the Apache Axis2/Java version: 1.5.1  Built on : Oct 19, 2009 (10:59:00 EDT)
    */

    #include "bam_publisher_statistics.h"
    #include <axis2_msg.h>
    #include <axis2_policy_include.h>
    #include <neethi_engine.h>
    #include <service_admin_util.h>
    #include <service_admin_counter.h>
    #include <service_admin_response_time_processor.h>
    #include <service_admin_constants.h>


    int AXIS2_CALL 
    bam_publisher_statistics_get_service_request_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc)
    {
        int ret = 0;
        if(svc)
        {
            axutil_param_t *param = NULL;
            
            param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_REQUEST_COUNTER);
            if(param)
            {
                service_admin_counter_t *counter = NULL;
                counter = axutil_param_get_value(param, env);
                if(counter)
                {
                    ret = service_admin_counter_get_count(counter, env, msg_ctx);
                }
            }
        }
        return ret;
    }

    int AXIS2_CALL 
    bam_publisher_statistics_get_service_response_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc)
    {
        int ret = 0;
        if(svc)
        {
            axutil_hash_t *op_map = NULL;
            axutil_hash_index_t *index;

            op_map = axis2_svc_get_all_ops(svc, env);
            for (index = axutil_hash_first(op_map, env); index; index = axutil_hash_next(env, index))
            {
                axutil_param_t *param = NULL;
                void *v = NULL;
                axis2_op_t *op = NULL;

                axutil_hash_this(index, NULL, NULL, &v);
                op = (axis2_op_t *) v;
                if(op)
                {
                    param = axis2_op_get_param(op, env, AXIS2_OUT_OPERATION_COUNTER);
                    if(param)
                    {
                        service_admin_counter_t *counter = NULL;
                        counter = axutil_param_get_value(param, env);
                        if(counter)
                        {
                            ret += service_admin_counter_get_count(counter, env, msg_ctx);
                        }
                    }
                }
            }
        }

        return ret;
    }

    int AXIS2_CALL 
    bam_publisher_statistics_get_service_fault_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc)
    {
        int ret = 0;
        if(svc)
        {
            axutil_param_t *param = NULL;
            param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_FAULT_COUNTER);
            if(param)
            {
                service_admin_counter_t *counter = NULL;
                counter = axutil_param_get_value(param, env);
                if(counter)
                {
                    ret = service_admin_counter_get_count(counter, env, msg_ctx);
                }
            }
        }
        return ret;
    }

    int AXIS2_CALL 
    bam_publisher_statistics_get_max_service_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc)
    {
        int ret = 0;
        if(svc)
        {
            axutil_param_t *param = NULL;
            param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_RESPONSE_TIME_PROCESSOR);
            if(param)
            {
                service_admin_response_time_processor_t *res_time_proc = NULL;
                res_time_proc = axutil_param_get_value(param, env);
                if(res_time_proc)
                {
                    ret = res_time_proc->max_response_time;
                }
            }
        }
        return ret;
    }
 

		 
    int AXIS2_CALL 
    bam_publisher_statistics_get_operation_response_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op)
    {
        int ret = 0;
        if(op)
        {
            axutil_param_t *param = NULL;
            param = axis2_op_get_param(op, env, AXIS2_OUT_OPERATION_COUNTER);
            if(param)
            {
                service_admin_counter_t *counter = NULL;
                counter = axutil_param_get_value(param, env);
                if(counter)
                {
                    ret = service_admin_counter_get_count(counter, env, msg_ctx);
                }
            }
        }
        return ret;
    }
 

    double AXIS2_CALL 
    bam_publisher_statistics_get_avg_operation_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op)
    {
        double ret = 0.0;
        if(op)
        {
            axutil_param_t *param = NULL;
            param = axis2_op_get_param(op, env, AXIS2_OPERATION_RESPONSE_TIME_PROCESSOR);
            if(param)
            {
                service_admin_response_time_processor_t *res_time_proc = NULL;
                res_time_proc = axutil_param_get_value(param, env);
                if(res_time_proc)
                {
                    ret = res_time_proc->avg_response_time;
                }
            }
        }
        return ret;
    }
 

    int AXIS2_CALL 
    bam_publisher_statistics_get_min_service_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc)
    {
        int ret = 0;

        if(svc)
        {
            axutil_param_t *param = NULL;
            param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_RESPONSE_TIME_PROCESSOR);
            if(param)
            {
                service_admin_response_time_processor_t *res_time_proc = NULL;
                res_time_proc = axutil_param_get_value(param, env);
                if(res_time_proc)
                {
                    ret = res_time_proc->min_response_time;
                }
            }
        }
        return ret;
    }
 
    int AXIS2_CALL 
    bam_publisher_statistics_get_max_operation_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op)
    {
        int ret = 0;
        if(op)
        {
            service_admin_response_time_processor_t *res_time_proc = NULL;
            axutil_param_t *param = NULL;
            param = axis2_op_get_param(op, env, AXIS2_OPERATION_RESPONSE_TIME_PROCESSOR);
            if(param)
            {
                res_time_proc = axutil_param_get_value(param, env);
                if(res_time_proc)
                {
                    ret = res_time_proc->max_response_time;
                }
            }
        }
        return ret;
    }
 

    int AXIS2_CALL 
    bam_publisher_statistics_get_operation_fault_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op)
    {
        int ret = 0;
        if(op)
        {
            axutil_param_t *param = NULL;
            param = axis2_op_get_param(op, env, AXIS2_OPERATION_FAULT_COUNTER);
            if(param)
            {
                service_admin_counter_t *counter = NULL;
                counter = axutil_param_get_value(param, env);
                if(counter)
                {
                    ret = service_admin_counter_get_count(counter, env, msg_ctx);
                }
            }
        }
        return ret;
    }
 
    double AXIS2_CALL 
    bam_publisher_statistics_get_avg_service_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc)
    {
        double ret = 0.0;
        if(svc)
        {
            axutil_param_t *param = NULL;
            param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_RESPONSE_TIME_PROCESSOR);
            if(param)
            {
                service_admin_response_time_processor_t *res_time_proc = NULL;
                res_time_proc = axutil_param_get_value(param, env);
                if(res_time_proc)
                {
                   ret = res_time_proc->avg_response_time;
                }
            }
        }
        return ret;
    }
 

    int AXIS2_CALL 
    bam_publisher_statistics_get_min_operation_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op)
    {
        int ret = 0;
        if(op)
        {
            axutil_param_t *param = NULL;
            param = axis2_op_get_param(op, env, AXIS2_OPERATION_RESPONSE_TIME_PROCESSOR);
            if(param)
            {
                service_admin_response_time_processor_t *res_time_proc = NULL;
                res_time_proc = axutil_param_get_value(param, env);
                if(res_time_proc)
                {
                    ret = res_time_proc->min_response_time;
                }
            }
        }
        return ret;
    }
 

		 
    		 
    int AXIS2_CALL
    bam_publisher_statistics_get_operation_request_count(
            const axutil_env_t *env , 
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t* op)
    {
        int ret = 0;
        if(op)
        {
            axutil_param_t *param = NULL;
            param = axis2_op_get_param(op, env, AXIS2_IN_OPERATION_COUNTER);
            if(param)
            {
                service_admin_counter_t *counter = NULL;
                counter = axutil_param_get_value(param, env);
                if(counter)
                {
                    ret = service_admin_counter_get_count(counter, env, msg_ctx);
                }
            }
        }
        return ret;
    }
     
