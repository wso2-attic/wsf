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
#include <axutil_qname.h>
#include <axiom_namespace.h>
#include <axiom_node.h>
#include <axiom_util.h>
#include <axiom_element.h>
#include <axis2_util.h>
#include <oxs_tokens.h>
#include <oxs_constants.h>
#include <oxs_axiom.h>
#include <oxs_ctx.h>
#include <oxs_error.h>
#include <oxs_buffer.h>
#include <oxs_cipher.h>
#include <oxs_iv.h>
#include <oxs_utility.h>
#include <oxs_encryption.h>
#include <oxs_xml_encryption.h>

/*private functions*/

/**
*   <KeyInfo>
*       <SecurityTokenReference>
*           <KeyIdentifier>WEqswOIUsd</KeyIdentifier>
*       </SecurityTokenReference>
*   </KeyInfo>
*   
*/
static axis2_status_t
oxs_xml_enc_populate_stref_with_key_identifier(const axutil_env_t *env,
        oxs_asym_ctx_t *asym_ctx,
        axiom_node_t *stref_node)
{
    axiom_node_t *key_identifier_node = NULL;
    axis2_char_t *key_identifier = NULL;
    oxs_x509_cert_t *cert = NULL;

    cert = oxs_asym_ctx_get_certificate(asym_ctx, env);
    key_identifier = oxs_x509_cert_get_key_identifier(cert, env);
    if(!key_identifier){
        return AXIS2_FAILURE;
    }

    /*Build KeyIdentifier node*/
    key_identifier_node = oxs_token_build_key_identifier_element(
                              env, stref_node, OXS_ENCODING_BASE64BINARY,
                              OXS_X509_SUBJ_KI, key_identifier);

    return AXIS2_SUCCESS;
}

/**
*  
*   <BinarySecurityToken ID="CertID">KJDSsdlDJjsd=</BinarySecurityToken>
*   <KeyInfo>
*       <SecurityTokenReference>
*           <Reference URI="CertID"/>
*       </SecurityTokenReference>
*   </KeyInfo>
*/
static axis2_status_t
oxs_xml_enc_populate_stref_with_bst(const axutil_env_t *env,
                                    oxs_asym_ctx_t *asym_ctx,
                                    axiom_node_t *stref_node,
                                    axiom_node_t *parent)
{
    axiom_node_t *ref_node = NULL;
    axiom_node_t *bst_node = NULL;
    axis2_char_t *bst_data = NULL;
    axis2_char_t *id = NULL;
    oxs_x509_cert_t *cert = NULL;

    cert = oxs_asym_ctx_get_certificate(asym_ctx, env);
    bst_data = oxs_x509_cert_get_data(cert, env);

    if(!bst_data){
        return AXIS2_FAILURE;
    }
    /*Generate an ID for BST*/
    id = oxs_util_generate_id(env,(axis2_char_t*)OXS_CERT_ID);

    /*Build BinarySecurityToken as a child of parent(wsse:Security)*/
    bst_node = oxs_token_build_binary_security_token_element(env, parent, id, OXS_VALUE_X509V3, OXS_ENCODING_BASE64BINARY, bst_data);

    /*Build a Reference to above BST*/
    ref_node = oxs_token_build_reference_element(env, stref_node, id, OXS_VALUE_X509V3);

    return AXIS2_SUCCESS;
}
/**
*   <KeyInfo>
*       <SecurityTokenReference>
*           <Embedded>
*               <BinarySecurityToken>UYISDjsdaousdWEqswOIUsd</BinarySecurityToken>
*           </Embedded>
*       </SecurityTokenReference>
*   </KeyInfo>
*/
static axis2_status_t
oxs_xml_enc_populate_stref_with_embedded(const axutil_env_t *env,
        oxs_asym_ctx_t *asym_ctx,
        axiom_node_t *stref_node)
{
    axiom_node_t *embedded_node = NULL;
    axiom_node_t *bst_node = NULL;
    axis2_char_t *bst_data = NULL;
    oxs_x509_cert_t *cert = NULL;

    cert = oxs_asym_ctx_get_certificate(asym_ctx, env);
    bst_data = oxs_x509_cert_get_data(cert, env);

    if(!bst_data){
        return AXIS2_FAILURE;
    }
    /*Build embedded token*/
    embedded_node = oxs_token_build_embedded_element(env, stref_node, NULL);
    /*Build BinarySecurityToken*/
    bst_node = oxs_token_build_binary_security_token_element(env, embedded_node, NULL, OXS_VALUE_X509V3, OXS_ENCODING_BASE64BINARY, bst_data);

    return AXIS2_SUCCESS;
}

