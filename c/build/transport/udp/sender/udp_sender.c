
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

#include <axis2_udp_transport.h>
#include <axis2_udp_sender.h>
#include <axutil_string.h>
#include <axis2_endpoint_ref.h>
#include <axis2_addr.h>
#include <axiom_xml_writer.h>
#include <axiom_output.h>
#include <axiom_soap_body.h>
#include <axiom_soap.h>
#include <axutil_generic_obj.h>
#include <axutil_types.h>
#include <axutil_url.h>
#include <axutil_network_handler.h>
#include <time.h>
#include <axis2_options.h>

#define RES_BUFF 50

typedef struct axis2_udp_transport_sender_impl
{
	axis2_transport_sender_t transport_sender;
	axis2_udp_transport_params_t unicast;
	axis2_udp_transport_params_t multicast;
	axis2_bool_t is_multicast;
} axis2_udp_transport_sender_impl_t;

#define AXIS2_INTF_TO_IMPL(transport_sender)((axis2_udp_transport_sender_impl_t *)(transport_sender))

void AXIS2_CALL
axis2_udp_transport_sender_free(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env);


axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_invoke(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_msg_ctx_t * msg_ctx);


axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_clean_up(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_msg_ctx_t * msg_ctx);


axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_init(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_conf_ctx_t * conf_ctx,
    axis2_transport_out_desc_t * out_desc);

static void AXIS2_CALL
axis2_udp_transport_set_param_value(
	const axutil_env_t *env, axutil_param_container_t *container, 
	axis2_char_t *name, int *value);

static const axis2_transport_sender_ops_t udp_transport_sender_ops = {
    axis2_udp_transport_sender_init,
    axis2_udp_transport_sender_invoke,
    axis2_udp_transport_sender_clean_up,
    axis2_udp_transport_sender_free
};


AXIS2_EXTERN axis2_transport_sender_t *AXIS2_CALL
axis2_udp_transport_sender_create(const axutil_env_t * env)
{
	axis2_udp_transport_sender_impl_t *udp_sender = NULL;

	udp_sender = (axis2_udp_transport_sender_impl_t *) AXIS2_MALLOC(env->allocator, sizeof(axis2_udp_transport_sender_impl_t));
	if (!udp_sender)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}	
	udp_sender->transport_sender.ops = &udp_transport_sender_ops;
	return &(udp_sender->transport_sender);
}

void AXIS2_CALL
axis2_udp_transport_sender_free(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env)
{
    axis2_udp_transport_sender_impl_t *transport_sender_impl = NULL;    
    transport_sender_impl = AXIS2_INTF_TO_IMPL(transport_sender);
    AXIS2_FREE(env->allocator, transport_sender_impl);
    return;		
}

axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_invoke(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_msg_ctx_t * msg_ctx)
{
	axis2_op_t *op = NULL;
    const axis2_char_t *mep_uri = NULL;
    axis2_bool_t is_server = AXIS2_TRUE;
    axiom_soap_envelope_t *soap_envelope = NULL;
    axiom_xml_writer_t *xml_writer = NULL;
	axiom_xml_reader_t *reader = NULL;
    axiom_output_t *om_output = NULL;
    axis2_char_t *buffer = NULL;
    axutil_stream_t *out_stream = NULL;
    int buffer_size = 0;
    axis2_conf_ctx_t *conf_ctx = NULL;
    axis2_conf_t *conf = NULL;
    axis2_transport_out_desc_t *trans_desc = NULL;
    axutil_param_t *write_xml_declaration_param = NULL;
    axutil_hash_t *transport_attrs = NULL;
    axis2_bool_t write_xml_declaration = AXIS2_FALSE;
	axis2_udp_transport_sender_impl_t *sender = NULL;
	int udp_repeat;
	int udp_min_delay;
	int udp_max_delay;
	int udp_upper_delay;
	int T;
	axis2_bool_t message_received = AXIS2_FALSE;
	axis2_char_t recv_buffer[AXIS2_UDP_PACKET_MAX_SIZE];
	int recv_buff_len = AXIS2_UDP_PACKET_MAX_SIZE;
	axis2_bool_t is_oneway = AXIS2_FALSE;

	
    AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
                    "start:udp transport sender invoke");
	sender = AXIS2_INTF_TO_IMPL(transport_sender);

    is_server = axis2_msg_ctx_get_server_side(msg_ctx, env);

    soap_envelope = axis2_msg_ctx_get_soap_envelope(msg_ctx, env);

    xml_writer = axiom_xml_writer_create_for_memory(env, NULL,
                                                    AXIS2_TRUE, 0,
                                                    AXIS2_XML_PARSER_TYPE_BUFFER);
    if (!xml_writer)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                        "Failed to create XML writer");
        return AXIS2_FAILURE;
    }

    om_output = axiom_output_create(env, xml_writer);
    if (!om_output)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                        "Failed to create OM output");
        axiom_xml_writer_free(xml_writer, env);
        xml_writer = NULL;
        return AXIS2_FAILURE;
    }
    conf_ctx = axis2_msg_ctx_get_conf_ctx (msg_ctx, env);
    if (conf_ctx)
    {
        conf = axis2_conf_ctx_get_conf (conf_ctx, env);
    }
    if (conf)
    {
        trans_desc = axis2_conf_get_transport_out (conf,
                                                   env, AXIS2_TRANSPORT_ENUM_TCP);
    }
    if (trans_desc)
    {
        write_xml_declaration_param =
            axutil_param_container_get_param
            (axis2_transport_out_desc_param_container (trans_desc, env), env,
             AXIS2_XML_DECLARATION);
    }
    if (write_xml_declaration_param)
    {
        transport_attrs = axutil_param_get_attributes (write_xml_declaration_param, env);
        if (transport_attrs)
        {
            axutil_generic_obj_t *obj = NULL;
            axiom_attribute_t *write_xml_declaration_attr = NULL;
            axis2_char_t *write_xml_declaration_attr_value = NULL;

            obj = axutil_hash_get (transport_attrs, AXIS2_ADD_XML_DECLARATION,
                           AXIS2_HASH_KEY_STRING);
            if (obj)
            {
                write_xml_declaration_attr = (axiom_attribute_t *) axutil_generic_obj_get_value (obj,
                                                                                         env);
            }
            if (write_xml_declaration_attr)
            {
                write_xml_declaration_attr_value = axiom_attribute_get_value (write_xml_declaration_attr, env);
            }
            if (write_xml_declaration_attr_value && 0 == axutil_strcasecmp (write_xml_declaration_attr_value, AXIS2_VALUE_TRUE))
            {
                write_xml_declaration = AXIS2_TRUE;
            }
        }
    }

    if (write_xml_declaration)
    {
        axiom_output_write_xml_version_encoding (om_output, env);
    }

    axiom_soap_envelope_serialize(soap_envelope, env, om_output, AXIS2_FALSE);

    buffer = (axis2_char_t *) axiom_xml_writer_get_xml(xml_writer, env);
    if (!buffer)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                        "[tcp]Failed to serialize the SOAP envelope");
        return AXIS2_FAILURE;
    }
    buffer_size = axiom_xml_writer_get_xml_size(xml_writer, env);
    buffer[buffer_size] = 0;
    if (is_server)
    {
        out_stream = axis2_msg_ctx_get_transport_out_stream(msg_ctx, env);
        axutil_stream_write(out_stream, env, buffer, buffer_size);
    }
    else
    {
		/* Client */
        axis2_endpoint_ref_t *to = NULL;
        axutil_url_t *to_url = NULL;
        const axis2_char_t *to_str = NULL;
        const axis2_char_t *host = NULL;
        int port = 0;
        int write = -1;
        int read = -1;        
        int res_size = 0;
        int size = 0;
        axiom_xml_reader_t *reader = NULL;
        axiom_stax_builder_t *builder = NULL;
        axiom_soap_builder_t *soap_builder = NULL;
        axiom_soap_envelope_t *soap_envelope = NULL;
		axis2_socket_t send_socket, recv_socket;
		axutil_property_t *prop = NULL;
		axis2_char_t *prop_val = NULL;
		axis2_options_t *options = NULL;
		axis2_char_t *res_buffer = (axis2_char_t *)AXIS2_MALLOC(env->allocator, RES_BUFF);

		options = axis2_msg_ctx_get_options(msg_ctx, env);
		/* Check weather this is for multicast */
		prop = axis2_options_get_property(options, env, AXIS2_UDP_TRANSPORT_IS_MULTICAT);
		
		if (prop)
		{
			prop_val = axutil_property_get_value(prop, env);
			if (prop_val && !axutil_strcmp(prop_val, "true"))
			{
				sender->is_multicast = AXIS2_TRUE;
			} 
			else if (prop_val && !axutil_strcmp(prop_val, "false"))
			{
				sender->is_multicast = AXIS2_FALSE;
			}
			else
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Invalid value for %s", 
					AXIS2_UDP_TRANSPORT_IS_MULTICAT);
				return AXIS2_FAILURE;
			}
		}

		prop = axis2_options_get_property(options, env,
                                              AXIS2_UDP_TRANSPORT_ADDRESS);
		if (prop)
		{
			prop_val = axutil_property_get_value(prop, env);
			if (prop_val)
			{
				host = prop_val;
			}
		}

		prop = axis2_options_get_property(options, env,
                                              AXIS2_UDP_TRANSPORT_PORT);
		if (prop)
		{
			prop_val = axutil_property_get_value(prop, env);
			if (prop_val)
			{
				port = atoi(prop_val);
			}
		}
		
		if (!host)
		{
			to = axis2_msg_ctx_get_to(msg_ctx, env);
			if (!to)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "To epr not presant");
				return AXIS2_FAILURE;
			}

			to_str = axis2_endpoint_ref_get_address(to, env);
			if (!to_str)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
								"Unable to convert epr to string");
				return AXIS2_FAILURE;
			}

			to_url = axutil_url_parse_string(env, to_str);
			if (!to_url)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
								"Unable to parser string to url");
				return AXIS2_FAILURE;
			}

			host = axutil_url_get_host(to_url, env);
			if (!host)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Retrieving host failed");
				return AXIS2_FAILURE;
			}

			port = axutil_url_get_port(to_url, env);
			if (!port)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Retrieving port failed");
				return AXIS2_FAILURE;
			}
		}
		
		send_socket = (int)axutil_network_handler_open_dgram_socket(env);
		if (!send_socket)
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Socket creation failed");
			return AXIS2_FAILURE;
		}		
		
		if (sender->is_multicast)
		{
			int flag = 1;
			/* We are using two sockets in multicast case */
			recv_socket = axutil_network_handler_open_dgram_socket(env);	
			if (!recv_socket)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Socket creation failed");
				return AXIS2_FAILURE;
			}

			/* We are setting the address reuse since we are using two sockets for 
			sending and receving with the same port */
			axutil_network_handler_set_sock_option(env, send_socket, SO_REUSEADDR, flag);
			axutil_network_handler_set_sock_option(env, recv_socket, SO_REUSEADDR, flag);

			udp_repeat = sender->multicast.udp_repeat;
			udp_max_delay = sender->multicast.udp_max_delay;
			udp_min_delay = sender->multicast.udp_min_delay;
			udp_upper_delay = sender->multicast.udp_upper_delay;
		} 
		else
		{
			udp_repeat = sender->unicast.udp_repeat;
			udp_max_delay = sender->unicast.udp_max_delay;
			udp_min_delay = sender->unicast.udp_min_delay;
			udp_upper_delay = sender->unicast.udp_upper_delay;
		}	

	    op = axis2_msg_ctx_get_op(msg_ctx, env);	
		if (op)
		{	
			mep_uri = axis2_op_get_msg_exchange_pattern(op, env);
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI,
							"OP name axutil_qname_get_localpart = %s", mep_uri);
			if (axutil_strcmp(mep_uri, AXIS2_MEP_URI_OUT_ONLY) == 0 ||
				axutil_strcmp(mep_uri, AXIS2_MEP_URI_ROBUST_OUT_ONLY) == 0 ||
				axutil_strcmp(mep_uri, AXIS2_MEP_URI_IN_ONLY) == 0)
			{
				is_oneway = AXIS2_TRUE;
			}
		}
		/* Retry and backoff algorithm as defined by the spec */
		if (udp_repeat > 0)
		{			
			axis2_char_t *addr = (axis2_char_t *)host;
			int source_port = 0;
			message_received = AXIS2_FALSE;
			if (axutil_network_handler_send_dgram(env, send_socket, buffer, &buffer_size, addr, port, &source_port) == AXIS2_FAILURE)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "UDP packet sending failed.");
				return AXIS2_FAILURE;			
			}
			srand((unsigned int)time(NULL));			
			T = (rand() % (udp_max_delay - udp_min_delay)) + udp_min_delay;
			if (sender->is_multicast)
			{
				axutil_network_handler_bind_socket(env, recv_socket, source_port);	
			}
			/* We are expecting a response */
			while (!is_oneway)
			{								
				if (!sender->is_multicast)
				{
					/* The recieve will happen on the same port as the send */
					axutil_network_handler_set_sock_option(env, send_socket, SO_RCVTIMEO, T);
					if (axutil_network_handler_read_dgram(env, send_socket, recv_buffer, &recv_buff_len, NULL, NULL) != AXIS2_FAILURE)
					{
						message_received = AXIS2_TRUE;
						break;			
					}
				}
				else
				{
					/* The receive will happen in a different port on the same port */
					axutil_network_handler_set_sock_option(env, recv_socket, SO_RCVTIMEO, T);
					if (axutil_network_handler_read_dgram(env, recv_socket, recv_buffer, &recv_buff_len, NULL, NULL) != AXIS2_FAILURE)
					{
						message_received = AXIS2_TRUE;
						break;			
					}
				}
				if (--udp_repeat <= 0)
					break;
				if (axutil_network_handler_send_dgram(env, send_socket, buffer, &buffer_size, addr, port, &source_port) == AXIS2_FAILURE)
				{
					AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "UDP packet sending failed.");
					return AXIS2_FAILURE;			
				}				
				T = T * 2;
				if (T > udp_upper_delay)
				{
					T = udp_upper_delay;
				}
			}			
		}
		/* Close the sockets */
		axutil_network_handler_close_socket(env, send_socket);
		if (sender->is_multicast)
		{
			axutil_network_handler_close_socket(env, recv_socket);
		}
		if (message_received && !is_oneway)
		{
			reader = axiom_xml_reader_create_for_memory(env, recv_buffer, (recv_buff_len),
														NULL, AXIS2_XML_PARSER_TYPE_BUFFER);
			if (!reader)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed to create XML reader");
				return AXIS2_FAILURE;
			}

			builder = axiom_stax_builder_create(env, reader);
			if (!builder)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
								"Failed to create Stax builder");
				return AXIS2_FAILURE;
			}

			soap_builder = axiom_soap_builder_create(env, builder,
													 AXIOM_SOAP12_SOAP_ENVELOPE_NAMESPACE_URI);
			if (!soap_builder)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
								"Failed to create SOAP builder");
				return AXIS2_FAILURE;
			}
			soap_envelope = axiom_soap_builder_get_soap_envelope(soap_builder, env);
			if (!soap_envelope)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
								"Failed to create SOAP envelope");
				return AXIS2_FAILURE;
			}
			axis2_msg_ctx_set_response_soap_envelope(msg_ctx, env, soap_envelope);
		}
		else if (is_oneway)
		{
			return AXIS2_SUCCESS;					
		}
		else
		{
			return AXIS2_FAILURE;
		}
    }
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "end: udp transport sender invoke");
    return AXIS2_SUCCESS;	
}

axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_clean_up(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_msg_ctx_t * msg_ctx)
{
	/* We do not have anything to clean */
	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_init(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_conf_ctx_t * conf_ctx,
    axis2_transport_out_desc_t * out_desc)
{
	axutil_param_container_t *container = NULL;
	axis2_udp_transport_sender_impl_t *udp_sender = NULL;   
	axutil_param_t *temp_param = NULL;
	axis2_char_t *temp = NULL;
	
	udp_sender = AXIS2_INTF_TO_IMPL(transport_sender);
	/* Setting the default values */
	udp_sender->multicast.udp_max_delay = AXIS2_UDP_TRANSPORT_MUL_MAX_DELAY;
	udp_sender->multicast.udp_min_delay = AXIS2_UDP_TRANSPORT_MUL_MIN_DELAY;
	udp_sender->multicast.udp_repeat = AXIS2_UDP_TRANSPORT_MUL_REPEAT;
	udp_sender->multicast.udp_upper_delay = AXIS2_UDP_TRANSPORT_MUL_UPPER_DELAY;

	udp_sender->unicast.udp_max_delay = AXIS2_UDP_TRANSPORT_UNI_MAX_DELAY;
	udp_sender->unicast.udp_min_delay = AXIS2_UDP_TRANSPORT_UNI_MIN_DELAY;
	udp_sender->unicast.udp_repeat = AXIS2_UDP_TRANSPORT_UNI_REPEAT;
	udp_sender->unicast.udp_upper_delay = AXIS2_UDP_TRANSPORT_UNI_UPPER_DELAY;

	udp_sender->is_multicast = AXIS2_FALSE;
	container = axis2_transport_out_desc_param_container(out_desc, env);
    temp_param = axutil_param_container_get_param(container, env, AXIS2_UDP_TRANSPORT_MULTICAST);
	if (temp_param)
	{
		temp = axutil_param_get_value(temp_param, env);
		if (axutil_strcmp(temp, "true"))
		{
			udp_sender->is_multicast = AXIS2_TRUE;
		}
		else if (axutil_strcmp(temp, "false"))
		{
			udp_sender->is_multicast = AXIS2_FALSE;	
		}
		else
		{
			/* Here we quit */
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
				"Invalid configuration for multicast parameter");
			return AXIS2_FAILURE;
		}
	}
	
	/* Setting the user defined values */
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_MUL_MAX_DELAY_STR, &(udp_sender->multicast.udp_max_delay));
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_MUL_MIN_DELAY_STR, &(udp_sender->multicast.udp_min_delay));
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_MUL_REPEAT_STR, &(udp_sender->multicast.udp_repeat));
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_MUL_UPPER_DELAY_STR, &(udp_sender->multicast.udp_upper_delay));

	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_UNI_MAX_DELAY_STR, &(udp_sender->unicast.udp_max_delay));
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_UNI_MIN_DELAY_STR, &(udp_sender->unicast.udp_min_delay));
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_UNI_REPEAT_STR, &(udp_sender->unicast.udp_repeat));
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_UNI_UPPER_DELAY_STR, &(udp_sender->unicast.udp_upper_delay));

	
    return AXIS2_SUCCESS;
}

