
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
#include <axis2_udp_receiver.h>
#include <axis2_transport_receiver.h>
#include <axis2_transport_in_desc.h>
#include <axutil_param_container.h>
#include <axutil_url.h>
#include <axis2_conf_init.h>
#include <stdlib.h>
#include <axiom.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap.h>
#include <axis2_engine.h>
#include <axutil_thread.h>

#define AXIS2_DEFAULT_HOST_ADDRESS "127.0.0.1"
#define AXIS2_DEFAULT_SVC_PATH "/axis2/services/"

/* UDP Receiver */
typedef struct axis2_udp_receiver_impl
{
    axis2_transport_receiver_t udp_receiver; 
	/* receiver will run until this is false */
	axis2_bool_t stop;
	/* configuration context */
    axis2_conf_ctx_t *conf_ctx;
    axis2_conf_ctx_t *conf_ctx_private;
	/* listening port */
	int port;
	/* socket to receive */
	axis2_socket_t socket;
	/* socket to send */
	axis2_socket_t send_socket;
	/* mutex to control sequential execution in dual channel */
	axutil_thread_mutex_t *mutex;
	/* if this is true receiver should close the socket */
	axis2_bool_t owns_socket;
	/* multicast properties */
	axis2_bool_t is_multicast;
	/* multicast group that this receiver listen */
	axis2_char_t *multicast_group;
	/* maximum packet size */
	axis2_bool_t max_packet_size;
} axis2_udp_receiver_impl_t;

/* This structure is used to hold information about a udp request */
typedef struct 
{
	axis2_char_t * buff;
	int buf_size;
	axis2_svc_t *svc;
	axis2_op_t *op;
} axis2_udp_request_t;

/* This structure is used to hold information about a udp response */
typedef struct 
{
	axis2_char_t *buff;
	int buf_size;
} axis2_udp_response_t;

typedef struct axis2_udp_recv_thd_args
{
    axutil_env_t *env;
    axis2_socket_t socket;
	axis2_socket_t send_socket;
	axis2_conf_ctx_t *conf_ctx;
	axis2_char_t *req_addr;
	int req_port;
	axis2_udp_request_t request;
	axis2_bool_t is_multicast;
} axis2_udp_recv_thd_args_t;

#define AXIS2_INTF_TO_IMPL(udp_receiver) ((axis2_udp_receiver_impl_t *)(udp_receiver))

void AXIS2_CALL
axis2_udp_receiver_free(
    axis2_transport_receiver_t * trn_receiver,
    const axutil_env_t * env);

axis2_status_t AXIS2_CALL
axis2_udp_receiver_init(
    axis2_transport_receiver_t * tr_receiver,
    const axutil_env_t * env,
    axis2_conf_ctx_t * conf_ctx,
    axis2_transport_in_desc_t * in_desc);

axis2_status_t AXIS2_CALL
axis2_udp_receiver_start(
    axis2_transport_receiver_t *tr_receiver,
    const axutil_env_t * env);

axis2_conf_ctx_t *AXIS2_CALL
axis2_udp_receiver_get_conf_ctx(
	axis2_transport_receiver_t * tr_receiver, 
	const axutil_env_t * env);

axis2_endpoint_ref_t *AXIS2_CALL
axis2_udp_receiver_get_reply_to_epr(
    axis2_transport_receiver_t * receiver,
    const axutil_env_t * env,
    const axis2_char_t * svc_name);

axis2_bool_t AXIS2_CALL
axis2_udp_receiver_is_running(
    axis2_transport_receiver_t * tr_receiver,
    const axutil_env_t * env);

void *AXIS2_THREAD_FUNC
axis2_udp_receiver_thread_worker_func(
    axutil_thread_t * thd,
    void *data);

AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_udp_receiver_process_request(
	const axutil_env_t * env,
	axis2_conf_ctx_t *conf_ctx,    
    axis2_udp_request_t * request,
	axis2_udp_response_t * responce);

