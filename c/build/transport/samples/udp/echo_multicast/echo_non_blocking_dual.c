
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

#include "echo_util.h"
#include <axis2_util.h>
#include <axiom_soap.h>
#include <axis2_client.h>

#include <axis2_udp_transport.h>
#include <axis2_udp_receiver.h>
#include <axis2_udp_sender.h>


/* my on_complete callback function */
axis2_status_t AXIS2_CALL echo_callback_on_complete(
    struct axis2_callback * callback,
    const axutil_env_t * env);

/* my on_error callback function */
axis2_status_t AXIS2_CALL echo_callback_on_error(
    struct axis2_callback *callback,
    const axutil_env_t * env,
    int exception);

int
main(
    int argc,
    char **argv)
{
    const axutil_env_t *env = NULL;
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t *endpoint_ref = NULL;
    axis2_endpoint_ref_t *reply_to = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t *svc_client = NULL;
    axiom_node_t *payload = NULL;
    axis2_callback_t *callback = NULL;
	axutil_property_t *prop_mul_group = NULL, *prop_port = NULL, *prop_is_mul = NULL;
    int *port = NULL;        
    /* Set up the environment */
    env =
        axutil_env_create_all("echo_non_blocking_dual.log",
                              AXIS2_LOG_LEVEL_DEBUG);

    /* Set end point reference of echo service */
    address = "soap.udp://localhost:9090/axis2/services/echo";
    if (argc > 1)
        address = argv[1];
    if (axutil_strcmp(address, "-h") == 0)
    {
        printf("Usage : %s [endpoint_url]\n", argv[0]);
        printf("use -h for help\n");
        return 0;
    }
    printf("Using endpoint : %s\n", address);

    /* Create EPR with given address */
    endpoint_ref = axis2_endpoint_ref_create(env, address);

    /* Setup options */
    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);
    axis2_options_set_use_separate_listener(options, env, AXIS2_TRUE);

    /* Seperate listner needs addressing, hence addressing stuff in options */
    axis2_options_set_action(options, env,
                             "http://ws.apache.org/axis2/c/samples/echoString");
    reply_to =
        axis2_endpoint_ref_create(env,
                                  "http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous");
    axis2_options_set_reply_to(options, env, reply_to);
	
	/* set the multicast group to which this send happens */
	prop_mul_group = axutil_property_create(env); 
    axutil_property_set_value(prop_mul_group, env, axutil_strdup(env, "225.1.10.4"));
    axis2_options_set_property(options, env, AXIS2_UDP_TRANSPORT_ADDRESS, prop_mul_group);
	
	/* set the port */
	port = AXIS2_MALLOC(env->allocator, sizeof(int));
	*port = 9090;
	prop_port = axutil_property_create(env); 
    axutil_property_set_value(prop_port, env, port);
    axis2_options_set_property(options, env, AXIS2_UDP_TRANSPORT_PORT, prop_port);

	/* set the use multicast to true */
	prop_is_mul = axutil_property_create(env); 
    axutil_property_set_value(prop_is_mul, env, axutil_strdup(env, "true"));
    axis2_options_set_property(options, env, AXIS2_UDP_TRANSPORT_IS_MULTICAT, prop_is_mul);

    /* Set up deploy folder. It is from the deploy folder, the configuration is picked up
     * using the axis2.xml file.
     * In this sample client_home points to the Axis2/C default deploy folder. The client_home can 
     * be different from this folder on your system. For example, you may have a different folder 
     * (say, my_client_folder) with its own axis2.xml file. my_client_folder/modules will have the 
     * modules that the client uses
     */
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home || !strcmp(client_home, ""))
        client_home = "../..";

    /* Create service client */
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf
            ("Error creating service client, Please check AXIS2C_HOME again\n");
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                        "Stub invoke FAILED: Error code:" " %d :: %s",
                        env->error->error_number,
                        AXIS2_ERROR_GET_MESSAGE(env->error));
        return -1;
    }
	axis2_options_set_transport_info(options, env, AXIS2_TRANSPORT_ENUM_UDP, AXIS2_TRANSPORT_ENUM_UDP, AXIS2_TRUE);
    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);

    axis2_svc_client_engage_module(svc_client, env, AXIS2_MODULE_ADDRESSING);
    /*axis2_svc_client_engage_module(svc_client, env, "sandesha2"); */

    /* Build the SOAP request message payload using OM API. */
    payload = build_om_payload_for_echo_svc(env);

    /* Create the callback object with default on_complete and on_error
       callback functions */
    callback = axis2_callback_create(env);

    /* Set our on_complete fucntion pointer to the callback object */
    axis2_callback_set_on_complete(callback, echo_callback_on_complete);

    /* Set our on_error function pointer to the callback object */
    axis2_callback_set_on_error(callback, echo_callback_on_error);

	/*discovery_client_set_transports(env, svc_client);*/
    /* Send request */
    axis2_svc_client_send_receive_non_blocking(svc_client, env,
                                               payload, callback);

    /** Wait till callback is complete. Simply keep the parent thread running
       until our on_complete or on_error is invoked */
	AXIS2_SLEEP(2);

    if (svc_client)
    {
        AXIS2_SLEEP(1);
        axis2_svc_client_free(svc_client, env);
        svc_client = NULL;
    }

    if (env)
    {
        axutil_env_free((axutil_env_t *) env);
        env = NULL;
    }

    return 0;
}

axis2_status_t AXIS2_CALL
echo_callback_on_complete(
    struct axis2_callback * callback,
    const axutil_env_t * env)
{

    /** SOAP response has arrived here; get the soap envelope
      from the callback object and do whatever you want to do with it */

    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_node_t *ret_node = NULL;
    axis2_status_t status = AXIS2_SUCCESS;

    soap_envelope = axis2_callback_get_envelope(callback, env);

    if (!soap_envelope)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                        "Stub invoke FAILED: Error code:" " %d :: %s",
                        env->error->error_number,
                        AXIS2_ERROR_GET_MESSAGE(env->error));
        printf("echo stub invoke FAILED!\n");
        status = AXIS2_FAILURE;
    }
    else
    {
        ret_node = axiom_soap_envelope_get_base_node(soap_envelope, env);

        if (!ret_node)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                            "Stub invoke FAILED: Error code:" " %d :: %s",
                            env->error->error_number,
                            AXIS2_ERROR_GET_MESSAGE(env->error));
            printf("echo stub invoke FAILED!\n");
            status = AXIS2_FAILURE;
        }
        else
        {
            axis2_char_t *om_str = NULL;
            om_str = axiom_node_to_string(ret_node, env);
            if (om_str)
                printf("\nReceived OM : %s\n", om_str);
            printf("\necho client invoke SUCCESSFUL!\n");
        }
    }
    return status;
}

axis2_status_t AXIS2_CALL
echo_callback_on_error(
    struct axis2_callback * callback,
    const axutil_env_t * env,
    int exception)
{

    /** take necessary action on error */
    printf("\nEcho client invoke FAILED. Error code:%d ::%s", exception,
           AXIS2_ERROR_GET_MESSAGE(env->error));
    return AXIS2_SUCCESS;
}
