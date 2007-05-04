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

#ifndef AXIS2_DISP_CHECKER_H
#define AXIS2_DISP_CHECKER_H

/**
 * @defgroup axis2_disp_checker dispatcher checker
 * @ingroup axis2_engine
 * dispatcher checker is responsible of checking the status of the dispatchers.
 * @{
 */

/**
 * @file axis2_disp_checker.h
 */

#include <axis2_defines.h>
#include <axutil_string.h>
#include <axis2_handler.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_disp_checker  */
    typedef struct axis2_disp_checker axis2_disp_checker_t;

    /**
     * Gets the base handler.
     * @param disp_checker pointer to dispatcher checker
     * @param env pointer to environment struct
     * @return pointer to base handler, returns a reference not a cloned copy
     */
    AXIS2_EXTERN axis2_handler_t *AXIS2_CALL
    axis2_disp_checker_get_base(const axis2_disp_checker_t *disp_checker,
        const axutil_env_t *env);


    /**
     * Gets QName.
     * @param disp_checker pointer to dispatcher checker
     * @param env pointer to environment struct
     * @return returns a pointer to the QName, returns a reference not a 
     * cloned copy
     */
    AXIS2_EXTERN axutil_string_t *AXIS2_CALL
    axis2_disp_checker_get_name(const axis2_disp_checker_t *disp_checker,
        const axutil_env_t *env);

    /**
     * Sets QName.
     * @param disp_checker pointer to dispatcher checker
     * @param env pointer to environment struct
     * @param name pointer to QName. A clone would be created within the method
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_disp_checker_set_name(axis2_disp_checker_t *disp_checker,
        const axutil_env_t *env,
        const axutil_string_t *name);

    /**
     * Frees dispatcher checker.
     * @param disp_checker pointer to dispatcher checker
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_disp_checker_free(axis2_disp_checker_t *disp_checker,
        const axutil_env_t *env);

    /**
     * Creates a dispatcher checker struct instance.
     * @param env pointer to environment struct
     * @return pointer to newly created dispatcher checker struct
     */
    AXIS2_EXTERN axis2_disp_checker_t *AXIS2_CALL
    axis2_disp_checker_create(const axutil_env_t *env);
    
#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_DISP_CHECKER_H */
