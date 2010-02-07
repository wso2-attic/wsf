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
    #include <service_admin_constants.h>

    static axis2_svc_skeleton_t *
    bam_publisher_make_new_svc_obj(
        const axutil_env_t * env,
        axis2_svc_t * svc);

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
        axis2_conf_ctx_t *conf_ctx = NULL;
        axis2_conf_t *conf = NULL;
        axis2_svc_t *svc = NULL;
        axis2_svc_skeleton_t *svc_obj = NULL;
        axiom_node_t *ret_node = NULL;
        axiom_node_t *payload = NULL;
        adb_getServiceStatisticsResponse_t* ret_val = NULL;
        axis2_msg_ctx_t *tmp_msg_ctx = NULL;
 
        conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
        conf = axis2_conf_ctx_get_conf(conf_ctx, env);
        svc = axis2_conf_get_svc(conf, env, ADMIN_SERVICE_STATISTICS_SVC_NAME);
        svc_obj = bam_publisher_make_new_svc_obj(env, svc);
        if(!svc_obj)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "Service Object could not be loaded for %s service", 
                ADMIN_SERVICE_STATISTICS_SVC_NAME);
            return (adb_getServiceStatisticsResponse_t*)NULL;
        }
        if(svc_stat)
        {
            payload = adb_getServiceStatistics_serialize(svc_stat, env, NULL, NULL, AXIS2_TRUE, 
                    NULL, NULL);
            if(!payload)
            {
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                    "Statistics payload creation failed. %d :: %s",
                    env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
                return (adb_getServiceStatisticsResponse_t*)NULL;
            }
        }

        tmp_msg_ctx = axis2_msg_ctx_create(env, conf_ctx, NULL, NULL);
        if(tmp_msg_ctx)
        {
            axis2_op_t *op = NULL;
            axis2_op_ctx_t *op_ctx = NULL;
            op = axis2_op_create_with_qname(env, axutil_qname_create(env, "getServiceStatistics", 
                        NULL, NULL));
            if(op)
            {
                op_ctx = axis2_op_ctx_create(env, op, NULL);
                if(op_ctx)
                {   
                    axis2_msg_ctx_set_op_ctx(tmp_msg_ctx, env, op_ctx);
                    ret_node = AXIS2_SVC_SKELETON_INVOKE(svc_obj, env, payload, tmp_msg_ctx);
                    axis2_op_ctx_free(op_ctx, env);
                    if (!ret_node )
                    {
                        axis2_msg_ctx_free(tmp_msg_ctx, env);
                        return (adb_getServiceStatisticsResponse_t*)NULL;
                    }
                }
                axis2_op_free(op, env);
            }
            axis2_msg_ctx_free(tmp_msg_ctx, env);
        }
        ret_val = adb_getServiceStatisticsResponse_create(env);
        if(ret_val)
        {
            if(adb_getServiceStatisticsResponse_deserialize(ret_val, env, &ret_node, NULL, 
                        AXIS2_FALSE ) == AXIS2_FAILURE)
            {
                if(ret_val)
                {
                    adb_getServiceStatisticsResponse_free(ret_val, env);
                    AXIS2_LOG_ERROR( env->log, AXIS2_LOG_SI, 
                            "NULL returnted from the adb_getServiceStatisticsResponse_deserialize: "
                                "This should be due to an invalid XML");
                    return (adb_getServiceStatisticsResponse_t*)NULL;
                }
            }
        }

        return ret_val;
    }

    static axis2_svc_skeleton_t *
    bam_publisher_make_new_svc_obj(
        const axutil_env_t * env,
        axis2_svc_t * svc)
    {
        axutil_param_t *impl_info_param = NULL;
        void *impl_class = NULL;

        AXIS2_PARAM_CHECK(env->error, svc, NULL);

        impl_class = axis2_svc_get_impl_class(svc, env);
        if(impl_class)
        {
            return impl_class;
        }
        else
        {
            /* When we load the DLL we have to make sure that only one thread will load it */
            axutil_thread_mutex_lock(axis2_svc_get_mutex(svc, env));
            /* If more than one thread tries to acquires the lock, first thread loads the DLL.
             Others should not load the DLL */
            impl_class = axis2_svc_get_impl_class(svc, env);
            if(impl_class)
            {
                axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));
                return impl_class;
            }
            impl_info_param = axis2_svc_get_param(svc, env, AXIS2_SERVICE_CLASS);
            if(!impl_info_param)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_STATE_SVC, AXIS2_FAILURE);
                axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));
                return NULL;
            }

            axutil_allocator_switch_to_global_pool(env->allocator);

            axutil_class_loader_init(env);

            impl_class = axutil_class_loader_create_dll(env, impl_info_param);

            if(impl_class)
            {
                AXIS2_SVC_SKELETON_INIT((axis2_svc_skeleton_t *)impl_class, env);
            }

            axis2_svc_set_impl_class(svc, env, impl_class);

            axutil_allocator_switch_to_local_pool(env->allocator);
            axutil_thread_mutex_unlock(axis2_svc_get_mutex(svc, env));
            return impl_class;
        }
    }