void *AXIS2_THREAD_FUNC
axis2_udp_receiver_thread_worker_func(
    axutil_thread_t * thd,
    void *data);

static axis2_status_t AXIS2_CALL
axis2_udp_transport_add_backchannel_info(
	const axutil_env_t *env, 
	axis2_ctx_t *ctx, 
	axis2_socket_t socket);

static const axis2_transport_receiver_ops_t udp_transport_recvr_ops = {
    axis2_udp_receiver_init,
    axis2_udp_receiver_start,
    axis2_udp_receiver_get_reply_to_epr,
    axis2_udp_receiver_get_conf_ctx,
    axis2_udp_receiver_is_running,
    axis2_udp_receiver_stop,
    axis2_udp_receiver_free
};


AXIS2_EXTERN axis2_transport_receiver_t *AXIS2_CALL
axis2_udp_receiver_create(
    const axutil_env_t * env,
    const axis2_char_t * repo,
    const int port,
	axis2_char_t *multicast_group)
{
	axis2_udp_receiver_impl_t *receiver = NULL;

	receiver = (axis2_udp_receiver_impl_t *) AXIS2_MALLOC(env->allocator, sizeof(axis2_udp_receiver_impl_t));
	if (!receiver)
	{
		AXIS2_HANDLE_ERROR(env, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}
	receiver->is_multicast = AXIS2_FALSE;
	receiver->conf_ctx = NULL;
	receiver->conf_ctx_private = NULL;
	receiver->port = port;
	receiver->udp_receiver.ops = &udp_transport_recvr_ops;
	receiver->multicast_group = multicast_group; 
	receiver->socket = AXIS2_INVALID_SOCKET;
	receiver->send_socket = AXIS2_INVALID_SOCKET;
	receiver->owns_socket = AXIS2_TRUE;
	receiver->max_packet_size = AXIS2_UDP_PACKET_MAX_SIZE;
	if (multicast_group)
	{
		receiver->is_multicast = AXIS2_TRUE;
	}
	receiver->mutex = axutil_thread_mutex_create(env->allocator,
                                                 AXIS2_THREAD_MUTEX_DEFAULT);
	/* 
	 * We are creating the receiver in two instances. When we create the receiver from the server 
	 * we create the conf context. If we are creating the receiver while creating the conf we are 
	 * not creating the conf as conf is already there.
	 */
	if (repo)
	{
		receiver->conf_ctx_private = axis2_build_conf_ctx(env, repo);
		if (!receiver->conf_ctx_private)
		{
			AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, 
                             "unable to create private configuration context for repo path %s", repo);
            axis2_udp_receiver_free((axis2_transport_receiver_t *) receiver,
                                   env);
            return NULL;
		}
		receiver->conf_ctx = receiver->conf_ctx_private;
	}
	axutil_thread_mutex_lock(receiver->mutex);
	return &(receiver->udp_receiver);
}

AXIS2_EXTERN axis2_transport_receiver_t *AXIS2_CALL
axis2_udp_receiver_create_with_file(
	const axutil_env_t * env,
	const axis2_char_t * file,
	const int port)
{
	axis2_udp_receiver_impl_t *receiver = NULL;

	receiver = (axis2_udp_receiver_impl_t *) AXIS2_MALLOC(env->allocator, sizeof(axis2_udp_receiver_impl_t));
	if (!receiver)
	{
		AXIS2_HANDLE_ERROR(env, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
		return NULL;
	}

	receiver->conf_ctx = NULL;
	receiver->conf_ctx_private = NULL;
	receiver->port = port;
	receiver->udp_receiver.ops = &udp_transport_recvr_ops;
	receiver->multicast_group = NULL; 
	receiver->socket = AXIS2_INVALID_SOCKET;
	receiver->send_socket = AXIS2_INVALID_SOCKET;
	receiver->owns_socket = AXIS2_TRUE;
	receiver->mutex = axutil_thread_mutex_create(env->allocator,
                                                 AXIS2_THREAD_MUTEX_DEFAULT);
	receiver->max_packet_size = AXIS2_UDP_PACKET_MAX_SIZE;
	/* 
	 * We are creating the receiver in two instances. When we create the receiver from the server 
	 * we create the conf context. If we are creating the receiver while creating the conf we are 
	 * not creating the conf as conf is already there.
	 */
	if (file)
	{
		receiver->conf_ctx_private = axis2_build_conf_ctx_with_file(env, file);
		if (!receiver->conf_ctx_private)
		{
			AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, 
                             "unable to create private configuration context for repo path %s", file);
            axis2_udp_receiver_free((axis2_transport_receiver_t *) receiver,
                                   env);
            return NULL;
		}
		receiver->conf_ctx = receiver->conf_ctx_private;
	}
	return &(receiver->udp_receiver);
}

