/**
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


#include <axis2_handler_desc.h>
#include <axutil_array_list.h>
#include <axiom_soap_const.h>
#include <axiom_soap_envelope.h>
#include <axiom_soap_header.h>
#include <axiom_soap_header_block.h>
#include <axis2_op.h>
#include <axis2_msg_ctx.h>
#include <axis2_msg_info_headers.h>
#include <axutil_property.h>
#include <rampart_constants.h>
#include <rampart_util.h>
#include <axis2_conf_ctx.h>


#ifndef RAMPART_HANDLER_UTIL_H
#define RAMPART_HANDLER_UTIL_H

/**
  * @file rampart_handler_util.h
  * @brief Utilities related to handlers 
  */

#ifdef __cplusplus
extern "C"
{
#endif


    /**
     * Get properties from the axis2 context
     * @param env pointer to environment struct
     * @param ctx axis2 context
     * @param key the property name
     * @return parameter
     */

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    rampart_get_property_from_ctx( const axutil_env_t *env,
                                   axis2_ctx_t *ctx,
                                   const axis2_char_t *key);

    /**
    * Get parameter for the given parameter name
    * @param env pointer to environment struct    
    * @param msg_ctx message context
    * @param parameter the parameter name
    * @return parameter 
    */

    AXIS2_EXTERN axutil_param_t* AXIS2_CALL
    rampart_get_security_param( const axutil_env_t *env,
                                axis2_msg_ctx_t *msg_ctx,
                                axis2_char_t *parameter);




    /**
    * Get the security token from the header block
    * @param env pointer to environment struct
    * @param msg_ctx message context
    * @param soap heamsg_ctxder
    * @return soap_header security element node
    */
    AXIS2_EXTERN axiom_node_t *AXIS2_CALL
    rampart_get_security_token(const axutil_env_t *env,
                               axis2_msg_ctx_t *msg_ctx,
                               axiom_soap_header_t *soap_header);

    /**
    * Creates a SOAP envelope based on params described below
    * @param env pointer to environment struct
    * @param sub_code the text of the Subcode element of a SOAP fault message
    * @param reason_text the text in soapenv:Reason element
    * @param detail_node_text the text in the soapenv:Detail element
    * @param msg_ctx the msg_ctx 
    * @return soap_header security element node
    */
    AXIS2_EXTERN void AXIS2_CALL
    rampart_create_fault_envelope(const axutil_env_t *env,
                                  const axis2_char_t *sub_code,
                                  const axis2_char_t *reason_text,
                                  const axis2_char_t *detail_node_text,
                                  axis2_msg_ctx_t *msg_ctx);

    /**
     * Validates a security header elements 
     * @param env pointer to environment struct  
     * @param msg_ctx the msg_ctx 
     * @param  sec_node the reference to the security node
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    rampart_validate_security_token(const axutil_env_t *env,
                                    axis2_msg_ctx_t *msg_ctx,
                                    axiom_node_t *sec_node);
    /**
     * Get rampart configurations from the message context
     * @param env pointer to environment struct
     * @param msg_ctx message context
     * @param param_name name of the parameter of the configuration
     * @return the loaded configuration params
     */
    AXIS2_EXTERN void *AXIS2_CALL
    rampart_get_rampart_configuration(const axutil_env_t *env,
                                      axis2_msg_ctx_t *msg_ctx,
                                      axis2_char_t *param_name);
    /**
     * Check wether rampart is engaged or not
     * @param env pointer to environment struct
     * @param msg_ctx message context
     * @return if engaged returns AXIS2_TRUE, else returns AXIS2_FALSE
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    rampart_is_rampart_engaged(const axutil_env_t *env,
                               axis2_msg_ctx_t *msg_ctx);



    /** @} */
#ifdef __cplusplus
}
#endif


#endif /*RAMPART_HANDLER_UTIL_H*/
