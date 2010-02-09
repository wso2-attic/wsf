    /**
    * statistics.c
    *
    * This file was auto-generated from WSDL for "StatisticsAdmin|http://services.statistics.carbon.wso2.org" service
    * by the Apache Axis2/Java version: 1.5.1  Built on : Oct 19, 2009 (10:59:00 EDT)
    */

    #include "axis2_stub_StatisticsAdmin.h"
    #include "bam_publisher_statistics.h"
    #include <axis2_msg.h>
    #include <axis2_policy_include.h>
    #include <neethi_engine.h>
    #include <service_admin_util.h>
    #include <service_admin_constants.h>


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
        const axis2_char_t *client_home = NULL;
        axis2_char_t *address = NULL;
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_stub_t *stub = NULL;
        adb_getOperationStatisticsResponse_t *get_op_stat_res = NULL;

        address = service_admin_util_get_epr_address(env, msg_ctx, 
                ADMIN_SERVICE_STATISTICS_SVC_NAME); 
        conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        client_home = axis2_conf_ctx_get_root_dir(conf_ctx, env);
        if(!client_home)
        {
            client_home = AXIS2_GETENV("AXIS2C_HOME");
        }
        stub = axis2_stub_create_StatisticsAdmin(env, client_home, address);
        if(stub)
        {
            get_op_stat_res = axis2_stub_op_StatisticsAdmin_getOperationStatistics(stub, env, op_stat);
        }

        return get_op_stat_res;
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
        const axis2_char_t *client_home = NULL;
        axis2_char_t *address = NULL;
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_stub_t *stub = NULL;
        adb_getServiceStatisticsResponse_t *get_svc_stat_res = NULL;

        address = service_admin_util_get_epr_address(env, msg_ctx, 
                ADMIN_SERVICE_STATISTICS_SVC_NAME);
        conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        client_home = axis2_conf_ctx_get_root_dir(conf_ctx, env);
        if(!client_home)
        {
            client_home = AXIS2_GETENV("AXIS2C_HOME");
        }
        stub = axis2_stub_create_StatisticsAdmin(env, client_home, address);
        if(stub)
        {
            get_svc_stat_res = axis2_stub_op_StatisticsAdmin_getServiceStatistics(stub, env, svc_stat);
        }

        return get_svc_stat_res;
    }



