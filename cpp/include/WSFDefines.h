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

#ifndef WSFDEFINES_H
#define WSFDEFINES_H


#include <axutil_utils_defines.h>

/**
 * @file WSFDefines.h
 * @brief Definitions for WSF/CPP Project
 */

/**
 * @defgroup WSF/CPP Project
 * @{
 * @}
 */

/** \mainpage WSF/CPP API Documentation
 * 
 * \section intro_sec Introduction 
 * This is the API documentation for WSF/CPP Project. A C++ Binding for the popular Web Services Library
 * <a href="http://wso2.org/projects/wsf/c">WSF/C</a>. WSF/CPP bring to the C++ world, not only the capability 
 * to handle Basic Web Services, but also the Advanced Web Services Sepecifcation Implementations including 
 * WS-Security, WS-Reliable Messaging WS-Addressing and WS-Eventing.
 * Being a lightweight framework with support for mulitiple transport protocols including, http, https, amqp, xmpp ...
 * WSF/CPP bring the flexibility the C++ Developers are looking for when trying to intergrate their lagacy applications and
 * to Web Service Enable their CPP applications. 
 * <p> We Welcome your feedback on this implementation and documentation. Please send your feedback to <a href="mailto:wsf-cpp-user@wso2.org">
 * wsf-cpp-user@wso2.org</a>. 
 * </p>
 */

#define WSF_EXTERN AXIS2_EXTERN
#define WSF_CALL AXIS2_CALL
#define WSF_USLEEP AXIS2_USLEEP
#define WSF_SLEEP AXIS2_SLEEP

#endif // WSFDEFINES_H
