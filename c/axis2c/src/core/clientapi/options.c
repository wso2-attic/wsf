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


#include <axis2_options.h>
#include <axis2_const.h>
#include <axutil_hash.h>
#include <axiom_soap_const.h>
#include <axis2_msg_info_headers.h>
#include <axutil_array_list.h>
#include <axis2_http_transport.h>

struct axis2_options
{
    /** parent options */
    axis2_options_t *parent;

    axutil_hash_t *properties;

    axis2_char_t *soap_version_uri;

    int soap_version;

    long timeout_in_milli_seconds;

    axis2_bool_t use_separate_listener;

    /** addressing specific properties */
    axis2_msg_info_headers_t *msg_info_headers;

    axis2_transport_receiver_t *receiver;

    axis2_transport_in_desc_t *transport_in;

    AXIS2_TRANSPORT_ENUMS transport_in_protocol;

    /** for sending and receiving messages */
    axis2_transport_out_desc_t *transport_out;
    AXIS2_TRANSPORT_ENUMS sender_transport_protocol;

    axis2_bool_t manage_session;
    axis2_bool_t enable_mtom;
    axutil_string_t *soap_action;
    axis2_bool_t xml_parser_reset;
};

AXIS2_EXTERN axis2_options_t *AXIS2_CALL
axis2_options_create(const axutil_env_t *env)
{
    axis2_options_t *options = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    options = AXIS2_MALLOC(env->allocator, sizeof(axis2_options_t));
    if (!options)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    options->parent = NULL;
    options->properties = NULL;
    options->soap_version_uri = NULL;
    options->timeout_in_milli_seconds = -1;
    options->use_separate_listener = -1;
    options->receiver = NULL;
    options->transport_in = NULL;
    options->transport_in_protocol = AXIS2_TRANSPORT_ENUM_HTTP;
    options->transport_out = NULL;
    options->sender_transport_protocol = AXIS2_TRANSPORT_ENUM_HTTP;
    options->manage_session = -1;
    options->soap_version = AXIOM_SOAP12;
    options->enable_mtom = AXIS2_FALSE;
    options->soap_action = NULL;
    options->xml_parser_reset = AXIS2_TRUE;


    options->msg_info_headers = axis2_msg_info_headers_create(env, NULL, NULL);
    if (!(options->msg_info_headers))
    {
        axis2_options_free(options, env);
        return NULL;
    }

    options->properties = axutil_hash_make(env);
    if (!(options->properties))
    {
        axis2_options_free(options, env);
        return NULL;
    }

    return options;
}

