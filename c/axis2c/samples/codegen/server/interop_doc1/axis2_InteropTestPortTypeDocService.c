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
 * axis2_InteropTestPortTypeDocService.c
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis2/Java version: #axisVersion# #today#
 * axis2_InteropTestPortTypeDocService Axis2/C skeleton for the axisService
 */

#include "axis2_InteropTestPortTypeDocService.h"




/**
 * Auto generated function definition

  * @param param0

 */
axis2_echoFloatResponse_t*axis2_InteropTestPortTypeDocService_echoFloat(const axutil_env_t* env  , axis2_echoFloat_t* param0)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param2

 */
axis2_echoVoidResponse_t*axis2_InteropTestPortTypeDocService_echoVoid(const axutil_env_t* env  , axis2_echoVoid_t* param2)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param4

 */
axis2_echoDateResponse_t*axis2_InteropTestPortTypeDocService_echoDate(const axutil_env_t* env  , axis2_echoDate_t* param4)

{
    /* Todo fill this with the necessary business logic */
    axis2_echoDate_t* echo_in =  param4;
    axis2_echoDateResponse_t* echo_out = NULL;

    axutil_date_time_t* echo_date = NULL;
    axis2_char_t* recieved_date_str  = NULL;

    echo_date = AXIS2_ECHODATE_GET_ARG_0_10(echo_in, env);

    recieved_date_str =  axutil_date_time_seriasize_date_time(echo_date, env);
    printf("echoing date %s\n", recieved_date_str);

    echo_out = axis2_echoDateResponse_create(env);
    AXIS2_ECHODATERESPONSE_SET_ECHODATERETURN(echo_out, env , echo_date);

    return echo_out;
}



/**
 * Auto generated function definition

  * @param param6

 */
axis2_echoDecimalResponse_t*axis2_InteropTestPortTypeDocService_echoDecimal(const axutil_env_t* env  , axis2_echoDecimal_t* param6)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param8

 */
axis2_echoStringResponse_t*axis2_InteropTestPortTypeDocService_echoString(const axutil_env_t* env  , axis2_echoString_t* param8)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param10

 */
axis2_echoBase64Response_t*axis2_InteropTestPortTypeDocService_echoBase64(const axutil_env_t* env  , axis2_echoBase64_t* param10)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param12

 */
axis2_echoFloatArrayResponse_t*axis2_InteropTestPortTypeDocService_echoFloatArray(const axutil_env_t* env  , axis2_echoFloatArray_t* param12)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param14

 */
axis2_echoIntegerArrayResponse_t*axis2_InteropTestPortTypeDocService_echoIntegerArray(const axutil_env_t* env  , axis2_echoIntegerArray_t* param14)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param16

 */
axis2_echoHexBinaryResponse_t*axis2_InteropTestPortTypeDocService_echoHexBinary(const axutil_env_t* env  , axis2_echoHexBinary_t* param16)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param18

 */
axis2_echoIntegerResponse_t*axis2_InteropTestPortTypeDocService_echoInteger(const axutil_env_t* env  , axis2_echoInteger_t* param18)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param20

 */
axis2_echoBooleanResponse_t*axis2_InteropTestPortTypeDocService_echoBoolean(const axutil_env_t* env  , axis2_echoBoolean_t* param20)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param22

 */
axis2_echoStringArrayResponse_t*axis2_InteropTestPortTypeDocService_echoStringArray(const axutil_env_t* env  , axis2_echoStringArray_t* param22)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

  * @param param24

 */
axis2_echoStructArrayResponse_t*axis2_InteropTestPortTypeDocService_echoStructArray(const axutil_env_t* env  , axis2_echoStructArray_t* param24)

{
    /* Todo fill this with the necessary business logic */
    axis2_echoStructArray_t* echo_in =  param24;
    axis2_echoStructArrayResponse_t* echo_out = NULL;

    axis2_SOAPStruct_t** echo_struct_arr = NULL;
    int arr_size = 0;

    int i = 0;

    echo_struct_arr =
        AXIS2_ECHOSTRUCTARRAY_GET_ARG_0_7(echo_in, env, &arr_size);

    for (i = 0;  i < arr_size ; i ++)
    {
        printf("echoing turn %d\n string %s\n int %d\n float %f\n\n", i,
                AXIS2_SOAPSTRUCT_GET_VARSTRING(echo_struct_arr[i], env),
                AXIS2_SOAPSTRUCT_GET_VARINT(echo_struct_arr[i], env),
                AXIS2_SOAPSTRUCT_GET_VARFLOAT(echo_struct_arr[i], env));
    }

    echo_out = axis2_echoStructArrayResponse_create(env);
    AXIS2_ECHOSTRUCTARRAYRESPONSE_SET_ECHOSTRUCTARRAYRETURN
    (echo_out, env, echo_struct_arr, arr_size);
    return echo_out;

}



/**
 * Auto generated function definition

  * @param param26

 */
axis2_echoStructResponse_t*axis2_InteropTestPortTypeDocService_echoStruct(const axutil_env_t* env  , axis2_echoStruct_t* param26)

{
    /* Todo fill this with the necessary business logic */
    return NULL;
}

