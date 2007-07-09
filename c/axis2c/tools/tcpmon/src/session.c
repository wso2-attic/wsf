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

#include <stdio.h>
#include <axutil_string.h>
#include <axutil_utils.h>
#include <axutil_error.h>
#include <tcpmon_util.h>
#include <axutil_thread.h>
#include <axutil_network_handler.h>
#include <axutil_array_list.h>

#include "tcpmon_session_local.h"
#include "tcpmon_entry_local.h"

/**
 * @brief
 */
typedef struct tcpmon_session_impl
{
    tcpmon_session_t session;
    int listen_port;
    int target_port;
	int test_bit;
    int format_bit;
    axis2_char_t *target_host;
    TCPMON_SESSION_NEW_ENTRY_FUNCT on_new_entry_funct;
    TCPMON_SESSION_TRANS_ERROR_FUNCT on_trans_fault_funct;
    axutil_array_list_t* entries;

    axis2_bool_t is_running;
}
tcpmon_session_impl_t;

typedef struct tcpmon_session_server_thread_data
{
    tcpmon_session_impl_t* session_impl;
    const axutil_env_t* env;
}
tcpmon_session_server_thread_data_t;

#define AXIS2_INTF_TO_IMPL(session) \
    ((tcpmon_session_impl_t *) session)

/************************* Function prototypes ********************************/

