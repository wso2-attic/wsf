/*
 * Copyright 2005,2010 WSO2, Inc. http://wso2.com
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

#ifndef WSF_XML_MSG_RECV_H
#define WSF_XML_MSG_RECV_H

#include "wsf_common.h"

WSF_PHP_API axis2_msg_recv_t *WSF_CALL 
wsf_xml_msg_recv_create (
    const axutil_env_t * env);

#endif /* WS_XML_MSG_RECV_H */
