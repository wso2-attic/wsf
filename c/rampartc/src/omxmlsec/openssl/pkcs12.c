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
#include <oxs_error.h>
#include <openssl_pkcs12.h>

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_pkcs12_load(const axutil_env_t *env,
                    axis2_char_t *filename,
                    PKCS12 **p12)
{
    FILE *fp = NULL;

    SSLeay_add_all_algorithms();
    ERR_load_crypto_strings();
    if (!(fp = fopen(filename, "rb"))) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return AXIS2_FAILURE;
    }
    /*Load pkcs store*/
    *p12 = d2i_PKCS12_fp(fp, NULL);
    fclose (fp);

    if (!p12) {
        fprintf(stderr, "Error reading PKCS#12 file %s\n", filename);
        ERR_print_errors_fp(stderr);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_pkcs12_parse(const axutil_env_t *env,
                     axis2_char_t *password ,
                     PKCS12 *p12,
                     EVP_PKEY **prvkey,
                     X509 **cert,
                     STACK_OF(X509) **ca)
{
    /*Parse the pkcs store*/
    if (!PKCS12_parse(p12, password, prvkey, cert, ca)) {
        fprintf(stderr, "Error parsing PKCS#12 file\n");
        ERR_print_errors_fp(stderr);
        return AXIS2_FAILURE;
    }
    return AXIS2_SUCCESS;
}

AXIS2_EXTERN axis2_status_t AXIS2_CALL
openssl_pkcs12_free(const axutil_env_t *env,
                    PKCS12 *p12)
{

    PKCS12_free(p12);
    return AXIS2_SUCCESS;
}


