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

#include <stdio.h>
#include <axiom.h>
#include <axis2_util.h>
#include <axiom_soap.h>
#include <axis2_client.h>

axiom_node_t *
build_soap_body_content(const axutil_env_t *env,
        const axis2_char_t *operation,
        const axis2_char_t *flickr_key,
        const axis2_char_t *search_term);

void print_invalid_om(const axutil_env_t *env, axiom_node_t *ret_node);

int main(int argc, char** argv)
{
    const axutil_env_t *env = NULL;
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t *payload = NULL;
    axiom_node_t *ret_node = NULL;

    const axis2_char_t *flickr_key = NULL;
    const axis2_char_t *search_term = NULL;
    const axis2_char_t *operation = NULL;

    operation = "echo";
    flickr_key = "00000000000000000000000000000000";

    /* Set up the environment */
    env = axutil_env_create_all("flickr_client.log", AXIS2_LOG_LEVEL_TRACE);

    /* Set end point reference of flickr service */
    address = "http://api.flickr.com/services/soap/";

    if ((argc > 1) && (axutil_strcmp("-h", argv[1]) == 0))
    {
        printf("\nUsage : %s flickr_key [search_term] \n", argv[0]);
        printf("\tflickr_key Your Flicker license key. Default value won't work. You must use your key here.\n");
        printf("\tsearch_term Search term to be used with Flicker photo search service.\n");
        printf("NOTE: command line arguments must appear in given order, with trailing ones being optional\n");
        printf("\tUse -h for help\n");
        return 0;
    }

    if (argc > 1)
        flickr_key = argv[1];
    if (argc > 2)
        search_term = argv[2];
    if (argc > 3)
        address = argv[3];

    printf("Using endpoint : %s\n", address);
    printf("\nInvoking operation %s with params %s and %s\n", operation, flickr_key, search_term);

    /* Create EPR with given address */
    endpoint_ref = axis2_endpoint_ref_create(env, address);

    /* Setup options */
    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);

    /* Set up deploy folder.*/
    client_home = AXIS2_GETENV("WSFC_HOME");
    if (!client_home || !strcmp (client_home, ""))
        client_home = "../..";

    /* Create service client */
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf("Error creating service client, Please check WSFC_HOME again\n");
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                AXIS2_ERROR_GET_MESSAGE(env->error));
		  return -1;
    }

    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);

    /* Build the SOAP request message payload using OM API.*/
    payload = build_soap_body_content(env, operation, flickr_key, search_term);

    /* Send request */
    ret_node = axis2_svc_client_send_receive(svc_client, env, payload);

    if (axis2_svc_client_get_last_response_has_fault(svc_client, env))
    {
        axiom_soap_envelope_t *soap_envelope = NULL;
        axiom_soap_body_t *soap_body = NULL;
        axiom_soap_fault_t *soap_fault = NULL;
        
        printf ("\nResponse has a SOAP fault\n");
        soap_envelope = 
            axis2_svc_client_get_last_response_soap_envelope(svc_client, env);
        if (soap_envelope)
            soap_body = axiom_soap_envelope_get_body(soap_envelope, env);
        if (soap_body)
            soap_fault = axiom_soap_body_get_fault(soap_body, env);
        if (soap_fault)
        {
            printf("\nReturned SOAP fault: %s\n", 
                axiom_node_to_string(axiom_soap_fault_get_base_node(soap_fault,env), 
                env));
        }
        return -1;
    }

    if (ret_node)
    {
        if (axiom_node_get_node_type(ret_node, env) == AXIOM_ELEMENT)
        {
            axis2_char_t *buffer = axiom_node_to_string(ret_node, env);
            printf("%s\n", buffer);
        }
        else
        {
            print_invalid_om(env, ret_node);
            return AXIS2_FAILURE;
        }
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                AXIS2_ERROR_GET_MESSAGE(env->error));
        printf("Flicker client invoke FAILED!\n");
    }

    if (svc_client)
    {
        axis2_svc_client_free(svc_client, env);
        svc_client = NULL;
    }

    return 0;
}

axiom_node_t *
build_soap_body_content(const axutil_env_t *env,
        const axis2_char_t *operation,
        const axis2_char_t *flickr_key,
        const axis2_char_t *search_term)
{
    axiom_node_t *flickr_om_node = NULL;
    axiom_element_t* flickr_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns0 = NULL;
    axis2_char_t *buffer = NULL;

    ns0 = axiom_namespace_create(env, "urn:flickr", "x");

    flickr_om_ele = axiom_element_create(env, NULL, "FlickrRequest", ns0, &flickr_om_node);

    if (search_term)
        buffer = "flickr.photos.search";
    else
        buffer = "flickr.test.echo";

    text_om_ele = axiom_element_create(env, flickr_om_node, "method", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, buffer, text_om_node);

    text_om_ele = axiom_element_create(env, flickr_om_node, "api_key", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, flickr_key, text_om_node);
   
    if (!search_term)
    {
        text_om_ele = axiom_element_create(env, flickr_om_node, "name", NULL, &text_om_node);
        axiom_element_set_text(text_om_ele, env, "test", text_om_node);
    }
    else
    {
        text_om_ele = axiom_element_create(env, flickr_om_node, "tags", NULL, &text_om_node);
        axiom_element_set_text(text_om_ele, env, search_term, text_om_node);
    }

    buffer = axiom_node_to_string(flickr_om_node, env);
    printf("%s\n", buffer);
    return flickr_om_node;
}

void print_invalid_om(const axutil_env_t *env, axiom_node_t *ret_node)
{
    axis2_char_t *buffer = NULL;
    buffer = axiom_node_get_data_element(ret_node, env);
    printf("\nReceived OM as result : %s\n", buffer);
}

