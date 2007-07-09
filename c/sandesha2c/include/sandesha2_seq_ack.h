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
 
#ifndef SANDESHA2_SEQ_ACK_H
#define SANDESHA2_SEQ_ACK_H

/**
  * @file sandesha2_seq_ack.h
  * @brief 
  */

#include <axutil_utils_defines.h>
#include <axutil_env.h>
#include <axiom_soap_envelope.h>
#include <sandesha2_iom_rm_part.h>
#include <sandesha2_error.h>
#include <sandesha2_identifier.h>
#include <sandesha2_nack.h>
#include <sandesha2_ack_range.h>
#include <sandesha2_ack_final.h>
#include <sandesha2_ack_none.h>
#include <axutil_array_list.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_seq_ack
 * @ingroup sandesha2_wsrm
 * @{
 */
    
typedef struct sandesha2_seq_ack sandesha2_seq_ack_t;
/**
 * @brief sandesha2_seq_ack
 *    sandesha2_seq_ack
 */
AXIS2_DECLARE_DATA struct sandesha2_seq_ack
{
    sandesha2_iom_rm_part_t part;
};

AXIS2_EXTERN sandesha2_seq_ack_t* AXIS2_CALL
sandesha2_seq_ack_create(
    const axutil_env_t *env,
	axis2_char_t *ns_value);
 
sandesha2_identifier_t * AXIS2_CALL
sandesha2_seq_ack_get_identifier(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_seq_ack_set_identifier(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier);
        
axutil_array_list_t * AXIS2_CALL
sandesha2_seq_ack_get_nack_list(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_seq_ack_set_ack_final(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env, 
    sandesha2_ack_final_t *ack_final);
                    
axutil_array_list_t * AXIS2_CALL
sandesha2_seq_ack_get_ack_range_list(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_seq_ack_add_ack_range(
    sandesha2_seq_ack_t *seq_ack,
    const axutil_env_t *env, 
    sandesha2_ack_range_t *ack_range);
    
axis2_bool_t AXIS2_CALL
sandesha2_seq_ack_is_must_understand(
    sandesha2_seq_ack_t *element,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_seq_ack_set_must_understand(
    sandesha2_seq_ack_t *element,
    const axutil_env_t *env, 
    axis2_bool_t mu);

/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_SEQ_ACK_H */

