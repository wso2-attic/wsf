dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(axis2c-src, 1.6.0)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/axis2c)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET


dnl check for flavours of varargs macros (test from GLib)
AC_MSG_CHECKING(for ISO C99 varargs macros in C)
AC_TRY_COMPILE([],[
int a(int p1, int p2, int p3);
#define call_a(...) a(1,__VA_ARGS__)
call_a(2,3);
],axis2c_have_iso_c_varargs=yes,axis2c_have_iso_c_varargs=no)
AC_MSG_RESULT($axis2c_have_iso_c_varargs)

AC_MSG_CHECKING(for GNUC varargs macros)
AC_TRY_COMPILE([],[
int a(int p1, int p2, int p3);
#define call_a(params...) a(1,params)
call_a(2,3);
],axis2c_have_gnuc_varargs=yes,axis2c_have_gnuc_varargs=no)
AC_MSG_RESULT($axis2c_have_gnuc_varargs)

dnl Output varargs tests
if test x$axis2c_have_iso_c_varargs = xyes; then
    AC_DEFINE(HAVE_ISO_VARARGS,1,[Have ISO C99 varargs macros])
fi
if test x$axis2c_have_gnuc_varargs = xyes; then
    AC_DEFINE(HAVE_GNUC_VARARGS,1,[Have GNU-style varargs macros])
fi

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)
AC_CHECK_LIB(z, inflate)
AC_CHECK_LIB(socket,socket,LDFLAGS="$LDFLAGS -lsocket",)

if test -d $srcdir/util; then
    AC_CONFIG_SUBDIRS(util)
fi

if test -d $srcdir/axiom; then
    AC_CONFIG_SUBDIRS(axiom)
fi

if test -d $srcdir/neethi; then
    AC_CONFIG_SUBDIRS(neethi)
fi

#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall  -Wno-implicit-function-declaration -g -D_GNU_SOURCE"
#    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration"
fi
LDFLAGS="$LDFLAGS -lpthread"

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])
AC_CHECK_HEADERS([sys/socket.h])
AC_CHECK_HEADERS([net/if.h], [], [],
[#include <stdio.h>
#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
# include <stdlib.h>
# endif
#endif
#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
])
AC_CHECK_HEADERS([linux/if.h],[],[],
[
#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
])
AC_CHECK_HEADERS([net/if_types.h])
AC_CHECK_HEADERS([net/if_dl.h])

dnl This is a check to see if we are running MacOS X
dnl It may be better to do a Darwin check
AC_CHECK_HEADERS([sys/appleapiopts.h]) 
dnl Checks for typedefs, structures, and compiler characteristics.

dnl Checks for library functions.
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])

