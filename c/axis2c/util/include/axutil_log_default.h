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

#ifndef AXUTIL_LOG_DEFAULT_H
#define AXUTIL_LOG_DEFAULT_H

#include <stdlib.h>
#include <stdarg.h>
#include <axutil_log.h>
#include <axutil_allocator.h>


#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @defgroup axutil_log Log
 * @ingroup axis2_util 
 * @{
 */

#define AXIS2_LEN_VALUE 6000


  /**
    * Creates a log struct
    * @param allocator allocator to be used. Mandatory, cannot be NULL    
    * @return pointer to the newly created log struct 
    */
    AXIS2_EXTERN axutil_log_t * AXIS2_CALL axutil_log_create (axutil_allocator_t * allocator,
                     axutil_log_ops_t * ops, const axis2_char_t * stream_name);
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL  axutil_log_impl_get_time_str(void);
    
    AXIS2_EXTERN axutil_log_t * AXIS2_CALL 
    axutil_log_create_default (axutil_allocator_t *allocator);

/** @} */
    
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_LOG_DEFAULT_H */
