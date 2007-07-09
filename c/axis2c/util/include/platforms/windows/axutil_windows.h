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


#ifndef AXIS2_WINDOWS_H
#define AXIS2_WINDOWS_H

/**
  * @file axutil_unix.h
  * @brief axis2 unix platform specific interface
  */
#include <axutil_utils_defines.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup axis2_unix Platform Specific 
 * @ingroup axis2_platforms_unix
 * @{
 */

/*enum platform_error_codes
{
   PLATFORM_ERROR_UUID_NO_ADDRESS = 0,
   PLATFORM_ERROR_OUT_OF_MEMORY = 1
};*/

#define _WINSOCKAPI_ /* Prevent inclusion of winsock.h in windows.h */
#include <windows.h>

/*for minizip uncompression library */
# include <direct.h>


/*for file access check*/
#include <io.h>
#include <sys/stat.h>

/*for network handling*/
#include <winsock2.h>
#include <fcntl.h>
#include <Mswsock.h>
/* for time */
#include <time.h>
#include <sys/timeb.h>
/* get opt */
#include "axutil_getopt_windows.h"

/***************************************************************
 * Default paths to shared library/DLLs and files
 ***************************************************************
 */
 
#define AXIS2_PLATFORM_DEFAULT_DEPLOY_PATH ""

#define AXIS2_PLATFORM_XMLPARSER_PATH      "axis2_parser.dll"
#define AXIS2_PLATFORM_TRANSPORTHTTP_PATH  "http_transport.dll"
#define AXIS2_PLATFORM_CHANNEL_PATH        "http_channel.dll"
#define AXIS2_PLATFORM_SSLCHANNEL_PATH     "Unknown"

#define AXIS2_PLATFORM_LOG_PATH            ""  /*/usr/local/axis2/log/axutil_log*/
#define AXIS2_PLATFORM_CLIENTLOG_PATH      "" /* /usr/local/axis2/log/axis2_client_log*/
#define AXIS2_PLATFORM_CONFIG_PATH         "" /* /etc/axiscpp.conf */
#define AXIS2_PLATFORM_SECUREINFO          "" 

/**
 * Resource that contains the configuration
 */
#define AXIS2_CONFIGURATION_RESOURCE "" /* should be set */

// =============================================================
// Library loading and procedure resolution
// =============================================================
#define DLHandler HINSTANCE
#define RTLD_LAZY 0    // not sure this is needed?

#define AXIS2_PLATFORM_LOADLIBINIT()
#define AXIS2_PLATFORM_LOADLIB(_lib)     /*LoadLibrary(_lib) */ callLoadLib(_lib)
#define AXIS2_PLATFORM_UNLOADLIB         FreeLibrary
#define AXIS2_PLATFORM_GETPROCADDR       GetProcAddress
#define AXIS2_PLATFORM_LOADLIBEXIT()
#define AXIS2_PLATFORM_LOADLIB_ERROR     ""

#define AXIS2_DLHANDLER void*

// =============================================================
// National Language Support
// =============================================================

// STRTOASC is to translate single byte 'native' character representation to ASCII
// ASCTOSTR is to translate single byte ascii representation to 'native' character
// CANNOT be used with constants
#define AXIS2_PLATFORM_STRTOASC( x ) ( x )
#define AXIS2_PLATFORM_ASCTOSTR( x ) ( x )

// =============================================================
// Miscellaneous
// =============================================================

#define AXIS2_STRRCHR(x, y) (strrchr(x, y))

#define AXIS2_PLATFORM_SLEEP(x) Sleep(0);

#define AXIS2_SLEEP(x) Sleep((x)*1000)
#define AXIS2_USLEEP(x) Sleep((x)/1000);
/**
 * Get the last error code from the system.
 * Please ensure that this is a thread safe implementation
 * and that it returns a long
 * @return long the lsat error message for this thread
 */
#define AXIS2_GETLASTERROR GetLastError();

/**
 * From the last error number get a sensible std::string representing it
 * @param errorNumber the error Number you are trying to get a message for
 * @return the error message. NOTE: The caller is responsible for deleting the returned string
 */
#define AXIS2_PLATFORM_GET_ERROR_MESSAGE(errorNumber) getPlatformErrorMessage(errorNumber);

/**
 * type to be used for 64bit integers
 */
#define AXIS2_LONGLONG __int64

/**
 * Format string to be used in printf for 64bit integers
 */
#define AXIS2_PRINTF_LONGLONG_FORMAT_SPECIFIER "%I64d"
#define AXIS2_PRINTF_LONGLONG_FORMAT_SPECIFIER_CHARS "I64d"

AXIS2_EXTERN HMODULE AXIS2_CALL
callLoadLib(char* lib);

AXIS2_EXTERN struct tm * AXIS2_CALL 
axis2_win_gmtime(const time_t *timep, struct tm *result);

/**
 * Platform specific path separator char
 */
#define AXIS2_PATH_SEP_CHAR '/'
#define AXIS2_PATH_SEP_STR "/"
#define AXIS2_LIB_PREFIX ""
#define AXIS2_LIB_SUFFIX ".dll"

/**
 * Platform specific time
 */
#define AXIS2_TIME_T time_t
/**
 * Platform specific method to obtain current time in milli seconds
 */
#define AXIS2_PLATFORM_GET_TIME_IN_MILLIS _ftime
#define AXIS2_PLATFORM_TIMEB _timeb
/**
 * Platform specific file handling
 */
#define AXIS2_FOPEN fopen
#define AXIS2_FREAD fread
#define AXIS2_FWRITE fwrite
#define AXIS2_FCLOSE fclose
#define AXIS2_ACCESS(zpath,imode) _access(zpath,imode)
#define AXIS2_R_OK 04 /* test for read permission */
#define AXIS2_W_OK 02 /* test for write permission */
#define AXIS2_X_OK 00 /* test for execute or search permission */
#define AXIS2_F_OK 00 /* test whether the directories leading to the file can be 
                      searched and the file exists */
/**
  * windows specific directory handling functions
  */
#define AXIS2_SCANDIR      scandir
#define AXIS2_ALPHASORT      alphasort
#define AXIS2_OPENDIR      opendir
#define AXIS2_CLOSEDIR      closedir
#define AXIS2_READDIR      readdir
#define AXIS2_READDIR_R      readdir_r
#define AXIS2_REWINDDIR      rewinddir
#define AXIS2_MKDIR(path,x)  _mkdir(path)

/**
  * network specific functions and defs
  */
#define axis2_socket_t                  SOCKET

#define AXIS2_INVALID_SOCKET            INVALID_SOCKET
#define AXIS2_INADDR_NONE               INADDR_NONE
#define axis2_unsigned_short_t            u_short
#define AXIS2_CLOSE_SOCKET(sock)         closesocket(sock)
#define AXIS2_CLOSE_SOCKET_ON_EXIT(sock)   
#define axis2_socket_len_t               int
#define AXIS2_SHUT_WR                       SD_SEND

/**
 * Platform specific environment variable access method
 */
#define AXIS2_GETENV(_env_var_name) getenv(_env_var_name)

/**
 * minizip functions
 */
#define axis2_fill_win32_filefunc(ffunc) fill_win32_filefunc(ffunc)
#define AXIS2_UNZOPEN2(zipfilename,ffunc)   unzOpen2(zipfilename,NULL)

/**
  * handling variable number of arguments (for log.c)
  */
  
/** getopt function */
#define AXIS2_GETOPT axis2_getopt  
/** string functions */  
#define AXIS2_VSNPRINTF _vsnprintf

#define AXIS2_SNPRINTF _snprintf

#define axis2_gmtime_r axis2_win_gmtime

/** @} */
#ifdef __cplusplus
}
#endif
#endif /*  AXIS2_WINDOWS_H */


