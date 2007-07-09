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

#ifndef AXIS2_CONST_H
#define AXIS2_CONST_H

/**
 * @file axis2.h
 * @brief Axis2c specific global declarations
 */

#include <axutil_env.h>
#include <axutil_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif


/** @defgroup axis2 Axis2/C project
  * @{
  * @}
  */
    
/** \mainpage Axis2/C API Documentation
  *
  * \section intro_sec Introduction
  *
  * This is the API documetation of Axis2/C, a SOAP engine written in C.
  * This implementation is based on the popular Axis2 architecture. 
  * <p>We welcome your feedback on this implementation and documentation.
  * Please send your feedback to <a href="mailto:axis-c-user@ws.apache.org">
  * axis-c-user@ws.apache.org</a> and please remember to prefix the subject
  * of the mail with [Axis2].
  *
  */    
    
/******************************************************************************/
/********************Axis2 specific constants**********************************/
/******************************************************************************/


/**
 * Field SOAP_STYLE_RPC_ENCODED
 */
#define AXIOM_SOAP_STYLE_RPC_ENCODED 1000

/**
 * Field SOAP_STYLE_RPC_LITERAL
 */
/*#define AXIOM_SOAP_STYLE_RPC_LITERAL 1001 */

/**
 * Field SOAP_STYLE_DOC_LITERAL_WRAPPED
 */
#define AXIOM_SOAP_STYLE_DOC_LITERAL_WRAPPED 1002

#define AXIS2_SCOPE "scope"

/**
 * Field APPLICATION_SCOPE
 */
#define AXIS2_APPLICATION_SCOPE "application"

/**
 * Field SESSION_SCOPE
 */
#define AXIS2_SESSION_SCOPE "session"

/**
 * Field GLOBAL_SCOPE
 */
#define AXIS2_MESSAGE_SCOPE "message"

/**
 * Field PHASE_SERVICE
 */
#define AXIS2_PHASE_SERVICE "service"

/**
 * Field PHASE_TRANSPORT
 */
#define AXIS2_PHASE_TRANSPORT "transport"

/**
 * Field PHASE_GLOBAL
 */
#define AXIS2_PHASE_GLOBAL "global"

/**
 * Field SESSION_CONTEXT_PROPERTY
 */
#define AXIS2_SESSION_CONTEXT_PROPERTY "SessionContext"

/**
 * TRANSPORT constants
 */
#define AXIS2_TRANSPORT_HTTP "http"
#define AXIS2_TRANSPORT_SMTP "smtp"
#define AXIS2_TRANSPORT_TCP "tcp"
#define AXIS2_TRANSPORT_XMPP "xmpp"
#define AXIS2_TRANSPORT_HTTPS "https"
typedef enum
{
    AXIS2_TRANSPORT_ENUM_HTTP = 0,
    AXIS2_TRANSPORT_ENUM_SMTP,
    AXIS2_TRANSPORT_ENUM_TCP,
    AXIS2_TRANSPORT_ENUM_XMPP,
	AXIS2_TRANSPORT_ENUM_HTTPS,
    AXIS2_TRANSPORT_ENUM_MAX
} AXIS2_TRANSPORT_ENUMS;

/**
 * Field LISTSERVICES
 */
#define AXIS2_REQUEST_URL_PREFIX "/services"

#define AXIS2_LISTSERVICES "listServices"

#define AXIS2_LIST_SERVICE_FOR_MODULE_ENGAMNET "listop"


/**
 * List service for adminpagse
 */
#define AXIS2_ADMIN_LISTSERVICES "listService"

#define AXIS2_LIST_MODULES "listModules"

#define AXIS2_LIST_GLOABLLY_ENGAGED_MODULES "globalModules"

#define AXIS2_LIST_PHASES "listPhases"

#define AXIS2_ENGAGE_GLOBAL_MODULE "engagingglobally"
#define AXIS2_ENGAGE_MODULE_TO_SERVICE "engageToService"

#define AXIS2_ENGAGE_MODULE_TO_SERVICE_GROUP "engageToServiceGroup"

