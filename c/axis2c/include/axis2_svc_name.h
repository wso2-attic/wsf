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

#ifndef AXIS2_SVC_NAME_H
#define AXIS2_SVC_NAME_H

/**
 * @defgroup axis2_svc_name service name
 * @ingroup axis2_addr
 * service name provides a full description of the service endpoint. service 
 * name contains a QName identifying the WSDL service element that contains 
 * the definition of the endpoint being conveyed. It also contains an optional 
 * non-qualified name that identifies the specific port in the service that 
 * corresponds to the endpoint. 
 * @{
 */

/**
 * @file axis2_svc_name.h
 */

#include <axis2_defines.h>
#include <axutil_env.h>
#include <axis2_const.h>
#include <axutil_qname.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /** Type name for struct axis2_svc_name */
    typedef struct axis2_svc_name axis2_svc_name_t;

    /**
     * Creates a service name struct with given QName and endpoint name. 
     * @param env pointer to environment struct
     * @param qname pointer to QName, this method creates a clone of QName
     * @param endpoint_name endpoint name string
     * @return pointer to newly create service name struct
     */
    AXIS2_EXTERN axis2_svc_name_t *AXIS2_CALL
    axis2_svc_name_create(
        const axutil_env_t *env,
        const axutil_qname_t *qname,
        const axis2_char_t *endpoint_name) ;

    /**
     * Gets QName. QName identifies the WSDL service element that contains 
     * the definition of the endpoint being conveyed.
     * @param svc_name pointer to service name struct
     * @param env pointer to environment struct
     * @return pointer to QName struct, returns a reference, not a cloned 
     * copy
     */
    AXIS2_EXTERN const axutil_qname_t *AXIS2_CALL
    axis2_svc_name_get_qname(const axis2_svc_name_t *svc_name,
        const axutil_env_t *env);

    /**
     * Sets QName. QName identifies the WSDL service element that contains 
     * the definition of the endpoint being conveyed.
     * @param svc_name pointer to service name struct
     * @param env pointer to environment struct
     * @param qname pointer to QName, service name creates a clone of QName
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_name_set_qname(struct axis2_svc_name *svc_name,
        const axutil_env_t *env,
        const axutil_qname_t *qname);

    /**
     * Gets endpoint name. Endpoint name is a non-qualified name that 
     * identifies the specific port in the service that corresponds to 
     * the endpoint.
     * @param svc_name pointer to service name struct
     * @param env pointer to environment struct
     * @return endpoint name string
     */
    AXIS2_EXTERN const axis2_char_t *AXIS2_CALL
    axis2_svc_name_get_endpoint_name(const axis2_svc_name_t *svc_name,
        const axutil_env_t *env);

    /**
     * Sets endpoint name. Endpoint name is a non-qualified name that 
     * identifies the specific port in the service that corresponds to 
     * the endpoint.
     * @param svc_name pointer to service name struct
     * @param env pointer to environment struct
     * @param endpoint_name endpoint name string
     * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
     */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axis2_svc_name_set_endpoint_name(struct axis2_svc_name *svc_name,
        const axutil_env_t *env,
        const axis2_char_t *endpoint_name);

    /**
     * Frees service name struct.
     * @param svc_name pointer to service name struct
     * @param env pointer to environment struct
     * @return void
     */
    AXIS2_EXTERN void AXIS2_CALL
    axis2_svc_name_free(struct axis2_svc_name *svc_name,
        const axutil_env_t *env);

/** @} */

#ifdef __cplusplus
}
#endif

#endif    /* AXIS2_SVC_NAME_H */
