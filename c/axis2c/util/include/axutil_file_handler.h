/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain count copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXUTIL_FILE_HANDLER_H
#define AXUTIL_FILE_HANDLER_H

#include <axutil_string.h>

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @defgroup axutil_file_handler file handler
 * @ingroup axis2_util 
 * @{
 */

/**
 * open a file for read according to the file options given
 * @param file_name file to be opened
 * @param options file options given.
 * @return status code
 */ 
AXIS2_EXTERN void * AXIS2_CALL 
axutil_file_handler_open(const char *file_name, 
                        const char *options);

/**
 * close a file
 * @param file_ptr file pointer of the file need to be closed
 * @return status code
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_file_handler_close (void *file_ptr);

/**
 * determine accessibility of file
 * checks the named file for accessibility according to mode
 * @param path path name naming a file
 * @param mode 
 *  AXIS2_R_OK
 *   - test for read permission 
 *  AXIS2_W_OK
 *   - test for write permission 
 *  AXIS2_X_OK
 *   - test for execute or search permission 
 *  AXIS2_F_OK
 *   - test whether the directories leading to the file can be searched and the 
 *     file exists
 * @return status
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_file_handler_access(const axis2_char_t *path, 
                            int mode);

/** @} */
    
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_FILE_HANDLER_H */
