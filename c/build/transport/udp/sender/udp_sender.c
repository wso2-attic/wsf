
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
#include <time.h>
#include <axis2_options.h>
#include <axutil_thread.h>

#define RES_BUFF 50

/* UDP sender */
typedef struct axis2_udp_transport_sender_impl
{
	/* axis2_transport sender. This struct provides the interface */
	axis2_transport_sender_t transport_sender;
	/* If the socket is set it will be used */
	axis2_socket_t socket;
	/* if true sender should free the socket */
	axis2_bool_t owns_socket;
	/* Unicast parameters */
	axis2_udp_transport_params_t unicast;
	/* Multicast parameters */
	axis2_udp_transport_params_t multicast;
	/* Flag to set the multicast sending */
	axis2_bool_t is_multicast;
	/* Time that the sender will wait for a response */
	unsigned int time_out;
	/* Max packet size */
	unsigned int max_packet_size;
} axis2_udp_transport_sender_impl_t;

/* This structure is used for passsing information to the listner thread */
typedef struct axis2_udp_transport_sender_args_s
{
	/* env is passed to the threa */
	axutil_env_t *env;
	/* Actual sender */
	axis2_udp_transport_sender_impl_t *udp_sender;
	/* mutex to synchronize the sending and receiving thread */
	axutil_thread_mutex_t *mutex;	
	/* Buffer to receive the data */
	axis2_char_t *recv_buffer;
	/* Buffer length */
	int recv_buff_len;
	/* This flag is set when the receiving thread receives a message */
	axis2_bool_t message_received;
} axis2_udp_transport_sender_args_t;

#define AXIS2_INTF_TO_IMPL(transport_sender)((axis2_udp_transport_sender_impl_t *)(transport_sender))

void AXIS2_CALL
axis2_udp_transport_sender_free(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env);

/*
 * This function will run on a seperate thread to listen for incoming messages 
 */
void *AXIS2_THREAD_FUNC
axis2_udp_sender_thread_worker_func(
    axutil_thread_t * thd,
    void *data);

/* adds information to the axis2_conf so that the receiver can pick up and start 
 * from where sender left off. 
 */
static axis2_status_t AXIS2_CALL
axis2_udp_transport_add_backchannel_info(
	const axutil_env_t *env, 
	axis2_msg_ctx_t *msg_ctx);

 /* 
  * Invoke function 
  */
axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_invoke(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_msg_ctx_t * msg_ctx);

/* 
 * Clean up function.
 */
axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_clean_up(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_msg_ctx_t * msg_ctx);

/* 
 * Initialization function. This function will initialize the sender from the axis2.xml conf values.
 */
axis2_status_t AXIS2_CALL
axis2_udp_transport_sender_init(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
    axis2_conf_ctx_t * conf_ctx,
    axis2_transport_out_desc_t * out_desc);

/* 
 * Utility funtion to retrieve param values from the conf.
 */ 
static void AXIS2_CALL
axis2_udp_transport_set_param_value(
	const axutil_env_t *env, axutil_param_container_t *container, 
	axis2_char_t *name, int *value);

/* These are the operations for the sender */
static const axis2_transport_sender_ops_t udp_transport_sender_ops = {
    axis2_udp_transport_sender_init,
    axis2_udp_transport_sender_invoke,
    axis2_udp_transport_sender_clean_up,
    axis2_udp_transport_sender_free
};


AXIS2_EXTERN axis2_transport_sender_t *AXIS2_CALL
axis2_udp_ender_create(const axutil_env_t * env)
{
	axis2_udp_transport_sender_impl_t *udp_sender = NULL;

	udp_sender = (axis2_udp_transport_sender_impl_t *) AXIS2_MALLOC(env->allocator, sizeof(axis2_udp_transport_sender_impl_t));
	if (!udp_sender)
	{
		AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}	
	udp_sender->transport_sender.ops = &udp_transport_sender_ops;
	udp_sender->socket = AXIS2_INVALID_SOCKET;
	udp_sender->owns_socket = AXIS2_TRUE;
	udp_sender->time_out = 5000;
	udp_sender->is_multicast = AXIS2_FALSE;
	udp_sender->max_packet_size = AXIS2_UDP_PACKET_MAX_SIZE;
	return &(udp_sender->transport_sender);
}