void AXIS2_CALL
axis2_udp_receiver_free(
    axis2_transport_receiver_t * trn_receiver,
    const axutil_env_t * env)
{
	axis2_udp_receiver_impl_t * receiver = NULL;
	receiver = AXIS2_INTF_TO_IMPL(trn_receiver);
	if (!receiver)
	{
        AXIS2_LOG_ERROR (env->log, AXIS2_LOG_SI, 
                         "failure, receiver value is null , nothing to free");
        return;
	}	
	if (!receiver->stop)
	{
		receiver->stop = AXIS2_TRUE;
	}
	/* We do not free the conf_ctx as this is not the right place to do it */
	receiver->conf_ctx = NULL;
	/* Close the sockets */
	if (receiver->send_socket != AXIS2_INVALID_SOCKET)
	{
		axutil_network_handler_close_socket(env, receiver->send_socket);
	}
	/* we free this socket only if we owns it */
	if (receiver->owns_socket && receiver->socket != AXIS2_INVALID_SOCKET)
	{
		axutil_network_handler_close_socket(env, receiver->socket);
	}
	if (receiver->mutex)
	{
		axutil_thread_mutex_destroy(receiver->mutex);
	}
	AXIS2_FREE(env->allocator, receiver);
}


axis2_status_t AXIS2_CALL
axis2_udp_receiver_init(
    axis2_transport_receiver_t * tr_receiver,
    const axutil_env_t * env,
    axis2_conf_ctx_t * conf_ctx,
    axis2_transport_in_desc_t * in_desc)
{
	axis2_udp_receiver_impl_t *receiver = NULL;
	axis2_char_t *str = NULL;
	axutil_param_t *param = NULL;
	axutil_param_container_t *container = NULL;

	receiver = AXIS2_INTF_TO_IMPL(tr_receiver);
	receiver->conf_ctx = conf_ctx;
	container = axis2_transport_in_desc_param_container(in_desc, env);

	/* Get the port */
	param = (axutil_param_t *) axutil_param_container_get_param(container, env, AXIS2_PORT_STRING);	
	if (param)
	{
		str = (axis2_char_t *)axutil_param_get_value(param, env);
		if (str)
		{
			receiver->port = atoi(str);
		}
	}
	
	/* Get the multicast group */
	param = (axutil_param_t *) axutil_param_container_get_param(container, env, 
		AXIS2_UDP_TRANSPORT_MULTICAST_GROUP);
	if (param)
	{
		receiver->multicast_group = (axis2_char_t *)axutil_param_get_value(param, env);
		receiver->is_multicast = AXIS2_TRUE;
	}
	/* Get the max packet size */
	param = (axutil_param_t *) axutil_param_container_get_param(container, env, 
		AXIS2_UDP_TRANSPORT_MAX_PACKET_SIZE_STR);
	if (param)
	{
		str = (axis2_char_t *)axutil_param_get_value(param, env);
		if (str)
		{
			receiver->max_packet_size = atoi(str);
		} 	
	}
	return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
axis2_udp_receiver_start(
    axis2_transport_receiver_t *tr_receiver,
    const axutil_env_t * env)
{
	axis2_status_t status;
	axis2_udp_receiver_impl_t *receiver = NULL;

	receiver = AXIS2_INTF_TO_IMPL(tr_receiver);

	AXIS2_LOG_INFO(env->log, "Started the UDP server");
	if (receiver->socket == AXIS2_INVALID_SOCKET)
	{
		/* socket not set, we should create one */
		if (receiver->is_multicast && receiver->multicast_group)
		{
			/* Setup a socket to receive multicast packets */
			receiver->socket = axutil_network_hadler_create_multicast_svr_socket(
				env, receiver->port, receiver->multicast_group);		
		}
		else
		{
			axis2_ctx_t *ctx = NULL;
			/* Setup a socket to receive unicast packets */
			receiver->socket = axutil_network_handler_create_dgram_svr_socket(
				env, receiver->port);
			receiver->owns_socket = AXIS2_TRUE; 
			/* bind the socket to a unique address */
			/*axutil_network_handler_bind_socket(env, receiver->socket, 0);*/
			ctx = axis2_conf_ctx_get_base(receiver->conf_ctx, env);
			axis2_udp_transport_add_backchannel_info(env, ctx, receiver->socket);
		}
		receiver->owns_socket = AXIS2_TRUE;
	}
	if (receiver->socket == AXIS2_INVALID_SOCKET)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Socket creation faild on socket");
		return AXIS2_FAILURE;
	}

	/* We are using a seperate socket to send the request */
	receiver->send_socket = axutil_network_handler_open_dgram_socket(env);
	if (receiver->send_socket == AXIS2_INVALID_SOCKET)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Socket creation faild on socket");
		return AXIS2_FAILURE;
	}
	receiver->stop =  AXIS2_FALSE;
	axutil_thread_mutex_unlock(receiver->mutex);
	while (!receiver->stop)
	{
		axis2_udp_recv_thd_args_t *args = NULL;
		axutil_thread_t *worker_thread = NULL;
		axis2_char_t *addr = NULL;
		int port = receiver->port;		
		int buf_len = AXIS2_UDP_PACKET_MAX_SIZE;
		axis2_char_t *in_buff = NULL;

		in_buff = AXIS2_MALLOC(env->allocator, sizeof(char) * receiver->max_packet_size);
		/* This is a blocking call. This will block until data is available in the socket */
		status = axutil_network_handler_read_dgram(env, receiver->socket, in_buff, &buf_len, &addr, &port);   
		if (status == AXIS2_FAILURE)
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error in reading data from the datagram.");
			return AXIS2_FAILURE;
		}	

		args = (axis2_udp_recv_thd_args_t *)AXIS2_MALLOC(env->allocator, sizeof(axis2_udp_recv_thd_args_t));		
		if (!args)
		{
			AXIS2_HANDLE_ERROR(env, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
			return AXIS2_FAILURE;
		}
		/* Set the data required by the thread */
		args->env = axutil_init_thread_env(env);
		args->socket = receiver->socket;
		args->send_socket = receiver->send_socket;
		args->conf_ctx = receiver->conf_ctx;
		args->req_addr = addr;
		args->req_port = port;
		args->request.buff = in_buff;
		args->request.buf_size = buf_len;
		args->request.op = NULL;
		args->request.svc = NULL;
		args->is_multicast = receiver->is_multicast;
#ifdef AXIS2_SVR_MULTI_THREADED
		worker_thread = axutil_thread_pool_get_thread(env->thread_pool,
													axis2_udp_receiver_thread_worker_func,
													(void *) args);
		if (!worker_thread)
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed"
							"server thread loop");
			continue;
		}
		axutil_thread_pool_thread_detach(env->thread_pool, worker_thread);
