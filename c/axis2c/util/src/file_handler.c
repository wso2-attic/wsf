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

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <platforms/axutil_platform_auto_sense.h>

#include <axutil_file_handler.h>

void* AXIS2_CALL
axutil_file_handler_open(const axis2_char_t *file_name,
        const axis2_char_t *options)

{
    FILE *file_ptr;

    if (!file_name)
        return NULL;

    if (!options)
        return NULL;

    file_ptr = fopen(file_name, options);
    return file_ptr;
}

axis2_status_t AXIS2_CALL
axutil_file_handler_close(void *file_ptr)
{
    if (!file_ptr) return -1;
    return (axis2_status_t) fclose(file_ptr);
}

axis2_status_t AXIS2_CALL
axutil_file_handler_access(const axis2_char_t *path,
        int mode)
{
    int i = 0;
    axis2_status_t status = AXIS2_FAILURE;
    i = AXIS2_ACCESS(path, mode);
    if (0 == i)
    {
        status = AXIS2_SUCCESS;
    }
    else if (-1 == i)
    {
        status = AXIS2_FAILURE;
    }
    return status;
}

