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

#include "axis2_math_stub.h"
#include <stdio.h>
#include <axiom.h>
#include <axis2_util.h>
#include <axiom_soap.h>
#include <axis2_client.h>

axiom_node_t *
build_om_programatically(const axutil_env_t *env,
        const axis2_char_t *operation,
        const axis2_char_t *param1,
        const axis2_char_t *param2);

int main(int argc, char** argv)
{
    axis2_stub_t *stub = NULL;
    axiom_node_t *node = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    const axutil_env_t *env = NULL;
    const axis2_char_t *address = NULL;
    const axis2_char_t *client_home = NULL;
    axiom_node_t *ret_node = NULL;

    const axis2_char_t *operation = "add";
    const axis2_char_t *param1 = "40";
    const axis2_char_t *param2 = "8";

    env = axutil_env_create_all("math_blocking.log", AXIS2_LOG_LEVEL_TRACE);

    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home || !strcmp (client_home, ""))
        client_home = "../..";

    address = "http://localhost:9090/axis2/services/math";
    if (argc > 1)
        operation = argv[1];
    if (axutil_strcmp(operation, "-h") == 0)
    {
        printf("Usage : %s [operation] [param1] [param2] [endpoint_url]\n", argv[0]);
        printf("use -h for help\n");
        printf("default operation add\n");
        printf("default param1 %s\n", param1);
        printf("default param2 %s\n", param2);
        printf("default endpoint_url %s\n", address);
        printf("NOTE: command line arguments must appear in given order, with trailing ones being optional\n");
        return 0;
    }
    if (argc > 2)
        param1 = argv[2];
    if (argc > 3)
        param2 = argv[3];
    if (argc > 4)
        address = argv[4];

    printf("Using endpoint : %s\n", address);
    printf("\nInvoking operation %s with params %s and %s\n", operation, param1, param2);

    node = build_om_programatically(env, operation, param1, param2);
    stub =
        axis2_math_stub_create_with_endpoint_uri_and_client_home(env, address,   client_home);
    /* create node and invoke math */
    ret_node = axis2_math_stub_add(stub, env, node);
    if (ret_node)
    {
        if (axiom_node_get_node_type(ret_node, env) == AXIOM_ELEMENT)
        {
            axis2_char_t *result = NULL;
            axiom_element_t *result_ele = (axiom_element_t*)axiom_node_get_data_element(ret_node, env);

            result = axiom_element_get_text(result_ele, env, ret_node);
            printf("\nResult = %s\n", result);
        }
        else
        {
            axiom_xml_writer_t *writer = NULL;
            axiom_output_t *om_output = NULL;
            axis2_char_t *buffer = NULL;
            writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_TRUE, 0,
                    AXIS2_XML_PARSER_TYPE_BUFFER);
            om_output = axiom_output_create(env, writer);

            axiom_node_serialize(ret_node, env, om_output);
            buffer = (axis2_char_t*)axiom_xml_writer_get_xml(writer, env);
            printf("\nReceived invalid OM as result : %s\n", buffer);
            if (buffer)
            {
                AXIS2_FREE(env->allocator, buffer);
                buffer = NULL;
            }
            if (om_output)
            {
                axiom_output_free(om_output, env);
                om_output = NULL;
            }
            axiom_xml_writer_free(writer, env);
        }
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                AXIS2_ERROR_GET_MESSAGE(env->error));
        printf("math stub invoke FAILED!\n");
    }

    if (stub)
    {
        axis2_stub_free(stub, env);
    }

    if (env)
    {
        axutil_env_free((axutil_env_t *) env);
        env = NULL;
    }
    
    return status;
}

axiom_node_t *
build_om_programatically(const axutil_env_t *env,
        const axis2_char_t *operation,
        const axis2_char_t *param1,
        const axis2_char_t *param2)
{
    axiom_node_t *math_om_node = NULL;
    axiom_element_t* math_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;


    axiom_xml_writer_t *xml_writer = NULL;
    axiom_output_t *om_output = NULL;
    axis2_char_t *buffer = NULL;

    ns1 = axiom_namespace_create(env, "http://ws.apache.org/axis2/c/samplesmath", "ns1");

    math_om_ele = axiom_element_create(env, NULL, operation, ns1, &math_om_node);

    text_om_ele = axiom_element_create(env, math_om_node, "param1", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, param1, text_om_node);

    text_om_ele = axiom_element_create(env, math_om_node, "param2", NULL, &text_om_node);
    axiom_element_set_text(text_om_ele, env, param2, text_om_node);

    xml_writer = axiom_xml_writer_create_for_memory(env, NULL, AXIS2_FALSE, AXIS2_FALSE,
            AXIS2_XML_PARSER_TYPE_BUFFER);
    om_output = axiom_output_create(env, xml_writer);

    axiom_node_serialize(math_om_node, env, om_output);
    buffer = (axis2_char_t*)axiom_xml_writer_get_xml(xml_writer, env);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "\nSending OM node in XML : %s \n",  buffer);
    if (om_output)
    {
        axiom_output_free(om_output, env);
        om_output = NULL;
    }

    return math_om_node;
}
