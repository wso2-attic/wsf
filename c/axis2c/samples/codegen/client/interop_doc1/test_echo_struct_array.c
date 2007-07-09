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
    axis2_echoStructArray_t* echo_in = NULL;
    axis2_echoStructArrayResponse_t* echo_out = NULL;

    axis2_SOAPStruct_t** echo_struct_arr = NULL;
    int arr_size = 0;
    axis2_SOAPStruct_t** ret_echo_struct_arr = NULL;
    int ret_arr_size = 0;

    int i = 0 ; /* for for loop */


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

    /* create the struct array */
    arr_size = 3;
    echo_struct_arr = (axis2_SOAPStruct_t**) malloc
            (arr_size * sizeof(axis2_SOAPStruct_t*));

    echo_struct_arr[0] = axis2_SOAPStruct_create(env);
    AXIS2_SOAPSTRUCT_SET_VARSTRING(echo_struct_arr[0], env, "sturct0");
    AXIS2_SOAPSTRUCT_SET_VARINT(echo_struct_arr[0], env, 0);
    AXIS2_SOAPSTRUCT_SET_VARFLOAT(echo_struct_arr[0], env, 0);

    echo_struct_arr[1] = axis2_SOAPStruct_create(env);
    AXIS2_SOAPSTRUCT_SET_VARSTRING(echo_struct_arr[1], env, "sturct1");
    AXIS2_SOAPSTRUCT_SET_VARINT(echo_struct_arr[1], env, 10);
    AXIS2_SOAPSTRUCT_SET_VARFLOAT(echo_struct_arr[1], env, 100);

    echo_struct_arr[2] = axis2_SOAPStruct_create(env);
    AXIS2_SOAPSTRUCT_SET_VARSTRING(echo_struct_arr[2], env, "sturct2");
    AXIS2_SOAPSTRUCT_SET_VARINT(echo_struct_arr[2], env, 20);
    AXIS2_SOAPSTRUCT_SET_VARFLOAT(echo_struct_arr[2], env, 200);

    /* create the struct */
    echo_in = axis2_echoStructArray_create(env);
    AXIS2_ECHOSTRUCTARRAY_SET_ARG_0_7(echo_in, env, echo_struct_arr, arr_size);

    /* invoke the web service method*/
    echo_out = axis2_echoStructArray(stub, env, echo_in);

    ret_echo_struct_arr =
        AXIS2_ECHOSTRUCTARRAYRESPONSE_GET_ECHOSTRUCTARRAYRETURN
        (echo_out, env , &ret_arr_size);
    for (i = 0;  i < ret_arr_size ; i ++)
    {
        printf("recieved turn %d \n string %s\n int %d\n float %f\n\n", i,
                AXIS2_SOAPSTRUCT_GET_VARSTRING(ret_echo_struct_arr[i], env),
                AXIS2_SOAPSTRUCT_GET_VARINT(ret_echo_struct_arr[i], env),
                AXIS2_SOAPSTRUCT_GET_VARFLOAT(ret_echo_struct_arr[i], env));
    }
    return 0;
}