axis2_status_t AXIS2_CALL
tcpmon_session_free(tcpmon_session_t *session,
        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
tcpmon_session_set_listen_port(tcpmon_session_t *session,
        const axutil_env_t *env,
        int listen_port);

int AXIS2_CALL
tcpmon_session_get_listen_port(tcpmon_session_t *session,
        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
tcpmon_session_set_target_port(tcpmon_session_t *session,
        const axutil_env_t *env,
        int target_port);

int AXIS2_CALL
tcpmon_session_get_target_port(tcpmon_session_t *session,
        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
tcpmon_session_set_target_host(tcpmon_session_t *session,
        const axutil_env_t *env,
        axis2_char_t* target_host);

axis2_char_t* AXIS2_CALL
tcpmon_session_get_target_host(tcpmon_session_t *session,
        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
tcpmon_session_start(tcpmon_session_t *session,
        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
tcpmon_session_stop(tcpmon_session_t *session,
        const axutil_env_t *env);

axis2_status_t AXIS2_CALL
tcpmon_session_on_new_entry(tcpmon_session_t *session,
        const axutil_env_t *env,
        TCPMON_SESSION_NEW_ENTRY_FUNCT on_new_entry_funct);

axis2_status_t AXIS2_CALL
tcpmon_session_on_trans_fault(tcpmon_session_t *session,
        const axutil_env_t *env,
        TCPMON_SESSION_TRANS_ERROR_FUNCT on_trans_fault_funct);

int AXIS2_CALL
tcpmon_session_get_test_bit (tcpmon_session_t *session,
									  const axutil_env_t *env);

int AXIS2_CALL
tcpmon_session_set_test_bit (tcpmon_session_t *session,
									  const axutil_env_t *env,
									  int test_bit);

int AXIS2_CALL
tcpmon_session_get_format_bit (tcpmon_session_t *session,
                                      const axutil_env_t *env);
                                      
int AXIS2_CALL 
tcpmon_session_set_format_bit(tcpmon_session_t *session,
                                      const axutil_env_t *env,
                                      int format_bit);

/** internal implementations */

void * AXIS2_THREAD_FUNC
server_funct(axutil_thread_t *thd, void *data);

/************************** End of function prototypes ************************/

tcpmon_session_t * AXIS2_CALL
tcpmon_session_create(const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    session_impl = (tcpmon_session_impl_t *) AXIS2_MALLOC(env->
            allocator, sizeof(tcpmon_session_impl_t));

    if (! session_impl)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }

    session_impl -> listen_port = -1;
    session_impl -> target_port = -1;
	 session_impl->test_bit = -1;
     session_impl->format_bit = 0;
    session_impl -> target_host = NULL;

    session_impl -> on_new_entry_funct = NULL;
    session_impl -> on_trans_fault_funct = NULL;
    session_impl -> entries = axutil_array_list_create(env, AXIS2_ARRAY_LIST_DEFAULT_CAPACITY);

    session_impl->session.ops =
        AXIS2_MALLOC(env->allocator, sizeof(tcpmon_session_ops_t));
    if (! session_impl->session.ops)
    {
        tcpmon_session_free(&(session_impl->session), env);
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    
    session_impl-> is_running = AXIS2_FALSE;
    session_impl->session.ops->free = tcpmon_session_free;
    session_impl->session.ops->set_test_bit = tcpmon_session_set_test_bit;
    session_impl->session.ops->get_test_bit = tcpmon_session_get_test_bit;
    session_impl->session.ops->get_format_bit = tcpmon_session_get_format_bit;
    session_impl->session.ops->set_format_bit = tcpmon_session_set_format_bit;
    session_impl->session.ops->set_listen_port = tcpmon_session_set_listen_port;
    session_impl->session.ops->get_listen_port = tcpmon_session_get_listen_port;
    session_impl->session.ops->set_target_port = tcpmon_session_set_target_port;
    session_impl->session.ops->get_target_port = tcpmon_session_get_target_port;
    session_impl->session.ops->set_target_host = tcpmon_session_set_target_host;
    session_impl->session.ops->get_target_host = tcpmon_session_get_target_host;
    session_impl->session.ops->start = tcpmon_session_start;
    session_impl->session.ops->stop = tcpmon_session_stop;
    session_impl->session.ops->on_new_entry = tcpmon_session_on_new_entry;
    session_impl->session.ops->on_trans_fault = tcpmon_session_on_trans_fault;

    return &(session_impl->session);
}


/***************************Function implementation****************************/

axis2_status_t AXIS2_CALL
tcpmon_session_free(tcpmon_session_t *session,
        const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;
    int entries_size = 0;
    tcpmon_entry_t* entry = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    for (entries_size = axutil_array_list_size(session_impl-> entries, env) - 1;
            entries_size >= 0; entries_size --)
    {
        TCPMON_ENTRY_FREE(entry, env);
    }
    axutil_array_list_free(session_impl-> entries, env);

    if (session->ops)
    {
        AXIS2_FREE(env->allocator, session->ops);
        session->ops = NULL;
    }

    if (session_impl->target_host)
    {
        AXIS2_FREE(env-> allocator, session_impl->target_host);
        session_impl-> target_host = NULL;
    }

    if (session_impl)
    {
        AXIS2_FREE(env->allocator, session_impl);
        session_impl = NULL;
    }

    return AXIS2_SUCCESS;
}


axis2_status_t AXIS2_CALL
tcpmon_session_set_test_bit (tcpmon_session_t *session,
									  const axutil_env_t *env,
									  int test_bit)
{
	 tcpmon_session_impl_t *session_impl = NULL;

	 AXIS2_ENV_CHECK (env, AXIS2_FAILURE);

	 session_impl = AXIS2_INTF_TO_IMPL (session);
	 session_impl -> test_bit = test_bit;
	 return AXIS2_SUCCESS;
}


int AXIS2_CALL
tcpmon_session_get_test_bit (tcpmon_session_t *session,
									  const axutil_env_t *env)
{
	 tcpmon_session_impl_t *session_impl = NULL;

	 AXIS2_ENV_CHECK (env, AXIS2_FAILURE);

	 session_impl = AXIS2_INTF_TO_IMPL (session);

	 return session_impl->test_bit;
}

axis2_status_t AXIS2_CALL
tcpmon_session_set_format_bit (tcpmon_session_t *session,
                                     const axutil_env_t *env,
                                     int format_bit)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK (env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    session_impl->format_bit = format_bit;

    return AXIS2_SUCCESS;
}

int AXIS2_CALL
tcpmon_session_get_format_bit (tcpmon_session_t *session,
                                     const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK (env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    return session_impl->format_bit;
}

axis2_status_t AXIS2_CALL
tcpmon_session_set_listen_port(tcpmon_session_t *session,
        const axutil_env_t *env,
        int listen_port)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    session_impl-> listen_port = listen_port;
    return AXIS2_SUCCESS;
}

int AXIS2_CALL
tcpmon_session_get_listen_port(tcpmon_session_t *session,
        const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, -1);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    return session_impl-> listen_port;
}

axis2_status_t AXIS2_CALL
tcpmon_session_set_target_port(tcpmon_session_t *session,
        const axutil_env_t *env,
        int target_port)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    session_impl-> target_port = target_port;
    return AXIS2_SUCCESS;
}

int AXIS2_CALL
tcpmon_session_get_target_port(tcpmon_session_t *session,
        const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, -1);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    return session_impl-> target_port;
}

axis2_status_t AXIS2_CALL
tcpmon_session_set_target_host(tcpmon_session_t *session,
        const axutil_env_t *env,
        axis2_char_t* target_host)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    session_impl-> target_host = (axis2_char_t*)axutil_strdup(env, target_host);
    return AXIS2_SUCCESS;
}

axis2_char_t* AXIS2_CALL
tcpmon_session_get_target_host(tcpmon_session_t *session,
        const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, NULL);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    return session_impl-> target_host;
}

