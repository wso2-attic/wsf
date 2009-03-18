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

#ifndef DATETIME_H
#define DATETIME_H

#include <WSFDefines.h>
#include <axutil_utils.h>
#include <axutil_qname.h>
#include <string>
#include <AxisObject.h>
/**
 * @file Property.h
 */

/**
 * @brief namespace wso2wsf Namespace of WSO2 Web Services Framework.
 */
namespace wso2wsf
{
    /**
    * @defgroup property Property
    * @ingroup wso2wsf
    * @{
    */

    /**
     * @brief class Qname
	 */
	class DateTime: public AxisObject
    {
    
	private:
        /**
         * Namespace uri of the qname
         */
		axutil_date_time_t  *_dateTime;	

    public:
        
		
		//************************************
		// Method:    DateTime
		// FullName:  wso2wsf::DateTime::DateTime
		// Access:    public 
		// Returns:   WSF_EXTERN WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN WSF_CALL DateTime();

		//************************************
		// Method:    DateTime
		// FullName:  wso2wsf::DateTime::DateTime
		// Access:    public 
		// Returns:   WSF_EXTERN WSF_CALL
		// Qualifier:
		// Parameter: int year
		// Parameter: int month
		// Parameter: int date
		// Parameter: int hour
		// Parameter: int min
		// Parameter: int second
		// Parameter: int milliseconds
		//************************************
		WSF_EXTERN WSF_CALL DateTime(int year, int month, int date, int hour, int min, int second, int milliseconds);

		//************************************
		// Method:    deserializeTime
		// FullName:  wso2wsf::DateTime::deserializeTime
		// Access:    public 
		// Returns:   WSF_EXTERN bool WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN bool WSF_CALL deserializeTime(std::string timeStr);

		//************************************
		// Method:    deserializeDate
		// FullName:  wso2wsf::DateTime::deserializeDate
		// Access:    public 
		// Returns:   WSF_EXTERN bool WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN bool WSF_CALL deserializeDate(std::string timeStr);

		//************************************
		// Method:    serializeTime
		// FullName:  wso2wsf::DateTime::serializeTime
		// Access:    public 
		// Returns:   WSF_EXTERN std::string WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN std::string WSF_CALL serializeTime();
		
		//************************************
		// Method:    serializeDate
		// FullName:  wso2wsf::DateTime::serializeDate
		// Access:    public 
		// Returns:   WSF_EXTERN std::string WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN std::string WSF_CALL serializeDate();

		//************************************
		// Method:    serializeDateTime
		// FullName:  wso2wsf::DateTime::serializeDateTime
		// Access:    public 
		// Returns:   WSF_EXTERN std::string WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN std::string WSF_CALL serializeDateTime();

		//************************************
		// Method:    serializeDateTimeWithoutMillisecond
		// FullName:  wso2wsf::DateTime::serializeDateTimeWithoutMillisecond
		// Access:    public 
		// Returns:   WSF_EXTERN std::string WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN std::string WSF_CALL serializeDateTimeWithoutMillisecond();

		//************************************
		// Method:    getYear
		// FullName:  wso2wsf::DateTime::getYear
		// Access:    public 
		// Returns:   WSF_EXTERN int WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN int WSF_CALL getYear();

		//************************************
		// Method:    getMonth
		// FullName:  wso2wsf::DateTime::getMonth
		// Access:    public 
		// Returns:   WSF_EXTERN int WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN int WSF_CALL getMonth();

		//************************************
		// Method:    getDate
		// FullName:  wso2wsf::DateTime::getDate
		// Access:    public 
		// Returns:   WSF_EXTERN int WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN int WSF_CALL getDate();

		//************************************
		// Method:    getMinute
		// FullName:  wso2wsf::DateTime::getMinute
		// Access:    public 
		// Returns:   WSF_EXTERN int WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN int WSF_CALL getMinute();

		//************************************
		// Method:    getSecond
		// FullName:  wso2wsf::DateTime::getSecond
		// Access:    public 
		// Returns:   WSF_EXTERN int WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN int WSF_CALL getSecond();

		//************************************
		// Method:    getMsec
		// FullName:  wso2wsf::DateTime::getMsec
		// Access:    public 
		// Returns:   WSF_EXTERN int WSF_CALL
		// Qualifier:
		//************************************
		WSF_EXTERN int WSF_CALL getMsec();


	};
    /** @} */
}
#endif // DATETIME_H