AXIS2_EXTERN axis2_options_t *AXIS2_CALL
axis2_options_create_with_parent(const axutil_env_t *env,
    axis2_options_t *parent)
{

    axis2_options_t *options = NULL;

    options = axis2_options_create(env);

    if (options)
    {
        options->parent = parent;
    }
    return options;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_options_get_action(const axis2_options_t *options,
    const axutil_env_t *env)
{
    const axis2_char_t *action = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    action = axis2_msg_info_headers_get_action(options->msg_info_headers, env);

    if (action == NULL && options->parent)
    {
        return axis2_options_get_action(options->parent, env);
    }

    return action;
}

AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
axis2_options_get_fault_to(const axis2_options_t *options,
    const axutil_env_t *env)
{
    axis2_endpoint_ref_t *fault_to = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    fault_to = axis2_msg_info_headers_get_fault_to(options->msg_info_headers, env);

    if (fault_to == NULL && options->parent)
    {
        return axis2_options_get_fault_to(options->parent, env);
    }

    return fault_to;
}


AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
axis2_options_get_from(const axis2_options_t *options,
    const axutil_env_t *env)
{
    axis2_endpoint_ref_t *from = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    from = axis2_msg_info_headers_get_from(options->msg_info_headers, env);

    if (from == NULL && options->parent)
    {
        return axis2_options_get_from(options->parent, env);
    }

    return from;
}

AXIS2_EXTERN axis2_transport_receiver_t *AXIS2_CALL
axis2_options_get_transport_receiver(const axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (options->receiver == NULL && options->parent)
    {
        return axis2_options_get_transport_receiver(options->parent, env);
    }

    return options->receiver;
}

AXIS2_EXTERN axis2_transport_in_desc_t *AXIS2_CALL
axis2_options_get_transport_in(const axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (options->transport_in == NULL && options->parent)
    {
        return axis2_options_get_transport_in(options->parent, env);
    }

    return options->transport_in;
}

AXIS2_EXTERN AXIS2_TRANSPORT_ENUMS AXIS2_CALL
axis2_options_get_transport_in_protocol(const axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (options->parent)
    {
        return axis2_options_get_transport_in_protocol(options->parent, env);
    }

    return options->transport_in_protocol;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_options_get_message_id(const axis2_options_t *options,
    const axutil_env_t *env)
{
    const axis2_char_t *message_id = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    message_id = axis2_msg_info_headers_get_message_id(options->msg_info_headers, env);

    if (message_id == NULL && options->parent)
    {
        return axis2_options_get_message_id(options->parent, env);
    }

    return message_id;
}

AXIS2_EXTERN axutil_hash_t *AXIS2_CALL
axis2_options_get_properties(const axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (axutil_hash_count(options->properties) == 0 && options->parent)
    {
        return axis2_options_get_properties(options->parent, env);
    }

    return options->properties;
}

AXIS2_EXTERN void *AXIS2_CALL
axis2_options_get_property(const axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_char_t *key)
{
    void *property = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    property = axutil_hash_get(options->properties, key, AXIS2_HASH_KEY_STRING);

    if (property == NULL && options->parent)
    {
        return axis2_options_get_property(options->parent, env, key);
    }

    return property;
}

AXIS2_EXTERN axis2_relates_to_t *AXIS2_CALL
axis2_options_get_relates_to(const axis2_options_t *options,
    const axutil_env_t *env)
{
    axis2_relates_to_t *relates_to = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    relates_to = axis2_msg_info_headers_get_relates_to(options->msg_info_headers, env);

    if (relates_to == NULL && options->parent)
    {
        return axis2_options_get_relates_to(options->parent, env);
    }

    return relates_to;
}

AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
axis2_options_get_reply_to(const axis2_options_t *options,
    const axutil_env_t *env)
{
    axis2_endpoint_ref_t *reply_to = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    reply_to = axis2_msg_info_headers_get_reply_to(options->msg_info_headers, env);

    if (reply_to == NULL && options->parent)
    {
        return axis2_options_get_reply_to(options->parent, env);
    }

    return reply_to;
}

AXIS2_EXTERN axis2_transport_out_desc_t *AXIS2_CALL
axis2_options_get_transport_out(const axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (options->transport_out == NULL && options->parent)
    {
        return axis2_options_get_transport_out(options->parent, env);
    }

    return options->transport_out;
}

AXIS2_EXTERN AXIS2_TRANSPORT_ENUMS AXIS2_CALL
axis2_options_get_sender_transport_protocol(const axis2_options_t *options,
    const axutil_env_t *env)
{

    AXIS2_ENV_CHECK(env, NULL);

    if (options->parent)
    {
        return axis2_options_get_sender_transport_protocol(options->parent, env);
    }

    return options->sender_transport_protocol;
}

AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
axis2_options_get_soap_version_uri(const axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    if (options->soap_version_uri == NULL && options->parent)
    {
        return axis2_options_get_soap_version_uri(options->parent, env);
    }

    if (options->soap_version_uri)
    {
        return options->soap_version_uri;
    }
    return AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI;

}

AXIS2_EXTERN long AXIS2_CALL
axis2_options_get_timeout_in_milli_seconds(const axis2_options_t *options,
    const axutil_env_t *env)
{
    if (options->timeout_in_milli_seconds == -1 && options->parent)
    {
        return axis2_options_get_timeout_in_milli_seconds(options->parent, env);
    }

    if (options->timeout_in_milli_seconds == -1)
    {
        return AXIS2_DEFAULT_TIMEOUT_MILLISECONDS;
    }

    return options->timeout_in_milli_seconds;
}


AXIS2_EXTERN axis2_endpoint_ref_t* AXIS2_CALL
axis2_options_get_to(const axis2_options_t *options,
    const axutil_env_t *env)
{
    axis2_endpoint_ref_t *to = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    to = axis2_msg_info_headers_get_to(options->msg_info_headers, env);

    if (to == NULL && options->parent)
    {
        return axis2_options_get_to(options->parent, env);
    }

    return to;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_options_get_use_separate_listener(const axis2_options_t *options,
    const axutil_env_t *env)
{
    if (options->use_separate_listener == -1 && options->parent)
    {
        return axis2_options_get_use_separate_listener(options->parent, env);
    }

    if (options->use_separate_listener == -1)
    {
        return AXIS2_FALSE;
    }

    return options->use_separate_listener;
}

AXIS2_EXTERN axis2_options_t *AXIS2_CALL
axis2_options_get_parent(const axis2_options_t *options,
    const axutil_env_t *env)
{
    return options->parent;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_parent(axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_options_t *parent)
{
    options->parent = (axis2_options_t *)parent;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_action(axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_char_t *action)
{
    axis2_msg_info_headers_set_action(options->msg_info_headers, env, action);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_fault_to(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *fault_to)
{
    axis2_msg_info_headers_set_fault_to(options->msg_info_headers, env, fault_to);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_from(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *from)
{
    axis2_msg_info_headers_set_from(options->msg_info_headers, env, from);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_to(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *to)
{
    axis2_msg_info_headers_set_to(options->msg_info_headers, env, to);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_transport_receiver(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_transport_receiver_t *receiver)
{
    options->receiver = receiver;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_transport_in(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_transport_in_desc_t *transport_in)
{
    options->transport_in = transport_in;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_transport_in_protocol(axis2_options_t *options,
    const axutil_env_t *env,
    const AXIS2_TRANSPORT_ENUMS transport_in_protocol)
{
    options->transport_in_protocol = transport_in_protocol;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_message_id(axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_char_t *message_id)
{
    axis2_msg_info_headers_set_message_id(options->msg_info_headers, env, message_id);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_properties(axis2_options_t *options,
    const axutil_env_t *env,
    axutil_hash_t *properties)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (options->properties)
    {
        axutil_hash_free(options->properties, env);
    }
    options->properties = properties;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_property(axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_char_t *property_key,
    const void *property)
{
    axutil_hash_set(options->properties, property_key,
        AXIS2_HASH_KEY_STRING, property);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_relates_to(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_relates_to_t *relates_to)
{
    axis2_msg_info_headers_set_relates_to(options->msg_info_headers, env, relates_to);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_reply_to(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_endpoint_ref_t *reply_to)
{
    axis2_msg_info_headers_set_reply_to(options->msg_info_headers, env, reply_to);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_transport_out(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_transport_out_desc_t *transport_out)
{
    options->transport_out = transport_out;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_sender_transport(axis2_options_t *options,
    const axutil_env_t *env,
    const AXIS2_TRANSPORT_ENUMS sender_transport,
    axis2_conf_t *conf)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    options->transport_out =  axis2_conf_get_transport_out(conf, env, sender_transport);

    if (!(options->transport_out))
    {
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_soap_version_uri(axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_char_t *soap_version_uri)
{
    if (options->soap_version_uri)
    {
        AXIS2_FREE(env->allocator, options->soap_version_uri);
        options->soap_version_uri = NULL;
    }

    if (soap_version_uri)
    {
        options->soap_version_uri = axutil_strdup(env, soap_version_uri);
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_timeout_in_milli_seconds(axis2_options_t *options,
    const axutil_env_t *env,
    long timeout_in_milli_seconds)
{
    options->timeout_in_milli_seconds = timeout_in_milli_seconds;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_transport_info(axis2_options_t *options,
    const axutil_env_t *env,
    const AXIS2_TRANSPORT_ENUMS sender_transport,
    const AXIS2_TRANSPORT_ENUMS receiver_transport,
    const axis2_bool_t use_separate_listener)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    /**
      here we check for the legal combination
      */
    if (!use_separate_listener)
    {
        if (sender_transport != receiver_transport)
        {
            return AXIS2_FAILURE;
        }
    }
    else
    {
        axis2_options_set_use_separate_listener(options,
            env, use_separate_listener);
    }
    axis2_options_set_transport_in_protocol(options, env, receiver_transport);
    options->sender_transport_protocol = sender_transport;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_use_separate_listener(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t use_separate_listener)
{
    options->use_separate_listener = use_separate_listener;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_add_reference_parameter(axis2_options_t *options,
    const axutil_env_t *env,
    axiom_node_t *reference_parameter)
{
    axis2_msg_info_headers_add_ref_param(options->msg_info_headers,
        env, reference_parameter);
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_manage_session(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t manage_session)
{
    options->manage_session = manage_session;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_options_get_manage_session(const axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FALSE);

    if (options->manage_session == -1 && options->parent)
    {
        return axis2_options_get_manage_session(options->parent, env);
    }

    if (options->manage_session == -1)
    {
        return AXIS2_FALSE;
    }

    return options->manage_session;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_msg_info_headers(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_msg_info_headers_t *msg_info_headers)
{
    options->msg_info_headers = msg_info_headers;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_msg_info_headers_t *AXIS2_CALL
axis2_options_get_msg_info_headers(const axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, NULL);

    return options->msg_info_headers;
}

AXIS2_EXTERN void AXIS2_CALL
axis2_options_free(axis2_options_t *options,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, void);

    if (options->properties)
    {
        axutil_hash_index_t *hi = NULL;
        void *val = NULL;
        const void *key = NULL;
        for (hi = axutil_hash_first(options->properties, env);
            hi; hi = axutil_hash_next(env, hi))
        {
            axutil_property_t *property = NULL;

            axutil_hash_this(hi, &key, NULL, &val);
            property = (axutil_property_t *) val;

            if (property)
            {
                axutil_property_free(property, env);
            }
        }
        axutil_hash_free(options->properties, env);
    }

    if (options->soap_version_uri)
    {
        AXIS2_FREE(env->allocator, options->soap_version_uri);
    }

    if (options->msg_info_headers)
    {
        axis2_msg_info_headers_free(options->msg_info_headers, env);
    }

    if (options->soap_action)
    {
        axutil_string_free(options->soap_action, env);
    }

    AXIS2_FREE(env->allocator, options);

    return;
}

AXIS2_EXTERN int AXIS2_CALL
axis2_options_get_soap_version(const axis2_options_t *options,
    const axutil_env_t *env)
{
    return options->soap_version;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_soap_version(axis2_options_t *options,
    const axutil_env_t *env,
    int soap_version)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (soap_version == AXIOM_SOAP11)
    {
        options->soap_version = soap_version;
        axis2_options_set_soap_version_uri(options, env,
            AXIOM_SOAP11_SOAP_ENVELOPE_NAMESPACE_URI);
    }
    else
    {
        options->soap_version = AXIOM_SOAP12;
        axis2_options_set_soap_version_uri(options, env,
            AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_enable_mtom(axis2_options_t *options,
    const axutil_env_t *env,
    axis2_bool_t enable_mtom)
{
    options->enable_mtom = enable_mtom;

    if (enable_mtom)
    {
        axutil_property_t *property = axutil_property_create(env);
        if (property)
        {
            axutil_property_set_scope(property, env, AXIS2_SCOPE_REQUEST);
            axutil_property_set_value(property, env, axutil_strdup(env, AXIS2_VALUE_TRUE));
            axis2_options_set_property(options, env, AXIS2_ENABLE_MTOM, property);
        }
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_options_get_enable_mtom(const axis2_options_t *options,
    const axutil_env_t *env)
{
    return options->enable_mtom;
}

AXIS2_EXTERN axutil_string_t *AXIS2_CALL
axis2_options_get_soap_action(const axis2_options_t *options,
    const axutil_env_t *env)
{
    return options->soap_action;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axis2_options_set_soap_action(axis2_options_t *options,
    const axutil_env_t *env,
    axutil_string_t *soap_action)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (options->soap_action)
    {
        axutil_string_free(options->soap_action, env);
        options->soap_action = NULL;
    }

    if (soap_action)
    {
        options->soap_action = axutil_string_clone(soap_action, env);
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_options_get_xml_parser_reset(const axis2_options_t *options,
	const axutil_env_t *env)
{
    return options->xml_parser_reset;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL 
axis2_options_set_xml_parser_reset(axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_bool_t xml_parser_reset)
{
    options->xml_parser_reset = xml_parser_reset;
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_enable_rest(axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_bool_t enable_rest)
{
    axutil_property_t *rest_property = NULL;
    
    AXIS2_ENV_CHECK(env, NULL);
    if (enable_rest)
    {
        rest_property = axutil_property_create(env);
        axutil_property_set_value(rest_property, env, axutil_strdup (env, AXIS2_VALUE_TRUE));
        axis2_options_set_property(options, env, AXIS2_ENABLE_REST,
            rest_property);
    }
    else
    {
        rest_property = axutil_property_create(env);
        axutil_property_set_value(rest_property, env, axutil_strdup (env, AXIS2_VALUE_FALSE));
        axis2_options_set_property(options, env, AXIS2_ENABLE_REST,
            rest_property);
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_options_set_http_method(axis2_options_t *options,
    const axutil_env_t *env,
    const axis2_char_t *http_method)
{
    axutil_property_t *method_property = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    method_property = axutil_property_create(env);
    axutil_property_set_value(method_property, env, axutil_strdup(env, http_method));
    axis2_options_set_property(options, env, AXIS2_HTTP_METHOD,
            method_property);
    return AXIS2_SUCCESS;
}

