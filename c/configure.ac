dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wso2-wsf-c-src, 2.0.0)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/opt/wso2/wsf_c)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)
AC_CHECK_LIB(z, inflate)

if test -d $srcdir/axis2c; then
    AC_CONFIG_SUBDIRS(axis2c)
fi

if test -d $srcdir/axis2c/tools/tcpmon; then
    AC_CONFIG_SUBDIRS(axis2c/tools/tcpmon)
fi

#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
#    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration "
    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration -Wall -D_GNU_SOURCE"
fi
LDFLAGS="-lpthread"

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

AC_MSG_CHECKING(path to use sqlite storage .)
AC_ARG_WITH(sqlite,
[  --with-sqlite[=PATH]      use sqlite storage.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    WRAPPER_DIR=""
    ;;
  *)
    AC_MSG_RESULT($withval)
    WRAPPER_DIR="sqlite"
    dnl Find sqlite include dir in the path
    if test -d $withval; then
        sqliteinc="-I$withval"
    dnl else find the sqliteinc include dir in /usr/include
    elif test -d '/usr/include'; then
        sqliteinc="-I/usr/include"
    else
        AC_MSG_ERROR(could not find sqliteinc. stop)
    fi
    WRAPPER_DIR="sqlite"
    LDFLAGS="$LDFLAGS -lsqlite3"
    ;;
  esac ],
  AC_MSG_RESULT(yes)
  WRAPPER_DIR="sqlite"
  sqliteinc="-I/usr/include"
  LDFLAGS="$LDFLAGS -lsqlite3"
)


AC_MSG_CHECKING(whether to use openssl)
AC_ARG_ENABLE(openssl, [  --enable-openssl	enable OpenSSL support in client transport (default=no)],
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
  AC_MSG_RESULT(no)
  CFLAGS="$CFLAGS"
)

AC_MSG_CHECKING(whether to use xmpp as a transport)
AC_ARG_WITH(xmpp,
[  --with-xmpp[=PATH]   Whether to build XMPP support.
    ],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    XMPP_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    dnl Find iksemel XMPP include dir 
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
        AC_MSG_ERROR(Could not find XMPP. stop)
    fi
        XMPP_DIR="xmpp"
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

AC_MSG_CHECKING(whether to build rampart)
AC_ARG_ENABLE(rampart, [  --enable-rampart	build rampart. default=yes],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    RAMPART_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    RAMPART_DIR="rampartc"
    CFLAGS="$CFLAGS -DWSF_RAMPART_ENABLED"
    RAMPART_LIBS="../../rampartc/src/core/libmod_rampart.la"
    OMXMLSEC_LIBS="../../rampartc/src/omxmlsec/libomxmlsec.la"
    ;;
  esac ],
  AC_MSG_RESULT(yes)
  RAMPART_DIR="rampartc"
)

AC_SUBST(RAMPART_DIR)
if test "rampartc" = ${RAMPART_DIR}; then
    AC_CONFIG_SUBDIRS(rampartc)
fi    

AC_MSG_CHECKING(whether to build wsclient)
AC_ARG_ENABLE(wsclient, [  --enable-wsclient	build wsclient. default=yes],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    WSCLIENT_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    WSCLIENT_DIR="wsclient"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  WSCLIENT_DIR="wsclient"
)

AC_SUBST(WSCLIENT_DIR)
if test "wsclient" = ${WSCLIENT_DIR}; then
    AC_CONFIG_SUBDIRS(wsclient)
fi
AC_MSG_CHECKING(whether to build sandesha)
AC_ARG_ENABLE(sandesha, [  --enable-sandesha	build sandesha. default=yes],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    SANDESHA_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    SANDESHA_DIR="sandesha2c"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  SANDESHA_DIR="sandesha2c"
)

AC_SUBST(SANDESHA_DIR)
if test "sandesha2c" = ${SANDESHA_DIR}; then
    AC_CONFIG_SUBDIRS(sandesha2c)
fi    

AC_MSG_CHECKING(whether to build savan)
AC_ARG_ENABLE(savan, [  --enable-savan	build savan. default=yes],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    SAVAN_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    SAVAN_DIR="savanc"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  SAVAN_DIR="savanc"
)

AC_SUBST(SAVAN_DIR)
if test "savanc" = ${SAVAN_DIR}; then
    AC_CONFIG_SUBDIRS(savanc)
fi

AC_MSG_CHECKING(whether to build guththila xml parser library)
AC_ARG_ENABLE(guththila, [  --enable-guththila	build Guththila XML parser library wrapper (default=yes)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    WRAPPER_DIR="guththila"
    if test -d $srcdir/guththila; then
        AC_CONFIG_SUBDIRS(guththila)
    fi

    GUTHTHILA_LIBS="/guththila/src/"
    GUTHTHILA_DIR="guththila"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  WRAPPER_DIR="guththila"
)

AC_MSG_CHECKING(whether to build libxml2 xml parser library)
AC_ARG_ENABLE(libxml2, [  --enable-libxml2	build Libxml2 XML parser library wrapper (default=no)],
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

AC_MSG_CHECKING(path to use openssl . This is a compulsory to build Rampart-C)
AC_ARG_WITH(openssl,
[  --with-openssl[=PATH]      use openssl.],
[ case "$withval" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT($withval)
    dnl Find oprnssl dir in the path
    if test -d $withval; then
        opensslinc="-I$withval/include/openssl"
        openssllib="-L$withval/lib"
	CFLAGS="$CFLAGS -DAXIS2_SSL_ENABLED"
	ssl_enabled=true
    elif test -d '/usr/include/openssl'; then
        opensslinc="-I/usr/include/openssl"
        openssllib=""
	CFLAGS="$CFLAGS -DAXIS2_SSL_ENABLED"
	ssl_enabled=true
    else
        AC_MSG_ERROR(could not find openssl. stop)
    fi
    ;;
  esac ],
  AC_MSG_RESULT(no)
)

IKSEMELINC=$iksemelinc
IKSEMELLIB=$iksemellib

AC_SUBST(IKSEMELINC)
AC_SUBST(IKSEMELLIB)
OPENSSLINC=$opensslinc
OPENSSLLIB=$openssllib
AC_SUBST(OPENSSLINC)
AC_SUBST(OPENSSLLIB)
AC_SUBST(OMXMLSEC_LIBS)
AC_SUBST(RAMPART_LIBS)
dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])
AC_CHECK_HEADERS([linux/if.h],[],[],
[
#include <sys/socket.h>
])

dnl Checks for typedefs, structures, and compiler characteristics.
dnl AC_C_CONST

dnl Checks for library functions.
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])


AC_CONFIG_FILES([Makefile 
    ])
    
AC_OUTPUT
