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

#ifndef AXUTIL_DIR_HANDLER_H
#define AXUTIL_DIR_HANDLER_H

#include <axutil_utils_defines.h>
#include <axutil_error.h>
#include <axutil_env.h>
#include <axutil_string.h>
#include <axutil_array_list.h>
#include <axutil_utils.h>


#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_dir_handler dir handler
     * @ingroup axis2_util
     * @{
     */
    /**
     * List the dll files in the given service or module folder path
     * @param pathname path to your service or module directory
     * @return array list of dll file names
     */
    AXIS2_EXTERN axutil_array_list_t * AXIS2_CALL
    axutil_dir_handler_list_services_or_modules_in_dir(const axutil_env_t *env,
            const axis2_char_t *pathname);

    /**
     * List services or modules directories in the services or modules folder
     * respectively
     * @param pathname path  your modules or services folder
     * @return array list of contents of services or modules folder
     */
    AXIS2_EXTERN axutil_array_list_t * AXIS2_CALL
    axutil_dir_handler_list_service_or_module_dirs(const axutil_env_t *env,
            const axis2_char_t *pathname);

    /*
     *extentions for module and service archives
     */
#define AXIS2_AAR_SUFFIX ".aar"
#define AXIS2_MAR_SUFFIX ".mar"

#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_DIR_HANDLER_H */
