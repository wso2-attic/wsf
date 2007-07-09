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
build_om_programatically(const axutil_env_t *env);

int main(int argc, char** argv)
{
    const axutil_env_t *env = NULL;
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t *payload = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    axutil_property_t *xmpp_jid = NULL;
    axutil_property_t *xmpp_password = NULL;
    axutil_property_t *xmpp_svc_jid = NULL;
    axutil_property_t *xmpp_sasl = NULL;

    /* Set up the environment */
    env = axutil_env_create_all("notify.log", AXIS2_LOG_LEVEL_TRACE);

    /* Set end point reference of echo service */
    address = "xmpp://localhost/axis2/services/notify";
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
    axis2_options_set_action(options, env,
            "http://example.org/action/notify");

    /* Set up deploy folder. It is from the deploy folder, the configuration is picked up
     * using the axis2.xml file.
     * In this sample client_home points to the Axis2/C default deploy folder. The client_home can 
     * be different from this folder on your system. For example, you may have a different folder 
     * (say, my_client_folder) with its own axis2.xml file. my_client_folder/modules will have the 
     * modules that the client uses
     */
    client_home = AXIS2_GETENV("WSFC_HOME");
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
    xmpp_jid = axutil_property_create (env);
    axutil_property_set_value (xmpp_jid, env, (void *)axutil_strdup (env, "xynet@xmpp.ws/Home"));
    axis2_options_set_property (options, env, "XMPP_JID", (void *)xmpp_jid);

    xmpp_password = axutil_property_create (env);
    axutil_property_set_value (xmpp_password, env, (void *)axutil_strdup (env, "123"));
    axis2_options_set_property (options, env, "XMPP_PASSWORD", (void *)xmpp_password);


    xmpp_svc_jid = axutil_property_create (env);
    axutil_property_set_value (xmpp_svc_jid, env, 
                               (void *)axutil_strdup (env, "xynot@xmpp.ws/Home"));
    axis2_options_set_property (options, env, "XMPP_SVC_JID", (void *)xmpp_svc_jid);


    xmpp_sasl = axutil_property_create (env);
    axutil_property_set_value (xmpp_sasl, env, (void *)axutil_strdup (env, "true"));
    axis2_options_set_property (options, env, "XMPP_SASL", (void *)xmpp_sasl);

    axis2_svc_client_set_options(svc_client, env, options);

    /* Engage addressing module */
    axis2_svc_client_engage_module(svc_client, env, AXIS2_MODULE_ADDRESSING);

    /* Build the SOAP request message payload using OM API.*/
    payload = build_om_programatically(env);

    /* Send request */
    status = axis2_svc_client_send_robust(svc_client, env, payload);

    if (status == AXIS2_SUCCESS)
    {
        printf("\nnotify client invoke SUCCESSFUL!\n");
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                AXIS2_ERROR_GET_MESSAGE(env->error));
        printf("notify client invoke FAILED!\n");
    }

    if (svc_client)
    {
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

/* build SOAP request message content using OM */
axiom_node_t *
build_om_programatically(const axutil_env_t *env)
{
    axiom_node_t *notify_om_node = NULL;
    axiom_element_t* notify_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;
    axis2_char_t *buffer = NULL;

    ns1 = axiom_namespace_create(env, "http://example.org/notify", "m");
    notify_om_ele = axiom_element_create(env, NULL, "notify", ns1, &notify_om_node);
    axiom_element_set_text(notify_om_ele, env, "notify5", notify_om_node);

    buffer = axiom_node_to_string(notify_om_node, env);
    if (buffer)
    {
        printf("\nSending OM node in XML : %s \n",  buffer);
        AXIS2_FREE(env->allocator, buffer);
    }

    return notify_om_node;
}