#else
		axis2_udp_receiver_thread_worker_func(NULL, (void *)args);
#endif
	}
	return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_udp_receiver_stop(
    axis2_transport_receiver_t * tr_receiver,
    const axutil_env_t * env)
{
	axis2_udp_receiver_impl_t *receiver = NULL;
	receiver = AXIS2_INTF_TO_IMPL(tr_receiver);	
	receiver->stop = AXIS2_TRUE;
	return AXIS2_SUCCESS;
}

axis2_conf_ctx_t *AXIS2_CALL
axis2_udp_receiver_get_conf_ctx(axis2_transport_receiver_t * tr_receiver, 
								const axutil_env_t * env)
{
	axis2_udp_receiver_impl_t *receiver = NULL;
	receiver = AXIS2_INTF_TO_IMPL(tr_receiver);	
	return receiver->conf_ctx;
}

axis2_endpoint_ref_t *AXIS2_CALL
axis2_udp_receiver_get_reply_to_epr(
    axis2_transport_receiver_t * receiver,
    const axutil_env_t * env,
    const axis2_char_t * svc_name)
{
	axis2_endpoint_ref_t *epr = NULL;
    const axis2_char_t *host_address = NULL;
    axis2_char_t *svc_path = NULL;
    axutil_url_t *url = NULL;

    AXIS2_PARAM_CHECK(env->error, svc_name, NULL);
    AXIS2_PARAM_CHECK(env->error, receiver, NULL);

    host_address = AXIS2_DEFAULT_HOST_ADDRESS; /* TODO : get from axis2.xml */
    svc_path = axutil_stracat(env, AXIS2_DEFAULT_SVC_PATH, svc_name);
    url = axutil_url_create(env, "soap.udp", host_address,
                            AXIS2_INTF_TO_IMPL(receiver)->port, svc_path);
    AXIS2_FREE(env->allocator, svc_path);
    if (!url)
    {
        return NULL;
    }
    epr = axis2_endpoint_ref_create(env, axutil_url_to_external_form(url, env));
    axutil_url_free(url, env);
    return epr;
}

