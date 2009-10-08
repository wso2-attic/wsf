/*
 * Copyright 2005-2009 WSO2, Inc. http://wso2.com
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

#ifndef WSFERROR_H
#define WSFERROR_H
#include <Environment.h>

/**
 * @file WSFError.h
 * @brief Defines WSF/CPP specific error codes.
 */

/**@defgroup WSFError WSFError
 * @ingroup wso2wsf
 * {
 * }
 */

/**
 * Macro to use for logging user level information.
 */
#define WSF_LOG_USER_MSG axutil_log_impl_log_user
/**
 * Macro to use for logging debug information.
 */
#define WSF_LOG_DEBUG_MSG axutil_log_impl_log_debug
/**
 * Macro to use for logging information.
 */   
#define WSF_LOG_INFO_MSG axutil_log_impl_log_info
/**
 * Macro to use for logging warnings.
 */
#define WSF_LOG_WARNING_MSG axutil_log_impl_log_warning
/**
 * Macro to use for logging errors.
 */
#define WSF_LOG_ERROR_MSG axutil_log_impl_log_error
/**
 * Macro to use for logging critical issues. critical usually means the server of client failure.
 */
#define WSF_LOG_CRITICAL_MSG axutil_log_impl_log_critical
/**
 * Macro to use for logging trace information.
 */
#define WSF_LOG_TRACE_MSG axutil_log_impl_log_trace
/**
 * Maps AXIS2_LOG_SI macro which writes the source information to the log file ( Line number and file name ) to WSF_LOG_SI
 */
#define WSF_LOG_SI AXIS2_LOG_SI
/**
 *  Creation of the execution environment failed. 
 */
#define CREATION_OF_EXECUTION_ENVIRONMENT_FAILED "Creation of Execution Environment Failed"
/**
 * Instantiation of NeethiPolicy Object filed. Could be due to invalid xml input, invalid policy.
 */
#define CREATION_OF_NEETHI_POLICY_OBJECT_FAILED "Unable to create NeethiPolicy object"
/**
 * Instantiation of OMAttribute Object failed.
 */
#define CREATION_OF_OM_ATTRIBUTE_OBJECT_FAILED "Unable to create OMAttribute object"
/**
 * Creation of OMDataHandler Object failed.
 */
#define CREATION_OF_OM_DATA_HANDLER_OBJECT_FAILED "Unable to create OMDataHandler object"
/**
 * Creation of OMElement Object failed.
 */
#define CREATION_OF_OM_ELEMENT_OBJECT_FAILED "Unable to create OMElement object"
/**
 * Creation of OMNamespace object failed.
 */
#define CREATION_OF_OM_NAMESPACE_OBJECT_FAILED "Unable to create OMNamespace object"
/**
 * Creation of OMText Object failed.
 */
#define CREATION_OF_OM_TEXT_OBJECT_FAILED "Unable to create OMText object"
/**
 * Iinitialization of Service Client Failed. Can be due to a. Incorrect repository path.
 * b. Missing axis2.xml file in the repository.
 * c. Library loading issues to missing dependancy DLLs in the path.
 */
#define CREATION_OF_SERVICE_CLIENT_FAILED "Initialization of Service Client Failed"
/**
 * Creation of Service Client Options Failed.
 */
#define CREATION_OF_SERVICE_CLIENT_OPTIONS_FAILED "Creation of Service Options Failed"
/**
 * Creation of Callback Object failed.
 */
#define CREATION_OF_CALLBACK_OBJECT_FAILED "Creation of Callback Failed"
/**
 * Setting of service client options failed.
 */
#define SETTING_UP_SERVICE_CLIENT_OPTIONS_FAILED "Setting up Options Failed"
/**
 *Setting SOAP Action failed
 */
#define SETTING_SOAP_ACTION_FAILED "Failure occured while setting SOAP Action"
/**
 *Setting WSA Action failed.
 */
#define SETTING_WSA_ACTION_FAILED "Failure occured while setting Web Services Addressing (WSA) Action"
/**
 *Send Receive Operation Failed. This can be due to multiple situations. Check the log files for more details
 * on the error occured
 */
#define SEND_RECIEVE_OPERATION_FAILED "Send Recieve Operation Failed"
/**
 * Send Robust Operation failed.
 */
#define ROBUST_SEND_OPERATION_FAILED "Robust Send Operation Failed"
/**
 * Retrival of the response Object failed.
 */
#define UNABLE_TO_RETRIEVE_RESPONSE_ELEMENT "Unable to retrieve Response Element"
/**
 *Received a SOAP fault as the response.
 */
#define SOAP_FAULT_RECIEVED "A SOAP Fault Occured"
/**
 * Empty payload has been provided to the service client object.
 */
#define EMPTY_PAYLOAD_RECIEVED "Empty Payload"

#endif // WSFERROR_H

