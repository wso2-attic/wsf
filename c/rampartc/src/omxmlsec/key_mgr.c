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
#include <oxs_error.h>
#include <oxs_key_mgr.h>
#include <openssl_pem.h>



/**
 * Loads the key
 * 1. If the key buffer is specified, Take that as the source.
 * 2. Else if the key file name has specified, Take that as the source.
 */
AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_key_mgr_load_key(const axutil_env_t *env,
                     oxs_asym_ctx_t *ctx,
                     axis2_char_t *password)
{
    axis2_char_t *filename = NULL;
    axis2_char_t *pem_buf = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    openssl_x509_format_t format;
    openssl_pkey_t *open_prvkey = NULL;
    openssl_pkey_t *open_pubkey = NULL;
    oxs_x509_cert_t *oxs_cert = NULL;

    X509 *cert = NULL;
    STACK_OF(X509) *ca = NULL;
    EVP_PKEY *prvkey = NULL;
    EVP_PKEY *pubkey = NULL;

    /*If user has specified the certificate/private key directly we will extract the information from it.
     * Else we will look for a file name to load the certificate/private key*/
    pem_buf = oxs_asym_ctx_get_pem_buf(ctx, env);
    if(pem_buf){
        if( OXS_ASYM_CTX_OPERATION_PUB_ENCRYPT == oxs_asym_ctx_get_operation(ctx, env) ||
                OXS_ASYM_CTX_OPERATION_PUB_DECRYPT == oxs_asym_ctx_get_operation(ctx, env)){
            /*load certificate from buf*/
            status = openssl_x509_load_from_buffer(env, pem_buf, &cert);
        }else{
            /*load private key from buf*/
            status = openssl_pem_buf_read_pkey(env, pem_buf, password, OPENSSL_PEM_PKEY_TYPE_PRIVATE_KEY, &prvkey);
            if(status == AXIS2_FAILURE){
                prvkey = NULL;
            }
        }
    }else{
        /*pem_buf is NULL. So we have to fetch the key in a file*/
        /*Get file to be loaded. Can be either in PEM or PKCS12 format*/
        filename = oxs_asym_ctx_get_file_name(ctx, env);
        if(!filename){
            return AXIS2_FAILURE;
        }

        if(OXS_ASYM_CTX_FORMAT_PEM == oxs_asym_ctx_get_format(ctx, env)){
            oxs_asym_ctx_operation_t operation ;
            format = OPENSSL_X509_FORMAT_PEM;


            /*First let's check if this is a file containing a certificate*/
            status = openssl_x509_load_from_pem(env, filename,  &cert);

            if((status == AXIS2_FAILURE) || (!cert)){/*>>*/
                /*If we cannot get the certificate then the file might contain either a public key or a private key*/
                /*The type depends on the operation*/
                operation = oxs_asym_ctx_get_operation(ctx, env);

                if((operation == OXS_ASYM_CTX_OPERATION_PRV_DECRYPT) || (operation == OXS_ASYM_CTX_OPERATION_PRV_ENCRYPT)){
                    status = openssl_pem_read_pkey(env, filename, password, OPENSSL_PEM_PKEY_TYPE_PRIVATE_KEY, &prvkey);
                    if(status == AXIS2_FAILURE){
                        prvkey = NULL;
                    }
                } else if((operation == OXS_ASYM_CTX_OPERATION_PUB_DECRYPT) || (operation == OXS_ASYM_CTX_OPERATION_PUB_ENCRYPT)){
                    status = openssl_pem_read_pkey(env, filename, password, OPENSSL_PEM_PKEY_TYPE_PUBLIC_KEY, &pubkey);
                    if(status == AXIS2_FAILURE){
                        pubkey = NULL;
                    }
                }
            }/*>>*/
        }else if(OXS_ASYM_CTX_FORMAT_PKCS12 == oxs_asym_ctx_get_format(ctx, env)){
            format = OPENSSL_X509_FORMAT_PKCS12;
            /*Here we load both key and the certificate*/
            status = openssl_x509_load_from_pkcs12(env, filename, password, &cert, &prvkey, &ca);
            if(AXIS2_FAILURE == status){
                oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                          "Error reading the certificate");
                return AXIS2_FAILURE;
            }
        }

    }/*end of pem_buf*/

    /*Wht ever the way, right now we should have either the public key or the private key*/

    /*If the prvkey is available, populate the openssl_pkey*/
    if(prvkey){
        open_prvkey = openssl_pkey_create(env);
        openssl_pkey_populate(open_prvkey, env, prvkey, filename, OPENSSL_PKEY_TYPE_PRIVATE_KEY);
        oxs_asym_ctx_set_private_key(ctx, env, open_prvkey);
    }
    /*If the public key is available populate*/
    if(pubkey){
        /*This scenario is not recommonded. This will be executed iff the file is a public key file in PEM format*/
        open_pubkey = openssl_pkey_create(env);
        openssl_pkey_populate(open_pubkey, env, pubkey, filename, OPENSSL_PKEY_TYPE_PUBLIC_KEY);
        oxs_cert = oxs_x509_cert_create(env);
        oxs_x509_cert_set_public_key(oxs_cert, env, open_pubkey);
        oxs_asym_ctx_set_certificate(ctx, env, oxs_cert);
    }
    /*If the X509 certificate is available, populate oxs_x509_cert*/
    if(cert){

        /*Create certificate*/
        oxs_cert = oxs_x509_cert_create(env);
        /*And populate it*/
        oxs_x509_cert_set_data(oxs_cert, env, openssl_x509_get_cert_data(env, cert));
        oxs_x509_cert_set_date(oxs_cert, env, openssl_x509_get_info(env, OPENSSL_X509_INFO_VALID_TO ,cert));
        oxs_x509_cert_set_issuer(oxs_cert, env, openssl_x509_get_info(env, OPENSSL_X509_INFO_ISSUER ,cert));
        oxs_x509_cert_set_subject(oxs_cert, env, openssl_x509_get_info(env, OPENSSL_X509_INFO_SUBJECT ,cert));
        oxs_x509_cert_set_fingerprint(oxs_cert, env, openssl_x509_get_info(env, OPENSSL_X509_INFO_FINGER,cert));
        oxs_x509_cert_set_serial_number(oxs_cert, env, openssl_x509_get_serial(env, cert));
        oxs_x509_cert_set_key_identifier(oxs_cert, env, openssl_x509_get_subject_key_identifier(env, cert));

        /*Additionally we need to set the public key*/
        openssl_x509_get_pubkey(env, cert, &pubkey);
        open_pubkey = openssl_pkey_create(env);
        openssl_pkey_populate(open_pubkey, env, pubkey, openssl_x509_get_info(env, OPENSSL_X509_INFO_FINGER,cert), OPENSSL_PKEY_TYPE_PUBLIC_KEY);
        /*Set the public key to the x509 certificate*/
        oxs_x509_cert_set_public_key(oxs_cert, env, open_pubkey);
        /*Set the x509 certificate to the asym ctx*/
        oxs_asym_ctx_set_certificate(ctx, env, oxs_cert);
    }
    /*If this fails to get anything return failure*/
    if((!cert) && (!pubkey) && (!prvkey)){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                  "Error reading the key");
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

