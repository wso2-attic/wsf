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

#ifndef AXIS2_ENDPOINT_REF_H
#define AXIS2_ENDPOINT_REF_H

/**
 * @defgroup axis2_endpoint_ref  endpoint reference
 * @ingroup axis2_addr
 * endpoint reference represent an endpoint address in WS-Addressing.
 * In addition to the endpoint address, it also encapsulates meta data,
 * reference attributes and the service hosted at the given endpoint.
 * In addition to the addressing related implementation, the endpoint reference 
 * struct is used across core code-base to represent endpoints. 
 * @{
 */

/**
 * @file axis2_endpoint_ref.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_const.h>
#include <axutil_array_list.h>
#include <axis2_any_content_type.h>
#include <axis2_svc_name.h>
#include <axiom_node.h>
#include <axiom_attribute.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_endpoint_ref */
    typedef struct axis2_endpoint_ref axis2_endpoint_ref_t;

    /**
     * Creates endpoint reference struct.
     * @param env pointer to environment struct
     * @param address endpoint address string 
     * @return pointer to newly created endpoint reference
     */
    AXIS2_EXTERN axis2_endpoint_ref_t *AXIS2_CALL
    axis2_endpoint_ref_create(const axutil_env_t *env,
        const axis2_char_t *address);

    /**
     * Frees the endpoint_ref given as a void pointer. This method would cast the 
     * void parameter to an endpoint_ref pointer and then call free method.
     * @param pointer to endpoint_ref as a void pointer
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    void AXIS2_CALL
    axis2_endpoint_ref_free_void_arg(void *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Gets endpoint address. Address URI identifies the endpoint. 
     * This may be a network address or a logical address.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return endpoint address string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_endpoint_ref_get_address(const axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Sets endpoint address. Address URI identifies the endpoint. 
     * This may be a network address or a logical address.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @param address address string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_endpoint_ref_set_address(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env,
        const axis2_char_t *address);

    /**
     * Gets interface QName. QName represents the primary portType of 
     * the endpoint being conveyed.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return pointer to interface QName, returns a reference, not a cloned
     * copy
     */
    AXIS2_EXTERN const axutil_qname_t *AXIS2_CALL
    axis2_endpoint_ref_get_interface_qname(const axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Sets interface QName. QName represents the primary portType of 
     * the endpoint being conveyed.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @param interface_name pointer to interface QName, this method creates
     * a clone of the QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_endpoint_ref_set_interface_qname(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env,
        const axutil_qname_t *interface_qname);

    /**
     * Gets reference parameter list. A reference may contain a number 
     * of individual parameters which are associated with the endpoint 
     * to facilitate a particular interaction. Reference parameters 
     * are element information items that are named by QName and are 
     * required to properly interact with the endpoint. 
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return pointer to array list containing all reference parameters,
     * returns a reference, not a cloned copy 
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_endpoint_ref_get_ref_param_list(const axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Gets the list of metadata. An endpoint can have different associated 
     * metadata such as WSDL, XML Schema, and WS-Policy policies.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return pointer to array list containing metadata, returns a 
     * reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_endpoint_ref_get_metadata_list(const axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Gets the list of reference attributes. 
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return pointer to array list containing reference attributes, 
     * returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_endpoint_ref_get_ref_attribute_list(const axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Gets the list of metadata attributes.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return pointer to array list containing metadata attributes, 
     * returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_endpoint_ref_get_metadata_attribute_list(const axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Gets the list of extensions. Extensions are a mechanism to allow 
     * additional elements to be specified in association with the endpoint.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return pointer to array list containing extensions, 
     * returns a reference, not a cloned copy
     */
    AXIS2_EXTERN axutil_array_list_t *AXIS2_CALL
    axis2_endpoint_ref_get_extension_list(const axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Adds a reference parameter in the form of an AXIOM node. 
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @param ref_param_node pointer to AXIOM node representing reference 
     * parameter, endpoint reference does not assume the ownership of 
     * the node 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_endpoint_ref_add_ref_param(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env,
        axiom_node_t *ref_param_node);

    /**
     * Adds metadata in the form of an AXIOM node. An endpoint can have 
     * different associated metadata such as WSDL, XML Schema and 
     * WS-Policy policies.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @param metadata_node AXIOM node representing metadata, 
     * endpoint reference does not assume the ownership of the node 
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_endpoint_ref_add_metadata(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env,
        axiom_node_t *metadata_node);

    /**
     * Adds a reference attribute in the form of an AXIOM attribute.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @param attr AXIOM attribute representing reference attribute,
     * endpoint reference does not assume the ownership of the attribute
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_endpoint_ref_add_ref_attribute(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env,
        axiom_attribute_t *attr);

    /**
     * Adds a meta attribute in the form of an AXIOM attribute.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @param attr AXIOM attribute representing meta attribute,
     * endpoint reference does not assume the ownership of the attribute
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_endpoint_ref_add_metadata_attribute(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env,
        axiom_attribute_t *attr);

    /**
     * Adds an extension in the form of an AXIOM node.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @param extension_node pointer to AXIOM node representing extension,
     * endpoint reference does not assume the ownership of the node
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_endpoint_ref_add_extension(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env,
        axiom_node_t *extension_node);

    /**
     * Gets service name. An endpoint in WS-Addressing has a QName 
     * identifying the WSDL service element that contains the definition 
     * of the endpoint being conveyed. The service name provides a link 
     * to a full description of the service endpoint.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return pointer to service name struct, returns a reference, not 
     * a cloned copy
     */
    AXIS2_EXTERN axis2_svc_name_t *AXIS2_CALL
    axis2_endpoint_ref_get_svc_name(const axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);

    /**
     * Sets service name. An endpoint in WS-Addressing has a QName 
     * identifying the WSDL service element that contains the definition 
     * of the endpoint being conveyed. The service name provides a link 
     * to a full description of the service endpoint.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @param svc_name pointer to service name struct, endpoint assumes
     * ownership of the struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_endpoint_ref_set_svc_name(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env,
        axis2_svc_name_t *svc_name);

    /**
     * Frees endpoint reference struct.
     * @param endpoint_ref pointer to endpoint reference struct
     * @param env pointer to environment struct
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_endpoint_ref_free(axis2_endpoint_ref_t *endpoint_ref,
        const axutil_env_t *env);


/** @} */

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_ENDPOINT_REF_H */
