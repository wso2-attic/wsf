/*
 * Copyright 2005,2006 WSO2, Inc. http://www.wso2.org
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


//values for soap versions
#define WSREQUEST_SOAP_VER_1_1       1.1
#define WSREQUEST_SOAP_VER_1_2       1.2

#define SOAP_VERSION_1_1 "1.1"
#define SOAP_VERSION_1_2 "1.2"

#define WSREQUEST_SOAP_VER_UNKNOWN   1.2
#define WSREQUEST_COMPARE_SOAP_VERSIONS( ver1, ver2)  (ver1)-(ver2) < 0.1 

//values for options
#define WSPREQUEST_OPT_WSA_ACTION "Action"
#define WSREQUEST_OPT_USE_SOAP "useSOAP"
#define WSREQUEST_OPT_USE_WSA "useWSA"
#define WSREQUEST_HTTP_METHOD "HTTPMethod"
#define WSREQUEST_OPT_FROM "From"
#define WSREQUEST_OPT_REPLY_TO "ReplyTo"
#define WSREQUEST_OPT_FAULT_TO "FaultTo"

#define TRUE "1"
#define FALSE "0"

#define WSREQUEST_HTTP_METHOD_POST "POST"
#define WSREQUEST_HTTP_METHOD_GET "GET"

#define WSREQUEST_HTTP_METHOD_POST_LOWER "post"
#define WSREQUEST_HTTP_METHOD_GET_LOWER "get"


// default http method - post
#define WSREQUEST_HTTP_METHOD_DEFAULT "POST"

// WSA options
#define WSREQUEST_WSA_VERSION 1.0
#define WSREQUEST_WSA_1_0 "1.0"
#define WSREQUEST_WSA_SUBMISSION "submissions" //change this ...??

//values for readyState
#define WSREQUEST_UNINITIALIZED   0
#define WSREQUEST_OPENED          1	
#define WSREQUEST_LOADED          2
#define WSREQUEST_INTERACTIVE     3
#define WSREQUEST_COMPLETED       4

//values for the http transport status
#define WSREQUEST_HTTP_STATUS_FAILURE 500
#define WSREQUEST_HTTP_STATUS_SUCCESS 200


