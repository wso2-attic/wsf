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

#include <platforms/axutil_platform_auto_sense.h>
#include <axis2_udp_receiver.h>
#include <stdio.h>
#include <stdlib.h>
#include <axutil_error_default.h>
#include <axutil_log_default.h>
#include <axutil_thread_pool.h>
#include <signal.h>
#include <axutil_types.h>
#include <ctype.h>
#include <axiom_xml_reader.h>
#include <axutil_version.h>
#include <axutil_file_handler.h>

axutil_env_t *system_env = NULL;
axis2_transport_receiver_t *server = NULL;
AXIS2_IMPORT extern int axis2_udp_socket_read_timeout;
AXIS2_IMPORT extern axis2_char_t *axis2_request_url_prefix;

#define DEFAULT_REPO_PATH "../"

/***************************** Function headers *******************************/
axutil_env_t *init_syetem_env(
    axutil_allocator_t * allocator,
    const axis2_char_t * log_file);

void system_exit(
    axutil_env_t * env,
    int status);

void usage(
    axis2_char_t * prog_name);

void sig_handler(
    int signal);


axutil_env_t *
init_syetem_env(
    axutil_allocator_t * allocator,
    const axis2_char_t * log_file)
{
    axutil_error_t *error = axutil_error_create(allocator);
    axutil_log_t *log = axutil_log_create(allocator, NULL, log_file);

    axutil_thread_pool_t *thread_pool = axutil_thread_pool_init(allocator);
    /* We need to init the parser in main thread before spawning child
     * threads
     */
    axiom_xml_reader_init();
    return axutil_env_create_with_error_log_thread_pool(allocator, error, log,
                                                        thread_pool);
}

void
system_exit(
    axutil_env_t * env,
    int status)
{
    axutil_allocator_t *allocator = NULL;
    if (server)
    {
        axis2_transport_receiver_free(server, system_env);
    }
    if (env)
    {
        allocator = env->allocator;
        axutil_env_free(env);
    }
    /*axutil_allocator_free(allocator); */
    axiom_xml_reader_cleanup();
    exit(status);
}

int
main(
    int argc,
    char *argv[])
{
    axutil_allocator_t *allocator = NULL;
    axutil_env_t *env = NULL;
    extern char *optarg;
    extern int optopt;
    int c;
	unsigned int len;
    int log_file_size = AXUTIL_LOG_FILE_SIZE;
	unsigned int file_flag = 0;
    axutil_log_levels_t log_level = AXIS2_LOG_LEVEL_DEBUG;
    const axis2_char_t *log_file = "axis2.log";
    const axis2_char_t *repo_path = DEFAULT_REPO_PATH;
	axis2_char_t *multicast_group = NULL;
    int port = 9090;
	axis2_status_t status;
	

    /* Set the service URL prefix to be used. This could default to services if not 
       set with AXIS2_REQUEST_URL_PREFIX macro at compile time */
    axis2_request_url_prefix = AXIS2_REQUEST_URL_PREFIX;

	while ((c = AXIS2_GETOPT(argc, argv, ":p:r:h:m:l:s:f:")) != -1)
    {

        switch (c)
        {
        case 'p':
            port = AXIS2_ATOI(optarg);
            break;
        case 'r':
            repo_path = optarg;
            break;      
		case 'm':
			multicast_group = optarg;
        case 'l':
            log_level = AXIS2_ATOI(optarg);
            if (log_level < AXIS2_LOG_LEVEL_CRITICAL)
                log_level = AXIS2_LOG_LEVEL_CRITICAL;
            if (log_level > AXIS2_LOG_LEVEL_TRACE)
                log_level = AXIS2_LOG_LEVEL_TRACE;
            break;
        case 's':
            log_file_size = 1024 * 1024 * AXIS2_ATOI(optarg);
            break;
        case 'f':
            log_file = optarg;
            break;
        case 'h':
            usage(argv[0]);
            return 0;
        case ':':
            fprintf(stderr, "\nOption -%c requires an operand\n", optopt);
            usage(argv[0]);
            return -1;
        case '?':
            if (isprint(optopt))
                fprintf(stderr, "\nUnknown option `-%c'.\n", optopt);
            usage(argv[0]);
            return -1;
        }
    }

    allocator = axutil_allocator_init(NULL);

    if (!allocator)
    {
        system_exit(NULL, -1);
    }

    env = init_syetem_env(allocator, log_file);
    env->log->level = log_level;
    env->log->size = log_file_size;

    axutil_error_init();
    system_env = env;

    signal(SIGINT, sig_handler);
#ifndef WIN32
    signal(SIGPIPE, sig_handler);
#endif

    AXIS2_LOG_INFO(env->log, "Starting Axis2 UDP server....");
    AXIS2_LOG_INFO(env->log, "Apache Axis2/C version in use : %s",
                   axis2_version_string());
    AXIS2_LOG_INFO(env->log, "Server port : %d", port);
    AXIS2_LOG_INFO(env->log, "Repo location : %s", repo_path);
	
	status = axutil_file_handler_access (repo_path, AXIS2_R_OK);
	if (status == AXIS2_SUCCESS)
	{
		len = (unsigned int)strlen (repo_path);
        /* We are sure that the difference lies within the unsigned int range */
		if ((len >= 9) &&
            !strcmp ((repo_path + (len - 9)), "axis2.xml"))
		{
			file_flag = 1;
		}
	}
	else
	{
		AXIS2_LOG_WARNING (env->log, AXIS2_LOG_SI, "provided repo path %s does " 
						   "not exist or no permissions to read, set "
						   "repo_path to DEFAULT_REPO_PATH", repo_path);
		repo_path = DEFAULT_REPO_PATH;
	}
	

	if (!file_flag)
    	server = axis2_udp_receiver_create(env, repo_path, port, multicast_group);
	else
		server = axis2_udp_receiver_create_with_file (env, repo_path, port);
	
    if (!server)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                        "Server creation failed: Error code:" " %d :: %s",
                        env->error->error_number,
                        AXIS2_ERROR_GET_MESSAGE(env->error));
        system_exit(env, -1);

    }
    printf("Started Simple Axis2 UDP Server ...\n");
    if (axis2_transport_receiver_start(server, env) == AXIS2_FAILURE)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                        "Server start failed: Error code:" " %d :: %s",
                        env->error->error_number,
                        AXIS2_ERROR_GET_MESSAGE(env->error));
        system_exit(env, -1);
    }
    return 0;
}

