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

#ifndef WSCLIENT_OPTION_H
#define WSCLIENT_OPTION_H
#include <axis2_util.h>
#include "util.h"


#define no_argument 0
#define required_argument 1
#define optional_argument 2

typedef struct wsclient_cmd_options {
    char *long_name;
    char short_name;
    int has_arg;
}wsclient_cmd_options_t;


typedef struct options
{
      char *opt_name;
      int short_name;
      void *value;
      int has_arg;
}wsclient_options_t;


/* this enum and above array mapped there */
enum cmd_options_em
{
      GET = 0,
      CONTENT_TYPE,
      SOAP,
      SOAP_OLD,
      SEND_ONLY,
      ACTION,
      SOAP_DUMP,
      SOAP_OUT,
      SOAP_HEADER, /* {"soap-header", 0, required_argument}, */
      NO_WSA,
      TO,
      FROM,
      REPLY_TO /*{"reply-to", 0, required_argument},*/,
	  FAULT_TO /* {"fault-to", 0, required_argument},*/,
      IN_REPLY_TO /*{"in-reply-to", 0, required_argument},*/,
      USER, /* {"user", 0, required_argument}, */
      PASSWORD, /* {"password", 0, required_argument}, */
      PASSWORD_FILE, /* {"password-file", 0, required_argument}, */
      HTTP_HEADER, /* {"http-header", 0, required_argument}, */
      OUTPUT_HTTP_HEADERS, /* {"output-http-headers", 0, required_argument}, */
      DIGEST, /* {"digest", 0, no_argument}, */
      TIMESTAMP, /* {"timestamp", 0, no_argument}, */
      NO_MTOM, /* {"no-mtom", 0, no_argument}, */
	  XOP_IN, /* {"xop-in", 0, optional_argument}, */
	  XOP_OUT, /* {"xop-out", 0, optional_argument}, */
	  SERVER_CERT, /* {"server-cert", 0, required_argument}*/
      ENCRYPT_PAYLOAD, /* {"encrypt-payload", 0, required_argument}*/
      SIGN_BODY, /* {"sign-body", 0, required_argument} */
      ENCRYPT_BEFORE_SIGNING, /*{"encrypt-before-signing", 0, no_argument}*/
      ENCRYPT_SIGNATURE, /*{"encrypt-signature", 0, no_argument}*/
      KEY, /*{"key", 0, required_argument}*/
      CERTIFICATE, /*{"certificate", 0, required_argument}*/
      RECIPIENT_CERTIFICATE, /*{"recipient-certificate", 0, required_argument}*/
      POLICY_FILE, /*{"policy-file", 0, required_argument}*/
      ALGORITHMSUITE, /*{"algorithmsuite", 0, required_argument}*/
};


axis2_char_t *
wsclient_destination (int argc,
		      char **argv);


axutil_array_list_t *
wsclient_process_options (int argc,
			  char **argv,
			  const axutil_env_t *env);


#endif /* WSCLIENT_OPTION_H */
