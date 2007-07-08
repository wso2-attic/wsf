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

#ifndef OXS_XML_KEY_INFO_BUILDER_H
#define OXS_XML_KEY_INFO_BUILDER_H


/**
  * @file oxs_xml_key_info_builder.h
  * @brief Process elements available under ds:KeyInfo  
  */

#include <axis2_defines.h>
#include <oxs_ctx.h>
#include <axutil_env.h>
#include <axiom_node.h>
#include <axiom_element.h>
#include <axutil_qname.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum{
        OXS_KIBP_UNKNOWN = 0,
        OXS_KIBP_X509DATA_X509CERTIFICATE,
        OXS_KIBP_X509DATA_ISSUER_SERIAL,
    }oxs_key_info_build_pattern_t;

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_key_info_build(const axutil_env_t *env,
                           axiom_node_t *parent,
                           oxs_x509_cert_t *cert,
                           oxs_key_info_build_pattern_t pattern);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_key_info_build_x509_data_x509_certificate(const axutil_env_t *env,
            axiom_node_t *parent,
            oxs_x509_cert_t *cert);

    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_key_info_build_x509_data_issuer_serial(const axutil_env_t *env,
            axiom_node_t *parent,
            oxs_x509_cert_t *cert);

    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_XML_KEY_INFO_BUILDER_H */
