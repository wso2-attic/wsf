/*
 *   Copyright 2003-2004 The Apache Software Foundation.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <axis2_util.h>
#include <oxs_buffer.h>

/**
  * @file 
  * @brief 
  */
#ifndef OXS_AXIS_UTILS
#define OXS_AXIS_UTILS

#ifdef __cplusplus
extern "C" {
#endif

    /** @defgroup
     * @ingroup
     * @{
     */
#if 0
    /*Decoded buffer will be returned*/
    AXIS2_EXTERN oxs_buffer_ptr AXIS2_CALL  oxs_base64_decode(axutil_env_t *env,
            oxs_buffer_ptr coded_buf);

    /*Encoded input buffer will be returned*/
    AXIS2_EXTERN oxs_buffer_ptr AXIS2_CALL  oxs_base64_encode(axutil_env_t *env,
            oxs_buffer_ptr plain_buf);
#endif

    /** @} */
#ifdef __cplusplus
}
#endif

#endif    /* OXS_AXIS_UTILS */
