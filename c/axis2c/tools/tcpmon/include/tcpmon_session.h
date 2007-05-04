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
  
#ifndef TCPMON_SESSION_H
#define TCPMON_SESSION_H

#include <axutil_env.h>
#include <tcpmon_entry.h>
#include <axutil_string.h>
 
/**
 * @file tcpmon_session.h
 * @brief represent session of tcpmon
 */

#ifdef __cplusplus
extern "C"
{
#endif
   
/** 
 * @defgroup represent session of tcpmon
 * @ingroup tcpmon
 * @{
 */    
 
typedef struct tcpmon_session_ops tcpmon_session_ops_t;   
typedef struct tcpmon_session tcpmon_session_t;

/**
 * callback functions for the tcpmon session
 */
typedef int (*TCPMON_SESSION_NEW_ENTRY_FUNCT) 
                 ( const axutil_env_t *env,
                   tcpmon_entry_t* entry,
                   int status);   /* 0-started, 1-finished */

typedef int (*TCPMON_SESSION_TRANS_ERROR_FUNCT) 
                   ( const axutil_env_t *env,
                     axis2_char_t* error_message);


 struct tcpmon_session_ops
{
   /**
    * free the tcpmon_session.
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE.
    */
    axis2_status_t (AXIS2_CALL * 
    free)(tcpmon_session_t *session,
            const axutil_env_t *env);


	 axis2_status_t (AXIS2_CALL *
						  set_test_bit) (tcpmon_session_t *session,
											  const axutil_env_t *env,
											  int test_bit);

	 axis2_status_t (AXIS2_CALL *
						  get_test_bit) (tcpmon_session_t *session,
											  const axutil_env_t *env);
    axis2_status_t (AXIS2_CALL *
                          set_format_bit) (tcpmon_session_t *session,
                                              const axutil_env_t *env,
                                              int format_bit);

    int (AXIS2_CALL *
                    get_format_bit) (tcpmon_session_t *session,
                                              const axutil_env_t *env);
   /**
    * configure the listening port.
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    * @param listen_port listening port ( port of a localhost).
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE.
    */
    axis2_status_t (AXIS2_CALL *
						  set_listen_port) (tcpmon_session_t *session,
								const axutil_env_t *env,
								int listen_port);

   /**
    * retrieve the listening port
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    int (AXIS2_CALL *
    get_listen_port) (tcpmon_session_t *session,
                        const axutil_env_t *env);
  
   /**
    * configure the target port
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    * @param target_port tartet port
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE.
    */
    axis2_status_t (AXIS2_CALL *
    set_target_port) (tcpmon_session_t *session,
                        const axutil_env_t *env,
                        int target_port);

   /**
    * retrieve the target port
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    int (AXIS2_CALL *
    get_target_port) (tcpmon_session_t *session,
                        const axutil_env_t *env);

   /**
    * configure the target host
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    * @param target_host url of the target host
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE.
    */
    axis2_status_t (AXIS2_CALL *
    set_target_host) (tcpmon_session_t *session,
                        const axutil_env_t *env,
                        axis2_char_t* target_host);

   /**
    * retrieve the base uri of the target host
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_char_t* (AXIS2_CALL *
    get_target_host) (tcpmon_session_t *session,
                        const axutil_env_t *env);

   /**
    * start the session
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_status_t (AXIS2_CALL *
    start) (tcpmon_session_t *session,
                        const axutil_env_t *env);

   /**
    * stop the session.
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_status_t (AXIS2_CALL *
    stop) (tcpmon_session_t *session,
                        const axutil_env_t *env);
 
   /**
    * set on new entry.
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    * @param on_new_entry_funct function to triger on new entry
    */
    axis2_status_t (AXIS2_CALL *
    on_new_entry) (tcpmon_session_t *session,
                        const axutil_env_t *env,
                        TCPMON_SESSION_NEW_ENTRY_FUNCT on_new_entry_funct);

   /**
    * set on new entry.
    * @param session represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    * @param on_new_entry function to triger on new entry
    */
    axis2_status_t (AXIS2_CALL *
    on_trans_fault) (tcpmon_session_t *session,
                        const axutil_env_t *env,
                        TCPMON_SESSION_TRANS_ERROR_FUNCT on_trans_fault_funct);


};

 struct tcpmon_session 
{
    tcpmon_session_ops_t *ops;
};

/**
 * Creates tcpmon_session struct
 * @param env double pointer to environment struct. MUST NOT be NULL
 * @return pointer to newly created tcpmon_session struct
 */
tcpmon_session_t * AXIS2_CALL
tcpmon_session_create(const axutil_env_t *env );

/*************************** Function macros **********************************/

#define TCPMON_SESSION_FREE(session, env) \
        ((session)->ops->free (session, env))

#define TCPMON_SESSION_SET_TEST_BIT(session, env, test_bit) \
        ((session)->ops->set_test_bit(session, env, test_bit))

#define TCPMON_SESSION_GET_TEST_BIT(session, env) \
        ((session)->ops->get_test_bit(session, env))

#define TCPMON_SESSION_SET_FORMAT_BIT(session, env, format_bit) \
        ((session)->ops->set_format_bit(session, env, format_bit))

#define TCPMON_SESSION_GET_FORMAT_BIT(session, env) \
        ((session)->ops->get_format_bit(session, env))

#define TCPMON_SESSION_SET_LISTEN_PORT(session, env, listen_port) \
        ((session)->ops->set_listen_port(session, env, listen_port))

#define TCPMON_SESSION_GET_LISTEN_PORT(session, env) \
        ((session)->ops->get_listen_port(session, env))

#define TCPMON_SESSION_SET_TARGET_PORT(session, env, target_port) \
        ((session)->ops->set_target_port(session, env, target_port))

#define TCPMON_SESSION_GET_TARGET_PORT(session, env) \
        ((session)->ops->get_target_port(session, env))

#define TCPMON_SESSION_SET_TARGET_HOST(session, env, target_host) \
        ((session)->ops->set_target_host(session, env, target_host))

#define TCPMON_SESSION_GET_TARGET_HOST(session, env) \
        ((session)->ops->get_target_host(session, env))

#define TCPMON_SESSION_START(session, env) \
        ((session)->ops->start(session, env))

#define TCPMON_SESSION_STOP(session, env) \
        ((session)->ops->stop(session, env))

#define TCPMON_SESSION_ON_TRANS_FAULT(session, env, funct) \
        ((session)->ops->on_trans_fault(session, env, funct))

#define TCPMON_SESSION_ON_NEW_ENTRY(session, env, funct) \
        ((session)->ops->on_new_entry(session, env, funct))

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* TCPMON_SESSION_H */
