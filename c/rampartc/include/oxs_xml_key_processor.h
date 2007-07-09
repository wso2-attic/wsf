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

#ifndef OXS_XML_KEY_PROCESSOR_H
#define OXS_XML_KEY_PROCESSOR_H


/**
  * @file oxs_xml_key_processor.h
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
    /*Process a ds:X509SKI element and populate a certificate */
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_key_process_X509SKI(const axutil_env_t *env,
                                axiom_node_t *X509SKI_node,
                                oxs_x509_cert_t *cert);

    /*Process a ds:X509SubjectName element and populate a  certificate*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_key_process_X509SubjectName(const axutil_env_t *env,
                                        axiom_node_t *X509_subj_name_node,
                                        oxs_x509_cert_t *cert);

    /*Process a ds:X509IssuerSerial element and populate a certificate*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_key_process_X509IssuerSerial(const axutil_env_t *env,
                                         axiom_node_t *X509_issuer_serial_node,
                                         oxs_x509_cert_t *cert);

    /*Process data in a ds:X509Certificate and returns a certificate*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_key_process_X509Certificate(const axutil_env_t *env,
                                        axiom_node_t *X509_cert_node,
                                        oxs_x509_cert_t *cert);

    /*Higher level function ot process an ds:X509Data element*/
    AXIS2_EXTERN axis2_status_t AXIS2_CALL
    oxs_xml_key_process_X509Data(const axutil_env_t *env,
                                 axiom_node_t *X509_data_node,
                                 oxs_x509_cert_t *cert);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif                          /* OXS_XML_KEY_PROCESSOR_H */
