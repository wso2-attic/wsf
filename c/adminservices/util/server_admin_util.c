

/**
* axis2_skel_ServiceGroupAdmin.c
*
* This file was auto-generated from WSDL for "ServiceGroupAdmin|http://mgt.service.carbon.wso2.org" service
* by the Apache Axis2/C version: #axisVersion# #today#
* axis2_skel_ServiceGroupAdmin Axis2/C skeleton for the axisService
*/

#include "server_admin_util.h"

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