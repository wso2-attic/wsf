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
 
#ifndef SANDESHA2_MSG_PENDING_H
#define SANDESHA2_MSG_PENDING_H

/**
  * @file sandesha2_msg_pending.h
  * @brief 
  */

#include <axiom_soap_envelope.h>
#include <sandesha2_iom_rm_part.h>
#include <sandesha2_error.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_msg_pending
 * @ingroup sandesha2_wsrm
 * @{
 */
    
typedef struct sandesha2_msg_pending sandesha2_msg_pending_t;
 
/**
 * @brief sandesha2_msg_pending
 *    sandesha2_msg_pending
 */
AXIS2_DECLARE_DATA struct sandesha2_msg_pending
{
    sandesha2_iom_rm_part_t part;
};

AXIS2_EXTERN sandesha2_msg_pending_t* AXIS2_CALL
sandesha2_msg_pending_create(
    const axutil_env_t *env, 
	axis2_char_t *ns_value);

axis2_status_t AXIS2_CALL
sandesha2_msg_pending_free_void_arg(
    void *msg_pending,
    const axutil_env_t *env);
                    	
axis2_bool_t AXIS2_CALL
sandesha2_msg_pending_is_pending(
    sandesha2_msg_pending_t *msg_pending,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL                 
sandesha2_msg_pending_set_pending(
    sandesha2_msg_pending_t *msg_pending,
    const axutil_env_t *env, 
    axis2_bool_t pending);

axis2_status_t AXIS2_CALL
sandesha2_msg_pending_to_soap_envelope(
    sandesha2_iom_rm_part_t *msg_pending,
    const axutil_env_t *env, 
    axiom_soap_envelope_t *envelope);


/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_MSG_PENDING_H */

