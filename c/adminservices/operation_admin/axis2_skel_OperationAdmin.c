

    /**
     * axis2_skel_OperationAdmin.c
     *
     * This file was auto-generated from WSDL for "OperationAdmin|http://mgt.operation.carbon.wso2.org" service
     * by the Apache Axis2/C version: #axisVersion# #today#
     * axis2_skel_OperationAdmin Axis2/C skeleton for the axisService
     */

     #include "codegen/axis2_skel_OperationAdmin.h"

     

		 
        /**
         * auto generated function definition signature
         * for "listOperationPhaseHandlers|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listOperationPhaseHandlers of the adb_listOperationPhaseHandlers_t*
         *
         * @return adb_listOperationPhaseHandlersResponse_t*
         */
        adb_listOperationPhaseHandlersResponse_t* axis2_skel_OperationAdmin_listOperationPhaseHandlers(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_listOperationPhaseHandlers_t* _listOperationPhaseHandlers )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_listOperationPhaseHandlersResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "setPolicy|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setPolicy of the adb_setPolicy_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_OperationAdmin_setPolicy(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_setPolicy_t* _setPolicy )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "listOperationPhases|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listOperationPhases of the adb_listOperationPhases_t*
         *
         * @return adb_listOperationPhasesResponse_t*
         */
        adb_listOperationPhasesResponse_t* axis2_skel_OperationAdmin_listOperationPhases(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_listOperationPhases_t* _listOperationPhases )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_listOperationPhasesResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "listControlOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listControlOperations of the adb_listControlOperations_t*
         *
         * @return adb_listControlOperationsResponse_t*
         */
        adb_listControlOperationsResponse_t* axis2_skel_OperationAdmin_listControlOperations(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_listControlOperations_t* _listControlOperations )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_listControlOperationsResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getDeclaredOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getDeclaredOperationParameters of the adb_getDeclaredOperationParameters_t*
         *
         * @return adb_getDeclaredOperationParametersResponse_t*
         */
        adb_getDeclaredOperationParametersResponse_t* axis2_skel_OperationAdmin_getDeclaredOperationParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getDeclaredOperationParameters_t* _getDeclaredOperationParameters )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getDeclaredOperationParametersResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "listAllOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listAllOperations of the adb_listAllOperations_t*
         *
         * @return adb_listAllOperationsResponse_t*
         */
        adb_listAllOperationsResponse_t* axis2_skel_OperationAdmin_listAllOperations(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_listAllOperations_t* _listAllOperations )
        {
            adb_OperationMetaDataWrapper_t *op_metadata_wrapper = NULL;
            axutil_array_list_t *op_list = NULL;
            adb_listPublishedOperations_t *list_published_ops = NULL;
            adb_listPublishedOperationsResponse_t *list_published_ops_res = NULL;

            if(!_listAllOperations)
            {
                return NULL;
            }
            list_published_ops = adb_listPublishedOperations_create_with_values(env, adb_listAllOperations_get_serviceName (_listAllOperations, env));
            if(list_published_ops)
            {
                list_published_ops_res = axis2_skel_OperationAdmin_listPublishedOperations(env, msg_ctx, list_published_ops);
                if(list_published_ops_res)
                {
                    op_list = adb_listPublishedOperationsResponse_get_return(list_published_ops_res, env);
                    
                }
                op_metadata_wrapper = adb_OperationMetaDataWrapper_create(env);
                adb_OperationMetaDataWrapper_set_publishedOperations (op_metadata_wrapper, env, op_list);
                adb_OperationMetaDataWrapper_set_controlOperations (op_metadata_wrapper, env, NULL);
            }

            return (adb_listAllOperationsResponse_t*) op_metadata_wrapper;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "configureMTOM|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _configureMTOM of the adb_configureMTOM_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_OperationAdmin_configureMTOM(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_configureMTOM_t* _configureMTOM )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationMetaData|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationMetaData of the adb_getOperationMetaData_t*
         *
         * @return adb_getOperationMetaDataResponse_t*
         */
        adb_getOperationMetaDataResponse_t* axis2_skel_OperationAdmin_getOperationMetaData(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationMetaData_t* _getOperationMetaData )
        {
            axis2_char_t *svc_name = NULL;
            axis2_char_t *op_name = NULL;
            adb_OperationMetaData_t * op_metadata = NULL;
            adb_getOperationMetaDataResponse_t * get_op_metadata_res = NULL;

            if(!_getOperationMetaData)
            {
                return NULL;
            }
            svc_name = adb_getOperationMetaData_get_serviceName(_getOperationMetaData, env);
            op_name = adb_getOperationMetaData_get_operationName(_getOperationMetaData, env);

            op_metadata = adb_OperationMetaData_create(env);
            adb_OperationMetaData_set_name(op_metadata, env, op_name);
            adb_OperationMetaData_set_controlOperation(op_metadata, env, AXIS2_FALSE);
            adb_OperationMetaData_set_enableMTOM(op_metadata, env, NULL);
            get_op_metadata_res = adb_getOperationMetaDataResponse_create_with_values (env, op_metadata); 
            return (adb_getOperationMetaDataResponse_t*) get_op_metadata_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationParameters of the adb_getOperationParameters_t*
         *
         * @return adb_getOperationParametersResponse_t*
         */
        adb_getOperationParametersResponse_t* axis2_skel_OperationAdmin_getOperationParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationParameters_t* _getOperationParameters )
        {
          return (adb_getOperationParametersResponse_t*) NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "removeOperationParameter|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _removeOperationParameter of the adb_removeOperationParameter_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_OperationAdmin_removeOperationParameter(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_removeOperationParameter_t* _removeOperationParameter )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getOperationStatistics|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getOperationStatistics of the adb_getOperationStatistics_t*
         *
         * @return adb_getOperationStatisticsResponse_t*
         */
        adb_getOperationStatisticsResponse_t* axis2_skel_OperationAdmin_getOperationStatistics(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getOperationStatistics_t* _getOperationStatistics )
        {
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            adb_getOperationStatisticsResponse_t* get_op_stat_res = NULL;
            axutil_array_list_t *op_list = NULL;

            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            svc_name = adb_getOperationStatistics_get_serviceName(_getOperationStatistics, env);
            svc = axis2_conf_get_svc(conf, env, svc_name);
            if(svc)
            {
                axis2_char_t *op_name = NULL;
                adb_getOperationMetaData_t *get_op_meta_data = NULL;
                adb_getOperationMetaDataResponse_t *get_op_meta_data_res = NULL;
                adb_OperationMetaData_t *op_meta_data = NULL;

                op_list = axutil_array_list_create(env, 0);
                op_name = adb_getOperationStatistics_get_operationName(_getOperationStatistics, env);
                get_op_meta_data = adb_getOperationMetaData_create_with_values(env, svc_name, op_name);
                if(get_op_meta_data)
                {
                    get_op_meta_data_res = axis2_skel_OperationAdmin_getOperationMetaData(env, msg_ctx, get_op_meta_data); 
                    if(get_op_meta_data_res)
                    {
                        op_meta_data = adb_getOperationMetaDataResponse_get_return(get_op_meta_data_res, env);
                        adb_getOperationMetaDataResponse_free(get_op_meta_data_res, env);
                    }
                    adb_getOperationMetaData_free(get_op_meta_data, env);
                    get_op_stat_res = adb_getOperationStatisticsResponse_create_with_values(env, op_meta_data);
                }
            }

            return (adb_getOperationStatisticsResponse_t*) get_op_stat_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "getPolicy|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _getPolicy of the adb_getPolicy_t*
         *
         * @return adb_getPolicyResponse_t*
         */
        adb_getPolicyResponse_t* axis2_skel_OperationAdmin_getPolicy(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_getPolicy_t* _getPolicy )
        {
          /* TODO fill this with the necessary business logic */
          return (adb_getPolicyResponse_t*)NULL;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "listPublishedOperations|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _listPublishedOperations of the adb_listPublishedOperations_t*
         *
         * @return adb_listPublishedOperationsResponse_t*
         */
        adb_listPublishedOperationsResponse_t* axis2_skel_OperationAdmin_listPublishedOperations(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_listPublishedOperations_t* _listPublishedOperations )
        {
            axis2_conf_ctx_t *conf_ctx = NULL;
            axis2_conf_t *conf = NULL;
            axis2_svc_t *svc = NULL;
            axis2_char_t *svc_name = NULL;
            axutil_hash_t *op_map = NULL;
            axutil_hash_index_t *index;
            int count = 0;
            adb_listPublishedOperationsResponse_t* published_op_list_res = NULL;
            axutil_array_list_t *op_list = NULL;

            conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
            conf = axis2_conf_ctx_get_conf(conf_ctx, env);
            svc_name = adb_listPublishedOperations_get_serviceName(_listPublishedOperations, env);
            svc = axis2_conf_get_svc(conf, env, svc_name);
            if(svc)
            {
                op_list = axutil_array_list_create(env, 0);
                op_map = axis2_svc_get_all_ops(svc, env);
                for (index = axutil_hash_first(op_map, env); index; index = axutil_hash_next(env, index))
                {
                    adb_getOperationMetaData_t *get_op_meta_data = NULL;
                    adb_getOperationMetaDataResponse_t *get_op_meta_data_res = NULL;
                    void *v = NULL;
                    axis2_op_t *op = NULL;
                    axis2_char_t *op_name = NULL;

                    axutil_hash_this(index, NULL, NULL, &v);
                    op = (axis2_op_t *) v;
                    op_name = axutil_qname_get_localpart(axis2_op_get_qname(op, env), env);
                    get_op_meta_data = adb_getOperationMetaData_create_with_values(env, svc_name, op_name);
                    if(get_op_meta_data)
                    {
                        get_op_meta_data_res = axis2_skel_OperationAdmin_getOperationMetaData(env, msg_ctx, get_op_meta_data);
                        if(get_op_meta_data_res)
                        {
                            axutil_array_list_add(op_list, env, adb_getOperationMetaDataResponse_get_return(get_op_meta_data_res, env));
                            adb_getOperationMetaDataResponse_free(get_op_meta_data_res, env);
                        }
                        adb_getOperationMetaData_free(get_op_meta_data, env);
                    }
                }
                published_op_list_res = adb_listPublishedOperationsResponse_create_with_values(env, op_list);
            }
            return (adb_listPublishedOperationsResponse_t*) published_op_list_res;
        }
     

		 
        /**
         * auto generated function definition signature
         * for "setOperationParameters|http://mgt.operation.carbon.wso2.org" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _setOperationParameters of the adb_setOperationParameters_t*
         *
         * @return 
         */
        axis2_status_t  axis2_skel_OperationAdmin_setOperationParameters(const axutil_env_t *env , axis2_msg_ctx_t *msg_ctx,
                                              adb_setOperationParameters_t* _setOperationParameters )
        {
          /* TODO fill this with the necessary business logic */
          return AXIS2_SUCCESS;
        }
     

