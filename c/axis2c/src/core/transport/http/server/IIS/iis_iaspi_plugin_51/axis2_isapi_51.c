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

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <httpfilt.h>

#include "..\\axis2_isapi_plugin.h"
#include "..\\axis2_iis_constants.h"


/*
This function is called by the IIS server at the server 
initialization. So this is the ideal plcae for initializing 
axis2c.
*/
BOOL WINAPI GetFilterVersion(PHTTP_FILTER_VERSION pVer) 
{
	DWORD rc = FALSE;
    ULONG http_filter_revision = HTTP_FILTER_REVISION;
    pVer->dwFilterVersion = pVer->dwServerFilterVersion;
    if (pVer->dwFilterVersion > http_filter_revision) {
        pVer->dwFilterVersion = http_filter_revision;
    }

	/*
	Receive notifictions when
		1. Server preprocessed the headers.
		2. Log 
		3. All the request coming in secure and none secure ports.
	*/
	pVer->dwFlags = (SF_NOTIFY_ORDER_HIGH |                    
                    SF_NOTIFY_PREPROC_HEADERS |
					SF_NOTIFY_SECURE_PORT |
					SF_NOTIFY_NONSECURE_PORT |
					SF_NOTIFY_AUTH_COMPLETE
					);

	// Give a short discription about the module.
	strcpy(pVer->lpszFilterDesc, "axis2c filter");
	
	// initialize axis2
	rc = init_axis2();

	return rc;
}

/*
When a notification happens this function is called by the IIS.
*/
DWORD WINAPI HttpFilterProc(
		PHTTP_FILTER_CONTEXT pfc,
		DWORD notificationType,
		LPVOID pvNotification)
{
		
	DWORD bufferLength = INTERNET_MAX_URL_LENGTH;
	char url[INTERNET_MAX_URL_LENGTH];
	char modified_url[INTERNET_MAX_URL_LENGTH];


	if (notificationType == SF_NOTIFY_PREPROC_HEADERS)
	{		
		pfc->GetServerVariable(pfc, "HTTP_URL", url, &bufferLength);			
		if(get_extension_url(url, modified_url))
		{
			((PHTTP_FILTER_PREPROC_HEADERS)pvNotification)->SetHeader(pfc, "url", modified_url);
			return SF_STATUS_REQ_HANDLED_NOTIFICATION;
		}			
	}
	return SF_STATUS_REQ_NEXT_NOTIFICATION;
}

/*
This is the exit point of the filter. Here we shut down 
the axis2 engine.
*/
BOOL WINAPI TerminateFilter(DWORD dwfalgs)
{
	return axis2_terminate();	
}

