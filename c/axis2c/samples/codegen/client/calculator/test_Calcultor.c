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

int main(int argc, char** argv)
{
    axutil_env_t* env = NULL;
    axis2_char_t* operation = NULL;
    axis2_char_t* client_home = NULL;

    axis2_char_t* endpoint_uri = NULL;

    axis2_stub_t* stub = NULL;

    /* variables use databinding */
    axis2_addResponse_t* add_out = NULL;
    axis2_add_t* add_in = NULL;
    axis2_addRequest_t* add_req = NULL;
    axis2_addResponse20_t* add_res = NULL;

    int ret_val = 0;

    int val1 = 8;
    int val2 = 13;

    endpoint_uri = "http://localhost:9090/axis2/services/calculator";

    env = axutil_env_create_all("codegen_utest_blocking.log", AXIS2_LOG_LEVEL_TRACE);

    /* Set up deploy folder.*/
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../../deploy";

    stub = axis2_Calculator_stub_create(env, client_home , endpoint_uri);


    /* create the struct */
    add_req = axis2_addRequest_create(env);
    AXIS2_ADDREQUEST_SET_IN0(add_req, env, val1);
    AXIS2_ADDREQUEST_SET_IN1(add_req, env, val2);

    /* create the input params using databinding */
    add_in = axis2_add_create(env);
    AXIS2_ADD_SET_ADD(add_in, env, add_req);

    /* invoke the web service method*/
    add_res = axis2_add(stub, env, add_in);

    if (!add_res)
    {
        printf("Error: response NULL\n");
        return -1;
    }

    /* return the output params using databinding */
    add_out = AXIS2_ADDRESPONSE20_GET_ADDRESPONSE(add_res, env);
    ret_val = AXIS2_ADDRESPONSE_GET_ADDRETURN(add_out, env);

    printf("finally: add (%d %d ) = %d\n", val1, val2, ret_val);

    return 0;
}
