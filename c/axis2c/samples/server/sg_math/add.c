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
#include "add.h"
#include <stdio.h>
#include <axis2_svc_grp_ctx.h>

axiom_node_t *
axis2_add_add(const axutil_env_t *env, axiom_node_t *node, axis2_msg_ctx_t *msg_ctx)
{
    axiom_node_t *param1_node = NULL;
    axiom_node_t *param1_text_node = NULL;
    axis2_char_t *param1_str = NULL;
    long int param1 = 0;
    axiom_node_t *param2_node = NULL;
    axiom_node_t *param2_text_node = NULL;
    axis2_char_t *param2_str = NULL;
    long int param2 = 0;

    if (!node)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INPUT_OM_NODE_NULL, AXIS2_FAILURE);
        printf("Math client request ERROR: input parameter NULL\n");
        return NULL;
    }

    param1_node = axiom_node_get_first_child(node, env);
    if (!param1_node)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Math service  ERROR: invalid XML in request\n");
        return NULL;
    }

    param1_text_node = axiom_node_get_first_child(param1_node, env);
    if (!param1_text_node)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Math service ERROR: invalid XML in request\n");
        return NULL;
    }

    if (axiom_node_get_node_type(param1_text_node, env) == AXIOM_TEXT)
    {
        axiom_text_t *text = (axiom_text_t *)axiom_node_get_data_element(param1_text_node, env);
        if (text && axiom_text_get_value(text , env))
        {
            param1_str = (axis2_char_t *)axiom_text_get_value(text, env);
        }
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Math service ERROR: invalid XML in request\n");
        return NULL;
    }

    param2_node = axiom_node_get_next_sibling(param1_node, env);
    if (!param2_node)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Math service  ERROR: invalid XML in request\n");
        return NULL;
    }

    param2_text_node = axiom_node_get_first_child(param2_node, env);
    if (!param2_text_node)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Math service ERROR: invalid XML in request\n");
        return NULL;
    }

    if (axiom_node_get_node_type(param2_text_node, env) == AXIOM_TEXT)
    {
        axiom_text_t *text = (axiom_text_t *)axiom_node_get_data_element(param2_text_node, env);
        if (text && axiom_text_get_value(text , env))
        {
            param2_str = (axis2_char_t *)axiom_text_get_value(text, env);
        }
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Math service ERROR: invalid XML in request\n");
        return NULL;
    }

    if (param1_str && param2_str)
    {
        long int result = 0;
        axis2_char_t result_str[255];

        axiom_element_t *ele1 = NULL;
        axiom_node_t *node1 = NULL, *node2 = NULL;
        axiom_namespace_t *ns1 = NULL;
        axiom_text_t *text1 = NULL;

        axis2_svc_grp_ctx_t *svc_grp_ctx = NULL;

        param1 = strtol(param1_str, NULL, 10);
        param2 = strtol(param2_str, NULL, 10);
        result = param1 + param2;
        sprintf(result_str, "%ld", result);



        ns1 = axiom_namespace_create(env,
                "http://axis2/test/namespace1",
                "ns1");
        ele1 = axiom_element_create(env, NULL, "result", ns1, &node1);
        text1 = axiom_text_create(env, node1, result_str, &node2);

        /* Put the result into service group context */
        svc_grp_ctx =  axis2_msg_ctx_get_svc_grp_ctx(msg_ctx, env);
        if (svc_grp_ctx)
        {
            axis2_ctx_t* ctx = NULL;
            ctx =  axis2_svc_grp_ctx_get_base(svc_grp_ctx, env);
            if (ctx)
            {
                axutil_property_t* prop = NULL;
                /* get value */
                prop =  axis2_ctx_get_property(ctx, env, "ADD_RESULT");
                if (prop)
                {
                    axis2_char_t *val = (axis2_char_t*)axutil_property_get_value(prop, env);
                    printf("Previous result = %s\n", val);
                }
                /* set value */
                prop = axutil_property_create(env);
                if (prop)
                {
                    axutil_property_set_value(prop, env, axutil_strdup(env, result_str));
                    axis2_ctx_set_property(ctx, env, "ADD_RESULT", prop);
                }
            }
        }


        return node1;
    }

    AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_OPERATION_PARAMETERS_IN_SOAP_REQUEST, AXIS2_FAILURE);
    printf("Math service ERROR: invalid parameters\n");
    return NULL;
}


