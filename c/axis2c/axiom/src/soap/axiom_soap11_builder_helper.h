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

#ifndef AXIOM_SOAP11_BUILDER_HELPER_H
#define AXIOM_SOAP11_BUILDER_HELPER_H


/**
 * @file axiom_soap_11_builder_helper.h
 * @brief axiom_soap11_builder_helper
 */
#include <axiom_soap_builder.h>

#ifdef __cplusplus
extern "C"
{
#endif


    typedef struct axiom_soap11_builder_helper axiom_soap11_builder_helper_t;

    /**
     * @defgroup axiom_soap11_builder_helper
     * @ingroup axiom_soap
     * @{
     */

    /**
      * creates a soap11_builder_helper_create
      * @param env Environment. MUST NOT be NULL
      */
    AXIS2_EXTERN axiom_soap11_builder_helper_t* AXIS2_CALL
    axiom_soap11_builder_helper_create(const axutil_env_t *env,
        axiom_soap_builder_t *soap_builder,
        axiom_stax_builder_t *om_builder);

    AXIS2_EXTERN void AXIS2_CALL
    axiom_soap11_builder_helper_free(axiom_soap11_builder_helper_t *builder_helper,
        const axutil_env_t *env);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    axiom_soap11_builder_helper_handle_event(axiom_soap11_builder_helper_t *builder_helper,
        const axutil_env_t *env,
        axiom_node_t *om_element_node,
        int element_level);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif /* AXIOM_SOAP11_BUILDER_HELPER_H */