AC_MSG_CHECKING(whether to use archive)
AC_ARG_WITH(archive,
[  --with-archive[=PATH]      Find the zlib header files in 'PATH'.
    If you omit the '=PATH' part completely, the configure script will search
    '/usr/include/' for zlib headers.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ZLIBBUILD=""
    zliblibs=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    zliblibs="minizip/libaxis2_minizip.la"
    CFLAGS="$CFLAGS -DAXIS2_ARCHIVE_ENABLED"
    if test -d $withval; then
        zlibinc="-I$withval"
    elif test -d '/usr/include'; then
        zlibinc="-I/usr/include"
    else
        AC_MSG_ERROR(could not find zlib stop)
    fi
    ZLIBBUILD="minizip"
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

GUTHTHILA_LIBS=""

AC_MSG_CHECKING(whether to build guththila xml parser library)
AC_ARG_ENABLE(guththila, [  --enable-guththila    
                          build Guththila XML parser library wrapper (default=yes)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    WRAPPER_DIR="guththila"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  WRAPPER_DIR="guththila"
  AC_CONFIG_SUBDIRS(guththila)
  GUTHTHILA_LIBS="/guththila/src/"
  GUTHTHILA_DIR="guththila"

)

AC_MSG_CHECKING(whether to build libxml2 xml parser library)
AC_ARG_ENABLE(libxml2, [  --enable-libxml2    
                          build Libxml2 XML parser library wrapper (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    WRAPPER_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    WRAPPER_DIR="libxml2"
    PKG_CHECK_MODULES(PARSER, libxml-2.0)
    CFLAGS="$CFLAGS $PARSER_CFLAGS"
    LDFLAGS="$LDFLAGS $PARSER_LIBS"
    ;;
  esac ],
  AC_MSG_RESULT(no)
)


AC_MSG_CHECKING(whether to build tcp transport)
AC_ARG_ENABLE(tcp, [  --enable-tcp
                          build tcp transport (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    TCP_DIR="tcp"

    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to build udp transport)
AC_ARG_ENABLE(udp, [  --enable-udp
                          build udp transport (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    UDP_DIR="udp"

    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to use apache2 as server transport)
AC_ARG_WITH(apache2,
[  --with-apache2[=PATH]      Find the Apache2 HTTP Web server header files in 'PATH'.
    If this option is given, the Apache2 httpd module would be built.
    'PATH' should point to Apache2 httpd include files location.
    If you omit the '=PATH' part completely, the configure script will search
    '/usr/include/apache2' for Apache2 headers.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    APACHE2BUILD=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find apache2 include dir in the path pointed by APACHE2_HOME env variable
    if test -d $withval; then
        apache2inc="-I$withval"
    dnl else find the apache2 include dir in /usr/local/apache2
    elif test -d '/usr/include/apache2'; then
        apache2inc="-I/usr/include/apache2"
    else
        AC_MSG_ERROR(could not find apache2. stop)
    fi
    APACHE2BUILD="apache2"
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to use apr. Note that if you build with apache2 you might need to do this.)
AC_ARG_WITH(apr,
[  --with-apr[=PATH]      Find the APR header files in 'PATH'.
    Some Apache2 distributions, specially development versions, install APR 
    (Apache Portable Run-time) include files in a separate location. 
    In that case, to build Apache2 httpd module, this option is also required.
    'PATH' should point to APR include files location.
    If you omit the '=PATH' part completely, the configure script will search
    '/usr/include/apr-0' for APR headers.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find apr include dir in the path
    if test -d $withval; then
        aprinc="-I$withval"
    dnl else find the apache2 include dir in /usr/local/apache2
    elif test -d '/usr/include/apr-0'; then
        aprinc="-I/usr/include/apr-0"
    else
        AC_MSG_ERROR(could not find apr. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to build tests)
AC_ARG_ENABLE(tests, [  --enable-tests    
                          build tests (default=no)],
[ case "${enableval}" in
  yes)
    AC_MSG_RESULT(no)
    TESTDIR=""
    ;;
  *)
    AC_MSG_RESULT(no)
    TESTDIR=""

    ;;
  esac ],
  AC_MSG_RESULT(no)
  TESTDIR=""
)


AC_MSG_CHECKING(whether to enable trace)
AC_ARG_ENABLE(trace, [  --enable-trace    
                          enable logging trace messages, useful when debugging (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    CFLAGS="$CFLAGS"
    ;;
  *)
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DAXIS2_TRACE"
    ;;
  esac ],
  AC_MSG_RESULT(no)
  CFLAGS="$CFLAGS"
)

AC_MSG_CHECKING(whether to enable multi threading)
AC_ARG_ENABLE(multi-thread, [  --enable-multi-thread  
                          enable multi threading (default=yes)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    CFLAGS="$CFLAGS"
    ;;
  *)
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DAXIS2_SVR_MULTI_THREADED"
    ;;
  esac ],[
  AC_MSG_RESULT(yes)
  CFLAGS="$CFLAGS -DAXIS2_SVR_MULTI_THREADED"]
)

AC_MSG_CHECKING(whether to use openssl)
AC_ARG_ENABLE(openssl, [  --enable-openssl  
                          enable OpenSSL support in client transport (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    CFLAGS="$CFLAGS"
    ssl_enabled=false
    ;;
  *)
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DAXIS2_SSL_ENABLED"
    ssl_enabled=true
    ;;
  esac ],
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DAXIS2_SSL_ENABLED"
    ssl_enabled=true
	opensslinc="-I/usr/include/openssl"
	openssllib=""

)

AC_MSG_CHECKING(whether to use libcurl)
AC_ARG_ENABLE(libcurl, [  --enable-libcurl  
                          enable libcurl based client transport (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    CFLAGS="$CFLAGS"
    libcurl_enabled=false
    ;;
  *)
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DAXIS2_LIBCURL_ENABLED"
    libcurl_enabled=true
    ;;
  esac ],
  AC_MSG_RESULT(no)
  CFLAGS="$CFLAGS"
)

AC_MSG_CHECKING(whether to use XMPP as a transport)
AC_ARG_WITH(xmpp,
[  --with-xmpp[=PATH]   Whether to build XMPP transport support.
    ],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    XMPP_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find iksemel include dir
    if test -d $withval; then
        iksemelinc="-I$withval/include"
        iksemellib="-L$withval/lib -liksemel"
    	XMPP_DIR="xmpp"
    dnl else find the iksemel include dir in /usr/include
    elif test -d '/usr'; then
        iksemelinc="-I/usr/include"
        iksemellib="-L/usr/lib -liksemel"
    	XMPP_DIR="xmpp"
    else
        AC_MSG_ERROR(could not find iksemel. stop)
    fi
	XMPP_DIR="xmpp"
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to use gssapi)
AC_ARG_ENABLE(gssapi, [  --enable-gssapi      enable gssapi (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    CFLAGS="$CFLAGS"
    gssapi_enabled=false
    ;;
  *)
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -DAXIS2_XMPP_GSSAPI"
    gssapi_enabled=true
    ;;
  esac ],
  AC_MSG_RESULT(no)
  CFLAGS="$CFLAGS"
)

#AC_MSG_CHECKING(whether to build xmpp)
#AC_ARG_ENABLE(xmpp, [  --enable-xmpp
#                          enable xmpp build (default=no)],
#[ case "${enableval}" in
#  no)
#    AC_MSG_RESULT(no)
#    CFLAGS="$CFLAGS"
#    xmpp_enabled=false
#    ;;
#  *)
#    AC_MSG_RESULT(yes)
#    XMPP_DIR="xmpp"
#    CFLAGS="$CFLAGS -DAXIS2_XMPP_ENABLED"
#    xmpp_enabled=false
#    ;;
#  esac ],
#  AC_MSG_RESULT(no)
#  CFLAGS="$CFLAGS"
#)


APACHE2INC=$apache2inc
IKSEMELINC=$iksemelinc
IKSEMELLIB=$iksemellib
APRINC=$aprinc
VERSION_NO="6:0:6"
OPENSSLINC=$opensslinc
OPENSSLLIB=$openssllib

AC_SUBST(OPENSSLLIB)
AC_SUBST(OPENSSLINC)
AC_SUBST(VERSION_NO)
AC_SUBST(PARSER_LIBS)
AC_SUBST(APACHE2INC)
AC_SUBST(IKSEMELINC)
AC_SUBST(IKSEMELLIB)
AC_SUBST(APRINC)
AC_SUBST(DICLIENT_DIR)
AC_SUBST(TESTDIR)
AC_SUBST(SAMPLES)
AC_SUBST(APACHE2BUILD)
AC_SUBST(PARSER_DIR)
AC_SUBST(WRAPPER_DIR)
AC_SUBST(XMPP_DIR)
AC_SUBST(TCP_DIR)
AC_SUBST(UDP_DIR)
AC_SUBST(GUTHTHILA_DIR)
AC_SUBST(GUTHTHILA_LIBS)
AC_SUBST(ZLIBBUILD)
AM_CONDITIONAL(AXIS2_SSL_ENABLED, test x$ssl_enabled = xtrue)
AM_CONDITIONAL(AXIS2_LIBCURL_ENABLED, test x$libcurl_enabled = xtrue)
AM_CONDITIONAL(AXIS2_XMPP_GSSAPI, test x$gssapi_enabled = xtrue)
AM_CONDITIONAL(AXIS2_XMPP_ENABLED, test x$xmpp_enabled = xtrue)

#export PARSER_DIR
export WRAPPER_DIR
export prefix 

AC_CONFIG_FILES([Makefile \
    src/Makefile \
    src/core/Makefile \
    src/core/description/Makefile \
    src/core/context/Makefile \
    src/core/engine/Makefile \
    src/core/addr/Makefile \
    src/core/phaseresolver/Makefile \
    src/core/transport/Makefile \
    src/core/transport/http/Makefile \
    src/core/transport/http/common/Makefile \
    src/core/transport/http/util/Makefile \
    src/core/transport/http/sender/Makefile \
    src/core/transport/http/sender/ssl/Makefile \
    src/core/transport/http/sender/libcurl/Makefile \
    src/core/transport/http/receiver/Makefile \
    src/core/transport/http/server/simple_axis2_server/Makefile \
    src/core/transport/http/server/Makefile \
    src/core/transport/tcp/Makefile \
    src/core/transport/tcp/sender/Makefile \
    src/core/transport/tcp/receiver/Makefile \
    src/core/transport/tcp/server/Makefile \
    src/core/transport/tcp/server/simple_tcp_server/Makefile \
    src/core/transport/xmpp/Makefile \
    src/core/transport/xmpp/sender/Makefile \
    src/core/transport/xmpp/receiver/Makefile \
    src/core/transport/xmpp/server/Makefile \
    src/core/transport/xmpp/server/simple_xmpp_server/Makefile \
    src/core/transport/udp/Makefile \
    src/core/transport/udp/sender/Makefile \
    src/core/transport/udp/receiver/Makefile \
    src/core/transport/udp/server/Makefile \
    src/core/deployment/Makefile \
    src/core/clientapi/Makefile \
    src/core/receivers/Makefile \
    src/core/util/Makefile \
    src/modules/Makefile \
    src/modules/mod_addr/Makefile \
    src/modules/mod_log/Makefile \
    ides/Makefile \
    include/Makefile \
    axis2c.pc
    ])
    
AC_OUTPUT
