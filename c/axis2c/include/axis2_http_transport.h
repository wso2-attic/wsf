/*
* Copyright 2004,2005 The Apache Software Foundation.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain count copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef AXIS2_HTTP_TRANSPORT_H
#define AXIS2_HTTP_TRANSPORT_H

#include <axis2_const.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup axis2_core_trans_http http transport
 * @ingroup axis2_transport
 * Description.
 * @{
 */

/**
 * @defgroup axis2_core_transport_http core http transport
 * @ingroup axis2_core_trans_http
 * @{
 */

/**
 * @brief HTTP protocol and message context constants.
 *
 */
#define AXIS2_HTTP_OUT_TRANSPORT_INFO "HTTPOutTransportInfo"

/**
 * CARRIAGE RETURN AND LINE FEED
 */
#define AXIS2_HTTP_CRLF "\r\n"

/**
 * PROTOCOL_VERSION
 */
#define AXIS2_HTTP_PROTOCOL_VERSION "PROTOCOL"

/**
 * REQUEST_URI
 */
#define AXIS2_HTTP_REQUEST_URI "REQUEST_URI"

/**
 * RESPONSE_CODE
 */
#define AXIS2_HTTP_RESPONSE_CODE "RESPONSE_CODE"

/**
 * RESPONSE_WORD
 */
#define AXIS2_HTTP_RESPONSE_WORD "RESPONSE_WORD"

/**
 * RESPONSE_ACK_CODE_VAL
 */
#define AXIS2_HTTP_RESPONSE_ACK_CODE_VAL 202

/*
 * RESPONSE_OK_CODE_VAL
 */
#define AXIS2_HTTP_RESPONSE_OK_CODE_VAL 200

/*
 * RESPONSE_CONTINUE_CODE_VAL
 */
#define AXIS2_HTTP_RESPONSE_CONTINUE_CODE_VAL 100

/*
 * RESPONSE_INTERNAL_SERVER_ERROR_CODE_VAL
 */
#define  AXIS2_HTTP_RESPONSE_INTERNAL_SERVER_ERROR_CODE_VAL 500

/**
 * SOCKET
 */
#define AXIS2_SOCKET "SOCKET"

/**
 * HEADER_PROTOCOL_10
 */
#define AXIS2_HTTP_HEADER_PROTOCOL_10 "HTTP/1.0"

/**
 * HEADER_PROTOCOL_11
 */
#define AXIS2_HTTP_HEADER_PROTOCOL_11 "HTTP/1.1"

/**
 * CHAR_SET_ENCODING
 */
#define AXIS2_HTTP_CHAR_SET_ENCODING "charset"

/**
 * HEADER_POST
 */
#define AXIS2_HTTP_POST  "POST"

/**
 * HEADER_GET
 */
#define AXIS2_HTTP_GET "GET"

/**
 * HEADER_HOST
 */
#define AXIS2_HTTP_HEADER_HOST "Host"

/**
 * HEADER_CONTENT_DESCRIPTION
 */
#define AXIS2_HTP_HEADER_CONTENT_DESCRIPTION "Content-Description"

/**
 * HEADER_CONTENT_TYPE
 */
#define AXIS2_HTTP_HEADER_CONTENT_TYPE "Content-Type"
#define AXIS2_HTTP_HEADER_CONTENT_TYPE_ "Content-Type:"

/**
 *USER DEFINED HEADER CONTENT TYPE
 */

#define AXIS2_USER_DEFINED_HTTP_HEADER_CONTENT_TYPE "User_Content_Type"

/**
 * HEADER_CONTENT_TYPE
 */
#define AXIS2_HTTP_HEADER_CONTENT_TYPE_MIME_BOUNDARY "boundary"

/**
 * HEADER_CONTENT_TRANSFER_ENCODING
 */
#define AXIS2_HTTP_HEADER_CONTENT_TRANSFER_ENCODING \
                                    "Content-Transfer-Encoding"

/**
 * HEADER_CONTENT_LENGTH
 */
#define AXIS2_HTTP_HEADER_CONTENT_LENGTH "Content-Length"

#define AXIS2_HTTP_HEADER_CONTENT_LENGTH_ "Content-Length:"

/**
 * HEADER_CONTENT_LOCATION
 */
#define AXIS2_HTTP_HEADER_CONTENT_LOCATION "Content-Location"

/**
 * HEADER_CONTENT_ID
 */
#define AXIS2_HTTP_HEADER_CONTENT_ID "Content-Id"

/**
 * HEADER_SOAP_ACTION
 */
#define AXIS2_HTTP_HEADER_SOAP_ACTION "SOAPAction"
#define AXIS2_HTTP_HEADER_SOAP_ACTION_ "SOAPAction:"

