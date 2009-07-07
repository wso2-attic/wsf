/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>

#include <platforms/axutil_platform_auto_sense.h>
#include <axiom.h>
#include <axutil_thread_pool.h>
#include <axutil_types.h>
#include <axutil_error_default.h>
#include <axutil_log_default.h>

#include <axis2_xmpp_server.h>
#include <axis2_xmpp_transport.h>
#include <axis2_xmpp_worker.h>

axutil_env_t *system_env = NULL;
axis2_transport_receiver_t *server = NULL;

/* Function headers ***********************************************************/

axutil_env_t *
init_syetem_env(
    axutil_allocator_t *allocator,
    const axis2_char_t *log_file);

void system_exit(
    axutil_env_t *env,
    int status);

void usage(
    axis2_char_t *prog_name);

void sig_handler(
    int signal);

/* End of function headers ****************************************************/

/******************************************************************************/

axutil_env_t *
init_syetem_env(
    axutil_allocator_t *allocator,
    const axis2_char_t *log_file)
{
    axutil_error_t *error = axutil_error_create(allocator);
    axutil_log_t *log = axutil_log_create(allocator, NULL, log_file);

	/* if (!log) 
 	    log = axutil_log_create_default (allocator); */

    axutil_thread_pool_t *thread_pool = axutil_thread_pool_init(allocator);
    
    /* We need to init the parser in main thread before spawning child
     * threads
     */
    
    axiom_xml_reader_init();
    
    return axutil_env_create_with_error_log_thread_pool(allocator, error, log,
            thread_pool);
}

/******************************************************************************/

void system_exit(
    axutil_env_t *env,
    int status)
{
    axutil_allocator_t *allocator = NULL;
    if (server)
    {
        axis2_transport_receiver_free(server,  system_env);
    }

    if (env)
    {
        allocator = env->allocator;
        axutil_env_free(env);
    }

    /*axutil_allocator_free(allocator);*/
    axiom_xml_reader_cleanup();
    
    _exit(status);
}

/******************************************************************************/

int main(
    int argc,
    char *argv[])
{
    axutil_allocator_t *allocator = NULL;
    axutil_env_t *env = NULL;
    extern char *optarg;
    extern int optopt;
    int c;
    axutil_log_levels_t log_level = AXIS2_LOG_LEVEL_DEBUG;
    const axis2_char_t *log_file = "axis2.log";
    int port = IKS_JABBER_PORT; /* the default port for xmpp */
    const axis2_char_t *repo_path = "../";
    int use_sasl = 0;
    int use_tls = 0;
    int subscribe = 0;

    allocator = axutil_allocator_init(NULL);

    if (NULL == allocator)
    {
        printf("[Axis2]Startup FAILED due to memory allocation failure\n");
        system_exit(NULL, -1);
    }

    env = init_syetem_env(allocator, log_file);

    axutil_error_init();
    system_env = env;

    axis2_xmpp_socket_read_timeout = AXIS2_XMPP_DEFAULT_SO_TIMEOUT;

    while ((c = AXIS2_GETOPT(argc, argv, ":p:r:t:l:f:seuh")) != -1)
    {
        switch (c)
        {
            case 'p':
                port = AXIS2_ATOI(optarg);
                break;
            case 'r':
                repo_path = optarg;
                break;
            case 't':
                axis2_xmpp_socket_read_timeout = AXIS2_ATOI(optarg) * 1000;
                break;
            case 'l':
                log_level = AXIS2_ATOI(optarg);
                if (log_level < AXIS2_LOG_LEVEL_CRITICAL)
                    log_level = AXIS2_LOG_LEVEL_CRITICAL;
                if (log_level > AXIS2_LOG_LEVEL_TRACE)
                    log_level = AXIS2_LOG_LEVEL_TRACE;
                break;
            case 'f':
                log_file = optarg;
                break;
            case 's':
                use_sasl = 1;
                break;
            case 'e':
                use_tls = 1;
                break;
            case 'u':
                subscribe = 1;
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

    env->log->level = log_level;

#ifndef WIN32
    signal(SIGINT, sig_handler);
    signal(SIGPIPE, sig_handler);
    signal(SIGSEGV, sig_handler);
#endif

    AXIS2_LOG_INFO(env->log, "Starting Axis2 XMPP server....");
    AXIS2_LOG_INFO(env->log, "Server port : %d", port);
    AXIS2_LOG_INFO(env->log, "Repo location : %s", repo_path);
    AXIS2_LOG_INFO(env->log, "Read Timeout : %d ms", axis2_xmpp_socket_read_timeout);

    server = axis2_xmpp_server_create(env, repo_path, port, use_sasl, use_tls, subscribe);
    if (!server)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create server: "
            "Error code: %d : Reason: %s",
            env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
        system_exit(env, -1);
    }

    printf("Started simple Axis2 XMPP server.\n");

    if (axis2_transport_receiver_start(server, env) == AXIS2_FAILURE)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to start server: "
            "Error code: %d : Reason: %s",
            env->error->error_number, AXIS2_ERROR_GET_MESSAGE(env->error));
        system_exit(env, -1);
    }

    return 0;
}

