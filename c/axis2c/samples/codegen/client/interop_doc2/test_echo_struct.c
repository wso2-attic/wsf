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
    axis2_echoStruct_t* echo_in = NULL;
    axis2_echoStructResponse_t* echo_out = NULL;
    axis2_SOAPStruct_t* struct_in = NULL;
    axis2_SOAPStruct_t* struct_out = NULL;


    float float_val = 11;
    int int_val = 10;
    char* string_val = "hello struct";

    int ret_int_val = 0;
    float ret_float_val = 0;
    char* ret_string_val = "";

    endpoint_uri = "http://localhost:9090/axis2/services/interop_doc2";

    env = axutil_env_create_all("codegen_utest_blocking.log", AXIS2_LOG_LEVEL_TRACE);

    /* Set up deploy folder.*/
    client_home = AXIS2_GETENV("AXIS2C_HOME");
    if (!client_home)
        client_home = "../../../deploy";

    stub = axis2_WSDLInteropTestDocLitService_stub_create(env,
            client_home , endpoint_uri);

    /* create the struct */
    struct_in = axis2_SOAPStruct_create(env);
    AXIS2_SOAPSTRUCT_SET_VARFLOAT(struct_in, env, float_val);
    AXIS2_SOAPSTRUCT_SET_VARINT(struct_in, env, int_val);
    AXIS2_SOAPSTRUCT_SET_VARSTRING(struct_in, env, string_val);

    /* create the input params using databinding */
    echo_in = axis2_echoStruct_create(env);
    AXIS2_ECHOSTRUCT_SET_PARAM0(echo_in, env, struct_in);

    /* invoke the web service method*/
    echo_out = axis2_echoStruct(stub, env, echo_in);

    /* return the output params using databinding */
    struct_out = AXIS2_ECHOSTRUCTRESPONSE_GET_RETURN(echo_out, env);
    /*struct_out = AXIS2_ECHOSTRUCT_GET_PARAM0( ret_val, env ); */

    ret_float_val = AXIS2_SOAPSTRUCT_GET_VARFLOAT(struct_out, env);
    ret_int_val = AXIS2_SOAPSTRUCT_GET_VARINT(struct_out, env);
    ret_string_val = AXIS2_SOAPSTRUCT_GET_VARSTRING(struct_out, env);

    printf("returned values \n");
    printf(" float %f\n", ret_float_val);
    printf(" int %d \n", ret_int_val);
    printf(" string %s \n", ret_string_val);

    return 0;
}
