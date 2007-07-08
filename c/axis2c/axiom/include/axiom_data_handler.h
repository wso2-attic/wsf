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

#ifndef AXIOM_DATA_HANDLER_H
#define AXIOM_DATA_HANDLER_H

/**
 * @file axiom_data_handler.h
 * @brief axis2 data_handler interface
 */

#include <axutil_utils.h>
#include <axutil_error.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axutil_allocator.h>
#include <axutil_string.h>
#include <axutil_array_list.h>


#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum axiom_data_handler_type
    {
        AXIOM_DATA_HANDLER_TYPE_FILE,
        AXIOM_DATA_HANDLER_TYPE_BUFFER
    }axiom_data_handler_type_t;


    typedef struct axiom_data_handler axiom_data_handler_t;

    /** @defgroup axiom_data_handler Flow
      * @ingroup axiom_data_handler
      * @{
      */

    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    axiom_data_handler_get_content_type(axiom_data_handler_t *data_handler,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_byte_t *AXIS2_CALL
    axiom_data_handler_get_input_stream(axiom_data_handler_t *data_handler,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_data_handler_read_from(axiom_data_handler_t *data_handler,
        const axutil_env_t *env,
        axis2_byte_t** output_stream,
        int *output_stream_size);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_data_handler_set_binary_data(axiom_data_handler_t *data_handler,
        const axutil_env_t *env,
        axis2_byte_t* input_stream,
        int input_stream_len);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_data_handler_write_to(axiom_data_handler_t *data_handler,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_data_handler_set_file_name(axiom_data_handler_t *data_handler,
        const axutil_env_t *env,
        axis2_char_t* file_name);

    AXIS2_EXTERN void AXIS2_CALL
    axiom_data_handler_free(axiom_data_handler_t *data_handler,
        const axutil_env_t *env);

    /**
     * Creates data_handler struct
     * @return pointer to newly created data_handler
     */
    AXIS2_EXTERN axiom_data_handler_t * AXIS2_CALL
    axiom_data_handler_create(const axutil_env_t *env,
        const axis2_char_t *file_name,
        const axis2_char_t *mime_type);

    /** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIOM_DATA_HANDLER_H */
