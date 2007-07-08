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

#include <axiom_xml_writer.h>
#include <stdio.h>

#include "listener.h"

axiom_node_t *
axis2_listener_notify(const axutil_env_t *env, axiom_node_t *node)
{
    axis2_char_t *str = NULL;
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "Start:axis2_listener_notify");
    AXIS2_ENV_CHECK(env, NULL);

    str = axiom_node_to_string(node, env);
    if (str)
        printf("\nReceived : %s\n", str);
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "End:axis2_listener_notify");

    return NULL;
}