/**
*   <KeyInfo>
*       <SecurityTokenReference>
*           <x509Data>
*               <X509IssuerSerial>
*                   <X509IssuerName>C=US, O=VeriSign, Inc.,</X509IssuerName>
*                   <X509SerialNumber>93243297328</X509SerialNumber>
*               </X509IssuerSerial>
*           </x509Data>
*       </SecurityTokenReference>
*   </KeyInfo>
*/
static axis2_status_t
oxs_xml_enc_populate_stref_with_issuer_serial(const axutil_env_t *env,
        oxs_asym_ctx_t *asym_ctx,
        axiom_node_t *stref_node)
{
    axiom_node_t *x509_data_node = NULL;
    axiom_node_t *issuer_serial_node = NULL;
    oxs_x509_cert_t *cert = NULL;
    axis2_char_t *issuer_name = NULL;
    axis2_char_t serial_number[255];
    int serial = -1;

    cert = oxs_asym_ctx_get_certificate(asym_ctx, env);

    issuer_name = oxs_x509_cert_get_issuer(cert, env);
    serial =  oxs_x509_cert_get_serial_number(cert, env);
    if((!issuer_name) || (serial<0)){
        return AXIS2_FAILURE;
    }

    sprintf(serial_number, "%d", serial);
    /*Build x509Data*/
    x509_data_node = oxs_token_build_x509_data_element(env, stref_node);
    issuer_serial_node = oxs_token_build_x509_issuer_serial_with_data(env, x509_data_node, issuer_name, serial_number);
    return AXIS2_SUCCESS;
}

static axis2_status_t
oxs_xml_enc_process_key_info(const axutil_env_t *env,
                             oxs_asym_ctx_t *asym_ctx,
                             axiom_node_t *key_info_node,
                             axiom_node_t *parent_node)
{
    axiom_node_t *st_ref_node = NULL;
    axiom_node_t *cur_node = NULL;
    axis2_char_t *node_name = NULL;

    st_ref_node =  oxs_axiom_get_first_child_node_by_name(env, key_info_node, OXS_NODE_SECURITY_TOKEN_REFRENCE,OXS_WSSE_XMLNS,OXS_WSSE);
    if(!st_ref_node){
        return AXIS2_FAILURE;
    }
    /*
        WSS-Core specification suggests
        1. Resolve any <wsse:Reference> elements (specified within
           <wsse:SecurityTokenReference>).
        2. Resolve any <wsse:KeyIdentifier> elements (specified within
           <wsse:SecurityTokenReference>).
        3. Resolve any <ds:KeyName> elements. NOT PERMITTED by WS-i
        4. Resolve any other <ds:KeyInfo> elements. NOT PERMITTED by WS-i
    */

    /*
     * Implementation of these are not important for Encryption.
     * Might've to relocate to another file as this processing is essential in Signature
     */
    cur_node = axiom_node_get_first_element(st_ref_node, env);
    node_name = axiom_util_get_localname(cur_node, env);
    if(0 == axutil_strcmp(OXS_NODE_REFERENCE, node_name)){

    }
    else if(0 == axutil_strcmp(OXS_NODE_KEY_IDENTIFIER, node_name)){

    }
    else if(0 == axutil_strcmp(OXS_NODE_X509_DATA, node_name)){

    }
    else if(0 == axutil_strcmp(OXS_NODE_EMBEDDED, node_name)){

    }
    else{
        /*Unsupported*/
    }

    return AXIS2_SUCCESS;
}

