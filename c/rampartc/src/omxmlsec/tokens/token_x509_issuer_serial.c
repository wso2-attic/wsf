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
#include <oxs_constants.h>
#include <oxs_error.h>
#include <oxs_token_x509_issuer_serial.h>
#include <oxs_token_x509_issuer_name.h>
#include <oxs_token_x509_serial_number.h>
#include <axiom_element.h>


AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_x509_issuer_serial_with_data(const axutil_env_t *env,
        axiom_node_t *parent,
        axis2_char_t *issuer_name,
        axis2_char_t *serial_number)
{
    axiom_node_t *x509_issuer_serial_node = NULL;
    axiom_node_t *x509_issuer_name_node = NULL;
    axiom_node_t *x509_serial_number_node = NULL;

    x509_issuer_serial_node = oxs_token_build_x509_issuer_serial_element(env, parent);
    if(issuer_name){
        x509_issuer_name_node = oxs_token_build_issuer_name_element(env, x509_issuer_serial_node, issuer_name);
    }
    if(serial_number){
        x509_serial_number_node = oxs_token_build_serial_number_element(env, x509_issuer_serial_node, serial_number);
    }
    return x509_issuer_serial_node;

}

AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_x509_issuer_serial_element(const axutil_env_t *env,
        axiom_node_t *parent)
{
    axiom_node_t *x509_issuer_serial_node = NULL;
    axiom_element_t *x509_issuer_serial_ele = NULL;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_DSIG_NS,
                                    OXS_DS);


    x509_issuer_serial_ele = axiom_element_create(env, parent, OXS_NODE_X509_ISSUER_SERIAL, ns_obj, &x509_issuer_serial_node);
    if (!x509_issuer_serial_ele)
    {
        oxs_error(env, ERROR_LOCATION,
                  OXS_ERROR_ELEMENT_FAILED, "Error creating X509IssuerSerial element");
        return NULL;
    }

    return x509_issuer_serial_node;
}

