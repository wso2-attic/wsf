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
 
#ifndef SANDESHA2_ACK_REQUESTED_H
#define SANDESHA2_ACK_REQUESTED_H

/**
  * @file sandesha2_ack_requested.h
  * @brief 
  */

#include <sandesha2_iom_rm_part.h>
#include <sandesha2_identifier.h>
#include <sandesha2_msg_number.h>
#include <sandesha2_error.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_ack_requested
 * @ingroup sandesha2_wsrm
 * @{
 */

typedef struct sandesha2_ack_requested sandesha2_ack_requested_t;
 
/**
 * @brief sandesha2_ack_requested
 *    sandesha2_ack_requested
 */
AXIS2_DECLARE_DATA struct sandesha2_ack_requested
{
    sandesha2_iom_rm_part_t part;
};

AXIS2_EXTERN sandesha2_ack_requested_t* AXIS2_CALL
sandesha2_ack_requested_create(
    const axutil_env_t *env, 
    axis2_char_t *ns_value);
                    	
sandesha2_identifier_t * AXIS2_CALL
sandesha2_ack_requested_get_identifier(
    sandesha2_ack_requested_t *ack_requested,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL                 
sandesha2_ack_requested_set_identifier(
    sandesha2_ack_requested_t *ack_requested,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier);

sandesha2_msg_number_t * AXIS2_CALL                    	
sandesha2_ack_requested_get_msg_number(
    sandesha2_ack_requested_t *ack_requested,
    const axutil_env_t *env);
                    	
axis2_status_t AXIS2_CALL
sandesha2_ack_requested_set_msg_number(
    sandesha2_ack_requested_t *ack_requested,
    const axutil_env_t *env, 
    sandesha2_msg_number_t *msg_number);

axis2_bool_t AXIS2_CALL
sandesha2_ack_requested_is_must_understand(
    sandesha2_ack_requested_t *ack_requested,
    const axutil_env_t *env);
                    	
axis2_status_t AXIS2_CALL
sandesha2_ack_requested_set_must_understand(
    sandesha2_ack_requested_t *ack_requested,
    const axutil_env_t *env, 
    axis2_bool_t mu);
                    	

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_ACK_REQUESTED_H */

