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
  
#ifndef TCPMON_ENTRY_H
#define TCPMON_ENTRY_H

#include <axutil_env.h>
#include <axutil_string.h>
 
/**
 * @file tcpmon_entry.h
 * @brief represent entry of tcpmon
 */

#ifdef __cplusplus
extern "C"
{
#endif
   
/** 
 * @defgroup represent entry of tcpmon
 * @ingroup tcpmon
 * @{
 */    
 
typedef struct tcpmon_entry_ops tcpmon_entry_ops_t;   
typedef struct tcpmon_entry tcpmon_entry_t;

 struct tcpmon_entry_ops
{
   /**
    * free the tcpmon_entry.
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE.
    */
    axis2_status_t (AXIS2_CALL * 
    free)(tcpmon_entry_t *entry,
            const axutil_env_t *env);
   
   /**
    * retrieve the arrived_time
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_char_t* (AXIS2_CALL *
    arrived_time) (tcpmon_entry_t *entry,
                        const axutil_env_t *env);

   /**
    * retrieve the sent_time
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_char_t* (AXIS2_CALL *
    sent_time) (tcpmon_entry_t *entry,
                        const axutil_env_t *env);

   /**
    * retrieve the arrived_time - sent_time ( in seconds)
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_char_t* (AXIS2_CALL *
    time_diff) (tcpmon_entry_t *entry,
                        const axutil_env_t *env);

   /**
    * retrieve the sent data
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_char_t* (AXIS2_CALL *
    sent_data) (tcpmon_entry_t *entry,
                        const axutil_env_t *env);
 
   /**
    * retrieve the arrived data
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_char_t* (AXIS2_CALL *
    arrived_data) (tcpmon_entry_t *entry,
                        const axutil_env_t *env);

    /**
    * retrieve the sent headers 
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_char_t* (AXIS2_CALL *
    sent_headers) (tcpmon_entry_t *entry,
                        const axutil_env_t *env);
 
   /**
    * retrieve the arrived headers
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_char_t* (AXIS2_CALL *
    arrived_headers) (tcpmon_entry_t *entry,
                        const axutil_env_t *env);

   /**
    * retrieve whether the transportation success
    * @param entry represet the type object.
    * @param env pointer to environment struct. MUST NOT be NULL.
    */
    axis2_bool_t (AXIS2_CALL *
    is_success) (tcpmon_entry_t *entry,
                        const axutil_env_t *env);

    int (AXIS2_CALL *
    get_format_bit) (tcpmon_entry_t *entry,
	                    const axutil_env_t *env);

    axis2_status_t (AXIS2_CALL *
    set_format_bit) (tcpmon_entry_t *entry,
                        const axutil_env_t *env,
                        int format_bit);
};

 struct tcpmon_entry 
{
    tcpmon_entry_ops_t *ops;
};

/**
 * Creates tcpmon_entry struct
 * @param env double pointer to environment struct. MUST NOT be NULL
 * @return pointer to newly created tcpmon_entry struct
 */
tcpmon_entry_t * AXIS2_CALL
tcpmon_entry_create(const axutil_env_t *env );

/*************************** Function macros **********************************/

#define TCPMON_ENTRY_FREE(entry, env) \
        ((entry)->ops->free (entry, env))

#define TCPMON_ENTRY_ARRIVED_TIME(entry, env) \
        ((entry)->ops->arrived_time(entry, env))

#define TCPMON_ENTRY_SENT_TIME(entry, env) \
        ((entry)->ops->sent_time(entry, env))

#define TCPMON_ENTRY_TIME_DIFF(entry, env) \
        ((entry)->ops->time_diff(entry, env))

#define TCPMON_ENTRY_SENT_DATA(entry, env) \
        ((entry)->ops->sent_data(entry, env))

#define TCPMON_ENTRY_ARRIVED_DATA(entry, env) \
        ((entry)->ops->arrived_data(entry, env))

#define TCPMON_ENTRY_SENT_HEADERS(entry, env) \
        ((entry)->ops->sent_headers(entry, env))

#define TCPMON_ENTRY_ARRIVED_HEADERS(entry, env) \
        ((entry)->ops->arrived_headers(entry, env))

#define TCPMON_ENTRY_IS_SUCCESS(entry, env) \
        ((entry)->ops->is_success(entry, env))

#define TCPMON_ENTRY_SET_FORMAT_BIT(entry, env, format_bit) \
        ((entry)->ops->set_format_bit(entry, env, format_bit))

#define TCPMON_ENTRY_GET_FORMAT_BIT(entry, env) \
        ((entry)->ops->get_format_bit(entry, env))

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* TCPMON_ENTRY_H */
