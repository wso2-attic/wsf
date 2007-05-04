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
#include "echo.h"
#include <axiom_xml_writer.h>
#include <stdio.h>

axiom_node_t *
build_om_programatically(const axutil_env_t *env, axis2_char_t *text);

axiom_node_t *
axis2_echo_echo(const axutil_env_t *env, axiom_node_t *node)
{
    axiom_node_t *text_parent_node = NULL;
    axiom_node_t *text_node = NULL;
    axiom_node_t *ret_node = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    /* Expected request format is :-
     * <ns1:echoString xmlns:ns1="http://ws.apache.org/axis2/c/samples">
     *      <text>echo5</text>
     * </ns1:echoString>
     */
    if (!node) /* 'echoString' node */
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INPUT_OM_NODE_NULL, AXIS2_FAILURE);
        printf("Echo client ERROR: input parameter NULL\n");
        return NULL;
    }

    text_parent_node = axiom_node_get_first_child(node, env);
    if (!text_parent_node) /* 'text' node */
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Echo client ERROR: invalid XML in request\n");
        return NULL;
    }

    text_node = axiom_node_get_first_child(text_parent_node, env);
    if (!text_node) /* actual text to echo */
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Echo client ERROR: invalid XML in request\n");
        return NULL;
    }

    if (axiom_node_get_node_type(text_node, env) == AXIOM_TEXT)
    {
        axiom_text_t *text = (axiom_text_t *)axiom_node_get_data_element(text_node, env);
        if (text && axiom_text_get_value(text , env))
        {
            axis2_char_t *text_str = (axis2_char_t *)axiom_text_get_value(text, env);
            /*printf("Echoing text value  %s \n", text_str);*/
            ret_node = build_om_programatically(env, text_str);
        }
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Echo client ERROR: invalid XML in request\n");
        return NULL;
    }

    return ret_node;
}

/* Builds the response content */
axiom_node_t *
build_om_programatically(const axutil_env_t *env, axis2_char_t *text)
{
    axiom_node_t *echo_om_node = NULL;
    axiom_element_t* echo_om_ele = NULL;
    axiom_node_t* text_om_node = NULL;
    axiom_element_t * text_om_ele = NULL;
    axiom_namespace_t *ns1 = NULL;

    ns1 = axiom_namespace_create(env, "http://ws.apache.org/axis2/c/samples", "ns1");

    echo_om_ele = axiom_element_create(env, NULL, "echoString", ns1, &echo_om_node);

    text_om_ele = axiom_element_create(env, echo_om_node, "text", NULL, &text_om_node);

    axiom_element_set_text(text_om_ele, env, text, text_om_node);

    return echo_om_node;
}





