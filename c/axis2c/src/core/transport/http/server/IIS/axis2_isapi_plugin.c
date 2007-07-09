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
#include <httpext.h>

/* Axis headers */
#include <axutil_error_default.h>
#include <axutil_log_default.h>
#include <axutil_thread_pool.h>
#include <axiom_xml_reader.h>
#include <axutil_log.h>

#include "axis2_isapi_plugin.h"

#include "axis2_iis_worker.h"
#include "axis2_iis_constants.h"

#define	AXIS2_IIS_LOG_FILE_TAG		("log_file")
#define AXIS2_IIS_LOG_LEVEL_TAG		("log_level")
#define AXIS2_IIS_REPO_PATH_TAG		("axis2c_home")
#define AXIS2_IIS_EXTENSION_URI_TAG	("extension_uri")
#define AXIS2_IIS_REDIRECT_WORD_TAG	("redirect_uri")

#define AXIS2_IIS_LOG_TRACE_VERB	("trace")
#define AXIS2_IIS_LOG_ERROR_VERB	("error")
#define AXIS2_IIS_LOG_INFO_VERB		("info")
#define AXIS2_IIS_LOG_CRITICAL_VERB	("critical")
#define AXIS2_IIS_LOG_WARN_VERB		("warning")
#define AXIS2_IIS_LOG_DEBUG_VERB	("debug")

#define MAX_FILE_PATH				256


#define REGISTRY_LOCATION			("Software\\Apache Axis2c\\IIS ISAPI Redirector")
static int is_inited = FALSE;

static axis2_iis_worker_t*	axis2_worker = NULL;
static const axutil_env_t*	axutil_env = NULL;
static axis2_char_t			repo_path[MAX_FILE_PATH] = "c:\\axis2c";
static axis2_char_t			log_file[MAX_FILE_PATH] = "axis2.log";
static axutil_log_levels_t	log_level = AXIS2_LOG_LEVEL_CRITICAL;
static axis2_char_t			redirect_word[INTERNET_MAX_URL_LENGTH] = "/axis2/mod_axis2_IIS.dll\?";

/*
This is a utility functipn for reading configuration data from the registery.
*/
static axis2_status_t read_registery_init_data();

/*
Utility function for reading 
*/
static axis2_status_t get_registry_config_parameter(HKEY hkey,
                                         const char *tag, char *b, DWORD sz);

/*
Parse the given string and return the corresponding log_level
*/
axutil_log_levels_t axis2_iis_parse_log_level(char level[]);


/*
This is the entry point for the extention. The filter will redirect a 
given request to this extentiom. 
*/
BOOL WINAPI GetExtensionVersion(HSE_VERSION_INFO *pVer) 
{ 
	  // Create the extension version string, and copy string to HSE_VERSION_INFO structure. 
	  pVer->dwExtensionVersion =  MAKELONG(HSE_VERSION_MINOR, HSE_VERSION_MAJOR); 
	  // Copy description string into HSE_VERSION_INFO structure. 
	  strcpy(pVer->lpszExtensionDesc, "Apache Axis2c ISAPI Redirector"); 
	  return TRUE; 
} 

/*
This is the entri point for every request to the axis2c. The redirected response 
will come here. This method invoke the axis2 engine and build the response result 
and send it.
*/
DWORD WINAPI HttpExtensionProc(LPEXTENSION_CONTROL_BLOCK lpECB)
{
	DWORD rc = HSE_STATUS_ERROR;
    lpECB->dwHttpStatusCode = HTTP_INTERNAL_SERVER_ERROR;

	if (axis2_worker)
		AXIS2_IIS_WORKER_PROCESS_REQUEST(axis2_worker, axutil_env, lpECB);
	else
		return HSE_STATUS_ERROR;

	return HSE_STATUS_SUCCESS;
}

/**
This method initializes the axis2 engine. All the required variables are set to 
their initial values in this method.
*/
axis2_status_t init_axis2()
{
	/*
	These are the varibles required to initialize axis.
	*/		
    axutil_error_t *error = NULL;
    axutil_log_t *axutil_logger = NULL;
    axutil_thread_pool_t *thread_pool = NULL;
	axis2_status_t status = FALSE;	
    // We need to init xml readers before we go into threaded env     
	if (!is_inited){		
		axiom_xml_reader_init();		
		
		status = read_registery_init_data();
	 
		axutil_error_init();

		axutil_env = axutil_env_create_all(log_file, log_level);
		if (axutil_env == NULL){
			return FALSE;
		}
		
		axis2_worker = axis2_iis_worker_create(axutil_env, repo_path);
		if (axis2_worker == NULL){
			return FALSE;
		}	
		is_inited = TRUE;
	}
	return TRUE;
}