/* Utility method for retrieving a parameter from a param container */
static void AXIS2_CALL
axis2_udp_transport_set_param_value(const axutil_env_t *env, axutil_param_container_t *container, 
									axis2_char_t *name, int *value)
{
	axutil_param_t *temp_param = NULL;
	axis2_char_t *temp = NULL;
	temp_param = axutil_param_container_get_param(container, env, name);
	if (temp_param)
	{
		temp = axutil_param_get_value(temp_param, env);
		if (temp)
		{
			*value = AXIS2_ATOI(temp);
		}
	}
}

/**
 * Following is the exposed part of the dll.
 */

/* 
 * When building for static deployment, give the get and remove methods
 * unique names.  This avoids having the linker fail with duplicate symbol
 * errors.
 */

AXIS2_EXPORT int
#ifndef AXIS2_STATIC_DEPLOY
 axis2_get_instance(
#else
axis2_udp_transport_sender_get_instance(
#endif
    struct axis2_transport_sender **inst,
    const axutil_env_t * env)
{
    *inst = axis2_udp_transport_sender_create(env);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
#ifndef AXIS2_STATIC_DEPLOY
 axis2_remove_instance(
#else
axis2_udp_transport_sender_remove_instance(
#endif
    axis2_transport_sender_t * inst,
    const axutil_env_t * env)
{
    if (inst)
    {
        AXIS2_TRANSPORT_SENDER_FREE(inst, env);
    }
    return AXIS2_SUCCESS;
}