/******************************************************************************/

void usage(
    axis2_char_t *prog_name)
{
    fprintf(stdout, "\n Usage : %s", prog_name);
    fprintf(stdout, " [-p PORT]");
    fprintf(stdout, " [-t TIMEOUT]");
    fprintf(stdout, " [-r REPO_PATH]");
    fprintf(stdout, " [-l LOG_LEVEL]");
    fprintf(stdout, " [-f LOG_FILE]");
    fprintf(stdout, " [-s]");
    fprintf(stdout, " [-e]\n");

    fprintf(stdout, " Options :\n");
    fprintf(stdout, "\t-p PORT \t\t use the port number PORT. The default port is"
            " 5222\n");
    fprintf(stdout, "\t-r REPO_PATH \t\t use the repository path REPO_PATH. The"
            " default repository path is ../\n");
    fprintf(stdout, "\t-t SOCKET_READ_TIMEOUT\t set socket read timeout to "
            "SOCKET_READ_TIMEOUT. Default timeout is 30 seconds\n");
    fprintf(stdout, "\t-l LOG_LEVEL\t\t set log level to LOG_LEVEL. Available "
            "log levels range from 0(critical only) to 4(debug)."
            "\n\t\t\t\t Default log level is 4(debug).\n");
    fprintf(stdout, "\t-f LOG_FILE\t\t set log file to LOG_FILE. Default is $AXIS2C_HOME/logs/axis2.log"
            "\n\t\t\t\t or current folder if AXIS2C_HOME not set\n");
    fprintf(stdout, "\t-s \t\t\t enable SASL authentication\n");
    fprintf(stdout, "\t-e \t\t\t enable TLS\n");

    fprintf(stdout, " Help :\n\t-h \t\t\t display this help screen.\n\n");
}

/******************************************************************************/

/**
 * Signal handler
 */
#ifndef WIN32

void sig_handler(
    int signal)
{
    switch (signal)
    {
        case SIGINT:
        {
            AXIS2_LOG_INFO(system_env->log, "Received signal SIGINT. "
                    "Shutting down server...");
            axis2_xmpp_server_stop(server, system_env);
            AXIS2_LOG_INFO(system_env->log, "Shutdown complete.");
            system_exit(system_env, 0);
        }
        case SIGPIPE:
        {
            AXIS2_LOG_INFO(system_env->log, "Received signal SIGPIPE.  Client "
                    "request aborted.");
            return;
        }
        case SIGSEGV:
        {
            fprintf(stderr, "Received deadly signal SIGSEGV!\n");
            _exit(-1);
        }
    }
}
#endif
