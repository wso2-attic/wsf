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


#ifndef AXIS2_UNIX_H
#define AXIS2_UNIX_H

#ifdef IS_MACOSX
    #include <config.h>
#endif

/**
  * @file axutil_unix.h
  * @brief axis2 unix platform specific interface
  */

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup axis2_unix Platform Specific 
 * @ingroup axis2_platforms_unix
 * @{
 */
    
/***************************************************************
 * Default paths to shared library/DLLs and files
 ***************************************************************
 */
 
#define AXIS2_PLATFORM_DEFAULT_DEPLOY_PATH ""

#define AXIS2_PLATFORM_XMLPARSER_PATH      "libaxis2_parser.so"
#define AXIS2_PLATFORM_TRANSPORTHTTP_PATH  "libhttp_transport.so"
#define AXIS2_PLATFORM_CHANNEL_PATH        "libhttp_channel.so"
#define AXIS2_PLATFORM_SSLCHANNEL_PATH     "Unknown"

#define AXIS2_PLATFORM_LOG_PATH            "/usr/local/axis2/log/axutil_log"
#define AXIS2_PLATFORM_CLIENTLOG_PATH      "/usr/local/axis2/log/axis2_client_log"
#define AXIS2_PLATFORM_CONFIG_PATH         "/etc/axiscpp.conf"
#define AXIS2_PLATFORM_SECUREINFO          ""
/**
 * Resource that contains the configuration
 */
#define AXIS2_CONFIGURATION_RESOURCE "/usr/local/axis2/axis2.xml"

/*****************************************************************
 * Library loading and procedure resolution
 ****************************************************************/
#ifdef USE_LTDL
 #include <ltdl.h>
 #define AXIS2_DLHandler lt_dlhandle

 #define AXIS2_PLATFORM_LOADLIBINIT       lt_dlinit
 #define AXIS2_PLATFORM_LOADLIB(_lib)     lt_dlopen(_lib)
 #define AXIS2_PLATFORM_UNLOADLIB         lt_dlclose
 #define AXIS2_PLATFORM_GETPROCADDR       lt_dlsym
 #define AXIS2_PLATFORM_LOADLIBEXIT       lt_dlexit
 #define AXIS2_PLATFORM_LOADLIB_ERROR     lt_dlerror()
#else
 #include <dlfcn.h>
 #define AXIS2_DLHANDLER void*

 #define AXIS2_PLATFORM_LOADLIBINIT()
 #define AXIS2_PLATFORM_LOADLIB(_lib)     dlopen(_lib, RTLD_LAZY)
 /*#define AXIS2_PLATFORM_LOADLIB(_lib)     dlopen(_lib, RTLD_NOW)*/

 #define AXIS2_PLATFORM_UNLOADLIB         dlclose
 #define AXIS2_PLATFORM_GETPROCADDR       dlsym
 #define AXIS2_PLATFORM_LOADLIBEXIT()
 #define AXIS2_PLATFORM_LOADLIB_ERROR     dlerror()

#endif

/***************************************************************
 * National Language Support
 ****************************************************************/

/* STRTOASC is to translate single byte 'native' character representation to ASCII */
/* ASCTOSTR is to translate single byte ascii representation to 'native' character */
/* CANNOT be used with constants */
#define AXIS2_PLATFORM_STRTOASC( x ) ( x )
#define AXIS2_PLATFORM_ASCTOSTR( x ) ( x )

/***************************************************************
 * Miscellaneous
****************************************************************/
#include <sys/time.h>
#include <sys/timeb.h>
#include <unistd.h>
#include <errno.h>
#include <sys/param.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "axutil_uuid_gen_unix.h" /* uuid_gen unix implementation */
#include <netinet/tcp.h>    /* TCP_NODELAY */
#include <utime.h>
#include <getopt.h>
#include "axutil_date_time_util_unix.h"


/* for file access handling */
#include <unistd.h>

/* network handling*/
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>

#include <zlib.h>
#include <fcntl.h>


/* dir handling */
#include <dirent.h>

#define AXIS2_STRRCHR(x, y) (strrchr(x, y))

#define AXIS2_PLATFORM_SLEEP(x) sleep(0);
/** sleep function abstraction */
#define AXIS2_SLEEP sleep 
#define AXIS2_USLEEP usleep 
/**
 * Get the last error code from the system.
 * Please ensure that this is a thread safe implementation
 * and that it returns a long
 * @return long the lsat error message for this thread
 */
/*#define AXIS2_GETLASTERROR errno; */

/**
 * From the last error number get a sensible std::string representing it
 * @param errorNumber the error Number you are trying to get a message for
 * @return the error message. NOTE: The caller is responsible for deleting the returned string
 */

/*#define AXIS2_PLATFORM_GET_ERROR_MESSAGE(errorNumber) new string(strerror(errorNumber));*/

/**
 * Platform specific method to obtain current thread ID
 */
#include <pthread.h>
#define AXIS2_PLATFORM_GET_THREAD_ID pthread_self()

/**
 * Platform specific method to obtain current time in milli seconds
 */
#define AXIS2_PLATFORM_GET_TIME_IN_MILLIS ftime
#define AXIS2_PLATFORM_TIMEB timeb

/**
 * type to be used for 64bit integers
 */
#define AXIS2_LONGLONG long long
#define AXIS2_LONGLONGVALUE(value) value##LL
#define AXIS2_UNSIGNED_LONGLONGVALUE(value) value##ULL

/**
 * Format string to be used in printf for 64bit integers
 */
#define AXIS2_PRINTF_LONGLONG_FORMAT_SPECIFIER "%lld"
#define AXIS2_PRINTF_LONGLONG_FORMAT_SPECIFIER_CHARS "lld"
#define AXIS2_PRINTF_UNSIGNED_LONGLONG_FORMAT_SPECIFIER "%llu"
#define AXIS2_PRINTF_UNSIGNED_LONGLONG_FORMAT_SPECIFIER_CHARS "llu"

/**
 * Platform specific path separator char
 */
#define AXIS2_PATH_SEP_CHAR '/'
#define AXIS2_PATH_SEP_STR "/"
#define AXIS2_LIB_PREFIX "lib"
#define AXIS2_LIB_SUFFIX ".so"

/**
 * Platform specific time
 */
#define AXIS2_TIME_T time_t

/**
 * Platform specific file handling
 */
#define AXIS2_FOPEN fopen
#define AXIS2_FREAD fread
#define AXIS2_FWRITE fwrite
#define AXIS2_FCLOSE fclose
#define AXIS2_ACCESS(zpath,imode) access(zpath,imode)
#define AXIS2_R_OK R_OK /* test for read permission */
#define AXIS2_W_OK W_OK /* test for write permission */
#define AXIS2_X_OK X_OK /* test for execute or search permission */
#define AXIS2_F_OK F_OK /* test whether the directories leading to the file can be 
                      searched and the file exists */
                      
/**
 * Platform specific environment variable access method
 */
#define AXIS2_GETENV(_env_var_name) getenv(_env_var_name)

/**
  * unix specific directory handling functions
  */
#define AXIS2_SCANDIR       scandir
#define AXIS2_ALPHASORT     alphasort
#define AXIS2_OPENDIR       opendir
#define AXIS2_CLOSEDIR      closedir
#define AXIS2_READDIR       readdir
#define AXIS2_READDIR_R     readdir_r
#define AXIS2_REWINDDIR     rewinddir
#define AXIS2_MKDIR			mkdir

/**
  * network specific functions and defs
  */
#define axis2_socket_t                      int
#define AXIS2_INVALID_SOCKET                -1
#define AXIS2_INADDR_NONE                   (in_addr_t)-1
#define axis2_unsigned_short_t                uint16_t
#define AXIS2_CLOSE_SOCKET(sock)            close(sock)
#define AXIS2_CLOSE_SOCKET_ON_EXIT(sock)    fcntl(sock,F_SETFD, FD_CLOEXEC);
#define axis2_socket_len_t                  socklen_t
#define AXIS2_SHUT_WR                       SHUT_WR

/** getopt function */
#define AXIS2_GETOPT getopt

/** minizip functions */
#define axis2_fill_win32_filefunc(ffunc) 
#define AXIS2_UNZOPEN2(zipfilename,ffunc) unzOpen2(zipfilename,NULL); memset(&ffunc, 0, sizeof(ffunc)); 

/**
  * handling variable number of arguments (for log.c)
  */
#define AXIS2_VSNPRINTF vsnprintf

#define AXIS2_SNPRINTF snprintf

#define axis2_gmtime_r gmtime_r

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* AXIS2_UNIX_H */
