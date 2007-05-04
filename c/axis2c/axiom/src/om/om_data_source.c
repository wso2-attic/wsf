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

#include <axiom_data_source.h>
#include <axiom_output.h>
#include <axutil_string.h>
#include "axiom_node_internal.h"
#include <axiom_xml_writer.h>
#include <axiom_output.h>
#include <axiom_attribute.h>
#include <axiom_namespace.h>
#include <axutil_base64.h>


/********************* axiom_data_source_struct ***************/

struct axiom_data_source
{
    /** stream holding serialized XML string */
    axutil_stream_t *stream;
};

AXIS2_EXTERN axiom_data_source_t *AXIS2_CALL
axiom_data_source_create(const axutil_env_t *env,
    axiom_node_t * parent,
    axiom_node_t **node)
{

    axiom_data_source_t *data_source = NULL;
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, node, NULL);

    *node = axiom_node_create(env);

    if (!(*node))
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    data_source = (axiom_data_source_t *) AXIS2_MALLOC(env->allocator,
        sizeof(axiom_data_source_t));
    if (!data_source)
    {
        AXIS2_FREE(env->allocator, *node);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    axiom_node_set_data_element((*node), env, data_source);
    axiom_node_set_node_type((*node), env, AXIOM_DATA_SOURCE);
    axiom_node_set_complete((*node), env, AXIS2_FALSE);

    data_source->stream = NULL;
    
    data_source->stream = axutil_stream_create_basic(env);
    if (!(data_source->stream))
    {
        AXIS2_FREE(env->allocator, *node);
        AXIS2_FREE(env->allocator, data_source);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    if (parent && axiom_node_get_node_type(parent, env) == AXIOM_ELEMENT)
    {
        axiom_node_add_child(parent, env, (*node));
    }

    return data_source;
}

AXIS2_EXTERN void AXIS2_CALL
axiom_data_source_free(axiom_data_source_t * data_source,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (data_source->stream)
    {
        axutil_stream_free(data_source->stream, env);
    }

    AXIS2_FREE(env->allocator, data_source);

    return;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axiom_data_source_serialize(axiom_data_source_t *data_source,
    const axutil_env_t *env,
    axiom_output_t *om_output)
{
    int status = AXIS2_SUCCESS;
    axis2_char_t *data = NULL;
    unsigned int data_len = 0;


    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
    AXIS2_PARAM_CHECK(env->error, om_output, AXIS2_FAILURE);

    data = axutil_stream_get_buffer(data_source->stream, env);
    data_len = axutil_stream_get_len(data_source->stream, env);
    if (data)
    {
        data[data_len] = '\0';
        status = axiom_output_write(om_output, env,
            AXIOM_DATA_SOURCE, 1, data);
    }
    return status;
}

AXIS2_EXTERN axutil_stream_t *AXIS2_CALL
axiom_data_source_get_stream(axiom_data_source_t *data_source,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);
    return data_source->stream;
}


