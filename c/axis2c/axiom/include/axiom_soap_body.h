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

#ifndef AXIOM_SOAP_BODY_H
#define AXIOM_SOAP_BODY_H

/**
 * @file axiom_soap_body.h
 * @brief axiom_soap_body struct
 */

#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axiom_namespace.h>
#include <axiom_soap_fault.h>
#include <axiom_soap_envelope.h>


#ifdef __cplusplus
extern "C"
{
#endif


    typedef struct axiom_soap_body      axiom_soap_body_t;
    struct axiom_soap_builder;

    /**
     * @defgroup axiom_soap_body soap body
     * @ingroup axiom_soap
     * @{
     */

    /**
     * a struct that represents the contents of the SOAP body
     * element in a SOAP message. SOAP body element consists of XML data
     * that affects the way the application-specific content is processed.
     * soap_body_struct contains soap_header and
     * which have the content for the SOAP body.
     * this also contains axiom_soap_fault_t struct , which carries status and/or
     * error information.
     */

    /**
      * creates a soap body struct 
      * @param env Environment. MUST NOT be NULL
      */

    AXIS2_EXTERN axiom_soap_body_t * AXIS2_CALL
    axiom_soap_body_create_with_parent(const axutil_env_t *env,
            struct axiom_soap_envelope *envelope);

    /**
     * Deallocate all the resources associated to soap_body
     * But it does not deallocate the underlying om structure
     * @param body soap_body struct
     * @param env must not be null
     * @return status code AXIS2_SUCCESS 
     */
    AXIS2_EXTERN void AXIS2_CALL
    axiom_soap_body_free(axiom_soap_body_t *body,
            const axutil_env_t *env);

    /**
     * Indicates whether a soap fault is available with this 
     * soap body 
     * @param body soap_body struct
     * @param env environment must not be null
     * @return AXIS2_TRUE if fault is available, AXIS2_FALSE otherwise
     */
    AXIS2_EXTERN axis2_bool_t AXIS2_CALL
    axiom_soap_body_has_fault(axiom_soap_body_t *body,
            const axutil_env_t *env);

    /**
     * returns the soap fault in this soap_body 
     * IF a soap_builder is associated with the soap_body
     * Pulling will  take place 
     * @param body soap_body 
     * @param env environment must not be null
     * @return axiom_soap_fault_t if available, NULL otherwise
    */
    AXIS2_EXTERN axiom_soap_fault_t* AXIS2_CALL
    axiom_soap_body_get_fault(axiom_soap_body_t *body,
            const axutil_env_t *env);

    /**
     * get the underlying om_node 
     * @param body soap_body
     * @param env environment must not be null
     * @returns axiom_node_t
     */
    AXIS2_EXTERN axiom_node_t* AXIS2_CALL
    axiom_soap_body_get_base_node(axiom_soap_body_t *body,
            const axutil_env_t *env);

    /**
     *  return the soap version 
     * @param body soap_body
     * @param env environment must not be null
     * @return one of AXIOM_SOAP11 or AXIOM_SOAP12 
     */
    AXIS2_EXTERN int AXIS2_CALL
    axiom_soap_body_get_soap_version(axiom_soap_body_t *body,
            const axutil_env_t *env);


    /**
     * build the soap body completely . return the status code,
    * @return AXIS2_SUCCESS on success and AXIS2_FAILURE on error
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_body_build(axiom_soap_body_t *body,
            const axutil_env_t *env);

    /** add an om node as the child to this soap_body
     * the child is added to as the first child 
     * @param body pointer to soap_body struct
     * @param env axutil_environment struct MUST not be NULL
     * @returns status code , AXIS2_SUCCESS on success , AXIS2_ERROR
     * otherwise
     */

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap_body_add_child(axiom_soap_body_t *body,
            const axutil_env_t *env,
            axiom_node_t *child);

	/**
	 * SOAP builder construct a SOAP 1.2 fault all the time. 
	 * So when SOAP 1.1 is in use, we should convert SOAP fault to 
	 * SOAP 1.1 fault format before use.
	 */
	AXIS2_EXTERN axis2_status_t AXIS2_CALL
	axiom_soap_body_convert_fault_to_soap11(axiom_soap_body_t *soap_body,
		const axutil_env_t *env);

#ifdef __cplusplus
}
#endif

#endif /* AXIOM_SOAP_BODY_H */