void AXIS2_CALL
axis2_udp_transport_sender_free(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env)
{
    axis2_udp_transport_sender_impl_t *sender = NULL;    
    sender = AXIS2_INTF_TO_IMPL(transport_sender);
	
	if (sender->owns_socket && sender->socket != AXIS2_INVALID_SOCKET)
	{
		axutil_network_handler_close_socket(env, sender->socket);
	}
    AXIS2_FREE(env->allocator, sender);
    return;		
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
    temp_param = axutil_param_container_get_param(container, env, AXIS2_UDP_TRANSPORT_IS_MULTICAT);
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

	/* set the max packet size */
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_MAX_PACKET_SIZE_STR, &(udp_sender->max_packet_size));

	/* Set the time out */
	axis2_udp_transport_set_param_value(env, container, 
		AXIS2_UDP_TRANSPORT_TIMEOUT, &(udp_sender->time_out));

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_udp_sender_set_socket(
    axis2_transport_sender_t * transport_sender,
    const axutil_env_t * env,
	axis2_socket_t socket)
{
	axis2_udp_transport_sender_impl_t *udp_sender = NULL;   
	udp_sender = AXIS2_INTF_TO_IMPL(transport_sender);		
	/* We only let a socket to be set only if there is no socket set */
	if (udp_sender->socket == AXIS2_INVALID_SOCKET)
	{
		udp_sender->socket = socket;
		udp_sender->owns_socket = AXIS2_FALSE;
		return AXIS2_SUCCESS;
	}
	return AXIS2_SUCCESS;
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
	if (buffer_size > AXIS2_UDP_PACKET_MAX_SIZE)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
			"Message exceeds Maximum UDP packet limit:%d ", AXIS2_UDP_PACKET_MAX_SIZE);
		return AXIS2_FAILURE;
	}
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
		axutil_property_t *prop = NULL;
		axis2_char_t *prop_val = NULL;
		axis2_options_t *options = NULL;
		axis2_bool_t use_seperate_listnener = AXIS2_FALSE;
		axis2_udp_transport_sender_args_t *args = NULL;
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
		/* Retrieve the transport address */
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
		/* Retrieve the port */
		prop = axis2_options_get_property(options, env,
                                              AXIS2_UDP_TRANSPORT_PORT);
		if (prop)
		{
			int *int_val = NULL;
			int_val = axutil_property_get_value(prop, env);
			if (int_val)
			{
				port = *int_val;
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
		/* Determine weather we are using a seperate listener */
		prop = axis2_options_get_property(options, env, AXIS2_USE_SEPARATE_LISTENER);
		if (prop)
		{
			prop_val = axutil_property_get_value(prop, env);
			if (prop_val && !axutil_strcmp(prop_val, AXIS2_VALUE_TRUE))
			{
				use_seperate_listnener = AXIS2_TRUE;
			} 
			else if (prop_val && !axutil_strcmp(prop_val, AXIS2_VALUE_FALSE))
			{
				use_seperate_listnener = AXIS2_FALSE;
			}
			else
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Invalid value for %s", 
					AXIS2_UDP_TRANSPORT_IS_MULTICAT);
				return AXIS2_FAILURE;
			}
		}
		/* if we use a seperate listener we need to make sure that the listener is up 
		before sending. So we call the receiver_is_running method to make sure that 
		it is running 
		*/
		if (use_seperate_listnener)
		{
			axis2_transport_in_desc_t *in_desc = NULL;
			axis2_transport_receiver_t *receiver = NULL;
			in_desc = axis2_msg_ctx_get_transport_in_desc(msg_ctx, env);
			if (!in_desc)
			{	
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Transport in protocol cannot be found");
				return AXIS2_FAILURE;
			}
			receiver = axis2_transport_in_desc_get_recv(in_desc, env);
			if (!axis2_transport_receiver_is_running(receiver, env))
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Receiver is not running");
				return AXIS2_FAILURE;
			}
		}
		/* If a socket is not set, create one or get the one set by the receiver. */
		if (sender->socket == AXIS2_INVALID_SOCKET)
		{	
			if (use_seperate_listnener)
			{
				/* if we use a seperate listener, fetch the UDP socket set by the receiver */
				axis2_ctx_t *ctx = NULL;
				axutil_property_t *prop = NULL;
				axis2_udp_backchannel_info_t *binfo = NULL;
				ctx = axis2_conf_ctx_get_base(conf_ctx, env);
				prop = axis2_ctx_get_property(ctx, env, AXIS2_UDP_BACKCHANNEL_INFO);
				if (prop)
				{
					binfo = axutil_property_get_value(prop, env);	
					sender->socket = binfo->socket;		
					sender->owns_socket = AXIS2_FALSE;
					axis2_udp_transport_add_backchannel_info(env, msg_ctx);
				}				
			}
			else
			{
				sender->socket = (int)axutil_network_handler_open_dgram_socket(env);		
			}
		}
		/* If a socket is not set and socket creation failed quit sender. */
		if (sender->socket == AXIS2_INVALID_SOCKET)
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Socket creation failed");
			return AXIS2_FAILURE;
		}		
		/* retreive the back-off algorithm config values */
		if (sender->is_multicast)
		{
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
		/* Check weather we want to send a response */
	    op = axis2_msg_ctx_get_op(msg_ctx, env);	
		if (op)
		{	
			mep_uri = axis2_op_get_msg_exchange_pattern(op, env);
			AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "OP name axutil_qname_get_localpart = %s", mep_uri);
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
			axutil_thread_t *thread = NULL;
			axis2_char_t *addr = (axis2_char_t *)host;
			int source_port = 0;
			/* Send the datagram */
			if (axutil_network_handler_send_dgram(env, sender->socket, buffer, 
				&buffer_size, addr, port, &source_port) == AXIS2_FAILURE)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "UDP packet sending failed.");
				return AXIS2_FAILURE;			
			}
			udp_repeat--;
			/* Generate T */
			srand((unsigned int)time(NULL));			
			T = (rand() % (udp_max_delay - udp_min_delay)) + udp_min_delay;
			/* Start the receiving thread */
			args = AXIS2_MALLOC(env->allocator, sizeof(axis2_udp_transport_sender_args_t));
			if (!args)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "out of memory");
				return AXIS2_FAILURE;
			}
			args->env = axutil_init_thread_env(env);
			args->message_received = AXIS2_FALSE;
			args->recv_buffer = AXIS2_MALLOC(env->allocator, 
				sizeof(axis2_char_t) * sender->max_packet_size);
			if (!args->recv_buffer)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "out of memory");
				return AXIS2_FAILURE;
			}
			args->recv_buff_len = AXIS2_UDP_PACKET_MAX_SIZE;
			args->udp_sender = sender;
			args->mutex = NULL;	
			/* we are creating the listening thread only if use seperate listener is false */
			if (!use_seperate_listnener)
			{
				args->mutex = axutil_thread_mutex_create(env->allocator, 
					AXIS2_THREAD_MUTEX_DEFAULT);
				if (!args->mutex)
				{
					AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Mutex creation failed");
					return AXIS2_FAILURE;
				}
				/* We do a lock which is unlocked by the receiving thread. 
				Unloack happens after it get the response */
				axutil_thread_mutex_lock(args->mutex);							
				thread = axutil_thread_pool_get_thread(env->thread_pool,
														axis2_udp_sender_thread_worker_func,
														(void *) args);
				if (!thread)
				{
					AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed");
					return AXIS2_FAILURE;
				}
				axutil_thread_pool_thread_detach(env->thread_pool, thread);
			}
			/* Sleep */
			AXIS2_USLEEP(T * 1000);
			while (udp_repeat > 0 && !args->message_received)
			{								
				/* send */			
				if (axutil_network_handler_send_dgram(env, sender->socket, buffer, 
					&buffer_size, addr, port, &source_port) == AXIS2_FAILURE)
				{
					AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "UDP packet sending failed.");
					return AXIS2_FAILURE;			
				}
				if (--udp_repeat <= 0)
					break;				
				T = T * 2;
				if (T > udp_upper_delay)
				{
					T = udp_upper_delay;
				}
				AXIS2_USLEEP(T);	
			}			
		}
		if (!use_seperate_listnener)
		{
			/* We should wait until the receiver finishes */
			axutil_thread_mutex_lock(args->mutex);
			axutil_thread_mutex_unlock(args->mutex);
		}
		if (args->message_received && !is_oneway)
		{
			reader = axiom_xml_reader_create_for_memory(env, args->recv_buffer, args->recv_buff_len,
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
    }
	AXIS2_LOG_DEBUG(env->log, AXIS2_LOG_SI, "end: udp transport sender invoke");
    return AXIS2_SUCCESS;	
}

