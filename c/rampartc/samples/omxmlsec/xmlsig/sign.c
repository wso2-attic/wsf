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
#include <oxs_axiom.h>
#include <axiom.h>
#include <axiom_xml_reader.h>
#include <axutil_env.h>
#include <oxs_ctx.h>
#include <oxs_key.h>
#include <oxs_key_mgr.h>
#include <openssl_pkey.h>
#include <oxs_error.h>
#include <oxs_transform.h>
#include <oxs_transforms_factory.h>
#include <oxs_xml_signature.h>
#include <oxs_sign_ctx.h>
#include <oxs_sign_part.h>
#include <oxs_xml_key_processor.h>
#include <oxs_xml_key_info_builder.h>

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
load_sample_xml(const axutil_env_t *env,
        axiom_node_t* tmpl,
        axis2_char_t* filename
               )
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

    /*    tmpl = axiom_document_get_root_element(doc, env);*/
    if (!tmpl) printf("\n tmpl is NULL");
    return tmpl;
}

axis2_status_t sign(axutil_env_t *env,
    axis2_char_t *filename,
    openssl_pkey_t *prvkey ,
    oxs_x509_cert_t *cert)
{
    axis2_char_t *signed_result = NULL;
    axis2_char_t *signed_filename = "result-sign.xml";
    axiom_node_t *node = NULL;
    axiom_node_t *tmpl = NULL;
    oxs_sign_part_t *sign_part = NULL;
    oxs_sign_ctx_t *sign_ctx = NULL;
    oxs_transform_t *tr = NULL;
    axutil_array_list_t *sign_parts = NULL;
    axutil_array_list_t *tr_list = NULL;
    axis2_char_t *id = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    FILE *outf;
    
    tmpl = load_sample_xml(env , tmpl, filename);

    if (tmpl)
    {
        printf("load_sample_xml SUCCESS\n");
    }
    else
    {
        printf("load_sample_xml FAILED");
        return -1;
    }
    
     /*Sign specific*/
    sign_part = oxs_sign_part_create(env);

    tr_list = axutil_array_list_create(env, 1);
    /*We need C14N transform*/
    tr = oxs_transforms_factory_produce_transform(env, OXS_HREF_TRANSFORM_XML_EXC_C14N);
    axutil_array_list_add(tr_list, env, tr);
    oxs_sign_part_set_transforms(sign_part, env, tr_list);

    /*We need to sign this node add an ID to it*/
    node = axiom_node_get_first_element(tmpl, env);
    id = /*"Sig-ID-EFG";*/  oxs_util_generate_id(env,(axis2_char_t*)OXS_SIG_ID);
    oxs_axiom_add_attribute(env, node, OXS_WSU, OXS_WSSE_XMLNS,  OXS_ATTR_ID, id);
    status = oxs_sign_part_set_node(sign_part, env,node);

    status = oxs_sign_part_set_digest_mtd(sign_part, env, OXS_HREF_SHA1);

    sign_parts = axutil_array_list_create(env, 1);
    axutil_array_list_add(sign_parts, env, sign_part);
    sign_ctx = oxs_sign_ctx_create(env);
    if(sign_ctx){
        axiom_node_t *sig_node = NULL;

        oxs_sign_ctx_set_private_key(sign_ctx, env, prvkey);
        oxs_sign_ctx_set_certificate(sign_ctx, env, cert);
        /*Set sig algo*/
        oxs_sign_ctx_set_sign_mtd_algo(sign_ctx, env, OXS_HREF_RSA_SHA1);
        /*Set C14N method*/
        oxs_sign_ctx_set_c14n_mtd(sign_ctx, env, OXS_HREF_XML_EXC_C14N);
        /*Set sig parts*/
        oxs_sign_ctx_set_sign_parts(sign_ctx, env, sign_parts);
        /*Set the operation*/
        oxs_sign_ctx_set_operation(sign_ctx, env, OXS_SIGN_OPERATION_SIGN);
        /*Sign*/
        oxs_xml_sig_sign(env, sign_ctx, tmpl, &sig_node);
        /*Finally build KeyInfo*/
        oxs_xml_key_info_build(env, sig_node, cert, OXS_KIBP_X509DATA_X509CERTIFICATE);
    }else{
        printf("Sign ctx creation failed");
    }
    signed_result = axiom_node_to_string(tmpl, env) ;

    outf = fopen(signed_filename, "wb");
    fwrite(signed_result, 1, axutil_strlen(signed_result), outf);

    return AXIS2_SUCCESS;

}

