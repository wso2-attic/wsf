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

#ifndef AXIOM_SOAP_CONST_H
#define AXIOM_SOAP_CONST_H

/**
* @file axiom_soap.h
* @brief defines SOAP constants
*/
#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axiom_soap SOAP
     * @ingroup axiom
     * @{
     * @}
     */
    typedef enum soap_version
    {
        AXIOM_SOAP_VERSION_NOT_SET = 0,

        AXIOM_SOAP11,

        AXIOM_SOAP12
    }axiom_soap_version;



    /** soap 11 constants */

#define AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI "http://schemas.xmlsoap.org/soap/envelope/"

#define AXIOM_SOAP11_ATTR_ACTOR "actor"

#define AXIOM_SOAP11_SOAP_FAULT_CODE_LOCAL_NAME "faultcode"

#define AXIOM_SOAP11_SOAP_FAULT_STRING_LOCAL_NAME "faultstring"

#define AXIOM_SOAP11_SOAP_FAULT_ACTOR_LOCAL_NAME "faultactor"

#define AXIOM_SOAP11_SOAP_FAULT_DETAIL_LOCAL_NAME "detail"

#define AXIOM_SOAP11_CONTENT_TYPE "text/xml"

#define AXIOM_SOAP11_FAULT_CODE_SENDER "Client"

#define AXIOM_SOAP11_FAULT_CODE_RECEIVER "Server"

#define AXIOM_SOAP11_SOAP_ACTOR_NEXT "http://schemas.xmlsoap.org/soap/actor/next"


    /** soap12 constants */

#define AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI "http://www.w3.org/2003/05/soap-envelope"

#define AXIOM_SOAP12_SOAP_ROLE "role"

#define AXIOM_SOAP12_SOAP_RELAY "relay"

#define AXIOM_SOAP12_SOAP_FAULT_CODE_LOCAL_NAME "Code"

#define AXIOM_SOAP12_SOAP_FAULT_SUB_CODE_LOCAL_NAME "Subcode"

#define AXIOM_SOAP12_SOAP_FAULT_VALUE_LOCAL_NAME "Value"

#define AXIOM_SOAP12_SOAP_FAULT_VALUE_VERSION_MISMATCH "VersionMismatch"

#define AXIOM_SOAP12_SOAP_FAULT_VALUE_MUST_UNDERSTAND "MustUnderstant"

#define AXIOM_SOAP12_SOAP_FAULT_VALUE_DATA_ENCODING_UKNOWN "DataEncodingUnknown"

#define AXIOM_SOAP12_SOAP_FAULT_VALUE_SENDER "Sender"

#define AXIOM_SOAP12_SOAP_FAULT_VALUE_RECEIVER "Receiver"

    /** SOAP Fault */

#define AXIOM_SOAP12_SOAP_FAULT_REASON_LOCAL_NAME "Reason"

#define AXIOM_SOAP12_SOAP_FAULT_TEXT_LOCAL_NAME "Text"

#define AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_LOCAL_NAME "lang"

#define AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_NS_URI "http://www.w3.org/XML/1998/namespace"

#define AXIOM_SOAP12_SOAP_FAULT_TEXT_LANG_ATTR_NS_PREFIX "xml"

#define AXIOM_SOAP12_SOAP_FAULT_NODE_LOCAL_NAME "Node"

#define AXIOM_SOAP12_SOAP_FAULT_DETAIL_LOCAL_NAME "Detail"

#define AXIOM_SOAP12_SOAP_FAULT_ROLE_LOCAL_NAME "Role"

#define AXIOM_SOAP12_CONTENT_TYPE "application/soap+xml"

#define AXIOM_SOAP12_FAULT_CODE_SENDER "Sender"

#define AXIOM_SOAP12_FAULT_CODE_RECEIVER "Receiver"

#define AXIOM_SOAP12_SOAP_ROLE_NEXT "http://www.w3.org/2003/05/soap-envelope/role/next"

#define AXIOM_SOAP12_SOAP_ROLE_NONE "http://www.w3.org/2003/05/soap-envelope/role/none"

#define SOAP12_SOAP_ROLE_ULTIMATE_RECEIVER "http://www.w3.org/2003/05/soap-envelope/role/ultimateReceiver"

#define AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX "soapenv"

#define AXIOM_SOAP_ENVELOPE_LOCAL_NAME "Envelope"

#define AXIOM_SOAP_HEADER_LOCAL_NAME "Header"

#define AXIOM_SOAP_BODY_LOCAL_NAME "Body"

#define AXIOM_SOAP_BODY_NAMESPACE_PREFIX AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX

#define AXIOM_SOAP_BODY_FAULT_LOCAL_NAME "Fault"

    /** attribute must understand */

#define AXIOM_SOAP_ATTR_MUST_UNDERSTAND "mustUnderstand"

#define AXIOM_SOAP_ATTR_MUST_UNDERSTAND_TRUE "true"

#define AXIOM_SOAP_ATTR_MUST_UNDERSTAND_FALSE "false"

#define AXIOM_SOAP_ATTR_MUST_UNDERSTAND_0 "0"

#define AXIOM_SOAP_ATTR_MUST_UNDERSTAND_1 "1"

#define AXIOM_SOAP_FAULT_LOCAL_NAME "Fault"

#define AXIOM_SOAP_FAULT_DETAIL_LOCAL_NAME "detail"

#define AXIOM_SOAP_FAULT_NAMESPACE_PREFIX AXIOM_SOAP_DEFAULT_NAMESPACE_PREFIX

#define AXIOM_SOAP_FAULT_DETAIL_EXCEPTION_ENTRY "Exception"

#define AXIOM_SOAP_FAULT_CODE_VERSION_MISMATCH "env:VersionMismatch"

#define AXIOM_SOAP_FAULT_CODE_MUST_UNDERSTAND "env:MustUnderstand"

#define AXIOM_SOAP_FAULT_CODE_DATA_ENCODING_UNKNOWN "env:DataEncodingUnknown"

#define AXIOM_SOAP_FAULT_CODE_SENDER ""

#define AXIOM_SOAP_FAULT_CODE_RECEIVER ""

    /* MTOM related  */

#define AXIS2_XOP_NAMESPACE_URI "http://www.w3.org/2004/08/xop/include"

#define AXIS2_XOP_INCLUDE "Include"
    /** @} */

#ifdef __cplusplus
}
#endif

#endif /* AXIOM_SOAP_CONSTANTS_H */
