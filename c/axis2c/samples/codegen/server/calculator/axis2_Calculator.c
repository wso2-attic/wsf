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
 * axis2_Calculator.c
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis2/Java version: #axisVersion# #today#
 * axis2_Calculator Axis2/C skeleton for the axisService
 */

#include "axis2_Calculator.h"




/**
 * Auto generated function definition

  * @param param0

 */
axis2_addResponse20_t*axis2_Calculator_add(const axutil_env_t* env  , axis2_add_t* param0)

{
    /* Todo fill this with the necessary business logic */
    axis2_addResponse_t* add_out = NULL;
    axis2_add_t* add_in = param0;
    axis2_addRequest_t* add_req = NULL;
    axis2_addResponse20_t* add_res = NULL;

    int ret_val = 0;

    int val1 = 0;
    int val2 = 0;


    add_req = AXIS2_ADD_GET_ADD(add_in, env);

    val1 = AXIS2_ADDREQUEST_GET_IN0(add_req, env);
    val2 = AXIS2_ADDREQUEST_GET_IN1(add_req, env);

    ret_val = val1 + val2;

    add_out = axis2_addResponse_create(env);
    AXIS2_ADDRESPONSE_SET_ADDRETURN(add_out, env, ret_val);

    add_res = axis2_addResponse20_create(env);
    AXIS2_ADDRESPONSE20_SET_ADDRESPONSE(add_res, env, add_out);

    return add_res;
}



/**
 * Auto generated function definition

  * @param param2

 */
axis2_divResponse16_t*axis2_Calculator_div(const axutil_env_t* env  , axis2_div_t* param2)

{
    /* Todo fill this with the necessary business logic */
    axis2_divResponse_t* div_out = NULL;
    axis2_div_t* div_in = param2;
    axis2_divRequest_t* div_req = NULL;
    axis2_divResponse16_t* div_res = NULL;

    int ret_val = 0;

    int val1 = 0;
    int val2 = 0;


    div_req = AXIS2_DIV_GET_DIV(div_in, env);

    val1 = AXIS2_DIVREQUEST_GET_IN0(div_req, env);
    val2 = AXIS2_DIVREQUEST_GET_IN1(div_req, env);


    ret_val = val1 / val2;

    div_out = axis2_divResponse_create(env);
    AXIS2_DIVRESPONSE_SET_ADDRETURN(div_out, env, ret_val);

    div_res = axis2_divResponse16_create(env);
    AXIS2_DIVRESPONSE16_SET_DIVRESPONSE(div_res, env, div_out);

    return div_res;
}



/**
 * Auto generated function definition

  * @param param4

 */
axis2_subResponse12_t*axis2_Calculator_sub(const axutil_env_t* env  , axis2_sub_t* param4)

{
    /* Todo fill this with the necessary business logic */
    axis2_subResponse_t* sub_out = NULL;
    axis2_sub_t* sub_in = param4;
    axis2_subRequest_t* sub_req = NULL;
    axis2_subResponse12_t* sub_res = NULL;

    int ret_val = 0;

    int val1 = 0;
    int val2 = 0;


    sub_req = AXIS2_SUB_GET_SUB(sub_in, env);

    val1 = AXIS2_SUBREQUEST_GET_IN0(sub_req, env);
    val2 = AXIS2_SUBREQUEST_GET_IN1(sub_req, env);


    ret_val = val1 - val2;

    sub_out = axis2_subResponse_create(env);
    AXIS2_SUBRESPONSE_SET_SUBRETURN(sub_out, env, ret_val);

    sub_res = axis2_subResponse12_create(env);
    AXIS2_SUBRESPONSE12_SET_SUBRESPONSE(sub_res, env, sub_out);

    return sub_res;
}



/**
 * Auto generated function definition

  * @param param6

 */
axis2_mulResponse14_t*axis2_Calculator_mul(const axutil_env_t* env  , axis2_mul_t* param6)

{
    /* Todo fill this with the necessary business logic */
    axis2_mulResponse_t* mul_out = NULL;
    axis2_mul_t* mul_in = param6;
    axis2_mulRequest_t* mul_req = NULL;
    axis2_mulResponse14_t* mul_res = NULL;

    int ret_val = 0;

    int val1 = 0;
    int val2 = 0;


    mul_req = AXIS2_MUL_GET_MUL(mul_in, env);

    val1 = AXIS2_MULREQUEST_GET_IN0(mul_req, env);
    val2 = AXIS2_MULREQUEST_GET_IN1(mul_req, env);


    ret_val = val1 * val2;

    mul_out = axis2_mulResponse_create(env);
    AXIS2_MULRESPONSE_SET_ADDRETURN(mul_out, env, ret_val);

    mul_res = axis2_mulResponse14_create(env);
    AXIS2_MULRESPONSE14_SET_MULRESPONSE(mul_res, env, mul_out);

    return mul_res;
}

