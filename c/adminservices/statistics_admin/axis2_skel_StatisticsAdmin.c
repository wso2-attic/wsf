

    /**
     * axis2_skel_StatisticsAdmin.c
     *
     * This file was auto-generated from WSDL for "StatisticsAdmin|http://services.statistics.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_StatisticsAdmin Axis2/C skeleton for the axisService
     */

     #include "codegen/axis2_skel_StatisticsAdmin.h"
     #include "statistics_admin_constants.h"
     #include "module/axis2_response_time_processor.h"
     #include "module/axis2_counter.h"

     

		 
        /**
         * auto generated function definition signature
         * for "getMaxServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMaxServiceResponseTime of the adb_getMaxServiceResponseTime_t*
         *
         * @return adb_getMaxServiceResponseTimeResponse_t*
         */
        adb_getMaxServiceResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMaxServiceResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getMaxServiceResponseTime_t* _getMaxServiceResponseTime )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getMaxServiceResponseTimeResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getServiceRequestCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceRequestCount of the adb_getServiceRequestCount_t*
         *
         * @return adb_getServiceRequestCountResponse_t*
         */
        adb_getServiceRequestCountResponse_t* axis2_skel_StatisticsAdmin_getServiceRequestCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceRequestCount_t* _getServiceRequestCount )
        {
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            axutil_param_t *param = NULL;
            adb_getServiceRequestCountResponse_t* get_svc_req_count_res = NULL;
            axis2_counter_t *counter = NULL;

            if(!_getServiceRequestCount)
            {
                return NULL;
            }
            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            svc_name = adb_getServiceRequestCount_get_serviceName(_getServiceRequestCount, env);
            svc = axis2_conf_get_svc(conf, env, svc_name);
            if(svc)
            {
                param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_REQUEST_COUNTER);
                if(param)
                {
                    counter = axutil_param_get_value(param, env);
                    if(counter)
                    {
                        svc_req_count_res = adb_getServiceRequestCountResponse_create_with_values(env, counter->count);
                    }
                }
            }

            return (adb_getServiceRequestCountResponse_t*) svc_req_count_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getSystemResponseCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemResponseCountResponse_t*
         */
        adb_getSystemResponseCountResponse_t* axis2_skel_StatisticsAdmin_getSystemResponseCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getSystemResponseCountResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationResponseCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationResponseCount of the adb_getOperationResponseCount_t*
         *
         * @return adb_getOperationResponseCountResponse_t*
         */
        adb_getOperationResponseCountResponse_t* axis2_skel_StatisticsAdmin_getOperationResponseCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationResponseCount_t* _getOperationResponseCount )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getOperationResponseCountResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getAvgOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getAvgOperationResponseTime of the adb_getAvgOperationResponseTime_t*
         *
         * @return adb_getAvgOperationResponseTimeResponse_t*
         */
        adb_getAvgOperationResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getAvgOperationResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getAvgOperationResponseTime_t* _getAvgOperationResponseTime )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getAvgOperationResponseTimeResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationStatistics|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationStatistics of the adb_getOperationStatistics_t*
         *
         * @return adb_getOperationStatisticsResponse_t*
         */
        adb_getOperationStatisticsResponse_t* axis2_skel_StatisticsAdmin_getOperationStatistics(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationStatistics_t* _getOperationStatistics )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getOperationStatisticsResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getMinSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getMinSystemResponseTimeResponse_t*
         */
        adb_getMinSystemResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMinSystemResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getMinSystemResponseTimeResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getSystemFaultCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemFaultCountResponse_t*
         */
        adb_getSystemFaultCountResponse_t* axis2_skel_StatisticsAdmin_getSystemFaultCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getSystemFaultCountResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getMaxSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getMaxSystemResponseTimeResponse_t*
         */
        adb_getMaxSystemResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMaxSystemResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getMaxSystemResponseTimeResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getServiceFaultCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceFaultCount of the adb_getServiceFaultCount_t*
         *
         * @return adb_getServiceFaultCountResponse_t*
         */
        adb_getServiceFaultCountResponse_t* axis2_skel_StatisticsAdmin_getServiceFaultCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceFaultCount_t* _getServiceFaultCount )
        {
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            axutil_param_t *param = NULL;
            adb_getServiceFaultCountResponse_t* svc_fault_count_res = NULL;
            axis2_counter_t *counter = NULL;

            if(!_getServiceFaultCount)
            {
                return NULL;
            }
            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            svc_name = adb_getServiceFaultCount_get_serviceName(_getServiceFaultCount, env);
            svc = axis2_conf_get_svc(conf, env, svc_name);
            if(!svc)
            {
                return NULL;
            }
            param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_FAULT_COUNTER);
            if(param)
            {
                counter = axutil_param_get_value(param, env);
                svc_fault_count_res = adb_getServiceFaultCountResponse_create_with_values(env, counter->count);
            }

            return (adb_getServiceFaultCountResponse_t*) svc_fault_count_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getMinServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMinServiceResponseTime of the adb_getMinServiceResponseTime_t*
         *
         * @return adb_getMinServiceResponseTimeResponse_t*
         */
        adb_getMinServiceResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMinServiceResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getMinServiceResponseTime_t* _getMinServiceResponseTime )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getMinServiceResponseTimeResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getMaxOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMaxOperationResponseTime of the adb_getMaxOperationResponseTime_t*
         *
         * @return adb_getMaxOperationResponseTimeResponse_t*
         */
        adb_getMaxOperationResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMaxOperationResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getMaxOperationResponseTime_t* _getMaxOperationResponseTime )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getMaxOperationResponseTimeResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getServiceStatistics|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceStatistics of the adb_getServiceStatistics_t*
         *
         * @return adb_getServiceStatisticsResponse_t*
         */
        adb_getServiceStatisticsResponse_t* axis2_skel_StatisticsAdmin_getServiceStatistics(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceStatistics_t* _getServiceStatistics )
        {
            adb_getServiceStatisticsResponse_t *get_svc_stat_res = NULL;
            adb_ServiceStatistics_t *svc_stat = NULL;
            axis2_char_t *svc_name = NULL;
            double avg_res_time = 0;
            int res_count = 0;
            int req_count = 0;
            int fault_count = 0;
            adb_getAvgServiceResponseTime_t *get_avg_svc_res_time = NULL;
            adb_getAvgServiceResponseTimeResponse_t *get_avg_svc_res_time_res = NULL;
            adb_getServiceResponseCount_t *get_svc_res_count = NULL;
            adb_getServiceResponseCountResponse_t *get_svc_res_count_res = NULL;
            adb_getServiceRequestCount_t *get_svc_req_count = NULL;
            adb_getServiceRequestCountResponse_t *get_svc_req_count_res = NULL;
            adb_getServiceFaultCount_t *get_svc_fault_count = NULL;
            adb_getServiceFaultCountResponse_t *get_svc_fault_count_res = NULL;

            if(!_getServiceStatistics)
            {
                return NULL;
            }
            svc_stat = adb_ServiceStatistics_create(env);
            if(svc_stat)
            {
                return NULL;
            }
            svc_name = adb_getServiceStatistics_get_serviceName(_getServiceStatistics, env);

            get_avg_svc_res_time = adb_getAvgServiceResponseTime_create_with_values(env, svc_name);
            if(get_avg_svc_res_time)
            {
                get_avg_svc_res_time_res = axis2_skel_StatisticsAdmin_getAvgServiceResponseTime(env, msg_ctx, get_avg_svc_res_time);
                if(get_avg_svc_res_time_res)
                {
                    avg_res_time = adb_getAvgServiceResponseTimeResponse_get_return(get_avg_svc_res_time_res, env);
                    adb_ServiceStatistics_set_avgResponseTime(svc_stat, env, avg_res_time);
                    adb_getAvgServiceResponseTimeResponse_free(get_avg_svc_res_time_res, env);
                }
                adb_getAvgServiceResponseTime_free(get_avg_svc_res_time, env);
            }

            get_svc_res_count = adb_getServiceResponseCount_create_with_values(env, svc_name);
            if(get_svc_res_count)
            {
                get_svc_res_count_res = axis2_skel_StatisticsAdmin_getServiceResponseCount(env, msg_ctx, get_svc_res_count);
                if(get_svc_res_count_res)
                {
                    res_count = adb_getServiceResponseCountResponse_get_return(get_svc_res_count_res, env);
                    adb_ServiceStatistics_set_responseCount (svc_stat, env, res_count);
                    adb_getServiceResponseCountResponse_free(get_svc_res_count_res, env);
                }
                adb_getServiceResponseCount_free(get_svc_res_count, env);
            }
            
            get_svc_req_count = adb_getServiceRequestCount_create_with_values(env, svc_name);
            if(get_svc_req_count)
            {
                get_svc_req_count_res = axis2_skel_StatisticsAdmin_getServiceRequestCount(env, msg_ctx, get_svc_req_count);
                if(get_svc_req_count_res)
                {
                    req_count = adb_getServiceRequestCountResponse_get_return(get_svc_req_count_res, env);
                    adb_ServiceStatistics_set_requestCount (svc_stat, env, req_count);
                    adb_getServiceRequestCountResponse_free(get_svc_req_count_res, env);
                }
                adb_getServiceRequestCount_free(get_svc_req_count, env);
            }
            
            get_svc_fault_count = adb_getServiceFaultCount_create_with_values(env, svc_name);
            if(get_svc_fault_count)
            {
                get_svc_fault_count_res = axis2_skel_StatisticsAdmin_getServiceFaultCount(env, msg_ctx, get_svc_fault_count);
                if(get_svc_fault_count_res)
                {
                    fault_count = adb_getServiceFaultCountResponse_get_return(get_svc_fault_count_res, env);
                    adb_ServiceStatistics_set_FaultCount (svc_stat, env, fault_count);
                    adb_getServiceFaultCountResponse_free(get_svc_fault_count_res, env);
                }
                adb_getServiceFaultCount_free(get_svc_fault_count, env);
            }

            get_svc_stat_res = adb_getServiceStatisticsResponse_create_with_values(env, svc_stat);
            return (adb_getServiceStatisticsResponse_t*) get_svc_stat_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationFaultCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationFaultCount of the adb_getOperationFaultCount_t*
         *
         * @return adb_getOperationFaultCountResponse_t*
         */
        adb_getOperationFaultCountResponse_t* axis2_skel_StatisticsAdmin_getOperationFaultCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationFaultCount_t* _getOperationFaultCount )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getOperationFaultCountResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getAvgServiceResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getAvgServiceResponseTime of the adb_getAvgServiceResponseTime_t*
         *
         * @return adb_getAvgServiceResponseTimeResponse_t*
         */
        adb_getAvgServiceResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getAvgServiceResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getAvgServiceResponseTime_t* _getAvgServiceResponseTime )
        {
            adb_getAvgServiceResponseTimeResponse_t *avg_svc_res_time_res = NULL;
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;

            if(!_getAvgServiceResponseTime)
            {
                return NULL;
            }
            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            svc_name = adb_getAvgServiceResponseTime_get_serviceName(_getAvgServiceResponseTime, env);
            svc = axis2_conf_get_svc(conf, env, svc_name);
            if(svc)
            {
                axutil_param_t *param = NULL;
                double avg_res_time = 0.0;
                param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_RESPONSE_TIME_PROCESSOR);
                if(param)
                {
                    axis2_response_time_processor_t *res_time_proc = NULL;
                    res_time_proc = axutil_param_get_value(param, env);
                    if(res_time_proc)
                    {
                        avg_svc_res_time_res = adb_getAvgServiceResponseTimeResponse_create_with_values(env, res_time_proc->avg_response_time);
                    }
                }
            }
            return (adb_getAvgServiceResponseTimeResponse_t*) avg_svc_res_time_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getServiceResponseCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getServiceResponseCount of the adb_getServiceResponseCount_t*
         *
         * @return adb_getServiceResponseCountResponse_t*
         */
        adb_getServiceResponseCountResponse_t* axis2_skel_StatisticsAdmin_getServiceResponseCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getServiceResponseCount_t* _getServiceResponseCount )
        {
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            axutil_hash_t *op_map = NULL;
            axutil_hash_index_t *index;
            int count = 0;
            adb_getServiceResponseCountResponse_t* svc_res_count_res = NULL;

            if(!_getServiceResponseCount)
            {
                return NULL;
            }
            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            svc_name = adb_getServiceResponseCount_get_serviceName(_getServiceResponseCount, env);
            svc = axis2_conf_get_svc(conf, env, svc_name);
            if(!svc)
            {
                return NULL;
            }
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
                        axis2_counter_t *counter = NULL;
                        counter = axutil_param_get_value(param, env);
                        count += counter->count;
                    }
                }
            }
            svc_res_count_res = adb_getServiceResponseCountResponse_create_with_values(env, count);
            return (adb_getServiceResponseCountResponse_t*) svc_res_count_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getSystemRequestCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemRequestCountResponse_t*
         */
        adb_getSystemRequestCountResponse_t* axis2_skel_StatisticsAdmin_getSystemRequestCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          return (adb_getSystemRequestCountResponse_t*) NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getMinOperationResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getMinOperationResponseTime of the adb_getMinOperationResponseTime_t*
         *
         * @return adb_getMinOperationResponseTimeResponse_t*
         */
        adb_getMinOperationResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getMinOperationResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getMinOperationResponseTime_t* _getMinOperationResponseTime )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getMinOperationResponseTimeResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getAvgSystemResponseTime|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getAvgSystemResponseTimeResponse_t*
         */
        adb_getAvgSystemResponseTimeResponse_t* axis2_skel_StatisticsAdmin_getAvgSystemResponseTime(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getAvgSystemResponseTimeResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getSystemStatistics|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         *
         * @return adb_getSystemStatisticsResponse_t*
         */
        adb_getSystemStatisticsResponse_t* axis2_skel_StatisticsAdmin_getSystemStatistics(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getSystemStatisticsResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationRequestCount|http://services.statistics.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationRequestCount of the adb_getOperationRequestCount_t*
         *
         * @return adb_getOperationRequestCountResponse_t*
         */
        adb_getOperationRequestCountResponse_t* axis2_skel_StatisticsAdmin_getOperationRequestCount(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationRequestCount_t* _getOperationRequestCount )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getOperationRequestCountResponse_t*)NULL;
        }
     

