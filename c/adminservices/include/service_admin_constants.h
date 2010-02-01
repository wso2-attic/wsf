/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SERVICE_ADMIN_CONSTANTS_H_
#define SERVICE_ADMIN_CONSTANTS_H_

#define DEFAULT_SERVICE_TYPE_FILTER "ALL"
#define AXIS2_DEFAULT_SERVICE_TYPE "axis2"

/* Parameters in service.xml needed by admin services */
#define AXIS2_SERVICE_TYPE "serviceType"
#define AXIS2_SERVICE_AUTHORIZATION_ACTION "AuthorizationAction"
#define AXIS2_SERVICE_DISABLE_TRYIT "disableTryIt"
#define AXIS2_GLOBAL_REQUEST_COUNTER "wso2statistics.GlobalRequestCounter"
#define AXIS2_GLOBAL_RESPONSE_COUNTER "wso2statistics.GlobalResponseCounter"
#define AXIS2_SERVICE_RESPONSE_TIME_PROCESSOR "wso2statistics.ServiceResponseTimeProc"
#define AXIS2_OPERATION_RESPONSE_TIME_PROCESSOR "wso2statistics.OperationResponseTimeProc"
#define AXIS2_GLOBAL_FAULT_COUNTER "wso2statistics.GlobalFaultCounter"
#define AXIS2_SERVICE_REQUEST_COUNTER "wso2statistics.ServiceRequestCounter"
#define AXIS2_SERVICE_FAULT_COUNTER "wso2statistics.ServiceFaultCounter"
#define AXIS2_IN_OPERATION_COUNTER "wso2statistics.InOperationCounter"
#define AXIS2_OUT_OPERATION_COUNTER "wso2statistics.OutOperationCounter"
#define AXIS2_OPERATION_FAULT_COUNTER "wso2statistics.OperationFaultCounter"
#define AXIS2_REQUEST_RECEIVED_TIME "wso2statistics.request.received.time"
#define AXIS2_RESPONSE_SENT_TIME "wso2statistics.response.sent.time"
#define AXIS2_STATISTISTICS_MODULE_NAME "wso2statistics"
#define AXIS2_MOD_STATISTICS_ADMIN_OUT_OP_COUNT_HANDLER "wso2statistics.out_op_count_handler"
#define AXIS2_MOD_STATISTICS_ADMIN_IN_OP_COUNT_HANDLER "wso2statistics.in_op_count_handler"
#define AXIS2_MOD_STATISTICS_ADMIN_FAULT_COUNT_HANDLER "wso2statistics.fault_count_handler"

#endif /* SERVICE_ADMIN_CONSTANTS_H_ */