/*public functions*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_enc_encrypt_node(const axutil_env_t *env,
                         oxs_ctx_t * enc_ctx,
                         axiom_node_t *node,
                         axiom_node_t **enc_type_node)
{
    axis2_char_t *serialized_data = NULL;
    oxs_buffer_t *serialized_buf= NULL;
    axis2_status_t ret = AXIS2_FAILURE;

    /*Serialize node*/
    serialized_data = axiom_node_to_string(node, env);
    serialized_buf = oxs_buffer_create(env);
    ret =  oxs_buffer_populate(serialized_buf, env, (unsigned char *)serialized_data, axutil_strlen(serialized_data));

    /*We call encrypt_data*/
    ret = oxs_xml_enc_encrypt_data(env, enc_ctx, serialized_buf, enc_type_node);

    /*Remove the node from the parent*/
    if(AXIS2_SUCCESS == ret){
        axiom_node_detach(node, env);
    }
    /*Free*/
    oxs_buffer_free(serialized_buf, env);
    serialized_buf = NULL;

    /*Return success*/
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_enc_encrypt_data(const axutil_env_t *env,
                         oxs_ctx_t * enc_ctx,
                         oxs_buffer_t *content_buf,
                         axiom_node_t **enc_type_node)
{
    oxs_buffer_t *result_buf= NULL;
    oxs_key_t *sym_key = NULL;
    axis2_char_t *sym_algo = NULL;
    axiom_node_t *enc_mtd_node = NULL;
    axiom_node_t *cd_node = NULL;
    axiom_node_t *cv_node = NULL;
    axis2_status_t ret = AXIS2_FAILURE;

    /*Determine the algorithm to be used*/
    sym_algo = oxs_ctx_get_enc_mtd_algorithm(enc_ctx, env);

    /*Determine the key to be used*/
    sym_key = oxs_ctx_get_key(enc_ctx, env);

    /*Set the operation to encrypt*/
    oxs_ctx_set_operation(enc_ctx, env, OXS_CTX_OPERATION_ENCRYPT);

    /*Create an empty buffer for encrypted data*/
    result_buf = oxs_buffer_create(env);
    /*Call encryption. Result should be base64 encoded*/
    ret = oxs_encryption_symmetric_crypt(env, enc_ctx, content_buf, result_buf);

    /*Create EncryptionMethod, CipherData element and populate*/
    enc_mtd_node = oxs_token_build_encryption_method_element(env, *enc_type_node, sym_algo);
    cd_node = oxs_token_build_cipher_data_element(env, *enc_type_node);
    cv_node = oxs_token_build_cipher_value_element(env, cd_node, (axis2_char_t*)oxs_buffer_get_data(result_buf, env));

    /*Free buffers*/
    oxs_buffer_free(result_buf, env);
    result_buf = NULL;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_enc_decrypt_node(const axutil_env_t *env,
                         oxs_ctx_t * enc_ctx,
                         axiom_node_t *enc_type_node,
                         axiom_node_t **decrypted_node)
{
    axiom_node_t *deserialized_node = NULL;
    axiom_node_t *parent_of_enc_node = NULL;
    oxs_buffer_t *result_buf = NULL;
    axis2_char_t *decrypted_data = NULL;/*Can be either am XML-Element or XML-Content*/
    axis2_status_t status = AXIS2_FAILURE;

    /*Create an empty buffer for results*/
    result_buf = oxs_buffer_create(env);

    /*Decrypt*/
    status = oxs_xml_enc_decrypt_data(env, enc_ctx, enc_type_node, result_buf);
    if(AXIS2_FAILURE == status){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_ENCRYPT_FAILED,
                  "Data encryption failed");
        return AXIS2_FAILURE;
    }
    decrypted_data = axutil_strmemdup(oxs_buffer_get_data(result_buf, env), oxs_buffer_get_size(result_buf, env), env);
    /*De-serialize the decrypted content to build the node*/
    deserialized_node = (axiom_node_t*)oxs_axiom_deserialize_node(env, decrypted_data);
    if(!deserialized_node){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_ENCRYPT_FAILED,"Cannot deserialize a node from the content.\n%s", decrypted_data);
        return AXIS2_FAILURE;
    }
    /*Assign deserialized_node to the reference passed*/
    *decrypted_node = deserialized_node;

    /*Replace the encrypted node with the de-serialized node*/
    parent_of_enc_node = axiom_node_get_parent(enc_type_node, env);
    axiom_node_add_child(parent_of_enc_node, env, deserialized_node);
    axiom_node_detach(enc_type_node, env);

    oxs_buffer_free(result_buf, env);
    result_buf = NULL;

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_enc_decrypt_data(const axutil_env_t *env,
                         oxs_ctx_t * enc_ctx,
                         axiom_node_t *enc_type_node,
                         oxs_buffer_t *result_buf)
{
    axiom_node_t *enc_mtd_node = NULL;
    axiom_node_t *cd_node = NULL;
    axiom_node_t *cv_node = NULL;
    axis2_char_t *cipher_val = NULL;
    axis2_char_t *sym_algo = NULL;
    axis2_char_t *type = NULL;
    axis2_char_t *id = NULL;
    oxs_buffer_t *input_buf = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    /*Get the symmetric encryption algorithm*/
    enc_mtd_node = oxs_axiom_get_first_child_node_by_name(env, enc_type_node, OXS_NODE_ENCRYPTION_METHOD,OXS_ENC_NS,OXS_XENC);
    sym_algo = oxs_token_get_encryption_method(env, enc_mtd_node);
    if(!sym_algo){
        return AXIS2_FAILURE;
    }
    /*Get ID, Type, MimeType attributes from the EncryptedDataNode*/
    id = oxs_axiom_get_attribute_value_of_node_by_name(env, enc_type_node, OXS_ATTR_ID);
    type = oxs_axiom_get_attribute_value_of_node_by_name(env, enc_type_node, OXS_ATTR_TYPE);

    /*Populate the context for future use*/
    oxs_ctx_set_enc_mtd_algorithm(enc_ctx, env, sym_algo);
    oxs_ctx_set_id(enc_ctx, env, id);
    oxs_ctx_set_id(enc_ctx, env, type);

    /*Get the cipher value*/
    cd_node = oxs_axiom_get_first_child_node_by_name(env, enc_type_node, OXS_NODE_CIPHER_DATA,OXS_ENC_NS,OXS_XENC);
    cv_node = oxs_axiom_get_first_child_node_by_name(env, cd_node, OXS_NODE_CIPHER_VALUE,OXS_ENC_NS,OXS_XENC);
    cipher_val = oxs_token_get_cipher_value(env, cv_node);

    /*Create input buffer with cipher data obtained*/
    input_buf = oxs_buffer_create(env);
    oxs_buffer_populate(input_buf, env, (unsigned char*)cipher_val, axutil_strlen(cipher_val) );

    /*Decrypt*/
    oxs_ctx_set_operation(enc_ctx, env, OXS_CTX_OPERATION_DECRYPT);
    status =  oxs_encryption_symmetric_crypt(env, enc_ctx, input_buf, result_buf);

    /*Free*/
    oxs_buffer_free(input_buf, env);
    input_buf = NULL;

    return status;
}

