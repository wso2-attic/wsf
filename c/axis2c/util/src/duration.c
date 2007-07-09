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
#include <axutil_duration.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <axutil_error.h>
#include <axutil_utils.h>

/**
 * @brief
 */

struct axutil_duration
{	
    axis2_bool_t is_negative;
    int years;
    int months;
    int days;
    int hours;
    int mins;
    double secs;   
};


AXIS2_EXTERN axutil_duration_t * AXIS2_CALL
axutil_duration_create(axutil_env_t *env)
{
    return axutil_duration_create_from_values(env, 0, 0, 0, 0, 0, 0, 0.0);
}

AXIS2_EXTERN axutil_duration_t * AXIS2_CALL
axutil_duration_create_from_values(const axutil_env_t *env, 
        axis2_bool_t negative, 
		int years, int months, int days, int hours, 
		int minutes, double seconds)
{
    axutil_duration_t *duration = NULL;

    AXIS2_ENV_CHECK(env, NULL);
	
	duration = (axutil_duration_t *)AXIS2_MALLOC(env->allocator, 
												sizeof(axutil_duration_t));
	if (NULL == duration)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
    	return NULL;
	}
    
	duration->is_negative = negative;
	duration->years = years;
	duration->months = months;
	duration->days = days;
	duration->hours = hours;
	duration->mins = minutes;
	duration->secs = seconds;

    return duration;
}

AXIS2_EXTERN axutil_duration_t * AXIS2_CALL
axutil_duration_create_from_string(const axutil_env_t *env, 
        axis2_char_t *duration_str)
{
    axutil_duration_t *duration = NULL;
    axutil_duration_deserialize_duration(duration, env, duration_str);
    return duration;
}


/***************************Function implementation****************************/

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_duration_free(axutil_duration_t *duration,
		const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (duration)
    {
        AXIS2_FREE(env->allocator, duration);
        duration = NULL;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_duration_deserialize_duration(axutil_duration_t *duration,
		const axutil_env_t *env,
		const axis2_char_t *duration_str)
{
    const axis2_char_t *cur = duration_str;
    double         num;
    int            num_type = 0;
    unsigned int seq = 0;
    const char  desig[]  = {'Y', 'M', 'D', 'H', 'M', 'S'};

    if (duration_str == NULL)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    if (*cur == '-')
    {
        duration->is_negative = 1;
        cur++;
    }

    if (*cur++ != 'P')
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NONE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    if (*cur == 0)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NONE, AXIS2_FAILURE);
        return AXIS2_FAILURE;
    }

    while ( *cur != 0 )
    {
        if ( seq >= sizeof(desig))
        {
            AXIS2_ERROR_SET(env->error,AXIS2_ERROR_NONE, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }

        if (*cur == 'T')
        {
            if (seq < 3) {
                seq = 3;
                cur++;
            }
            else
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NONE, AXIS2_FAILURE);
                return AXIS2_FAILURE;
            }
        }
        else if (seq == 3)
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NONE, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }
        
        num = 0;

		if ((*cur < '0') || (*cur > '9'))
			num_type = -1;
		else
		{
			while ((*cur >= '0') && (*cur <= '9')) {
		        	num = num * 10 + (*cur - '0');
				cur++;
			}
		}
		
		if (!num_type && (*cur == '.')) {
			double mult = 1;	
			cur++;
			if ((*cur < '0') || (*cur > '9'))	
				num_type = -1;	
			else
				num_type = 1;
			while ((*cur >= '0') && (*cur <= '9')) {	
				mult /= 10;
				num += (*cur - '0') * mult;
				cur++;	
			}
		}

        if ((num_type == -1) || (*cur == 0))
        {
            AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NONE, AXIS2_FAILURE);
            return AXIS2_FAILURE;
        }

        while ( seq < sizeof(desig) )
        {
            if (*cur == desig[seq])
            {
                if ((num_type = 0) && (seq < (sizeof(desig)-1)))
                {
                    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NONE, AXIS2_FAILURE);
                    return AXIS2_FAILURE;
                }

                switch (seq)
                {
                    case 0:
                        duration->years = (int)num;
                        seq++;
                        break;
                    case 1:
                        duration->months = (int)num;
                        seq++;
                        break;
                    case 2:
                        duration->days = (int)num;
						seq++;
						break;
					case 3:
						duration->hours =  (int)num;
						seq++;
						break;
					case 4:
						duration->mins = (int)num;
						seq++;
						break;
					case 5:
						duration->secs = num;
						seq++;
						break;
				}
				break;
			}
		    if ((++seq == 3) || (seq == 6))
				return 1;
		}
		cur++;
	}
	return AXIS2_SUCCESS;   

}

AXIS2_EXTERN char* AXIS2_CALL
axutil_duration_serialize_duration(axutil_duration_t *duration,
		const axutil_env_t *env )
{
    axis2_char_t *duration_str = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    duration_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) * 64);
    
    if (duration->is_negative == 0)
        sprintf(duration_str, "P%dY%dM%dDT%dH%dM%fS", duration->years, duration->months,
                duration->days, duration->hours, duration->mins, duration->secs);
    else 
        sprintf(duration_str, "-P%dY%dM%dDT%dH%dM%fS", duration->years, duration->months,
                duration->days, duration->hours, duration->mins, duration->secs);

    return duration_str;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axutil_duration_set_duration(axutil_duration_t* duration,
		const axutil_env_t *env,
		axis2_bool_t negative,
		int years, int months, int days,
		int hours, int mins, double seconds)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if(years > -1)duration->years = years;
    if(months > -1)duration->months = months;
    if(days > -1)duration->days = days;
    if(hours > -1)duration->hours = hours;
    if(mins > -1)duration->mins = mins;
    if(seconds > -1)duration->secs = seconds;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axutil_duration_get_years(axutil_duration_t *duration,
	    const axutil_env_t *env )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return duration->years;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_duration_set_years(axutil_duration_t *duration,
		const axutil_env_t *env,
		int years)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    duration->years = years;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axutil_duration_get_months(axutil_duration_t *duration,
	    const axutil_env_t *env )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return duration->months;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_duration_set_months(axutil_duration_t *duration,
		const axutil_env_t *env,
		int months)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    duration->months = months;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axutil_duration_get_days(axutil_duration_t *duration,
	    const axutil_env_t *env )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return duration->days;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_duration_set_days(axutil_duration_t *duration,
		const axutil_env_t *env,
		int days)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    duration->days = days;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axutil_duration_get_hours(axutil_duration_t *duration,
	    const axutil_env_t *env )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return duration->hours;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_duration_set_hours(axutil_duration_t *duration,
		const axutil_env_t *env,
		int hours)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    duration->hours = hours;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN int AXIS2_CALL
axutil_duration_get_mins(axutil_duration_t *duration,
	    const axutil_env_t *env )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return duration->mins;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_duration_set_mins(axutil_duration_t *duration,
		const axutil_env_t *env,
		int mins)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    duration->mins = mins;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN double AXIS2_CALL
axutil_duration_get_seconds(axutil_duration_t *duration,
	    const axutil_env_t *env )
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    return duration->secs;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axutil_duration_set_seconds(axutil_duration_t *duration,
		const axutil_env_t *env,
	    double seconds)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    duration->secs = seconds;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axutil_duration_compare(axutil_duration_t *duration_one, 
        axutil_duration_t *duration_two, 
        axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);

    if (!duration_one || !duration_two)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_INVALID_NULL_PARAM, AXIS2_FAILURE);
        return -1;
    }

	/*TODO*/

    return AXIS2_SUCCESS;
}



