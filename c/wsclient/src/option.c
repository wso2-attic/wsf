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
#if defined(WIN32)
#include <windows.h>
#endif

/* this is a global variable used in wsclient_stub.c */
int array_size;

/**
 *cmd_options_data [] array should be correctly mapped with enum
 *(cmd_options_em) in the wsclient_option.h. That enum value is used
 *in switch statement in wsclient_stub.c
 */

wsclient_cmd_options_t cmd_options_data [] = 
{
      {"get", 0, no_argument},
      {"content-type", 0, required_argument},
      {"soap", 0, no_argument},
      {"soap1.1", 0, no_argument},
      {"send-only", 0, no_argument},
      {"action", 'a', required_argument},
      {"soap-dump", 0, no_argument},
      {"soap-out", 0, no_argument},
      {"soap-header", 0, required_argument},
      {"no-wsa", 0, no_argument},
      {"to", 0, required_argument},
      {"from", 0, required_argument},
      {"reply-to", 0, required_argument},
      {"fault-to", 0, required_argument},
      {"in-reply-to", 0, required_argument},
      {"user", 0, required_argument},
      {"password", 0, required_argument},
      {"password-file", 0, required_argument},
      {"http-header", 0, required_argument},
      {"output-http-headers", 0, required_argument},
      {"digest", 0, no_argument},
      {"timestamp", 0, no_argument},
      {"no-mtom", 0, no_argument},
	  {"xop-in", 0, optional_argument},
	  {"xop-out", 0, optional_argument},
	  {"server-cert", 0, required_argument},
      {"encrypt-payload", 0, no_argument},
      {"sign-body", 0, no_argument},
      {"encrypt-before-signing", 0, no_argument},
      {"encrypt-signature", 0, no_argument},
      {"key", 0, required_argument},
      {"certificate", 0, required_argument},
      {"recipient-certificate", 0, required_argument},
      {"policy-file", 0, required_argument},
      {"algorithmsuite", 0, required_argument}
};


axis2_char_t *
wsclient_destination (int argc, char **argv)
{
      char *dest_uri = NULL;
      if (argc > 1 && argv)
      {
	    if (strstr (argv[argc-1], "http://") || strstr (argv[argc-1], "https://"))
	    {
		  dest_uri = argv[argc - 1];
	    }
      }
      else
		  return WSCLIENT_FAILURE;

      return dest_uri;
}


axutil_array_list_t *
wsclient_process_options (int argc,
			  char **argv, 
			  const axutil_env_t *env)
{
      axutil_array_list_t *array_list;
      wsclient_options_t *options;
      int i = 0;
      int ii = 0;
      char *name = NULL;
	  char *optional_value;
      array_list = axutil_array_list_create (env, 3);
	  /* array size is a global varialbe */
	  array_size = array_sizeof (cmd_options_data);
      for (i = 0;i < array_size; i++)
      {
	    char *long_name;
	    char short_name;
	    int has_arg;
	    int short_arg = 0;

	    long_name = cmd_options_data [i].long_name;
	    short_name = cmd_options_data [i].short_name;
	    has_arg = cmd_options_data [i].has_arg;

	    for (ii = 0; ii < argc; ii++)
	    {
		  name = NULL;
		  if (argv[ii][0] == '-' && argv[ii][1] == '-')
		  {
			name = argv[ii]+2;
		  }
		  else if (argv [ii][0] == '-')
		  {
			name = argv [ii] + 1;
			short_arg = 1;
		  }

		  if (name)
		  {
			if (!strcmp (name, long_name))
			{
			      options = AXIS2_MALLOC (env->allocator, sizeof (wsclient_options_t));
			      if (options)
			      {
				    options->opt_name = long_name;
				    options->short_name = 0;
				    if (has_arg == required_argument)
				    {
					  options->has_arg = has_arg;
					  options->value = (void *)argv[++ii];
				    }
					else if (has_arg == optional_argument)
					{
						optional_value = (char *) argv[ii+1];
						if (optional_value)
						{
							if (!strcmp (long_name, "xop-in") || (!strcmp (long_name, "xop-out")))
							{
								char *pwd;

                                #if defined(WIN32)
									char path[256];
								    GetCurrentDirectory(256, path);
									pwd = path;
                                #else
								    pwd = AXIS2_GETENV ("PWD");
                                #endif

								strcat (pwd, "/");
								if (strstr (optional_value, "http://"))
								{
									options->value = (void *)pwd;
								}
								else if (strstr (optional_value, "--"))
								{
									options->value = (void *)pwd;
								}
								else if (strstr (optional_value, "."))
								{
									options->value = (void *)pwd;
								}
								else
									options->value = (void *)optional_value;
								ii ++;
								options->has_arg = has_arg;
							}
						}
					}
				    else
				    {
					  options->value = NULL;
					  options->has_arg = no_argument;
				    }
			      }
			      axutil_array_list_add (array_list, env, (void *)options);
			}
			else 
			{
			      if (short_name == name [0] && short_arg)
			      {
				    options = AXIS2_MALLOC (env->allocator, sizeof (wsclient_options_t));
				    if (options)
				    {
					  options->short_name = short_name;
					  options->opt_name = NULL;
					  if (has_arg == required_argument)
					  {
						options->has_arg = has_arg;
						options->value = (void *)argv[++ii];
					  }
					  else
					  {
						options->value = NULL;
						options->has_arg = no_argument;
					  }
				    }
				    axutil_array_list_add (array_list, env, (void *)options);
			      }
			}
		  }
	    }
      }
      return array_list;
}