#define AXIS2_ADMIN_LOGIN "adminlogin"

#define AXIS2_LIST_CONTEXTS "listContexts"
#define AXIS2_LOGOUT "logout"

#define AXIS2_VIEW_GLOBAL_HANDLERS "viewGlobalHandlers"
#define AXIS2_SELECT_SERVICE "selectService"
#define AXIS2_EDIR_SERVICE_PARA "editServicepara"
#define AXIS2_SELECT_SERVICE_FOR_PARA_EDIT "selectServiceParaEdit"
#define AXIS2_VIEW_SERVICE_HANDLERS "viewServiceHandlers"
#define AXIS2_LIST_SERVIC_GROUPS "listServciceGroups"

/**
 * Field SERVICE_MAP
 */
#define AXIS2_SERVICE_MAP "servicemap"
#define AXIS2_SERVICE_GROUP_MAP "serviceGroupmap"

#define AXIS2_CONFIG_CONTEXT "config_context"
#define AXIS2_ACTION_MAPPING "actionMapping"
#define AXIS2_OUTPUT_ACTION_MAPPING "outputActionMapping"
#define AXI2_FAULT_ACTION_MAPPING "faultActionMapping"
    
#define AXIS2_SERVICE "service"

#define AXIS2_OPEARTION_MAP "opmap"
/**
 * Field Available modules
 */
#define AXIS2_MODULE_MAP "modulemap"

#define AXIS2_SELECT_SERVICE_TYPE "SELECT_SERVICE_TYPE"

#define AXIS2_GLOBAL_HANDLERS "axisconfig"
#define AXIS2_SERVICE_HANDLERS "serviceHandlers"

#define AXIS2_PHASE_LIST "phaseList"

#define AXIS2_LIST_OPS_FOR_THE_SERVICE "listOperations"

#define AXIS2_REMOVE_SERVICE "removeService"

#define AXIS2_ENGAGE_STATUS "engagestatus"

/**
 * Errorness servcie
 */
#define AXIS2_ERROR_SERVICE_MAP "errprservicemap"
#define AXIS2_ERROR_MODULE_MAP "errormodulesmap"

#define AXIS2_IS_FAULTY "Fault"

#define AXIS2_MODULE_ADDRESSING "addressing"

#define AXIS2_USER_NAME "userName"
#define AXIS2_PASSWORD "password"

/**
 * Field SINGLE_SERVICE
 */
#define AXIS2_SINGLE_SERVICE "singleservice"
#define AXIS2_WSDL_CONTENT "wsdl"
#define AXIS2_REQUEST_WSDL "?wsdl"

#define AXIS2_STYLE_RPC  "rpc"
#define AXIS2_STYLE_DOC  "doc"
#define AXIS2_STYLE_MSG  "msg"

typedef enum axis2_wsdl_msg_labels 
{
    AXIS2_WSDL_MESSAGE_LABEL_IN = 0,
    AXIS2_WSDL_MESSAGE_LABEL_OUT,
    AXIS2_WSDL_MESSAGE_LABEL_MAX
}axis2_wsdl_msg_labels_t;

/*********************Message Exchange Pattern Constants***********************/
/**
 * Field MEP_URI_IN_ONLY
 */
#define AXIS2_MEP_URI_IN_ONLY "http://www.w3.org/2004/08/wsdl/in-only"

#define AXIS2_MEP_CONSTANT_IN_ONLY 10

/**
 * Field MEP_URI_ROBUST_IN_ONLY
 */
#define AXIS2_MEP_URI_ROBUST_IN_ONLY "http://www.w3.org/2004/08/wsdl/robust-in-only"

#define AXIS2_MEP_CONSTANT_ROBUST_IN_ONLY 11

/**
 * Field MEP_URI_IN_OUT
 */
#define AXIS2_MEP_URI_IN_OUT "http://www.w3.org/2004/08/wsdl/in-out"

#define AXIS2_MEP_CONSTANT_IN_OUT 12

/**
 * Field MEP_URI_IN_OPTIONAL_OUT
 */
