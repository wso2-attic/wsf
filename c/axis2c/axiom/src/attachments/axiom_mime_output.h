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

#ifndef AXIOM_MIME_OUTPUT_H
#define AXIOM_MIME_OUTPUT_H

/**
 * @file axiom_mime_output.h
 * @brief axis2 mime_output interface
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

/* This should be moved to header file later axutil_utils_defines.h*/    
#define axis2_byte_t char
   
typedef struct axiom_mime_output axiom_mime_output_t;   
   

/** @defgroup axiom_mime_output Flow
  * @ingroup axiom_mime_output
  * @{
  */

    AXIS2_EXTERN axis2_byte_t* AXIS2_CALL
    axiom_mime_output_complete(axiom_mime_output_t *mime_output,
        const axutil_env_t *env, 
        axis2_byte_t **output_stream,
        int *output_stream_size,
        axis2_char_t *soap_body_buffer,
        axutil_array_list_t *binary_node_list,
        axis2_char_t *boundary, 
        axis2_char_t *content_id,
        axis2_char_t *char_set_encoding,
        const axis2_char_t *soap_content_type);

    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axiom_mime_output_get_content_type_for_mime(axiom_mime_output_t *mime_output, 
        const axutil_env_t *env, 
        axis2_char_t *boundary, 
        axis2_char_t *content_id, 
        axis2_char_t *char_set_encoding, 
        const axis2_char_t *soap_content_type);
    
   /** Deallocate memory
     * @return status code
     */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_mime_output_free(axiom_mime_output_t *mime_output,
        const axutil_env_t *env);

    /**
     * Creates mime_output struct
     * @return pointer to newly created mime_output
     */
    AXIS2_EXTERN axiom_mime_output_t * AXIS2_CALL 
    axiom_mime_output_create (const axutil_env_t *env);

/** @} */

#ifdef __cplusplus
}
#endif
#endif  /* AXIOM_MIME_OUTPUT_H */
