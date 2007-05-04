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

#include "axis2_Calculator_stub.h"

axiom_node_t* generate_request_xml(const  axutil_env_t* env);
void handle_respone_xml(const  axutil_env_t* env, axiom_node_t* res);

int main(int argc, char** argv)
{
    axutil_env_t* env = NULL;
    axis2_char_t* operation = NULL;
    axis2_char_t* client_home = NULL;

    axis2_char_t* endpoint_uri = NULL;

    axis2_stub_t* stub = NULL;

    axiom_node_t* req = NULL;
    axiom_node_t* res = NULL;

    endpoint_uri = "http://localhost:9090/axis2/services/Calculator";

    env = axutil_env_create_all("codegen_utest_blocking.log", AXIS2_LOG_LEVEL_TRACE);

    /* Set up deploy folder.*/
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../../deploy";

    stub = axis2_Calculator_stub_create(env, client_home , endpoint_uri);

    req =  generate_request_xml(env);

    /* invoke the web service method*/
    res = axis2_add(stub, env, req);

    handle_respone_xml(env , res);

    return 0;
}

axiom_node_t* generate_request_xml(const  axutil_env_t* env)
{
    axiom_node_t *op_node = NULL;
    axiom_element_t* op_ele = NULL;
    axiom_node_t* value_node = NULL;
    axiom_element_t * value_ele = NULL;
    axiom_namespace_t *ns1 = NULL;
    axis2_char_t *om_str = NULL;

    int value1 =  13;
    int value2 =  7;
    char value_str[64];

    ns1 = axiom_namespace_create(env, "http://localhost/axis/Calculator", "ns1");
    op_ele = axiom_element_create(env, NULL, "add", ns1, &op_node);

    value_ele = axiom_element_create(env, op_node, "in1", NULL, &value_node);
    sprintf(value_str, "%d", value1);
    axiom_element_set_text(value_ele, env, value_str , value_node);

    value_ele = axiom_element_create(env, op_node, "in2", NULL, &value_node);
    sprintf(value_str, "%d", value1);
    axiom_element_set_text(value_ele, env, value_str , value_node);

    printf("requesting %d  + %d \n", value1, value2);
    om_str = AXIOM_NODE_TO_STRING(op_node, env);
    if (om_str)
        printf("\nSending OM : %s\n", om_str);

    return op_node;

}

void handle_respone_xml(const  axutil_env_t* env, axiom_node_t* res)
{
    axiom_node_t* node = NULL;
    axiom_element_t* ele = NULL;
    axis2_char_t* text =  NULL;

    if (! res)
    {
        printf("response null\n");
        return;
    }
    node = AXIOM_NODE_GET_FIRST_CHILD(res, env);
    if (node)
    {
        ele = AXIOM_NODE_GET_DATA_ELEMENT(node, env);
        text = axiom_element_get_text(ele, env, node);

        printf("answer = %s\n", text);
    }

}
