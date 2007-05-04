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

#ifndef	AXIS2_ISAPI_PLUGIN_H
#define AXIS2_ISAPI_PLUGIN_H

#include <axutil_utils.h>
#ifdef __cplusplus
extern "C"
{
#endif
/*
Initialize axis. This function is called in the begining of the module loading.
It initializes the axis by reading values from the configuration and creating the 
required structures for the axis2c
*/
axis2_status_t init_axis2();

/*
Cleanup the axis2.
*/
axis2_status_t axis2_terminate();

/*
Search a given uri to find weather it matches a uri for the axis2
The uri format for axis2 is of the form
scheme://server:port/axis2/other_parts
This function search  a give uri for the /axis2/. If a match 
is found it will replace the /axis2 part of the url with /axis2/mod_iis.dll?
*/
axis2_status_t get_extension_url(char url[], char ret_url[]);

#ifdef __cplusplus
}
#endif

#endif