axis2_status_t AXIS2_CALL
tcpmon_session_start(tcpmon_session_t *session,
        const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;
    axutil_thread_t* server_thread = NULL;
    tcpmon_session_server_thread_data_t* thread_data = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    thread_data = (tcpmon_session_server_thread_data_t*) AXIS2_MALLOC(
                env-> allocator, sizeof(tcpmon_session_server_thread_data_t));
    thread_data-> session_impl = session_impl;
    thread_data-> env = env;

    session_impl-> is_running = AXIS2_TRUE;
    server_thread = axutil_thread_pool_get_thread(env->thread_pool,
            server_funct, (void*)thread_data);
    if (! server_thread)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed"
                "server thread");
        if (session_impl->on_trans_fault_funct)
        {
            (session_impl->on_trans_fault_funct)(env,
                    "error in creating the server thread");
        }
    }

    axutil_thread_pool_thread_detach(env->thread_pool, server_thread);
    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
tcpmon_session_stop(tcpmon_session_t *session,
        const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);
    session_impl-> is_running = AXIS2_FALSE;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
tcpmon_session_on_new_entry(tcpmon_session_t *session,
        const axutil_env_t *env,
        TCPMON_SESSION_NEW_ENTRY_FUNCT on_new_entry_funct)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    session_impl-> on_new_entry_funct = on_new_entry_funct;

    return AXIS2_SUCCESS;
}

axis2_status_t AXIS2_CALL
tcpmon_session_on_trans_fault(tcpmon_session_t *session,
        const axutil_env_t *env,
        TCPMON_SESSION_TRANS_ERROR_FUNCT on_trans_fault_funct)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    session_impl-> on_trans_fault_funct = on_trans_fault_funct;
    return AXIS2_SUCCESS;
}


/** internal implementations */
void * AXIS2_THREAD_FUNC
server_funct(axutil_thread_t *thd, void *data)
{
    tcpmon_session_server_thread_data_t* thread_data = data;
    tcpmon_session_impl_t *session_impl = NULL;
    const axutil_env_t* env = NULL;
    int listen_socket = -1;
    int socket = -1;
    axutil_thread_t* request_thread = NULL;
    tcpmon_entry_request_data_t* request_thread_data = NULL;

    session_impl = thread_data -> session_impl;
    env = thread_data -> env;

    listen_socket = axutil_network_handler_create_server_socket
            (env, session_impl->listen_port);
    if (-1 == listen_socket)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI,
                "error in creating the server socket, "
                "port may be already occupied",
                "create socket");
        if (session_impl->on_trans_fault_funct)
        {
            (session_impl->on_trans_fault_funct)(env,
                    "error in creating the server socket, "
                    "port may be already occupied");
        }
        return NULL;
    }
    while (session_impl-> is_running)
    {
        socket = axutil_network_handler_svr_socket_accept(env,
                listen_socket);
        if (socket == -1)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "error in creating the socket"
                    "create socket");
            if (session_impl->on_trans_fault_funct)
            {
                (session_impl->on_trans_fault_funct)(env,
                        "error in creating the socket");
            }
            break;
        }

        request_thread_data = (tcpmon_entry_request_data_t*) AXIS2_MALLOC(
                    env-> allocator, sizeof(tcpmon_entry_request_data_t));
        request_thread_data-> env = env;
        request_thread_data-> socket = socket;
        request_thread_data-> session = (tcpmon_session_t*)session_impl;

        request_thread = axutil_thread_pool_get_thread(env->thread_pool,
                tcpmon_entry_new_entry_funct,
                (void*)request_thread_data);
        if (! request_thread)
        {
            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Thread creation failed"
                    "request thread");
            if (session_impl->on_trans_fault_funct)
            {
                (session_impl->on_trans_fault_funct)(env,
                        "fail in creating the thread");
            }
            break;
        }

        axutil_thread_pool_thread_detach(env->thread_pool, request_thread);
    }
    axutil_network_handler_close_socket(env, listen_socket);

    return NULL;
}


/* implementations for protected functions */

axis2_status_t
tcpmon_session_add_new_entry(tcpmon_session_t* session,
        const axutil_env_t* env,
        tcpmon_entry_t* entry)
{
    tcpmon_session_impl_t *session_impl = NULL;

    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    axutil_array_list_add(session_impl-> entries,
            env,
            entry);
    return AXIS2_SUCCESS;

}

TCPMON_SESSION_TRANS_ERROR_FUNCT
tcpmon_session_get_on_trans_fault(tcpmon_session_t *session,
        const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;

	AXIS2_ENV_CHECK(env, NULL);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    return session_impl-> on_trans_fault_funct;
}

TCPMON_SESSION_NEW_ENTRY_FUNCT
tcpmon_session_get_on_new_entry(tcpmon_session_t *session,
        const axutil_env_t *env)
{
    tcpmon_session_impl_t *session_impl = NULL;

	AXIS2_ENV_CHECK(env, NULL);

    session_impl = AXIS2_INTF_TO_IMPL(session);

    return session_impl-> on_new_entry_funct;
}