/**
 * HEADER_AUTHORIZATION
 */
#define AXIS2_HTTP_HEADER_AUTHORIZATION "Authorization"

/**
 * HEADER_PROXY_AUTHORIZATION
 */
#define AXIS2_HTTP_HEADER_PROXY_AUTHORIZATION "Proxy-Authorization"

/**
 * HEADER_EXPECT
 */
#define AXIS2_HTTP_HEADER_EXPECT "Expect"

/**
 * HEADER_EXPECT_100_Continue
 */
#define AXIS2_HTTP_HEADER_EXPECT_100_CONTINUE "100-continue"

/**
 * HEADER_USER_AGENT
 */
#define AXIS2_HTTP_HEADER_USER_AGENT "User-Agent"

/**
 * HEADER_USER_AGENT_AXIS2C
 */
#define AXIS2_HTTP_HEADER_USER_AGENT_AXIS2C "User-Agent:Axis2/C"

#define AXIS2_HTTP_HEADER_ACCEPT_ "Accept:"

#define AXIS2_HTTP_HEADER_EXPECT_ "Expect:"
/**
 * HEADER_CACHE_CONTROL
 */
#define AXIS2_HTTP_HEADER_CACHE_CONTROL "Cache-Control"

/**
 * HEADER_CACHE_CONTROL_NOCACHE
 */
#define AXIS2_HTTP_HEADER_CACHE_CONTROL_NOCACHE "no-cache"

/**
 * HEADER_PRAGMA
 */
#define AXIS2_HTTP_HEADER_PRAGMA "Pragma"

/**
 * HEADER_LOCATION
 */
#define AXIS2_HTTP_HEADER_LOCATION "Location"

/**
 * REQUEST_HEADERS
 */
#define AXIS2_HTTP_REQUEST_HEADERS "HTTP-Request-Headers"

/**
 * RESPONSE_HEADERS
 */
#define AXIS2_HTTP_RESPONSE_HEADERS "HTTP-Response-Headers"

    /* http 1.1 */

/**
 * HEADER_TRANSFER_ENCODING
 */
#define AXIS2_HTTP_HEADER_TRANSFER_ENCODING "Transfer-Encoding"

/**
 * HEADER_TRANSFER_ENCODING_CHUNKED
 */
#define AXIS2_HTTP_HEADER_TRANSFER_ENCODING_CHUNKED "chunked"

/**
 * HEADER_CONNECTION
 */
#define AXIS2_HTTP_HEADER_CONNECTION "Connection"

/**
 * HEADER_CONNECTION_CLOSE
 */
#define AXIS2_HTTP_HEADER_CONNECTION_CLOSE "close"

/**
 * HEADER_CONNECTION_KEEPALIVE
 */
#define AXIS2_HTTP_HEADER_CONNECTION_KEEPALIVE "Keep-Alive"

/**
 * HEADER_ACCEPT
 */
#define AXIS2_HTTP_HEADER_ACCEPT "Accept"

/**
 * HEADER_ACCEPT_TEXT_ALL
 */
#define AXIS2_HTTP_HEADER_ACCEPT_TEXT_ALL "text/*"

/**
 * HEADER_ACCEPT_TEXT_PLAIN
 */
#define AXIS2_HTTP_HEADER_ACCEPT_TEXT_PLAIN "text/plain"

/**
 * HEADER_ACCEPT_TEXT_HTML
 */
#define AXIS2_HTTP_HEADER_ACCEPT_TEXT_HTML "text/html"

/**
 * HEADER_ACCEPT_TEXT_XML
 */
#define AXIS2_HTTP_HEADER_ACCEPT_TEXT_XML "text/xml"

/**
 * HEADER_ACCEPT_APPL_SOAP
 */
#define AXIS2_HTTP_HEADER_ACCEPT_APPL_SOAP "application/soap+xml"

/**
 * HEADER_ACCEPT_X_WWW_FROM_URLENCODED
 */
#define AXIS2_HTTP_HEADER_ACCEPT_X_WWW_FROM_URLENCODED "application/x-www-form-urlencoded"


/**
 * HEADER XOP XML
 */
#define AXIS2_HTTP_HEADER_XOP_XML "application/xop+xml"

/**
 * HEADER_ACCEPT_MULTIPART_RELATED
 */
#define AXIS2_HTTP_HEADER_ACCEPT_MULTIPART_RELATED "multipart/related"

/**
 * HEADER_ACCEPT_APPLICATION_DIME
 */
#define AXIS2_HTTP_HEADER_ACCEPT_APPLICATION_DIME "application/dime"

