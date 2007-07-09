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

#ifndef OXS_BUFFER_H
#define OXS_BUFFER_H


/**
  * @file oxs_buffer.h
  * @brief The buffer representation in OMXMLSecurity. 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_util.h>
#include <oxs_axiom.h>
#include <oxs_error.h>
#include <oxs_constants.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** @defgroup
     * @ingroup 
     * @{
     */

#define OXS_BUFFER_INITIAL_SIZE 1024

    /**
    * Allocate mode for the buffer
    * oxs_alloc_mode_exact : Minimizes the allocated memory size
    * oxs_alloc_mode_double : Minimizes number of Malloc calls
    */
    typedef enum {
        oxs_alloc_mode_exact = 0,
        oxs_alloc_mode_double
    } oxs_AllocMode;


    /** Type name for struct  oxs_buffer */
    typedef struct oxs_buffer oxs_buffer_t;

    /**
    *Free function of the buffer
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_free(
        oxs_buffer_t *buffer,
        const axutil_env_t *env
    );
    /**
    *Removes the first (size) charcters from the buffer
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@size number of characters to be removed
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_remove_head(
        oxs_buffer_t *buffer,
        const axutil_env_t *env,
        int size
    );
    /**
    *Removes the last (size) charcters from the buffer
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@size number of characters to be removed		
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_remove_tail(
        oxs_buffer_t *buffer,
        const axutil_env_t *env,
        int size
    );
    /**
    *populates the buffer using the @data set the @size as the useful length
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@data the data for the buffer
    *@size the effective length of data
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_populate(
        oxs_buffer_t *buffer,
        const axutil_env_t *env,
        unsigned char *data,
        int size
    );
    /**
    *Append data (to the end)
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@data the data for the buffer
    *@size the effective length of data
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_append(
        oxs_buffer_t *buffer,
        const axutil_env_t *env,
        unsigned char *data,
        int size
    );
    /**
    *Prepends data (to the front of the buffer)
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@data the data for the buffer
    *@size the effective length of data
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_prepend(
        oxs_buffer_t *buffer,
        const axutil_env_t *env,
        unsigned char *data,
        int size
    );
    /**
    *Reads a file specified by @filename
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@filename The name of the file
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_read_file(
        oxs_buffer_t *buffer,
        const axutil_env_t *env,
        const axis2_char_t *filename
    );
    /**
    *Sets the size
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@size the value of the size
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_set_size(
        oxs_buffer_t *buffer,
        const axutil_env_t *env,
        int size
    );
    /**
    *Sets the maximum size of the buffer. Usually this will be allocated dynamically
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@size the maximum size of the buffer
    *@return AXIS2_SUCCESS on success, else AXIS2_FAILURE
    */
    axis2_status_t AXIS2_CALL
    oxs_buffer_set_max_size(
        oxs_buffer_t *buffer,
        const axutil_env_t *env,
        int size
    );
    /**
    *Returns data
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@return data in the buffer
    */
    unsigned char* AXIS2_CALL
    oxs_buffer_get_data(
        oxs_buffer_t *buffer,
        const axutil_env_t *env
    );
    /**
    *Returns the effective length of the buffer
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@return the effective length of the buffer as int
    */
    int AXIS2_CALL
    oxs_buffer_get_size(
        oxs_buffer_t *buffer,
        const axutil_env_t *env
    );
    /**
    *Returns the maximum size of the buffer
    *@buffer pointer to the OMXMLSec buffer struct
    *@env pointer to environment struct
    *@return the maximum size of the buffer
    */
    int AXIS2_CALL
    oxs_buffer_get_max_size(
        oxs_buffer_t *buffer,
        const axutil_env_t *env
    );



    AXIS2_EXTERN oxs_buffer_t *AXIS2_CALL
    oxs_buffer_create(const axutil_env_t *env);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_BUFFER_H */
