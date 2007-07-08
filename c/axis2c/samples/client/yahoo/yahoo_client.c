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

#include <axis2_util.h>
#include <axiom.h>
#include <axis2_client.h>
#include <axis2_http_transport.h>

axiom_node_t *
build_yahoo_rest_payload (const axutil_env_t *env, axis2_char_t *string);

void 
format_output (const axutil_env_t *env, axiom_node_t *ret_node);

void 
format_output_one (const axutil_env_t *env, axiom_node_t *child_node);

int
print_help ();

int main (int argc, char *argv[])
{
    const axutil_env_t *env = NULL;
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t *payload = NULL;
    axiom_node_t *ret_node = NULL;
	axis2_char_t *search_string = NULL;

	if (argc > 1)
	{

		if (!strcmp (argv[1], "-h") || !strcmp (argv[1], "--help"))
		{
			print_help ();
		}
		else
			search_string = argv[1];
	}

    env = axutil_env_create_all("yahoo_rest_search.log", AXIS2_LOG_LEVEL_TRACE);
	address = "http://search.yahooapis.com/WebSearchService/V1/webSearch";

	printf ("using endpoint %s \n", address);

    endpoint_ref = axis2_endpoint_ref_create(env, address);

    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);

    axis2_options_set_enable_rest(options, env, AXIS2_TRUE);
    axis2_options_set_http_method(options, env, AXIS2_HTTP_GET);

    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home || !strcmp (client_home, ""))
        client_home = "../..";

    /* Create service client */
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf("Error creating service client, Please check AXIS2C_HOME again\n");
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                AXIS2_ERROR_GET_MESSAGE(env->error));
		  return -1;
    }

    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);

    /* Build the SOAP request message payload using OM API.*/
    payload = build_yahoo_rest_payload (env, search_string);

    /* Send request */
    ret_node = axis2_svc_client_send_receive(svc_client, env, payload);

    if (ret_node)
    {
		format_output (env, ret_node);
        printf("\necho client invoke SUCCESSFUL!\n");
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                AXIS2_ERROR_GET_MESSAGE(env->error));
        printf("Yahoo REST client invoke FAILED!\n");
    }

    if (svc_client)
    {
        axis2_svc_client_free(svc_client, env);
        svc_client = NULL;
    }
    return 0;
}

axiom_node_t *
build_yahoo_rest_payload (const axutil_env_t *env, axis2_char_t *string)
{
	axiom_node_t *root_node;
	axiom_node_t *appid_node;
	axiom_node_t *query_node;
	axiom_element_t *appid_element;
	axiom_element_t *query_element;
	axiom_element_t *root_element;
	root_node = axiom_node_create (env);
	appid_node = axiom_node_create (env);
	query_node = axiom_node_create (env);
	root_element = axiom_element_create (env, NULL, "yahoo_rest_search", NULL, &root_node);
	appid_element = axiom_element_create (env, root_node, "appid", NULL, &appid_node);
	axiom_element_set_text (appid_element, env, "YahooDemo",  appid_node); 
	query_element = axiom_element_create (env, root_node, "query", NULL, &query_node);
	if (string)
		axiom_element_set_text (query_element, env, string,  query_node); 
	else
		axiom_element_set_text (query_element, env, "finance",  query_node); 
	return root_node;
}

void 
format_output (const axutil_env_t *env, axiom_node_t *node)
{
	axiom_node_t *child_node;
	child_node = axiom_node_get_first_child (node, env);
	while (axiom_node_is_complete (node, env) && child_node)
	{
		printf ("\n\n");
		format_output_one (env, child_node);
		child_node = axiom_node_get_next_sibling (child_node, env);
	}


}

void
format_output_one (const axutil_env_t *env, axiom_node_t *node)
{
	axiom_node_t *child_node;
	child_node = axiom_node_get_first_child (node, env);
	while (axiom_node_is_complete (node, env) && child_node)
	{
        axis2_char_t *om_str = axiom_node_to_string(child_node, env);
        if (om_str) 
        {
    		printf ("\t%s\n", om_str);
            AXIS2_FREE(env->allocator, om_str);
        }
		child_node = axiom_node_get_next_sibling (child_node, env);
	}
}


int
print_help ()
{
	printf ("./yahoosearch string_to_search \n");
	exit (0);
	return 0;
}