void
usage(
    axis2_char_t * prog_name)
{
    fprintf(stdout, "\n Usage : %s", prog_name);
    fprintf(stdout, " [-p PORT]");
	fprintf(stdout, " [-m MULTICAST_GROUP]");
    fprintf(stdout, " [-r REPO_PATH]");
    fprintf(stdout, " [-l LOG_LEVEL]");
    fprintf(stdout, " [-f LOG_FILE]\n");
    fprintf(stdout, " [-s LOG_FILE_SIZE]\n");
    fprintf(stdout, " Options :\n");
    fprintf(stdout, "\t-p PORT \t port number to use, default port is 9090\n");
    fprintf(stdout, "\t-r REPO_PATH \t repository path, default is ../\n");
    fprintf(stdout,
            "\t-t TIMEOUT\t socket read timeout, default is 30 seconds\n");
    fprintf(stdout,
            "\t-l LOG_LEVEL\t log level, available log levels:"
            "\n\t\t\t 0 - critical    1 - errors 2 - warnings"
            "\n\t\t\t 3 - information 4 - debug  5- user 6- trace"
            "\n\t\t\t Default log level is 4(debug).\n");
#ifndef WIN32
    fprintf(stdout,
            "\t-f LOG_FILE\t log file, default is $AXIS2C_HOME/logs/axis2.log"
            "\n\t\t\t or axis2.log in current folder if AXIS2C_HOME not set\n");
#else
    fprintf(stdout,
            "\t-f LOG_FILE\t log file, default is %%AXIS2C_HOME%%\\logs\\axis2.log"
            "\n\t\t\t or axis2.log in current folder if AXIS2C_HOME not set\n");
#endif
    fprintf(stdout,
            "\t-s LOG_FILE_SIZE\t Maximum log file size in mega bytes, default maximum size is 1MB.\n");
    fprintf(stdout, " Help :\n\t-h \t display this help screen.\n\n");
}

/**
 * Signal handler
 */
void
sig_handler(
    int signal)
{

    if (!system_env)
    {
        AXIS2_LOG_ERROR(system_env->log, AXIS2_LOG_SI,
                        "Received signal %d, unable to proceed system_env is NULL ,\
                         system exit with -1", signal);
        _exit (-1);
    }

    switch (signal)
    {
    case SIGINT:
        {
            /* Use of SIGINT in Windows is valid, since we have a console application
             * Thus, eventhough this may a single threaded application, it does work.
             */
            AXIS2_LOG_INFO(system_env->log, "Received signal SIGINT. Server "
                           "shutting down");
            if (server)
            {
                axis2_udp_receiver_stop(server, system_env);
            }

            AXIS2_LOG_INFO(system_env->log, "Shutdown complete ...");
            system_exit(system_env, 0);
        }
#ifndef WIN32
    case SIGPIPE:
        {
            AXIS2_LOG_INFO(system_env->log, "Received signal SIGPIPE.  Client "
                           "request serve aborted");
            return;
        }
#endif
    case SIGSEGV:
        {
            fprintf(stderr, "Received deadly signal SIGSEGV. Terminating\n");
            _exit(-1);
        }
    }
}
