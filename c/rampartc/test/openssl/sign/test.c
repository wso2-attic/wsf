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
#include <axutil_env.h>
#include <oxs_buffer.h>
#include <oxs_error.h>
#include <oxs_key_mgr.h>
#include <openssl_sign.h>
#include <openssl_digest.h>
#include <openssl_constants.h>
#include <openssl_pkey.h>
#include <oxs_axis2_utils.h>
#include <oxs_x509_cert.h>

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

axiom_node_t* 
load_sample_xml(const axutil_env_t *env,
        axis2_char_t* filename
               )
{

    axiom_document_t *doc = NULL;
    axiom_stax_builder_t *builder = NULL;
    axiom_xml_reader_t *reader = NULL;
    /*axiom_xml_writer_t *writer = NULL;*/
    axiom_node_t *tmpl = NULL;

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

axis2_char_t *
c14n(axutil_env_t *env, axis2_char_t* filename)
{
    axiom_document_t *doc = NULL;
    axis2_char_t *algo = NULL;
    axis2_char_t *c14nized = NULL;
    axiom_node_t *input = NULL;
    FILE *outf = NULL;

    input = load_sample_xml(env, filename); 
    doc = axiom_node_get_document(input, env);
    algo = OXS_HREF_TRANSFORM_XML_EXC_C14N; 
    oxs_c14n_apply_algo(env, doc, &c14nized, NULL, (axiom_node_t*)input, algo);
    outf = fopen("c14n.txt", "w");
    fwrite(c14nized, 1, strlen(c14nized), outf);
    return c14nized;
}

axis2_char_t* digest(axutil_env_t *env, axis2_char_t *in){
    axis2_char_t *dg = NULL;
    FILE *outf = NULL;

    dg = openssl_sha1(env, in, strlen(in));
    outf = fopen("digest.txt", "w");
    fwrite(dg, 1, strlen(dg), outf);
    printf("DIGEST = %s", dg);
    return dg;
}

int main()
{
    axutil_env_t *env = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    oxs_buffer_t *inbuf = NULL;
    oxs_buffer_t *outbuf = NULL;
    openssl_pkey_t *prvkey = NULL;
    openssl_pkey_t *pubkey = NULL;
    oxs_x509_cert_t *cert = NULL;
    char *data = "Winners in good times and survivors in hard times";
    int len = -1;

    env = axutil_env_create_all("./openssl.log", AXIS2_LOG_LEVEL_TRACE);
#if 0
    /*new code*/
    {
        axis2_char_t *c14op = NULL;
        axis2_char_t *digestop = NULL;
        /*FILE *inf = NULL;*/
        /*c14op = c14n(env, "input.xml");*/
        /*inf = fopen("c14n.txt", "r");
        c14op = malloc(2000);
        fread(c14op, 1, 1999, inf);*/
        c14op = "<soapenv:Body xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" wsu:Id=\"Id-26953436\"><example1:echo xmlns:example1=\"http://example1.org/example1\"><example1:Text>Testing Rampart with WS-SecPolicy</example1:Text></example1:echo></soapenv:Body>";
        digestop = digest(env, c14op);
        return 0;
    }
    /*eof new code*/
#endif
    /*Load private key*/
    prvkey = oxs_key_mgr_load_private_key_from_pem_file(env, "key.pem", "");
    if(!prvkey){
            printf("Cannot load private key");
            return 0;
    }

    /*Load certificate*/
    cert = oxs_key_mgr_load_x509_cert_from_pem_file(env, "cert.pem");
    if(!cert){
         printf("Cannot load certificate");
         return 0;
    }

    inbuf = oxs_buffer_create(env);
    oxs_buffer_populate(inbuf, env, (unsigned char *)data, strlen(data));

    outbuf = oxs_buffer_create(env);
    
    /*Sign*/
    printf("Signing\n");
    len = openssl_sig_sign(env, prvkey, inbuf, outbuf);
    if(len < 0 ){
        printf("Signing failed\n");
        return 0;
    }else{
        printf("Signing OK. Sig len = %d\n", len);
    }


    /*Verify*/
    printf("Verifying\n");
    pubkey = oxs_x509_cert_get_public_key(cert, env);
    
    status = openssl_sig_verify(env, pubkey, inbuf, outbuf);
    if(AXIS2_SUCCESS != status){
        printf("Sign verification failed\n");
    }else{
        printf("Sign verification success\n");

    }

    
    return 0;
}
