

    /**
    * bam_publisher_statistics.h
    *
    * This file was auto-generated from WSDL for "StatisticsAdmin|http://services.statistics.carbon.wso2.org" service
    * by the Apache Axis2/Java version: 1.5.1  Built on : Oct 19, 2009 (10:59:00 EDT)
    */

    #include <axutil_utils.h>
    #include <axutil_qname.h>
    #include <axis2_op.h>
    #include <axis2_svc.h>
    #include <axis2_msg_ctx.h>

	#ifdef __cplusplus
	extern "C" {
	#endif

    AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
    bam_publisher_svc_stat_handler_create(
            const axutil_env_t *env, 
            axutil_qname_t *qname);

    AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
    bam_publisher_op_stat_handler_create(
            const axutil_env_t *env, 
            axutil_qname_t *qname);

    int AXIS2_CALL 
    bam_publisher_statistics_get_service_request_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc);

    int AXIS2_CALL 
    bam_publisher_statistics_get_service_response_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc);

    int AXIS2_CALL 
    bam_publisher_statistics_get_service_fault_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc);

    int AXIS2_CALL 
    bam_publisher_statistics_get_max_service_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc);
		 
    int AXIS2_CALL 
    bam_publisher_statistics_get_operation_response_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op);

    double AXIS2_CALL 
    bam_publisher_statistics_get_avg_operation_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op);

    int AXIS2_CALL 
    bam_publisher_statistics_get_min_service_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc);
 
    int AXIS2_CALL 
    bam_publisher_statistics_get_max_operation_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op);

    int AXIS2_CALL 
    bam_publisher_statistics_get_operation_fault_count(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op);
 
    double AXIS2_CALL 
    bam_publisher_statistics_get_avg_service_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_svc_t *svc);

    int AXIS2_CALL 
    bam_publisher_statistics_get_min_operation_response_time(
            const axutil_env_t *env,
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t *op);
    		 
    int AXIS2_CALL  
    bam_publisher_statistics_get_operation_request_count(
            const axutil_env_t *env , 
            axis2_msg_ctx_t *msg_ctx,
            axis2_op_t* op);

	#ifdef __cplusplus
	}
	#endif
   

