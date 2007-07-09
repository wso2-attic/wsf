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
#include <string.h>

axiom_node_t *build_soap_body_content(const axutil_env_t *env,
        const axis2_char_t * echo_operation,
        const axis2_char_t * echo_type,
        const axis2_char_t * word_to_echo);

int
main(int argc, char **argv)
{
    axutil_env_t *env = NULL;
    const axis2_char_t *address = NULL;
    axis2_endpoint_ref_t* endpoint_ref = NULL;
    axis2_options_t *options = NULL;
    const axis2_char_t *client_home = NULL;
    axis2_svc_client_t* svc_client = NULL;
    axiom_node_t *payload = NULL;
    axiom_node_t *ret_node = NULL;
    axiom_element_t *ret_ele = NULL;
    axis2_char_t *om_str = NULL;
    axis2_char_t *result = NULL;

    const axis2_char_t *echo_operation = NULL;
    const axis2_char_t *word_to_echo = NULL;
    const axis2_char_t *echo_type = NULL;
    axis2_char_t operation[32];
    axis2_char_t echo_response_buff[32];

    echo_operation = "String";
    word_to_echo = "helloworld";
    echo_type = "string";

    if ((argc > 1) && (axutil_strcmp("-h", argv[1]) == 0))
    {
        printf("\nUsage : %s [echo_operation] [echo_value] [XSD_type]\n",
                argv[0]);
        printf("use -h for help\n");
        return 0;
    }

    if (argc > 1)
        echo_operation = argv[1];
    if (argc > 2)
        word_to_echo = argv[2];
    if (argc > 3)
        echo_type = argv[3];

    /* address = "http://localhost:7070/asmx/simple.asmx"; */
    address = "http://www.mssoapinterop.org/asmx/simple.asmx";

    sprintf(operation, "echo%s", echo_operation);

    printf("Using endpoint : %s\n", address);
    printf("Invoking %s with param %s\n", operation, word_to_echo);


    /* Set up the environment */
    env = axutil_env_create_all("echo.log", AXIS2_LOG_LEVEL_TRACE);

    /* Create EPR with given address */

    endpoint_ref = axis2_endpoint_ref_create(env, address);
    options = axis2_options_create(env);
    axis2_options_set_to(options, env, endpoint_ref);

    /* this itest requried soap 1.1 message */
    axis2_options_set_soap_version(options, env, AXIOM_SOAP11);
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../deploy";

    /* Create service client */
    svc_client = axis2_svc_client_create(env, client_home);
    if (!svc_client)
    {
        printf("Error creating service client\n");
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Stub invoke FAILED: Error code:"
                " %d :: %s", env->error->error_number,
                axutil_error_get_message(env->error));
    }

    /* Set service client options */
    axis2_svc_client_set_options(svc_client, env, options);

    payload = build_soap_body_content(env, echo_operation,
            echo_type, word_to_echo);
    /* Send request */
    ret_node = axis2_svc_client_send_receive(svc_client, env, payload);



    if (ret_node)
    {
        om_str = AXIOM_NODE_TO_STRING(ret_node, env);
        if (om_str)
            printf("\nRecieving OM : %s\n", om_str);
        if (AXIOM_NODE_GET_NODE_TYPE(ret_node, env) == AXIOM_ELEMENT)
        {

            sprintf(echo_response_buff, "echo%sResponse", echo_operation);
            ret_ele =
                (axiom_element_t *)
                AXIOM_NODE_GET_DATA_ELEMENT(ret_node, env);
            if (axutil_strcmp
                    (axiom_element_get_localname(ret_ele, env),
                            echo_response_buff) != 0)
            {
                printf("%s != %s\n", axiom_element_get_localname(ret_ele, env), echo_response_buff);
                printf("\nFAIL\n\n");
                return AXIS2_FAILURE;
            }

            ret_node = AXIOM_NODE_GET_FIRST_CHILD(ret_node, env);
            ret_ele =
                (axiom_element_t *)
                AXIOM_NODE_GET_DATA_ELEMENT(ret_node, env);
            result = axiom_element_get_text(ret_ele, env, ret_node);
            if (!strcmp(word_to_echo, result))
            {
                printf("\nSUCCESS\n\n");
            }
            else
            {
                printf("\nFAIL\n\n");
            }

        }
        else
        {
            printf("\nFAIL\n\n");
            return AXIS2_FAILURE;
        }
    }
    else
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "Stub invoke FAILED: Error code:" " %d :: %s",
                env->error->error_number,
                axutil_error_get_message(env->error));
        printf("round1 stub invoke FAILED!\n");
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

axiom_node_t *
build_soap_body_content(const axutil_env_t *env,
        const axis2_char_t * echo_operation,
        const axis2_char_t * echo_type,
        const axis2_char_t * word_to_echo)
{

    axiom_node_t *operation_om_node = NULL;
    axiom_element_t *operation_om_ele = NULL;

    axiom_node_t *text_om_node = NULL;
    axiom_element_t *text_om_ele = NULL;

    axiom_attribute_t *attri1 = NULL;
    axiom_namespace_t *ns0 = NULL, *ns1 = NULL, *ns2 = NULL, *ns3 = NULL,
            *ns4 = NULL, *ns5 = NULL;
    axis2_char_t *om_str = NULL;


    axis2_char_t echo_operation_buff[32];
    axis2_char_t input_type_buff[32];

    /*generating the requried parameters */
    sprintf(echo_operation_buff, "echo%s", echo_operation);
    sprintf(input_type_buff, "input%s", echo_operation);

    ns0 =  axiom_namespace_create(env,
            "http://schemas.xmlsoap.org/soap/envelope/", "soapenv");
    ns1 = axiom_namespace_create(env,
            "http://www.w3.org/2001/XMLSchema-instance", "xsi");
    ns2 = axiom_namespace_create(env,
            "http://www.w3.org/2001/XMLSchema", "xsd");
    ns3 = axiom_namespace_create(env,
            "http://schemas.xmlsoap.org/soap/encoding/", "soapenc");
    ns4 = axiom_namespace_create(env,
            "http://soapinterop.org/", "tns");
    ns5 = axiom_namespace_create(env,
            "http://soapinterop.org/encodedTypes", "types");

    operation_om_ele = axiom_element_create(env, NULL, echo_operation_buff,
            ns4, &operation_om_node);

    axiom_element_declare_namespace(operation_om_ele, env,
            operation_om_node, ns0);
    axiom_element_declare_namespace(operation_om_ele, env,
            operation_om_node, ns1);
    axiom_element_declare_namespace(operation_om_ele, env,
            operation_om_node, ns2);
    axiom_element_declare_namespace(operation_om_ele, env,
            operation_om_node, ns3);
    axiom_element_declare_namespace(operation_om_ele, env,
            operation_om_node, ns4);
    axiom_element_declare_namespace(operation_om_ele, env,
            operation_om_node, ns5);

    attri1 =
        axiom_attribute_create(env, "encodingStyle",
                "http://schemas.xmlsoap.org/soap/encoding/",
                ns0);

    operation_om_ele = AXIOM_NODE_GET_DATA_ELEMENT(operation_om_node, env);
    AXIOM_ELEMENT_ADD_ATTRIBUTE(operation_om_ele, env, attri1, operation_om_node);


    text_om_ele =
        axiom_element_create(env, operation_om_node, input_type_buff, NULL,
                &text_om_node);
    axiom_element_set_text(text_om_ele, env, word_to_echo, text_om_node);

    om_str = AXIOM_NODE_TO_STRING(operation_om_node, env);
    if (om_str)
        printf("\nSending OM : %s\n", om_str);

    return operation_om_node;
}
