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
#include <oxs_constants.h>
#include <oxs_key_mgr.h>
#include <oxs_axiom.h>
#include <oxs_x509_cert.h>
#include <oxs_token_reference.h>
#include <oxs_token_binary_security_token.h>
#include <oxs_xml_key_processor.h>
#include <rampart_token_processor.h>

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_process_security_token_reference(const axutil_env_t *env,
        axiom_node_t *st_ref_node,
        axiom_node_t *scope_node,/*Can be NULL for all other scenarios but the Direct Reference*/
        oxs_x509_cert_t *cert)
{
    axis2_char_t *child_name = NULL;
    axiom_node_t *child_node = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    child_node = axiom_node_get_first_element(st_ref_node, env);
    child_name = axiom_util_get_localname(child_node, env);

    if(0 == axutil_strcmp(child_name, OXS_NODE_REFERENCE)){
        status = rampart_token_process_direct_ref(env, child_node, scope_node, cert);
    }else if(0 == axutil_strcmp(child_name, OXS_NODE_EMBEDDED)){
        status = rampart_token_process_embedded(env, child_node, cert);
    }else if(0 == axutil_strcmp(child_name, OXS_NODE_KEY_IDENTIFIER)){
        status = rampart_token_process_key_identifier(env, child_node, cert);
    }else if(0 == axutil_strcmp(child_name, OXS_NODE_X509_DATA)){
        status = rampart_token_process_x509_data(env, child_node, cert);
    }else{
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_ELEMENT_FAILED, "Unsupported child %s of wsse:SecurityTokenReference ", child_name);
        /*We do not support*/
        return AXIS2_FAILURE;
    }

    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_process_direct_ref(const axutil_env_t *env,
                                 axiom_node_t *ref_node,
                                 axiom_node_t *scope_node,
                                 oxs_x509_cert_t *cert)
{
    axis2_char_t *ref = NULL;
    axis2_char_t *ref_id = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    axiom_node_t *bst_node = NULL;
    axis2_char_t *data = NULL;
    oxs_x509_cert_t *_cert = NULL;

    /*Select ref using node*/
    ref = oxs_token_get_reference(env, ref_node);
    ref_id = axutil_string_substring_starting_at(axutil_strdup(env, ref), 1);

    /*Find the token with the id=ref_id within the scope of scope_node*/
    bst_node = oxs_axiom_get_node_by_id(env, scope_node,"wsu:Id",ref_id);
    if(!bst_node){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_ELEMENT_FAILED, "Error retrieving element with ID=%s", ref_id);
        return AXIS2_FAILURE;
    }

    data = oxs_axiom_get_node_content(env, bst_node);
    /*Process data*/
    _cert = oxs_key_mgr_load_x509_cert_from_string(env, data);
    if(_cert){
        status =  AXIS2_SUCCESS;
    }else{
        status =  AXIS2_FAILURE;
    }

    oxs_x509_cert_copy_to(_cert, env, cert);
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_process_embedded(const axutil_env_t *env,
                               axiom_node_t *embed_node,
                               oxs_x509_cert_t *cert)
{
    axis2_status_t status = AXIS2_FAILURE;
    axis2_char_t *data = NULL;
    oxs_x509_cert_t *_cert = NULL;
    axiom_node_t *bst_node = NULL;

    bst_node = axiom_node_get_first_element(embed_node, env);

    if(!bst_node){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_ELEMENT_FAILED, "BST element is not found");
        return AXIS2_FAILURE;
    }

    data = oxs_axiom_get_node_content(env, bst_node);
    /*Process data*/
    _cert = oxs_key_mgr_load_x509_cert_from_string(env, data);
    if(_cert){
        status =  AXIS2_SUCCESS;
    }else{
        status =  AXIS2_FAILURE;
    }

    oxs_x509_cert_copy_to(_cert, env, cert);
    return status;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_process_key_identifier(const axutil_env_t *env,
                                     axiom_node_t *ki_node,
                                     oxs_x509_cert_t *cert)
{
    axis2_char_t *ki = NULL;

    ki = oxs_axiom_get_node_content(env, ki_node);
    oxs_x509_cert_set_key_identifier(cert, env, ki);

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
rampart_token_process_x509_data(const axutil_env_t *env,
                                axiom_node_t *x509_data_node,
                                oxs_x509_cert_t *cert)
{
    return oxs_xml_key_process_X509Data(env, x509_data_node, cert);
}
