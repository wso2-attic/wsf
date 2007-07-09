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
#include <openssl_rsa.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/rand.h>
#include <oxs_buffer.h>
#include <oxs_error.h>
#include <openssl_pkcs12.h>
#include <openssl_x509.h>
#include <oxs_utility.h>

/*Usefull when we have BinarySecurityTokn*/
AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_x509_load_from_buffer(const axutil_env_t *env,
                              axis2_char_t *b64_encoded_buf,
                              X509 **cert)
{
    unsigned char *buff = NULL;
    BIO *mem = NULL;
    int ilen = 0;
    axis2_char_t *formatted_buf = NULL;
    axis2_char_t *buf_to_format = NULL;
    int decode_len = 0;
    int decoded_len = -1;

    /*We should remove new lines here.*/
    buf_to_format = (axis2_char_t*)axutil_strdup(env, b64_encoded_buf);
    if(buf_to_format)
    {
        formatted_buf = oxs_util_get_newline_removed_string(env,buf_to_format);
        AXIS2_FREE(env->allocator,buf_to_format);
        buf_to_format = NULL;
    }
    else
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DECRYPT_FAILED,
                  "New line removed buffer creation failed.");
        return AXIS2_FAILURE;
    }
    /*First we need to base64 decode*/
    /*  EVP_ENCODE_CTX ctx;*/
    /*  int len = 0;*/
    /*  int ret = 0;*/

    decode_len = axutil_base64_decode_len(formatted_buf );
    buff = AXIS2_MALLOC(env->allocator, decode_len);

    ilen = axutil_strlen(formatted_buf);

    decoded_len = axutil_base64_decode_binary(buff,formatted_buf);
    if (decoded_len < 0)
    {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DECRYPT_FAILED,
                  "axutil_base64_decode_binary failed");
        return AXIS2_FAILURE;
    }

    /*  EVP_DecodeInit(&ctx);
        EVP_DecodeUpdate(&ctx, (unsigned char*)buff, &len,
                       (unsigned char*)b64_encoded_buf, ilen);
        EVP_DecodeFinal(&ctx, (unsigned char*)buff, &ret);
        ret += len;
    */
    if ((mem = BIO_new_mem_buf(buff, ilen)) == NULL)
    {
        /*oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                "BIO memeory allocation failure");*/
        return AXIS2_FAILURE;
    }

    *cert = d2i_X509_bio(mem, NULL);
    /*Free*/
    BIO_free(mem);
    mem = NULL;
    AXIS2_FREE(env->allocator, buff);
    buff = NULL;

    if (*cert == NULL){
        /*oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                "Certificate is NULL");*/
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;

}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_x509_load_from_pem(const axutil_env_t *env,
                           axis2_char_t *filename,
                           X509 **cert)
{
    BIO *in;

    if ((in=BIO_new_file(filename,"r")) == NULL)
    {
        /*oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                "Error reading the file %s", filename);*/
        return AXIS2_FAILURE;
    }
    /*Read certificate*/
    PEM_read_bio_X509(in, cert,NULL,NULL);
    if(!*cert)
    {
        return AXIS2_FAILURE;
    }

    if (-1 == BIO_reset(in) ){
        return AXIS2_FAILURE;
    }

    if (-1 == BIO_free(in)  ){
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}


AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_x509_load_from_pkcs12(const axutil_env_t *env,
                              axis2_char_t *filename,
                              axis2_char_t *password,
                              X509 **cert,
                              EVP_PKEY **pkey,
                              STACK_OF(X509) **ca)
{
    PKCS12 *p12 = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    /*Load*/
    status = openssl_pkcs12_load(env, filename, &p12);
    if(AXIS2_FAILURE == status){
        return AXIS2_FAILURE;
    }
    /*Parse*/
    status = openssl_pkcs12_parse(env, password, p12, pkey,
                                  cert,
                                  ca);
    if(AXIS2_FAILURE == status){
        return AXIS2_FAILURE;
    }
    /*Free*/
    status = openssl_pkcs12_free(env, p12);
    if(AXIS2_FAILURE == status){
        return AXIS2_FAILURE;
    }

    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_x509_load_certificate(const axutil_env_t *env,
                              openssl_x509_format_t format,
                              axis2_char_t *filename,
                              axis2_char_t *password,
                              X509 **cert)
{
    axis2_status_t status = AXIS2_FAILURE;

    if(OPENSSL_X509_FORMAT_PEM == format){
        /*Load from PEM*/
        status = openssl_x509_load_from_pem(env, filename, cert);
        if(AXIS2_FAILURE == status){
            return AXIS2_FAILURE;
        }
    }else if(OPENSSL_X509_FORMAT_PKCS12 == format){
        /*Load from PKCS12*/
        EVP_PKEY *pkey = NULL;
        STACK_OF(X509) *ca = NULL;
        status = openssl_x509_load_from_pkcs12(env, filename, password, cert, &pkey, &ca);
        if(AXIS2_FAILURE == status){
            return AXIS2_FAILURE;
        }
    }else if(OPENSSL_X509_FORMAT_DER == format){
        /*Load from DER*/

    }else{
        /*Unspported*/
    }
    return AXIS2_SUCCESS;
}


/*
 * Here we take data in btwn
 -----BEGIN CERTIFICATE-----
 -----END CERTIFICATE-----
 */

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
openssl_x509_get_cert_data(const axutil_env_t *env,
                           X509 *cert)
{
    axis2_char_t *unformatted = NULL;
    axis2_char_t *core_tail = NULL;
    axis2_char_t *core = NULL;
    axis2_char_t *res = NULL;
    axis2_char_t *buffer = NULL;

    unformatted = openssl_x509_get_info(env, OPENSSL_X509_INFO_DATA_CERT, cert);
    core_tail = axutil_strstr(unformatted, "\n");
    res = axutil_strstr(core_tail,"-----END");
    res[0] = '\0';
    core = (axis2_char_t*)axutil_strdup(env, core_tail);
    if(core)
    {
        buffer = oxs_util_get_newline_removed_string(env,core);
        AXIS2_FREE(env->allocator,core);
        core = NULL;
        return buffer;
    }
    else
        return NULL;
}


AXIS2_EXTERN int AXIS2_CALL
openssl_x509_get_serial(const axutil_env_t *env,
                        X509 *cert)
{
    axis2_char_t *serial = NULL;
    int no = 0;
    /*WARN: Do not use the serial number without converting it to the integer.*/
    serial = (axis2_char_t*)i2s_ASN1_INTEGER(NULL, X509_get_serialNumber(cert));
    no = atoi(serial);

    return no;
}

AXIS2_EXTERN unsigned long AXIS2_CALL
openssl_x509_get_subject_name_hash(const axutil_env_t *env,
                                   X509 *cert)
{
    unsigned long l = 0;
    l=X509_subject_name_hash(cert);
    return l;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_x509_get_pubkey(const axutil_env_t *env,
                        X509 *cert,
                        EVP_PKEY **pubkey)
{
    *pubkey = X509_get_pubkey(cert);
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
openssl_x509_get_subject_key_identifier(const axutil_env_t *env,
                                        X509 *cert)
{
    X509_EXTENSION *ext;
    ASN1_OCTET_STRING *keyId = NULL;
    int index = 0;
    EVP_ENCODE_CTX ctx;
    int len, ret;
    char buf[1000];
    char output[100];
    axis2_char_t *ski = NULL;

    /*Get ext by ID*/
    index = X509_get_ext_by_NID(cert, NID_subject_key_identifier, -1);
    if (index < 0) {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                  "The extenension index of NID_subject_key_identifier is not valid");
        return NULL;
    }
    /*Get the extension*/
    ext = X509_get_ext(cert, index);
    if (ext == NULL) {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                  "The extension for NID_subject_key_identifier is NULL");
        return NULL;
    }
    /*Subject Key Identifier*/
    keyId = (ASN1_OCTET_STRING *)X509V3_EXT_d2i(ext);
    if (keyId == NULL) {
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                  "The SubjectKeyIdentifier is NULL");
        return NULL;
    }
    memcpy(buf, keyId->data, keyId->length);
    buf[keyId->length] = 0;

    EVP_EncodeInit(&ctx);
    EVP_EncodeUpdate(&ctx, (unsigned char*)output, &len, (unsigned char*)buf, keyId->length);
    EVP_EncodeFinal(&ctx, (unsigned char*)(output+len), &ret);

    ret += len;
    ski = axutil_strdup(env, output);
    return ski;
}

AXIS2_EXTERN axis2_char_t *AXIS2_CALL
openssl_x509_get_info(const axutil_env_t *env,
                      openssl_x509_info_type_t type,
                      X509 *cert)
{
    BIO *out = NULL;
    unsigned char *data= NULL;
    axis2_char_t *result = NULL;
    int n = 0;

    out = BIO_new(BIO_s_mem());
    if(OPENSSL_X509_INFO_SUBJECT==type){
        X509_NAME_print_ex(out, X509_get_subject_name(cert), 0, 0);
    }else if(OPENSSL_X509_INFO_ISSUER == type){
        X509_NAME_print_ex(out,  X509_get_issuer_name(cert), 0, 0);
    }else if(OPENSSL_X509_INFO_VALID_FROM == type){
        ASN1_TIME_print(out, X509_get_notBefore(cert));
    }else if(OPENSSL_X509_INFO_VALID_TO == type){
        ASN1_TIME_print(out, X509_get_notAfter(cert));
    }else if(OPENSSL_X509_INFO_DATA_CERT == type){
        if(!PEM_write_bio_X509_AUX(out, cert)){
            return NULL;
        }
    }else if(OPENSSL_X509_INFO_FINGER == type){
        int j = 0;
        const EVP_MD *digest = NULL;
        unsigned char md[EVP_MAX_MD_SIZE];
        unsigned int _n = 0;

        digest = EVP_sha1();/*If we use EVP_md5(); here we can get the digest from md5. */
        if(X509_digest(cert,digest,md,&_n))
        {
            BIO_printf(out, "%s:", OBJ_nid2sn(EVP_MD_type(digest)));
            for (j=0; j<(int)_n; j++)
            {
                BIO_printf (out, "%02X",md[j]);
                if (j+1 != (int)_n) BIO_printf(out,":");
            }
        }
    }else if(OPENSSL_X509_INFO_SIGNATURE == type){
        int i = 0;
        unsigned char *s = NULL;

        n=cert->signature->length;
        s=cert->signature->data;
        for (i=0; i<n; i++)
        {
            if ( ((i%18) == 0) && (i!=0) ) BIO_printf(out,"\n");
            BIO_printf(out,"%02x%s",s[i], (((i+1)%18) == 0)?"":":");
        }

    }else if(OPENSSL_X509_INFO_VERSION == type){
        long l = 0.0;

        l = X509_get_version(cert);
        BIO_printf (out,"%lu (0x%lx)",l+1,l);
    }else if(OPENSSL_X509_INFO_PUBKEY == type){
        EVP_PKEY *pkey = NULL;

        pkey=X509_get_pubkey(cert);
        if (pkey != NULL)
        {
            if (pkey->type == EVP_PKEY_RSA){
                RSA_print(out,pkey->pkey.rsa,0);
            }else if (pkey->type == EVP_PKEY_DSA){
                DSA_print(out,pkey->pkey.dsa,0);
            }
            EVP_PKEY_free(pkey);
        }
    }else if(OPENSSL_X509_INFO_PUBKEY_ALGO == type){
        X509_CINF *ci = NULL;

        ci = cert->cert_info;
        i2a_ASN1_OBJECT(out, ci->key->algor->algorithm);
    }
    n = BIO_get_mem_data(out, &data);
    result = axutil_strndup( env, data, n);
    BIO_free(out);
    out = NULL;

    return result;
}

AXIS2_EXTERN void  AXIS2_CALL
openssl_x509_print(const axutil_env_t *env,
                   X509 *cert)
{
    printf("\n*************START PRINTING*****************\n");
    printf("OPENSSL_X509_INFO_SUBJECT : %s\n", openssl_x509_get_info(env, OPENSSL_X509_INFO_SUBJECT,cert));
    printf("OPENSSL_X509_INFO_ISSUER : %s\n", openssl_x509_get_info(env,OPENSSL_X509_INFO_ISSUER ,cert));
    printf("OPENSSL_X509_INFO_VALID_FROM : %s\n", openssl_x509_get_info(env, OPENSSL_X509_INFO_VALID_FROM,cert));
    printf("OPENSSL_X509_INFO_VALID_TO : %s\n", openssl_x509_get_info(env,OPENSSL_X509_INFO_VALID_TO ,cert));
    printf("OPENSSL_X509_INFO_FINGER : %s\n", openssl_x509_get_info(env,OPENSSL_X509_INFO_FINGER ,cert));
    printf("OPENSSL_X509_INFO_SIGNATURE : %s\n", openssl_x509_get_info(env, OPENSSL_X509_INFO_SIGNATURE,cert));
    printf("OPENSSL_X509_INFO_VERSION : %s\n", openssl_x509_get_info(env,OPENSSL_X509_INFO_VERSION ,cert));
    printf("OPENSSL_X509_INFO_PUBKEY : %s\n", openssl_x509_get_info(env,OPENSSL_X509_INFO_PUBKEY ,cert));
    printf("OPENSSL_X509_INFO_PUBKEY_ALGO : %s\n", openssl_x509_get_info(env,OPENSSL_X509_INFO_PUBKEY_ALGO ,cert));
    printf("SERIAL : %u\n", openssl_x509_get_serial(env,cert));
    printf("PUBKEY : %s\n", openssl_x509_get_cert_data(env,cert));

    printf("\n*************END PRINTING********************\n");


}
