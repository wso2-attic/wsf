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
 
#ifndef SANDESHA2_CREARE_SEQ_RES_H
#define SANDESHA2_CREARE_SEQ_RES_H

/**
  * @file sandesha2_create_seq_res.h
  * @brief 
  */

#include <sandesha2_iom_rm_part.h>
#include <sandesha2_error.h>
#include <sandesha2_expires.h>
#include <sandesha2_accept.h>
#include <sandesha2_identifier.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_create_seq_res
 * @ingroup sandesha2_wsrm
 * @{
 */
    
typedef struct sandesha2_create_seq_res sandesha2_create_seq_res_t;
 
/**
 * @brief sandesha2_create_seq_res
 *    sandesha2_create_seq_res
 */
AXIS2_DECLARE_DATA struct sandesha2_create_seq_res
{
    sandesha2_iom_rm_part_t part;
};

AXIS2_EXTERN sandesha2_create_seq_res_t* AXIS2_CALL
sandesha2_create_seq_res_create(
    const axutil_env_t *env, 
    axis2_char_t *rm_ns_value, 
    axis2_char_t *addr_ns_value);

axis2_status_t AXIS2_CALL
sandesha2_create_seq_res_set_identifier(
   sandesha2_create_seq_res_t *create_seq_res,
   const axutil_env_t *env, 
   sandesha2_identifier_t *identifier);

sandesha2_identifier_t * AXIS2_CALL
sandesha2_create_seq_res_get_identifier(
   sandesha2_create_seq_res_t *create_seq_res,
   const axutil_env_t *env);

axis2_status_t AXIS2_CALL
sandesha2_create_seq_res_set_accept(
   sandesha2_create_seq_res_t *create_seq_res,
   const axutil_env_t *env, sandesha2_accept_t *accept);

sandesha2_accept_t * AXIS2_CALL
sandesha2_create_seq_res_get_accept(
   sandesha2_create_seq_res_t *create_seq_res,
   const axutil_env_t *env);
                        
axis2_status_t AXIS2_CALL
sandesha2_create_seq_res_set_expires(
   sandesha2_create_seq_res_t *create_seq_res,
   const axutil_env_t *env, sandesha2_expires_t *expires);

sandesha2_expires_t * AXIS2_CALL
sandesha2_create_seq_res_get_expires(
   sandesha2_create_seq_res_t *create_seq_res,
   const axutil_env_t *env);


/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_CREARE_SEQ_RES_H */

