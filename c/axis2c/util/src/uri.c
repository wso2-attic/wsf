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

#include <stdlib.h>

#define AXIS2_WANT_STRFUNC

#include <axutil_uri.h>

typedef struct schemes_t schemes_t;

/** Structure to store various schemes and their default ports */
struct schemes_t
{
    /** The name of the scheme */
    const axis2_char_t *name;
    /** The default port for the scheme */
    axis2_port_t default_port;
};

/* Some WWW schemes and their default ports; this is basically /etc/services */
/* This will become global when the protocol abstraction comes */
/* As the schemes are searched by a linear search, */
/* they are sorted by their expected frequency */
static schemes_t schemes[] =
    {
        {"http",     AXIS2_URI_HTTP_DEFAULT_PORT
        },
        {"ftp",      AXIS2_URI_FTP_DEFAULT_PORT},
        {"https",    AXIS2_URI_HTTPS_DEFAULT_PORT},
        {"gopher",   AXIS2_URI_GOPHER_DEFAULT_PORT},
        {"ldap",     AXIS2_URI_LDAP_DEFAULT_PORT},
        {"nntp",     AXIS2_URI_NNTP_DEFAULT_PORT},
        {"snews",    AXIS2_URI_SNEWS_DEFAULT_PORT},
        {"imap",     AXIS2_URI_IMAP_DEFAULT_PORT},
        {"pop",      AXIS2_URI_POP_DEFAULT_PORT},
        {"sip",      AXIS2_URI_SIP_DEFAULT_PORT},
        {"rtsp",     AXIS2_URI_RTSP_DEFAULT_PORT},
        {"wais",     AXIS2_URI_WAIS_DEFAULT_PORT},
        {"z39.50r",  AXIS2_URI_WAIS_DEFAULT_PORT},
        {"z39.50s",  AXIS2_URI_WAIS_DEFAULT_PORT},
        {"prospero", AXIS2_URI_PROSPERO_DEFAULT_PORT},
        {"nfs",      AXIS2_URI_NFS_DEFAULT_PORT},
        {"tip",      AXIS2_URI_TIP_DEFAULT_PORT},
        {"acap",     AXIS2_URI_ACAP_DEFAULT_PORT},
        {"telnet",   AXIS2_URI_TELNET_DEFAULT_PORT},
        {"ssh",      AXIS2_URI_SSH_DEFAULT_PORT},
        { NULL, 0xFFFF }     /* unknown port */
    };

/* Here is the hand-optimized parse_uri_components().  There are some wild
 * tricks we could pull in assembly language that we don't pull here... like we
 * can do word-at-time scans for delimiter characters using the same technique
 * that fast axutil_memchr()s use.  But that would be way non-portable. -djg
 */

/* We have a axis2_table_t that we can index by character and it tells us if the
 * character is one of the interesting delimiters.  Note that we even get
 * compares for NUL for free -- it's just another delimiter.
 */

#define T_COLON           0x01        /* ':' */
#define T_SLASH           0x02        /* '/' */
#define T_QUESTION        0x04        /* '?' */
#define T_HASH            0x08        /* '#' */
#define T_NUL             0x80        /* '\0' */

