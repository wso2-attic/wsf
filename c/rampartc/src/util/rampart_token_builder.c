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

/*
 *
 */
#include <stdio.h>
#include <rampart_util.h>
#include <axis2_util.h>
#include <axutil_base64.h>
#include <oxs_buffer.h>
#include <rampart_constants.h>
#include <rampart_token_builder.h>
#include <oxs_constants.h>
#include <oxs_key_mgr.h>
#include <oxs_axiom.h>
#include <oxs_x509_cert.h>
#include <oxs_xml_key_processor.h>
#include <oxs_tokens.h>
#include <oxs_utility.h>

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_build_security_token_reference(const axutil_env_t *env,
        axiom_node_t *parent,
        oxs_x509_cert_t *cert,
        rampart_token_build_pattern_t pattern)
{
    axis2_status_t status = AXIS2_FAILURE;
    axiom_node_t *stref_node = NULL;

    stref_node = oxs_token_build_security_token_reference_element(env, parent);

    if(RTBP_EMBEDDED == pattern){
        status = rampart_token_build_embedded(env, stref_node, cert);
    }else if(RTBP_KEY_IDENTIFIER == pattern){
        status = rampart_token_build_key_identifier(env, stref_node, cert);
    }else if(RTBP_X509DATA_X509CERTIFICATE == pattern){
        status = rampart_token_build_x509_data_x509_certificate(env, stref_node, cert);
    }else if(RTBP_X509DATA_ISSUER_SERIAL == pattern){
        status = rampart_token_build_x509_data_issuer_serial(env, stref_node, cert);
    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_ELEMENT_FAILED, "Unsupported pattern %d to build wsse:SecurityTokenReference ", pattern);
        /*We do not support*/
        return AXIS2_FAILURE;
    }

    return status;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_build_embedded(const axutil_env_t *env,
                             axiom_node_t *parent,
                             oxs_x509_cert_t *cert)
{
    axis2_char_t *data  = NULL;
    axis2_char_t *bst_id  = NULL;
    axiom_node_t *embedded_node = NULL;
    axiom_node_t *bst_node = NULL;

    /*Get data from the certificate*/
    data = oxs_x509_cert_get_data(cert, env);
    if(!data){
        return AXIS2_FAILURE;
    }
    embedded_node = oxs_token_build_embedded_element(env, parent, "ID");
    bst_id = oxs_util_generate_id(env, (axis2_char_t*)"BST-");
    bst_node =  oxs_token_build_binary_security_token_element(env, embedded_node, bst_id , OXS_VALUE_X509V3, OXS_ENCODING_BASE64BINARY, data);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_build_key_identifier(const axutil_env_t *env,
                                   axiom_node_t *parent,
                                   oxs_x509_cert_t *cert)
{
    axiom_node_t *ki_node = NULL;
    axis2_char_t *ki =  NULL;

    ki = oxs_x509_cert_get_key_identifier(cert, env);
    if(!ki){
        return AXIS2_FAILURE;
    }
    ki_node = oxs_token_build_key_identifier_element(env, parent, OXS_ENCODING_BASE64BINARY,
              OXS_X509_SUBJ_KI, ki);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_build_x509_data_x509_certificate(const axutil_env_t *env,
        axiom_node_t *parent,
        oxs_x509_cert_t *cert)
{
    axiom_node_t *x509_data_node = NULL;
    axiom_node_t *x509_cert_node = NULL;
    axis2_char_t *data = NULL;


    data = oxs_x509_cert_get_data(cert, env);
    if(!data){
        return AXIS2_FAILURE;
    }

    x509_data_node = oxs_token_build_x509_data_element(env, parent);
    x509_cert_node = oxs_token_build_x509_certificate_element(env, x509_data_node, data);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_build_x509_data_issuer_serial(const axutil_env_t *env,
        axiom_node_t *parent,
        oxs_x509_cert_t *cert)
{
    axiom_node_t *x509_data_node = NULL;
    axiom_node_t *x509_issuer_serial_node = NULL;

    axis2_char_t *issuer = NULL;
    /*axis2_char_t *serial_num = NULL;*/
    int serial = -1;
    axis2_char_t serial_no[20];

    issuer = oxs_x509_cert_get_issuer(cert, env);
    serial = oxs_x509_cert_get_serial_number(cert, env);

    if(!issuer){
        return AXIS2_FAILURE;
    }

    sprintf(serial_no, "%d", serial);
    /*Build tokens*/
    x509_data_node = oxs_token_build_x509_data_element(env, parent);
    x509_issuer_serial_node = oxs_token_build_x509_issuer_serial_with_data(env, x509_data_node, issuer, serial_no);

    return AXIS2_SUCCESS;

}
