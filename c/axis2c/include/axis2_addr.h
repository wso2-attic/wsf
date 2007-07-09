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

#ifndef AXIS2_ADDR_H
#define AXIS2_ADDR_H

#ifdef __cplusplus
extern "C"
{
#endif

/** 
  * @defgroup axis2_addr WS-Addressing
  * @ingroup axis2
  * @{
  * @}
  */

/**
  * @defgroup axis2_addr_consts WS-Addressing related constants
  * @ingroup axis2_addr
  * @{
  */

    /* ====================== Common Message Addressing Properties ===========*/
    #define AXIS2_WSA_MESSAGE_ID "MessageID"
    #define AXIS2_WSA_RELATES_TO "RelatesTo"
    #define AXIS2_WSA_RELATES_TO_RELATIONSHIP_TYPE "RelationshipType"
    #define AXIS2_WSA_TO "To"
    #define AXIS2_WSA_FROM "From"
    #define AXIS2_WSA_REPLY_TO "ReplyTo"
    #define AXIS2_WSA_FAULT_TO "FaultTo"
    #define AXIS2_WSA_ACTION "Action"
    #define AXIS2_WSA_MAPPING "wsamapping"

    /* ====================== Common EPR Elements ============================*/
    #define EPR_ADDRESS "Address"
    #define EPR_REFERENCE_PARAMETERS "ReferenceParameters"
    #define EPR_SERVICE_NAME "ServiceName"

    /* ====================== Addressing Submission Version Constants ========*/
    #define AXIS2_WSA_NAMESPACE_SUBMISSION "http://schemas.xmlsoap.org/ws/2004/08/addressing"
    #define AXIS2_WSA_RELATES_TO_RELATIONSHIP_TYPE_DEFAULT_VALUE_SUBMISSION "wsa:Reply"
    #define AXIS2_WSA_ANONYMOUS_URL_SUBMISSION "http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous"
    #define AXIS2_WSA_NONE_URL_SUBMISSION "http://schemas.xmlsoap.org/ws/2004/08/addressing/role/none"

    #define EPR_REFERENCE_PROPERTIES "ReferenceProperties"
    #define EPR_PORT_TYPE "PortType"
    #define EPR_SERVICE_NAME_PORT_NAME "PortName"

    /* =====================Addressing 1.0 Final Version Constants ===========*/
    #define AXIS2_WSA_NAMESPACE "http://www.w3.org/2005/08/addressing"
    #define AXIS2_WSA_RELATES_TO_RELATIONSHIP_TYPE_DEFAULT_VALUE "http://www.w3.org/2005/08/addressing/reply"
    #define AXIS2_WSA_ANONYMOUS_URL "http://www.w3.org/2005/08/addressing/anonymous"
    #define AXIS2_WSA_NONE_URL "http://www.w3.org/2005/08/addressing/none"

    #define AXIS2_WSA_IS_REFERENCE_PARAMETER_ATTRIBUTE "IsReferenceParameter"
    #define AXIS2_WSA_TYPE_ATTRIBUTE_VALUE "true"

    #define AXIS2_WSA_INTERFACE_NAME "InterfaceName"
    #define AXIS2_WSA_SERVICE_NAME_ENDPOINT_NAME "EndpointName"
    #define AXIS2_WSA_POLICIES "Policies"
    #define AXIS2_WSA_METADATA "Metadata"
        
    /* =======================================================================*/

    #define AXIS2_WSA_VERSION "WSAddressingVersion"
    #define AXIS2_WSA_DEFAULT_PREFIX "wsa"

    #define PARAM_SERVICE_GROUP_CONTEXT_ID "ServiceGroupContextIdFromAddressing"

/** @} */
    
#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_ADDR_H */