#if AXIS2_CHARSET_EBCDIC
/* Delimiter table for the EBCDIC character set */
static const unsigned char uri_delims[256] =
    {
        T_NUL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, T_SLASH, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, T_QUESTION,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, T_COLON, T_HASH, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
#else
/* Delimiter table for the ASCII character set */
static const unsigned char uri_delims[256] =
    {
        T_NUL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, T_HASH, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, T_SLASH,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, T_COLON, 0, 0, 0, 0, T_QUESTION,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
#endif


/* it works like this:
    if (uri_delims[ch] & NOTEND_foobar) {
        then we're not at a delimiter for foobar
    }
*/

/* Note that we optimize the scheme scanning here, we cheat and let the
 * compiler know that it doesn't have to do the & masking.
 */
#define NOTEND_SCHEME     (0xff)
#define NOTEND_HOSTINFO   (T_SLASH | T_QUESTION | T_HASH | T_NUL)
#define NOTEND_PATH       (T_QUESTION | T_HASH | T_NUL)


/**
 * A structure to encompass all of the fields in a uri
 */
struct axutil_uri
{
    /** scheme ("http"/"ftp"/...) */
    axis2_char_t *scheme;
    /** combined [user[:password]\@]host[:port] */
    axis2_char_t *hostinfo;
    /** user name, as in http://user:passwd\@host:port/ */
    axis2_char_t *user;
    /** password, as in http://user:passwd\@host:port/ */
    axis2_char_t *password;
    /** hostname from URI (or from Host: header) */
    axis2_char_t *hostname;
    /** port string (integer representation is in "port") */
    axis2_char_t *port_str;
    /** the request path (or "/" if only scheme://host was given) */
    axis2_char_t *path;
    /** Everything after a '?' in the path, if present */
    axis2_char_t *query;
    /** Trailing "#fragment" string, if present */
    axis2_char_t *fragment;

    /** structure returned from gethostbyname() */
    struct hostent *hostent;

    /** The port number, numeric, valid only if port_str  */
    axis2_port_t port;

    /** has the structure been initialized */
unsigned is_initialized:
    1;

    /** has the DNS been looked up yet */
unsigned dns_looked_up:
    1;
    /** has the dns been resolved yet */
unsigned dns_resolved:
    1;
};

AXIS2_EXTERN axutil_uri_t * AXIS2_CALL
axutil_uri_create(const axutil_env_t *env)
{
    axutil_uri_t *uri = NULL;
    AXIS2_ENV_CHECK(env, NULL);

    uri = (axutil_uri_t *)AXIS2_MALLOC(env->allocator,
        sizeof(axutil_uri_t));

    if (!uri)
    {
        AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
        return NULL;
    }
    uri->scheme = NULL;
    uri->hostinfo = NULL;
    uri->user = NULL;
    uri->password = NULL;
    uri->hostname = NULL;
    uri->port_str = NULL;
    uri->path = NULL;
    uri->query = NULL;
    uri->fragment = NULL;
    uri->hostent = NULL;

    return uri;
}

AXIS2_EXTERN void AXIS2_CALL
axutil_uri_free(axutil_uri_t *uri,
    const axutil_env_t *env)
{
    AXIS2_ENV_CHECK(env, AXIS2_FAILURE);

    if (uri->scheme)
    {
        AXIS2_FREE(env->allocator, uri->scheme);
        uri->scheme = NULL;
    }

    if (uri->hostinfo)
    {
        AXIS2_FREE(env->allocator, uri->hostinfo);
        uri->hostinfo = NULL;
    }

    if (uri->user)
    {
        AXIS2_FREE(env->allocator, uri->user);
        uri->user = NULL;
    }

    if (uri->password)
    {
        AXIS2_FREE(env->allocator, uri->password);
        uri->password = NULL;
    }

    if (uri->hostname)
    {
        AXIS2_FREE(env->allocator, uri->hostname);
        uri->hostname = NULL;
    }

    if (uri->port_str)
    {
        AXIS2_FREE(env->allocator, uri->port_str);
        uri->port_str = NULL;
    }

    if (uri->path)
    {
        AXIS2_FREE(env->allocator, uri->path);
        uri->path = NULL;
    }

    if (uri->query)
    {
        AXIS2_FREE(env->allocator, uri->query);
        uri->query = NULL;
    }

    if (uri->fragment)
    {
        AXIS2_FREE(env->allocator, uri->fragment);
        uri->fragment = NULL;
    }

    AXIS2_FREE(env->allocator, uri);

    return;
}

/* parse_uri_components():
 * Parse a given URI, fill in all supplied fields of a uri_components
 * structure. This eliminates the necessity of extracting host, port,
 * path, query info repeatedly in the modules.
 * Side effects:
 *  - fills in fields of uri_components *uptr
 *  - none on any of the r->* fields
 */

AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
axutil_uri_parse_string(const axutil_env_t *env,
    const axis2_char_t *uri_str)
{
    axutil_uri_t *uri = NULL;
    const axis2_char_t *s;
    const axis2_char_t *s1;
    const axis2_char_t *hostinfo;
    axis2_char_t *endstr;
    int port;
    int v6_offset1 = 0, v6_offset2 = 0;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, uri_str, NULL);

    uri = (axutil_uri_t *) axutil_uri_create(env);

    /* Initialize the structure. parse_uri() and parse_uri_components()
     * can be called more than once per request.
     */
    /*memset (uri, '\0', sizeof(*uri));*/
    uri->is_initialized = 1;

    /* We assume the processor has a branch predictor like most --
     * it assumes forward branches are untaken and backwards are taken.  That's
     * the reason for the gotos.
     */
    if (uri_str[0] == '/')
    {
        /* RFC2396 #4.3 says that two leading slashes mean we have an
         * authority component, not a path!  Fixing this looks scary
         * with the gotos here.  But if the existing logic is valid,
         * then presumably a goto pointing to deal_with_authority works.
         *
         * RFC2396 describes this as resolving an ambiguity.  In the
         * case of three or more slashes there would seem to be no
         * ambiguity, so it is a path after all.
         */
        if (uri_str[1] == '/' && uri_str[2] != '/')
        {
            s = uri_str + 2 ;
            goto deal_with_authority ;
        }

deal_with_path:
        /* we expect uri to point to first character of path ... remember
         * that the path could be empty -- http://foobar?query for example
         */
        s = uri_str;
        while ((uri_delims[*(unsigned char *)s] & NOTEND_PATH) == 0)
        {
            ++s;
        }
        if (s != uri_str)
        {
            uri->path = axutil_strmemdup(uri_str, s - uri_str, env);
        }
        if (*s == 0)
        {
            return uri;
        }
        if (*s == '?')
        {
            ++s;
            s1 = strchr(s, '#');
            if (s1)
            {
                uri->fragment = axutil_strdup(env, s1 + 1);
                uri->query = axutil_strmemdup(s, s1 - s, env);
            }
            else
            {
                uri->query = axutil_strdup(env, s);
            }
            return uri;
        }
        /* otherwise it's a fragment */
        uri->fragment = axutil_strdup(env, s + 1);

        return uri;
    }

    /* find the scheme: */
    s = uri_str;
    while ((uri_delims[*(unsigned char *)s] & NOTEND_SCHEME) == 0)
    {
        ++s;
    }
    /* scheme must be non-empty and followed by :// */
    if (s == uri_str || s[0] != ':' || s[1] != '/' || s[2] != '/')
    {
        goto deal_with_path;        /* backwards predicted taken! */
    }

    uri->scheme = axutil_strmemdup(uri_str, s - uri_str, env);
    s += 3;

deal_with_authority:
    hostinfo = s;
    while ((uri_delims[*(unsigned char *)s] & NOTEND_HOSTINFO) == 0)
    {
        ++s;
    }
    uri_str = s;        /* whatever follows hostinfo is start of uri */
    uri->hostinfo = axutil_strmemdup(hostinfo, uri_str - hostinfo, env);

    /* If there's a username:password@host:port, the @ we want is the last @...
     * too bad there's no memrchr()... For the C purists, note that hostinfo
     * is definately not the first character of the original uri so therefore
     * &hostinfo[-1] < &hostinfo[0] ... and this loop is valid C.
     */
    do
    {
        --s;
    }
    while (s >= hostinfo && *s != '@');
    if (s < hostinfo)
    {
        /* again we want the common case to be fall through */
deal_with_host:
        /* We expect hostinfo to point to the first character of
         * the hostname.  If there's a port it is the first colon,
         * except with IPv6.
         */
        if (*hostinfo == '[')
        {
            v6_offset1 = 1;
            v6_offset2 = 2;
            s = axutil_memchr(hostinfo, ']', uri_str - hostinfo);
            if (!s)
            {
                return NULL;
            }
            if (*++s != ':')
            {
                s = NULL; /* no port */
            }
        }
        else
        {
            s = axutil_memchr(hostinfo, ':', uri_str - hostinfo);
        }
        if (!s)
        {
            /* we expect the common case to have no port */
            uri->hostname = axutil_strmemdup(hostinfo + v6_offset1,
                 uri_str - hostinfo - v6_offset2, env);
            goto deal_with_path;
        }
        uri->hostname = axutil_strmemdup(
            hostinfo + v6_offset1,
            s - hostinfo - v6_offset2, env);
        ++s;
        uri->port_str = axutil_strmemdup(s, uri_str - s, env);
        if (uri_str != s)
        {
            port = strtol(uri->port_str, &endstr, 10);
            uri->port = port;
            if (*endstr == '\0')
            {
                goto deal_with_path;
            }
            /* Invalid characters after ':' found */
            return NULL;
        }
        uri->port = axutil_uri_port_of_scheme(uri->scheme);
        goto deal_with_path;
    }

    /* first colon delimits username:password */
    s1 = axutil_memchr(hostinfo, ':', s - hostinfo);
    if (s1)
    {
        uri->user = axutil_strmemdup(hostinfo, s1 - hostinfo, env);
        ++s1;
        uri->password = axutil_strmemdup(s1, s - s1, env);
    }
    else
    {
        uri->user = axutil_strmemdup(hostinfo, s - hostinfo, env);
    }
    hostinfo = s + 1;
    goto deal_with_host;

    return uri;
}

/* Special case for CONNECT parsing: it comes with the hostinfo part only */
/* See the INTERNET-DRAFT document "Tunneling SSL Through a WWW Proxy"
 * currently at http://www.mcom.com/newsref/std/tunneling_ssl.html
 * for the format of the "CONNECT host:port HTTP/1.0" request
 */
AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
axutil_uri_parse_hostinfo(const axutil_env_t *env,
    const axis2_char_t *hostinfo)
{
    axutil_uri_t *uri = NULL;
    const axis2_char_t *s;
    axis2_char_t *endstr;
    const axis2_char_t *rsb;
    int v6_offset1 = 0;

    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, hostinfo, NULL);

    uri = (axutil_uri_t *) axutil_uri_create(env);

    /* Initialize the structure. parse_uri() and parse_uri_components()
     * can be called more than once per request.
     */
    memset(uri, '\0', sizeof(*uri));
    uri->is_initialized = 1;
    uri->hostinfo = axutil_strdup(env, hostinfo);

    /* We expect hostinfo to point to the first character of
     * the hostname.  There must be a port, separated by a colon
     */
    if (*hostinfo == '[')
    {
        if (!(rsb = strchr(hostinfo, ']')) ||
            *(rsb + 1) != ':')
        {
            return NULL;
        }
        /* literal IPv6 address */
        s = rsb + 1;
        ++hostinfo;
        v6_offset1 = 1;
    }
    else
    {
        s = strchr(hostinfo, ':');
    }
    if (!s)
    {
        return NULL;
    }
    uri->hostname = axutil_strndup(env, hostinfo, s - hostinfo - v6_offset1);
    ++s;
    uri->port_str = axutil_strdup(env, s);
    if (*s != '\0')
    {
        uri->port = (unsigned short) strtol(uri->port_str, &endstr, 10);
        if (*endstr == '\0')
        {
            return uri;
        }
        /* Invalid characters after ':' found */
    }
    return NULL;
}

