dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(wso2-wsf-c-src, 1.0alpha2)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/wsf_c)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AM_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

dnl Checks for libraries.
AC_CHECK_LIB(dl, dlopen)
AC_CHECK_LIB(z, inflate)

if test -d $srcdir/axis2c; then
    AC_CONFIG_SUBDIRS(axis2c)
fi

if test -d $srcdir/savanc; then
    AC_CONFIG_SUBDIRS(savanc)
fi

#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
#    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration "
    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration -Wall"
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
  AC_MSG_RESULT(no)
  CFLAGS="$CFLAGS"
)

AC_MSG_CHECKING(whether to build xmpp)
AC_ARG_ENABLE(xmpp, [  --enable-xmpp  
                          enable xmpp build (default=no)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    CFLAGS="$CFLAGS"
    xmpp_enabled=false
    ;;
  *)
    AC_MSG_RESULT(yes)
    XMPP_DIR="xmpp"
    CFLAGS="$CFLAGS -DAXIS2_XMPP_ENABLED"
    xmpp_enabled=false
    ;;
  esac ],
  AC_MSG_RESULT(no)
  CFLAGS="$CFLAGS"
)

AC_MSG_CHECKING(whether to build )
AC_ARG_ENABLE(rampart, [  --enable-rampart
                          build  (default=yes)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    RAMPART_DIR="c"
    if test -d $srcdir/c; then
        AC_CONFIG_SUBDIRS(c)
    fi

    RAMPART_DIR="c"

    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to build wsclient)
AC_ARG_ENABLE(wsclient, [  --enable-wsclient
                          build wsclient (default=yes)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    WSCLIENT_DIR="wsclient"
    if test -d $srcdir/wsclient; then
        AC_CONFIG_SUBDIRS(wsclient)
    fi

    WSCLIENT_DIR="wsclient"

    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to build sandesha)
AC_ARG_ENABLE(sandesha, [  --enable-sandesha
                          build sandesha (default=yes)],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    ;;
  *)
    AC_MSG_RESULT(yes)
    SANDESHA_DIR="sandesha"
    if test -d $srcdir/sandesha; then
        AC_CONFIG_SUBDIRS(sandesha)
    fi

    SANDESHA_DIR="sandesha"

    ;;
  esac ],
  AC_MSG_RESULT(no)
)


dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])
AC_CHECK_HEADERS([linux/if.h],[],[],
[
#include <sys/socket.h>
])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])

AC_SUBST(RAMPART_DIR)
AC_SUBST(WSCLIENT_DIR)
AC_SUBST(SANDESHA_DIR)

AC_CONFIG_FILES([Makefile 
    ])
    
AC_OUTPUT
