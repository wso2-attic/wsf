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

#ifndef _AXIS2_GETOPT_WINDOWS_H_
#define _AXIS2_GETOPT_WINDOWS_H_

#include <axutil_utils_defines.h>
/**
 * @file axis2_getopt_windows.h
 * @brief windows cutdown version of getopt function in unix
 */

#ifdef   __cplusplus
extern "C" {
#endif

/** @defgroup axis2_getopt_windows getopt
 * @ingroup axis2_windows
 * @{
 */

AXIS2_IMPORT extern int   opterr;
AXIS2_IMPORT extern int optopt;   
AXIS2_IMPORT extern char  *optarg;

/**
  * return and log error
  * @param __optopt option
  * @param __err error code
  * @param __showerr whether or not send to stderr
  * @return ':' or '?'
  */
int _axis2_opt_error(int __optopt, int __err, int __showerr);

/**
  * cutdown version of getopt in unix
  * @param __argc no of arguments
  * @param __argv list of arguments
  * @param __shortopts options
  * @return option char if successful, -1 if over, ':' or '?' if error
  */
AXIS2_EXTERN int AXIS2_CALL 
axis2_getopt(int __argc, char * const *__argv, const char *__shortopts);

/** @} */

#ifdef   __cplusplus
}
#endif

#endif