/* Resolve relative to a base.  This means host/etc, and (crucially) path */
AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
axutil_uri_resolve_relative(const axutil_env_t *env,
    const axutil_uri_t* base,
    axutil_uri_t* uri)
{
    AXIS2_ENV_CHECK(env, NULL);
    AXIS2_PARAM_CHECK(env->error, base, NULL);
    AXIS2_PARAM_CHECK(env->error, uri, NULL);

    if (!uri || !base || ! base->is_initialized
        || ! uri->is_initialized)
    {
        return NULL;
    }
    /* The interesting bit is the path.  */
    if (!uri->path)
    {
        if (!uri->hostname)
        {
            /* is this compatible with is_initialised?  Harmless in any case */
            uri->path = base->path ? base->path : axutil_strdup(env, "/") ;
        }
        else
        {
            /* deal with the idiosyncracy of APR allowing path==NULL
             * without risk of breaking back-compatibility
             */
            uri->path = axutil_strdup(env, "/") ;
        }
    }
    else if (uri->path[0] != '/')
    {
        size_t baselen ;
        const char* basepath = base->path ? base->path : "/" ;
        const char* path = uri->path ;
        const char* base_end = strrchr(basepath, '/') ;

        /* if base is nonsensical, bail out */
        if (basepath[0] != '/')
        {
            return NULL;
        }
        /* munch "up" components at the start, and chop them from base path */
        while (!strncmp(path, "../", 3))
        {
            while (base_end > basepath)
            {
                if (*--base_end == '/')
                {
                    break ;
                }
            }
            path += 3 ;
        }
        /* munch "here" components at the start */
        while (!strncmp(path, "./", 2))
        {
            path += 2 ;
        }
        baselen = base_end - basepath + 1 ;
        uri->path = AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) * baselen + strlen(path) + 1) ;
        memcpy(uri->path, basepath, baselen) ;
        strcpy(uri->path + baselen, path) ;
    }

    /* The trivial bits are everything-but-path */
    if (!uri->scheme)
    {
        uri->scheme = axutil_strdup(env, base->scheme) ;
    }
    if (!uri->hostinfo)
    {
        uri->hostinfo = axutil_strdup(env, base->hostinfo) ;
    }
    if (!uri->user)
    {
        uri->user = axutil_strdup(env, base->user) ;
    }
    if (!uri->password)
    {
        uri->password = axutil_strdup(env, base->password) ;
    }
    if (!uri->hostname)
    {
        uri->hostname = axutil_strdup(env, base->hostname) ;
    }
    if (!uri->port_str)
    {
        uri->port_str = axutil_strdup(env, base->port_str) ;
    }
    if (!uri->hostent)
    {
        uri->hostent = base->hostent ;
    }
    if (! uri->port)
    {
        uri->port = base->port ;
    }

    return uri;
}

AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
axutil_uri_parse_relative(const axutil_env_t *env,
    const axutil_uri_t* base,
    const char* uri)
{
    axutil_uri_t *uptr = NULL;

    uptr = axutil_uri_parse_string(env, uri) ;
    if (! uptr && AXIS2_SUCCESS != AXIS2_ERROR_GET_STATUS_CODE(env->error))
    {
        return uptr ;
    }
    uptr = axutil_uri_resolve_relative(env, base, uptr) ;

    return uptr;
}
AXIS2_EXTERN axis2_port_t AXIS2_CALL
axutil_uri_port_of_scheme(const axis2_char_t *scheme_str)
{
    schemes_t *scheme;

    if (scheme_str)
    {
        for (scheme = schemes; scheme->name ; ++scheme)
        {
            if (axutil_strcasecmp(scheme_str, scheme->name) == 0)
            {
                return scheme->default_port;
            }
        }
    }
    return 0;
}

AXIS2_EXTERN axutil_uri_t *AXIS2_CALL
axutil_uri_clone(const axutil_uri_t* uri,
    const axutil_env_t *env)
{
    axutil_uri_t *new_uri = NULL;

    AXIS2_ENV_CHECK(env, NULL);
    new_uri = (axutil_uri_t *) axutil_uri_create(env);

    new_uri->scheme = axutil_strdup(env, uri->scheme);
    new_uri->hostinfo = axutil_strdup(env, uri->hostinfo);
    new_uri->user = axutil_strdup(env, uri->user);
    new_uri->password = axutil_strdup(env, uri->password);
    new_uri->hostname = axutil_strdup(env, uri->hostname);
    new_uri->port_str = axutil_strdup(env, uri->port_str);
    new_uri->path = axutil_strdup(env, uri->path);
    new_uri->query = axutil_strdup(env, uri->query);
    new_uri->fragment = axutil_strdup(env, uri->fragment);
    new_uri->hostent = uri->hostent;
    new_uri->port = uri->port;
    new_uri->is_initialized = uri->is_initialized;
    new_uri->dns_looked_up = uri->dns_looked_up;
    new_uri->dns_resolved = uri->dns_resolved;

    return new_uri;
}

