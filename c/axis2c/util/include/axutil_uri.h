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

#ifndef AXUTIL_URI_H
#define AXUTIL_URI_H

/**
 * @file axutil_uri.h
 * @brief AXIS2-UTIL URI Routines
 * axutil_uri.h: External Interface of axutil_uri.c
 */

#include <axutil_string.h>
#include <axutil_utils.h>
#include <axutil_utils_defines.h>
#include <axutil_env.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @defgroup axutil_uri URI
     * @ingroup axis2_util
     * @{
     */

#define AXIS2_URI_FTP_DEFAULT_PORT         21 /**< default FTP port */
#define AXIS2_URI_SSH_DEFAULT_PORT         22 /**< default SSH port */
#define AXIS2_URI_TELNET_DEFAULT_PORT      23 /**< default telnet port */
#define AXIS2_URI_GOPHER_DEFAULT_PORT      70 /**< default Gopher port */
#define AXIS2_URI_HTTP_DEFAULT_PORT        80 /**< default HTTP port */
#define AXIS2_URI_POP_DEFAULT_PORT        110 /**< default POP port */
#define AXIS2_URI_NNTP_DEFAULT_PORT       119 /**< default NNTP port */
#define AXIS2_URI_IMAP_DEFAULT_PORT       143 /**< default IMAP port */
#define AXIS2_URI_PROSPERO_DEFAULT_PORT   191 /**< default Prospero port */
#define AXIS2_URI_WAIS_DEFAULT_PORT       210 /**< default WAIS port */
#define AXIS2_URI_LDAP_DEFAULT_PORT       389 /**< default LDAP port */
#define AXIS2_URI_HTTPS_DEFAULT_PORT      443 /**< default HTTPS port */
#define AXIS2_URI_RTSP_DEFAULT_PORT       554 /**< default RTSP port */
#define AXIS2_URI_SNEWS_DEFAULT_PORT      563 /**< default SNEWS port */
#define AXIS2_URI_ACAP_DEFAULT_PORT       674 /**< default ACAP port */
#define AXIS2_URI_NFS_DEFAULT_PORT       2049 /**< default NFS port */
#define AXIS2_URI_TIP_DEFAULT_PORT       3372 /**< default TIP port */
#define AXIS2_URI_SIP_DEFAULT_PORT       5060 /**< default SIP port */

    /** Flags passed to unparse_uri_components(): */
    /** suppress "scheme://user\@site:port" */
#define AXIS2_URI_UNP_OMITSITEPART    (1U<<0)
    /** Just omit user */
#define AXIS2_URI_UNP_OMITUSER        (1U<<1)
    /** Just omit password */
#define AXIS2_URI_UNP_OMITPASSWORD    (1U<<2)
    /** omit "user:password\@" part */
#define AXIS2_URI_UNP_OMITUSERINFO    (AXIS2_URI_UNP_OMITUSER | \
                                     AXIS2_URI_UNP_OMITPASSWORD)
    /** Show plain text password (default: show XXXXXXXX) */
#define AXIS2_URI_UNP_REVEALPASSWORD  (1U<<3)
    /** Show "scheme://user\@site:port" only */
#define AXIS2_URI_UNP_OMITPATHINFO    (1U<<4)
    /** Omit the "?queryarg" from the path */
#define AXIS2_URI_UNP_OMITQUERY       (1U<<5)

    /** @see axutil_uri_t */
    typedef  unsigned short  axis2_port_t;
    /* axutil_uri.c */

    typedef struct axutil_uri axutil_uri_t;

    /**
     * Return the default port for a given scheme.  The schemes recognized are
     * http, ftp, https, gopher, wais, nntp, snews, and prospero
     * @param scheme_str The string that contains the current scheme
     * @return The default port for this scheme
     */
    AXIS2_EXTERN axis2_port_t AXIS2_CALL
    axutil_uri_port_of_scheme(
        const axis2_char_t *scheme_str);

    /**
     * Parse a given URI, fill in all supplied fields of a axutil_uri_t
     * structure. This eliminates the necessity of extracting host, port,
     * path, query info repeatedly in the modules.
     * @param uri The uri to parse
     * @param uptr The axutil_uri_t to fill out
     * @return AXIS2_SUCCESS for success or error code
     */
    AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
    axutil_uri_parse_string(
        const axutil_env_t *env,
        const axis2_char_t *uri);

    /**
     * Special case for CONNECT parsing: it comes with the hostinfo part only
     * @param hostinfo The hostinfo string to parse
     * @param uptr The axutil_uri_t to fill out
     * @return AXIS2_SUCCESS for success or error code
     */
    AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
    axutil_uri_parse_hostinfo(
        const axutil_env_t *env,
        const axis2_char_t *hostinfo);

    /** Resolve relative to a base.  This means host/etc, and (crucially) path */
    AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
    axutil_uri_resolve_relative(
        const axutil_env_t *env,
        const axutil_uri_t* base,
        axutil_uri_t* uptr);

    /**
     * Return a URI created from a context URI and a relative URI.
     * If a valid URI cannot be created the only other possibility
     * this method will consider is that an absolute file path has
     * been passed in as the relative URI argument, and it will try
     * to create a 'file' URI from it.
     *
     * @param context_uri the document base URI
     * @param uri a file URI relative to the context_uri or an
     * absolute file path
     * @return the URIcreated from context_uri and uri
     */
    AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
    axutil_uri_parse_relative(
        const axutil_env_t *env,
        const axutil_uri_t* base,
        const char* uri);

    AXIS2_EXTERN void AXIS2_CALL
    axutil_uri_free(axutil_uri_t *uri,
            const axutil_env_t *env);

    /**
     * Unparse a axutil_uri_t structure to an URI string.  Optionally 
     * suppress the password for security reasons.
     * @param uptr All of the parts of the uri
     * @param flags How to unparse the uri.  One of:
     * <PRE>
     *    AXIS2_URI_UNP_OMITSITEPART        Suppress "scheme://user\@site:port" 
     *    AXIS2_URI_UNP_OMITUSER            Just omit user 
     *    AXIS2_URI_UNP_OMITPASSWORD        Just omit password 
     *    AXIS2_URI_UNP_OMITUSERINFO        Omit "user:password\@" part
     *    AXIS2_URI_UNP_REVEALPASSWORD      Show plain text password (default: show XXXXXXXX)
     *    AXIS2_URI_UNP_OMITPATHINFO        Show "scheme://user\@site:port" only 
     *    AXIS2_URI_UNP_OMITQUERY           Omit "?queryarg" or "#fragment" 
     * </PRE>
     * @return The uri as a string
     */
    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_uri_to_string(const axutil_uri_t *uri,
            const axutil_env_t *env,
            unsigned flags);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_uri_get_protocol(axutil_uri_t *uri,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_uri_get_server(axutil_uri_t *uri,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_port_t AXIS2_CALL
    axutil_uri_get_port(axutil_uri_t *uri,
            const axutil_env_t *env);

    AXIS2_EXTERN axis2_char_t* AXIS2_CALL
    axutil_uri_get_path(axutil_uri_t *uri,
            const axutil_env_t *env);

    AXIS2_EXTERN axutil_uri_t* AXIS2_CALL
    axutil_uri_clone(const axutil_uri_t *uri,
            const axutil_env_t *env);


    /** @} */
#ifdef __cplusplus
}
#endif

#endif /* AXIS2_URI_H */
