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
#include <axiom.h>
#include <axis2_util.h>
#include <axiom_soap.h>
#include <axis2_client.h>
#include <axis2_svc_client.h>
#include <axutil_env.h>

#include <savan_client.h>
#include <savan_constants.h>

axiom_node_t *
build_om_payload_for_echo_svc(const axutil_env_t *env);

int main(int argc, char** argv)
{
    const axutil_env_t *env = NULL;
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axutil_hash_t *savan_options = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    savan_client_t *savan_client = NULL;

    /* Set up the environment */
    env = axutil_env_create_all("./subscriber.log", AXIS2_LOG_LEVEL_DEBUG);

    printf("Starting Savan subscriber...\n");

    client_home = AXIS2_GETENV("AXIS2C_HOME");
    
    /* Set end point reference of echo service */
    address = "http://localhost:9090/axis2/services/wso2";
    if (argc > 1 )
        address = argv[1];
    
    printf ("Event source endpoint : %s\n", address);
    
    /* Create EPR with given address */
    endpoint_ref = axis2_endpoint_ref_create(env, address);

    /* Setup options */
    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);
/*    axis2_options_set_action(options, env,
        "http://schemas.xmlsoap.org/ws/2004/08/eventing/Subscribe");    
*/
    /* Create service client */
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf("Error creating service client\n");
        exit(1);
    }

    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);    
    
    /* Engage addressing module */
    axis2_svc_client_engage_module(svc_client, env, AXIS2_MODULE_ADDRESSING);
    
    /* Engage savan module */
    axis2_svc_client_engage_module(svc_client, env, "savan");

    savan_options = axutil_hash_make(env);
    axutil_hash_set(savan_options, SAVAN_OP_KEY_NOTIFY_EPR, AXIS2_HASH_KEY_STRING,
        "http://localhost:9090/axis2/services/wsfc");

    /**
     * Following commented lines show how to use filtering when savan server side is
     * built and running with filtering enabled.
     */
    /*axutil_hash_set(savan_options, SAVAN_OP_KEY_FILTER, AXIS2_HASH_KEY_STRING,
        "//wsfc");

    axutil_hash_set(savan_options, SAVAN_OP_KEY_FILTER_DIALECT, AXIS2_HASH_KEY_STRING,
        DEFAULT_FILTER_DIALECT);*/

    /* Create a savan client */
    savan_client = savan_client_create(env);

    /* Send request */
    status  = savan_client_subscribe(savan_client, env, svc_client, savan_options);
    
    if (status == AXIS2_SUCCESS)
    {
        printf("Subscribe successful\n");
        printf("Subscription ID: %s\n", savan_client_get_sub_id(savan_client));
    }
    else
    {
        printf("Subscription Failed\n");
        exit(0);
    }

    AXIS2_SLEEP(120);


    printf("Unsubscribing...\n");
    address = savan_client_get_sub_url(savan_client);
    endpoint_ref = axis2_options_get_to(options, env);
    axis2_endpoint_ref_set_address(endpoint_ref, env, address);
    axis2_svc_client_remove_all_headers(svc_client, env);
    status = savan_client_unsubscribe(savan_client, env, svc_client);
    if (status == AXIS2_SUCCESS)
    {
        printf("Unsubscribe successful\n");
    }


    if (svc_client)
    {
        axis2_svc_client_free(svc_client, env);
        svc_client = NULL;
    }
    
    return 0;
}

/* build SOAP request message content using OM */
axiom_node_t *
build_om_payload_for_echo_svc(const axutil_env_t *env)
{
    axiom_node_t *echo_om_node = NULL;
    axiom_element_t* echo_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;
    axis2_char_t *om_str = NULL;

    ns1 = axiom_namespace_create(env, "http://ws.apache.org/axis2/c/samples", "ns1");
    echo_om_ele = axiom_element_create(env, NULL, "echoString", ns1, &echo_om_node);
    text_om_ele = axiom_element_create(env, echo_om_node, "text", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, "echo5", text_om_node);

    om_str = axiom_node_to_string(echo_om_node, env);
    if (om_str)
    {
        AXIS2_FREE(env->allocator, om_str);
        om_str =  NULL;
    }
    return echo_om_node;
}