#define AXIS2_MEP_URI_IN_OPTIONAL_OUT "http://www.w3.org/2004/08/wsdl/in-opt-out"

#define AXIS2_MEP_CONSTANT_IN_OPTIONAL_OUT 13

/**
 * Field MEP_URI_OUT_ONLY
 */
#define AXIS2_MEP_URI_OUT_ONLY "http://www.w3.org/2004/08/wsdl/out-only"

#define AXIS2_MEP_CONSTANT_OUT_ONLY 14

/**
 * Field MEP_URI_ROBUST_OUT_ONLY
 */
#define AXIS2_MEP_URI_ROBUST_OUT_ONLY "http://www.w3.org/2004/08/wsdl/robust-out-only"

#define AXIS2_MEP_CONSTANT_ROBUST_OUT_ONLY 15

/**
 * Field MEP_URI_OUT_IN
 */
#define AXIS2_MEP_URI_OUT_IN "http://www.w3.org/2004/08/wsdl/out-in"

#define AXIS2_MEP_CONSTANT_OUT_IN 16

/**
 * Field MEP_URI_OUT_OPTIONL_IN
 */
#define AXIS2_MEP_URI_OUT_OPTIONAL_IN "http://www.w3.org/2004/08/wsdl/out-opt-in"

#define AXIS2_MEP_CONSTANT_OUT_OPTIONAL_IN 17

#define AXIS2_MEP_CONSTANT_INVALID -1

/**
 * Field WSDL_MESSAGE_DIRECTION_IN
 */
#define AXIS2_WSDL_MESSAGE_DIRECTION_IN "in"


/**
 * Field WSDL_MESSAGE_DIRECTION_OUT
 */
#define AXIS2_WSDL_MESSAGE_DIRECTION_OUT "out"


/**
 * Field METHOD_NAME_ESCAPE_CHARACTOR
 */
/* static const char METHOD_NAME_ESCAPE_CHARACTOR '?' */

#define AXIS2_LOGGED "Logged"


/* static const char SERVICE_NAME_SPLIT_CHAR':' */


/*********************Configuration *******************************************/

#define AXIS2_ENABLE_REST "enableREST"
#define AXIS2_ENABLE_REST_THROUGH_GET "restThroughGet"
/* globally enable MTOM */
#define AXIS2_ENABLE_MTOM "enableMTOM"
#define AXIS2_ATTACHMENT_TEMP_DIR "attachmentDIR"
#define AXIS2_CACHE_ATTACHMENTS "cacheAttachments"
#define AXIS2_FILE_SIZE_THRESHOLD "sizeThreshold"
/* op_ctx persistance */
#define AXIS2_PERSIST_OP_CTX "persistOperationContext"

/******************************************************************************/

#define AXIS2_VALUE_TRUE "true"
#define AXIS2_VALUE_FALSE "false"
#define AXIS2_CONTAINER_MANAGED "ContainerManaged"
#define AXIS2_RESPONSE_WRITTEN "CONTENT_WRITTEN"

#define AXIS2_TESTING_PATH "target/test-resources/"

#define AXIS2_TESTING_REPOSITORY "target/test-resources/samples"

/* Indicate whether the axis2 service should be loaded at start up */
#define AXIS2_LOAD_SVC_STARTUP "loadServiceAtStartup"


/*************************** REST_WITH_GET ************************************/

#define AXIS2_GET_PARAMETER_OP "op"
#define AXIS2_GET_PARAMETER_URL "http://ws.apache.org/goGetWithREST"

/******************************************************************************/


#define AXIS2_NAMESPACE_PREFIX "axis2"
#define AXIS2_NAMESPACE_URI "http://ws.apache.org/namespaces/axis2"

#define AXIS2_SVC_GRP_ID "ServiceGroupId"    


#define AXIS2_RESPONSE_SOAP_ENVELOPE "Axis2ResponseEnvelope"    
#define AXIS2_HANDLER_ALREADY_VISITED "handler_already_visited"

#ifdef __cplusplus
}
#endif

#endif /* AXIS2_CONST_H */