BOOL WINAPI TerminateExtension(DWORD dwFlags)
{
	return TRUE;
}


axis2_status_t axis2_terminate()
{
//	axiom_xml_reader_cleanup();

//	AXIS2_IIS_WORKER_FREE(axis2_worker, axutil_env);

//	axutil_env_free(axutil_env);
	return TRUE;
}


axis2_status_t get_extension_url(char url[], char ret_url[])
{
	unsigned int i = 0;	
	// Should contain "/axis2/"
	ret_url[0] = '\0';	
	
	// The url should begin with "/axis2/"
	if (url[0] == '/' && (url[1] == 'a' || url[1] == 'A') 
					&& (url[2] == 'x' || url[2] == 'X') 
					&& (url[3] == 'i' || url[3] == 'I') 
					&& (url[4] == 's' || url[4] == 'S') 
					&& url[5] == '2' && url[6] == '/' )
	{		

		// Append the string to redirect the request
		strcpy(ret_url, redirect_word);
		strcat(ret_url, &url[7]);
		return TRUE;
	}
	if (url[0] == '/' && (url[1] == 'a' || url[1] == 'A') 
					&& (url[2] == 'x' || url[2] == 'X') 
					&& (url[3] == 'i' || url[3] == 'I') 
					&& (url[4] == 's' || url[4] == 'S') 
					&& url[5] == '2' && url[6] == '\0')
	{
		strcpy(ret_url, redirect_word);
		return TRUE;
	}	
	return FALSE;
}

axis2_status_t read_registery_init_data()
{
	long rc = 0;
	axis2_status_t ok = TRUE;
	char tmpbuf[INTERNET_MAX_URL_LENGTH];
	HKEY hkey;

	rc = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                      REGISTRY_LOCATION, (DWORD) 0, KEY_READ, &hkey);
    
	if (ERROR_SUCCESS != rc) {
        return FALSE;
    }

    if (get_registry_config_parameter(hkey,
                                      AXIS2_IIS_REPO_PATH_TAG,
                                      tmpbuf, sizeof(repo_path))) {
        strcpy(repo_path, tmpbuf);
    }
    else {
        ok = FALSE;
    }

    if (get_registry_config_parameter(hkey,
                                      AXIS2_IIS_LOG_FILE_TAG,
                                      tmpbuf, sizeof(log_file))) {
        strcpy(log_file, tmpbuf);
    }
    else {
        ok = FALSE;
    }

    if (get_registry_config_parameter(hkey,
                                      AXIS2_IIS_LOG_LEVEL_TAG,
                                      tmpbuf, sizeof(tmpbuf))) {
        log_level = axis2_iis_parse_log_level(tmpbuf);
    }
	RegCloseKey(hkey);

	return ok;
}



axutil_log_levels_t axis2_iis_parse_log_level(char level[])
{
    if (0 == stricmp(level, AXIS2_IIS_LOG_TRACE_VERB)) {
        return AXIS2_LOG_LEVEL_TRACE;
    }

    if (0 == stricmp(level, AXIS2_IIS_LOG_DEBUG_VERB)) {
        return AXIS2_LOG_LEVEL_DEBUG;
    }

    if (0 == stricmp(level, AXIS2_IIS_LOG_INFO_VERB)) {
        return AXIS2_LOG_LEVEL_INFO;
    }

    if (0 == stricmp(level, AXIS2_IIS_LOG_WARN_VERB)) {
        return AXIS2_LOG_LEVEL_WARNING;
    }

    if (0 == stricmp(level, AXIS2_IIS_LOG_ERROR_VERB)) {
        return AXIS2_LOG_LEVEL_ERROR;
    }

    if (0 == stricmp(level, AXIS2_IIS_LOG_CRITICAL_VERB)) {
        return AXIS2_LOG_LEVEL_CRITICAL;
    }
    return AXIS2_LOG_LEVEL_CRITICAL;
}

axis2_status_t get_registry_config_parameter(HKEY hkey,
                                         const char *tag, char *b, DWORD sz)
{
    DWORD type = 0;
    LONG lrc;

    lrc = RegQueryValueEx(hkey, tag, (LPDWORD) 0, &type, (LPBYTE) b, &sz);
    if ((ERROR_SUCCESS != lrc) || (type != REG_SZ)) {
        return FALSE;
    }
    b[sz] = '\0';
    return TRUE;
}