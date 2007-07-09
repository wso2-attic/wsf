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
#include <oxs_xml_key_processor.h>
/*Private functions*/

/*Public functions*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_key_process_X509SKI(const axutil_env_t *env,
                            axiom_node_t *X509SKI_node,
                            oxs_x509_cert_t *cert)
{
    axis2_char_t *ski = NULL;
    axis2_char_t *node_name = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    node_name = axiom_util_get_localname(X509SKI_node, env);
    if(0 != axutil_strcmp(node_name, OXS_NODE_X509_SKI)){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,"Invalid node. Expected %s. Found", OXS_NODE_X509_SKI, node_name);
        return AXIS2_FAILURE;
    }

    ski = oxs_axiom_get_node_content(env, X509SKI_node);
    oxs_x509_cert_set_subject(cert, env, ski);

    return status;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_key_process_X509SubjectName(const axutil_env_t *env,
                                    axiom_node_t *X509_subj_name_node,
                                    oxs_x509_cert_t *cert)
{
    axis2_char_t *subj_name = NULL;
    axis2_char_t *node_name = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    node_name = axiom_util_get_localname(X509_subj_name_node, env);
    if(0 != axutil_strcmp(node_name, OXS_NODE_X509_SUBJECT_NAME)){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,"Invalid node. Expected %s. Found", OXS_NODE_X509_SUBJECT_NAME, node_name);
        return AXIS2_FAILURE;
    }

    subj_name = oxs_axiom_get_node_content(env, X509_subj_name_node);
    oxs_x509_cert_set_subject(cert, env, subj_name);

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_key_process_X509IssuerSerial(const axutil_env_t *env,
                                     axiom_node_t *X509_issuer_serial_node,
                                     oxs_x509_cert_t *cert)
{
    axiom_node_t *issuer_name_node = NULL;
    axiom_node_t *serial_num_node = NULL;
    axis2_char_t *node_name = NULL;
    axis2_char_t *issuer_name = NULL;
    axis2_char_t *serial_num_str = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    node_name = axiom_util_get_localname(X509_issuer_serial_node, env);
    if(0 != axutil_strcmp(node_name, OXS_NODE_X509_ISSUER_SERIAL)){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,"Invalid node. Expected %s. Found", OXS_NODE_X509_ISSUER_SERIAL, node_name);
        return AXIS2_FAILURE;
    }

    issuer_name_node =  axiom_node_get_first_element(X509_issuer_serial_node, env);
    if(issuer_name_node){
        issuer_name = oxs_axiom_get_node_content(env, issuer_name_node);
    }

    serial_num_node = axiom_node_get_next_sibling(issuer_name_node, env);
    if(serial_num_node){
        serial_num_str = oxs_axiom_get_node_content(env, serial_num_node);
    }

    /*we set the key issuername and the serial number*/
    oxs_x509_cert_set_issuer(cert, env, issuer_name);
    oxs_x509_cert_set_serial_number(cert, env, atoi(serial_num_str));

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_key_process_X509Certificate(const axutil_env_t *env,
                                    axiom_node_t *X509_cert_node,
                                    oxs_x509_cert_t *cert)
{
    axis2_char_t *data = NULL;
    axis2_char_t *node_name = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    oxs_x509_cert_t *_cert = NULL;
    node_name = axiom_util_get_localname(X509_cert_node, env);
    if(0 != axutil_strcmp(node_name, OXS_NODE_X509_CERTIFICATE)){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,"Invalid node. Expected %s. Found", OXS_NODE_X509_CERTIFICATE, node_name);
        return AXIS2_FAILURE;
    }
    /*Get contents*/
    data = oxs_token_get_x509_certificate(env, X509_cert_node);
    _cert = oxs_key_mgr_load_x509_cert_from_string(env, data);
    if(_cert){
        status =  AXIS2_SUCCESS;
    }else{
        status =  AXIS2_FAILURE;
    }
    oxs_x509_cert_copy_to(_cert, env, cert);
    return status;
}

AXIS2_EXTERN  axis2_status_t AXIS2_CALL
oxs_xml_key_process_X509Data(const axutil_env_t *env,
                             axiom_node_t *X509_data_node,
                             oxs_x509_cert_t *cert)
{
    axiom_node_t *child_node = NULL;
    axis2_char_t *child_name = NULL;
    axis2_char_t *node_name = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    node_name = axiom_util_get_localname(X509_data_node, env);
    if(0 != axutil_strcmp(node_name, OXS_NODE_X509_DATA)){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_INVALID_DATA,"Invalid node. Expected %s. Found", OXS_NODE_X509_DATA, node_name);
        return AXIS2_FAILURE;
    }
    child_node = axiom_node_get_first_element( X509_data_node, env);
    child_name = axiom_util_get_localname(child_node, env);

    /*Check wht's inside the <ds:X509Data>*/
    if(0 == axutil_strcmp(child_name, OXS_NODE_X509_CERTIFICATE)){
        status = oxs_xml_key_process_X509Certificate(env, child_node, cert);
    }else if(0 == axutil_strcmp(child_name, OXS_NODE_X509_ISSUER_SERIAL)){
        status = oxs_xml_key_process_X509IssuerSerial(env, child_node, cert);
    }else if(0 == axutil_strcmp(child_name, OXS_NODE_X509_SUBJECT_NAME )){
        status = oxs_xml_key_process_X509SubjectName(env, child_node, cert);
    }else if(0 == axutil_strcmp(child_name, OXS_NODE_X509_SKI )){
        status = oxs_xml_key_process_X509SKI(env, child_node, cert);
    }else{
        /*We do not support*/
    }

    return status;
}