/* Unparse a axutil_uri_t structure to an URI string.
 * Optionally suppress the password for security reasons.
 */
AXIS2_EXTERN axis2_char_t * AXIS2_CALL
axutil_uri_to_string(const axutil_uri_t *uri,
    const axutil_env_t *env,
    unsigned flags)
{
    axis2_char_t *ret = "";
    AXIS2_ENV_CHECK(env, NULL);

    /* If suppressing the site part, omit both user name & scheme://hostname */
    if (!(flags & AXIS2_URI_UNP_OMITSITEPART))
    {

        /* Construct a "user:password@" string, honoring the passed
         * AXIS2_URI_UNP_ flags: */
        if (uri->user || uri->password)
        {
            ret = axutil_strcat(env,
                (uri->user     && !(flags & AXIS2_URI_UNP_OMITUSER))
                ? uri->user : "",
                (uri->password && !(flags & AXIS2_URI_UNP_OMITPASSWORD))
                ? ":" : "",
                (uri->password && !(flags & AXIS2_URI_UNP_OMITPASSWORD))
                ? ((flags & AXIS2_URI_UNP_REVEALPASSWORD)
                ? uri->password : "XXXXXXXX")
                : "",
                ((uri->user     && !(flags & AXIS2_URI_UNP_OMITUSER)) ||
                (uri->password && !(flags & AXIS2_URI_UNP_OMITPASSWORD)))
                ? "@" : "",
                NULL);
        }

        /* Construct scheme://site string */
        if (uri->hostname)
{
            int is_default_port;
            const axis2_char_t *lbrk = "", *rbrk = "";

            if (strchr(uri->hostname, ':'))
            { /* v6 literal */
                lbrk = "[";
                rbrk = "]";
            }

            is_default_port =
                (uri->port_str == NULL ||
                    uri->port == 0 ||
                    uri->port == axutil_uri_port_of_scheme(uri->scheme));

            if (uri->scheme)
            {
                ret = axutil_strcat(env,
                    uri->scheme, "://", ret,
                    lbrk, uri->hostname, rbrk,
                    is_default_port ? "" : ":",
                    is_default_port ? "" : uri->port_str,
                    NULL);
            }
            else
            {
                /* A violation of RFC2396, but it is clear from section 3.2
                 * that the : belongs above to the scheme, while // belongs
                 * to the authority, so include the authority prefix while
                 * omitting the "scheme:" that the user neglected to pass us.
                 */
                ret = axutil_strcat(env,
                    "//", ret, lbrk, uri->hostname, rbrk,
                    is_default_port ? "" : ":",
                    is_default_port ? "" : uri->port_str,
                    NULL);
            }
        }
    }

    /* Should we suppress all path info? */
    if (!(flags & AXIS2_URI_UNP_OMITPATHINFO))
    {
        /* Append path, query and fragment strings: */
        ret = axutil_strcat(env,
            ret,
            (uri->path)
            ? uri->path : "",
            (uri->query    && !(flags & AXIS2_URI_UNP_OMITQUERY))
            ? "?" : "",
            (uri->query    && !(flags & AXIS2_URI_UNP_OMITQUERY))
            ? uri->query : "",
            (uri->fragment && !(flags & AXIS2_URI_UNP_OMITQUERY))
            ? "#" : NULL,
            (uri->fragment && !(flags & AXIS2_URI_UNP_OMITQUERY))
            ? uri->fragment : NULL,
            NULL);
    }
    return ret;
}

axis2_char_t *AXIS2_CALL
axutil_uri_get_protocol(axutil_uri_t *uri,
    const axutil_env_t *env)
{
    return uri->scheme;
}

axis2_char_t *AXIS2_CALL
axutil_uri_get_server(axutil_uri_t *uri,
    const axutil_env_t *env)
{
    return uri->hostinfo;
}

axis2_port_t AXIS2_CALL
axutil_uri_get_port(axutil_uri_t *uri,
    const axutil_env_t *env)
{
    return uri->port;
}

axis2_char_t *AXIS2_CALL
axutil_uri_get_path(axutil_uri_t *uri,
    const axutil_env_t *env)
{
    return uri->path;
}

