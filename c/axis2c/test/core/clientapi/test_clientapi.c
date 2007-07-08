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

#include <axis2_const.h>
#include <axutil_env.h>
#include <axis2_engine.h>
#include <axutil_allocator.h>
#include <axis2_svc_client.h>
#include <axis2_options.h>
#include <platforms/axutil_platform_auto_sense.h>

axiom_node_t *
build_om_payload_for_echo_svc(const axutil_env_t *env,
        const axis2_char_t* echo_str);

void axis2_test_svc_client_blocking()
{
    axutil_env_t* env = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t *payload = NULL;
    axiom_node_t *ret_node = NULL;
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;

    axutil_allocator_t *allocator = axutil_allocator_init(NULL);
    env = axutil_env_create(allocator);
    axiom_element_t *result_ele = NULL;
    const axis2_char_t* echo_text = "echo_text";
    axis2_char_t* result = NULL;

    address = "http://localhost:9090/axis2/services/echo/echo";
    endpoint_ref = axis2_endpoint_ref_create(env, address);
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../deploy";

    svc_client = axis2_svc_client_create(env, client_home);

    if (!svc_client)
    {
        printf("axis2_test axis2_svc_client_create FAILURE\n");
        printf("Client repository path not properly set. Please check AXIS2C_HOME setting\n");
        return;
    }

    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);
    axis2_svc_client_set_options(svc_client, env, options);

    payload = build_om_payload_for_echo_svc(env, echo_text);
    ret_node = axis2_svc_client_send_receive(svc_client, env, payload);
    if (ret_node)
    {
        if (axiom_node_get_node_type(ret_node, env) == AXIOM_ELEMENT)
        {
            ret_node = axiom_node_get_first_child(ret_node, env);
            result_ele = (axiom_element_t*)axiom_node_get_data_element(ret_node, env);
            result = axiom_element_get_text(result_ele, env, ret_node);
            if (!strcmp(result, echo_text))
                printf("axis2_test SVC_CLIENT_SEND_RECEIVE SUCCESS\n");
            else
                printf("axis2_test SVC_CLIENT_SEND_RECEIVE FAILURE\n");
        }
    }
    axis2_svc_client_free(svc_client, env);
}

/* build SOAP request message content using OM */
axiom_node_t *
build_om_payload_for_echo_svc(const axutil_env_t *env,
        const axis2_char_t* echo_text)
{
    axiom_node_t *echo_om_node = NULL;
    axiom_element_t* echo_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;

    ns1 = axiom_namespace_create(env, "http://ws.apache.org/axis2/c/samples", "ns1");
    echo_om_ele = axiom_element_create(env, NULL, "echoString", ns1, &echo_om_node);
    text_om_ele = axiom_element_create(env, echo_om_node, "text", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, echo_text, text_om_node);

    return echo_om_node;
}

int main()
{
    axis2_test_svc_client_blocking();
    return 0;
}