/**
 * Cookie headers
 */
#define AXIS2_HTTP_HEADER_COOKIE "Cookie"

/**
 * HEADER_COOKIE2
 */
#define AXIS2_HTTP_HEADER_COOKIE2 "Cookie2"

/**
 * HEADER_SET_COOKIE
 */
#define AXIS2_HTTP_HEADER_SET_COOKIE "Set-Cookie"

/**
 * HEADER_SET_COOKIE2
 */
#define AXIS2_HTTP_HEADER_SET_COOKIE2 "Set-Cookie2"

/**
 * HTTP header field values
 */
#define AXIS2_HTTP_HEADER_DEFAULT_CHAR_ENCODING "iso-8859-1"

/**
 * REPONSE_HTTP_OK
 */
#define AXIS2_HTTP_RESPONSE_OK "200 OK"

/**
 * RESPONSE_HTTP_NOCONTENT
 */
#define AXIS2_HTTP_RESPONSE_NOCONTENT "202 OK";

/**
 * RESPONSE_HTTP_UNAUTHORIZED
 */
#define AXIS2_HTTP_RESPONSE_HTTP_UNAUTHORIZED "401 Unauthorized"

/**
 * RESPONSE_BAD_REQUEST
 */
#define AXIS2_HTTP_RESPONSE_BAD_REQUEST "400 Bad Request"

/**
 * RESPONSE_HTTP_INTERNAL_SERVER_ERROR
 */
#define AXIS2_HTTP_RESPONSE_INTERNAL_SERVER_ERROR "500 Internal server error"

/**
 * HTTP_REQ_TYPE
 */
#define AXIS2_HTTP_REQ_TYPE "HTTP_REQ_TYPE"

/**
 * SO_TIMEOUT
 */
#define AXIS2_HTTP_SO_TIMEOUT "SO_TIMEOUT"

/**
 * CONNECTION_TIMEOUT
 */
#define AXIS2_HTTP_CONNECTION_TIMEOUT "CONNECTION_TIMEOUT"

/**
 * DEFAULT_SO_TIMEOUT
 */
#define AXIS2_HTTP_DEFAULT_SO_TIMEOUT 60000

/**
 * DEFAULT_CONNECTION_TIMEOUT
 */
#define AXIS2_HTTP_DEFAULT_CONNECTION_TIMEOUT 60000

#define AXIS2_HTTP_PROXY "PROXY"

/**
 * ISO-8859-1 encoding
 */
#define AXIS2_HTTP_ISO_8859_1 "ISO-8859-1"

/**
 * Default charset in content
 */
#define AXIS2_HTTP_DEFAULT_CONTENT_CHARSET "ISO-8859-1"

/**
 * Field TRANSPORT_HTTP
 */
#define AXIS2_TRANSPORT_HTTP "http"

/**
 * Msg context response written key
 */
#define AXIS2_RESPONSE_WRITTEN "CONTENT_WRITTEN"

/**
 * Content type for MTOM
 */
#define MTOM_RECIVED_CONTENT_TYPE "MTOM_RECEIVED"

/**
 * Constant for HTTP proxy
 */
#define AXIS2_HTTP_PROXY "PROXY"

/**
 * Constant for HTTP proxy host
 */
#define AXIS2_HTTP_PROXY_HOST "proxy_host"

/**
 * Constant for HTTP proxy port
 */
#define AXIS2_HTTP_PROXY_PORT "proxy_port"

#define AXIS2_HTTP_PROXY_API "PROXY_API"

/**
 * Constant for HTTP method
 */
#define AXIS2_HTTP_METHOD "HTTP_METHOD"

/**
 * Constant for SSL Server Certificate
 */
#define AXIS2_SSL_SERVER_CERT "SERVER_CERT"

/**
 * Constant for SSL Key File
 */
#define AXIS2_SSL_KEY_FILE "KEY_FILE"

/**
 * Constant for SSL Passphrase
 */
#define AXIS2_SSL_PASSPHRASE "SSL_PASSPHRASE"

/**
 *HTTP Transport Level Error
 */
#define AXIS2_HTTP_TRANSPORT_ERROR "http_transport_error"


/**
 *415 Unsupported media Type
 */

#define AXIS2_HTTP_UNSUPPORTED_MEDIA_TYPE "415 Unsupported Media Type\r\n"

/**
 *Constant for HTTP headers that user specify, Those headers will
 *provided as property to the message context.
 */
#define AXIS2_TRANSPORT_HEADER_PROPERTY "HTTP_HEADER_PROPERTY"

    /** @} */

#ifdef __cplusplus
}
#endif
#endif                          /* AXIS2_HTTP_TRANSPORT_H */
