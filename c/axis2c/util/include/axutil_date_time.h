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

#ifndef AXUTIL_DATE_TIME_H
#define AXUTIL_DATE_TIME_H

#include <axutil_utils_defines.h>
#include <axutil_env.h>

/**
 * @file axutil_date_time.h
 * @brief axis2-util
 */

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_date_time
     * @ingroup axis2_util
     * @{
     */

    typedef struct axutil_date_time axutil_date_time_t;


    typedef enum  {
        AXIS2_DATE_TIME_COMP_RES_FAILURE = -1,
        AXIS2_DATE_TIME_COMP_RES_UNKNOWN,
        AXIS2_DATE_TIME_COMP_RES_EXPIRED,
        AXIS2_DATE_TIME_COMP_RES_EQUAL,
        AXIS2_DATE_TIME_COMP_RES_NOT_EXPIRED
    }axutil_date_time_comp_result_t; 

    /**
     * Creates axutil_date_time struct with current date time
     * @param env double pointer to environment struct. MUST NOT be NULL
     * @return pointer to newly created axutil_date_time struct
     */
    AXIS2_EXTERN axutil_date_time_t * AXIS2_CALL
    axutil_date_time_create(const axutil_env_t *env);

    /*
     * Creates axutil_date_time struct with an additional offset value
     * If the offset is a positive value then the time will be in the future
     *        offset is 0, then the time will be the current time
     *        offset is a negative value then the time is in the past.
     * @param env double pointer to environment struct. MUST NOT be NULL
     * @param offset the offset from the current time in seconds
     * @return pointer to newly created axutil_date_time struct
     **/
    AXIS2_EXTERN axutil_date_time_t * AXIS2_CALL
    axutil_date_time_create_with_offset(const axutil_env_t *env, int offset);

    /**
     * free the axutil_date_time.
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL 
    axutil_date_time_free(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * store the time value from plain text.
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @param time time as a string format HH:MM:TTZ
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axutil_date_time_deserialize_time(axutil_date_time_t *date_time,
        const axutil_env_t *env,
        const axis2_char_t* time_str);

    /**
     * store the date value from plain text.
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @param date date as a string format YYYY-MM-DD
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axutil_date_time_deserialize_date(axutil_date_time_t *date_time,
        const axutil_env_t *env,
        const axis2_char_t* date_str);

    /**
     * store the date value from plain text.
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @param date_time string format YYYY-MM-DDTHH:MM:SSZ
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL 
    axutil_date_time_deserialize_date_time(axutil_date_time_t *date_time,
        const axutil_env_t *env,
        const axis2_char_t* date_time_str);

    /**
     * store the date value from set of values
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @param year Integer -1 can be used to ignore
     * @param month Integer -1 can be used to ignore
     * @param date Integer -1 can be used to ignore
     * @param hour Integer -1 can be used to ignore
     * @param min Integer -1 can be used to ignore
     * @param second Integer -1 can be used to ignore
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axutil_date_time_set_date_time(axutil_date_time_t* date_time,
        const axutil_env_t *env,
        int year, int month, int date,
        int hour, int min, int second, int milliseconds);

    /**
     * retrive the stored time  as a string
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return time as a string format HH:MM:SSZ
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
    axutil_date_time_serialize_time(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * retrive the stored date as a string
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return date as a string  format YYYY-MM-DD
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
    axutil_date_time_serialize_date(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * retrive the stored date time  as a string
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return time as a string format YYYY-MM-DDTHH:MM:SSZ
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL 
    axutil_date_time_serialize_date_time(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * retrieve the year of the date time
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return year as an integer 
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_date_time_get_year(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * retrieve the month of the date time
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return month as an integer 
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_date_time_get_month(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * retrieve the date of the date time
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return date as an integer 
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_date_time_get_date(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * retrieve the hour of the date time
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return hour as an integer 
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_date_time_get_hour(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * retrieve the minute of the date time
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return minute as an integer 
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_date_time_get_minute(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    /**
     * retrieve the second of the date time
     * @param date_time represet the type object
     * @param env pointer to environment struct. MUST NOT be NULL
     * @return second as an integer 
     */
    AXIS2_EXTERN int AXIS2_CALL 
    axutil_date_time_get_second(axutil_date_time_t *date_time,
        const axutil_env_t *env);

    AXIS2_EXTERN int AXIS2_CALL 
    axutil_date_time_get_msec(axutil_date_time_t *date_time,
        const axutil_env_t *env);
    /**
     * Compare the date and time of @date_time with the reference @ref.
     * If the @date_time < @ref this returns NOT_EXPIRED.
     * If the @date_time > @ref this returns EXPIRED.
     * If the @date_time = @ref this returns EQUAL.
     * @param date_time the date time to be compared
     * @param env pointer to environment struct. MUST NOT be NULL
     * @ref the reference date time
     * @return NOT_EXPIRED/EXPIRED/EQUAL if valid otherwise return FAILURE
     */
    AXIS2_EXTERN axutil_date_time_comp_result_t AXIS2_CALL
    axutil_date_time_compare(axutil_date_time_t *date_time,   
        const axutil_env_t *env, axutil_date_time_t *ref);

#ifdef __cplusplus
}
#endif

#endif /* AXIS2_DATE_TIME_H */
