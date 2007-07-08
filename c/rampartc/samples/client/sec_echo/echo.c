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
#include <rampart_constants.h>
#include <neethi_util.h>
#include <neethi_policy.h>

axiom_node_t *
build_om_payload_for_echo_svc(const axutil_env_t *env);


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
    axis2_status_t status = AXIS2_FAILURE;
    neethi_policy_t *policy = NULL;
    axis2_char_t *file_name = NULL;
	
	/* Set up the environment */
    env = axutil_env_create_all("echo.log", AXIS2_LOG_LEVEL_TRACE);


    /* Set end point reference of echo service */
    address = "http://localhost:9090/axis2/services/echo";
    if (argc > 2)
    {
        address = argv[1];
        client_home = argv[2];
        printf("Using endpoint : %s\n", address);
        printf("Using client_home : %s\n", client_home);
    }

    if (axutil_strcmp(address, "-h") == 0)
    {
        printf("Usage : %s [endpoint_url] [client_home]\n", argv[0]);
        printf("use -h for help\n");
        return 0;
    }


    /* Create EPR with given address */
    endpoint_ref = axis2_endpoint_ref_create(env, address);

    /* Setup options */
    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);
    /*axis2_options_set_action(options, env,
            "http://ws.apache.org/axis2/c/samples/sec_echo");*/
    axis2_options_set_action(options, env,
            "http://example.com/ws/2004/09/policy/Test/EchoRequest");



    /*
     * Set security params. If you need to enable dynamic settings uncomment
     * following code section.
     */


    if (!client_home)
    {
        client_home = AXIS2_GETENV("AXIS2C_HOME");
        printf("\nNo client_home specified. Using default %s", client_home);
    }


    /* Set up deploy folder. It is from the deploy folder, the configuration is picked up
     * using the axis2.xml file.
     * In this sample client_home points to the Axis2/C default deploy folder. The client_home can 
     * be different from this folder on your system. For example, you may have a different folder 
     * (say, my_client_folder) with its own axis2.xml file. my_client_folder/modules will have the 
     * modules that the client uses
     */
    /*    if (!client_home)
            client_home = "../../deploy";
    */

    /* Create service client */
    printf("client_home= %s", client_home);
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf("Error creating service client\n");
        /*AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                axutil_error_get_message(env->error));*/
        return -1;
    }

    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);

    /*status = echo_helper_set_policy(svc_client, client_home, env);*/

    if(client_home)
    {
        file_name = axutil_stracat(env, client_home, AXIS2_PATH_SEP_STR);
        file_name = axutil_stracat(env, file_name, "policy.xml" );
    }
    else
    {
        printf("Client Home not Specified\n");
        printf("echo client invoke FAILED!\n");
        return 0;
    }
       

    policy = neethi_util_create_policy_from_file(env, file_name);

    if(!policy)
    {
        printf("\nPolicy creation failed from the file. %s\n", file_name);
        /*printf("echo client invoke FAILED!\n");
        return 0;*/
    }

    status = axis2_svc_client_set_policy(svc_client, env, policy);

    if(status == AXIS2_FAILURE)
    {
        printf("Policy setting failed\n");
    }
    
    /* Build the SOAP request message payload using OM API.*/
    payload = build_om_payload_for_echo_svc(env);
    /*axis2_svc_client_engage_module(svc_client, env, "rampart");*/
    /* Send request */
    ret_node = axis2_svc_client_send_receive(svc_client, env, payload);

    if (ret_node){
        axis2_char_t *om_str = NULL;
        om_str = axiom_node_to_string(ret_node, env);
        if (om_str)
            printf("\nReceived OM : %s\n", om_str);
        printf("\necho client invoke SUCCESSFUL!\n");
    }else{
        /*AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                axutil_error_get_message(env->error));*/
        printf("echo client invoke FAILED!\n");
    }

    if (svc_client)
    {
        axis2_svc_client_free(svc_client, env);
        svc_client = NULL;
    }
    /*    if (endpoint_ref)
        {
            axis2_endpoint_ref_free(endpoint_ref, env);
            endpoint_ref = NULL;
        }
    */
    if (env)
    {
        axutil_env_free((axutil_env_t *) env);
        env = NULL;
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

    ns1 = axiom_namespace_create(env, /*"http://ws.apache.org/axis2/c/samples"*/ "http://example.com/ws/2004/09/policy", "ns1");
    echo_om_ele = axiom_element_create(env, NULL, /*"echoString"*/"echoIn", ns1, &echo_om_node);
    
    
    text_om_ele = axiom_element_create(env, echo_om_node, "text", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, "Hello", text_om_node);

    om_str = axiom_node_to_string(echo_om_node, env);
    if (om_str){
        printf("\nSending OM : %s\n", om_str);
        AXIS2_FREE(env->allocator, om_str);
        om_str =  NULL;
    }
    return echo_om_node;
}
