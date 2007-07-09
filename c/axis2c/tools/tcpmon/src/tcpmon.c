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
#include <stdio.h>

#define SIZE 1024
axis2_char_t *tcpmon_traffic_log = "tcpmon_traffic.log";

int on_new_entry(const axutil_env_t *env,
					  tcpmon_entry_t* entry,
					  int status);
int on_new_entry_to_file(const axutil_env_t *env,
					  tcpmon_entry_t* entry,
					  int status);
int on_error_func(const axutil_env_t *env,
						char* error_message);

char *str_replace(char *str, const char *search, const char *replace);


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
				printf("Usage : %s [-lp LISTEN_PORT] [-tp TARGET_PORT] [-th TARGET_HOST] [-f LOG_FILE]\n", argv[0]);
                fprintf(stdout, " Options :\n");
                fprintf(stdout, "\t-lp LISTEN_PORT \t port number to listen on, default is 9090\n");
                fprintf(stdout, "\t-tp TARGET_PORT \t port number to connect and re-direct messages, default is 8080\n");
                fprintf(stdout, "\t-th TARGET_HOST \t target host to connect, default is localhost\n");
                fprintf(stdout, "\t-f  LOG_FILE    \t file to write the messages to, default is %s\n", tcpmon_traffic_log);
                fprintf(stdout, " Help :\n\t-h \t display this help screen.\n\n");
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
								printf("Use -h for help\n");
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
								printf("Use -h for help\n");
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
                else if (!strcmp ("-f", argv[ii]))
				{
						ii++;
						tcpmon_traffic_log = argv[ii++];
				}
				else
				{
						printf("INVALID value for tcpmon \n");
						printf("Use -h for help\n");
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

		TCPMON_SESSION_ON_NEW_ENTRY(session, env, on_new_entry_to_file);

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


int on_new_entry_to_file(const axutil_env_t *env,
					  tcpmon_entry_t* entry,
					  int status)
{
		char* plain_buffer = NULL;
		char* formated_buffer = NULL;
        int format = 0;
		FILE *file;
		char *convert = NULL;

		file = fopen(tcpmon_traffic_log, "a+");

		if(NULL == file) {
			printf("\ncould not create or open log-file\n");
			return -1;
		}

		fprintf(file, "\n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");

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
				/* 2 screen */
				printf("%s\n", "SENDING DATA..");
				printf("/* sending time = %s*/\n", TCPMON_ENTRY_SENT_TIME(entry, env));
				printf("---------------------\n");

				printf("%s\n\n%s\n\n", TCPMON_ENTRY_SENT_HEADERS(entry, env), formated_buffer);

				/* 2 file */
				fprintf(file, "%s\n", "SENDING DATA..");
				fprintf(file, "/* sending time = %s*/\n", TCPMON_ENTRY_SENT_TIME(entry, env));
				fprintf(file, "---------------------\n");

				convert = TCPMON_ENTRY_SENT_HEADERS(entry, env);
				convert = str_replace(convert, "; ", ";\n\t");
				fprintf(file, "%s", convert);

				convert = formated_buffer;
				convert = str_replace(convert, "; ", ";\n\t");
				convert = str_replace(convert, "><", ">\n<");
				fprintf(file, "%s", convert);

				
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
				/* 2 screen */
				printf("%s\n", "RETRIEVING DATA..");
				printf("/* retrieving time = %s*/\n", TCPMON_ENTRY_ARRIVED_TIME(entry, env));
				printf("/* time throughput = %s*/\n", TCPMON_ENTRY_TIME_DIFF(entry, env));
				printf("---------------------\n");

				printf("%s\n\n%s\n\n", TCPMON_ENTRY_ARRIVED_HEADERS(entry, env), formated_buffer);

				/* 2 file */
				fprintf(file, "%s\n", "RETRIEVING DATA..");
				fprintf(file, "/* retrieving time = %s*/\n", TCPMON_ENTRY_ARRIVED_TIME(entry, env));
				fprintf(file, "/* time throughput = %s*/\n", TCPMON_ENTRY_TIME_DIFF(entry, env));
				fprintf(file, "---------------------\n");

				convert = TCPMON_ENTRY_ARRIVED_HEADERS(entry, env);
				convert = str_replace(convert, "; ", ";\n\t");
				fprintf(file, "%s", convert);

				convert = formated_buffer;
				convert = str_replace(convert, "; ", ";\n\t");
				convert = str_replace(convert, "><", ">\n<");
				fprintf(file, "%s", convert);
		}

		fclose(file);

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

				printf("%s\n\n%s\n\n", TCPMON_ENTRY_SENT_HEADERS(entry, env), formated_buffer);
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




char *str_replace(char *str, const char *search, const char *replace) {
	int size = strlen(str) * 2;
	int addmem = size;
	int diff = strlen(replace)-strlen(search);

	char *str_return = (char *) malloc(size *sizeof(char));
	char *str_tmp = (char *) malloc(size * sizeof(char));
	char *str_relic;	

	if(str_return == NULL || str_tmp == NULL) {
		free(str_return);
		free(str_tmp);
		return "function str_replace : gimme more memory";
	}

	strcpy(str_return, str);

	while( (str_relic = strstr(str_return, search)) != NULL) {
		if( strlen(str_return) + diff >= addmem) {
			str_return = (char *) realloc(str_return, addmem+=size);
			str_tmp = (char *) realloc(str_tmp, addmem);

			if(str_return == NULL || str_tmp == NULL) {
				free(str_return);
				free(str_tmp);
				return "function str_replace : gimme more memory";
			}
		}

		strcpy(str_tmp, replace);
		strcat(str_tmp, (str_relic+strlen(search)) );
		*str_relic = '\0';

		strcat(str_return, str_tmp);
	}

	free(str_tmp);
	return(str_return);
}