axis2_bool_t AXIS2_CALL
axis2_udp_receiver_is_running(
    axis2_transport_receiver_t * tr_receiver,
    const axutil_env_t * env)
{
	axis2_bool_t running = AXIS2_FALSE;
	axis2_udp_receiver_impl_t *receiver = NULL;
	receiver = AXIS2_INTF_TO_IMPL(tr_receiver);	
	axutil_thread_mutex_lock(receiver->mutex);
	running = !receiver->stop;
	axutil_thread_mutex_unlock(receiver->mutex);
	return running;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
axis2_udp_receiver_set_socket(
    axis2_transport_receiver_t * tr_receiver,
    const axutil_env_t * env,
	axis2_socket_t socket)
{
	axis2_udp_receiver_impl_t *receiver = NULL;
	receiver = AXIS2_INTF_TO_IMPL(tr_receiver);	
	/* If we already have a socket free it */
	if (receiver->socket== AXIS2_INVALID_SOCKET)
	{
		receiver->socket = socket;
		receiver->owns_socket = AXIS2_FALSE;
		return AXIS2_SUCCESS;
	}	
	return AXIS2_FAILURE;	
}

/* This is the function where threads start running */
void *AXIS2_THREAD_FUNC
axis2_udp_receiver_thread_worker_func(
    axutil_thread_t * thd,
    void *data)
{
	const axutil_env_t *env = NULL;
	axis2_status_t status = AXIS2_FAILURE;
	axis2_conf_t *conf = NULL;
	axis2_svc_t *svc = NULL;
	axis2_udp_recv_thd_args_t *args = NULL;
	axis2_udp_response_t response;
	axutil_hash_index_t *hi = NULL;
	axutil_hash_t *ori_all_svcs = NULL, *all_svcs = NULL;
	void *val = NULL;
	
	args = (axis2_udp_recv_thd_args_t *) data;
	env = (axutil_env_t *) args->env;	

	conf = axis2_conf_ctx_get_conf(args->conf_ctx, env);
	/* Get all the service discriptions */
	ori_all_svcs = axis2_conf_get_all_svcs(conf, env);
	if (!ori_all_svcs)
	{
		return NULL;
	}
	all_svcs = axutil_hash_copy(ori_all_svcs, env);	
	if (args->is_multicast)
	{
	/* If multicast we go through every service and try to figure out weather they are 
	   accepting multicast messages. If a service accepts a multicast message we send the 
	   request to that service bypassing the normal dispatchers. Dispatchers cannot be 
	   used since no dispatching information is found in the multicast messages 
	*/
    for (hi = axutil_hash_first(all_svcs, env); hi;
         hi = axutil_hash_next(env, hi))
    {		
        axutil_hash_this(hi, NULL, NULL, &val);
        svc = (axis2_svc_t *) val;
        if (svc)
        {
			axutil_param_t *param = NULL;
			axis2_char_t *param_val = NULL;
			/* Get the Multicast accept parameter from the services.xml */
            param = axis2_svc_get_param(svc, env, AXIS2_UDP_MULTICAST_ACCEPT);
			if (!param) 
			{
				continue;
			}
			/* check weather this service accepts multicast requests */
			param_val = axutil_param_get_value(param, env);
			if (!param_val || !axutil_strcmp(param_val, "false") || axutil_strcmp(param_val, "true"))
			{
				continue;
			}
			
			response.buf_size = 0;
			response.buff = NULL;

			/* set the service to the request. This will bypass the dispatches */
			args->request.svc = svc;
			/* Process the request */
			status = axis2_udp_receiver_process_request(args->env, args->conf_ctx, 
															&args->request, &response);
			if (status == AXIS2_FAILURE)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error processing the request.");
				return NULL;
			}

			/* If we have a response send it */
			if (response.buff)
			{
				status = axutil_network_handler_send_dgram(env, args->send_socket, 
													response.buff, &response.buf_size, 
													args->req_addr, args->req_port, NULL);
				if (status == AXIS2_FAILURE)
				{
					AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error sending the response.");
					return NULL;
				}
			}
		}
	}
	}
	else
	{
		axis2_ctx_t *ctx = NULL;
		axutil_property_t *prop = NULL;
		axis2_udp_backchannel_info_t *binfo = NULL;

		ctx = axis2_conf_ctx_get_base(args->conf_ctx, env);
		prop = axis2_ctx_get_property(ctx, env, AXIS2_UDP_BACKCHANNEL_INFO);
		if (prop)
		{
			binfo = axutil_property_get_value(prop, env);
		}
		/* Unicast case. In this case message contains dispatching information. 
		 * So we send the request in the normal way 
		 */
		response.buf_size = 0;
		response.buff = NULL;
		if (binfo)
		{
			args->request.svc = binfo->svc;
			args->request.op = binfo->op;
		}
		
		/* Process the request */
		status = axis2_udp_receiver_process_request(args->env, args->conf_ctx, 
														&args->request, &response);
		if (status == AXIS2_FAILURE)
		{
			AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error processing the request.");
			return NULL;
		}

		/* If we have a response send it */
		if (response.buff)
		{
			status = axutil_network_handler_send_dgram(env, args->send_socket, 
												response.buff, &response.buf_size, 
												args->req_addr, args->req_port, NULL);
			if (status == AXIS2_FAILURE)
			{
				AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error sending the response.");
				return NULL;
			}
		}
	}
	return NULL;
}

