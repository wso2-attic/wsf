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

#include "axis2_InteropTestPortTypeDocService_stub.h"

int main(int argc, char** argv)
{
    axutil_env_t* env = NULL;
    axis2_char_t* client_home = NULL;

    axis2_char_t* endpoint_uri = NULL;

    axis2_stub_t* stub = NULL;

    /* variables use databinding */
    axis2_echoDate_t* echo_in = NULL;
    axis2_echoDateResponse_t* echo_out = NULL;

    axutil_date_time_t* echo_date = NULL;
    axutil_date_time_t* return_echo_date = NULL;

    axis2_char_t* send_date_str = NULL;
    axis2_char_t* return_date_str = NULL;

    endpoint_uri =
        "http://localhost:9090/axis2/services/interop_doc1";

    env = axutil_env_create_all("codegen_utest_blocking.log",
            AXIS2_LOG_LEVEL_TRACE);

    /* Set up deploy folder.*/
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../../deploy";

    stub = axis2_InteropTestPortTypeDocService_stub_create(env,
            client_home , endpoint_uri);

    /* create the struct */
    echo_date = axutil_date_time_create(env); /* default to current date */
    send_date_str =  axutil_date_time_seriasize_date_time(echo_date, env);
    printf("sending date %s\n", send_date_str);

    /* create the input params using databinding */
    echo_in = axis2_echoDate_create(env);
    AXIS2_ECHODATE_SET_ARG_0_10(echo_in, env, echo_date);

    /* invoke the web service method*/
    echo_out = axis2_echoDate(stub, env, echo_in);

    /* return the output params using databinding */
    return_echo_date  = AXIS2_ECHODATERESPONSE_GET_ECHODATERETURN(echo_out, env);

    return_date_str =  axutil_date_time_seriasize_date_time(return_echo_date, env);
    printf("returned date %s\n", return_date_str);

    return 0;
}
