/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AXUTIL_DURATION_H
#define AXUTIL_DURATION_H

#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_duration
     * @ingroup axis2_util
     * @{
     */

    typedef struct axutil_duration axutil_duration_t;


    /**
     * Creates axutil_duration struct with current date time
     * @param env double pointer to environment struct. MUST NOT be NULL
     * @return pointer to newly created axutil_duration struct
     */
    AXIS2_EXTERN axutil_duration_t * AXIS2_CALL
    axutil_duration_create(axutil_env_t *env);

    AXIS2_EXTERN axutil_duration_t * AXIS2_CALL
    axutil_duration_create_from_values(const axutil_env_t *env, 
        axis2_bool_t negative, 
		int years, int months, int days, int hours, 
		int minutes, double seconds);
	
	AXIS2_EXTERN axutil_duration_t * AXIS2_CALL
	axutil_duration_create_from_string(const axutil_env_t *env, 
        axis2_char_t *duration_str);

	AXIS2_EXTERN axis2_status_t AXIS2_CALL 
	axutil_duration_free(axutil_duration_t *duration,
		const axutil_env_t *env);	

	AXIS2_EXTERN axis2_status_t AXIS2_CALL
	axutil_duration_deserialize_duration(axutil_duration_t *duration,
		const axutil_env_t *env,
		const char* duration_str);
	
	AXIS2_EXTERN char* AXIS2_CALL
	axutil_duration_serialize_duration(axutil_duration_t *duration,
		const axutil_env_t *env );

	AXIS2_EXTERN axis2_status_t AXIS2_CALL
	axutil_duration_set_duration(axutil_duration_t* duration,
		const axutil_env_t *env,
		axis2_bool_t negative,
		int years, int months, int days,
		int hours, int mins, double seconds);

	AXIS2_EXTERN int AXIS2_CALL
	axutil_duration_get_years(axutil_duration_t *duration,
	    const axutil_env_t *env );

	AXIS2_EXTERN axis2_status_t AXIS2_CALL 
	axutil_duration_set_years(axutil_duration_t *duration,
		const axutil_env_t *env,
		int years);

	
	AXIS2_EXTERN int AXIS2_CALL
	axutil_duration_get_months(axutil_duration_t *duration,
	    const axutil_env_t *env );

	AXIS2_EXTERN axis2_status_t AXIS2_CALL 
	axutil_duration_set_months(axutil_duration_t *duration,
		const axutil_env_t *env,
		int months);

	AXIS2_EXTERN int AXIS2_CALL
	axutil_duration_get_days(axutil_duration_t *duration,
	    const axutil_env_t *env );

	AXIS2_EXTERN axis2_status_t AXIS2_CALL 
	axutil_duration_set_days(axutil_duration_t *duration,
		const axutil_env_t *env,
		int days);

	AXIS2_EXTERN int AXIS2_CALL
	axutil_duration_get_hours(axutil_duration_t *duration,
	    const axutil_env_t *env );

	AXIS2_EXTERN axis2_status_t AXIS2_CALL 
	axutil_duration_set_hours(axutil_duration_t *duration,
		const axutil_env_t *env,
		int hours);

	AXIS2_EXTERN int AXIS2_CALL
	axutil_duration_get_mins(axutil_duration_t *duration,
	    const axutil_env_t *env );

	
	AXIS2_EXTERN axis2_status_t AXIS2_CALL 
	axutil_duration_set_mins(axutil_duration_t *duration,
		const axutil_env_t *env,
		int mins);

	AXIS2_EXTERN double AXIS2_CALL
	axutil_duration_get_seconds(axutil_duration_t *duration,
	    const axutil_env_t *env );

	AXIS2_EXTERN axis2_status_t AXIS2_CALL 
	axutil_duration_set_seconds(axutil_duration_t *duration,
		const axutil_env_t *env,
	    double seconds);

	AXIS2_EXTERN axis2_bool_t AXIS2_CALL
	axutil_duration_compare(axutil_duration_t *duration_one, 
        axutil_duration_t *duration_two, 
        axutil_env_t *env);

#ifdef __cplusplus
}
#endif

#endif /* AXIS2_DURATION_H */



