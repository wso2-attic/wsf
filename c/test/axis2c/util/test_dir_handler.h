
/*
 * Copyright 2005-2008 WSO2, Inc. http://wso2.com
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

#ifndef TEST_DIR_HANDLER_H
#define TEST_DIR_HANDLER_H

#include <axutil_dir_handler.h>

/* uncomment to enable test_axutil_dir_handler_list_service_or_module_dirs */
/* #define TEST_DIR_HANDLER_LIST_DIRS_IMPLEMENTED */

/* Absolute path to AXIS2C_HOME */
#ifndef WIN32
    #define TEST_DIR_HANDLER_LIST_DIRS_PATH "/tmp/test/"
#else
    #define TEST_DIR_HANDLER_LIST_DIRS_PATH "C:\temp\test"
#endif

/* Number of sub folders with dlls in AXIS2C_HOME/services + AXIS2C_HOME/modules */
#define TEST_DIR_HANDLER_LIST_DIRS_FOLDER_COUNT 0

/* uncomment to enable test_axutil_dir_handler_list_services_or_modules_in_dir */
/* #define TEST_DIR_HANDLER_LIST_DLLS_IMPLEMENTED */ 

/* Absolute path to AXIS2C_HOME */
#ifndef WIN32
    #define TEST_DIR_HANDLER_LIST_DLLS_PATH "/tmp/test/"
#else
    #define TEST_DIR_HANDLER_LIST_DLLS_PATH "C:\temp\test"
#endif

/* Number of dlls in sub folders of AXIS2C_HOME/services + AXIS2C_HOME/modules */
#define TEST_DIR_HANDLER_LIST_DLLS_FILE_COUNT 0

#endif
