

/**
 * axis2_skel_Calculator.c
 *
 * This file was auto-generated from WSDL for "Calculator|http://localhost/axis/Calculator" service
 * by the Apache Axis2/C version: #axisVersion# #today#
 * axis2_skel_Calculator Axis2/C skeleton for the axisService
 */

 #include "axis2_skel_Calculator.h"



 
/**
 * auto generated function definition signature
 * for "add|" operation.
 
 * @param add
 */
axis2_addResponse_t* axis2_skel_Calculator_add (const axutil_env_t *env  ,
                                      axis2_add_t* add )
{
    axis2_addResponse_t* add_res = NULL;

    int ret_val = 0;

    int val1 = 0;
    int val2 = 0;

    val1 = AXIS2_ADD_GET_IN0(add, env);
    val2 = AXIS2_ADD_GET_IN1(add, env);

    ret_val = val1 + val2;

    add_res = axis2_addResponse_create(env);
    AXIS2_ADDRESPONSE_SET_ADDRETURN(add_res, env, ret_val);

    return add_res; 
}
 
/**
 * auto generated function definition signature
 * for "div|" operation.
 
 * @param div
 */
axis2_divResponse_t* axis2_skel_Calculator_div (const axutil_env_t *env  ,
                                      axis2_div_t* div )
{
    axis2_divResponse_t *div_res = NULL;

    int ret_val = 0;

    int val1 = 0;
    int val2 = 0;

    val1 = AXIS2_DIV_GET_IN0(div, env);
    val2 = AXIS2_DIV_GET_IN1(div, env);

    ret_val = val1/val2;

    div_res = axis2_divResponse_create(env);
    AXIS2_DIVRESPONSE_SET_ADDRETURN(div_res, env, ret_val);

    return div_res;
}


 
/**
 * auto generated function definition signature
 * for "sub|" operation.
 
 * @param sub
 */
axis2_subResponse_t* axis2_skel_Calculator_sub (const axutil_env_t *env  ,
                                      axis2_sub_t* sub )
{
    axis2_subResponse_t *sub_res = NULL;

    int ret_val = 0;

    int val1 = 0;
    int val2 = 0;

    val1 = AXIS2_SUB_GET_IN0(sub, env);
    val2 = AXIS2_SUB_GET_IN1(sub, env);
    
    ret_val = val1 - val2;

    sub_res = axis2_subResponse_create(env);
    AXIS2_SUBRESPONSE_SET_SUBRETURN(sub_res, env, ret_val);

    return sub_res;
}


 
/**
 * auto generated function definition signature
 * for "mul|" operation.
 
 * @param mul
 */
axis2_mulResponse_t* axis2_skel_Calculator_mul (const axutil_env_t *env  ,
                                      axis2_mul_t* mul )
{
    axis2_mulResponse_t *mul_res = NULL;

    int ret_val = 0;

    int val1 = 0;
    int val2 = 0;

    val1 = AXIS2_MUL_GET_IN0(mul, env);
    val2 = AXIS2_MUL_GET_IN1(mul, env);

    ret_val = val1*val2;

    mul_res = axis2_mulResponse_create(env);
    AXIS2_MULRESPONSE_SET_ADDRETURN(mul_res, env, ret_val);

    return mul_res;

}
