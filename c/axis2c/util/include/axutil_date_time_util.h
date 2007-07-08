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

#ifndef AXUTIL_DATE_TIME_UTIL_H
#define AXUTIL_DATE_TIME_UTIL_H

#include <axutil_utils.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <platforms/axutil_platform_auto_sense.h>


#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @defgroup axutil_uuid_gen UUID generator
 * @ingroup axis2_util 
 * @{
 */
   
/**
 * generate a uuid
 * @return generated uuid as a string
 */ 
AXIS2_EXTERN int AXIS2_CALL
axutil_get_milliseconds(const axutil_env_t *env);

/** @} */
    
#ifdef __cplusplus
}
#endif

#endif                          /* AXIS2_DATE_TIME_UTIL_H */
