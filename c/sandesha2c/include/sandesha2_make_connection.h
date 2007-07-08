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
 
#ifndef SANDESHA2_MAKE_CONNECTION_H
#define SANDESHA2_MAKE_CONNECTION_H

/**
  * @file sandesha2_make_connection.h
  * @brief 
  */

#include <axiom_soap_envelope.h>
#include <sandesha2_iom_rm_part.h>
#include <sandesha2_identifier.h>
#include <sandesha2_address.h>
#include <sandesha2_error.h>


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup sandesha2_make_connection
 * @ingroup sandesha2_wsrm
 * @{
 */
    
typedef struct sandesha2_make_connection sandesha2_make_connection_t;
 
/**
 * @brief sandesha2_make_connection
 *    sandesha2_make_connection
 */
AXIS2_DECLARE_DATA struct sandesha2_make_connection
{
    sandesha2_iom_rm_part_t part;
};

AXIS2_EXTERN sandesha2_make_connection_t* AXIS2_CALL
sandesha2_make_connection_create(
    const axutil_env_t *env, 
	axis2_char_t *ns_value);

axis2_status_t AXIS2_CALL
sandesha2_make_connection_free_void_arg(
    void *make_conn,
    const axutil_env_t *env);
                    	
sandesha2_identifier_t * AXIS2_CALL
sandesha2_make_connection_get_identifier(
    sandesha2_make_connection_t *make_conn,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL                 
sandesha2_make_connection_set_identifier(
    sandesha2_make_connection_t *make_conn,
    const axutil_env_t *env, 
    sandesha2_identifier_t *identifier);
                    	
sandesha2_address_t * AXIS2_CALL
sandesha2_make_connection_get_address(
    sandesha2_make_connection_t *make_conn,
    const axutil_env_t *env);

axis2_status_t AXIS2_CALL                 
sandesha2_make_connection_set_address(
    sandesha2_make_connection_t *make_conn,
    const axutil_env_t *env, 
    sandesha2_address_t *address);
                    	
/** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* SANDESHA2_MAKE_CONNECTION_H */

