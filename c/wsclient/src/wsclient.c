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

#include "option.h"
#include "constants.h"
#include "stub.h"
#include "error.h"
#include <axiom.h>

#define BUFF_SIZE 32

static void 
print_help ();

static void 
print_usage ();

static void 
print_version ();

static void
parse_input(const axutil_env_t *env,
			axis2_char_t **input);


int main (int argc, char **argv)
{
	axutil_env_t *env;
	char *input[2];
 	char *dest_uri = NULL;
	axutil_array_list_t *array_list;
	axis2_status_t status;
	env = axutil_env_create_all ("wsclient.log", AXIS2_LOG_LEVEL_DEBUG);
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
					"[wsclient]wsclient initiated ");

	if (argc > 1)
	{
	    if (!strcmp (argv[1], "-h") || !strcmp (argv[1], "--help"))
			print_help ();
		else if (!strcmp (argv[1], "-v") || !strcmp (argv[1], "--version"))
			print_version ();

		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
						"[wsclient]waiting for input  ");
	    parse_input (env, input);

	    dest_uri = wsclient_destination (argc, argv);
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
						"[wsclient]sending request to  %s", dest_uri);

	    array_list = wsclient_process_options (argc, argv, env);
	    status = wsclient_stub_invoke (env, array_list, dest_uri, *input);
		AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "[wsclient]wsclient invoked ");
		
		switch (status)
		{
			case WSCLIENT_FAILURE:
			{
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
								"[wsclient] wsclient invoke failed!");
				printf ("\nwsclient invoke failed ! \n");
			}
			break;
			case WSCLIENT_ERROR_NO_DESTURI:
			{
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
								"[wsclient] wsclient invoke failed !");
				printf ("\nwsclient invoke failed ! \n");
			}
			break;
			case WSCLIENT_SUCCESS:
			{
				AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, 
								"[wsclient] wsclient invoke Success !");
				printf ("\nwsclient invoke Success ! \n");
			}
			break;
		};

	}
	else
	    print_usage ();
	axutil_env_free ((void *)env);
	return 0;
}


static void print_usage ()
{
	printf ("Usage: wsclient [options] [destURI]\n");
	printf ("      See wsclient -h for help.\n");
}

static void print_version ()
{
	static const char *version [] = 
	    {
			("\
\n"),
			("\
             wsclient 1.0     \n"),
			("\
\n"),
			("\
  Licensed to the Apache Software Foundation (ASF) under one or more\n"),
			("\
 contributor license agreements.  See the NOTICE file distributed with\n"),
			("\
 this work for additional information regarding copyright ownership.\n"),
			("\
 The ASF licenses this file to You under the Apache License, Version 2.0\n"),
			("\
 (the \"License\"); you may not use this file except in compliance with\n"),
			("\
 the License.  You may obtain a copy of the License at\n"),
			("\
\n"),
			("\
      http://www.apache.org/licenses/LICENSE-2.0\n"),
			("\
\n"),
			("\
 Unless required by applicable law or agreed to in writing, software\n"),
			("\
 distributed under the License is distributed on an \"AS IS\" BASIS,\n"),
			("\
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"),
			("\
 See the License for the specific language governing permissions and\n"),
			("\
 limitations under the License.\n"),
			("\
\n"),
		};
	int i = 0;
	for (i = 0; i < array_sizeof(version); i++)
	    fputs (version[i], stdout);
	exit (0);
}

static void
parse_input(const axutil_env_t *env,
			axis2_char_t **input)
{
	int c, nc, index;
	axis2_char_t buff[BUFF_SIZE];
	nc = 0;
	index = 0;
	*input = "";
	c = getchar();
	while(!feof(stdin) && !ferror(stdin))
	{
	    nc++;
	    buff[index] = (axis2_char_t) c;
	    if(index == (BUFF_SIZE - 2))
	    {
			buff[BUFF_SIZE - 1] = '\0';
			*input = axutil_strcat(env, *input, buff, NULL);
			index = 0;
			c = getchar();
			continue;
	    }
	    c = getchar();
	    index++;
	}
	if(feof(stdin) && !ferror(stdin))
	{
	    buff[index] = '\0';
	    *input = axutil_strcat(env, *input, buff, NULL);
	}
}


static void 
print_help ()
{
	static const char *help [] = 
	    {
			("\
wsclient 1.0, command line tool to consume webservices.\n"),
			("\
Usage: wsclient [options] [destURI]\n\n"),
			("\
Mandatory arguments to long options are mandatory for short options too.\n\n"),
			("\
Startup:\n"),
			("\
  -v,  --version                    display the version of WSclientt and exit.\n"),
			("\
  -h,  --help                       print this help.\n"),
			"\n",
			("\
HTTP:\n"),
			("\
       --get                        use get as the HTTP method.\n"),
			("\
       --content-type TYPE          specify the payloads content type.\n"),
			"\n",
			("\
SOAP:\n"),
			("\
       --soap                       use the SOAP binding.\n"),
			("\
       --soap1.1                    use version 1.1 of SOAP.\n"),
			("\
  -a,  --action URI                 use URI as the SOAP action.\n"),
			("\
       --soap-out                   output entire SOAP reply.\n"),
			("\
       --send-only                  send SOAP request only.\n"),
			("\
       --soap-dump                  output SOAP request.\n"),
			"\n",
			("\
Addressing:\n"),
			("\
       --no-wsa                     don't add WS-Addressing headers.\n"),
			("\
       --to URI                     uses URI as the To address.\n"),
			("\
       --from URI                   uses URI as the From address.\n"),
			("\
       --reply-to URI               uses URI as the ReplyTo address.\n"),
			("\
       --fault-to URI               uses URI as the FaultTo address.\n"),
			("\
       --in-reply-to URI            uses URI as the RelatesTo header value.\n"),
			"\n",
			("\
MTOM:\n"),
			("\
       --no-mtom                    disable mtom.\n"),
			("\
       --xop-in DIR                 DIR is the base directory of the package need to transmit.\n"),
			("\
       --xop-out DIR                DIR is a directory for save attachments receive.\n"),
			"\n",
			("\
Rampart:\n"),
			("\
       --user USERNAME              includes username token with user as the USERNAME.\n"),
			("\
       --password PASSWD            uses PASSWD as the password for username token.\n"),
			("\
       --password-file FILE         uses password from FILE.\n"),
			("\
       --digest                     uses a password digest for the usename token.\n"),
			"\n",
			("\
General HTTP Options:\n"),
			("\
       --http-header LINE           add LINE as a HTTP header.\n"),
			("\
       --output-http-headers FILE   output the HTTP headers in the response to FILE.\n"),
			"\n",
			("\
SSL options:\n"),
			("\
       --server-cert PATH           path to certificate file to use with https transport.\n"),
			"\n",
	    };
	int i = 0;
	for (i = 0; i < array_sizeof(help); i++)
	    fputs (help[i], stdout);
	exit (0);
}
