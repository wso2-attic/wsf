dnl run autogen.sh to generate the configure script.

AC_PREREQ(2.59)

AC_INIT(axis2c-src, 0.96)
AC_CANONICAL_SYSTEM
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([tar-ustar])
AC_PREFIX_DEFAULT(/usr/local/axis2c)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AM_PROG_LIBTOOL
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

if test -d $srcdir/util; then
    AC_CONFIG_SUBDIRS(util)
fi

if test -d $srcdir/axiom; then
    AC_CONFIG_SUBDIRS(axiom)
fi

#CFLAGS="$CFLAGS -ansi -Wall -D_LARGEFILE64_SOURCE -Wno-implicit-function-declaration"
CFLAGS="$CFLAGS -D_LARGEFILE64_SOURCE"
if test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -ansi -Wall -Wno-implicit-function-declaration -g"
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
AC_C_CONST

dnl Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
#AC_CHECK_FUNCS([memmove])

AC_MSG_CHECKING(whether to build rampart )
AC_ARG_ENABLE(rampart, [  --enable-rampart build ramprt. default=no],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    RAMPART_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    RAMPART_DIR="rampart"
    if test -d $srcdir/rampart; then
        AC_CONFIG_SUBDIRS(rampart)
    fi

    ;;
  esac ],
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to build libxml2 xml parser library)
AC_ARG_ENABLE(libxml2, [  --enable-libxml2    build libxml2 xml parser library wrapper. default=yes],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    WRAPPER_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    WRAPPER_DIR="libxml2"
    PKG_CHECK_MODULES(PARSER, libxml-2.0)
    CFLAGS="$CFLAGS $PARSER_LIBS"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  WRAPPER_DIR="libxml2"
)


GUTHTHILA_LIBS=""

AC_MSG_CHECKING(whether to build guththila xml parser library)
AC_ARG_ENABLE(guththila, [  --enable-guththila    build guththila xml parser library wrapper. default=no],
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
  AC_MSG_RESULT(no)
)

AC_MSG_CHECKING(whether to use apache2 as server transport)
AC_ARG_WITH(apache2,
[  --with-apache2[=PATH]      use apache2 as server transport.],
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
[  --with-apr[=PATH]      use apr.],
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
AC_ARG_ENABLE(tests, [  --enable-tests    build tests. default=yes],
[ case "${enableval}" in
  yes)
    AC_MSG_RESULT(yes)
    TESTDIR="test"
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
AC_ARG_ENABLE(trace, [  --enable-trace    enable trace. default=no],
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
AC_ARG_ENABLE(multi-thread, [  --enable-multi-thread  enable multi thread. default=yes],
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
AC_ARG_ENABLE(openssl, [  --enable-openssl  enable ssl. default=no],
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


AC_MSG_CHECKING(whether to build dynamic invocation client library)
AC_ARG_ENABLE(diclient, [  --enable-diclient    build diclient library wrapper. default=no],
[ case "${enableval}" in
  no)
    AC_MSG_RESULT(no)
    DICLIENT_DIR=""
    ;;
  *)
    AC_MSG_RESULT(yes)
    DICLIENT_DIR="diclient"

    ;;
  esac ],
  AC_MSG_RESULT(yes)
  DICLIENT_DIR="diclient"
)



APACHE2INC=$apache2inc
APRINC=$aprinc

AC_SUBST(PARSER_LIBS)
AC_SUBST(APACHE2INC)
AC_SUBST(APRINC)
AC_SUBST(DICLIENT_DIR)
AC_SUBST(TESTDIR)
AC_SUBST(SAMPLES)
AC_SUBST(APACHE2BUILD)
AC_SUBST(PARSER_DIR)
AC_SUBST(WRAPPER_DIR)
AC_SUBST(GUTHTHILA_DIR)
AC_SUBST(RAMPART_DIR)
AC_SUBST(GUTHTHILA_LIBS)
AM_CONDITIONAL(AXIS2_SSL_ENABLED, test x$ssl_enabled = xtrue)
#export PARSER_DIR
export WRAPPER_DIR
export prefix 

AC_CONFIG_FILES([Makefile \
    modules/Makefile \
    modules/core/Makefile \
    modules/core/description/Makefile \
    modules/core/context/Makefile \
    modules/core/engine/Makefile \
    modules/core/addr/Makefile \
    modules/core/phaseresolver/Makefile \
    modules/core/transport/http/Makefile \
    modules/core/transport/http/common/Makefile \
    modules/core/transport/http/util/Makefile \
    modules/core/transport/http/sender/Makefile \
    modules/core/transport/http/sender/ssl/Makefile \
    modules/core/transport/http/receiver/Makefile \
    modules/core/transport/http/server/simple_axis2_server/Makefile \
    modules/core/transport/http/server/Makefile \
    modules/core/transport/http/server/apache2/Makefile \
    modules/core/deployment/Makefile \
    modules/core/clientapi/Makefile \
    modules/core/receivers/Makefile \
    modules/core/util/Makefile \
    modules/mod_addr/Makefile \
    modules/mod_log/Makefile \
    test/Makefile \
    test/core/Makefile \
    test/core/description/Makefile \
    test/core/clientapi/Makefile \
    test/core/deployment/Makefile \
    test/core/context/Makefile \
    test/core/engine/Makefile \
    test/core/addr/Makefile \
    test/core/transport/Makefile\
    test/core/transport/http/Makefile \
    test/itest/Makefile \
    test/itest/whitemesa/Makefile \
    test/itest/whitemesa/round1/Makefile \
    test/itest/whitemesa/round2/Makefile \
    test/tools/Makefile \
    ides/Makefile \
    ides/anjuta/Makefile \
    include/Makefile \
    axis2c.pc
    ])
    
AC_OUTPUT
