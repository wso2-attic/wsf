/*
* Copyright 2009-2010 WSO2, Inc. http://wso2.com
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


/**
* axis2_skel_ServiceGroupAdmin.c
*
* This file was auto-generated from WSDL for "ServiceGroupAdmin|http://mgt.service.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_ServiceGroupAdmin Axis2/C skeleton for the axisService
*/

#include "server_admin_util.h"
#ifdef WIN32
#include <windows.h>
#endif

#if WIN32 
#define snprintf sprintf_s
#endif

AXIS2_EXTERN void AXIS2_CALL 
server_admin_util_get_up_time(time_t start_time, 
							  axis2_char_t* buffer)
{
	time_t current_time;
	long elapsed_time = 0;
	int days = 0;
	int hours = 0;
	int mins = 0;
	int secs = 0;

	time(&current_time);

	/* Get time diff */
	elapsed_time = difftime(current_time, start_time);

	mins = elapsed_time / 60;
	secs = elapsed_time % 60;

	hours = mins / 60;
	mins = mins % 60;

	days = hours / 24;
	hours = hours % 24;

	sprintf(buffer, "%d day(s) %d hr(s) %d min(s) %d sec(s)", days, hours, mins, secs);
}

AXIS2_EXTERN void AXIS2_CALL 
server_admin_util_get_timezone(axis2_char_t* buffer)
{
#ifdef WIN32
	TIME_ZONE_INFORMATION tzi;
	DWORD dwRet;
	
	dwRet = GetTimeZoneInformation(&tzi);

	if (dwRet == TIME_ZONE_ID_STANDARD || dwRet == TIME_ZONE_ID_UNKNOWN)
		wcstombs(buffer, tzi.StandardName, sizeof(tzi.StandardName));
	else if(dwRet == TIME_ZONE_ID_DAYLIGHT)
		wprintf(buffer, tzi.DaylightName, sizeof(tzi.DaylightName));
#endif
}