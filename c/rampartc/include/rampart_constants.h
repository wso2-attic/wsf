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


#ifndef RAMPART_CONSTANTS_H
#define RAMPART_CONSTANTS_H

/**
  * @file rampart_constants.h
  * @brief Holds constants for rampart
  */

#include <oxs_constants.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /*Default values*/
#define RAMPART_DEFAULT_KT_ALGO OXS_DEFAULT_KT_ALGO_HREF
#define RAMPART_STR_DEFAULT OXS_STR_DEFAULT

    /* rampart element names*/
#define RAMPART_SECURITY "Security"
#define RAMPART_SECURITY_USERNAMETOKEN "UsernameToken"
#define RAMPART_SECURITY_USERNAMETOKEN_USERNAME "Username"
#define RAMPART_SECURITY_USERNAMETOKEN_PASSWORD "Password"
#define RAMPART_SECURITY_USERNAMETOKEN_CREATED "Created"
#define RAMPART_SECURITY_USERNAMETOKEN_NONCE "Nonce"
#define RAMPART_SECURITY_USERNAMETOKEN_PASSWORD_ATTR_TYPE "Type"
#define RAMPART_SECURITY_TIMESTAMP "Timestamp"
#define RAMPART_SECURITY_TIMESTAMP_CREATED "Created"
#define RAMPART_SECURITY_TIMESTAMP_EXPIRES "Expires"
#define RAMPART_RAMPART "rampart"

    /*Rampart URIs*/
#define RAMPART_WSSE "wsse"
#define RAMPART_WSSE_XMLNS "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd"
#define RAMPART_WSU "wsu"
#define RAMPART_WSU_XMLNS "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd"
#define RAMPART_PASSWORD_DIGEST_URI "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordDigest"

#define RAMPART_PASSWORD_TEXT_URI "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordText"


#define RAMPART_INFLOW_SECURITY_POLICY              "InflowSecurityPolicy"
#define RAMPART_OUTFLOW_SECURITY_POLICY             "OutflowSecurityPolicy"

#define INFLOW_RAMPART_CONTEXT                      "InflowRampartContext"
#define OUTFLOW_RAMPART_CONTEXT                     "OutflowRampartContext"

#define RAMPART_CONTEXT                             "RampartContext"

#define IN_MESSAGE_SECURITY                          "InMessageSecurity"
#define OUT_MESSAGE_SECURITY                         "OutMessageSEcurity"
#define RAMPART_PASSWORD_TEXT                       "plainText"
#define RAMPART_PASSWORD_DIGEST                     "Digest"
#define RAMPART_CONFIGURATION                       "RampartConfiguration"

    /************fault codes***************/
#define RAMPART_FAULT_UNSUPPORTED_SECURITY_TOKEN    "wsse:UnsupportedSecurityToken"
#define RAMPART_FAULT_UNSUPPORTED_ALGORITHM         "wsse:UnsupportedAlgorithm"
#define RAMPART_FAULT_INVALID_SECURITY              "wsse:InvalidSecurity"
#define RAMPART_FAULT_INVALID_SECURITY_TOKEN        "wsse:InvalidSecurityToken"
#define RAMPART_FAULT_FAILED_AUTHENTICATION         "wsse:FailedAuthentication"
#define RAMPART_FAULT_FAILED_CHECK                  "wsse:FailedCheck"
#define RAMPART_FAULT_SECURITY_TOKEN_UNAVAILABLE    "wsse:SecurityTokenUnavailable"

    /***********fault related strings*********/
#define RAMPART_FAULT_IN_TIMESTAMP             "wsse:Timestamp"
#define RAMPART_FAULT_IN_USERNAMETOKEN         "wsse:UsernameToken"
#define RAMPART_FAULT_IN_ENCRYPTED_KEY         "xenc:EncryptedKey"
#define RAMPART_FAULT_IN_ENCRYPTED_DATA        "xenc:EncryptedData"
#define RAMPART_FAULT_IN_SIGNATURE             "ds:Signature"
#define RAMPART_FAULT_MSG_REPLAYED             "rampc:Message-Replayed"

    /*Dynamically set values*/
#define RAMPART_ACTION_PASSWORD "password"
#define RAMPART_ACTION_ENC_USER_PASSWORD "encUserPassword"
#define RAMPART_CALLBACK_SPECIFIC_PROPERTY "callbackSpecificProperty"

    /*Security processed results*/
#define RAMPART_SECURITY_PROCESSED_RESULTS "SecurityProcessedResults"
#define RAMPART_SPR_UT_USERNAME "SPR_UT_username"
#define RAMPART_SPR_UT_CREATED "SPR_UT_created"
#define RAMPART_SPR_UT_NONCE "SPR_UT_nonce"
#define RAMPART_SPR_UT_PASSWORD_TYPE "SPR_UT_passwordType"
#define RAMPART_SPR_TS_CREATED "SPR_TS_created"
#define RAMPART_SPR_TS_EXPIRES "SPR_TS_expires"
#define RAMPART_SPR_UT_CHECKED "SPR_UT_Checked"
#define RAMPART_SPR_TS_CHECKED "SPR_TS_Checked"
#define RAMPART_SPR_ENC_CHECKED "SPR_ENC_Checked"

#define RAMPART_YES "YES"
#define RAMPART_NO "NO"

#define RAMPART_STR_DIRECT_REFERENCE    OXS_STR_DIRECT_REFERENCE
#define RAMPART_STR_KEY_IDENTIFIER      OXS_STR_KEY_IDENTIFIER
#define RAMPART_STR_EMBEDDED            OXS_STR_EMBEDDED
#define RAMPART_STR_ISSUER_SERIAL       OXS_STR_ISSUER_SERIAL
#define RAMPART_STR_THUMB_PRINT         OXS_STR_THUMB_PRINT
#define RAMPART_STR_EXTERNAL_URI        OXS_STR_EXTERNAL_URI
#define RAMPART_STR_ENCRYPTED_KEY       OXS_STR_ENCRYPTED_KEY

#define RAMPART_RD_DB_PROP "Rampart_RD_DB_Prop"
#define RAMPART_RD_DEF_VALID_DURATION 60
#define RAMPART_RD_DEF_MAX_RCDS 5
#ifdef __cplusplus
}
#endif

#endif /* RAMPART_CONSTANTS_H*/
