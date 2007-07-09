/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <axis2_svc_skeleton.h>
#include <axutil_log_default.h>
#include <axutil_error_default.h>
#include <axutil_array_list.h>
#include <axiom_text.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <stdio.h>

axiom_node_t *axis2_hello_greet(const axutil_env_t *env,
        axiom_node_t *node);

int AXIS2_CALL
hello_free(axis2_svc_skeleton_t *svc_skeleton,
        const axutil_env_t *env);

axiom_node_t* AXIS2_CALL
hello_invoke(axis2_svc_skeleton_t *svc_skeleton,
        const axutil_env_t *env,
        axiom_node_t *node,
        axis2_msg_ctx_t *msg_ctx);


int AXIS2_CALL
hello_init(axis2_svc_skeleton_t *svc_skeleton,
        const axutil_env_t *env);

axiom_node_t* AXIS2_CALL
hello_on_fault(axis2_svc_skeleton_t *svc_skeli,
        const axutil_env_t *env, axiom_node_t *node);


axiom_node_t *
build_greeting_response(const axutil_env_t *env, 
        axis2_char_t *greeting);

axiom_node_t *
axis2_hello_greet(const axutil_env_t *env, axiom_node_t *node)
{
    axiom_node_t *client_greeting_node = NULL;
    axiom_node_t *return_node = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    if (node)
    {
        client_greeting_node = axiom_node_get_first_child(node, env);
        if (client_greeting_node &&
                axiom_node_get_node_type(client_greeting_node, env) == AXIOM_TEXT)
        {
            axiom_text_t *greeting = (axiom_text_t *)axiom_node_get_data_element(client_greeting_node, env);
            if (greeting && axiom_text_get_value(greeting , env))
            {
                const axis2_char_t *greeting_str = axiom_text_get_value(greeting, env);
                printf("Client greeted saying \"%s\" \n", greeting_str);
                return_node = build_greeting_response(env, "Hello Client!");
            }
        }
    }
    else
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_SVC_SKEL_INVALID_XML_FORMAT_IN_REQUEST, AXIS2_FAILURE);
        printf("ERROR: invalid XML in request\n");
        return_node = build_greeting_response(env, "Client! Who are you?");
    }

    return return_node;
}

axiom_node_t *
build_greeting_response(const axutil_env_t *env, axis2_char_t *greeting)
{
    axiom_node_t* greeting_om_node = NULL;
    axiom_element_t * greeting_om_ele = NULL;

    greeting_om_ele = axiom_element_create(env, NULL, "greetResponse", NULL, &greeting_om_node);

    axiom_element_set_text(greeting_om_ele, env, greeting, greeting_om_node);

    return greeting_om_node;
}

static const axis2_svc_skeleton_ops_t hello_svc_skeleton_ops_var = {
    hello_init,
    hello_invoke,
    hello_on_fault,
    hello_free
};

axis2_svc_skeleton_t *
axis2_hello_create(const axutil_env_t *env)
{
    axis2_svc_skeleton_t *svc_skeleton = NULL;
    svc_skeleton = AXIS2_MALLOC(env->allocator,
            sizeof(axis2_svc_skeleton_t));

    svc_skeleton->ops = &hello_svc_skeleton_ops_var;

    svc_skeleton->func_array = NULL;
 
    return svc_skeleton;
}

int AXIS2_CALL
hello_init(axis2_svc_skeleton_t *svc_skeleton,
        const axutil_env_t *env)
{
    svc_skeleton->func_array = axutil_array_list_create(env, 0);
    axutil_array_list_add(svc_skeleton->func_array, env, "helloString");
    return AXIS2_SUCCESS;
}

axiom_node_t* AXIS2_CALL
hello_invoke(axis2_svc_skeleton_t *svc_skeleton,
        const axutil_env_t *env,
        axiom_node_t *node,
        axis2_msg_ctx_t *msg_ctx)
{
    return axis2_hello_greet(env, node);
}

axiom_node_t* AXIS2_CALL
hello_on_fault(axis2_svc_skeleton_t *svc_skeli,
        const axutil_env_t *env, axiom_node_t *node)
{
    axiom_node_t *error_node = NULL;
    axiom_node_t* text_node = NULL;
    axiom_element_t *error_ele = NULL;
    error_ele = axiom_element_create(env, node, "EchoServiceError", NULL,
            &error_node);
    axiom_element_set_text(error_ele, env, "Echo service failed ",
            text_node);
    return error_node;
}

int AXIS2_CALL
hello_free(axis2_svc_skeleton_t *svc_skeleton,
        const axutil_env_t *env)
{
    if (svc_skeleton->func_array)
    {
        axutil_array_list_free(svc_skeleton->func_array, env);
        svc_skeleton->func_array = NULL;
    }

    if (svc_skeleton)
    {
        AXIS2_FREE(env->allocator, svc_skeleton);
        svc_skeleton = NULL;
    }

    return AXIS2_SUCCESS;
}


AXIS2_EXPORT int
axis2_get_instance(axis2_svc_skeleton_t **inst,
        const axutil_env_t *env)
{
    *inst = axis2_hello_create(env);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
axis2_remove_instance(axis2_svc_skeleton_t *inst,
        const axutil_env_t *env)
{
    axis2_status_t status = AXIS2_FAILURE;
    if (inst)
    {
        status = AXIS2_SVC_SKELETON_FREE(inst, env);
    }
    return status;
}


