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

#include <stdio.h>
#include <axis2_util.h>
#include <oxs_constants.h>
#include <oxs_error.h>
#include <oxs_buffer.h>
#include <oxs_cipher.h>
#include <oxs_c14n.h>
#include <oxs_axiom.h>
#include <oxs_utility.h>
#include <openssl_rsa.h>
#include <openssl_digest.h>
#include <oxs_key_mgr.h>
#include <oxs_tokens.h>
#include <oxs_xml_key_info_builder.h>

/*Private functions*/

/*Public functions*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_key_info_build(const axutil_env_t *env,
                       axiom_node_t *parent,
                       oxs_x509_cert_t *cert,
                       oxs_key_info_build_pattern_t pattern)
{
    axis2_status_t status = AXIS2_FAILURE;
    axiom_node_t *key_info_node = NULL;

    /*Build the KeyInfo node*/
    key_info_node = oxs_token_build_key_info_element(env, parent);

    if(OXS_KIBP_X509DATA_X509CERTIFICATE == pattern){
        status = oxs_xml_key_info_build_x509_data_x509_certificate(env, key_info_node, cert);
    }else if(OXS_KIBP_X509DATA_ISSUER_SERIAL == pattern){
        status = oxs_xml_key_info_build_x509_data_issuer_serial(env, key_info_node, cert);
    }else{
        /*We do not support*/
    }
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_key_info_build_x509_data_x509_certificate(const axutil_env_t *env,
        axiom_node_t *parent,
        oxs_x509_cert_t *cert)
{
    axiom_node_t *x509_data_node = NULL;
    axiom_node_t *x509_certificate_node = NULL;
    axis2_char_t *cert_data = NULL;

    /*Get certificate data*/
    cert_data = oxs_x509_cert_get_data(cert, env);
    /*Build the X509Data node*/
    x509_data_node = oxs_token_build_x509_data_element(env, parent);

    /*Now build the X509Certificate node*/
    x509_certificate_node = oxs_token_build_x509_certificate_element(env, x509_data_node, cert_data);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_key_info_build_x509_data_issuer_serial(const axutil_env_t *env,
        axiom_node_t *parent,
        oxs_x509_cert_t *cert)
{

    axiom_node_t *x509_data_node = NULL;
    axiom_node_t *x509_issuer_serial_node = NULL;

    axis2_char_t *issuer = NULL;
    axis2_char_t *serial_num = NULL;
    int serial = -1;

    issuer = oxs_x509_cert_get_issuer(cert, env);
    serial = oxs_x509_cert_get_serial_number(cert, env);

    if(!issuer || (serial_num <0)){
        return AXIS2_FAILURE;
    }
    serial_num = AXIS2_MALLOC(env->allocator, 10);
    sprintf(serial_num, "%d", serial);
    /*Build tokens*/
    x509_data_node = oxs_token_build_x509_data_element(env, parent);
    x509_issuer_serial_node = oxs_token_build_x509_issuer_serial_with_data(env, x509_data_node, issuer, serial_num);

    return AXIS2_SUCCESS;


}

