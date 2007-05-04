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

#include <axutil_utils.h>
#include <axutil_error_default.h>
#include <axutil_log_default.h>
#include <axutil_thread_pool.h>
#include <tcpmon_session.h>
#include <tcpmon_entry.h>
#include <tcpmon_util.h>
#include <platforms/axutil_platform_auto_sense.h>
#include <axutil_string.h>

#define SIZE 1024

int on_new_entry(const axutil_env_t *env,
					  tcpmon_entry_t* entry,
					  int status);
int on_error_func(const axutil_env_t *env,
						char* error_message);

int main(int argc, char** argv)
{
		axutil_env_t* env = NULL;
		axutil_allocator_t* allocator = NULL;
		axutil_error_t *error = NULL;
		axutil_log_t *log = NULL;
		axutil_thread_pool_t *thread_pool = NULL;
		tcpmon_session_t* session = NULL;
		int c;
		int listen_port = 9090, target_port = 8080;
		char *target_host = NULL;
		int test_bit = 0;
        int format_bit = 0;
		int ii = 1;

		allocator = axutil_allocator_init(NULL);

		error = axutil_error_create(allocator);
		log = axutil_log_create(allocator, NULL, "axis2_tcpmon.log");
		thread_pool = axutil_thread_pool_init(allocator);

		env = axutil_env_create_with_error_log_thread_pool(allocator, error, log,
																		  thread_pool);
        target_host = axutil_strdup(env, "localhost");
        
		if (!axutil_strcmp(argv[1], "-h"))
		{
				printf("Usage : %s [OPTIONS] -lp LISTEN_PORT -tp TARGET_PORT -th [TARGET_HOST]\n", argv[0]);
				printf("use -h for help\n");
				return 0;
		}

		while (ii < argc)
		{
				if (!strcmp ("-lp", argv[ii]))
				{
						ii++;
						listen_port = atoi(argv[ii++]);
						if (listen_port == 0)
						{
								printf("INVALID value for listen port\n");
								printf("use -h for help\n");
								return 0;
						}

				}
				else if (!strcmp ("-tp", argv[ii]))
				{
						ii++;
						target_port = atoi(argv[ii++]);
						if (target_port == 0)
						{
								printf("INVALID value for target port\n");
								printf("use -h for help\n");
								return 0;
						}
				}
				else if (!strcmp ("-th", argv[ii]))
				{
						ii++;
						target_host = (char*)axutil_strdup(env, argv[ii++]);
				}
				else if (!strcmp ("--test", argv [ii]))
				{
						ii++;
						test_bit = 1;
				}
                else if (!strcmp ("--format",argv [ii]))
                {
                    ii++;
                    format_bit = 1;
                }
				else
				  {
						printf("INVALID value for tcpmon \n");
						printf("use -h for help\n");
						return 0;
				  }
		}

		if (!(listen_port && target_port && target_host))
        {
				printf ("ERROR: essential argument missing \n");
				printf ("Please recheck values of listen_port (-lp), target_port(-tp) and target_host (-th)\n");
				return 0;
        }

        printf ("Listen port : %d Target port : %d Target host: %s\n", 
            listen_port, target_port, target_host);
		session = tcpmon_session_create(env);

		TCPMON_SESSION_SET_LISTEN_PORT(session, env, listen_port);
		TCPMON_SESSION_SET_TARGET_PORT(session, env, target_port);
		TCPMON_SESSION_SET_TARGET_HOST(session, env, target_host);
		TCPMON_SESSION_ON_TRANS_FAULT(session, env, on_error_func);
		TCPMON_SESSION_ON_NEW_ENTRY(session, env, on_new_entry);
		TCPMON_SESSION_SET_TEST_BIT (session, env, test_bit);
		TCPMON_SESSION_SET_FORMAT_BIT(session, env, format_bit);
		TCPMON_SESSION_START(session, env);

		do
		{
				c = getchar();
		}
		while (c != 'q');

		TCPMON_SESSION_STOP(session, env);
		TCPMON_SESSION_FREE(session, env);
		AXIS2_FREE(env-> allocator, target_host);
		axutil_allocator_free(allocator);
		axutil_env_free(env);
		return 0;
}

int on_new_entry(const axutil_env_t *env,
					  tcpmon_entry_t* entry,
					  int status)
{
		char* plain_buffer = NULL;
		char* formated_buffer = NULL;
        int format = 0;

        format = TCPMON_ENTRY_GET_FORMAT_BIT(entry, env);

		if (status == 0)
		{
				plain_buffer = TCPMON_ENTRY_SENT_DATA(entry, env);
				if (plain_buffer) /* this can be possible as no xml present */
				{
						formated_buffer = tcpmon_util_format_as_xml
								(env, plain_buffer, format);
				}
				else
				{
						formated_buffer = "";
				}
				printf("%s\n", "SENDING DATA..");
				printf("/* sending time = %s*/\n", TCPMON_ENTRY_SENT_TIME(entry, env));
				printf("---------------------\n");

				printf("%s\n\n%s\n\n", TCPMON_ENTRY_SENT_HEADERS(entry, env),
						 formated_buffer);
		}
		if (status == 1)
		{
				plain_buffer = TCPMON_ENTRY_ARRIVED_DATA(entry, env);
				if (plain_buffer) /* this can be possible as no xml present */
				{
						formated_buffer = tcpmon_util_format_as_xml
								(env, plain_buffer, format);
				}
				else
				{
						formated_buffer = "";
				}
				printf("%s\n", "RETRIEVING DATA..");
				printf("/* retrieving time = %s*/\n", TCPMON_ENTRY_ARRIVED_TIME(entry, env));
				printf("/* time throughput = %s*/\n", TCPMON_ENTRY_TIME_DIFF(entry, env));
				printf("---------------------\n");

				printf("%s\n\n%s\n\n", TCPMON_ENTRY_ARRIVED_HEADERS(entry, env),
						 formated_buffer);
		}
		return 0;
}

int on_error_func(const axutil_env_t *env,
						char* error_message)
{
		fprintf(stderr, "ERROR: %s\n", error_message);
		return 0;
}