/*For SOAP this parent is the wsse:Security node*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_enc_encrypt_key(const axutil_env_t *env,
                        oxs_asym_ctx_t * asym_ctx,
                        axiom_node_t *parent,
                        oxs_key_t *sym_key,
                        axutil_array_list_t *id_list)
{
    axis2_char_t *algorithm = NULL;
    axis2_char_t *encrypted_key_data = NULL;
    axis2_char_t *st_ref_pattern = NULL;
    oxs_buffer_t *input = NULL;
    oxs_buffer_t *result = NULL;
    axiom_node_t *encrypted_key_node = NULL;
    axiom_node_t *enc_mtd_node = NULL;
    axiom_node_t *key_info_node = NULL;
    axiom_node_t *stref_node = NULL;
    axiom_node_t *cd_node = NULL;
    axiom_node_t *cv_node = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    /*Create input buffer*/
    input = oxs_buffer_create(env);
    oxs_buffer_populate(input, env, oxs_key_get_data(sym_key, env), oxs_key_get_size(sym_key, env));

    /*Create an empty buffer to collect results*/
    result = oxs_buffer_create(env);

    /*Call encryption*/
    status = oxs_encryption_asymmetric_crypt(env, asym_ctx, input, result);
    /*Free input*/
    oxs_buffer_free(input, env);
    input = NULL;

    if(AXIS2_FAILURE == status){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_ENCRYPT_FAILED,
                  "Assymmetric key encryption failed");
        return AXIS2_FAILURE;
    }
    /*Get the encrypted key*/
    encrypted_key_data = (axis2_char_t *)oxs_buffer_get_data(result, env);

    /*Build nodes*/
    encrypted_key_node = oxs_token_build_encrypted_key_element(env, parent);
    algorithm = oxs_asym_ctx_get_algorithm(asym_ctx, env);
    enc_mtd_node = oxs_token_build_encryption_method_element(env, encrypted_key_node, algorithm);
    key_info_node = oxs_token_build_key_info_element(env, encrypted_key_node);

    stref_node = oxs_token_build_security_token_reference_element(env, key_info_node);
    /*Get the ST REF pattern. If not set the default*/
    st_ref_pattern = oxs_asym_ctx_get_st_ref_pattern(asym_ctx, env);
    if((!st_ref_pattern) || (0 == axutil_strcmp(st_ref_pattern, ""))){
        st_ref_pattern = OXS_STR_DEFAULT;
    }

    if(0 == axutil_strcmp(st_ref_pattern, OXS_STR_ISSUER_SERIAL)){
        status = oxs_xml_enc_populate_stref_with_issuer_serial(env, asym_ctx, stref_node);
    }else if(0 == axutil_strcmp(st_ref_pattern, OXS_STR_EMBEDDED)){
        status = oxs_xml_enc_populate_stref_with_embedded(env, asym_ctx, stref_node);
    }else if(0 == axutil_strcmp(st_ref_pattern, OXS_STR_DIRECT_REFERENCE)){
        status = oxs_xml_enc_populate_stref_with_bst(env, asym_ctx, stref_node, parent);
    }else if(0 == axutil_strcmp(st_ref_pattern, OXS_STR_KEY_IDENTIFIER)){
        status = oxs_xml_enc_populate_stref_with_key_identifier(env, asym_ctx, stref_node);
    }


    cd_node = oxs_token_build_cipher_data_element(env, encrypted_key_node);
    cv_node = oxs_token_build_cipher_value_element(env, cd_node,  encrypted_key_data);
    oxs_token_build_data_reference_list(env, encrypted_key_node, id_list);

    /*Free*/
    oxs_buffer_free(result, env);
    result = NULL;

    return AXIS2_SUCCESS;
}

