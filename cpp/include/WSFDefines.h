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

/** 
 * \mainpage WSF/CPP API Documentation
 * \image html "../../images/wsf_cpp_logo.gif" 
 *
 * \section intro_sec Introduction 
 * This is the API documentation for WSF/CPP Project. A C++ Binding for the popular Web Services Library
 * <a href="http://wso2.org/projects/wsf/c">WSF/C</a>. WSF/CPP bring to the C++ world, not only the capability 
 * to handle Basic Web Services, but also the ability add qualities of services such as security and reliable messaging.
 * Being a lightweight framework with support for mulitiple transport protocols including, HTTP, HTTPS, AMQP, XMPP,UDP,TCP
 * WSF/CPP bring the flexibility the C++ Developers are looking for, When trying to intergrate their lagacy applications and
 * Web Service enable their C++ applications. 
 *
 * \section feature_sec Features available in this Release
 *
 *<table>
 *   <tr>
 *     <th>Feature</th>
 *     <th><p>Description</p>
 *     </th>
 *   </tr>
 *   <tr valign="top">
 *     <td width="145"><p>Comprehensive Support for Web Services Standards</p>
 *     </td>
 *     <td width="502"><p>WSO2 WSF/C++ supports the basic Web Services standards
 *       including SOAP 1.1, SOAP 1.2 and MTOM.</p>
 *
 *       <p>WSF/C++ also supports the following WS-* specifications:</p>
 *
 *       <ul>
 *         <li><p>WS-Addressing</p>
 *         </li>
 *         <li><p>WS-Policy</p>
 *         </li>
 *         <li><p>WS-Security</p>
 *         </li>
 *
 *         <li><p>WS-SecurityPolicy</p>
 *         </li>
 *       </ul>
 *     </td>
 *   </tr>
 *   <tr valign="top">
 *     <td width="145"><p>Portability and Platform Support</p>
 *     </td>
 *     <td width="502"><p>WSO2 WSF/C++ has been tested on:</p>
 *       <ul>
 *         <li><p>Windows XP - Microsoft Visual C++ 7.1</p></li>
 *         <li><p>Windows XP - Microsoft Visual C++ 8.0</p></li>
 *         <li><p>Windows XP - Microsoft Visual C++ 9.0</p></li>
 *         <li><p>Linux – gcc/g++ 4.3.2</p></li>
 *         <li><p>Sun Solaris 2.10 x86 - gcc 3.4.3</p></li>
 *          <li><p>MacOS 10.4.10 - gcc/g++ 4.0.1</p></li>
 *        </ul>
 *      </td>
 *    </tr>
 *    <tr valign="top">
 *     <td width="145"><p>WSDL2CPP Codegeneration</p>
 *     </td>
 *     <td width="502"><p>WSO2 WSF/C++ comes with code generation tool which generates client stubs and
 *       service skeletons  for a given wsdl.</p>
 *     </td>
 *   </tr>
 *   <tr valign="top">
 *     <td width="145"><p>Other Features inherited from WSF/C</p>
 *   <tr valign="top">
 *     <td width="145"><p>Web Server Extensions</p>
 *     </td>
 *     <td width="502"><p>WSO2 WSF/C++ can be deployed as a server-side
 *       extension within a Web server, such as Apache Web Server or Microsoft
 *       IIS. It also includes an HTTP server and can be deployed as a
 *       stand-alone server.</p>
 *     </td>
 *   </tr>
 *   <tr valign="top">
 *     <td width="145"><p>Other Features inherited from WSF/C</p>
 *     </td>
 *     <td width="502"><p>WSO2 WSF/C++ Inherits an array of features from it's 
 *       base, WSO2 WSF/C such as,
 *       <ul>
 *       <li>Proven Interoperability</li>
 *       <li>Transport Abstraction</li>
 *       <li>XML Parser Abstraction</li>
 *       <li>WSDL2C Code Generation</li>
 *		</ul>
 *     </td>
 *   </tr>
 *</table>
 *
 *\section feedback_sec Feedback
 * <p> We Welcome your feedback on this implementation and documentation. Please send your feedback to <a href="mailto:wsf-cpp-user@wso2.org">
 * wsf-cpp-user@wso2.org</a></p>
 */

/** Map os dependent export macro to WSF */
#define WSF_EXTERN AXIS2_EXTERN
/** Map Axis2 Calling convention to WSF */
#define WSF_CALL AXIS2_CALL
/** Define AXIS2_USLEEP as WSF_USLEEP */
#define WSF_USLEEP AXIS2_USLEEP
/** Define AXIS2_SLEEP as WSF_SLEEP */
#define WSF_SLEEP AXIS2_SLEEP

/** Log Levels */
/** Critical level, logs only critical errors */
#define WSF_LOG_LEVEL_CRITICAL AXIS2_LOG_LEVEL_CRITICAL

/** Error level, logs only errors */
#define WSF_LOG_LEVEL_ERROR AXIS2_LOG_LEVEL_ERROR

/** Warning level, logs only warnings */
#define WSF_LOG_LEVEL_WARNING AXIS2_LOG_LEVEL_WARNING

/** Info level, logs information */
#define WSF_LOG_LEVEL_INFO AXIS2_LOG_LEVEL_INFO

/** Debug level, logs everything */
#define WSF_LOG_LEVEL_DEBUG AXIS2_LOG_LEVEL_DEBUG

/** User level, logs only user level debug messages */
#define WSF_LOG_LEVEL_USER AXIS2_LOG_LEVEL_USER

/** Trace level, Enable with compiler time option AXIS2_TRACE */
#define WSF_LOG_LEVEL_TRACE AXIS2_LOG_LEVEL_TRACE

#define AxisFault WSFault

#endif // WSFDEFINES_H
