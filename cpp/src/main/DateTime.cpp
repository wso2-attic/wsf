/*
 * Copyright 2005-2009 WSO2, Inc. http://wso2.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <DateTime.h>
using namespace std;
using namespace wso2wsf;

DateTime::DateTime()
{
	_dateTime = axutil_date_time_create(getEnv());
}

//************************************
// Method:    DateTime
// FullName:  wso2wsf::DateTime::DateTime
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: int year
// Parameter: int month
// Parameter: int date
// Parameter: int hour
// Parameter: int min
// Parameter: int second
// Parameter: int milliseconds
//************************************
DateTime::DateTime(int year, int month, int date, int hour, int min, int second, int milliseconds)
{
	_dateTime = axutil_date_time_create(getEnv());
	axutil_date_time_set_date_time(_dateTime, getEnv(), year, month, date, hour, min, second, milliseconds);
}
/**
*                                                    
*
*/
bool DateTime::deserializeDate(std::string timeStr)
{	
	return axutil_date_time_deserialize_date(_dateTime, getEnv(), timeStr.c_str()) ? true : false;
}
/**
*                                                    
*
*/
//************************************
// Method:    deserializeTime
// FullName:  wso2wsf::DateTime::deserializeTime
// Access:    public 
// Returns:   int
// Qualifier:
//************************************
bool DateTime::deserializeTime(string timeStr)
{
	return axutil_date_time_deserialize_time(_dateTime, getEnv(), timeStr.c_str()) ? true: false;
}

string DateTime::serializeDate()
{
	return axutil_date_time_serialize_date(_dateTime, getEnv());
}

string DateTime::serializeDateTime()
{
	return axutil_date_time_serialize_date_time(_dateTime, getEnv());
}

int DateTime::getDate()
{
	return axutil_date_time_get_date(_dateTime, getEnv());
}

int DateTime::getSecond()
{
	return axutil_date_time_get_second(_dateTime, getEnv());
}

string DateTime::serializeDateTimeWithoutMillisecond()
{
	return axutil_date_time_serialize_date_time_without_millisecond(_dateTime, getEnv());
}

string DateTime::serializeTime()
{
	return axutil_date_time_serialize_time(_dateTime, getEnv());
}