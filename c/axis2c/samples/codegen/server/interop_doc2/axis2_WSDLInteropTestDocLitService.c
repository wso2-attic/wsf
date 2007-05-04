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

/**
 * axis2_WSDLInteropTestDocLitService.c
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis2/Java version: #axisVersion# #today#
 * axis2_WSDLInteropTestDocLitService Axis2/C skeleton for the axisService
 */

#include "axis2_WSDLInteropTestDocLitService.h"




/**
 * Auto generated function definition

  * @param param0

 */
axis2_echoVoidResponse_t*axis2_WSDLInteropTestDocLitService_echoVoid(const axutil_env_t* env  , axis2_echoVoid_t* param0)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param2

 */
axis2_echoStringArrayResponse_t*axis2_WSDLInteropTestDocLitService_echoStringArray(const axutil_env_t* env  , axis2_echoStringArray_t* param2)

{
    /* Todo fill this with the necessary business logic */
    axis2_echoStringArray_t* echo_in = param2;
    axis2_echoStringArrayResponse_t* echo_out = NULL;
    axis2_ArrayOfstring_literal_t* array_in = NULL;
    axis2_ArrayOfstring_literal_t* array_out = NULL;
    char ** string_array = NULL;
    int string_array_length = 0;

    array_in = AXIS2_ECHOSTRINGARRAY_GET_PARAM0(echo_in, env);
    string_array = AXIS2_ARRAYOFSTRING_LITERAL_GET_STRING(array_in, env,
            &string_array_length);

    array_out = axis2_ArrayOfstring_literal_create(env);
    AXIS2_ARRAYOFSTRING_LITERAL_SET_STRING(array_out, env,
            string_array, string_array_length);
    echo_out = axis2_echoStringArrayResponse_create(env);

    AXIS2_ECHOSTRINGARRAYRESPONSE_SET_RETURN(echo_out, env , array_out);

    return echo_out;

}



/**
 * Auto generated function definition

  * @param param4

 */
axis2_echoStructResponse_t*axis2_WSDLInteropTestDocLitService_echoStruct(const axutil_env_t* env  , axis2_echoStruct_t* param4)

{
    /* Todo fill this with the necessary business logic */
    axis2_echoStruct_t* echo_in = param4;
    axis2_echoStructResponse_t* echo_out = NULL;
    axis2_SOAPStruct_t* struct_in = NULL;
    axis2_SOAPStruct_t* struct_out = NULL;

    float float_val = 0;
    int int_val = 0;
    char* string_val = NULL;

    struct_in = AXIS2_ECHOSTRUCT_GET_PARAM0(echo_in, env);

    float_val = AXIS2_SOAPSTRUCT_GET_VARFLOAT(struct_in, env);
    int_val = AXIS2_SOAPSTRUCT_GET_VARINT(struct_in, env);
    string_val = AXIS2_SOAPSTRUCT_GET_VARSTRING(struct_in, env);

    struct_out = axis2_SOAPStruct_create(env);
    AXIS2_SOAPSTRUCT_SET_VARFLOAT(struct_out, env, float_val);
    AXIS2_SOAPSTRUCT_SET_VARINT(struct_out, env, int_val);
    AXIS2_SOAPSTRUCT_SET_VARSTRING(struct_out, env, string_val);

    echo_out = axis2_echoStructResponse_create(env);
    AXIS2_ECHOSTRUCTRESPONSE_SET_RETURN(echo_out, env, struct_out);

    return echo_out;
}



/**
 * Auto generated function definition

  * @param param6

 */
axis2_echoStringResponse_t*axis2_WSDLInteropTestDocLitService_echoString(const axutil_env_t* env  , axis2_echoString_t* param6)

{
    /* Todo fill this with the necessary business logic */
    axis2_echoString_t* echo_in = param6;
    axis2_echoStringResponse_t* echo_out = NULL;

    char* echo_string = NULL;

    echo_string = AXIS2_ECHOSTRING_GET_PARAM0(echo_in, env);

    echo_out = axis2_echoStringResponse_create(env);
    AXIS2_ECHOSTRUCTRESPONSE_SET_RETURN(echo_out, env, echo_string);

    return echo_out;
}

