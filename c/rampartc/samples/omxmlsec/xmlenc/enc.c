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
#include <oxs_utility.h>
#include <axiom.h>
#include <axiom_xml_reader.h>
#include <axutil_env.h>
#include <oxs_ctx.h>
#include <oxs_key.h>
#include <oxs_error.h>
#include <oxs_encryption.h>
#include <oxs_xml_encryption.h>
#include <oxs_token_encrypted_data.h>
#include <oxs_x509_cert.h>


AXIS2_EXTERN axiom_node_t* AXIS2_CALL
load_sample_xml(const axutil_env_t *env,
        axiom_node_t* tmpl,
        axis2_char_t* filename)
{

    axiom_document_t *doc = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_xml_reader_t *reader = NULL;
    /*axiom_xml_writer_t *writer = NULL;*/

    reader = axiom_xml_reader_create_for_file(env, filename, NULL);
    if (!reader) printf("\n Reader is NULL");
    builder = axiom_stax_builder_create(env, reader);
    if (!builder) printf("\n builder is NULL");
    doc = axiom_document_create(env, NULL, builder);
    if (!doc) printf("\n doc is NULL");
    tmpl = axiom_document_build_all(doc, env);

    axiom_xml_reader_xml_free(reader, env, NULL);
    /*    tmpl = axiom_document_get_root_element(doc, env);*/
    if (!tmpl) printf("\n tmpl is NULL");
    return tmpl;
}


oxs_key_t *create_key(axutil_env_t *env)
{
    oxs_key_t *key = NULL;
    key = oxs_key_create(env);
    oxs_key_populate(key, env, (unsigned char*)"012345670123456701234567", "session_key",  32, OXS_KEY_USAGE_DECRYPT);
    return key;
}

axis2_status_t 
decrypt(axutil_env_t *env,  axis2_char_t *filename)
{
    oxs_ctx_t *ctx = NULL;
    axiom_node_t *tmpl = NULL;
    axiom_node_t *enc_data_node = NULL;
    axiom_node_t *decrypted_node = NULL;
    oxs_key_t *key = NULL;

    tmpl = load_sample_xml(env , tmpl, filename);
    axis2_status_t temp_status = AXIS2_FAILURE;
    axis2_char_t *serialized_data = NULL;
    FILE *outf;

    /*Create key*/
    key = create_key(env);

    /*Create ctx*/
    ctx = oxs_ctx_create(env);
    oxs_ctx_set_key(ctx, env, key);

    /*Get the EncryptedData node*/
    enc_data_node = axiom_node_get_first_element(tmpl, env);
    temp_status = oxs_xml_enc_decrypt_node(env, ctx, enc_data_node, &decrypted_node);

    if (temp_status){
        printf("\nooxs_xml_enc_decrypt_node SUCCESS\n");
    }else{
        printf("\noxs_xml_enc_decrypt_node FAILURE\n");
    }
    serialized_data = axiom_node_to_string(tmpl, env);
    outf = fopen("decrypted-result.xml", "wb");
    fwrite(serialized_data, 1, axutil_strlen(serialized_data), outf);
    fclose(outf);
    printf("Node decrypted successfully. Result is written to decrypted-result.xml\n");
    return AXIS2_SUCCESS;
}

axis2_status_t 
encrypt(axutil_env_t *env,  axis2_char_t *filename)
{
    oxs_ctx_t *ctx = NULL;
    oxs_key_t *key = NULL;
    axis2_status_t temp_status = AXIS2_FAILURE;
    axiom_node_t *tmpl = NULL, *enc_node = NULL, *enc_data_node = NULL;
    axis2_char_t *encrypted_result = NULL;
    axis2_char_t *id = NULL;
    FILE *outf;
    
    tmpl = load_sample_xml(env , tmpl, filename);

    /*Create key*/
    key = create_key(env);
   
    /*Create ctx*/
    ctx = oxs_ctx_create(env);
    oxs_ctx_set_key(ctx, env, key);

    /*Set algorithm*/
    oxs_ctx_set_enc_mtd_algorithm(ctx, env, OXS_HREF_DES3_CBC);

    /*Get the node to be encrypted*/
    enc_node = axiom_node_get_first_element(tmpl, env);

    /*Create a reference to encrypted node*/
    id =  oxs_util_generate_id(env, OXS_ENCDATA_ID);
    enc_data_node =  oxs_token_build_encrypted_data_element(env, tmpl, OXS_TYPE_ENC_ELEMENT, id); 

    temp_status = oxs_xml_enc_encrypt_node(env, ctx,  enc_node, &enc_data_node);

    oxs_ctx_free( ctx, env);

    if (temp_status){
        printf("\noxs_enc_encrypt_template SUCCESS\n");
    }else{
        printf("\noxs_enc_encrypt_template FAILURE\n");
    }

    encrypted_result = axiom_node_to_string(tmpl, env) ;

    outf = fopen("result.xml", "wb");
    fwrite(encrypted_result, 1, axutil_strlen(encrypted_result), outf);
    fclose(outf);
    printf("Node encrypted successfully. Result is written to result.xml\n");
    axiom_document_free( axiom_node_get_document(tmpl, env), env);
    return temp_status;
}

int main(int argc, char *argv[])
{
    axutil_env_t *env = NULL;
    axis2_char_t *filename = NULL;
    axis2_char_t *operation = NULL;

    env = axutil_env_create_all("enc.log", AXIS2_LOG_LEVEL_TRACE);

    if (argc > 2){
        filename = argv[1];
        operation = argv[2];
    }else{
        printf("Usage ./enc inputfile operation[E/D]\n");
        return -1;
    }
   
    if( 0 == axutil_strcmp(operation, "D")){
        decrypt(env, filename);
    }else{
        encrypt(env, filename);
    }
    
    return 0;
}