/* Process a request. If the request has a response the response structure will be populated */
AXIS2_EXTERN axis2_bool_t AXIS2_CALL
axis2_udp_receiver_process_request(
	const axutil_env_t * env,
	axis2_conf_ctx_t *conf_ctx,    
    axis2_udp_request_t * request,
	axis2_udp_response_t * responce)
{   
    axis2_transport_out_desc_t *out_desc = NULL;
    axis2_transport_in_desc_t *in_desc = NULL;
    axis2_msg_ctx_t *msg_ctx = NULL;
    axiom_xml_reader_t *reader = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_soap_builder_t *soap_builder = NULL;
    axiom_soap_envelope_t *soap_envelope = NULL;
    axis2_engine_t *engine = NULL;
    axis2_status_t status = AXIS2_FALSE;
    axutil_stream_t *out_stream = NULL;

    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI,
                    "start:axis2_udp_worker_process_request");

    if (!conf_ctx)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "conf ctx not available");
        return AXIS2_FAILURE;
    }

    out_stream = axutil_stream_create_basic(env);
    reader = axiom_xml_reader_create_for_memory(env, request->buff,
                                                request->buf_size,
                                                NULL,
                                                AXIS2_XML_PARSER_TYPE_BUFFER);
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

    out_desc =
        axis2_conf_get_transport_out(axis2_conf_ctx_get_conf(conf_ctx, env),
                                     env, AXIS2_TRANSPORT_ENUM_UDP);
    if (!out_desc)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Transport out not set");
        return AXIS2_FAILURE;
    }

    in_desc =
        axis2_conf_get_transport_in(axis2_conf_ctx_get_conf(conf_ctx, env), env,
                                    AXIS2_TRANSPORT_ENUM_UDP);

    msg_ctx = axis2_msg_ctx_create(env, conf_ctx, in_desc, out_desc);
    axis2_msg_ctx_set_server_side(msg_ctx, env, AXIS2_TRUE);
    axis2_msg_ctx_set_transport_out_stream(msg_ctx, env, out_stream);

    soap_envelope = axiom_soap_builder_get_soap_envelope(soap_builder, env);
    axis2_msg_ctx_set_soap_envelope(msg_ctx, env, soap_envelope);
	if (request->svc)
	{
		axis2_msg_ctx_set_svc(msg_ctx, env, request->svc);
	}
	if (request->op)
	{
		axis2_msg_ctx_set_op(msg_ctx, env, request->op);	
	}
    engine = axis2_engine_create(env, conf_ctx);
    status = axis2_engine_receive(engine, env, msg_ctx);

    responce->buff = axutil_stream_get_buffer(out_stream, env);
	responce->buf_size = axutil_stream_get_len(out_stream, env);
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI,
                    "end:axis2_udp_worker_process_request");
    return AXIS2_SUCCESS;
}

