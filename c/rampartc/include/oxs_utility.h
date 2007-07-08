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

#ifndef OXS_UTILITY_H
#define OXS_UTILITY_H


/**
  * @file oxs_utilty.h
  * @brief The utility module for OMXMLSecurity 
  */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <oxs_asym_ctx.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Generates an id for an element.
     * Specially used in xml encryption and signature references.
     * @param env pointer to environment struct
     * @param prefix the prefix of the id. For ex: EncDataID-1u343yrcarwqe
     * @return the generated id
     **/
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    oxs_util_generate_id(const axutil_env_t *env,
                         axis2_char_t *prefix);

    /**
     * Given the filename returns the format of the file.
     * These formats are defined in asym_ctx.h
     * @param env pointer to environment struct
     * @param file_name the file name 
     **/
    AXIS2_EXTERN oxs_asym_ctx_format_t AXIS2_CALL
    oxs_util_get_format_by_file_extension(const axutil_env_t *env,
                                          axis2_char_t *file_name);


    /**
     * Given string and returns new lined removed string
     * @param env pointer to environment struct
     * @param input a pointer to the string which has \n s.
     * return the newline removed buffer.
     **/
    AXIS2_EXTERN axis2_char_t *AXIS2_CALL
    oxs_util_get_newline_removed_string(const axutil_env_t *env,
                                        axis2_char_t *input);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_UTILITY_H */
