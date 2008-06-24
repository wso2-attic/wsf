/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WSF_UTIL_H
#define WSF_UTIL_H

/** @defgroup wsf_util_h
 * @ingroup wsf_util_h
 * @{
 */

#include <axis2_util.h>

#ifdef __cplusplus
extern "C"
{
#endif


    #define array_sizeof(x) (sizeof (x) / sizeof ((x)[0]))    


    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    wsf_create_stock_market(
        const axutil_env_t *env);

    AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
    wsf_create_client_data(
        const axutil_env_t *env);
        

#ifdef __cplusplus
}
#endif
#endif
