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
#include "notify.h"
#include <stdio.h>

void
axis2_notify_notify(const axutil_env_t *env, axiom_node_t *node)
{
    axiom_node_t *text_node = NULL;

    if (!env || !env)
        return;

    /* Expected request format is :-
       <m:notify xmlns:m="http://example.org/notify">Message 3</m:notify>
     */
    if (!node) /* 'notify' node */
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INPUT_OM_NODE_NULL, AXIS2_FAILURE);
        printf("Echo client ERROR: input parameter NULL\n");
        return;
    }

    text_node = axiom_node_get_first_child(node, env);
    if (!node) /* actual text to notify */
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Echo client ERROR: invalid XML in request\n");
        return;
    }

    if (axiom_node_get_node_type(text_node, env) == AXIOM_TEXT)
    {
        axiom_text_t *text = (axiom_text_t *)axiom_node_get_data_element(text_node, env);
        if (text && axiom_text_get_value(text , env))
        {
            axis2_char_t *text_str = (axis2_char_t *)axiom_text_get_value(text, env);
            printf("Notification received :  %s \n", text_str);
        }
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("Echo client ERROR: invalid XML in request\n");
        return;
    }

    return;
}


