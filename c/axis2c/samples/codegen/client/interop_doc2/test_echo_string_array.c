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

#include "axis2_WSDLInteropTestDocLitService_stub.h"

int main(int argc, char** argv)
{
    axutil_env_t* env = NULL;
    axis2_char_t* client_home = NULL;

    axis2_char_t* endpoint_uri = NULL;

    axis2_stub_t* stub = NULL;


    /* variables use databinding */
    axis2_echoStringArray_t* echo_in = NULL;
    axis2_echoStringArrayResponse_t* echo_out = NULL;
    axis2_ArrayOfstring_literal_t* array_in = NULL;
    axis2_ArrayOfstring_literal_t* array_out = NULL;

    char *string_array[] = { "test", "this", "array" };
    int array_length = 3;

    char **string_return_string_array = NULL;
    int return_array_length = 0;
    int i = 0; /* for loops */

    endpoint_uri = "http://localhost:9090/axis2/services/interop_doc2";

    env = axutil_env_create_all("codegen_utest_blocking.log", AXIS2_LOG_LEVEL_TRACE);

    /* Set up deploy folder.*/
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../../deploy";

    stub = axis2_WSDLInteropTestDocLitService_stub_create(env, client_home , endpoint_uri);


    /* create the array */
    array_in = axis2_ArrayOfstring_literal_create(env);

    AXIS2_ARRAYOFSTRING_LITERAL_SET_STRING(array_in, env,
            string_array, array_length);

    /* create the input params using databinding */
    echo_in = axis2_echoStringArray_create(env);
    AXIS2_ECHOSTRINGARRAY_SET_PARAM0(echo_in, env, array_in);

    /* invoke the web service method*/
    echo_out = axis2_echoStringArray(stub, env, echo_in);

    /* return the output params using databinding */
    array_out = AXIS2_ECHOSTRINGARRAYRESPONSE_GET_RETURN(echo_out, env);

    string_return_string_array = AXIS2_ARRAYOFSTRING_LITERAL_GET_STRING
            (array_out, env, &return_array_length);

    for (i = 0; i < return_array_length ; i ++)
    {
        printf("value%d: %s \n", i, string_return_string_array[i]);
    }

    return 0;
}