/********************************************************************************************/
/*These are new set of functions that break-up the complex logic in oxs_key_mgr_load_key()*/

AXIS2_EXTERN openssl_pkey_t* AXIS2_CALL
oxs_key_mgr_load_private_key_from_string(const axutil_env_t *env,
        axis2_char_t *pem_string, /*in PEM format*/
        axis2_char_t *password)
{
    openssl_pkey_t *open_prvkey = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    EVP_PKEY *prvkey = NULL;

    /*load private key from buf*/
    status = openssl_pem_buf_read_pkey(env, pem_string, password, OPENSSL_PEM_PKEY_TYPE_PRIVATE_KEY, &prvkey);
    /*Populate*/
    if(prvkey){
        open_prvkey = openssl_pkey_create(env);
        openssl_pkey_populate(open_prvkey, env, prvkey, NULL, OPENSSL_PKEY_TYPE_PRIVATE_KEY);
    }else{
        return NULL;
    }

    return open_prvkey;
}

AXIS2_EXTERN openssl_pkey_t* AXIS2_CALL
oxs_key_mgr_load_private_key_from_pem_file(const axutil_env_t *env,
        axis2_char_t *filename,
        axis2_char_t *password)
{
    openssl_pkey_t *open_prvkey = NULL;
    axis2_status_t status = AXIS2_FAILURE;
    EVP_PKEY *prvkey = NULL;

    /*Read EVP_PKEY*/
    status = openssl_pem_read_pkey(env, filename, password, OPENSSL_PEM_PKEY_TYPE_PRIVATE_KEY, &prvkey);

    /*Populate*/
    if(prvkey){
        open_prvkey = openssl_pkey_create(env);
        openssl_pkey_populate(open_prvkey, env, prvkey, filename, OPENSSL_PKEY_TYPE_PRIVATE_KEY);
    }else{
        return NULL;
    }

    return open_prvkey;
}

