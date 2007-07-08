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
axiom_node_t *
axis2_Calculator_add(const axutil_env_t * env, axiom_node_t* param0)
{
    /* Todo fill this with the necessary business logic */
    axiom_node_t* req = param0;
    axiom_node_t* node = NULL;
    axiom_element_t* ele = NULL;
    axis2_char_t* text =  NULL;

    axiom_node_t *op_node = NULL;
    axiom_element_t* op_ele = NULL;
    axiom_node_t* value_node = NULL;
    axiom_element_t * value_ele = NULL;
    axiom_namespace_t *ns1 = NULL;
    axis2_char_t *om_str = NULL;

    char value_str[64];

    int result = 0;

    int value1, value2;
    if (! req)
    {
        printf("response null\n");
        return NULL;
    }
    else
    {
        node = AXIOM_NODE_GET_FIRST_CHILD(req, env);
        ele = AXIOM_NODE_GET_DATA_ELEMENT(node, env);
        text = axiom_element_get_text(ele, env, node);
        value1 = atoi(text);

        node = AXIOM_NODE_GET_NEXT_SIBLING(node, env);
        ele = AXIOM_NODE_GET_DATA_ELEMENT(node, env);
        text = axiom_element_get_text(ele, env, node);
        value2 = atoi(text);

    }

    result = value1 + value2;


    ns1 = axiom_namespace_create(env, "http://localhost/axis/Calculator", "ns1");
    op_ele = axiom_element_create(env, NULL, "addResponse", ns1, &op_node);

    value_ele = axiom_element_create(env, op_node, "in1", NULL, &value_node);
    sprintf(value_str, "%d", result);
    axiom_element_set_text(value_ele, env, value_str , value_node);

    return op_node;

}



/**
 * Auto generated function definition

 * @param param2

*/
axiom_node_t *
axis2_Calculator_div(const axutil_env_t * env, axiom_node_t* param2)
{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

 * @param param4

*/
axiom_node_t *
axis2_Calculator_sub(const axutil_env_t * env, axiom_node_t* param4)
{
    /* Todo fill this with the necessary business logic */
    return NULL;
}



/**
 * Auto generated function definition

 * @param param6

*/
axiom_node_t *
axis2_Calculator_mul(const axutil_env_t * env, axiom_node_t* param6)
{
    /* Todo fill this with the necessary business logic */
    return NULL;
}
