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

#ifndef AXUTIL_ERROR_DEFAULT_H
#define AXUTIL_ERROR_DEFAULT_H

#include <axutil_utils_defines.h>
#include <axutil_allocator.h>
#include <axutil_error.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @defgroup axutil_error Error
 * @ingroup axis2_util 
 * @{
 */


  /**
    * Creates an error struct
    * @param allocator allocator to be used. Mandatory, cannot be NULL    
    * @return pointer to the newly created error struct 
    */
    AXIS2_EXTERN axutil_error_t *AXIS2_CALL axutil_error_create (axutil_allocator_t * allocator);


/** @} */
    
#ifdef __cplusplus
}
#endif


#endif                          /* AXIS2_ERROR_DEFAULT_H */