/*Private function to convert X509* -> oxs_x509_cert_t* */
static oxs_x509_cert_t*
oxs_key_mgr_convert_to_x509(const axutil_env_t *env,
                            X509 *cert)
{
    oxs_x509_cert_t *oxs_cert = NULL;

    if(cert){
        EVP_PKEY *pubkey = NULL;
        openssl_pkey_t *open_pubkey = NULL;

        oxs_cert = oxs_x509_cert_create(env);

        oxs_x509_cert_set_data(oxs_cert, env, openssl_x509_get_cert_data(env, cert));
        oxs_x509_cert_set_date(oxs_cert, env, openssl_x509_get_info(env, OPENSSL_X509_INFO_VALID_TO ,cert));
        oxs_x509_cert_set_issuer(oxs_cert, env, openssl_x509_get_info(env, OPENSSL_X509_INFO_ISSUER ,cert));
        oxs_x509_cert_set_subject(oxs_cert, env, openssl_x509_get_info(env, OPENSSL_X509_INFO_SUBJECT ,cert));
        oxs_x509_cert_set_fingerprint(oxs_cert, env, openssl_x509_get_info(env, OPENSSL_X509_INFO_FINGER,cert));
        oxs_x509_cert_set_serial_number(oxs_cert, env, openssl_x509_get_serial(env, cert));
        oxs_x509_cert_set_key_identifier(oxs_cert, env, openssl_x509_get_subject_key_identifier(env, cert));

        /*Additionally we need to set the public key*/
        openssl_x509_get_pubkey(env, cert, &pubkey);
        open_pubkey = openssl_pkey_create(env);
        openssl_pkey_populate(open_pubkey, env, pubkey, openssl_x509_get_info(env, OPENSSL_X509_INFO_FINGER,cert), OPENSSL_PKEY_TYPE_PUBLIC_KEY);
        /*Set the public key to the x509 certificate*/
        oxs_x509_cert_set_public_key(oxs_cert, env, open_pubkey);
    }

    return oxs_cert;
}

AXIS2_EXTERN oxs_x509_cert_t* AXIS2_CALL
oxs_key_mgr_load_x509_cert_from_pem_file(const axutil_env_t *env,
        axis2_char_t *filename)
{
    X509 *cert = NULL;
    oxs_x509_cert_t *oxs_cert = NULL;
    openssl_x509_load_from_pem(env, filename,  &cert);

    oxs_cert = oxs_key_mgr_convert_to_x509(env, cert);

    return oxs_cert;
}

AXIS2_EXTERN oxs_x509_cert_t* AXIS2_CALL
oxs_key_mgr_load_x509_cert_from_string(const axutil_env_t *env,
                                       axis2_char_t *pem_string)
{
    X509 *cert = NULL;
    oxs_x509_cert_t *oxs_cert = NULL;
    openssl_x509_load_from_buffer(env, pem_string, &cert);

    oxs_cert = oxs_key_mgr_convert_to_x509(env, cert);

    return oxs_cert;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
oxs_key_mgr_read_pkcs12_key_store(const axutil_env_t *env,
                                  axis2_char_t *filename,
                                  axis2_char_t *password,
                                  oxs_x509_cert_t **cert,
                                  openssl_pkey_t **prv_key)
{
    X509 *c = NULL;
    STACK_OF(X509) *ca = NULL;
    EVP_PKEY *pkey = NULL;
    axis2_status_t status = AXIS2_FAILURE;

    status = openssl_x509_load_from_pkcs12(env, filename, password, &c, &pkey, &ca);
    if(AXIS2_FAILURE == status){
        oxs_error(env, ERROR_LOCATION, OXS_ERROR_DEFAULT,
                  "Error reading the PKCS12 Key Store");
        return AXIS2_FAILURE;
    }
    if(*prv_key){
        if(pkey){
            *prv_key = openssl_pkey_create(env);
            openssl_pkey_populate(*prv_key, env, pkey, filename, OPENSSL_PKEY_TYPE_PRIVATE_KEY);
        }
    }

    if(*cert){
        if(c){
            *cert = oxs_key_mgr_convert_to_x509(env, c);
        }
    }
    return AXIS2_SUCCESS;
}