axis2_status_t verify(axutil_env_t *env,
        axis2_char_t *filename,
        openssl_pkey_t *prvkey ,
        oxs_x509_cert_t *cert)
{
    oxs_sign_ctx_t *sign_ctx = NULL;
    axiom_node_t *tmpl = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    tmpl = load_sample_xml(env , tmpl, filename);
    printf("File : \n%s\n", axiom_node_to_string(tmpl, env));
    sign_ctx = oxs_sign_ctx_create(env);
    if(sign_ctx){
        axiom_node_t *sig_node = NULL;
        /*Set the operation*/
        oxs_sign_ctx_set_operation(sign_ctx, env, OXS_SIGN_OPERATION_VERIFY);
        
        sig_node = oxs_axiom_get_first_child_node_by_name(env, tmpl,
                                    OXS_NODE_SIGNATURE, OXS_DSIG_NS, OXS_DS );
        if(!sig_node){
            printf("Verification : Cannot find ds:Signature node\n");
            return AXIS2_FAILURE;
        }
       
        /**If the certificate is not given check key information*/
        if(!cert){
            axiom_node_t *ki_node = NULL;
            axiom_node_t *x509_node = NULL;
            ki_node = oxs_axiom_get_first_child_node_by_name(env, sig_node, OXS_NODE_KEY_INFO, OXS_DSIG_NS, OXS_DS);
            x509_node = oxs_axiom_get_first_child_node_by_name(env, ki_node, OXS_NODE_X509_DATA, OXS_DSIG_NS, OXS_DS);
           
            cert = oxs_x509_cert_create(env);
            printf("No certificate is given. Fetching certificate from the KeyInfo\n");
            status =  oxs_xml_key_process_X509Data(env, x509_node, cert);
            if(AXIS2_FAILURE == status){
                printf("Error reading KeyInfo\n");
                return AXIS2_FAILURE;
            }
        }            

        
        /*Set certificate*/
        if(cert){
            oxs_sign_ctx_set_certificate(sign_ctx, env, cert);
        }else{
            printf("Certificate is NULL\n");
            return AXIS2_FAILURE;
        }
        /*Verify*/
        status = oxs_xml_sig_verify(env, sign_ctx, sig_node, tmpl);
        if(AXIS2_SUCCESS != status){
            printf("\nSignature Failed :-(\n");
        }else{
            printf("\nSignature Verified :-)\n");
        }
    }

    return status;
}

int main(int argc, char *argv[])
{
    axutil_env_t *env = NULL;
    axis2_char_t *filename = NULL;
    axis2_char_t *certfile = NULL;
    axis2_char_t *prvkeyfile = NULL;
    axis2_char_t *operation = NULL;
    openssl_pkey_t *prvkey = NULL;
    oxs_x509_cert_t *cert = NULL;


    if (argc > 2){
        filename = argv[1];
        operation = argv[2];
        certfile = argv[3];
        prvkeyfile = argv[4];
    }else{
        printf("Usage ./test inputfile operation[S/V] certificate prvkey \n");
        return -1;
    }
    
    env = axutil_env_create_all("./oxs.log", AXIS2_LOG_LEVEL_TRACE);
    printf("--Testing started--------------------------------------------\n");
    
    /*Load private key*/
    prvkey = oxs_key_mgr_load_private_key_from_pem_file(env, prvkeyfile, "");
    if(!prvkey){
            printf("Cannot load private key");
    }

    /*Load certificate*/
    cert = oxs_key_mgr_load_x509_cert_from_pem_file(env, certfile);
    if(!cert){
         printf("Cannot load certificate");
    }
    
    if(0 == axutil_strcmp(operation, "S")){
        sign(env, filename, prvkey, cert);
    }else{
        verify(env, filename, prvkey, cert);
    }

    printf("\nDONE\n");
    return 0;
}
