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

#ifndef	AXIS2_IIS_CONSTANTS_H
#define AXIS2_IIS_CONSTANTS_H

#define INTERNET_MAX_PATH_LENGTH        2048
#define INTERNET_MAX_SCHEME_LENGTH      32          // longest protocol name length
#define INTERNET_MAX_URL_LENGTH         (INTERNET_MAX_SCHEME_LENGTH \
                                        + sizeof("://") \
                                        + INTERNET_MAX_PATH_LENGTH)

#define URI_MATCHED						1
#define URI_UN_MATCHED					2

#define EXTENSION_URL					"/axis2/mod_axis2_IIS.dll\? "
#define EXTENSION_URL_AXIS2				"/axis2/"
#define EXTENSION_URL_MODIIS			"mod_axis2_IIS.dll\? "


#define MAX_SERVERNAME					128
#define MAX_PORT_LEN					8

#define MAX_HTTP_VERSION_LEN			16
#define MAX_HTTP_CONTENT_TYPE_LEN		2048
#define MAX_CONTENT_ENCODING_LEN		16
#define MAX_HTTP_METHOD_LEN				8
#define MAX_TCP_PORT_LEN				8
#define MAX_CONTENT_LEN					16

#define OK								200
#define HTTP_INTERNAL_SERVER_ERROR		500
#define HTTP_ACCEPTED					202


#endif			/*AXIS2_IIS_CONSTANTS_H*/