static axis2_status_t AXIS2_CALL
axis2_udp_transport_add_backchannel_info(const axutil_env_t *env, axis2_ctx_t *ctx, axis2_socket_t socket)
{
	axis2_udp_backchannel_info_t *binfo = NULL;
	axutil_property_t *prop = NULL;
	binfo = AXIS2_MALLOC(env->allocator, sizeof(axis2_udp_backchannel_info_t));
	if (!binfo)
	{
		AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Out of memory");
		return AXIS2_FAILURE;
	}
	/* We set the axis2_svc and oparation. When the response comes it will bypass the dispatchers 
	   and will directly go the service and operation 
	   */
	binfo->op = NULL;
	binfo->svc = NULL;
	binfo->socket = socket;
	prop = axutil_property_create(env);
	axutil_property_set_value(prop, env, binfo);
	axis2_ctx_set_property(ctx, env, AXIS2_UDP_BACKCHANNEL_INFO, prop);
	return AXIS2_SUCCESS;
}


/**
 * Following block distinguish the exposed part of the dll.
 */
AXIS2_EXPORT int
axis2_get_instance(
    struct axis2_transport_receiver **inst,
    const axutil_env_t * env)
{
    *inst = axis2_udp_receiver_create(env, NULL, 0, NULL);
    if (!(*inst))
    {
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXPORT int
axis2_remove_instance(
    axis2_transport_receiver_t * inst,
    const axutil_env_t * env)
{
    if (inst)
    {
        axis2_transport_receiver_free(inst, env);
    }
    return AXIS2_SUCCESS;
}