/**
* Inspect the key node. Then populate the sym_key
*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_xml_enc_decrypt_key(const axutil_env_t *env,
                        oxs_asym_ctx_t * asym_ctx,
                        axiom_node_t *parent,
                        axiom_node_t *encrypted_key_node,
                        oxs_key_t *key)
{
    axiom_node_t *enc_mtd_node = NULL;
    axiom_node_t *key_info_node = NULL;
    axiom_node_t *cd_node = NULL;
    axis2_char_t *enc_mtd_algo = NULL;
    axis2_char_t *cipher_val = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    oxs_buffer_t *input_buf = NULL;
    oxs_buffer_t *result_buf = NULL;

    /*Get encryption method algorithm*/
    enc_mtd_node = oxs_axiom_get_first_child_node_by_name(env, encrypted_key_node, OXS_NODE_ENCRYPTION_METHOD,OXS_ENC_NS,OXS_XENC);
    enc_mtd_algo = oxs_token_get_encryption_method(env, enc_mtd_node);
    if(!enc_mtd_algo){
        return AXIS2_FAILURE;
    }
    /*Get cipher data*/
    cd_node = oxs_axiom_get_first_child_node_by_name(env, encrypted_key_node, OXS_NODE_CIPHER_DATA,OXS_ENC_NS,OXS_XENC);
    cipher_val = oxs_token_get_cipher_value_from_cipher_data(env, cd_node);
    if(!cipher_val){
        return AXIS2_FAILURE;
    }

    /*Get key used to encrypt*/
    key_info_node = oxs_axiom_get_first_child_node_by_name(env, encrypted_key_node, OXS_NODE_KEY_INFO,OXS_DSIG_NS,OXS_DS);
    status = oxs_xml_enc_process_key_info(env, asym_ctx, key_info_node, parent);
    /*Right now we support KeyInfo -> SecurityTokenReference -> Reference
                           KeyInfo -> SecurityTokenReference -> X509IssuerSerial */


    /*Get the pkey used to decrypt the session key. If found set it to the asym_ctx*/
    /*Create the input buffer*/
    input_buf = oxs_buffer_create(env);
    oxs_buffer_populate(input_buf, env, (unsigned char*)cipher_val, axutil_strlen(cipher_val));

    /*Create a results buffer*/
    result_buf = oxs_buffer_create(env);

    /*Call decryption*/
    status = oxs_encryption_asymmetric_crypt(env, asym_ctx, input_buf, result_buf);
    /*Free input*/
    oxs_buffer_free(input_buf, env);
    input_buf = NULL;

    if(AXIS2_FAILURE == status){
        return AXIS2_FAILURE;
    }

    /*Populate the key with the data in the result buffer*/
    oxs_key_populate(key, env,
                     oxs_buffer_get_data(result_buf, env),
                     "decrypted_session_key",
                     oxs_buffer_get_size(result_buf, env),
                     OXS_KEY_USAGE_DECRYPT  );
    /*Free*/
    oxs_buffer_free(result_buf, env);
    result_buf = NULL;

    return AXIS2_SUCCESS;
}