static axis2_status_t AXIS2_CALL
axis2_udp_transport_add_backchannel_info(const axutil_env_t *env, axis2_msg_ctx_t *msg_ctx)
{
	axis2_conf_ctx_t *conf_ctx = NULL;
	axis2_udp_backchannel_info_t *binfo = NULL;
	axis2_svc_t *svc = NULL;
	axis2_op_t *op = NULL;
	axutil_property_t *prop = NULL;
	axis2_ctx_t *ctx = NULL;
	binfo = AXIS2_MALLOC(env->allocator, sizeof(axis2_udp_backchannel_info_t));
	if (!binfo)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Out of memory");
		return AXIS2_FAILURE;
	}
	conf_ctx = axis2_msg_ctx_get_conf_ctx(msg_ctx, env);
	/* We set the axis2_svc and oparation. When the response comes it will bypass the dispatchers 
	   and will directly go the service and operation 
	   */
	ctx = axis2_conf_ctx_get_base(conf_ctx, env);
	prop = axis2_ctx_get_property(ctx, env, AXIS2_UDP_BACKCHANNEL_INFO);
	if (prop)
	{
		binfo = axutil_property_get_value(prop, env);	
		svc = axis2_msg_ctx_get_svc(msg_ctx, env);
		op = axis2_msg_ctx_get_op(msg_ctx, env);
		binfo->op = op;
		binfo->svc = svc;
	}
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

/* This is the function where threads start running */
void *AXIS2_THREAD_FUNC
axis2_udp_sender_thread_worker_func(
    axutil_thread_t * thd,
    void *data)
{
	const axutil_env_t *env = NULL;
	axis2_udp_transport_sender_args_t *args = NULL;
	axis2_udp_transport_sender_impl_t *sender = NULL;

	args = (axis2_udp_transport_sender_args_t *)data;
	sender = args->udp_sender;
	env = args->env;
	axutil_network_handler_set_sock_option(env, sender->socket, SO_RCVTIMEO, sender->time_out);
	if (axutil_network_handler_read_dgram(env, sender->socket, args->recv_buffer, 
		&args->recv_buff_len, NULL, NULL) != AXIS2_FAILURE)
	{
		args->message_received = AXIS2_TRUE;
	}
	else
	{
		args->message_received = AXIS2_FALSE;
	}
	/* Unlock the thread mutex */
	axutil_thread_mutex_unlock(args->mutex);
	return NULL;
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
    *inst = axis2_udp_ender_create(env);
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

