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


    /**
    * auto generated method signature
    * for "getOperationStatistics|http://services.statistics.carbon.wso2.org" operation.
    * @param stub The stub (axis2_stub_t)
    * @param env environment ( mandatory)
    * @param _getOperationStatistics of the adb_getOperationStatistics_t*
    *
    * @return adb_getOperationStatisticsResponse_t*
    */

    adb_getOperationStatisticsResponse_t* AXIS2_CALL 
    bam_publisher_statistics_get_operation_statistics(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            adb_getOperationStatistics_t *op_stat)
    {
        axis2_status_t status = AXIS2_SUCCESS;
        axis2_op_t *op = NULL;
        axis2_msg_recv_t *msg_recv = NULL;
        axis2_svc_skeleton_t *svc_obj = NULL;
        axiom_node_t *ret_node = NULL;
        axiom_node_t *payload = NULL;
        adb_getOperationStatisticsResponse_t* ret_val;

        if(op_stat)
        {
            payload = adb_getOperationStatistics_serialize(op_stat, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
        }
         
        op = axis2_msg_ctx_get_op(msg_ctx, env);
        msg_recv = axis2_op_get_msg_recv(op, env);

        svc_obj = axis2_msg_recv_make_new_svc_obj(msg_recv, env, msg_ctx);
        if(!svc_obj)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "Service Object could not be loaded for service. %d :: %s",
                env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));

            status = AXIS2_FAILURE;
        }
        if(status == AXIS2_SUCCESS)
        {
            ret_node = AXIS2_SVC_SKELETON_INVOKE(svc_obj, env, payload, msg_ctx);
        }

        if ( NULL == ret_node )
        {
            return (adb_getOperationStatisticsResponse_t*)NULL;
        }
        ret_val = adb_getOperationStatisticsResponse_create(env);

        if(adb_getOperationStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
        {
            if(!ret_val)
            {
                adb_getOperationStatisticsResponse_free(ret_val, env);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getOperationStatisticsResponse_deserialize: "
                                                    "This should be due to an invalid XML");
                return (adb_getOperationStatisticsResponse_t*)NULL;
            }
        }

        return ret_val;
    }

    /**
    * auto generated method signature
    * for "getServiceStatistics|http://services.statistics.carbon.wso2.org" operation.
    * @param stub The stub (axis2_stub_t)
    * @param env environment ( mandatory)
    * @param _getServiceStatistics of the adb_getServiceStatistics_t*
    *
    * @return adb_getServiceStatisticsResponse_t*
    */

    adb_getServiceStatisticsResponse_t* AXIS2_CALL 
    bam_publisher_statistics_get_service_statistics( 
            const axutil_env_t *env, 
            axis2_msg_ctx_t *msg_ctx,
            adb_getServiceStatistics_t *svc_stat)
    {
        axis2_status_t status = AXIS2_SUCCESS;
        axis2_op_t *op = NULL;
        axis2_msg_recv_t *msg_recv = NULL;
        axis2_svc_skeleton_t *svc_obj = NULL;
        axiom_node_t *ret_node = NULL;
        axiom_node_t *payload = NULL;
        adb_getServiceStatisticsResponse_t* ret_val = NULL;

        if(svc_stat)
        {
            payload = adb_getServiceStatistics_serialize(svc_stat, env, NULL, NULL, AXIS2_TRUE, NULL, NULL);
        }
         
        op = axis2_msg_ctx_get_op(msg_ctx, env);
        msg_recv = axis2_op_get_msg_recv(op, env);

        svc_obj = axis2_msg_recv_make_new_svc_obj(msg_recv, env, msg_ctx);
        if(!svc_obj)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "Service Object could not be loaded for service. %d :: %s",
                env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));

            status = AXIS2_FAILURE;
        }
        if(status == AXIS2_SUCCESS)
        {
            ret_node = AXIS2_SVC_SKELETON_INVOKE(svc_obj, env, payload, msg_ctx);
        }

        if ( NULL == ret_node )
        {
            return (adb_getServiceStatisticsResponse_t*)NULL;
        }
        ret_val = adb_getServiceStatisticsResponse_create(env);

        if(adb_getServiceStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, AXIS2_FALSE ) == AXIS2_FAILURE)
        {
            if(!ret_val)
            {
                adb_getServiceStatisticsResponse_free(ret_val, env);
                AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, "NULL returnted from the adb_getServiceStatisticsResponse_deserialize: "
                                                    "This should be due to an invalid XML");
                return (adb_getServiceStatisticsResponse_t*)NULL;
            }
        }

        return ret_val;
    }

